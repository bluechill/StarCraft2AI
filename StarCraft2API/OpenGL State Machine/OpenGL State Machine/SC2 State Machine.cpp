//
//  SC2 State Machine.cpp
//  StarCraft2API
//
//  Created by Alex Turner on 1/11/15.
//  Copyright (c) 2015 Alex Turner. All rights reserved.
//

#include "SC2 State Machine.h"

#include "SC2VertexProgram.h"

#include <string>
#include <fstream>

using namespace std;

#include "Logging.h"
#include "xxhash.h"

#include <OpenCL/cl_gl.h>

#include "opencl_error.hpp"

extern std::string GLenumToString(GLenum value);

namespace OpenGL
{
	SC2_StateMachine::SC2_StateMachine()
	{
		was_setup = false;
		m_active_texture = 0;
		
		m_texture_units = nullptr;
		m_vert_program_env = nullptr;
		m_frag_program_env = nullptr;
		m_opencl_frag_program_env = nullptr;
		m_opencl_vert_program_env = nullptr;
		
		for (int i = 0;i < 16;++i)
			m_vertex_attribs[i].enabled = false;
	}
	
	SC2_StateMachine::~SC2_StateMachine()
	{
		if (m_texture_units)
			delete[] m_texture_units;
		
		if (m_vert_program_env)
			delete[] m_vert_program_env;
		
		if (m_frag_program_env)
			delete[] m_frag_program_env;
		
		if (m_opencl_frag_program_env)
			clReleaseMemObject(m_opencl_frag_program_env);
		
		if (m_opencl_vert_program_env)
			clReleaseMemObject(m_opencl_vert_program_env);
	}
	
	/////////////////////////////////////////////////////////////////
	// ACTIVE
	/////////////////////////////////////////////////////////////////
	
	void SC2_StateMachine::active_texture(GLIContext ctx, GLenum target)
	{
		shared_setup();
		
		m_active_texture = target - GL_TEXTURE0;
	}
	
	void SC2_StateMachine::active_stencil_face_EXT(GLIContext ctx, GLenum face)
	{
		shared_setup();
	}
	
	void SC2_StateMachine::active_shader_program(GLIContext ctx, GLuint pipeline, GLuint program)
	{
		shared_setup();
	}
	
	/////////////////////////////////////////////////////////////////
	// BIND
	/////////////////////////////////////////////////////////////////
	
	void SC2_StateMachine::bind_texture(GLIContext ctx, GLenum target, GLuint texture)
	{
		shared_setup();
		
		m_texture_units[m_active_texture].first = target;
		m_texture_units[m_active_texture].second = texture;
		
		if (db.has_texture(texture))
		{
			const Texture& t = db.get_texture(texture);
			SC2::Utilities::file_log("Bound Texture (hash: %lu): %s\n", t.get_hash(), t.get_classification().c_str());
		}
	}
	
	void SC2_StateMachine::bind_program_ARB(GLIContext ctx, GLenum target, GLuint program)
	{
		shared_setup();
		
		if (target == GL_FRAGMENT_PROGRAM_ARB)
		{
			m_bound_frag_program = program;
			
			if (!m_frag_program_env)
			{
				m_frag_program_env = new cl_float4[m_frag_program_env_size];
				m_opencl_frag_program_env = clCreateBuffer(opencl_context, CL_MEM_READ_ONLY, sizeof(cl_float4) * m_frag_program_env_size, nullptr, nullptr);
			}
		}
		else if (target == GL_VERTEX_PROGRAM_ARB)
		{
			m_bound_vert_program = program;
			
			if (!m_vert_program_env)
			{
				m_vert_program_env = new cl_float4[m_vert_program_env_size];
				m_opencl_vert_program_env = clCreateBuffer(opencl_context, CL_MEM_READ_ONLY, sizeof(cl_float4) * m_vert_program_env_size, nullptr, nullptr);
			}
			
			if (m_gl_program_to_cl.find(m_bound_vert_program) == m_gl_program_to_cl.end())
			{
				GLint length = 0;
				glGetProgramivARB(GL_VERTEX_PROGRAM_ARB, GL_PROGRAM_LENGTH_ARB, &length);
				
				if (length != 0)
				{
					GLvoid* program_string = new GLchar[length];
					glGetProgramStringARB(GL_VERTEX_PROGRAM_ARB, GL_PROGRAM_STRING_ARB, program_string);
					
					program_string_ARB(this->ctx->rend, GL_VERTEX_PROGRAM_ARB, GL_PROGRAM_FORMAT_ASCII_ARB, length, program_string);
				}
				else
					SC2::Utilities::file_log("Unable to compile shader: 0 length\n");
			}
		}
	}
	
