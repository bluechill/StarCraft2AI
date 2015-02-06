//
//  SC2Program.cpp
//  StarCraft2API
//
//  Created by Alex Turner on 1/22/15.
//  Copyright (c) 2015 Alex Turner. All rights reserved.
//

#include "SC2Program.h"
#include "SC2FragmentProgram.h"
#include "SC2VertexProgram.h"

#include "OpenGL State Machine.h"
#include "ARBtoOpenCL.h"

#include "Logging.h"

#include "xxhash.h"

#include <sstream>
#include <fstream>
#include <functional>
#include <cstdio>

using namespace std;

namespace OpenGL
{
	//class SC2Program
	//{
	//public:
	//	struct vec4
	//	{
	//		float x,y,z,w;
	//	};
	//
	//	struct color
	//	{
	//		float r,g,b,a;
	//	};
	//
	//	struct tex
	//	{
	//		float s,t,r,q;
	//	};
	//
	//	struct result
	//	{
	//		// Vertex Shader
	//		vec4 position;
	//
	//		color front_primary;
	//		color front_secondary;
	//
	//		color back_primary;
	//		color back_secondary;
	//
	//		float fogcoord;
	//		float pointsize;
	//
	//		std::vector<tex> texcoord;
	//
	//		// Fragment Shader
	//		std::vector<color> fragment_color;
	//		float depth;
	//	};
	//
	//	virtual void load(std::string program_string);
	SC2Program::SC2Program(StateMachine* s, GLint max_local_parameters)
	: state(s)
	{
		m_opencl_local_parameters = clCreateBuffer(state->opencl_context, CL_MEM_READ_ONLY, sizeof(cl_float4) * max_local_parameters, nullptr, nullptr);
		m_local_parameters = new cl_float4[max_local_parameters];
	}
	
	SC2Program::~SC2Program()
	{
		clReleaseMemObject(m_opencl_local_parameters);
		delete[] m_local_parameters;
	}
	
	std::vector<std::string> SC2Program::split_string(std::string str, char delim ) {
		std::vector<std::string> result;
		string tmp;
		string::iterator i;
		result.clear();
		
		for(i = str.begin(); i <= str.end(); ++i) {
			if((const char)*i != delim  && i != str.end())
				tmp += *i;
			else
			{
				result.push_back(tmp);
				tmp = "";
			}
		}
		
		return result;
	}
	
	void SC2Program::load(std::vector<std::string> program_lines, unsigned long hash)
	{
		std::string name = "";
		
		ConvertToOpenCL* converter = new ARBtoOpenCL;
		converter->load(program_lines, hash);
		
		name = converter->get_name();
		
		std::string path = "/Users/bluechill/Developer/OpenGLInjector/StarCraft2API/StarCraft2API/SC2Info/SC2Shaders/" + name + "-" + to_string(hash) + ".cl";
		
		ofstream file(path);
		
		file << converter;
		
		this->load(hash, name);
	}
	
