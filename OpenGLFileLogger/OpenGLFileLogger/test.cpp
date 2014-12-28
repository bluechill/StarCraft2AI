static CGLContextObj (*CGLGetCurrentContext_reenter)();
static bool overriden = false;
static void (*accum_reenter)(GLIContext ctx, GLenum op, GLfloat value);
static void (*alpha_func_reenter)(GLIContext ctx, GLenum func, GLclampf ref);
static GLboolean (*are_textures_resident_reenter)(GLIContext ctx, GLsizei n, const GLuint *textures, GLboolean *residences);
static void (*array_element_reenter)(GLIContext ctx, GLint i);
static void (*begin_reenter)(GLIContext ctx, GLenum mode);
static void (*bind_texture_reenter)(GLIContext ctx, GLenum target, GLuint texture);
static void (*bitmap_reenter)(GLIContext ctx, GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte *bitmap);
static void (*blend_func_reenter)(GLIContext ctx, GLenum sfactor, GLenum dfactor);
static void (*call_list_reenter)(GLIContext ctx, GLuint list);
static void (*call_lists_reenter)(GLIContext ctx, GLsizei n, GLenum type, const GLvoid *lists);
static void (*clear_reenter)(GLIContext ctx, GLbitfield mask);
static void (*clear_accum_reenter)(GLIContext ctx, GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
static void (*clear_color_reenter)(GLIContext ctx, GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
static void (*clear_depth_reenter)(GLIContext ctx, GLclampd depth);
static void (*clear_index_reenter)(GLIContext ctx, GLfloat c);
static void (*clear_stencil_reenter)(GLIContext ctx, GLint s);
static void (*clip_plane_reenter)(GLIContext ctx, GLenum plane, const GLdouble *equation);
static void (*color3b_reenter)(GLIContext ctx, GLbyte red, GLbyte green, GLbyte blue);
static void (*color3bv_reenter)(GLIContext ctx, const GLbyte *v);
static void (*color3d_reenter)(GLIContext ctx, GLdouble red, GLdouble green, GLdouble blue);
static void (*color3dv_reenter)(GLIContext ctx, const GLdouble *v);
static void (*color3f_reenter)(GLIContext ctx, GLfloat red, GLfloat green, GLfloat blue);
static void (*color3fv_reenter)(GLIContext ctx, const GLfloat *v);
static void (*color3i_reenter)(GLIContext ctx, GLint red, GLint green, GLint blue);
static void (*color3iv_reenter)(GLIContext ctx, const GLint *v);
static void (*color3s_reenter)(GLIContext ctx, GLshort red, GLshort green, GLshort blue);
static void (*color3sv_reenter)(GLIContext ctx, const GLshort *v);
static void (*color3ub_reenter)(GLIContext ctx, GLubyte red, GLubyte green, GLubyte blue);
static void (*color3ubv_reenter)(GLIContext ctx, const GLubyte *v);
static void (*color3ui_reenter)(GLIContext ctx, GLuint red, GLuint green, GLuint blue);
static void (*color3uiv_reenter)(GLIContext ctx, const GLuint *v);
static void (*color3us_reenter)(GLIContext ctx, GLushort red, GLushort green, GLushort blue);
static void (*color3usv_reenter)(GLIContext ctx, const GLushort *v);
static void (*color4b_reenter)(GLIContext ctx, GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha);
static void (*color4bv_reenter)(GLIContext ctx, const GLbyte *v);
static void (*color4d_reenter)(GLIContext ctx, GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha);
static void (*color4dv_reenter)(GLIContext ctx, const GLdouble *v);
static void (*color4f_reenter)(GLIContext ctx, GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
static void (*color4fv_reenter)(GLIContext ctx, const GLfloat *v);
static void (*color4i_reenter)(GLIContext ctx, GLint red, GLint green, GLint blue, GLint alpha);
static void (*color4iv_reenter)(GLIContext ctx, const GLint *v);
static void (*color4s_reenter)(GLIContext ctx, GLshort red, GLshort green, GLshort blue, GLshort alpha);
static void (*color4sv_reenter)(GLIContext ctx, const GLshort *v);
static void (*color4ub_reenter)(GLIContext ctx, GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
static void (*color4ubv_reenter)(GLIContext ctx, const GLubyte *v);
static void (*color4ui_reenter)(GLIContext ctx, GLuint red, GLuint green, GLuint blue, GLuint alpha);
static void (*color4uiv_reenter)(GLIContext ctx, const GLuint *v);
static void (*color4us_reenter)(GLIContext ctx, GLushort red, GLushort green, GLushort blue, GLushort alpha);
static void (*color4usv_reenter)(GLIContext ctx, const GLushort *v);
static void (*color_mask_reenter)(GLIContext ctx, GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
static void (*color_material_reenter)(GLIContext ctx, GLenum face, GLenum mode);
static void (*color_pointer_reenter)(GLIContext ctx, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
static void (*copy_pixels_reenter)(GLIContext ctx, GLint x, GLint y, GLsizei width, GLsizei height, GLenum type);
static void (*copy_tex_image1D_reenter)(GLIContext ctx, GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLint border);
static void (*copy_tex_image2D_reenter)(GLIContext ctx, GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
static void (*copy_tex_sub_image1D_reenter)(GLIContext ctx, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
static void (*copy_tex_sub_image2D_reenter)(GLIContext ctx, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
static void (*cull_face_reenter)(GLIContext ctx, GLenum mode);
static void (*delete_lists_reenter)(GLIContext ctx, GLuint list, GLsizei range);
static void (*delete_textures_reenter)(GLIContext ctx, GLsizei n, const GLuint *textures);
static void (*depth_func_reenter)(GLIContext ctx, GLenum func);
static void (*depth_mask_reenter)(GLIContext ctx, GLboolean flag);
static void (*depth_range_reenter)(GLIContext ctx, GLclampd zNear, GLclampd zFar);
static void (*disable_reenter)(GLIContext ctx, GLenum cap);
static void (*disable_client_state_reenter)(GLIContext ctx, GLenum array);
static void (*draw_arrays_reenter)(GLIContext ctx, GLenum mode, GLint first, GLsizei count);
static void (*draw_buffer_reenter)(GLIContext ctx, GLenum mode);
static void (*draw_elements_reenter)(GLIContext ctx, GLenum mode, GLsizei count, GLenum type, const GLvoid *indices);
static void (*draw_pixels_reenter)(GLIContext ctx, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
static void (*edge_flag_reenter)(GLIContext ctx, GLboolean flag);
static void (*edge_flag_pointer_reenter)(GLIContext ctx, GLsizei stride, const GLvoid *pointer);
static void (*edge_flagv_reenter)(GLIContext ctx, const GLboolean *flag);
static void (*enable_reenter)(GLIContext ctx, GLenum cap);
static void (*enable_client_state_reenter)(GLIContext ctx, GLenum array);
static void (*end_reenter)(GLIContext ctx);
static void (*end_list_reenter)(GLIContext ctx);
static void (*eval_coord1d_reenter)(GLIContext ctx, GLdouble u);
static void (*eval_coord1dv_reenter)(GLIContext ctx, const GLdouble *u);
static void (*eval_coord1f_reenter)(GLIContext ctx, GLfloat u);
static void (*eval_coord1fv_reenter)(GLIContext ctx, const GLfloat *u);
static void (*eval_coord2d_reenter)(GLIContext ctx, GLdouble u, GLdouble v);
static void (*eval_coord2dv_reenter)(GLIContext ctx, const GLdouble *u);
static void (*eval_coord2f_reenter)(GLIContext ctx, GLfloat u, GLfloat v);
static void (*eval_coord2fv_reenter)(GLIContext ctx, const GLfloat *u);
static void (*eval_mesh1_reenter)(GLIContext ctx, GLenum mode, GLint i1, GLint i2);
static void (*eval_mesh2_reenter)(GLIContext ctx, GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2);
static void (*eval_point1_reenter)(GLIContext ctx, GLint i);
static void (*eval_point2_reenter)(GLIContext ctx, GLint i, GLint j);
static void (*feedback_buffer_reenter)(GLIContext ctx, GLsizei size, GLenum type, GLfloat *buffer);
static void (*finish_reenter)(GLIContext ctx);
static void (*flush_reenter)(GLIContext ctx);
static void (*fogf_reenter)(GLIContext ctx, GLenum pname, GLfloat param);
static void (*fogfv_reenter)(GLIContext ctx, GLenum pname, const GLfloat *params);
static void (*fogi_reenter)(GLIContext ctx, GLenum pname, GLint param);
static void (*fogiv_reenter)(GLIContext ctx, GLenum pname, const GLint *params);
static void (*front_face_reenter)(GLIContext ctx, GLenum mode);
static void (*frustum_reenter)(GLIContext ctx, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
static GLuint (*gen_lists_reenter)(GLIContext ctx, GLsizei range);
static void (*gen_textures_reenter)(GLIContext ctx, GLsizei n, GLuint *textures);
static void (*get_booleanv_reenter)(GLIContext ctx, GLenum pname, GLboolean *params);
static void (*get_clip_plane_reenter)(GLIContext ctx, GLenum plane, GLdouble *equation);
static void (*get_doublev_reenter)(GLIContext ctx, GLenum pname, GLdouble *params);
static GLenum (*get_error_reenter)(GLIContext ctx);
static void (*get_floatv_reenter)(GLIContext ctx, GLenum pname, GLfloat *params);
static void (*get_integerv_reenter)(GLIContext ctx, GLenum pname, GLint *params);
static void (*get_lightfv_reenter)(GLIContext ctx, GLenum light, GLenum pname, GLfloat *params);
static void (*get_lightiv_reenter)(GLIContext ctx, GLenum light, GLenum pname, GLint *params);
static void (*get_mapdv_reenter)(GLIContext ctx, GLenum target, GLenum query, GLdouble *v);
static void (*get_mapfv_reenter)(GLIContext ctx, GLenum target, GLenum query, GLfloat *v);
static void (*get_mapiv_reenter)(GLIContext ctx, GLenum target, GLenum query, GLint *v);
static void (*get_materialfv_reenter)(GLIContext ctx, GLenum face, GLenum pname, GLfloat *params);
static void (*get_materialiv_reenter)(GLIContext ctx, GLenum face, GLenum pname, GLint *params);
static void (*get_pixel_mapfv_reenter)(GLIContext ctx, GLenum map, GLfloat *values);
static void (*get_pixel_mapuiv_reenter)(GLIContext ctx, GLenum map, GLuint *values);
static void (*get_pixel_mapusv_reenter)(GLIContext ctx, GLenum map, GLushort *values);
static void (*get_pointerv_reenter)(GLIContext ctx, GLenum pname, GLvoid **params);
static void (*get_polygon_stipple_reenter)(GLIContext ctx, GLubyte *mask);
static void (*get_tex_envfv_reenter)(GLIContext ctx, GLenum target, GLenum pname, GLfloat *params);
static void (*get_tex_enviv_reenter)(GLIContext ctx, GLenum target, GLenum pname, GLint *params);
static void (*get_tex_gendv_reenter)(GLIContext ctx, GLenum coord, GLenum pname, GLdouble *params);
static void (*get_tex_genfv_reenter)(GLIContext ctx, GLenum coord, GLenum pname, GLfloat *params);
static void (*get_tex_geniv_reenter)(GLIContext ctx, GLenum coord, GLenum pname, GLint *params);
static void (*get_tex_image_reenter)(GLIContext ctx, GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels);
static void (*get_tex_level_parameterfv_reenter)(GLIContext ctx, GLenum target, GLint level, GLenum pname, GLfloat *params);
static void (*get_tex_level_parameteriv_reenter)(GLIContext ctx, GLenum target, GLint level, GLenum pname, GLint *params);
static void (*get_tex_parameterfv_reenter)(GLIContext ctx, GLenum target, GLenum pname, GLfloat *params);
static void (*get_tex_parameteriv_reenter)(GLIContext ctx, GLenum target, GLenum pname, GLint *params);
static void (*hint_reenter)(GLIContext ctx, GLenum target, GLenum mode);
static void (*index_mask_reenter)(GLIContext ctx, GLuint mask);
static void (*index_pointer_reenter)(GLIContext ctx, GLenum type, GLsizei stride, const GLvoid *pointer);
static void (*indexd_reenter)(GLIContext ctx, GLdouble c);
static void (*indexdv_reenter)(GLIContext ctx, const GLdouble *c);
static void (*indexf_reenter)(GLIContext ctx, GLfloat c);
static void (*indexfv_reenter)(GLIContext ctx, const GLfloat *c);
static void (*indexi_reenter)(GLIContext ctx, GLint c);
static void (*indexiv_reenter)(GLIContext ctx, const GLint *c);
static void (*indexs_reenter)(GLIContext ctx, GLshort c);
static void (*indexsv_reenter)(GLIContext ctx, const GLshort *c);
static void (*indexub_reenter)(GLIContext ctx, GLubyte c);
static void (*indexubv_reenter)(GLIContext ctx, const GLubyte *c);
static void (*init_names_reenter)(GLIContext ctx);
static void (*interleaved_arrays_reenter)(GLIContext ctx, GLenum format, GLsizei stride, const GLvoid *pointer);
static GLboolean (*is_enabled_reenter)(GLIContext ctx, GLenum cap);
static GLboolean (*is_list_reenter)(GLIContext ctx, GLuint list);
static GLboolean (*is_texture_reenter)(GLIContext ctx, GLuint texture);
static void (*light_modelf_reenter)(GLIContext ctx, GLenum pname, GLfloat param);
static void (*light_modelfv_reenter)(GLIContext ctx, GLenum pname, const GLfloat *params);
static void (*light_modeli_reenter)(GLIContext ctx, GLenum pname, GLint param);
static void (*light_modeliv_reenter)(GLIContext ctx, GLenum pname, const GLint *params);
static void (*lightf_reenter)(GLIContext ctx, GLenum light, GLenum pname, GLfloat param);
static void (*lightfv_reenter)(GLIContext ctx, GLenum light, GLenum pname, const GLfloat *params);
static void (*lighti_reenter)(GLIContext ctx, GLenum light, GLenum pname, GLint param);
static void (*lightiv_reenter)(GLIContext ctx, GLenum light, GLenum pname, const GLint *params);
static void (*line_stipple_reenter)(GLIContext ctx, GLint factor, GLushort pattern);
static void (*line_width_reenter)(GLIContext ctx, GLfloat width);
static void (*list_base_reenter)(GLIContext ctx, GLuint base);
static void (*load_identity_reenter)(GLIContext ctx);
static void (*load_matrixd_reenter)(GLIContext ctx, const GLdouble *m);
static void (*load_matrixf_reenter)(GLIContext ctx, const GLfloat *m);
static void (*load_name_reenter)(GLIContext ctx, GLuint name);
static void (*logic_op_reenter)(GLIContext ctx, GLenum opcode);
static void (*map1d_reenter)(GLIContext ctx, GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points);
static void (*map1f_reenter)(GLIContext ctx, GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points);
static void (*map2d_reenter)(GLIContext ctx, GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points);
static void (*map2f_reenter)(GLIContext ctx, GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points);
static void (*map_grid1d_reenter)(GLIContext ctx, GLint un, GLdouble u1, GLdouble u2);
static void (*map_grid1f_reenter)(GLIContext ctx, GLint un, GLfloat u1, GLfloat u2);
static void (*map_grid2d_reenter)(GLIContext ctx, GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2);
static void (*map_grid2f_reenter)(GLIContext ctx, GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2);
static void (*materialf_reenter)(GLIContext ctx, GLenum face, GLenum pname, GLfloat param);
static void (*materialfv_reenter)(GLIContext ctx, GLenum face, GLenum pname, const GLfloat *params);
static void (*materiali_reenter)(GLIContext ctx, GLenum face, GLenum pname, GLint param);
static void (*materialiv_reenter)(GLIContext ctx, GLenum face, GLenum pname, const GLint *params);
static void (*matrix_mode_reenter)(GLIContext ctx, GLenum mode);
static void (*mult_matrixd_reenter)(GLIContext ctx, const GLdouble *m);
static void (*mult_matrixf_reenter)(GLIContext ctx, const GLfloat *m);
static void (*new_list_reenter)(GLIContext ctx, GLuint list, GLenum mode);
static void (*normal3b_reenter)(GLIContext ctx, GLbyte nx, GLbyte ny, GLbyte nz);
static void (*normal3bv_reenter)(GLIContext ctx, const GLbyte *v);
static void (*normal3d_reenter)(GLIContext ctx, GLdouble nx, GLdouble ny, GLdouble nz);
static void (*normal3dv_reenter)(GLIContext ctx, const GLdouble *v);
static void (*normal3f_reenter)(GLIContext ctx, GLfloat nx, GLfloat ny, GLfloat nz);
static void (*normal3fv_reenter)(GLIContext ctx, const GLfloat *v);
static void (*normal3i_reenter)(GLIContext ctx, GLint nx, GLint ny, GLint nz);
static void (*normal3iv_reenter)(GLIContext ctx, const GLint *v);
static void (*normal3s_reenter)(GLIContext ctx, GLshort nx, GLshort ny, GLshort nz);
static void (*normal3sv_reenter)(GLIContext ctx, const GLshort *v);
static void (*normal_pointer_reenter)(GLIContext ctx, GLenum type, GLsizei stride, const GLvoid *pointer);
static void (*ortho_reenter)(GLIContext ctx, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
static void (*pass_through_reenter)(GLIContext ctx, GLfloat token);
static void (*pixel_mapfv_reenter)(GLIContext ctx, GLenum map, GLsizei mapsize, const GLfloat *values);
static void (*pixel_mapuiv_reenter)(GLIContext ctx, GLenum map, GLsizei mapsize, const GLuint *values);
static void (*pixel_mapusv_reenter)(GLIContext ctx, GLenum map, GLsizei mapsize, const GLushort *values);
static void (*pixel_storef_reenter)(GLIContext ctx, GLenum pname, GLfloat param);
static void (*pixel_storei_reenter)(GLIContext ctx, GLenum pname, GLint param);
static void (*pixel_transferf_reenter)(GLIContext ctx, GLenum pname, GLfloat param);
static void (*pixel_transferi_reenter)(GLIContext ctx, GLenum pname, GLint param);
static void (*pixel_zoom_reenter)(GLIContext ctx, GLfloat xfactor, GLfloat yfactor);
static void (*point_size_reenter)(GLIContext ctx, GLfloat size);
static void (*polygon_mode_reenter)(GLIContext ctx, GLenum face, GLenum mode);
static void (*polygon_offset_reenter)(GLIContext ctx, GLfloat factor, GLfloat units);
static void (*polygon_stipple_reenter)(GLIContext ctx, const GLubyte *mask);
static void (*pop_attrib_reenter)(GLIContext ctx);
static void (*pop_client_attrib_reenter)(GLIContext ctx);
static void (*pop_matrix_reenter)(GLIContext ctx);
static void (*pop_name_reenter)(GLIContext ctx);
static void (*prioritize_textures_reenter)(GLIContext ctx, GLsizei n, const GLuint *textures, const GLclampf *priorities);
static void (*push_attrib_reenter)(GLIContext ctx, GLbitfield mask);
static void (*push_client_attrib_reenter)(GLIContext ctx, GLbitfield mask);
static void (*push_matrix_reenter)(GLIContext ctx);
static void (*push_name_reenter)(GLIContext ctx, GLuint name);
static void (*raster_pos2d_reenter)(GLIContext ctx, GLdouble x, GLdouble y);
static void (*raster_pos2dv_reenter)(GLIContext ctx, const GLdouble *v);
static void (*raster_pos2f_reenter)(GLIContext ctx, GLfloat x, GLfloat y);
static void (*raster_pos2fv_reenter)(GLIContext ctx, const GLfloat *v);
static void (*raster_pos2i_reenter)(GLIContext ctx, GLint x, GLint y);
static void (*raster_pos2iv_reenter)(GLIContext ctx, const GLint *v);
static void (*raster_pos2s_reenter)(GLIContext ctx, GLshort x, GLshort y);
static void (*raster_pos2sv_reenter)(GLIContext ctx, const GLshort *v);
static void (*raster_pos3d_reenter)(GLIContext ctx, GLdouble x, GLdouble y, GLdouble z);
static void (*raster_pos3dv_reenter)(GLIContext ctx, const GLdouble *v);
static void (*raster_pos3f_reenter)(GLIContext ctx, GLfloat x, GLfloat y, GLfloat z);
static void (*raster_pos3fv_reenter)(GLIContext ctx, const GLfloat *v);
static void (*raster_pos3i_reenter)(GLIContext ctx, GLint x, GLint y, GLint z);
static void (*raster_pos3iv_reenter)(GLIContext ctx, const GLint *v);
static void (*raster_pos3s_reenter)(GLIContext ctx, GLshort x, GLshort y, GLshort z);
static void (*raster_pos3sv_reenter)(GLIContext ctx, const GLshort *v);
static void (*raster_pos4d_reenter)(GLIContext ctx, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
static void (*raster_pos4dv_reenter)(GLIContext ctx, const GLdouble *v);
static void (*raster_pos4f_reenter)(GLIContext ctx, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
static void (*raster_pos4fv_reenter)(GLIContext ctx, const GLfloat *v);
static void (*raster_pos4i_reenter)(GLIContext ctx, GLint x, GLint y, GLint z, GLint w);
static void (*raster_pos4iv_reenter)(GLIContext ctx, const GLint *v);
static void (*raster_pos4s_reenter)(GLIContext ctx, GLshort x, GLshort y, GLshort z, GLshort w);
static void (*raster_pos4sv_reenter)(GLIContext ctx, const GLshort *v);
static void (*read_buffer_reenter)(GLIContext ctx, GLenum mode);
static void (*read_pixels_reenter)(GLIContext ctx, GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels);
static void (*rectd_reenter)(GLIContext ctx, GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2);
static void (*rectdv_reenter)(GLIContext ctx, const GLdouble *v1, const GLdouble *v2);
static void (*rectf_reenter)(GLIContext ctx, GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
static void (*rectfv_reenter)(GLIContext ctx, const GLfloat *v1, const GLfloat *v2);
static void (*recti_reenter)(GLIContext ctx, GLint x1, GLint y1, GLint x2, GLint y2);
static void (*rectiv_reenter)(GLIContext ctx, const GLint *v1, const GLint *v2);
static void (*rects_reenter)(GLIContext ctx, GLshort x1, GLshort y1, GLshort x2, GLshort y2);
static void (*rectsv_reenter)(GLIContext ctx, const GLshort *v1, const GLshort *v2);
static GLint (*render_mode_reenter)(GLIContext ctx, GLenum mode);
static void (*rotated_reenter)(GLIContext ctx, GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
static void (*rotatef_reenter)(GLIContext ctx, GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
static void (*scaled_reenter)(GLIContext ctx, GLdouble x, GLdouble y, GLdouble z);
static void (*scalef_reenter)(GLIContext ctx, GLfloat x, GLfloat y, GLfloat z);
static void (*scissor_reenter)(GLIContext ctx, GLint x, GLint y, GLsizei width, GLsizei height);
static void (*select_buffer_reenter)(GLIContext ctx, GLsizei size, GLuint *buffer);
static void (*shade_model_reenter)(GLIContext ctx, GLenum mode);
static void (*stencil_func_reenter)(GLIContext ctx, GLenum func, GLint ref, GLuint mask);
static void (*stencil_mask_reenter)(GLIContext ctx, GLuint mask);
static void (*stencil_op_reenter)(GLIContext ctx, GLenum fail, GLenum zfail, GLenum zpass);
static void (*tex_coord1d_reenter)(GLIContext ctx, GLdouble s);
static void (*tex_coord1dv_reenter)(GLIContext ctx, const GLdouble *v);
static void (*tex_coord1f_reenter)(GLIContext ctx, GLfloat s);
static void (*tex_coord1fv_reenter)(GLIContext ctx, const GLfloat *v);
static void (*tex_coord1i_reenter)(GLIContext ctx, GLint s);
static void (*tex_coord1iv_reenter)(GLIContext ctx, const GLint *v);
static void (*tex_coord1s_reenter)(GLIContext ctx, GLshort s);
static void (*tex_coord1sv_reenter)(GLIContext ctx, const GLshort *v);
static void (*tex_coord2d_reenter)(GLIContext ctx, GLdouble s, GLdouble t);
static void (*tex_coord2dv_reenter)(GLIContext ctx, const GLdouble *v);
static void (*tex_coord2f_reenter)(GLIContext ctx, GLfloat s, GLfloat t);
static void (*tex_coord2fv_reenter)(GLIContext ctx, const GLfloat *v);
static void (*tex_coord2i_reenter)(GLIContext ctx, GLint s, GLint t);
static void (*tex_coord2iv_reenter)(GLIContext ctx, const GLint *v);
static void (*tex_coord2s_reenter)(GLIContext ctx, GLshort s, GLshort t);
static void (*tex_coord2sv_reenter)(GLIContext ctx, const GLshort *v);
static void (*tex_coord3d_reenter)(GLIContext ctx, GLdouble s, GLdouble t, GLdouble r);
static void (*tex_coord3dv_reenter)(GLIContext ctx, const GLdouble *v);
static void (*tex_coord3f_reenter)(GLIContext ctx, GLfloat s, GLfloat t, GLfloat r);
static void (*tex_coord3fv_reenter)(GLIContext ctx, const GLfloat *v);
static void (*tex_coord3i_reenter)(GLIContext ctx, GLint s, GLint t, GLint r);
static void (*tex_coord3iv_reenter)(GLIContext ctx, const GLint *v);
static void (*tex_coord3s_reenter)(GLIContext ctx, GLshort s, GLshort t, GLshort r);
static void (*tex_coord3sv_reenter)(GLIContext ctx, const GLshort *v);
static void (*tex_coord4d_reenter)(GLIContext ctx, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
static void (*tex_coord4dv_reenter)(GLIContext ctx, const GLdouble *v);
static void (*tex_coord4f_reenter)(GLIContext ctx, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
static void (*tex_coord4fv_reenter)(GLIContext ctx, const GLfloat *v);
static void (*tex_coord4i_reenter)(GLIContext ctx, GLint s, GLint t, GLint r, GLint q);
static void (*tex_coord4iv_reenter)(GLIContext ctx, const GLint *v);
static void (*tex_coord4s_reenter)(GLIContext ctx, GLshort s, GLshort t, GLshort r, GLshort q);
static void (*tex_coord4sv_reenter)(GLIContext ctx, const GLshort *v);
static void (*tex_coord_pointer_reenter)(GLIContext ctx, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
static void (*tex_envf_reenter)(GLIContext ctx, GLenum target, GLenum pname, GLfloat param);
static void (*tex_envfv_reenter)(GLIContext ctx, GLenum target, GLenum pname, const GLfloat *params);
static void (*tex_envi_reenter)(GLIContext ctx, GLenum target, GLenum pname, GLint param);
static void (*tex_enviv_reenter)(GLIContext ctx, GLenum target, GLenum pname, const GLint *params);
static void (*tex_gend_reenter)(GLIContext ctx, GLenum coord, GLenum pname, GLdouble param);
static void (*tex_gendv_reenter)(GLIContext ctx, GLenum coord, GLenum pname, const GLdouble *params);
static void (*tex_genf_reenter)(GLIContext ctx, GLenum coord, GLenum pname, GLfloat param);
static void (*tex_genfv_reenter)(GLIContext ctx, GLenum coord, GLenum pname, const GLfloat *params);
static void (*tex_geni_reenter)(GLIContext ctx, GLenum coord, GLenum pname, GLint param);
static void (*tex_geniv_reenter)(GLIContext ctx, GLenum coord, GLenum pname, const GLint *params);
static void (*tex_image1D_reenter)(GLIContext ctx, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
static void (*tex_image2D_reenter)(GLIContext ctx, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
static void (*tex_parameterf_reenter)(GLIContext ctx, GLenum target, GLenum pname, GLfloat param);
static void (*tex_parameterfv_reenter)(GLIContext ctx, GLenum target, GLenum pname, const GLfloat *params);
static void (*tex_parameteri_reenter)(GLIContext ctx, GLenum target, GLenum pname, GLint param);
static void (*tex_parameteriv_reenter)(GLIContext ctx, GLenum target, GLenum pname, const GLint *params);
static void (*tex_sub_image1D_reenter)(GLIContext ctx, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels);
static void (*tex_sub_image2D_reenter)(GLIContext ctx, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
static void (*translated_reenter)(GLIContext ctx, GLdouble x, GLdouble y, GLdouble z);
static void (*translatef_reenter)(GLIContext ctx, GLfloat x, GLfloat y, GLfloat z);
static void (*vertex2d_reenter)(GLIContext ctx, GLdouble x, GLdouble y);
static void (*vertex2dv_reenter)(GLIContext ctx, const GLdouble *v);
static void (*vertex2f_reenter)(GLIContext ctx, GLfloat x, GLfloat y);
static void (*vertex2fv_reenter)(GLIContext ctx, const GLfloat *v);
static void (*vertex2i_reenter)(GLIContext ctx, GLint x, GLint y);
static void (*vertex2iv_reenter)(GLIContext ctx, const GLint *v);
static void (*vertex2s_reenter)(GLIContext ctx, GLshort x, GLshort y);
static void (*vertex2sv_reenter)(GLIContext ctx, const GLshort *v);
static void (*vertex3d_reenter)(GLIContext ctx, GLdouble x, GLdouble y, GLdouble z);
static void (*vertex3dv_reenter)(GLIContext ctx, const GLdouble *v);
static void (*vertex3f_reenter)(GLIContext ctx, GLfloat x, GLfloat y, GLfloat z);
static void (*vertex3fv_reenter)(GLIContext ctx, const GLfloat *v);
static void (*vertex3i_reenter)(GLIContext ctx, GLint x, GLint y, GLint z);
static void (*vertex3iv_reenter)(GLIContext ctx, const GLint *v);
static void (*vertex3s_reenter)(GLIContext ctx, GLshort x, GLshort y, GLshort z);
static void (*vertex3sv_reenter)(GLIContext ctx, const GLshort *v);
static void (*vertex4d_reenter)(GLIContext ctx, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
static void (*vertex4dv_reenter)(GLIContext ctx, const GLdouble *v);
static void (*vertex4f_reenter)(GLIContext ctx, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
static void (*vertex4fv_reenter)(GLIContext ctx, const GLfloat *v);
static void (*vertex4i_reenter)(GLIContext ctx, GLint x, GLint y, GLint z, GLint w);
static void (*vertex4iv_reenter)(GLIContext ctx, const GLint *v);
static void (*vertex4s_reenter)(GLIContext ctx, GLshort x, GLshort y, GLshort z, GLshort w);
static void (*vertex4sv_reenter)(GLIContext ctx, const GLshort *v);
static void (*vertex_pointer_reenter)(GLIContext ctx, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
static void (*viewport_reenter)(GLIContext ctx, GLint x, GLint y, GLsizei width, GLsizei height);
static void (*blend_func_separate_reenter)(GLIContext ctx, GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
static void (*blend_color_reenter)(GLIContext ctx, GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
static void (*blend_equation_reenter)(GLIContext ctx, GLenum mode);
static void (*lock_arrays_EXT_reenter)(GLIContext ctx, GLint first, GLsizei count);
static void (*unlock_arrays_EXT_reenter)(GLIContext ctx);
static void (*client_active_texture_reenter)(GLIContext ctx, GLenum target);
static void (*active_texture_reenter)(GLIContext ctx, GLenum target);
static void (*multi_tex_coord1d_reenter)(GLIContext ctx, GLenum target, GLdouble s);
static void (*multi_tex_coord1dv_reenter)(GLIContext ctx, GLenum target, const GLdouble *v);
static void (*multi_tex_coord1f_reenter)(GLIContext ctx, GLenum target, GLfloat s);
static void (*multi_tex_coord1fv_reenter)(GLIContext ctx, GLenum target, const GLfloat *v);
static void (*multi_tex_coord1i_reenter)(GLIContext ctx, GLenum target, GLint s);
static void (*multi_tex_coord1iv_reenter)(GLIContext ctx, GLenum target, const GLint *v);
static void (*multi_tex_coord1s_reenter)(GLIContext ctx, GLenum target, GLshort s);
static void (*multi_tex_coord1sv_reenter)(GLIContext ctx, GLenum target, const GLshort *v);
static void (*multi_tex_coord2d_reenter)(GLIContext ctx, GLenum target, GLdouble s, GLdouble t);
static void (*multi_tex_coord2dv_reenter)(GLIContext ctx, GLenum target, const GLdouble *v);
static void (*multi_tex_coord2f_reenter)(GLIContext ctx, GLenum target, GLfloat s, GLfloat t);
static void (*multi_tex_coord2fv_reenter)(GLIContext ctx, GLenum target, const GLfloat *v);
static void (*multi_tex_coord2i_reenter)(GLIContext ctx, GLenum target, GLint s, GLint t);
static void (*multi_tex_coord2iv_reenter)(GLIContext ctx, GLenum target, const GLint *v);
static void (*multi_tex_coord2s_reenter)(GLIContext ctx, GLenum target, GLshort s, GLshort t);
static void (*multi_tex_coord2sv_reenter)(GLIContext ctx, GLenum target, const GLshort *v);
static void (*multi_tex_coord3d_reenter)(GLIContext ctx, GLenum target, GLdouble s, GLdouble t, GLdouble r);
static void (*multi_tex_coord3dv_reenter)(GLIContext ctx, GLenum target, const GLdouble *v);
static void (*multi_tex_coord3f_reenter)(GLIContext ctx, GLenum target, GLfloat s, GLfloat t, GLfloat r);
static void (*multi_tex_coord3fv_reenter)(GLIContext ctx, GLenum target, const GLfloat *v);
static void (*multi_tex_coord3i_reenter)(GLIContext ctx, GLenum target, GLint s, GLint t, GLint r);
static void (*multi_tex_coord3iv_reenter)(GLIContext ctx, GLenum target, const GLint *v);
static void (*multi_tex_coord3s_reenter)(GLIContext ctx, GLenum target, GLshort s, GLshort t, GLshort r);
static void (*multi_tex_coord3sv_reenter)(GLIContext ctx, GLenum target, const GLshort *v);
static void (*multi_tex_coord4d_reenter)(GLIContext ctx, GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
static void (*multi_tex_coord4dv_reenter)(GLIContext ctx, GLenum target, const GLdouble *v);
static void (*multi_tex_coord4f_reenter)(GLIContext ctx, GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
static void (*multi_tex_coord4fv_reenter)(GLIContext ctx, GLenum target, const GLfloat *v);
static void (*multi_tex_coord4i_reenter)(GLIContext ctx, GLenum target, GLint s, GLint t, GLint r, GLint q);
static void (*multi_tex_coord4iv_reenter)(GLIContext ctx, GLenum target, const GLint *v);
static void (*multi_tex_coord4s_reenter)(GLIContext ctx, GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
static void (*multi_tex_coord4sv_reenter)(GLIContext ctx, GLenum target, const GLshort *v);
static void (*load_transpose_matrixd_reenter)(GLIContext ctx, const GLdouble *m);
static void (*load_transpose_matrixf_reenter)(GLIContext ctx, const GLfloat *m);
static void (*mult_transpose_matrixd_reenter)(GLIContext ctx, const GLdouble *m);
static void (*mult_transpose_matrixf_reenter)(GLIContext ctx, const GLfloat *m);
static void (*compressed_tex_image3D_reenter)(GLIContext ctx, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *data);
static void (*compressed_tex_image2D_reenter)(GLIContext ctx, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data);
static void (*compressed_tex_image1D_reenter)(GLIContext ctx, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data);
static void (*compressed_tex_sub_image3D_reenter)(GLIContext ctx, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data);
static void (*compressed_tex_sub_image2D_reenter)(GLIContext ctx, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data);
static void (*compressed_tex_sub_image1D_reenter)(GLIContext ctx, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data);
static void (*get_compressed_tex_image_reenter)(GLIContext ctx, GLenum target, GLint level, GLvoid *img);
static void (*secondary_color3b_reenter)(GLIContext ctx, GLbyte red, GLbyte green, GLbyte blue);
static void (*secondary_color3bv_reenter)(GLIContext ctx, const GLbyte *v);
static void (*secondary_color3d_reenter)(GLIContext ctx, GLdouble red, GLdouble green, GLdouble blue);
static void (*secondary_color3dv_reenter)(GLIContext ctx, const GLdouble *v);
static void (*secondary_color3f_reenter)(GLIContext ctx, GLfloat red, GLfloat green, GLfloat blue);
static void (*secondary_color3fv_reenter)(GLIContext ctx, const GLfloat *v);
static void (*secondary_color3i_reenter)(GLIContext ctx, GLint red, GLint green, GLint blue);
static void (*secondary_color3iv_reenter)(GLIContext ctx, const GLint *v);
static void (*secondary_color3s_reenter)(GLIContext ctx, GLshort red, GLshort green, GLshort blue);
static void (*secondary_color3sv_reenter)(GLIContext ctx, const GLshort *v);
static void (*secondary_color3ub_reenter)(GLIContext ctx, GLubyte red, GLubyte green, GLubyte blue);
static void (*secondary_color3ubv_reenter)(GLIContext ctx, const GLubyte *v);
static void (*secondary_color3ui_reenter)(GLIContext ctx, GLuint red, GLuint green, GLuint blue);
static void (*secondary_color3uiv_reenter)(GLIContext ctx, const GLuint *v);
static void (*secondary_color3us_reenter)(GLIContext ctx, GLushort red, GLushort green, GLushort blue);
static void (*secondary_color3usv_reenter)(GLIContext ctx, const GLushort *v);
static void (*secondary_color_pointer_reenter)(GLIContext ctx, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
static void (*vertex_array_range_EXT_reenter)(GLIContext ctx, GLsizei count, const GLvoid *pointer);
static void (*flush_vertex_array_range_EXT_reenter)(GLIContext ctx, GLsizei count, const GLvoid *pointer);
static void (*draw_range_elements_reenter)(GLIContext ctx, GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices);
static void (*color_table_reenter)(GLIContext ctx, GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *table);
static void (*color_table_parameterfv_reenter)(GLIContext ctx, GLenum target, GLenum pname, const GLfloat *params);
static void (*color_table_parameteriv_reenter)(GLIContext ctx, GLenum target, GLenum pname, const GLint *params);
static void (*copy_color_table_reenter)(GLIContext ctx, GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
static void (*get_color_table_reenter)(GLIContext ctx, GLenum target, GLenum format, GLenum type, GLvoid *table);
static void (*get_color_table_parameterfv_reenter)(GLIContext ctx, GLenum target, GLenum pname, GLfloat *params);
static void (*get_color_table_parameteriv_reenter)(GLIContext ctx, GLenum target, GLenum pname, GLint *params);
static void (*color_sub_table_reenter)(GLIContext ctx, GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const GLvoid *data);
static void (*copy_color_sub_table_reenter)(GLIContext ctx, GLenum target, GLsizei start, GLint x, GLint y, GLsizei width);
static void (*convolution_filter1D_reenter)(GLIContext ctx, GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *image);
static void (*convolution_filter2D_reenter)(GLIContext ctx, GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *image);
static void (*convolution_parameterf_reenter)(GLIContext ctx, GLenum target, GLenum pname, GLfloat params);
static void (*convolution_parameterfv_reenter)(GLIContext ctx, GLenum target, GLenum pname, const GLfloat *params);
static void (*convolution_parameteri_reenter)(GLIContext ctx, GLenum target, GLenum pname, GLint params);
static void (*convolution_parameteriv_reenter)(GLIContext ctx, GLenum target, GLenum pname, const GLint *params);
static void (*copy_convolution_filter1D_reenter)(GLIContext ctx, GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
static void (*copy_convolution_filter2D_reenter)(GLIContext ctx, GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height);
static void (*get_convolution_filter_reenter)(GLIContext ctx, GLenum target, GLenum format, GLenum type, GLvoid *image);
static void (*get_convolution_parameterfv_reenter)(GLIContext ctx, GLenum target, GLenum pname, GLfloat *params);
static void (*get_convolution_parameteriv_reenter)(GLIContext ctx, GLenum target, GLenum pname, GLint *params);
static void (*get_separable_filter_reenter)(GLIContext ctx, GLenum target, GLenum format, GLenum type, GLvoid *row, GLvoid *column, GLvoid *span);
static void (*separable_filter2D_reenter)(GLIContext ctx, GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *row, const GLvoid *column);
static void (*get_histogram_reenter)(GLIContext ctx, GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid *values);
static void (*get_histogram_parameterfv_reenter)(GLIContext ctx, GLenum target, GLenum pname, GLfloat *params);
static void (*get_histogram_parameteriv_reenter)(GLIContext ctx, GLenum target, GLenum pname, GLint *params);
static void (*get_minmax_reenter)(GLIContext ctx, GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid *values);
static void (*get_minmax_parameterfv_reenter)(GLIContext ctx, GLenum target, GLenum pname, GLfloat *params);
static void (*get_minmax_parameteriv_reenter)(GLIContext ctx, GLenum target, GLenum pname, GLint *params);
static void (*histogram_reenter)(GLIContext ctx, GLenum target, GLsizei width, GLenum internalformat, GLboolean sink);
static void (*minmax_reenter)(GLIContext ctx, GLenum target, GLenum internalformat, GLboolean sink);
static void (*reset_histogram_reenter)(GLIContext ctx, GLenum target);
static void (*reset_minmax_reenter)(GLIContext ctx, GLenum target);
static void (*tex_image3D_reenter)(GLIContext ctx, GLenum target, GLint level, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
static void (*tex_sub_image3D_reenter)(GLIContext ctx, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels);
static void (*copy_tex_sub_image3D_reenter)(GLIContext ctx, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
static void (*get_uniform_indices_reenter)((GLIContext ctx, GLuint program, GLsizei uniformCount, const GLchar* const *uniformNames, GLuint* uniformIndices);
static void (*get_active_uniformsiv_reenter)((GLIContext ctx, GLuint program, GLsizei uniformCount, const GLuint* uniformIndices, GLenum pname, GLint* params);
static void (*get_active_uniform_name_reenter)((GLIContext ctx, GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformName);
static GLuint (*get_uniform_block_index_reenter)((GLIContext ctx, GLuint program, const GLchar* uniformBlockName);
static void (*get_active_uniform_blockiv_reenter)((GLIContext ctx, GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint* params);
static void (*get_active_uniform_block_name_reenter)((GLIContext ctx, GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformBlockName);
static void (*uniform_block_binding_reenter)((GLIContext ctx, GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
static void (*get_combiner_input_parameterfv_NV_reenter)(GLIContext ctx, GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLfloat *params);
static void (*get_combiner_input_parameteriv_NV_reenter)(GLIContext ctx, GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLint *params);
static void (*get_combiner_output_parameterfv_NV_reenter)(GLIContext ctx, GLenum stage, GLenum portion, GLenum pname, GLfloat *params);
static void (*get_combiner_output_parameteriv_NV_reenter)(GLIContext ctx, GLenum stage, GLenum portion, GLenum pname, GLint *params);
static void (*get_final_combiner_input_parameterfv_NV_reenter)(GLIContext ctx, GLenum variable, GLenum pname, GLfloat *params);
static void (*get_final_combiner_input_parameteriv_NV_reenter)(GLIContext ctx, GLenum variable, GLenum pname, GLint *params);
static void (*combiner_stage_parameterfv_NV_reenter)(GLIContext ctx, GLenum stage, GLenum pname, const GLfloat *params);
static void (*get_combiner_stage_parameterfv_NV_reenter)(GLIContext ctx, GLenum stage, GLenum pname, GLfloat *params);
static void (*texture_range_APPLE_reenter)(GLIContext ctx, GLenum target, GLsizei length, const GLvoid *pointer);
static void (*get_tex_parameter_pointerv_APPLE_reenter)(GLIContext ctx, GLenum target, GLenum pname, GLvoid **params);
static void (*blend_equation_separate_EXT_reenter)(GLIContext ctx, GLenum equationRGB, GLenum equationAlpha);
static void (*sample_coverage_reenter)(GLIContext ctx, GLclampf value, GLboolean invert);
static void (*sample_pass_reenter)(GLIContext ctx, GLenum mode);
static void (*pn_trianglesi_ATI_reenter)(GLIContext ctx, GLenum pname, GLint param);
static void (*pn_trianglesf_ATI_reenter)(GLIContext ctx, GLenum pname, GLfloat param);
static void (*gen_fences_APPLE_reenter)(GLIContext ctx, GLsizei n, GLuint *fences);
static void (*delete_fences_APPLE_reenter)(GLIContext ctx, GLsizei n, const GLuint *fences);
static void (*set_fence_APPLE_reenter)(GLIContext ctx, GLuint fence);
static GLboolean (*is_fence_APPLE_reenter)(GLIContext ctx, GLuint fence);
static GLboolean (*test_fence_APPLE_reenter)(GLIContext ctx, GLuint fence);
static void (*finish_fence_APPLE_reenter)(GLIContext ctx, GLuint fence);
static GLboolean (*test_object_APPLE_reenter)(GLIContext ctx, GLenum object, GLuint name);
static void (*finish_object_APPLE_reenter)(GLIContext ctx, GLenum object, GLuint name);
static void (*bind_program_ARB_reenter)(GLIContext ctx, GLenum target, GLuint program);
static void (*delete_programs_ARB_reenter)(GLIContext ctx, GLsizei n, const GLuint *programs);
static void (*gen_programs_ARB_reenter)(GLIContext ctx, GLsizei n, GLuint *programs);
static GLboolean (*is_program_ARB_reenter)(GLIContext ctx, GLuint program);
static void (*vertex_attrib1s_ARB_reenter)(GLIContext ctx, GLuint index, GLshort x);
static void (*vertex_attrib1f_ARB_reenter)(GLIContext ctx, GLuint index, GLfloat x);
static void (*vertex_attrib1d_ARB_reenter)(GLIContext ctx, GLuint index, GLdouble x);
static void (*vertex_attrib2s_ARB_reenter)(GLIContext ctx, GLuint index, GLshort x, GLshort y);
static void (*vertex_attrib2f_ARB_reenter)(GLIContext ctx, GLuint index, GLfloat x, GLfloat y);
static void (*vertex_attrib2d_ARB_reenter)(GLIContext ctx, GLuint index, GLdouble x, GLdouble y);
static void (*vertex_attrib3s_ARB_reenter)(GLIContext ctx, GLuint index, GLshort x, GLshort y, GLshort z);
static void (*vertex_attrib3f_ARB_reenter)(GLIContext ctx, GLuint index, GLfloat x, GLfloat y, GLfloat z);
static void (*vertex_attrib3d_ARB_reenter)(GLIContext ctx, GLuint index, GLdouble x, GLdouble y, GLdouble z);
static void (*vertex_attrib4s_ARB_reenter)(GLIContext ctx, GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
static void (*vertex_attrib4f_ARB_reenter)(GLIContext ctx, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
static void (*vertex_attrib4d_ARB_reenter)(GLIContext ctx, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
static void (*vertex_attrib4Nub_ARB_reenter)(GLIContext ctx, GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
static void (*vertex_attrib1sv_ARB_reenter)(GLIContext ctx, GLuint index, const GLshort *v);
static void (*vertex_attrib1fv_ARB_reenter)(GLIContext ctx, GLuint index, const GLfloat *v);
static void (*vertex_attrib1dv_ARB_reenter)(GLIContext ctx, GLuint index, const GLdouble *v);
static void (*vertex_attrib2sv_ARB_reenter)(GLIContext ctx, GLuint index, const GLshort *v);
static void (*vertex_attrib2fv_ARB_reenter)(GLIContext ctx, GLuint index, const GLfloat *v);
static void (*vertex_attrib2dv_ARB_reenter)(GLIContext ctx, GLuint index, const GLdouble *v);
static void (*vertex_attrib3sv_ARB_reenter)(GLIContext ctx, GLuint index, const GLshort *v);
static void (*vertex_attrib3fv_ARB_reenter)(GLIContext ctx, GLuint index, const GLfloat *v);
static void (*vertex_attrib3dv_ARB_reenter)(GLIContext ctx, GLuint index, const GLdouble *v);
static void (*vertex_attrib4bv_ARB_reenter)(GLIContext ctx, GLuint index, const GLbyte *v);
static void (*vertex_attrib4sv_ARB_reenter)(GLIContext ctx, GLuint index, const GLshort *v);
static void (*vertex_attrib4iv_ARB_reenter)(GLIContext ctx, GLuint index, const GLint *v);
static void (*vertex_attrib4ubv_ARB_reenter)(GLIContext ctx, GLuint index, const GLubyte *v);
static void (*vertex_attrib4usv_ARB_reenter)(GLIContext ctx, GLuint index, const GLushort *v);
static void (*vertex_attrib4uiv_ARB_reenter)(GLIContext ctx, GLuint index, const GLuint *v);
static void (*vertex_attrib4fv_ARB_reenter)(GLIContext ctx, GLuint index, const GLfloat *v);
static void (*vertex_attrib4dv_ARB_reenter)(GLIContext ctx, GLuint index, const GLdouble *v);
static void (*vertex_attrib4Nbv_ARB_reenter)(GLIContext ctx, GLuint index, const GLbyte *v);
static void (*vertex_attrib4Nsv_ARB_reenter)(GLIContext ctx, GLuint index, const GLshort *v);
static void (*vertex_attrib4Niv_ARB_reenter)(GLIContext ctx, GLuint index, const GLint *v);
static void (*vertex_attrib4Nubv_ARB_reenter)(GLIContext ctx, GLuint index, const GLubyte *v);
static void (*vertex_attrib4Nusv_ARB_reenter)(GLIContext ctx, GLuint index, const GLushort *v);
static void (*vertex_attrib4Nuiv_ARB_reenter)(GLIContext ctx, GLuint index, const GLuint *v);
static void (*vertex_attrib_pointer_ARB_reenter)(GLIContext ctx, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid *pointer);
static void (*enable_vertex_attrib_array_ARB_reenter)(GLIContext ctx, GLuint index);
static void (*disable_vertex_attrib_array_ARB_reenter)(GLIContext ctx, GLuint index);
static void (*get_vertex_attribdv_ARB_reenter)(GLIContext ctx, GLuint index, GLenum pname, GLdouble *params);
static void (*get_vertex_attribfv_ARB_reenter)(GLIContext ctx, GLuint index, GLenum pname, GLfloat *params);
static void (*get_vertex_attribiv_ARB_reenter)(GLIContext ctx, GLuint index, GLenum pname, GLint *params);
static void (*get_vertex_attrib_pointerv_ARB_reenter)(GLIContext ctx, GLuint index, GLenum pname, GLvoid **pointer);
static void (*program_env_parameter4d_ARB_reenter)(GLIContext ctx, GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
static void (*program_env_parameter4dv_ARB_reenter)(GLIContext ctx, GLenum target, GLuint index, const GLdouble *params);
static void (*program_env_parameter4f_ARB_reenter)(GLIContext ctx, GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
static void (*program_env_parameter4fv_ARB_reenter)(GLIContext ctx, GLenum target, GLuint index, const GLfloat *params);
static void (*program_local_parameter4d_ARB_reenter)(GLIContext ctx, GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
static void (*program_local_parameter4dv_ARB_reenter)(GLIContext ctx, GLenum target, GLuint index, const GLdouble *params);
static void (*program_local_parameter4f_ARB_reenter)(GLIContext ctx, GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
static void (*program_local_parameter4fv_ARB_reenter)(GLIContext ctx, GLenum target, GLuint index, const GLfloat *params);
static void (*get_program_env_parameterdv_ARB_reenter)(GLIContext ctx, GLenum target, GLuint index, GLdouble *params);
static void (*get_program_env_parameterfv_ARB_reenter)(GLIContext ctx, GLenum target, GLuint index, GLfloat *params);
static void (*get_program_local_parameterdv_ARB_reenter)(GLIContext ctx, GLenum target, GLuint index, GLdouble *params);
static void (*get_program_local_parameterfv_ARB_reenter)(GLIContext ctx, GLenum target, GLuint index, GLfloat *params);
static void (*program_string_ARB_reenter)(GLIContext ctx, GLenum target, GLenum format, GLsizei len, const GLvoid* string);
static void (*get_program_string_ARB_reenter)(GLIContext ctx, GLenum target, GLenum pname, GLvoid *string);
static void (*get_programiv_ARB_reenter)(GLIContext ctx, GLenum target, GLenum pname, GLint *params);
static void (*enable_vertex_attrib_ARB_reenter)(GLIContext ctx, GLuint index, GLenum pname);
static void (*disable_vertex_attrib_ARB_reenter)(GLIContext ctx, GLuint index, GLenum pname);
static GLboolean (*is_vertex_attrib_enabled_ARB_reenter)(GLIContext ctx, GLuint index, GLenum pname);
static void (*map_vertex_attrib1d_ARB_reenter)(GLIContext ctx, GLuint index, GLuint size, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points);
static void (*map_vertex_attrib1f_ARB_reenter)(GLIContext ctx, GLuint index, GLuint size, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points);
static void (*map_vertex_attrib2d_ARB_reenter)(GLIContext ctx, GLuint index, GLuint size, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points);
static void (*map_vertex_attrib2f_ARB_reenter)(GLIContext ctx, GLuint index, GLuint size, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points);
static void (*point_parameterf_reenter)(GLIContext ctx, GLenum pname, GLfloat param);
static void (*point_parameterfv_reenter)(GLIContext ctx, GLenum pname, const GLfloat *params);
static void (*point_parameteri_reenter)(GLIContext ctx, GLenum pname, GLint param);
static void (*point_parameteriv_reenter)(GLIContext ctx, GLenum pname, const GLint *params);
static void (*fog_coordf_reenter)(GLIContext ctx, GLfloat coord);
static void (*fog_coordfv_reenter)(GLIContext ctx, const GLfloat *coord);
static void (*fog_coordd_reenter)(GLIContext ctx, GLdouble coord);
static void (*fog_coorddv_reenter)(GLIContext ctx, const GLdouble *coord);
static void (*fog_coord_pointer_reenter)(GLIContext ctx, GLenum type, GLsizei stride, const GLvoid *pointer);
static void (*vertex_array_parameteri_EXT_reenter)(GLIContext ctx, GLenum pname, GLint param);
static void (*bind_vertex_array_EXT_reenter)(GLIContext ctx, GLuint id);
static void (*delete_vertex_arrays_EXT_reenter)(GLIContext ctx, GLsizei n, const GLuint *ids);
static void (*gen_vertex_arrays_EXT_reenter)(GLIContext ctx, GLsizei n, GLuint *ids);
static GLboolean (*is_vertex_array_EXT_reenter)(GLIContext ctx, GLuint id);
static void (*element_pointer_APPLE_reenter)(GLIContext ctx, GLenum type, const GLvoid *pointer);
static void (*draw_element_array_APPLE_reenter)(GLIContext ctx, GLenum mode, GLint first, GLsizei count);
static void (*draw_range_element_array_APPLE_reenter)(GLIContext ctx, GLenum mode, GLuint start, GLuint end, GLint first, GLsizei count);
static void (*weightbv_ARB_reenter)(GLIContext ctx, GLint size, const GLbyte *weights);
static void (*weightsv_ARB_reenter)(GLIContext ctx, GLint size, const GLshort *weights);
static void (*weightiv_ARB_reenter)(GLIContext ctx, GLint size, const GLint *weights);
static void (*weightfv_ARB_reenter)(GLIContext ctx, GLint size, const GLfloat *weights);
static void (*weightdv_ARB_reenter)(GLIContext ctx, GLint size, const GLdouble *weights);
static void (*weightubv_ARB_reenter)(GLIContext ctx, GLint size, const GLubyte *weights);
static void (*weightusv_ARB_reenter)(GLIContext ctx, GLint size, const GLushort *weights);
static void (*weightuiv_ARB_reenter)(GLIContext ctx, GLint size, const GLuint *weights);
static void (*weight_pointer_ARB_reenter)(GLIContext ctx, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
static void (*vertex_blend_ARB_reenter)(GLIContext ctx, GLint count);
static void (*multi_draw_arrays_reenter)(GLIContext ctx, GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount);
static void (*multi_draw_elements_reenter)(GLIContext ctx, GLenum mode, const GLsizei *count, GLenum type, const GLvoid* const *indices, GLsizei drawcount);
static void (*window_pos2d_reenter)((GLIContext ctx, GLdouble x, GLdouble y);
static void (*window_pos2dv_reenter)((GLIContext ctx, const GLdouble *v);
static void (*window_pos2f_reenter)((GLIContext ctx, GLfloat x, GLfloat y);
static void (*window_pos2fv_reenter)((GLIContext ctx, const GLfloat *v);
static void (*window_pos2i_reenter)((GLIContext ctx, GLint x, GLint y);
static void (*window_pos2iv_reenter)((GLIContext ctx, const GLint *v);
static void (*window_pos2s_reenter)((GLIContext ctx, GLshort x, GLshort y);
static void (*window_pos2sv_reenter)((GLIContext ctx, const GLshort *v);
static void (*window_pos3d_reenter)((GLIContext ctx, GLdouble x, GLdouble y, GLdouble z);
static void (*window_pos3dv_reenter)((GLIContext ctx, const GLdouble *v);
static void (*window_pos3f_reenter)((GLIContext ctx, GLfloat x, GLfloat y, GLfloat z);
static void (*window_pos3fv_reenter)((GLIContext ctx, const GLfloat *v);
static void (*window_pos3i_reenter)((GLIContext ctx, GLint x, GLint y, GLint z);
static void (*window_pos3iv_reenter)((GLIContext ctx, const GLint *v);
static void (*window_pos3s_reenter)((GLIContext ctx, GLshort x, GLshort y, GLshort z);
static void (*window_pos3sv_reenter)((GLIContext ctx, const GLshort *v);
static void (*active_stencil_face_EXT_reenter)((GLIContext ctx, GLenum face);
static void (*stencil_op_separate_ATI_reenter)((GLIContext ctx, GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
static void (*stencil_func_separate_ATI_reenter)((GLIContext ctx, GLenum frontfunc, GLenum backfunc, GLint ref, GLuint mask);
static void (*flush_render_APPLE_reenter)((GLIContext ctx);
static void (*finish_render_APPLE_reenter)((GLIContext ctx);
static void (*swap_APPLE_reenter)(GLIContext ctx);
static void (*delete_object_ARB_reenter)((GLIContext ctx, GLhandleARB obj);
static GLhandleARB (*get_handle_ARB_reenter)((GLIContext ctx, GLenum pname);
static void (*detach_object_ARB_reenter)((GLIContext ctx, GLhandleARB containerObj, GLhandleARB attachedObj);
static GLhandleARB (*create_shader_object_ARB_reenter)((GLIContext ctx, GLenum shaderType);
static void (*shader_source_ARB_reenter)((GLIContext ctx, GLhandleARB shaderObj, GLsizei count, const GLcharARB* const *string, const GLint *length);
static void (*compile_shader_ARB_reenter)((GLIContext ctx, GLhandleARB shaderObj);
static GLhandleARB (*create_program_object_ARB_reenter)((GLIContext ctx);
static void (*attach_object_ARB_reenter)((GLIContext ctx, GLhandleARB containerObj, GLhandleARB obj);
static void (*link_program_ARB_reenter)((GLIContext ctx, GLhandleARB programObj);
static void (*use_program_object_ARB_reenter)((GLIContext ctx, GLhandleARB programObj);
static void (*validate_program_ARB_reenter)((GLIContext ctx, GLhandleARB programObj);
static void (*uniform1f_ARB_reenter)((GLIContext ctx, GLint location, GLfloat v0);
static void (*uniform2f_ARB_reenter)((GLIContext ctx, GLint location, GLfloat v0, GLfloat v1);
static void (*uniform3f_ARB_reenter)((GLIContext ctx, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
static void (*uniform4f_ARB_reenter)((GLIContext ctx, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
static void (*uniform1i_ARB_reenter)((GLIContext ctx, GLint location, GLint v0);
static void (*uniform2i_ARB_reenter)((GLIContext ctx, GLint location, GLint v0, GLint v1);
static void (*uniform3i_ARB_reenter)((GLIContext ctx, GLint location, GLint v0, GLint v1, GLint v2);
static void (*uniform4i_ARB_reenter)((GLIContext ctx, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
static void (*uniform1fv_ARB_reenter)((GLIContext ctx, GLint location, GLsizei count, const GLfloat *value);
static void (*uniform2fv_ARB_reenter)((GLIContext ctx, GLint location, GLsizei count, const GLfloat *value);
static void (*uniform3fv_ARB_reenter)((GLIContext ctx, GLint location, GLsizei count, const GLfloat *value);
static void (*uniform4fv_ARB_reenter)((GLIContext ctx, GLint location, GLsizei count, const GLfloat *value);
static void (*uniform1iv_ARB_reenter)((GLIContext ctx, GLint location, GLsizei count, const GLint *value);
static void (*uniform2iv_ARB_reenter)((GLIContext ctx, GLint location, GLsizei count, const GLint *value);
static void (*uniform3iv_ARB_reenter)((GLIContext ctx, GLint location, GLsizei count, const GLint *value);
static void (*uniform4iv_ARB_reenter)((GLIContext ctx, GLint location, GLsizei count, const GLint *value);
static void (*uniform_matrix2fv_ARB_reenter)((GLIContext ctx, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void (*uniform_matrix3fv_ARB_reenter)((GLIContext ctx, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void (*uniform_matrix4fv_ARB_reenter)((GLIContext ctx, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void (*get_object_parameterfv_ARB_reenter)((GLIContext ctx, GLhandleARB obj, GLenum pname, GLfloat *params);
static void (*get_object_parameteriv_ARB_reenter)((GLIContext ctx, GLhandleARB obj, GLenum pname, GLint *params);
static void (*get_info_log_ARB_reenter)((GLIContext ctx, GLhandleARB obj, GLsizei maxLength, GLsizei *length, GLcharARB *infoLog);
static void (*get_attached_objects_ARB_reenter)((GLIContext ctx, GLhandleARB containerObj, GLsizei maxCount, GLsizei *count, GLhandleARB *obj);
static GLint (*get_uniform_location_ARB_reenter)((GLIContext ctx, GLhandleARB programObj, const GLcharARB *name);
static void (*get_active_uniform_ARB_reenter)((GLIContext ctx, GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei *length, GLint *size, GLenum *type, GLcharARB *name);
static void (*get_uniformfv_ARB_reenter)((GLIContext ctx, GLhandleARB programObj, GLint location, GLfloat *params);
static void (*get_uniformiv_ARB_reenter)((GLIContext ctx, GLhandleARB programObj, GLint location, GLint *params);
static void (*get_shader_source_ARB_reenter)((GLIContext ctx, GLhandleARB obj, GLsizei maxLength, GLsizei *length, GLcharARB *source);
static void (*bind_attrib_location_ARB_reenter)((GLIContext ctx, GLhandleARB programObj, GLuint index, const GLcharARB *name);
static void (*get_active_attrib_ARB_reenter)((GLIContext ctx, GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei *length, GLint *size, GLenum *type, GLcharARB *name);
static GLint (*get_attrib_location_ARB_reenter)((GLIContext ctx, GLhandleARB programObj, const GLcharARB *name);
static void (*clamp_color_ARB_reenter)((GLIContext ctx, GLenum target, GLenum clamp);
static void (*gen_queries_reenter)((GLIContext ctx, GLsizei n, GLuint *ids);
static void (*delete_queries_reenter)((GLIContext ctx, GLsizei n, const GLuint *ids);
static GLboolean (*is_query_reenter)((GLIContext ctx, GLuint id);
static void (*begin_query_reenter)((GLIContext ctx, GLenum target, GLuint id);
static void (*end_query_reenter)((GLIContext ctx, GLenum target);
static void (*get_queryiv_reenter)((GLIContext ctx, GLenum target, GLenum pname, GLint *params);
static void (*get_query_objectiv_reenter)((GLIContext ctx, GLuint id, GLenum pname, GLint *params);
static void (*get_query_objectuiv_reenter)((GLIContext ctx, GLuint id, GLenum pname, GLuint *params);
static void (*bind_buffer_reenter)((GLIContext ctx, GLenum target, GLuint buffer);
static void (*delete_buffers_reenter)((GLIContext ctx, GLsizei n, const GLuint *buffers);
static void (*gen_buffers_reenter)((GLIContext ctx, GLsizei n, GLuint *buffers);
static GLboolean (*is_buffer_reenter)((GLIContext ctx, GLuint buffer);
static void (*buffer_data_reenter)((GLIContext ctx, GLenum target, GLsizeiptrARB size, const GLvoid *data, GLenum usage);
static void (*buffer_sub_data_reenter)((GLIContext ctx, GLenum target, GLintptrARB offset, GLsizeiptrARB size, const GLvoid *data);
static void (*get_buffer_sub_data_reenter)((GLIContext ctx, GLenum target, GLintptrARB offset, GLsizeiptrARB size, GLvoid *data);
static GLvoid (**map_buffer_reenter)((GLIContext ctx, GLenum target, GLenum access);
static GLboolean (*unmap_buffer_reenter)((GLIContext ctx, GLenum target);
static void (*get_buffer_parameteriv_reenter)((GLIContext ctx, GLenum target, GLenum pname, GLint *params);
static void (*get_buffer_pointerv_reenter)((GLIContext ctx, GLenum target, GLenum pname, GLvoid **params);
static void (*depth_bounds_EXT_reenter)((GLIContext ctx, GLclampd zmin, GLclampd zmax);
static void (*draw_buffers_ARB_reenter)((GLIContext ctx, GLsizei n, const GLenum *bufs);
static GLboolean (*is_shader_reenter)((GLIContext ctx, GLuint shader);
static GLboolean (*is_program_reenter)((GLIContext ctx, GLuint program);
static void (*get_shaderiv_reenter)((GLIContext ctx, GLuint shader, GLenum pname, GLint *params);
static void (*get_programiv_reenter)((GLIContext ctx, GLuint program, GLenum pname, GLint *params);
static void (*get_shader_info_log_reenter)((GLIContext ctx, GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
static void (*get_program_info_log_reenter)((GLIContext ctx, GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
static void (*stencil_func_separate_reenter)((GLIContext ctx, GLenum face, GLenum func, GLint ref, GLuint mask);
static void (*stencil_mask_separate_reenter)((GLIContext ctx, GLenum face, GLuint mask);
static void (*multi_draw_element_array_APPLE_reenter)(GLIContext ctx, GLenum mode, const GLint *first, const GLsizei *count, GLsizei primcount);
static void (*multi_draw_range_element_array_APPLE_reenter)(GLIContext ctx, GLenum mode, GLuint start, GLuint end, const GLint *first, const GLsizei *count, GLsizei primcount);
static GLboolean (*is_renderbuffer_EXT_reenter)((GLIContext ctx, GLuint renderbuffer);
static void (*bind_renderbuffer_EXT_reenter)((GLIContext ctx, GLenum target, GLuint renderbuffer);
static void (*delete_renderbuffers_EXT_reenter)((GLIContext ctx, GLsizei n, const GLuint *renderbuffers);
static void (*gen_renderbuffers_EXT_reenter)((GLIContext ctx, GLsizei n, GLuint *renderbuffers);
static void (*renderbuffer_storage_EXT_reenter)((GLIContext ctx, GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
static void (*get_renderbuffer_parameteriv_EXT_reenter)((GLIContext ctx, GLenum target, GLenum pname, GLint *params);
static GLboolean (*is_framebuffer_EXT_reenter)((GLIContext ctx, GLuint framebuffer);
static void (*bind_framebuffer_EXT_reenter)((GLIContext ctx, GLenum target, GLuint framebuffer);
static void (*delete_framebuffers_EXT_reenter)((GLIContext ctx, GLsizei n, const GLuint *framebuffers);
static void (*gen_framebuffers_EXT_reenter)((GLIContext ctx, GLsizei n, GLuint *framebuffers);
static GLenum (*check_framebuffer_status_EXT_reenter)((GLIContext ctx, GLenum target);
static void (*framebuffer_texture1D_EXT_reenter)((GLIContext ctx, GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
static void (*framebuffer_texture2D_EXT_reenter)((GLIContext ctx, GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
static void (*framebuffer_texture3D_EXT_reenter)((GLIContext ctx, GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
static void (*framebuffer_renderbuffer_EXT_reenter)((GLIContext ctx, GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
static void (*get_framebuffer_attachment_parameteriv_EXT_reenter)((GLIContext ctx, GLenum target, GLenum attachment, GLenum pname, GLint *params);
static void (*generate_mipmap_EXT_reenter)((GLIContext ctx, GLenum target);
static void (*buffer_parameteri_APPLE_reenter)((GLIContext ctx, GLenum target, GLenum pname, GLint param);
static void (*flush_mapped_buffer_range_APPLE_reenter)((GLIContext ctx, GLenum target, GLintptr offset, GLsizeiptr size);
static void (*program_env_parameters4fv_EXT_reenter)(GLIContext ctx, GLenum target, GLuint index, GLsizei count, const GLfloat *params);
static void (*program_local_parameters4fv_EXT_reenter)(GLIContext ctx, GLenum target, GLuint index, GLsizei count, const GLfloat *params);
static GLenum (*object_purgeable_APPLE_reenter)(GLIContext ctx, GLenum objectType, GLuint name, GLenum option);
static GLenum (*object_unpurgeable_APPLE_reenter)(GLIContext ctx, GLenum objectType, GLuint name, GLenum option);
static void (*(*get_object_parameteriv_APPLE_reenter)((GLIContext ctx, GLenum objectType, GLuint name, GLenum pname, GLint* params);
static void (*program_parameteri_EXT_reenter)(GLIContext ctx, GLuint program_name, GLenum pname, GLint value);
static void (*framebuffer_texture_EXT_reenter)(GLIContext ctx, GLenum target, GLenum attachment, GLuint texture, GLint level);
static void (*framebuffer_texture_layer_EXT_reenter)(GLIContext ctx, GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
static void (*framebuffer_texture_face_EXT_reenter)(GLIContext ctx, GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face);
static void (*bind_buffer_range_EXT_reenter)(GLIContext ctx, GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
static void (*bind_buffer_offset_EXT_reenter)(GLIContext ctx, GLenum target, GLuint index, GLuint buffer, GLintptr offset);
static void (*bind_buffer_base_EXT_reenter)(GLIContext ctx, GLenum target, GLuint index, GLuint buffer);
static void (*begin_transform_feedback_EXT_reenter)(GLIContext ctx, GLenum primitiveMode);
static void (*end_transform_feedback_EXT_reenter)(GLIContext ctx);
static void (*transform_feedback_varyings_EXT_reenter)(GLIContext ctx, GLuint program, GLsizei count, const GLchar* const *varyings, GLenum bufferMode);
static void (*get_transform_feedback_varying_EXT_reenter)(GLIContext ctx, GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
static void (*get_integer_indexedv_EXT_reenter)(GLIContext ctx, GLenum param, GLuint index, GLint *values);
static void (*get_boolean_indexedv_EXT_reenter)(GLIContext ctx, GLenum param, GLuint index, GLboolean *values);
static void (*uniform_buffer_EXT_reenter)(GLIContext ctx, GLuint program, GLint location, GLuint buffer);
static GLint (*get_uniform_buffer_size_EXT_reenter)(GLIContext ctx, GLuint program, GLint location);
static GLintptr (*get_uniform_buffer_offset_EXT_reenter)(GLIContext ctx, GLuint program, GLint location);
static void (*clear_colorIi_EXT_reenter)((GLIContext ctx, GLint r, GLint g, GLint b, GLint a );
static void (*clear_colorIui_EXT_reenter)((GLIContext ctx, GLuint r, GLuint g, GLuint b, GLuint a );
static void (*tex_parameterIiv_EXT_reenter)(GLIContext ctx, GLenum target, GLenum pname, GLint *params );
static void (*tex_parameterIuiv_EXT_reenter)(GLIContext ctx, GLenum target, GLenum pname, GLuint *params );
static void (*get_tex_parameterIiv_EXT_reenter)((GLIContext ctx, GLenum target, GLenum pname, GLint *params);
static void (*get_tex_parameterIuiv_EXT_reenter)((GLIContext ctx, GLenum target, GLenum pname, GLuint *params);
static void (*vertex_attribI1i_EXT_reenter)(GLIContext ctx, GLuint index, GLint x);
static void (*vertex_attribI2i_EXT_reenter)(GLIContext ctx, GLuint index, GLint x, GLint y);
static void (*vertex_attribI3i_EXT_reenter)(GLIContext ctx, GLuint index, GLint x, GLint y, GLint z);
static void (*vertex_attribI4i_EXT_reenter)(GLIContext ctx, GLuint index, GLint x, GLint y, GLint z, GLint w);
static void (*vertex_attribI1ui_EXT_reenter)(GLIContext ctx, GLuint index, GLuint x);
static void (*vertex_attribI2ui_EXT_reenter)(GLIContext ctx, GLuint index, GLuint x, GLuint y);
static void (*vertex_attribI3ui_EXT_reenter)(GLIContext ctx, GLuint index, GLuint x, GLuint y, GLuint z);
static void (*vertex_attribI4ui_EXT_reenter)(GLIContext ctx, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
static void (*vertex_attribI1iv_EXT_reenter)(GLIContext ctx, GLuint index, const GLint *v);
static void (*vertex_attribI2iv_EXT_reenter)(GLIContext ctx, GLuint index, const GLint *v);
static void (*vertex_attribI3iv_EXT_reenter)(GLIContext ctx, GLuint index, const GLint *v);
static void (*vertex_attribI4iv_EXT_reenter)(GLIContext ctx, GLuint index, const GLint *v);
static void (*vertex_attribI1uiv_EXT_reenter)(GLIContext ctx, GLuint index, const GLuint *v);
static void (*vertex_attribI2uiv_EXT_reenter)(GLIContext ctx, GLuint index, const GLuint *v);
static void (*vertex_attribI3uiv_EXT_reenter)(GLIContext ctx, GLuint index, const GLuint *v);
static void (*vertex_attribI4uiv_EXT_reenter)(GLIContext ctx, GLuint index, const GLuint *v);
static void (*vertex_attribI4bv_EXT_reenter)(GLIContext ctx, GLuint index, const GLbyte *v);
static void (*vertex_attribI4sv_EXT_reenter)(GLIContext ctx, GLuint index, const GLshort *v);
static void (*vertex_attribI4ubv_EXT_reenter)(GLIContext ctx, GLuint index, const GLubyte *v);
static void (*vertex_attribI4usv_EXT_reenter)(GLIContext ctx, GLuint index, const GLushort *v);
static void (*vertex_attribI_pointer_EXT_reenter)(GLIContext ctx, GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
static void (*get_vertex_attribIiv_EXT_reenter)(GLIContext ctx, GLuint index, GLenum pname, GLint *params);
static void (*get_vertex_attribIuiv_EXT_reenter)(GLIContext ctx, GLuint index, GLenum pname, GLuint *params);
static void (*uniform1ui_EXT_reenter)(GLIContext ctx, GLint location, GLuint v0);
static void (*uniform2ui_EXT_reenter)(GLIContext ctx, GLint location, GLuint v0, GLuint v1);
static void (*uniform3ui_EXT_reenter)(GLIContext ctx, GLint location, GLuint v0, GLuint v1, GLuint v2);
static void (*uniform4ui_EXT_reenter)(GLIContext ctx, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
static void (*uniform1uiv_EXT_reenter)(GLIContext ctx, GLint location, GLsizei count, const GLuint *value);
static void (*uniform2uiv_EXT_reenter)(GLIContext ctx, GLint location, GLsizei count, const GLuint *value);
static void (*uniform3uiv_EXT_reenter)(GLIContext ctx, GLint location, GLsizei count, const GLuint *value);
static void (*uniform4uiv_EXT_reenter)(GLIContext ctx, GLint location, GLsizei count, const GLuint *value);
static void (*get_uniformuiv_EXT_reenter)(GLIContext ctx, GLuint program, GLint location, GLuint *params);
static void (*bind_frag_data_location_EXT_reenter)(GLIContext ctx, GLuint program, GLuint colorNumber, const GLchar *name);
static GLint (*get_frag_data_location_EXT_reenter)(GLIContext ctx, GLuint program, const GLchar *name);
static void (*color_mask_indexed_EXT_reenter)((GLIContext ctx, GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
static void (*enable_indexed_EXT_reenter)((GLIContext ctx, GLenum target, GLuint index);
static void (*disable_indexed_EXT_reenter)((GLIContext ctx, GLenum target, GLuint index);
static GLboolean (*is_enabled_indexed_EXT_reenter)((GLIContext ctx, GLenum target, GLuint index);
static void (*uniform_matrix2x3fv_reenter)((GLIContext ctx, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void (*uniform_matrix3x2fv_reenter)((GLIContext ctx, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void (*uniform_matrix2x4fv_reenter)((GLIContext ctx, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void (*uniform_matrix4x2fv_reenter)((GLIContext ctx, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void (*uniform_matrix3x4fv_reenter)((GLIContext ctx, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void (*uniform_matrix4x3fv_reenter)((GLIContext ctx, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void (*blit_framebuffer_EXT_reenter)((GLIContext ctx, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
static void (*renderbuffer_storage_multisample_EXT_reenter)((GLIContext ctx, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
static void (*begin_conditional_render_NV_reenter)(GLIContext ctx, GLuint id, GLenum mode);
static void (*end_conditional_render_NV_reenter)(GLIContext ctx);
static void (*get_attached_shaders_reenter)((GLIContext ctx, GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders);
static void (*provoking_vertex_EXT_reenter)((GLIContext ctx, GLenum mode);
static void (*vertex_attrib_divisor_reenter)((GLIContext ctx, GLuint index, GLuint divisor);
static void (*draw_arrays_instanced_reenter)(GLIContext ctx, GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
static void (*draw_elements_instanced_reenter)(GLIContext ctx, GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLsizei instancecount);
static void (*draw_elements_base_vertex_reenter)(GLIContext ctx, GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLint base_vertex);
static void (*draw_range_elements_base_vertex_reenter)(GLIContext ctx, GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices, GLint base_vertex);
static void (*draw_elements_instanced_base_vertex_reenter)(GLIContext ctx, GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLsizei instancecount, GLint base_vertex);
static void (*multi_draw_elements_base_vertex_reenter)(GLIContext ctx, GLenum mode, const GLsizei *count, GLenum type, const GLvoid* const *indices, GLsizei drawcount, const GLint *base_vertex);
static void (*bind_vertex_array_ARB_reenter)(GLIContext ctx, GLuint array);
static void (*delete_vertex_arrays_ARB_reenter)(GLIContext ctx, GLsizei n, const GLuint *arrays);
static void (*gen_vertex_arrays_ARB_reenter)(GLIContext ctx, GLsizei n, GLuint *arrays);
static GLboolean (*is_vertex_array_ARB_reenter)(GLIContext ctx, GLuint array);
static void (*point_size_pointer_reenter)((GLIContext ctx, GLenum type, GLsizei stride, const GLvoid *pointer);
static void (*vertex_point_sizef_APPLE_reenter)((GLIContext ctx, GLfloat size);
static void (*clear_bufferiv_reenter)(GLIContext ctx, GLenum buffer, GLint drawbuffer, const GLint *value);
static void (*clear_bufferuiv_reenter)(GLIContext ctx, GLenum buffer, GLint drawbuffer, const GLuint *value);
static void (*clear_bufferfv_reenter)(GLIContext ctx, GLenum buffer, GLint drawbuffer, const GLfloat *value);
static void (*clear_bufferfi_reenter)(GLIContext ctx, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
static GLsync (*fence_sync_reenter)((GLIContext ctx, GLenum condition, GLbitfield flags);
static GLboolean (*is_sync_reenter)((GLIContext ctx, GLsync sync);
static void (*delete_sync_reenter)((GLIContext ctx, GLsync sync);
static GLenum (*client_wait_sync_reenter)((GLIContext ctx, GLsync sync, GLbitfield flags, GLuint64 timeout);
static void (*wait_sync_reenter)((GLIContext ctx, GLsync sync, GLbitfield flags, GLuint64 timeout);
static void (*get_integer64v_sync_reenter)((GLIContext ctx, GLenum pname, GLint64 *params);
static void (*get_synciv_reenter)((GLIContext ctx, GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values);
static void (*tex_image2D_multisample_reenter)(GLIContext ctx, GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
static void (*tex_image3D_multisample_reenter)(GLIContext ctx, GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
static void (*get_multisamplefv_reenter)(GLIContext ctx, GLenum pname, GLuint index, GLfloat *val);
static void (*sample_maski_reenter)(GLIContext ctx, GLuint index, GLbitfield mask);
static void (*tex_buffer_reenter)(GLIContext ctx, GLenum target, GLenum internalformat, GLuint buffer);
static void (*copy_buffer_sub_data_reenter)(GLIContext ctx, GLenum readtarget, GLenum writetarget, GLintptr readoffset, GLintptr writeoffset, GLsizeiptr size);
static void (*primitive_restart_index_reenter)(GLIContext ctx, GLuint index);
static void (*get_query_objecti64v_reenter)((GLIContext ctx, GLuint id, GLenum pname, GLint64EXT *params);
static void (*get_query_objectui64v_reenter)((GLIContext ctx, GLuint id, GLenum pname, GLuint64EXT *params);
static GLvoid (**map_buffer_range_reenter)((GLIContext ctx, GLenum target, GLintptr offset, GLsizeiptr length, GLenum access);
static void (*flush_mapped_buffer_range_reenter)((GLIContext ctx, GLenum target, GLintptr offset, GLsizeiptr length);
static void (*query_counter_reenter)((GLIContext ctx, GLuint id, GLenum target);
static void (*get_integer64i_v_reenter)((GLIContext ctx, GLenum target, GLuint index, GLint64 *data);
static void (*get_buffer_parameteri64v_reenter)(GLIContext ctx, GLenum target, GLenum pname, GLint64 *params);
static void (*gen_samplers_reenter)((GLIContext ctx, GLsizei count, GLuint *samplers);
static void (*delete_samplers_reenter)((GLIContext ctx, GLsizei count, const GLuint *samplers);
static GLboolean (*is_sampler_reenter)((GLIContext ctx, GLuint sampler);
static void (*bind_sampler_reenter)((GLIContext ctx, GLuint unit, GLuint sampler);
static void (*sampler_parameteri_reenter)((GLIContext ctx, GLuint sampler, GLenum pname, GLint param);
static void (*sampler_parameteriv_reenter)((GLIContext ctx, GLuint sampler, GLenum pname, const GLint *param);
static void (*sampler_parameterf_reenter)((GLIContext ctx, GLuint sampler, GLenum pname, GLfloat param);
static void (*sampler_parameterfv_reenter)((GLIContext ctx, GLuint sampler, GLenum pname, const GLfloat *param);
static void (*sampler_parameterIiv_reenter)((GLIContext ctx, GLuint sampler, GLenum pname, const GLint *param);
static void (*sampler_parameterIuiv_reenter)((GLIContext ctx, GLuint sampler, GLenum pname, const GLuint *param);
static void (*get_sampler_parameteriv_reenter)((GLIContext ctx, GLuint sampler, GLenum pname, GLint *params);
static void (*get_sampler_parameterfv_reenter)((GLIContext ctx, GLuint sampler, GLenum pname, GLfloat *params);
static void (*get_sampler_parameterIiv_reenter)((GLIContext ctx, GLuint sampler, GLenum pname, GLint *params);
static void (*get_sampler_parameterIuiv_reenter)((GLIContext ctx, GLuint sampler, GLenum pname, GLuint *params);
static void (*label_object_EXT_reenter)(GLIContext ctx, GLenum type, GLuint object, GLsizei length, const GLchar *label);
static void (*get_object_label_EXT_reenter)(GLIContext ctx, GLenum type, GLuint object, GLsizei bufSize, GLsizei *length, GLchar *label);
static void (*insert_event_marker_EXT_reenter)(GLIContext ctx, GLsizei length, const GLchar *marker);
static void (*push_group_marker_EXT_reenter)(GLIContext ctx, GLsizei length, const GLchar *marker);
static void (*pop_group_marker_EXT_reenter)(GLIContext ctx);
static void (*use_program_stages_reenter)(GLIContext ctx, GLuint pipeline, GLbitfield stages, GLuint program);
static void (*active_shader_program_reenter)(GLIContext ctx, GLuint pipeline, GLuint program);
static GLuint (*create_shader_programv_reenter)(GLIContext ctx, GLenum type, GLsizei count, const GLchar* const *strings);
static void (*bind_program_pipeline_reenter)(GLIContext ctx, GLuint pipeline);
static void (*delete_program_pipelines_reenter)(GLIContext ctx, GLsizei n, const GLuint *pipelines);
static void (*gen_program_pipelines_reenter)(GLIContext ctx, GLsizei n, GLuint *pipelines);
static GLboolean (*is_program_pipeline_reenter)(GLIContext ctx, GLuint pipeline);
static void (*get_program_pipelineiv_reenter)(GLIContext ctx, GLuint pipeline, GLenum pname, GLint *params);
static void (*validate_program_pipeline_reenter)(GLIContext ctx, GLuint pipeline);
static void (*get_program_pipeline_info_log_reenter)(GLIContext ctx, GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
static void (*program_uniform1i_reenter)(GLIContext ctx, GLuint program, GLint location, GLint x);
static void (*program_uniform2i_reenter)(GLIContext ctx, GLuint program, GLint location, GLint x, GLint y);
static void (*program_uniform3i_reenter)(GLIContext ctx, GLuint program, GLint location, GLint x, GLint y, GLint z);
static void (*program_uniform4i_reenter)(GLIContext ctx, GLuint program, GLint location, GLint x, GLint y, GLint z, GLint w);
static void (*program_uniform1f_reenter)(GLIContext ctx, GLuint program, GLint location, GLfloat x);
static void (*program_uniform2f_reenter)(GLIContext ctx, GLuint program, GLint location, GLfloat x, GLfloat y);
static void (*program_uniform3f_reenter)(GLIContext ctx, GLuint program, GLint location, GLfloat x, GLfloat y, GLfloat z);
static void (*program_uniform4f_reenter)(GLIContext ctx, GLuint program, GLint location, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
static void (*program_uniform1iv_reenter)(GLIContext ctx, GLuint program, GLint location, GLsizei count, const GLint *value);
static void (*program_uniform2iv_reenter)(GLIContext ctx, GLuint program, GLint location, GLsizei count, const GLint *value);
static void (*program_uniform3iv_reenter)(GLIContext ctx, GLuint program, GLint location, GLsizei count, const GLint *value);
static void (*program_uniform4iv_reenter)(GLIContext ctx, GLuint program, GLint location, GLsizei count, const GLint *value);
static void (*program_uniform1fv_reenter)(GLIContext ctx, GLuint program, GLint location, GLsizei count, const GLfloat *value);
static void (*program_uniform2fv_reenter)(GLIContext ctx, GLuint program, GLint location, GLsizei count, const GLfloat *value);
static void (*program_uniform3fv_reenter)(GLIContext ctx, GLuint program, GLint location, GLsizei count, const GLfloat *value);
static void (*program_uniform4fv_reenter)(GLIContext ctx, GLuint program, GLint location, GLsizei count, const GLfloat *value);
static void (*program_uniform_matrix2fv_reenter)(GLIContext ctx, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void (*program_uniform_matrix3fv_reenter)(GLIContext ctx, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void (*program_uniform_matrix4fv_reenter)(GLIContext ctx, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void (*program_uniform1ui_reenter)(GLIContext ctx, GLuint program, GLint location, GLuint x);
static void (*program_uniform2ui_reenter)(GLIContext ctx, GLuint program, GLint location, GLuint x, GLuint y);
static void (*program_uniform3ui_reenter)(GLIContext ctx, GLuint program, GLint location, GLuint x, GLuint y, GLuint z);
static void (*program_uniform4ui_reenter)(GLIContext ctx, GLuint program, GLint location, GLuint x, GLuint y, GLuint z, GLuint w);
static void (*program_uniform1uiv_reenter)(GLIContext ctx, GLuint program, GLint location, GLsizei count, const GLuint *value);
static void (*program_uniform2uiv_reenter)(GLIContext ctx, GLuint program, GLint location, GLsizei count, const GLuint *value);
static void (*program_uniform3uiv_reenter)(GLIContext ctx, GLuint program, GLint location, GLsizei count, const GLuint *value);
static void (*program_uniform4uiv_reenter)(GLIContext ctx, GLuint program, GLint location, GLsizei count, const GLuint *value);
static void (*program_uniform_matrix2x3fv_reenter)(GLIContext ctx, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void (*program_uniform_matrix3x2fv_reenter)(GLIContext ctx, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void (*program_uniform_matrix2x4fv_reenter)(GLIContext ctx, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void (*program_uniform_matrix4x2fv_reenter)(GLIContext ctx, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void (*program_uniform_matrix3x4fv_reenter)(GLIContext ctx, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void (*program_uniform_matrix4x3fv_reenter)(GLIContext ctx, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void (*bind_frag_data_location_indexed_reenter)((GLIContext ctx, GLuint program, GLuint colorNumber, GLuint index, const GLchar *name);
static GLint (*get_frag_data_index_reenter)((GLIContext ctx, GLuint program, const GLchar *name);
static void (*blend_func_i_reenter)((GLIContext ctx, GLuint buf, GLenum src, GLenum dst);
static void (*blend_func_separate_i_reenter)((GLIContext ctx, GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
static void (*blend_equation_i_reenter)((GLIContext ctx, GLuint buf, GLenum mode);
static void (*blend_equation_separate_i_reenter)((GLIContext ctx, GLuint buf, GLenum modeRGB, GLenum modeAlpha);
static void (*named_string_ARB_reenter)((GLIContext ctx, GLenum type, GLint namelen, const GLchar *name, GLint stringlen, const GLchar *string);
static void (*delete_named_string_ARB_reenter)((GLIContext ctx, GLint namelen, const GLchar *name);
static void (*compile_shader_include_ARB_reenter)((GLIContext ctx, GLuint shader, GLsizei count, const GLchar* const *path, const GLint *length);
static GLboolean (*is_named_string_ARB_reenter)((GLIContext ctx, GLint namelen, const GLchar *name);
static void (*get_named_string_ARB_reenter)((GLIContext ctx, GLint namelen, const GLchar *name, GLsizei bufSize, GLint *stringlen, GLchar *string);
static void (*get_named_string_iv_ARB_reenter)((GLIContext ctx, GLint namelen, const GLchar *name, GLenum pname, GLint *params);
static void (*release_shader_compiler_reenter)(GLIContext ctx);
static void (*shader_binary_reenter)(GLIContext ctx, GLint n, GLuint *shaders, GLenum binaryformat, const GLvoid *binary, GLint length);
static void (*get_shader_precision_format_reenter)(GLIContext ctx, GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision);
static void (*depth_rangef_reenter)((GLIContext ctx, GLclampf zNear, GLclampf zFar);
static void (*clear_depthf_reenter)((GLIContext ctx, GLclampf depth);
static void (*vertex_attribP1ui_reenter)((GLIContext ctx, GLuint index, GLenum type, GLboolean normalized, GLuint value);
static void (*vertex_attribP2ui_reenter)((GLIContext ctx, GLuint index, GLenum type, GLboolean normalized, GLuint value);
static void (*vertex_attribP3ui_reenter)((GLIContext ctx, GLuint index, GLenum type, GLboolean normalized, GLuint value);
static void (*vertex_attribP4ui_reenter)((GLIContext ctx, GLuint index, GLenum type, GLboolean normalized, GLuint value);
static void (*vertex_attribP1uiv_reenter)((GLIContext ctx, GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
static void (*vertex_attribP2uiv_reenter)((GLIContext ctx, GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
static void (*vertex_attribP3uiv_reenter)((GLIContext ctx, GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
static void (*vertex_attribP4uiv_reenter)((GLIContext ctx, GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
static void (*get_program_binary_reenter)((GLIContext ctx, GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, GLvoid *binary);
static void (*program_binary_reenter)((GLIContext ctx, GLuint program, GLenum binaryFormat, const GLvoid *binary, GLsizei length);
static void (*min_sample_shading_reenter)((GLIContext ctx, GLclampf value);
static void (*viewport_arrayv_reenter)((GLIContext ctx, GLuint first, GLsizei count, const GLfloat * v);
static void (*viewport_indexedf_reenter)((GLIContext ctx, GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
static void (*viewport_indexedfv_reenter)((GLIContext ctx, GLuint index, const GLfloat * v);
static void (*scissor_arrayv_reenter)((GLIContext ctx, GLuint first, GLsizei count, const GLint * v);
static void (*scissor_indexed_reenter)((GLIContext ctx, GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
static void (*scissor_indexedv_reenter)((GLIContext ctx, GLuint index, const GLint * v);
static void (*depth_range_arrayv_reenter)((GLIContext ctx, GLuint first, GLsizei count, const GLclampd * v);
static void (*depth_range_indexed_reenter)((GLIContext ctx, GLuint index, GLclampd n, GLclampd f);
static void (*get_floati_v_reenter)((GLIContext ctx, GLenum target, GLuint index, GLfloat *data);
static void (*get_doublei_v_reenter)((GLIContext ctx, GLenum target, GLuint index, GLdouble *data);
static void (*draw_arrays_indirect_reenter)((GLIContext ctx, GLenum mode, const GLvoid *indirect);
static void (*draw_elements_indirect_reenter)((GLIContext ctx, GLenum mode, GLenum type, const GLvoid *indirect);
static void (*patch_parameteri_reenter)((GLIContext ctx, GLenum pname, GLint value);
static void (*patch_parameterfv_reenter)((GLIContext ctx, GLenum pname, const GLfloat* values);
static void (*bind_transform_feedback_reenter)((GLIContext ctx, GLenum target, GLuint name);
static void (*gen_transform_feedbacks_reenter)((GLIContext ctx, GLsizei n, GLuint* ids);
static void (*delete_transform_feedbacks_reenter)((GLIContext ctx, GLsizei n, const GLuint* ids);
static void (*pause_transform_feedback_reenter)((GLIContext ctx);
static void (*resume_transform_feedback_reenter)((GLIContext ctx);
static GLboolean (*is_transform_feedback_reenter)((GLIContext ctx, GLuint name);
static void (*draw_transform_feedback_reenter)((GLIContext ctx, GLenum mode, GLuint name);
static void (*begin_query_indexed_reenter)((GLIContext ctx, GLenum target, GLuint index, GLuint id);
static void (*end_query_indexed_reenter)((GLIContext ctx, GLenum target, GLuint index);
static void (*get_query_indexediv_reenter)((GLIContext ctx, GLenum target, GLuint index, GLenum pname, GLint *params);
static void (*draw_transform_feedback_stream_reenter)((GLIContext ctx, GLenum mode, GLuint name, GLuint stream);
static void (*program_uniform1d_reenter)(GLIContext ctx, GLuint program, GLint location, GLdouble x);
static void (*program_uniform2d_reenter)(GLIContext ctx, GLuint program, GLint location, GLdouble x, GLdouble y);
static void (*program_uniform3d_reenter)(GLIContext ctx, GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z);
static void (*program_uniform4d_reenter)(GLIContext ctx, GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
static void (*program_uniform1dv_reenter)(GLIContext ctx, GLuint program, GLint location, GLsizei count, const GLdouble *value);
static void (*program_uniform2dv_reenter)(GLIContext ctx, GLuint program, GLint location, GLsizei count, const GLdouble *value);
static void (*program_uniform3dv_reenter)(GLIContext ctx, GLuint program, GLint location, GLsizei count, const GLdouble *value);
static void (*program_uniform4dv_reenter)(GLIContext ctx, GLuint program, GLint location, GLsizei count, const GLdouble *value);
static void (*program_uniform_matrix2dv_reenter)(GLIContext ctx, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void (*program_uniform_matrix3dv_reenter)(GLIContext ctx, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void (*program_uniform_matrix4dv_reenter)(GLIContext ctx, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void (*program_uniform_matrix2x3dv_reenter)(GLIContext ctx, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void (*program_uniform_matrix3x2dv_reenter)(GLIContext ctx, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void (*program_uniform_matrix2x4dv_reenter)(GLIContext ctx, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void (*program_uniform_matrix4x2dv_reenter)(GLIContext ctx, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void (*program_uniform_matrix3x4dv_reenter)(GLIContext ctx, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void (*program_uniform_matrix4x3dv_reenter)(GLIContext ctx, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void (*uniform1d_reenter)(GLIContext ctx, GLint location, GLdouble x);
static void (*uniform2d_reenter)(GLIContext ctx, GLint location, GLdouble x, GLdouble y);
static void (*uniform3d_reenter)(GLIContext ctx, GLint location, GLdouble x, GLdouble y, GLdouble z);
static void (*uniform4d_reenter)(GLIContext ctx, GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
static void (*uniform1dv_reenter)(GLIContext ctx, GLint location, GLsizei count, const GLdouble *value);
static void (*uniform2dv_reenter)(GLIContext ctx, GLint location, GLsizei count, const GLdouble *value);
static void (*uniform3dv_reenter)(GLIContext ctx, GLint location, GLsizei count, const GLdouble *value);
static void (*uniform4dv_reenter)(GLIContext ctx, GLint location, GLsizei count, const GLdouble *value);
static void (*uniform_matrix2dv_reenter)(GLIContext ctx, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void (*uniform_matrix3dv_reenter)(GLIContext ctx, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void (*uniform_matrix4dv_reenter)(GLIContext ctx, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void (*uniform_matrix2x3dv_reenter)(GLIContext ctx, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void (*uniform_matrix3x2dv_reenter)(GLIContext ctx, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void (*uniform_matrix2x4dv_reenter)(GLIContext ctx, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void (*uniform_matrix4x2dv_reenter)(GLIContext ctx, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void (*uniform_matrix3x4dv_reenter)(GLIContext ctx, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void (*uniform_matrix4x3dv_reenter)(GLIContext ctx, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void (*get_uniformdv_reenter)(GLIContext ctx, GLuint program_obj, GLint location, GLdouble *params);
static void (*vertex_attribl1d_reenter)(GLIContext ctx, GLuint index, GLdouble x);
static void (*vertex_attribl2d_reenter)(GLIContext ctx, GLuint index, GLdouble x, GLdouble y);
static void (*vertex_attribl3d_reenter)(GLIContext ctx, GLuint index, GLdouble x, GLdouble y, GLdouble z);
static void (*vertex_attribl4d_reenter)(GLIContext ctx, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
static void (*vertex_attribl1dv_reenter)(GLIContext ctx, GLuint index, const GLdouble *v);
static void (*vertex_attribl2dv_reenter)(GLIContext ctx, GLuint index, const GLdouble *v);
static void (*vertex_attribl3dv_reenter)(GLIContext ctx, GLuint index, const GLdouble *v);
static void (*vertex_attribl4dv_reenter)(GLIContext ctx, GLuint index, const GLdouble *v);
static void (*vertex_attrib_lpointer_reenter)(GLIContext ctx, GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
static void (*get_vertex_attrib_ldv_reenter)(GLIContext ctx, GLuint index, GLenum pname, GLdouble *params);
static GLint (*get_subroutine_uniform_location_reenter)(GLIContext ctx, GLuint program, GLenum shadertype, const GLchar *name);
static GLuint (*get_subroutine_index_reenter)(GLIContext ctx, GLuint program, GLenum shadertype, const GLchar *name);
static void (*get_active_subroutine_uniformiv_reenter)(GLIContext ctx, GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint *values);
static void (*get_active_subroutine_uniform_name_reenter)(GLIContext ctx, GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name);
static void (*get_active_subroutine_name_reenter)(GLIContext ctx, GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name);
static void (*uniform_subroutinesuiv_reenter)(GLIContext ctx, GLenum shadertype, GLsizei count, const GLuint *indices);
static void (*get_uniform_subroutineuiv_reenter)(GLIContext ctx, GLenum shadertype, GLint location, GLuint *params);
static void (*get_program_stageiv_reenter)(GLIContext ctx, GLuint program, GLenum shadertype, GLenum pname, GLint *values);
static void (*get_internal_formativ_reenter)((GLIContext ctx, GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint* params);
static void (*tex_storage1D_reenter)((GLIContext ctx, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
static void (*tex_storage2D_reenter)((GLIContext ctx, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
static void (*tex_storage3D_reenter)((GLIContext ctx, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
static void (*label_object_with_responsible_process_APPLE_reenter)((GLIContext ctx, GLenum type, GLuint name, GLint pid);
static void (*texture_barrier_NV_reenter)((GLIContext ctx);

struct replacement
{
	static void accum_replacement(GLIContext ctx, GLenum op, GLfloat value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: accum called.");
		
		return accum_reenter(ctx, op, value);
	}
	
	static void alpha_func_replacement(GLIContext ctx, GLenum func, GLclampf ref)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: alpha_func called.");
		
		return alpha_func_reenter(ctx, func, ref);
	}
	
	static GLboolean are_textures_resident_replacement(GLIContext ctx, GLsizei n, const GLuint *textures, GLboolean *residences)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: are_textures_resident called.");
		
		return are_textures_resident_reenter(ctx, n, GLuint GLboolean);
	}
	
	static void array_element_replacement(GLIContext ctx, GLint i)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: array_element called.");
		
		return array_element_reenter(ctx, i);
	}
	
	static void begin_replacement(GLIContext ctx, GLenum mode)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: begin called.");
		
		return begin_reenter(ctx, mode);
	}
	
	static void bind_texture_replacement(GLIContext ctx, GLenum target, GLuint texture)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: bind_texture called.");
		
		return bind_texture_reenter(ctx, target, texture);
	}
	
	static void bitmap_replacement(GLIContext ctx, GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte *bitmap)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: bitmap called.");
		
		return bitmap_reenter(ctx, width, height, xorig, yorig, xmove, ymove, GLubyte);
	}
	
	static void blend_func_replacement(GLIContext ctx, GLenum sfactor, GLenum dfactor)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: blend_func called.");
		
		return blend_func_reenter(ctx, sfactor, dfactor);
	}
	
	static void call_list_replacement(GLIContext ctx, GLuint list)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: call_list called.");
		
		return call_list_reenter(ctx, list);
	}
	
	static void call_lists_replacement(GLIContext ctx, GLsizei n, GLenum type, const GLvoid *lists)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: call_lists called.");
		
		return call_lists_reenter(ctx, n, type, GLvoid);
	}
	
	static void clear_replacement(GLIContext ctx, GLbitfield mask)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: clear called.");
		
		return clear_reenter(ctx, mask);
	}
	
	static void clear_accum_replacement(GLIContext ctx, GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: clear_accum called.");
		
		return clear_accum_reenter(ctx, red, green, blue, alpha);
	}
	
	static void clear_color_replacement(GLIContext ctx, GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: clear_color called.");
		
		return clear_color_reenter(ctx, red, green, blue, alpha);
	}
	
	static void clear_depth_replacement(GLIContext ctx, GLclampd depth)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: clear_depth called.");
		
		return clear_depth_reenter(ctx, depth);
	}
	
	static void clear_index_replacement(GLIContext ctx, GLfloat c)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: clear_index called.");
		
		return clear_index_reenter(ctx, c);
	}
	
	static void clear_stencil_replacement(GLIContext ctx, GLint s)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: clear_stencil called.");
		
		return clear_stencil_reenter(ctx, s);
	}
	
	static void clip_plane_replacement(GLIContext ctx, GLenum plane, const GLdouble *equation)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: clip_plane called.");
		
		return clip_plane_reenter(ctx, plane, GLdouble);
	}
	
	static void color3b_replacement(GLIContext ctx, GLbyte red, GLbyte green, GLbyte blue)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: color3b called.");
		
		return color3b_reenter(ctx, red, green, blue);
	}
	
	static void color3bv_replacement(GLIContext ctx, const GLbyte *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: color3bv called.");
		
		return color3bv_reenter(ctx, GLbyte);
	}
	
	static void color3d_replacement(GLIContext ctx, GLdouble red, GLdouble green, GLdouble blue)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: color3d called.");
		
		return color3d_reenter(ctx, red, green, blue);
	}
	
	static void color3dv_replacement(GLIContext ctx, const GLdouble *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: color3dv called.");
		
		return color3dv_reenter(ctx, GLdouble);
	}
	
	static void color3f_replacement(GLIContext ctx, GLfloat red, GLfloat green, GLfloat blue)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: color3f called.");
		
		return color3f_reenter(ctx, red, green, blue);
	}
	
	static void color3fv_replacement(GLIContext ctx, const GLfloat *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: color3fv called.");
		
		return color3fv_reenter(ctx, GLfloat);
	}
	
	static void color3i_replacement(GLIContext ctx, GLint red, GLint green, GLint blue)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: color3i called.");
		
		return color3i_reenter(ctx, red, green, blue);
	}
	
	static void color3iv_replacement(GLIContext ctx, const GLint *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: color3iv called.");
		
		return color3iv_reenter(ctx, GLint);
	}
	
	static void color3s_replacement(GLIContext ctx, GLshort red, GLshort green, GLshort blue)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: color3s called.");
		
		return color3s_reenter(ctx, red, green, blue);
	}
	
	static void color3sv_replacement(GLIContext ctx, const GLshort *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: color3sv called.");
		
		return color3sv_reenter(ctx, GLshort);
	}
	
	static void color3ub_replacement(GLIContext ctx, GLubyte red, GLubyte green, GLubyte blue)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: color3ub called.");
		
		return color3ub_reenter(ctx, red, green, blue);
	}
	
	static void color3ubv_replacement(GLIContext ctx, const GLubyte *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: color3ubv called.");
		
		return color3ubv_reenter(ctx, GLubyte);
	}
	
	static void color3ui_replacement(GLIContext ctx, GLuint red, GLuint green, GLuint blue)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: color3ui called.");
		
		return color3ui_reenter(ctx, red, green, blue);
	}
	
	static void color3uiv_replacement(GLIContext ctx, const GLuint *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: color3uiv called.");
		
		return color3uiv_reenter(ctx, GLuint);
	}
	
	static void color3us_replacement(GLIContext ctx, GLushort red, GLushort green, GLushort blue)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: color3us called.");
		
		return color3us_reenter(ctx, red, green, blue);
	}
	
	static void color3usv_replacement(GLIContext ctx, const GLushort *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: color3usv called.");
		
		return color3usv_reenter(ctx, GLushort);
	}
	
	static void color4b_replacement(GLIContext ctx, GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: color4b called.");
		
		return color4b_reenter(ctx, red, green, blue, alpha);
	}
	
	static void color4bv_replacement(GLIContext ctx, const GLbyte *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: color4bv called.");
		
		return color4bv_reenter(ctx, GLbyte);
	}
	
	static void color4d_replacement(GLIContext ctx, GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: color4d called.");
		
		return color4d_reenter(ctx, red, green, blue, alpha);
	}
	
	static void color4dv_replacement(GLIContext ctx, const GLdouble *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: color4dv called.");
		
		return color4dv_reenter(ctx, GLdouble);
	}
	
	static void color4f_replacement(GLIContext ctx, GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: color4f called.");
		
		return color4f_reenter(ctx, red, green, blue, alpha);
	}
	
	static void color4fv_replacement(GLIContext ctx, const GLfloat *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: color4fv called.");
		
		return color4fv_reenter(ctx, GLfloat);
	}
	
	static void color4i_replacement(GLIContext ctx, GLint red, GLint green, GLint blue, GLint alpha)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: color4i called.");
		
		return color4i_reenter(ctx, red, green, blue, alpha);
	}
	
	static void color4iv_replacement(GLIContext ctx, const GLint *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: color4iv called.");
		
		return color4iv_reenter(ctx, GLint);
	}
	
	static void color4s_replacement(GLIContext ctx, GLshort red, GLshort green, GLshort blue, GLshort alpha)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: color4s called.");
		
		return color4s_reenter(ctx, red, green, blue, alpha);
	}
	
	static void color4sv_replacement(GLIContext ctx, const GLshort *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: color4sv called.");
		
		return color4sv_reenter(ctx, GLshort);
	}
	
	static void color4ub_replacement(GLIContext ctx, GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: color4ub called.");
		
		return color4ub_reenter(ctx, red, green, blue, alpha);
	}
	
	static void color4ubv_replacement(GLIContext ctx, const GLubyte *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: color4ubv called.");
		
		return color4ubv_reenter(ctx, GLubyte);
	}
	
	static void color4ui_replacement(GLIContext ctx, GLuint red, GLuint green, GLuint blue, GLuint alpha)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: color4ui called.");
		
		return color4ui_reenter(ctx, red, green, blue, alpha);
	}
	
	static void color4uiv_replacement(GLIContext ctx, const GLuint *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: color4uiv called.");
		
		return color4uiv_reenter(ctx, GLuint);
	}
	
	static void color4us_replacement(GLIContext ctx, GLushort red, GLushort green, GLushort blue, GLushort alpha)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: color4us called.");
		
		return color4us_reenter(ctx, red, green, blue, alpha);
	}
	
	static void color4usv_replacement(GLIContext ctx, const GLushort *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: color4usv called.");
		
		return color4usv_reenter(ctx, GLushort);
	}
	
	static void color_mask_replacement(GLIContext ctx, GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: color_mask called.");
		
		return color_mask_reenter(ctx, red, green, blue, alpha);
	}
	
	static void color_material_replacement(GLIContext ctx, GLenum face, GLenum mode)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: color_material called.");
		
		return color_material_reenter(ctx, face, mode);
	}
	
	static void color_pointer_replacement(GLIContext ctx, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: color_pointer called.");
		
		return color_pointer_reenter(ctx, size, type, stride, GLvoid);
	}
	
	static void copy_pixels_replacement(GLIContext ctx, GLint x, GLint y, GLsizei width, GLsizei height, GLenum type)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: copy_pixels called.");
		
		return copy_pixels_reenter(ctx, x, y, width, height, type);
	}
	
	static void copy_tex_image1D_replacement(GLIContext ctx, GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLint border)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: copy_tex_image1D called.");
		
		return copy_tex_image1D_reenter(ctx, target, level, internalFormat, x, y, width, border);
	}
	
	static void copy_tex_image2D_replacement(GLIContext ctx, GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: copy_tex_image2D called.");
		
		return copy_tex_image2D_reenter(ctx, target, level, internalFormat, x, y, width, height, border);
	}
	
	static void copy_tex_sub_image1D_replacement(GLIContext ctx, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: copy_tex_sub_image1D called.");
		
		return copy_tex_sub_image1D_reenter(ctx, target, level, xoffset, x, y, width);
	}
	
	static void copy_tex_sub_image2D_replacement(GLIContext ctx, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: copy_tex_sub_image2D called.");
		
		return copy_tex_sub_image2D_reenter(ctx, target, level, xoffset, yoffset, x, y, width, height);
	}
	
	static void cull_face_replacement(GLIContext ctx, GLenum mode)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: cull_face called.");
		
		return cull_face_reenter(ctx, mode);
	}
	
	static void delete_lists_replacement(GLIContext ctx, GLuint list, GLsizei range)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: delete_lists called.");
		
		return delete_lists_reenter(ctx, list, range);
	}
	
	static void delete_textures_replacement(GLIContext ctx, GLsizei n, const GLuint *textures)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: delete_textures called.");
		
		return delete_textures_reenter(ctx, n, GLuint);
	}
	
	static void depth_func_replacement(GLIContext ctx, GLenum func)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: depth_func called.");
		
		return depth_func_reenter(ctx, func);
	}
	
	static void depth_mask_replacement(GLIContext ctx, GLboolean flag)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: depth_mask called.");
		
		return depth_mask_reenter(ctx, flag);
	}
	
	static void depth_range_replacement(GLIContext ctx, GLclampd zNear, GLclampd zFar)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: depth_range called.");
		
		return depth_range_reenter(ctx, zNear, zFar);
	}
	
	static void disable_replacement(GLIContext ctx, GLenum cap)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: disable called.");
		
		return disable_reenter(ctx, cap);
	}
	
	static void disable_client_state_replacement(GLIContext ctx, GLenum array)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: disable_client_state called.");
		
		return disable_client_state_reenter(ctx, array);
	}
	
	static void draw_arrays_replacement(GLIContext ctx, GLenum mode, GLint first, GLsizei count)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: draw_arrays called.");
		
		return draw_arrays_reenter(ctx, mode, first, count);
	}
	
	static void draw_buffer_replacement(GLIContext ctx, GLenum mode)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: draw_buffer called.");
		
		return draw_buffer_reenter(ctx, mode);
	}
	
	static void draw_elements_replacement(GLIContext ctx, GLenum mode, GLsizei count, GLenum type, const GLvoid *indices)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: draw_elements called.");
		
		return draw_elements_reenter(ctx, mode, count, type, GLvoid);
	}
	
	static void draw_pixels_replacement(GLIContext ctx, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: draw_pixels called.");
		
		return draw_pixels_reenter(ctx, width, height, format, type, GLvoid);
	}
	
	static void edge_flag_replacement(GLIContext ctx, GLboolean flag)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: edge_flag called.");
		
		return edge_flag_reenter(ctx, flag);
	}
	
	static void edge_flag_pointer_replacement(GLIContext ctx, GLsizei stride, const GLvoid *pointer)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: edge_flag_pointer called.");
		
		return edge_flag_pointer_reenter(ctx, stride, GLvoid);
	}
	
	static void edge_flagv_replacement(GLIContext ctx, const GLboolean *flag)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: edge_flagv called.");
		
		return edge_flagv_reenter(ctx, GLboolean);
	}
	
	static void enable_replacement(GLIContext ctx, GLenum cap)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: enable called.");
		
		return enable_reenter(ctx, cap);
	}
	
	static void enable_client_state_replacement(GLIContext ctx, GLenum array)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: enable_client_state called.");
		
		return enable_client_state_reenter(ctx, array);
	}
	
	static void end_replacement(GLIContext ctx)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: end called.");
		
		return end_reenter(ctx);
	}
	
	static void end_list_replacement(GLIContext ctx)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: end_list called.");
		
		return end_list_reenter(ctx);
	}
	
	static void eval_coord1d_replacement(GLIContext ctx, GLdouble u)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: eval_coord1d called.");
		
		return eval_coord1d_reenter(ctx, u);
	}
	
	static void eval_coord1dv_replacement(GLIContext ctx, const GLdouble *u)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: eval_coord1dv called.");
		
		return eval_coord1dv_reenter(ctx, GLdouble);
	}
	
	static void eval_coord1f_replacement(GLIContext ctx, GLfloat u)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: eval_coord1f called.");
		
		return eval_coord1f_reenter(ctx, u);
	}
	
	static void eval_coord1fv_replacement(GLIContext ctx, const GLfloat *u)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: eval_coord1fv called.");
		
		return eval_coord1fv_reenter(ctx, GLfloat);
	}
	
	static void eval_coord2d_replacement(GLIContext ctx, GLdouble u, GLdouble v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: eval_coord2d called.");
		
		return eval_coord2d_reenter(ctx, u, v);
	}
	
	static void eval_coord2dv_replacement(GLIContext ctx, const GLdouble *u)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: eval_coord2dv called.");
		
		return eval_coord2dv_reenter(ctx, GLdouble);
	}
	
	static void eval_coord2f_replacement(GLIContext ctx, GLfloat u, GLfloat v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: eval_coord2f called.");
		
		return eval_coord2f_reenter(ctx, u, v);
	}
	
	static void eval_coord2fv_replacement(GLIContext ctx, const GLfloat *u)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: eval_coord2fv called.");
		
		return eval_coord2fv_reenter(ctx, GLfloat);
	}
	
	static void eval_mesh1_replacement(GLIContext ctx, GLenum mode, GLint i1, GLint i2)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: eval_mesh1 called.");
		
		return eval_mesh1_reenter(ctx, mode, i1, i2);
	}
	
	static void eval_mesh2_replacement(GLIContext ctx, GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: eval_mesh2 called.");
		
		return eval_mesh2_reenter(ctx, mode, i1, i2, j1, j2);
	}
	
	static void eval_point1_replacement(GLIContext ctx, GLint i)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: eval_point1 called.");
		
		return eval_point1_reenter(ctx, i);
	}
	
	static void eval_point2_replacement(GLIContext ctx, GLint i, GLint j)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: eval_point2 called.");
		
		return eval_point2_reenter(ctx, i, j);
	}
	
	static void feedback_buffer_replacement(GLIContext ctx, GLsizei size, GLenum type, GLfloat *buffer)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: feedback_buffer called.");
		
		return feedback_buffer_reenter(ctx, size, type, *buffer);
	}
	
	static void finish_replacement(GLIContext ctx)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: finish called.");
		
		return finish_reenter(ctx);
	}
	
	static void flush_replacement(GLIContext ctx)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: flush called.");
		
		return flush_reenter(ctx);
	}
	
	static void fogf_replacement(GLIContext ctx, GLenum pname, GLfloat param)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: fogf called.");
		
		return fogf_reenter(ctx, pname, param);
	}
	
	static void fogfv_replacement(GLIContext ctx, GLenum pname, const GLfloat *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: fogfv called.");
		
		return fogfv_reenter(ctx, pname, GLfloat);
	}
	
	static void fogi_replacement(GLIContext ctx, GLenum pname, GLint param)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: fogi called.");
		
		return fogi_reenter(ctx, pname, param);
	}
	
	static void fogiv_replacement(GLIContext ctx, GLenum pname, const GLint *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: fogiv called.");
		
		return fogiv_reenter(ctx, pname, GLint);
	}
	
	static void front_face_replacement(GLIContext ctx, GLenum mode)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: front_face called.");
		
		return front_face_reenter(ctx, mode);
	}
	
	static void frustum_replacement(GLIContext ctx, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: frustum called.");
		
		return frustum_reenter(ctx, left, right, bottom, top, zNear, zFar);
	}
	
	static GLuint gen_lists_replacement(GLIContext ctx, GLsizei range)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: gen_lists called.");
		
		return gen_lists_reenter(ctx, range);
	}
	
	static void gen_textures_replacement(GLIContext ctx, GLsizei n, GLuint *textures)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: gen_textures called.");
		
		return gen_textures_reenter(ctx, n, *textures);
	}
	
	static void get_booleanv_replacement(GLIContext ctx, GLenum pname, GLboolean *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_booleanv called.");
		
		return get_booleanv_reenter(ctx, pname, *params);
	}
	
	static void get_clip_plane_replacement(GLIContext ctx, GLenum plane, GLdouble *equation)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_clip_plane called.");
		
		return get_clip_plane_reenter(ctx, plane, *equation);
	}
	
	static void get_doublev_replacement(GLIContext ctx, GLenum pname, GLdouble *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_doublev called.");
		
		return get_doublev_reenter(ctx, pname, *params);
	}
	
	static GLenum get_error_replacement(GLIContext ctx)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_error called.");
		
		return get_error_reenter(ctx);
	}
	
	static void get_floatv_replacement(GLIContext ctx, GLenum pname, GLfloat *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_floatv called.");
		
		return get_floatv_reenter(ctx, pname, *params);
	}
	
	static void get_integerv_replacement(GLIContext ctx, GLenum pname, GLint *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_integerv called.");
		
		return get_integerv_reenter(ctx, pname, *params);
	}
	
	static void get_lightfv_replacement(GLIContext ctx, GLenum light, GLenum pname, GLfloat *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_lightfv called.");
		
		return get_lightfv_reenter(ctx, light, pname, *params);
	}
	
	static void get_lightiv_replacement(GLIContext ctx, GLenum light, GLenum pname, GLint *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_lightiv called.");
		
		return get_lightiv_reenter(ctx, light, pname, *params);
	}
	
	static void get_mapdv_replacement(GLIContext ctx, GLenum target, GLenum query, GLdouble *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_mapdv called.");
		
		return get_mapdv_reenter(ctx, target, query, *v);
	}
	
	static void get_mapfv_replacement(GLIContext ctx, GLenum target, GLenum query, GLfloat *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_mapfv called.");
		
		return get_mapfv_reenter(ctx, target, query, *v);
	}
	
	static void get_mapiv_replacement(GLIContext ctx, GLenum target, GLenum query, GLint *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_mapiv called.");
		
		return get_mapiv_reenter(ctx, target, query, *v);
	}
	
	static void get_materialfv_replacement(GLIContext ctx, GLenum face, GLenum pname, GLfloat *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_materialfv called.");
		
		return get_materialfv_reenter(ctx, face, pname, *params);
	}
	
	static void get_materialiv_replacement(GLIContext ctx, GLenum face, GLenum pname, GLint *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_materialiv called.");
		
		return get_materialiv_reenter(ctx, face, pname, *params);
	}
	
	static void get_pixel_mapfv_replacement(GLIContext ctx, GLenum map, GLfloat *values)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_pixel_mapfv called.");
		
		return get_pixel_mapfv_reenter(ctx, map, *values);
	}
	
	static void get_pixel_mapuiv_replacement(GLIContext ctx, GLenum map, GLuint *values)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_pixel_mapuiv called.");
		
		return get_pixel_mapuiv_reenter(ctx, map, *values);
	}
	
	static void get_pixel_mapusv_replacement(GLIContext ctx, GLenum map, GLushort *values)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_pixel_mapusv called.");
		
		return get_pixel_mapusv_reenter(ctx, map, *values);
	}
	
	static void get_pointerv_replacement(GLIContext ctx, GLenum pname, GLvoid **params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_pointerv called.");
		
		return get_pointerv_reenter(ctx, pname, **params);
	}
	
	static void get_polygon_stipple_replacement(GLIContext ctx, GLubyte *mask)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_polygon_stipple called.");
		
		return get_polygon_stipple_reenter(ctx, *mask);
	}
	
	static void get_tex_envfv_replacement(GLIContext ctx, GLenum target, GLenum pname, GLfloat *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_tex_envfv called.");
		
		return get_tex_envfv_reenter(ctx, target, pname, *params);
	}
	
	static void get_tex_enviv_replacement(GLIContext ctx, GLenum target, GLenum pname, GLint *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_tex_enviv called.");
		
		return get_tex_enviv_reenter(ctx, target, pname, *params);
	}
	
	static void get_tex_gendv_replacement(GLIContext ctx, GLenum coord, GLenum pname, GLdouble *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_tex_gendv called.");
		
		return get_tex_gendv_reenter(ctx, coord, pname, *params);
	}
	
	static void get_tex_genfv_replacement(GLIContext ctx, GLenum coord, GLenum pname, GLfloat *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_tex_genfv called.");
		
		return get_tex_genfv_reenter(ctx, coord, pname, *params);
	}
	
	static void get_tex_geniv_replacement(GLIContext ctx, GLenum coord, GLenum pname, GLint *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_tex_geniv called.");
		
		return get_tex_geniv_reenter(ctx, coord, pname, *params);
	}
	
	static void get_tex_image_replacement(GLIContext ctx, GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_tex_image called.");
		
		return get_tex_image_reenter(ctx, target, level, format, type, *pixels);
	}
	
	static void get_tex_level_parameterfv_replacement(GLIContext ctx, GLenum target, GLint level, GLenum pname, GLfloat *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_tex_level_parameterfv called.");
		
		return get_tex_level_parameterfv_reenter(ctx, target, level, pname, *params);
	}
	
	static void get_tex_level_parameteriv_replacement(GLIContext ctx, GLenum target, GLint level, GLenum pname, GLint *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_tex_level_parameteriv called.");
		
		return get_tex_level_parameteriv_reenter(ctx, target, level, pname, *params);
	}
	
	static void get_tex_parameterfv_replacement(GLIContext ctx, GLenum target, GLenum pname, GLfloat *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_tex_parameterfv called.");
		
		return get_tex_parameterfv_reenter(ctx, target, pname, *params);
	}
	
	static void get_tex_parameteriv_replacement(GLIContext ctx, GLenum target, GLenum pname, GLint *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_tex_parameteriv called.");
		
		return get_tex_parameteriv_reenter(ctx, target, pname, *params);
	}
	
	static void hint_replacement(GLIContext ctx, GLenum target, GLenum mode)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: hint called.");
		
		return hint_reenter(ctx, target, mode);
	}
	
	static void index_mask_replacement(GLIContext ctx, GLuint mask)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: index_mask called.");
		
		return index_mask_reenter(ctx, mask);
	}
	
	static void index_pointer_replacement(GLIContext ctx, GLenum type, GLsizei stride, const GLvoid *pointer)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: index_pointer called.");
		
		return index_pointer_reenter(ctx, type, stride, GLvoid);
	}
	
	static void indexd_replacement(GLIContext ctx, GLdouble c)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: indexd called.");
		
		return indexd_reenter(ctx, c);
	}
	
	static void indexdv_replacement(GLIContext ctx, const GLdouble *c)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: indexdv called.");
		
		return indexdv_reenter(ctx, GLdouble);
	}
	
	static void indexf_replacement(GLIContext ctx, GLfloat c)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: indexf called.");
		
		return indexf_reenter(ctx, c);
	}
	
	static void indexfv_replacement(GLIContext ctx, const GLfloat *c)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: indexfv called.");
		
		return indexfv_reenter(ctx, GLfloat);
	}
	
	static void indexi_replacement(GLIContext ctx, GLint c)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: indexi called.");
		
		return indexi_reenter(ctx, c);
	}
	
	static void indexiv_replacement(GLIContext ctx, const GLint *c)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: indexiv called.");
		
		return indexiv_reenter(ctx, GLint);
	}
	
	static void indexs_replacement(GLIContext ctx, GLshort c)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: indexs called.");
		
		return indexs_reenter(ctx, c);
	}
	
	static void indexsv_replacement(GLIContext ctx, const GLshort *c)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: indexsv called.");
		
		return indexsv_reenter(ctx, GLshort);
	}
	
	static void indexub_replacement(GLIContext ctx, GLubyte c)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: indexub called.");
		
		return indexub_reenter(ctx, c);
	}
	
	static void indexubv_replacement(GLIContext ctx, const GLubyte *c)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: indexubv called.");
		
		return indexubv_reenter(ctx, GLubyte);
	}
	
	static void init_names_replacement(GLIContext ctx)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: init_names called.");
		
		return init_names_reenter(ctx);
	}
	
	static void interleaved_arrays_replacement(GLIContext ctx, GLenum format, GLsizei stride, const GLvoid *pointer)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: interleaved_arrays called.");
		
		return interleaved_arrays_reenter(ctx, format, stride, GLvoid);
	}
	
	static GLboolean is_enabled_replacement(GLIContext ctx, GLenum cap)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: is_enabled called.");
		
		return is_enabled_reenter(ctx, cap);
	}
	
	static GLboolean is_list_replacement(GLIContext ctx, GLuint list)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: is_list called.");
		
		return is_list_reenter(ctx, list);
	}
	
	static GLboolean is_texture_replacement(GLIContext ctx, GLuint texture)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: is_texture called.");
		
		return is_texture_reenter(ctx, texture);
	}
	
	static void light_modelf_replacement(GLIContext ctx, GLenum pname, GLfloat param)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: light_modelf called.");
		
		return light_modelf_reenter(ctx, pname, param);
	}
	
	static void light_modelfv_replacement(GLIContext ctx, GLenum pname, const GLfloat *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: light_modelfv called.");
		
		return light_modelfv_reenter(ctx, pname, GLfloat);
	}
	
	static void light_modeli_replacement(GLIContext ctx, GLenum pname, GLint param)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: light_modeli called.");
		
		return light_modeli_reenter(ctx, pname, param);
	}
	
	static void light_modeliv_replacement(GLIContext ctx, GLenum pname, const GLint *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: light_modeliv called.");
		
		return light_modeliv_reenter(ctx, pname, GLint);
	}
	
	static void lightf_replacement(GLIContext ctx, GLenum light, GLenum pname, GLfloat param)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: lightf called.");
		
		return lightf_reenter(ctx, light, pname, param);
	}
	
	static void lightfv_replacement(GLIContext ctx, GLenum light, GLenum pname, const GLfloat *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: lightfv called.");
		
		return lightfv_reenter(ctx, light, pname, GLfloat);
	}
	
	static void lighti_replacement(GLIContext ctx, GLenum light, GLenum pname, GLint param)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: lighti called.");
		
		return lighti_reenter(ctx, light, pname, param);
	}
	
	static void lightiv_replacement(GLIContext ctx, GLenum light, GLenum pname, const GLint *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: lightiv called.");
		
		return lightiv_reenter(ctx, light, pname, GLint);
	}
	
	static void line_stipple_replacement(GLIContext ctx, GLint factor, GLushort pattern)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: line_stipple called.");
		
		return line_stipple_reenter(ctx, factor, pattern);
	}
	
	static void line_width_replacement(GLIContext ctx, GLfloat width)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: line_width called.");
		
		return line_width_reenter(ctx, width);
	}
	
	static void list_base_replacement(GLIContext ctx, GLuint base)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: list_base called.");
		
		return list_base_reenter(ctx, base);
	}
	
	static void load_identity_replacement(GLIContext ctx)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: load_identity called.");
		
		return load_identity_reenter(ctx);
	}
	
	static void load_matrixd_replacement(GLIContext ctx, const GLdouble *m)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: load_matrixd called.");
		
		return load_matrixd_reenter(ctx, GLdouble);
	}
	
	static void load_matrixf_replacement(GLIContext ctx, const GLfloat *m)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: load_matrixf called.");
		
		return load_matrixf_reenter(ctx, GLfloat);
	}
	
	static void load_name_replacement(GLIContext ctx, GLuint name)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: load_name called.");
		
		return load_name_reenter(ctx, name);
	}
	
	static void logic_op_replacement(GLIContext ctx, GLenum opcode)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: logic_op called.");
		
		return logic_op_reenter(ctx, opcode);
	}
	
	static void map1d_replacement(GLIContext ctx, GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: map1d called.");
		
		return map1d_reenter(ctx, target, u1, u2, stride, order, GLdouble);
	}
	
	static void map1f_replacement(GLIContext ctx, GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: map1f called.");
		
		return map1f_reenter(ctx, target, u1, u2, stride, order, GLfloat);
	}
	
	static void map2d_replacement(GLIContext ctx, GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: map2d called.");
		
		return map2d_reenter(ctx, target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, GLdouble);
	}
	
	static void map2f_replacement(GLIContext ctx, GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: map2f called.");
		
		return map2f_reenter(ctx, target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, GLfloat);
	}
	
	static void map_grid1d_replacement(GLIContext ctx, GLint un, GLdouble u1, GLdouble u2)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: map_grid1d called.");
		
		return map_grid1d_reenter(ctx, un, u1, u2);
	}
	
	static void map_grid1f_replacement(GLIContext ctx, GLint un, GLfloat u1, GLfloat u2)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: map_grid1f called.");
		
		return map_grid1f_reenter(ctx, un, u1, u2);
	}
	
	static void map_grid2d_replacement(GLIContext ctx, GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: map_grid2d called.");
		
		return map_grid2d_reenter(ctx, un, u1, u2, vn, v1, v2);
	}
	
	static void map_grid2f_replacement(GLIContext ctx, GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: map_grid2f called.");
		
		return map_grid2f_reenter(ctx, un, u1, u2, vn, v1, v2);
	}
	
	static void materialf_replacement(GLIContext ctx, GLenum face, GLenum pname, GLfloat param)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: materialf called.");
		
		return materialf_reenter(ctx, face, pname, param);
	}
	
	static void materialfv_replacement(GLIContext ctx, GLenum face, GLenum pname, const GLfloat *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: materialfv called.");
		
		return materialfv_reenter(ctx, face, pname, GLfloat);
	}
	
	static void materiali_replacement(GLIContext ctx, GLenum face, GLenum pname, GLint param)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: materiali called.");
		
		return materiali_reenter(ctx, face, pname, param);
	}
	
	static void materialiv_replacement(GLIContext ctx, GLenum face, GLenum pname, const GLint *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: materialiv called.");
		
		return materialiv_reenter(ctx, face, pname, GLint);
	}
	
	static void matrix_mode_replacement(GLIContext ctx, GLenum mode)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: matrix_mode called.");
		
		return matrix_mode_reenter(ctx, mode);
	}
	
	static void mult_matrixd_replacement(GLIContext ctx, const GLdouble *m)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: mult_matrixd called.");
		
		return mult_matrixd_reenter(ctx, GLdouble);
	}
	
	static void mult_matrixf_replacement(GLIContext ctx, const GLfloat *m)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: mult_matrixf called.");
		
		return mult_matrixf_reenter(ctx, GLfloat);
	}
	
	static void new_list_replacement(GLIContext ctx, GLuint list, GLenum mode)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: new_list called.");
		
		return new_list_reenter(ctx, list, mode);
	}
	
	static void normal3b_replacement(GLIContext ctx, GLbyte nx, GLbyte ny, GLbyte nz)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: normal3b called.");
		
		return normal3b_reenter(ctx, nx, ny, nz);
	}
	
	static void normal3bv_replacement(GLIContext ctx, const GLbyte *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: normal3bv called.");
		
		return normal3bv_reenter(ctx, GLbyte);
	}
	
	static void normal3d_replacement(GLIContext ctx, GLdouble nx, GLdouble ny, GLdouble nz)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: normal3d called.");
		
		return normal3d_reenter(ctx, nx, ny, nz);
	}
	
	static void normal3dv_replacement(GLIContext ctx, const GLdouble *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: normal3dv called.");
		
		return normal3dv_reenter(ctx, GLdouble);
	}
	
	static void normal3f_replacement(GLIContext ctx, GLfloat nx, GLfloat ny, GLfloat nz)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: normal3f called.");
		
		return normal3f_reenter(ctx, nx, ny, nz);
	}
	
	static void normal3fv_replacement(GLIContext ctx, const GLfloat *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: normal3fv called.");
		
		return normal3fv_reenter(ctx, GLfloat);
	}
	
	static void normal3i_replacement(GLIContext ctx, GLint nx, GLint ny, GLint nz)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: normal3i called.");
		
		return normal3i_reenter(ctx, nx, ny, nz);
	}
	
	static void normal3iv_replacement(GLIContext ctx, const GLint *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: normal3iv called.");
		
		return normal3iv_reenter(ctx, GLint);
	}
	
	static void normal3s_replacement(GLIContext ctx, GLshort nx, GLshort ny, GLshort nz)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: normal3s called.");
		
		return normal3s_reenter(ctx, nx, ny, nz);
	}
	
	static void normal3sv_replacement(GLIContext ctx, const GLshort *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: normal3sv called.");
		
		return normal3sv_reenter(ctx, GLshort);
	}
	
	static void normal_pointer_replacement(GLIContext ctx, GLenum type, GLsizei stride, const GLvoid *pointer)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: normal_pointer called.");
		
		return normal_pointer_reenter(ctx, type, stride, GLvoid);
	}
	
	static void ortho_replacement(GLIContext ctx, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: ortho called.");
		
		return ortho_reenter(ctx, left, right, bottom, top, zNear, zFar);
	}
	
	static void pass_through_replacement(GLIContext ctx, GLfloat token)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: pass_through called.");
		
		return pass_through_reenter(ctx, token);
	}
	
	static void pixel_mapfv_replacement(GLIContext ctx, GLenum map, GLsizei mapsize, const GLfloat *values)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: pixel_mapfv called.");
		
		return pixel_mapfv_reenter(ctx, map, mapsize, GLfloat);
	}
	
	static void pixel_mapuiv_replacement(GLIContext ctx, GLenum map, GLsizei mapsize, const GLuint *values)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: pixel_mapuiv called.");
		
		return pixel_mapuiv_reenter(ctx, map, mapsize, GLuint);
	}
	
	static void pixel_mapusv_replacement(GLIContext ctx, GLenum map, GLsizei mapsize, const GLushort *values)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: pixel_mapusv called.");
		
		return pixel_mapusv_reenter(ctx, map, mapsize, GLushort);
	}
	
	static void pixel_storef_replacement(GLIContext ctx, GLenum pname, GLfloat param)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: pixel_storef called.");
		
		return pixel_storef_reenter(ctx, pname, param);
	}
	
	static void pixel_storei_replacement(GLIContext ctx, GLenum pname, GLint param)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: pixel_storei called.");
		
		return pixel_storei_reenter(ctx, pname, param);
	}
	
	static void pixel_transferf_replacement(GLIContext ctx, GLenum pname, GLfloat param)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: pixel_transferf called.");
		
		return pixel_transferf_reenter(ctx, pname, param);
	}
	
	static void pixel_transferi_replacement(GLIContext ctx, GLenum pname, GLint param)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: pixel_transferi called.");
		
		return pixel_transferi_reenter(ctx, pname, param);
	}
	
	static void pixel_zoom_replacement(GLIContext ctx, GLfloat xfactor, GLfloat yfactor)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: pixel_zoom called.");
		
		return pixel_zoom_reenter(ctx, xfactor, yfactor);
	}
	
	static void point_size_replacement(GLIContext ctx, GLfloat size)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: point_size called.");
		
		return point_size_reenter(ctx, size);
	}
	
	static void polygon_mode_replacement(GLIContext ctx, GLenum face, GLenum mode)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: polygon_mode called.");
		
		return polygon_mode_reenter(ctx, face, mode);
	}
	
	static void polygon_offset_replacement(GLIContext ctx, GLfloat factor, GLfloat units)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: polygon_offset called.");
		
		return polygon_offset_reenter(ctx, factor, units);
	}
	
	static void polygon_stipple_replacement(GLIContext ctx, const GLubyte *mask)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: polygon_stipple called.");
		
		return polygon_stipple_reenter(ctx, GLubyte);
	}
	
	static void pop_attrib_replacement(GLIContext ctx)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: pop_attrib called.");
		
		return pop_attrib_reenter(ctx);
	}
	
	static void pop_client_attrib_replacement(GLIContext ctx)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: pop_client_attrib called.");
		
		return pop_client_attrib_reenter(ctx);
	}
	
	static void pop_matrix_replacement(GLIContext ctx)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: pop_matrix called.");
		
		return pop_matrix_reenter(ctx);
	}
	
	static void pop_name_replacement(GLIContext ctx)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: pop_name called.");
		
		return pop_name_reenter(ctx);
	}
	
	static void prioritize_textures_replacement(GLIContext ctx, GLsizei n, const GLuint *textures, const GLclampf *priorities)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: prioritize_textures called.");
		
		return prioritize_textures_reenter(ctx, n, GLuint const *priorities);
	}
	
	static void push_attrib_replacement(GLIContext ctx, GLbitfield mask)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: push_attrib called.");
		
		return push_attrib_reenter(ctx, mask);
	}
	
	static void push_client_attrib_replacement(GLIContext ctx, GLbitfield mask)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: push_client_attrib called.");
		
		return push_client_attrib_reenter(ctx, mask);
	}
	
	static void push_matrix_replacement(GLIContext ctx)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: push_matrix called.");
		
		return push_matrix_reenter(ctx);
	}
	
	static void push_name_replacement(GLIContext ctx, GLuint name)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: push_name called.");
		
		return push_name_reenter(ctx, name);
	}
	
	static void raster_pos2d_replacement(GLIContext ctx, GLdouble x, GLdouble y)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: raster_pos2d called.");
		
		return raster_pos2d_reenter(ctx, x, y);
	}
	
	static void raster_pos2dv_replacement(GLIContext ctx, const GLdouble *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: raster_pos2dv called.");
		
		return raster_pos2dv_reenter(ctx, GLdouble);
	}
	
	static void raster_pos2f_replacement(GLIContext ctx, GLfloat x, GLfloat y)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: raster_pos2f called.");
		
		return raster_pos2f_reenter(ctx, x, y);
	}
	
	static void raster_pos2fv_replacement(GLIContext ctx, const GLfloat *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: raster_pos2fv called.");
		
		return raster_pos2fv_reenter(ctx, GLfloat);
	}
	
	static void raster_pos2i_replacement(GLIContext ctx, GLint x, GLint y)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: raster_pos2i called.");
		
		return raster_pos2i_reenter(ctx, x, y);
	}
	
	static void raster_pos2iv_replacement(GLIContext ctx, const GLint *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: raster_pos2iv called.");
		
		return raster_pos2iv_reenter(ctx, GLint);
	}
	
	static void raster_pos2s_replacement(GLIContext ctx, GLshort x, GLshort y)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: raster_pos2s called.");
		
		return raster_pos2s_reenter(ctx, x, y);
	}
	
	static void raster_pos2sv_replacement(GLIContext ctx, const GLshort *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: raster_pos2sv called.");
		
		return raster_pos2sv_reenter(ctx, GLshort);
	}
	
	static void raster_pos3d_replacement(GLIContext ctx, GLdouble x, GLdouble y, GLdouble z)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: raster_pos3d called.");
		
		return raster_pos3d_reenter(ctx, x, y, z);
	}
	
	static void raster_pos3dv_replacement(GLIContext ctx, const GLdouble *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: raster_pos3dv called.");
		
		return raster_pos3dv_reenter(ctx, GLdouble);
	}
	
	static void raster_pos3f_replacement(GLIContext ctx, GLfloat x, GLfloat y, GLfloat z)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: raster_pos3f called.");
		
		return raster_pos3f_reenter(ctx, x, y, z);
	}
	
	static void raster_pos3fv_replacement(GLIContext ctx, const GLfloat *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: raster_pos3fv called.");
		
		return raster_pos3fv_reenter(ctx, GLfloat);
	}
	
	static void raster_pos3i_replacement(GLIContext ctx, GLint x, GLint y, GLint z)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: raster_pos3i called.");
		
		return raster_pos3i_reenter(ctx, x, y, z);
	}
	
	static void raster_pos3iv_replacement(GLIContext ctx, const GLint *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: raster_pos3iv called.");
		
		return raster_pos3iv_reenter(ctx, GLint);
	}
	
	static void raster_pos3s_replacement(GLIContext ctx, GLshort x, GLshort y, GLshort z)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: raster_pos3s called.");
		
		return raster_pos3s_reenter(ctx, x, y, z);
	}
	
	static void raster_pos3sv_replacement(GLIContext ctx, const GLshort *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: raster_pos3sv called.");
		
		return raster_pos3sv_reenter(ctx, GLshort);
	}
	
	static void raster_pos4d_replacement(GLIContext ctx, GLdouble x, GLdouble y, GLdouble z, GLdouble w)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: raster_pos4d called.");
		
		return raster_pos4d_reenter(ctx, x, y, z, w);
	}
	
	static void raster_pos4dv_replacement(GLIContext ctx, const GLdouble *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: raster_pos4dv called.");
		
		return raster_pos4dv_reenter(ctx, GLdouble);
	}
	
	static void raster_pos4f_replacement(GLIContext ctx, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: raster_pos4f called.");
		
		return raster_pos4f_reenter(ctx, x, y, z, w);
	}
	
	static void raster_pos4fv_replacement(GLIContext ctx, const GLfloat *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: raster_pos4fv called.");
		
		return raster_pos4fv_reenter(ctx, GLfloat);
	}
	
	static void raster_pos4i_replacement(GLIContext ctx, GLint x, GLint y, GLint z, GLint w)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: raster_pos4i called.");
		
		return raster_pos4i_reenter(ctx, x, y, z, w);
	}
	
	static void raster_pos4iv_replacement(GLIContext ctx, const GLint *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: raster_pos4iv called.");
		
		return raster_pos4iv_reenter(ctx, GLint);
	}
	
	static void raster_pos4s_replacement(GLIContext ctx, GLshort x, GLshort y, GLshort z, GLshort w)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: raster_pos4s called.");
		
		return raster_pos4s_reenter(ctx, x, y, z, w);
	}
	
	static void raster_pos4sv_replacement(GLIContext ctx, const GLshort *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: raster_pos4sv called.");
		
		return raster_pos4sv_reenter(ctx, GLshort);
	}
	
	static void read_buffer_replacement(GLIContext ctx, GLenum mode)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: read_buffer called.");
		
		return read_buffer_reenter(ctx, mode);
	}
	
	static void read_pixels_replacement(GLIContext ctx, GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: read_pixels called.");
		
		return read_pixels_reenter(ctx, x, y, width, height, format, type, *pixels);
	}
	
	static void rectd_replacement(GLIContext ctx, GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: rectd called.");
		
		return rectd_reenter(ctx, x1, y1, x2, y2);
	}
	
	static void rectdv_replacement(GLIContext ctx, const GLdouble *v1, const GLdouble *v2)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: rectdv called.");
		
		return rectdv_reenter(ctx, GLdouble const *v2);
	}
	
	static void rectf_replacement(GLIContext ctx, GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: rectf called.");
		
		return rectf_reenter(ctx, x1, y1, x2, y2);
	}
	
	static void rectfv_replacement(GLIContext ctx, const GLfloat *v1, const GLfloat *v2)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: rectfv called.");
		
		return rectfv_reenter(ctx, GLfloat const *v2);
	}
	
	static void recti_replacement(GLIContext ctx, GLint x1, GLint y1, GLint x2, GLint y2)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: recti called.");
		
		return recti_reenter(ctx, x1, y1, x2, y2);
	}
	
	static void rectiv_replacement(GLIContext ctx, const GLint *v1, const GLint *v2)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: rectiv called.");
		
		return rectiv_reenter(ctx, GLint const *v2);
	}
	
	static void rects_replacement(GLIContext ctx, GLshort x1, GLshort y1, GLshort x2, GLshort y2)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: rects called.");
		
		return rects_reenter(ctx, x1, y1, x2, y2);
	}
	
	static void rectsv_replacement(GLIContext ctx, const GLshort *v1, const GLshort *v2)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: rectsv called.");
		
		return rectsv_reenter(ctx, GLshort const *v2);
	}
	
	static GLint render_mode_replacement(GLIContext ctx, GLenum mode)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: render_mode called.");
		
		return render_mode_reenter(ctx, mode);
	}
	
	static void rotated_replacement(GLIContext ctx, GLdouble angle, GLdouble x, GLdouble y, GLdouble z)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: rotated called.");
		
		return rotated_reenter(ctx, angle, x, y, z);
	}
	
	static void rotatef_replacement(GLIContext ctx, GLfloat angle, GLfloat x, GLfloat y, GLfloat z)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: rotatef called.");
		
		return rotatef_reenter(ctx, angle, x, y, z);
	}
	
	static void scaled_replacement(GLIContext ctx, GLdouble x, GLdouble y, GLdouble z)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: scaled called.");
		
		return scaled_reenter(ctx, x, y, z);
	}
	
	static void scalef_replacement(GLIContext ctx, GLfloat x, GLfloat y, GLfloat z)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: scalef called.");
		
		return scalef_reenter(ctx, x, y, z);
	}
	
	static void scissor_replacement(GLIContext ctx, GLint x, GLint y, GLsizei width, GLsizei height)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: scissor called.");
		
		return scissor_reenter(ctx, x, y, width, height);
	}
	
	static void select_buffer_replacement(GLIContext ctx, GLsizei size, GLuint *buffer)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: select_buffer called.");
		
		return select_buffer_reenter(ctx, size, *buffer);
	}
	
	static void shade_model_replacement(GLIContext ctx, GLenum mode)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: shade_model called.");
		
		return shade_model_reenter(ctx, mode);
	}
	
	static void stencil_func_replacement(GLIContext ctx, GLenum func, GLint ref, GLuint mask)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: stencil_func called.");
		
		return stencil_func_reenter(ctx, func, ref, mask);
	}
	
	static void stencil_mask_replacement(GLIContext ctx, GLuint mask)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: stencil_mask called.");
		
		return stencil_mask_reenter(ctx, mask);
	}
	
	static void stencil_op_replacement(GLIContext ctx, GLenum fail, GLenum zfail, GLenum zpass)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: stencil_op called.");
		
		return stencil_op_reenter(ctx, fail, zfail, zpass);
	}
	
	static void tex_coord1d_replacement(GLIContext ctx, GLdouble s)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_coord1d called.");
		
		return tex_coord1d_reenter(ctx, s);
	}
	
	static void tex_coord1dv_replacement(GLIContext ctx, const GLdouble *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_coord1dv called.");
		
		return tex_coord1dv_reenter(ctx, GLdouble);
	}
	
	static void tex_coord1f_replacement(GLIContext ctx, GLfloat s)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_coord1f called.");
		
		return tex_coord1f_reenter(ctx, s);
	}
	
	static void tex_coord1fv_replacement(GLIContext ctx, const GLfloat *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_coord1fv called.");
		
		return tex_coord1fv_reenter(ctx, GLfloat);
	}
	
	static void tex_coord1i_replacement(GLIContext ctx, GLint s)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_coord1i called.");
		
		return tex_coord1i_reenter(ctx, s);
	}
	
	static void tex_coord1iv_replacement(GLIContext ctx, const GLint *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_coord1iv called.");
		
		return tex_coord1iv_reenter(ctx, GLint);
	}
	
	static void tex_coord1s_replacement(GLIContext ctx, GLshort s)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_coord1s called.");
		
		return tex_coord1s_reenter(ctx, s);
	}
	
	static void tex_coord1sv_replacement(GLIContext ctx, const GLshort *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_coord1sv called.");
		
		return tex_coord1sv_reenter(ctx, GLshort);
	}
	
	static void tex_coord2d_replacement(GLIContext ctx, GLdouble s, GLdouble t)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_coord2d called.");
		
		return tex_coord2d_reenter(ctx, s, t);
	}
	
	static void tex_coord2dv_replacement(GLIContext ctx, const GLdouble *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_coord2dv called.");
		
		return tex_coord2dv_reenter(ctx, GLdouble);
	}
	
	static void tex_coord2f_replacement(GLIContext ctx, GLfloat s, GLfloat t)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_coord2f called.");
		
		return tex_coord2f_reenter(ctx, s, t);
	}
	
	static void tex_coord2fv_replacement(GLIContext ctx, const GLfloat *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_coord2fv called.");
		
		return tex_coord2fv_reenter(ctx, GLfloat);
	}
	
	static void tex_coord2i_replacement(GLIContext ctx, GLint s, GLint t)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_coord2i called.");
		
		return tex_coord2i_reenter(ctx, s, t);
	}
	
	static void tex_coord2iv_replacement(GLIContext ctx, const GLint *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_coord2iv called.");
		
		return tex_coord2iv_reenter(ctx, GLint);
	}
	
	static void tex_coord2s_replacement(GLIContext ctx, GLshort s, GLshort t)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_coord2s called.");
		
		return tex_coord2s_reenter(ctx, s, t);
	}
	
	static void tex_coord2sv_replacement(GLIContext ctx, const GLshort *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_coord2sv called.");
		
		return tex_coord2sv_reenter(ctx, GLshort);
	}
	
	static void tex_coord3d_replacement(GLIContext ctx, GLdouble s, GLdouble t, GLdouble r)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_coord3d called.");
		
		return tex_coord3d_reenter(ctx, s, t, r);
	}
	
	static void tex_coord3dv_replacement(GLIContext ctx, const GLdouble *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_coord3dv called.");
		
		return tex_coord3dv_reenter(ctx, GLdouble);
	}
	
	static void tex_coord3f_replacement(GLIContext ctx, GLfloat s, GLfloat t, GLfloat r)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_coord3f called.");
		
		return tex_coord3f_reenter(ctx, s, t, r);
	}
	
	static void tex_coord3fv_replacement(GLIContext ctx, const GLfloat *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_coord3fv called.");
		
		return tex_coord3fv_reenter(ctx, GLfloat);
	}
	
	static void tex_coord3i_replacement(GLIContext ctx, GLint s, GLint t, GLint r)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_coord3i called.");
		
		return tex_coord3i_reenter(ctx, s, t, r);
	}
	
	static void tex_coord3iv_replacement(GLIContext ctx, const GLint *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_coord3iv called.");
		
		return tex_coord3iv_reenter(ctx, GLint);
	}
	
	static void tex_coord3s_replacement(GLIContext ctx, GLshort s, GLshort t, GLshort r)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_coord3s called.");
		
		return tex_coord3s_reenter(ctx, s, t, r);
	}
	
	static void tex_coord3sv_replacement(GLIContext ctx, const GLshort *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_coord3sv called.");
		
		return tex_coord3sv_reenter(ctx, GLshort);
	}
	
	static void tex_coord4d_replacement(GLIContext ctx, GLdouble s, GLdouble t, GLdouble r, GLdouble q)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_coord4d called.");
		
		return tex_coord4d_reenter(ctx, s, t, r, q);
	}
	
	static void tex_coord4dv_replacement(GLIContext ctx, const GLdouble *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_coord4dv called.");
		
		return tex_coord4dv_reenter(ctx, GLdouble);
	}
	
	static void tex_coord4f_replacement(GLIContext ctx, GLfloat s, GLfloat t, GLfloat r, GLfloat q)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_coord4f called.");
		
		return tex_coord4f_reenter(ctx, s, t, r, q);
	}
	
	static void tex_coord4fv_replacement(GLIContext ctx, const GLfloat *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_coord4fv called.");
		
		return tex_coord4fv_reenter(ctx, GLfloat);
	}
	
	static void tex_coord4i_replacement(GLIContext ctx, GLint s, GLint t, GLint r, GLint q)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_coord4i called.");
		
		return tex_coord4i_reenter(ctx, s, t, r, q);
	}
	
	static void tex_coord4iv_replacement(GLIContext ctx, const GLint *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_coord4iv called.");
		
		return tex_coord4iv_reenter(ctx, GLint);
	}
	
	static void tex_coord4s_replacement(GLIContext ctx, GLshort s, GLshort t, GLshort r, GLshort q)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_coord4s called.");
		
		return tex_coord4s_reenter(ctx, s, t, r, q);
	}
	
	static void tex_coord4sv_replacement(GLIContext ctx, const GLshort *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_coord4sv called.");
		
		return tex_coord4sv_reenter(ctx, GLshort);
	}
	
	static void tex_coord_pointer_replacement(GLIContext ctx, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_coord_pointer called.");
		
		return tex_coord_pointer_reenter(ctx, size, type, stride, GLvoid);
	}
	
	static void tex_envf_replacement(GLIContext ctx, GLenum target, GLenum pname, GLfloat param)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_envf called.");
		
		return tex_envf_reenter(ctx, target, pname, param);
	}
	
	static void tex_envfv_replacement(GLIContext ctx, GLenum target, GLenum pname, const GLfloat *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_envfv called.");
		
		return tex_envfv_reenter(ctx, target, pname, GLfloat);
	}
	
	static void tex_envi_replacement(GLIContext ctx, GLenum target, GLenum pname, GLint param)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_envi called.");
		
		return tex_envi_reenter(ctx, target, pname, param);
	}
	
	static void tex_enviv_replacement(GLIContext ctx, GLenum target, GLenum pname, const GLint *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_enviv called.");
		
		return tex_enviv_reenter(ctx, target, pname, GLint);
	}
	
	static void tex_gend_replacement(GLIContext ctx, GLenum coord, GLenum pname, GLdouble param)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_gend called.");
		
		return tex_gend_reenter(ctx, coord, pname, param);
	}
	
	static void tex_gendv_replacement(GLIContext ctx, GLenum coord, GLenum pname, const GLdouble *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_gendv called.");
		
		return tex_gendv_reenter(ctx, coord, pname, GLdouble);
	}
	
	static void tex_genf_replacement(GLIContext ctx, GLenum coord, GLenum pname, GLfloat param)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_genf called.");
		
		return tex_genf_reenter(ctx, coord, pname, param);
	}
	
	static void tex_genfv_replacement(GLIContext ctx, GLenum coord, GLenum pname, const GLfloat *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_genfv called.");
		
		return tex_genfv_reenter(ctx, coord, pname, GLfloat);
	}
	
	static void tex_geni_replacement(GLIContext ctx, GLenum coord, GLenum pname, GLint param)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_geni called.");
		
		return tex_geni_reenter(ctx, coord, pname, param);
	}
	
	static void tex_geniv_replacement(GLIContext ctx, GLenum coord, GLenum pname, const GLint *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_geniv called.");
		
		return tex_geniv_reenter(ctx, coord, pname, GLint);
	}
	
	static void tex_image1D_replacement(GLIContext ctx, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_image1D called.");
		
		return tex_image1D_reenter(ctx, target, level, internalformat, width, border, format, type, GLvoid);
	}
	
	static void tex_image2D_replacement(GLIContext ctx, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_image2D called.");
		
		return tex_image2D_reenter(ctx, target, level, internalformat, width, height, border, format, type, GLvoid);
	}
	
	static void tex_parameterf_replacement(GLIContext ctx, GLenum target, GLenum pname, GLfloat param)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_parameterf called.");
		
		return tex_parameterf_reenter(ctx, target, pname, param);
	}
	
	static void tex_parameterfv_replacement(GLIContext ctx, GLenum target, GLenum pname, const GLfloat *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_parameterfv called.");
		
		return tex_parameterfv_reenter(ctx, target, pname, GLfloat);
	}
	
	static void tex_parameteri_replacement(GLIContext ctx, GLenum target, GLenum pname, GLint param)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_parameteri called.");
		
		return tex_parameteri_reenter(ctx, target, pname, param);
	}
	
	static void tex_parameteriv_replacement(GLIContext ctx, GLenum target, GLenum pname, const GLint *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_parameteriv called.");
		
		return tex_parameteriv_reenter(ctx, target, pname, GLint);
	}
	
	static void tex_sub_image1D_replacement(GLIContext ctx, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_sub_image1D called.");
		
		return tex_sub_image1D_reenter(ctx, target, level, xoffset, width, format, type, GLvoid);
	}
	
	static void tex_sub_image2D_replacement(GLIContext ctx, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_sub_image2D called.");
		
		return tex_sub_image2D_reenter(ctx, target, level, xoffset, yoffset, width, height, format, type, GLvoid);
	}
	
	static void translated_replacement(GLIContext ctx, GLdouble x, GLdouble y, GLdouble z)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: translated called.");
		
		return translated_reenter(ctx, x, y, z);
	}
	
	static void translatef_replacement(GLIContext ctx, GLfloat x, GLfloat y, GLfloat z)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: translatef called.");
		
		return translatef_reenter(ctx, x, y, z);
	}
	
	static void vertex2d_replacement(GLIContext ctx, GLdouble x, GLdouble y)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex2d called.");
		
		return vertex2d_reenter(ctx, x, y);
	}
	
	static void vertex2dv_replacement(GLIContext ctx, const GLdouble *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex2dv called.");
		
		return vertex2dv_reenter(ctx, GLdouble);
	}
	
	static void vertex2f_replacement(GLIContext ctx, GLfloat x, GLfloat y)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex2f called.");
		
		return vertex2f_reenter(ctx, x, y);
	}
	
	static void vertex2fv_replacement(GLIContext ctx, const GLfloat *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex2fv called.");
		
		return vertex2fv_reenter(ctx, GLfloat);
	}
	
	static void vertex2i_replacement(GLIContext ctx, GLint x, GLint y)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex2i called.");
		
		return vertex2i_reenter(ctx, x, y);
	}
	
	static void vertex2iv_replacement(GLIContext ctx, const GLint *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex2iv called.");
		
		return vertex2iv_reenter(ctx, GLint);
	}
	
	static void vertex2s_replacement(GLIContext ctx, GLshort x, GLshort y)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex2s called.");
		
		return vertex2s_reenter(ctx, x, y);
	}
	
	static void vertex2sv_replacement(GLIContext ctx, const GLshort *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex2sv called.");
		
		return vertex2sv_reenter(ctx, GLshort);
	}
	
	static void vertex3d_replacement(GLIContext ctx, GLdouble x, GLdouble y, GLdouble z)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex3d called.");
		
		return vertex3d_reenter(ctx, x, y, z);
	}
	
	static void vertex3dv_replacement(GLIContext ctx, const GLdouble *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex3dv called.");
		
		return vertex3dv_reenter(ctx, GLdouble);
	}
	
	static void vertex3f_replacement(GLIContext ctx, GLfloat x, GLfloat y, GLfloat z)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex3f called.");
		
		return vertex3f_reenter(ctx, x, y, z);
	}
	
	static void vertex3fv_replacement(GLIContext ctx, const GLfloat *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex3fv called.");
		
		return vertex3fv_reenter(ctx, GLfloat);
	}
	
	static void vertex3i_replacement(GLIContext ctx, GLint x, GLint y, GLint z)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex3i called.");
		
		return vertex3i_reenter(ctx, x, y, z);
	}
	
	static void vertex3iv_replacement(GLIContext ctx, const GLint *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex3iv called.");
		
		return vertex3iv_reenter(ctx, GLint);
	}
	
	static void vertex3s_replacement(GLIContext ctx, GLshort x, GLshort y, GLshort z)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex3s called.");
		
		return vertex3s_reenter(ctx, x, y, z);
	}
	
	static void vertex3sv_replacement(GLIContext ctx, const GLshort *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex3sv called.");
		
		return vertex3sv_reenter(ctx, GLshort);
	}
	
	static void vertex4d_replacement(GLIContext ctx, GLdouble x, GLdouble y, GLdouble z, GLdouble w)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex4d called.");
		
		return vertex4d_reenter(ctx, x, y, z, w);
	}
	
	static void vertex4dv_replacement(GLIContext ctx, const GLdouble *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex4dv called.");
		
		return vertex4dv_reenter(ctx, GLdouble);
	}
	
	static void vertex4f_replacement(GLIContext ctx, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex4f called.");
		
		return vertex4f_reenter(ctx, x, y, z, w);
	}
	
	static void vertex4fv_replacement(GLIContext ctx, const GLfloat *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex4fv called.");
		
		return vertex4fv_reenter(ctx, GLfloat);
	}
	
	static void vertex4i_replacement(GLIContext ctx, GLint x, GLint y, GLint z, GLint w)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex4i called.");
		
		return vertex4i_reenter(ctx, x, y, z, w);
	}
	
	static void vertex4iv_replacement(GLIContext ctx, const GLint *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex4iv called.");
		
		return vertex4iv_reenter(ctx, GLint);
	}
	
	static void vertex4s_replacement(GLIContext ctx, GLshort x, GLshort y, GLshort z, GLshort w)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex4s called.");
		
		return vertex4s_reenter(ctx, x, y, z, w);
	}
	
	static void vertex4sv_replacement(GLIContext ctx, const GLshort *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex4sv called.");
		
		return vertex4sv_reenter(ctx, GLshort);
	}
	
	static void vertex_pointer_replacement(GLIContext ctx, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_pointer called.");
		
		return vertex_pointer_reenter(ctx, size, type, stride, GLvoid);
	}
	
	static void viewport_replacement(GLIContext ctx, GLint x, GLint y, GLsizei width, GLsizei height)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: viewport called.");
		
		return viewport_reenter(ctx, x, y, width, height);
	}
	
	static void blend_func_separate_replacement(GLIContext ctx, GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: blend_func_separate called.");
		
		return blend_func_separate_reenter(ctx, sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
	}
	
	static void blend_color_replacement(GLIContext ctx, GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: blend_color called.");
		
		return blend_color_reenter(ctx, red, green, blue, alpha);
	}
	
	static void blend_equation_replacement(GLIContext ctx, GLenum mode)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: blend_equation called.");
		
		return blend_equation_reenter(ctx, mode);
	}
	
	static void lock_arrays_EXT_replacement(GLIContext ctx, GLint first, GLsizei count)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: lock_arrays_EXT called.");
		
		return lock_arrays_EXT_reenter(ctx, first, count);
	}
	
	static void unlock_arrays_EXT_replacement(GLIContext ctx)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: unlock_arrays_EXT called.");
		
		return unlock_arrays_EXT_reenter(ctx);
	}
	
	static void client_active_texture_replacement(GLIContext ctx, GLenum target)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: client_active_texture called.");
		
		return client_active_texture_reenter(ctx, target);
	}
	
	static void active_texture_replacement(GLIContext ctx, GLenum target)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: active_texture called.");
		
		return active_texture_reenter(ctx, target);
	}
	
	static void multi_tex_coord1d_replacement(GLIContext ctx, GLenum target, GLdouble s)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: multi_tex_coord1d called.");
		
		return multi_tex_coord1d_reenter(ctx, target, s);
	}
	
	static void multi_tex_coord1dv_replacement(GLIContext ctx, GLenum target, const GLdouble *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: multi_tex_coord1dv called.");
		
		return multi_tex_coord1dv_reenter(ctx, target, GLdouble);
	}
	
	static void multi_tex_coord1f_replacement(GLIContext ctx, GLenum target, GLfloat s)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: multi_tex_coord1f called.");
		
		return multi_tex_coord1f_reenter(ctx, target, s);
	}
	
	static void multi_tex_coord1fv_replacement(GLIContext ctx, GLenum target, const GLfloat *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: multi_tex_coord1fv called.");
		
		return multi_tex_coord1fv_reenter(ctx, target, GLfloat);
	}
	
	static void multi_tex_coord1i_replacement(GLIContext ctx, GLenum target, GLint s)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: multi_tex_coord1i called.");
		
		return multi_tex_coord1i_reenter(ctx, target, s);
	}
	
	static void multi_tex_coord1iv_replacement(GLIContext ctx, GLenum target, const GLint *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: multi_tex_coord1iv called.");
		
		return multi_tex_coord1iv_reenter(ctx, target, GLint);
	}
	
	static void multi_tex_coord1s_replacement(GLIContext ctx, GLenum target, GLshort s)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: multi_tex_coord1s called.");
		
		return multi_tex_coord1s_reenter(ctx, target, s);
	}
	
	static void multi_tex_coord1sv_replacement(GLIContext ctx, GLenum target, const GLshort *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: multi_tex_coord1sv called.");
		
		return multi_tex_coord1sv_reenter(ctx, target, GLshort);
	}
	
	static void multi_tex_coord2d_replacement(GLIContext ctx, GLenum target, GLdouble s, GLdouble t)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: multi_tex_coord2d called.");
		
		return multi_tex_coord2d_reenter(ctx, target, s, t);
	}
	
	static void multi_tex_coord2dv_replacement(GLIContext ctx, GLenum target, const GLdouble *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: multi_tex_coord2dv called.");
		
		return multi_tex_coord2dv_reenter(ctx, target, GLdouble);
	}
	
	static void multi_tex_coord2f_replacement(GLIContext ctx, GLenum target, GLfloat s, GLfloat t)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: multi_tex_coord2f called.");
		
		return multi_tex_coord2f_reenter(ctx, target, s, t);
	}
	
	static void multi_tex_coord2fv_replacement(GLIContext ctx, GLenum target, const GLfloat *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: multi_tex_coord2fv called.");
		
		return multi_tex_coord2fv_reenter(ctx, target, GLfloat);
	}
	
	static void multi_tex_coord2i_replacement(GLIContext ctx, GLenum target, GLint s, GLint t)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: multi_tex_coord2i called.");
		
		return multi_tex_coord2i_reenter(ctx, target, s, t);
	}
	
	static void multi_tex_coord2iv_replacement(GLIContext ctx, GLenum target, const GLint *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: multi_tex_coord2iv called.");
		
		return multi_tex_coord2iv_reenter(ctx, target, GLint);
	}
	
	static void multi_tex_coord2s_replacement(GLIContext ctx, GLenum target, GLshort s, GLshort t)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: multi_tex_coord2s called.");
		
		return multi_tex_coord2s_reenter(ctx, target, s, t);
	}
	
	static void multi_tex_coord2sv_replacement(GLIContext ctx, GLenum target, const GLshort *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: multi_tex_coord2sv called.");
		
		return multi_tex_coord2sv_reenter(ctx, target, GLshort);
	}
	
	static void multi_tex_coord3d_replacement(GLIContext ctx, GLenum target, GLdouble s, GLdouble t, GLdouble r)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: multi_tex_coord3d called.");
		
		return multi_tex_coord3d_reenter(ctx, target, s, t, r);
	}
	
	static void multi_tex_coord3dv_replacement(GLIContext ctx, GLenum target, const GLdouble *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: multi_tex_coord3dv called.");
		
		return multi_tex_coord3dv_reenter(ctx, target, GLdouble);
	}
	
	static void multi_tex_coord3f_replacement(GLIContext ctx, GLenum target, GLfloat s, GLfloat t, GLfloat r)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: multi_tex_coord3f called.");
		
		return multi_tex_coord3f_reenter(ctx, target, s, t, r);
	}
	
	static void multi_tex_coord3fv_replacement(GLIContext ctx, GLenum target, const GLfloat *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: multi_tex_coord3fv called.");
		
		return multi_tex_coord3fv_reenter(ctx, target, GLfloat);
	}
	
	static void multi_tex_coord3i_replacement(GLIContext ctx, GLenum target, GLint s, GLint t, GLint r)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: multi_tex_coord3i called.");
		
		return multi_tex_coord3i_reenter(ctx, target, s, t, r);
	}
	
	static void multi_tex_coord3iv_replacement(GLIContext ctx, GLenum target, const GLint *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: multi_tex_coord3iv called.");
		
		return multi_tex_coord3iv_reenter(ctx, target, GLint);
	}
	
	static void multi_tex_coord3s_replacement(GLIContext ctx, GLenum target, GLshort s, GLshort t, GLshort r)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: multi_tex_coord3s called.");
		
		return multi_tex_coord3s_reenter(ctx, target, s, t, r);
	}
	
	static void multi_tex_coord3sv_replacement(GLIContext ctx, GLenum target, const GLshort *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: multi_tex_coord3sv called.");
		
		return multi_tex_coord3sv_reenter(ctx, target, GLshort);
	}
	
	static void multi_tex_coord4d_replacement(GLIContext ctx, GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: multi_tex_coord4d called.");
		
		return multi_tex_coord4d_reenter(ctx, target, s, t, r, q);
	}
	
	static void multi_tex_coord4dv_replacement(GLIContext ctx, GLenum target, const GLdouble *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: multi_tex_coord4dv called.");
		
		return multi_tex_coord4dv_reenter(ctx, target, GLdouble);
	}
	
	static void multi_tex_coord4f_replacement(GLIContext ctx, GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: multi_tex_coord4f called.");
		
		return multi_tex_coord4f_reenter(ctx, target, s, t, r, q);
	}
	
	static void multi_tex_coord4fv_replacement(GLIContext ctx, GLenum target, const GLfloat *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: multi_tex_coord4fv called.");
		
		return multi_tex_coord4fv_reenter(ctx, target, GLfloat);
	}
	
	static void multi_tex_coord4i_replacement(GLIContext ctx, GLenum target, GLint s, GLint t, GLint r, GLint q)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: multi_tex_coord4i called.");
		
		return multi_tex_coord4i_reenter(ctx, target, s, t, r, q);
	}
	
	static void multi_tex_coord4iv_replacement(GLIContext ctx, GLenum target, const GLint *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: multi_tex_coord4iv called.");
		
		return multi_tex_coord4iv_reenter(ctx, target, GLint);
	}
	
	static void multi_tex_coord4s_replacement(GLIContext ctx, GLenum target, GLshort s, GLshort t, GLshort r, GLshort q)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: multi_tex_coord4s called.");
		
		return multi_tex_coord4s_reenter(ctx, target, s, t, r, q);
	}
	
	static void multi_tex_coord4sv_replacement(GLIContext ctx, GLenum target, const GLshort *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: multi_tex_coord4sv called.");
		
		return multi_tex_coord4sv_reenter(ctx, target, GLshort);
	}
	
	static void load_transpose_matrixd_replacement(GLIContext ctx, const GLdouble *m)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: load_transpose_matrixd called.");
		
		return load_transpose_matrixd_reenter(ctx, GLdouble);
	}
	
	static void load_transpose_matrixf_replacement(GLIContext ctx, const GLfloat *m)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: load_transpose_matrixf called.");
		
		return load_transpose_matrixf_reenter(ctx, GLfloat);
	}
	
	static void mult_transpose_matrixd_replacement(GLIContext ctx, const GLdouble *m)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: mult_transpose_matrixd called.");
		
		return mult_transpose_matrixd_reenter(ctx, GLdouble);
	}
	
	static void mult_transpose_matrixf_replacement(GLIContext ctx, const GLfloat *m)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: mult_transpose_matrixf called.");
		
		return mult_transpose_matrixf_reenter(ctx, GLfloat);
	}
	
	static void compressed_tex_image3D_replacement(GLIContext ctx, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *data)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: compressed_tex_image3D called.");
		
		return compressed_tex_image3D_reenter(ctx, target, level, internalformat, width, height, depth, border, imageSize, GLvoid);
	}
	
	static void compressed_tex_image2D_replacement(GLIContext ctx, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: compressed_tex_image2D called.");
		
		return compressed_tex_image2D_reenter(ctx, target, level, internalformat, width, height, border, imageSize, GLvoid);
	}
	
	static void compressed_tex_image1D_replacement(GLIContext ctx, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: compressed_tex_image1D called.");
		
		return compressed_tex_image1D_reenter(ctx, target, level, internalformat, width, border, imageSize, GLvoid);
	}
	
	static void compressed_tex_sub_image3D_replacement(GLIContext ctx, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: compressed_tex_sub_image3D called.");
		
		return compressed_tex_sub_image3D_reenter(ctx, target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, GLvoid);
	}
	
	static void compressed_tex_sub_image2D_replacement(GLIContext ctx, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: compressed_tex_sub_image2D called.");
		
		return compressed_tex_sub_image2D_reenter(ctx, target, level, xoffset, yoffset, width, height, format, imageSize, GLvoid);
	}
	
	static void compressed_tex_sub_image1D_replacement(GLIContext ctx, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: compressed_tex_sub_image1D called.");
		
		return compressed_tex_sub_image1D_reenter(ctx, target, level, xoffset, width, format, imageSize, GLvoid);
	}
	
	static void get_compressed_tex_image_replacement(GLIContext ctx, GLenum target, GLint level, GLvoid *img)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_compressed_tex_image called.");
		
		return get_compressed_tex_image_reenter(ctx, target, level, *img);
	}
	
	static void secondary_color3b_replacement(GLIContext ctx, GLbyte red, GLbyte green, GLbyte blue)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: secondary_color3b called.");
		
		return secondary_color3b_reenter(ctx, red, green, blue);
	}
	
	static void secondary_color3bv_replacement(GLIContext ctx, const GLbyte *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: secondary_color3bv called.");
		
		return secondary_color3bv_reenter(ctx, GLbyte);
	}
	
	static void secondary_color3d_replacement(GLIContext ctx, GLdouble red, GLdouble green, GLdouble blue)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: secondary_color3d called.");
		
		return secondary_color3d_reenter(ctx, red, green, blue);
	}
	
	static void secondary_color3dv_replacement(GLIContext ctx, const GLdouble *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: secondary_color3dv called.");
		
		return secondary_color3dv_reenter(ctx, GLdouble);
	}
	
	static void secondary_color3f_replacement(GLIContext ctx, GLfloat red, GLfloat green, GLfloat blue)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: secondary_color3f called.");
		
		return secondary_color3f_reenter(ctx, red, green, blue);
	}
	
	static void secondary_color3fv_replacement(GLIContext ctx, const GLfloat *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: secondary_color3fv called.");
		
		return secondary_color3fv_reenter(ctx, GLfloat);
	}
	
	static void secondary_color3i_replacement(GLIContext ctx, GLint red, GLint green, GLint blue)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: secondary_color3i called.");
		
		return secondary_color3i_reenter(ctx, red, green, blue);
	}
	
	static void secondary_color3iv_replacement(GLIContext ctx, const GLint *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: secondary_color3iv called.");
		
		return secondary_color3iv_reenter(ctx, GLint);
	}
	
	static void secondary_color3s_replacement(GLIContext ctx, GLshort red, GLshort green, GLshort blue)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: secondary_color3s called.");
		
		return secondary_color3s_reenter(ctx, red, green, blue);
	}
	
	static void secondary_color3sv_replacement(GLIContext ctx, const GLshort *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: secondary_color3sv called.");
		
		return secondary_color3sv_reenter(ctx, GLshort);
	}
	
	static void secondary_color3ub_replacement(GLIContext ctx, GLubyte red, GLubyte green, GLubyte blue)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: secondary_color3ub called.");
		
		return secondary_color3ub_reenter(ctx, red, green, blue);
	}
	
	static void secondary_color3ubv_replacement(GLIContext ctx, const GLubyte *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: secondary_color3ubv called.");
		
		return secondary_color3ubv_reenter(ctx, GLubyte);
	}
	
	static void secondary_color3ui_replacement(GLIContext ctx, GLuint red, GLuint green, GLuint blue)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: secondary_color3ui called.");
		
		return secondary_color3ui_reenter(ctx, red, green, blue);
	}
	
	static void secondary_color3uiv_replacement(GLIContext ctx, const GLuint *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: secondary_color3uiv called.");
		
		return secondary_color3uiv_reenter(ctx, GLuint);
	}
	
	static void secondary_color3us_replacement(GLIContext ctx, GLushort red, GLushort green, GLushort blue)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: secondary_color3us called.");
		
		return secondary_color3us_reenter(ctx, red, green, blue);
	}
	
	static void secondary_color3usv_replacement(GLIContext ctx, const GLushort *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: secondary_color3usv called.");
		
		return secondary_color3usv_reenter(ctx, GLushort);
	}
	
	static void secondary_color_pointer_replacement(GLIContext ctx, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: secondary_color_pointer called.");
		
		return secondary_color_pointer_reenter(ctx, size, type, stride, GLvoid);
	}
	
	static void vertex_array_range_EXT_replacement(GLIContext ctx, GLsizei count, const GLvoid *pointer)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_array_range_EXT called.");
		
		return vertex_array_range_EXT_reenter(ctx, count, GLvoid);
	}
	
	static void flush_vertex_array_range_EXT_replacement(GLIContext ctx, GLsizei count, const GLvoid *pointer)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: flush_vertex_array_range_EXT called.");
		
		return flush_vertex_array_range_EXT_reenter(ctx, count, GLvoid);
	}
	
	static void draw_range_elements_replacement(GLIContext ctx, GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: draw_range_elements called.");
		
		return draw_range_elements_reenter(ctx, mode, start, end, count, type, GLvoid);
	}
	
	static void color_table_replacement(GLIContext ctx, GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *table)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: color_table called.");
		
		return color_table_reenter(ctx, target, internalformat, width, format, type, GLvoid);
	}
	
	static void color_table_parameterfv_replacement(GLIContext ctx, GLenum target, GLenum pname, const GLfloat *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: color_table_parameterfv called.");
		
		return color_table_parameterfv_reenter(ctx, target, pname, GLfloat);
	}
	
	static void color_table_parameteriv_replacement(GLIContext ctx, GLenum target, GLenum pname, const GLint *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: color_table_parameteriv called.");
		
		return color_table_parameteriv_reenter(ctx, target, pname, GLint);
	}
	
	static void copy_color_table_replacement(GLIContext ctx, GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: copy_color_table called.");
		
		return copy_color_table_reenter(ctx, target, internalformat, x, y, width);
	}
	
	static void get_color_table_replacement(GLIContext ctx, GLenum target, GLenum format, GLenum type, GLvoid *table)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_color_table called.");
		
		return get_color_table_reenter(ctx, target, format, type, *table);
	}
	
	static void get_color_table_parameterfv_replacement(GLIContext ctx, GLenum target, GLenum pname, GLfloat *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_color_table_parameterfv called.");
		
		return get_color_table_parameterfv_reenter(ctx, target, pname, *params);
	}
	
	static void get_color_table_parameteriv_replacement(GLIContext ctx, GLenum target, GLenum pname, GLint *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_color_table_parameteriv called.");
		
		return get_color_table_parameteriv_reenter(ctx, target, pname, *params);
	}
	
	static void color_sub_table_replacement(GLIContext ctx, GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const GLvoid *data)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: color_sub_table called.");
		
		return color_sub_table_reenter(ctx, target, start, count, format, type, GLvoid);
	}
	
	static void copy_color_sub_table_replacement(GLIContext ctx, GLenum target, GLsizei start, GLint x, GLint y, GLsizei width)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: copy_color_sub_table called.");
		
		return copy_color_sub_table_reenter(ctx, target, start, x, y, width);
	}
	
	static void convolution_filter1D_replacement(GLIContext ctx, GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *image)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: convolution_filter1D called.");
		
		return convolution_filter1D_reenter(ctx, target, internalformat, width, format, type, GLvoid);
	}
	
	static void convolution_filter2D_replacement(GLIContext ctx, GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *image)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: convolution_filter2D called.");
		
		return convolution_filter2D_reenter(ctx, target, internalformat, width, height, format, type, GLvoid);
	}
	
	static void convolution_parameterf_replacement(GLIContext ctx, GLenum target, GLenum pname, GLfloat params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: convolution_parameterf called.");
		
		return convolution_parameterf_reenter(ctx, target, pname, params);
	}
	
	static void convolution_parameterfv_replacement(GLIContext ctx, GLenum target, GLenum pname, const GLfloat *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: convolution_parameterfv called.");
		
		return convolution_parameterfv_reenter(ctx, target, pname, GLfloat);
	}
	
	static void convolution_parameteri_replacement(GLIContext ctx, GLenum target, GLenum pname, GLint params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: convolution_parameteri called.");
		
		return convolution_parameteri_reenter(ctx, target, pname, params);
	}
	
	static void convolution_parameteriv_replacement(GLIContext ctx, GLenum target, GLenum pname, const GLint *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: convolution_parameteriv called.");
		
		return convolution_parameteriv_reenter(ctx, target, pname, GLint);
	}
	
	static void copy_convolution_filter1D_replacement(GLIContext ctx, GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: copy_convolution_filter1D called.");
		
		return copy_convolution_filter1D_reenter(ctx, target, internalformat, x, y, width);
	}
	
	static void copy_convolution_filter2D_replacement(GLIContext ctx, GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: copy_convolution_filter2D called.");
		
		return copy_convolution_filter2D_reenter(ctx, target, internalformat, x, y, width, height);
	}
	
	static void get_convolution_filter_replacement(GLIContext ctx, GLenum target, GLenum format, GLenum type, GLvoid *image)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_convolution_filter called.");
		
		return get_convolution_filter_reenter(ctx, target, format, type, *image);
	}
	
	static void get_convolution_parameterfv_replacement(GLIContext ctx, GLenum target, GLenum pname, GLfloat *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_convolution_parameterfv called.");
		
		return get_convolution_parameterfv_reenter(ctx, target, pname, *params);
	}
	
	static void get_convolution_parameteriv_replacement(GLIContext ctx, GLenum target, GLenum pname, GLint *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_convolution_parameteriv called.");
		
		return get_convolution_parameteriv_reenter(ctx, target, pname, *params);
	}
	
	static void get_separable_filter_replacement(GLIContext ctx, GLenum target, GLenum format, GLenum type, GLvoid *row, GLvoid *column, GLvoid *span)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_separable_filter called.");
		
		return get_separable_filter_reenter(ctx, target, format, type, *row, *column, *span);
	}
	
	static void separable_filter2D_replacement(GLIContext ctx, GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *row, const GLvoid *column)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: separable_filter2D called.");
		
		return separable_filter2D_reenter(ctx, target, internalformat, width, height, format, type, GLvoid const *column);
	}
	
	static void get_histogram_replacement(GLIContext ctx, GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid *values)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_histogram called.");
		
		return get_histogram_reenter(ctx, target, reset, format, type, *values);
	}
	
	static void get_histogram_parameterfv_replacement(GLIContext ctx, GLenum target, GLenum pname, GLfloat *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_histogram_parameterfv called.");
		
		return get_histogram_parameterfv_reenter(ctx, target, pname, *params);
	}
	
	static void get_histogram_parameteriv_replacement(GLIContext ctx, GLenum target, GLenum pname, GLint *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_histogram_parameteriv called.");
		
		return get_histogram_parameteriv_reenter(ctx, target, pname, *params);
	}
	
	static void get_minmax_replacement(GLIContext ctx, GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid *values)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_minmax called.");
		
		return get_minmax_reenter(ctx, target, reset, format, type, *values);
	}
	
	static void get_minmax_parameterfv_replacement(GLIContext ctx, GLenum target, GLenum pname, GLfloat *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_minmax_parameterfv called.");
		
		return get_minmax_parameterfv_reenter(ctx, target, pname, *params);
	}
	
	static void get_minmax_parameteriv_replacement(GLIContext ctx, GLenum target, GLenum pname, GLint *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_minmax_parameteriv called.");
		
		return get_minmax_parameteriv_reenter(ctx, target, pname, *params);
	}
	
	static void histogram_replacement(GLIContext ctx, GLenum target, GLsizei width, GLenum internalformat, GLboolean sink)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: histogram called.");
		
		return histogram_reenter(ctx, target, width, internalformat, sink);
	}
	
	static void minmax_replacement(GLIContext ctx, GLenum target, GLenum internalformat, GLboolean sink)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: minmax called.");
		
		return minmax_reenter(ctx, target, internalformat, sink);
	}
	
	static void reset_histogram_replacement(GLIContext ctx, GLenum target)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: reset_histogram called.");
		
		return reset_histogram_reenter(ctx, target);
	}
	
	static void reset_minmax_replacement(GLIContext ctx, GLenum target)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: reset_minmax called.");
		
		return reset_minmax_reenter(ctx, target);
	}
	
	static void tex_image3D_replacement(GLIContext ctx, GLenum target, GLint level, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_image3D called.");
		
		return tex_image3D_reenter(ctx, target, level, internalFormat, width, height, depth, border, format, type, GLvoid);
	}
	
	static void tex_sub_image3D_replacement(GLIContext ctx, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_sub_image3D called.");
		
		return tex_sub_image3D_reenter(ctx, target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, GLvoid);
	}
	
	static void copy_tex_sub_image3D_replacement(GLIContext ctx, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: copy_tex_sub_image3D called.");
		
		return copy_tex_sub_image3D_reenter(ctx, target, level, xoffset, yoffset, zoffset, x, y, width, height);
	}
	
	static void get_uniform_indices_replacement((GLIContext ctx, GLuint program, GLsizei uniformCount, const GLchar* const *uniformNames, GLuint* uniformIndices)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_uniform_indices called.");
		
		return get_uniform_indices_reenter(ctx, program, uniformCount, GLchar* *uniformNames, uniformIndices);
	}
	
	static void get_active_uniformsiv_replacement((GLIContext ctx, GLuint program, GLsizei uniformCount, const GLuint* uniformIndices, GLenum pname, GLint* params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_active_uniformsiv called.");
		
		return get_active_uniformsiv_reenter(ctx, program, uniformCount, GLuint* GLenum GLint*);
	}
	
	static void get_active_uniform_name_replacement((GLIContext ctx, GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformName)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_active_uniform_name called.");
		
		return get_active_uniform_name_reenter(ctx, program, uniformIndex, bufSize, length, uniformName);
	}
	
	static GLuint get_uniform_block_index_replacement((GLIContext ctx, GLuint program, const GLchar* uniformBlockName)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_uniform_block_index called.");
		
		return get_uniform_block_index_reenter(ctx, program, GLchar*);
	}
	
	static void get_active_uniform_blockiv_replacement((GLIContext ctx, GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint* params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_active_uniform_blockiv called.");
		
		return get_active_uniform_blockiv_reenter(ctx, program, uniformBlockIndex, pname, params);
	}
	
	static void get_active_uniform_block_name_replacement((GLIContext ctx, GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformBlockName)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_active_uniform_block_name called.");
		
		return get_active_uniform_block_name_reenter(ctx, program, uniformBlockIndex, bufSize, length, uniformBlockName);
	}
	
	static void uniform_block_binding_replacement((GLIContext ctx, GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: uniform_block_binding called.");
		
		return uniform_block_binding_reenter(ctx, program, uniformBlockIndex, uniformBlockBinding);
	}
	
	static void get_combiner_input_parameterfv_NV_replacement(GLIContext ctx, GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLfloat *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_combiner_input_parameterfv_NV called.");
		
		return get_combiner_input_parameterfv_NV_reenter(ctx, stage, portion, variable, pname, *params);
	}
	
	static void get_combiner_input_parameteriv_NV_replacement(GLIContext ctx, GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLint *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_combiner_input_parameteriv_NV called.");
		
		return get_combiner_input_parameteriv_NV_reenter(ctx, stage, portion, variable, pname, *params);
	}
	
	static void get_combiner_output_parameterfv_NV_replacement(GLIContext ctx, GLenum stage, GLenum portion, GLenum pname, GLfloat *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_combiner_output_parameterfv_NV called.");
		
		return get_combiner_output_parameterfv_NV_reenter(ctx, stage, portion, pname, *params);
	}
	
	static void get_combiner_output_parameteriv_NV_replacement(GLIContext ctx, GLenum stage, GLenum portion, GLenum pname, GLint *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_combiner_output_parameteriv_NV called.");
		
		return get_combiner_output_parameteriv_NV_reenter(ctx, stage, portion, pname, *params);
	}
	
	static void get_final_combiner_input_parameterfv_NV_replacement(GLIContext ctx, GLenum variable, GLenum pname, GLfloat *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_final_combiner_input_parameterfv_NV called.");
		
		return get_final_combiner_input_parameterfv_NV_reenter(ctx, variable, pname, *params);
	}
	
	static void get_final_combiner_input_parameteriv_NV_replacement(GLIContext ctx, GLenum variable, GLenum pname, GLint *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_final_combiner_input_parameteriv_NV called.");
		
		return get_final_combiner_input_parameteriv_NV_reenter(ctx, variable, pname, *params);
	}
	
	static void combiner_stage_parameterfv_NV_replacement(GLIContext ctx, GLenum stage, GLenum pname, const GLfloat *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: combiner_stage_parameterfv_NV called.");
		
		return combiner_stage_parameterfv_NV_reenter(ctx, stage, pname, GLfloat);
	}
	
	static void get_combiner_stage_parameterfv_NV_replacement(GLIContext ctx, GLenum stage, GLenum pname, GLfloat *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_combiner_stage_parameterfv_NV called.");
		
		return get_combiner_stage_parameterfv_NV_reenter(ctx, stage, pname, *params);
	}
	
	static void texture_range_APPLE_replacement(GLIContext ctx, GLenum target, GLsizei length, const GLvoid *pointer)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: texture_range_APPLE called.");
		
		return texture_range_APPLE_reenter(ctx, target, length, GLvoid);
	}
	
	static void get_tex_parameter_pointerv_APPLE_replacement(GLIContext ctx, GLenum target, GLenum pname, GLvoid **params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_tex_parameter_pointerv_APPLE called.");
		
		return get_tex_parameter_pointerv_APPLE_reenter(ctx, target, pname, **params);
	}
	
	static void blend_equation_separate_EXT_replacement(GLIContext ctx, GLenum equationRGB, GLenum equationAlpha)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: blend_equation_separate_EXT called.");
		
		return blend_equation_separate_EXT_reenter(ctx, equationRGB, equationAlpha);
	}
	
	static void sample_coverage_replacement(GLIContext ctx, GLclampf value, GLboolean invert)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: sample_coverage called.");
		
		return sample_coverage_reenter(ctx, value, invert);
	}
	
	static void sample_pass_replacement(GLIContext ctx, GLenum mode)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: sample_pass called.");
		
		return sample_pass_reenter(ctx, mode);
	}
	
	static void pn_trianglesi_ATI_replacement(GLIContext ctx, GLenum pname, GLint param)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: pn_trianglesi_ATI called.");
		
		return pn_trianglesi_ATI_reenter(ctx, pname, param);
	}
	
	static void pn_trianglesf_ATI_replacement(GLIContext ctx, GLenum pname, GLfloat param)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: pn_trianglesf_ATI called.");
		
		return pn_trianglesf_ATI_reenter(ctx, pname, param);
	}
	
	static void gen_fences_APPLE_replacement(GLIContext ctx, GLsizei n, GLuint *fences)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: gen_fences_APPLE called.");
		
		return gen_fences_APPLE_reenter(ctx, n, *fences);
	}
	
	static void delete_fences_APPLE_replacement(GLIContext ctx, GLsizei n, const GLuint *fences)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: delete_fences_APPLE called.");
		
		return delete_fences_APPLE_reenter(ctx, n, GLuint);
	}
	
	static void set_fence_APPLE_replacement(GLIContext ctx, GLuint fence)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: set_fence_APPLE called.");
		
		return set_fence_APPLE_reenter(ctx, fence);
	}
	
	static GLboolean is_fence_APPLE_replacement(GLIContext ctx, GLuint fence)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: is_fence_APPLE called.");
		
		return is_fence_APPLE_reenter(ctx, fence);
	}
	
	static GLboolean test_fence_APPLE_replacement(GLIContext ctx, GLuint fence)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: test_fence_APPLE called.");
		
		return test_fence_APPLE_reenter(ctx, fence);
	}
	
	static void finish_fence_APPLE_replacement(GLIContext ctx, GLuint fence)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: finish_fence_APPLE called.");
		
		return finish_fence_APPLE_reenter(ctx, fence);
	}
	
	static GLboolean test_object_APPLE_replacement(GLIContext ctx, GLenum object, GLuint name)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: test_object_APPLE called.");
		
		return test_object_APPLE_reenter(ctx, object, name);
	}
	
	static void finish_object_APPLE_replacement(GLIContext ctx, GLenum object, GLuint name)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: finish_object_APPLE called.");
		
		return finish_object_APPLE_reenter(ctx, object, name);
	}
	
	static void bind_program_ARB_replacement(GLIContext ctx, GLenum target, GLuint program)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: bind_program_ARB called.");
		
		return bind_program_ARB_reenter(ctx, target, program);
	}
	
	static void delete_programs_ARB_replacement(GLIContext ctx, GLsizei n, const GLuint *programs)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: delete_programs_ARB called.");
		
		return delete_programs_ARB_reenter(ctx, n, GLuint);
	}
	
	static void gen_programs_ARB_replacement(GLIContext ctx, GLsizei n, GLuint *programs)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: gen_programs_ARB called.");
		
		return gen_programs_ARB_reenter(ctx, n, *programs);
	}
	
	static GLboolean is_program_ARB_replacement(GLIContext ctx, GLuint program)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: is_program_ARB called.");
		
		return is_program_ARB_reenter(ctx, program);
	}
	
	static void vertex_attrib1s_ARB_replacement(GLIContext ctx, GLuint index, GLshort x)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attrib1s_ARB called.");
		
		return vertex_attrib1s_ARB_reenter(ctx, index, x);
	}
	
	static void vertex_attrib1f_ARB_replacement(GLIContext ctx, GLuint index, GLfloat x)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attrib1f_ARB called.");
		
		return vertex_attrib1f_ARB_reenter(ctx, index, x);
	}
	
	static void vertex_attrib1d_ARB_replacement(GLIContext ctx, GLuint index, GLdouble x)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attrib1d_ARB called.");
		
		return vertex_attrib1d_ARB_reenter(ctx, index, x);
	}
	
	static void vertex_attrib2s_ARB_replacement(GLIContext ctx, GLuint index, GLshort x, GLshort y)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attrib2s_ARB called.");
		
		return vertex_attrib2s_ARB_reenter(ctx, index, x, y);
	}
	
	static void vertex_attrib2f_ARB_replacement(GLIContext ctx, GLuint index, GLfloat x, GLfloat y)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attrib2f_ARB called.");
		
		return vertex_attrib2f_ARB_reenter(ctx, index, x, y);
	}
	
	static void vertex_attrib2d_ARB_replacement(GLIContext ctx, GLuint index, GLdouble x, GLdouble y)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attrib2d_ARB called.");
		
		return vertex_attrib2d_ARB_reenter(ctx, index, x, y);
	}
	
	static void vertex_attrib3s_ARB_replacement(GLIContext ctx, GLuint index, GLshort x, GLshort y, GLshort z)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attrib3s_ARB called.");
		
		return vertex_attrib3s_ARB_reenter(ctx, index, x, y, z);
	}
	
	static void vertex_attrib3f_ARB_replacement(GLIContext ctx, GLuint index, GLfloat x, GLfloat y, GLfloat z)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attrib3f_ARB called.");
		
		return vertex_attrib3f_ARB_reenter(ctx, index, x, y, z);
	}
	
	static void vertex_attrib3d_ARB_replacement(GLIContext ctx, GLuint index, GLdouble x, GLdouble y, GLdouble z)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attrib3d_ARB called.");
		
		return vertex_attrib3d_ARB_reenter(ctx, index, x, y, z);
	}
	
	static void vertex_attrib4s_ARB_replacement(GLIContext ctx, GLuint index, GLshort x, GLshort y, GLshort z, GLshort w)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attrib4s_ARB called.");
		
		return vertex_attrib4s_ARB_reenter(ctx, index, x, y, z, w);
	}
	
	static void vertex_attrib4f_ARB_replacement(GLIContext ctx, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attrib4f_ARB called.");
		
		return vertex_attrib4f_ARB_reenter(ctx, index, x, y, z, w);
	}
	
	static void vertex_attrib4d_ARB_replacement(GLIContext ctx, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attrib4d_ARB called.");
		
		return vertex_attrib4d_ARB_reenter(ctx, index, x, y, z, w);
	}
	
	static void vertex_attrib4Nub_ARB_replacement(GLIContext ctx, GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attrib4Nub_ARB called.");
		
		return vertex_attrib4Nub_ARB_reenter(ctx, index, x, y, z, w);
	}
	
	static void vertex_attrib1sv_ARB_replacement(GLIContext ctx, GLuint index, const GLshort *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attrib1sv_ARB called.");
		
		return vertex_attrib1sv_ARB_reenter(ctx, index, GLshort);
	}
	
	static void vertex_attrib1fv_ARB_replacement(GLIContext ctx, GLuint index, const GLfloat *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attrib1fv_ARB called.");
		
		return vertex_attrib1fv_ARB_reenter(ctx, index, GLfloat);
	}
	
	static void vertex_attrib1dv_ARB_replacement(GLIContext ctx, GLuint index, const GLdouble *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attrib1dv_ARB called.");
		
		return vertex_attrib1dv_ARB_reenter(ctx, index, GLdouble);
	}
	
	static void vertex_attrib2sv_ARB_replacement(GLIContext ctx, GLuint index, const GLshort *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attrib2sv_ARB called.");
		
		return vertex_attrib2sv_ARB_reenter(ctx, index, GLshort);
	}
	
	static void vertex_attrib2fv_ARB_replacement(GLIContext ctx, GLuint index, const GLfloat *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attrib2fv_ARB called.");
		
		return vertex_attrib2fv_ARB_reenter(ctx, index, GLfloat);
	}
	
	static void vertex_attrib2dv_ARB_replacement(GLIContext ctx, GLuint index, const GLdouble *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attrib2dv_ARB called.");
		
		return vertex_attrib2dv_ARB_reenter(ctx, index, GLdouble);
	}
	
	static void vertex_attrib3sv_ARB_replacement(GLIContext ctx, GLuint index, const GLshort *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attrib3sv_ARB called.");
		
		return vertex_attrib3sv_ARB_reenter(ctx, index, GLshort);
	}
	
	static void vertex_attrib3fv_ARB_replacement(GLIContext ctx, GLuint index, const GLfloat *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attrib3fv_ARB called.");
		
		return vertex_attrib3fv_ARB_reenter(ctx, index, GLfloat);
	}
	
	static void vertex_attrib3dv_ARB_replacement(GLIContext ctx, GLuint index, const GLdouble *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attrib3dv_ARB called.");
		
		return vertex_attrib3dv_ARB_reenter(ctx, index, GLdouble);
	}
	
	static void vertex_attrib4bv_ARB_replacement(GLIContext ctx, GLuint index, const GLbyte *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attrib4bv_ARB called.");
		
		return vertex_attrib4bv_ARB_reenter(ctx, index, GLbyte);
	}
	
	static void vertex_attrib4sv_ARB_replacement(GLIContext ctx, GLuint index, const GLshort *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attrib4sv_ARB called.");
		
		return vertex_attrib4sv_ARB_reenter(ctx, index, GLshort);
	}
	
	static void vertex_attrib4iv_ARB_replacement(GLIContext ctx, GLuint index, const GLint *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attrib4iv_ARB called.");
		
		return vertex_attrib4iv_ARB_reenter(ctx, index, GLint);
	}
	
	static void vertex_attrib4ubv_ARB_replacement(GLIContext ctx, GLuint index, const GLubyte *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attrib4ubv_ARB called.");
		
		return vertex_attrib4ubv_ARB_reenter(ctx, index, GLubyte);
	}
	
	static void vertex_attrib4usv_ARB_replacement(GLIContext ctx, GLuint index, const GLushort *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attrib4usv_ARB called.");
		
		return vertex_attrib4usv_ARB_reenter(ctx, index, GLushort);
	}
	
	static void vertex_attrib4uiv_ARB_replacement(GLIContext ctx, GLuint index, const GLuint *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attrib4uiv_ARB called.");
		
		return vertex_attrib4uiv_ARB_reenter(ctx, index, GLuint);
	}
	
	static void vertex_attrib4fv_ARB_replacement(GLIContext ctx, GLuint index, const GLfloat *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attrib4fv_ARB called.");
		
		return vertex_attrib4fv_ARB_reenter(ctx, index, GLfloat);
	}
	
	static void vertex_attrib4dv_ARB_replacement(GLIContext ctx, GLuint index, const GLdouble *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attrib4dv_ARB called.");
		
		return vertex_attrib4dv_ARB_reenter(ctx, index, GLdouble);
	}
	
	static void vertex_attrib4Nbv_ARB_replacement(GLIContext ctx, GLuint index, const GLbyte *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attrib4Nbv_ARB called.");
		
		return vertex_attrib4Nbv_ARB_reenter(ctx, index, GLbyte);
	}
	
	static void vertex_attrib4Nsv_ARB_replacement(GLIContext ctx, GLuint index, const GLshort *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attrib4Nsv_ARB called.");
		
		return vertex_attrib4Nsv_ARB_reenter(ctx, index, GLshort);
	}
	
	static void vertex_attrib4Niv_ARB_replacement(GLIContext ctx, GLuint index, const GLint *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attrib4Niv_ARB called.");
		
		return vertex_attrib4Niv_ARB_reenter(ctx, index, GLint);
	}
	
	static void vertex_attrib4Nubv_ARB_replacement(GLIContext ctx, GLuint index, const GLubyte *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attrib4Nubv_ARB called.");
		
		return vertex_attrib4Nubv_ARB_reenter(ctx, index, GLubyte);
	}
	
	static void vertex_attrib4Nusv_ARB_replacement(GLIContext ctx, GLuint index, const GLushort *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attrib4Nusv_ARB called.");
		
		return vertex_attrib4Nusv_ARB_reenter(ctx, index, GLushort);
	}
	
	static void vertex_attrib4Nuiv_ARB_replacement(GLIContext ctx, GLuint index, const GLuint *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attrib4Nuiv_ARB called.");
		
		return vertex_attrib4Nuiv_ARB_reenter(ctx, index, GLuint);
	}
	
	static void vertex_attrib_pointer_ARB_replacement(GLIContext ctx, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid *pointer)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attrib_pointer_ARB called.");
		
		return vertex_attrib_pointer_ARB_reenter(ctx, index, size, type, normalized, stride, GLvoid);
	}
	
	static void enable_vertex_attrib_array_ARB_replacement(GLIContext ctx, GLuint index)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: enable_vertex_attrib_array_ARB called.");
		
		return enable_vertex_attrib_array_ARB_reenter(ctx, index);
	}
	
	static void disable_vertex_attrib_array_ARB_replacement(GLIContext ctx, GLuint index)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: disable_vertex_attrib_array_ARB called.");
		
		return disable_vertex_attrib_array_ARB_reenter(ctx, index);
	}
	
	static void get_vertex_attribdv_ARB_replacement(GLIContext ctx, GLuint index, GLenum pname, GLdouble *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_vertex_attribdv_ARB called.");
		
		return get_vertex_attribdv_ARB_reenter(ctx, index, pname, *params);
	}
	
	static void get_vertex_attribfv_ARB_replacement(GLIContext ctx, GLuint index, GLenum pname, GLfloat *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_vertex_attribfv_ARB called.");
		
		return get_vertex_attribfv_ARB_reenter(ctx, index, pname, *params);
	}
	
	static void get_vertex_attribiv_ARB_replacement(GLIContext ctx, GLuint index, GLenum pname, GLint *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_vertex_attribiv_ARB called.");
		
		return get_vertex_attribiv_ARB_reenter(ctx, index, pname, *params);
	}
	
	static void get_vertex_attrib_pointerv_ARB_replacement(GLIContext ctx, GLuint index, GLenum pname, GLvoid **pointer)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_vertex_attrib_pointerv_ARB called.");
		
		return get_vertex_attrib_pointerv_ARB_reenter(ctx, index, pname, **pointer);
	}
	
	static void program_env_parameter4d_ARB_replacement(GLIContext ctx, GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_env_parameter4d_ARB called.");
		
		return program_env_parameter4d_ARB_reenter(ctx, target, index, x, y, z, w);
	}
	
	static void program_env_parameter4dv_ARB_replacement(GLIContext ctx, GLenum target, GLuint index, const GLdouble *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_env_parameter4dv_ARB called.");
		
		return program_env_parameter4dv_ARB_reenter(ctx, target, index, GLdouble);
	}
	
	static void program_env_parameter4f_ARB_replacement(GLIContext ctx, GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_env_parameter4f_ARB called.");
		
		return program_env_parameter4f_ARB_reenter(ctx, target, index, x, y, z, w);
	}
	
	static void program_env_parameter4fv_ARB_replacement(GLIContext ctx, GLenum target, GLuint index, const GLfloat *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_env_parameter4fv_ARB called.");
		
		return program_env_parameter4fv_ARB_reenter(ctx, target, index, GLfloat);
	}
	
	static void program_local_parameter4d_ARB_replacement(GLIContext ctx, GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_local_parameter4d_ARB called.");
		
		return program_local_parameter4d_ARB_reenter(ctx, target, index, x, y, z, w);
	}
	
	static void program_local_parameter4dv_ARB_replacement(GLIContext ctx, GLenum target, GLuint index, const GLdouble *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_local_parameter4dv_ARB called.");
		
		return program_local_parameter4dv_ARB_reenter(ctx, target, index, GLdouble);
	}
	
	static void program_local_parameter4f_ARB_replacement(GLIContext ctx, GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_local_parameter4f_ARB called.");
		
		return program_local_parameter4f_ARB_reenter(ctx, target, index, x, y, z, w);
	}
	
	static void program_local_parameter4fv_ARB_replacement(GLIContext ctx, GLenum target, GLuint index, const GLfloat *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_local_parameter4fv_ARB called.");
		
		return program_local_parameter4fv_ARB_reenter(ctx, target, index, GLfloat);
	}
	
	static void get_program_env_parameterdv_ARB_replacement(GLIContext ctx, GLenum target, GLuint index, GLdouble *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_program_env_parameterdv_ARB called.");
		
		return get_program_env_parameterdv_ARB_reenter(ctx, target, index, *params);
	}
	
	static void get_program_env_parameterfv_ARB_replacement(GLIContext ctx, GLenum target, GLuint index, GLfloat *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_program_env_parameterfv_ARB called.");
		
		return get_program_env_parameterfv_ARB_reenter(ctx, target, index, *params);
	}
	
	static void get_program_local_parameterdv_ARB_replacement(GLIContext ctx, GLenum target, GLuint index, GLdouble *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_program_local_parameterdv_ARB called.");
		
		return get_program_local_parameterdv_ARB_reenter(ctx, target, index, *params);
	}
	
	static void get_program_local_parameterfv_ARB_replacement(GLIContext ctx, GLenum target, GLuint index, GLfloat *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_program_local_parameterfv_ARB called.");
		
		return get_program_local_parameterfv_ARB_reenter(ctx, target, index, *params);
	}
	
	static void program_string_ARB_replacement(GLIContext ctx, GLenum target, GLenum format, GLsizei len, const GLvoid* string)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_string_ARB called.");
		
		return program_string_ARB_reenter(ctx, target, format, len, GLvoid*);
	}
	
	static void get_program_string_ARB_replacement(GLIContext ctx, GLenum target, GLenum pname, GLvoid *string)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_program_string_ARB called.");
		
		return get_program_string_ARB_reenter(ctx, target, pname, *string);
	}
	
	static void get_programiv_ARB_replacement(GLIContext ctx, GLenum target, GLenum pname, GLint *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_programiv_ARB called.");
		
		return get_programiv_ARB_reenter(ctx, target, pname, *params);
	}
	
	static void enable_vertex_attrib_ARB_replacement(GLIContext ctx, GLuint index, GLenum pname)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: enable_vertex_attrib_ARB called.");
		
		return enable_vertex_attrib_ARB_reenter(ctx, index, pname);
	}
	
	static void disable_vertex_attrib_ARB_replacement(GLIContext ctx, GLuint index, GLenum pname)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: disable_vertex_attrib_ARB called.");
		
		return disable_vertex_attrib_ARB_reenter(ctx, index, pname);
	}
	
	static GLboolean is_vertex_attrib_enabled_ARB_replacement(GLIContext ctx, GLuint index, GLenum pname)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: is_vertex_attrib_enabled_ARB called.");
		
		return is_vertex_attrib_enabled_ARB_reenter(ctx, index, pname);
	}
	
	static void map_vertex_attrib1d_ARB_replacement(GLIContext ctx, GLuint index, GLuint size, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: map_vertex_attrib1d_ARB called.");
		
		return map_vertex_attrib1d_ARB_reenter(ctx, index, size, u1, u2, stride, order, GLdouble);
	}
	
	static void map_vertex_attrib1f_ARB_replacement(GLIContext ctx, GLuint index, GLuint size, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: map_vertex_attrib1f_ARB called.");
		
		return map_vertex_attrib1f_ARB_reenter(ctx, index, size, u1, u2, stride, order, GLfloat);
	}
	
	static void map_vertex_attrib2d_ARB_replacement(GLIContext ctx, GLuint index, GLuint size, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: map_vertex_attrib2d_ARB called.");
		
		return map_vertex_attrib2d_ARB_reenter(ctx, index, size, u1, u2, ustride, uorder, v1, v2, vstride, vorder, GLdouble);
	}
	
	static void map_vertex_attrib2f_ARB_replacement(GLIContext ctx, GLuint index, GLuint size, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: map_vertex_attrib2f_ARB called.");
		
		return map_vertex_attrib2f_ARB_reenter(ctx, index, size, u1, u2, ustride, uorder, v1, v2, vstride, vorder, GLfloat);
	}
	
	static void point_parameterf_replacement(GLIContext ctx, GLenum pname, GLfloat param)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: point_parameterf called.");
		
		return point_parameterf_reenter(ctx, pname, param);
	}
	
	static void point_parameterfv_replacement(GLIContext ctx, GLenum pname, const GLfloat *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: point_parameterfv called.");
		
		return point_parameterfv_reenter(ctx, pname, GLfloat);
	}
	
	static void point_parameteri_replacement(GLIContext ctx, GLenum pname, GLint param)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: point_parameteri called.");
		
		return point_parameteri_reenter(ctx, pname, param);
	}
	
	static void point_parameteriv_replacement(GLIContext ctx, GLenum pname, const GLint *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: point_parameteriv called.");
		
		return point_parameteriv_reenter(ctx, pname, GLint);
	}
	
	static void fog_coordf_replacement(GLIContext ctx, GLfloat coord)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: fog_coordf called.");
		
		return fog_coordf_reenter(ctx, coord);
	}
	
	static void fog_coordfv_replacement(GLIContext ctx, const GLfloat *coord)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: fog_coordfv called.");
		
		return fog_coordfv_reenter(ctx, GLfloat);
	}
	
	static void fog_coordd_replacement(GLIContext ctx, GLdouble coord)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: fog_coordd called.");
		
		return fog_coordd_reenter(ctx, coord);
	}
	
	static void fog_coorddv_replacement(GLIContext ctx, const GLdouble *coord)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: fog_coorddv called.");
		
		return fog_coorddv_reenter(ctx, GLdouble);
	}
	
	static void fog_coord_pointer_replacement(GLIContext ctx, GLenum type, GLsizei stride, const GLvoid *pointer)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: fog_coord_pointer called.");
		
		return fog_coord_pointer_reenter(ctx, type, stride, GLvoid);
	}
	
	static void vertex_array_parameteri_EXT_replacement(GLIContext ctx, GLenum pname, GLint param)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_array_parameteri_EXT called.");
		
		return vertex_array_parameteri_EXT_reenter(ctx, pname, param);
	}
	
	static void bind_vertex_array_EXT_replacement(GLIContext ctx, GLuint id)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: bind_vertex_array_EXT called.");
		
		return bind_vertex_array_EXT_reenter(ctx, id);
	}
	
	static void delete_vertex_arrays_EXT_replacement(GLIContext ctx, GLsizei n, const GLuint *ids)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: delete_vertex_arrays_EXT called.");
		
		return delete_vertex_arrays_EXT_reenter(ctx, n, GLuint);
	}
	
	static void gen_vertex_arrays_EXT_replacement(GLIContext ctx, GLsizei n, GLuint *ids)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: gen_vertex_arrays_EXT called.");
		
		return gen_vertex_arrays_EXT_reenter(ctx, n, *ids);
	}
	
	static GLboolean is_vertex_array_EXT_replacement(GLIContext ctx, GLuint id)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: is_vertex_array_EXT called.");
		
		return is_vertex_array_EXT_reenter(ctx, id);
	}
	
	static void element_pointer_APPLE_replacement(GLIContext ctx, GLenum type, const GLvoid *pointer)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: element_pointer_APPLE called.");
		
		return element_pointer_APPLE_reenter(ctx, type, GLvoid);
	}
	
	static void draw_element_array_APPLE_replacement(GLIContext ctx, GLenum mode, GLint first, GLsizei count)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: draw_element_array_APPLE called.");
		
		return draw_element_array_APPLE_reenter(ctx, mode, first, count);
	}
	
	static void draw_range_element_array_APPLE_replacement(GLIContext ctx, GLenum mode, GLuint start, GLuint end, GLint first, GLsizei count)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: draw_range_element_array_APPLE called.");
		
		return draw_range_element_array_APPLE_reenter(ctx, mode, start, end, first, count);
	}
	
	static void weightbv_ARB_replacement(GLIContext ctx, GLint size, const GLbyte *weights)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: weightbv_ARB called.");
		
		return weightbv_ARB_reenter(ctx, size, GLbyte);
	}
	
	static void weightsv_ARB_replacement(GLIContext ctx, GLint size, const GLshort *weights)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: weightsv_ARB called.");
		
		return weightsv_ARB_reenter(ctx, size, GLshort);
	}
	
	static void weightiv_ARB_replacement(GLIContext ctx, GLint size, const GLint *weights)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: weightiv_ARB called.");
		
		return weightiv_ARB_reenter(ctx, size, GLint);
	}
	
	static void weightfv_ARB_replacement(GLIContext ctx, GLint size, const GLfloat *weights)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: weightfv_ARB called.");
		
		return weightfv_ARB_reenter(ctx, size, GLfloat);
	}
	
	static void weightdv_ARB_replacement(GLIContext ctx, GLint size, const GLdouble *weights)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: weightdv_ARB called.");
		
		return weightdv_ARB_reenter(ctx, size, GLdouble);
	}
	
	static void weightubv_ARB_replacement(GLIContext ctx, GLint size, const GLubyte *weights)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: weightubv_ARB called.");
		
		return weightubv_ARB_reenter(ctx, size, GLubyte);
	}
	
	static void weightusv_ARB_replacement(GLIContext ctx, GLint size, const GLushort *weights)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: weightusv_ARB called.");
		
		return weightusv_ARB_reenter(ctx, size, GLushort);
	}
	
	static void weightuiv_ARB_replacement(GLIContext ctx, GLint size, const GLuint *weights)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: weightuiv_ARB called.");
		
		return weightuiv_ARB_reenter(ctx, size, GLuint);
	}
	
	static void weight_pointer_ARB_replacement(GLIContext ctx, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: weight_pointer_ARB called.");
		
		return weight_pointer_ARB_reenter(ctx, size, type, stride, GLvoid);
	}
	
	static void vertex_blend_ARB_replacement(GLIContext ctx, GLint count)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_blend_ARB called.");
		
		return vertex_blend_ARB_reenter(ctx, count);
	}
	
	static void multi_draw_arrays_replacement(GLIContext ctx, GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: multi_draw_arrays called.");
		
		return multi_draw_arrays_reenter(ctx, mode, GLint const *count, drawcount);
	}
	
	static void multi_draw_elements_replacement(GLIContext ctx, GLenum mode, const GLsizei *count, GLenum type, const GLvoid* const *indices, GLsizei drawcount)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: multi_draw_elements called.");
		
		return multi_draw_elements_reenter(ctx, mode, GLsizei GLenum const const GLsizei);
	}
	
	static void window_pos2d_replacement((GLIContext ctx, GLdouble x, GLdouble y)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: window_pos2d called.");
		
		return window_pos2d_reenter(ctx, x, y);
	}
	
	static void window_pos2dv_replacement((GLIContext ctx, const GLdouble *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: window_pos2dv called.");
		
		return window_pos2dv_reenter(ctx, GLdouble);
	}
	
	static void window_pos2f_replacement((GLIContext ctx, GLfloat x, GLfloat y)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: window_pos2f called.");
		
		return window_pos2f_reenter(ctx, x, y);
	}
	
	static void window_pos2fv_replacement((GLIContext ctx, const GLfloat *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: window_pos2fv called.");
		
		return window_pos2fv_reenter(ctx, GLfloat);
	}
	
	static void window_pos2i_replacement((GLIContext ctx, GLint x, GLint y)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: window_pos2i called.");
		
		return window_pos2i_reenter(ctx, x, y);
	}
	
	static void window_pos2iv_replacement((GLIContext ctx, const GLint *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: window_pos2iv called.");
		
		return window_pos2iv_reenter(ctx, GLint);
	}
	
	static void window_pos2s_replacement((GLIContext ctx, GLshort x, GLshort y)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: window_pos2s called.");
		
		return window_pos2s_reenter(ctx, x, y);
	}
	
	static void window_pos2sv_replacement((GLIContext ctx, const GLshort *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: window_pos2sv called.");
		
		return window_pos2sv_reenter(ctx, GLshort);
	}
	
	static void window_pos3d_replacement((GLIContext ctx, GLdouble x, GLdouble y, GLdouble z)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: window_pos3d called.");
		
		return window_pos3d_reenter(ctx, x, y, z);
	}
	
	static void window_pos3dv_replacement((GLIContext ctx, const GLdouble *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: window_pos3dv called.");
		
		return window_pos3dv_reenter(ctx, GLdouble);
	}
	
	static void window_pos3f_replacement((GLIContext ctx, GLfloat x, GLfloat y, GLfloat z)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: window_pos3f called.");
		
		return window_pos3f_reenter(ctx, x, y, z);
	}
	
	static void window_pos3fv_replacement((GLIContext ctx, const GLfloat *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: window_pos3fv called.");
		
		return window_pos3fv_reenter(ctx, GLfloat);
	}
	
	static void window_pos3i_replacement((GLIContext ctx, GLint x, GLint y, GLint z)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: window_pos3i called.");
		
		return window_pos3i_reenter(ctx, x, y, z);
	}
	
	static void window_pos3iv_replacement((GLIContext ctx, const GLint *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: window_pos3iv called.");
		
		return window_pos3iv_reenter(ctx, GLint);
	}
	
	static void window_pos3s_replacement((GLIContext ctx, GLshort x, GLshort y, GLshort z)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: window_pos3s called.");
		
		return window_pos3s_reenter(ctx, x, y, z);
	}
	
	static void window_pos3sv_replacement((GLIContext ctx, const GLshort *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: window_pos3sv called.");
		
		return window_pos3sv_reenter(ctx, GLshort);
	}
	
	static void active_stencil_face_EXT_replacement((GLIContext ctx, GLenum face)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: active_stencil_face_EXT called.");
		
		return active_stencil_face_EXT_reenter(ctx, face);
	}
	
	static void stencil_op_separate_ATI_replacement((GLIContext ctx, GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: stencil_op_separate_ATI called.");
		
		return stencil_op_separate_ATI_reenter(ctx, face, sfail, dpfail, dppass);
	}
	
	static void stencil_func_separate_ATI_replacement((GLIContext ctx, GLenum frontfunc, GLenum backfunc, GLint ref, GLuint mask)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: stencil_func_separate_ATI called.");
		
		return stencil_func_separate_ATI_reenter(ctx, frontfunc, backfunc, ref, mask);
	}
	
	static void flush_render_APPLE_replacement((GLIContext ctx)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: flush_render_APPLE called.");
		
		return flush_render_APPLE_reenter(ctx);
	}
	
	static void finish_render_APPLE_replacement((GLIContext ctx)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: finish_render_APPLE called.");
		
		return finish_render_APPLE_reenter(ctx);
	}
	
	static void swap_APPLE_replacement(GLIContext ctx)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: swap_APPLE called.");
		
		return swap_APPLE_reenter(ctx);
	}
	
	static void delete_object_ARB_replacement((GLIContext ctx, GLhandleARB obj)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: delete_object_ARB called.");
		
		return delete_object_ARB_reenter(ctx, obj);
	}
	
	static GLhandleARB get_handle_ARB_replacement((GLIContext ctx, GLenum pname)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_handle_ARB called.");
		
		return get_handle_ARB_reenter(ctx, pname);
	}
	
	static void detach_object_ARB_replacement((GLIContext ctx, GLhandleARB containerObj, GLhandleARB attachedObj)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: detach_object_ARB called.");
		
		return detach_object_ARB_reenter(ctx, containerObj, attachedObj);
	}
	
	static GLhandleARB create_shader_object_ARB_replacement((GLIContext ctx, GLenum shaderType)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: create_shader_object_ARB called.");
		
		return create_shader_object_ARB_reenter(ctx, shaderType);
	}
	
	static void shader_source_ARB_replacement((GLIContext ctx, GLhandleARB shaderObj, GLsizei count, const GLcharARB* const *string, const GLint *length)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: shader_source_ARB called.");
		
		return shader_source_ARB_reenter(ctx, shaderObj, count, GLcharARB* *string, GLint);
	}
	
	static void compile_shader_ARB_replacement((GLIContext ctx, GLhandleARB shaderObj)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: compile_shader_ARB called.");
		
		return compile_shader_ARB_reenter(ctx, shaderObj);
	}
	
	static GLhandleARB create_program_object_ARB_replacement((GLIContext ctx)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: create_program_object_ARB called.");
		
		return create_program_object_ARB_reenter(ctx);
	}
	
	static void attach_object_ARB_replacement((GLIContext ctx, GLhandleARB containerObj, GLhandleARB obj)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: attach_object_ARB called.");
		
		return attach_object_ARB_reenter(ctx, containerObj, obj);
	}
	
	static void link_program_ARB_replacement((GLIContext ctx, GLhandleARB programObj)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: link_program_ARB called.");
		
		return link_program_ARB_reenter(ctx, programObj);
	}
	
	static void use_program_object_ARB_replacement((GLIContext ctx, GLhandleARB programObj)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: use_program_object_ARB called.");
		
		return use_program_object_ARB_reenter(ctx, programObj);
	}
	
	static void validate_program_ARB_replacement((GLIContext ctx, GLhandleARB programObj)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: validate_program_ARB called.");
		
		return validate_program_ARB_reenter(ctx, programObj);
	}
	
	static void uniform1f_ARB_replacement((GLIContext ctx, GLint location, GLfloat v0)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: uniform1f_ARB called.");
		
		return uniform1f_ARB_reenter(ctx, location, v0);
	}
	
	static void uniform2f_ARB_replacement((GLIContext ctx, GLint location, GLfloat v0, GLfloat v1)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: uniform2f_ARB called.");
		
		return uniform2f_ARB_reenter(ctx, location, v0, v1);
	}
	
	static void uniform3f_ARB_replacement((GLIContext ctx, GLint location, GLfloat v0, GLfloat v1, GLfloat v2)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: uniform3f_ARB called.");
		
		return uniform3f_ARB_reenter(ctx, location, v0, v1, v2);
	}
	
	static void uniform4f_ARB_replacement((GLIContext ctx, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: uniform4f_ARB called.");
		
		return uniform4f_ARB_reenter(ctx, location, v0, v1, v2, v3);
	}
	
	static void uniform1i_ARB_replacement((GLIContext ctx, GLint location, GLint v0)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: uniform1i_ARB called.");
		
		return uniform1i_ARB_reenter(ctx, location, v0);
	}
	
	static void uniform2i_ARB_replacement((GLIContext ctx, GLint location, GLint v0, GLint v1)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: uniform2i_ARB called.");
		
		return uniform2i_ARB_reenter(ctx, location, v0, v1);
	}
	
	static void uniform3i_ARB_replacement((GLIContext ctx, GLint location, GLint v0, GLint v1, GLint v2)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: uniform3i_ARB called.");
		
		return uniform3i_ARB_reenter(ctx, location, v0, v1, v2);
	}
	
	static void uniform4i_ARB_replacement((GLIContext ctx, GLint location, GLint v0, GLint v1, GLint v2, GLint v3)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: uniform4i_ARB called.");
		
		return uniform4i_ARB_reenter(ctx, location, v0, v1, v2, v3);
	}
	
	static void uniform1fv_ARB_replacement((GLIContext ctx, GLint location, GLsizei count, const GLfloat *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: uniform1fv_ARB called.");
		
		return uniform1fv_ARB_reenter(ctx, location, count, GLfloat);
	}
	
	static void uniform2fv_ARB_replacement((GLIContext ctx, GLint location, GLsizei count, const GLfloat *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: uniform2fv_ARB called.");
		
		return uniform2fv_ARB_reenter(ctx, location, count, GLfloat);
	}
	
	static void uniform3fv_ARB_replacement((GLIContext ctx, GLint location, GLsizei count, const GLfloat *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: uniform3fv_ARB called.");
		
		return uniform3fv_ARB_reenter(ctx, location, count, GLfloat);
	}
	
	static void uniform4fv_ARB_replacement((GLIContext ctx, GLint location, GLsizei count, const GLfloat *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: uniform4fv_ARB called.");
		
		return uniform4fv_ARB_reenter(ctx, location, count, GLfloat);
	}
	
	static void uniform1iv_ARB_replacement((GLIContext ctx, GLint location, GLsizei count, const GLint *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: uniform1iv_ARB called.");
		
		return uniform1iv_ARB_reenter(ctx, location, count, GLint);
	}
	
	static void uniform2iv_ARB_replacement((GLIContext ctx, GLint location, GLsizei count, const GLint *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: uniform2iv_ARB called.");
		
		return uniform2iv_ARB_reenter(ctx, location, count, GLint);
	}
	
	static void uniform3iv_ARB_replacement((GLIContext ctx, GLint location, GLsizei count, const GLint *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: uniform3iv_ARB called.");
		
		return uniform3iv_ARB_reenter(ctx, location, count, GLint);
	}
	
	static void uniform4iv_ARB_replacement((GLIContext ctx, GLint location, GLsizei count, const GLint *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: uniform4iv_ARB called.");
		
		return uniform4iv_ARB_reenter(ctx, location, count, GLint);
	}
	
	static void uniform_matrix2fv_ARB_replacement((GLIContext ctx, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: uniform_matrix2fv_ARB called.");
		
		return uniform_matrix2fv_ARB_reenter(ctx, location, count, transpose, GLfloat);
	}
	
	static void uniform_matrix3fv_ARB_replacement((GLIContext ctx, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: uniform_matrix3fv_ARB called.");
		
		return uniform_matrix3fv_ARB_reenter(ctx, location, count, transpose, GLfloat);
	}
	
	static void uniform_matrix4fv_ARB_replacement((GLIContext ctx, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: uniform_matrix4fv_ARB called.");
		
		return uniform_matrix4fv_ARB_reenter(ctx, location, count, transpose, GLfloat);
	}
	
	static void get_object_parameterfv_ARB_replacement((GLIContext ctx, GLhandleARB obj, GLenum pname, GLfloat *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_object_parameterfv_ARB called.");
		
		return get_object_parameterfv_ARB_reenter(ctx, obj, pname, *params);
	}
	
	static void get_object_parameteriv_ARB_replacement((GLIContext ctx, GLhandleARB obj, GLenum pname, GLint *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_object_parameteriv_ARB called.");
		
		return get_object_parameteriv_ARB_reenter(ctx, obj, pname, *params);
	}
	
	static void get_info_log_ARB_replacement((GLIContext ctx, GLhandleARB obj, GLsizei maxLength, GLsizei *length, GLcharARB *infoLog)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_info_log_ARB called.");
		
		return get_info_log_ARB_reenter(ctx, obj, maxLength, *length, *infoLog);
	}
	
	static void get_attached_objects_ARB_replacement((GLIContext ctx, GLhandleARB containerObj, GLsizei maxCount, GLsizei *count, GLhandleARB *obj)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_attached_objects_ARB called.");
		
		return get_attached_objects_ARB_reenter(ctx, containerObj, maxCount, *count, *obj);
	}
	
	static GLint get_uniform_location_ARB_replacement((GLIContext ctx, GLhandleARB programObj, const GLcharARB *name)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_uniform_location_ARB called.");
		
		return get_uniform_location_ARB_reenter(ctx, programObj, GLcharARB);
	}
	
	static void get_active_uniform_ARB_replacement((GLIContext ctx, GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei *length, GLint *size, GLenum *type, GLcharARB *name)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_active_uniform_ARB called.");
		
		return get_active_uniform_ARB_reenter(ctx, programObj, index, maxLength, *length, *size, *type, *name);
	}
	
	static void get_uniformfv_ARB_replacement((GLIContext ctx, GLhandleARB programObj, GLint location, GLfloat *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_uniformfv_ARB called.");
		
		return get_uniformfv_ARB_reenter(ctx, programObj, location, *params);
	}
	
	static void get_uniformiv_ARB_replacement((GLIContext ctx, GLhandleARB programObj, GLint location, GLint *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_uniformiv_ARB called.");
		
		return get_uniformiv_ARB_reenter(ctx, programObj, location, *params);
	}
	
	static void get_shader_source_ARB_replacement((GLIContext ctx, GLhandleARB obj, GLsizei maxLength, GLsizei *length, GLcharARB *source)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_shader_source_ARB called.");
		
		return get_shader_source_ARB_reenter(ctx, obj, maxLength, *length, *source);
	}
	
	static void bind_attrib_location_ARB_replacement((GLIContext ctx, GLhandleARB programObj, GLuint index, const GLcharARB *name)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: bind_attrib_location_ARB called.");
		
		return bind_attrib_location_ARB_reenter(ctx, programObj, index, GLcharARB);
	}
	
	static void get_active_attrib_ARB_replacement((GLIContext ctx, GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei *length, GLint *size, GLenum *type, GLcharARB *name)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_active_attrib_ARB called.");
		
		return get_active_attrib_ARB_reenter(ctx, programObj, index, maxLength, *length, *size, *type, *name);
	}
	
	static GLint get_attrib_location_ARB_replacement((GLIContext ctx, GLhandleARB programObj, const GLcharARB *name)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_attrib_location_ARB called.");
		
		return get_attrib_location_ARB_reenter(ctx, programObj, GLcharARB);
	}
	
	static void clamp_color_ARB_replacement((GLIContext ctx, GLenum target, GLenum clamp)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: clamp_color_ARB called.");
		
		return clamp_color_ARB_reenter(ctx, target, clamp);
	}
	
	static void gen_queries_replacement((GLIContext ctx, GLsizei n, GLuint *ids)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: gen_queries called.");
		
		return gen_queries_reenter(ctx, n, *ids);
	}
	
	static void delete_queries_replacement((GLIContext ctx, GLsizei n, const GLuint *ids)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: delete_queries called.");
		
		return delete_queries_reenter(ctx, n, GLuint);
	}
	
	static GLboolean is_query_replacement((GLIContext ctx, GLuint id)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: is_query called.");
		
		return is_query_reenter(ctx, id);
	}
	
	static void begin_query_replacement((GLIContext ctx, GLenum target, GLuint id)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: begin_query called.");
		
		return begin_query_reenter(ctx, target, id);
	}
	
	static void end_query_replacement((GLIContext ctx, GLenum target)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: end_query called.");
		
		return end_query_reenter(ctx, target);
	}
	
	static void get_queryiv_replacement((GLIContext ctx, GLenum target, GLenum pname, GLint *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_queryiv called.");
		
		return get_queryiv_reenter(ctx, target, pname, *params);
	}
	
	static void get_query_objectiv_replacement((GLIContext ctx, GLuint id, GLenum pname, GLint *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_query_objectiv called.");
		
		return get_query_objectiv_reenter(ctx, id, pname, *params);
	}
	
	static void get_query_objectuiv_replacement((GLIContext ctx, GLuint id, GLenum pname, GLuint *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_query_objectuiv called.");
		
		return get_query_objectuiv_reenter(ctx, id, pname, *params);
	}
	
	static void bind_buffer_replacement((GLIContext ctx, GLenum target, GLuint buffer)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: bind_buffer called.");
		
		return bind_buffer_reenter(ctx, target, buffer);
	}
	
	static void delete_buffers_replacement((GLIContext ctx, GLsizei n, const GLuint *buffers)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: delete_buffers called.");
		
		return delete_buffers_reenter(ctx, n, GLuint);
	}
	
	static void gen_buffers_replacement((GLIContext ctx, GLsizei n, GLuint *buffers)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: gen_buffers called.");
		
		return gen_buffers_reenter(ctx, n, *buffers);
	}
	
	static GLboolean is_buffer_replacement((GLIContext ctx, GLuint buffer)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: is_buffer called.");
		
		return is_buffer_reenter(ctx, buffer);
	}
	
	static void buffer_data_replacement((GLIContext ctx, GLenum target, GLsizeiptrARB size, const GLvoid *data, GLenum usage)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: buffer_data called.");
		
		return buffer_data_reenter(ctx, target, size, GLvoid GLenum);
	}
	
	static void buffer_sub_data_replacement((GLIContext ctx, GLenum target, GLintptrARB offset, GLsizeiptrARB size, const GLvoid *data)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: buffer_sub_data called.");
		
		return buffer_sub_data_reenter(ctx, target, offset, size, GLvoid);
	}
	
	static void get_buffer_sub_data_replacement((GLIContext ctx, GLenum target, GLintptrARB offset, GLsizeiptrARB size, GLvoid *data)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_buffer_sub_data called.");
		
		return get_buffer_sub_data_reenter(ctx, target, offset, size, *data);
	}
	
	static GLvoid *map_buffer_replacement((GLIContext ctx, GLenum target, GLenum access)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: *map_buffer called.");
		
		return *map_buffer_reenter(ctx, target, access);
	}
	
	static GLboolean unmap_buffer_replacement((GLIContext ctx, GLenum target)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: unmap_buffer called.");
		
		return unmap_buffer_reenter(ctx, target);
	}
	
	static void get_buffer_parameteriv_replacement((GLIContext ctx, GLenum target, GLenum pname, GLint *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_buffer_parameteriv called.");
		
		return get_buffer_parameteriv_reenter(ctx, target, pname, *params);
	}
	
	static void get_buffer_pointerv_replacement((GLIContext ctx, GLenum target, GLenum pname, GLvoid **params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_buffer_pointerv called.");
		
		return get_buffer_pointerv_reenter(ctx, target, pname, **params);
	}
	
	static void depth_bounds_EXT_replacement((GLIContext ctx, GLclampd zmin, GLclampd zmax)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: depth_bounds_EXT called.");
		
		return depth_bounds_EXT_reenter(ctx, zmin, zmax);
	}
	
	static void draw_buffers_ARB_replacement((GLIContext ctx, GLsizei n, const GLenum *bufs)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: draw_buffers_ARB called.");
		
		return draw_buffers_ARB_reenter(ctx, n, GLenum);
	}
	
	static GLboolean is_shader_replacement((GLIContext ctx, GLuint shader)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: is_shader called.");
		
		return is_shader_reenter(ctx, shader);
	}
	
	static GLboolean is_program_replacement((GLIContext ctx, GLuint program)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: is_program called.");
		
		return is_program_reenter(ctx, program);
	}
	
	static void get_shaderiv_replacement((GLIContext ctx, GLuint shader, GLenum pname, GLint *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_shaderiv called.");
		
		return get_shaderiv_reenter(ctx, shader, pname, *params);
	}
	
	static void get_programiv_replacement((GLIContext ctx, GLuint program, GLenum pname, GLint *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_programiv called.");
		
		return get_programiv_reenter(ctx, program, pname, *params);
	}
	
	static void get_shader_info_log_replacement((GLIContext ctx, GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_shader_info_log called.");
		
		return get_shader_info_log_reenter(ctx, shader, bufSize, *length, *infoLog);
	}
	
	static void get_program_info_log_replacement((GLIContext ctx, GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_program_info_log called.");
		
		return get_program_info_log_reenter(ctx, program, bufSize, *length, *infoLog);
	}
	
	static void stencil_func_separate_replacement((GLIContext ctx, GLenum face, GLenum func, GLint ref, GLuint mask)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: stencil_func_separate called.");
		
		return stencil_func_separate_reenter(ctx, face, func, ref, mask);
	}
	
	static void stencil_mask_separate_replacement((GLIContext ctx, GLenum face, GLuint mask)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: stencil_mask_separate called.");
		
		return stencil_mask_separate_reenter(ctx, face, mask);
	}
	
	static void multi_draw_element_array_APPLE_replacement(GLIContext ctx, GLenum mode, const GLint *first, const GLsizei *count, GLsizei primcount)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: multi_draw_element_array_APPLE called.");
		
		return multi_draw_element_array_APPLE_reenter(ctx, mode, GLint const *count, primcount);
	}
	
	static void multi_draw_range_element_array_APPLE_replacement(GLIContext ctx, GLenum mode, GLuint start, GLuint end, const GLint *first, const GLsizei *count, GLsizei primcount)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: multi_draw_range_element_array_APPLE called.");
		
		return multi_draw_range_element_array_APPLE_reenter(ctx, mode, start, end, GLint const *count, primcount);
	}
	
	static GLboolean is_renderbuffer_EXT_replacement((GLIContext ctx, GLuint renderbuffer)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: is_renderbuffer_EXT called.");
		
		return is_renderbuffer_EXT_reenter(ctx, renderbuffer);
	}
	
	static void bind_renderbuffer_EXT_replacement((GLIContext ctx, GLenum target, GLuint renderbuffer)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: bind_renderbuffer_EXT called.");
		
		return bind_renderbuffer_EXT_reenter(ctx, target, renderbuffer);
	}
	
	static void delete_renderbuffers_EXT_replacement((GLIContext ctx, GLsizei n, const GLuint *renderbuffers)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: delete_renderbuffers_EXT called.");
		
		return delete_renderbuffers_EXT_reenter(ctx, n, GLuint);
	}
	
	static void gen_renderbuffers_EXT_replacement((GLIContext ctx, GLsizei n, GLuint *renderbuffers)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: gen_renderbuffers_EXT called.");
		
		return gen_renderbuffers_EXT_reenter(ctx, n, *renderbuffers);
	}
	
	static void renderbuffer_storage_EXT_replacement((GLIContext ctx, GLenum target, GLenum internalformat, GLsizei width, GLsizei height)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: renderbuffer_storage_EXT called.");
		
		return renderbuffer_storage_EXT_reenter(ctx, target, internalformat, width, height);
	}
	
	static void get_renderbuffer_parameteriv_EXT_replacement((GLIContext ctx, GLenum target, GLenum pname, GLint *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_renderbuffer_parameteriv_EXT called.");
		
		return get_renderbuffer_parameteriv_EXT_reenter(ctx, target, pname, *params);
	}
	
	static GLboolean is_framebuffer_EXT_replacement((GLIContext ctx, GLuint framebuffer)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: is_framebuffer_EXT called.");
		
		return is_framebuffer_EXT_reenter(ctx, framebuffer);
	}
	
	static void bind_framebuffer_EXT_replacement((GLIContext ctx, GLenum target, GLuint framebuffer)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: bind_framebuffer_EXT called.");
		
		return bind_framebuffer_EXT_reenter(ctx, target, framebuffer);
	}
	
	static void delete_framebuffers_EXT_replacement((GLIContext ctx, GLsizei n, const GLuint *framebuffers)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: delete_framebuffers_EXT called.");
		
		return delete_framebuffers_EXT_reenter(ctx, n, GLuint);
	}
	
	static void gen_framebuffers_EXT_replacement((GLIContext ctx, GLsizei n, GLuint *framebuffers)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: gen_framebuffers_EXT called.");
		
		return gen_framebuffers_EXT_reenter(ctx, n, *framebuffers);
	}
	
	static GLenum check_framebuffer_status_EXT_replacement((GLIContext ctx, GLenum target)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: check_framebuffer_status_EXT called.");
		
		return check_framebuffer_status_EXT_reenter(ctx, target);
	}
	
	static void framebuffer_texture1D_EXT_replacement((GLIContext ctx, GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: framebuffer_texture1D_EXT called.");
		
		return framebuffer_texture1D_EXT_reenter(ctx, target, attachment, textarget, texture, level);
	}
	
	static void framebuffer_texture2D_EXT_replacement((GLIContext ctx, GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: framebuffer_texture2D_EXT called.");
		
		return framebuffer_texture2D_EXT_reenter(ctx, target, attachment, textarget, texture, level);
	}
	
	static void framebuffer_texture3D_EXT_replacement((GLIContext ctx, GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: framebuffer_texture3D_EXT called.");
		
		return framebuffer_texture3D_EXT_reenter(ctx, target, attachment, textarget, texture, level, zoffset);
	}
	
	static void framebuffer_renderbuffer_EXT_replacement((GLIContext ctx, GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: framebuffer_renderbuffer_EXT called.");
		
		return framebuffer_renderbuffer_EXT_reenter(ctx, target, attachment, renderbuffertarget, renderbuffer);
	}
	
	static void get_framebuffer_attachment_parameteriv_EXT_replacement((GLIContext ctx, GLenum target, GLenum attachment, GLenum pname, GLint *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_framebuffer_attachment_parameteriv_EXT called.");
		
		return get_framebuffer_attachment_parameteriv_EXT_reenter(ctx, target, attachment, pname, *params);
	}
	
	static void generate_mipmap_EXT_replacement((GLIContext ctx, GLenum target)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: generate_mipmap_EXT called.");
		
		return generate_mipmap_EXT_reenter(ctx, target);
	}
	
	static void buffer_parameteri_APPLE_replacement((GLIContext ctx, GLenum target, GLenum pname, GLint param)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: buffer_parameteri_APPLE called.");
		
		return buffer_parameteri_APPLE_reenter(ctx, target, pname, param);
	}
	
	static void flush_mapped_buffer_range_APPLE_replacement((GLIContext ctx, GLenum target, GLintptr offset, GLsizeiptr size)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: flush_mapped_buffer_range_APPLE called.");
		
		return flush_mapped_buffer_range_APPLE_reenter(ctx, target, offset, size);
	}
	
	static void program_env_parameters4fv_EXT_replacement(GLIContext ctx, GLenum target, GLuint index, GLsizei count, const GLfloat *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_env_parameters4fv_EXT called.");
		
		return program_env_parameters4fv_EXT_reenter(ctx, target, index, count, GLfloat);
	}
	
	static void program_local_parameters4fv_EXT_replacement(GLIContext ctx, GLenum target, GLuint index, GLsizei count, const GLfloat *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_local_parameters4fv_EXT called.");
		
		return program_local_parameters4fv_EXT_reenter(ctx, target, index, count, GLfloat);
	}
	
	static GLenum object_purgeable_APPLE_replacement(GLIContext ctx, GLenum objectType, GLuint name, GLenum option)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: object_purgeable_APPLE called.");
		
		return object_purgeable_APPLE_reenter(ctx, objectType, name, option);
	}
	
	static GLenum object_unpurgeable_APPLE_replacement(GLIContext ctx, GLenum objectType, GLuint name, GLenum option)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: object_unpurgeable_APPLE called.");
		
		return object_unpurgeable_APPLE_reenter(ctx, objectType, name, option);
	}
	
	static void (*get_object_parameteriv_APPLE_replacement((GLIContext ctx, GLenum objectType, GLuint name, GLenum pname, GLint* params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: (*get_object_parameteriv_APPLE called.");
		
		return (*get_object_parameteriv_APPLE_reenter(ctx, objectType, name, pname, params);
	}
	
	static void program_parameteri_EXT_replacement(GLIContext ctx, GLuint program_name, GLenum pname, GLint value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_parameteri_EXT called.");
		
		return program_parameteri_EXT_reenter(ctx, program_name, pname, value);
	}
	
	static void framebuffer_texture_EXT_replacement(GLIContext ctx, GLenum target, GLenum attachment, GLuint texture, GLint level)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: framebuffer_texture_EXT called.");
		
		return framebuffer_texture_EXT_reenter(ctx, target, attachment, texture, level);
	}
	
	static void framebuffer_texture_layer_EXT_replacement(GLIContext ctx, GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: framebuffer_texture_layer_EXT called.");
		
		return framebuffer_texture_layer_EXT_reenter(ctx, target, attachment, texture, level, layer);
	}
	
	static void framebuffer_texture_face_EXT_replacement(GLIContext ctx, GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: framebuffer_texture_face_EXT called.");
		
		return framebuffer_texture_face_EXT_reenter(ctx, target, attachment, texture, level, face);
	}
	
	static void bind_buffer_range_EXT_replacement(GLIContext ctx, GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: bind_buffer_range_EXT called.");
		
		return bind_buffer_range_EXT_reenter(ctx, target, index, buffer, offset, size);
	}
	
	static void bind_buffer_offset_EXT_replacement(GLIContext ctx, GLenum target, GLuint index, GLuint buffer, GLintptr offset)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: bind_buffer_offset_EXT called.");
		
		return bind_buffer_offset_EXT_reenter(ctx, target, index, buffer, offset);
	}
	
	static void bind_buffer_base_EXT_replacement(GLIContext ctx, GLenum target, GLuint index, GLuint buffer)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: bind_buffer_base_EXT called.");
		
		return bind_buffer_base_EXT_reenter(ctx, target, index, buffer);
	}
	
	static void begin_transform_feedback_EXT_replacement(GLIContext ctx, GLenum primitiveMode)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: begin_transform_feedback_EXT called.");
		
		return begin_transform_feedback_EXT_reenter(ctx, primitiveMode);
	}
	
	static void end_transform_feedback_EXT_replacement(GLIContext ctx)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: end_transform_feedback_EXT called.");
		
		return end_transform_feedback_EXT_reenter(ctx);
	}
	
	static void transform_feedback_varyings_EXT_replacement(GLIContext ctx, GLuint program, GLsizei count, const GLchar* const *varyings, GLenum bufferMode)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: transform_feedback_varyings_EXT called.");
		
		return transform_feedback_varyings_EXT_reenter(ctx, program, count, GLchar* *varyings, bufferMode);
	}
	
	static void get_transform_feedback_varying_EXT_replacement(GLIContext ctx, GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_transform_feedback_varying_EXT called.");
		
		return get_transform_feedback_varying_EXT_reenter(ctx, program, index, bufSize, *length, *size, *type, *name);
	}
	
	static void get_integer_indexedv_EXT_replacement(GLIContext ctx, GLenum param, GLuint index, GLint *values)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_integer_indexedv_EXT called.");
		
		return get_integer_indexedv_EXT_reenter(ctx, param, index, *values);
	}
	
	static void get_boolean_indexedv_EXT_replacement(GLIContext ctx, GLenum param, GLuint index, GLboolean *values)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_boolean_indexedv_EXT called.");
		
		return get_boolean_indexedv_EXT_reenter(ctx, param, index, *values);
	}
	
	static void uniform_buffer_EXT_replacement(GLIContext ctx, GLuint program, GLint location, GLuint buffer)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: uniform_buffer_EXT called.");
		
		return uniform_buffer_EXT_reenter(ctx, program, location, buffer);
	}
	
	static GLint get_uniform_buffer_size_EXT_replacement(GLIContext ctx, GLuint program, GLint location)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_uniform_buffer_size_EXT called.");
		
		return get_uniform_buffer_size_EXT_reenter(ctx, program, location);
	}
	
	static GLintptr get_uniform_buffer_offset_EXT_replacement(GLIContext ctx, GLuint program, GLint location)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_uniform_buffer_offset_EXT called.");
		
		return get_uniform_buffer_offset_EXT_reenter(ctx, program, location);
	}
	
	static void clear_colorIi_EXT_replacement((GLIContext ctx, GLint r, GLint g, GLint b, GLint a )
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: clear_colorIi_EXT called.");
		
		return clear_colorIi_EXT_reenter(ctx, r, g, b, a);
	}
	
	static void clear_colorIui_EXT_replacement((GLIContext ctx, GLuint r, GLuint g, GLuint b, GLuint a )
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: clear_colorIui_EXT called.");
		
		return clear_colorIui_EXT_reenter(ctx, r, g, b, a);
	}
	
	static void tex_parameterIiv_EXT_replacement(GLIContext ctx, GLenum target, GLenum pname, GLint *params )
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_parameterIiv_EXT called.");
		
		return tex_parameterIiv_EXT_reenter(ctx, target, pname, *params);
	}
	
	static void tex_parameterIuiv_EXT_replacement(GLIContext ctx, GLenum target, GLenum pname, GLuint *params )
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_parameterIuiv_EXT called.");
		
		return tex_parameterIuiv_EXT_reenter(ctx, target, pname, *params);
	}
	
	static void get_tex_parameterIiv_EXT_replacement((GLIContext ctx, GLenum target, GLenum pname, GLint *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_tex_parameterIiv_EXT called.");
		
		return get_tex_parameterIiv_EXT_reenter(ctx, target, pname, *params);
	}
	
	static void get_tex_parameterIuiv_EXT_replacement((GLIContext ctx, GLenum target, GLenum pname, GLuint *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_tex_parameterIuiv_EXT called.");
		
		return get_tex_parameterIuiv_EXT_reenter(ctx, target, pname, *params);
	}
	
	static void vertex_attribI1i_EXT_replacement(GLIContext ctx, GLuint index, GLint x)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attribI1i_EXT called.");
		
		return vertex_attribI1i_EXT_reenter(ctx, index, x);
	}
	
	static void vertex_attribI2i_EXT_replacement(GLIContext ctx, GLuint index, GLint x, GLint y)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attribI2i_EXT called.");
		
		return vertex_attribI2i_EXT_reenter(ctx, index, x, y);
	}
	
	static void vertex_attribI3i_EXT_replacement(GLIContext ctx, GLuint index, GLint x, GLint y, GLint z)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attribI3i_EXT called.");
		
		return vertex_attribI3i_EXT_reenter(ctx, index, x, y, z);
	}
	
	static void vertex_attribI4i_EXT_replacement(GLIContext ctx, GLuint index, GLint x, GLint y, GLint z, GLint w)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attribI4i_EXT called.");
		
		return vertex_attribI4i_EXT_reenter(ctx, index, x, y, z, w);
	}
	
	static void vertex_attribI1ui_EXT_replacement(GLIContext ctx, GLuint index, GLuint x)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attribI1ui_EXT called.");
		
		return vertex_attribI1ui_EXT_reenter(ctx, index, x);
	}
	
	static void vertex_attribI2ui_EXT_replacement(GLIContext ctx, GLuint index, GLuint x, GLuint y)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attribI2ui_EXT called.");
		
		return vertex_attribI2ui_EXT_reenter(ctx, index, x, y);
	}
	
	static void vertex_attribI3ui_EXT_replacement(GLIContext ctx, GLuint index, GLuint x, GLuint y, GLuint z)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attribI3ui_EXT called.");
		
		return vertex_attribI3ui_EXT_reenter(ctx, index, x, y, z);
	}
	
	static void vertex_attribI4ui_EXT_replacement(GLIContext ctx, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attribI4ui_EXT called.");
		
		return vertex_attribI4ui_EXT_reenter(ctx, index, x, y, z, w);
	}
	
	static void vertex_attribI1iv_EXT_replacement(GLIContext ctx, GLuint index, const GLint *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attribI1iv_EXT called.");
		
		return vertex_attribI1iv_EXT_reenter(ctx, index, GLint);
	}
	
	static void vertex_attribI2iv_EXT_replacement(GLIContext ctx, GLuint index, const GLint *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attribI2iv_EXT called.");
		
		return vertex_attribI2iv_EXT_reenter(ctx, index, GLint);
	}
	
	static void vertex_attribI3iv_EXT_replacement(GLIContext ctx, GLuint index, const GLint *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attribI3iv_EXT called.");
		
		return vertex_attribI3iv_EXT_reenter(ctx, index, GLint);
	}
	
	static void vertex_attribI4iv_EXT_replacement(GLIContext ctx, GLuint index, const GLint *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attribI4iv_EXT called.");
		
		return vertex_attribI4iv_EXT_reenter(ctx, index, GLint);
	}
	
	static void vertex_attribI1uiv_EXT_replacement(GLIContext ctx, GLuint index, const GLuint *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attribI1uiv_EXT called.");
		
		return vertex_attribI1uiv_EXT_reenter(ctx, index, GLuint);
	}
	
	static void vertex_attribI2uiv_EXT_replacement(GLIContext ctx, GLuint index, const GLuint *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attribI2uiv_EXT called.");
		
		return vertex_attribI2uiv_EXT_reenter(ctx, index, GLuint);
	}
	
	static void vertex_attribI3uiv_EXT_replacement(GLIContext ctx, GLuint index, const GLuint *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attribI3uiv_EXT called.");
		
		return vertex_attribI3uiv_EXT_reenter(ctx, index, GLuint);
	}
	
	static void vertex_attribI4uiv_EXT_replacement(GLIContext ctx, GLuint index, const GLuint *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attribI4uiv_EXT called.");
		
		return vertex_attribI4uiv_EXT_reenter(ctx, index, GLuint);
	}
	
	static void vertex_attribI4bv_EXT_replacement(GLIContext ctx, GLuint index, const GLbyte *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attribI4bv_EXT called.");
		
		return vertex_attribI4bv_EXT_reenter(ctx, index, GLbyte);
	}
	
	static void vertex_attribI4sv_EXT_replacement(GLIContext ctx, GLuint index, const GLshort *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attribI4sv_EXT called.");
		
		return vertex_attribI4sv_EXT_reenter(ctx, index, GLshort);
	}
	
	static void vertex_attribI4ubv_EXT_replacement(GLIContext ctx, GLuint index, const GLubyte *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attribI4ubv_EXT called.");
		
		return vertex_attribI4ubv_EXT_reenter(ctx, index, GLubyte);
	}
	
	static void vertex_attribI4usv_EXT_replacement(GLIContext ctx, GLuint index, const GLushort *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attribI4usv_EXT called.");
		
		return vertex_attribI4usv_EXT_reenter(ctx, index, GLushort);
	}
	
	static void vertex_attribI_pointer_EXT_replacement(GLIContext ctx, GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attribI_pointer_EXT called.");
		
		return vertex_attribI_pointer_EXT_reenter(ctx, index, size, type, stride, GLvoid);
	}
	
	static void get_vertex_attribIiv_EXT_replacement(GLIContext ctx, GLuint index, GLenum pname, GLint *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_vertex_attribIiv_EXT called.");
		
		return get_vertex_attribIiv_EXT_reenter(ctx, index, pname, *params);
	}
	
	static void get_vertex_attribIuiv_EXT_replacement(GLIContext ctx, GLuint index, GLenum pname, GLuint *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_vertex_attribIuiv_EXT called.");
		
		return get_vertex_attribIuiv_EXT_reenter(ctx, index, pname, *params);
	}
	
	static void uniform1ui_EXT_replacement(GLIContext ctx, GLint location, GLuint v0)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: uniform1ui_EXT called.");
		
		return uniform1ui_EXT_reenter(ctx, location, v0);
	}
	
	static void uniform2ui_EXT_replacement(GLIContext ctx, GLint location, GLuint v0, GLuint v1)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: uniform2ui_EXT called.");
		
		return uniform2ui_EXT_reenter(ctx, location, v0, v1);
	}
	
	static void uniform3ui_EXT_replacement(GLIContext ctx, GLint location, GLuint v0, GLuint v1, GLuint v2)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: uniform3ui_EXT called.");
		
		return uniform3ui_EXT_reenter(ctx, location, v0, v1, v2);
	}
	
	static void uniform4ui_EXT_replacement(GLIContext ctx, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: uniform4ui_EXT called.");
		
		return uniform4ui_EXT_reenter(ctx, location, v0, v1, v2, v3);
	}
	
	static void uniform1uiv_EXT_replacement(GLIContext ctx, GLint location, GLsizei count, const GLuint *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: uniform1uiv_EXT called.");
		
		return uniform1uiv_EXT_reenter(ctx, location, count, GLuint);
	}
	
	static void uniform2uiv_EXT_replacement(GLIContext ctx, GLint location, GLsizei count, const GLuint *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: uniform2uiv_EXT called.");
		
		return uniform2uiv_EXT_reenter(ctx, location, count, GLuint);
	}
	
	static void uniform3uiv_EXT_replacement(GLIContext ctx, GLint location, GLsizei count, const GLuint *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: uniform3uiv_EXT called.");
		
		return uniform3uiv_EXT_reenter(ctx, location, count, GLuint);
	}
	
	static void uniform4uiv_EXT_replacement(GLIContext ctx, GLint location, GLsizei count, const GLuint *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: uniform4uiv_EXT called.");
		
		return uniform4uiv_EXT_reenter(ctx, location, count, GLuint);
	}
	
	static void get_uniformuiv_EXT_replacement(GLIContext ctx, GLuint program, GLint location, GLuint *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_uniformuiv_EXT called.");
		
		return get_uniformuiv_EXT_reenter(ctx, program, location, *params);
	}
	
	static void bind_frag_data_location_EXT_replacement(GLIContext ctx, GLuint program, GLuint colorNumber, const GLchar *name)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: bind_frag_data_location_EXT called.");
		
		return bind_frag_data_location_EXT_reenter(ctx, program, colorNumber, GLchar);
	}
	
	static GLint get_frag_data_location_EXT_replacement(GLIContext ctx, GLuint program, const GLchar *name)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_frag_data_location_EXT called.");
		
		return get_frag_data_location_EXT_reenter(ctx, program, GLchar);
	}
	
	static void color_mask_indexed_EXT_replacement((GLIContext ctx, GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: color_mask_indexed_EXT called.");
		
		return color_mask_indexed_EXT_reenter(ctx, index, r, g, b, a);
	}
	
	static void enable_indexed_EXT_replacement((GLIContext ctx, GLenum target, GLuint index)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: enable_indexed_EXT called.");
		
		return enable_indexed_EXT_reenter(ctx, target, index);
	}
	
	static void disable_indexed_EXT_replacement((GLIContext ctx, GLenum target, GLuint index)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: disable_indexed_EXT called.");
		
		return disable_indexed_EXT_reenter(ctx, target, index);
	}
	
	static GLboolean is_enabled_indexed_EXT_replacement((GLIContext ctx, GLenum target, GLuint index)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: is_enabled_indexed_EXT called.");
		
		return is_enabled_indexed_EXT_reenter(ctx, target, index);
	}
	
	static void uniform_matrix2x3fv_replacement((GLIContext ctx, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: uniform_matrix2x3fv called.");
		
		return uniform_matrix2x3fv_reenter(ctx, location, count, transpose, GLfloat);
	}
	
	static void uniform_matrix3x2fv_replacement((GLIContext ctx, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: uniform_matrix3x2fv called.");
		
		return uniform_matrix3x2fv_reenter(ctx, location, count, transpose, GLfloat);
	}
	
	static void uniform_matrix2x4fv_replacement((GLIContext ctx, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: uniform_matrix2x4fv called.");
		
		return uniform_matrix2x4fv_reenter(ctx, location, count, transpose, GLfloat);
	}
	
	static void uniform_matrix4x2fv_replacement((GLIContext ctx, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: uniform_matrix4x2fv called.");
		
		return uniform_matrix4x2fv_reenter(ctx, location, count, transpose, GLfloat);
	}
	
	static void uniform_matrix3x4fv_replacement((GLIContext ctx, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: uniform_matrix3x4fv called.");
		
		return uniform_matrix3x4fv_reenter(ctx, location, count, transpose, GLfloat);
	}
	
	static void uniform_matrix4x3fv_replacement((GLIContext ctx, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: uniform_matrix4x3fv called.");
		
		return uniform_matrix4x3fv_reenter(ctx, location, count, transpose, GLfloat);
	}
	
	static void blit_framebuffer_EXT_replacement((GLIContext ctx, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: blit_framebuffer_EXT called.");
		
		return blit_framebuffer_EXT_reenter(ctx, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
	}
	
	static void renderbuffer_storage_multisample_EXT_replacement((GLIContext ctx, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: renderbuffer_storage_multisample_EXT called.");
		
		return renderbuffer_storage_multisample_EXT_reenter(ctx, target, samples, internalformat, width, height);
	}
	
	static void begin_conditional_render_NV_replacement(GLIContext ctx, GLuint id, GLenum mode)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: begin_conditional_render_NV called.");
		
		return begin_conditional_render_NV_reenter(ctx, id, mode);
	}
	
	static void end_conditional_render_NV_replacement(GLIContext ctx)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: end_conditional_render_NV called.");
		
		return end_conditional_render_NV_reenter(ctx);
	}
	
	static void get_attached_shaders_replacement((GLIContext ctx, GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_attached_shaders called.");
		
		return get_attached_shaders_reenter(ctx, program, maxCount, *count, *shaders);
	}
	
	static void provoking_vertex_EXT_replacement((GLIContext ctx, GLenum mode)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: provoking_vertex_EXT called.");
		
		return provoking_vertex_EXT_reenter(ctx, mode);
	}
	
	static void vertex_attrib_divisor_replacement((GLIContext ctx, GLuint index, GLuint divisor)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attrib_divisor called.");
		
		return vertex_attrib_divisor_reenter(ctx, index, divisor);
	}
	
	static void draw_arrays_instanced_replacement(GLIContext ctx, GLenum mode, GLint first, GLsizei count, GLsizei instancecount)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: draw_arrays_instanced called.");
		
		return draw_arrays_instanced_reenter(ctx, mode, first, count, instancecount);
	}
	
	static void draw_elements_instanced_replacement(GLIContext ctx, GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLsizei instancecount)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: draw_elements_instanced called.");
		
		return draw_elements_instanced_reenter(ctx, mode, count, type, GLvoid GLsizei);
	}
	
	static void draw_elements_base_vertex_replacement(GLIContext ctx, GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLint base_vertex)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: draw_elements_base_vertex called.");
		
		return draw_elements_base_vertex_reenter(ctx, mode, count, type, GLvoid GLint);
	}
	
	static void draw_range_elements_base_vertex_replacement(GLIContext ctx, GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices, GLint base_vertex)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: draw_range_elements_base_vertex called.");
		
		return draw_range_elements_base_vertex_reenter(ctx, mode, start, end, count, type, GLvoid GLint);
	}
	
	static void draw_elements_instanced_base_vertex_replacement(GLIContext ctx, GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLsizei instancecount, GLint base_vertex)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: draw_elements_instanced_base_vertex called.");
		
		return draw_elements_instanced_base_vertex_reenter(ctx, mode, count, type, GLvoid GLsizei GLint);
	}
	
	static void multi_draw_elements_base_vertex_replacement(GLIContext ctx, GLenum mode, const GLsizei *count, GLenum type, const GLvoid* const *indices, GLsizei drawcount, const GLint *base_vertex)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: multi_draw_elements_base_vertex called.");
		
		return multi_draw_elements_base_vertex_reenter(ctx, mode, GLsizei GLenum const const GLsizei const *base_vertex);
	}
	
	static void bind_vertex_array_ARB_replacement(GLIContext ctx, GLuint array)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: bind_vertex_array_ARB called.");
		
		return bind_vertex_array_ARB_reenter(ctx, array);
	}
	
	static void delete_vertex_arrays_ARB_replacement(GLIContext ctx, GLsizei n, const GLuint *arrays)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: delete_vertex_arrays_ARB called.");
		
		return delete_vertex_arrays_ARB_reenter(ctx, n, GLuint);
	}
	
	static void gen_vertex_arrays_ARB_replacement(GLIContext ctx, GLsizei n, GLuint *arrays)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: gen_vertex_arrays_ARB called.");
		
		return gen_vertex_arrays_ARB_reenter(ctx, n, *arrays);
	}
	
	static GLboolean is_vertex_array_ARB_replacement(GLIContext ctx, GLuint array)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: is_vertex_array_ARB called.");
		
		return is_vertex_array_ARB_reenter(ctx, array);
	}
	
	static void point_size_pointer_replacement((GLIContext ctx, GLenum type, GLsizei stride, const GLvoid *pointer)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: point_size_pointer called.");
		
		return point_size_pointer_reenter(ctx, type, stride, GLvoid);
	}
	
	static void vertex_point_sizef_APPLE_replacement((GLIContext ctx, GLfloat size)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_point_sizef_APPLE called.");
		
		return vertex_point_sizef_APPLE_reenter(ctx, size);
	}
	
	static void clear_bufferiv_replacement(GLIContext ctx, GLenum buffer, GLint drawbuffer, const GLint *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: clear_bufferiv called.");
		
		return clear_bufferiv_reenter(ctx, buffer, drawbuffer, GLint);
	}
	
	static void clear_bufferuiv_replacement(GLIContext ctx, GLenum buffer, GLint drawbuffer, const GLuint *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: clear_bufferuiv called.");
		
		return clear_bufferuiv_reenter(ctx, buffer, drawbuffer, GLuint);
	}
	
	static void clear_bufferfv_replacement(GLIContext ctx, GLenum buffer, GLint drawbuffer, const GLfloat *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: clear_bufferfv called.");
		
		return clear_bufferfv_reenter(ctx, buffer, drawbuffer, GLfloat);
	}
	
	static void clear_bufferfi_replacement(GLIContext ctx, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: clear_bufferfi called.");
		
		return clear_bufferfi_reenter(ctx, buffer, drawbuffer, depth, stencil);
	}
	
	static GLsync fence_sync_replacement((GLIContext ctx, GLenum condition, GLbitfield flags)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: fence_sync called.");
		
		return fence_sync_reenter(ctx, condition, flags);
	}
	
	static GLboolean is_sync_replacement((GLIContext ctx, GLsync sync)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: is_sync called.");
		
		return is_sync_reenter(ctx, sync);
	}
	
	static void delete_sync_replacement((GLIContext ctx, GLsync sync)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: delete_sync called.");
		
		return delete_sync_reenter(ctx, sync);
	}
	
	static GLenum client_wait_sync_replacement((GLIContext ctx, GLsync sync, GLbitfield flags, GLuint64 timeout)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: client_wait_sync called.");
		
		return client_wait_sync_reenter(ctx, sync, flags, timeout);
	}
	
	static void wait_sync_replacement((GLIContext ctx, GLsync sync, GLbitfield flags, GLuint64 timeout)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: wait_sync called.");
		
		return wait_sync_reenter(ctx, sync, flags, timeout);
	}
	
	static void get_integer64v_sync_replacement((GLIContext ctx, GLenum pname, GLint64 *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_integer64v_sync called.");
		
		return get_integer64v_sync_reenter(ctx, pname, *params);
	}
	
	static void get_synciv_replacement((GLIContext ctx, GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_synciv called.");
		
		return get_synciv_reenter(ctx, sync, pname, bufSize, *length, *values);
	}
	
	static void tex_image2D_multisample_replacement(GLIContext ctx, GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_image2D_multisample called.");
		
		return tex_image2D_multisample_reenter(ctx, target, samples, internalformat, width, height, fixedsamplelocations);
	}
	
	static void tex_image3D_multisample_replacement(GLIContext ctx, GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_image3D_multisample called.");
		
		return tex_image3D_multisample_reenter(ctx, target, samples, internalformat, width, height, depth, fixedsamplelocations);
	}
	
	static void get_multisamplefv_replacement(GLIContext ctx, GLenum pname, GLuint index, GLfloat *val)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_multisamplefv called.");
		
		return get_multisamplefv_reenter(ctx, pname, index, *val);
	}
	
	static void sample_maski_replacement(GLIContext ctx, GLuint index, GLbitfield mask)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: sample_maski called.");
		
		return sample_maski_reenter(ctx, index, mask);
	}
	
	static void tex_buffer_replacement(GLIContext ctx, GLenum target, GLenum internalformat, GLuint buffer)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_buffer called.");
		
		return tex_buffer_reenter(ctx, target, internalformat, buffer);
	}
	
	static void copy_buffer_sub_data_replacement(GLIContext ctx, GLenum readtarget, GLenum writetarget, GLintptr readoffset, GLintptr writeoffset, GLsizeiptr size)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: copy_buffer_sub_data called.");
		
		return copy_buffer_sub_data_reenter(ctx, readtarget, writetarget, readoffset, writeoffset, size);
	}
	
	static void primitive_restart_index_replacement(GLIContext ctx, GLuint index)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: primitive_restart_index called.");
		
		return primitive_restart_index_reenter(ctx, index);
	}
	
	static void get_query_objecti64v_replacement((GLIContext ctx, GLuint id, GLenum pname, GLint64EXT *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_query_objecti64v called.");
		
		return get_query_objecti64v_reenter(ctx, id, pname, *params);
	}
	
	static void get_query_objectui64v_replacement((GLIContext ctx, GLuint id, GLenum pname, GLuint64EXT *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_query_objectui64v called.");
		
		return get_query_objectui64v_reenter(ctx, id, pname, *params);
	}
	
	static GLvoid *map_buffer_range_replacement((GLIContext ctx, GLenum target, GLintptr offset, GLsizeiptr length, GLenum access)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: *map_buffer_range called.");
		
		return *map_buffer_range_reenter(ctx, target, offset, length, access);
	}
	
	static void flush_mapped_buffer_range_replacement((GLIContext ctx, GLenum target, GLintptr offset, GLsizeiptr length)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: flush_mapped_buffer_range called.");
		
		return flush_mapped_buffer_range_reenter(ctx, target, offset, length);
	}
	
	static void query_counter_replacement((GLIContext ctx, GLuint id, GLenum target)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: query_counter called.");
		
		return query_counter_reenter(ctx, id, target);
	}
	
	static void get_integer64i_v_replacement((GLIContext ctx, GLenum target, GLuint index, GLint64 *data)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_integer64i_v called.");
		
		return get_integer64i_v_reenter(ctx, target, index, *data);
	}
	
	static void get_buffer_parameteri64v_replacement(GLIContext ctx, GLenum target, GLenum pname, GLint64 *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_buffer_parameteri64v called.");
		
		return get_buffer_parameteri64v_reenter(ctx, target, pname, *params);
	}
	
	static void gen_samplers_replacement((GLIContext ctx, GLsizei count, GLuint *samplers)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: gen_samplers called.");
		
		return gen_samplers_reenter(ctx, count, *samplers);
	}
	
	static void delete_samplers_replacement((GLIContext ctx, GLsizei count, const GLuint *samplers)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: delete_samplers called.");
		
		return delete_samplers_reenter(ctx, count, GLuint);
	}
	
	static GLboolean is_sampler_replacement((GLIContext ctx, GLuint sampler)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: is_sampler called.");
		
		return is_sampler_reenter(ctx, sampler);
	}
	
	static void bind_sampler_replacement((GLIContext ctx, GLuint unit, GLuint sampler)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: bind_sampler called.");
		
		return bind_sampler_reenter(ctx, unit, sampler);
	}
	
	static void sampler_parameteri_replacement((GLIContext ctx, GLuint sampler, GLenum pname, GLint param)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: sampler_parameteri called.");
		
		return sampler_parameteri_reenter(ctx, sampler, pname, param);
	}
	
	static void sampler_parameteriv_replacement((GLIContext ctx, GLuint sampler, GLenum pname, const GLint *param)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: sampler_parameteriv called.");
		
		return sampler_parameteriv_reenter(ctx, sampler, pname, GLint);
	}
	
	static void sampler_parameterf_replacement((GLIContext ctx, GLuint sampler, GLenum pname, GLfloat param)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: sampler_parameterf called.");
		
		return sampler_parameterf_reenter(ctx, sampler, pname, param);
	}
	
	static void sampler_parameterfv_replacement((GLIContext ctx, GLuint sampler, GLenum pname, const GLfloat *param)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: sampler_parameterfv called.");
		
		return sampler_parameterfv_reenter(ctx, sampler, pname, GLfloat);
	}
	
	static void sampler_parameterIiv_replacement((GLIContext ctx, GLuint sampler, GLenum pname, const GLint *param)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: sampler_parameterIiv called.");
		
		return sampler_parameterIiv_reenter(ctx, sampler, pname, GLint);
	}
	
	static void sampler_parameterIuiv_replacement((GLIContext ctx, GLuint sampler, GLenum pname, const GLuint *param)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: sampler_parameterIuiv called.");
		
		return sampler_parameterIuiv_reenter(ctx, sampler, pname, GLuint);
	}
	
	static void get_sampler_parameteriv_replacement((GLIContext ctx, GLuint sampler, GLenum pname, GLint *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_sampler_parameteriv called.");
		
		return get_sampler_parameteriv_reenter(ctx, sampler, pname, *params);
	}
	
	static void get_sampler_parameterfv_replacement((GLIContext ctx, GLuint sampler, GLenum pname, GLfloat *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_sampler_parameterfv called.");
		
		return get_sampler_parameterfv_reenter(ctx, sampler, pname, *params);
	}
	
	static void get_sampler_parameterIiv_replacement((GLIContext ctx, GLuint sampler, GLenum pname, GLint *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_sampler_parameterIiv called.");
		
		return get_sampler_parameterIiv_reenter(ctx, sampler, pname, *params);
	}
	
	static void get_sampler_parameterIuiv_replacement((GLIContext ctx, GLuint sampler, GLenum pname, GLuint *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_sampler_parameterIuiv called.");
		
		return get_sampler_parameterIuiv_reenter(ctx, sampler, pname, *params);
	}
	
	static void label_object_EXT_replacement(GLIContext ctx, GLenum type, GLuint object, GLsizei length, const GLchar *label)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: label_object_EXT called.");
		
		return label_object_EXT_reenter(ctx, type, object, length, GLchar);
	}
	
	static void get_object_label_EXT_replacement(GLIContext ctx, GLenum type, GLuint object, GLsizei bufSize, GLsizei *length, GLchar *label)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_object_label_EXT called.");
		
		return get_object_label_EXT_reenter(ctx, type, object, bufSize, *length, *label);
	}
	
	static void insert_event_marker_EXT_replacement(GLIContext ctx, GLsizei length, const GLchar *marker)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: insert_event_marker_EXT called.");
		
		return insert_event_marker_EXT_reenter(ctx, length, GLchar);
	}
	
	static void push_group_marker_EXT_replacement(GLIContext ctx, GLsizei length, const GLchar *marker)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: push_group_marker_EXT called.");
		
		return push_group_marker_EXT_reenter(ctx, length, GLchar);
	}
	
	static void pop_group_marker_EXT_replacement(GLIContext ctx)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: pop_group_marker_EXT called.");
		
		return pop_group_marker_EXT_reenter(ctx);
	}
	
	static void use_program_stages_replacement(GLIContext ctx, GLuint pipeline, GLbitfield stages, GLuint program)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: use_program_stages called.");
		
		return use_program_stages_reenter(ctx, pipeline, stages, program);
	}
	
	static void active_shader_program_replacement(GLIContext ctx, GLuint pipeline, GLuint program)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: active_shader_program called.");
		
		return active_shader_program_reenter(ctx, pipeline, program);
	}
	
	static GLuint create_shader_programv_replacement(GLIContext ctx, GLenum type, GLsizei count, const GLchar* const *strings)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: create_shader_programv called.");
		
		return create_shader_programv_reenter(ctx, type, count, GLchar* *strings);
	}
	
	static void bind_program_pipeline_replacement(GLIContext ctx, GLuint pipeline)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: bind_program_pipeline called.");
		
		return bind_program_pipeline_reenter(ctx, pipeline);
	}
	
	static void delete_program_pipelines_replacement(GLIContext ctx, GLsizei n, const GLuint *pipelines)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: delete_program_pipelines called.");
		
		return delete_program_pipelines_reenter(ctx, n, GLuint);
	}
	
	static void gen_program_pipelines_replacement(GLIContext ctx, GLsizei n, GLuint *pipelines)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: gen_program_pipelines called.");
		
		return gen_program_pipelines_reenter(ctx, n, *pipelines);
	}
	
	static GLboolean is_program_pipeline_replacement(GLIContext ctx, GLuint pipeline)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: is_program_pipeline called.");
		
		return is_program_pipeline_reenter(ctx, pipeline);
	}
	
	static void get_program_pipelineiv_replacement(GLIContext ctx, GLuint pipeline, GLenum pname, GLint *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_program_pipelineiv called.");
		
		return get_program_pipelineiv_reenter(ctx, pipeline, pname, *params);
	}
	
	static void validate_program_pipeline_replacement(GLIContext ctx, GLuint pipeline)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: validate_program_pipeline called.");
		
		return validate_program_pipeline_reenter(ctx, pipeline);
	}
	
	static void get_program_pipeline_info_log_replacement(GLIContext ctx, GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_program_pipeline_info_log called.");
		
		return get_program_pipeline_info_log_reenter(ctx, pipeline, bufSize, *length, *infoLog);
	}
	
	static void program_uniform1i_replacement(GLIContext ctx, GLuint program, GLint location, GLint x)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_uniform1i called.");
		
		return program_uniform1i_reenter(ctx, program, location, x);
	}
	
	static void program_uniform2i_replacement(GLIContext ctx, GLuint program, GLint location, GLint x, GLint y)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_uniform2i called.");
		
		return program_uniform2i_reenter(ctx, program, location, x, y);
	}
	
	static void program_uniform3i_replacement(GLIContext ctx, GLuint program, GLint location, GLint x, GLint y, GLint z)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_uniform3i called.");
		
		return program_uniform3i_reenter(ctx, program, location, x, y, z);
	}
	
	static void program_uniform4i_replacement(GLIContext ctx, GLuint program, GLint location, GLint x, GLint y, GLint z, GLint w)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_uniform4i called.");
		
		return program_uniform4i_reenter(ctx, program, location, x, y, z, w);
	}
	
	static void program_uniform1f_replacement(GLIContext ctx, GLuint program, GLint location, GLfloat x)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_uniform1f called.");
		
		return program_uniform1f_reenter(ctx, program, location, x);
	}
	
	static void program_uniform2f_replacement(GLIContext ctx, GLuint program, GLint location, GLfloat x, GLfloat y)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_uniform2f called.");
		
		return program_uniform2f_reenter(ctx, program, location, x, y);
	}
	
	static void program_uniform3f_replacement(GLIContext ctx, GLuint program, GLint location, GLfloat x, GLfloat y, GLfloat z)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_uniform3f called.");
		
		return program_uniform3f_reenter(ctx, program, location, x, y, z);
	}
	
	static void program_uniform4f_replacement(GLIContext ctx, GLuint program, GLint location, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_uniform4f called.");
		
		return program_uniform4f_reenter(ctx, program, location, x, y, z, w);
	}
	
	static void program_uniform1iv_replacement(GLIContext ctx, GLuint program, GLint location, GLsizei count, const GLint *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_uniform1iv called.");
		
		return program_uniform1iv_reenter(ctx, program, location, count, GLint);
	}
	
	static void program_uniform2iv_replacement(GLIContext ctx, GLuint program, GLint location, GLsizei count, const GLint *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_uniform2iv called.");
		
		return program_uniform2iv_reenter(ctx, program, location, count, GLint);
	}
	
	static void program_uniform3iv_replacement(GLIContext ctx, GLuint program, GLint location, GLsizei count, const GLint *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_uniform3iv called.");
		
		return program_uniform3iv_reenter(ctx, program, location, count, GLint);
	}
	
	static void program_uniform4iv_replacement(GLIContext ctx, GLuint program, GLint location, GLsizei count, const GLint *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_uniform4iv called.");
		
		return program_uniform4iv_reenter(ctx, program, location, count, GLint);
	}
	
	static void program_uniform1fv_replacement(GLIContext ctx, GLuint program, GLint location, GLsizei count, const GLfloat *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_uniform1fv called.");
		
		return program_uniform1fv_reenter(ctx, program, location, count, GLfloat);
	}
	
	static void program_uniform2fv_replacement(GLIContext ctx, GLuint program, GLint location, GLsizei count, const GLfloat *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_uniform2fv called.");
		
		return program_uniform2fv_reenter(ctx, program, location, count, GLfloat);
	}
	
	static void program_uniform3fv_replacement(GLIContext ctx, GLuint program, GLint location, GLsizei count, const GLfloat *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_uniform3fv called.");
		
		return program_uniform3fv_reenter(ctx, program, location, count, GLfloat);
	}
	
	static void program_uniform4fv_replacement(GLIContext ctx, GLuint program, GLint location, GLsizei count, const GLfloat *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_uniform4fv called.");
		
		return program_uniform4fv_reenter(ctx, program, location, count, GLfloat);
	}
	
	static void program_uniform_matrix2fv_replacement(GLIContext ctx, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_uniform_matrix2fv called.");
		
		return program_uniform_matrix2fv_reenter(ctx, program, location, count, transpose, GLfloat);
	}
	
	static void program_uniform_matrix3fv_replacement(GLIContext ctx, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_uniform_matrix3fv called.");
		
		return program_uniform_matrix3fv_reenter(ctx, program, location, count, transpose, GLfloat);
	}
	
	static void program_uniform_matrix4fv_replacement(GLIContext ctx, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_uniform_matrix4fv called.");
		
		return program_uniform_matrix4fv_reenter(ctx, program, location, count, transpose, GLfloat);
	}
	
	static void program_uniform1ui_replacement(GLIContext ctx, GLuint program, GLint location, GLuint x)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_uniform1ui called.");
		
		return program_uniform1ui_reenter(ctx, program, location, x);
	}
	
	static void program_uniform2ui_replacement(GLIContext ctx, GLuint program, GLint location, GLuint x, GLuint y)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_uniform2ui called.");
		
		return program_uniform2ui_reenter(ctx, program, location, x, y);
	}
	
	static void program_uniform3ui_replacement(GLIContext ctx, GLuint program, GLint location, GLuint x, GLuint y, GLuint z)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_uniform3ui called.");
		
		return program_uniform3ui_reenter(ctx, program, location, x, y, z);
	}
	
	static void program_uniform4ui_replacement(GLIContext ctx, GLuint program, GLint location, GLuint x, GLuint y, GLuint z, GLuint w)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_uniform4ui called.");
		
		return program_uniform4ui_reenter(ctx, program, location, x, y, z, w);
	}
	
	static void program_uniform1uiv_replacement(GLIContext ctx, GLuint program, GLint location, GLsizei count, const GLuint *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_uniform1uiv called.");
		
		return program_uniform1uiv_reenter(ctx, program, location, count, GLuint);
	}
	
	static void program_uniform2uiv_replacement(GLIContext ctx, GLuint program, GLint location, GLsizei count, const GLuint *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_uniform2uiv called.");
		
		return program_uniform2uiv_reenter(ctx, program, location, count, GLuint);
	}
	
	static void program_uniform3uiv_replacement(GLIContext ctx, GLuint program, GLint location, GLsizei count, const GLuint *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_uniform3uiv called.");
		
		return program_uniform3uiv_reenter(ctx, program, location, count, GLuint);
	}
	
	static void program_uniform4uiv_replacement(GLIContext ctx, GLuint program, GLint location, GLsizei count, const GLuint *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_uniform4uiv called.");
		
		return program_uniform4uiv_reenter(ctx, program, location, count, GLuint);
	}
	
	static void program_uniform_matrix2x3fv_replacement(GLIContext ctx, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_uniform_matrix2x3fv called.");
		
		return program_uniform_matrix2x3fv_reenter(ctx, program, location, count, transpose, GLfloat);
	}
	
	static void program_uniform_matrix3x2fv_replacement(GLIContext ctx, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_uniform_matrix3x2fv called.");
		
		return program_uniform_matrix3x2fv_reenter(ctx, program, location, count, transpose, GLfloat);
	}
	
	static void program_uniform_matrix2x4fv_replacement(GLIContext ctx, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_uniform_matrix2x4fv called.");
		
		return program_uniform_matrix2x4fv_reenter(ctx, program, location, count, transpose, GLfloat);
	}
	
	static void program_uniform_matrix4x2fv_replacement(GLIContext ctx, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_uniform_matrix4x2fv called.");
		
		return program_uniform_matrix4x2fv_reenter(ctx, program, location, count, transpose, GLfloat);
	}
	
	static void program_uniform_matrix3x4fv_replacement(GLIContext ctx, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_uniform_matrix3x4fv called.");
		
		return program_uniform_matrix3x4fv_reenter(ctx, program, location, count, transpose, GLfloat);
	}
	
	static void program_uniform_matrix4x3fv_replacement(GLIContext ctx, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_uniform_matrix4x3fv called.");
		
		return program_uniform_matrix4x3fv_reenter(ctx, program, location, count, transpose, GLfloat);
	}
	
	static void bind_frag_data_location_indexed_replacement((GLIContext ctx, GLuint program, GLuint colorNumber, GLuint index, const GLchar *name)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: bind_frag_data_location_indexed called.");
		
		return bind_frag_data_location_indexed_reenter(ctx, program, colorNumber, index, GLchar);
	}
	
	static GLint get_frag_data_index_replacement((GLIContext ctx, GLuint program, const GLchar *name)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_frag_data_index called.");
		
		return get_frag_data_index_reenter(ctx, program, GLchar);
	}
	
	static void blend_func_i_replacement((GLIContext ctx, GLuint buf, GLenum src, GLenum dst)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: blend_func_i called.");
		
		return blend_func_i_reenter(ctx, buf, src, dst);
	}
	
	static void blend_func_separate_i_replacement((GLIContext ctx, GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: blend_func_separate_i called.");
		
		return blend_func_separate_i_reenter(ctx, buf, srcRGB, dstRGB, srcAlpha, dstAlpha);
	}
	
	static void blend_equation_i_replacement((GLIContext ctx, GLuint buf, GLenum mode)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: blend_equation_i called.");
		
		return blend_equation_i_reenter(ctx, buf, mode);
	}
	
	static void blend_equation_separate_i_replacement((GLIContext ctx, GLuint buf, GLenum modeRGB, GLenum modeAlpha)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: blend_equation_separate_i called.");
		
		return blend_equation_separate_i_reenter(ctx, buf, modeRGB, modeAlpha);
	}
	
	static void named_string_ARB_replacement((GLIContext ctx, GLenum type, GLint namelen, const GLchar *name, GLint stringlen, const GLchar *string)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: named_string_ARB called.");
		
		return named_string_ARB_reenter(ctx, type, namelen, GLchar GLint const *string);
	}
	
	static void delete_named_string_ARB_replacement((GLIContext ctx, GLint namelen, const GLchar *name)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: delete_named_string_ARB called.");
		
		return delete_named_string_ARB_reenter(ctx, namelen, GLchar);
	}
	
	static void compile_shader_include_ARB_replacement((GLIContext ctx, GLuint shader, GLsizei count, const GLchar* const *path, const GLint *length)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: compile_shader_include_ARB called.");
		
		return compile_shader_include_ARB_reenter(ctx, shader, count, GLchar* *path, GLint);
	}
	
	static GLboolean is_named_string_ARB_replacement((GLIContext ctx, GLint namelen, const GLchar *name)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: is_named_string_ARB called.");
		
		return is_named_string_ARB_reenter(ctx, namelen, GLchar);
	}
	
	static void get_named_string_ARB_replacement((GLIContext ctx, GLint namelen, const GLchar *name, GLsizei bufSize, GLint *stringlen, GLchar *string)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_named_string_ARB called.");
		
		return get_named_string_ARB_reenter(ctx, namelen, GLchar GLsizei GLint GLchar);
	}
	
	static void get_named_string_iv_ARB_replacement((GLIContext ctx, GLint namelen, const GLchar *name, GLenum pname, GLint *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_named_string_iv_ARB called.");
		
		return get_named_string_iv_ARB_reenter(ctx, namelen, GLchar GLenum GLint);
	}
	
	static void release_shader_compiler_replacement(GLIContext ctx)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: release_shader_compiler called.");
		
		return release_shader_compiler_reenter(ctx);
	}
	
	static void shader_binary_replacement(GLIContext ctx, GLint n, GLuint *shaders, GLenum binaryformat, const GLvoid *binary, GLint length)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: shader_binary called.");
		
		return shader_binary_reenter(ctx, n, *shaders, binaryformat, GLvoid GLint);
	}
	
	static void get_shader_precision_format_replacement(GLIContext ctx, GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_shader_precision_format called.");
		
		return get_shader_precision_format_reenter(ctx, shadertype, precisiontype, *range, *precision);
	}
	
	static void depth_rangef_replacement((GLIContext ctx, GLclampf zNear, GLclampf zFar)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: depth_rangef called.");
		
		return depth_rangef_reenter(ctx, zNear, zFar);
	}
	
	static void clear_depthf_replacement((GLIContext ctx, GLclampf depth)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: clear_depthf called.");
		
		return clear_depthf_reenter(ctx, depth);
	}
	
	static void vertex_attribP1ui_replacement((GLIContext ctx, GLuint index, GLenum type, GLboolean normalized, GLuint value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attribP1ui called.");
		
		return vertex_attribP1ui_reenter(ctx, index, type, normalized, value);
	}
	
	static void vertex_attribP2ui_replacement((GLIContext ctx, GLuint index, GLenum type, GLboolean normalized, GLuint value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attribP2ui called.");
		
		return vertex_attribP2ui_reenter(ctx, index, type, normalized, value);
	}
	
	static void vertex_attribP3ui_replacement((GLIContext ctx, GLuint index, GLenum type, GLboolean normalized, GLuint value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attribP3ui called.");
		
		return vertex_attribP3ui_reenter(ctx, index, type, normalized, value);
	}
	
	static void vertex_attribP4ui_replacement((GLIContext ctx, GLuint index, GLenum type, GLboolean normalized, GLuint value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attribP4ui called.");
		
		return vertex_attribP4ui_reenter(ctx, index, type, normalized, value);
	}
	
	static void vertex_attribP1uiv_replacement((GLIContext ctx, GLuint index, GLenum type, GLboolean normalized, const GLuint *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attribP1uiv called.");
		
		return vertex_attribP1uiv_reenter(ctx, index, type, normalized, GLuint);
	}
	
	static void vertex_attribP2uiv_replacement((GLIContext ctx, GLuint index, GLenum type, GLboolean normalized, const GLuint *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attribP2uiv called.");
		
		return vertex_attribP2uiv_reenter(ctx, index, type, normalized, GLuint);
	}
	
	static void vertex_attribP3uiv_replacement((GLIContext ctx, GLuint index, GLenum type, GLboolean normalized, const GLuint *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attribP3uiv called.");
		
		return vertex_attribP3uiv_reenter(ctx, index, type, normalized, GLuint);
	}
	
	static void vertex_attribP4uiv_replacement((GLIContext ctx, GLuint index, GLenum type, GLboolean normalized, const GLuint *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attribP4uiv called.");
		
		return vertex_attribP4uiv_reenter(ctx, index, type, normalized, GLuint);
	}
	
	static void get_program_binary_replacement((GLIContext ctx, GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, GLvoid *binary)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_program_binary called.");
		
		return get_program_binary_reenter(ctx, program, bufSize, *length, *binaryFormat, *binary);
	}
	
	static void program_binary_replacement((GLIContext ctx, GLuint program, GLenum binaryFormat, const GLvoid *binary, GLsizei length)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_binary called.");
		
		return program_binary_reenter(ctx, program, binaryFormat, GLvoid GLsizei);
	}
	
	static void min_sample_shading_replacement((GLIContext ctx, GLclampf value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: min_sample_shading called.");
		
		return min_sample_shading_reenter(ctx, value);
	}
	
	static void viewport_arrayv_replacement((GLIContext ctx, GLuint first, GLsizei count, const GLfloat * v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: viewport_arrayv called.");
		
		return viewport_arrayv_reenter(ctx, first, count, GLfloat v);
	}
	
	static void viewport_indexedf_replacement((GLIContext ctx, GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: viewport_indexedf called.");
		
		return viewport_indexedf_reenter(ctx, index, x, y, w, h);
	}
	
	static void viewport_indexedfv_replacement((GLIContext ctx, GLuint index, const GLfloat * v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: viewport_indexedfv called.");
		
		return viewport_indexedfv_reenter(ctx, index, GLfloat v);
	}
	
	static void scissor_arrayv_replacement((GLIContext ctx, GLuint first, GLsizei count, const GLint * v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: scissor_arrayv called.");
		
		return scissor_arrayv_reenter(ctx, first, count, GLint v);
	}
	
	static void scissor_indexed_replacement((GLIContext ctx, GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: scissor_indexed called.");
		
		return scissor_indexed_reenter(ctx, index, left, bottom, width, height);
	}
	
	static void scissor_indexedv_replacement((GLIContext ctx, GLuint index, const GLint * v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: scissor_indexedv called.");
		
		return scissor_indexedv_reenter(ctx, index, GLint v);
	}
	
	static void depth_range_arrayv_replacement((GLIContext ctx, GLuint first, GLsizei count, const GLclampd * v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: depth_range_arrayv called.");
		
		return depth_range_arrayv_reenter(ctx, first, count, GLclampd v);
	}
	
	static void depth_range_indexed_replacement((GLIContext ctx, GLuint index, GLclampd n, GLclampd f)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: depth_range_indexed called.");
		
		return depth_range_indexed_reenter(ctx, index, n, f);
	}
	
	static void get_floati_v_replacement((GLIContext ctx, GLenum target, GLuint index, GLfloat *data)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_floati_v called.");
		
		return get_floati_v_reenter(ctx, target, index, *data);
	}
	
	static void get_doublei_v_replacement((GLIContext ctx, GLenum target, GLuint index, GLdouble *data)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_doublei_v called.");
		
		return get_doublei_v_reenter(ctx, target, index, *data);
	}
	
	static void draw_arrays_indirect_replacement((GLIContext ctx, GLenum mode, const GLvoid *indirect)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: draw_arrays_indirect called.");
		
		return draw_arrays_indirect_reenter(ctx, mode, GLvoid);
	}
	
	static void draw_elements_indirect_replacement((GLIContext ctx, GLenum mode, GLenum type, const GLvoid *indirect)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: draw_elements_indirect called.");
		
		return draw_elements_indirect_reenter(ctx, mode, type, GLvoid);
	}
	
	static void patch_parameteri_replacement((GLIContext ctx, GLenum pname, GLint value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: patch_parameteri called.");
		
		return patch_parameteri_reenter(ctx, pname, value);
	}
	
	static void patch_parameterfv_replacement((GLIContext ctx, GLenum pname, const GLfloat* values)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: patch_parameterfv called.");
		
		return patch_parameterfv_reenter(ctx, pname, GLfloat*);
	}
	
	static void bind_transform_feedback_replacement((GLIContext ctx, GLenum target, GLuint name)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: bind_transform_feedback called.");
		
		return bind_transform_feedback_reenter(ctx, target, name);
	}
	
	static void gen_transform_feedbacks_replacement((GLIContext ctx, GLsizei n, GLuint* ids)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: gen_transform_feedbacks called.");
		
		return gen_transform_feedbacks_reenter(ctx, n, ids);
	}
	
	static void delete_transform_feedbacks_replacement((GLIContext ctx, GLsizei n, const GLuint* ids)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: delete_transform_feedbacks called.");
		
		return delete_transform_feedbacks_reenter(ctx, n, GLuint*);
	}
	
	static void pause_transform_feedback_replacement((GLIContext ctx)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: pause_transform_feedback called.");
		
		return pause_transform_feedback_reenter(ctx);
	}
	
	static void resume_transform_feedback_replacement((GLIContext ctx)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: resume_transform_feedback called.");
		
		return resume_transform_feedback_reenter(ctx);
	}
	
	static GLboolean is_transform_feedback_replacement((GLIContext ctx, GLuint name)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: is_transform_feedback called.");
		
		return is_transform_feedback_reenter(ctx, name);
	}
	
	static void draw_transform_feedback_replacement((GLIContext ctx, GLenum mode, GLuint name)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: draw_transform_feedback called.");
		
		return draw_transform_feedback_reenter(ctx, mode, name);
	}
	
	static void begin_query_indexed_replacement((GLIContext ctx, GLenum target, GLuint index, GLuint id)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: begin_query_indexed called.");
		
		return begin_query_indexed_reenter(ctx, target, index, id);
	}
	
	static void end_query_indexed_replacement((GLIContext ctx, GLenum target, GLuint index)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: end_query_indexed called.");
		
		return end_query_indexed_reenter(ctx, target, index);
	}
	
	static void get_query_indexediv_replacement((GLIContext ctx, GLenum target, GLuint index, GLenum pname, GLint *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_query_indexediv called.");
		
		return get_query_indexediv_reenter(ctx, target, index, pname, *params);
	}
	
	static void draw_transform_feedback_stream_replacement((GLIContext ctx, GLenum mode, GLuint name, GLuint stream)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: draw_transform_feedback_stream called.");
		
		return draw_transform_feedback_stream_reenter(ctx, mode, name, stream);
	}
	
	static void program_uniform1d_replacement(GLIContext ctx, GLuint program, GLint location, GLdouble x)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_uniform1d called.");
		
		return program_uniform1d_reenter(ctx, program, location, x);
	}
	
	static void program_uniform2d_replacement(GLIContext ctx, GLuint program, GLint location, GLdouble x, GLdouble y)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_uniform2d called.");
		
		return program_uniform2d_reenter(ctx, program, location, x, y);
	}
	
	static void program_uniform3d_replacement(GLIContext ctx, GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_uniform3d called.");
		
		return program_uniform3d_reenter(ctx, program, location, x, y, z);
	}
	
	static void program_uniform4d_replacement(GLIContext ctx, GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_uniform4d called.");
		
		return program_uniform4d_reenter(ctx, program, location, x, y, z, w);
	}
	
	static void program_uniform1dv_replacement(GLIContext ctx, GLuint program, GLint location, GLsizei count, const GLdouble *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_uniform1dv called.");
		
		return program_uniform1dv_reenter(ctx, program, location, count, GLdouble);
	}
	
	static void program_uniform2dv_replacement(GLIContext ctx, GLuint program, GLint location, GLsizei count, const GLdouble *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_uniform2dv called.");
		
		return program_uniform2dv_reenter(ctx, program, location, count, GLdouble);
	}
	
	static void program_uniform3dv_replacement(GLIContext ctx, GLuint program, GLint location, GLsizei count, const GLdouble *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_uniform3dv called.");
		
		return program_uniform3dv_reenter(ctx, program, location, count, GLdouble);
	}
	
	static void program_uniform4dv_replacement(GLIContext ctx, GLuint program, GLint location, GLsizei count, const GLdouble *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_uniform4dv called.");
		
		return program_uniform4dv_reenter(ctx, program, location, count, GLdouble);
	}
	
	static void program_uniform_matrix2dv_replacement(GLIContext ctx, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_uniform_matrix2dv called.");
		
		return program_uniform_matrix2dv_reenter(ctx, program, location, count, transpose, GLdouble);
	}
	
	static void program_uniform_matrix3dv_replacement(GLIContext ctx, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_uniform_matrix3dv called.");
		
		return program_uniform_matrix3dv_reenter(ctx, program, location, count, transpose, GLdouble);
	}
	
	static void program_uniform_matrix4dv_replacement(GLIContext ctx, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_uniform_matrix4dv called.");
		
		return program_uniform_matrix4dv_reenter(ctx, program, location, count, transpose, GLdouble);
	}
	
	static void program_uniform_matrix2x3dv_replacement(GLIContext ctx, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_uniform_matrix2x3dv called.");
		
		return program_uniform_matrix2x3dv_reenter(ctx, program, location, count, transpose, GLdouble);
	}
	
	static void program_uniform_matrix3x2dv_replacement(GLIContext ctx, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_uniform_matrix3x2dv called.");
		
		return program_uniform_matrix3x2dv_reenter(ctx, program, location, count, transpose, GLdouble);
	}
	
	static void program_uniform_matrix2x4dv_replacement(GLIContext ctx, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_uniform_matrix2x4dv called.");
		
		return program_uniform_matrix2x4dv_reenter(ctx, program, location, count, transpose, GLdouble);
	}
	
	static void program_uniform_matrix4x2dv_replacement(GLIContext ctx, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_uniform_matrix4x2dv called.");
		
		return program_uniform_matrix4x2dv_reenter(ctx, program, location, count, transpose, GLdouble);
	}
	
	static void program_uniform_matrix3x4dv_replacement(GLIContext ctx, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_uniform_matrix3x4dv called.");
		
		return program_uniform_matrix3x4dv_reenter(ctx, program, location, count, transpose, GLdouble);
	}
	
	static void program_uniform_matrix4x3dv_replacement(GLIContext ctx, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: program_uniform_matrix4x3dv called.");
		
		return program_uniform_matrix4x3dv_reenter(ctx, program, location, count, transpose, GLdouble);
	}
	
	static void uniform1d_replacement(GLIContext ctx, GLint location, GLdouble x)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: uniform1d called.");
		
		return uniform1d_reenter(ctx, location, x);
	}
	
	static void uniform2d_replacement(GLIContext ctx, GLint location, GLdouble x, GLdouble y)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: uniform2d called.");
		
		return uniform2d_reenter(ctx, location, x, y);
	}
	
	static void uniform3d_replacement(GLIContext ctx, GLint location, GLdouble x, GLdouble y, GLdouble z)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: uniform3d called.");
		
		return uniform3d_reenter(ctx, location, x, y, z);
	}
	
	static void uniform4d_replacement(GLIContext ctx, GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: uniform4d called.");
		
		return uniform4d_reenter(ctx, location, x, y, z, w);
	}
	
	static void uniform1dv_replacement(GLIContext ctx, GLint location, GLsizei count, const GLdouble *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: uniform1dv called.");
		
		return uniform1dv_reenter(ctx, location, count, GLdouble);
	}
	
	static void uniform2dv_replacement(GLIContext ctx, GLint location, GLsizei count, const GLdouble *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: uniform2dv called.");
		
		return uniform2dv_reenter(ctx, location, count, GLdouble);
	}
	
	static void uniform3dv_replacement(GLIContext ctx, GLint location, GLsizei count, const GLdouble *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: uniform3dv called.");
		
		return uniform3dv_reenter(ctx, location, count, GLdouble);
	}
	
	static void uniform4dv_replacement(GLIContext ctx, GLint location, GLsizei count, const GLdouble *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: uniform4dv called.");
		
		return uniform4dv_reenter(ctx, location, count, GLdouble);
	}
	
	static void uniform_matrix2dv_replacement(GLIContext ctx, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: uniform_matrix2dv called.");
		
		return uniform_matrix2dv_reenter(ctx, location, count, transpose, GLdouble);
	}
	
	static void uniform_matrix3dv_replacement(GLIContext ctx, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: uniform_matrix3dv called.");
		
		return uniform_matrix3dv_reenter(ctx, location, count, transpose, GLdouble);
	}
	
	static void uniform_matrix4dv_replacement(GLIContext ctx, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: uniform_matrix4dv called.");
		
		return uniform_matrix4dv_reenter(ctx, location, count, transpose, GLdouble);
	}
	
	static void uniform_matrix2x3dv_replacement(GLIContext ctx, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: uniform_matrix2x3dv called.");
		
		return uniform_matrix2x3dv_reenter(ctx, location, count, transpose, GLdouble);
	}
	
	static void uniform_matrix3x2dv_replacement(GLIContext ctx, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: uniform_matrix3x2dv called.");
		
		return uniform_matrix3x2dv_reenter(ctx, location, count, transpose, GLdouble);
	}
	
	static void uniform_matrix2x4dv_replacement(GLIContext ctx, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: uniform_matrix2x4dv called.");
		
		return uniform_matrix2x4dv_reenter(ctx, location, count, transpose, GLdouble);
	}
	
	static void uniform_matrix4x2dv_replacement(GLIContext ctx, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: uniform_matrix4x2dv called.");
		
		return uniform_matrix4x2dv_reenter(ctx, location, count, transpose, GLdouble);
	}
	
	static void uniform_matrix3x4dv_replacement(GLIContext ctx, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: uniform_matrix3x4dv called.");
		
		return uniform_matrix3x4dv_reenter(ctx, location, count, transpose, GLdouble);
	}
	
	static void uniform_matrix4x3dv_replacement(GLIContext ctx, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: uniform_matrix4x3dv called.");
		
		return uniform_matrix4x3dv_reenter(ctx, location, count, transpose, GLdouble);
	}
	
	static void get_uniformdv_replacement(GLIContext ctx, GLuint program_obj, GLint location, GLdouble *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_uniformdv called.");
		
		return get_uniformdv_reenter(ctx, program_obj, location, *params);
	}
	
	static void vertex_attribl1d_replacement(GLIContext ctx, GLuint index, GLdouble x)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attribl1d called.");
		
		return vertex_attribl1d_reenter(ctx, index, x);
	}
	
	static void vertex_attribl2d_replacement(GLIContext ctx, GLuint index, GLdouble x, GLdouble y)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attribl2d called.");
		
		return vertex_attribl2d_reenter(ctx, index, x, y);
	}
	
	static void vertex_attribl3d_replacement(GLIContext ctx, GLuint index, GLdouble x, GLdouble y, GLdouble z)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attribl3d called.");
		
		return vertex_attribl3d_reenter(ctx, index, x, y, z);
	}
	
	static void vertex_attribl4d_replacement(GLIContext ctx, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attribl4d called.");
		
		return vertex_attribl4d_reenter(ctx, index, x, y, z, w);
	}
	
	static void vertex_attribl1dv_replacement(GLIContext ctx, GLuint index, const GLdouble *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attribl1dv called.");
		
		return vertex_attribl1dv_reenter(ctx, index, GLdouble);
	}
	
	static void vertex_attribl2dv_replacement(GLIContext ctx, GLuint index, const GLdouble *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attribl2dv called.");
		
		return vertex_attribl2dv_reenter(ctx, index, GLdouble);
	}
	
	static void vertex_attribl3dv_replacement(GLIContext ctx, GLuint index, const GLdouble *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attribl3dv called.");
		
		return vertex_attribl3dv_reenter(ctx, index, GLdouble);
	}
	
	static void vertex_attribl4dv_replacement(GLIContext ctx, GLuint index, const GLdouble *v)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attribl4dv called.");
		
		return vertex_attribl4dv_reenter(ctx, index, GLdouble);
	}
	
	static void vertex_attrib_lpointer_replacement(GLIContext ctx, GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: vertex_attrib_lpointer called.");
		
		return vertex_attrib_lpointer_reenter(ctx, index, size, type, stride, void);
	}
	
	static void get_vertex_attrib_ldv_replacement(GLIContext ctx, GLuint index, GLenum pname, GLdouble *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_vertex_attrib_ldv called.");
		
		return get_vertex_attrib_ldv_reenter(ctx, index, pname, *params);
	}
	
	static GLint get_subroutine_uniform_location_replacement(GLIContext ctx, GLuint program, GLenum shadertype, const GLchar *name)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_subroutine_uniform_location called.");
		
		return get_subroutine_uniform_location_reenter(ctx, program, shadertype, GLchar);
	}
	
	static GLuint get_subroutine_index_replacement(GLIContext ctx, GLuint program, GLenum shadertype, const GLchar *name)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_subroutine_index called.");
		
		return get_subroutine_index_reenter(ctx, program, shadertype, GLchar);
	}
	
	static void get_active_subroutine_uniformiv_replacement(GLIContext ctx, GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint *values)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_active_subroutine_uniformiv called.");
		
		return get_active_subroutine_uniformiv_reenter(ctx, program, shadertype, index, pname, *values);
	}
	
	static void get_active_subroutine_uniform_name_replacement(GLIContext ctx, GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_active_subroutine_uniform_name called.");
		
		return get_active_subroutine_uniform_name_reenter(ctx, program, shadertype, index, bufsize, *length, *name);
	}
	
	static void get_active_subroutine_name_replacement(GLIContext ctx, GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_active_subroutine_name called.");
		
		return get_active_subroutine_name_reenter(ctx, program, shadertype, index, bufsize, *length, *name);
	}
	
	static void uniform_subroutinesuiv_replacement(GLIContext ctx, GLenum shadertype, GLsizei count, const GLuint *indices)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: uniform_subroutinesuiv called.");
		
		return uniform_subroutinesuiv_reenter(ctx, shadertype, count, GLuint);
	}
	
	static void get_uniform_subroutineuiv_replacement(GLIContext ctx, GLenum shadertype, GLint location, GLuint *params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_uniform_subroutineuiv called.");
		
		return get_uniform_subroutineuiv_reenter(ctx, shadertype, location, *params);
	}
	
	static void get_program_stageiv_replacement(GLIContext ctx, GLuint program, GLenum shadertype, GLenum pname, GLint *values)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_program_stageiv called.");
		
		return get_program_stageiv_reenter(ctx, program, shadertype, pname, *values);
	}
	
	static void get_internal_formativ_replacement((GLIContext ctx, GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint* params)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: get_internal_formativ called.");
		
		return get_internal_formativ_reenter(ctx, target, internalformat, pname, bufSize, params);
	}
	
	static void tex_storage1D_replacement((GLIContext ctx, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_storage1D called.");
		
		return tex_storage1D_reenter(ctx, target, levels, internalformat, width);
	}
	
	static void tex_storage2D_replacement((GLIContext ctx, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_storage2D called.");
		
		return tex_storage2D_reenter(ctx, target, levels, internalformat, width, height);
	}
	
	static void tex_storage3D_replacement((GLIContext ctx, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: tex_storage3D called.");
		
		return tex_storage3D_reenter(ctx, target, levels, internalformat, width, height, depth);
	}
	
	static void label_object_with_responsible_process_APPLE_replacement((GLIContext ctx, GLenum type, GLuint name, GLint pid)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: label_object_with_responsible_process_APPLE called.");
		
		return label_object_with_responsible_process_APPLE_reenter(ctx, type, name, pid);
	}
	
	static void texture_barrier_NV_replacement((GLIContext ctx)
	{
		syslog(LOG_NOTICE, "OpenGLFileLogger: texture_barrier_NV called.");
		
		return texture_barrier_NV_reenter(ctx);
	}
	
	static CGLContextObj CGLGetCurrentContext_replacement(void)
	{
		CGLContextObj obj = CGLGetCurrentContext_reenter();
		syslog(LOG_NOTICE, "OpenGLFileLogger: Found Context: %p", obj);
		if (!overriden)
		{
			mach_override_ptr((void*)obj->disp.accum, (void*)accum_replacement, (void**)&accum_reenter);
			mach_override_ptr((void*)obj->disp.alpha_func, (void*)alpha_func_replacement, (void**)&alpha_func_reenter);
			mach_override_ptr((void*)obj->disp.are_textures_resident, (void*)are_textures_resident_replacement, (void**)&are_textures_resident_reenter);
			mach_override_ptr((void*)obj->disp.array_element, (void*)array_element_replacement, (void**)&array_element_reenter);
			mach_override_ptr((void*)obj->disp.begin, (void*)begin_replacement, (void**)&begin_reenter);
			mach_override_ptr((void*)obj->disp.bind_texture, (void*)bind_texture_replacement, (void**)&bind_texture_reenter);
			mach_override_ptr((void*)obj->disp.bitmap, (void*)bitmap_replacement, (void**)&bitmap_reenter);
			mach_override_ptr((void*)obj->disp.blend_func, (void*)blend_func_replacement, (void**)&blend_func_reenter);
			mach_override_ptr((void*)obj->disp.call_list, (void*)call_list_replacement, (void**)&call_list_reenter);
			mach_override_ptr((void*)obj->disp.call_lists, (void*)call_lists_replacement, (void**)&call_lists_reenter);
			mach_override_ptr((void*)obj->disp.clear, (void*)clear_replacement, (void**)&clear_reenter);
			mach_override_ptr((void*)obj->disp.clear_accum, (void*)clear_accum_replacement, (void**)&clear_accum_reenter);
			mach_override_ptr((void*)obj->disp.clear_color, (void*)clear_color_replacement, (void**)&clear_color_reenter);
			mach_override_ptr((void*)obj->disp.clear_depth, (void*)clear_depth_replacement, (void**)&clear_depth_reenter);
			mach_override_ptr((void*)obj->disp.clear_index, (void*)clear_index_replacement, (void**)&clear_index_reenter);
			mach_override_ptr((void*)obj->disp.clear_stencil, (void*)clear_stencil_replacement, (void**)&clear_stencil_reenter);
			mach_override_ptr((void*)obj->disp.clip_plane, (void*)clip_plane_replacement, (void**)&clip_plane_reenter);
			mach_override_ptr((void*)obj->disp.color3b, (void*)color3b_replacement, (void**)&color3b_reenter);
			mach_override_ptr((void*)obj->disp.color3bv, (void*)color3bv_replacement, (void**)&color3bv_reenter);
			mach_override_ptr((void*)obj->disp.color3d, (void*)color3d_replacement, (void**)&color3d_reenter);
			mach_override_ptr((void*)obj->disp.color3dv, (void*)color3dv_replacement, (void**)&color3dv_reenter);
			mach_override_ptr((void*)obj->disp.color3f, (void*)color3f_replacement, (void**)&color3f_reenter);
			mach_override_ptr((void*)obj->disp.color3fv, (void*)color3fv_replacement, (void**)&color3fv_reenter);
			mach_override_ptr((void*)obj->disp.color3i, (void*)color3i_replacement, (void**)&color3i_reenter);
			mach_override_ptr((void*)obj->disp.color3iv, (void*)color3iv_replacement, (void**)&color3iv_reenter);
			mach_override_ptr((void*)obj->disp.color3s, (void*)color3s_replacement, (void**)&color3s_reenter);
			mach_override_ptr((void*)obj->disp.color3sv, (void*)color3sv_replacement, (void**)&color3sv_reenter);
			mach_override_ptr((void*)obj->disp.color3ub, (void*)color3ub_replacement, (void**)&color3ub_reenter);
			mach_override_ptr((void*)obj->disp.color3ubv, (void*)color3ubv_replacement, (void**)&color3ubv_reenter);
			mach_override_ptr((void*)obj->disp.color3ui, (void*)color3ui_replacement, (void**)&color3ui_reenter);
			mach_override_ptr((void*)obj->disp.color3uiv, (void*)color3uiv_replacement, (void**)&color3uiv_reenter);
			mach_override_ptr((void*)obj->disp.color3us, (void*)color3us_replacement, (void**)&color3us_reenter);
			mach_override_ptr((void*)obj->disp.color3usv, (void*)color3usv_replacement, (void**)&color3usv_reenter);
			mach_override_ptr((void*)obj->disp.color4b, (void*)color4b_replacement, (void**)&color4b_reenter);
			mach_override_ptr((void*)obj->disp.color4bv, (void*)color4bv_replacement, (void**)&color4bv_reenter);
			mach_override_ptr((void*)obj->disp.color4d, (void*)color4d_replacement, (void**)&color4d_reenter);
			mach_override_ptr((void*)obj->disp.color4dv, (void*)color4dv_replacement, (void**)&color4dv_reenter);
			mach_override_ptr((void*)obj->disp.color4f, (void*)color4f_replacement, (void**)&color4f_reenter);
			mach_override_ptr((void*)obj->disp.color4fv, (void*)color4fv_replacement, (void**)&color4fv_reenter);
			mach_override_ptr((void*)obj->disp.color4i, (void*)color4i_replacement, (void**)&color4i_reenter);
			mach_override_ptr((void*)obj->disp.color4iv, (void*)color4iv_replacement, (void**)&color4iv_reenter);
			mach_override_ptr((void*)obj->disp.color4s, (void*)color4s_replacement, (void**)&color4s_reenter);
			mach_override_ptr((void*)obj->disp.color4sv, (void*)color4sv_replacement, (void**)&color4sv_reenter);
			mach_override_ptr((void*)obj->disp.color4ub, (void*)color4ub_replacement, (void**)&color4ub_reenter);
			mach_override_ptr((void*)obj->disp.color4ubv, (void*)color4ubv_replacement, (void**)&color4ubv_reenter);
			mach_override_ptr((void*)obj->disp.color4ui, (void*)color4ui_replacement, (void**)&color4ui_reenter);
			mach_override_ptr((void*)obj->disp.color4uiv, (void*)color4uiv_replacement, (void**)&color4uiv_reenter);
			mach_override_ptr((void*)obj->disp.color4us, (void*)color4us_replacement, (void**)&color4us_reenter);
			mach_override_ptr((void*)obj->disp.color4usv, (void*)color4usv_replacement, (void**)&color4usv_reenter);
			mach_override_ptr((void*)obj->disp.color_mask, (void*)color_mask_replacement, (void**)&color_mask_reenter);
			mach_override_ptr((void*)obj->disp.color_material, (void*)color_material_replacement, (void**)&color_material_reenter);
			mach_override_ptr((void*)obj->disp.color_pointer, (void*)color_pointer_replacement, (void**)&color_pointer_reenter);
			mach_override_ptr((void*)obj->disp.copy_pixels, (void*)copy_pixels_replacement, (void**)&copy_pixels_reenter);
			mach_override_ptr((void*)obj->disp.copy_tex_image1D, (void*)copy_tex_image1D_replacement, (void**)&copy_tex_image1D_reenter);
			mach_override_ptr((void*)obj->disp.copy_tex_image2D, (void*)copy_tex_image2D_replacement, (void**)&copy_tex_image2D_reenter);
			mach_override_ptr((void*)obj->disp.copy_tex_sub_image1D, (void*)copy_tex_sub_image1D_replacement, (void**)&copy_tex_sub_image1D_reenter);
			mach_override_ptr((void*)obj->disp.copy_tex_sub_image2D, (void*)copy_tex_sub_image2D_replacement, (void**)&copy_tex_sub_image2D_reenter);
			mach_override_ptr((void*)obj->disp.cull_face, (void*)cull_face_replacement, (void**)&cull_face_reenter);
			mach_override_ptr((void*)obj->disp.delete_lists, (void*)delete_lists_replacement, (void**)&delete_lists_reenter);
			mach_override_ptr((void*)obj->disp.delete_textures, (void*)delete_textures_replacement, (void**)&delete_textures_reenter);
			mach_override_ptr((void*)obj->disp.depth_func, (void*)depth_func_replacement, (void**)&depth_func_reenter);
			mach_override_ptr((void*)obj->disp.depth_mask, (void*)depth_mask_replacement, (void**)&depth_mask_reenter);
			mach_override_ptr((void*)obj->disp.depth_range, (void*)depth_range_replacement, (void**)&depth_range_reenter);
			mach_override_ptr((void*)obj->disp.disable, (void*)disable_replacement, (void**)&disable_reenter);
			mach_override_ptr((void*)obj->disp.disable_client_state, (void*)disable_client_state_replacement, (void**)&disable_client_state_reenter);
			mach_override_ptr((void*)obj->disp.draw_arrays, (void*)draw_arrays_replacement, (void**)&draw_arrays_reenter);
			mach_override_ptr((void*)obj->disp.draw_buffer, (void*)draw_buffer_replacement, (void**)&draw_buffer_reenter);
			mach_override_ptr((void*)obj->disp.draw_elements, (void*)draw_elements_replacement, (void**)&draw_elements_reenter);
			mach_override_ptr((void*)obj->disp.draw_pixels, (void*)draw_pixels_replacement, (void**)&draw_pixels_reenter);
			mach_override_ptr((void*)obj->disp.edge_flag, (void*)edge_flag_replacement, (void**)&edge_flag_reenter);
			mach_override_ptr((void*)obj->disp.edge_flag_pointer, (void*)edge_flag_pointer_replacement, (void**)&edge_flag_pointer_reenter);
			mach_override_ptr((void*)obj->disp.edge_flagv, (void*)edge_flagv_replacement, (void**)&edge_flagv_reenter);
			mach_override_ptr((void*)obj->disp.enable, (void*)enable_replacement, (void**)&enable_reenter);
			mach_override_ptr((void*)obj->disp.enable_client_state, (void*)enable_client_state_replacement, (void**)&enable_client_state_reenter);
			mach_override_ptr((void*)obj->disp.end, (void*)end_replacement, (void**)&end_reenter);
			mach_override_ptr((void*)obj->disp.end_list, (void*)end_list_replacement, (void**)&end_list_reenter);
			mach_override_ptr((void*)obj->disp.eval_coord1d, (void*)eval_coord1d_replacement, (void**)&eval_coord1d_reenter);
			mach_override_ptr((void*)obj->disp.eval_coord1dv, (void*)eval_coord1dv_replacement, (void**)&eval_coord1dv_reenter);
			mach_override_ptr((void*)obj->disp.eval_coord1f, (void*)eval_coord1f_replacement, (void**)&eval_coord1f_reenter);
			mach_override_ptr((void*)obj->disp.eval_coord1fv, (void*)eval_coord1fv_replacement, (void**)&eval_coord1fv_reenter);
			mach_override_ptr((void*)obj->disp.eval_coord2d, (void*)eval_coord2d_replacement, (void**)&eval_coord2d_reenter);
			mach_override_ptr((void*)obj->disp.eval_coord2dv, (void*)eval_coord2dv_replacement, (void**)&eval_coord2dv_reenter);
			mach_override_ptr((void*)obj->disp.eval_coord2f, (void*)eval_coord2f_replacement, (void**)&eval_coord2f_reenter);
			mach_override_ptr((void*)obj->disp.eval_coord2fv, (void*)eval_coord2fv_replacement, (void**)&eval_coord2fv_reenter);
			mach_override_ptr((void*)obj->disp.eval_mesh1, (void*)eval_mesh1_replacement, (void**)&eval_mesh1_reenter);
			mach_override_ptr((void*)obj->disp.eval_mesh2, (void*)eval_mesh2_replacement, (void**)&eval_mesh2_reenter);
			mach_override_ptr((void*)obj->disp.eval_point1, (void*)eval_point1_replacement, (void**)&eval_point1_reenter);
			mach_override_ptr((void*)obj->disp.eval_point2, (void*)eval_point2_replacement, (void**)&eval_point2_reenter);
			mach_override_ptr((void*)obj->disp.feedback_buffer, (void*)feedback_buffer_replacement, (void**)&feedback_buffer_reenter);
			mach_override_ptr((void*)obj->disp.finish, (void*)finish_replacement, (void**)&finish_reenter);
			mach_override_ptr((void*)obj->disp.flush, (void*)flush_replacement, (void**)&flush_reenter);
			mach_override_ptr((void*)obj->disp.fogf, (void*)fogf_replacement, (void**)&fogf_reenter);
			mach_override_ptr((void*)obj->disp.fogfv, (void*)fogfv_replacement, (void**)&fogfv_reenter);
			mach_override_ptr((void*)obj->disp.fogi, (void*)fogi_replacement, (void**)&fogi_reenter);
			mach_override_ptr((void*)obj->disp.fogiv, (void*)fogiv_replacement, (void**)&fogiv_reenter);
			mach_override_ptr((void*)obj->disp.front_face, (void*)front_face_replacement, (void**)&front_face_reenter);
			mach_override_ptr((void*)obj->disp.frustum, (void*)frustum_replacement, (void**)&frustum_reenter);
			mach_override_ptr((void*)obj->disp.gen_lists, (void*)gen_lists_replacement, (void**)&gen_lists_reenter);
			mach_override_ptr((void*)obj->disp.gen_textures, (void*)gen_textures_replacement, (void**)&gen_textures_reenter);
			mach_override_ptr((void*)obj->disp.get_booleanv, (void*)get_booleanv_replacement, (void**)&get_booleanv_reenter);
			mach_override_ptr((void*)obj->disp.get_clip_plane, (void*)get_clip_plane_replacement, (void**)&get_clip_plane_reenter);
			mach_override_ptr((void*)obj->disp.get_doublev, (void*)get_doublev_replacement, (void**)&get_doublev_reenter);
			mach_override_ptr((void*)obj->disp.get_error, (void*)get_error_replacement, (void**)&get_error_reenter);
			mach_override_ptr((void*)obj->disp.get_floatv, (void*)get_floatv_replacement, (void**)&get_floatv_reenter);
			mach_override_ptr((void*)obj->disp.get_integerv, (void*)get_integerv_replacement, (void**)&get_integerv_reenter);
			mach_override_ptr((void*)obj->disp.get_lightfv, (void*)get_lightfv_replacement, (void**)&get_lightfv_reenter);
			mach_override_ptr((void*)obj->disp.get_lightiv, (void*)get_lightiv_replacement, (void**)&get_lightiv_reenter);
			mach_override_ptr((void*)obj->disp.get_mapdv, (void*)get_mapdv_replacement, (void**)&get_mapdv_reenter);
			mach_override_ptr((void*)obj->disp.get_mapfv, (void*)get_mapfv_replacement, (void**)&get_mapfv_reenter);
			mach_override_ptr((void*)obj->disp.get_mapiv, (void*)get_mapiv_replacement, (void**)&get_mapiv_reenter);
			mach_override_ptr((void*)obj->disp.get_materialfv, (void*)get_materialfv_replacement, (void**)&get_materialfv_reenter);
			mach_override_ptr((void*)obj->disp.get_materialiv, (void*)get_materialiv_replacement, (void**)&get_materialiv_reenter);
			mach_override_ptr((void*)obj->disp.get_pixel_mapfv, (void*)get_pixel_mapfv_replacement, (void**)&get_pixel_mapfv_reenter);
			mach_override_ptr((void*)obj->disp.get_pixel_mapuiv, (void*)get_pixel_mapuiv_replacement, (void**)&get_pixel_mapuiv_reenter);
			mach_override_ptr((void*)obj->disp.get_pixel_mapusv, (void*)get_pixel_mapusv_replacement, (void**)&get_pixel_mapusv_reenter);
			mach_override_ptr((void*)obj->disp.get_pointerv, (void*)get_pointerv_replacement, (void**)&get_pointerv_reenter);
			mach_override_ptr((void*)obj->disp.get_polygon_stipple, (void*)get_polygon_stipple_replacement, (void**)&get_polygon_stipple_reenter);
			mach_override_ptr((void*)obj->disp.get_tex_envfv, (void*)get_tex_envfv_replacement, (void**)&get_tex_envfv_reenter);
			mach_override_ptr((void*)obj->disp.get_tex_enviv, (void*)get_tex_enviv_replacement, (void**)&get_tex_enviv_reenter);
			mach_override_ptr((void*)obj->disp.get_tex_gendv, (void*)get_tex_gendv_replacement, (void**)&get_tex_gendv_reenter);
			mach_override_ptr((void*)obj->disp.get_tex_genfv, (void*)get_tex_genfv_replacement, (void**)&get_tex_genfv_reenter);
			mach_override_ptr((void*)obj->disp.get_tex_geniv, (void*)get_tex_geniv_replacement, (void**)&get_tex_geniv_reenter);
			mach_override_ptr((void*)obj->disp.get_tex_image, (void*)get_tex_image_replacement, (void**)&get_tex_image_reenter);
			mach_override_ptr((void*)obj->disp.get_tex_level_parameterfv, (void*)get_tex_level_parameterfv_replacement, (void**)&get_tex_level_parameterfv_reenter);
			mach_override_ptr((void*)obj->disp.get_tex_level_parameteriv, (void*)get_tex_level_parameteriv_replacement, (void**)&get_tex_level_parameteriv_reenter);
			mach_override_ptr((void*)obj->disp.get_tex_parameterfv, (void*)get_tex_parameterfv_replacement, (void**)&get_tex_parameterfv_reenter);
			mach_override_ptr((void*)obj->disp.get_tex_parameteriv, (void*)get_tex_parameteriv_replacement, (void**)&get_tex_parameteriv_reenter);
			mach_override_ptr((void*)obj->disp.hint, (void*)hint_replacement, (void**)&hint_reenter);
			mach_override_ptr((void*)obj->disp.index_mask, (void*)index_mask_replacement, (void**)&index_mask_reenter);
			mach_override_ptr((void*)obj->disp.index_pointer, (void*)index_pointer_replacement, (void**)&index_pointer_reenter);
			mach_override_ptr((void*)obj->disp.indexd, (void*)indexd_replacement, (void**)&indexd_reenter);
			mach_override_ptr((void*)obj->disp.indexdv, (void*)indexdv_replacement, (void**)&indexdv_reenter);
			mach_override_ptr((void*)obj->disp.indexf, (void*)indexf_replacement, (void**)&indexf_reenter);
			mach_override_ptr((void*)obj->disp.indexfv, (void*)indexfv_replacement, (void**)&indexfv_reenter);
			mach_override_ptr((void*)obj->disp.indexi, (void*)indexi_replacement, (void**)&indexi_reenter);
			mach_override_ptr((void*)obj->disp.indexiv, (void*)indexiv_replacement, (void**)&indexiv_reenter);
			mach_override_ptr((void*)obj->disp.indexs, (void*)indexs_replacement, (void**)&indexs_reenter);
			mach_override_ptr((void*)obj->disp.indexsv, (void*)indexsv_replacement, (void**)&indexsv_reenter);
			mach_override_ptr((void*)obj->disp.indexub, (void*)indexub_replacement, (void**)&indexub_reenter);
			mach_override_ptr((void*)obj->disp.indexubv, (void*)indexubv_replacement, (void**)&indexubv_reenter);
			mach_override_ptr((void*)obj->disp.init_names, (void*)init_names_replacement, (void**)&init_names_reenter);
			mach_override_ptr((void*)obj->disp.interleaved_arrays, (void*)interleaved_arrays_replacement, (void**)&interleaved_arrays_reenter);
			mach_override_ptr((void*)obj->disp.is_enabled, (void*)is_enabled_replacement, (void**)&is_enabled_reenter);
			mach_override_ptr((void*)obj->disp.is_list, (void*)is_list_replacement, (void**)&is_list_reenter);
			mach_override_ptr((void*)obj->disp.is_texture, (void*)is_texture_replacement, (void**)&is_texture_reenter);
			mach_override_ptr((void*)obj->disp.light_modelf, (void*)light_modelf_replacement, (void**)&light_modelf_reenter);
			mach_override_ptr((void*)obj->disp.light_modelfv, (void*)light_modelfv_replacement, (void**)&light_modelfv_reenter);
			mach_override_ptr((void*)obj->disp.light_modeli, (void*)light_modeli_replacement, (void**)&light_modeli_reenter);
			mach_override_ptr((void*)obj->disp.light_modeliv, (void*)light_modeliv_replacement, (void**)&light_modeliv_reenter);
			mach_override_ptr((void*)obj->disp.lightf, (void*)lightf_replacement, (void**)&lightf_reenter);
			mach_override_ptr((void*)obj->disp.lightfv, (void*)lightfv_replacement, (void**)&lightfv_reenter);
			mach_override_ptr((void*)obj->disp.lighti, (void*)lighti_replacement, (void**)&lighti_reenter);
			mach_override_ptr((void*)obj->disp.lightiv, (void*)lightiv_replacement, (void**)&lightiv_reenter);
			mach_override_ptr((void*)obj->disp.line_stipple, (void*)line_stipple_replacement, (void**)&line_stipple_reenter);
			mach_override_ptr((void*)obj->disp.line_width, (void*)line_width_replacement, (void**)&line_width_reenter);
			mach_override_ptr((void*)obj->disp.list_base, (void*)list_base_replacement, (void**)&list_base_reenter);
			mach_override_ptr((void*)obj->disp.load_identity, (void*)load_identity_replacement, (void**)&load_identity_reenter);
			mach_override_ptr((void*)obj->disp.load_matrixd, (void*)load_matrixd_replacement, (void**)&load_matrixd_reenter);
			mach_override_ptr((void*)obj->disp.load_matrixf, (void*)load_matrixf_replacement, (void**)&load_matrixf_reenter);
			mach_override_ptr((void*)obj->disp.load_name, (void*)load_name_replacement, (void**)&load_name_reenter);
			mach_override_ptr((void*)obj->disp.logic_op, (void*)logic_op_replacement, (void**)&logic_op_reenter);
			mach_override_ptr((void*)obj->disp.map1d, (void*)map1d_replacement, (void**)&map1d_reenter);
			mach_override_ptr((void*)obj->disp.map1f, (void*)map1f_replacement, (void**)&map1f_reenter);
			mach_override_ptr((void*)obj->disp.map2d, (void*)map2d_replacement, (void**)&map2d_reenter);
			mach_override_ptr((void*)obj->disp.map2f, (void*)map2f_replacement, (void**)&map2f_reenter);
			mach_override_ptr((void*)obj->disp.map_grid1d, (void*)map_grid1d_replacement, (void**)&map_grid1d_reenter);
			mach_override_ptr((void*)obj->disp.map_grid1f, (void*)map_grid1f_replacement, (void**)&map_grid1f_reenter);
			mach_override_ptr((void*)obj->disp.map_grid2d, (void*)map_grid2d_replacement, (void**)&map_grid2d_reenter);
			mach_override_ptr((void*)obj->disp.map_grid2f, (void*)map_grid2f_replacement, (void**)&map_grid2f_reenter);
			mach_override_ptr((void*)obj->disp.materialf, (void*)materialf_replacement, (void**)&materialf_reenter);
			mach_override_ptr((void*)obj->disp.materialfv, (void*)materialfv_replacement, (void**)&materialfv_reenter);
			mach_override_ptr((void*)obj->disp.materiali, (void*)materiali_replacement, (void**)&materiali_reenter);
			mach_override_ptr((void*)obj->disp.materialiv, (void*)materialiv_replacement, (void**)&materialiv_reenter);
			mach_override_ptr((void*)obj->disp.matrix_mode, (void*)matrix_mode_replacement, (void**)&matrix_mode_reenter);
			mach_override_ptr((void*)obj->disp.mult_matrixd, (void*)mult_matrixd_replacement, (void**)&mult_matrixd_reenter);
			mach_override_ptr((void*)obj->disp.mult_matrixf, (void*)mult_matrixf_replacement, (void**)&mult_matrixf_reenter);
			mach_override_ptr((void*)obj->disp.new_list, (void*)new_list_replacement, (void**)&new_list_reenter);
			mach_override_ptr((void*)obj->disp.normal3b, (void*)normal3b_replacement, (void**)&normal3b_reenter);
			mach_override_ptr((void*)obj->disp.normal3bv, (void*)normal3bv_replacement, (void**)&normal3bv_reenter);
			mach_override_ptr((void*)obj->disp.normal3d, (void*)normal3d_replacement, (void**)&normal3d_reenter);
			mach_override_ptr((void*)obj->disp.normal3dv, (void*)normal3dv_replacement, (void**)&normal3dv_reenter);
			mach_override_ptr((void*)obj->disp.normal3f, (void*)normal3f_replacement, (void**)&normal3f_reenter);
			mach_override_ptr((void*)obj->disp.normal3fv, (void*)normal3fv_replacement, (void**)&normal3fv_reenter);
			mach_override_ptr((void*)obj->disp.normal3i, (void*)normal3i_replacement, (void**)&normal3i_reenter);
			mach_override_ptr((void*)obj->disp.normal3iv, (void*)normal3iv_replacement, (void**)&normal3iv_reenter);
			mach_override_ptr((void*)obj->disp.normal3s, (void*)normal3s_replacement, (void**)&normal3s_reenter);
			mach_override_ptr((void*)obj->disp.normal3sv, (void*)normal3sv_replacement, (void**)&normal3sv_reenter);
			mach_override_ptr((void*)obj->disp.normal_pointer, (void*)normal_pointer_replacement, (void**)&normal_pointer_reenter);
			mach_override_ptr((void*)obj->disp.ortho, (void*)ortho_replacement, (void**)&ortho_reenter);
			mach_override_ptr((void*)obj->disp.pass_through, (void*)pass_through_replacement, (void**)&pass_through_reenter);
			mach_override_ptr((void*)obj->disp.pixel_mapfv, (void*)pixel_mapfv_replacement, (void**)&pixel_mapfv_reenter);
			mach_override_ptr((void*)obj->disp.pixel_mapuiv, (void*)pixel_mapuiv_replacement, (void**)&pixel_mapuiv_reenter);
			mach_override_ptr((void*)obj->disp.pixel_mapusv, (void*)pixel_mapusv_replacement, (void**)&pixel_mapusv_reenter);
			mach_override_ptr((void*)obj->disp.pixel_storef, (void*)pixel_storef_replacement, (void**)&pixel_storef_reenter);
			mach_override_ptr((void*)obj->disp.pixel_storei, (void*)pixel_storei_replacement, (void**)&pixel_storei_reenter);
			mach_override_ptr((void*)obj->disp.pixel_transferf, (void*)pixel_transferf_replacement, (void**)&pixel_transferf_reenter);
			mach_override_ptr((void*)obj->disp.pixel_transferi, (void*)pixel_transferi_replacement, (void**)&pixel_transferi_reenter);
			mach_override_ptr((void*)obj->disp.pixel_zoom, (void*)pixel_zoom_replacement, (void**)&pixel_zoom_reenter);
			mach_override_ptr((void*)obj->disp.point_size, (void*)point_size_replacement, (void**)&point_size_reenter);
			mach_override_ptr((void*)obj->disp.polygon_mode, (void*)polygon_mode_replacement, (void**)&polygon_mode_reenter);
			mach_override_ptr((void*)obj->disp.polygon_offset, (void*)polygon_offset_replacement, (void**)&polygon_offset_reenter);
			mach_override_ptr((void*)obj->disp.polygon_stipple, (void*)polygon_stipple_replacement, (void**)&polygon_stipple_reenter);
			mach_override_ptr((void*)obj->disp.pop_attrib, (void*)pop_attrib_replacement, (void**)&pop_attrib_reenter);
			mach_override_ptr((void*)obj->disp.pop_client_attrib, (void*)pop_client_attrib_replacement, (void**)&pop_client_attrib_reenter);
			mach_override_ptr((void*)obj->disp.pop_matrix, (void*)pop_matrix_replacement, (void**)&pop_matrix_reenter);
			mach_override_ptr((void*)obj->disp.pop_name, (void*)pop_name_replacement, (void**)&pop_name_reenter);
			mach_override_ptr((void*)obj->disp.prioritize_textures, (void*)prioritize_textures_replacement, (void**)&prioritize_textures_reenter);
			mach_override_ptr((void*)obj->disp.push_attrib, (void*)push_attrib_replacement, (void**)&push_attrib_reenter);
			mach_override_ptr((void*)obj->disp.push_client_attrib, (void*)push_client_attrib_replacement, (void**)&push_client_attrib_reenter);
			mach_override_ptr((void*)obj->disp.push_matrix, (void*)push_matrix_replacement, (void**)&push_matrix_reenter);
			mach_override_ptr((void*)obj->disp.push_name, (void*)push_name_replacement, (void**)&push_name_reenter);
			mach_override_ptr((void*)obj->disp.raster_pos2d, (void*)raster_pos2d_replacement, (void**)&raster_pos2d_reenter);
			mach_override_ptr((void*)obj->disp.raster_pos2dv, (void*)raster_pos2dv_replacement, (void**)&raster_pos2dv_reenter);
			mach_override_ptr((void*)obj->disp.raster_pos2f, (void*)raster_pos2f_replacement, (void**)&raster_pos2f_reenter);
			mach_override_ptr((void*)obj->disp.raster_pos2fv, (void*)raster_pos2fv_replacement, (void**)&raster_pos2fv_reenter);
			mach_override_ptr((void*)obj->disp.raster_pos2i, (void*)raster_pos2i_replacement, (void**)&raster_pos2i_reenter);
			mach_override_ptr((void*)obj->disp.raster_pos2iv, (void*)raster_pos2iv_replacement, (void**)&raster_pos2iv_reenter);
			mach_override_ptr((void*)obj->disp.raster_pos2s, (void*)raster_pos2s_replacement, (void**)&raster_pos2s_reenter);
			mach_override_ptr((void*)obj->disp.raster_pos2sv, (void*)raster_pos2sv_replacement, (void**)&raster_pos2sv_reenter);
			mach_override_ptr((void*)obj->disp.raster_pos3d, (void*)raster_pos3d_replacement, (void**)&raster_pos3d_reenter);
			mach_override_ptr((void*)obj->disp.raster_pos3dv, (void*)raster_pos3dv_replacement, (void**)&raster_pos3dv_reenter);
			mach_override_ptr((void*)obj->disp.raster_pos3f, (void*)raster_pos3f_replacement, (void**)&raster_pos3f_reenter);
			mach_override_ptr((void*)obj->disp.raster_pos3fv, (void*)raster_pos3fv_replacement, (void**)&raster_pos3fv_reenter);
			mach_override_ptr((void*)obj->disp.raster_pos3i, (void*)raster_pos3i_replacement, (void**)&raster_pos3i_reenter);
			mach_override_ptr((void*)obj->disp.raster_pos3iv, (void*)raster_pos3iv_replacement, (void**)&raster_pos3iv_reenter);
			mach_override_ptr((void*)obj->disp.raster_pos3s, (void*)raster_pos3s_replacement, (void**)&raster_pos3s_reenter);
			mach_override_ptr((void*)obj->disp.raster_pos3sv, (void*)raster_pos3sv_replacement, (void**)&raster_pos3sv_reenter);
			mach_override_ptr((void*)obj->disp.raster_pos4d, (void*)raster_pos4d_replacement, (void**)&raster_pos4d_reenter);
			mach_override_ptr((void*)obj->disp.raster_pos4dv, (void*)raster_pos4dv_replacement, (void**)&raster_pos4dv_reenter);
			mach_override_ptr((void*)obj->disp.raster_pos4f, (void*)raster_pos4f_replacement, (void**)&raster_pos4f_reenter);
			mach_override_ptr((void*)obj->disp.raster_pos4fv, (void*)raster_pos4fv_replacement, (void**)&raster_pos4fv_reenter);
			mach_override_ptr((void*)obj->disp.raster_pos4i, (void*)raster_pos4i_replacement, (void**)&raster_pos4i_reenter);
			mach_override_ptr((void*)obj->disp.raster_pos4iv, (void*)raster_pos4iv_replacement, (void**)&raster_pos4iv_reenter);
			mach_override_ptr((void*)obj->disp.raster_pos4s, (void*)raster_pos4s_replacement, (void**)&raster_pos4s_reenter);
			mach_override_ptr((void*)obj->disp.raster_pos4sv, (void*)raster_pos4sv_replacement, (void**)&raster_pos4sv_reenter);
			mach_override_ptr((void*)obj->disp.read_buffer, (void*)read_buffer_replacement, (void**)&read_buffer_reenter);
			mach_override_ptr((void*)obj->disp.read_pixels, (void*)read_pixels_replacement, (void**)&read_pixels_reenter);
			mach_override_ptr((void*)obj->disp.rectd, (void*)rectd_replacement, (void**)&rectd_reenter);
			mach_override_ptr((void*)obj->disp.rectdv, (void*)rectdv_replacement, (void**)&rectdv_reenter);
			mach_override_ptr((void*)obj->disp.rectf, (void*)rectf_replacement, (void**)&rectf_reenter);
			mach_override_ptr((void*)obj->disp.rectfv, (void*)rectfv_replacement, (void**)&rectfv_reenter);
			mach_override_ptr((void*)obj->disp.recti, (void*)recti_replacement, (void**)&recti_reenter);
			mach_override_ptr((void*)obj->disp.rectiv, (void*)rectiv_replacement, (void**)&rectiv_reenter);
			mach_override_ptr((void*)obj->disp.rects, (void*)rects_replacement, (void**)&rects_reenter);
			mach_override_ptr((void*)obj->disp.rectsv, (void*)rectsv_replacement, (void**)&rectsv_reenter);
			mach_override_ptr((void*)obj->disp.render_mode, (void*)render_mode_replacement, (void**)&render_mode_reenter);
			mach_override_ptr((void*)obj->disp.rotated, (void*)rotated_replacement, (void**)&rotated_reenter);
			mach_override_ptr((void*)obj->disp.rotatef, (void*)rotatef_replacement, (void**)&rotatef_reenter);
			mach_override_ptr((void*)obj->disp.scaled, (void*)scaled_replacement, (void**)&scaled_reenter);
			mach_override_ptr((void*)obj->disp.scalef, (void*)scalef_replacement, (void**)&scalef_reenter);
			mach_override_ptr((void*)obj->disp.scissor, (void*)scissor_replacement, (void**)&scissor_reenter);
			mach_override_ptr((void*)obj->disp.select_buffer, (void*)select_buffer_replacement, (void**)&select_buffer_reenter);
			mach_override_ptr((void*)obj->disp.shade_model, (void*)shade_model_replacement, (void**)&shade_model_reenter);
			mach_override_ptr((void*)obj->disp.stencil_func, (void*)stencil_func_replacement, (void**)&stencil_func_reenter);
			mach_override_ptr((void*)obj->disp.stencil_mask, (void*)stencil_mask_replacement, (void**)&stencil_mask_reenter);
			mach_override_ptr((void*)obj->disp.stencil_op, (void*)stencil_op_replacement, (void**)&stencil_op_reenter);
			mach_override_ptr((void*)obj->disp.tex_coord1d, (void*)tex_coord1d_replacement, (void**)&tex_coord1d_reenter);
			mach_override_ptr((void*)obj->disp.tex_coord1dv, (void*)tex_coord1dv_replacement, (void**)&tex_coord1dv_reenter);
			mach_override_ptr((void*)obj->disp.tex_coord1f, (void*)tex_coord1f_replacement, (void**)&tex_coord1f_reenter);
			mach_override_ptr((void*)obj->disp.tex_coord1fv, (void*)tex_coord1fv_replacement, (void**)&tex_coord1fv_reenter);
			mach_override_ptr((void*)obj->disp.tex_coord1i, (void*)tex_coord1i_replacement, (void**)&tex_coord1i_reenter);
			mach_override_ptr((void*)obj->disp.tex_coord1iv, (void*)tex_coord1iv_replacement, (void**)&tex_coord1iv_reenter);
			mach_override_ptr((void*)obj->disp.tex_coord1s, (void*)tex_coord1s_replacement, (void**)&tex_coord1s_reenter);
			mach_override_ptr((void*)obj->disp.tex_coord1sv, (void*)tex_coord1sv_replacement, (void**)&tex_coord1sv_reenter);
			mach_override_ptr((void*)obj->disp.tex_coord2d, (void*)tex_coord2d_replacement, (void**)&tex_coord2d_reenter);
			mach_override_ptr((void*)obj->disp.tex_coord2dv, (void*)tex_coord2dv_replacement, (void**)&tex_coord2dv_reenter);
			mach_override_ptr((void*)obj->disp.tex_coord2f, (void*)tex_coord2f_replacement, (void**)&tex_coord2f_reenter);
			mach_override_ptr((void*)obj->disp.tex_coord2fv, (void*)tex_coord2fv_replacement, (void**)&tex_coord2fv_reenter);
			mach_override_ptr((void*)obj->disp.tex_coord2i, (void*)tex_coord2i_replacement, (void**)&tex_coord2i_reenter);
			mach_override_ptr((void*)obj->disp.tex_coord2iv, (void*)tex_coord2iv_replacement, (void**)&tex_coord2iv_reenter);
			mach_override_ptr((void*)obj->disp.tex_coord2s, (void*)tex_coord2s_replacement, (void**)&tex_coord2s_reenter);
			mach_override_ptr((void*)obj->disp.tex_coord2sv, (void*)tex_coord2sv_replacement, (void**)&tex_coord2sv_reenter);
			mach_override_ptr((void*)obj->disp.tex_coord3d, (void*)tex_coord3d_replacement, (void**)&tex_coord3d_reenter);
			mach_override_ptr((void*)obj->disp.tex_coord3dv, (void*)tex_coord3dv_replacement, (void**)&tex_coord3dv_reenter);
			mach_override_ptr((void*)obj->disp.tex_coord3f, (void*)tex_coord3f_replacement, (void**)&tex_coord3f_reenter);
			mach_override_ptr((void*)obj->disp.tex_coord3fv, (void*)tex_coord3fv_replacement, (void**)&tex_coord3fv_reenter);
			mach_override_ptr((void*)obj->disp.tex_coord3i, (void*)tex_coord3i_replacement, (void**)&tex_coord3i_reenter);
			mach_override_ptr((void*)obj->disp.tex_coord3iv, (void*)tex_coord3iv_replacement, (void**)&tex_coord3iv_reenter);
			mach_override_ptr((void*)obj->disp.tex_coord3s, (void*)tex_coord3s_replacement, (void**)&tex_coord3s_reenter);
			mach_override_ptr((void*)obj->disp.tex_coord3sv, (void*)tex_coord3sv_replacement, (void**)&tex_coord3sv_reenter);
			mach_override_ptr((void*)obj->disp.tex_coord4d, (void*)tex_coord4d_replacement, (void**)&tex_coord4d_reenter);
			mach_override_ptr((void*)obj->disp.tex_coord4dv, (void*)tex_coord4dv_replacement, (void**)&tex_coord4dv_reenter);
			mach_override_ptr((void*)obj->disp.tex_coord4f, (void*)tex_coord4f_replacement, (void**)&tex_coord4f_reenter);
			mach_override_ptr((void*)obj->disp.tex_coord4fv, (void*)tex_coord4fv_replacement, (void**)&tex_coord4fv_reenter);
			mach_override_ptr((void*)obj->disp.tex_coord4i, (void*)tex_coord4i_replacement, (void**)&tex_coord4i_reenter);
			mach_override_ptr((void*)obj->disp.tex_coord4iv, (void*)tex_coord4iv_replacement, (void**)&tex_coord4iv_reenter);
			mach_override_ptr((void*)obj->disp.tex_coord4s, (void*)tex_coord4s_replacement, (void**)&tex_coord4s_reenter);
			mach_override_ptr((void*)obj->disp.tex_coord4sv, (void*)tex_coord4sv_replacement, (void**)&tex_coord4sv_reenter);
			mach_override_ptr((void*)obj->disp.tex_coord_pointer, (void*)tex_coord_pointer_replacement, (void**)&tex_coord_pointer_reenter);
			mach_override_ptr((void*)obj->disp.tex_envf, (void*)tex_envf_replacement, (void**)&tex_envf_reenter);
			mach_override_ptr((void*)obj->disp.tex_envfv, (void*)tex_envfv_replacement, (void**)&tex_envfv_reenter);
			mach_override_ptr((void*)obj->disp.tex_envi, (void*)tex_envi_replacement, (void**)&tex_envi_reenter);
			mach_override_ptr((void*)obj->disp.tex_enviv, (void*)tex_enviv_replacement, (void**)&tex_enviv_reenter);
			mach_override_ptr((void*)obj->disp.tex_gend, (void*)tex_gend_replacement, (void**)&tex_gend_reenter);
			mach_override_ptr((void*)obj->disp.tex_gendv, (void*)tex_gendv_replacement, (void**)&tex_gendv_reenter);
			mach_override_ptr((void*)obj->disp.tex_genf, (void*)tex_genf_replacement, (void**)&tex_genf_reenter);
			mach_override_ptr((void*)obj->disp.tex_genfv, (void*)tex_genfv_replacement, (void**)&tex_genfv_reenter);
			mach_override_ptr((void*)obj->disp.tex_geni, (void*)tex_geni_replacement, (void**)&tex_geni_reenter);
			mach_override_ptr((void*)obj->disp.tex_geniv, (void*)tex_geniv_replacement, (void**)&tex_geniv_reenter);
			mach_override_ptr((void*)obj->disp.tex_image1D, (void*)tex_image1D_replacement, (void**)&tex_image1D_reenter);
			mach_override_ptr((void*)obj->disp.tex_image2D, (void*)tex_image2D_replacement, (void**)&tex_image2D_reenter);
			mach_override_ptr((void*)obj->disp.tex_parameterf, (void*)tex_parameterf_replacement, (void**)&tex_parameterf_reenter);
			mach_override_ptr((void*)obj->disp.tex_parameterfv, (void*)tex_parameterfv_replacement, (void**)&tex_parameterfv_reenter);
			mach_override_ptr((void*)obj->disp.tex_parameteri, (void*)tex_parameteri_replacement, (void**)&tex_parameteri_reenter);
			mach_override_ptr((void*)obj->disp.tex_parameteriv, (void*)tex_parameteriv_replacement, (void**)&tex_parameteriv_reenter);
			mach_override_ptr((void*)obj->disp.tex_sub_image1D, (void*)tex_sub_image1D_replacement, (void**)&tex_sub_image1D_reenter);
			mach_override_ptr((void*)obj->disp.tex_sub_image2D, (void*)tex_sub_image2D_replacement, (void**)&tex_sub_image2D_reenter);
			mach_override_ptr((void*)obj->disp.translated, (void*)translated_replacement, (void**)&translated_reenter);
			mach_override_ptr((void*)obj->disp.translatef, (void*)translatef_replacement, (void**)&translatef_reenter);
			mach_override_ptr((void*)obj->disp.vertex2d, (void*)vertex2d_replacement, (void**)&vertex2d_reenter);
			mach_override_ptr((void*)obj->disp.vertex2dv, (void*)vertex2dv_replacement, (void**)&vertex2dv_reenter);
			mach_override_ptr((void*)obj->disp.vertex2f, (void*)vertex2f_replacement, (void**)&vertex2f_reenter);
			mach_override_ptr((void*)obj->disp.vertex2fv, (void*)vertex2fv_replacement, (void**)&vertex2fv_reenter);
			mach_override_ptr((void*)obj->disp.vertex2i, (void*)vertex2i_replacement, (void**)&vertex2i_reenter);
			mach_override_ptr((void*)obj->disp.vertex2iv, (void*)vertex2iv_replacement, (void**)&vertex2iv_reenter);
			mach_override_ptr((void*)obj->disp.vertex2s, (void*)vertex2s_replacement, (void**)&vertex2s_reenter);
			mach_override_ptr((void*)obj->disp.vertex2sv, (void*)vertex2sv_replacement, (void**)&vertex2sv_reenter);
			mach_override_ptr((void*)obj->disp.vertex3d, (void*)vertex3d_replacement, (void**)&vertex3d_reenter);
			mach_override_ptr((void*)obj->disp.vertex3dv, (void*)vertex3dv_replacement, (void**)&vertex3dv_reenter);
			mach_override_ptr((void*)obj->disp.vertex3f, (void*)vertex3f_replacement, (void**)&vertex3f_reenter);
			mach_override_ptr((void*)obj->disp.vertex3fv, (void*)vertex3fv_replacement, (void**)&vertex3fv_reenter);
			mach_override_ptr((void*)obj->disp.vertex3i, (void*)vertex3i_replacement, (void**)&vertex3i_reenter);
			mach_override_ptr((void*)obj->disp.vertex3iv, (void*)vertex3iv_replacement, (void**)&vertex3iv_reenter);
			mach_override_ptr((void*)obj->disp.vertex3s, (void*)vertex3s_replacement, (void**)&vertex3s_reenter);
			mach_override_ptr((void*)obj->disp.vertex3sv, (void*)vertex3sv_replacement, (void**)&vertex3sv_reenter);
			mach_override_ptr((void*)obj->disp.vertex4d, (void*)vertex4d_replacement, (void**)&vertex4d_reenter);
			mach_override_ptr((void*)obj->disp.vertex4dv, (void*)vertex4dv_replacement, (void**)&vertex4dv_reenter);
			mach_override_ptr((void*)obj->disp.vertex4f, (void*)vertex4f_replacement, (void**)&vertex4f_reenter);
			mach_override_ptr((void*)obj->disp.vertex4fv, (void*)vertex4fv_replacement, (void**)&vertex4fv_reenter);
			mach_override_ptr((void*)obj->disp.vertex4i, (void*)vertex4i_replacement, (void**)&vertex4i_reenter);
			mach_override_ptr((void*)obj->disp.vertex4iv, (void*)vertex4iv_replacement, (void**)&vertex4iv_reenter);
			mach_override_ptr((void*)obj->disp.vertex4s, (void*)vertex4s_replacement, (void**)&vertex4s_reenter);
			mach_override_ptr((void*)obj->disp.vertex4sv, (void*)vertex4sv_replacement, (void**)&vertex4sv_reenter);
			mach_override_ptr((void*)obj->disp.vertex_pointer, (void*)vertex_pointer_replacement, (void**)&vertex_pointer_reenter);
			mach_override_ptr((void*)obj->disp.viewport, (void*)viewport_replacement, (void**)&viewport_reenter);
			mach_override_ptr((void*)obj->disp.blend_func_separate, (void*)blend_func_separate_replacement, (void**)&blend_func_separate_reenter);
			mach_override_ptr((void*)obj->disp.blend_color, (void*)blend_color_replacement, (void**)&blend_color_reenter);
			mach_override_ptr((void*)obj->disp.blend_equation, (void*)blend_equation_replacement, (void**)&blend_equation_reenter);
			mach_override_ptr((void*)obj->disp.lock_arrays_EXT, (void*)lock_arrays_EXT_replacement, (void**)&lock_arrays_EXT_reenter);
			mach_override_ptr((void*)obj->disp.unlock_arrays_EXT, (void*)unlock_arrays_EXT_replacement, (void**)&unlock_arrays_EXT_reenter);
			mach_override_ptr((void*)obj->disp.client_active_texture, (void*)client_active_texture_replacement, (void**)&client_active_texture_reenter);
			mach_override_ptr((void*)obj->disp.active_texture, (void*)active_texture_replacement, (void**)&active_texture_reenter);
			mach_override_ptr((void*)obj->disp.multi_tex_coord1d, (void*)multi_tex_coord1d_replacement, (void**)&multi_tex_coord1d_reenter);
			mach_override_ptr((void*)obj->disp.multi_tex_coord1dv, (void*)multi_tex_coord1dv_replacement, (void**)&multi_tex_coord1dv_reenter);
			mach_override_ptr((void*)obj->disp.multi_tex_coord1f, (void*)multi_tex_coord1f_replacement, (void**)&multi_tex_coord1f_reenter);
			mach_override_ptr((void*)obj->disp.multi_tex_coord1fv, (void*)multi_tex_coord1fv_replacement, (void**)&multi_tex_coord1fv_reenter);
			mach_override_ptr((void*)obj->disp.multi_tex_coord1i, (void*)multi_tex_coord1i_replacement, (void**)&multi_tex_coord1i_reenter);
			mach_override_ptr((void*)obj->disp.multi_tex_coord1iv, (void*)multi_tex_coord1iv_replacement, (void**)&multi_tex_coord1iv_reenter);
			mach_override_ptr((void*)obj->disp.multi_tex_coord1s, (void*)multi_tex_coord1s_replacement, (void**)&multi_tex_coord1s_reenter);
			mach_override_ptr((void*)obj->disp.multi_tex_coord1sv, (void*)multi_tex_coord1sv_replacement, (void**)&multi_tex_coord1sv_reenter);
			mach_override_ptr((void*)obj->disp.multi_tex_coord2d, (void*)multi_tex_coord2d_replacement, (void**)&multi_tex_coord2d_reenter);
			mach_override_ptr((void*)obj->disp.multi_tex_coord2dv, (void*)multi_tex_coord2dv_replacement, (void**)&multi_tex_coord2dv_reenter);
			mach_override_ptr((void*)obj->disp.multi_tex_coord2f, (void*)multi_tex_coord2f_replacement, (void**)&multi_tex_coord2f_reenter);
			mach_override_ptr((void*)obj->disp.multi_tex_coord2fv, (void*)multi_tex_coord2fv_replacement, (void**)&multi_tex_coord2fv_reenter);
			mach_override_ptr((void*)obj->disp.multi_tex_coord2i, (void*)multi_tex_coord2i_replacement, (void**)&multi_tex_coord2i_reenter);
			mach_override_ptr((void*)obj->disp.multi_tex_coord2iv, (void*)multi_tex_coord2iv_replacement, (void**)&multi_tex_coord2iv_reenter);
			mach_override_ptr((void*)obj->disp.multi_tex_coord2s, (void*)multi_tex_coord2s_replacement, (void**)&multi_tex_coord2s_reenter);
			mach_override_ptr((void*)obj->disp.multi_tex_coord2sv, (void*)multi_tex_coord2sv_replacement, (void**)&multi_tex_coord2sv_reenter);
			mach_override_ptr((void*)obj->disp.multi_tex_coord3d, (void*)multi_tex_coord3d_replacement, (void**)&multi_tex_coord3d_reenter);
			mach_override_ptr((void*)obj->disp.multi_tex_coord3dv, (void*)multi_tex_coord3dv_replacement, (void**)&multi_tex_coord3dv_reenter);
			mach_override_ptr((void*)obj->disp.multi_tex_coord3f, (void*)multi_tex_coord3f_replacement, (void**)&multi_tex_coord3f_reenter);
			mach_override_ptr((void*)obj->disp.multi_tex_coord3fv, (void*)multi_tex_coord3fv_replacement, (void**)&multi_tex_coord3fv_reenter);
			mach_override_ptr((void*)obj->disp.multi_tex_coord3i, (void*)multi_tex_coord3i_replacement, (void**)&multi_tex_coord3i_reenter);
			mach_override_ptr((void*)obj->disp.multi_tex_coord3iv, (void*)multi_tex_coord3iv_replacement, (void**)&multi_tex_coord3iv_reenter);
			mach_override_ptr((void*)obj->disp.multi_tex_coord3s, (void*)multi_tex_coord3s_replacement, (void**)&multi_tex_coord3s_reenter);
			mach_override_ptr((void*)obj->disp.multi_tex_coord3sv, (void*)multi_tex_coord3sv_replacement, (void**)&multi_tex_coord3sv_reenter);
			mach_override_ptr((void*)obj->disp.multi_tex_coord4d, (void*)multi_tex_coord4d_replacement, (void**)&multi_tex_coord4d_reenter);
			mach_override_ptr((void*)obj->disp.multi_tex_coord4dv, (void*)multi_tex_coord4dv_replacement, (void**)&multi_tex_coord4dv_reenter);
			mach_override_ptr((void*)obj->disp.multi_tex_coord4f, (void*)multi_tex_coord4f_replacement, (void**)&multi_tex_coord4f_reenter);
			mach_override_ptr((void*)obj->disp.multi_tex_coord4fv, (void*)multi_tex_coord4fv_replacement, (void**)&multi_tex_coord4fv_reenter);
			mach_override_ptr((void*)obj->disp.multi_tex_coord4i, (void*)multi_tex_coord4i_replacement, (void**)&multi_tex_coord4i_reenter);
			mach_override_ptr((void*)obj->disp.multi_tex_coord4iv, (void*)multi_tex_coord4iv_replacement, (void**)&multi_tex_coord4iv_reenter);
			mach_override_ptr((void*)obj->disp.multi_tex_coord4s, (void*)multi_tex_coord4s_replacement, (void**)&multi_tex_coord4s_reenter);
			mach_override_ptr((void*)obj->disp.multi_tex_coord4sv, (void*)multi_tex_coord4sv_replacement, (void**)&multi_tex_coord4sv_reenter);
			mach_override_ptr((void*)obj->disp.load_transpose_matrixd, (void*)load_transpose_matrixd_replacement, (void**)&load_transpose_matrixd_reenter);
			mach_override_ptr((void*)obj->disp.load_transpose_matrixf, (void*)load_transpose_matrixf_replacement, (void**)&load_transpose_matrixf_reenter);
			mach_override_ptr((void*)obj->disp.mult_transpose_matrixd, (void*)mult_transpose_matrixd_replacement, (void**)&mult_transpose_matrixd_reenter);
			mach_override_ptr((void*)obj->disp.mult_transpose_matrixf, (void*)mult_transpose_matrixf_replacement, (void**)&mult_transpose_matrixf_reenter);
			mach_override_ptr((void*)obj->disp.compressed_tex_image3D, (void*)compressed_tex_image3D_replacement, (void**)&compressed_tex_image3D_reenter);
			mach_override_ptr((void*)obj->disp.compressed_tex_image2D, (void*)compressed_tex_image2D_replacement, (void**)&compressed_tex_image2D_reenter);
			mach_override_ptr((void*)obj->disp.compressed_tex_image1D, (void*)compressed_tex_image1D_replacement, (void**)&compressed_tex_image1D_reenter);
			mach_override_ptr((void*)obj->disp.compressed_tex_sub_image3D, (void*)compressed_tex_sub_image3D_replacement, (void**)&compressed_tex_sub_image3D_reenter);
			mach_override_ptr((void*)obj->disp.compressed_tex_sub_image2D, (void*)compressed_tex_sub_image2D_replacement, (void**)&compressed_tex_sub_image2D_reenter);
			mach_override_ptr((void*)obj->disp.compressed_tex_sub_image1D, (void*)compressed_tex_sub_image1D_replacement, (void**)&compressed_tex_sub_image1D_reenter);
			mach_override_ptr((void*)obj->disp.get_compressed_tex_image, (void*)get_compressed_tex_image_replacement, (void**)&get_compressed_tex_image_reenter);
			mach_override_ptr((void*)obj->disp.secondary_color3b, (void*)secondary_color3b_replacement, (void**)&secondary_color3b_reenter);
			mach_override_ptr((void*)obj->disp.secondary_color3bv, (void*)secondary_color3bv_replacement, (void**)&secondary_color3bv_reenter);
			mach_override_ptr((void*)obj->disp.secondary_color3d, (void*)secondary_color3d_replacement, (void**)&secondary_color3d_reenter);
			mach_override_ptr((void*)obj->disp.secondary_color3dv, (void*)secondary_color3dv_replacement, (void**)&secondary_color3dv_reenter);
			mach_override_ptr((void*)obj->disp.secondary_color3f, (void*)secondary_color3f_replacement, (void**)&secondary_color3f_reenter);
			mach_override_ptr((void*)obj->disp.secondary_color3fv, (void*)secondary_color3fv_replacement, (void**)&secondary_color3fv_reenter);
			mach_override_ptr((void*)obj->disp.secondary_color3i, (void*)secondary_color3i_replacement, (void**)&secondary_color3i_reenter);
			mach_override_ptr((void*)obj->disp.secondary_color3iv, (void*)secondary_color3iv_replacement, (void**)&secondary_color3iv_reenter);
			mach_override_ptr((void*)obj->disp.secondary_color3s, (void*)secondary_color3s_replacement, (void**)&secondary_color3s_reenter);
			mach_override_ptr((void*)obj->disp.secondary_color3sv, (void*)secondary_color3sv_replacement, (void**)&secondary_color3sv_reenter);
			mach_override_ptr((void*)obj->disp.secondary_color3ub, (void*)secondary_color3ub_replacement, (void**)&secondary_color3ub_reenter);
			mach_override_ptr((void*)obj->disp.secondary_color3ubv, (void*)secondary_color3ubv_replacement, (void**)&secondary_color3ubv_reenter);
			mach_override_ptr((void*)obj->disp.secondary_color3ui, (void*)secondary_color3ui_replacement, (void**)&secondary_color3ui_reenter);
			mach_override_ptr((void*)obj->disp.secondary_color3uiv, (void*)secondary_color3uiv_replacement, (void**)&secondary_color3uiv_reenter);
			mach_override_ptr((void*)obj->disp.secondary_color3us, (void*)secondary_color3us_replacement, (void**)&secondary_color3us_reenter);
			mach_override_ptr((void*)obj->disp.secondary_color3usv, (void*)secondary_color3usv_replacement, (void**)&secondary_color3usv_reenter);
			mach_override_ptr((void*)obj->disp.secondary_color_pointer, (void*)secondary_color_pointer_replacement, (void**)&secondary_color_pointer_reenter);
			mach_override_ptr((void*)obj->disp.vertex_array_range_EXT, (void*)vertex_array_range_EXT_replacement, (void**)&vertex_array_range_EXT_reenter);
			mach_override_ptr((void*)obj->disp.flush_vertex_array_range_EXT, (void*)flush_vertex_array_range_EXT_replacement, (void**)&flush_vertex_array_range_EXT_reenter);
			mach_override_ptr((void*)obj->disp.draw_range_elements, (void*)draw_range_elements_replacement, (void**)&draw_range_elements_reenter);
			mach_override_ptr((void*)obj->disp.color_table, (void*)color_table_replacement, (void**)&color_table_reenter);
			mach_override_ptr((void*)obj->disp.color_table_parameterfv, (void*)color_table_parameterfv_replacement, (void**)&color_table_parameterfv_reenter);
			mach_override_ptr((void*)obj->disp.color_table_parameteriv, (void*)color_table_parameteriv_replacement, (void**)&color_table_parameteriv_reenter);
			mach_override_ptr((void*)obj->disp.copy_color_table, (void*)copy_color_table_replacement, (void**)&copy_color_table_reenter);
			mach_override_ptr((void*)obj->disp.get_color_table, (void*)get_color_table_replacement, (void**)&get_color_table_reenter);
			mach_override_ptr((void*)obj->disp.get_color_table_parameterfv, (void*)get_color_table_parameterfv_replacement, (void**)&get_color_table_parameterfv_reenter);
			mach_override_ptr((void*)obj->disp.get_color_table_parameteriv, (void*)get_color_table_parameteriv_replacement, (void**)&get_color_table_parameteriv_reenter);
			mach_override_ptr((void*)obj->disp.color_sub_table, (void*)color_sub_table_replacement, (void**)&color_sub_table_reenter);
			mach_override_ptr((void*)obj->disp.copy_color_sub_table, (void*)copy_color_sub_table_replacement, (void**)&copy_color_sub_table_reenter);
			mach_override_ptr((void*)obj->disp.convolution_filter1D, (void*)convolution_filter1D_replacement, (void**)&convolution_filter1D_reenter);
			mach_override_ptr((void*)obj->disp.convolution_filter2D, (void*)convolution_filter2D_replacement, (void**)&convolution_filter2D_reenter);
			mach_override_ptr((void*)obj->disp.convolution_parameterf, (void*)convolution_parameterf_replacement, (void**)&convolution_parameterf_reenter);
			mach_override_ptr((void*)obj->disp.convolution_parameterfv, (void*)convolution_parameterfv_replacement, (void**)&convolution_parameterfv_reenter);
			mach_override_ptr((void*)obj->disp.convolution_parameteri, (void*)convolution_parameteri_replacement, (void**)&convolution_parameteri_reenter);
			mach_override_ptr((void*)obj->disp.convolution_parameteriv, (void*)convolution_parameteriv_replacement, (void**)&convolution_parameteriv_reenter);
			mach_override_ptr((void*)obj->disp.copy_convolution_filter1D, (void*)copy_convolution_filter1D_replacement, (void**)&copy_convolution_filter1D_reenter);
			mach_override_ptr((void*)obj->disp.copy_convolution_filter2D, (void*)copy_convolution_filter2D_replacement, (void**)&copy_convolution_filter2D_reenter);
			mach_override_ptr((void*)obj->disp.get_convolution_filter, (void*)get_convolution_filter_replacement, (void**)&get_convolution_filter_reenter);
			mach_override_ptr((void*)obj->disp.get_convolution_parameterfv, (void*)get_convolution_parameterfv_replacement, (void**)&get_convolution_parameterfv_reenter);
			mach_override_ptr((void*)obj->disp.get_convolution_parameteriv, (void*)get_convolution_parameteriv_replacement, (void**)&get_convolution_parameteriv_reenter);
			mach_override_ptr((void*)obj->disp.get_separable_filter, (void*)get_separable_filter_replacement, (void**)&get_separable_filter_reenter);
			mach_override_ptr((void*)obj->disp.separable_filter2D, (void*)separable_filter2D_replacement, (void**)&separable_filter2D_reenter);
			mach_override_ptr((void*)obj->disp.get_histogram, (void*)get_histogram_replacement, (void**)&get_histogram_reenter);
			mach_override_ptr((void*)obj->disp.get_histogram_parameterfv, (void*)get_histogram_parameterfv_replacement, (void**)&get_histogram_parameterfv_reenter);
			mach_override_ptr((void*)obj->disp.get_histogram_parameteriv, (void*)get_histogram_parameteriv_replacement, (void**)&get_histogram_parameteriv_reenter);
			mach_override_ptr((void*)obj->disp.get_minmax, (void*)get_minmax_replacement, (void**)&get_minmax_reenter);
			mach_override_ptr((void*)obj->disp.get_minmax_parameterfv, (void*)get_minmax_parameterfv_replacement, (void**)&get_minmax_parameterfv_reenter);
			mach_override_ptr((void*)obj->disp.get_minmax_parameteriv, (void*)get_minmax_parameteriv_replacement, (void**)&get_minmax_parameteriv_reenter);
			mach_override_ptr((void*)obj->disp.histogram, (void*)histogram_replacement, (void**)&histogram_reenter);
			mach_override_ptr((void*)obj->disp.minmax, (void*)minmax_replacement, (void**)&minmax_reenter);
			mach_override_ptr((void*)obj->disp.reset_histogram, (void*)reset_histogram_replacement, (void**)&reset_histogram_reenter);
			mach_override_ptr((void*)obj->disp.reset_minmax, (void*)reset_minmax_replacement, (void**)&reset_minmax_reenter);
			mach_override_ptr((void*)obj->disp.tex_image3D, (void*)tex_image3D_replacement, (void**)&tex_image3D_reenter);
			mach_override_ptr((void*)obj->disp.tex_sub_image3D, (void*)tex_sub_image3D_replacement, (void**)&tex_sub_image3D_reenter);
			mach_override_ptr((void*)obj->disp.copy_tex_sub_image3D, (void*)copy_tex_sub_image3D_replacement, (void**)&copy_tex_sub_image3D_reenter);
			mach_override_ptr((void*)obj->disp.get_uniform_indices, (void*)get_uniform_indices_replacement, (void**)&get_uniform_indices_reenter);
			mach_override_ptr((void*)obj->disp.get_active_uniformsiv, (void*)get_active_uniformsiv_replacement, (void**)&get_active_uniformsiv_reenter);
			mach_override_ptr((void*)obj->disp.get_active_uniform_name, (void*)get_active_uniform_name_replacement, (void**)&get_active_uniform_name_reenter);
			mach_override_ptr((void*)obj->disp.get_uniform_block_index, (void*)get_uniform_block_index_replacement, (void**)&get_uniform_block_index_reenter);
			mach_override_ptr((void*)obj->disp.get_active_uniform_blockiv, (void*)get_active_uniform_blockiv_replacement, (void**)&get_active_uniform_blockiv_reenter);
			mach_override_ptr((void*)obj->disp.get_active_uniform_block_name, (void*)get_active_uniform_block_name_replacement, (void**)&get_active_uniform_block_name_reenter);
			mach_override_ptr((void*)obj->disp.uniform_block_binding, (void*)uniform_block_binding_replacement, (void**)&uniform_block_binding_reenter);
			mach_override_ptr((void*)obj->disp.get_combiner_input_parameterfv_NV, (void*)get_combiner_input_parameterfv_NV_replacement, (void**)&get_combiner_input_parameterfv_NV_reenter);
			mach_override_ptr((void*)obj->disp.get_combiner_input_parameteriv_NV, (void*)get_combiner_input_parameteriv_NV_replacement, (void**)&get_combiner_input_parameteriv_NV_reenter);
			mach_override_ptr((void*)obj->disp.get_combiner_output_parameterfv_NV, (void*)get_combiner_output_parameterfv_NV_replacement, (void**)&get_combiner_output_parameterfv_NV_reenter);
			mach_override_ptr((void*)obj->disp.get_combiner_output_parameteriv_NV, (void*)get_combiner_output_parameteriv_NV_replacement, (void**)&get_combiner_output_parameteriv_NV_reenter);
			mach_override_ptr((void*)obj->disp.get_final_combiner_input_parameterfv_NV, (void*)get_final_combiner_input_parameterfv_NV_replacement, (void**)&get_final_combiner_input_parameterfv_NV_reenter);
			mach_override_ptr((void*)obj->disp.get_final_combiner_input_parameteriv_NV, (void*)get_final_combiner_input_parameteriv_NV_replacement, (void**)&get_final_combiner_input_parameteriv_NV_reenter);
			mach_override_ptr((void*)obj->disp.combiner_stage_parameterfv_NV, (void*)combiner_stage_parameterfv_NV_replacement, (void**)&combiner_stage_parameterfv_NV_reenter);
			mach_override_ptr((void*)obj->disp.get_combiner_stage_parameterfv_NV, (void*)get_combiner_stage_parameterfv_NV_replacement, (void**)&get_combiner_stage_parameterfv_NV_reenter);
			mach_override_ptr((void*)obj->disp.texture_range_APPLE, (void*)texture_range_APPLE_replacement, (void**)&texture_range_APPLE_reenter);
			mach_override_ptr((void*)obj->disp.get_tex_parameter_pointerv_APPLE, (void*)get_tex_parameter_pointerv_APPLE_replacement, (void**)&get_tex_parameter_pointerv_APPLE_reenter);
			mach_override_ptr((void*)obj->disp.blend_equation_separate_EXT, (void*)blend_equation_separate_EXT_replacement, (void**)&blend_equation_separate_EXT_reenter);
			mach_override_ptr((void*)obj->disp.sample_coverage, (void*)sample_coverage_replacement, (void**)&sample_coverage_reenter);
			mach_override_ptr((void*)obj->disp.sample_pass, (void*)sample_pass_replacement, (void**)&sample_pass_reenter);
			mach_override_ptr((void*)obj->disp.pn_trianglesi_ATI, (void*)pn_trianglesi_ATI_replacement, (void**)&pn_trianglesi_ATI_reenter);
			mach_override_ptr((void*)obj->disp.pn_trianglesf_ATI, (void*)pn_trianglesf_ATI_replacement, (void**)&pn_trianglesf_ATI_reenter);
			mach_override_ptr((void*)obj->disp.gen_fences_APPLE, (void*)gen_fences_APPLE_replacement, (void**)&gen_fences_APPLE_reenter);
			mach_override_ptr((void*)obj->disp.delete_fences_APPLE, (void*)delete_fences_APPLE_replacement, (void**)&delete_fences_APPLE_reenter);
			mach_override_ptr((void*)obj->disp.set_fence_APPLE, (void*)set_fence_APPLE_replacement, (void**)&set_fence_APPLE_reenter);
			mach_override_ptr((void*)obj->disp.is_fence_APPLE, (void*)is_fence_APPLE_replacement, (void**)&is_fence_APPLE_reenter);
			mach_override_ptr((void*)obj->disp.test_fence_APPLE, (void*)test_fence_APPLE_replacement, (void**)&test_fence_APPLE_reenter);
			mach_override_ptr((void*)obj->disp.finish_fence_APPLE, (void*)finish_fence_APPLE_replacement, (void**)&finish_fence_APPLE_reenter);
			mach_override_ptr((void*)obj->disp.test_object_APPLE, (void*)test_object_APPLE_replacement, (void**)&test_object_APPLE_reenter);
			mach_override_ptr((void*)obj->disp.finish_object_APPLE, (void*)finish_object_APPLE_replacement, (void**)&finish_object_APPLE_reenter);
			mach_override_ptr((void*)obj->disp.bind_program_ARB, (void*)bind_program_ARB_replacement, (void**)&bind_program_ARB_reenter);
			mach_override_ptr((void*)obj->disp.delete_programs_ARB, (void*)delete_programs_ARB_replacement, (void**)&delete_programs_ARB_reenter);
			mach_override_ptr((void*)obj->disp.gen_programs_ARB, (void*)gen_programs_ARB_replacement, (void**)&gen_programs_ARB_reenter);
			mach_override_ptr((void*)obj->disp.is_program_ARB, (void*)is_program_ARB_replacement, (void**)&is_program_ARB_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attrib1s_ARB, (void*)vertex_attrib1s_ARB_replacement, (void**)&vertex_attrib1s_ARB_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attrib1f_ARB, (void*)vertex_attrib1f_ARB_replacement, (void**)&vertex_attrib1f_ARB_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attrib1d_ARB, (void*)vertex_attrib1d_ARB_replacement, (void**)&vertex_attrib1d_ARB_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attrib2s_ARB, (void*)vertex_attrib2s_ARB_replacement, (void**)&vertex_attrib2s_ARB_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attrib2f_ARB, (void*)vertex_attrib2f_ARB_replacement, (void**)&vertex_attrib2f_ARB_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attrib2d_ARB, (void*)vertex_attrib2d_ARB_replacement, (void**)&vertex_attrib2d_ARB_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attrib3s_ARB, (void*)vertex_attrib3s_ARB_replacement, (void**)&vertex_attrib3s_ARB_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attrib3f_ARB, (void*)vertex_attrib3f_ARB_replacement, (void**)&vertex_attrib3f_ARB_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attrib3d_ARB, (void*)vertex_attrib3d_ARB_replacement, (void**)&vertex_attrib3d_ARB_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attrib4s_ARB, (void*)vertex_attrib4s_ARB_replacement, (void**)&vertex_attrib4s_ARB_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attrib4f_ARB, (void*)vertex_attrib4f_ARB_replacement, (void**)&vertex_attrib4f_ARB_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attrib4d_ARB, (void*)vertex_attrib4d_ARB_replacement, (void**)&vertex_attrib4d_ARB_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attrib4Nub_ARB, (void*)vertex_attrib4Nub_ARB_replacement, (void**)&vertex_attrib4Nub_ARB_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attrib1sv_ARB, (void*)vertex_attrib1sv_ARB_replacement, (void**)&vertex_attrib1sv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attrib1fv_ARB, (void*)vertex_attrib1fv_ARB_replacement, (void**)&vertex_attrib1fv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attrib1dv_ARB, (void*)vertex_attrib1dv_ARB_replacement, (void**)&vertex_attrib1dv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attrib2sv_ARB, (void*)vertex_attrib2sv_ARB_replacement, (void**)&vertex_attrib2sv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attrib2fv_ARB, (void*)vertex_attrib2fv_ARB_replacement, (void**)&vertex_attrib2fv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attrib2dv_ARB, (void*)vertex_attrib2dv_ARB_replacement, (void**)&vertex_attrib2dv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attrib3sv_ARB, (void*)vertex_attrib3sv_ARB_replacement, (void**)&vertex_attrib3sv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attrib3fv_ARB, (void*)vertex_attrib3fv_ARB_replacement, (void**)&vertex_attrib3fv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attrib3dv_ARB, (void*)vertex_attrib3dv_ARB_replacement, (void**)&vertex_attrib3dv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attrib4bv_ARB, (void*)vertex_attrib4bv_ARB_replacement, (void**)&vertex_attrib4bv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attrib4sv_ARB, (void*)vertex_attrib4sv_ARB_replacement, (void**)&vertex_attrib4sv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attrib4iv_ARB, (void*)vertex_attrib4iv_ARB_replacement, (void**)&vertex_attrib4iv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attrib4ubv_ARB, (void*)vertex_attrib4ubv_ARB_replacement, (void**)&vertex_attrib4ubv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attrib4usv_ARB, (void*)vertex_attrib4usv_ARB_replacement, (void**)&vertex_attrib4usv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attrib4uiv_ARB, (void*)vertex_attrib4uiv_ARB_replacement, (void**)&vertex_attrib4uiv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attrib4fv_ARB, (void*)vertex_attrib4fv_ARB_replacement, (void**)&vertex_attrib4fv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attrib4dv_ARB, (void*)vertex_attrib4dv_ARB_replacement, (void**)&vertex_attrib4dv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attrib4Nbv_ARB, (void*)vertex_attrib4Nbv_ARB_replacement, (void**)&vertex_attrib4Nbv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attrib4Nsv_ARB, (void*)vertex_attrib4Nsv_ARB_replacement, (void**)&vertex_attrib4Nsv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attrib4Niv_ARB, (void*)vertex_attrib4Niv_ARB_replacement, (void**)&vertex_attrib4Niv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attrib4Nubv_ARB, (void*)vertex_attrib4Nubv_ARB_replacement, (void**)&vertex_attrib4Nubv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attrib4Nusv_ARB, (void*)vertex_attrib4Nusv_ARB_replacement, (void**)&vertex_attrib4Nusv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attrib4Nuiv_ARB, (void*)vertex_attrib4Nuiv_ARB_replacement, (void**)&vertex_attrib4Nuiv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attrib_pointer_ARB, (void*)vertex_attrib_pointer_ARB_replacement, (void**)&vertex_attrib_pointer_ARB_reenter);
			mach_override_ptr((void*)obj->disp.enable_vertex_attrib_array_ARB, (void*)enable_vertex_attrib_array_ARB_replacement, (void**)&enable_vertex_attrib_array_ARB_reenter);
			mach_override_ptr((void*)obj->disp.disable_vertex_attrib_array_ARB, (void*)disable_vertex_attrib_array_ARB_replacement, (void**)&disable_vertex_attrib_array_ARB_reenter);
			mach_override_ptr((void*)obj->disp.get_vertex_attribdv_ARB, (void*)get_vertex_attribdv_ARB_replacement, (void**)&get_vertex_attribdv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.get_vertex_attribfv_ARB, (void*)get_vertex_attribfv_ARB_replacement, (void**)&get_vertex_attribfv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.get_vertex_attribiv_ARB, (void*)get_vertex_attribiv_ARB_replacement, (void**)&get_vertex_attribiv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.get_vertex_attrib_pointerv_ARB, (void*)get_vertex_attrib_pointerv_ARB_replacement, (void**)&get_vertex_attrib_pointerv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.program_env_parameter4d_ARB, (void*)program_env_parameter4d_ARB_replacement, (void**)&program_env_parameter4d_ARB_reenter);
			mach_override_ptr((void*)obj->disp.program_env_parameter4dv_ARB, (void*)program_env_parameter4dv_ARB_replacement, (void**)&program_env_parameter4dv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.program_env_parameter4f_ARB, (void*)program_env_parameter4f_ARB_replacement, (void**)&program_env_parameter4f_ARB_reenter);
			mach_override_ptr((void*)obj->disp.program_env_parameter4fv_ARB, (void*)program_env_parameter4fv_ARB_replacement, (void**)&program_env_parameter4fv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.program_local_parameter4d_ARB, (void*)program_local_parameter4d_ARB_replacement, (void**)&program_local_parameter4d_ARB_reenter);
			mach_override_ptr((void*)obj->disp.program_local_parameter4dv_ARB, (void*)program_local_parameter4dv_ARB_replacement, (void**)&program_local_parameter4dv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.program_local_parameter4f_ARB, (void*)program_local_parameter4f_ARB_replacement, (void**)&program_local_parameter4f_ARB_reenter);
			mach_override_ptr((void*)obj->disp.program_local_parameter4fv_ARB, (void*)program_local_parameter4fv_ARB_replacement, (void**)&program_local_parameter4fv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.get_program_env_parameterdv_ARB, (void*)get_program_env_parameterdv_ARB_replacement, (void**)&get_program_env_parameterdv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.get_program_env_parameterfv_ARB, (void*)get_program_env_parameterfv_ARB_replacement, (void**)&get_program_env_parameterfv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.get_program_local_parameterdv_ARB, (void*)get_program_local_parameterdv_ARB_replacement, (void**)&get_program_local_parameterdv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.get_program_local_parameterfv_ARB, (void*)get_program_local_parameterfv_ARB_replacement, (void**)&get_program_local_parameterfv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.program_string_ARB, (void*)program_string_ARB_replacement, (void**)&program_string_ARB_reenter);
			mach_override_ptr((void*)obj->disp.get_program_string_ARB, (void*)get_program_string_ARB_replacement, (void**)&get_program_string_ARB_reenter);
			mach_override_ptr((void*)obj->disp.get_programiv_ARB, (void*)get_programiv_ARB_replacement, (void**)&get_programiv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.enable_vertex_attrib_ARB, (void*)enable_vertex_attrib_ARB_replacement, (void**)&enable_vertex_attrib_ARB_reenter);
			mach_override_ptr((void*)obj->disp.disable_vertex_attrib_ARB, (void*)disable_vertex_attrib_ARB_replacement, (void**)&disable_vertex_attrib_ARB_reenter);
			mach_override_ptr((void*)obj->disp.is_vertex_attrib_enabled_ARB, (void*)is_vertex_attrib_enabled_ARB_replacement, (void**)&is_vertex_attrib_enabled_ARB_reenter);
			mach_override_ptr((void*)obj->disp.map_vertex_attrib1d_ARB, (void*)map_vertex_attrib1d_ARB_replacement, (void**)&map_vertex_attrib1d_ARB_reenter);
			mach_override_ptr((void*)obj->disp.map_vertex_attrib1f_ARB, (void*)map_vertex_attrib1f_ARB_replacement, (void**)&map_vertex_attrib1f_ARB_reenter);
			mach_override_ptr((void*)obj->disp.map_vertex_attrib2d_ARB, (void*)map_vertex_attrib2d_ARB_replacement, (void**)&map_vertex_attrib2d_ARB_reenter);
			mach_override_ptr((void*)obj->disp.map_vertex_attrib2f_ARB, (void*)map_vertex_attrib2f_ARB_replacement, (void**)&map_vertex_attrib2f_ARB_reenter);
			mach_override_ptr((void*)obj->disp.point_parameterf, (void*)point_parameterf_replacement, (void**)&point_parameterf_reenter);
			mach_override_ptr((void*)obj->disp.point_parameterfv, (void*)point_parameterfv_replacement, (void**)&point_parameterfv_reenter);
			mach_override_ptr((void*)obj->disp.point_parameteri, (void*)point_parameteri_replacement, (void**)&point_parameteri_reenter);
			mach_override_ptr((void*)obj->disp.point_parameteriv, (void*)point_parameteriv_replacement, (void**)&point_parameteriv_reenter);
			mach_override_ptr((void*)obj->disp.fog_coordf, (void*)fog_coordf_replacement, (void**)&fog_coordf_reenter);
			mach_override_ptr((void*)obj->disp.fog_coordfv, (void*)fog_coordfv_replacement, (void**)&fog_coordfv_reenter);
			mach_override_ptr((void*)obj->disp.fog_coordd, (void*)fog_coordd_replacement, (void**)&fog_coordd_reenter);
			mach_override_ptr((void*)obj->disp.fog_coorddv, (void*)fog_coorddv_replacement, (void**)&fog_coorddv_reenter);
			mach_override_ptr((void*)obj->disp.fog_coord_pointer, (void*)fog_coord_pointer_replacement, (void**)&fog_coord_pointer_reenter);
			mach_override_ptr((void*)obj->disp.vertex_array_parameteri_EXT, (void*)vertex_array_parameteri_EXT_replacement, (void**)&vertex_array_parameteri_EXT_reenter);
			mach_override_ptr((void*)obj->disp.bind_vertex_array_EXT, (void*)bind_vertex_array_EXT_replacement, (void**)&bind_vertex_array_EXT_reenter);
			mach_override_ptr((void*)obj->disp.delete_vertex_arrays_EXT, (void*)delete_vertex_arrays_EXT_replacement, (void**)&delete_vertex_arrays_EXT_reenter);
			mach_override_ptr((void*)obj->disp.gen_vertex_arrays_EXT, (void*)gen_vertex_arrays_EXT_replacement, (void**)&gen_vertex_arrays_EXT_reenter);
			mach_override_ptr((void*)obj->disp.is_vertex_array_EXT, (void*)is_vertex_array_EXT_replacement, (void**)&is_vertex_array_EXT_reenter);
			mach_override_ptr((void*)obj->disp.element_pointer_APPLE, (void*)element_pointer_APPLE_replacement, (void**)&element_pointer_APPLE_reenter);
			mach_override_ptr((void*)obj->disp.draw_element_array_APPLE, (void*)draw_element_array_APPLE_replacement, (void**)&draw_element_array_APPLE_reenter);
			mach_override_ptr((void*)obj->disp.draw_range_element_array_APPLE, (void*)draw_range_element_array_APPLE_replacement, (void**)&draw_range_element_array_APPLE_reenter);
			mach_override_ptr((void*)obj->disp.weightbv_ARB, (void*)weightbv_ARB_replacement, (void**)&weightbv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.weightsv_ARB, (void*)weightsv_ARB_replacement, (void**)&weightsv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.weightiv_ARB, (void*)weightiv_ARB_replacement, (void**)&weightiv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.weightfv_ARB, (void*)weightfv_ARB_replacement, (void**)&weightfv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.weightdv_ARB, (void*)weightdv_ARB_replacement, (void**)&weightdv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.weightubv_ARB, (void*)weightubv_ARB_replacement, (void**)&weightubv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.weightusv_ARB, (void*)weightusv_ARB_replacement, (void**)&weightusv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.weightuiv_ARB, (void*)weightuiv_ARB_replacement, (void**)&weightuiv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.weight_pointer_ARB, (void*)weight_pointer_ARB_replacement, (void**)&weight_pointer_ARB_reenter);
			mach_override_ptr((void*)obj->disp.vertex_blend_ARB, (void*)vertex_blend_ARB_replacement, (void**)&vertex_blend_ARB_reenter);
			mach_override_ptr((void*)obj->disp.multi_draw_arrays, (void*)multi_draw_arrays_replacement, (void**)&multi_draw_arrays_reenter);
			mach_override_ptr((void*)obj->disp.multi_draw_elements, (void*)multi_draw_elements_replacement, (void**)&multi_draw_elements_reenter);
			mach_override_ptr((void*)obj->disp.window_pos2d, (void*)window_pos2d_replacement, (void**)&window_pos2d_reenter);
			mach_override_ptr((void*)obj->disp.window_pos2dv, (void*)window_pos2dv_replacement, (void**)&window_pos2dv_reenter);
			mach_override_ptr((void*)obj->disp.window_pos2f, (void*)window_pos2f_replacement, (void**)&window_pos2f_reenter);
			mach_override_ptr((void*)obj->disp.window_pos2fv, (void*)window_pos2fv_replacement, (void**)&window_pos2fv_reenter);
			mach_override_ptr((void*)obj->disp.window_pos2i, (void*)window_pos2i_replacement, (void**)&window_pos2i_reenter);
			mach_override_ptr((void*)obj->disp.window_pos2iv, (void*)window_pos2iv_replacement, (void**)&window_pos2iv_reenter);
			mach_override_ptr((void*)obj->disp.window_pos2s, (void*)window_pos2s_replacement, (void**)&window_pos2s_reenter);
			mach_override_ptr((void*)obj->disp.window_pos2sv, (void*)window_pos2sv_replacement, (void**)&window_pos2sv_reenter);
			mach_override_ptr((void*)obj->disp.window_pos3d, (void*)window_pos3d_replacement, (void**)&window_pos3d_reenter);
			mach_override_ptr((void*)obj->disp.window_pos3dv, (void*)window_pos3dv_replacement, (void**)&window_pos3dv_reenter);
			mach_override_ptr((void*)obj->disp.window_pos3f, (void*)window_pos3f_replacement, (void**)&window_pos3f_reenter);
			mach_override_ptr((void*)obj->disp.window_pos3fv, (void*)window_pos3fv_replacement, (void**)&window_pos3fv_reenter);
			mach_override_ptr((void*)obj->disp.window_pos3i, (void*)window_pos3i_replacement, (void**)&window_pos3i_reenter);
			mach_override_ptr((void*)obj->disp.window_pos3iv, (void*)window_pos3iv_replacement, (void**)&window_pos3iv_reenter);
			mach_override_ptr((void*)obj->disp.window_pos3s, (void*)window_pos3s_replacement, (void**)&window_pos3s_reenter);
			mach_override_ptr((void*)obj->disp.window_pos3sv, (void*)window_pos3sv_replacement, (void**)&window_pos3sv_reenter);
			mach_override_ptr((void*)obj->disp.active_stencil_face_EXT, (void*)active_stencil_face_EXT_replacement, (void**)&active_stencil_face_EXT_reenter);
			mach_override_ptr((void*)obj->disp.stencil_op_separate_ATI, (void*)stencil_op_separate_ATI_replacement, (void**)&stencil_op_separate_ATI_reenter);
			mach_override_ptr((void*)obj->disp.stencil_func_separate_ATI, (void*)stencil_func_separate_ATI_replacement, (void**)&stencil_func_separate_ATI_reenter);
			mach_override_ptr((void*)obj->disp.flush_render_APPLE, (void*)flush_render_APPLE_replacement, (void**)&flush_render_APPLE_reenter);
			mach_override_ptr((void*)obj->disp.finish_render_APPLE, (void*)finish_render_APPLE_replacement, (void**)&finish_render_APPLE_reenter);
			mach_override_ptr((void*)obj->disp.swap_APPLE, (void*)swap_APPLE_replacement, (void**)&swap_APPLE_reenter);
			mach_override_ptr((void*)obj->disp.delete_object_ARB, (void*)delete_object_ARB_replacement, (void**)&delete_object_ARB_reenter);
			mach_override_ptr((void*)obj->disp.get_handle_ARB, (void*)get_handle_ARB_replacement, (void**)&get_handle_ARB_reenter);
			mach_override_ptr((void*)obj->disp.detach_object_ARB, (void*)detach_object_ARB_replacement, (void**)&detach_object_ARB_reenter);
			mach_override_ptr((void*)obj->disp.create_shader_object_ARB, (void*)create_shader_object_ARB_replacement, (void**)&create_shader_object_ARB_reenter);
			mach_override_ptr((void*)obj->disp.shader_source_ARB, (void*)shader_source_ARB_replacement, (void**)&shader_source_ARB_reenter);
			mach_override_ptr((void*)obj->disp.compile_shader_ARB, (void*)compile_shader_ARB_replacement, (void**)&compile_shader_ARB_reenter);
			mach_override_ptr((void*)obj->disp.create_program_object_ARB, (void*)create_program_object_ARB_replacement, (void**)&create_program_object_ARB_reenter);
			mach_override_ptr((void*)obj->disp.attach_object_ARB, (void*)attach_object_ARB_replacement, (void**)&attach_object_ARB_reenter);
			mach_override_ptr((void*)obj->disp.link_program_ARB, (void*)link_program_ARB_replacement, (void**)&link_program_ARB_reenter);
			mach_override_ptr((void*)obj->disp.use_program_object_ARB, (void*)use_program_object_ARB_replacement, (void**)&use_program_object_ARB_reenter);
			mach_override_ptr((void*)obj->disp.validate_program_ARB, (void*)validate_program_ARB_replacement, (void**)&validate_program_ARB_reenter);
			mach_override_ptr((void*)obj->disp.uniform1f_ARB, (void*)uniform1f_ARB_replacement, (void**)&uniform1f_ARB_reenter);
			mach_override_ptr((void*)obj->disp.uniform2f_ARB, (void*)uniform2f_ARB_replacement, (void**)&uniform2f_ARB_reenter);
			mach_override_ptr((void*)obj->disp.uniform3f_ARB, (void*)uniform3f_ARB_replacement, (void**)&uniform3f_ARB_reenter);
			mach_override_ptr((void*)obj->disp.uniform4f_ARB, (void*)uniform4f_ARB_replacement, (void**)&uniform4f_ARB_reenter);
			mach_override_ptr((void*)obj->disp.uniform1i_ARB, (void*)uniform1i_ARB_replacement, (void**)&uniform1i_ARB_reenter);
			mach_override_ptr((void*)obj->disp.uniform2i_ARB, (void*)uniform2i_ARB_replacement, (void**)&uniform2i_ARB_reenter);
			mach_override_ptr((void*)obj->disp.uniform3i_ARB, (void*)uniform3i_ARB_replacement, (void**)&uniform3i_ARB_reenter);
			mach_override_ptr((void*)obj->disp.uniform4i_ARB, (void*)uniform4i_ARB_replacement, (void**)&uniform4i_ARB_reenter);
			mach_override_ptr((void*)obj->disp.uniform1fv_ARB, (void*)uniform1fv_ARB_replacement, (void**)&uniform1fv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.uniform2fv_ARB, (void*)uniform2fv_ARB_replacement, (void**)&uniform2fv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.uniform3fv_ARB, (void*)uniform3fv_ARB_replacement, (void**)&uniform3fv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.uniform4fv_ARB, (void*)uniform4fv_ARB_replacement, (void**)&uniform4fv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.uniform1iv_ARB, (void*)uniform1iv_ARB_replacement, (void**)&uniform1iv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.uniform2iv_ARB, (void*)uniform2iv_ARB_replacement, (void**)&uniform2iv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.uniform3iv_ARB, (void*)uniform3iv_ARB_replacement, (void**)&uniform3iv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.uniform4iv_ARB, (void*)uniform4iv_ARB_replacement, (void**)&uniform4iv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.uniform_matrix2fv_ARB, (void*)uniform_matrix2fv_ARB_replacement, (void**)&uniform_matrix2fv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.uniform_matrix3fv_ARB, (void*)uniform_matrix3fv_ARB_replacement, (void**)&uniform_matrix3fv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.uniform_matrix4fv_ARB, (void*)uniform_matrix4fv_ARB_replacement, (void**)&uniform_matrix4fv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.get_object_parameterfv_ARB, (void*)get_object_parameterfv_ARB_replacement, (void**)&get_object_parameterfv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.get_object_parameteriv_ARB, (void*)get_object_parameteriv_ARB_replacement, (void**)&get_object_parameteriv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.get_info_log_ARB, (void*)get_info_log_ARB_replacement, (void**)&get_info_log_ARB_reenter);
			mach_override_ptr((void*)obj->disp.get_attached_objects_ARB, (void*)get_attached_objects_ARB_replacement, (void**)&get_attached_objects_ARB_reenter);
			mach_override_ptr((void*)obj->disp.get_uniform_location_ARB, (void*)get_uniform_location_ARB_replacement, (void**)&get_uniform_location_ARB_reenter);
			mach_override_ptr((void*)obj->disp.get_active_uniform_ARB, (void*)get_active_uniform_ARB_replacement, (void**)&get_active_uniform_ARB_reenter);
			mach_override_ptr((void*)obj->disp.get_uniformfv_ARB, (void*)get_uniformfv_ARB_replacement, (void**)&get_uniformfv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.get_uniformiv_ARB, (void*)get_uniformiv_ARB_replacement, (void**)&get_uniformiv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.get_shader_source_ARB, (void*)get_shader_source_ARB_replacement, (void**)&get_shader_source_ARB_reenter);
			mach_override_ptr((void*)obj->disp.bind_attrib_location_ARB, (void*)bind_attrib_location_ARB_replacement, (void**)&bind_attrib_location_ARB_reenter);
			mach_override_ptr((void*)obj->disp.get_active_attrib_ARB, (void*)get_active_attrib_ARB_replacement, (void**)&get_active_attrib_ARB_reenter);
			mach_override_ptr((void*)obj->disp.get_attrib_location_ARB, (void*)get_attrib_location_ARB_replacement, (void**)&get_attrib_location_ARB_reenter);
			mach_override_ptr((void*)obj->disp.clamp_color_ARB, (void*)clamp_color_ARB_replacement, (void**)&clamp_color_ARB_reenter);
			mach_override_ptr((void*)obj->disp.gen_queries, (void*)gen_queries_replacement, (void**)&gen_queries_reenter);
			mach_override_ptr((void*)obj->disp.delete_queries, (void*)delete_queries_replacement, (void**)&delete_queries_reenter);
			mach_override_ptr((void*)obj->disp.is_query, (void*)is_query_replacement, (void**)&is_query_reenter);
			mach_override_ptr((void*)obj->disp.begin_query, (void*)begin_query_replacement, (void**)&begin_query_reenter);
			mach_override_ptr((void*)obj->disp.end_query, (void*)end_query_replacement, (void**)&end_query_reenter);
			mach_override_ptr((void*)obj->disp.get_queryiv, (void*)get_queryiv_replacement, (void**)&get_queryiv_reenter);
			mach_override_ptr((void*)obj->disp.get_query_objectiv, (void*)get_query_objectiv_replacement, (void**)&get_query_objectiv_reenter);
			mach_override_ptr((void*)obj->disp.get_query_objectuiv, (void*)get_query_objectuiv_replacement, (void**)&get_query_objectuiv_reenter);
			mach_override_ptr((void*)obj->disp.bind_buffer, (void*)bind_buffer_replacement, (void**)&bind_buffer_reenter);
			mach_override_ptr((void*)obj->disp.delete_buffers, (void*)delete_buffers_replacement, (void**)&delete_buffers_reenter);
			mach_override_ptr((void*)obj->disp.gen_buffers, (void*)gen_buffers_replacement, (void**)&gen_buffers_reenter);
			mach_override_ptr((void*)obj->disp.is_buffer, (void*)is_buffer_replacement, (void**)&is_buffer_reenter);
			mach_override_ptr((void*)obj->disp.buffer_data, (void*)buffer_data_replacement, (void**)&buffer_data_reenter);
			mach_override_ptr((void*)obj->disp.buffer_sub_data, (void*)buffer_sub_data_replacement, (void**)&buffer_sub_data_reenter);
			mach_override_ptr((void*)obj->disp.get_buffer_sub_data, (void*)get_buffer_sub_data_replacement, (void**)&get_buffer_sub_data_reenter);
			mach_override_ptr((void*)obj->disp.*map_buffer, (void*)*map_buffer_replacement, (void**)&*map_buffer_reenter);
			mach_override_ptr((void*)obj->disp.unmap_buffer, (void*)unmap_buffer_replacement, (void**)&unmap_buffer_reenter);
			mach_override_ptr((void*)obj->disp.get_buffer_parameteriv, (void*)get_buffer_parameteriv_replacement, (void**)&get_buffer_parameteriv_reenter);
			mach_override_ptr((void*)obj->disp.get_buffer_pointerv, (void*)get_buffer_pointerv_replacement, (void**)&get_buffer_pointerv_reenter);
			mach_override_ptr((void*)obj->disp.depth_bounds_EXT, (void*)depth_bounds_EXT_replacement, (void**)&depth_bounds_EXT_reenter);
			mach_override_ptr((void*)obj->disp.draw_buffers_ARB, (void*)draw_buffers_ARB_replacement, (void**)&draw_buffers_ARB_reenter);
			mach_override_ptr((void*)obj->disp.is_shader, (void*)is_shader_replacement, (void**)&is_shader_reenter);
			mach_override_ptr((void*)obj->disp.is_program, (void*)is_program_replacement, (void**)&is_program_reenter);
			mach_override_ptr((void*)obj->disp.get_shaderiv, (void*)get_shaderiv_replacement, (void**)&get_shaderiv_reenter);
			mach_override_ptr((void*)obj->disp.get_programiv, (void*)get_programiv_replacement, (void**)&get_programiv_reenter);
			mach_override_ptr((void*)obj->disp.get_shader_info_log, (void*)get_shader_info_log_replacement, (void**)&get_shader_info_log_reenter);
			mach_override_ptr((void*)obj->disp.get_program_info_log, (void*)get_program_info_log_replacement, (void**)&get_program_info_log_reenter);
			mach_override_ptr((void*)obj->disp.stencil_func_separate, (void*)stencil_func_separate_replacement, (void**)&stencil_func_separate_reenter);
			mach_override_ptr((void*)obj->disp.stencil_mask_separate, (void*)stencil_mask_separate_replacement, (void**)&stencil_mask_separate_reenter);
			mach_override_ptr((void*)obj->disp.multi_draw_element_array_APPLE, (void*)multi_draw_element_array_APPLE_replacement, (void**)&multi_draw_element_array_APPLE_reenter);
			mach_override_ptr((void*)obj->disp.multi_draw_range_element_array_APPLE, (void*)multi_draw_range_element_array_APPLE_replacement, (void**)&multi_draw_range_element_array_APPLE_reenter);
			mach_override_ptr((void*)obj->disp.is_renderbuffer_EXT, (void*)is_renderbuffer_EXT_replacement, (void**)&is_renderbuffer_EXT_reenter);
			mach_override_ptr((void*)obj->disp.bind_renderbuffer_EXT, (void*)bind_renderbuffer_EXT_replacement, (void**)&bind_renderbuffer_EXT_reenter);
			mach_override_ptr((void*)obj->disp.delete_renderbuffers_EXT, (void*)delete_renderbuffers_EXT_replacement, (void**)&delete_renderbuffers_EXT_reenter);
			mach_override_ptr((void*)obj->disp.gen_renderbuffers_EXT, (void*)gen_renderbuffers_EXT_replacement, (void**)&gen_renderbuffers_EXT_reenter);
			mach_override_ptr((void*)obj->disp.renderbuffer_storage_EXT, (void*)renderbuffer_storage_EXT_replacement, (void**)&renderbuffer_storage_EXT_reenter);
			mach_override_ptr((void*)obj->disp.get_renderbuffer_parameteriv_EXT, (void*)get_renderbuffer_parameteriv_EXT_replacement, (void**)&get_renderbuffer_parameteriv_EXT_reenter);
			mach_override_ptr((void*)obj->disp.is_framebuffer_EXT, (void*)is_framebuffer_EXT_replacement, (void**)&is_framebuffer_EXT_reenter);
			mach_override_ptr((void*)obj->disp.bind_framebuffer_EXT, (void*)bind_framebuffer_EXT_replacement, (void**)&bind_framebuffer_EXT_reenter);
			mach_override_ptr((void*)obj->disp.delete_framebuffers_EXT, (void*)delete_framebuffers_EXT_replacement, (void**)&delete_framebuffers_EXT_reenter);
			mach_override_ptr((void*)obj->disp.gen_framebuffers_EXT, (void*)gen_framebuffers_EXT_replacement, (void**)&gen_framebuffers_EXT_reenter);
			mach_override_ptr((void*)obj->disp.check_framebuffer_status_EXT, (void*)check_framebuffer_status_EXT_replacement, (void**)&check_framebuffer_status_EXT_reenter);
			mach_override_ptr((void*)obj->disp.framebuffer_texture1D_EXT, (void*)framebuffer_texture1D_EXT_replacement, (void**)&framebuffer_texture1D_EXT_reenter);
			mach_override_ptr((void*)obj->disp.framebuffer_texture2D_EXT, (void*)framebuffer_texture2D_EXT_replacement, (void**)&framebuffer_texture2D_EXT_reenter);
			mach_override_ptr((void*)obj->disp.framebuffer_texture3D_EXT, (void*)framebuffer_texture3D_EXT_replacement, (void**)&framebuffer_texture3D_EXT_reenter);
			mach_override_ptr((void*)obj->disp.framebuffer_renderbuffer_EXT, (void*)framebuffer_renderbuffer_EXT_replacement, (void**)&framebuffer_renderbuffer_EXT_reenter);
			mach_override_ptr((void*)obj->disp.get_framebuffer_attachment_parameteriv_EXT, (void*)get_framebuffer_attachment_parameteriv_EXT_replacement, (void**)&get_framebuffer_attachment_parameteriv_EXT_reenter);
			mach_override_ptr((void*)obj->disp.generate_mipmap_EXT, (void*)generate_mipmap_EXT_replacement, (void**)&generate_mipmap_EXT_reenter);
			mach_override_ptr((void*)obj->disp.buffer_parameteri_APPLE, (void*)buffer_parameteri_APPLE_replacement, (void**)&buffer_parameteri_APPLE_reenter);
			mach_override_ptr((void*)obj->disp.flush_mapped_buffer_range_APPLE, (void*)flush_mapped_buffer_range_APPLE_replacement, (void**)&flush_mapped_buffer_range_APPLE_reenter);
			mach_override_ptr((void*)obj->disp.program_env_parameters4fv_EXT, (void*)program_env_parameters4fv_EXT_replacement, (void**)&program_env_parameters4fv_EXT_reenter);
			mach_override_ptr((void*)obj->disp.program_local_parameters4fv_EXT, (void*)program_local_parameters4fv_EXT_replacement, (void**)&program_local_parameters4fv_EXT_reenter);
			mach_override_ptr((void*)obj->disp.object_purgeable_APPLE, (void*)object_purgeable_APPLE_replacement, (void**)&object_purgeable_APPLE_reenter);
			mach_override_ptr((void*)obj->disp.object_unpurgeable_APPLE, (void*)object_unpurgeable_APPLE_replacement, (void**)&object_unpurgeable_APPLE_reenter);
			mach_override_ptr((void*)obj->disp.(*get_object_parameteriv_APPLE, (void*)(*get_object_parameteriv_APPLE_replacement, (void**)&(*get_object_parameteriv_APPLE_reenter);
			mach_override_ptr((void*)obj->disp.program_parameteri_EXT, (void*)program_parameteri_EXT_replacement, (void**)&program_parameteri_EXT_reenter);
			mach_override_ptr((void*)obj->disp.framebuffer_texture_EXT, (void*)framebuffer_texture_EXT_replacement, (void**)&framebuffer_texture_EXT_reenter);
			mach_override_ptr((void*)obj->disp.framebuffer_texture_layer_EXT, (void*)framebuffer_texture_layer_EXT_replacement, (void**)&framebuffer_texture_layer_EXT_reenter);
			mach_override_ptr((void*)obj->disp.framebuffer_texture_face_EXT, (void*)framebuffer_texture_face_EXT_replacement, (void**)&framebuffer_texture_face_EXT_reenter);
			mach_override_ptr((void*)obj->disp.bind_buffer_range_EXT, (void*)bind_buffer_range_EXT_replacement, (void**)&bind_buffer_range_EXT_reenter);
			mach_override_ptr((void*)obj->disp.bind_buffer_offset_EXT, (void*)bind_buffer_offset_EXT_replacement, (void**)&bind_buffer_offset_EXT_reenter);
			mach_override_ptr((void*)obj->disp.bind_buffer_base_EXT, (void*)bind_buffer_base_EXT_replacement, (void**)&bind_buffer_base_EXT_reenter);
			mach_override_ptr((void*)obj->disp.begin_transform_feedback_EXT, (void*)begin_transform_feedback_EXT_replacement, (void**)&begin_transform_feedback_EXT_reenter);
			mach_override_ptr((void*)obj->disp.end_transform_feedback_EXT, (void*)end_transform_feedback_EXT_replacement, (void**)&end_transform_feedback_EXT_reenter);
			mach_override_ptr((void*)obj->disp.transform_feedback_varyings_EXT, (void*)transform_feedback_varyings_EXT_replacement, (void**)&transform_feedback_varyings_EXT_reenter);
			mach_override_ptr((void*)obj->disp.get_transform_feedback_varying_EXT, (void*)get_transform_feedback_varying_EXT_replacement, (void**)&get_transform_feedback_varying_EXT_reenter);
			mach_override_ptr((void*)obj->disp.get_integer_indexedv_EXT, (void*)get_integer_indexedv_EXT_replacement, (void**)&get_integer_indexedv_EXT_reenter);
			mach_override_ptr((void*)obj->disp.get_boolean_indexedv_EXT, (void*)get_boolean_indexedv_EXT_replacement, (void**)&get_boolean_indexedv_EXT_reenter);
			mach_override_ptr((void*)obj->disp.uniform_buffer_EXT, (void*)uniform_buffer_EXT_replacement, (void**)&uniform_buffer_EXT_reenter);
			mach_override_ptr((void*)obj->disp.get_uniform_buffer_size_EXT, (void*)get_uniform_buffer_size_EXT_replacement, (void**)&get_uniform_buffer_size_EXT_reenter);
			mach_override_ptr((void*)obj->disp.get_uniform_buffer_offset_EXT, (void*)get_uniform_buffer_offset_EXT_replacement, (void**)&get_uniform_buffer_offset_EXT_reenter);
			mach_override_ptr((void*)obj->disp.clear_colorIi_EXT, (void*)clear_colorIi_EXT_replacement, (void**)&clear_colorIi_EXT_reenter);
			mach_override_ptr((void*)obj->disp.clear_colorIui_EXT, (void*)clear_colorIui_EXT_replacement, (void**)&clear_colorIui_EXT_reenter);
			mach_override_ptr((void*)obj->disp.tex_parameterIiv_EXT, (void*)tex_parameterIiv_EXT_replacement, (void**)&tex_parameterIiv_EXT_reenter);
			mach_override_ptr((void*)obj->disp.tex_parameterIuiv_EXT, (void*)tex_parameterIuiv_EXT_replacement, (void**)&tex_parameterIuiv_EXT_reenter);
			mach_override_ptr((void*)obj->disp.get_tex_parameterIiv_EXT, (void*)get_tex_parameterIiv_EXT_replacement, (void**)&get_tex_parameterIiv_EXT_reenter);
			mach_override_ptr((void*)obj->disp.get_tex_parameterIuiv_EXT, (void*)get_tex_parameterIuiv_EXT_replacement, (void**)&get_tex_parameterIuiv_EXT_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attribI1i_EXT, (void*)vertex_attribI1i_EXT_replacement, (void**)&vertex_attribI1i_EXT_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attribI2i_EXT, (void*)vertex_attribI2i_EXT_replacement, (void**)&vertex_attribI2i_EXT_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attribI3i_EXT, (void*)vertex_attribI3i_EXT_replacement, (void**)&vertex_attribI3i_EXT_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attribI4i_EXT, (void*)vertex_attribI4i_EXT_replacement, (void**)&vertex_attribI4i_EXT_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attribI1ui_EXT, (void*)vertex_attribI1ui_EXT_replacement, (void**)&vertex_attribI1ui_EXT_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attribI2ui_EXT, (void*)vertex_attribI2ui_EXT_replacement, (void**)&vertex_attribI2ui_EXT_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attribI3ui_EXT, (void*)vertex_attribI3ui_EXT_replacement, (void**)&vertex_attribI3ui_EXT_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attribI4ui_EXT, (void*)vertex_attribI4ui_EXT_replacement, (void**)&vertex_attribI4ui_EXT_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attribI1iv_EXT, (void*)vertex_attribI1iv_EXT_replacement, (void**)&vertex_attribI1iv_EXT_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attribI2iv_EXT, (void*)vertex_attribI2iv_EXT_replacement, (void**)&vertex_attribI2iv_EXT_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attribI3iv_EXT, (void*)vertex_attribI3iv_EXT_replacement, (void**)&vertex_attribI3iv_EXT_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attribI4iv_EXT, (void*)vertex_attribI4iv_EXT_replacement, (void**)&vertex_attribI4iv_EXT_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attribI1uiv_EXT, (void*)vertex_attribI1uiv_EXT_replacement, (void**)&vertex_attribI1uiv_EXT_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attribI2uiv_EXT, (void*)vertex_attribI2uiv_EXT_replacement, (void**)&vertex_attribI2uiv_EXT_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attribI3uiv_EXT, (void*)vertex_attribI3uiv_EXT_replacement, (void**)&vertex_attribI3uiv_EXT_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attribI4uiv_EXT, (void*)vertex_attribI4uiv_EXT_replacement, (void**)&vertex_attribI4uiv_EXT_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attribI4bv_EXT, (void*)vertex_attribI4bv_EXT_replacement, (void**)&vertex_attribI4bv_EXT_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attribI4sv_EXT, (void*)vertex_attribI4sv_EXT_replacement, (void**)&vertex_attribI4sv_EXT_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attribI4ubv_EXT, (void*)vertex_attribI4ubv_EXT_replacement, (void**)&vertex_attribI4ubv_EXT_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attribI4usv_EXT, (void*)vertex_attribI4usv_EXT_replacement, (void**)&vertex_attribI4usv_EXT_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attribI_pointer_EXT, (void*)vertex_attribI_pointer_EXT_replacement, (void**)&vertex_attribI_pointer_EXT_reenter);
			mach_override_ptr((void*)obj->disp.get_vertex_attribIiv_EXT, (void*)get_vertex_attribIiv_EXT_replacement, (void**)&get_vertex_attribIiv_EXT_reenter);
			mach_override_ptr((void*)obj->disp.get_vertex_attribIuiv_EXT, (void*)get_vertex_attribIuiv_EXT_replacement, (void**)&get_vertex_attribIuiv_EXT_reenter);
			mach_override_ptr((void*)obj->disp.uniform1ui_EXT, (void*)uniform1ui_EXT_replacement, (void**)&uniform1ui_EXT_reenter);
			mach_override_ptr((void*)obj->disp.uniform2ui_EXT, (void*)uniform2ui_EXT_replacement, (void**)&uniform2ui_EXT_reenter);
			mach_override_ptr((void*)obj->disp.uniform3ui_EXT, (void*)uniform3ui_EXT_replacement, (void**)&uniform3ui_EXT_reenter);
			mach_override_ptr((void*)obj->disp.uniform4ui_EXT, (void*)uniform4ui_EXT_replacement, (void**)&uniform4ui_EXT_reenter);
			mach_override_ptr((void*)obj->disp.uniform1uiv_EXT, (void*)uniform1uiv_EXT_replacement, (void**)&uniform1uiv_EXT_reenter);
			mach_override_ptr((void*)obj->disp.uniform2uiv_EXT, (void*)uniform2uiv_EXT_replacement, (void**)&uniform2uiv_EXT_reenter);
			mach_override_ptr((void*)obj->disp.uniform3uiv_EXT, (void*)uniform3uiv_EXT_replacement, (void**)&uniform3uiv_EXT_reenter);
			mach_override_ptr((void*)obj->disp.uniform4uiv_EXT, (void*)uniform4uiv_EXT_replacement, (void**)&uniform4uiv_EXT_reenter);
			mach_override_ptr((void*)obj->disp.get_uniformuiv_EXT, (void*)get_uniformuiv_EXT_replacement, (void**)&get_uniformuiv_EXT_reenter);
			mach_override_ptr((void*)obj->disp.bind_frag_data_location_EXT, (void*)bind_frag_data_location_EXT_replacement, (void**)&bind_frag_data_location_EXT_reenter);
			mach_override_ptr((void*)obj->disp.get_frag_data_location_EXT, (void*)get_frag_data_location_EXT_replacement, (void**)&get_frag_data_location_EXT_reenter);
			mach_override_ptr((void*)obj->disp.color_mask_indexed_EXT, (void*)color_mask_indexed_EXT_replacement, (void**)&color_mask_indexed_EXT_reenter);
			mach_override_ptr((void*)obj->disp.enable_indexed_EXT, (void*)enable_indexed_EXT_replacement, (void**)&enable_indexed_EXT_reenter);
			mach_override_ptr((void*)obj->disp.disable_indexed_EXT, (void*)disable_indexed_EXT_replacement, (void**)&disable_indexed_EXT_reenter);
			mach_override_ptr((void*)obj->disp.is_enabled_indexed_EXT, (void*)is_enabled_indexed_EXT_replacement, (void**)&is_enabled_indexed_EXT_reenter);
			mach_override_ptr((void*)obj->disp.uniform_matrix2x3fv, (void*)uniform_matrix2x3fv_replacement, (void**)&uniform_matrix2x3fv_reenter);
			mach_override_ptr((void*)obj->disp.uniform_matrix3x2fv, (void*)uniform_matrix3x2fv_replacement, (void**)&uniform_matrix3x2fv_reenter);
			mach_override_ptr((void*)obj->disp.uniform_matrix2x4fv, (void*)uniform_matrix2x4fv_replacement, (void**)&uniform_matrix2x4fv_reenter);
			mach_override_ptr((void*)obj->disp.uniform_matrix4x2fv, (void*)uniform_matrix4x2fv_replacement, (void**)&uniform_matrix4x2fv_reenter);
			mach_override_ptr((void*)obj->disp.uniform_matrix3x4fv, (void*)uniform_matrix3x4fv_replacement, (void**)&uniform_matrix3x4fv_reenter);
			mach_override_ptr((void*)obj->disp.uniform_matrix4x3fv, (void*)uniform_matrix4x3fv_replacement, (void**)&uniform_matrix4x3fv_reenter);
			mach_override_ptr((void*)obj->disp.blit_framebuffer_EXT, (void*)blit_framebuffer_EXT_replacement, (void**)&blit_framebuffer_EXT_reenter);
			mach_override_ptr((void*)obj->disp.renderbuffer_storage_multisample_EXT, (void*)renderbuffer_storage_multisample_EXT_replacement, (void**)&renderbuffer_storage_multisample_EXT_reenter);
			mach_override_ptr((void*)obj->disp.begin_conditional_render_NV, (void*)begin_conditional_render_NV_replacement, (void**)&begin_conditional_render_NV_reenter);
			mach_override_ptr((void*)obj->disp.end_conditional_render_NV, (void*)end_conditional_render_NV_replacement, (void**)&end_conditional_render_NV_reenter);
			mach_override_ptr((void*)obj->disp.get_attached_shaders, (void*)get_attached_shaders_replacement, (void**)&get_attached_shaders_reenter);
			mach_override_ptr((void*)obj->disp.provoking_vertex_EXT, (void*)provoking_vertex_EXT_replacement, (void**)&provoking_vertex_EXT_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attrib_divisor, (void*)vertex_attrib_divisor_replacement, (void**)&vertex_attrib_divisor_reenter);
			mach_override_ptr((void*)obj->disp.draw_arrays_instanced, (void*)draw_arrays_instanced_replacement, (void**)&draw_arrays_instanced_reenter);
			mach_override_ptr((void*)obj->disp.draw_elements_instanced, (void*)draw_elements_instanced_replacement, (void**)&draw_elements_instanced_reenter);
			mach_override_ptr((void*)obj->disp.draw_elements_base_vertex, (void*)draw_elements_base_vertex_replacement, (void**)&draw_elements_base_vertex_reenter);
			mach_override_ptr((void*)obj->disp.draw_range_elements_base_vertex, (void*)draw_range_elements_base_vertex_replacement, (void**)&draw_range_elements_base_vertex_reenter);
			mach_override_ptr((void*)obj->disp.draw_elements_instanced_base_vertex, (void*)draw_elements_instanced_base_vertex_replacement, (void**)&draw_elements_instanced_base_vertex_reenter);
			mach_override_ptr((void*)obj->disp.multi_draw_elements_base_vertex, (void*)multi_draw_elements_base_vertex_replacement, (void**)&multi_draw_elements_base_vertex_reenter);
			mach_override_ptr((void*)obj->disp.bind_vertex_array_ARB, (void*)bind_vertex_array_ARB_replacement, (void**)&bind_vertex_array_ARB_reenter);
			mach_override_ptr((void*)obj->disp.delete_vertex_arrays_ARB, (void*)delete_vertex_arrays_ARB_replacement, (void**)&delete_vertex_arrays_ARB_reenter);
			mach_override_ptr((void*)obj->disp.gen_vertex_arrays_ARB, (void*)gen_vertex_arrays_ARB_replacement, (void**)&gen_vertex_arrays_ARB_reenter);
			mach_override_ptr((void*)obj->disp.is_vertex_array_ARB, (void*)is_vertex_array_ARB_replacement, (void**)&is_vertex_array_ARB_reenter);
			mach_override_ptr((void*)obj->disp.point_size_pointer, (void*)point_size_pointer_replacement, (void**)&point_size_pointer_reenter);
			mach_override_ptr((void*)obj->disp.vertex_point_sizef_APPLE, (void*)vertex_point_sizef_APPLE_replacement, (void**)&vertex_point_sizef_APPLE_reenter);
			mach_override_ptr((void*)obj->disp.clear_bufferiv, (void*)clear_bufferiv_replacement, (void**)&clear_bufferiv_reenter);
			mach_override_ptr((void*)obj->disp.clear_bufferuiv, (void*)clear_bufferuiv_replacement, (void**)&clear_bufferuiv_reenter);
			mach_override_ptr((void*)obj->disp.clear_bufferfv, (void*)clear_bufferfv_replacement, (void**)&clear_bufferfv_reenter);
			mach_override_ptr((void*)obj->disp.clear_bufferfi, (void*)clear_bufferfi_replacement, (void**)&clear_bufferfi_reenter);
			mach_override_ptr((void*)obj->disp.fence_sync, (void*)fence_sync_replacement, (void**)&fence_sync_reenter);
			mach_override_ptr((void*)obj->disp.is_sync, (void*)is_sync_replacement, (void**)&is_sync_reenter);
			mach_override_ptr((void*)obj->disp.delete_sync, (void*)delete_sync_replacement, (void**)&delete_sync_reenter);
			mach_override_ptr((void*)obj->disp.client_wait_sync, (void*)client_wait_sync_replacement, (void**)&client_wait_sync_reenter);
			mach_override_ptr((void*)obj->disp.wait_sync, (void*)wait_sync_replacement, (void**)&wait_sync_reenter);
			mach_override_ptr((void*)obj->disp.get_integer64v_sync, (void*)get_integer64v_sync_replacement, (void**)&get_integer64v_sync_reenter);
			mach_override_ptr((void*)obj->disp.get_synciv, (void*)get_synciv_replacement, (void**)&get_synciv_reenter);
			mach_override_ptr((void*)obj->disp.tex_image2D_multisample, (void*)tex_image2D_multisample_replacement, (void**)&tex_image2D_multisample_reenter);
			mach_override_ptr((void*)obj->disp.tex_image3D_multisample, (void*)tex_image3D_multisample_replacement, (void**)&tex_image3D_multisample_reenter);
			mach_override_ptr((void*)obj->disp.get_multisamplefv, (void*)get_multisamplefv_replacement, (void**)&get_multisamplefv_reenter);
			mach_override_ptr((void*)obj->disp.sample_maski, (void*)sample_maski_replacement, (void**)&sample_maski_reenter);
			mach_override_ptr((void*)obj->disp.tex_buffer, (void*)tex_buffer_replacement, (void**)&tex_buffer_reenter);
			mach_override_ptr((void*)obj->disp.copy_buffer_sub_data, (void*)copy_buffer_sub_data_replacement, (void**)&copy_buffer_sub_data_reenter);
			mach_override_ptr((void*)obj->disp.primitive_restart_index, (void*)primitive_restart_index_replacement, (void**)&primitive_restart_index_reenter);
			mach_override_ptr((void*)obj->disp.get_query_objecti64v, (void*)get_query_objecti64v_replacement, (void**)&get_query_objecti64v_reenter);
			mach_override_ptr((void*)obj->disp.get_query_objectui64v, (void*)get_query_objectui64v_replacement, (void**)&get_query_objectui64v_reenter);
			mach_override_ptr((void*)obj->disp.*map_buffer_range, (void*)*map_buffer_range_replacement, (void**)&*map_buffer_range_reenter);
			mach_override_ptr((void*)obj->disp.flush_mapped_buffer_range, (void*)flush_mapped_buffer_range_replacement, (void**)&flush_mapped_buffer_range_reenter);
			mach_override_ptr((void*)obj->disp.query_counter, (void*)query_counter_replacement, (void**)&query_counter_reenter);
			mach_override_ptr((void*)obj->disp.get_integer64i_v, (void*)get_integer64i_v_replacement, (void**)&get_integer64i_v_reenter);
			mach_override_ptr((void*)obj->disp.get_buffer_parameteri64v, (void*)get_buffer_parameteri64v_replacement, (void**)&get_buffer_parameteri64v_reenter);
			mach_override_ptr((void*)obj->disp.gen_samplers, (void*)gen_samplers_replacement, (void**)&gen_samplers_reenter);
			mach_override_ptr((void*)obj->disp.delete_samplers, (void*)delete_samplers_replacement, (void**)&delete_samplers_reenter);
			mach_override_ptr((void*)obj->disp.is_sampler, (void*)is_sampler_replacement, (void**)&is_sampler_reenter);
			mach_override_ptr((void*)obj->disp.bind_sampler, (void*)bind_sampler_replacement, (void**)&bind_sampler_reenter);
			mach_override_ptr((void*)obj->disp.sampler_parameteri, (void*)sampler_parameteri_replacement, (void**)&sampler_parameteri_reenter);
			mach_override_ptr((void*)obj->disp.sampler_parameteriv, (void*)sampler_parameteriv_replacement, (void**)&sampler_parameteriv_reenter);
			mach_override_ptr((void*)obj->disp.sampler_parameterf, (void*)sampler_parameterf_replacement, (void**)&sampler_parameterf_reenter);
			mach_override_ptr((void*)obj->disp.sampler_parameterfv, (void*)sampler_parameterfv_replacement, (void**)&sampler_parameterfv_reenter);
			mach_override_ptr((void*)obj->disp.sampler_parameterIiv, (void*)sampler_parameterIiv_replacement, (void**)&sampler_parameterIiv_reenter);
			mach_override_ptr((void*)obj->disp.sampler_parameterIuiv, (void*)sampler_parameterIuiv_replacement, (void**)&sampler_parameterIuiv_reenter);
			mach_override_ptr((void*)obj->disp.get_sampler_parameteriv, (void*)get_sampler_parameteriv_replacement, (void**)&get_sampler_parameteriv_reenter);
			mach_override_ptr((void*)obj->disp.get_sampler_parameterfv, (void*)get_sampler_parameterfv_replacement, (void**)&get_sampler_parameterfv_reenter);
			mach_override_ptr((void*)obj->disp.get_sampler_parameterIiv, (void*)get_sampler_parameterIiv_replacement, (void**)&get_sampler_parameterIiv_reenter);
			mach_override_ptr((void*)obj->disp.get_sampler_parameterIuiv, (void*)get_sampler_parameterIuiv_replacement, (void**)&get_sampler_parameterIuiv_reenter);
			mach_override_ptr((void*)obj->disp.label_object_EXT, (void*)label_object_EXT_replacement, (void**)&label_object_EXT_reenter);
			mach_override_ptr((void*)obj->disp.get_object_label_EXT, (void*)get_object_label_EXT_replacement, (void**)&get_object_label_EXT_reenter);
			mach_override_ptr((void*)obj->disp.insert_event_marker_EXT, (void*)insert_event_marker_EXT_replacement, (void**)&insert_event_marker_EXT_reenter);
			mach_override_ptr((void*)obj->disp.push_group_marker_EXT, (void*)push_group_marker_EXT_replacement, (void**)&push_group_marker_EXT_reenter);
			mach_override_ptr((void*)obj->disp.pop_group_marker_EXT, (void*)pop_group_marker_EXT_replacement, (void**)&pop_group_marker_EXT_reenter);
			mach_override_ptr((void*)obj->disp.use_program_stages, (void*)use_program_stages_replacement, (void**)&use_program_stages_reenter);
			mach_override_ptr((void*)obj->disp.active_shader_program, (void*)active_shader_program_replacement, (void**)&active_shader_program_reenter);
			mach_override_ptr((void*)obj->disp.create_shader_programv, (void*)create_shader_programv_replacement, (void**)&create_shader_programv_reenter);
			mach_override_ptr((void*)obj->disp.bind_program_pipeline, (void*)bind_program_pipeline_replacement, (void**)&bind_program_pipeline_reenter);
			mach_override_ptr((void*)obj->disp.delete_program_pipelines, (void*)delete_program_pipelines_replacement, (void**)&delete_program_pipelines_reenter);
			mach_override_ptr((void*)obj->disp.gen_program_pipelines, (void*)gen_program_pipelines_replacement, (void**)&gen_program_pipelines_reenter);
			mach_override_ptr((void*)obj->disp.is_program_pipeline, (void*)is_program_pipeline_replacement, (void**)&is_program_pipeline_reenter);
			mach_override_ptr((void*)obj->disp.get_program_pipelineiv, (void*)get_program_pipelineiv_replacement, (void**)&get_program_pipelineiv_reenter);
			mach_override_ptr((void*)obj->disp.validate_program_pipeline, (void*)validate_program_pipeline_replacement, (void**)&validate_program_pipeline_reenter);
			mach_override_ptr((void*)obj->disp.get_program_pipeline_info_log, (void*)get_program_pipeline_info_log_replacement, (void**)&get_program_pipeline_info_log_reenter);
			mach_override_ptr((void*)obj->disp.program_uniform1i, (void*)program_uniform1i_replacement, (void**)&program_uniform1i_reenter);
			mach_override_ptr((void*)obj->disp.program_uniform2i, (void*)program_uniform2i_replacement, (void**)&program_uniform2i_reenter);
			mach_override_ptr((void*)obj->disp.program_uniform3i, (void*)program_uniform3i_replacement, (void**)&program_uniform3i_reenter);
			mach_override_ptr((void*)obj->disp.program_uniform4i, (void*)program_uniform4i_replacement, (void**)&program_uniform4i_reenter);
			mach_override_ptr((void*)obj->disp.program_uniform1f, (void*)program_uniform1f_replacement, (void**)&program_uniform1f_reenter);
			mach_override_ptr((void*)obj->disp.program_uniform2f, (void*)program_uniform2f_replacement, (void**)&program_uniform2f_reenter);
			mach_override_ptr((void*)obj->disp.program_uniform3f, (void*)program_uniform3f_replacement, (void**)&program_uniform3f_reenter);
			mach_override_ptr((void*)obj->disp.program_uniform4f, (void*)program_uniform4f_replacement, (void**)&program_uniform4f_reenter);
			mach_override_ptr((void*)obj->disp.program_uniform1iv, (void*)program_uniform1iv_replacement, (void**)&program_uniform1iv_reenter);
			mach_override_ptr((void*)obj->disp.program_uniform2iv, (void*)program_uniform2iv_replacement, (void**)&program_uniform2iv_reenter);
			mach_override_ptr((void*)obj->disp.program_uniform3iv, (void*)program_uniform3iv_replacement, (void**)&program_uniform3iv_reenter);
			mach_override_ptr((void*)obj->disp.program_uniform4iv, (void*)program_uniform4iv_replacement, (void**)&program_uniform4iv_reenter);
			mach_override_ptr((void*)obj->disp.program_uniform1fv, (void*)program_uniform1fv_replacement, (void**)&program_uniform1fv_reenter);
			mach_override_ptr((void*)obj->disp.program_uniform2fv, (void*)program_uniform2fv_replacement, (void**)&program_uniform2fv_reenter);
			mach_override_ptr((void*)obj->disp.program_uniform3fv, (void*)program_uniform3fv_replacement, (void**)&program_uniform3fv_reenter);
			mach_override_ptr((void*)obj->disp.program_uniform4fv, (void*)program_uniform4fv_replacement, (void**)&program_uniform4fv_reenter);
			mach_override_ptr((void*)obj->disp.program_uniform_matrix2fv, (void*)program_uniform_matrix2fv_replacement, (void**)&program_uniform_matrix2fv_reenter);
			mach_override_ptr((void*)obj->disp.program_uniform_matrix3fv, (void*)program_uniform_matrix3fv_replacement, (void**)&program_uniform_matrix3fv_reenter);
			mach_override_ptr((void*)obj->disp.program_uniform_matrix4fv, (void*)program_uniform_matrix4fv_replacement, (void**)&program_uniform_matrix4fv_reenter);
			mach_override_ptr((void*)obj->disp.program_uniform1ui, (void*)program_uniform1ui_replacement, (void**)&program_uniform1ui_reenter);
			mach_override_ptr((void*)obj->disp.program_uniform2ui, (void*)program_uniform2ui_replacement, (void**)&program_uniform2ui_reenter);
			mach_override_ptr((void*)obj->disp.program_uniform3ui, (void*)program_uniform3ui_replacement, (void**)&program_uniform3ui_reenter);
			mach_override_ptr((void*)obj->disp.program_uniform4ui, (void*)program_uniform4ui_replacement, (void**)&program_uniform4ui_reenter);
			mach_override_ptr((void*)obj->disp.program_uniform1uiv, (void*)program_uniform1uiv_replacement, (void**)&program_uniform1uiv_reenter);
			mach_override_ptr((void*)obj->disp.program_uniform2uiv, (void*)program_uniform2uiv_replacement, (void**)&program_uniform2uiv_reenter);
			mach_override_ptr((void*)obj->disp.program_uniform3uiv, (void*)program_uniform3uiv_replacement, (void**)&program_uniform3uiv_reenter);
			mach_override_ptr((void*)obj->disp.program_uniform4uiv, (void*)program_uniform4uiv_replacement, (void**)&program_uniform4uiv_reenter);
			mach_override_ptr((void*)obj->disp.program_uniform_matrix2x3fv, (void*)program_uniform_matrix2x3fv_replacement, (void**)&program_uniform_matrix2x3fv_reenter);
			mach_override_ptr((void*)obj->disp.program_uniform_matrix3x2fv, (void*)program_uniform_matrix3x2fv_replacement, (void**)&program_uniform_matrix3x2fv_reenter);
			mach_override_ptr((void*)obj->disp.program_uniform_matrix2x4fv, (void*)program_uniform_matrix2x4fv_replacement, (void**)&program_uniform_matrix2x4fv_reenter);
			mach_override_ptr((void*)obj->disp.program_uniform_matrix4x2fv, (void*)program_uniform_matrix4x2fv_replacement, (void**)&program_uniform_matrix4x2fv_reenter);
			mach_override_ptr((void*)obj->disp.program_uniform_matrix3x4fv, (void*)program_uniform_matrix3x4fv_replacement, (void**)&program_uniform_matrix3x4fv_reenter);
			mach_override_ptr((void*)obj->disp.program_uniform_matrix4x3fv, (void*)program_uniform_matrix4x3fv_replacement, (void**)&program_uniform_matrix4x3fv_reenter);
			mach_override_ptr((void*)obj->disp.bind_frag_data_location_indexed, (void*)bind_frag_data_location_indexed_replacement, (void**)&bind_frag_data_location_indexed_reenter);
			mach_override_ptr((void*)obj->disp.get_frag_data_index, (void*)get_frag_data_index_replacement, (void**)&get_frag_data_index_reenter);
			mach_override_ptr((void*)obj->disp.blend_func_i, (void*)blend_func_i_replacement, (void**)&blend_func_i_reenter);
			mach_override_ptr((void*)obj->disp.blend_func_separate_i, (void*)blend_func_separate_i_replacement, (void**)&blend_func_separate_i_reenter);
			mach_override_ptr((void*)obj->disp.blend_equation_i, (void*)blend_equation_i_replacement, (void**)&blend_equation_i_reenter);
			mach_override_ptr((void*)obj->disp.blend_equation_separate_i, (void*)blend_equation_separate_i_replacement, (void**)&blend_equation_separate_i_reenter);
			mach_override_ptr((void*)obj->disp.named_string_ARB, (void*)named_string_ARB_replacement, (void**)&named_string_ARB_reenter);
			mach_override_ptr((void*)obj->disp.delete_named_string_ARB, (void*)delete_named_string_ARB_replacement, (void**)&delete_named_string_ARB_reenter);
			mach_override_ptr((void*)obj->disp.compile_shader_include_ARB, (void*)compile_shader_include_ARB_replacement, (void**)&compile_shader_include_ARB_reenter);
			mach_override_ptr((void*)obj->disp.is_named_string_ARB, (void*)is_named_string_ARB_replacement, (void**)&is_named_string_ARB_reenter);
			mach_override_ptr((void*)obj->disp.get_named_string_ARB, (void*)get_named_string_ARB_replacement, (void**)&get_named_string_ARB_reenter);
			mach_override_ptr((void*)obj->disp.get_named_string_iv_ARB, (void*)get_named_string_iv_ARB_replacement, (void**)&get_named_string_iv_ARB_reenter);
			mach_override_ptr((void*)obj->disp.release_shader_compiler, (void*)release_shader_compiler_replacement, (void**)&release_shader_compiler_reenter);
			mach_override_ptr((void*)obj->disp.shader_binary, (void*)shader_binary_replacement, (void**)&shader_binary_reenter);
			mach_override_ptr((void*)obj->disp.get_shader_precision_format, (void*)get_shader_precision_format_replacement, (void**)&get_shader_precision_format_reenter);
			mach_override_ptr((void*)obj->disp.depth_rangef, (void*)depth_rangef_replacement, (void**)&depth_rangef_reenter);
			mach_override_ptr((void*)obj->disp.clear_depthf, (void*)clear_depthf_replacement, (void**)&clear_depthf_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attribP1ui, (void*)vertex_attribP1ui_replacement, (void**)&vertex_attribP1ui_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attribP2ui, (void*)vertex_attribP2ui_replacement, (void**)&vertex_attribP2ui_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attribP3ui, (void*)vertex_attribP3ui_replacement, (void**)&vertex_attribP3ui_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attribP4ui, (void*)vertex_attribP4ui_replacement, (void**)&vertex_attribP4ui_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attribP1uiv, (void*)vertex_attribP1uiv_replacement, (void**)&vertex_attribP1uiv_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attribP2uiv, (void*)vertex_attribP2uiv_replacement, (void**)&vertex_attribP2uiv_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attribP3uiv, (void*)vertex_attribP3uiv_replacement, (void**)&vertex_attribP3uiv_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attribP4uiv, (void*)vertex_attribP4uiv_replacement, (void**)&vertex_attribP4uiv_reenter);
			mach_override_ptr((void*)obj->disp.get_program_binary, (void*)get_program_binary_replacement, (void**)&get_program_binary_reenter);
			mach_override_ptr((void*)obj->disp.program_binary, (void*)program_binary_replacement, (void**)&program_binary_reenter);
			mach_override_ptr((void*)obj->disp.min_sample_shading, (void*)min_sample_shading_replacement, (void**)&min_sample_shading_reenter);
			mach_override_ptr((void*)obj->disp.viewport_arrayv, (void*)viewport_arrayv_replacement, (void**)&viewport_arrayv_reenter);
			mach_override_ptr((void*)obj->disp.viewport_indexedf, (void*)viewport_indexedf_replacement, (void**)&viewport_indexedf_reenter);
			mach_override_ptr((void*)obj->disp.viewport_indexedfv, (void*)viewport_indexedfv_replacement, (void**)&viewport_indexedfv_reenter);
			mach_override_ptr((void*)obj->disp.scissor_arrayv, (void*)scissor_arrayv_replacement, (void**)&scissor_arrayv_reenter);
			mach_override_ptr((void*)obj->disp.scissor_indexed, (void*)scissor_indexed_replacement, (void**)&scissor_indexed_reenter);
			mach_override_ptr((void*)obj->disp.scissor_indexedv, (void*)scissor_indexedv_replacement, (void**)&scissor_indexedv_reenter);
			mach_override_ptr((void*)obj->disp.depth_range_arrayv, (void*)depth_range_arrayv_replacement, (void**)&depth_range_arrayv_reenter);
			mach_override_ptr((void*)obj->disp.depth_range_indexed, (void*)depth_range_indexed_replacement, (void**)&depth_range_indexed_reenter);
			mach_override_ptr((void*)obj->disp.get_floati_v, (void*)get_floati_v_replacement, (void**)&get_floati_v_reenter);
			mach_override_ptr((void*)obj->disp.get_doublei_v, (void*)get_doublei_v_replacement, (void**)&get_doublei_v_reenter);
			mach_override_ptr((void*)obj->disp.draw_arrays_indirect, (void*)draw_arrays_indirect_replacement, (void**)&draw_arrays_indirect_reenter);
			mach_override_ptr((void*)obj->disp.draw_elements_indirect, (void*)draw_elements_indirect_replacement, (void**)&draw_elements_indirect_reenter);
			mach_override_ptr((void*)obj->disp.patch_parameteri, (void*)patch_parameteri_replacement, (void**)&patch_parameteri_reenter);
			mach_override_ptr((void*)obj->disp.patch_parameterfv, (void*)patch_parameterfv_replacement, (void**)&patch_parameterfv_reenter);
			mach_override_ptr((void*)obj->disp.bind_transform_feedback, (void*)bind_transform_feedback_replacement, (void**)&bind_transform_feedback_reenter);
			mach_override_ptr((void*)obj->disp.gen_transform_feedbacks, (void*)gen_transform_feedbacks_replacement, (void**)&gen_transform_feedbacks_reenter);
			mach_override_ptr((void*)obj->disp.delete_transform_feedbacks, (void*)delete_transform_feedbacks_replacement, (void**)&delete_transform_feedbacks_reenter);
			mach_override_ptr((void*)obj->disp.pause_transform_feedback, (void*)pause_transform_feedback_replacement, (void**)&pause_transform_feedback_reenter);
			mach_override_ptr((void*)obj->disp.resume_transform_feedback, (void*)resume_transform_feedback_replacement, (void**)&resume_transform_feedback_reenter);
			mach_override_ptr((void*)obj->disp.is_transform_feedback, (void*)is_transform_feedback_replacement, (void**)&is_transform_feedback_reenter);
			mach_override_ptr((void*)obj->disp.draw_transform_feedback, (void*)draw_transform_feedback_replacement, (void**)&draw_transform_feedback_reenter);
			mach_override_ptr((void*)obj->disp.begin_query_indexed, (void*)begin_query_indexed_replacement, (void**)&begin_query_indexed_reenter);
			mach_override_ptr((void*)obj->disp.end_query_indexed, (void*)end_query_indexed_replacement, (void**)&end_query_indexed_reenter);
			mach_override_ptr((void*)obj->disp.get_query_indexediv, (void*)get_query_indexediv_replacement, (void**)&get_query_indexediv_reenter);
			mach_override_ptr((void*)obj->disp.draw_transform_feedback_stream, (void*)draw_transform_feedback_stream_replacement, (void**)&draw_transform_feedback_stream_reenter);
			mach_override_ptr((void*)obj->disp.program_uniform1d, (void*)program_uniform1d_replacement, (void**)&program_uniform1d_reenter);
			mach_override_ptr((void*)obj->disp.program_uniform2d, (void*)program_uniform2d_replacement, (void**)&program_uniform2d_reenter);
			mach_override_ptr((void*)obj->disp.program_uniform3d, (void*)program_uniform3d_replacement, (void**)&program_uniform3d_reenter);
			mach_override_ptr((void*)obj->disp.program_uniform4d, (void*)program_uniform4d_replacement, (void**)&program_uniform4d_reenter);
			mach_override_ptr((void*)obj->disp.program_uniform1dv, (void*)program_uniform1dv_replacement, (void**)&program_uniform1dv_reenter);
			mach_override_ptr((void*)obj->disp.program_uniform2dv, (void*)program_uniform2dv_replacement, (void**)&program_uniform2dv_reenter);
			mach_override_ptr((void*)obj->disp.program_uniform3dv, (void*)program_uniform3dv_replacement, (void**)&program_uniform3dv_reenter);
			mach_override_ptr((void*)obj->disp.program_uniform4dv, (void*)program_uniform4dv_replacement, (void**)&program_uniform4dv_reenter);
			mach_override_ptr((void*)obj->disp.program_uniform_matrix2dv, (void*)program_uniform_matrix2dv_replacement, (void**)&program_uniform_matrix2dv_reenter);
			mach_override_ptr((void*)obj->disp.program_uniform_matrix3dv, (void*)program_uniform_matrix3dv_replacement, (void**)&program_uniform_matrix3dv_reenter);
			mach_override_ptr((void*)obj->disp.program_uniform_matrix4dv, (void*)program_uniform_matrix4dv_replacement, (void**)&program_uniform_matrix4dv_reenter);
			mach_override_ptr((void*)obj->disp.program_uniform_matrix2x3dv, (void*)program_uniform_matrix2x3dv_replacement, (void**)&program_uniform_matrix2x3dv_reenter);
			mach_override_ptr((void*)obj->disp.program_uniform_matrix3x2dv, (void*)program_uniform_matrix3x2dv_replacement, (void**)&program_uniform_matrix3x2dv_reenter);
			mach_override_ptr((void*)obj->disp.program_uniform_matrix2x4dv, (void*)program_uniform_matrix2x4dv_replacement, (void**)&program_uniform_matrix2x4dv_reenter);
			mach_override_ptr((void*)obj->disp.program_uniform_matrix4x2dv, (void*)program_uniform_matrix4x2dv_replacement, (void**)&program_uniform_matrix4x2dv_reenter);
			mach_override_ptr((void*)obj->disp.program_uniform_matrix3x4dv, (void*)program_uniform_matrix3x4dv_replacement, (void**)&program_uniform_matrix3x4dv_reenter);
			mach_override_ptr((void*)obj->disp.program_uniform_matrix4x3dv, (void*)program_uniform_matrix4x3dv_replacement, (void**)&program_uniform_matrix4x3dv_reenter);
			mach_override_ptr((void*)obj->disp.uniform1d, (void*)uniform1d_replacement, (void**)&uniform1d_reenter);
			mach_override_ptr((void*)obj->disp.uniform2d, (void*)uniform2d_replacement, (void**)&uniform2d_reenter);
			mach_override_ptr((void*)obj->disp.uniform3d, (void*)uniform3d_replacement, (void**)&uniform3d_reenter);
			mach_override_ptr((void*)obj->disp.uniform4d, (void*)uniform4d_replacement, (void**)&uniform4d_reenter);
			mach_override_ptr((void*)obj->disp.uniform1dv, (void*)uniform1dv_replacement, (void**)&uniform1dv_reenter);
			mach_override_ptr((void*)obj->disp.uniform2dv, (void*)uniform2dv_replacement, (void**)&uniform2dv_reenter);
			mach_override_ptr((void*)obj->disp.uniform3dv, (void*)uniform3dv_replacement, (void**)&uniform3dv_reenter);
			mach_override_ptr((void*)obj->disp.uniform4dv, (void*)uniform4dv_replacement, (void**)&uniform4dv_reenter);
			mach_override_ptr((void*)obj->disp.uniform_matrix2dv, (void*)uniform_matrix2dv_replacement, (void**)&uniform_matrix2dv_reenter);
			mach_override_ptr((void*)obj->disp.uniform_matrix3dv, (void*)uniform_matrix3dv_replacement, (void**)&uniform_matrix3dv_reenter);
			mach_override_ptr((void*)obj->disp.uniform_matrix4dv, (void*)uniform_matrix4dv_replacement, (void**)&uniform_matrix4dv_reenter);
			mach_override_ptr((void*)obj->disp.uniform_matrix2x3dv, (void*)uniform_matrix2x3dv_replacement, (void**)&uniform_matrix2x3dv_reenter);
			mach_override_ptr((void*)obj->disp.uniform_matrix3x2dv, (void*)uniform_matrix3x2dv_replacement, (void**)&uniform_matrix3x2dv_reenter);
			mach_override_ptr((void*)obj->disp.uniform_matrix2x4dv, (void*)uniform_matrix2x4dv_replacement, (void**)&uniform_matrix2x4dv_reenter);
			mach_override_ptr((void*)obj->disp.uniform_matrix4x2dv, (void*)uniform_matrix4x2dv_replacement, (void**)&uniform_matrix4x2dv_reenter);
			mach_override_ptr((void*)obj->disp.uniform_matrix3x4dv, (void*)uniform_matrix3x4dv_replacement, (void**)&uniform_matrix3x4dv_reenter);
			mach_override_ptr((void*)obj->disp.uniform_matrix4x3dv, (void*)uniform_matrix4x3dv_replacement, (void**)&uniform_matrix4x3dv_reenter);
			mach_override_ptr((void*)obj->disp.get_uniformdv, (void*)get_uniformdv_replacement, (void**)&get_uniformdv_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attribl1d, (void*)vertex_attribl1d_replacement, (void**)&vertex_attribl1d_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attribl2d, (void*)vertex_attribl2d_replacement, (void**)&vertex_attribl2d_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attribl3d, (void*)vertex_attribl3d_replacement, (void**)&vertex_attribl3d_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attribl4d, (void*)vertex_attribl4d_replacement, (void**)&vertex_attribl4d_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attribl1dv, (void*)vertex_attribl1dv_replacement, (void**)&vertex_attribl1dv_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attribl2dv, (void*)vertex_attribl2dv_replacement, (void**)&vertex_attribl2dv_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attribl3dv, (void*)vertex_attribl3dv_replacement, (void**)&vertex_attribl3dv_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attribl4dv, (void*)vertex_attribl4dv_replacement, (void**)&vertex_attribl4dv_reenter);
			mach_override_ptr((void*)obj->disp.vertex_attrib_lpointer, (void*)vertex_attrib_lpointer_replacement, (void**)&vertex_attrib_lpointer_reenter);
			mach_override_ptr((void*)obj->disp.get_vertex_attrib_ldv, (void*)get_vertex_attrib_ldv_replacement, (void**)&get_vertex_attrib_ldv_reenter);
			mach_override_ptr((void*)obj->disp.get_subroutine_uniform_location, (void*)get_subroutine_uniform_location_replacement, (void**)&get_subroutine_uniform_location_reenter);
			mach_override_ptr((void*)obj->disp.get_subroutine_index, (void*)get_subroutine_index_replacement, (void**)&get_subroutine_index_reenter);
			mach_override_ptr((void*)obj->disp.get_active_subroutine_uniformiv, (void*)get_active_subroutine_uniformiv_replacement, (void**)&get_active_subroutine_uniformiv_reenter);
			mach_override_ptr((void*)obj->disp.get_active_subroutine_uniform_name, (void*)get_active_subroutine_uniform_name_replacement, (void**)&get_active_subroutine_uniform_name_reenter);
			mach_override_ptr((void*)obj->disp.get_active_subroutine_name, (void*)get_active_subroutine_name_replacement, (void**)&get_active_subroutine_name_reenter);
			mach_override_ptr((void*)obj->disp.uniform_subroutinesuiv, (void*)uniform_subroutinesuiv_replacement, (void**)&uniform_subroutinesuiv_reenter);
			mach_override_ptr((void*)obj->disp.get_uniform_subroutineuiv, (void*)get_uniform_subroutineuiv_replacement, (void**)&get_uniform_subroutineuiv_reenter);
			mach_override_ptr((void*)obj->disp.get_program_stageiv, (void*)get_program_stageiv_replacement, (void**)&get_program_stageiv_reenter);
			mach_override_ptr((void*)obj->disp.get_internal_formativ, (void*)get_internal_formativ_replacement, (void**)&get_internal_formativ_reenter);
			mach_override_ptr((void*)obj->disp.tex_storage1D, (void*)tex_storage1D_replacement, (void**)&tex_storage1D_reenter);
			mach_override_ptr((void*)obj->disp.tex_storage2D, (void*)tex_storage2D_replacement, (void**)&tex_storage2D_reenter);
			mach_override_ptr((void*)obj->disp.tex_storage3D, (void*)tex_storage3D_replacement, (void**)&tex_storage3D_reenter);
			mach_override_ptr((void*)obj->disp.label_object_with_responsible_process_APPLE, (void*)label_object_with_responsible_process_APPLE_replacement, (void**)&label_object_with_responsible_process_APPLE_reenter);
			mach_override_ptr((void*)obj->disp.texture_barrier_NV, (void*)texture_barrier_NV_replacement, (void**)&texture_barrier_NV_reenter);

			overriden = true;
		}
	
		return obj;
	}
};