	void SC2_StateMachine::bind_vertex_array_EXT(GLIContext ctx, GLuint id)
	{
		shared_setup();
	}
	
	void SC2_StateMachine::bind_attrib_location_ARB(GLIContext ctx, GLhandleARB programObj, GLuint index, const GLcharARB *name)
	{
		shared_setup();
	}
	
	void SC2_StateMachine::bind_buffer(GLIContext ctx, GLenum target, GLuint buffer)
	{
		shared_setup();
		
		if (target == GL_ELEMENT_ARRAY_BUFFER)
		{
			m_bound_element_buffer = buffer;
			
			if (gl_buffer_to_cl.find(buffer) != gl_buffer_to_cl.end())
				m_bound_element_buffer_cl = gl_buffer_to_cl[buffer];
			else
			{
				m_bound_element_buffer_cl = clCreateFromGLBuffer(opencl_context, CL_MEM_READ_ONLY, buffer, nullptr);
				gl_buffer_to_cl[buffer] = m_bound_element_buffer_cl;
			}
			
			glGetBufferParameteriv(GL_ELEMENT_ARRAY_BUFFER, GL_BUFFER_SIZE, &m_bound_element_buffer_size);
			m_bound_element_buffer_size /= sizeof(float);
		}
		else if (target == GL_ARRAY_BUFFER)
		{
			m_bound_array_buffer = buffer;
			
			if (gl_buffer_to_cl.find(buffer) != gl_buffer_to_cl.end())
				m_bound_array_buffer_cl = gl_buffer_to_cl[buffer];
			else
			{
				m_bound_array_buffer_cl = clCreateFromGLBuffer(opencl_context, CL_MEM_READ_ONLY, buffer, nullptr);
				gl_buffer_to_cl[buffer] = m_bound_array_buffer_cl;
			}
			
			glGetBufferParameteriv(GL_ARRAY_BUFFER, GL_BUFFER_SIZE, &m_bound_array_buffer_size);
			m_bound_array_buffer_size /= sizeof(float);
		}
	}
	
	void SC2_StateMachine::bind_renderbuffer_EXT(GLIContext ctx, GLenum target, GLuint renderbuffer)
	{
		shared_setup();
	}
	
	void SC2_StateMachine::bind_framebuffer_EXT(GLIContext ctx, GLenum target, GLuint framebuffer)
	{
		shared_setup();
	}
	
	void SC2_StateMachine::bind_buffer_range_EXT(GLIContext ctx, GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size)
	{
		shared_setup();
	}
	
	void SC2_StateMachine::bind_buffer_offset_EXT(GLIContext ctx, GLenum target, GLuint index, GLuint buffer, GLintptr offset)
	{
		shared_setup();
	}
	
	void SC2_StateMachine::bind_buffer_base_EXT(GLIContext ctx, GLenum target, GLuint index, GLuint buffer)
	{
		shared_setup();
	}
	
	void SC2_StateMachine::bind_frag_data_location_EXT(GLIContext ctx, GLuint program, GLuint colorNumber, const GLchar *name)
	{
		shared_setup();
	}
	
	void SC2_StateMachine::bind_vertex_array_ARB(GLIContext ctx, GLuint array)
	{
		shared_setup();
	}
	
	void SC2_StateMachine::bind_sampler(GLIContext ctx, GLuint unit, GLuint sampler)
	{
		shared_setup();
	}
	
	void SC2_StateMachine::bind_program_pipeline(GLIContext ctx, GLuint pipeline)
	{
		shared_setup();
	}
	
	void SC2_StateMachine::bind_frag_data_location_indexed(GLIContext ctx, GLuint program, GLuint colorNumber, GLuint index, const GLchar *name)
	{
		shared_setup();
	}
	
	void SC2_StateMachine::bind_transform_feedback(GLIContext ctx, GLenum target, GLuint name)
	{
		shared_setup();
	}
	
