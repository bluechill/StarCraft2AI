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
	class StateMachine;
	class SC2ProgramFactory;
	
	class SC2Program
	{
	public:
		SC2Program(StateMachine* s, GLint max_local_parameters);
		~SC2Program();
		
		struct vec4
		{
			float x,y,z,w;
		};
		
		struct color
		{
			float r,g,b,a;
		};
		
		struct tex
		{
			float s,t,r,q;
		};
		
		struct result
		{
			// Vertex Shader
			vec4 position;
			
			color front_primary;
			color front_secondary;
			
			color back_primary;
			color back_secondary;
			
			float fogcoord;
			float pointsize;
			
			std::vector<tex> texcoord;
			
			// Fragment Shader
			std::vector<color> fragment_color;
			float depth;
		};
		
		virtual std::vector<result> run() = 0;
		
		cl_float4* m_local_parameters;
		cl_mem m_opencl_local_parameters;
		
	protected:
		friend class SC2ProgramFactory;
		
		StateMachine* state;
		
		cl_program m_program;
		cl_kernel m_kernel;
		
		//__global vertex_struct* vertex, __global result_struct* result, __global fragment_struct* fragment, __global program_struct* program, const unsigned int count
		
		
	private:
		std::vector<std::string> split_string(std::string str, char delim );
		
		void load(std::vector<std::string> program_lines, unsigned long hash);
		void load(unsigned long hash, std::string name);
		
		void save_program(std::string path, cl_program program, cl_device_id device);
	};
	
	class SC2ProgramFactory
	{
	public:
		static SC2Program* construct(std::string program_string, StateMachine* state);
		
	private:
		static std::unordered_map<unsigned long, SC2Program*> hash_to_program;
	};
	
}

#endif /* defined(__StarCraft2API__SC2Program__) */
