//
//  SC2Program.h
//  StarCraft2API
//
//  Created by Alex Turner on 1/22/15.
//  Copyright (c) 2015 Alex Turner. All rights reserved.
//

#ifndef __StarCraft2API__SC2Program__
#define __StarCraft2API__SC2Program__

#include <string>
#include <vector>

#include <unordered_map>

#include <OpenCL/OpenCL.h>

namespace OpenGL
{
	class SC2_StateMachine;
	class SC2ProgramFactory;
	
	class SC2Program
	{
	public:
		SC2Program(SC2_StateMachine* s, GLint max_local_parameters);
		~SC2Program();
		
#include "Structures.h"
		
		virtual std::vector<sc2_result_struct> run(size_t vertex_count, size_t offset) = 0;
		
		cl_float4* m_local_parameters;
		size_t m_local_parameters_size;
		cl_mem m_opencl_local_parameters;
		
	protected:
		friend class SC2ProgramFactory;
		
		SC2_StateMachine* state;
		
		cl_program m_program;
		cl_kernel m_kernel;
		
		result_struct* m_result_array;
		cl_mem m_opencl_result_array;
		
		size_t max_texcoord;
	private:
		std::vector<std::string> split_string(std::string str, char delim );
		
		void load(std::vector<std::string> program_lines, unsigned long hash);
		void load(unsigned long hash, std::string name);
		
		void save_program(std::string path, cl_program program, cl_device_id device);
	};
	
	class SC2ProgramFactory
	{
	public:
		static SC2Program* construct(std::string program_string, SC2_StateMachine* state);
		
	private:
		static std::unordered_map<unsigned long, SC2Program*> hash_to_program;
	};
	
}

#endif /* defined(__StarCraft2API__SC2Program__) */