	void SC2_StateMachine::program_local_parameters4fv_EXT(GLIContext ctx, GLenum target, GLuint index, GLsizei count, const GLfloat* params)
	{
		GLuint program = 0;
		
		if (target == GL_FRAGMENT_PROGRAM_ARB)
			program = m_bound_frag_program;
		else if (target == GL_VERTEX_PROGRAM_ARB)
			program = m_bound_vert_program;
		
		for (int i = index, j = 0;i < count+index;++i)
		{
			m_gl_program_to_cl[program]->m_local_parameters[i].x = params[j++];
			m_gl_program_to_cl[program]->m_local_parameters[i].y = params[j++];
			m_gl_program_to_cl[program]->m_local_parameters[i].z = params[j++];
			m_gl_program_to_cl[program]->m_local_parameters[i].w = params[j++];
		}
	}
	
	void SC2_StateMachine::program_env_parameters4fv_EXT(GLIContext ctx, GLenum target, GLuint index, GLsizei count, const GLfloat* params)
	{
		cl_float4* array = nullptr;
		
		if (target == GL_FRAGMENT_PROGRAM_ARB)
			array = m_frag_program_env;
		else if (target == GL_VERTEX_PROGRAM_ARB)
		{
			array = m_vert_program_env;
		}
		
		for (int i = index, j = 0;i < count+index;++i)
		{
			array[i].x = params[j++];
			array[i].y = params[j++];
			array[i].z = params[j++];
			array[i].w = params[j++];
		}
	}
	
	void SC2_StateMachine::vertex_attrib_pointer_ARB(GLIContext ctx, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid *pointer)
	{
		SC2VertexProgram::attrib_info_struct& attrib = m_vertex_attribs[index];

		attrib.index = index;
		attrib.size = size;
		
		switch (type)
		{
			case GL_UNSIGNED_BYTE:
				attrib.type_size = -sizeof(GLubyte);
				break;
			case GL_BYTE:
				attrib.type_size = sizeof(GLbyte);
				break;
			case GL_UNSIGNED_SHORT:
				attrib.type_size = -sizeof(GLushort);
				break;
			case GL_SHORT:
				attrib.type_size = sizeof(GLshort);
				break;
			case GL_UNSIGNED_INT:
				attrib.type_size = -sizeof(GLuint);
				break;
			case GL_INT:
				attrib.type_size = sizeof(GLint);
				break;
			case GL_FLOAT:
				attrib.type_size = sizeof(GLfloat);
				break;
			case GL_DOUBLE:
				attrib.type_size = sizeof(GLdouble);
				break;
		}
		
		attrib.normalize = normalized;
		attrib.stride = stride;
		
		attrib.offset = int(pointer);
	}
	
	void SC2_StateMachine::enable_vertex_attrib_array_ARB(GLIContext ctx, GLuint index)
	{
		m_vertex_attribs[index].enabled = true;
	}
	
	void SC2_StateMachine::disable_vertex_attrib_array_ARB(GLIContext ctx, GLuint index)
	{
		m_vertex_attribs[index].enabled = false;
	}
	
	/////////////////////////////////////////////////////////////////
	// DRAW
	/////////////////////////////////////////////////////////////////
	
	void SC2_StateMachine::draw_arrays(GLIContext ctx, GLenum mode, GLint first, GLsizei count)
	{
		draw_event(count, 0);
	}
	
	void SC2_StateMachine::draw_buffer(GLIContext ctx, GLenum mode)
	{
		draw_event(m_bound_array_buffer_size, 0);
	}
	
	void SC2_StateMachine::draw_elements(GLIContext ctx, GLenum mode, GLsizei count, GLenum type, const GLvoid *indices)
	{
		draw_event(count, (unsigned int)indices);
	}
	
	void SC2_StateMachine::draw_pixels(GLIContext ctx, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels)
	{}
	
	void SC2_StateMachine::draw_range_elements(GLIContext ctx, GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices)
	{
		draw_event(count, (unsigned int)indices);
	}
	
	void SC2_StateMachine::draw_element_array_APPLE(GLIContext ctx, GLenum mode, GLint first, GLsizei count)
	{
		draw_event(count, 0);
	}
	
	void SC2_StateMachine::draw_range_element_array_APPLE(GLIContext ctx, GLenum mode, GLuint start, GLuint end, GLint first, GLsizei count)
	{
		draw_event(count, first);
	}
	
	void SC2_StateMachine::multi_draw_arrays(GLIContext ctx, GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount)
	{
		for (int i = 0;i < drawcount;++i)
			draw_event(count[i], first[i]);
	}
	
