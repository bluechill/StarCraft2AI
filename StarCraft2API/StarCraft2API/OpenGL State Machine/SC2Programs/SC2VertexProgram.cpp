//
//  SC2VertexProgram.cpp
//  StarCraft2API
//
//  Created by Alex Turner on 1/22/15.
//  Copyright (c) 2015 Alex Turner. All rights reserved.
//

#include "SC2VertexProgram.h"
#include "OpenGL State Machine.h"

#include "Structures.h"

namespace OpenGL
{
	SC2VertexProgram::SC2VertexProgram(StateMachine* s, GLint max_local_parameters)
	: SC2Program(s, max_local_parameters)
	{
		
	}
	
	std::vector<SC2Program::result_struct> SC2VertexProgram::run()
	{
		glFinish();
		
		std::vector<SC2Program::result_struct> results;
		std::vector<cl_float4> tex_coords;

		size_t kernel_count = state->m_bound_array_buffer_size;
		
		results.resize(kernel_count);
		tex_coords.resize(kernel_count * 16);
		
		//	__global float4* program_env
		// __global float4* program_local
		// __global float* vertex_attrib_array
		// __global unsigned int vertex_attrib_index_array_count,
		// __global struct attrib_info* vertex_attrib_info_array
		// __global fragment_struct* fragment_array
		// __global float4* fragment_texcoord_array
		// __global unsigned int fragment_max_texcoord_size
		// __global result_struct* result_array
		// __global float4* result_texcoord_array
		// __global unsigned int result_texcoord_max_size
		// __global float4* result_frag_color_array
		// __global unsigned int result_frag_color_max_size
		// const unsigned int count

		// Send the program_env to the GPU
		clEnqueueWriteBuffer(state->commands, state->m_opencl_vert_program_env, false, 0, state->m_vert_program_env_size * sizeof(cl_float), state->m_vert_program_env, 0, nullptr, nullptr);
		
		// Send the program_local to the GPU
		clEnqueueWriteBuffer(state->commands, m_opencl_local_parameters, false, 0, m_local_parameters_size * sizeof(cl_float), m_local_parameters, 0, nullptr, nullptr);
		
		// Aquire the attrib buffer
		clEnqueueAcquireGLObjects(state->commands, 1, &state->m_bound_array_buffer_cl, 0, nullptr, nullptr);
		
		// Send the attrib info array to the GPU
		clEnqueueWriteBuffer(state->commands, m_opencl_attrib_info_array, false, 0, sizeof(attrib_info_struct)*16, m_vertex_attribs, 0, nullptr, nullptr);
		
		// Create a result array for the kernel
		cl_mem result_buffer = clCreateBuffer(state->opencl_context, CL_MEM_WRITE_ONLY, sizeof(result_struct) * kernel_count, &results[0], nullptr);
		
		// Create a tex coord result array for the kernel
		cl_mem tex_coord_array = clCreateBuffer(state->opencl_context, CL_MEM_WRITE_ONLY, sizeof(cl_float4) * 16 * kernel_count, nullptr, nullptr);
		
		unsigned int zero = 0;
		
		// Set the arguments
		clSetKernelArg(this->m_kernel, 0, sizeof(cl_mem), state->m_opencl_vert_program_env);
		clSetKernelArg(this->m_kernel, 1, sizeof(cl_mem), m_opencl_local_parameters);
		
		// Vertex
		clSetKernelArg(this->m_kernel, 2, sizeof(cl_mem), state->m_bound_array_buffer_cl);
		clSetKernelArg(this->m_kernel, 3, sizeof(unsigned int), &kernel_count);
		clSetKernelArg(this->m_kernel, 4, sizeof(cl_mem), m_opencl_attrib_info_array);
		
		// Fragments
		clSetKernelArg(this->m_kernel, 5, sizeof(cl_mem), nullptr);
		clSetKernelArg(this->m_kernel, 5, sizeof(unsigned int), &zero);
		clSetKernelArg(this->m_kernel, 6, sizeof(cl_mem), nullptr);
		clSetKernelArg(this->m_kernel, 5, sizeof(unsigned int), &zero);

		// Results
		unsigned int sixteen = 16;
		clSetKernelArg(this->m_kernel, 7, sizeof(cl_mem), result_buffer);
		clSetKernelArg(this->m_kernel, 8, sizeof(cl_mem), tex_coord_array);
		clSetKernelArg(this->m_kernel, 5, sizeof(unsigned int), &sixteen);
		clSetKernelArg(this->m_kernel, 9, sizeof(cl_mem), nullptr);
		clSetKernelArg(this->m_kernel, 5, sizeof(unsigned int), &zero);
		clSetKernelArg(this->m_kernel, 10, sizeof(unsigned int), &kernel_count);
		
		// Run the kernel
		size_t local_item_size = 1;
		clEnqueueNDRangeKernel(state->commands, this->m_kernel, 1, nullptr, &kernel_count, &local_item_size, 0, nullptr, nullptr);
		
		clEnqueueReadBuffer(state->commands, result_buffer, CL_TRUE, 0, kernel_count * sizeof(SC2Program::result_struct), &results[0], 0, nullptr, nullptr);
		clEnqueueReadBuffer(state->commands, tex_coord_array, CL_TRUE, 0, kernel_count * sizeof(cl_float4) * 16, &tex_coords[0], 0, nullptr, nullptr);
		
		for (int i = 0;i < kernel_count;++i)
		{
			results[i].texcoord = new cl_float4[16];
			
			for (int j = 0;j < 16;++j)
				results[i].texcoord[j] = tex_coords[i * 16 + j];
		}
		
		clEnqueueReleaseGLObjects(state->commands, 1, &state->m_bound_array_buffer_cl, 0, nullptr, nullptr);
		
		clFlush(state->commands);
		clFinish(state->commands);
		clReleaseMemObject(result_buffer);
		clReleaseMemObject(tex_coord_array);
		
		return results;
	}
}