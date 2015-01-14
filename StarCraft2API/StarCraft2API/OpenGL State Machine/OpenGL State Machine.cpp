//
//  OpenGL State Machine.cpp
//  StarCraft2API
//
//  Created by Alex Turner on 1/11/15.
//  Copyright (c) 2015 Alex Turner. All rights reserved.
//

#include "OpenGL State Machine.h"

#include <string>

using namespace std;

#include "Logging.h"

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
	
	void StateMachine::shared_setup()
	{
		if (!was_setup)
		{
			was_setup = true;
			
			GLint t_size;
			glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &t_size);
			
			m_texture_units = new pair<GLenum, GLuint>[t_size];
		}
	}
	
	void StateMachine::draw_event()
	{
		SC2::Utilities::file_log("DRAW EVENT\n\n\n");

		// Log the texture to a file if we haven't already
		if (!db.has_texture(m_texture_units[m_active_texture].second))
			db.create_texture(m_texture_units[m_active_texture].second);
		
		SC2::Utilities::file_log("\n\n\n");

	}
	
	void StateMachine::end_of_frame()
	{
		SC2::Utilities::file_log("END OF FRAME\n\n\n");
	}
}