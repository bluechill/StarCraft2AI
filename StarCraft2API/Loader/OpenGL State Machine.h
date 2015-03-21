//
//  OpenGL State Machine.h
//  StarCraft2API
//
//  Created by Alex Turner on 1/11/15.
//  Copyright (c) 2015 Alex Turner. All rights reserved.
//

#ifndef __StarCraft2API__OpenGL_State_Machine__
#define __StarCraft2API__OpenGL_State_Machine__

#include <OpenGL/gl.h>
#include <OpenGL/CGLContext.h>
#include <OpenGL/OpenGL.h>
#include <OpenCL/OpenCL.h>

namespace OpenGL
{
	class StateMachine
	{
	public:
		CGLContextObj ctx;
		
		virtual ~StateMachine() {};
		
		virtual void active_texture(GLIContext ctx, GLenum target) = 0;
		virtual void active_stencil_face_EXT(GLIContext ctx, GLenum face) = 0;
		virtual void active_shader_program(GLIContext ctx, GLuint pipeline, GLuint program) = 0;
		
		virtual void bind_texture(GLIContext ctx, GLenum target, GLuint texture) = 0;
		virtual void bind_program_ARB(GLIContext ctx, GLenum target, GLuint program) = 0;
		virtual void bind_vertex_array_EXT(GLIContext ctx, GLuint id) = 0;
		virtual void bind_attrib_location_ARB(GLIContext ctx, GLhandleARB programObj, GLuint index, const GLcharARB *name) = 0;
		virtual void bind_buffer(GLIContext ctx, GLenum target, GLuint buffer) = 0;
		virtual void bind_renderbuffer_EXT(GLIContext ctx, GLenum target, GLuint renderbuffer) = 0;
		virtual void bind_framebuffer_EXT(GLIContext ctx, GLenum target, GLuint framebuffer) = 0;
		virtual void bind_buffer_range_EXT(GLIContext ctx, GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) = 0;
		virtual void bind_buffer_offset_EXT(GLIContext ctx, GLenum target, GLuint index, GLuint buffer, GLintptr offset) = 0;
		virtual void bind_buffer_base_EXT(GLIContext ctx, GLenum target, GLuint index, GLuint buffer) = 0;
		virtual void bind_frag_data_location_EXT(GLIContext ctx, GLuint program, GLuint colorNumber, const GLchar *name) = 0;
		virtual void bind_vertex_array_ARB(GLIContext ctx, GLuint array) = 0;
		virtual void bind_sampler(GLIContext ctx, GLuint unit, GLuint sampler) = 0;
		virtual void bind_program_pipeline(GLIContext ctx, GLuint pipeline) = 0;
		virtual void bind_frag_data_location_indexed(GLIContext ctx, GLuint program, GLuint colorNumber, GLuint index, const GLchar *name) = 0;
		virtual void bind_transform_feedback(GLIContext ctx, GLenum target, GLuint name) = 0;
		
		virtual void program_env_parameters4fv_EXT(GLIContext ctx, GLenum target, GLuint index, GLsizei count, const GLfloat *params) = 0;
		virtual void program_local_parameters4fv_EXT(GLIContext ctx, GLenum target, GLuint index, GLsizei count, const GLfloat *params) = 0;
		
		virtual void draw_arrays(GLIContext ctx, GLenum mode, GLint first, GLsizei count) = 0;
		virtual void draw_buffer(GLIContext ctx, GLenum mode) = 0;
		virtual void draw_elements(GLIContext ctx, GLenum mode, GLsizei count, GLenum type, const GLvoid* indices) = 0;
		virtual void draw_pixels(GLIContext ctx, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid*pixels) = 0;
		virtual void draw_range_elements(GLIContext ctx, GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices) = 0;
		virtual void draw_element_array_APPLE(GLIContext ctx, GLenum mode, GLint first, GLsizei count) = 0;
		virtual void draw_range_element_array_APPLE(GLIContext ctx, GLenum mode, GLuint start, GLuint end, GLint first, GLsizei count) = 0;
		virtual void multi_draw_arrays(GLIContext ctx, GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount) = 0;
		virtual void multi_draw_elements(GLIContext ctx, GLenum mode, const GLsizei *count, GLenum type, const GLvoid* const *indices, GLsizei drawcount) = 0;
		virtual void draw_buffers_ARB(GLIContext ctx, GLsizei n, const GLenum *bufs) = 0;
		virtual void multi_draw_element_array_APPLE(GLIContext ctx, GLenum mode, const GLint *first, const GLsizei *count, GLsizei primcount) = 0;
		virtual void multi_draw_range_element_array_APPLE(GLIContext ctx, GLenum mode, GLuint start, GLuint end, const GLint *first, const GLsizei *count, GLsizei primcount) = 0;
		virtual void draw_arrays_instanced(GLIContext ctx, GLenum mode, GLint first, GLsizei count, GLsizei instancecount) = 0;
		virtual void draw_elements_instanced(GLIContext ctx, GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLsizei instancecount) = 0;
		virtual void draw_elements_base_vertex(GLIContext ctx, GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLint base_vertex) = 0;
		virtual void draw_range_elements_base_vertex(GLIContext ctx, GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices, GLint base_vertex) = 0;
		virtual void draw_elements_instanced_base_vertex(GLIContext ctx, GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLsizei instancecount, GLint base_vertex) = 0;
		virtual void multi_draw_elements_base_vertex(GLIContext ctx, GLenum mode, const GLsizei *count, GLenum type, const GLvoid* const *indices, GLsizei drawcount, const GLint *base_vertex) = 0;
		virtual void draw_arrays_indirect(GLIContext ctx, GLenum mode, const GLvoid *indirect) = 0;
		virtual void draw_elements_indirect(GLIContext ctx, GLenum mode, GLenum type, const GLvoid *indirect) = 0;
		virtual void draw_transform_feedback(GLIContext ctx, GLenum mode, GLuint name) = 0;
		virtual void draw_transform_feedback_stream(GLIContext ctx, GLenum mode, GLuint name, GLuint stream) = 0;
		
		virtual void swap_APPLE(GLIContext ctx) = 0;
		
		virtual void program_string_ARB(GLIContext ctx, GLenum target, GLenum format, GLsizei len, const GLvoid* string) = 0;
		virtual void vertex_attrib_pointer_ARB(GLIContext ctx, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid *pointer) = 0;
		virtual void enable_vertex_attrib_array_ARB(GLIContext ctx, GLuint index) = 0;
		virtual void disable_vertex_attrib_array_ARB(GLIContext ctx, GLuint index) = 0;

		
		virtual cl_context get_opencl_context() = 0;
	};
	
	extern StateMachine* Shared;
};

#endif /* defined(__StarCraft2API__OpenGL_State_Machine__) */
