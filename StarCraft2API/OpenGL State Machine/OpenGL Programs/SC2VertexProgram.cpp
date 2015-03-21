//
//  SC2VertexProgram.cpp
//  StarCraft2API
//
//  Created by Alex Turner on 1/22/15.
//  Copyright (c) 2015 Alex Turner. All rights reserved.
//

#include "SC2VertexProgram.h"
#include "SC2 State Machine.h"

#include "Structures.h"
#include "Logging.h"

#include "opencl_error.hpp"

namespace OpenGL
{
	SC2VertexProgram::SC2VertexProgram(SC2_StateMachine* s, GLint max_local_parameters)
	: SC2Program(s, max_local_parameters)
	{
	}
	
	std::vector<SC2Program::sc2_result_struct> SC2VertexProgram::run(size_t vertex_count, size_t offset)
	{
		glFinish();
		
		std::vector<SC2Program::sc2_result_struct> sc2_results;
		std::vector<SC2Program::result_struct> results;
		std::vector<cl_float4> tex_coords;

		size_t kernel_count = vertex_count;
		
		results.resize(kernel_count);
		sc2_results.resize(kernel_count);
		tex_coords.resize(kernel_count * 16);

		// Send the program_env to the GPU
		cl_int error = CL_SUCCESS;
		
		error = clEnqueueWriteBuffer(state->commands, state->m_opencl_vert_program_env, false, 0, state->m_vert_program_env_size * sizeof(cl_float), state->m_vert_program_env, 0, nullptr, nullptr);
		if (error != CL_SUCCESS)
		{
			SC2::Utilities::console_log("Failed to Enqueue Write Buffer: %s", boost::compute::opencl_error::to_string(error).c_str());
			return sc2_results;
		}
		
		// Send the program_local to the GPU
		error = clEnqueueWriteBuffer(state->commands, m_opencl_local_parameters, false, 0, m_local_parameters_size * sizeof(cl_float), m_local_parameters, 0, nullptr, nullptr);
		if (error != CL_SUCCESS)
		{
			SC2::Utilities::console_log("Failed to Enqueue Write Buffer: %s", boost::compute::opencl_error::to_string(error).c_str());
			return sc2_results;
		}
		
		// Aquire the attrib buffer
		error = clEnqueueAcquireGLObjects(state->commands, 1, &state->m_bound_array_buffer_cl, 0, nullptr, nullptr);
		if (error != CL_SUCCESS)
		{
			SC2::Utilities::console_log("Failed to Aquire GL objects: %s", boost::compute::opencl_error::to_string(error).c_str());
			return sc2_results;
		}
		
		// Aquire the element buffer
		error = clEnqueueAcquireGLObjects(state->commands, 1, &state->m_bound_element_buffer_cl, 0, nullptr, nullptr);
		if (error != CL_SUCCESS)
		{
			SC2::Utilities::console_log("Failed to Aquire GL objects: %s", boost::compute::opencl_error::to_string(error).c_str());
			return sc2_results;
		}
		
		// Send the attrib info array to the GPU
		error = clEnqueueWriteBuffer(state->commands, state->m_opencl_attrib_info_array, CL_TRUE, 0, sizeof(attrib_info_struct)*16, state->m_vertex_attribs, 0, nullptr, nullptr);
		if (error != CL_SUCCESS)
		{
			SC2::Utilities::console_log("Failed to Enqueue Write Buffer: %s", boost::compute::opencl_error::to_string(error).c_str());
			return sc2_results;
		}
		
		// Create a result array for the kernel
		cl_mem result_buffer = clCreateBuffer(state->opencl_context, CL_MEM_WRITE_ONLY, sizeof(result_struct) * kernel_count, nullptr, &error);
		if (error != CL_SUCCESS)
		{
			SC2::Utilities::console_log("Failed to Create Buffer: %s", boost::compute::opencl_error::to_string(error).c_str());
			return sc2_results;
		}
		
		// Create a tex coord result array for the kernel
		cl_mem tex_coord_array = clCreateBuffer(state->opencl_context, CL_MEM_WRITE_ONLY, sizeof(cl_float4) * 16 * kernel_count, nullptr, &error);
		if (error != CL_SUCCESS)
		{
			SC2::Utilities::console_log("Failed to Create Buffer: %s", boost::compute::opencl_error::to_string(error).c_str());
			return sc2_results;
		}
		
		// Set the arguments
		// Program.*
		error = clSetKernelArg(this->m_kernel, 0, sizeof(cl_mem), &state->m_opencl_vert_program_env);
		if (error != CL_SUCCESS)
		{
			SC2::Utilities::console_log("Failed to set kernel arg: %s", boost::compute::opencl_error::to_string(error).c_str());
			return sc2_results;
		}
		
		error = clSetKernelArg(this->m_kernel, 1, sizeof(cl_mem), &m_opencl_local_parameters);
		if (error != CL_SUCCESS)
		{
			SC2::Utilities::console_log("Failed to set kernel arg: %s", boost::compute::opencl_error::to_string(error).c_str());
			return sc2_results;
		}
		
		size_t sixteen = 16;

		// vertex.*
		error = clSetKernelArg(this->m_kernel, 2, sizeof(cl_mem), &state->m_bound_array_buffer_cl);
		if (error != CL_SUCCESS)
		{
			SC2::Utilities::console_log("Failed to set kernel arg: %s", boost::compute::opencl_error::to_string(error).c_str());
			return sc2_results;
		}
		
		error = clSetKernelArg(this->m_kernel, 3, sizeof(cl_mem), &state->m_bound_element_buffer_cl);
		if (error != CL_SUCCESS)
		{
			SC2::Utilities::console_log("Failed to set kernel arg: %s", boost::compute::opencl_error::to_string(error).c_str());
			return sc2_results;
		}
		
		error = clSetKernelArg(this->m_kernel, 4, sizeof(size_t), &offset);
		if (error != CL_SUCCESS)
		{
			SC2::Utilities::console_log("Failed to set kernel arg: %s", boost::compute::opencl_error::to_string(error).c_str());
			return sc2_results;
		}
		
		error = clSetKernelArg(this->m_kernel, 5, sizeof(size_t), &vertex_count);
		if (error != CL_SUCCESS)
		{
			SC2::Utilities::console_log("Failed to set kernel arg: %s", boost::compute::opencl_error::to_string(error).c_str());
			return sc2_results;
		}
		
		error = clSetKernelArg(this->m_kernel, 6, sizeof(cl_mem), &state->m_opencl_attrib_info_array);
		if (error != CL_SUCCESS)
		{
			SC2::Utilities::console_log("Failed to set kernel arg: %s", boost::compute::opencl_error::to_string(error).c_str());
			return sc2_results;
		}
		
		// result.*
		error = clSetKernelArg(this->m_kernel, 7, sizeof(cl_mem), &result_buffer);
		if (error != CL_SUCCESS)
		{
			SC2::Utilities::console_log("Failed to set kernel arg: %s", boost::compute::opencl_error::to_string(error).c_str());
			return sc2_results;
		}
		
		error = clSetKernelArg(this->m_kernel, 8, sizeof(cl_mem), &tex_coord_array);
		if (error != CL_SUCCESS)
		{
			SC2::Utilities::console_log("Failed to set kernel arg: %s", boost::compute::opencl_error::to_string(error).c_str());
			return sc2_results;
		}
		
		error = clSetKernelArg(this->m_kernel, 9, sizeof(size_t), &sixteen);
		if (error != CL_SUCCESS)
		{
			SC2::Utilities::console_log("Failed to set kernel arg: %s", boost::compute::opencl_error::to_string(error).c_str());
			return sc2_results;
		}
		
		error = clSetKernelArg(this->m_kernel, 10, sizeof(size_t), &kernel_count);
		if (error != CL_SUCCESS)
		{
			SC2::Utilities::console_log("Failed to set kernel arg: %s", boost::compute::opencl_error::to_string(error).c_str());
			return sc2_results;
		}
		
		// Run the kernel
		error = clEnqueueNDRangeKernel(state->commands, this->m_kernel, 1, nullptr, &kernel_count, nullptr, 0, nullptr, nullptr);
		if (error != CL_SUCCESS)
		{
			SC2::Utilities::console_log("Failed to enqueue NDRange kernel: %s", boost::compute::opencl_error::to_string(error).c_str());
			return sc2_results;
		}
		
		error = clFinish(state->commands);
		if (error != CL_SUCCESS)
		{
			SC2::Utilities::console_log("Failed to run kernel: %s", boost::compute::opencl_error::to_string(error).c_str());
			return sc2_results;
		}
		
		// Read the results
		error = clEnqueueReadBuffer(state->commands, result_buffer, CL_TRUE, 0, sizeof(result_struct) * kernel_count, &results[0], 0, nullptr, nullptr);
		if (error != CL_SUCCESS)
		{
			SC2::Utilities::console_log("Failed to enqueue read buffer: %s", boost::compute::opencl_error::to_string(error).c_str());
			return sc2_results;
		}
		
		error = clEnqueueReadBuffer(state->commands, tex_coord_array, CL_TRUE, 0, sizeof(cl_float4) * 16 * kernel_count, &tex_coords[0], 0, nullptr, nullptr);
		if (error != CL_SUCCESS)
		{
			SC2::Utilities::console_log("Failed to enqueue read buffer: %s", boost::compute::opencl_error::to_string(error).c_str());
			return sc2_results;
		}
		
		error = clFinish(state->commands);
		if (error != CL_SUCCESS)
		{
			SC2::Utilities::console_log("Failed to finish read buffers: %s", boost::compute::opencl_error::to_string(error).c_str());
			return sc2_results;
		}
		
		// Use the results
		
		for (int i = 0;i < kernel_count;++i)
		{
			sc2_results[i].position = results[i].position;
			sc2_results[i].color = results[i].color;
			
			sc2_results[i].texcoord = new cl_float4[16];
			
			for (int j = 0;j < 16;++j)
				sc2_results[i].texcoord[j] = tex_coords[i * 16 + j];
		}
		
		// Clean up
		clEnqueueReleaseGLObjects(state->commands, 1, &state->m_bound_array_buffer_cl, 0, nullptr, nullptr);
		clFlush(state->commands);
		clFinish(state->commands);
		clReleaseMemObject(result_buffer);
		clReleaseMemObject(tex_coord_array);
		
		// Return the results
		return sc2_results;
	}
}
