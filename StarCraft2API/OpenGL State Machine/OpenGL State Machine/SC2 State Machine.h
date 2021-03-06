//
//  SC2 State Machine.h
//  StarCraft2API
//
//  Created by Alex Turner on 1/11/15.
//  Copyright (c) 2015 Alex Turner. All rights reserved.
//

#ifndef __StarCraft2API__SC2_State_Machine__
#define __StarCraft2API__SC2_State_Machine__

#include "OpenGL State Machine.h"

#include "TextureDatabase.h"
#include "SC2Program.h"

#include <unordered_set>


namespace OpenGL
{
	class SC2_StateMachine : public StateMachine
	{
	public:
		SC2_StateMachine();
		~SC2_StateMachine();
		
		void active_texture(GLIContext ctx, GLenum target);
		void active_stencil_face_EXT(GLIContext ctx, GLenum face);
		void active_shader_program(GLIContext ctx, GLuint pipeline, GLuint program);
		
		void bind_texture(GLIContext ctx, GLenum target, GLuint texture);
		void bind_program_ARB(GLIContext ctx, GLenum target, GLuint program);
		void bind_vertex_array_EXT(GLIContext ctx, GLuint id);
		void bind_attrib_location_ARB(GLIContext ctx, GLhandleARB programObj, GLuint index, const GLcharARB *name);
		void bind_buffer(GLIContext ctx, GLenum target, GLuint buffer);
		void bind_renderbuffer_EXT(GLIContext ctx, GLenum target, GLuint renderbuffer);
		void bind_framebuffer_EXT(GLIContext ctx, GLenum target, GLuint framebuffer);
		void bind_buffer_range_EXT(GLIContext ctx, GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
		void bind_buffer_offset_EXT(GLIContext ctx, GLenum target, GLuint index, GLuint buffer, GLintptr offset);
		void bind_buffer_base_EXT(GLIContext ctx, GLenum target, GLuint index, GLuint buffer);
		void bind_frag_data_location_EXT(GLIContext ctx, GLuint program, GLuint colorNumber, const GLchar *name);
		void bind_vertex_array_ARB(GLIContext ctx, GLuint array);
		void bind_sampler(GLIContext ctx, GLuint unit, GLuint sampler);
		void bind_program_pipeline(GLIContext ctx, GLuint pipeline);
		void bind_frag_data_location_indexed(GLIContext ctx, GLuint program, GLuint colorNumber, GLuint index, const GLchar *name);
		void bind_transform_feedback(GLIContext ctx, GLenum target, GLuint name);
		
		void program_env_parameters4fv_EXT(GLIContext ctx, GLenum target, GLuint index, GLsizei count, const GLfloat *params);
		void program_local_parameters4fv_EXT(GLIContext ctx, GLenum target, GLuint index, GLsizei count, const GLfloat *params);
		
		void draw_arrays(GLIContext ctx, GLenum mode, GLint first, GLsizei count);
		void draw_buffer(GLIContext ctx, GLenum mode);
		void draw_elements(GLIContext ctx, GLenum mode, GLsizei count, GLenum type, const GLvoid *indices);
		void draw_pixels(GLIContext ctx, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
		void draw_range_elements(GLIContext ctx, GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices);
		void draw_element_array_APPLE(GLIContext ctx, GLenum mode, GLint first, GLsizei count);
		void draw_range_element_array_APPLE(GLIContext ctx, GLenum mode, GLuint start, GLuint end, GLint first, GLsizei count);
		void multi_draw_arrays(GLIContext ctx, GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount);
		void multi_draw_elements(GLIContext ctx, GLenum mode, const GLsizei *count, GLenum type, const GLvoid* const *indices, GLsizei drawcount);
		void draw_buffers_ARB(GLIContext ctx, GLsizei n, const GLenum *bufs);
		void multi_draw_element_array_APPLE(GLIContext ctx, GLenum mode, const GLint *first, const GLsizei *count, GLsizei primcount);
		void multi_draw_range_element_array_APPLE(GLIContext ctx, GLenum mode, GLuint start, GLuint end, const GLint *first, const GLsizei *count, GLsizei primcount);
		void draw_arrays_instanced(GLIContext ctx, GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
		void draw_elements_instanced(GLIContext ctx, GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLsizei instancecount);
		void draw_elements_base_vertex(GLIContext ctx, GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLint base_vertex);
		void draw_range_elements_base_vertex(GLIContext ctx, GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices, GLint base_vertex);
		void draw_elements_instanced_base_vertex(GLIContext ctx, GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLsizei instancecount, GLint base_vertex);
		void multi_draw_elements_base_vertex(GLIContext ctx, GLenum mode, const GLsizei *count, GLenum type, const GLvoid* const *indices, GLsizei drawcount, const GLint *base_vertex);
		void draw_arrays_indirect(GLIContext ctx, GLenum mode, const GLvoid *indirect);
		void draw_elements_indirect(GLIContext ctx, GLenum mode, GLenum type, const GLvoid *indirect);
		void draw_transform_feedback(GLIContext ctx, GLenum mode, GLuint name);
		void draw_transform_feedback_stream(GLIContext ctx, GLenum mode, GLuint name, GLuint stream);
		
		void swap_APPLE(GLIContext ctx);
		
		void program_string_ARB(GLIContext ctx, GLenum target, GLenum format, GLsizei len, const GLvoid* string);
		void vertex_attrib_pointer_ARB(GLIContext ctx, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid *pointer);
		void enable_vertex_attrib_array_ARB(GLIContext ctx, GLuint index);
		void disable_vertex_attrib_array_ARB(GLIContext ctx, GLuint index);
		
		cl_context get_opencl_context() { return opencl_context; }
		
	private:
		friend class TextureDatabase;
		friend class SC2Program;
		friend class SC2ProgramFactory;
		friend class SC2VertexProgram;
		friend class SC2FragmentProgram;
		
		// OpenGL state
		GLuint m_active_texture;
		std::pair<GLenum,GLuint> *m_texture_units;
		
		GLuint m_bound_frag_program;
		cl_mem m_opencl_frag_program_env = nullptr;
		cl_float4* m_frag_program_env = nullptr;
		size_t m_frag_program_env_size = 0;
		
		GLuint m_bound_vert_program;
		cl_mem m_opencl_vert_program_env = nullptr;
		cl_float4* m_vert_program_env = nullptr;
		size_t m_vert_program_env_size = 0;
		
		std::unordered_map<GLuint, SC2Program*> m_gl_program_to_cl;
		
		GLuint m_bound_array_buffer;
		cl_mem m_bound_array_buffer_cl;
		GLint m_bound_array_buffer_size;
		
		GLuint m_bound_element_buffer;
		cl_mem m_bound_element_buffer_cl;
		GLint m_bound_element_buffer_size;
		
		std::unordered_map<GLuint, cl_mem> gl_buffer_to_cl;
		
		std::unordered_set<GLuint> m_logged_textures;
		
		// Setup & Interpreting
		bool was_setup;
		inline void shared_setup();
		
		void draw_event(size_t vertex_count, size_t offset);
		void end_of_frame();
		
		TextureDatabase db;
		
		// OpenCL setup
		cl_device_id opencl_device_id;
		cl_context opencl_context;
		cl_command_queue commands;
		dispatch_queue_t queue;
		dispatch_semaphore_t cl_gl_semaphore;
		
		cl_mem m_opencl_attrib_info_array;
		SC2Program::attrib_info_struct m_vertex_attribs[16];
	};
}

#endif /* defined(__StarCraft2API__OpenGL_State_Machine__) */