	void SC2Program::load(unsigned long hash, std::string name)
	{
		// Load the file into a string
		std::string path_source = "/Users/bluechill/Developer/OpenGLInjector/StarCraft2API/StarCraft2API/SC2Info/SC2Shaders/" + name + "-" + to_string(hash) + ".cl";
		std::string path_binary = "/Users/bluechill/Developer/OpenGLInjector/StarCraft2API/StarCraft2API/SC2Info/SC2Shaders/" + name + "-" + to_string(hash) + ".sc2program";
		
		cl_int error = 0;
		
		ifstream file_binary(path_binary);
		ifstream file_source(path_source);
		
		m_program = nullptr;
		
		if (file_binary.is_open())
		{
			FILE *fp = fopen(path_binary.c_str(), "rb");
			
			if (fp == NULL)
				return;
			
			// Determine the size of the binary
			size_t binarySize;
			fseek(fp, 0, SEEK_END);
			binarySize = ftell(fp);
			rewind(fp);
			
			unsigned char *programBinary = new unsigned char[binarySize];
			fread(programBinary, 1, binarySize, fp);
			fclose(fp);
			
			cl_int errNum = 0;
			cl_int binaryStatus;
			
			m_program = clCreateProgramWithBinary(state->opencl_context,
												1,
												&state->opencl_device_id,
												&binarySize,
												(const unsigned char**)&programBinary,
												&binaryStatus,
												&errNum);
			delete [] programBinary;
			if (errNum != CL_SUCCESS)
			{
				std::cerr << "Error loading program binary." << std::endl;
				m_program = nullptr;
				
				remove(path_binary.c_str());
			}
			
			if (binaryStatus != CL_SUCCESS)
			{
				SC2::Utilities::console_log("Error: Failed to create compute program! Invalid binary for device");
				m_program = nullptr;
				
				remove(path_binary.c_str());
			}
		}
		
		if (!m_program)
		{
			std::string opencl_source((std::istreambuf_iterator<char>(file_source)),
									  std::istreambuf_iterator<char>());
			
			const char* source = opencl_source.c_str();
			
			m_program = clCreateProgramWithSource(state->opencl_context, 1, &source, nullptr, &error);
			if (!m_program)
			{
				SC2::Utilities::console_log("Error: Failed to create compute program!");
				return;
			}
		}
		
		error = clBuildProgram(m_program, 0, NULL, "-cl-mad-enable -cl-fast-relaxed-math -Werror -cl-unsafe-math-optimizations -cl-finite-math-only", NULL, NULL);
		if (error != CL_SUCCESS)
		{
			size_t len;
			char buffer[2048];
			
			SC2::Utilities::console_log("Error: Failed to build program executable!\n");
			clGetProgramBuildInfo(m_program, state->opencl_device_id, CL_PROGRAM_BUILD_LOG, sizeof(buffer), buffer, &len);
			SC2::Utilities::console_log("%s\n", buffer);
			
			return;
		}
		
		// Save for later.
		FILE *fp = fopen(path_binary.c_str(), "rb");
		
		if (fp == NULL)
			save_program(path_binary, m_program, state->opencl_device_id);
		
		string kernel_name = name + "-" + to_string(hash);
		m_kernel = clCreateKernel(m_program, kernel_name.c_str(), &error);
		if (!m_kernel || error != CL_SUCCESS)
		{
			SC2::Utilities::console_log("Error: Failed to create compute kernel!");
			return;
		}
	}
	
	
	void SC2Program::save_program(std::string path, cl_program program, cl_device_id device)
	{
		// Taken from: https://code.google.com/p/opencl-book-samples/source/browse/trunk/src/Chapter_6/HelloBinaryWorld/HelloBinaryWorld.cpp
		
		cl_uint numDevices = 0;
		cl_int errNum;
		
		// 1 - Query for number of devices attached to program
		errNum = clGetProgramInfo(program, CL_PROGRAM_NUM_DEVICES, sizeof(cl_uint),
								  &numDevices, NULL);
		if (errNum != CL_SUCCESS)
		{
			std::cerr << "Error querying for number of devices." << std::endl;
			return;
		}
		
		// 2 - Get all of the Device IDs
		cl_device_id *devices = new cl_device_id[numDevices];
		errNum = clGetProgramInfo(program, CL_PROGRAM_DEVICES,
								  sizeof(cl_device_id) * numDevices,
								  devices, NULL);
		if (errNum != CL_SUCCESS)
		{
			std::cerr << "Error querying for devices." << std::endl;
			delete [] devices;
			return;
		}
		
		// 3 - Determine the size of each program binary
		size_t *programBinarySizes = new size_t [numDevices];
		errNum = clGetProgramInfo(program, CL_PROGRAM_BINARY_SIZES,
								  sizeof(size_t) * numDevices,
								  programBinarySizes, NULL);
		if (errNum != CL_SUCCESS)
		{
			std::cerr << "Error querying for program binary sizes." << std::endl;
			delete [] devices;
			delete [] programBinarySizes;
			return;
		}
		
		unsigned char **programBinaries = new unsigned char*[numDevices];
		for (cl_uint i = 0; i < numDevices; i++)
			programBinaries[i] = new unsigned char[programBinarySizes[i]];
		
		// 4 - Get all of the program binaries
		errNum = clGetProgramInfo(program, CL_PROGRAM_BINARIES, sizeof(unsigned char*) * numDevices,
								  programBinaries, NULL);
		if (errNum != CL_SUCCESS)
		{
			std::cerr << "Error querying for program binaries" << std::endl;
			
			delete [] devices;
			delete [] programBinarySizes;
			for (cl_uint i = 0; i < numDevices; i++)
				delete [] programBinaries[i];
			
			delete [] programBinaries;
			return;
		}
		
		// 5 - Finally store the binaries for the device requested out to disk for future reading.
		for (cl_uint i = 0; i < numDevices; i++)
		{
			// Store the binary just for the device requested.  In a scenario where
			// multiple devices were being used you would save all of the binaries out here.
			if (devices[i] == device)
			{
				FILE *fp = fopen(path.c_str(), "wb");
				fwrite(programBinaries[i], 1, programBinarySizes[i], fp);
				fclose(fp);
				break;
			}
		}
		
		// Cleanup
		delete [] devices;
		delete [] programBinarySizes;
		for (cl_uint i = 0; i < numDevices; i++)
			delete [] programBinaries[i];
		
		delete [] programBinaries;
	}
	
	SC2Program* SC2ProgramFactory::construct(std::string program_string, StateMachine* state)
	{
		// Split up into lines
		std::vector<std::string> program_lines;
		
		std::stringstream ss(program_string);
		
		std::string line;
		while (std::getline(ss, line))
			program_lines.push_back(line);
		
		SC2Program* program = nullptr;
		
		unsigned long hash = XXH32(program_string.c_str(), program_string.length(), 0xDEADBEEF);
		
		if (hash_to_program.find(hash) == hash_to_program.end())
		{
			GLint max_local_parameters;
			
			// New program
			if (program_lines[0] == "!!ARBfp1.0")
			{
				glGetProgramiv(state->m_bound_frag_program, GL_MAX_PROGRAM_LOCAL_PARAMETERS_ARB, &max_local_parameters);
				
				program = new SC2FragmentProgram(state, max_local_parameters);
			}
			else if (program_lines[0] == "!!ARBvp1.0")
			{
				glGetProgramiv(state->m_bound_vert_program, GL_MAX_PROGRAM_LOCAL_PARAMETERS_ARB, &max_local_parameters);
				
				program = new SC2VertexProgram(state, max_local_parameters);
			}
			
			program->load(program_lines, hash);
		}
		else
		{
			// Already have it
			program = hash_to_program[hash];
		}
		
		return program;
	}
	
	std::unordered_map<unsigned long, SC2Program*> SC2ProgramFactory::hash_to_program;
}