	void SC2_StateMachine::multi_draw_elements(GLIContext ctx, GLenum mode, const GLsizei *count, GLenum type, const GLvoid* const *indices, GLsizei drawcount)
	{
		for (int i = 0;i < drawcount;++i)
			draw_event(count[i], (unsigned int)indices[i]);
	}
	
	void SC2_StateMachine::draw_buffers_ARB(GLIContext ctx, GLsizei n, const GLenum *bufs)
	{
		assert(1);
	}
	
	void SC2_StateMachine::multi_draw_element_array_APPLE(GLIContext ctx, GLenum mode, const GLint *first, const GLsizei *count, GLsizei primcount)
	{
		assert(1);
	}
	
	void SC2_StateMachine::multi_draw_range_element_array_APPLE(GLIContext ctx, GLenum mode, GLuint start, GLuint end, const GLint *first, const GLsizei *count, GLsizei primcount)
	{
		assert(1);
	}
	
	void SC2_StateMachine::draw_arrays_instanced(GLIContext ctx, GLenum mode, GLint first, GLsizei count, GLsizei instancecount)
	{
		assert(1);
	}
	
	void SC2_StateMachine::draw_elements_instanced(GLIContext ctx, GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLsizei instancecount)
	{
		assert(1);
	}
	
	void SC2_StateMachine::draw_elements_base_vertex(GLIContext ctx, GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLint base_vertex)
	{
		assert(1);
	}
	
	void SC2_StateMachine::draw_range_elements_base_vertex(GLIContext ctx, GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices, GLint base_vertex)
	{
		assert(1);
	}
	
	void SC2_StateMachine::draw_elements_instanced_base_vertex(GLIContext ctx, GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLsizei instancecount, GLint base_vertex)
	{
		assert(1);
	}
	
	void SC2_StateMachine::multi_draw_elements_base_vertex(GLIContext ctx, GLenum mode, const GLsizei *count, GLenum type, const GLvoid* const *indices, GLsizei drawcount, const GLint *base_vertex)
	{
		assert(1);
	}
	
	void SC2_StateMachine::draw_arrays_indirect(GLIContext ctx, GLenum mode, const GLvoid *indirect)
	{
		assert(1);
	}
	
	void SC2_StateMachine::draw_elements_indirect(GLIContext ctx, GLenum mode, GLenum type, const GLvoid *indirect)
	{
		assert(1);
	}
	
	void SC2_StateMachine::draw_transform_feedback(GLIContext ctx, GLenum mode, GLuint name)
	{
		assert(1);
	}
	
	void SC2_StateMachine::draw_transform_feedback_stream(GLIContext ctx, GLenum mode, GLuint name, GLuint stream)
	{
		assert(1);
	}
	
	void SC2_StateMachine::swap_APPLE(GLIContext ctx)
	{
		end_of_frame();
	}
	
	void SC2_StateMachine::program_string_ARB(GLIContext ctx, GLenum target, GLenum format, GLsizei len, const GLvoid* string)
	{
		unsigned int hash = XXH32(string, len, 0xDEADBEEF);

		std::string shader_source = (const char*)string;
		
		size_t program = shader_source.find("#program ");
		size_t end = shader_source.find("\n", program);
		
		if (program == string::npos || end == string::npos)
			SC2::Utilities::console_log("Failed to find #program string: %i", hash);
		
		program += 9;
		
		std::string name = shader_source.substr(program, end-program);
		std::string path = "/Users/bluechill/Developer/OpenGLInjector/StarCraft2API/SC2 Info/SC2Shaders/" + name + "-" + to_string(hash) + ".arb";

		ofstream shader_file;
		shader_file.open(path, std::ios::trunc | std::ios::out);
		shader_file << shader_source;
		shader_file.close();
		
		if (target == GL_VERTEX_PROGRAM_ARB && m_gl_program_to_cl.find(m_bound_vert_program) == m_gl_program_to_cl.end())
			m_gl_program_to_cl[m_bound_vert_program] = SC2ProgramFactory::construct(shader_source, this);
//		else if (target == GL_FRAGMENT_PROGRAM_ARB && m_gl_program_to_cl.find(m_bound_frag_program) == m_gl_program_to_cl.end())
//			m_gl_program_to_cl[m_bound_frag_program] = SC2ProgramFactory::construct(shader_source, this);
	}
	
