//
//  OpenGL State Machine.cpp
//  StarCraft2API
//
//  Created by Alex Turner on 1/11/15.
//  Copyright (c) 2015 Alex Turner. All rights reserved.
//

#include "OpenGL State Machine.h"

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
	StateMachine StateMachine::Shared;
	
	StateMachine::StateMachine()
	{
		was_setup = false;
		m_active_texture = 0;
	}
	
	StateMachine::~StateMachine()
	{
		delete[] m_texture_units;
		delete[] m_vert_program_env;
		delete[] m_frag_program_env;
		
		clReleaseMemObject(m_opencl_frag_program_env);
		clReleaseMemObject(m_opencl_vert_program_env);
	}
	
	/////////////////////////////////////////////////////////////////
	// ACTIVE
	/////////////////////////////////////////////////////////////////
	
	void StateMachine::active_texture(GLIContext ctx, GLenum target)
	{
		shared_setup();
		
		m_active_texture = target - GL_TEXTURE0;
	}
	
	void StateMachine::active_stencil_face_EXT(GLIContext ctx, GLenum face)
	{
		shared_setup();
	}
	
	void StateMachine::active_shader_program(GLIContext ctx, GLuint pipeline, GLuint program)
	{
		shared_setup();
	}
	
	/////////////////////////////////////////////////////////////////
	// BIND
	/////////////////////////////////////////////////////////////////
	
	void StateMachine::bind_texture(GLIContext ctx, GLenum target, GLuint texture)
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
	
	void StateMachine::bind_program_ARB(GLIContext ctx, GLenum target, GLuint program)
	{
		shared_setup();
		
		if (target == GL_FRAGMENT_PROGRAM_ARB)
		{
			m_bound_frag_program = program;
			
			if (!m_frag_program_env)
			{
				GLint max_env_params;
				glGetProgramiv(m_bound_frag_program, GL_MAX_PROGRAM_ENV_PARAMETERS_ARB, &max_env_params);

				m_frag_program_env = new cl_float4[max_env_params];
				m_opencl_frag_program_env = clCreateBuffer(opencl_context, CL_MEM_READ_ONLY, sizeof(cl_float4) * max_env_params, nullptr, nullptr);
			}
		}
		else if (target == GL_VERTEX_PROGRAM_ARB)
		{
			m_bound_vert_program = program;
			
			if (!m_vert_program_env)
			{
				GLint max_env_params;
				glGetProgramiv(m_bound_vert_program, GL_MAX_PROGRAM_ENV_PARAMETERS_ARB, &max_env_params);
				
				m_vert_program_env = new cl_float4[max_env_params];
				m_opencl_vert_program_env = clCreateBuffer(opencl_context, CL_MEM_READ_ONLY, sizeof(cl_float4) * max_env_params, nullptr, nullptr);
			}
		}
	}
	
	void StateMachine::bind_vertex_array_EXT(GLIContext ctx, GLuint id)
	{
		shared_setup();
	}
	
	void StateMachine::bind_attrib_location_ARB(GLIContext ctx, GLhandleARB programObj, GLuint index, const GLcharARB *name)
	{
		shared_setup();
	}
	
	void StateMachine::bind_buffer(GLIContext ctx, GLenum target, GLuint buffer)
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
	
	void StateMachine::bind_renderbuffer_EXT(GLIContext ctx, GLenum target, GLuint renderbuffer)
	{
		shared_setup();
	}
	
	void StateMachine::bind_framebuffer_EXT(GLIContext ctx, GLenum target, GLuint framebuffer)
	{
		shared_setup();
	}
	
	void StateMachine::bind_buffer_range_EXT(GLIContext ctx, GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size)
	{
		shared_setup();
	}
	
	void StateMachine::bind_buffer_offset_EXT(GLIContext ctx, GLenum target, GLuint index, GLuint buffer, GLintptr offset)
	{
		shared_setup();
	}
	
	void StateMachine::bind_buffer_base_EXT(GLIContext ctx, GLenum target, GLuint index, GLuint buffer)
	{
		shared_setup();
	}
	
	void StateMachine::bind_frag_data_location_EXT(GLIContext ctx, GLuint program, GLuint colorNumber, const GLchar *name)
	{
		shared_setup();
	}
	
	void StateMachine::bind_vertex_array_ARB(GLIContext ctx, GLuint array)
	{
		shared_setup();
	}
	
	void StateMachine::bind_sampler(GLIContext ctx, GLuint unit, GLuint sampler)
	{
		shared_setup();
	}
	
	void StateMachine::bind_program_pipeline(GLIContext ctx, GLuint pipeline)
	{
		shared_setup();
	}
	
	void StateMachine::bind_frag_data_location_indexed(GLIContext ctx, GLuint program, GLuint colorNumber, GLuint index, const GLchar *name)
	{
		shared_setup();
	}
	
	void StateMachine::bind_transform_feedback(GLIContext ctx, GLenum target, GLuint name)
	{
		shared_setup();
	}
	
	void StateMachine::program_local_parameters4fv_EXT(GLIContext ctx, GLenum target, GLuint index, GLsizei count, const GLfloat* params)
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
	
	void StateMachine::program_env_parameters4fv_EXT(GLIContext ctx, GLenum target, GLuint index, GLsizei count, const GLfloat* params)
	{
		cl_float4* array = nullptr;
		
		if (target == GL_FRAGMENT_PROGRAM_ARB)
			array = m_frag_program_env;
		else if (target == GL_VERTEX_PROGRAM_ARB)
			array = m_vert_program_env;
		
		for (int i = index, j = 0;i < count+index;++i)
		{
			array[i].x = params[j++];
			array[i].y = params[j++];
			array[i].z = params[j++];
			array[i].w = params[j++];
		}
	}
	
	/////////////////////////////////////////////////////////////////
	// DRAW
	/////////////////////////////////////////////////////////////////
	
	void StateMachine::draw_arrays(GLIContext ctx, GLenum mode, GLint first, GLsizei count)
	{
		draw_event();
	}
	
	void StateMachine::draw_buffer(GLIContext ctx, GLenum mode)
	{
		draw_event();
	}
	
	void StateMachine::draw_elements(GLIContext ctx, GLenum mode, GLsizei count, GLenum type, const GLvoid *indices)
	{
		draw_event();
	}
	
	void StateMachine::draw_pixels(GLIContext ctx, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels)
	{
		draw_event();
	}
	
	void StateMachine::draw_range_elements(GLIContext ctx, GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices)
	{
		draw_event();
	}
	
	void StateMachine::draw_element_array_APPLE(GLIContext ctx, GLenum mode, GLint first, GLsizei count)
	{
		draw_event();
	}
	
	void StateMachine::draw_range_element_array_APPLE(GLIContext ctx, GLenum mode, GLuint start, GLuint end, GLint first, GLsizei count)
	{
		draw_event();
	}
	
	void StateMachine::multi_draw_arrays(GLIContext ctx, GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount)
	{
		draw_event();
	}
	
	void StateMachine::multi_draw_elements(GLIContext ctx, GLenum mode, const GLsizei *count, GLenum type, const GLvoid* const *indices, GLsizei drawcount)
	{
		draw_event();
	}
	
	void StateMachine::draw_buffers_ARB(GLIContext ctx, GLsizei n, const GLenum *bufs)
	{
		draw_event();
	}
	
	void StateMachine::multi_draw_element_array_APPLE(GLIContext ctx, GLenum mode, const GLint *first, const GLsizei *count, GLsizei primcount)
	{
		draw_event();
	}
	
	void StateMachine::multi_draw_range_element_array_APPLE(GLIContext ctx, GLenum mode, GLuint start, GLuint end, const GLint *first, const GLsizei *count, GLsizei primcount)
	{
		draw_event();
	}
	
	void StateMachine::draw_arrays_instanced(GLIContext ctx, GLenum mode, GLint first, GLsizei count, GLsizei instancecount)
	{
		draw_event();
	}
	
	void StateMachine::draw_elements_instanced(GLIContext ctx, GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLsizei instancecount)
	{
		draw_event();
	}
	
	void StateMachine::draw_elements_base_vertex(GLIContext ctx, GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLint base_vertex)
	{
		draw_event();
	}
	
	void StateMachine::draw_range_elements_base_vertex(GLIContext ctx, GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices, GLint base_vertex)
	{
		draw_event();
	}
	
	void StateMachine::draw_elements_instanced_base_vertex(GLIContext ctx, GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLsizei instancecount, GLint base_vertex)
	{
		draw_event();
	}
	
	void StateMachine::multi_draw_elements_base_vertex(GLIContext ctx, GLenum mode, const GLsizei *count, GLenum type, const GLvoid* const *indices, GLsizei drawcount, const GLint *base_vertex)
	{
		draw_event();
	}
	
	void StateMachine::draw_arrays_indirect(GLIContext ctx, GLenum mode, const GLvoid *indirect)
	{
		draw_event();
	}
	
	void StateMachine::draw_elements_indirect(GLIContext ctx, GLenum mode, GLenum type, const GLvoid *indirect)
	{
		draw_event();
	}
	
	void StateMachine::draw_transform_feedback(GLIContext ctx, GLenum mode, GLuint name)
	{
		draw_event();
	}
	
	void StateMachine::draw_transform_feedback_stream(GLIContext ctx, GLenum mode, GLuint name, GLuint stream)
	{
		draw_event();
	}
	
	void StateMachine::swap_APPLE(GLIContext ctx)
	{
		end_of_frame();
	}
	
	void StateMachine::program_string_ARB(GLIContext ctx, GLenum target, GLenum format, GLsizei len, const GLvoid* string)
	{
		unsigned int hash = XXH32(string, len, 0xDEADBEEF);

		std::string shader_source = (const char*)string;
		
		size_t program = shader_source.find("#program ");
		size_t end = shader_source.find("\n", program);
		
		if (program == string::npos || end == string::npos)
			SC2::Utilities::console_log("Failed to find #program string: %i", hash);
		
		program += 9;
		
		std::string name = shader_source.substr(program, end-program);
		std::string path = "/Users/bluechill/Developer/OpenGLInjector/StarCraft2API/StarCraft2API/SC2Info/SC2Shaders/" + name + "-" + to_string(hash) + ".arb";

		ofstream shader_file;
		shader_file.open(path, std::ios::trunc | std::ios::out);
		shader_file << shader_source;
		shader_file.close();
		
		if (target == GL_VERTEX_PROGRAM_ARB && m_gl_program_to_cl.find(m_bound_vert_program) == m_gl_program_to_cl.end())
			m_gl_program_to_cl[m_bound_vert_program] = SC2ProgramFactory::construct(shader_source, this);
		else if (target == GL_FRAGMENT_PROGRAM_ARB && m_gl_program_to_cl.find(m_bound_frag_program) == m_gl_program_to_cl.end())
			m_gl_program_to_cl[m_bound_frag_program] = SC2ProgramFactory::construct(shader_source, this);
	}
	
	void StateMachine::shared_setup()
	{
		if (!was_setup)
		{
			was_setup = true;
			
			GLint t_size;
			glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &t_size);
			
			m_texture_units = new pair<GLenum, GLuint>[t_size];
			
			// Setup OpenCL
			cl_int error = 0;
			error = clGetPlatformIDs(1, &opencl_platform_id, nullptr);
			
			if (error != CL_SUCCESS)
			{
				// Failed to setup OpenCL
				SC2::Utilities::console_log("Failed to get OpenCL Platform! %s", boost::compute::opencl_error::to_string(error).c_str());
				return;
			}
			
			error = clGetDeviceIDs(opencl_platform_id, CL_DEVICE_TYPE_GPU, 1, &opencl_device_id, nullptr);
			
			if (error != CL_SUCCESS)
			{
				// Failed to setup OpenCL
				SC2::Utilities::console_log("Failed to get OpenCL Device! %s", boost::compute::opencl_error::to_string(error).c_str());
				return;
			}
			
			 // Get current CGL Context and CGL Share group
			CGLContextObj cgl_context = CGLGetCurrentContext();
			CGLShareGroupObj sharegroup = CGLGetShareGroup(cgl_context);
			
			// Create CL context properties, add handle & share-group enum
			cl_context_properties properties[] = {
				CL_CONTEXT_PROPERTY_USE_CGL_SHAREGROUP_APPLE,
				(cl_context_properties)sharegroup,
				CL_CONTEXT_PLATFORM,
				(cl_context_properties)opencl_platform_id, 0
			};
			
			opencl_context = clCreateContext(properties, 1, &opencl_device_id, nullptr, 0, &error);
			
			if (error != CL_SUCCESS)
			{
				// Failed to setup OpenCL
				SC2::Utilities::console_log("Failed to share OpenGL OpenCL Context! %s", boost::compute::opencl_error::to_string(error).c_str());
				return;
			}
		}
	}
	
	void StateMachine::draw_event()
	{
		SC2::Utilities::file_log("DRAW EVENT\n\n\n");

		// Log the texture to a file if we haven't already
		if (!db.has_texture(m_texture_units[m_active_texture].second))
			db.create_texture(m_texture_units[m_active_texture].second);
		
		vector<SC2Program::result_struct> results = m_gl_program_to_cl[m_bound_vert_program]->run();
		
		cl_float4 position;
		
		const float size = results.size();
		
		for (SC2Program::result_struct& s : results)
		{
			position.x += s.position.x / size;
			position.y += s.position.y / size;
			position.z += s.position.z / size;
			position.w += s.position.w / size;
		}
		
		SC2::Utilities::file_log("Rendering Object at (x,y,z,w): (%f, %f, %f, %f)", position.x, position.y, position.z, position.w);
		
		SC2::Utilities::file_log("\n\n\n");
	}
	
	void StateMachine::end_of_frame()
	{
		SC2::Utilities::file_log("END OF FRAME\n\n\n");
	}
}