	void SC2_StateMachine::shared_setup()
	{
		if (!was_setup)
		{
			was_setup = true;
			
			GLint max_env_params = 0;
			glGetProgramivARB(GL_VERTEX_PROGRAM_ARB, GL_MAX_PROGRAM_ENV_PARAMETERS_ARB, &max_env_params);
			m_vert_program_env_size = max_env_params;
			
			glGetProgramivARB(GL_FRAGMENT_PROGRAM_ARB, GL_MAX_PROGRAM_ENV_PARAMETERS_ARB, &max_env_params);
			m_frag_program_env_size = max_env_params;
			
			GLint t_size;
			glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &t_size);
			
			m_texture_units = new pair<GLenum, GLuint>[t_size];
			
			// Setup OpenCL
			cl_int error = 0;
			
			 // Get current CGL Context and CGL Share group
			CGLContextObj cgl_context = CGLGetCurrentContext();
			CGLShareGroupObj sharegroup = CGLGetShareGroup(cgl_context);
			gcl_gl_set_sharegroup(sharegroup);
			
			queue = gcl_create_dispatch_queue(CL_DEVICE_TYPE_GPU, nullptr);
			if (!queue)
			{
				SC2::Utilities::console_log("Failed to create dispatch queue!");
				return;
			}
			
			cl_gl_semaphore = dispatch_semaphore_create(0);
			if (!cl_gl_semaphore)
			{
				SC2::Utilities::console_log("Failed to create dispatch semaphore!");
				return;
			}
			
			opencl_device_id = nullptr;
			opencl_device_id = gcl_get_device_id_with_dispatch_queue(queue);
			
			if (!opencl_device_id)
			{
				SC2::Utilities::console_log("Failed to get opencl device id!");
				return;
			}
			
			opencl_context = nullptr;
			opencl_context = gcl_get_context();
			
			if (!opencl_context)
			{
				SC2::Utilities::console_log("Failed to get opencl context!");
				return;
			}
			
			commands = clCreateCommandQueue(opencl_context, opencl_device_id, 0, &error);
			if (error != CL_SUCCESS)
			{
				SC2::Utilities::console_log("Failed to create command queue!");
				return;
			}
			
			cl_char vendor_name[1024] = {0};
			cl_char device_name[1024] = {0};
			size_t returned_size;
			error = clGetDeviceInfo(opencl_device_id, CL_DEVICE_VENDOR, sizeof(vendor_name), vendor_name, &returned_size);
			error |= clGetDeviceInfo(opencl_device_id, CL_DEVICE_NAME, sizeof(device_name), device_name, &returned_size);
			if (error != CL_SUCCESS)
			{
				SC2::Utilities::console_log("Failed to retrieve device info!");
				return;
			}
			
			SC2::Utilities::console_log("SC2API: Connecting to %s %s...\n", vendor_name, device_name);
			
			m_opencl_attrib_info_array = clCreateBuffer(opencl_context, CL_MEM_WRITE_ONLY, sizeof(SC2Program::attrib_info_struct)*16, nullptr, &error);
			
			if (error != CL_SUCCESS)
			{
				SC2::Utilities::console_log("Failed to allocate attrib info structures! %s", boost::compute::opencl_error::to_string(error).c_str());
				return;
			}
		}
	}
	
	void SC2_StateMachine::draw_event(size_t vertex_count, unsigned long offset)
	{
		SC2::Utilities::file_log("DRAW EVENT\n\n\n");

		// Log the texture to a file if we haven't already
		if (!db.has_texture(m_texture_units[m_active_texture].second))
			db.create_texture(m_texture_units[m_active_texture].second);
		
		if (m_gl_program_to_cl.find(m_bound_vert_program) != m_gl_program_to_cl.end())
		{
			vector<SC2Program::sc2_result_struct> results = m_gl_program_to_cl[m_bound_vert_program]->run(vertex_count, offset);
			
			cl_float4 position;
			
			const float size = results.size();
			
			for (SC2Program::sc2_result_struct& s : results)
			{
				position.x += s.position.x / size;
				position.y += s.position.y / size;
				position.z += s.position.z / size;
				position.w += s.position.w / size;
			}
			
			SC2::Utilities::file_log("Rendering Object at (x,y,z,w): (%f, %f, %f, %f)", position.x, position.y, position.z, position.w);
			
			SC2::Utilities::file_log("\n\n\n");
		}
		else
			SC2::Utilities::file_log("Uncompiled shader used.\n\n\n");
	}
	
	void SC2_StateMachine::end_of_frame()
	{
		SC2::Utilities::file_log("END OF FRAME\n\n\n");
	}
}