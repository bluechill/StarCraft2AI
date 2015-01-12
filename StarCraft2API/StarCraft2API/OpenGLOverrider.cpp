#include <OpenGL/OpenGL.h>
#include <OpenGL/CGLTypes.h>
#include <OpenGL/CGLContext.h>
#include <OpenGL/gliContext.h>

#include <syslog.h>
#include <cstdio>
#include <dlfcn.h>

#include <mutex>
#include <string>
#include <map>

#include "mach_override.h"

extern std::string GLenumToString(GLenum value);
#include "OpenGL State Machine.h"

using namespace std;


static mutex file_mutex;
static FILE* output = fopen("/Users/bluechill/Developer/OpenGLInjector/StarCraft2API/StarCraft2API/SC2Info/SC2Log.log", "w");
void file_log(const char* message, ...)
{
	va_list list;
	va_start(list, message);
	
	std::string cpp_message = message;
	cpp_message.insert(0, "SC2API: ");
	
	file_mutex.lock();
	vfprintf(output, cpp_message.c_str(), list);
	file_mutex.unlock();
}

void log(int priority, const char* message, ...)
{
	va_list list;
	va_start(list, message);
	
	std::string cpp_message = message;
	cpp_message.insert(0, "SC2API: ");
	
	vsyslog(priority, cpp_message.c_str(), list);
}

static void HandleCGLGetCurrentContext(CGLContextObj obj)
{
	static map<GLIContext, CGLContextObj> overriden_ctx;
	
	if (obj && overriden_ctx.find(obj->rend) == overriden_ctx.end())
	{
		log(LOG_NOTICE, "Overriding Context Function PTRs\n");
		
		overriden_ctx[obj->rend] = obj;
		OpenGL::StateMachine::Shared.ctx = obj;
		
		extern void suspend_all_threads();
		suspend_all_threads();
		kern_return_t err;
		
		MACH_OVERRIDE(void,accum,(GLIContext ctx, GLenum op, GLfloat value), err ) {
			file_log("accum called: ctx (GLIContext : %p) op (GLenum : %s) value (GLfloat : %f)\n", ctx, GLenumToString(op).c_str(), value);
			return accum_reenter(ctx, op, value);
		} END_MACH_OVERRIDE_PTR(accum, obj->disp.accum);

		if (err)
			log(LOG_ERR, "Failed to override accum: %i", err);

		MACH_OVERRIDE(void,alpha_func,(GLIContext ctx, GLenum func, GLclampf ref), err ) {
			file_log("alpha_func called: ctx (GLIContext : %p) func (GLenum : %s) ref (GLclampf : %f)\n", ctx, GLenumToString(func).c_str(), ref);
			return alpha_func_reenter(ctx, func, ref);
		} END_MACH_OVERRIDE_PTR(alpha_func, obj->disp.alpha_func);

		if (err)
			log(LOG_ERR, "Failed to override alpha_func: %i", err);

		MACH_OVERRIDE(GLboolean,are_textures_resident,(GLIContext ctx, GLsizei n, const GLuint *textures, GLboolean *residences), err ) {
			file_log("are_textures_resident called: ctx (GLIContext : %p) n (GLsizei : %i) textures (const GLuint* : %p) residences (GLboolean* : %p)\n", ctx, n, textures, residences);
			GLboolean result = are_textures_resident_reenter(ctx, n, textures, residences);
			return result;
		} END_MACH_OVERRIDE_PTR(are_textures_resident, obj->disp.are_textures_resident);

		if (err)
			log(LOG_ERR, "Failed to override are_textures_resident: %i", err);

		MACH_OVERRIDE(void,array_element,(GLIContext ctx, GLint i), err ) {
			file_log("array_element called: ctx (GLIContext : %p) i (GLint : %i)\n", ctx, i);
			return array_element_reenter(ctx, i);
		} END_MACH_OVERRIDE_PTR(array_element, obj->disp.array_element);

		if (err)
			log(LOG_ERR, "Failed to override array_element: %i", err);

		MACH_OVERRIDE(void,begin,(GLIContext ctx, GLenum mode), err ) {
			file_log("begin called: ctx (GLIContext : %p) mode (GLenum : %s)\n", ctx, GLenumToString(mode).c_str());
			return begin_reenter(ctx, mode);
		} END_MACH_OVERRIDE_PTR(begin, obj->disp.begin);

		if (err)
			log(LOG_ERR, "Failed to override begin: %i", err);

		MACH_OVERRIDE(void,bind_texture,(GLIContext ctx, GLenum target, GLuint texture), err ) {
			file_log("bind_texture called: ctx (GLIContext : %p) target (GLenum : %s) texture (GLuint : %u)\n", ctx, GLenumToString(target).c_str(), texture);
			OpenGL::StateMachine::Shared.bind_texture(ctx, target, texture);
			return bind_texture_reenter(ctx, target, texture);
		} END_MACH_OVERRIDE_PTR(bind_texture, obj->disp.bind_texture);

		if (err)
			log(LOG_ERR, "Failed to override bind_texture: %i", err);

		MACH_OVERRIDE(void,bitmap,(GLIContext ctx, GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte *bitmap), err ) {
			file_log("bitmap called: ctx (GLIContext : %p) width (GLsizei : %i) height (GLsizei : %i) xorig (GLfloat : %f) yorig (GLfloat : %f) xmove (GLfloat : %f) ymove (GLfloat : %f) bitmap (const GLubyte* : %p)\n", ctx, width, height, xorig, yorig, xmove, ymove, bitmap);
			return bitmap_reenter(ctx, width, height, xorig, yorig, xmove, ymove, bitmap);
		} END_MACH_OVERRIDE_PTR(bitmap, obj->disp.bitmap);

		if (err)
			log(LOG_ERR, "Failed to override bitmap: %i", err);

		MACH_OVERRIDE(void,blend_func,(GLIContext ctx, GLenum sfactor, GLenum dfactor), err ) {
			file_log("blend_func called: ctx (GLIContext : %p) sfactor (GLenum : %s) dfactor (GLenum : %s)\n", ctx, GLenumToString(sfactor).c_str(), GLenumToString(dfactor).c_str());
			return blend_func_reenter(ctx, sfactor, dfactor);
		} END_MACH_OVERRIDE_PTR(blend_func, obj->disp.blend_func);

		if (err)
			log(LOG_ERR, "Failed to override blend_func: %i", err);

		MACH_OVERRIDE(void,call_list,(GLIContext ctx, GLuint list), err ) {
			file_log("call_list called: ctx (GLIContext : %p) list (GLuint : %u)\n", ctx, list);
			return call_list_reenter(ctx, list);
		} END_MACH_OVERRIDE_PTR(call_list, obj->disp.call_list);

		if (err)
			log(LOG_ERR, "Failed to override call_list: %i", err);

		MACH_OVERRIDE(void,call_lists,(GLIContext ctx, GLsizei n, GLenum type, const GLvoid *lists), err ) {
			file_log("call_lists called: ctx (GLIContext : %p) n (GLsizei : %i) type (GLenum : %s) lists (const GLvoid* : %p)\n", ctx, n, GLenumToString(type).c_str(), lists);
			return call_lists_reenter(ctx, n, type, lists);
		} END_MACH_OVERRIDE_PTR(call_lists, obj->disp.call_lists);

		if (err)
			log(LOG_ERR, "Failed to override call_lists: %i", err);

		MACH_OVERRIDE(void,clear,(GLIContext ctx, GLbitfield mask), err ) {
			file_log("clear called: ctx (GLIContext : %p) mask (GLbitfield : %u)\n", ctx, mask);
			return clear_reenter(ctx, mask);
		} END_MACH_OVERRIDE_PTR(clear, obj->disp.clear);

		if (err)
			log(LOG_ERR, "Failed to override clear: %i", err);

		MACH_OVERRIDE(void,clear_accum,(GLIContext ctx, GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha), err ) {
			file_log("clear_accum called: ctx (GLIContext : %p) red (GLfloat : %f) green (GLfloat : %f) blue (GLfloat : %f) alpha (GLfloat : %f)\n", ctx, red, green, blue, alpha);
			return clear_accum_reenter(ctx, red, green, blue, alpha);
		} END_MACH_OVERRIDE_PTR(clear_accum, obj->disp.clear_accum);

		if (err)
			log(LOG_ERR, "Failed to override clear_accum: %i", err);

		MACH_OVERRIDE(void,clear_color,(GLIContext ctx, GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha), err ) {
			file_log("clear_color called: ctx (GLIContext : %p) red (GLclampf : %f) green (GLclampf : %f) blue (GLclampf : %f) alpha (GLclampf : %f)\n", ctx, red, green, blue, alpha);
			return clear_color_reenter(ctx, red, green, blue, alpha);
		} END_MACH_OVERRIDE_PTR(clear_color, obj->disp.clear_color);

		if (err)
			log(LOG_ERR, "Failed to override clear_color: %i", err);

		MACH_OVERRIDE(void,clear_depth,(GLIContext ctx, GLclampd depth), err ) {
			file_log("clear_depth called: ctx (GLIContext : %p) depth (GLclampd : %f)\n", ctx, depth);
			return clear_depth_reenter(ctx, depth);
		} END_MACH_OVERRIDE_PTR(clear_depth, obj->disp.clear_depth);

		if (err)
			log(LOG_ERR, "Failed to override clear_depth: %i", err);

		MACH_OVERRIDE(void,clear_index,(GLIContext ctx, GLfloat c), err ) {
			file_log("clear_index called: ctx (GLIContext : %p) c (GLfloat : %f)\n", ctx, c);
			return clear_index_reenter(ctx, c);
		} END_MACH_OVERRIDE_PTR(clear_index, obj->disp.clear_index);

		if (err)
			log(LOG_ERR, "Failed to override clear_index: %i", err);

		MACH_OVERRIDE(void,clear_stencil,(GLIContext ctx, GLint s), err ) {
			file_log("clear_stencil called: ctx (GLIContext : %p) s (GLint : %i)\n", ctx, s);
			return clear_stencil_reenter(ctx, s);
		} END_MACH_OVERRIDE_PTR(clear_stencil, obj->disp.clear_stencil);

		if (err)
			log(LOG_ERR, "Failed to override clear_stencil: %i", err);

		MACH_OVERRIDE(void,clip_plane,(GLIContext ctx, GLenum plane, const GLdouble *equation), err ) {
			file_log("clip_plane called: ctx (GLIContext : %p) plane (GLenum : %s) equation (const GLdouble* : %p)\n", ctx, GLenumToString(plane).c_str(), equation);
			return clip_plane_reenter(ctx, plane, equation);
		} END_MACH_OVERRIDE_PTR(clip_plane, obj->disp.clip_plane);

		if (err)
			log(LOG_ERR, "Failed to override clip_plane: %i", err);

		MACH_OVERRIDE(void,color3b,(GLIContext ctx, GLbyte red, GLbyte green, GLbyte blue), err ) {
			file_log("color3b called: ctx (GLIContext : %p) red (GLbyte : %i) green (GLbyte : %i) blue (GLbyte : %i)\n", ctx, red, green, blue);
			return color3b_reenter(ctx, red, green, blue);
		} END_MACH_OVERRIDE_PTR(color3b, obj->disp.color3b);

		if (err)
			log(LOG_ERR, "Failed to override color3b: %i", err);

		MACH_OVERRIDE(void,color3bv,(GLIContext ctx, const GLbyte *v), err ) {
			file_log("color3bv called: ctx (GLIContext : %p) v (const GLbyte* : %p)\n", ctx, v);
			return color3bv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(color3bv, obj->disp.color3bv);

		if (err)
			log(LOG_ERR, "Failed to override color3bv: %i", err);

		MACH_OVERRIDE(void,color3d,(GLIContext ctx, GLdouble red, GLdouble green, GLdouble blue), err ) {
			file_log("color3d called: ctx (GLIContext : %p) red (GLdouble : %f) green (GLdouble : %f) blue (GLdouble : %f)\n", ctx, red, green, blue);
			return color3d_reenter(ctx, red, green, blue);
		} END_MACH_OVERRIDE_PTR(color3d, obj->disp.color3d);

		if (err)
			log(LOG_ERR, "Failed to override color3d: %i", err);

		MACH_OVERRIDE(void,color3dv,(GLIContext ctx, const GLdouble *v), err ) {
			file_log("color3dv called: ctx (GLIContext : %p) v (const GLdouble* : %p)\n", ctx, v);
			return color3dv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(color3dv, obj->disp.color3dv);

		if (err)
			log(LOG_ERR, "Failed to override color3dv: %i", err);

		MACH_OVERRIDE(void,color3f,(GLIContext ctx, GLfloat red, GLfloat green, GLfloat blue), err ) {
			file_log("color3f called: ctx (GLIContext : %p) red (GLfloat : %f) green (GLfloat : %f) blue (GLfloat : %f)\n", ctx, red, green, blue);
			return color3f_reenter(ctx, red, green, blue);
		} END_MACH_OVERRIDE_PTR(color3f, obj->disp.color3f);

		if (err)
			log(LOG_ERR, "Failed to override color3f: %i", err);

		MACH_OVERRIDE(void,color3fv,(GLIContext ctx, const GLfloat *v), err ) {
			file_log("color3fv called: ctx (GLIContext : %p) v (const GLfloat* : %p)\n", ctx, v);
			return color3fv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(color3fv, obj->disp.color3fv);

		if (err)
			log(LOG_ERR, "Failed to override color3fv: %i", err);

		MACH_OVERRIDE(void,color3i,(GLIContext ctx, GLint red, GLint green, GLint blue), err ) {
			file_log("color3i called: ctx (GLIContext : %p) red (GLint : %i) green (GLint : %i) blue (GLint : %i)\n", ctx, red, green, blue);
			return color3i_reenter(ctx, red, green, blue);
		} END_MACH_OVERRIDE_PTR(color3i, obj->disp.color3i);

		if (err)
			log(LOG_ERR, "Failed to override color3i: %i", err);

		MACH_OVERRIDE(void,color3iv,(GLIContext ctx, const GLint *v), err ) {
			file_log("color3iv called: ctx (GLIContext : %p) v (const GLint* : %p)\n", ctx, v);
			return color3iv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(color3iv, obj->disp.color3iv);

		if (err)
			log(LOG_ERR, "Failed to override color3iv: %i", err);

		MACH_OVERRIDE(void,color3s,(GLIContext ctx, GLshort red, GLshort green, GLshort blue), err ) {
			file_log("color3s called: ctx (GLIContext : %p) red (GLshort : %i) green (GLshort : %i) blue (GLshort : %i)\n", ctx, red, green, blue);
			return color3s_reenter(ctx, red, green, blue);
		} END_MACH_OVERRIDE_PTR(color3s, obj->disp.color3s);

		if (err)
			log(LOG_ERR, "Failed to override color3s: %i", err);

		MACH_OVERRIDE(void,color3sv,(GLIContext ctx, const GLshort *v), err ) {
			file_log("color3sv called: ctx (GLIContext : %p) v (const GLshort* : %p)\n", ctx, v);
			return color3sv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(color3sv, obj->disp.color3sv);

		if (err)
			log(LOG_ERR, "Failed to override color3sv: %i", err);

		MACH_OVERRIDE(void,color3ub,(GLIContext ctx, GLubyte red, GLubyte green, GLubyte blue), err ) {
			file_log("color3ub called: ctx (GLIContext : %p) red (GLubyte : %u) green (GLubyte : %u) blue (GLubyte : %u)\n", ctx, red, green, blue);
			return color3ub_reenter(ctx, red, green, blue);
		} END_MACH_OVERRIDE_PTR(color3ub, obj->disp.color3ub);

		if (err)
			log(LOG_ERR, "Failed to override color3ub: %i", err);

		MACH_OVERRIDE(void,color3ubv,(GLIContext ctx, const GLubyte *v), err ) {
			file_log("color3ubv called: ctx (GLIContext : %p) v (const GLubyte* : %p)\n", ctx, v);
			return color3ubv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(color3ubv, obj->disp.color3ubv);

		if (err)
			log(LOG_ERR, "Failed to override color3ubv: %i", err);

		MACH_OVERRIDE(void,color3ui,(GLIContext ctx, GLuint red, GLuint green, GLuint blue), err ) {
			file_log("color3ui called: ctx (GLIContext : %p) red (GLuint : %u) green (GLuint : %u) blue (GLuint : %u)\n", ctx, red, green, blue);
			return color3ui_reenter(ctx, red, green, blue);
		} END_MACH_OVERRIDE_PTR(color3ui, obj->disp.color3ui);

		if (err)
			log(LOG_ERR, "Failed to override color3ui: %i", err);

		MACH_OVERRIDE(void,color3uiv,(GLIContext ctx, const GLuint *v), err ) {
			file_log("color3uiv called: ctx (GLIContext : %p) v (const GLuint* : %p)\n", ctx, v);
			return color3uiv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(color3uiv, obj->disp.color3uiv);

		if (err)
			log(LOG_ERR, "Failed to override color3uiv: %i", err);

		MACH_OVERRIDE(void,color3us,(GLIContext ctx, GLushort red, GLushort green, GLushort blue), err ) {
			file_log("color3us called: ctx (GLIContext : %p) red (GLushort : %u) green (GLushort : %u) blue (GLushort : %u)\n", ctx, red, green, blue);
			return color3us_reenter(ctx, red, green, blue);
		} END_MACH_OVERRIDE_PTR(color3us, obj->disp.color3us);

		if (err)
			log(LOG_ERR, "Failed to override color3us: %i", err);

		MACH_OVERRIDE(void,color3usv,(GLIContext ctx, const GLushort *v), err ) {
			file_log("color3usv called: ctx (GLIContext : %p) v (const GLushort* : %p)\n", ctx, v);
			return color3usv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(color3usv, obj->disp.color3usv);

		if (err)
			log(LOG_ERR, "Failed to override color3usv: %i", err);

		MACH_OVERRIDE(void,color4b,(GLIContext ctx, GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha), err ) {
			file_log("color4b called: ctx (GLIContext : %p) red (GLbyte : %i) green (GLbyte : %i) blue (GLbyte : %i) alpha (GLbyte : %i)\n", ctx, red, green, blue, alpha);
			return color4b_reenter(ctx, red, green, blue, alpha);
		} END_MACH_OVERRIDE_PTR(color4b, obj->disp.color4b);

		if (err)
			log(LOG_ERR, "Failed to override color4b: %i", err);

		MACH_OVERRIDE(void,color4bv,(GLIContext ctx, const GLbyte *v), err ) {
			file_log("color4bv called: ctx (GLIContext : %p) v (const GLbyte* : %p)\n", ctx, v);
			return color4bv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(color4bv, obj->disp.color4bv);

		if (err)
			log(LOG_ERR, "Failed to override color4bv: %i", err);

		MACH_OVERRIDE(void,color4d,(GLIContext ctx, GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha), err ) {
			file_log("color4d called: ctx (GLIContext : %p) red (GLdouble : %f) green (GLdouble : %f) blue (GLdouble : %f) alpha (GLdouble : %f)\n", ctx, red, green, blue, alpha);
			return color4d_reenter(ctx, red, green, blue, alpha);
		} END_MACH_OVERRIDE_PTR(color4d, obj->disp.color4d);

		if (err)
			log(LOG_ERR, "Failed to override color4d: %i", err);

		MACH_OVERRIDE(void,color4dv,(GLIContext ctx, const GLdouble *v), err ) {
			file_log("color4dv called: ctx (GLIContext : %p) v (const GLdouble* : %p)\n", ctx, v);
			return color4dv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(color4dv, obj->disp.color4dv);

		if (err)
			log(LOG_ERR, "Failed to override color4dv: %i", err);

		MACH_OVERRIDE(void,color4f,(GLIContext ctx, GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha), err ) {
			file_log("color4f called: ctx (GLIContext : %p) red (GLfloat : %f) green (GLfloat : %f) blue (GLfloat : %f) alpha (GLfloat : %f)\n", ctx, red, green, blue, alpha);
			return color4f_reenter(ctx, red, green, blue, alpha);
		} END_MACH_OVERRIDE_PTR(color4f, obj->disp.color4f);

		if (err)
			log(LOG_ERR, "Failed to override color4f: %i", err);

		MACH_OVERRIDE(void,color4fv,(GLIContext ctx, const GLfloat *v), err ) {
			file_log("color4fv called: ctx (GLIContext : %p) v (const GLfloat* : %p)\n", ctx, v);
			return color4fv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(color4fv, obj->disp.color4fv);

		if (err)
			log(LOG_ERR, "Failed to override color4fv: %i", err);

		MACH_OVERRIDE(void,color4i,(GLIContext ctx, GLint red, GLint green, GLint blue, GLint alpha), err ) {
			file_log("color4i called: ctx (GLIContext : %p) red (GLint : %i) green (GLint : %i) blue (GLint : %i) alpha (GLint : %i)\n", ctx, red, green, blue, alpha);
			return color4i_reenter(ctx, red, green, blue, alpha);
		} END_MACH_OVERRIDE_PTR(color4i, obj->disp.color4i);

		if (err)
			log(LOG_ERR, "Failed to override color4i: %i", err);

		MACH_OVERRIDE(void,color4iv,(GLIContext ctx, const GLint *v), err ) {
			file_log("color4iv called: ctx (GLIContext : %p) v (const GLint* : %p)\n", ctx, v);
			return color4iv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(color4iv, obj->disp.color4iv);

		if (err)
			log(LOG_ERR, "Failed to override color4iv: %i", err);

		MACH_OVERRIDE(void,color4s,(GLIContext ctx, GLshort red, GLshort green, GLshort blue, GLshort alpha), err ) {
			file_log("color4s called: ctx (GLIContext : %p) red (GLshort : %i) green (GLshort : %i) blue (GLshort : %i) alpha (GLshort : %i)\n", ctx, red, green, blue, alpha);
			return color4s_reenter(ctx, red, green, blue, alpha);
		} END_MACH_OVERRIDE_PTR(color4s, obj->disp.color4s);

		if (err)
			log(LOG_ERR, "Failed to override color4s: %i", err);

		MACH_OVERRIDE(void,color4sv,(GLIContext ctx, const GLshort *v), err ) {
			file_log("color4sv called: ctx (GLIContext : %p) v (const GLshort* : %p)\n", ctx, v);
			return color4sv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(color4sv, obj->disp.color4sv);

		if (err)
			log(LOG_ERR, "Failed to override color4sv: %i", err);

		MACH_OVERRIDE(void,color4ub,(GLIContext ctx, GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha), err ) {
			file_log("color4ub called: ctx (GLIContext : %p) red (GLubyte : %u) green (GLubyte : %u) blue (GLubyte : %u) alpha (GLubyte : %u)\n", ctx, red, green, blue, alpha);
			return color4ub_reenter(ctx, red, green, blue, alpha);
		} END_MACH_OVERRIDE_PTR(color4ub, obj->disp.color4ub);

		if (err)
			log(LOG_ERR, "Failed to override color4ub: %i", err);

		MACH_OVERRIDE(void,color4ubv,(GLIContext ctx, const GLubyte *v), err ) {
			file_log("color4ubv called: ctx (GLIContext : %p) v (const GLubyte* : %p)\n", ctx, v);
			return color4ubv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(color4ubv, obj->disp.color4ubv);

		if (err)
			log(LOG_ERR, "Failed to override color4ubv: %i", err);

		MACH_OVERRIDE(void,color4ui,(GLIContext ctx, GLuint red, GLuint green, GLuint blue, GLuint alpha), err ) {
			file_log("color4ui called: ctx (GLIContext : %p) red (GLuint : %u) green (GLuint : %u) blue (GLuint : %u) alpha (GLuint : %u)\n", ctx, red, green, blue, alpha);
			return color4ui_reenter(ctx, red, green, blue, alpha);
		} END_MACH_OVERRIDE_PTR(color4ui, obj->disp.color4ui);

		if (err)
			log(LOG_ERR, "Failed to override color4ui: %i", err);

		MACH_OVERRIDE(void,color4uiv,(GLIContext ctx, const GLuint *v), err ) {
			file_log("color4uiv called: ctx (GLIContext : %p) v (const GLuint* : %p)\n", ctx, v);
			return color4uiv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(color4uiv, obj->disp.color4uiv);

		if (err)
			log(LOG_ERR, "Failed to override color4uiv: %i", err);

		MACH_OVERRIDE(void,color4us,(GLIContext ctx, GLushort red, GLushort green, GLushort blue, GLushort alpha), err ) {
			file_log("color4us called: ctx (GLIContext : %p) red (GLushort : %u) green (GLushort : %u) blue (GLushort : %u) alpha (GLushort : %u)\n", ctx, red, green, blue, alpha);
			return color4us_reenter(ctx, red, green, blue, alpha);
		} END_MACH_OVERRIDE_PTR(color4us, obj->disp.color4us);

		if (err)
			log(LOG_ERR, "Failed to override color4us: %i", err);

		MACH_OVERRIDE(void,color4usv,(GLIContext ctx, const GLushort *v), err ) {
			file_log("color4usv called: ctx (GLIContext : %p) v (const GLushort* : %p)\n", ctx, v);
			return color4usv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(color4usv, obj->disp.color4usv);

		if (err)
			log(LOG_ERR, "Failed to override color4usv: %i", err);

		MACH_OVERRIDE(void,color_mask,(GLIContext ctx, GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha), err ) {
			file_log("color_mask called: ctx (GLIContext : %p) red (GLboolean : %i) green (GLboolean : %i) blue (GLboolean : %i) alpha (GLboolean : %i)\n", ctx, red, green, blue, alpha);
			return color_mask_reenter(ctx, red, green, blue, alpha);
		} END_MACH_OVERRIDE_PTR(color_mask, obj->disp.color_mask);

		if (err)
			log(LOG_ERR, "Failed to override color_mask: %i", err);

		MACH_OVERRIDE(void,color_material,(GLIContext ctx, GLenum face, GLenum mode), err ) {
			file_log("color_material called: ctx (GLIContext : %p) face (GLenum : %s) mode (GLenum : %s)\n", ctx, GLenumToString(face).c_str(), GLenumToString(mode).c_str());
			return color_material_reenter(ctx, face, mode);
		} END_MACH_OVERRIDE_PTR(color_material, obj->disp.color_material);

		if (err)
			log(LOG_ERR, "Failed to override color_material: %i", err);

		MACH_OVERRIDE(void,color_pointer,(GLIContext ctx, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer), err ) {
			file_log("color_pointer called: ctx (GLIContext : %p) size (GLint : %i) type (GLenum : %s) stride (GLsizei : %i) pointer (const GLvoid* : %p)\n", ctx, size, GLenumToString(type).c_str(), stride, pointer);
			return color_pointer_reenter(ctx, size, type, stride, pointer);
		} END_MACH_OVERRIDE_PTR(color_pointer, obj->disp.color_pointer);

		if (err)
			log(LOG_ERR, "Failed to override color_pointer: %i", err);

		MACH_OVERRIDE(void,copy_pixels,(GLIContext ctx, GLint x, GLint y, GLsizei width, GLsizei height, GLenum type), err ) {
			file_log("copy_pixels called: ctx (GLIContext : %p) x (GLint : %i) y (GLint : %i) width (GLsizei : %i) height (GLsizei : %i) type (GLenum : %s)\n", ctx, x, y, width, height, GLenumToString(type).c_str());
			return copy_pixels_reenter(ctx, x, y, width, height, type);
		} END_MACH_OVERRIDE_PTR(copy_pixels, obj->disp.copy_pixels);

		if (err)
			log(LOG_ERR, "Failed to override copy_pixels: %i", err);

		MACH_OVERRIDE(void,copy_tex_image1D,(GLIContext ctx, GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLint border), err ) {
			file_log("copy_tex_image1D called: ctx (GLIContext : %p) target (GLenum : %s) level (GLint : %i) internalFormat (GLenum : %s) x (GLint : %i) y (GLint : %i) width (GLsizei : %i) border (GLint : %i)\n", ctx, GLenumToString(target).c_str(), level, GLenumToString(internalFormat).c_str(), x, y, width, border);
			return copy_tex_image1D_reenter(ctx, target, level, internalFormat, x, y, width, border);
		} END_MACH_OVERRIDE_PTR(copy_tex_image1D, obj->disp.copy_tex_image1D);

		if (err)
			log(LOG_ERR, "Failed to override copy_tex_image1D: %i", err);

		MACH_OVERRIDE(void,copy_tex_image2D,(GLIContext ctx, GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border), err ) {
			file_log("copy_tex_image2D called: ctx (GLIContext : %p) target (GLenum : %s) level (GLint : %i) internalFormat (GLenum : %s) x (GLint : %i) y (GLint : %i) width (GLsizei : %i) height (GLsizei : %i) border (GLint : %i)\n", ctx, GLenumToString(target).c_str(), level, GLenumToString(internalFormat).c_str(), x, y, width, height, border);
			return copy_tex_image2D_reenter(ctx, target, level, internalFormat, x, y, width, height, border);
		} END_MACH_OVERRIDE_PTR(copy_tex_image2D, obj->disp.copy_tex_image2D);

		if (err)
			log(LOG_ERR, "Failed to override copy_tex_image2D: %i", err);

		MACH_OVERRIDE(void,copy_tex_sub_image1D,(GLIContext ctx, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width), err ) {
			file_log("copy_tex_sub_image1D called: ctx (GLIContext : %p) target (GLenum : %s) level (GLint : %i) xoffset (GLint : %i) x (GLint : %i) y (GLint : %i) width (GLsizei : %i)\n", ctx, GLenumToString(target).c_str(), level, xoffset, x, y, width);
			return copy_tex_sub_image1D_reenter(ctx, target, level, xoffset, x, y, width);
		} END_MACH_OVERRIDE_PTR(copy_tex_sub_image1D, obj->disp.copy_tex_sub_image1D);

		if (err)
			log(LOG_ERR, "Failed to override copy_tex_sub_image1D: %i", err);

		MACH_OVERRIDE(void,copy_tex_sub_image2D,(GLIContext ctx, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height), err ) {
			file_log("copy_tex_sub_image2D called: ctx (GLIContext : %p) target (GLenum : %s) level (GLint : %i) xoffset (GLint : %i) yoffset (GLint : %i) x (GLint : %i) y (GLint : %i) width (GLsizei : %i) height (GLsizei : %i)\n", ctx, GLenumToString(target).c_str(), level, xoffset, yoffset, x, y, width, height);
			return copy_tex_sub_image2D_reenter(ctx, target, level, xoffset, yoffset, x, y, width, height);
		} END_MACH_OVERRIDE_PTR(copy_tex_sub_image2D, obj->disp.copy_tex_sub_image2D);

		if (err)
			log(LOG_ERR, "Failed to override copy_tex_sub_image2D: %i", err);

		MACH_OVERRIDE(void,cull_face,(GLIContext ctx, GLenum mode), err ) {
			file_log("cull_face called: ctx (GLIContext : %p) mode (GLenum : %s)\n", ctx, GLenumToString(mode).c_str());
			return cull_face_reenter(ctx, mode);
		} END_MACH_OVERRIDE_PTR(cull_face, obj->disp.cull_face);

		if (err)
			log(LOG_ERR, "Failed to override cull_face: %i", err);

		MACH_OVERRIDE(void,delete_lists,(GLIContext ctx, GLuint list, GLsizei range), err ) {
			file_log("delete_lists called: ctx (GLIContext : %p) list (GLuint : %u) range (GLsizei : %i)\n", ctx, list, range);
			return delete_lists_reenter(ctx, list, range);
		} END_MACH_OVERRIDE_PTR(delete_lists, obj->disp.delete_lists);

		if (err)
			log(LOG_ERR, "Failed to override delete_lists: %i", err);

		MACH_OVERRIDE(void,delete_textures,(GLIContext ctx, GLsizei n, const GLuint *textures), err ) {
			file_log("delete_textures called: ctx (GLIContext : %p) n (GLsizei : %i) textures (const GLuint* : %p)\n", ctx, n, textures);
			return delete_textures_reenter(ctx, n, textures);
		} END_MACH_OVERRIDE_PTR(delete_textures, obj->disp.delete_textures);

		if (err)
			log(LOG_ERR, "Failed to override delete_textures: %i", err);

		MACH_OVERRIDE(void,depth_func,(GLIContext ctx, GLenum func), err ) {
			file_log("depth_func called: ctx (GLIContext : %p) func (GLenum : %s)\n", ctx, GLenumToString(func).c_str());
			return depth_func_reenter(ctx, func);
		} END_MACH_OVERRIDE_PTR(depth_func, obj->disp.depth_func);

		if (err)
			log(LOG_ERR, "Failed to override depth_func: %i", err);

		MACH_OVERRIDE(void,depth_mask,(GLIContext ctx, GLboolean flag), err ) {
			file_log("depth_mask called: ctx (GLIContext : %p) flag (GLboolean : %i)\n", ctx, flag);
			return depth_mask_reenter(ctx, flag);
		} END_MACH_OVERRIDE_PTR(depth_mask, obj->disp.depth_mask);

		if (err)
			log(LOG_ERR, "Failed to override depth_mask: %i", err);

		MACH_OVERRIDE(void,depth_range,(GLIContext ctx, GLclampd zNear, GLclampd zFar), err ) {
			file_log("depth_range called: ctx (GLIContext : %p) zNear (GLclampd : %f) zFar (GLclampd : %f)\n", ctx, zNear, zFar);
			return depth_range_reenter(ctx, zNear, zFar);
		} END_MACH_OVERRIDE_PTR(depth_range, obj->disp.depth_range);

		if (err)
			log(LOG_ERR, "Failed to override depth_range: %i", err);

		MACH_OVERRIDE(void,disable,(GLIContext ctx, GLenum cap), err ) {
			file_log("disable called: ctx (GLIContext : %p) cap (GLenum : %s)\n", ctx, GLenumToString(cap).c_str());
			return disable_reenter(ctx, cap);
		} END_MACH_OVERRIDE_PTR(disable, obj->disp.disable);

		if (err)
			log(LOG_ERR, "Failed to override disable: %i", err);

		MACH_OVERRIDE(void,disable_client_state,(GLIContext ctx, GLenum array), err ) {
			file_log("disable_client_state called: ctx (GLIContext : %p) array (GLenum : %s)\n", ctx, GLenumToString(array).c_str());
			return disable_client_state_reenter(ctx, array);
		} END_MACH_OVERRIDE_PTR(disable_client_state, obj->disp.disable_client_state);

		if (err)
			log(LOG_ERR, "Failed to override disable_client_state: %i", err);

		MACH_OVERRIDE(void,draw_arrays,(GLIContext ctx, GLenum mode, GLint first, GLsizei count), err ) {
			file_log("draw_arrays called: ctx (GLIContext : %p) mode (GLenum : %s) first (GLint : %i) count (GLsizei : %i)\n", ctx, GLenumToString(mode).c_str(), first, count);
			OpenGL::StateMachine::Shared.draw_arrays(ctx, mode, first, count);
			return draw_arrays_reenter(ctx, mode, first, count);
		} END_MACH_OVERRIDE_PTR(draw_arrays, obj->disp.draw_arrays);

		if (err)
			log(LOG_ERR, "Failed to override draw_arrays: %i", err);

		MACH_OVERRIDE(void,draw_buffer,(GLIContext ctx, GLenum mode), err ) {
			file_log("draw_buffer called: ctx (GLIContext : %p) mode (GLenum : %s)\n", ctx, GLenumToString(mode).c_str());
			OpenGL::StateMachine::Shared.draw_buffer(ctx, mode);
			return draw_buffer_reenter(ctx, mode);
		} END_MACH_OVERRIDE_PTR(draw_buffer, obj->disp.draw_buffer);

		if (err)
			log(LOG_ERR, "Failed to override draw_buffer: %i", err);

		MACH_OVERRIDE(void,draw_elements,(GLIContext ctx, GLenum mode, GLsizei count, GLenum type, const GLvoid *indices), err ) {
			file_log("draw_elements called: ctx (GLIContext : %p) mode (GLenum : %s) count (GLsizei : %i) type (GLenum : %s) indices (const GLvoid* : %p)\n", ctx, GLenumToString(mode).c_str(), count, GLenumToString(type).c_str(), indices);
			OpenGL::StateMachine::Shared.draw_elements(ctx, mode, count, type, indices);
			return draw_elements_reenter(ctx, mode, count, type, indices);
		} END_MACH_OVERRIDE_PTR(draw_elements, obj->disp.draw_elements);

		if (err)
			log(LOG_ERR, "Failed to override draw_elements: %i", err);

		MACH_OVERRIDE(void,draw_pixels,(GLIContext ctx, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels), err ) {
			file_log("draw_pixels called: ctx (GLIContext : %p) width (GLsizei : %i) height (GLsizei : %i) format (GLenum : %s) type (GLenum : %s) pixels (const GLvoid* : %p)\n", ctx, width, height, GLenumToString(format).c_str(), GLenumToString(type).c_str(), pixels);
			OpenGL::StateMachine::Shared.draw_pixels(ctx, width, height, format, type, pixels);
			return draw_pixels_reenter(ctx, width, height, format, type, pixels);
		} END_MACH_OVERRIDE_PTR(draw_pixels, obj->disp.draw_pixels);

		if (err)
			log(LOG_ERR, "Failed to override draw_pixels: %i", err);

		MACH_OVERRIDE(void,edge_flag,(GLIContext ctx, GLboolean flag), err ) {
			file_log("edge_flag called: ctx (GLIContext : %p) flag (GLboolean : %i)\n", ctx, flag);
			return edge_flag_reenter(ctx, flag);
		} END_MACH_OVERRIDE_PTR(edge_flag, obj->disp.edge_flag);

		if (err)
			log(LOG_ERR, "Failed to override edge_flag: %i", err);

		MACH_OVERRIDE(void,edge_flag_pointer,(GLIContext ctx, GLsizei stride, const GLvoid *pointer), err ) {
			file_log("edge_flag_pointer called: ctx (GLIContext : %p) stride (GLsizei : %i) pointer (const GLvoid* : %p)\n", ctx, stride, pointer);
			return edge_flag_pointer_reenter(ctx, stride, pointer);
		} END_MACH_OVERRIDE_PTR(edge_flag_pointer, obj->disp.edge_flag_pointer);

		if (err)
			log(LOG_ERR, "Failed to override edge_flag_pointer: %i", err);

		MACH_OVERRIDE(void,edge_flagv,(GLIContext ctx, const GLboolean *flag), err ) {
			file_log("edge_flagv called: ctx (GLIContext : %p) flag (const GLboolean* : %p)\n", ctx, flag);
			return edge_flagv_reenter(ctx, flag);
		} END_MACH_OVERRIDE_PTR(edge_flagv, obj->disp.edge_flagv);

		if (err)
			log(LOG_ERR, "Failed to override edge_flagv: %i", err);

		MACH_OVERRIDE(void,enable,(GLIContext ctx, GLenum cap), err ) {
			file_log("enable called: ctx (GLIContext : %p) cap (GLenum : %s)\n", ctx, GLenumToString(cap).c_str());
			return enable_reenter(ctx, cap);
		} END_MACH_OVERRIDE_PTR(enable, obj->disp.enable);

		if (err)
			log(LOG_ERR, "Failed to override enable: %i", err);

		MACH_OVERRIDE(void,enable_client_state,(GLIContext ctx, GLenum array), err ) {
			file_log("enable_client_state called: ctx (GLIContext : %p) array (GLenum : %s)\n", ctx, GLenumToString(array).c_str());
			return enable_client_state_reenter(ctx, array);
		} END_MACH_OVERRIDE_PTR(enable_client_state, obj->disp.enable_client_state);

		if (err)
			log(LOG_ERR, "Failed to override enable_client_state: %i", err);

		MACH_OVERRIDE(void,end,(GLIContext ctx), err ) {
			file_log("end called: ctx (GLIContext : %p)\n", ctx);
			return end_reenter(ctx);
		} END_MACH_OVERRIDE_PTR(end, obj->disp.end);

		if (err)
			log(LOG_ERR, "Failed to override end: %i", err);

		MACH_OVERRIDE(void,end_list,(GLIContext ctx), err ) {
			file_log("end_list called: ctx (GLIContext : %p)\n", ctx);
			return end_list_reenter(ctx);
		} END_MACH_OVERRIDE_PTR(end_list, obj->disp.end_list);

		if (err)
			log(LOG_ERR, "Failed to override end_list: %i", err);

		MACH_OVERRIDE(void,eval_coord1d,(GLIContext ctx, GLdouble u), err ) {
			file_log("eval_coord1d called: ctx (GLIContext : %p) u (GLdouble : %f)\n", ctx, u);
			return eval_coord1d_reenter(ctx, u);
		} END_MACH_OVERRIDE_PTR(eval_coord1d, obj->disp.eval_coord1d);

		if (err)
			log(LOG_ERR, "Failed to override eval_coord1d: %i", err);

		MACH_OVERRIDE(void,eval_coord1dv,(GLIContext ctx, const GLdouble *u), err ) {
			file_log("eval_coord1dv called: ctx (GLIContext : %p) u (const GLdouble* : %p)\n", ctx, u);
			return eval_coord1dv_reenter(ctx, u);
		} END_MACH_OVERRIDE_PTR(eval_coord1dv, obj->disp.eval_coord1dv);

		if (err)
			log(LOG_ERR, "Failed to override eval_coord1dv: %i", err);

		MACH_OVERRIDE(void,eval_coord1f,(GLIContext ctx, GLfloat u), err ) {
			file_log("eval_coord1f called: ctx (GLIContext : %p) u (GLfloat : %f)\n", ctx, u);
			return eval_coord1f_reenter(ctx, u);
		} END_MACH_OVERRIDE_PTR(eval_coord1f, obj->disp.eval_coord1f);

		if (err)
			log(LOG_ERR, "Failed to override eval_coord1f: %i", err);

		MACH_OVERRIDE(void,eval_coord1fv,(GLIContext ctx, const GLfloat *u), err ) {
			file_log("eval_coord1fv called: ctx (GLIContext : %p) u (const GLfloat* : %p)\n", ctx, u);
			return eval_coord1fv_reenter(ctx, u);
		} END_MACH_OVERRIDE_PTR(eval_coord1fv, obj->disp.eval_coord1fv);

		if (err)
			log(LOG_ERR, "Failed to override eval_coord1fv: %i", err);

		MACH_OVERRIDE(void,eval_coord2d,(GLIContext ctx, GLdouble u, GLdouble v), err ) {
			file_log("eval_coord2d called: ctx (GLIContext : %p) u (GLdouble : %f) v (GLdouble : %f)\n", ctx, u, v);
			return eval_coord2d_reenter(ctx, u, v);
		} END_MACH_OVERRIDE_PTR(eval_coord2d, obj->disp.eval_coord2d);

		if (err)
			log(LOG_ERR, "Failed to override eval_coord2d: %i", err);

		MACH_OVERRIDE(void,eval_coord2dv,(GLIContext ctx, const GLdouble *u), err ) {
			file_log("eval_coord2dv called: ctx (GLIContext : %p) u (const GLdouble* : %p)\n", ctx, u);
			return eval_coord2dv_reenter(ctx, u);
		} END_MACH_OVERRIDE_PTR(eval_coord2dv, obj->disp.eval_coord2dv);

		if (err)
			log(LOG_ERR, "Failed to override eval_coord2dv: %i", err);

		MACH_OVERRIDE(void,eval_coord2f,(GLIContext ctx, GLfloat u, GLfloat v), err ) {
			file_log("eval_coord2f called: ctx (GLIContext : %p) u (GLfloat : %f) v (GLfloat : %f)\n", ctx, u, v);
			return eval_coord2f_reenter(ctx, u, v);
		} END_MACH_OVERRIDE_PTR(eval_coord2f, obj->disp.eval_coord2f);

		if (err)
			log(LOG_ERR, "Failed to override eval_coord2f: %i", err);

		MACH_OVERRIDE(void,eval_coord2fv,(GLIContext ctx, const GLfloat *u), err ) {
			file_log("eval_coord2fv called: ctx (GLIContext : %p) u (const GLfloat* : %p)\n", ctx, u);
			return eval_coord2fv_reenter(ctx, u);
		} END_MACH_OVERRIDE_PTR(eval_coord2fv, obj->disp.eval_coord2fv);

		if (err)
			log(LOG_ERR, "Failed to override eval_coord2fv: %i", err);

		MACH_OVERRIDE(void,eval_mesh1,(GLIContext ctx, GLenum mode, GLint i1, GLint i2), err ) {
			file_log("eval_mesh1 called: ctx (GLIContext : %p) mode (GLenum : %s) i1 (GLint : %i) i2 (GLint : %i)\n", ctx, GLenumToString(mode).c_str(), i1, i2);
			return eval_mesh1_reenter(ctx, mode, i1, i2);
		} END_MACH_OVERRIDE_PTR(eval_mesh1, obj->disp.eval_mesh1);

		if (err)
			log(LOG_ERR, "Failed to override eval_mesh1: %i", err);

		MACH_OVERRIDE(void,eval_mesh2,(GLIContext ctx, GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2), err ) {
			file_log("eval_mesh2 called: ctx (GLIContext : %p) mode (GLenum : %s) i1 (GLint : %i) i2 (GLint : %i) j1 (GLint : %i) j2 (GLint : %i)\n", ctx, GLenumToString(mode).c_str(), i1, i2, j1, j2);
			return eval_mesh2_reenter(ctx, mode, i1, i2, j1, j2);
		} END_MACH_OVERRIDE_PTR(eval_mesh2, obj->disp.eval_mesh2);

		if (err)
			log(LOG_ERR, "Failed to override eval_mesh2: %i", err);

		MACH_OVERRIDE(void,eval_point1,(GLIContext ctx, GLint i), err ) {
			file_log("eval_point1 called: ctx (GLIContext : %p) i (GLint : %i)\n", ctx, i);
			return eval_point1_reenter(ctx, i);
		} END_MACH_OVERRIDE_PTR(eval_point1, obj->disp.eval_point1);

		if (err)
			log(LOG_ERR, "Failed to override eval_point1: %i", err);

		MACH_OVERRIDE(void,eval_point2,(GLIContext ctx, GLint i, GLint j), err ) {
			file_log("eval_point2 called: ctx (GLIContext : %p) i (GLint : %i) j (GLint : %i)\n", ctx, i, j);
			return eval_point2_reenter(ctx, i, j);
		} END_MACH_OVERRIDE_PTR(eval_point2, obj->disp.eval_point2);

		if (err)
			log(LOG_ERR, "Failed to override eval_point2: %i", err);

		MACH_OVERRIDE(void,feedback_buffer,(GLIContext ctx, GLsizei size, GLenum type, GLfloat *buffer), err ) {
			file_log("feedback_buffer called: ctx (GLIContext : %p) size (GLsizei : %i) type (GLenum : %s) buffer (GLfloat* : %p)\n", ctx, size, GLenumToString(type).c_str(), buffer);
			return feedback_buffer_reenter(ctx, size, type, buffer);
		} END_MACH_OVERRIDE_PTR(feedback_buffer, obj->disp.feedback_buffer);

		if (err)
			log(LOG_ERR, "Failed to override feedback_buffer: %i", err);

		MACH_OVERRIDE(void,finish,(GLIContext ctx), err ) {
			file_log("finish called: ctx (GLIContext : %p)\n", ctx);
			return finish_reenter(ctx);
		} END_MACH_OVERRIDE_PTR(finish, obj->disp.finish);

		if (err)
			log(LOG_ERR, "Failed to override finish: %i", err);

		MACH_OVERRIDE(void,flush,(GLIContext ctx), err ) {
			file_log("flush called: ctx (GLIContext : %p)\n", ctx);
			return flush_reenter(ctx);
		} END_MACH_OVERRIDE_PTR(flush, obj->disp.flush);

		if (err)
			log(LOG_ERR, "Failed to override flush: %i", err);

		MACH_OVERRIDE(void,fogf,(GLIContext ctx, GLenum pname, GLfloat param), err ) {
			file_log("fogf called: ctx (GLIContext : %p) pname (GLenum : %s) param (GLfloat : %f)\n", ctx, GLenumToString(pname).c_str(), param);
			return fogf_reenter(ctx, pname, param);
		} END_MACH_OVERRIDE_PTR(fogf, obj->disp.fogf);

		if (err)
			log(LOG_ERR, "Failed to override fogf: %i", err);

		MACH_OVERRIDE(void,fogfv,(GLIContext ctx, GLenum pname, const GLfloat *params), err ) {
			file_log("fogfv called: ctx (GLIContext : %p) pname (GLenum : %s) params (const GLfloat* : %p)\n", ctx, GLenumToString(pname).c_str(), params);
			return fogfv_reenter(ctx, pname, params);
		} END_MACH_OVERRIDE_PTR(fogfv, obj->disp.fogfv);

		if (err)
			log(LOG_ERR, "Failed to override fogfv: %i", err);

		MACH_OVERRIDE(void,fogi,(GLIContext ctx, GLenum pname, GLint param), err ) {
			file_log("fogi called: ctx (GLIContext : %p) pname (GLenum : %s) param (GLint : %i)\n", ctx, GLenumToString(pname).c_str(), param);
			return fogi_reenter(ctx, pname, param);
		} END_MACH_OVERRIDE_PTR(fogi, obj->disp.fogi);

		if (err)
			log(LOG_ERR, "Failed to override fogi: %i", err);

		MACH_OVERRIDE(void,fogiv,(GLIContext ctx, GLenum pname, const GLint *params), err ) {
			file_log("fogiv called: ctx (GLIContext : %p) pname (GLenum : %s) params (const GLint* : %p)\n", ctx, GLenumToString(pname).c_str(), params);
			return fogiv_reenter(ctx, pname, params);
		} END_MACH_OVERRIDE_PTR(fogiv, obj->disp.fogiv);

		if (err)
			log(LOG_ERR, "Failed to override fogiv: %i", err);

		MACH_OVERRIDE(void,front_face,(GLIContext ctx, GLenum mode), err ) {
			file_log("front_face called: ctx (GLIContext : %p) mode (GLenum : %s)\n", ctx, GLenumToString(mode).c_str());
			return front_face_reenter(ctx, mode);
		} END_MACH_OVERRIDE_PTR(front_face, obj->disp.front_face);

		if (err)
			log(LOG_ERR, "Failed to override front_face: %i", err);

		MACH_OVERRIDE(void,frustum,(GLIContext ctx, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar), err ) {
			file_log("frustum called: ctx (GLIContext : %p) left (GLdouble : %f) right (GLdouble : %f) bottom (GLdouble : %f) top (GLdouble : %f) zNear (GLdouble : %f) zFar (GLdouble : %f)\n", ctx, left, right, bottom, top, zNear, zFar);
			return frustum_reenter(ctx, left, right, bottom, top, zNear, zFar);
		} END_MACH_OVERRIDE_PTR(frustum, obj->disp.frustum);

		if (err)
			log(LOG_ERR, "Failed to override frustum: %i", err);

		MACH_OVERRIDE(GLuint,gen_lists,(GLIContext ctx, GLsizei range), err ) {
			file_log("gen_lists called: ctx (GLIContext : %p) range (GLsizei : %i)\n", ctx, range);
			GLuint result = gen_lists_reenter(ctx, range);
			return result;
		} END_MACH_OVERRIDE_PTR(gen_lists, obj->disp.gen_lists);

		if (err)
			log(LOG_ERR, "Failed to override gen_lists: %i", err);

		MACH_OVERRIDE(void,gen_textures,(GLIContext ctx, GLsizei n, GLuint *textures), err ) {
			file_log("gen_textures called: ctx (GLIContext : %p) n (GLsizei : %i) textures (GLuint* : %p)\n", ctx, n, textures);
			return gen_textures_reenter(ctx, n, textures);
		} END_MACH_OVERRIDE_PTR(gen_textures, obj->disp.gen_textures);

		if (err)
			log(LOG_ERR, "Failed to override gen_textures: %i", err);

		MACH_OVERRIDE(void,get_booleanv,(GLIContext ctx, GLenum pname, GLboolean *params), err ) {
			file_log("get_booleanv called: ctx (GLIContext : %p) pname (GLenum : %s) params (GLboolean* : %p)\n", ctx, GLenumToString(pname).c_str(), params);
			return get_booleanv_reenter(ctx, pname, params);
		} END_MACH_OVERRIDE_PTR(get_booleanv, obj->disp.get_booleanv);

		if (err)
			log(LOG_ERR, "Failed to override get_booleanv: %i", err);

		MACH_OVERRIDE(void,get_clip_plane,(GLIContext ctx, GLenum plane, GLdouble *equation), err ) {
			file_log("get_clip_plane called: ctx (GLIContext : %p) plane (GLenum : %s) equation (GLdouble* : %p)\n", ctx, GLenumToString(plane).c_str(), equation);
			return get_clip_plane_reenter(ctx, plane, equation);
		} END_MACH_OVERRIDE_PTR(get_clip_plane, obj->disp.get_clip_plane);

		if (err)
			log(LOG_ERR, "Failed to override get_clip_plane: %i", err);

		MACH_OVERRIDE(void,get_doublev,(GLIContext ctx, GLenum pname, GLdouble *params), err ) {
			file_log("get_doublev called: ctx (GLIContext : %p) pname (GLenum : %s) params (GLdouble* : %p)\n", ctx, GLenumToString(pname).c_str(), params);
			return get_doublev_reenter(ctx, pname, params);
		} END_MACH_OVERRIDE_PTR(get_doublev, obj->disp.get_doublev);

		if (err)
			log(LOG_ERR, "Failed to override get_doublev: %i", err);

		MACH_OVERRIDE(GLenum,get_error,(GLIContext ctx), err ) {
			file_log("get_error called: ctx (GLIContext : %p)\n", ctx);
			GLenum result = get_error_reenter(ctx);
			return result;
		} END_MACH_OVERRIDE_PTR(get_error, obj->disp.get_error);

		if (err)
			log(LOG_ERR, "Failed to override get_error: %i", err);

		MACH_OVERRIDE(void,get_floatv,(GLIContext ctx, GLenum pname, GLfloat *params), err ) {
			file_log("get_floatv called: ctx (GLIContext : %p) pname (GLenum : %s) params (GLfloat* : %p)\n", ctx, GLenumToString(pname).c_str(), params);
			return get_floatv_reenter(ctx, pname, params);
		} END_MACH_OVERRIDE_PTR(get_floatv, obj->disp.get_floatv);

		if (err)
			log(LOG_ERR, "Failed to override get_floatv: %i", err);

		MACH_OVERRIDE(void,get_integerv,(GLIContext ctx, GLenum pname, GLint *params), err ) {
			file_log("get_integerv called: ctx (GLIContext : %p) pname (GLenum : %s) params (GLint* : %p)\n", ctx, GLenumToString(pname).c_str(), params);
			return get_integerv_reenter(ctx, pname, params);
		} END_MACH_OVERRIDE_PTR(get_integerv, obj->disp.get_integerv);

		if (err)
			log(LOG_ERR, "Failed to override get_integerv: %i", err);

		MACH_OVERRIDE(void,get_lightfv,(GLIContext ctx, GLenum light, GLenum pname, GLfloat *params), err ) {
			file_log("get_lightfv called: ctx (GLIContext : %p) light (GLenum : %s) pname (GLenum : %s) params (GLfloat* : %p)\n", ctx, GLenumToString(light).c_str(), GLenumToString(pname).c_str(), params);
			return get_lightfv_reenter(ctx, light, pname, params);
		} END_MACH_OVERRIDE_PTR(get_lightfv, obj->disp.get_lightfv);

		if (err)
			log(LOG_ERR, "Failed to override get_lightfv: %i", err);

		MACH_OVERRIDE(void,get_lightiv,(GLIContext ctx, GLenum light, GLenum pname, GLint *params), err ) {
			file_log("get_lightiv called: ctx (GLIContext : %p) light (GLenum : %s) pname (GLenum : %s) params (GLint* : %p)\n", ctx, GLenumToString(light).c_str(), GLenumToString(pname).c_str(), params);
			return get_lightiv_reenter(ctx, light, pname, params);
		} END_MACH_OVERRIDE_PTR(get_lightiv, obj->disp.get_lightiv);

		if (err)
			log(LOG_ERR, "Failed to override get_lightiv: %i", err);

		MACH_OVERRIDE(void,get_mapdv,(GLIContext ctx, GLenum target, GLenum query, GLdouble *v), err ) {
			file_log("get_mapdv called: ctx (GLIContext : %p) target (GLenum : %s) query (GLenum : %s) v (GLdouble* : %p)\n", ctx, GLenumToString(target).c_str(), GLenumToString(query).c_str(), v);
			return get_mapdv_reenter(ctx, target, query, v);
		} END_MACH_OVERRIDE_PTR(get_mapdv, obj->disp.get_mapdv);

		if (err)
			log(LOG_ERR, "Failed to override get_mapdv: %i", err);

		MACH_OVERRIDE(void,get_mapfv,(GLIContext ctx, GLenum target, GLenum query, GLfloat *v), err ) {
			file_log("get_mapfv called: ctx (GLIContext : %p) target (GLenum : %s) query (GLenum : %s) v (GLfloat* : %p)\n", ctx, GLenumToString(target).c_str(), GLenumToString(query).c_str(), v);
			return get_mapfv_reenter(ctx, target, query, v);
		} END_MACH_OVERRIDE_PTR(get_mapfv, obj->disp.get_mapfv);

		if (err)
			log(LOG_ERR, "Failed to override get_mapfv: %i", err);

		MACH_OVERRIDE(void,get_mapiv,(GLIContext ctx, GLenum target, GLenum query, GLint *v), err ) {
			file_log("get_mapiv called: ctx (GLIContext : %p) target (GLenum : %s) query (GLenum : %s) v (GLint* : %p)\n", ctx, GLenumToString(target).c_str(), GLenumToString(query).c_str(), v);
			return get_mapiv_reenter(ctx, target, query, v);
		} END_MACH_OVERRIDE_PTR(get_mapiv, obj->disp.get_mapiv);

		if (err)
			log(LOG_ERR, "Failed to override get_mapiv: %i", err);

		MACH_OVERRIDE(void,get_materialfv,(GLIContext ctx, GLenum face, GLenum pname, GLfloat *params), err ) {
			file_log("get_materialfv called: ctx (GLIContext : %p) face (GLenum : %s) pname (GLenum : %s) params (GLfloat* : %p)\n", ctx, GLenumToString(face).c_str(), GLenumToString(pname).c_str(), params);
			return get_materialfv_reenter(ctx, face, pname, params);
		} END_MACH_OVERRIDE_PTR(get_materialfv, obj->disp.get_materialfv);

		if (err)
			log(LOG_ERR, "Failed to override get_materialfv: %i", err);

		MACH_OVERRIDE(void,get_materialiv,(GLIContext ctx, GLenum face, GLenum pname, GLint *params), err ) {
			file_log("get_materialiv called: ctx (GLIContext : %p) face (GLenum : %s) pname (GLenum : %s) params (GLint* : %p)\n", ctx, GLenumToString(face).c_str(), GLenumToString(pname).c_str(), params);
			return get_materialiv_reenter(ctx, face, pname, params);
		} END_MACH_OVERRIDE_PTR(get_materialiv, obj->disp.get_materialiv);

		if (err)
			log(LOG_ERR, "Failed to override get_materialiv: %i", err);

		MACH_OVERRIDE(void,get_pixel_mapfv,(GLIContext ctx, GLenum map, GLfloat *values), err ) {
			file_log("get_pixel_mapfv called: ctx (GLIContext : %p) map (GLenum : %s) values (GLfloat* : %p)\n", ctx, GLenumToString(map).c_str(), values);
			return get_pixel_mapfv_reenter(ctx, map, values);
		} END_MACH_OVERRIDE_PTR(get_pixel_mapfv, obj->disp.get_pixel_mapfv);

		if (err)
			log(LOG_ERR, "Failed to override get_pixel_mapfv: %i", err);

		MACH_OVERRIDE(void,get_pixel_mapuiv,(GLIContext ctx, GLenum map, GLuint *values), err ) {
			file_log("get_pixel_mapuiv called: ctx (GLIContext : %p) map (GLenum : %s) values (GLuint* : %p)\n", ctx, GLenumToString(map).c_str(), values);
			return get_pixel_mapuiv_reenter(ctx, map, values);
		} END_MACH_OVERRIDE_PTR(get_pixel_mapuiv, obj->disp.get_pixel_mapuiv);

		if (err)
			log(LOG_ERR, "Failed to override get_pixel_mapuiv: %i", err);

		MACH_OVERRIDE(void,get_pixel_mapusv,(GLIContext ctx, GLenum map, GLushort *values), err ) {
			file_log("get_pixel_mapusv called: ctx (GLIContext : %p) map (GLenum : %s) values (GLushort* : %p)\n", ctx, GLenumToString(map).c_str(), values);
			return get_pixel_mapusv_reenter(ctx, map, values);
		} END_MACH_OVERRIDE_PTR(get_pixel_mapusv, obj->disp.get_pixel_mapusv);

		if (err)
			log(LOG_ERR, "Failed to override get_pixel_mapusv: %i", err);

		MACH_OVERRIDE(void,get_pointerv,(GLIContext ctx, GLenum pname, GLvoid **params), err ) {
			file_log("get_pointerv called: ctx (GLIContext : %p) pname (GLenum : %s) params (GLvoid** : %p)\n", ctx, GLenumToString(pname).c_str(), params);
			return get_pointerv_reenter(ctx, pname, params);
		} END_MACH_OVERRIDE_PTR(get_pointerv, obj->disp.get_pointerv);

		if (err)
			log(LOG_ERR, "Failed to override get_pointerv: %i", err);

		MACH_OVERRIDE(void,get_polygon_stipple,(GLIContext ctx, GLubyte *mask), err ) {
			file_log("get_polygon_stipple called: ctx (GLIContext : %p) mask (GLubyte* : %p)\n", ctx, mask);
			return get_polygon_stipple_reenter(ctx, mask);
		} END_MACH_OVERRIDE_PTR(get_polygon_stipple, obj->disp.get_polygon_stipple);

		if (err)
			log(LOG_ERR, "Failed to override get_polygon_stipple: %i", err);

		MACH_OVERRIDE(void,get_tex_envfv,(GLIContext ctx, GLenum target, GLenum pname, GLfloat *params), err ) {
			file_log("get_tex_envfv called: ctx (GLIContext : %p) target (GLenum : %s) pname (GLenum : %s) params (GLfloat* : %p)\n", ctx, GLenumToString(target).c_str(), GLenumToString(pname).c_str(), params);
			return get_tex_envfv_reenter(ctx, target, pname, params);
		} END_MACH_OVERRIDE_PTR(get_tex_envfv, obj->disp.get_tex_envfv);

		if (err)
			log(LOG_ERR, "Failed to override get_tex_envfv: %i", err);

		MACH_OVERRIDE(void,get_tex_enviv,(GLIContext ctx, GLenum target, GLenum pname, GLint *params), err ) {
			file_log("get_tex_enviv called: ctx (GLIContext : %p) target (GLenum : %s) pname (GLenum : %s) params (GLint* : %p)\n", ctx, GLenumToString(target).c_str(), GLenumToString(pname).c_str(), params);
			return get_tex_enviv_reenter(ctx, target, pname, params);
		} END_MACH_OVERRIDE_PTR(get_tex_enviv, obj->disp.get_tex_enviv);

		if (err)
			log(LOG_ERR, "Failed to override get_tex_enviv: %i", err);

		MACH_OVERRIDE(void,get_tex_gendv,(GLIContext ctx, GLenum coord, GLenum pname, GLdouble *params), err ) {
			file_log("get_tex_gendv called: ctx (GLIContext : %p) coord (GLenum : %s) pname (GLenum : %s) params (GLdouble* : %p)\n", ctx, GLenumToString(coord).c_str(), GLenumToString(pname).c_str(), params);
			return get_tex_gendv_reenter(ctx, coord, pname, params);
		} END_MACH_OVERRIDE_PTR(get_tex_gendv, obj->disp.get_tex_gendv);

		if (err)
			log(LOG_ERR, "Failed to override get_tex_gendv: %i", err);

		MACH_OVERRIDE(void,get_tex_genfv,(GLIContext ctx, GLenum coord, GLenum pname, GLfloat *params), err ) {
			file_log("get_tex_genfv called: ctx (GLIContext : %p) coord (GLenum : %s) pname (GLenum : %s) params (GLfloat* : %p)\n", ctx, GLenumToString(coord).c_str(), GLenumToString(pname).c_str(), params);
			return get_tex_genfv_reenter(ctx, coord, pname, params);
		} END_MACH_OVERRIDE_PTR(get_tex_genfv, obj->disp.get_tex_genfv);

		if (err)
			log(LOG_ERR, "Failed to override get_tex_genfv: %i", err);

		MACH_OVERRIDE(void,get_tex_geniv,(GLIContext ctx, GLenum coord, GLenum pname, GLint *params), err ) {
			file_log("get_tex_geniv called: ctx (GLIContext : %p) coord (GLenum : %s) pname (GLenum : %s) params (GLint* : %p)\n", ctx, GLenumToString(coord).c_str(), GLenumToString(pname).c_str(), params);
			return get_tex_geniv_reenter(ctx, coord, pname, params);
		} END_MACH_OVERRIDE_PTR(get_tex_geniv, obj->disp.get_tex_geniv);

		if (err)
			log(LOG_ERR, "Failed to override get_tex_geniv: %i", err);

		MACH_OVERRIDE(void,get_tex_image,(GLIContext ctx, GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels), err ) {
			file_log("get_tex_image called: ctx (GLIContext : %p) target (GLenum : %s) level (GLint : %i) format (GLenum : %s) type (GLenum : %s) pixels (GLvoid* : %p)\n", ctx, GLenumToString(target).c_str(), level, GLenumToString(format).c_str(), GLenumToString(type).c_str(), pixels);
			return get_tex_image_reenter(ctx, target, level, format, type, pixels);
		} END_MACH_OVERRIDE_PTR(get_tex_image, obj->disp.get_tex_image);

		if (err)
			log(LOG_ERR, "Failed to override get_tex_image: %i", err);

		MACH_OVERRIDE(void,get_tex_level_parameterfv,(GLIContext ctx, GLenum target, GLint level, GLenum pname, GLfloat *params), err ) {
			file_log("get_tex_level_parameterfv called: ctx (GLIContext : %p) target (GLenum : %s) level (GLint : %i) pname (GLenum : %s) params (GLfloat* : %p)\n", ctx, GLenumToString(target).c_str(), level, GLenumToString(pname).c_str(), params);
			return get_tex_level_parameterfv_reenter(ctx, target, level, pname, params);
		} END_MACH_OVERRIDE_PTR(get_tex_level_parameterfv, obj->disp.get_tex_level_parameterfv);

		if (err)
			log(LOG_ERR, "Failed to override get_tex_level_parameterfv: %i", err);

		MACH_OVERRIDE(void,get_tex_level_parameteriv,(GLIContext ctx, GLenum target, GLint level, GLenum pname, GLint *params), err ) {
			file_log("get_tex_level_parameteriv called: ctx (GLIContext : %p) target (GLenum : %s) level (GLint : %i) pname (GLenum : %s) params (GLint* : %p)\n", ctx, GLenumToString(target).c_str(), level, GLenumToString(pname).c_str(), params);
			return get_tex_level_parameteriv_reenter(ctx, target, level, pname, params);
		} END_MACH_OVERRIDE_PTR(get_tex_level_parameteriv, obj->disp.get_tex_level_parameteriv);

		if (err)
			log(LOG_ERR, "Failed to override get_tex_level_parameteriv: %i", err);

		MACH_OVERRIDE(void,get_tex_parameterfv,(GLIContext ctx, GLenum target, GLenum pname, GLfloat *params), err ) {
			file_log("get_tex_parameterfv called: ctx (GLIContext : %p) target (GLenum : %s) pname (GLenum : %s) params (GLfloat* : %p)\n", ctx, GLenumToString(target).c_str(), GLenumToString(pname).c_str(), params);
			return get_tex_parameterfv_reenter(ctx, target, pname, params);
		} END_MACH_OVERRIDE_PTR(get_tex_parameterfv, obj->disp.get_tex_parameterfv);

		if (err)
			log(LOG_ERR, "Failed to override get_tex_parameterfv: %i", err);

		MACH_OVERRIDE(void,get_tex_parameteriv,(GLIContext ctx, GLenum target, GLenum pname, GLint *params), err ) {
			file_log("get_tex_parameteriv called: ctx (GLIContext : %p) target (GLenum : %s) pname (GLenum : %s) params (GLint* : %p)\n", ctx, GLenumToString(target).c_str(), GLenumToString(pname).c_str(), params);
			return get_tex_parameteriv_reenter(ctx, target, pname, params);
		} END_MACH_OVERRIDE_PTR(get_tex_parameteriv, obj->disp.get_tex_parameteriv);

		if (err)
			log(LOG_ERR, "Failed to override get_tex_parameteriv: %i", err);

		MACH_OVERRIDE(void,hint,(GLIContext ctx, GLenum target, GLenum mode), err ) {
			file_log("hint called: ctx (GLIContext : %p) target (GLenum : %s) mode (GLenum : %s)\n", ctx, GLenumToString(target).c_str(), GLenumToString(mode).c_str());
			return hint_reenter(ctx, target, mode);
		} END_MACH_OVERRIDE_PTR(hint, obj->disp.hint);

		if (err)
			log(LOG_ERR, "Failed to override hint: %i", err);

		MACH_OVERRIDE(void,index_mask,(GLIContext ctx, GLuint mask), err ) {
			file_log("index_mask called: ctx (GLIContext : %p) mask (GLuint : %u)\n", ctx, mask);
			return index_mask_reenter(ctx, mask);
		} END_MACH_OVERRIDE_PTR(index_mask, obj->disp.index_mask);

		if (err)
			log(LOG_ERR, "Failed to override index_mask: %i", err);

		MACH_OVERRIDE(void,index_pointer,(GLIContext ctx, GLenum type, GLsizei stride, const GLvoid *pointer), err ) {
			file_log("index_pointer called: ctx (GLIContext : %p) type (GLenum : %s) stride (GLsizei : %i) pointer (const GLvoid* : %p)\n", ctx, GLenumToString(type).c_str(), stride, pointer);
			return index_pointer_reenter(ctx, type, stride, pointer);
		} END_MACH_OVERRIDE_PTR(index_pointer, obj->disp.index_pointer);

		if (err)
			log(LOG_ERR, "Failed to override index_pointer: %i", err);

		MACH_OVERRIDE(void,indexd,(GLIContext ctx, GLdouble c), err ) {
			file_log("indexd called: ctx (GLIContext : %p) c (GLdouble : %f)\n", ctx, c);
			return indexd_reenter(ctx, c);
		} END_MACH_OVERRIDE_PTR(indexd, obj->disp.indexd);

		if (err)
			log(LOG_ERR, "Failed to override indexd: %i", err);

		MACH_OVERRIDE(void,indexdv,(GLIContext ctx, const GLdouble *c), err ) {
			file_log("indexdv called: ctx (GLIContext : %p) c (const GLdouble* : %p)\n", ctx, c);
			return indexdv_reenter(ctx, c);
		} END_MACH_OVERRIDE_PTR(indexdv, obj->disp.indexdv);

		if (err)
			log(LOG_ERR, "Failed to override indexdv: %i", err);

		MACH_OVERRIDE(void,indexf,(GLIContext ctx, GLfloat c), err ) {
			file_log("indexf called: ctx (GLIContext : %p) c (GLfloat : %f)\n", ctx, c);
			return indexf_reenter(ctx, c);
		} END_MACH_OVERRIDE_PTR(indexf, obj->disp.indexf);

		if (err)
			log(LOG_ERR, "Failed to override indexf: %i", err);

		MACH_OVERRIDE(void,indexfv,(GLIContext ctx, const GLfloat *c), err ) {
			file_log("indexfv called: ctx (GLIContext : %p) c (const GLfloat* : %p)\n", ctx, c);
			return indexfv_reenter(ctx, c);
		} END_MACH_OVERRIDE_PTR(indexfv, obj->disp.indexfv);

		if (err)
			log(LOG_ERR, "Failed to override indexfv: %i", err);

		MACH_OVERRIDE(void,indexi,(GLIContext ctx, GLint c), err ) {
			file_log("indexi called: ctx (GLIContext : %p) c (GLint : %i)\n", ctx, c);
			return indexi_reenter(ctx, c);
		} END_MACH_OVERRIDE_PTR(indexi, obj->disp.indexi);

		if (err)
			log(LOG_ERR, "Failed to override indexi: %i", err);

		MACH_OVERRIDE(void,indexiv,(GLIContext ctx, const GLint *c), err ) {
			file_log("indexiv called: ctx (GLIContext : %p) c (const GLint* : %p)\n", ctx, c);
			return indexiv_reenter(ctx, c);
		} END_MACH_OVERRIDE_PTR(indexiv, obj->disp.indexiv);

		if (err)
			log(LOG_ERR, "Failed to override indexiv: %i", err);

		MACH_OVERRIDE(void,indexs,(GLIContext ctx, GLshort c), err ) {
			file_log("indexs called: ctx (GLIContext : %p) c (GLshort : %i)\n", ctx, c);
			return indexs_reenter(ctx, c);
		} END_MACH_OVERRIDE_PTR(indexs, obj->disp.indexs);

		if (err)
			log(LOG_ERR, "Failed to override indexs: %i", err);

		MACH_OVERRIDE(void,indexsv,(GLIContext ctx, const GLshort *c), err ) {
			file_log("indexsv called: ctx (GLIContext : %p) c (const GLshort* : %p)\n", ctx, c);
			return indexsv_reenter(ctx, c);
		} END_MACH_OVERRIDE_PTR(indexsv, obj->disp.indexsv);

		if (err)
			log(LOG_ERR, "Failed to override indexsv: %i", err);

		MACH_OVERRIDE(void,indexub,(GLIContext ctx, GLubyte c), err ) {
			file_log("indexub called: ctx (GLIContext : %p) c (GLubyte : %u)\n", ctx, c);
			return indexub_reenter(ctx, c);
		} END_MACH_OVERRIDE_PTR(indexub, obj->disp.indexub);

		if (err)
			log(LOG_ERR, "Failed to override indexub: %i", err);

		MACH_OVERRIDE(void,indexubv,(GLIContext ctx, const GLubyte *c), err ) {
			file_log("indexubv called: ctx (GLIContext : %p) c (const GLubyte* : %p)\n", ctx, c);
			return indexubv_reenter(ctx, c);
		} END_MACH_OVERRIDE_PTR(indexubv, obj->disp.indexubv);

		if (err)
			log(LOG_ERR, "Failed to override indexubv: %i", err);

		MACH_OVERRIDE(void,init_names,(GLIContext ctx), err ) {
			file_log("init_names called: ctx (GLIContext : %p)\n", ctx);
			return init_names_reenter(ctx);
		} END_MACH_OVERRIDE_PTR(init_names, obj->disp.init_names);

		if (err)
			log(LOG_ERR, "Failed to override init_names: %i", err);

		MACH_OVERRIDE(void,interleaved_arrays,(GLIContext ctx, GLenum format, GLsizei stride, const GLvoid *pointer), err ) {
			file_log("interleaved_arrays called: ctx (GLIContext : %p) format (GLenum : %s) stride (GLsizei : %i) pointer (const GLvoid* : %p)\n", ctx, GLenumToString(format).c_str(), stride, pointer);
			return interleaved_arrays_reenter(ctx, format, stride, pointer);
		} END_MACH_OVERRIDE_PTR(interleaved_arrays, obj->disp.interleaved_arrays);

		if (err)
			log(LOG_ERR, "Failed to override interleaved_arrays: %i", err);

		MACH_OVERRIDE(GLboolean,is_enabled,(GLIContext ctx, GLenum cap), err ) {
			file_log("is_enabled called: ctx (GLIContext : %p) cap (GLenum : %s)\n", ctx, GLenumToString(cap).c_str());
			GLboolean result = is_enabled_reenter(ctx, cap);
			return result;
		} END_MACH_OVERRIDE_PTR(is_enabled, obj->disp.is_enabled);

		if (err)
			log(LOG_ERR, "Failed to override is_enabled: %i", err);

		MACH_OVERRIDE(GLboolean,is_list,(GLIContext ctx, GLuint list), err ) {
			file_log("is_list called: ctx (GLIContext : %p) list (GLuint : %u)\n", ctx, list);
			GLboolean result = is_list_reenter(ctx, list);
			return result;
		} END_MACH_OVERRIDE_PTR(is_list, obj->disp.is_list);

		if (err)
			log(LOG_ERR, "Failed to override is_list: %i", err);

		MACH_OVERRIDE(GLboolean,is_texture,(GLIContext ctx, GLuint texture), err ) {
			file_log("is_texture called: ctx (GLIContext : %p) texture (GLuint : %u)\n", ctx, texture);
			GLboolean result = is_texture_reenter(ctx, texture);
			return result;
		} END_MACH_OVERRIDE_PTR(is_texture, obj->disp.is_texture);

		if (err)
			log(LOG_ERR, "Failed to override is_texture: %i", err);

		MACH_OVERRIDE(void,light_modelf,(GLIContext ctx, GLenum pname, GLfloat param), err ) {
			file_log("light_modelf called: ctx (GLIContext : %p) pname (GLenum : %s) param (GLfloat : %f)\n", ctx, GLenumToString(pname).c_str(), param);
			return light_modelf_reenter(ctx, pname, param);
		} END_MACH_OVERRIDE_PTR(light_modelf, obj->disp.light_modelf);

		if (err)
			log(LOG_ERR, "Failed to override light_modelf: %i", err);

		MACH_OVERRIDE(void,light_modelfv,(GLIContext ctx, GLenum pname, const GLfloat *params), err ) {
			file_log("light_modelfv called: ctx (GLIContext : %p) pname (GLenum : %s) params (const GLfloat* : %p)\n", ctx, GLenumToString(pname).c_str(), params);
			return light_modelfv_reenter(ctx, pname, params);
		} END_MACH_OVERRIDE_PTR(light_modelfv, obj->disp.light_modelfv);

		if (err)
			log(LOG_ERR, "Failed to override light_modelfv: %i", err);

		MACH_OVERRIDE(void,light_modeli,(GLIContext ctx, GLenum pname, GLint param), err ) {
			file_log("light_modeli called: ctx (GLIContext : %p) pname (GLenum : %s) param (GLint : %i)\n", ctx, GLenumToString(pname).c_str(), param);
			return light_modeli_reenter(ctx, pname, param);
		} END_MACH_OVERRIDE_PTR(light_modeli, obj->disp.light_modeli);

		if (err)
			log(LOG_ERR, "Failed to override light_modeli: %i", err);

		MACH_OVERRIDE(void,light_modeliv,(GLIContext ctx, GLenum pname, const GLint *params), err ) {
			file_log("light_modeliv called: ctx (GLIContext : %p) pname (GLenum : %s) params (const GLint* : %p)\n", ctx, GLenumToString(pname).c_str(), params);
			return light_modeliv_reenter(ctx, pname, params);
		} END_MACH_OVERRIDE_PTR(light_modeliv, obj->disp.light_modeliv);

		if (err)
			log(LOG_ERR, "Failed to override light_modeliv: %i", err);

		MACH_OVERRIDE(void,lightf,(GLIContext ctx, GLenum light, GLenum pname, GLfloat param), err ) {
			file_log("lightf called: ctx (GLIContext : %p) light (GLenum : %s) pname (GLenum : %s) param (GLfloat : %f)\n", ctx, GLenumToString(light).c_str(), GLenumToString(pname).c_str(), param);
			return lightf_reenter(ctx, light, pname, param);
		} END_MACH_OVERRIDE_PTR(lightf, obj->disp.lightf);

		if (err)
			log(LOG_ERR, "Failed to override lightf: %i", err);

		MACH_OVERRIDE(void,lightfv,(GLIContext ctx, GLenum light, GLenum pname, const GLfloat *params), err ) {
			file_log("lightfv called: ctx (GLIContext : %p) light (GLenum : %s) pname (GLenum : %s) params (const GLfloat* : %p)\n", ctx, GLenumToString(light).c_str(), GLenumToString(pname).c_str(), params);
			return lightfv_reenter(ctx, light, pname, params);
		} END_MACH_OVERRIDE_PTR(lightfv, obj->disp.lightfv);

		if (err)
			log(LOG_ERR, "Failed to override lightfv: %i", err);

		MACH_OVERRIDE(void,lighti,(GLIContext ctx, GLenum light, GLenum pname, GLint param), err ) {
			file_log("lighti called: ctx (GLIContext : %p) light (GLenum : %s) pname (GLenum : %s) param (GLint : %i)\n", ctx, GLenumToString(light).c_str(), GLenumToString(pname).c_str(), param);
			return lighti_reenter(ctx, light, pname, param);
		} END_MACH_OVERRIDE_PTR(lighti, obj->disp.lighti);

		if (err)
			log(LOG_ERR, "Failed to override lighti: %i", err);

		MACH_OVERRIDE(void,lightiv,(GLIContext ctx, GLenum light, GLenum pname, const GLint *params), err ) {
			file_log("lightiv called: ctx (GLIContext : %p) light (GLenum : %s) pname (GLenum : %s) params (const GLint* : %p)\n", ctx, GLenumToString(light).c_str(), GLenumToString(pname).c_str(), params);
			return lightiv_reenter(ctx, light, pname, params);
		} END_MACH_OVERRIDE_PTR(lightiv, obj->disp.lightiv);

		if (err)
			log(LOG_ERR, "Failed to override lightiv: %i", err);

		MACH_OVERRIDE(void,line_stipple,(GLIContext ctx, GLint factor, GLushort pattern), err ) {
			file_log("line_stipple called: ctx (GLIContext : %p) factor (GLint : %i) pattern (GLushort : %u)\n", ctx, factor, pattern);
			return line_stipple_reenter(ctx, factor, pattern);
		} END_MACH_OVERRIDE_PTR(line_stipple, obj->disp.line_stipple);

		if (err)
			log(LOG_ERR, "Failed to override line_stipple: %i", err);

		MACH_OVERRIDE(void,line_width,(GLIContext ctx, GLfloat width), err ) {
			file_log("line_width called: ctx (GLIContext : %p) width (GLfloat : %f)\n", ctx, width);
			return line_width_reenter(ctx, width);
		} END_MACH_OVERRIDE_PTR(line_width, obj->disp.line_width);

		if (err)
			log(LOG_ERR, "Failed to override line_width: %i", err);

		MACH_OVERRIDE(void,list_base,(GLIContext ctx, GLuint base), err ) {
			file_log("list_base called: ctx (GLIContext : %p) base (GLuint : %u)\n", ctx, base);
			return list_base_reenter(ctx, base);
		} END_MACH_OVERRIDE_PTR(list_base, obj->disp.list_base);

		if (err)
			log(LOG_ERR, "Failed to override list_base: %i", err);

		MACH_OVERRIDE(void,load_identity,(GLIContext ctx), err ) {
			file_log("load_identity called: ctx (GLIContext : %p)\n", ctx);
			return load_identity_reenter(ctx);
		} END_MACH_OVERRIDE_PTR(load_identity, obj->disp.load_identity);

		if (err)
			log(LOG_ERR, "Failed to override load_identity: %i", err);

		MACH_OVERRIDE(void,load_matrixd,(GLIContext ctx, const GLdouble *m), err ) {
			file_log("load_matrixd called: ctx (GLIContext : %p) m (const GLdouble* : %p)\n", ctx, m);
			return load_matrixd_reenter(ctx, m);
		} END_MACH_OVERRIDE_PTR(load_matrixd, obj->disp.load_matrixd);

		if (err)
			log(LOG_ERR, "Failed to override load_matrixd: %i", err);

		MACH_OVERRIDE(void,load_matrixf,(GLIContext ctx, const GLfloat *m), err ) {
			file_log("load_matrixf called: ctx (GLIContext : %p) m (const GLfloat* : %p)\n", ctx, m);
			return load_matrixf_reenter(ctx, m);
		} END_MACH_OVERRIDE_PTR(load_matrixf, obj->disp.load_matrixf);

		if (err)
			log(LOG_ERR, "Failed to override load_matrixf: %i", err);

		MACH_OVERRIDE(void,load_name,(GLIContext ctx, GLuint name), err ) {
			file_log("load_name called: ctx (GLIContext : %p) name (GLuint : %u)\n", ctx, name);
			return load_name_reenter(ctx, name);
		} END_MACH_OVERRIDE_PTR(load_name, obj->disp.load_name);

		if (err)
			log(LOG_ERR, "Failed to override load_name: %i", err);

		MACH_OVERRIDE(void,logic_op,(GLIContext ctx, GLenum opcode), err ) {
			file_log("logic_op called: ctx (GLIContext : %p) opcode (GLenum : %s)\n", ctx, GLenumToString(opcode).c_str());
			return logic_op_reenter(ctx, opcode);
		} END_MACH_OVERRIDE_PTR(logic_op, obj->disp.logic_op);

		if (err)
			log(LOG_ERR, "Failed to override logic_op: %i", err);

		MACH_OVERRIDE(void,map1d,(GLIContext ctx, GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points), err ) {
			file_log("map1d called: ctx (GLIContext : %p) target (GLenum : %s) u1 (GLdouble : %f) u2 (GLdouble : %f) stride (GLint : %i) order (GLint : %i) points (const GLdouble* : %p)\n", ctx, GLenumToString(target).c_str(), u1, u2, stride, order, points);
			return map1d_reenter(ctx, target, u1, u2, stride, order, points);
		} END_MACH_OVERRIDE_PTR(map1d, obj->disp.map1d);

		if (err)
			log(LOG_ERR, "Failed to override map1d: %i", err);

		MACH_OVERRIDE(void,map1f,(GLIContext ctx, GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points), err ) {
			file_log("map1f called: ctx (GLIContext : %p) target (GLenum : %s) u1 (GLfloat : %f) u2 (GLfloat : %f) stride (GLint : %i) order (GLint : %i) points (const GLfloat* : %p)\n", ctx, GLenumToString(target).c_str(), u1, u2, stride, order, points);
			return map1f_reenter(ctx, target, u1, u2, stride, order, points);
		} END_MACH_OVERRIDE_PTR(map1f, obj->disp.map1f);

		if (err)
			log(LOG_ERR, "Failed to override map1f: %i", err);

		MACH_OVERRIDE(void,map2d,(GLIContext ctx, GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points), err ) {
			file_log("map2d called: ctx (GLIContext : %p) target (GLenum : %s) u1 (GLdouble : %f) u2 (GLdouble : %f) ustride (GLint : %i) uorder (GLint : %i) v1 (GLdouble : %f) v2 (GLdouble : %f) vstride (GLint : %i) vorder (GLint : %i) points (const GLdouble* : %p)\n", ctx, GLenumToString(target).c_str(), u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
			return map2d_reenter(ctx, target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
		} END_MACH_OVERRIDE_PTR(map2d, obj->disp.map2d);

		if (err)
			log(LOG_ERR, "Failed to override map2d: %i", err);

		MACH_OVERRIDE(void,map2f,(GLIContext ctx, GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points), err ) {
			file_log("map2f called: ctx (GLIContext : %p) target (GLenum : %s) u1 (GLfloat : %f) u2 (GLfloat : %f) ustride (GLint : %i) uorder (GLint : %i) v1 (GLfloat : %f) v2 (GLfloat : %f) vstride (GLint : %i) vorder (GLint : %i) points (const GLfloat* : %p)\n", ctx, GLenumToString(target).c_str(), u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
			return map2f_reenter(ctx, target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
		} END_MACH_OVERRIDE_PTR(map2f, obj->disp.map2f);

		if (err)
			log(LOG_ERR, "Failed to override map2f: %i", err);

		MACH_OVERRIDE(void,map_grid1d,(GLIContext ctx, GLint un, GLdouble u1, GLdouble u2), err ) {
			file_log("map_grid1d called: ctx (GLIContext : %p) un (GLint : %i) u1 (GLdouble : %f) u2 (GLdouble : %f)\n", ctx, un, u1, u2);
			return map_grid1d_reenter(ctx, un, u1, u2);
		} END_MACH_OVERRIDE_PTR(map_grid1d, obj->disp.map_grid1d);

		if (err)
			log(LOG_ERR, "Failed to override map_grid1d: %i", err);

		MACH_OVERRIDE(void,map_grid1f,(GLIContext ctx, GLint un, GLfloat u1, GLfloat u2), err ) {
			file_log("map_grid1f called: ctx (GLIContext : %p) un (GLint : %i) u1 (GLfloat : %f) u2 (GLfloat : %f)\n", ctx, un, u1, u2);
			return map_grid1f_reenter(ctx, un, u1, u2);
		} END_MACH_OVERRIDE_PTR(map_grid1f, obj->disp.map_grid1f);

		if (err)
			log(LOG_ERR, "Failed to override map_grid1f: %i", err);

		MACH_OVERRIDE(void,map_grid2d,(GLIContext ctx, GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2), err ) {
			file_log("map_grid2d called: ctx (GLIContext : %p) un (GLint : %i) u1 (GLdouble : %f) u2 (GLdouble : %f) vn (GLint : %i) v1 (GLdouble : %f) v2 (GLdouble : %f)\n", ctx, un, u1, u2, vn, v1, v2);
			return map_grid2d_reenter(ctx, un, u1, u2, vn, v1, v2);
		} END_MACH_OVERRIDE_PTR(map_grid2d, obj->disp.map_grid2d);

		if (err)
			log(LOG_ERR, "Failed to override map_grid2d: %i", err);

		MACH_OVERRIDE(void,map_grid2f,(GLIContext ctx, GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2), err ) {
			file_log("map_grid2f called: ctx (GLIContext : %p) un (GLint : %i) u1 (GLfloat : %f) u2 (GLfloat : %f) vn (GLint : %i) v1 (GLfloat : %f) v2 (GLfloat : %f)\n", ctx, un, u1, u2, vn, v1, v2);
			return map_grid2f_reenter(ctx, un, u1, u2, vn, v1, v2);
		} END_MACH_OVERRIDE_PTR(map_grid2f, obj->disp.map_grid2f);

		if (err)
			log(LOG_ERR, "Failed to override map_grid2f: %i", err);

		MACH_OVERRIDE(void,materialf,(GLIContext ctx, GLenum face, GLenum pname, GLfloat param), err ) {
			file_log("materialf called: ctx (GLIContext : %p) face (GLenum : %s) pname (GLenum : %s) param (GLfloat : %f)\n", ctx, GLenumToString(face).c_str(), GLenumToString(pname).c_str(), param);
			return materialf_reenter(ctx, face, pname, param);
		} END_MACH_OVERRIDE_PTR(materialf, obj->disp.materialf);

		if (err)
			log(LOG_ERR, "Failed to override materialf: %i", err);

		MACH_OVERRIDE(void,materialfv,(GLIContext ctx, GLenum face, GLenum pname, const GLfloat *params), err ) {
			file_log("materialfv called: ctx (GLIContext : %p) face (GLenum : %s) pname (GLenum : %s) params (const GLfloat* : %p)\n", ctx, GLenumToString(face).c_str(), GLenumToString(pname).c_str(), params);
			return materialfv_reenter(ctx, face, pname, params);
		} END_MACH_OVERRIDE_PTR(materialfv, obj->disp.materialfv);

		if (err)
			log(LOG_ERR, "Failed to override materialfv: %i", err);

		MACH_OVERRIDE(void,materiali,(GLIContext ctx, GLenum face, GLenum pname, GLint param), err ) {
			file_log("materiali called: ctx (GLIContext : %p) face (GLenum : %s) pname (GLenum : %s) param (GLint : %i)\n", ctx, GLenumToString(face).c_str(), GLenumToString(pname).c_str(), param);
			return materiali_reenter(ctx, face, pname, param);
		} END_MACH_OVERRIDE_PTR(materiali, obj->disp.materiali);

		if (err)
			log(LOG_ERR, "Failed to override materiali: %i", err);

		MACH_OVERRIDE(void,materialiv,(GLIContext ctx, GLenum face, GLenum pname, const GLint *params), err ) {
			file_log("materialiv called: ctx (GLIContext : %p) face (GLenum : %s) pname (GLenum : %s) params (const GLint* : %p)\n", ctx, GLenumToString(face).c_str(), GLenumToString(pname).c_str(), params);
			return materialiv_reenter(ctx, face, pname, params);
		} END_MACH_OVERRIDE_PTR(materialiv, obj->disp.materialiv);

		if (err)
			log(LOG_ERR, "Failed to override materialiv: %i", err);

		MACH_OVERRIDE(void,matrix_mode,(GLIContext ctx, GLenum mode), err ) {
			file_log("matrix_mode called: ctx (GLIContext : %p) mode (GLenum : %s)\n", ctx, GLenumToString(mode).c_str());
			return matrix_mode_reenter(ctx, mode);
		} END_MACH_OVERRIDE_PTR(matrix_mode, obj->disp.matrix_mode);

		if (err)
			log(LOG_ERR, "Failed to override matrix_mode: %i", err);

		MACH_OVERRIDE(void,mult_matrixd,(GLIContext ctx, const GLdouble *m), err ) {
			file_log("mult_matrixd called: ctx (GLIContext : %p) m (const GLdouble* : %p)\n", ctx, m);
			return mult_matrixd_reenter(ctx, m);
		} END_MACH_OVERRIDE_PTR(mult_matrixd, obj->disp.mult_matrixd);

		if (err)
			log(LOG_ERR, "Failed to override mult_matrixd: %i", err);

		MACH_OVERRIDE(void,mult_matrixf,(GLIContext ctx, const GLfloat *m), err ) {
			file_log("mult_matrixf called: ctx (GLIContext : %p) m (const GLfloat* : %p)\n", ctx, m);
			return mult_matrixf_reenter(ctx, m);
		} END_MACH_OVERRIDE_PTR(mult_matrixf, obj->disp.mult_matrixf);

		if (err)
			log(LOG_ERR, "Failed to override mult_matrixf: %i", err);

		MACH_OVERRIDE(void,new_list,(GLIContext ctx, GLuint list, GLenum mode), err ) {
			file_log("new_list called: ctx (GLIContext : %p) list (GLuint : %u) mode (GLenum : %s)\n", ctx, list, GLenumToString(mode).c_str());
			return new_list_reenter(ctx, list, mode);
		} END_MACH_OVERRIDE_PTR(new_list, obj->disp.new_list);

		if (err)
			log(LOG_ERR, "Failed to override new_list: %i", err);

		MACH_OVERRIDE(void,normal3b,(GLIContext ctx, GLbyte nx, GLbyte ny, GLbyte nz), err ) {
			file_log("normal3b called: ctx (GLIContext : %p) nx (GLbyte : %i) ny (GLbyte : %i) nz (GLbyte : %i)\n", ctx, nx, ny, nz);
			return normal3b_reenter(ctx, nx, ny, nz);
		} END_MACH_OVERRIDE_PTR(normal3b, obj->disp.normal3b);

		if (err)
			log(LOG_ERR, "Failed to override normal3b: %i", err);

		MACH_OVERRIDE(void,normal3bv,(GLIContext ctx, const GLbyte *v), err ) {
			file_log("normal3bv called: ctx (GLIContext : %p) v (const GLbyte* : %p)\n", ctx, v);
			return normal3bv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(normal3bv, obj->disp.normal3bv);

		if (err)
			log(LOG_ERR, "Failed to override normal3bv: %i", err);

		MACH_OVERRIDE(void,normal3d,(GLIContext ctx, GLdouble nx, GLdouble ny, GLdouble nz), err ) {
			file_log("normal3d called: ctx (GLIContext : %p) nx (GLdouble : %f) ny (GLdouble : %f) nz (GLdouble : %f)\n", ctx, nx, ny, nz);
			return normal3d_reenter(ctx, nx, ny, nz);
		} END_MACH_OVERRIDE_PTR(normal3d, obj->disp.normal3d);

		if (err)
			log(LOG_ERR, "Failed to override normal3d: %i", err);

		MACH_OVERRIDE(void,normal3dv,(GLIContext ctx, const GLdouble *v), err ) {
			file_log("normal3dv called: ctx (GLIContext : %p) v (const GLdouble* : %p)\n", ctx, v);
			return normal3dv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(normal3dv, obj->disp.normal3dv);

		if (err)
			log(LOG_ERR, "Failed to override normal3dv: %i", err);

		MACH_OVERRIDE(void,normal3f,(GLIContext ctx, GLfloat nx, GLfloat ny, GLfloat nz), err ) {
			file_log("normal3f called: ctx (GLIContext : %p) nx (GLfloat : %f) ny (GLfloat : %f) nz (GLfloat : %f)\n", ctx, nx, ny, nz);
			return normal3f_reenter(ctx, nx, ny, nz);
		} END_MACH_OVERRIDE_PTR(normal3f, obj->disp.normal3f);

		if (err)
			log(LOG_ERR, "Failed to override normal3f: %i", err);

		MACH_OVERRIDE(void,normal3fv,(GLIContext ctx, const GLfloat *v), err ) {
			file_log("normal3fv called: ctx (GLIContext : %p) v (const GLfloat* : %p)\n", ctx, v);
			return normal3fv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(normal3fv, obj->disp.normal3fv);

		if (err)
			log(LOG_ERR, "Failed to override normal3fv: %i", err);

		MACH_OVERRIDE(void,normal3i,(GLIContext ctx, GLint nx, GLint ny, GLint nz), err ) {
			file_log("normal3i called: ctx (GLIContext : %p) nx (GLint : %i) ny (GLint : %i) nz (GLint : %i)\n", ctx, nx, ny, nz);
			return normal3i_reenter(ctx, nx, ny, nz);
		} END_MACH_OVERRIDE_PTR(normal3i, obj->disp.normal3i);

		if (err)
			log(LOG_ERR, "Failed to override normal3i: %i", err);

		MACH_OVERRIDE(void,normal3iv,(GLIContext ctx, const GLint *v), err ) {
			file_log("normal3iv called: ctx (GLIContext : %p) v (const GLint* : %p)\n", ctx, v);
			return normal3iv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(normal3iv, obj->disp.normal3iv);

		if (err)
			log(LOG_ERR, "Failed to override normal3iv: %i", err);

		MACH_OVERRIDE(void,normal3s,(GLIContext ctx, GLshort nx, GLshort ny, GLshort nz), err ) {
			file_log("normal3s called: ctx (GLIContext : %p) nx (GLshort : %i) ny (GLshort : %i) nz (GLshort : %i)\n", ctx, nx, ny, nz);
			return normal3s_reenter(ctx, nx, ny, nz);
		} END_MACH_OVERRIDE_PTR(normal3s, obj->disp.normal3s);

		if (err)
			log(LOG_ERR, "Failed to override normal3s: %i", err);

		MACH_OVERRIDE(void,normal3sv,(GLIContext ctx, const GLshort *v), err ) {
			file_log("normal3sv called: ctx (GLIContext : %p) v (const GLshort* : %p)\n", ctx, v);
			return normal3sv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(normal3sv, obj->disp.normal3sv);

		if (err)
			log(LOG_ERR, "Failed to override normal3sv: %i", err);

		MACH_OVERRIDE(void,normal_pointer,(GLIContext ctx, GLenum type, GLsizei stride, const GLvoid *pointer), err ) {
			file_log("normal_pointer called: ctx (GLIContext : %p) type (GLenum : %s) stride (GLsizei : %i) pointer (const GLvoid* : %p)\n", ctx, GLenumToString(type).c_str(), stride, pointer);
			return normal_pointer_reenter(ctx, type, stride, pointer);
		} END_MACH_OVERRIDE_PTR(normal_pointer, obj->disp.normal_pointer);

		if (err)
			log(LOG_ERR, "Failed to override normal_pointer: %i", err);

		MACH_OVERRIDE(void,ortho,(GLIContext ctx, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar), err ) {
			file_log("ortho called: ctx (GLIContext : %p) left (GLdouble : %f) right (GLdouble : %f) bottom (GLdouble : %f) top (GLdouble : %f) zNear (GLdouble : %f) zFar (GLdouble : %f)\n", ctx, left, right, bottom, top, zNear, zFar);
			return ortho_reenter(ctx, left, right, bottom, top, zNear, zFar);
		} END_MACH_OVERRIDE_PTR(ortho, obj->disp.ortho);

		if (err)
			log(LOG_ERR, "Failed to override ortho: %i", err);

		MACH_OVERRIDE(void,pass_through,(GLIContext ctx, GLfloat token), err ) {
			file_log("pass_through called: ctx (GLIContext : %p) token (GLfloat : %f)\n", ctx, token);
			return pass_through_reenter(ctx, token);
		} END_MACH_OVERRIDE_PTR(pass_through, obj->disp.pass_through);

		if (err)
			log(LOG_ERR, "Failed to override pass_through: %i", err);

		MACH_OVERRIDE(void,pixel_mapfv,(GLIContext ctx, GLenum map, GLsizei mapsize, const GLfloat *values), err ) {
			file_log("pixel_mapfv called: ctx (GLIContext : %p) map (GLenum : %s) mapsize (GLsizei : %i) values (const GLfloat* : %p)\n", ctx, GLenumToString(map).c_str(), mapsize, values);
			return pixel_mapfv_reenter(ctx, map, mapsize, values);
		} END_MACH_OVERRIDE_PTR(pixel_mapfv, obj->disp.pixel_mapfv);

		if (err)
			log(LOG_ERR, "Failed to override pixel_mapfv: %i", err);

		MACH_OVERRIDE(void,pixel_mapuiv,(GLIContext ctx, GLenum map, GLsizei mapsize, const GLuint *values), err ) {
			file_log("pixel_mapuiv called: ctx (GLIContext : %p) map (GLenum : %s) mapsize (GLsizei : %i) values (const GLuint* : %p)\n", ctx, GLenumToString(map).c_str(), mapsize, values);
			return pixel_mapuiv_reenter(ctx, map, mapsize, values);
		} END_MACH_OVERRIDE_PTR(pixel_mapuiv, obj->disp.pixel_mapuiv);

		if (err)
			log(LOG_ERR, "Failed to override pixel_mapuiv: %i", err);

		MACH_OVERRIDE(void,pixel_mapusv,(GLIContext ctx, GLenum map, GLsizei mapsize, const GLushort *values), err ) {
			file_log("pixel_mapusv called: ctx (GLIContext : %p) map (GLenum : %s) mapsize (GLsizei : %i) values (const GLushort* : %p)\n", ctx, GLenumToString(map).c_str(), mapsize, values);
			return pixel_mapusv_reenter(ctx, map, mapsize, values);
		} END_MACH_OVERRIDE_PTR(pixel_mapusv, obj->disp.pixel_mapusv);

		if (err)
			log(LOG_ERR, "Failed to override pixel_mapusv: %i", err);

		MACH_OVERRIDE(void,pixel_storef,(GLIContext ctx, GLenum pname, GLfloat param), err ) {
			file_log("pixel_storef called: ctx (GLIContext : %p) pname (GLenum : %s) param (GLfloat : %f)\n", ctx, GLenumToString(pname).c_str(), param);
			return pixel_storef_reenter(ctx, pname, param);
		} END_MACH_OVERRIDE_PTR(pixel_storef, obj->disp.pixel_storef);

		if (err)
			log(LOG_ERR, "Failed to override pixel_storef: %i", err);

		MACH_OVERRIDE(void,pixel_storei,(GLIContext ctx, GLenum pname, GLint param), err ) {
			file_log("pixel_storei called: ctx (GLIContext : %p) pname (GLenum : %s) param (GLint : %i)\n", ctx, GLenumToString(pname).c_str(), param);
			return pixel_storei_reenter(ctx, pname, param);
		} END_MACH_OVERRIDE_PTR(pixel_storei, obj->disp.pixel_storei);

		if (err)
			log(LOG_ERR, "Failed to override pixel_storei: %i", err);

		MACH_OVERRIDE(void,pixel_transferf,(GLIContext ctx, GLenum pname, GLfloat param), err ) {
			file_log("pixel_transferf called: ctx (GLIContext : %p) pname (GLenum : %s) param (GLfloat : %f)\n", ctx, GLenumToString(pname).c_str(), param);
			return pixel_transferf_reenter(ctx, pname, param);
		} END_MACH_OVERRIDE_PTR(pixel_transferf, obj->disp.pixel_transferf);

		if (err)
			log(LOG_ERR, "Failed to override pixel_transferf: %i", err);

		MACH_OVERRIDE(void,pixel_transferi,(GLIContext ctx, GLenum pname, GLint param), err ) {
			file_log("pixel_transferi called: ctx (GLIContext : %p) pname (GLenum : %s) param (GLint : %i)\n", ctx, GLenumToString(pname).c_str(), param);
			return pixel_transferi_reenter(ctx, pname, param);
		} END_MACH_OVERRIDE_PTR(pixel_transferi, obj->disp.pixel_transferi);

		if (err)
			log(LOG_ERR, "Failed to override pixel_transferi: %i", err);

		MACH_OVERRIDE(void,pixel_zoom,(GLIContext ctx, GLfloat xfactor, GLfloat yfactor), err ) {
			file_log("pixel_zoom called: ctx (GLIContext : %p) xfactor (GLfloat : %f) yfactor (GLfloat : %f)\n", ctx, xfactor, yfactor);
			return pixel_zoom_reenter(ctx, xfactor, yfactor);
		} END_MACH_OVERRIDE_PTR(pixel_zoom, obj->disp.pixel_zoom);

		if (err)
			log(LOG_ERR, "Failed to override pixel_zoom: %i", err);

		MACH_OVERRIDE(void,point_size,(GLIContext ctx, GLfloat size), err ) {
			file_log("point_size called: ctx (GLIContext : %p) size (GLfloat : %f)\n", ctx, size);
			return point_size_reenter(ctx, size);
		} END_MACH_OVERRIDE_PTR(point_size, obj->disp.point_size);

		if (err)
			log(LOG_ERR, "Failed to override point_size: %i", err);

		MACH_OVERRIDE(void,polygon_mode,(GLIContext ctx, GLenum face, GLenum mode), err ) {
			file_log("polygon_mode called: ctx (GLIContext : %p) face (GLenum : %s) mode (GLenum : %s)\n", ctx, GLenumToString(face).c_str(), GLenumToString(mode).c_str());
			return polygon_mode_reenter(ctx, face, mode);
		} END_MACH_OVERRIDE_PTR(polygon_mode, obj->disp.polygon_mode);

		if (err)
			log(LOG_ERR, "Failed to override polygon_mode: %i", err);

		MACH_OVERRIDE(void,polygon_offset,(GLIContext ctx, GLfloat factor, GLfloat units), err ) {
			file_log("polygon_offset called: ctx (GLIContext : %p) factor (GLfloat : %f) units (GLfloat : %f)\n", ctx, factor, units);
			return polygon_offset_reenter(ctx, factor, units);
		} END_MACH_OVERRIDE_PTR(polygon_offset, obj->disp.polygon_offset);

		if (err)
			log(LOG_ERR, "Failed to override polygon_offset: %i", err);

		MACH_OVERRIDE(void,polygon_stipple,(GLIContext ctx, const GLubyte *mask), err ) {
			file_log("polygon_stipple called: ctx (GLIContext : %p) mask (const GLubyte* : %p)\n", ctx, mask);
			return polygon_stipple_reenter(ctx, mask);
		} END_MACH_OVERRIDE_PTR(polygon_stipple, obj->disp.polygon_stipple);

		if (err)
			log(LOG_ERR, "Failed to override polygon_stipple: %i", err);

		MACH_OVERRIDE(void,pop_attrib,(GLIContext ctx), err ) {
			file_log("pop_attrib called: ctx (GLIContext : %p)\n", ctx);
			return pop_attrib_reenter(ctx);
		} END_MACH_OVERRIDE_PTR(pop_attrib, obj->disp.pop_attrib);

		if (err)
			log(LOG_ERR, "Failed to override pop_attrib: %i", err);

		MACH_OVERRIDE(void,pop_client_attrib,(GLIContext ctx), err ) {
			file_log("pop_client_attrib called: ctx (GLIContext : %p)\n", ctx);
			return pop_client_attrib_reenter(ctx);
		} END_MACH_OVERRIDE_PTR(pop_client_attrib, obj->disp.pop_client_attrib);

		if (err)
			log(LOG_ERR, "Failed to override pop_client_attrib: %i", err);

		MACH_OVERRIDE(void,pop_matrix,(GLIContext ctx), err ) {
			file_log("pop_matrix called: ctx (GLIContext : %p)\n", ctx);
			return pop_matrix_reenter(ctx);
		} END_MACH_OVERRIDE_PTR(pop_matrix, obj->disp.pop_matrix);

		if (err)
			log(LOG_ERR, "Failed to override pop_matrix: %i", err);

		MACH_OVERRIDE(void,pop_name,(GLIContext ctx), err ) {
			file_log("pop_name called: ctx (GLIContext : %p)\n", ctx);
			return pop_name_reenter(ctx);
		} END_MACH_OVERRIDE_PTR(pop_name, obj->disp.pop_name);

		if (err)
			log(LOG_ERR, "Failed to override pop_name: %i", err);

		MACH_OVERRIDE(void,prioritize_textures,(GLIContext ctx, GLsizei n, const GLuint *textures, const GLclampf *priorities), err ) {
			file_log("prioritize_textures called: ctx (GLIContext : %p) n (GLsizei : %i) textures (const GLuint* : %p) priorities (const GLclampf* : %p)\n", ctx, n, textures, priorities);
			return prioritize_textures_reenter(ctx, n, textures, priorities);
		} END_MACH_OVERRIDE_PTR(prioritize_textures, obj->disp.prioritize_textures);

		if (err)
			log(LOG_ERR, "Failed to override prioritize_textures: %i", err);

		MACH_OVERRIDE(void,push_attrib,(GLIContext ctx, GLbitfield mask), err ) {
			file_log("push_attrib called: ctx (GLIContext : %p) mask (GLbitfield : %u)\n", ctx, mask);
			return push_attrib_reenter(ctx, mask);
		} END_MACH_OVERRIDE_PTR(push_attrib, obj->disp.push_attrib);

		if (err)
			log(LOG_ERR, "Failed to override push_attrib: %i", err);

		MACH_OVERRIDE(void,push_client_attrib,(GLIContext ctx, GLbitfield mask), err ) {
			file_log("push_client_attrib called: ctx (GLIContext : %p) mask (GLbitfield : %u)\n", ctx, mask);
			return push_client_attrib_reenter(ctx, mask);
		} END_MACH_OVERRIDE_PTR(push_client_attrib, obj->disp.push_client_attrib);

		if (err)
			log(LOG_ERR, "Failed to override push_client_attrib: %i", err);

		MACH_OVERRIDE(void,push_matrix,(GLIContext ctx), err ) {
			file_log("push_matrix called: ctx (GLIContext : %p)\n", ctx);
			return push_matrix_reenter(ctx);
		} END_MACH_OVERRIDE_PTR(push_matrix, obj->disp.push_matrix);

		if (err)
			log(LOG_ERR, "Failed to override push_matrix: %i", err);

		MACH_OVERRIDE(void,push_name,(GLIContext ctx, GLuint name), err ) {
			file_log("push_name called: ctx (GLIContext : %p) name (GLuint : %u)\n", ctx, name);
			return push_name_reenter(ctx, name);
		} END_MACH_OVERRIDE_PTR(push_name, obj->disp.push_name);

		if (err)
			log(LOG_ERR, "Failed to override push_name: %i", err);

		MACH_OVERRIDE(void,raster_pos2d,(GLIContext ctx, GLdouble x, GLdouble y), err ) {
			file_log("raster_pos2d called: ctx (GLIContext : %p) x (GLdouble : %f) y (GLdouble : %f)\n", ctx, x, y);
			return raster_pos2d_reenter(ctx, x, y);
		} END_MACH_OVERRIDE_PTR(raster_pos2d, obj->disp.raster_pos2d);

		if (err)
			log(LOG_ERR, "Failed to override raster_pos2d: %i", err);

		MACH_OVERRIDE(void,raster_pos2dv,(GLIContext ctx, const GLdouble *v), err ) {
			file_log("raster_pos2dv called: ctx (GLIContext : %p) v (const GLdouble* : %p)\n", ctx, v);
			return raster_pos2dv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(raster_pos2dv, obj->disp.raster_pos2dv);

		if (err)
			log(LOG_ERR, "Failed to override raster_pos2dv: %i", err);

		MACH_OVERRIDE(void,raster_pos2f,(GLIContext ctx, GLfloat x, GLfloat y), err ) {
			file_log("raster_pos2f called: ctx (GLIContext : %p) x (GLfloat : %f) y (GLfloat : %f)\n", ctx, x, y);
			return raster_pos2f_reenter(ctx, x, y);
		} END_MACH_OVERRIDE_PTR(raster_pos2f, obj->disp.raster_pos2f);

		if (err)
			log(LOG_ERR, "Failed to override raster_pos2f: %i", err);

		MACH_OVERRIDE(void,raster_pos2fv,(GLIContext ctx, const GLfloat *v), err ) {
			file_log("raster_pos2fv called: ctx (GLIContext : %p) v (const GLfloat* : %p)\n", ctx, v);
			return raster_pos2fv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(raster_pos2fv, obj->disp.raster_pos2fv);

		if (err)
			log(LOG_ERR, "Failed to override raster_pos2fv: %i", err);

		MACH_OVERRIDE(void,raster_pos2i,(GLIContext ctx, GLint x, GLint y), err ) {
			file_log("raster_pos2i called: ctx (GLIContext : %p) x (GLint : %i) y (GLint : %i)\n", ctx, x, y);
			return raster_pos2i_reenter(ctx, x, y);
		} END_MACH_OVERRIDE_PTR(raster_pos2i, obj->disp.raster_pos2i);

		if (err)
			log(LOG_ERR, "Failed to override raster_pos2i: %i", err);

		MACH_OVERRIDE(void,raster_pos2iv,(GLIContext ctx, const GLint *v), err ) {
			file_log("raster_pos2iv called: ctx (GLIContext : %p) v (const GLint* : %p)\n", ctx, v);
			return raster_pos2iv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(raster_pos2iv, obj->disp.raster_pos2iv);

		if (err)
			log(LOG_ERR, "Failed to override raster_pos2iv: %i", err);

		MACH_OVERRIDE(void,raster_pos2s,(GLIContext ctx, GLshort x, GLshort y), err ) {
			file_log("raster_pos2s called: ctx (GLIContext : %p) x (GLshort : %i) y (GLshort : %i)\n", ctx, x, y);
			return raster_pos2s_reenter(ctx, x, y);
		} END_MACH_OVERRIDE_PTR(raster_pos2s, obj->disp.raster_pos2s);

		if (err)
			log(LOG_ERR, "Failed to override raster_pos2s: %i", err);

		MACH_OVERRIDE(void,raster_pos2sv,(GLIContext ctx, const GLshort *v), err ) {
			file_log("raster_pos2sv called: ctx (GLIContext : %p) v (const GLshort* : %p)\n", ctx, v);
			return raster_pos2sv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(raster_pos2sv, obj->disp.raster_pos2sv);

		if (err)
			log(LOG_ERR, "Failed to override raster_pos2sv: %i", err);

		MACH_OVERRIDE(void,raster_pos3d,(GLIContext ctx, GLdouble x, GLdouble y, GLdouble z), err ) {
			file_log("raster_pos3d called: ctx (GLIContext : %p) x (GLdouble : %f) y (GLdouble : %f) z (GLdouble : %f)\n", ctx, x, y, z);
			return raster_pos3d_reenter(ctx, x, y, z);
		} END_MACH_OVERRIDE_PTR(raster_pos3d, obj->disp.raster_pos3d);

		if (err)
			log(LOG_ERR, "Failed to override raster_pos3d: %i", err);

		MACH_OVERRIDE(void,raster_pos3dv,(GLIContext ctx, const GLdouble *v), err ) {
			file_log("raster_pos3dv called: ctx (GLIContext : %p) v (const GLdouble* : %p)\n", ctx, v);
			return raster_pos3dv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(raster_pos3dv, obj->disp.raster_pos3dv);

		if (err)
			log(LOG_ERR, "Failed to override raster_pos3dv: %i", err);

		MACH_OVERRIDE(void,raster_pos3f,(GLIContext ctx, GLfloat x, GLfloat y, GLfloat z), err ) {
			file_log("raster_pos3f called: ctx (GLIContext : %p) x (GLfloat : %f) y (GLfloat : %f) z (GLfloat : %f)\n", ctx, x, y, z);
			return raster_pos3f_reenter(ctx, x, y, z);
		} END_MACH_OVERRIDE_PTR(raster_pos3f, obj->disp.raster_pos3f);

		if (err)
			log(LOG_ERR, "Failed to override raster_pos3f: %i", err);

		MACH_OVERRIDE(void,raster_pos3fv,(GLIContext ctx, const GLfloat *v), err ) {
			file_log("raster_pos3fv called: ctx (GLIContext : %p) v (const GLfloat* : %p)\n", ctx, v);
			return raster_pos3fv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(raster_pos3fv, obj->disp.raster_pos3fv);

		if (err)
			log(LOG_ERR, "Failed to override raster_pos3fv: %i", err);

		MACH_OVERRIDE(void,raster_pos3i,(GLIContext ctx, GLint x, GLint y, GLint z), err ) {
			file_log("raster_pos3i called: ctx (GLIContext : %p) x (GLint : %i) y (GLint : %i) z (GLint : %i)\n", ctx, x, y, z);
			return raster_pos3i_reenter(ctx, x, y, z);
		} END_MACH_OVERRIDE_PTR(raster_pos3i, obj->disp.raster_pos3i);

		if (err)
			log(LOG_ERR, "Failed to override raster_pos3i: %i", err);

		MACH_OVERRIDE(void,raster_pos3iv,(GLIContext ctx, const GLint *v), err ) {
			file_log("raster_pos3iv called: ctx (GLIContext : %p) v (const GLint* : %p)\n", ctx, v);
			return raster_pos3iv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(raster_pos3iv, obj->disp.raster_pos3iv);

		if (err)
			log(LOG_ERR, "Failed to override raster_pos3iv: %i", err);

		MACH_OVERRIDE(void,raster_pos3s,(GLIContext ctx, GLshort x, GLshort y, GLshort z), err ) {
			file_log("raster_pos3s called: ctx (GLIContext : %p) x (GLshort : %i) y (GLshort : %i) z (GLshort : %i)\n", ctx, x, y, z);
			return raster_pos3s_reenter(ctx, x, y, z);
		} END_MACH_OVERRIDE_PTR(raster_pos3s, obj->disp.raster_pos3s);

		if (err)
			log(LOG_ERR, "Failed to override raster_pos3s: %i", err);

		MACH_OVERRIDE(void,raster_pos3sv,(GLIContext ctx, const GLshort *v), err ) {
			file_log("raster_pos3sv called: ctx (GLIContext : %p) v (const GLshort* : %p)\n", ctx, v);
			return raster_pos3sv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(raster_pos3sv, obj->disp.raster_pos3sv);

		if (err)
			log(LOG_ERR, "Failed to override raster_pos3sv: %i", err);

		MACH_OVERRIDE(void,raster_pos4d,(GLIContext ctx, GLdouble x, GLdouble y, GLdouble z, GLdouble w), err ) {
			file_log("raster_pos4d called: ctx (GLIContext : %p) x (GLdouble : %f) y (GLdouble : %f) z (GLdouble : %f) w (GLdouble : %f)\n", ctx, x, y, z, w);
			return raster_pos4d_reenter(ctx, x, y, z, w);
		} END_MACH_OVERRIDE_PTR(raster_pos4d, obj->disp.raster_pos4d);

		if (err)
			log(LOG_ERR, "Failed to override raster_pos4d: %i", err);

		MACH_OVERRIDE(void,raster_pos4dv,(GLIContext ctx, const GLdouble *v), err ) {
			file_log("raster_pos4dv called: ctx (GLIContext : %p) v (const GLdouble* : %p)\n", ctx, v);
			return raster_pos4dv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(raster_pos4dv, obj->disp.raster_pos4dv);

		if (err)
			log(LOG_ERR, "Failed to override raster_pos4dv: %i", err);

		MACH_OVERRIDE(void,raster_pos4f,(GLIContext ctx, GLfloat x, GLfloat y, GLfloat z, GLfloat w), err ) {
			file_log("raster_pos4f called: ctx (GLIContext : %p) x (GLfloat : %f) y (GLfloat : %f) z (GLfloat : %f) w (GLfloat : %f)\n", ctx, x, y, z, w);
			return raster_pos4f_reenter(ctx, x, y, z, w);
		} END_MACH_OVERRIDE_PTR(raster_pos4f, obj->disp.raster_pos4f);

		if (err)
			log(LOG_ERR, "Failed to override raster_pos4f: %i", err);

		MACH_OVERRIDE(void,raster_pos4fv,(GLIContext ctx, const GLfloat *v), err ) {
			file_log("raster_pos4fv called: ctx (GLIContext : %p) v (const GLfloat* : %p)\n", ctx, v);
			return raster_pos4fv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(raster_pos4fv, obj->disp.raster_pos4fv);

		if (err)
			log(LOG_ERR, "Failed to override raster_pos4fv: %i", err);

		MACH_OVERRIDE(void,raster_pos4i,(GLIContext ctx, GLint x, GLint y, GLint z, GLint w), err ) {
			file_log("raster_pos4i called: ctx (GLIContext : %p) x (GLint : %i) y (GLint : %i) z (GLint : %i) w (GLint : %i)\n", ctx, x, y, z, w);
			return raster_pos4i_reenter(ctx, x, y, z, w);
		} END_MACH_OVERRIDE_PTR(raster_pos4i, obj->disp.raster_pos4i);

		if (err)
			log(LOG_ERR, "Failed to override raster_pos4i: %i", err);

		MACH_OVERRIDE(void,raster_pos4iv,(GLIContext ctx, const GLint *v), err ) {
			file_log("raster_pos4iv called: ctx (GLIContext : %p) v (const GLint* : %p)\n", ctx, v);
			return raster_pos4iv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(raster_pos4iv, obj->disp.raster_pos4iv);

		if (err)
			log(LOG_ERR, "Failed to override raster_pos4iv: %i", err);

		MACH_OVERRIDE(void,raster_pos4s,(GLIContext ctx, GLshort x, GLshort y, GLshort z, GLshort w), err ) {
			file_log("raster_pos4s called: ctx (GLIContext : %p) x (GLshort : %i) y (GLshort : %i) z (GLshort : %i) w (GLshort : %i)\n", ctx, x, y, z, w);
			return raster_pos4s_reenter(ctx, x, y, z, w);
		} END_MACH_OVERRIDE_PTR(raster_pos4s, obj->disp.raster_pos4s);

		if (err)
			log(LOG_ERR, "Failed to override raster_pos4s: %i", err);

		MACH_OVERRIDE(void,raster_pos4sv,(GLIContext ctx, const GLshort *v), err ) {
			file_log("raster_pos4sv called: ctx (GLIContext : %p) v (const GLshort* : %p)\n", ctx, v);
			return raster_pos4sv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(raster_pos4sv, obj->disp.raster_pos4sv);

		if (err)
			log(LOG_ERR, "Failed to override raster_pos4sv: %i", err);

		MACH_OVERRIDE(void,read_buffer,(GLIContext ctx, GLenum mode), err ) {
			file_log("read_buffer called: ctx (GLIContext : %p) mode (GLenum : %s)\n", ctx, GLenumToString(mode).c_str());
			return read_buffer_reenter(ctx, mode);
		} END_MACH_OVERRIDE_PTR(read_buffer, obj->disp.read_buffer);

		if (err)
			log(LOG_ERR, "Failed to override read_buffer: %i", err);

		MACH_OVERRIDE(void,read_pixels,(GLIContext ctx, GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels), err ) {
			file_log("read_pixels called: ctx (GLIContext : %p) x (GLint : %i) y (GLint : %i) width (GLsizei : %i) height (GLsizei : %i) format (GLenum : %s) type (GLenum : %s) pixels (GLvoid* : %p)\n", ctx, x, y, width, height, GLenumToString(format).c_str(), GLenumToString(type).c_str(), pixels);
			return read_pixels_reenter(ctx, x, y, width, height, format, type, pixels);
		} END_MACH_OVERRIDE_PTR(read_pixels, obj->disp.read_pixels);

		if (err)
			log(LOG_ERR, "Failed to override read_pixels: %i", err);

		MACH_OVERRIDE(void,rectd,(GLIContext ctx, GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2), err ) {
			file_log("rectd called: ctx (GLIContext : %p) x1 (GLdouble : %f) y1 (GLdouble : %f) x2 (GLdouble : %f) y2 (GLdouble : %f)\n", ctx, x1, y1, x2, y2);
			return rectd_reenter(ctx, x1, y1, x2, y2);
		} END_MACH_OVERRIDE_PTR(rectd, obj->disp.rectd);

		if (err)
			log(LOG_ERR, "Failed to override rectd: %i", err);

		MACH_OVERRIDE(void,rectdv,(GLIContext ctx, const GLdouble *v1, const GLdouble *v2), err ) {
			file_log("rectdv called: ctx (GLIContext : %p) v1 (const GLdouble* : %p) v2 (const GLdouble* : %p)\n", ctx, v1, v2);
			return rectdv_reenter(ctx, v1, v2);
		} END_MACH_OVERRIDE_PTR(rectdv, obj->disp.rectdv);

		if (err)
			log(LOG_ERR, "Failed to override rectdv: %i", err);

		MACH_OVERRIDE(void,rectf,(GLIContext ctx, GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2), err ) {
			file_log("rectf called: ctx (GLIContext : %p) x1 (GLfloat : %f) y1 (GLfloat : %f) x2 (GLfloat : %f) y2 (GLfloat : %f)\n", ctx, x1, y1, x2, y2);
			return rectf_reenter(ctx, x1, y1, x2, y2);
		} END_MACH_OVERRIDE_PTR(rectf, obj->disp.rectf);

		if (err)
			log(LOG_ERR, "Failed to override rectf: %i", err);

		MACH_OVERRIDE(void,rectfv,(GLIContext ctx, const GLfloat *v1, const GLfloat *v2), err ) {
			file_log("rectfv called: ctx (GLIContext : %p) v1 (const GLfloat* : %p) v2 (const GLfloat* : %p)\n", ctx, v1, v2);
			return rectfv_reenter(ctx, v1, v2);
		} END_MACH_OVERRIDE_PTR(rectfv, obj->disp.rectfv);

		if (err)
			log(LOG_ERR, "Failed to override rectfv: %i", err);

		MACH_OVERRIDE(void,recti,(GLIContext ctx, GLint x1, GLint y1, GLint x2, GLint y2), err ) {
			file_log("recti called: ctx (GLIContext : %p) x1 (GLint : %i) y1 (GLint : %i) x2 (GLint : %i) y2 (GLint : %i)\n", ctx, x1, y1, x2, y2);
			return recti_reenter(ctx, x1, y1, x2, y2);
		} END_MACH_OVERRIDE_PTR(recti, obj->disp.recti);

		if (err)
			log(LOG_ERR, "Failed to override recti: %i", err);

		MACH_OVERRIDE(void,rectiv,(GLIContext ctx, const GLint *v1, const GLint *v2), err ) {
			file_log("rectiv called: ctx (GLIContext : %p) v1 (const GLint* : %p) v2 (const GLint* : %p)\n", ctx, v1, v2);
			return rectiv_reenter(ctx, v1, v2);
		} END_MACH_OVERRIDE_PTR(rectiv, obj->disp.rectiv);

		if (err)
			log(LOG_ERR, "Failed to override rectiv: %i", err);

		MACH_OVERRIDE(void,rects,(GLIContext ctx, GLshort x1, GLshort y1, GLshort x2, GLshort y2), err ) {
			file_log("rects called: ctx (GLIContext : %p) x1 (GLshort : %i) y1 (GLshort : %i) x2 (GLshort : %i) y2 (GLshort : %i)\n", ctx, x1, y1, x2, y2);
			return rects_reenter(ctx, x1, y1, x2, y2);
		} END_MACH_OVERRIDE_PTR(rects, obj->disp.rects);

		if (err)
			log(LOG_ERR, "Failed to override rects: %i", err);

		MACH_OVERRIDE(void,rectsv,(GLIContext ctx, const GLshort *v1, const GLshort *v2), err ) {
			file_log("rectsv called: ctx (GLIContext : %p) v1 (const GLshort* : %p) v2 (const GLshort* : %p)\n", ctx, v1, v2);
			return rectsv_reenter(ctx, v1, v2);
		} END_MACH_OVERRIDE_PTR(rectsv, obj->disp.rectsv);

		if (err)
			log(LOG_ERR, "Failed to override rectsv: %i", err);

		MACH_OVERRIDE(GLint,render_mode,(GLIContext ctx, GLenum mode), err ) {
			file_log("render_mode called: ctx (GLIContext : %p) mode (GLenum : %s)\n", ctx, GLenumToString(mode).c_str());
			GLint result = render_mode_reenter(ctx, mode);
			return result;
		} END_MACH_OVERRIDE_PTR(render_mode, obj->disp.render_mode);

		if (err)
			log(LOG_ERR, "Failed to override render_mode: %i", err);

		MACH_OVERRIDE(void,rotated,(GLIContext ctx, GLdouble angle, GLdouble x, GLdouble y, GLdouble z), err ) {
			file_log("rotated called: ctx (GLIContext : %p) angle (GLdouble : %f) x (GLdouble : %f) y (GLdouble : %f) z (GLdouble : %f)\n", ctx, angle, x, y, z);
			return rotated_reenter(ctx, angle, x, y, z);
		} END_MACH_OVERRIDE_PTR(rotated, obj->disp.rotated);

		if (err)
			log(LOG_ERR, "Failed to override rotated: %i", err);

		MACH_OVERRIDE(void,rotatef,(GLIContext ctx, GLfloat angle, GLfloat x, GLfloat y, GLfloat z), err ) {
			file_log("rotatef called: ctx (GLIContext : %p) angle (GLfloat : %f) x (GLfloat : %f) y (GLfloat : %f) z (GLfloat : %f)\n", ctx, angle, x, y, z);
			return rotatef_reenter(ctx, angle, x, y, z);
		} END_MACH_OVERRIDE_PTR(rotatef, obj->disp.rotatef);

		if (err)
			log(LOG_ERR, "Failed to override rotatef: %i", err);

		MACH_OVERRIDE(void,scaled,(GLIContext ctx, GLdouble x, GLdouble y, GLdouble z), err ) {
			file_log("scaled called: ctx (GLIContext : %p) x (GLdouble : %f) y (GLdouble : %f) z (GLdouble : %f)\n", ctx, x, y, z);
			return scaled_reenter(ctx, x, y, z);
		} END_MACH_OVERRIDE_PTR(scaled, obj->disp.scaled);

		if (err)
			log(LOG_ERR, "Failed to override scaled: %i", err);

		MACH_OVERRIDE(void,scalef,(GLIContext ctx, GLfloat x, GLfloat y, GLfloat z), err ) {
			file_log("scalef called: ctx (GLIContext : %p) x (GLfloat : %f) y (GLfloat : %f) z (GLfloat : %f)\n", ctx, x, y, z);
			return scalef_reenter(ctx, x, y, z);
		} END_MACH_OVERRIDE_PTR(scalef, obj->disp.scalef);

		if (err)
			log(LOG_ERR, "Failed to override scalef: %i", err);

		MACH_OVERRIDE(void,scissor,(GLIContext ctx, GLint x, GLint y, GLsizei width, GLsizei height), err ) {
			file_log("scissor called: ctx (GLIContext : %p) x (GLint : %i) y (GLint : %i) width (GLsizei : %i) height (GLsizei : %i)\n", ctx, x, y, width, height);
			return scissor_reenter(ctx, x, y, width, height);
		} END_MACH_OVERRIDE_PTR(scissor, obj->disp.scissor);

		if (err)
			log(LOG_ERR, "Failed to override scissor: %i", err);

		MACH_OVERRIDE(void,select_buffer,(GLIContext ctx, GLsizei size, GLuint *buffer), err ) {
			file_log("select_buffer called: ctx (GLIContext : %p) size (GLsizei : %i) buffer (GLuint* : %p)\n", ctx, size, buffer);
			return select_buffer_reenter(ctx, size, buffer);
		} END_MACH_OVERRIDE_PTR(select_buffer, obj->disp.select_buffer);

		if (err)
			log(LOG_ERR, "Failed to override select_buffer: %i", err);

		MACH_OVERRIDE(void,shade_model,(GLIContext ctx, GLenum mode), err ) {
			file_log("shade_model called: ctx (GLIContext : %p) mode (GLenum : %s)\n", ctx, GLenumToString(mode).c_str());
			return shade_model_reenter(ctx, mode);
		} END_MACH_OVERRIDE_PTR(shade_model, obj->disp.shade_model);

		if (err)
			log(LOG_ERR, "Failed to override shade_model: %i", err);

		MACH_OVERRIDE(void,stencil_func,(GLIContext ctx, GLenum func, GLint ref, GLuint mask), err ) {
			file_log("stencil_func called: ctx (GLIContext : %p) func (GLenum : %s) ref (GLint : %i) mask (GLuint : %u)\n", ctx, GLenumToString(func).c_str(), ref, mask);
			return stencil_func_reenter(ctx, func, ref, mask);
		} END_MACH_OVERRIDE_PTR(stencil_func, obj->disp.stencil_func);

		if (err)
			log(LOG_ERR, "Failed to override stencil_func: %i", err);

		MACH_OVERRIDE(void,stencil_mask,(GLIContext ctx, GLuint mask), err ) {
			file_log("stencil_mask called: ctx (GLIContext : %p) mask (GLuint : %u)\n", ctx, mask);
			return stencil_mask_reenter(ctx, mask);
		} END_MACH_OVERRIDE_PTR(stencil_mask, obj->disp.stencil_mask);

		if (err)
			log(LOG_ERR, "Failed to override stencil_mask: %i", err);

		MACH_OVERRIDE(void,stencil_op,(GLIContext ctx, GLenum fail, GLenum zfail, GLenum zpass), err ) {
			file_log("stencil_op called: ctx (GLIContext : %p) fail (GLenum : %s) zfail (GLenum : %s) zpass (GLenum : %s)\n", ctx, GLenumToString(fail).c_str(), GLenumToString(zfail).c_str(), GLenumToString(zpass).c_str());
			return stencil_op_reenter(ctx, fail, zfail, zpass);
		} END_MACH_OVERRIDE_PTR(stencil_op, obj->disp.stencil_op);

		if (err)
			log(LOG_ERR, "Failed to override stencil_op: %i", err);

		MACH_OVERRIDE(void,tex_coord1d,(GLIContext ctx, GLdouble s), err ) {
			file_log("tex_coord1d called: ctx (GLIContext : %p) s (GLdouble : %f)\n", ctx, s);
			return tex_coord1d_reenter(ctx, s);
		} END_MACH_OVERRIDE_PTR(tex_coord1d, obj->disp.tex_coord1d);

		if (err)
			log(LOG_ERR, "Failed to override tex_coord1d: %i", err);

		MACH_OVERRIDE(void,tex_coord1dv,(GLIContext ctx, const GLdouble *v), err ) {
			file_log("tex_coord1dv called: ctx (GLIContext : %p) v (const GLdouble* : %p)\n", ctx, v);
			return tex_coord1dv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(tex_coord1dv, obj->disp.tex_coord1dv);

		if (err)
			log(LOG_ERR, "Failed to override tex_coord1dv: %i", err);

		MACH_OVERRIDE(void,tex_coord1f,(GLIContext ctx, GLfloat s), err ) {
			file_log("tex_coord1f called: ctx (GLIContext : %p) s (GLfloat : %f)\n", ctx, s);
			return tex_coord1f_reenter(ctx, s);
		} END_MACH_OVERRIDE_PTR(tex_coord1f, obj->disp.tex_coord1f);

		if (err)
			log(LOG_ERR, "Failed to override tex_coord1f: %i", err);

		MACH_OVERRIDE(void,tex_coord1fv,(GLIContext ctx, const GLfloat *v), err ) {
			file_log("tex_coord1fv called: ctx (GLIContext : %p) v (const GLfloat* : %p)\n", ctx, v);
			return tex_coord1fv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(tex_coord1fv, obj->disp.tex_coord1fv);

		if (err)
			log(LOG_ERR, "Failed to override tex_coord1fv: %i", err);

		MACH_OVERRIDE(void,tex_coord1i,(GLIContext ctx, GLint s), err ) {
			file_log("tex_coord1i called: ctx (GLIContext : %p) s (GLint : %i)\n", ctx, s);
			return tex_coord1i_reenter(ctx, s);
		} END_MACH_OVERRIDE_PTR(tex_coord1i, obj->disp.tex_coord1i);

		if (err)
			log(LOG_ERR, "Failed to override tex_coord1i: %i", err);

		MACH_OVERRIDE(void,tex_coord1iv,(GLIContext ctx, const GLint *v), err ) {
			file_log("tex_coord1iv called: ctx (GLIContext : %p) v (const GLint* : %p)\n", ctx, v);
			return tex_coord1iv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(tex_coord1iv, obj->disp.tex_coord1iv);

		if (err)
			log(LOG_ERR, "Failed to override tex_coord1iv: %i", err);

		MACH_OVERRIDE(void,tex_coord1s,(GLIContext ctx, GLshort s), err ) {
			file_log("tex_coord1s called: ctx (GLIContext : %p) s (GLshort : %i)\n", ctx, s);
			return tex_coord1s_reenter(ctx, s);
		} END_MACH_OVERRIDE_PTR(tex_coord1s, obj->disp.tex_coord1s);

		if (err)
			log(LOG_ERR, "Failed to override tex_coord1s: %i", err);

		MACH_OVERRIDE(void,tex_coord1sv,(GLIContext ctx, const GLshort *v), err ) {
			file_log("tex_coord1sv called: ctx (GLIContext : %p) v (const GLshort* : %p)\n", ctx, v);
			return tex_coord1sv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(tex_coord1sv, obj->disp.tex_coord1sv);

		if (err)
			log(LOG_ERR, "Failed to override tex_coord1sv: %i", err);

		MACH_OVERRIDE(void,tex_coord2d,(GLIContext ctx, GLdouble s, GLdouble t), err ) {
			file_log("tex_coord2d called: ctx (GLIContext : %p) s (GLdouble : %f) t (GLdouble : %f)\n", ctx, s, t);
			return tex_coord2d_reenter(ctx, s, t);
		} END_MACH_OVERRIDE_PTR(tex_coord2d, obj->disp.tex_coord2d);

		if (err)
			log(LOG_ERR, "Failed to override tex_coord2d: %i", err);

		MACH_OVERRIDE(void,tex_coord2dv,(GLIContext ctx, const GLdouble *v), err ) {
			file_log("tex_coord2dv called: ctx (GLIContext : %p) v (const GLdouble* : %p)\n", ctx, v);
			return tex_coord2dv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(tex_coord2dv, obj->disp.tex_coord2dv);

		if (err)
			log(LOG_ERR, "Failed to override tex_coord2dv: %i", err);

		MACH_OVERRIDE(void,tex_coord2f,(GLIContext ctx, GLfloat s, GLfloat t), err ) {
			file_log("tex_coord2f called: ctx (GLIContext : %p) s (GLfloat : %f) t (GLfloat : %f)\n", ctx, s, t);
			return tex_coord2f_reenter(ctx, s, t);
		} END_MACH_OVERRIDE_PTR(tex_coord2f, obj->disp.tex_coord2f);

		if (err)
			log(LOG_ERR, "Failed to override tex_coord2f: %i", err);

		MACH_OVERRIDE(void,tex_coord2fv,(GLIContext ctx, const GLfloat *v), err ) {
			file_log("tex_coord2fv called: ctx (GLIContext : %p) v (const GLfloat* : %p)\n", ctx, v);
			return tex_coord2fv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(tex_coord2fv, obj->disp.tex_coord2fv);

		if (err)
			log(LOG_ERR, "Failed to override tex_coord2fv: %i", err);

		MACH_OVERRIDE(void,tex_coord2i,(GLIContext ctx, GLint s, GLint t), err ) {
			file_log("tex_coord2i called: ctx (GLIContext : %p) s (GLint : %i) t (GLint : %i)\n", ctx, s, t);
			return tex_coord2i_reenter(ctx, s, t);
		} END_MACH_OVERRIDE_PTR(tex_coord2i, obj->disp.tex_coord2i);

		if (err)
			log(LOG_ERR, "Failed to override tex_coord2i: %i", err);

		MACH_OVERRIDE(void,tex_coord2iv,(GLIContext ctx, const GLint *v), err ) {
			file_log("tex_coord2iv called: ctx (GLIContext : %p) v (const GLint* : %p)\n", ctx, v);
			return tex_coord2iv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(tex_coord2iv, obj->disp.tex_coord2iv);

		if (err)
			log(LOG_ERR, "Failed to override tex_coord2iv: %i", err);

		MACH_OVERRIDE(void,tex_coord2s,(GLIContext ctx, GLshort s, GLshort t), err ) {
			file_log("tex_coord2s called: ctx (GLIContext : %p) s (GLshort : %i) t (GLshort : %i)\n", ctx, s, t);
			return tex_coord2s_reenter(ctx, s, t);
		} END_MACH_OVERRIDE_PTR(tex_coord2s, obj->disp.tex_coord2s);

		if (err)
			log(LOG_ERR, "Failed to override tex_coord2s: %i", err);

		MACH_OVERRIDE(void,tex_coord2sv,(GLIContext ctx, const GLshort *v), err ) {
			file_log("tex_coord2sv called: ctx (GLIContext : %p) v (const GLshort* : %p)\n", ctx, v);
			return tex_coord2sv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(tex_coord2sv, obj->disp.tex_coord2sv);

		if (err)
			log(LOG_ERR, "Failed to override tex_coord2sv: %i", err);

		MACH_OVERRIDE(void,tex_coord3d,(GLIContext ctx, GLdouble s, GLdouble t, GLdouble r), err ) {
			file_log("tex_coord3d called: ctx (GLIContext : %p) s (GLdouble : %f) t (GLdouble : %f) r (GLdouble : %f)\n", ctx, s, t, r);
			return tex_coord3d_reenter(ctx, s, t, r);
		} END_MACH_OVERRIDE_PTR(tex_coord3d, obj->disp.tex_coord3d);

		if (err)
			log(LOG_ERR, "Failed to override tex_coord3d: %i", err);

		MACH_OVERRIDE(void,tex_coord3dv,(GLIContext ctx, const GLdouble *v), err ) {
			file_log("tex_coord3dv called: ctx (GLIContext : %p) v (const GLdouble* : %p)\n", ctx, v);
			return tex_coord3dv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(tex_coord3dv, obj->disp.tex_coord3dv);

		if (err)
			log(LOG_ERR, "Failed to override tex_coord3dv: %i", err);

		MACH_OVERRIDE(void,tex_coord3f,(GLIContext ctx, GLfloat s, GLfloat t, GLfloat r), err ) {
			file_log("tex_coord3f called: ctx (GLIContext : %p) s (GLfloat : %f) t (GLfloat : %f) r (GLfloat : %f)\n", ctx, s, t, r);
			return tex_coord3f_reenter(ctx, s, t, r);
		} END_MACH_OVERRIDE_PTR(tex_coord3f, obj->disp.tex_coord3f);

		if (err)
			log(LOG_ERR, "Failed to override tex_coord3f: %i", err);

		MACH_OVERRIDE(void,tex_coord3fv,(GLIContext ctx, const GLfloat *v), err ) {
			file_log("tex_coord3fv called: ctx (GLIContext : %p) v (const GLfloat* : %p)\n", ctx, v);
			return tex_coord3fv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(tex_coord3fv, obj->disp.tex_coord3fv);

		if (err)
			log(LOG_ERR, "Failed to override tex_coord3fv: %i", err);

		MACH_OVERRIDE(void,tex_coord3i,(GLIContext ctx, GLint s, GLint t, GLint r), err ) {
			file_log("tex_coord3i called: ctx (GLIContext : %p) s (GLint : %i) t (GLint : %i) r (GLint : %i)\n", ctx, s, t, r);
			return tex_coord3i_reenter(ctx, s, t, r);
		} END_MACH_OVERRIDE_PTR(tex_coord3i, obj->disp.tex_coord3i);

		if (err)
			log(LOG_ERR, "Failed to override tex_coord3i: %i", err);

		MACH_OVERRIDE(void,tex_coord3iv,(GLIContext ctx, const GLint *v), err ) {
			file_log("tex_coord3iv called: ctx (GLIContext : %p) v (const GLint* : %p)\n", ctx, v);
			return tex_coord3iv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(tex_coord3iv, obj->disp.tex_coord3iv);

		if (err)
			log(LOG_ERR, "Failed to override tex_coord3iv: %i", err);

		MACH_OVERRIDE(void,tex_coord3s,(GLIContext ctx, GLshort s, GLshort t, GLshort r), err ) {
			file_log("tex_coord3s called: ctx (GLIContext : %p) s (GLshort : %i) t (GLshort : %i) r (GLshort : %i)\n", ctx, s, t, r);
			return tex_coord3s_reenter(ctx, s, t, r);
		} END_MACH_OVERRIDE_PTR(tex_coord3s, obj->disp.tex_coord3s);

		if (err)
			log(LOG_ERR, "Failed to override tex_coord3s: %i", err);

		MACH_OVERRIDE(void,tex_coord3sv,(GLIContext ctx, const GLshort *v), err ) {
			file_log("tex_coord3sv called: ctx (GLIContext : %p) v (const GLshort* : %p)\n", ctx, v);
			return tex_coord3sv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(tex_coord3sv, obj->disp.tex_coord3sv);

		if (err)
			log(LOG_ERR, "Failed to override tex_coord3sv: %i", err);

		MACH_OVERRIDE(void,tex_coord4d,(GLIContext ctx, GLdouble s, GLdouble t, GLdouble r, GLdouble q), err ) {
			file_log("tex_coord4d called: ctx (GLIContext : %p) s (GLdouble : %f) t (GLdouble : %f) r (GLdouble : %f) q (GLdouble : %f)\n", ctx, s, t, r, q);
			return tex_coord4d_reenter(ctx, s, t, r, q);
		} END_MACH_OVERRIDE_PTR(tex_coord4d, obj->disp.tex_coord4d);

		if (err)
			log(LOG_ERR, "Failed to override tex_coord4d: %i", err);

		MACH_OVERRIDE(void,tex_coord4dv,(GLIContext ctx, const GLdouble *v), err ) {
			file_log("tex_coord4dv called: ctx (GLIContext : %p) v (const GLdouble* : %p)\n", ctx, v);
			return tex_coord4dv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(tex_coord4dv, obj->disp.tex_coord4dv);

		if (err)
			log(LOG_ERR, "Failed to override tex_coord4dv: %i", err);

		MACH_OVERRIDE(void,tex_coord4f,(GLIContext ctx, GLfloat s, GLfloat t, GLfloat r, GLfloat q), err ) {
			file_log("tex_coord4f called: ctx (GLIContext : %p) s (GLfloat : %f) t (GLfloat : %f) r (GLfloat : %f) q (GLfloat : %f)\n", ctx, s, t, r, q);
			return tex_coord4f_reenter(ctx, s, t, r, q);
		} END_MACH_OVERRIDE_PTR(tex_coord4f, obj->disp.tex_coord4f);

		if (err)
			log(LOG_ERR, "Failed to override tex_coord4f: %i", err);

		MACH_OVERRIDE(void,tex_coord4fv,(GLIContext ctx, const GLfloat *v), err ) {
			file_log("tex_coord4fv called: ctx (GLIContext : %p) v (const GLfloat* : %p)\n", ctx, v);
			return tex_coord4fv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(tex_coord4fv, obj->disp.tex_coord4fv);

		if (err)
			log(LOG_ERR, "Failed to override tex_coord4fv: %i", err);

		MACH_OVERRIDE(void,tex_coord4i,(GLIContext ctx, GLint s, GLint t, GLint r, GLint q), err ) {
			file_log("tex_coord4i called: ctx (GLIContext : %p) s (GLint : %i) t (GLint : %i) r (GLint : %i) q (GLint : %i)\n", ctx, s, t, r, q);
			return tex_coord4i_reenter(ctx, s, t, r, q);
		} END_MACH_OVERRIDE_PTR(tex_coord4i, obj->disp.tex_coord4i);

		if (err)
			log(LOG_ERR, "Failed to override tex_coord4i: %i", err);

		MACH_OVERRIDE(void,tex_coord4iv,(GLIContext ctx, const GLint *v), err ) {
			file_log("tex_coord4iv called: ctx (GLIContext : %p) v (const GLint* : %p)\n", ctx, v);
			return tex_coord4iv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(tex_coord4iv, obj->disp.tex_coord4iv);

		if (err)
			log(LOG_ERR, "Failed to override tex_coord4iv: %i", err);

		MACH_OVERRIDE(void,tex_coord4s,(GLIContext ctx, GLshort s, GLshort t, GLshort r, GLshort q), err ) {
			file_log("tex_coord4s called: ctx (GLIContext : %p) s (GLshort : %i) t (GLshort : %i) r (GLshort : %i) q (GLshort : %i)\n", ctx, s, t, r, q);
			return tex_coord4s_reenter(ctx, s, t, r, q);
		} END_MACH_OVERRIDE_PTR(tex_coord4s, obj->disp.tex_coord4s);

		if (err)
			log(LOG_ERR, "Failed to override tex_coord4s: %i", err);

		MACH_OVERRIDE(void,tex_coord4sv,(GLIContext ctx, const GLshort *v), err ) {
			file_log("tex_coord4sv called: ctx (GLIContext : %p) v (const GLshort* : %p)\n", ctx, v);
			return tex_coord4sv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(tex_coord4sv, obj->disp.tex_coord4sv);

		if (err)
			log(LOG_ERR, "Failed to override tex_coord4sv: %i", err);

		MACH_OVERRIDE(void,tex_coord_pointer,(GLIContext ctx, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer), err ) {
			file_log("tex_coord_pointer called: ctx (GLIContext : %p) size (GLint : %i) type (GLenum : %s) stride (GLsizei : %i) pointer (const GLvoid* : %p)\n", ctx, size, GLenumToString(type).c_str(), stride, pointer);
			return tex_coord_pointer_reenter(ctx, size, type, stride, pointer);
		} END_MACH_OVERRIDE_PTR(tex_coord_pointer, obj->disp.tex_coord_pointer);

		if (err)
			log(LOG_ERR, "Failed to override tex_coord_pointer: %i", err);

		MACH_OVERRIDE(void,tex_envf,(GLIContext ctx, GLenum target, GLenum pname, GLfloat param), err ) {
			file_log("tex_envf called: ctx (GLIContext : %p) target (GLenum : %s) pname (GLenum : %s) param (GLfloat : %f)\n", ctx, GLenumToString(target).c_str(), GLenumToString(pname).c_str(), param);
			return tex_envf_reenter(ctx, target, pname, param);
		} END_MACH_OVERRIDE_PTR(tex_envf, obj->disp.tex_envf);

		if (err)
			log(LOG_ERR, "Failed to override tex_envf: %i", err);

		MACH_OVERRIDE(void,tex_envfv,(GLIContext ctx, GLenum target, GLenum pname, const GLfloat *params), err ) {
			file_log("tex_envfv called: ctx (GLIContext : %p) target (GLenum : %s) pname (GLenum : %s) params (const GLfloat* : %p)\n", ctx, GLenumToString(target).c_str(), GLenumToString(pname).c_str(), params);
			return tex_envfv_reenter(ctx, target, pname, params);
		} END_MACH_OVERRIDE_PTR(tex_envfv, obj->disp.tex_envfv);

		if (err)
			log(LOG_ERR, "Failed to override tex_envfv: %i", err);

		MACH_OVERRIDE(void,tex_envi,(GLIContext ctx, GLenum target, GLenum pname, GLint param), err ) {
			file_log("tex_envi called: ctx (GLIContext : %p) target (GLenum : %s) pname (GLenum : %s) param (GLint : %i)\n", ctx, GLenumToString(target).c_str(), GLenumToString(pname).c_str(), param);
			return tex_envi_reenter(ctx, target, pname, param);
		} END_MACH_OVERRIDE_PTR(tex_envi, obj->disp.tex_envi);

		if (err)
			log(LOG_ERR, "Failed to override tex_envi: %i", err);

		MACH_OVERRIDE(void,tex_enviv,(GLIContext ctx, GLenum target, GLenum pname, const GLint *params), err ) {
			file_log("tex_enviv called: ctx (GLIContext : %p) target (GLenum : %s) pname (GLenum : %s) params (const GLint* : %p)\n", ctx, GLenumToString(target).c_str(), GLenumToString(pname).c_str(), params);
			return tex_enviv_reenter(ctx, target, pname, params);
		} END_MACH_OVERRIDE_PTR(tex_enviv, obj->disp.tex_enviv);

		if (err)
			log(LOG_ERR, "Failed to override tex_enviv: %i", err);

		MACH_OVERRIDE(void,tex_gend,(GLIContext ctx, GLenum coord, GLenum pname, GLdouble param), err ) {
			file_log("tex_gend called: ctx (GLIContext : %p) coord (GLenum : %s) pname (GLenum : %s) param (GLdouble : %f)\n", ctx, GLenumToString(coord).c_str(), GLenumToString(pname).c_str(), param);
			return tex_gend_reenter(ctx, coord, pname, param);
		} END_MACH_OVERRIDE_PTR(tex_gend, obj->disp.tex_gend);

		if (err)
			log(LOG_ERR, "Failed to override tex_gend: %i", err);

		MACH_OVERRIDE(void,tex_gendv,(GLIContext ctx, GLenum coord, GLenum pname, const GLdouble *params), err ) {
			file_log("tex_gendv called: ctx (GLIContext : %p) coord (GLenum : %s) pname (GLenum : %s) params (const GLdouble* : %p)\n", ctx, GLenumToString(coord).c_str(), GLenumToString(pname).c_str(), params);
			return tex_gendv_reenter(ctx, coord, pname, params);
		} END_MACH_OVERRIDE_PTR(tex_gendv, obj->disp.tex_gendv);

		if (err)
			log(LOG_ERR, "Failed to override tex_gendv: %i", err);

		MACH_OVERRIDE(void,tex_genf,(GLIContext ctx, GLenum coord, GLenum pname, GLfloat param), err ) {
			file_log("tex_genf called: ctx (GLIContext : %p) coord (GLenum : %s) pname (GLenum : %s) param (GLfloat : %f)\n", ctx, GLenumToString(coord).c_str(), GLenumToString(pname).c_str(), param);
			return tex_genf_reenter(ctx, coord, pname, param);
		} END_MACH_OVERRIDE_PTR(tex_genf, obj->disp.tex_genf);

		if (err)
			log(LOG_ERR, "Failed to override tex_genf: %i", err);

		MACH_OVERRIDE(void,tex_genfv,(GLIContext ctx, GLenum coord, GLenum pname, const GLfloat *params), err ) {
			file_log("tex_genfv called: ctx (GLIContext : %p) coord (GLenum : %s) pname (GLenum : %s) params (const GLfloat* : %p)\n", ctx, GLenumToString(coord).c_str(), GLenumToString(pname).c_str(), params);
			return tex_genfv_reenter(ctx, coord, pname, params);
		} END_MACH_OVERRIDE_PTR(tex_genfv, obj->disp.tex_genfv);

		if (err)
			log(LOG_ERR, "Failed to override tex_genfv: %i", err);

		MACH_OVERRIDE(void,tex_geni,(GLIContext ctx, GLenum coord, GLenum pname, GLint param), err ) {
			file_log("tex_geni called: ctx (GLIContext : %p) coord (GLenum : %s) pname (GLenum : %s) param (GLint : %i)\n", ctx, GLenumToString(coord).c_str(), GLenumToString(pname).c_str(), param);
			return tex_geni_reenter(ctx, coord, pname, param);
		} END_MACH_OVERRIDE_PTR(tex_geni, obj->disp.tex_geni);

		if (err)
			log(LOG_ERR, "Failed to override tex_geni: %i", err);

		MACH_OVERRIDE(void,tex_geniv,(GLIContext ctx, GLenum coord, GLenum pname, const GLint *params), err ) {
			file_log("tex_geniv called: ctx (GLIContext : %p) coord (GLenum : %s) pname (GLenum : %s) params (const GLint* : %p)\n", ctx, GLenumToString(coord).c_str(), GLenumToString(pname).c_str(), params);
			return tex_geniv_reenter(ctx, coord, pname, params);
		} END_MACH_OVERRIDE_PTR(tex_geniv, obj->disp.tex_geniv);

		if (err)
			log(LOG_ERR, "Failed to override tex_geniv: %i", err);

		MACH_OVERRIDE(void,tex_image1D,(GLIContext ctx, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels), err ) {
			file_log("tex_image1D called: ctx (GLIContext : %p) target (GLenum : %s) level (GLint : %i) internalformat (GLenum : %s) width (GLsizei : %i) border (GLint : %i) format (GLenum : %s) type (GLenum : %s) pixels (const GLvoid* : %p)\n", ctx, GLenumToString(target).c_str(), level, GLenumToString(internalformat).c_str(), width, border, GLenumToString(format).c_str(), GLenumToString(type).c_str(), pixels);
			return tex_image1D_reenter(ctx, target, level, internalformat, width, border, format, type, pixels);
		} END_MACH_OVERRIDE_PTR(tex_image1D, obj->disp.tex_image1D);

		if (err)
			log(LOG_ERR, "Failed to override tex_image1D: %i", err);

		MACH_OVERRIDE(void,tex_image2D,(GLIContext ctx, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels), err ) {
			file_log("tex_image2D called: ctx (GLIContext : %p) target (GLenum : %s) level (GLint : %i) internalformat (GLenum : %s) width (GLsizei : %i) height (GLsizei : %i) border (GLint : %i) format (GLenum : %s) type (GLenum : %s) pixels (const GLvoid* : %p)\n", ctx, GLenumToString(target).c_str(), level, GLenumToString(internalformat).c_str(), width, height, border, GLenumToString(format).c_str(), GLenumToString(type).c_str(), pixels);
			return tex_image2D_reenter(ctx, target, level, internalformat, width, height, border, format, type, pixels);
		} END_MACH_OVERRIDE_PTR(tex_image2D, obj->disp.tex_image2D);

		if (err)
			log(LOG_ERR, "Failed to override tex_image2D: %i", err);

		MACH_OVERRIDE(void,tex_parameterf,(GLIContext ctx, GLenum target, GLenum pname, GLfloat param), err ) {
			file_log("tex_parameterf called: ctx (GLIContext : %p) target (GLenum : %s) pname (GLenum : %s) param (GLfloat : %f)\n", ctx, GLenumToString(target).c_str(), GLenumToString(pname).c_str(), param);
			return tex_parameterf_reenter(ctx, target, pname, param);
		} END_MACH_OVERRIDE_PTR(tex_parameterf, obj->disp.tex_parameterf);

		if (err)
			log(LOG_ERR, "Failed to override tex_parameterf: %i", err);

		MACH_OVERRIDE(void,tex_parameterfv,(GLIContext ctx, GLenum target, GLenum pname, const GLfloat *params), err ) {
			file_log("tex_parameterfv called: ctx (GLIContext : %p) target (GLenum : %s) pname (GLenum : %s) params (const GLfloat* : %p)\n", ctx, GLenumToString(target).c_str(), GLenumToString(pname).c_str(), params);
			return tex_parameterfv_reenter(ctx, target, pname, params);
		} END_MACH_OVERRIDE_PTR(tex_parameterfv, obj->disp.tex_parameterfv);

		if (err)
			log(LOG_ERR, "Failed to override tex_parameterfv: %i", err);

		MACH_OVERRIDE(void,tex_parameteri,(GLIContext ctx, GLenum target, GLenum pname, GLint param), err ) {
			file_log("tex_parameteri called: ctx (GLIContext : %p) target (GLenum : %s) pname (GLenum : %s) param (GLint : %i)\n", ctx, GLenumToString(target).c_str(), GLenumToString(pname).c_str(), param);
			return tex_parameteri_reenter(ctx, target, pname, param);
		} END_MACH_OVERRIDE_PTR(tex_parameteri, obj->disp.tex_parameteri);

		if (err)
			log(LOG_ERR, "Failed to override tex_parameteri: %i", err);

		MACH_OVERRIDE(void,tex_parameteriv,(GLIContext ctx, GLenum target, GLenum pname, const GLint *params), err ) {
			file_log("tex_parameteriv called: ctx (GLIContext : %p) target (GLenum : %s) pname (GLenum : %s) params (const GLint* : %p)\n", ctx, GLenumToString(target).c_str(), GLenumToString(pname).c_str(), params);
			return tex_parameteriv_reenter(ctx, target, pname, params);
		} END_MACH_OVERRIDE_PTR(tex_parameteriv, obj->disp.tex_parameteriv);

		if (err)
			log(LOG_ERR, "Failed to override tex_parameteriv: %i", err);

		MACH_OVERRIDE(void,tex_sub_image1D,(GLIContext ctx, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels), err ) {
			file_log("tex_sub_image1D called: ctx (GLIContext : %p) target (GLenum : %s) level (GLint : %i) xoffset (GLint : %i) width (GLsizei : %i) format (GLenum : %s) type (GLenum : %s) pixels (const GLvoid* : %p)\n", ctx, GLenumToString(target).c_str(), level, xoffset, width, GLenumToString(format).c_str(), GLenumToString(type).c_str(), pixels);
			return tex_sub_image1D_reenter(ctx, target, level, xoffset, width, format, type, pixels);
		} END_MACH_OVERRIDE_PTR(tex_sub_image1D, obj->disp.tex_sub_image1D);

		if (err)
			log(LOG_ERR, "Failed to override tex_sub_image1D: %i", err);

		MACH_OVERRIDE(void,tex_sub_image2D,(GLIContext ctx, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels), err ) {
			file_log("tex_sub_image2D called: ctx (GLIContext : %p) target (GLenum : %s) level (GLint : %i) xoffset (GLint : %i) yoffset (GLint : %i) width (GLsizei : %i) height (GLsizei : %i) format (GLenum : %s) type (GLenum : %s) pixels (const GLvoid* : %p)\n", ctx, GLenumToString(target).c_str(), level, xoffset, yoffset, width, height, GLenumToString(format).c_str(), GLenumToString(type).c_str(), pixels);
			return tex_sub_image2D_reenter(ctx, target, level, xoffset, yoffset, width, height, format, type, pixels);
		} END_MACH_OVERRIDE_PTR(tex_sub_image2D, obj->disp.tex_sub_image2D);

		if (err)
			log(LOG_ERR, "Failed to override tex_sub_image2D: %i", err);

		MACH_OVERRIDE(void,translated,(GLIContext ctx, GLdouble x, GLdouble y, GLdouble z), err ) {
			file_log("translated called: ctx (GLIContext : %p) x (GLdouble : %f) y (GLdouble : %f) z (GLdouble : %f)\n", ctx, x, y, z);
			return translated_reenter(ctx, x, y, z);
		} END_MACH_OVERRIDE_PTR(translated, obj->disp.translated);

		if (err)
			log(LOG_ERR, "Failed to override translated: %i", err);

		MACH_OVERRIDE(void,translatef,(GLIContext ctx, GLfloat x, GLfloat y, GLfloat z), err ) {
			file_log("translatef called: ctx (GLIContext : %p) x (GLfloat : %f) y (GLfloat : %f) z (GLfloat : %f)\n", ctx, x, y, z);
			return translatef_reenter(ctx, x, y, z);
		} END_MACH_OVERRIDE_PTR(translatef, obj->disp.translatef);

		if (err)
			log(LOG_ERR, "Failed to override translatef: %i", err);

		MACH_OVERRIDE(void,vertex2d,(GLIContext ctx, GLdouble x, GLdouble y), err ) {
			file_log("vertex2d called: ctx (GLIContext : %p) x (GLdouble : %f) y (GLdouble : %f)\n", ctx, x, y);
			return vertex2d_reenter(ctx, x, y);
		} END_MACH_OVERRIDE_PTR(vertex2d, obj->disp.vertex2d);

		if (err)
			log(LOG_ERR, "Failed to override vertex2d: %i", err);

		MACH_OVERRIDE(void,vertex2dv,(GLIContext ctx, const GLdouble *v), err ) {
			file_log("vertex2dv called: ctx (GLIContext : %p) v (const GLdouble* : %p)\n", ctx, v);
			return vertex2dv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(vertex2dv, obj->disp.vertex2dv);

		if (err)
			log(LOG_ERR, "Failed to override vertex2dv: %i", err);

		MACH_OVERRIDE(void,vertex2f,(GLIContext ctx, GLfloat x, GLfloat y), err ) {
			file_log("vertex2f called: ctx (GLIContext : %p) x (GLfloat : %f) y (GLfloat : %f)\n", ctx, x, y);
			return vertex2f_reenter(ctx, x, y);
		} END_MACH_OVERRIDE_PTR(vertex2f, obj->disp.vertex2f);

		if (err)
			log(LOG_ERR, "Failed to override vertex2f: %i", err);

		MACH_OVERRIDE(void,vertex2fv,(GLIContext ctx, const GLfloat *v), err ) {
			file_log("vertex2fv called: ctx (GLIContext : %p) v (const GLfloat* : %p)\n", ctx, v);
			return vertex2fv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(vertex2fv, obj->disp.vertex2fv);

		if (err)
			log(LOG_ERR, "Failed to override vertex2fv: %i", err);

		MACH_OVERRIDE(void,vertex2i,(GLIContext ctx, GLint x, GLint y), err ) {
			file_log("vertex2i called: ctx (GLIContext : %p) x (GLint : %i) y (GLint : %i)\n", ctx, x, y);
			return vertex2i_reenter(ctx, x, y);
		} END_MACH_OVERRIDE_PTR(vertex2i, obj->disp.vertex2i);

		if (err)
			log(LOG_ERR, "Failed to override vertex2i: %i", err);

		MACH_OVERRIDE(void,vertex2iv,(GLIContext ctx, const GLint *v), err ) {
			file_log("vertex2iv called: ctx (GLIContext : %p) v (const GLint* : %p)\n", ctx, v);
			return vertex2iv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(vertex2iv, obj->disp.vertex2iv);

		if (err)
			log(LOG_ERR, "Failed to override vertex2iv: %i", err);

		MACH_OVERRIDE(void,vertex2s,(GLIContext ctx, GLshort x, GLshort y), err ) {
			file_log("vertex2s called: ctx (GLIContext : %p) x (GLshort : %i) y (GLshort : %i)\n", ctx, x, y);
			return vertex2s_reenter(ctx, x, y);
		} END_MACH_OVERRIDE_PTR(vertex2s, obj->disp.vertex2s);

		if (err)
			log(LOG_ERR, "Failed to override vertex2s: %i", err);

		MACH_OVERRIDE(void,vertex2sv,(GLIContext ctx, const GLshort *v), err ) {
			file_log("vertex2sv called: ctx (GLIContext : %p) v (const GLshort* : %p)\n", ctx, v);
			return vertex2sv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(vertex2sv, obj->disp.vertex2sv);

		if (err)
			log(LOG_ERR, "Failed to override vertex2sv: %i", err);

		MACH_OVERRIDE(void,vertex3d,(GLIContext ctx, GLdouble x, GLdouble y, GLdouble z), err ) {
			file_log("vertex3d called: ctx (GLIContext : %p) x (GLdouble : %f) y (GLdouble : %f) z (GLdouble : %f)\n", ctx, x, y, z);
			return vertex3d_reenter(ctx, x, y, z);
		} END_MACH_OVERRIDE_PTR(vertex3d, obj->disp.vertex3d);

		if (err)
			log(LOG_ERR, "Failed to override vertex3d: %i", err);

		MACH_OVERRIDE(void,vertex3dv,(GLIContext ctx, const GLdouble *v), err ) {
			file_log("vertex3dv called: ctx (GLIContext : %p) v (const GLdouble* : %p)\n", ctx, v);
			return vertex3dv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(vertex3dv, obj->disp.vertex3dv);

		if (err)
			log(LOG_ERR, "Failed to override vertex3dv: %i", err);

		MACH_OVERRIDE(void,vertex3f,(GLIContext ctx, GLfloat x, GLfloat y, GLfloat z), err ) {
			file_log("vertex3f called: ctx (GLIContext : %p) x (GLfloat : %f) y (GLfloat : %f) z (GLfloat : %f)\n", ctx, x, y, z);
			return vertex3f_reenter(ctx, x, y, z);
		} END_MACH_OVERRIDE_PTR(vertex3f, obj->disp.vertex3f);

		if (err)
			log(LOG_ERR, "Failed to override vertex3f: %i", err);

		MACH_OVERRIDE(void,vertex3fv,(GLIContext ctx, const GLfloat *v), err ) {
			file_log("vertex3fv called: ctx (GLIContext : %p) v (const GLfloat* : %p)\n", ctx, v);
			return vertex3fv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(vertex3fv, obj->disp.vertex3fv);

		if (err)
			log(LOG_ERR, "Failed to override vertex3fv: %i", err);

		MACH_OVERRIDE(void,vertex3i,(GLIContext ctx, GLint x, GLint y, GLint z), err ) {
			file_log("vertex3i called: ctx (GLIContext : %p) x (GLint : %i) y (GLint : %i) z (GLint : %i)\n", ctx, x, y, z);
			return vertex3i_reenter(ctx, x, y, z);
		} END_MACH_OVERRIDE_PTR(vertex3i, obj->disp.vertex3i);

		if (err)
			log(LOG_ERR, "Failed to override vertex3i: %i", err);

		MACH_OVERRIDE(void,vertex3iv,(GLIContext ctx, const GLint *v), err ) {
			file_log("vertex3iv called: ctx (GLIContext : %p) v (const GLint* : %p)\n", ctx, v);
			return vertex3iv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(vertex3iv, obj->disp.vertex3iv);

		if (err)
			log(LOG_ERR, "Failed to override vertex3iv: %i", err);

		MACH_OVERRIDE(void,vertex3s,(GLIContext ctx, GLshort x, GLshort y, GLshort z), err ) {
			file_log("vertex3s called: ctx (GLIContext : %p) x (GLshort : %i) y (GLshort : %i) z (GLshort : %i)\n", ctx, x, y, z);
			return vertex3s_reenter(ctx, x, y, z);
		} END_MACH_OVERRIDE_PTR(vertex3s, obj->disp.vertex3s);

		if (err)
			log(LOG_ERR, "Failed to override vertex3s: %i", err);

		MACH_OVERRIDE(void,vertex3sv,(GLIContext ctx, const GLshort *v), err ) {
			file_log("vertex3sv called: ctx (GLIContext : %p) v (const GLshort* : %p)\n", ctx, v);
			return vertex3sv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(vertex3sv, obj->disp.vertex3sv);

		if (err)
			log(LOG_ERR, "Failed to override vertex3sv: %i", err);

		MACH_OVERRIDE(void,vertex4d,(GLIContext ctx, GLdouble x, GLdouble y, GLdouble z, GLdouble w), err ) {
			file_log("vertex4d called: ctx (GLIContext : %p) x (GLdouble : %f) y (GLdouble : %f) z (GLdouble : %f) w (GLdouble : %f)\n", ctx, x, y, z, w);
			return vertex4d_reenter(ctx, x, y, z, w);
		} END_MACH_OVERRIDE_PTR(vertex4d, obj->disp.vertex4d);

		if (err)
			log(LOG_ERR, "Failed to override vertex4d: %i", err);

		MACH_OVERRIDE(void,vertex4dv,(GLIContext ctx, const GLdouble *v), err ) {
			file_log("vertex4dv called: ctx (GLIContext : %p) v (const GLdouble* : %p)\n", ctx, v);
			return vertex4dv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(vertex4dv, obj->disp.vertex4dv);

		if (err)
			log(LOG_ERR, "Failed to override vertex4dv: %i", err);

		MACH_OVERRIDE(void,vertex4f,(GLIContext ctx, GLfloat x, GLfloat y, GLfloat z, GLfloat w), err ) {
			file_log("vertex4f called: ctx (GLIContext : %p) x (GLfloat : %f) y (GLfloat : %f) z (GLfloat : %f) w (GLfloat : %f)\n", ctx, x, y, z, w);
			return vertex4f_reenter(ctx, x, y, z, w);
		} END_MACH_OVERRIDE_PTR(vertex4f, obj->disp.vertex4f);

		if (err)
			log(LOG_ERR, "Failed to override vertex4f: %i", err);

		MACH_OVERRIDE(void,vertex4fv,(GLIContext ctx, const GLfloat *v), err ) {
			file_log("vertex4fv called: ctx (GLIContext : %p) v (const GLfloat* : %p)\n", ctx, v);
			return vertex4fv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(vertex4fv, obj->disp.vertex4fv);

		if (err)
			log(LOG_ERR, "Failed to override vertex4fv: %i", err);

		MACH_OVERRIDE(void,vertex4i,(GLIContext ctx, GLint x, GLint y, GLint z, GLint w), err ) {
			file_log("vertex4i called: ctx (GLIContext : %p) x (GLint : %i) y (GLint : %i) z (GLint : %i) w (GLint : %i)\n", ctx, x, y, z, w);
			return vertex4i_reenter(ctx, x, y, z, w);
		} END_MACH_OVERRIDE_PTR(vertex4i, obj->disp.vertex4i);

		if (err)
			log(LOG_ERR, "Failed to override vertex4i: %i", err);

		MACH_OVERRIDE(void,vertex4iv,(GLIContext ctx, const GLint *v), err ) {
			file_log("vertex4iv called: ctx (GLIContext : %p) v (const GLint* : %p)\n", ctx, v);
			return vertex4iv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(vertex4iv, obj->disp.vertex4iv);

		if (err)
			log(LOG_ERR, "Failed to override vertex4iv: %i", err);

		MACH_OVERRIDE(void,vertex4s,(GLIContext ctx, GLshort x, GLshort y, GLshort z, GLshort w), err ) {
			file_log("vertex4s called: ctx (GLIContext : %p) x (GLshort : %i) y (GLshort : %i) z (GLshort : %i) w (GLshort : %i)\n", ctx, x, y, z, w);
			return vertex4s_reenter(ctx, x, y, z, w);
		} END_MACH_OVERRIDE_PTR(vertex4s, obj->disp.vertex4s);

		if (err)
			log(LOG_ERR, "Failed to override vertex4s: %i", err);

		MACH_OVERRIDE(void,vertex4sv,(GLIContext ctx, const GLshort *v), err ) {
			file_log("vertex4sv called: ctx (GLIContext : %p) v (const GLshort* : %p)\n", ctx, v);
			return vertex4sv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(vertex4sv, obj->disp.vertex4sv);

		if (err)
			log(LOG_ERR, "Failed to override vertex4sv: %i", err);

		MACH_OVERRIDE(void,vertex_pointer,(GLIContext ctx, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer), err ) {
			file_log("vertex_pointer called: ctx (GLIContext : %p) size (GLint : %i) type (GLenum : %s) stride (GLsizei : %i) pointer (const GLvoid* : %p)\n", ctx, size, GLenumToString(type).c_str(), stride, pointer);
			return vertex_pointer_reenter(ctx, size, type, stride, pointer);
		} END_MACH_OVERRIDE_PTR(vertex_pointer, obj->disp.vertex_pointer);

		if (err)
			log(LOG_ERR, "Failed to override vertex_pointer: %i", err);

		MACH_OVERRIDE(void,viewport,(GLIContext ctx, GLint x, GLint y, GLsizei width, GLsizei height), err ) {
			file_log("viewport called: ctx (GLIContext : %p) x (GLint : %i) y (GLint : %i) width (GLsizei : %i) height (GLsizei : %i)\n", ctx, x, y, width, height);
			return viewport_reenter(ctx, x, y, width, height);
		} END_MACH_OVERRIDE_PTR(viewport, obj->disp.viewport);

		if (err)
			log(LOG_ERR, "Failed to override viewport: %i", err);

		MACH_OVERRIDE(void,blend_func_separate,(GLIContext ctx, GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha), err ) {
			file_log("blend_func_separate called: ctx (GLIContext : %p) sfactorRGB (GLenum : %s) dfactorRGB (GLenum : %s) sfactorAlpha (GLenum : %s) dfactorAlpha (GLenum : %s)\n", ctx, GLenumToString(sfactorRGB).c_str(), GLenumToString(dfactorRGB).c_str(), GLenumToString(sfactorAlpha).c_str(), GLenumToString(dfactorAlpha).c_str());
			return blend_func_separate_reenter(ctx, sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
		} END_MACH_OVERRIDE_PTR(blend_func_separate, obj->disp.blend_func_separate);

		if (err)
			log(LOG_ERR, "Failed to override blend_func_separate: %i", err);

		MACH_OVERRIDE(void,blend_color,(GLIContext ctx, GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha), err ) {
			file_log("blend_color called: ctx (GLIContext : %p) red (GLclampf : %f) green (GLclampf : %f) blue (GLclampf : %f) alpha (GLclampf : %f)\n", ctx, red, green, blue, alpha);
			return blend_color_reenter(ctx, red, green, blue, alpha);
		} END_MACH_OVERRIDE_PTR(blend_color, obj->disp.blend_color);

		if (err)
			log(LOG_ERR, "Failed to override blend_color: %i", err);

		MACH_OVERRIDE(void,blend_equation,(GLIContext ctx, GLenum mode), err ) {
			file_log("blend_equation called: ctx (GLIContext : %p) mode (GLenum : %s)\n", ctx, GLenumToString(mode).c_str());
			return blend_equation_reenter(ctx, mode);
		} END_MACH_OVERRIDE_PTR(blend_equation, obj->disp.blend_equation);

		if (err)
			log(LOG_ERR, "Failed to override blend_equation: %i", err);

		MACH_OVERRIDE(void,lock_arrays_EXT,(GLIContext ctx, GLint first, GLsizei count), err ) {
			file_log("lock_arrays_EXT called: ctx (GLIContext : %p) first (GLint : %i) count (GLsizei : %i)\n", ctx, first, count);
			return lock_arrays_EXT_reenter(ctx, first, count);
		} END_MACH_OVERRIDE_PTR(lock_arrays_EXT, obj->disp.lock_arrays_EXT);

		if (err)
			log(LOG_ERR, "Failed to override lock_arrays_EXT: %i", err);

		MACH_OVERRIDE(void,unlock_arrays_EXT,(GLIContext ctx), err ) {
			file_log("unlock_arrays_EXT called: ctx (GLIContext : %p)\n", ctx);
			return unlock_arrays_EXT_reenter(ctx);
		} END_MACH_OVERRIDE_PTR(unlock_arrays_EXT, obj->disp.unlock_arrays_EXT);

		if (err)
			log(LOG_ERR, "Failed to override unlock_arrays_EXT: %i", err);

		MACH_OVERRIDE(void,client_active_texture,(GLIContext ctx, GLenum target), err ) {
			file_log("client_active_texture called: ctx (GLIContext : %p) target (GLenum : %s)\n", ctx, GLenumToString(target).c_str());
			return client_active_texture_reenter(ctx, target);
		} END_MACH_OVERRIDE_PTR(client_active_texture, obj->disp.client_active_texture);

		if (err)
			log(LOG_ERR, "Failed to override client_active_texture: %i", err);

		MACH_OVERRIDE(void,active_texture,(GLIContext ctx, GLenum target), err ) {
			file_log("active_texture called: ctx (GLIContext : %p) target (GLenum : %s)\n", ctx, GLenumToString(target).c_str());
			OpenGL::StateMachine::Shared.active_texture(ctx, target);
			return active_texture_reenter(ctx, target);
		} END_MACH_OVERRIDE_PTR(active_texture, obj->disp.active_texture);

		if (err)
			log(LOG_ERR, "Failed to override active_texture: %i", err);

		MACH_OVERRIDE(void,multi_tex_coord1d,(GLIContext ctx, GLenum target, GLdouble s), err ) {
			file_log("multi_tex_coord1d called: ctx (GLIContext : %p) target (GLenum : %s) s (GLdouble : %f)\n", ctx, GLenumToString(target).c_str(), s);
			return multi_tex_coord1d_reenter(ctx, target, s);
		} END_MACH_OVERRIDE_PTR(multi_tex_coord1d, obj->disp.multi_tex_coord1d);

		if (err)
			log(LOG_ERR, "Failed to override multi_tex_coord1d: %i", err);

		MACH_OVERRIDE(void,multi_tex_coord1dv,(GLIContext ctx, GLenum target, const GLdouble *v), err ) {
			file_log("multi_tex_coord1dv called: ctx (GLIContext : %p) target (GLenum : %s) v (const GLdouble* : %p)\n", ctx, GLenumToString(target).c_str(), v);
			return multi_tex_coord1dv_reenter(ctx, target, v);
		} END_MACH_OVERRIDE_PTR(multi_tex_coord1dv, obj->disp.multi_tex_coord1dv);

		if (err)
			log(LOG_ERR, "Failed to override multi_tex_coord1dv: %i", err);

		MACH_OVERRIDE(void,multi_tex_coord1f,(GLIContext ctx, GLenum target, GLfloat s), err ) {
			file_log("multi_tex_coord1f called: ctx (GLIContext : %p) target (GLenum : %s) s (GLfloat : %f)\n", ctx, GLenumToString(target).c_str(), s);
			return multi_tex_coord1f_reenter(ctx, target, s);
		} END_MACH_OVERRIDE_PTR(multi_tex_coord1f, obj->disp.multi_tex_coord1f);

		if (err)
			log(LOG_ERR, "Failed to override multi_tex_coord1f: %i", err);

		MACH_OVERRIDE(void,multi_tex_coord1fv,(GLIContext ctx, GLenum target, const GLfloat *v), err ) {
			file_log("multi_tex_coord1fv called: ctx (GLIContext : %p) target (GLenum : %s) v (const GLfloat* : %p)\n", ctx, GLenumToString(target).c_str(), v);
			return multi_tex_coord1fv_reenter(ctx, target, v);
		} END_MACH_OVERRIDE_PTR(multi_tex_coord1fv, obj->disp.multi_tex_coord1fv);

		if (err)
			log(LOG_ERR, "Failed to override multi_tex_coord1fv: %i", err);

		MACH_OVERRIDE(void,multi_tex_coord1i,(GLIContext ctx, GLenum target, GLint s), err ) {
			file_log("multi_tex_coord1i called: ctx (GLIContext : %p) target (GLenum : %s) s (GLint : %i)\n", ctx, GLenumToString(target).c_str(), s);
			return multi_tex_coord1i_reenter(ctx, target, s);
		} END_MACH_OVERRIDE_PTR(multi_tex_coord1i, obj->disp.multi_tex_coord1i);

		if (err)
			log(LOG_ERR, "Failed to override multi_tex_coord1i: %i", err);

		MACH_OVERRIDE(void,multi_tex_coord1iv,(GLIContext ctx, GLenum target, const GLint *v), err ) {
			file_log("multi_tex_coord1iv called: ctx (GLIContext : %p) target (GLenum : %s) v (const GLint* : %p)\n", ctx, GLenumToString(target).c_str(), v);
			return multi_tex_coord1iv_reenter(ctx, target, v);
		} END_MACH_OVERRIDE_PTR(multi_tex_coord1iv, obj->disp.multi_tex_coord1iv);

		if (err)
			log(LOG_ERR, "Failed to override multi_tex_coord1iv: %i", err);

		MACH_OVERRIDE(void,multi_tex_coord1s,(GLIContext ctx, GLenum target, GLshort s), err ) {
			file_log("multi_tex_coord1s called: ctx (GLIContext : %p) target (GLenum : %s) s (GLshort : %i)\n", ctx, GLenumToString(target).c_str(), s);
			return multi_tex_coord1s_reenter(ctx, target, s);
		} END_MACH_OVERRIDE_PTR(multi_tex_coord1s, obj->disp.multi_tex_coord1s);

		if (err)
			log(LOG_ERR, "Failed to override multi_tex_coord1s: %i", err);

		MACH_OVERRIDE(void,multi_tex_coord1sv,(GLIContext ctx, GLenum target, const GLshort *v), err ) {
			file_log("multi_tex_coord1sv called: ctx (GLIContext : %p) target (GLenum : %s) v (const GLshort* : %p)\n", ctx, GLenumToString(target).c_str(), v);
			return multi_tex_coord1sv_reenter(ctx, target, v);
		} END_MACH_OVERRIDE_PTR(multi_tex_coord1sv, obj->disp.multi_tex_coord1sv);

		if (err)
			log(LOG_ERR, "Failed to override multi_tex_coord1sv: %i", err);

		MACH_OVERRIDE(void,multi_tex_coord2d,(GLIContext ctx, GLenum target, GLdouble s, GLdouble t), err ) {
			file_log("multi_tex_coord2d called: ctx (GLIContext : %p) target (GLenum : %s) s (GLdouble : %f) t (GLdouble : %f)\n", ctx, GLenumToString(target).c_str(), s, t);
			return multi_tex_coord2d_reenter(ctx, target, s, t);
		} END_MACH_OVERRIDE_PTR(multi_tex_coord2d, obj->disp.multi_tex_coord2d);

		if (err)
			log(LOG_ERR, "Failed to override multi_tex_coord2d: %i", err);

		MACH_OVERRIDE(void,multi_tex_coord2dv,(GLIContext ctx, GLenum target, const GLdouble *v), err ) {
			file_log("multi_tex_coord2dv called: ctx (GLIContext : %p) target (GLenum : %s) v (const GLdouble* : %p)\n", ctx, GLenumToString(target).c_str(), v);
			return multi_tex_coord2dv_reenter(ctx, target, v);
		} END_MACH_OVERRIDE_PTR(multi_tex_coord2dv, obj->disp.multi_tex_coord2dv);

		if (err)
			log(LOG_ERR, "Failed to override multi_tex_coord2dv: %i", err);

		MACH_OVERRIDE(void,multi_tex_coord2f,(GLIContext ctx, GLenum target, GLfloat s, GLfloat t), err ) {
			file_log("multi_tex_coord2f called: ctx (GLIContext : %p) target (GLenum : %s) s (GLfloat : %f) t (GLfloat : %f)\n", ctx, GLenumToString(target).c_str(), s, t);
			return multi_tex_coord2f_reenter(ctx, target, s, t);
		} END_MACH_OVERRIDE_PTR(multi_tex_coord2f, obj->disp.multi_tex_coord2f);

		if (err)
			log(LOG_ERR, "Failed to override multi_tex_coord2f: %i", err);

		MACH_OVERRIDE(void,multi_tex_coord2fv,(GLIContext ctx, GLenum target, const GLfloat *v), err ) {
			file_log("multi_tex_coord2fv called: ctx (GLIContext : %p) target (GLenum : %s) v (const GLfloat* : %p)\n", ctx, GLenumToString(target).c_str(), v);
			return multi_tex_coord2fv_reenter(ctx, target, v);
		} END_MACH_OVERRIDE_PTR(multi_tex_coord2fv, obj->disp.multi_tex_coord2fv);

		if (err)
			log(LOG_ERR, "Failed to override multi_tex_coord2fv: %i", err);

		MACH_OVERRIDE(void,multi_tex_coord2i,(GLIContext ctx, GLenum target, GLint s, GLint t), err ) {
			file_log("multi_tex_coord2i called: ctx (GLIContext : %p) target (GLenum : %s) s (GLint : %i) t (GLint : %i)\n", ctx, GLenumToString(target).c_str(), s, t);
			return multi_tex_coord2i_reenter(ctx, target, s, t);
		} END_MACH_OVERRIDE_PTR(multi_tex_coord2i, obj->disp.multi_tex_coord2i);

		if (err)
			log(LOG_ERR, "Failed to override multi_tex_coord2i: %i", err);

		MACH_OVERRIDE(void,multi_tex_coord2iv,(GLIContext ctx, GLenum target, const GLint *v), err ) {
			file_log("multi_tex_coord2iv called: ctx (GLIContext : %p) target (GLenum : %s) v (const GLint* : %p)\n", ctx, GLenumToString(target).c_str(), v);
			return multi_tex_coord2iv_reenter(ctx, target, v);
		} END_MACH_OVERRIDE_PTR(multi_tex_coord2iv, obj->disp.multi_tex_coord2iv);

		if (err)
			log(LOG_ERR, "Failed to override multi_tex_coord2iv: %i", err);

		MACH_OVERRIDE(void,multi_tex_coord2s,(GLIContext ctx, GLenum target, GLshort s, GLshort t), err ) {
			file_log("multi_tex_coord2s called: ctx (GLIContext : %p) target (GLenum : %s) s (GLshort : %i) t (GLshort : %i)\n", ctx, GLenumToString(target).c_str(), s, t);
			return multi_tex_coord2s_reenter(ctx, target, s, t);
		} END_MACH_OVERRIDE_PTR(multi_tex_coord2s, obj->disp.multi_tex_coord2s);

		if (err)
			log(LOG_ERR, "Failed to override multi_tex_coord2s: %i", err);

		MACH_OVERRIDE(void,multi_tex_coord2sv,(GLIContext ctx, GLenum target, const GLshort *v), err ) {
			file_log("multi_tex_coord2sv called: ctx (GLIContext : %p) target (GLenum : %s) v (const GLshort* : %p)\n", ctx, GLenumToString(target).c_str(), v);
			return multi_tex_coord2sv_reenter(ctx, target, v);
		} END_MACH_OVERRIDE_PTR(multi_tex_coord2sv, obj->disp.multi_tex_coord2sv);

		if (err)
			log(LOG_ERR, "Failed to override multi_tex_coord2sv: %i", err);

		MACH_OVERRIDE(void,multi_tex_coord3d,(GLIContext ctx, GLenum target, GLdouble s, GLdouble t, GLdouble r), err ) {
			file_log("multi_tex_coord3d called: ctx (GLIContext : %p) target (GLenum : %s) s (GLdouble : %f) t (GLdouble : %f) r (GLdouble : %f)\n", ctx, GLenumToString(target).c_str(), s, t, r);
			return multi_tex_coord3d_reenter(ctx, target, s, t, r);
		} END_MACH_OVERRIDE_PTR(multi_tex_coord3d, obj->disp.multi_tex_coord3d);

		if (err)
			log(LOG_ERR, "Failed to override multi_tex_coord3d: %i", err);

		MACH_OVERRIDE(void,multi_tex_coord3dv,(GLIContext ctx, GLenum target, const GLdouble *v), err ) {
			file_log("multi_tex_coord3dv called: ctx (GLIContext : %p) target (GLenum : %s) v (const GLdouble* : %p)\n", ctx, GLenumToString(target).c_str(), v);
			return multi_tex_coord3dv_reenter(ctx, target, v);
		} END_MACH_OVERRIDE_PTR(multi_tex_coord3dv, obj->disp.multi_tex_coord3dv);

		if (err)
			log(LOG_ERR, "Failed to override multi_tex_coord3dv: %i", err);

		MACH_OVERRIDE(void,multi_tex_coord3f,(GLIContext ctx, GLenum target, GLfloat s, GLfloat t, GLfloat r), err ) {
			file_log("multi_tex_coord3f called: ctx (GLIContext : %p) target (GLenum : %s) s (GLfloat : %f) t (GLfloat : %f) r (GLfloat : %f)\n", ctx, GLenumToString(target).c_str(), s, t, r);
			return multi_tex_coord3f_reenter(ctx, target, s, t, r);
		} END_MACH_OVERRIDE_PTR(multi_tex_coord3f, obj->disp.multi_tex_coord3f);

		if (err)
			log(LOG_ERR, "Failed to override multi_tex_coord3f: %i", err);

		MACH_OVERRIDE(void,multi_tex_coord3fv,(GLIContext ctx, GLenum target, const GLfloat *v), err ) {
			file_log("multi_tex_coord3fv called: ctx (GLIContext : %p) target (GLenum : %s) v (const GLfloat* : %p)\n", ctx, GLenumToString(target).c_str(), v);
			return multi_tex_coord3fv_reenter(ctx, target, v);
		} END_MACH_OVERRIDE_PTR(multi_tex_coord3fv, obj->disp.multi_tex_coord3fv);

		if (err)
			log(LOG_ERR, "Failed to override multi_tex_coord3fv: %i", err);

		MACH_OVERRIDE(void,multi_tex_coord3i,(GLIContext ctx, GLenum target, GLint s, GLint t, GLint r), err ) {
			file_log("multi_tex_coord3i called: ctx (GLIContext : %p) target (GLenum : %s) s (GLint : %i) t (GLint : %i) r (GLint : %i)\n", ctx, GLenumToString(target).c_str(), s, t, r);
			return multi_tex_coord3i_reenter(ctx, target, s, t, r);
		} END_MACH_OVERRIDE_PTR(multi_tex_coord3i, obj->disp.multi_tex_coord3i);

		if (err)
			log(LOG_ERR, "Failed to override multi_tex_coord3i: %i", err);

		MACH_OVERRIDE(void,multi_tex_coord3iv,(GLIContext ctx, GLenum target, const GLint *v), err ) {
			file_log("multi_tex_coord3iv called: ctx (GLIContext : %p) target (GLenum : %s) v (const GLint* : %p)\n", ctx, GLenumToString(target).c_str(), v);
			return multi_tex_coord3iv_reenter(ctx, target, v);
		} END_MACH_OVERRIDE_PTR(multi_tex_coord3iv, obj->disp.multi_tex_coord3iv);

		if (err)
			log(LOG_ERR, "Failed to override multi_tex_coord3iv: %i", err);

		MACH_OVERRIDE(void,multi_tex_coord3s,(GLIContext ctx, GLenum target, GLshort s, GLshort t, GLshort r), err ) {
			file_log("multi_tex_coord3s called: ctx (GLIContext : %p) target (GLenum : %s) s (GLshort : %i) t (GLshort : %i) r (GLshort : %i)\n", ctx, GLenumToString(target).c_str(), s, t, r);
			return multi_tex_coord3s_reenter(ctx, target, s, t, r);
		} END_MACH_OVERRIDE_PTR(multi_tex_coord3s, obj->disp.multi_tex_coord3s);

		if (err)
			log(LOG_ERR, "Failed to override multi_tex_coord3s: %i", err);

		MACH_OVERRIDE(void,multi_tex_coord3sv,(GLIContext ctx, GLenum target, const GLshort *v), err ) {
			file_log("multi_tex_coord3sv called: ctx (GLIContext : %p) target (GLenum : %s) v (const GLshort* : %p)\n", ctx, GLenumToString(target).c_str(), v);
			return multi_tex_coord3sv_reenter(ctx, target, v);
		} END_MACH_OVERRIDE_PTR(multi_tex_coord3sv, obj->disp.multi_tex_coord3sv);

		if (err)
			log(LOG_ERR, "Failed to override multi_tex_coord3sv: %i", err);

		MACH_OVERRIDE(void,multi_tex_coord4d,(GLIContext ctx, GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q), err ) {
			file_log("multi_tex_coord4d called: ctx (GLIContext : %p) target (GLenum : %s) s (GLdouble : %f) t (GLdouble : %f) r (GLdouble : %f) q (GLdouble : %f)\n", ctx, GLenumToString(target).c_str(), s, t, r, q);
			return multi_tex_coord4d_reenter(ctx, target, s, t, r, q);
		} END_MACH_OVERRIDE_PTR(multi_tex_coord4d, obj->disp.multi_tex_coord4d);

		if (err)
			log(LOG_ERR, "Failed to override multi_tex_coord4d: %i", err);

		MACH_OVERRIDE(void,multi_tex_coord4dv,(GLIContext ctx, GLenum target, const GLdouble *v), err ) {
			file_log("multi_tex_coord4dv called: ctx (GLIContext : %p) target (GLenum : %s) v (const GLdouble* : %p)\n", ctx, GLenumToString(target).c_str(), v);
			return multi_tex_coord4dv_reenter(ctx, target, v);
		} END_MACH_OVERRIDE_PTR(multi_tex_coord4dv, obj->disp.multi_tex_coord4dv);

		if (err)
			log(LOG_ERR, "Failed to override multi_tex_coord4dv: %i", err);

		MACH_OVERRIDE(void,multi_tex_coord4f,(GLIContext ctx, GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q), err ) {
			file_log("multi_tex_coord4f called: ctx (GLIContext : %p) target (GLenum : %s) s (GLfloat : %f) t (GLfloat : %f) r (GLfloat : %f) q (GLfloat : %f)\n", ctx, GLenumToString(target).c_str(), s, t, r, q);
			return multi_tex_coord4f_reenter(ctx, target, s, t, r, q);
		} END_MACH_OVERRIDE_PTR(multi_tex_coord4f, obj->disp.multi_tex_coord4f);

		if (err)
			log(LOG_ERR, "Failed to override multi_tex_coord4f: %i", err);

		MACH_OVERRIDE(void,multi_tex_coord4fv,(GLIContext ctx, GLenum target, const GLfloat *v), err ) {
			file_log("multi_tex_coord4fv called: ctx (GLIContext : %p) target (GLenum : %s) v (const GLfloat* : %p)\n", ctx, GLenumToString(target).c_str(), v);
			return multi_tex_coord4fv_reenter(ctx, target, v);
		} END_MACH_OVERRIDE_PTR(multi_tex_coord4fv, obj->disp.multi_tex_coord4fv);

		if (err)
			log(LOG_ERR, "Failed to override multi_tex_coord4fv: %i", err);

		MACH_OVERRIDE(void,multi_tex_coord4i,(GLIContext ctx, GLenum target, GLint s, GLint t, GLint r, GLint q), err ) {
			file_log("multi_tex_coord4i called: ctx (GLIContext : %p) target (GLenum : %s) s (GLint : %i) t (GLint : %i) r (GLint : %i) q (GLint : %i)\n", ctx, GLenumToString(target).c_str(), s, t, r, q);
			return multi_tex_coord4i_reenter(ctx, target, s, t, r, q);
		} END_MACH_OVERRIDE_PTR(multi_tex_coord4i, obj->disp.multi_tex_coord4i);

		if (err)
			log(LOG_ERR, "Failed to override multi_tex_coord4i: %i", err);

		MACH_OVERRIDE(void,multi_tex_coord4iv,(GLIContext ctx, GLenum target, const GLint *v), err ) {
			file_log("multi_tex_coord4iv called: ctx (GLIContext : %p) target (GLenum : %s) v (const GLint* : %p)\n", ctx, GLenumToString(target).c_str(), v);
			return multi_tex_coord4iv_reenter(ctx, target, v);
		} END_MACH_OVERRIDE_PTR(multi_tex_coord4iv, obj->disp.multi_tex_coord4iv);

		if (err)
			log(LOG_ERR, "Failed to override multi_tex_coord4iv: %i", err);

		MACH_OVERRIDE(void,multi_tex_coord4s,(GLIContext ctx, GLenum target, GLshort s, GLshort t, GLshort r, GLshort q), err ) {
			file_log("multi_tex_coord4s called: ctx (GLIContext : %p) target (GLenum : %s) s (GLshort : %i) t (GLshort : %i) r (GLshort : %i) q (GLshort : %i)\n", ctx, GLenumToString(target).c_str(), s, t, r, q);
			return multi_tex_coord4s_reenter(ctx, target, s, t, r, q);
		} END_MACH_OVERRIDE_PTR(multi_tex_coord4s, obj->disp.multi_tex_coord4s);

		if (err)
			log(LOG_ERR, "Failed to override multi_tex_coord4s: %i", err);

		MACH_OVERRIDE(void,multi_tex_coord4sv,(GLIContext ctx, GLenum target, const GLshort *v), err ) {
			file_log("multi_tex_coord4sv called: ctx (GLIContext : %p) target (GLenum : %s) v (const GLshort* : %p)\n", ctx, GLenumToString(target).c_str(), v);
			return multi_tex_coord4sv_reenter(ctx, target, v);
		} END_MACH_OVERRIDE_PTR(multi_tex_coord4sv, obj->disp.multi_tex_coord4sv);

		if (err)
			log(LOG_ERR, "Failed to override multi_tex_coord4sv: %i", err);

		MACH_OVERRIDE(void,load_transpose_matrixd,(GLIContext ctx, const GLdouble *m), err ) {
			file_log("load_transpose_matrixd called: ctx (GLIContext : %p) m (const GLdouble* : %p)\n", ctx, m);
			return load_transpose_matrixd_reenter(ctx, m);
		} END_MACH_OVERRIDE_PTR(load_transpose_matrixd, obj->disp.load_transpose_matrixd);

		if (err)
			log(LOG_ERR, "Failed to override load_transpose_matrixd: %i", err);

		MACH_OVERRIDE(void,load_transpose_matrixf,(GLIContext ctx, const GLfloat *m), err ) {
			file_log("load_transpose_matrixf called: ctx (GLIContext : %p) m (const GLfloat* : %p)\n", ctx, m);
			return load_transpose_matrixf_reenter(ctx, m);
		} END_MACH_OVERRIDE_PTR(load_transpose_matrixf, obj->disp.load_transpose_matrixf);

		if (err)
			log(LOG_ERR, "Failed to override load_transpose_matrixf: %i", err);

		MACH_OVERRIDE(void,mult_transpose_matrixd,(GLIContext ctx, const GLdouble *m), err ) {
			file_log("mult_transpose_matrixd called: ctx (GLIContext : %p) m (const GLdouble* : %p)\n", ctx, m);
			return mult_transpose_matrixd_reenter(ctx, m);
		} END_MACH_OVERRIDE_PTR(mult_transpose_matrixd, obj->disp.mult_transpose_matrixd);

		if (err)
			log(LOG_ERR, "Failed to override mult_transpose_matrixd: %i", err);

		MACH_OVERRIDE(void,mult_transpose_matrixf,(GLIContext ctx, const GLfloat *m), err ) {
			file_log("mult_transpose_matrixf called: ctx (GLIContext : %p) m (const GLfloat* : %p)\n", ctx, m);
			return mult_transpose_matrixf_reenter(ctx, m);
		} END_MACH_OVERRIDE_PTR(mult_transpose_matrixf, obj->disp.mult_transpose_matrixf);

		if (err)
			log(LOG_ERR, "Failed to override mult_transpose_matrixf: %i", err);

		MACH_OVERRIDE(void,compressed_tex_image3D,(GLIContext ctx, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *data), err ) {
			file_log("compressed_tex_image3D called: ctx (GLIContext : %p) target (GLenum : %s) level (GLint : %i) internalformat (GLenum : %s) width (GLsizei : %i) height (GLsizei : %i) depth (GLsizei : %i) border (GLint : %i) imageSize (GLsizei : %i) data (const GLvoid* : %p)\n", ctx, GLenumToString(target).c_str(), level, GLenumToString(internalformat).c_str(), width, height, depth, border, imageSize, data);
			return compressed_tex_image3D_reenter(ctx, target, level, internalformat, width, height, depth, border, imageSize, data);
		} END_MACH_OVERRIDE_PTR(compressed_tex_image3D, obj->disp.compressed_tex_image3D);

		if (err)
			log(LOG_ERR, "Failed to override compressed_tex_image3D: %i", err);

		MACH_OVERRIDE(void,compressed_tex_image2D,(GLIContext ctx, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data), err ) {
			file_log("compressed_tex_image2D called: ctx (GLIContext : %p) target (GLenum : %s) level (GLint : %i) internalformat (GLenum : %s) width (GLsizei : %i) height (GLsizei : %i) border (GLint : %i) imageSize (GLsizei : %i) data (const GLvoid* : %p)\n", ctx, GLenumToString(target).c_str(), level, GLenumToString(internalformat).c_str(), width, height, border, imageSize, data);
			return compressed_tex_image2D_reenter(ctx, target, level, internalformat, width, height, border, imageSize, data);
		} END_MACH_OVERRIDE_PTR(compressed_tex_image2D, obj->disp.compressed_tex_image2D);

		if (err)
			log(LOG_ERR, "Failed to override compressed_tex_image2D: %i", err);

		MACH_OVERRIDE(void,compressed_tex_image1D,(GLIContext ctx, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data), err ) {
			file_log("compressed_tex_image1D called: ctx (GLIContext : %p) target (GLenum : %s) level (GLint : %i) internalformat (GLenum : %s) width (GLsizei : %i) border (GLint : %i) imageSize (GLsizei : %i) data (const GLvoid* : %p)\n", ctx, GLenumToString(target).c_str(), level, GLenumToString(internalformat).c_str(), width, border, imageSize, data);
			return compressed_tex_image1D_reenter(ctx, target, level, internalformat, width, border, imageSize, data);
		} END_MACH_OVERRIDE_PTR(compressed_tex_image1D, obj->disp.compressed_tex_image1D);

		if (err)
			log(LOG_ERR, "Failed to override compressed_tex_image1D: %i", err);

		MACH_OVERRIDE(void,compressed_tex_sub_image3D,(GLIContext ctx, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data), err ) {
			file_log("compressed_tex_sub_image3D called: ctx (GLIContext : %p) target (GLenum : %s) level (GLint : %i) xoffset (GLint : %i) yoffset (GLint : %i) zoffset (GLint : %i) width (GLsizei : %i) height (GLsizei : %i) depth (GLsizei : %i) format (GLenum : %s) imageSize (GLsizei : %i) data (const GLvoid* : %p)\n", ctx, GLenumToString(target).c_str(), level, xoffset, yoffset, zoffset, width, height, depth, GLenumToString(format).c_str(), imageSize, data);
			return compressed_tex_sub_image3D_reenter(ctx, target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
		} END_MACH_OVERRIDE_PTR(compressed_tex_sub_image3D, obj->disp.compressed_tex_sub_image3D);

		if (err)
			log(LOG_ERR, "Failed to override compressed_tex_sub_image3D: %i", err);

		MACH_OVERRIDE(void,compressed_tex_sub_image2D,(GLIContext ctx, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data), err ) {
			file_log("compressed_tex_sub_image2D called: ctx (GLIContext : %p) target (GLenum : %s) level (GLint : %i) xoffset (GLint : %i) yoffset (GLint : %i) width (GLsizei : %i) height (GLsizei : %i) format (GLenum : %s) imageSize (GLsizei : %i) data (const GLvoid* : %p)\n", ctx, GLenumToString(target).c_str(), level, xoffset, yoffset, width, height, GLenumToString(format).c_str(), imageSize, data);
			return compressed_tex_sub_image2D_reenter(ctx, target, level, xoffset, yoffset, width, height, format, imageSize, data);
		} END_MACH_OVERRIDE_PTR(compressed_tex_sub_image2D, obj->disp.compressed_tex_sub_image2D);

		if (err)
			log(LOG_ERR, "Failed to override compressed_tex_sub_image2D: %i", err);

		MACH_OVERRIDE(void,compressed_tex_sub_image1D,(GLIContext ctx, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data), err ) {
			file_log("compressed_tex_sub_image1D called: ctx (GLIContext : %p) target (GLenum : %s) level (GLint : %i) xoffset (GLint : %i) width (GLsizei : %i) format (GLenum : %s) imageSize (GLsizei : %i) data (const GLvoid* : %p)\n", ctx, GLenumToString(target).c_str(), level, xoffset, width, GLenumToString(format).c_str(), imageSize, data);
			return compressed_tex_sub_image1D_reenter(ctx, target, level, xoffset, width, format, imageSize, data);
		} END_MACH_OVERRIDE_PTR(compressed_tex_sub_image1D, obj->disp.compressed_tex_sub_image1D);

		if (err)
			log(LOG_ERR, "Failed to override compressed_tex_sub_image1D: %i", err);

		MACH_OVERRIDE(void,get_compressed_tex_image,(GLIContext ctx, GLenum target, GLint level, GLvoid *img), err ) {
			file_log("get_compressed_tex_image called: ctx (GLIContext : %p) target (GLenum : %s) level (GLint : %i) img (GLvoid* : %p)\n", ctx, GLenumToString(target).c_str(), level, img);
			return get_compressed_tex_image_reenter(ctx, target, level, img);
		} END_MACH_OVERRIDE_PTR(get_compressed_tex_image, obj->disp.get_compressed_tex_image);

		if (err)
			log(LOG_ERR, "Failed to override get_compressed_tex_image: %i", err);

		MACH_OVERRIDE(void,secondary_color3b,(GLIContext ctx, GLbyte red, GLbyte green, GLbyte blue), err ) {
			file_log("secondary_color3b called: ctx (GLIContext : %p) red (GLbyte : %i) green (GLbyte : %i) blue (GLbyte : %i)\n", ctx, red, green, blue);
			return secondary_color3b_reenter(ctx, red, green, blue);
		} END_MACH_OVERRIDE_PTR(secondary_color3b, obj->disp.secondary_color3b);

		if (err)
			log(LOG_ERR, "Failed to override secondary_color3b: %i", err);

		MACH_OVERRIDE(void,secondary_color3bv,(GLIContext ctx, const GLbyte *v), err ) {
			file_log("secondary_color3bv called: ctx (GLIContext : %p) v (const GLbyte* : %p)\n", ctx, v);
			return secondary_color3bv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(secondary_color3bv, obj->disp.secondary_color3bv);

		if (err)
			log(LOG_ERR, "Failed to override secondary_color3bv: %i", err);

		MACH_OVERRIDE(void,secondary_color3d,(GLIContext ctx, GLdouble red, GLdouble green, GLdouble blue), err ) {
			file_log("secondary_color3d called: ctx (GLIContext : %p) red (GLdouble : %f) green (GLdouble : %f) blue (GLdouble : %f)\n", ctx, red, green, blue);
			return secondary_color3d_reenter(ctx, red, green, blue);
		} END_MACH_OVERRIDE_PTR(secondary_color3d, obj->disp.secondary_color3d);

		if (err)
			log(LOG_ERR, "Failed to override secondary_color3d: %i", err);

		MACH_OVERRIDE(void,secondary_color3dv,(GLIContext ctx, const GLdouble *v), err ) {
			file_log("secondary_color3dv called: ctx (GLIContext : %p) v (const GLdouble* : %p)\n", ctx, v);
			return secondary_color3dv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(secondary_color3dv, obj->disp.secondary_color3dv);

		if (err)
			log(LOG_ERR, "Failed to override secondary_color3dv: %i", err);

		MACH_OVERRIDE(void,secondary_color3f,(GLIContext ctx, GLfloat red, GLfloat green, GLfloat blue), err ) {
			file_log("secondary_color3f called: ctx (GLIContext : %p) red (GLfloat : %f) green (GLfloat : %f) blue (GLfloat : %f)\n", ctx, red, green, blue);
			return secondary_color3f_reenter(ctx, red, green, blue);
		} END_MACH_OVERRIDE_PTR(secondary_color3f, obj->disp.secondary_color3f);

		if (err)
			log(LOG_ERR, "Failed to override secondary_color3f: %i", err);

		MACH_OVERRIDE(void,secondary_color3fv,(GLIContext ctx, const GLfloat *v), err ) {
			file_log("secondary_color3fv called: ctx (GLIContext : %p) v (const GLfloat* : %p)\n", ctx, v);
			return secondary_color3fv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(secondary_color3fv, obj->disp.secondary_color3fv);

		if (err)
			log(LOG_ERR, "Failed to override secondary_color3fv: %i", err);

		MACH_OVERRIDE(void,secondary_color3i,(GLIContext ctx, GLint red, GLint green, GLint blue), err ) {
			file_log("secondary_color3i called: ctx (GLIContext : %p) red (GLint : %i) green (GLint : %i) blue (GLint : %i)\n", ctx, red, green, blue);
			return secondary_color3i_reenter(ctx, red, green, blue);
		} END_MACH_OVERRIDE_PTR(secondary_color3i, obj->disp.secondary_color3i);

		if (err)
			log(LOG_ERR, "Failed to override secondary_color3i: %i", err);

		MACH_OVERRIDE(void,secondary_color3iv,(GLIContext ctx, const GLint *v), err ) {
			file_log("secondary_color3iv called: ctx (GLIContext : %p) v (const GLint* : %p)\n", ctx, v);
			return secondary_color3iv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(secondary_color3iv, obj->disp.secondary_color3iv);

		if (err)
			log(LOG_ERR, "Failed to override secondary_color3iv: %i", err);

		MACH_OVERRIDE(void,secondary_color3s,(GLIContext ctx, GLshort red, GLshort green, GLshort blue), err ) {
			file_log("secondary_color3s called: ctx (GLIContext : %p) red (GLshort : %i) green (GLshort : %i) blue (GLshort : %i)\n", ctx, red, green, blue);
			return secondary_color3s_reenter(ctx, red, green, blue);
		} END_MACH_OVERRIDE_PTR(secondary_color3s, obj->disp.secondary_color3s);

		if (err)
			log(LOG_ERR, "Failed to override secondary_color3s: %i", err);

		MACH_OVERRIDE(void,secondary_color3sv,(GLIContext ctx, const GLshort *v), err ) {
			file_log("secondary_color3sv called: ctx (GLIContext : %p) v (const GLshort* : %p)\n", ctx, v);
			return secondary_color3sv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(secondary_color3sv, obj->disp.secondary_color3sv);

		if (err)
			log(LOG_ERR, "Failed to override secondary_color3sv: %i", err);

		MACH_OVERRIDE(void,secondary_color3ub,(GLIContext ctx, GLubyte red, GLubyte green, GLubyte blue), err ) {
			file_log("secondary_color3ub called: ctx (GLIContext : %p) red (GLubyte : %u) green (GLubyte : %u) blue (GLubyte : %u)\n", ctx, red, green, blue);
			return secondary_color3ub_reenter(ctx, red, green, blue);
		} END_MACH_OVERRIDE_PTR(secondary_color3ub, obj->disp.secondary_color3ub);

		if (err)
			log(LOG_ERR, "Failed to override secondary_color3ub: %i", err);

		MACH_OVERRIDE(void,secondary_color3ubv,(GLIContext ctx, const GLubyte *v), err ) {
			file_log("secondary_color3ubv called: ctx (GLIContext : %p) v (const GLubyte* : %p)\n", ctx, v);
			return secondary_color3ubv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(secondary_color3ubv, obj->disp.secondary_color3ubv);

		if (err)
			log(LOG_ERR, "Failed to override secondary_color3ubv: %i", err);

		MACH_OVERRIDE(void,secondary_color3ui,(GLIContext ctx, GLuint red, GLuint green, GLuint blue), err ) {
			file_log("secondary_color3ui called: ctx (GLIContext : %p) red (GLuint : %u) green (GLuint : %u) blue (GLuint : %u)\n", ctx, red, green, blue);
			return secondary_color3ui_reenter(ctx, red, green, blue);
		} END_MACH_OVERRIDE_PTR(secondary_color3ui, obj->disp.secondary_color3ui);

		if (err)
			log(LOG_ERR, "Failed to override secondary_color3ui: %i", err);

		MACH_OVERRIDE(void,secondary_color3uiv,(GLIContext ctx, const GLuint *v), err ) {
			file_log("secondary_color3uiv called: ctx (GLIContext : %p) v (const GLuint* : %p)\n", ctx, v);
			return secondary_color3uiv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(secondary_color3uiv, obj->disp.secondary_color3uiv);

		if (err)
			log(LOG_ERR, "Failed to override secondary_color3uiv: %i", err);

		MACH_OVERRIDE(void,secondary_color3us,(GLIContext ctx, GLushort red, GLushort green, GLushort blue), err ) {
			file_log("secondary_color3us called: ctx (GLIContext : %p) red (GLushort : %u) green (GLushort : %u) blue (GLushort : %u)\n", ctx, red, green, blue);
			return secondary_color3us_reenter(ctx, red, green, blue);
		} END_MACH_OVERRIDE_PTR(secondary_color3us, obj->disp.secondary_color3us);

		if (err)
			log(LOG_ERR, "Failed to override secondary_color3us: %i", err);

		MACH_OVERRIDE(void,secondary_color3usv,(GLIContext ctx, const GLushort *v), err ) {
			file_log("secondary_color3usv called: ctx (GLIContext : %p) v (const GLushort* : %p)\n", ctx, v);
			return secondary_color3usv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(secondary_color3usv, obj->disp.secondary_color3usv);

		if (err)
			log(LOG_ERR, "Failed to override secondary_color3usv: %i", err);

		MACH_OVERRIDE(void,secondary_color_pointer,(GLIContext ctx, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer), err ) {
			file_log("secondary_color_pointer called: ctx (GLIContext : %p) size (GLint : %i) type (GLenum : %s) stride (GLsizei : %i) pointer (const GLvoid* : %p)\n", ctx, size, GLenumToString(type).c_str(), stride, pointer);
			return secondary_color_pointer_reenter(ctx, size, type, stride, pointer);
		} END_MACH_OVERRIDE_PTR(secondary_color_pointer, obj->disp.secondary_color_pointer);

		if (err)
			log(LOG_ERR, "Failed to override secondary_color_pointer: %i", err);

		MACH_OVERRIDE(void,vertex_array_range_EXT,(GLIContext ctx, GLsizei count, const GLvoid *pointer), err ) {
			file_log("vertex_array_range_EXT called: ctx (GLIContext : %p) count (GLsizei : %i) pointer (const GLvoid* : %p)\n", ctx, count, pointer);
			return vertex_array_range_EXT_reenter(ctx, count, pointer);
		} END_MACH_OVERRIDE_PTR(vertex_array_range_EXT, obj->disp.vertex_array_range_EXT);

		if (err)
			log(LOG_ERR, "Failed to override vertex_array_range_EXT: %i", err);

		MACH_OVERRIDE(void,flush_vertex_array_range_EXT,(GLIContext ctx, GLsizei count, const GLvoid *pointer), err ) {
			file_log("flush_vertex_array_range_EXT called: ctx (GLIContext : %p) count (GLsizei : %i) pointer (const GLvoid* : %p)\n", ctx, count, pointer);
			return flush_vertex_array_range_EXT_reenter(ctx, count, pointer);
		} END_MACH_OVERRIDE_PTR(flush_vertex_array_range_EXT, obj->disp.flush_vertex_array_range_EXT);

		if (err)
			log(LOG_ERR, "Failed to override flush_vertex_array_range_EXT: %i", err);

		MACH_OVERRIDE(void,draw_range_elements,(GLIContext ctx, GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices), err ) {
			file_log("draw_range_elements called: ctx (GLIContext : %p) mode (GLenum : %s) start (GLuint : %u) end (GLuint : %u) count (GLsizei : %i) type (GLenum : %s) indices (const GLvoid* : %p)\n", ctx, GLenumToString(mode).c_str(), start, end, count, GLenumToString(type).c_str(), indices);
			OpenGL::StateMachine::Shared.draw_range_elements(ctx, mode, start, end, count, type, indices);
			return draw_range_elements_reenter(ctx, mode, start, end, count, type, indices);
		} END_MACH_OVERRIDE_PTR(draw_range_elements, obj->disp.draw_range_elements);

		if (err)
			log(LOG_ERR, "Failed to override draw_range_elements: %i", err);

		MACH_OVERRIDE(void,color_table,(GLIContext ctx, GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *table), err ) {
			file_log("color_table called: ctx (GLIContext : %p) target (GLenum : %s) internalformat (GLenum : %s) width (GLsizei : %i) format (GLenum : %s) type (GLenum : %s) table (const GLvoid* : %p)\n", ctx, GLenumToString(target).c_str(), GLenumToString(internalformat).c_str(), width, GLenumToString(format).c_str(), GLenumToString(type).c_str(), table);
			return color_table_reenter(ctx, target, internalformat, width, format, type, table);
		} END_MACH_OVERRIDE_PTR(color_table, obj->disp.color_table);

		if (err)
			log(LOG_ERR, "Failed to override color_table: %i", err);

		MACH_OVERRIDE(void,color_table_parameterfv,(GLIContext ctx, GLenum target, GLenum pname, const GLfloat *params), err ) {
			file_log("color_table_parameterfv called: ctx (GLIContext : %p) target (GLenum : %s) pname (GLenum : %s) params (const GLfloat* : %p)\n", ctx, GLenumToString(target).c_str(), GLenumToString(pname).c_str(), params);
			return color_table_parameterfv_reenter(ctx, target, pname, params);
		} END_MACH_OVERRIDE_PTR(color_table_parameterfv, obj->disp.color_table_parameterfv);

		if (err)
			log(LOG_ERR, "Failed to override color_table_parameterfv: %i", err);

		MACH_OVERRIDE(void,color_table_parameteriv,(GLIContext ctx, GLenum target, GLenum pname, const GLint *params), err ) {
			file_log("color_table_parameteriv called: ctx (GLIContext : %p) target (GLenum : %s) pname (GLenum : %s) params (const GLint* : %p)\n", ctx, GLenumToString(target).c_str(), GLenumToString(pname).c_str(), params);
			return color_table_parameteriv_reenter(ctx, target, pname, params);
		} END_MACH_OVERRIDE_PTR(color_table_parameteriv, obj->disp.color_table_parameteriv);

		if (err)
			log(LOG_ERR, "Failed to override color_table_parameteriv: %i", err);

		MACH_OVERRIDE(void,copy_color_table,(GLIContext ctx, GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width), err ) {
			file_log("copy_color_table called: ctx (GLIContext : %p) target (GLenum : %s) internalformat (GLenum : %s) x (GLint : %i) y (GLint : %i) width (GLsizei : %i)\n", ctx, GLenumToString(target).c_str(), GLenumToString(internalformat).c_str(), x, y, width);
			return copy_color_table_reenter(ctx, target, internalformat, x, y, width);
		} END_MACH_OVERRIDE_PTR(copy_color_table, obj->disp.copy_color_table);

		if (err)
			log(LOG_ERR, "Failed to override copy_color_table: %i", err);

		MACH_OVERRIDE(void,get_color_table,(GLIContext ctx, GLenum target, GLenum format, GLenum type, GLvoid *table), err ) {
			file_log("get_color_table called: ctx (GLIContext : %p) target (GLenum : %s) format (GLenum : %s) type (GLenum : %s) table (GLvoid* : %p)\n", ctx, GLenumToString(target).c_str(), GLenumToString(format).c_str(), GLenumToString(type).c_str(), table);
			return get_color_table_reenter(ctx, target, format, type, table);
		} END_MACH_OVERRIDE_PTR(get_color_table, obj->disp.get_color_table);

		if (err)
			log(LOG_ERR, "Failed to override get_color_table: %i", err);

		MACH_OVERRIDE(void,get_color_table_parameterfv,(GLIContext ctx, GLenum target, GLenum pname, GLfloat *params), err ) {
			file_log("get_color_table_parameterfv called: ctx (GLIContext : %p) target (GLenum : %s) pname (GLenum : %s) params (GLfloat* : %p)\n", ctx, GLenumToString(target).c_str(), GLenumToString(pname).c_str(), params);
			return get_color_table_parameterfv_reenter(ctx, target, pname, params);
		} END_MACH_OVERRIDE_PTR(get_color_table_parameterfv, obj->disp.get_color_table_parameterfv);

		if (err)
			log(LOG_ERR, "Failed to override get_color_table_parameterfv: %i", err);

		MACH_OVERRIDE(void,get_color_table_parameteriv,(GLIContext ctx, GLenum target, GLenum pname, GLint *params), err ) {
			file_log("get_color_table_parameteriv called: ctx (GLIContext : %p) target (GLenum : %s) pname (GLenum : %s) params (GLint* : %p)\n", ctx, GLenumToString(target).c_str(), GLenumToString(pname).c_str(), params);
			return get_color_table_parameteriv_reenter(ctx, target, pname, params);
		} END_MACH_OVERRIDE_PTR(get_color_table_parameteriv, obj->disp.get_color_table_parameteriv);

		if (err)
			log(LOG_ERR, "Failed to override get_color_table_parameteriv: %i", err);

		MACH_OVERRIDE(void,color_sub_table,(GLIContext ctx, GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const GLvoid *data), err ) {
			file_log("color_sub_table called: ctx (GLIContext : %p) target (GLenum : %s) start (GLsizei : %i) count (GLsizei : %i) format (GLenum : %s) type (GLenum : %s) data (const GLvoid* : %p)\n", ctx, GLenumToString(target).c_str(), start, count, GLenumToString(format).c_str(), GLenumToString(type).c_str(), data);
			return color_sub_table_reenter(ctx, target, start, count, format, type, data);
		} END_MACH_OVERRIDE_PTR(color_sub_table, obj->disp.color_sub_table);

		if (err)
			log(LOG_ERR, "Failed to override color_sub_table: %i", err);

		MACH_OVERRIDE(void,copy_color_sub_table,(GLIContext ctx, GLenum target, GLsizei start, GLint x, GLint y, GLsizei width), err ) {
			file_log("copy_color_sub_table called: ctx (GLIContext : %p) target (GLenum : %s) start (GLsizei : %i) x (GLint : %i) y (GLint : %i) width (GLsizei : %i)\n", ctx, GLenumToString(target).c_str(), start, x, y, width);
			return copy_color_sub_table_reenter(ctx, target, start, x, y, width);
		} END_MACH_OVERRIDE_PTR(copy_color_sub_table, obj->disp.copy_color_sub_table);

		if (err)
			log(LOG_ERR, "Failed to override copy_color_sub_table: %i", err);

		MACH_OVERRIDE(void,convolution_filter1D,(GLIContext ctx, GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *image), err ) {
			file_log("convolution_filter1D called: ctx (GLIContext : %p) target (GLenum : %s) internalformat (GLenum : %s) width (GLsizei : %i) format (GLenum : %s) type (GLenum : %s) image (const GLvoid* : %p)\n", ctx, GLenumToString(target).c_str(), GLenumToString(internalformat).c_str(), width, GLenumToString(format).c_str(), GLenumToString(type).c_str(), image);
			return convolution_filter1D_reenter(ctx, target, internalformat, width, format, type, image);
		} END_MACH_OVERRIDE_PTR(convolution_filter1D, obj->disp.convolution_filter1D);

		if (err)
			log(LOG_ERR, "Failed to override convolution_filter1D: %i", err);

		MACH_OVERRIDE(void,convolution_filter2D,(GLIContext ctx, GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *image), err ) {
			file_log("convolution_filter2D called: ctx (GLIContext : %p) target (GLenum : %s) internalformat (GLenum : %s) width (GLsizei : %i) height (GLsizei : %i) format (GLenum : %s) type (GLenum : %s) image (const GLvoid* : %p)\n", ctx, GLenumToString(target).c_str(), GLenumToString(internalformat).c_str(), width, height, GLenumToString(format).c_str(), GLenumToString(type).c_str(), image);
			return convolution_filter2D_reenter(ctx, target, internalformat, width, height, format, type, image);
		} END_MACH_OVERRIDE_PTR(convolution_filter2D, obj->disp.convolution_filter2D);

		if (err)
			log(LOG_ERR, "Failed to override convolution_filter2D: %i", err);

		MACH_OVERRIDE(void,convolution_parameterf,(GLIContext ctx, GLenum target, GLenum pname, GLfloat params), err ) {
			file_log("convolution_parameterf called: ctx (GLIContext : %p) target (GLenum : %s) pname (GLenum : %s) params (GLfloat : %f)\n", ctx, GLenumToString(target).c_str(), GLenumToString(pname).c_str(), params);
			return convolution_parameterf_reenter(ctx, target, pname, params);
		} END_MACH_OVERRIDE_PTR(convolution_parameterf, obj->disp.convolution_parameterf);

		if (err)
			log(LOG_ERR, "Failed to override convolution_parameterf: %i", err);

		MACH_OVERRIDE(void,convolution_parameterfv,(GLIContext ctx, GLenum target, GLenum pname, const GLfloat *params), err ) {
			file_log("convolution_parameterfv called: ctx (GLIContext : %p) target (GLenum : %s) pname (GLenum : %s) params (const GLfloat* : %p)\n", ctx, GLenumToString(target).c_str(), GLenumToString(pname).c_str(), params);
			return convolution_parameterfv_reenter(ctx, target, pname, params);
		} END_MACH_OVERRIDE_PTR(convolution_parameterfv, obj->disp.convolution_parameterfv);

		if (err)
			log(LOG_ERR, "Failed to override convolution_parameterfv: %i", err);

		MACH_OVERRIDE(void,convolution_parameteri,(GLIContext ctx, GLenum target, GLenum pname, GLint params), err ) {
			file_log("convolution_parameteri called: ctx (GLIContext : %p) target (GLenum : %s) pname (GLenum : %s) params (GLint : %i)\n", ctx, GLenumToString(target).c_str(), GLenumToString(pname).c_str(), params);
			return convolution_parameteri_reenter(ctx, target, pname, params);
		} END_MACH_OVERRIDE_PTR(convolution_parameteri, obj->disp.convolution_parameteri);

		if (err)
			log(LOG_ERR, "Failed to override convolution_parameteri: %i", err);

		MACH_OVERRIDE(void,convolution_parameteriv,(GLIContext ctx, GLenum target, GLenum pname, const GLint *params), err ) {
			file_log("convolution_parameteriv called: ctx (GLIContext : %p) target (GLenum : %s) pname (GLenum : %s) params (const GLint* : %p)\n", ctx, GLenumToString(target).c_str(), GLenumToString(pname).c_str(), params);
			return convolution_parameteriv_reenter(ctx, target, pname, params);
		} END_MACH_OVERRIDE_PTR(convolution_parameteriv, obj->disp.convolution_parameteriv);

		if (err)
			log(LOG_ERR, "Failed to override convolution_parameteriv: %i", err);

		MACH_OVERRIDE(void,copy_convolution_filter1D,(GLIContext ctx, GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width), err ) {
			file_log("copy_convolution_filter1D called: ctx (GLIContext : %p) target (GLenum : %s) internalformat (GLenum : %s) x (GLint : %i) y (GLint : %i) width (GLsizei : %i)\n", ctx, GLenumToString(target).c_str(), GLenumToString(internalformat).c_str(), x, y, width);
			return copy_convolution_filter1D_reenter(ctx, target, internalformat, x, y, width);
		} END_MACH_OVERRIDE_PTR(copy_convolution_filter1D, obj->disp.copy_convolution_filter1D);

		if (err)
			log(LOG_ERR, "Failed to override copy_convolution_filter1D: %i", err);

		MACH_OVERRIDE(void,copy_convolution_filter2D,(GLIContext ctx, GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height), err ) {
			file_log("copy_convolution_filter2D called: ctx (GLIContext : %p) target (GLenum : %s) internalformat (GLenum : %s) x (GLint : %i) y (GLint : %i) width (GLsizei : %i) height (GLsizei : %i)\n", ctx, GLenumToString(target).c_str(), GLenumToString(internalformat).c_str(), x, y, width, height);
			return copy_convolution_filter2D_reenter(ctx, target, internalformat, x, y, width, height);
		} END_MACH_OVERRIDE_PTR(copy_convolution_filter2D, obj->disp.copy_convolution_filter2D);

		if (err)
			log(LOG_ERR, "Failed to override copy_convolution_filter2D: %i", err);

		MACH_OVERRIDE(void,get_convolution_filter,(GLIContext ctx, GLenum target, GLenum format, GLenum type, GLvoid *image), err ) {
			file_log("get_convolution_filter called: ctx (GLIContext : %p) target (GLenum : %s) format (GLenum : %s) type (GLenum : %s) image (GLvoid* : %p)\n", ctx, GLenumToString(target).c_str(), GLenumToString(format).c_str(), GLenumToString(type).c_str(), image);
			return get_convolution_filter_reenter(ctx, target, format, type, image);
		} END_MACH_OVERRIDE_PTR(get_convolution_filter, obj->disp.get_convolution_filter);

		if (err)
			log(LOG_ERR, "Failed to override get_convolution_filter: %i", err);

		MACH_OVERRIDE(void,get_convolution_parameterfv,(GLIContext ctx, GLenum target, GLenum pname, GLfloat *params), err ) {
			file_log("get_convolution_parameterfv called: ctx (GLIContext : %p) target (GLenum : %s) pname (GLenum : %s) params (GLfloat* : %p)\n", ctx, GLenumToString(target).c_str(), GLenumToString(pname).c_str(), params);
			return get_convolution_parameterfv_reenter(ctx, target, pname, params);
		} END_MACH_OVERRIDE_PTR(get_convolution_parameterfv, obj->disp.get_convolution_parameterfv);

		if (err)
			log(LOG_ERR, "Failed to override get_convolution_parameterfv: %i", err);

		MACH_OVERRIDE(void,get_convolution_parameteriv,(GLIContext ctx, GLenum target, GLenum pname, GLint *params), err ) {
			file_log("get_convolution_parameteriv called: ctx (GLIContext : %p) target (GLenum : %s) pname (GLenum : %s) params (GLint* : %p)\n", ctx, GLenumToString(target).c_str(), GLenumToString(pname).c_str(), params);
			return get_convolution_parameteriv_reenter(ctx, target, pname, params);
		} END_MACH_OVERRIDE_PTR(get_convolution_parameteriv, obj->disp.get_convolution_parameteriv);

		if (err)
			log(LOG_ERR, "Failed to override get_convolution_parameteriv: %i", err);

		MACH_OVERRIDE(void,get_separable_filter,(GLIContext ctx, GLenum target, GLenum format, GLenum type, GLvoid *row, GLvoid *column, GLvoid *span), err ) {
			file_log("get_separable_filter called: ctx (GLIContext : %p) target (GLenum : %s) format (GLenum : %s) type (GLenum : %s) row (GLvoid* : %p) column (GLvoid* : %p) span (GLvoid* : %p)\n", ctx, GLenumToString(target).c_str(), GLenumToString(format).c_str(), GLenumToString(type).c_str(), row, column, span);
			return get_separable_filter_reenter(ctx, target, format, type, row, column, span);
		} END_MACH_OVERRIDE_PTR(get_separable_filter, obj->disp.get_separable_filter);

		if (err)
			log(LOG_ERR, "Failed to override get_separable_filter: %i", err);

		MACH_OVERRIDE(void,separable_filter2D,(GLIContext ctx, GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *row, const GLvoid *column), err ) {
			file_log("separable_filter2D called: ctx (GLIContext : %p) target (GLenum : %s) internalformat (GLenum : %s) width (GLsizei : %i) height (GLsizei : %i) format (GLenum : %s) type (GLenum : %s) row (const GLvoid* : %p) column (const GLvoid* : %p)\n", ctx, GLenumToString(target).c_str(), GLenumToString(internalformat).c_str(), width, height, GLenumToString(format).c_str(), GLenumToString(type).c_str(), row, column);
			return separable_filter2D_reenter(ctx, target, internalformat, width, height, format, type, row, column);
		} END_MACH_OVERRIDE_PTR(separable_filter2D, obj->disp.separable_filter2D);

		if (err)
			log(LOG_ERR, "Failed to override separable_filter2D: %i", err);

		MACH_OVERRIDE(void,get_histogram,(GLIContext ctx, GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid *values), err ) {
			file_log("get_histogram called: ctx (GLIContext : %p) target (GLenum : %s) reset (GLboolean : %i) format (GLenum : %s) type (GLenum : %s) values (GLvoid* : %p)\n", ctx, GLenumToString(target).c_str(), reset, GLenumToString(format).c_str(), GLenumToString(type).c_str(), values);
			return get_histogram_reenter(ctx, target, reset, format, type, values);
		} END_MACH_OVERRIDE_PTR(get_histogram, obj->disp.get_histogram);

		if (err)
			log(LOG_ERR, "Failed to override get_histogram: %i", err);

		MACH_OVERRIDE(void,get_histogram_parameterfv,(GLIContext ctx, GLenum target, GLenum pname, GLfloat *params), err ) {
			file_log("get_histogram_parameterfv called: ctx (GLIContext : %p) target (GLenum : %s) pname (GLenum : %s) params (GLfloat* : %p)\n", ctx, GLenumToString(target).c_str(), GLenumToString(pname).c_str(), params);
			return get_histogram_parameterfv_reenter(ctx, target, pname, params);
		} END_MACH_OVERRIDE_PTR(get_histogram_parameterfv, obj->disp.get_histogram_parameterfv);

		if (err)
			log(LOG_ERR, "Failed to override get_histogram_parameterfv: %i", err);

		MACH_OVERRIDE(void,get_histogram_parameteriv,(GLIContext ctx, GLenum target, GLenum pname, GLint *params), err ) {
			file_log("get_histogram_parameteriv called: ctx (GLIContext : %p) target (GLenum : %s) pname (GLenum : %s) params (GLint* : %p)\n", ctx, GLenumToString(target).c_str(), GLenumToString(pname).c_str(), params);
			return get_histogram_parameteriv_reenter(ctx, target, pname, params);
		} END_MACH_OVERRIDE_PTR(get_histogram_parameteriv, obj->disp.get_histogram_parameteriv);

		if (err)
			log(LOG_ERR, "Failed to override get_histogram_parameteriv: %i", err);

		MACH_OVERRIDE(void,get_minmax,(GLIContext ctx, GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid *values), err ) {
			file_log("get_minmax called: ctx (GLIContext : %p) target (GLenum : %s) reset (GLboolean : %i) format (GLenum : %s) type (GLenum : %s) values (GLvoid* : %p)\n", ctx, GLenumToString(target).c_str(), reset, GLenumToString(format).c_str(), GLenumToString(type).c_str(), values);
			return get_minmax_reenter(ctx, target, reset, format, type, values);
		} END_MACH_OVERRIDE_PTR(get_minmax, obj->disp.get_minmax);

		if (err)
			log(LOG_ERR, "Failed to override get_minmax: %i", err);

		MACH_OVERRIDE(void,get_minmax_parameterfv,(GLIContext ctx, GLenum target, GLenum pname, GLfloat *params), err ) {
			file_log("get_minmax_parameterfv called: ctx (GLIContext : %p) target (GLenum : %s) pname (GLenum : %s) params (GLfloat* : %p)\n", ctx, GLenumToString(target).c_str(), GLenumToString(pname).c_str(), params);
			return get_minmax_parameterfv_reenter(ctx, target, pname, params);
		} END_MACH_OVERRIDE_PTR(get_minmax_parameterfv, obj->disp.get_minmax_parameterfv);

		if (err)
			log(LOG_ERR, "Failed to override get_minmax_parameterfv: %i", err);

		MACH_OVERRIDE(void,get_minmax_parameteriv,(GLIContext ctx, GLenum target, GLenum pname, GLint *params), err ) {
			file_log("get_minmax_parameteriv called: ctx (GLIContext : %p) target (GLenum : %s) pname (GLenum : %s) params (GLint* : %p)\n", ctx, GLenumToString(target).c_str(), GLenumToString(pname).c_str(), params);
			return get_minmax_parameteriv_reenter(ctx, target, pname, params);
		} END_MACH_OVERRIDE_PTR(get_minmax_parameteriv, obj->disp.get_minmax_parameteriv);

		if (err)
			log(LOG_ERR, "Failed to override get_minmax_parameteriv: %i", err);

		MACH_OVERRIDE(void,histogram,(GLIContext ctx, GLenum target, GLsizei width, GLenum internalformat, GLboolean sink), err ) {
			file_log("histogram called: ctx (GLIContext : %p) target (GLenum : %s) width (GLsizei : %i) internalformat (GLenum : %s) sink (GLboolean : %i)\n", ctx, GLenumToString(target).c_str(), width, GLenumToString(internalformat).c_str(), sink);
			return histogram_reenter(ctx, target, width, internalformat, sink);
		} END_MACH_OVERRIDE_PTR(histogram, obj->disp.histogram);

		if (err)
			log(LOG_ERR, "Failed to override histogram: %i", err);

		MACH_OVERRIDE(void,minmax,(GLIContext ctx, GLenum target, GLenum internalformat, GLboolean sink), err ) {
			file_log("minmax called: ctx (GLIContext : %p) target (GLenum : %s) internalformat (GLenum : %s) sink (GLboolean : %i)\n", ctx, GLenumToString(target).c_str(), GLenumToString(internalformat).c_str(), sink);
			return minmax_reenter(ctx, target, internalformat, sink);
		} END_MACH_OVERRIDE_PTR(minmax, obj->disp.minmax);

		if (err)
			log(LOG_ERR, "Failed to override minmax: %i", err);

		MACH_OVERRIDE(void,reset_histogram,(GLIContext ctx, GLenum target), err ) {
			file_log("reset_histogram called: ctx (GLIContext : %p) target (GLenum : %s)\n", ctx, GLenumToString(target).c_str());
			return reset_histogram_reenter(ctx, target);
		} END_MACH_OVERRIDE_PTR(reset_histogram, obj->disp.reset_histogram);

		if (err)
			log(LOG_ERR, "Failed to override reset_histogram: %i", err);

		MACH_OVERRIDE(void,reset_minmax,(GLIContext ctx, GLenum target), err ) {
			file_log("reset_minmax called: ctx (GLIContext : %p) target (GLenum : %s)\n", ctx, GLenumToString(target).c_str());
			return reset_minmax_reenter(ctx, target);
		} END_MACH_OVERRIDE_PTR(reset_minmax, obj->disp.reset_minmax);

		if (err)
			log(LOG_ERR, "Failed to override reset_minmax: %i", err);

		MACH_OVERRIDE(void,tex_image3D,(GLIContext ctx, GLenum target, GLint level, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels), err ) {
			file_log("tex_image3D called: ctx (GLIContext : %p) target (GLenum : %s) level (GLint : %i) internalFormat (GLenum : %s) width (GLsizei : %i) height (GLsizei : %i) depth (GLsizei : %i) border (GLint : %i) format (GLenum : %s) type (GLenum : %s) pixels (const GLvoid* : %p)\n", ctx, GLenumToString(target).c_str(), level, GLenumToString(internalFormat).c_str(), width, height, depth, border, GLenumToString(format).c_str(), GLenumToString(type).c_str(), pixels);
			return tex_image3D_reenter(ctx, target, level, internalFormat, width, height, depth, border, format, type, pixels);
		} END_MACH_OVERRIDE_PTR(tex_image3D, obj->disp.tex_image3D);

		if (err)
			log(LOG_ERR, "Failed to override tex_image3D: %i", err);

		MACH_OVERRIDE(void,tex_sub_image3D,(GLIContext ctx, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels), err ) {
			file_log("tex_sub_image3D called: ctx (GLIContext : %p) target (GLenum : %s) level (GLint : %i) xoffset (GLint : %i) yoffset (GLint : %i) zoffset (GLint : %i) width (GLsizei : %i) height (GLsizei : %i) depth (GLsizei : %i) format (GLenum : %s) type (GLenum : %s) pixels (const GLvoid* : %p)\n", ctx, GLenumToString(target).c_str(), level, xoffset, yoffset, zoffset, width, height, depth, GLenumToString(format).c_str(), GLenumToString(type).c_str(), pixels);
			return tex_sub_image3D_reenter(ctx, target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
		} END_MACH_OVERRIDE_PTR(tex_sub_image3D, obj->disp.tex_sub_image3D);

		if (err)
			log(LOG_ERR, "Failed to override tex_sub_image3D: %i", err);

		MACH_OVERRIDE(void,copy_tex_sub_image3D,(GLIContext ctx, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height), err ) {
			file_log("copy_tex_sub_image3D called: ctx (GLIContext : %p) target (GLenum : %s) level (GLint : %i) xoffset (GLint : %i) yoffset (GLint : %i) zoffset (GLint : %i) x (GLint : %i) y (GLint : %i) width (GLsizei : %i) height (GLsizei : %i)\n", ctx, GLenumToString(target).c_str(), level, xoffset, yoffset, zoffset, x, y, width, height);
			return copy_tex_sub_image3D_reenter(ctx, target, level, xoffset, yoffset, zoffset, x, y, width, height);
		} END_MACH_OVERRIDE_PTR(copy_tex_sub_image3D, obj->disp.copy_tex_sub_image3D);

		if (err)
			log(LOG_ERR, "Failed to override copy_tex_sub_image3D: %i", err);

		MACH_OVERRIDE(void,get_uniform_indices,(GLIContext ctx, GLuint program, GLsizei uniformCount, const GLchar* const *uniformNames, GLuint* uniformIndices), err ) {
			file_log("get_uniform_indices called: ctx (GLIContext : %p) program (GLuint : %u) uniformCount (GLsizei : %i) uniformNames (const GLchar*const* : %p) uniformIndices (GLuint* : %p)\n", ctx, program, uniformCount, uniformNames, uniformIndices);
			return get_uniform_indices_reenter(ctx, program, uniformCount, uniformNames, uniformIndices);
		} END_MACH_OVERRIDE_PTR(get_uniform_indices, obj->disp.get_uniform_indices);

		if (err)
			log(LOG_ERR, "Failed to override get_uniform_indices: %i", err);

		MACH_OVERRIDE(void,get_active_uniformsiv,(GLIContext ctx, GLuint program, GLsizei uniformCount, const GLuint* uniformIndices, GLenum pname, GLint* params), err ) {
			file_log("get_active_uniformsiv called: ctx (GLIContext : %p) program (GLuint : %u) uniformCount (GLsizei : %i) uniformIndices (const GLuint* : %p) pname (GLenum : %s) params (GLint* : %p)\n", ctx, program, uniformCount, uniformIndices, GLenumToString(pname).c_str(), params);
			return get_active_uniformsiv_reenter(ctx, program, uniformCount, uniformIndices, pname, params);
		} END_MACH_OVERRIDE_PTR(get_active_uniformsiv, obj->disp.get_active_uniformsiv);

		if (err)
			log(LOG_ERR, "Failed to override get_active_uniformsiv: %i", err);

		MACH_OVERRIDE(void,get_active_uniform_name,(GLIContext ctx, GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformName), err ) {
			file_log("get_active_uniform_name called: ctx (GLIContext : %p) program (GLuint : %u) uniformIndex (GLuint : %u) bufSize (GLsizei : %i) length (GLsizei* : %p) uniformName (GLchar* : %p)\n", ctx, program, uniformIndex, bufSize, length, uniformName);
			return get_active_uniform_name_reenter(ctx, program, uniformIndex, bufSize, length, uniformName);
		} END_MACH_OVERRIDE_PTR(get_active_uniform_name, obj->disp.get_active_uniform_name);

		if (err)
			log(LOG_ERR, "Failed to override get_active_uniform_name: %i", err);

		MACH_OVERRIDE(GLuint,get_uniform_block_index,(GLIContext ctx, GLuint program, const GLchar* uniformBlockName), err ) {
			file_log("get_uniform_block_index called: ctx (GLIContext : %p) program (GLuint : %u) uniformBlockName (const GLchar* : %p)\n", ctx, program, uniformBlockName);
			GLuint result = get_uniform_block_index_reenter(ctx, program, uniformBlockName);
			return result;
		} END_MACH_OVERRIDE_PTR(get_uniform_block_index, obj->disp.get_uniform_block_index);

		if (err)
			log(LOG_ERR, "Failed to override get_uniform_block_index: %i", err);

		MACH_OVERRIDE(void,get_active_uniform_blockiv,(GLIContext ctx, GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint* params), err ) {
			file_log("get_active_uniform_blockiv called: ctx (GLIContext : %p) program (GLuint : %u) uniformBlockIndex (GLuint : %u) pname (GLenum : %s) params (GLint* : %p)\n", ctx, program, uniformBlockIndex, GLenumToString(pname).c_str(), params);
			return get_active_uniform_blockiv_reenter(ctx, program, uniformBlockIndex, pname, params);
		} END_MACH_OVERRIDE_PTR(get_active_uniform_blockiv, obj->disp.get_active_uniform_blockiv);

		if (err)
			log(LOG_ERR, "Failed to override get_active_uniform_blockiv: %i", err);

		MACH_OVERRIDE(void,get_active_uniform_block_name,(GLIContext ctx, GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformBlockName), err ) {
			file_log("get_active_uniform_block_name called: ctx (GLIContext : %p) program (GLuint : %u) uniformBlockIndex (GLuint : %u) bufSize (GLsizei : %i) length (GLsizei* : %p) uniformBlockName (GLchar* : %p)\n", ctx, program, uniformBlockIndex, bufSize, length, uniformBlockName);
			return get_active_uniform_block_name_reenter(ctx, program, uniformBlockIndex, bufSize, length, uniformBlockName);
		} END_MACH_OVERRIDE_PTR(get_active_uniform_block_name, obj->disp.get_active_uniform_block_name);

		if (err)
			log(LOG_ERR, "Failed to override get_active_uniform_block_name: %i", err);

		MACH_OVERRIDE(void,uniform_block_binding,(GLIContext ctx, GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding), err ) {
			file_log("uniform_block_binding called: ctx (GLIContext : %p) program (GLuint : %u) uniformBlockIndex (GLuint : %u) uniformBlockBinding (GLuint : %u)\n", ctx, program, uniformBlockIndex, uniformBlockBinding);
			return uniform_block_binding_reenter(ctx, program, uniformBlockIndex, uniformBlockBinding);
		} END_MACH_OVERRIDE_PTR(uniform_block_binding, obj->disp.uniform_block_binding);

		if (err)
			log(LOG_ERR, "Failed to override uniform_block_binding: %i", err);

		MACH_OVERRIDE(void,get_combiner_input_parameterfv_NV,(GLIContext ctx, GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLfloat *params), err ) {
			file_log("get_combiner_input_parameterfv_NV called: ctx (GLIContext : %p) stage (GLenum : %s) portion (GLenum : %s) variable (GLenum : %s) pname (GLenum : %s) params (GLfloat* : %p)\n", ctx, GLenumToString(stage).c_str(), GLenumToString(portion).c_str(), GLenumToString(variable).c_str(), GLenumToString(pname).c_str(), params);
			return get_combiner_input_parameterfv_NV_reenter(ctx, stage, portion, variable, pname, params);
		} END_MACH_OVERRIDE_PTR(get_combiner_input_parameterfv_NV, obj->disp.get_combiner_input_parameterfv_NV);

		if (err)
			log(LOG_ERR, "Failed to override get_combiner_input_parameterfv_NV: %i", err);

		MACH_OVERRIDE(void,get_combiner_input_parameteriv_NV,(GLIContext ctx, GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLint *params), err ) {
			file_log("get_combiner_input_parameteriv_NV called: ctx (GLIContext : %p) stage (GLenum : %s) portion (GLenum : %s) variable (GLenum : %s) pname (GLenum : %s) params (GLint* : %p)\n", ctx, GLenumToString(stage).c_str(), GLenumToString(portion).c_str(), GLenumToString(variable).c_str(), GLenumToString(pname).c_str(), params);
			return get_combiner_input_parameteriv_NV_reenter(ctx, stage, portion, variable, pname, params);
		} END_MACH_OVERRIDE_PTR(get_combiner_input_parameteriv_NV, obj->disp.get_combiner_input_parameteriv_NV);

		if (err)
			log(LOG_ERR, "Failed to override get_combiner_input_parameteriv_NV: %i", err);

		MACH_OVERRIDE(void,get_combiner_output_parameterfv_NV,(GLIContext ctx, GLenum stage, GLenum portion, GLenum pname, GLfloat *params), err ) {
			file_log("get_combiner_output_parameterfv_NV called: ctx (GLIContext : %p) stage (GLenum : %s) portion (GLenum : %s) pname (GLenum : %s) params (GLfloat* : %p)\n", ctx, GLenumToString(stage).c_str(), GLenumToString(portion).c_str(), GLenumToString(pname).c_str(), params);
			return get_combiner_output_parameterfv_NV_reenter(ctx, stage, portion, pname, params);
		} END_MACH_OVERRIDE_PTR(get_combiner_output_parameterfv_NV, obj->disp.get_combiner_output_parameterfv_NV);

		if (err)
			log(LOG_ERR, "Failed to override get_combiner_output_parameterfv_NV: %i", err);

		MACH_OVERRIDE(void,get_combiner_output_parameteriv_NV,(GLIContext ctx, GLenum stage, GLenum portion, GLenum pname, GLint *params), err ) {
			file_log("get_combiner_output_parameteriv_NV called: ctx (GLIContext : %p) stage (GLenum : %s) portion (GLenum : %s) pname (GLenum : %s) params (GLint* : %p)\n", ctx, GLenumToString(stage).c_str(), GLenumToString(portion).c_str(), GLenumToString(pname).c_str(), params);
			return get_combiner_output_parameteriv_NV_reenter(ctx, stage, portion, pname, params);
		} END_MACH_OVERRIDE_PTR(get_combiner_output_parameteriv_NV, obj->disp.get_combiner_output_parameteriv_NV);

		if (err)
			log(LOG_ERR, "Failed to override get_combiner_output_parameteriv_NV: %i", err);

		MACH_OVERRIDE(void,get_final_combiner_input_parameterfv_NV,(GLIContext ctx, GLenum variable, GLenum pname, GLfloat *params), err ) {
			file_log("get_final_combiner_input_parameterfv_NV called: ctx (GLIContext : %p) variable (GLenum : %s) pname (GLenum : %s) params (GLfloat* : %p)\n", ctx, GLenumToString(variable).c_str(), GLenumToString(pname).c_str(), params);
			return get_final_combiner_input_parameterfv_NV_reenter(ctx, variable, pname, params);
		} END_MACH_OVERRIDE_PTR(get_final_combiner_input_parameterfv_NV, obj->disp.get_final_combiner_input_parameterfv_NV);

		if (err)
			log(LOG_ERR, "Failed to override get_final_combiner_input_parameterfv_NV: %i", err);

		MACH_OVERRIDE(void,get_final_combiner_input_parameteriv_NV,(GLIContext ctx, GLenum variable, GLenum pname, GLint *params), err ) {
			file_log("get_final_combiner_input_parameteriv_NV called: ctx (GLIContext : %p) variable (GLenum : %s) pname (GLenum : %s) params (GLint* : %p)\n", ctx, GLenumToString(variable).c_str(), GLenumToString(pname).c_str(), params);
			return get_final_combiner_input_parameteriv_NV_reenter(ctx, variable, pname, params);
		} END_MACH_OVERRIDE_PTR(get_final_combiner_input_parameteriv_NV, obj->disp.get_final_combiner_input_parameteriv_NV);

		if (err)
			log(LOG_ERR, "Failed to override get_final_combiner_input_parameteriv_NV: %i", err);

		MACH_OVERRIDE(void,combiner_stage_parameterfv_NV,(GLIContext ctx, GLenum stage, GLenum pname, const GLfloat *params), err ) {
			file_log("combiner_stage_parameterfv_NV called: ctx (GLIContext : %p) stage (GLenum : %s) pname (GLenum : %s) params (const GLfloat* : %p)\n", ctx, GLenumToString(stage).c_str(), GLenumToString(pname).c_str(), params);
			return combiner_stage_parameterfv_NV_reenter(ctx, stage, pname, params);
		} END_MACH_OVERRIDE_PTR(combiner_stage_parameterfv_NV, obj->disp.combiner_stage_parameterfv_NV);

		if (err)
			log(LOG_ERR, "Failed to override combiner_stage_parameterfv_NV: %i", err);

		MACH_OVERRIDE(void,get_combiner_stage_parameterfv_NV,(GLIContext ctx, GLenum stage, GLenum pname, GLfloat *params), err ) {
			file_log("get_combiner_stage_parameterfv_NV called: ctx (GLIContext : %p) stage (GLenum : %s) pname (GLenum : %s) params (GLfloat* : %p)\n", ctx, GLenumToString(stage).c_str(), GLenumToString(pname).c_str(), params);
			return get_combiner_stage_parameterfv_NV_reenter(ctx, stage, pname, params);
		} END_MACH_OVERRIDE_PTR(get_combiner_stage_parameterfv_NV, obj->disp.get_combiner_stage_parameterfv_NV);

		if (err)
			log(LOG_ERR, "Failed to override get_combiner_stage_parameterfv_NV: %i", err);

		MACH_OVERRIDE(void,texture_range_APPLE,(GLIContext ctx, GLenum target, GLsizei length, const GLvoid *pointer), err ) {
			file_log("texture_range_APPLE called: ctx (GLIContext : %p) target (GLenum : %s) length (GLsizei : %i) pointer (const GLvoid* : %p)\n", ctx, GLenumToString(target).c_str(), length, pointer);
			return texture_range_APPLE_reenter(ctx, target, length, pointer);
		} END_MACH_OVERRIDE_PTR(texture_range_APPLE, obj->disp.texture_range_APPLE);

		if (err)
			log(LOG_ERR, "Failed to override texture_range_APPLE: %i", err);

		MACH_OVERRIDE(void,get_tex_parameter_pointerv_APPLE,(GLIContext ctx, GLenum target, GLenum pname, GLvoid **params), err ) {
			file_log("get_tex_parameter_pointerv_APPLE called: ctx (GLIContext : %p) target (GLenum : %s) pname (GLenum : %s) params (GLvoid** : %p)\n", ctx, GLenumToString(target).c_str(), GLenumToString(pname).c_str(), params);
			return get_tex_parameter_pointerv_APPLE_reenter(ctx, target, pname, params);
		} END_MACH_OVERRIDE_PTR(get_tex_parameter_pointerv_APPLE, obj->disp.get_tex_parameter_pointerv_APPLE);

		if (err)
			log(LOG_ERR, "Failed to override get_tex_parameter_pointerv_APPLE: %i", err);

		MACH_OVERRIDE(void,blend_equation_separate_EXT,(GLIContext ctx, GLenum equationRGB, GLenum equationAlpha), err ) {
			file_log("blend_equation_separate_EXT called: ctx (GLIContext : %p) equationRGB (GLenum : %s) equationAlpha (GLenum : %s)\n", ctx, GLenumToString(equationRGB).c_str(), GLenumToString(equationAlpha).c_str());
			return blend_equation_separate_EXT_reenter(ctx, equationRGB, equationAlpha);
		} END_MACH_OVERRIDE_PTR(blend_equation_separate_EXT, obj->disp.blend_equation_separate_EXT);

		if (err)
			log(LOG_ERR, "Failed to override blend_equation_separate_EXT: %i", err);

		MACH_OVERRIDE(void,sample_coverage,(GLIContext ctx, GLclampf value, GLboolean invert), err ) {
			file_log("sample_coverage called: ctx (GLIContext : %p) value (GLclampf : %f) invert (GLboolean : %i)\n", ctx, value, invert);
			return sample_coverage_reenter(ctx, value, invert);
		} END_MACH_OVERRIDE_PTR(sample_coverage, obj->disp.sample_coverage);

		if (err)
			log(LOG_ERR, "Failed to override sample_coverage: %i", err);

		MACH_OVERRIDE(void,sample_pass,(GLIContext ctx, GLenum mode), err ) {
			file_log("sample_pass called: ctx (GLIContext : %p) mode (GLenum : %s)\n", ctx, GLenumToString(mode).c_str());
			return sample_pass_reenter(ctx, mode);
		} END_MACH_OVERRIDE_PTR(sample_pass, obj->disp.sample_pass);

		if (err)
			log(LOG_ERR, "Failed to override sample_pass: %i", err);

		MACH_OVERRIDE(void,pn_trianglesi_ATI,(GLIContext ctx, GLenum pname, GLint param), err ) {
			file_log("pn_trianglesi_ATI called: ctx (GLIContext : %p) pname (GLenum : %s) param (GLint : %i)\n", ctx, GLenumToString(pname).c_str(), param);
			return pn_trianglesi_ATI_reenter(ctx, pname, param);
		} END_MACH_OVERRIDE_PTR(pn_trianglesi_ATI, obj->disp.pn_trianglesi_ATI);

		if (err)
			log(LOG_ERR, "Failed to override pn_trianglesi_ATI: %i", err);

		MACH_OVERRIDE(void,pn_trianglesf_ATI,(GLIContext ctx, GLenum pname, GLfloat param), err ) {
			file_log("pn_trianglesf_ATI called: ctx (GLIContext : %p) pname (GLenum : %s) param (GLfloat : %f)\n", ctx, GLenumToString(pname).c_str(), param);
			return pn_trianglesf_ATI_reenter(ctx, pname, param);
		} END_MACH_OVERRIDE_PTR(pn_trianglesf_ATI, obj->disp.pn_trianglesf_ATI);

		if (err)
			log(LOG_ERR, "Failed to override pn_trianglesf_ATI: %i", err);

		MACH_OVERRIDE(void,gen_fences_APPLE,(GLIContext ctx, GLsizei n, GLuint *fences), err ) {
			file_log("gen_fences_APPLE called: ctx (GLIContext : %p) n (GLsizei : %i) fences (GLuint* : %p)\n", ctx, n, fences);
			return gen_fences_APPLE_reenter(ctx, n, fences);
		} END_MACH_OVERRIDE_PTR(gen_fences_APPLE, obj->disp.gen_fences_APPLE);

		if (err)
			log(LOG_ERR, "Failed to override gen_fences_APPLE: %i", err);

		MACH_OVERRIDE(void,delete_fences_APPLE,(GLIContext ctx, GLsizei n, const GLuint *fences), err ) {
			file_log("delete_fences_APPLE called: ctx (GLIContext : %p) n (GLsizei : %i) fences (const GLuint* : %p)\n", ctx, n, fences);
			return delete_fences_APPLE_reenter(ctx, n, fences);
		} END_MACH_OVERRIDE_PTR(delete_fences_APPLE, obj->disp.delete_fences_APPLE);

		if (err)
			log(LOG_ERR, "Failed to override delete_fences_APPLE: %i", err);

		MACH_OVERRIDE(void,set_fence_APPLE,(GLIContext ctx, GLuint fence), err ) {
			file_log("set_fence_APPLE called: ctx (GLIContext : %p) fence (GLuint : %u)\n", ctx, fence);
			return set_fence_APPLE_reenter(ctx, fence);
		} END_MACH_OVERRIDE_PTR(set_fence_APPLE, obj->disp.set_fence_APPLE);

		if (err)
			log(LOG_ERR, "Failed to override set_fence_APPLE: %i", err);

		MACH_OVERRIDE(GLboolean,is_fence_APPLE,(GLIContext ctx, GLuint fence), err ) {
			file_log("is_fence_APPLE called: ctx (GLIContext : %p) fence (GLuint : %u)\n", ctx, fence);
			GLboolean result = is_fence_APPLE_reenter(ctx, fence);
			return result;
		} END_MACH_OVERRIDE_PTR(is_fence_APPLE, obj->disp.is_fence_APPLE);

		if (err)
			log(LOG_ERR, "Failed to override is_fence_APPLE: %i", err);

		MACH_OVERRIDE(GLboolean,test_fence_APPLE,(GLIContext ctx, GLuint fence), err ) {
			file_log("test_fence_APPLE called: ctx (GLIContext : %p) fence (GLuint : %u)\n", ctx, fence);
			GLboolean result = test_fence_APPLE_reenter(ctx, fence);
			return result;
		} END_MACH_OVERRIDE_PTR(test_fence_APPLE, obj->disp.test_fence_APPLE);

		if (err)
			log(LOG_ERR, "Failed to override test_fence_APPLE: %i", err);

		MACH_OVERRIDE(void,finish_fence_APPLE,(GLIContext ctx, GLuint fence), err ) {
			file_log("finish_fence_APPLE called: ctx (GLIContext : %p) fence (GLuint : %u)\n", ctx, fence);
			return finish_fence_APPLE_reenter(ctx, fence);
		} END_MACH_OVERRIDE_PTR(finish_fence_APPLE, obj->disp.finish_fence_APPLE);

		if (err)
			log(LOG_ERR, "Failed to override finish_fence_APPLE: %i", err);

		MACH_OVERRIDE(GLboolean,test_object_APPLE,(GLIContext ctx, GLenum object, GLuint name), err ) {
			file_log("test_object_APPLE called: ctx (GLIContext : %p) object (GLenum : %s) name (GLuint : %u)\n", ctx, GLenumToString(object).c_str(), name);
			GLboolean result = test_object_APPLE_reenter(ctx, object, name);
			return result;
		} END_MACH_OVERRIDE_PTR(test_object_APPLE, obj->disp.test_object_APPLE);

		if (err)
			log(LOG_ERR, "Failed to override test_object_APPLE: %i", err);

		MACH_OVERRIDE(void,finish_object_APPLE,(GLIContext ctx, GLenum object, GLuint name), err ) {
			file_log("finish_object_APPLE called: ctx (GLIContext : %p) object (GLenum : %s) name (GLuint : %u)\n", ctx, GLenumToString(object).c_str(), name);
			return finish_object_APPLE_reenter(ctx, object, name);
		} END_MACH_OVERRIDE_PTR(finish_object_APPLE, obj->disp.finish_object_APPLE);

		if (err)
			log(LOG_ERR, "Failed to override finish_object_APPLE: %i", err);

		MACH_OVERRIDE(void,bind_program_ARB,(GLIContext ctx, GLenum target, GLuint program), err ) {
			file_log("bind_program_ARB called: ctx (GLIContext : %p) target (GLenum : %s) program (GLuint : %u)\n", ctx, GLenumToString(target).c_str(), program);
			OpenGL::StateMachine::Shared.bind_program_ARB(ctx, target, program);
			return bind_program_ARB_reenter(ctx, target, program);
		} END_MACH_OVERRIDE_PTR(bind_program_ARB, obj->disp.bind_program_ARB);

		if (err)
			log(LOG_ERR, "Failed to override bind_program_ARB: %i", err);

		MACH_OVERRIDE(void,delete_programs_ARB,(GLIContext ctx, GLsizei n, const GLuint *programs), err ) {
			file_log("delete_programs_ARB called: ctx (GLIContext : %p) n (GLsizei : %i) programs (const GLuint* : %p)\n", ctx, n, programs);
			return delete_programs_ARB_reenter(ctx, n, programs);
		} END_MACH_OVERRIDE_PTR(delete_programs_ARB, obj->disp.delete_programs_ARB);

		if (err)
			log(LOG_ERR, "Failed to override delete_programs_ARB: %i", err);

		MACH_OVERRIDE(void,gen_programs_ARB,(GLIContext ctx, GLsizei n, GLuint *programs), err ) {
			file_log("gen_programs_ARB called: ctx (GLIContext : %p) n (GLsizei : %i) programs (GLuint* : %p)\n", ctx, n, programs);
			return gen_programs_ARB_reenter(ctx, n, programs);
		} END_MACH_OVERRIDE_PTR(gen_programs_ARB, obj->disp.gen_programs_ARB);

		if (err)
			log(LOG_ERR, "Failed to override gen_programs_ARB: %i", err);

		MACH_OVERRIDE(GLboolean,is_program_ARB,(GLIContext ctx, GLuint program), err ) {
			file_log("is_program_ARB called: ctx (GLIContext : %p) program (GLuint : %u)\n", ctx, program);
			GLboolean result = is_program_ARB_reenter(ctx, program);
			return result;
		} END_MACH_OVERRIDE_PTR(is_program_ARB, obj->disp.is_program_ARB);

		if (err)
			log(LOG_ERR, "Failed to override is_program_ARB: %i", err);

		MACH_OVERRIDE(void,vertex_attrib1s_ARB,(GLIContext ctx, GLuint index, GLshort x), err ) {
			file_log("vertex_attrib1s_ARB called: ctx (GLIContext : %p) index (GLuint : %u) x (GLshort : %i)\n", ctx, index, x);
			return vertex_attrib1s_ARB_reenter(ctx, index, x);
		} END_MACH_OVERRIDE_PTR(vertex_attrib1s_ARB, obj->disp.vertex_attrib1s_ARB);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attrib1s_ARB: %i", err);

		MACH_OVERRIDE(void,vertex_attrib1f_ARB,(GLIContext ctx, GLuint index, GLfloat x), err ) {
			file_log("vertex_attrib1f_ARB called: ctx (GLIContext : %p) index (GLuint : %u) x (GLfloat : %f)\n", ctx, index, x);
			return vertex_attrib1f_ARB_reenter(ctx, index, x);
		} END_MACH_OVERRIDE_PTR(vertex_attrib1f_ARB, obj->disp.vertex_attrib1f_ARB);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attrib1f_ARB: %i", err);

		MACH_OVERRIDE(void,vertex_attrib1d_ARB,(GLIContext ctx, GLuint index, GLdouble x), err ) {
			file_log("vertex_attrib1d_ARB called: ctx (GLIContext : %p) index (GLuint : %u) x (GLdouble : %f)\n", ctx, index, x);
			return vertex_attrib1d_ARB_reenter(ctx, index, x);
		} END_MACH_OVERRIDE_PTR(vertex_attrib1d_ARB, obj->disp.vertex_attrib1d_ARB);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attrib1d_ARB: %i", err);

		MACH_OVERRIDE(void,vertex_attrib2s_ARB,(GLIContext ctx, GLuint index, GLshort x, GLshort y), err ) {
			file_log("vertex_attrib2s_ARB called: ctx (GLIContext : %p) index (GLuint : %u) x (GLshort : %i) y (GLshort : %i)\n", ctx, index, x, y);
			return vertex_attrib2s_ARB_reenter(ctx, index, x, y);
		} END_MACH_OVERRIDE_PTR(vertex_attrib2s_ARB, obj->disp.vertex_attrib2s_ARB);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attrib2s_ARB: %i", err);

		MACH_OVERRIDE(void,vertex_attrib2f_ARB,(GLIContext ctx, GLuint index, GLfloat x, GLfloat y), err ) {
			file_log("vertex_attrib2f_ARB called: ctx (GLIContext : %p) index (GLuint : %u) x (GLfloat : %f) y (GLfloat : %f)\n", ctx, index, x, y);
			return vertex_attrib2f_ARB_reenter(ctx, index, x, y);
		} END_MACH_OVERRIDE_PTR(vertex_attrib2f_ARB, obj->disp.vertex_attrib2f_ARB);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attrib2f_ARB: %i", err);

		MACH_OVERRIDE(void,vertex_attrib2d_ARB,(GLIContext ctx, GLuint index, GLdouble x, GLdouble y), err ) {
			file_log("vertex_attrib2d_ARB called: ctx (GLIContext : %p) index (GLuint : %u) x (GLdouble : %f) y (GLdouble : %f)\n", ctx, index, x, y);
			return vertex_attrib2d_ARB_reenter(ctx, index, x, y);
		} END_MACH_OVERRIDE_PTR(vertex_attrib2d_ARB, obj->disp.vertex_attrib2d_ARB);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attrib2d_ARB: %i", err);

		MACH_OVERRIDE(void,vertex_attrib3s_ARB,(GLIContext ctx, GLuint index, GLshort x, GLshort y, GLshort z), err ) {
			file_log("vertex_attrib3s_ARB called: ctx (GLIContext : %p) index (GLuint : %u) x (GLshort : %i) y (GLshort : %i) z (GLshort : %i)\n", ctx, index, x, y, z);
			return vertex_attrib3s_ARB_reenter(ctx, index, x, y, z);
		} END_MACH_OVERRIDE_PTR(vertex_attrib3s_ARB, obj->disp.vertex_attrib3s_ARB);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attrib3s_ARB: %i", err);

		MACH_OVERRIDE(void,vertex_attrib3f_ARB,(GLIContext ctx, GLuint index, GLfloat x, GLfloat y, GLfloat z), err ) {
			file_log("vertex_attrib3f_ARB called: ctx (GLIContext : %p) index (GLuint : %u) x (GLfloat : %f) y (GLfloat : %f) z (GLfloat : %f)\n", ctx, index, x, y, z);
			return vertex_attrib3f_ARB_reenter(ctx, index, x, y, z);
		} END_MACH_OVERRIDE_PTR(vertex_attrib3f_ARB, obj->disp.vertex_attrib3f_ARB);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attrib3f_ARB: %i", err);

		MACH_OVERRIDE(void,vertex_attrib3d_ARB,(GLIContext ctx, GLuint index, GLdouble x, GLdouble y, GLdouble z), err ) {
			file_log("vertex_attrib3d_ARB called: ctx (GLIContext : %p) index (GLuint : %u) x (GLdouble : %f) y (GLdouble : %f) z (GLdouble : %f)\n", ctx, index, x, y, z);
			return vertex_attrib3d_ARB_reenter(ctx, index, x, y, z);
		} END_MACH_OVERRIDE_PTR(vertex_attrib3d_ARB, obj->disp.vertex_attrib3d_ARB);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attrib3d_ARB: %i", err);

		MACH_OVERRIDE(void,vertex_attrib4s_ARB,(GLIContext ctx, GLuint index, GLshort x, GLshort y, GLshort z, GLshort w), err ) {
			file_log("vertex_attrib4s_ARB called: ctx (GLIContext : %p) index (GLuint : %u) x (GLshort : %i) y (GLshort : %i) z (GLshort : %i) w (GLshort : %i)\n", ctx, index, x, y, z, w);
			return vertex_attrib4s_ARB_reenter(ctx, index, x, y, z, w);
		} END_MACH_OVERRIDE_PTR(vertex_attrib4s_ARB, obj->disp.vertex_attrib4s_ARB);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attrib4s_ARB: %i", err);

		MACH_OVERRIDE(void,vertex_attrib4f_ARB,(GLIContext ctx, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w), err ) {
			file_log("vertex_attrib4f_ARB called: ctx (GLIContext : %p) index (GLuint : %u) x (GLfloat : %f) y (GLfloat : %f) z (GLfloat : %f) w (GLfloat : %f)\n", ctx, index, x, y, z, w);
			return vertex_attrib4f_ARB_reenter(ctx, index, x, y, z, w);
		} END_MACH_OVERRIDE_PTR(vertex_attrib4f_ARB, obj->disp.vertex_attrib4f_ARB);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attrib4f_ARB: %i", err);

		MACH_OVERRIDE(void,vertex_attrib4d_ARB,(GLIContext ctx, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w), err ) {
			file_log("vertex_attrib4d_ARB called: ctx (GLIContext : %p) index (GLuint : %u) x (GLdouble : %f) y (GLdouble : %f) z (GLdouble : %f) w (GLdouble : %f)\n", ctx, index, x, y, z, w);
			return vertex_attrib4d_ARB_reenter(ctx, index, x, y, z, w);
		} END_MACH_OVERRIDE_PTR(vertex_attrib4d_ARB, obj->disp.vertex_attrib4d_ARB);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attrib4d_ARB: %i", err);

		MACH_OVERRIDE(void,vertex_attrib4Nub_ARB,(GLIContext ctx, GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w), err ) {
			file_log("vertex_attrib4Nub_ARB called: ctx (GLIContext : %p) index (GLuint : %u) x (GLubyte : %u) y (GLubyte : %u) z (GLubyte : %u) w (GLubyte : %u)\n", ctx, index, x, y, z, w);
			return vertex_attrib4Nub_ARB_reenter(ctx, index, x, y, z, w);
		} END_MACH_OVERRIDE_PTR(vertex_attrib4Nub_ARB, obj->disp.vertex_attrib4Nub_ARB);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attrib4Nub_ARB: %i", err);

		MACH_OVERRIDE(void,vertex_attrib1sv_ARB,(GLIContext ctx, GLuint index, const GLshort *v), err ) {
			file_log("vertex_attrib1sv_ARB called: ctx (GLIContext : %p) index (GLuint : %u) v (const GLshort* : %p)\n", ctx, index, v);
			return vertex_attrib1sv_ARB_reenter(ctx, index, v);
		} END_MACH_OVERRIDE_PTR(vertex_attrib1sv_ARB, obj->disp.vertex_attrib1sv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attrib1sv_ARB: %i", err);

		MACH_OVERRIDE(void,vertex_attrib1fv_ARB,(GLIContext ctx, GLuint index, const GLfloat *v), err ) {
			file_log("vertex_attrib1fv_ARB called: ctx (GLIContext : %p) index (GLuint : %u) v (const GLfloat* : %p)\n", ctx, index, v);
			return vertex_attrib1fv_ARB_reenter(ctx, index, v);
		} END_MACH_OVERRIDE_PTR(vertex_attrib1fv_ARB, obj->disp.vertex_attrib1fv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attrib1fv_ARB: %i", err);

		MACH_OVERRIDE(void,vertex_attrib1dv_ARB,(GLIContext ctx, GLuint index, const GLdouble *v), err ) {
			file_log("vertex_attrib1dv_ARB called: ctx (GLIContext : %p) index (GLuint : %u) v (const GLdouble* : %p)\n", ctx, index, v);
			return vertex_attrib1dv_ARB_reenter(ctx, index, v);
		} END_MACH_OVERRIDE_PTR(vertex_attrib1dv_ARB, obj->disp.vertex_attrib1dv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attrib1dv_ARB: %i", err);

		MACH_OVERRIDE(void,vertex_attrib2sv_ARB,(GLIContext ctx, GLuint index, const GLshort *v), err ) {
			file_log("vertex_attrib2sv_ARB called: ctx (GLIContext : %p) index (GLuint : %u) v (const GLshort* : %p)\n", ctx, index, v);
			return vertex_attrib2sv_ARB_reenter(ctx, index, v);
		} END_MACH_OVERRIDE_PTR(vertex_attrib2sv_ARB, obj->disp.vertex_attrib2sv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attrib2sv_ARB: %i", err);

		MACH_OVERRIDE(void,vertex_attrib2fv_ARB,(GLIContext ctx, GLuint index, const GLfloat *v), err ) {
			file_log("vertex_attrib2fv_ARB called: ctx (GLIContext : %p) index (GLuint : %u) v (const GLfloat* : %p)\n", ctx, index, v);
			return vertex_attrib2fv_ARB_reenter(ctx, index, v);
		} END_MACH_OVERRIDE_PTR(vertex_attrib2fv_ARB, obj->disp.vertex_attrib2fv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attrib2fv_ARB: %i", err);

		MACH_OVERRIDE(void,vertex_attrib2dv_ARB,(GLIContext ctx, GLuint index, const GLdouble *v), err ) {
			file_log("vertex_attrib2dv_ARB called: ctx (GLIContext : %p) index (GLuint : %u) v (const GLdouble* : %p)\n", ctx, index, v);
			return vertex_attrib2dv_ARB_reenter(ctx, index, v);
		} END_MACH_OVERRIDE_PTR(vertex_attrib2dv_ARB, obj->disp.vertex_attrib2dv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attrib2dv_ARB: %i", err);

		MACH_OVERRIDE(void,vertex_attrib3sv_ARB,(GLIContext ctx, GLuint index, const GLshort *v), err ) {
			file_log("vertex_attrib3sv_ARB called: ctx (GLIContext : %p) index (GLuint : %u) v (const GLshort* : %p)\n", ctx, index, v);
			return vertex_attrib3sv_ARB_reenter(ctx, index, v);
		} END_MACH_OVERRIDE_PTR(vertex_attrib3sv_ARB, obj->disp.vertex_attrib3sv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attrib3sv_ARB: %i", err);

		MACH_OVERRIDE(void,vertex_attrib3fv_ARB,(GLIContext ctx, GLuint index, const GLfloat *v), err ) {
			file_log("vertex_attrib3fv_ARB called: ctx (GLIContext : %p) index (GLuint : %u) v (const GLfloat* : %p)\n", ctx, index, v);
			return vertex_attrib3fv_ARB_reenter(ctx, index, v);
		} END_MACH_OVERRIDE_PTR(vertex_attrib3fv_ARB, obj->disp.vertex_attrib3fv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attrib3fv_ARB: %i", err);

		MACH_OVERRIDE(void,vertex_attrib3dv_ARB,(GLIContext ctx, GLuint index, const GLdouble *v), err ) {
			file_log("vertex_attrib3dv_ARB called: ctx (GLIContext : %p) index (GLuint : %u) v (const GLdouble* : %p)\n", ctx, index, v);
			return vertex_attrib3dv_ARB_reenter(ctx, index, v);
		} END_MACH_OVERRIDE_PTR(vertex_attrib3dv_ARB, obj->disp.vertex_attrib3dv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attrib3dv_ARB: %i", err);

		MACH_OVERRIDE(void,vertex_attrib4bv_ARB,(GLIContext ctx, GLuint index, const GLbyte *v), err ) {
			file_log("vertex_attrib4bv_ARB called: ctx (GLIContext : %p) index (GLuint : %u) v (const GLbyte* : %p)\n", ctx, index, v);
			return vertex_attrib4bv_ARB_reenter(ctx, index, v);
		} END_MACH_OVERRIDE_PTR(vertex_attrib4bv_ARB, obj->disp.vertex_attrib4bv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attrib4bv_ARB: %i", err);

		MACH_OVERRIDE(void,vertex_attrib4sv_ARB,(GLIContext ctx, GLuint index, const GLshort *v), err ) {
			file_log("vertex_attrib4sv_ARB called: ctx (GLIContext : %p) index (GLuint : %u) v (const GLshort* : %p)\n", ctx, index, v);
			return vertex_attrib4sv_ARB_reenter(ctx, index, v);
		} END_MACH_OVERRIDE_PTR(vertex_attrib4sv_ARB, obj->disp.vertex_attrib4sv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attrib4sv_ARB: %i", err);

		MACH_OVERRIDE(void,vertex_attrib4iv_ARB,(GLIContext ctx, GLuint index, const GLint *v), err ) {
			file_log("vertex_attrib4iv_ARB called: ctx (GLIContext : %p) index (GLuint : %u) v (const GLint* : %p)\n", ctx, index, v);
			return vertex_attrib4iv_ARB_reenter(ctx, index, v);
		} END_MACH_OVERRIDE_PTR(vertex_attrib4iv_ARB, obj->disp.vertex_attrib4iv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attrib4iv_ARB: %i", err);

		MACH_OVERRIDE(void,vertex_attrib4ubv_ARB,(GLIContext ctx, GLuint index, const GLubyte *v), err ) {
			file_log("vertex_attrib4ubv_ARB called: ctx (GLIContext : %p) index (GLuint : %u) v (const GLubyte* : %p)\n", ctx, index, v);
			return vertex_attrib4ubv_ARB_reenter(ctx, index, v);
		} END_MACH_OVERRIDE_PTR(vertex_attrib4ubv_ARB, obj->disp.vertex_attrib4ubv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attrib4ubv_ARB: %i", err);

		MACH_OVERRIDE(void,vertex_attrib4usv_ARB,(GLIContext ctx, GLuint index, const GLushort *v), err ) {
			file_log("vertex_attrib4usv_ARB called: ctx (GLIContext : %p) index (GLuint : %u) v (const GLushort* : %p)\n", ctx, index, v);
			return vertex_attrib4usv_ARB_reenter(ctx, index, v);
		} END_MACH_OVERRIDE_PTR(vertex_attrib4usv_ARB, obj->disp.vertex_attrib4usv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attrib4usv_ARB: %i", err);

		MACH_OVERRIDE(void,vertex_attrib4uiv_ARB,(GLIContext ctx, GLuint index, const GLuint *v), err ) {
			file_log("vertex_attrib4uiv_ARB called: ctx (GLIContext : %p) index (GLuint : %u) v (const GLuint* : %p)\n", ctx, index, v);
			return vertex_attrib4uiv_ARB_reenter(ctx, index, v);
		} END_MACH_OVERRIDE_PTR(vertex_attrib4uiv_ARB, obj->disp.vertex_attrib4uiv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attrib4uiv_ARB: %i", err);

		MACH_OVERRIDE(void,vertex_attrib4fv_ARB,(GLIContext ctx, GLuint index, const GLfloat *v), err ) {
			file_log("vertex_attrib4fv_ARB called: ctx (GLIContext : %p) index (GLuint : %u) v (const GLfloat* : %p)\n", ctx, index, v);
			return vertex_attrib4fv_ARB_reenter(ctx, index, v);
		} END_MACH_OVERRIDE_PTR(vertex_attrib4fv_ARB, obj->disp.vertex_attrib4fv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attrib4fv_ARB: %i", err);

		MACH_OVERRIDE(void,vertex_attrib4dv_ARB,(GLIContext ctx, GLuint index, const GLdouble *v), err ) {
			file_log("vertex_attrib4dv_ARB called: ctx (GLIContext : %p) index (GLuint : %u) v (const GLdouble* : %p)\n", ctx, index, v);
			return vertex_attrib4dv_ARB_reenter(ctx, index, v);
		} END_MACH_OVERRIDE_PTR(vertex_attrib4dv_ARB, obj->disp.vertex_attrib4dv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attrib4dv_ARB: %i", err);

		MACH_OVERRIDE(void,vertex_attrib4Nbv_ARB,(GLIContext ctx, GLuint index, const GLbyte *v), err ) {
			file_log("vertex_attrib4Nbv_ARB called: ctx (GLIContext : %p) index (GLuint : %u) v (const GLbyte* : %p)\n", ctx, index, v);
			return vertex_attrib4Nbv_ARB_reenter(ctx, index, v);
		} END_MACH_OVERRIDE_PTR(vertex_attrib4Nbv_ARB, obj->disp.vertex_attrib4Nbv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attrib4Nbv_ARB: %i", err);

		MACH_OVERRIDE(void,vertex_attrib4Nsv_ARB,(GLIContext ctx, GLuint index, const GLshort *v), err ) {
			file_log("vertex_attrib4Nsv_ARB called: ctx (GLIContext : %p) index (GLuint : %u) v (const GLshort* : %p)\n", ctx, index, v);
			return vertex_attrib4Nsv_ARB_reenter(ctx, index, v);
		} END_MACH_OVERRIDE_PTR(vertex_attrib4Nsv_ARB, obj->disp.vertex_attrib4Nsv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attrib4Nsv_ARB: %i", err);

		MACH_OVERRIDE(void,vertex_attrib4Niv_ARB,(GLIContext ctx, GLuint index, const GLint *v), err ) {
			file_log("vertex_attrib4Niv_ARB called: ctx (GLIContext : %p) index (GLuint : %u) v (const GLint* : %p)\n", ctx, index, v);
			return vertex_attrib4Niv_ARB_reenter(ctx, index, v);
		} END_MACH_OVERRIDE_PTR(vertex_attrib4Niv_ARB, obj->disp.vertex_attrib4Niv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attrib4Niv_ARB: %i", err);

		MACH_OVERRIDE(void,vertex_attrib4Nubv_ARB,(GLIContext ctx, GLuint index, const GLubyte *v), err ) {
			file_log("vertex_attrib4Nubv_ARB called: ctx (GLIContext : %p) index (GLuint : %u) v (const GLubyte* : %p)\n", ctx, index, v);
			return vertex_attrib4Nubv_ARB_reenter(ctx, index, v);
		} END_MACH_OVERRIDE_PTR(vertex_attrib4Nubv_ARB, obj->disp.vertex_attrib4Nubv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attrib4Nubv_ARB: %i", err);

		MACH_OVERRIDE(void,vertex_attrib4Nusv_ARB,(GLIContext ctx, GLuint index, const GLushort *v), err ) {
			file_log("vertex_attrib4Nusv_ARB called: ctx (GLIContext : %p) index (GLuint : %u) v (const GLushort* : %p)\n", ctx, index, v);
			return vertex_attrib4Nusv_ARB_reenter(ctx, index, v);
		} END_MACH_OVERRIDE_PTR(vertex_attrib4Nusv_ARB, obj->disp.vertex_attrib4Nusv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attrib4Nusv_ARB: %i", err);

		MACH_OVERRIDE(void,vertex_attrib4Nuiv_ARB,(GLIContext ctx, GLuint index, const GLuint *v), err ) {
			file_log("vertex_attrib4Nuiv_ARB called: ctx (GLIContext : %p) index (GLuint : %u) v (const GLuint* : %p)\n", ctx, index, v);
			return vertex_attrib4Nuiv_ARB_reenter(ctx, index, v);
		} END_MACH_OVERRIDE_PTR(vertex_attrib4Nuiv_ARB, obj->disp.vertex_attrib4Nuiv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attrib4Nuiv_ARB: %i", err);

		MACH_OVERRIDE(void,vertex_attrib_pointer_ARB,(GLIContext ctx, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid *pointer), err ) {
			file_log("vertex_attrib_pointer_ARB called: ctx (GLIContext : %p) index (GLuint : %u) size (GLint : %i) type (GLenum : %s) normalized (GLboolean : %i) stride (GLsizei : %i) pointer (const GLvoid* : %p)\n", ctx, index, size, GLenumToString(type).c_str(), normalized, stride, pointer);
			return vertex_attrib_pointer_ARB_reenter(ctx, index, size, type, normalized, stride, pointer);
		} END_MACH_OVERRIDE_PTR(vertex_attrib_pointer_ARB, obj->disp.vertex_attrib_pointer_ARB);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attrib_pointer_ARB: %i", err);

		MACH_OVERRIDE(void,enable_vertex_attrib_array_ARB,(GLIContext ctx, GLuint index), err ) {
			file_log("enable_vertex_attrib_array_ARB called: ctx (GLIContext : %p) index (GLuint : %u)\n", ctx, index);
			return enable_vertex_attrib_array_ARB_reenter(ctx, index);
		} END_MACH_OVERRIDE_PTR(enable_vertex_attrib_array_ARB, obj->disp.enable_vertex_attrib_array_ARB);

		if (err)
			log(LOG_ERR, "Failed to override enable_vertex_attrib_array_ARB: %i", err);

		MACH_OVERRIDE(void,disable_vertex_attrib_array_ARB,(GLIContext ctx, GLuint index), err ) {
			file_log("disable_vertex_attrib_array_ARB called: ctx (GLIContext : %p) index (GLuint : %u)\n", ctx, index);
			return disable_vertex_attrib_array_ARB_reenter(ctx, index);
		} END_MACH_OVERRIDE_PTR(disable_vertex_attrib_array_ARB, obj->disp.disable_vertex_attrib_array_ARB);

		if (err)
			log(LOG_ERR, "Failed to override disable_vertex_attrib_array_ARB: %i", err);

		MACH_OVERRIDE(void,get_vertex_attribdv_ARB,(GLIContext ctx, GLuint index, GLenum pname, GLdouble *params), err ) {
			file_log("get_vertex_attribdv_ARB called: ctx (GLIContext : %p) index (GLuint : %u) pname (GLenum : %s) params (GLdouble* : %p)\n", ctx, index, GLenumToString(pname).c_str(), params);
			return get_vertex_attribdv_ARB_reenter(ctx, index, pname, params);
		} END_MACH_OVERRIDE_PTR(get_vertex_attribdv_ARB, obj->disp.get_vertex_attribdv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override get_vertex_attribdv_ARB: %i", err);

		MACH_OVERRIDE(void,get_vertex_attribfv_ARB,(GLIContext ctx, GLuint index, GLenum pname, GLfloat *params), err ) {
			file_log("get_vertex_attribfv_ARB called: ctx (GLIContext : %p) index (GLuint : %u) pname (GLenum : %s) params (GLfloat* : %p)\n", ctx, index, GLenumToString(pname).c_str(), params);
			return get_vertex_attribfv_ARB_reenter(ctx, index, pname, params);
		} END_MACH_OVERRIDE_PTR(get_vertex_attribfv_ARB, obj->disp.get_vertex_attribfv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override get_vertex_attribfv_ARB: %i", err);

		MACH_OVERRIDE(void,get_vertex_attribiv_ARB,(GLIContext ctx, GLuint index, GLenum pname, GLint *params), err ) {
			file_log("get_vertex_attribiv_ARB called: ctx (GLIContext : %p) index (GLuint : %u) pname (GLenum : %s) params (GLint* : %p)\n", ctx, index, GLenumToString(pname).c_str(), params);
			return get_vertex_attribiv_ARB_reenter(ctx, index, pname, params);
		} END_MACH_OVERRIDE_PTR(get_vertex_attribiv_ARB, obj->disp.get_vertex_attribiv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override get_vertex_attribiv_ARB: %i", err);

		MACH_OVERRIDE(void,get_vertex_attrib_pointerv_ARB,(GLIContext ctx, GLuint index, GLenum pname, GLvoid **pointer), err ) {
			file_log("get_vertex_attrib_pointerv_ARB called: ctx (GLIContext : %p) index (GLuint : %u) pname (GLenum : %s) pointer (GLvoid** : %p)\n", ctx, index, GLenumToString(pname).c_str(), pointer);
			return get_vertex_attrib_pointerv_ARB_reenter(ctx, index, pname, pointer);
		} END_MACH_OVERRIDE_PTR(get_vertex_attrib_pointerv_ARB, obj->disp.get_vertex_attrib_pointerv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override get_vertex_attrib_pointerv_ARB: %i", err);

		MACH_OVERRIDE(void,program_env_parameter4d_ARB,(GLIContext ctx, GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w), err ) {
			file_log("program_env_parameter4d_ARB called: ctx (GLIContext : %p) target (GLenum : %s) index (GLuint : %u) x (GLdouble : %f) y (GLdouble : %f) z (GLdouble : %f) w (GLdouble : %f)\n", ctx, GLenumToString(target).c_str(), index, x, y, z, w);
			return program_env_parameter4d_ARB_reenter(ctx, target, index, x, y, z, w);
		} END_MACH_OVERRIDE_PTR(program_env_parameter4d_ARB, obj->disp.program_env_parameter4d_ARB);

		if (err)
			log(LOG_ERR, "Failed to override program_env_parameter4d_ARB: %i", err);

		MACH_OVERRIDE(void,program_env_parameter4dv_ARB,(GLIContext ctx, GLenum target, GLuint index, const GLdouble *params), err ) {
			file_log("program_env_parameter4dv_ARB called: ctx (GLIContext : %p) target (GLenum : %s) index (GLuint : %u) params (const GLdouble* : %p)\n", ctx, GLenumToString(target).c_str(), index, params);
			return program_env_parameter4dv_ARB_reenter(ctx, target, index, params);
		} END_MACH_OVERRIDE_PTR(program_env_parameter4dv_ARB, obj->disp.program_env_parameter4dv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override program_env_parameter4dv_ARB: %i", err);

		MACH_OVERRIDE(void,program_env_parameter4f_ARB,(GLIContext ctx, GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w), err ) {
			file_log("program_env_parameter4f_ARB called: ctx (GLIContext : %p) target (GLenum : %s) index (GLuint : %u) x (GLfloat : %f) y (GLfloat : %f) z (GLfloat : %f) w (GLfloat : %f)\n", ctx, GLenumToString(target).c_str(), index, x, y, z, w);
			return program_env_parameter4f_ARB_reenter(ctx, target, index, x, y, z, w);
		} END_MACH_OVERRIDE_PTR(program_env_parameter4f_ARB, obj->disp.program_env_parameter4f_ARB);

		if (err)
			log(LOG_ERR, "Failed to override program_env_parameter4f_ARB: %i", err);

		MACH_OVERRIDE(void,program_env_parameter4fv_ARB,(GLIContext ctx, GLenum target, GLuint index, const GLfloat *params), err ) {
			file_log("program_env_parameter4fv_ARB called: ctx (GLIContext : %p) target (GLenum : %s) index (GLuint : %u) params (const GLfloat* : %p)\n", ctx, GLenumToString(target).c_str(), index, params);
			return program_env_parameter4fv_ARB_reenter(ctx, target, index, params);
		} END_MACH_OVERRIDE_PTR(program_env_parameter4fv_ARB, obj->disp.program_env_parameter4fv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override program_env_parameter4fv_ARB: %i", err);

		MACH_OVERRIDE(void,program_local_parameter4d_ARB,(GLIContext ctx, GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w), err ) {
			file_log("program_local_parameter4d_ARB called: ctx (GLIContext : %p) target (GLenum : %s) index (GLuint : %u) x (GLdouble : %f) y (GLdouble : %f) z (GLdouble : %f) w (GLdouble : %f)\n", ctx, GLenumToString(target).c_str(), index, x, y, z, w);
			return program_local_parameter4d_ARB_reenter(ctx, target, index, x, y, z, w);
		} END_MACH_OVERRIDE_PTR(program_local_parameter4d_ARB, obj->disp.program_local_parameter4d_ARB);

		if (err)
			log(LOG_ERR, "Failed to override program_local_parameter4d_ARB: %i", err);

		MACH_OVERRIDE(void,program_local_parameter4dv_ARB,(GLIContext ctx, GLenum target, GLuint index, const GLdouble *params), err ) {
			file_log("program_local_parameter4dv_ARB called: ctx (GLIContext : %p) target (GLenum : %s) index (GLuint : %u) params (const GLdouble* : %p)\n", ctx, GLenumToString(target).c_str(), index, params);
			return program_local_parameter4dv_ARB_reenter(ctx, target, index, params);
		} END_MACH_OVERRIDE_PTR(program_local_parameter4dv_ARB, obj->disp.program_local_parameter4dv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override program_local_parameter4dv_ARB: %i", err);

		MACH_OVERRIDE(void,program_local_parameter4f_ARB,(GLIContext ctx, GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w), err ) {
			file_log("program_local_parameter4f_ARB called: ctx (GLIContext : %p) target (GLenum : %s) index (GLuint : %u) x (GLfloat : %f) y (GLfloat : %f) z (GLfloat : %f) w (GLfloat : %f)\n", ctx, GLenumToString(target).c_str(), index, x, y, z, w);
			return program_local_parameter4f_ARB_reenter(ctx, target, index, x, y, z, w);
		} END_MACH_OVERRIDE_PTR(program_local_parameter4f_ARB, obj->disp.program_local_parameter4f_ARB);

		if (err)
			log(LOG_ERR, "Failed to override program_local_parameter4f_ARB: %i", err);

		MACH_OVERRIDE(void,program_local_parameter4fv_ARB,(GLIContext ctx, GLenum target, GLuint index, const GLfloat *params), err ) {
			file_log("program_local_parameter4fv_ARB called: ctx (GLIContext : %p) target (GLenum : %s) index (GLuint : %u) params (const GLfloat* : %p)\n", ctx, GLenumToString(target).c_str(), index, params);
			return program_local_parameter4fv_ARB_reenter(ctx, target, index, params);
		} END_MACH_OVERRIDE_PTR(program_local_parameter4fv_ARB, obj->disp.program_local_parameter4fv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override program_local_parameter4fv_ARB: %i", err);

		MACH_OVERRIDE(void,get_program_env_parameterdv_ARB,(GLIContext ctx, GLenum target, GLuint index, GLdouble *params), err ) {
			file_log("get_program_env_parameterdv_ARB called: ctx (GLIContext : %p) target (GLenum : %s) index (GLuint : %u) params (GLdouble* : %p)\n", ctx, GLenumToString(target).c_str(), index, params);
			return get_program_env_parameterdv_ARB_reenter(ctx, target, index, params);
		} END_MACH_OVERRIDE_PTR(get_program_env_parameterdv_ARB, obj->disp.get_program_env_parameterdv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override get_program_env_parameterdv_ARB: %i", err);

		MACH_OVERRIDE(void,get_program_env_parameterfv_ARB,(GLIContext ctx, GLenum target, GLuint index, GLfloat *params), err ) {
			file_log("get_program_env_parameterfv_ARB called: ctx (GLIContext : %p) target (GLenum : %s) index (GLuint : %u) params (GLfloat* : %p)\n", ctx, GLenumToString(target).c_str(), index, params);
			return get_program_env_parameterfv_ARB_reenter(ctx, target, index, params);
		} END_MACH_OVERRIDE_PTR(get_program_env_parameterfv_ARB, obj->disp.get_program_env_parameterfv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override get_program_env_parameterfv_ARB: %i", err);

		MACH_OVERRIDE(void,get_program_local_parameterdv_ARB,(GLIContext ctx, GLenum target, GLuint index, GLdouble *params), err ) {
			file_log("get_program_local_parameterdv_ARB called: ctx (GLIContext : %p) target (GLenum : %s) index (GLuint : %u) params (GLdouble* : %p)\n", ctx, GLenumToString(target).c_str(), index, params);
			return get_program_local_parameterdv_ARB_reenter(ctx, target, index, params);
		} END_MACH_OVERRIDE_PTR(get_program_local_parameterdv_ARB, obj->disp.get_program_local_parameterdv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override get_program_local_parameterdv_ARB: %i", err);

		MACH_OVERRIDE(void,get_program_local_parameterfv_ARB,(GLIContext ctx, GLenum target, GLuint index, GLfloat *params), err ) {
			file_log("get_program_local_parameterfv_ARB called: ctx (GLIContext : %p) target (GLenum : %s) index (GLuint : %u) params (GLfloat* : %p)\n", ctx, GLenumToString(target).c_str(), index, params);
			return get_program_local_parameterfv_ARB_reenter(ctx, target, index, params);
		} END_MACH_OVERRIDE_PTR(get_program_local_parameterfv_ARB, obj->disp.get_program_local_parameterfv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override get_program_local_parameterfv_ARB: %i", err);

		MACH_OVERRIDE(void,program_string_ARB,(GLIContext ctx, GLenum target, GLenum format, GLsizei len, const GLvoid* string), err ) {
			file_log("program_string_ARB called: ctx (GLIContext : %p) target (GLenum : %s) format (GLenum : %s) len (GLsizei : %i) string (const GLvoid* : %p)\n", ctx, GLenumToString(target).c_str(), GLenumToString(format).c_str(), len, string);
			return program_string_ARB_reenter(ctx, target, format, len, string);
		} END_MACH_OVERRIDE_PTR(program_string_ARB, obj->disp.program_string_ARB);

		if (err)
			log(LOG_ERR, "Failed to override program_string_ARB: %i", err);

		MACH_OVERRIDE(void,get_program_string_ARB,(GLIContext ctx, GLenum target, GLenum pname, GLvoid *string), err ) {
			file_log("get_program_string_ARB called: ctx (GLIContext : %p) target (GLenum : %s) pname (GLenum : %s) string (GLvoid* : %p)\n", ctx, GLenumToString(target).c_str(), GLenumToString(pname).c_str(), string);
			return get_program_string_ARB_reenter(ctx, target, pname, string);
		} END_MACH_OVERRIDE_PTR(get_program_string_ARB, obj->disp.get_program_string_ARB);

		if (err)
			log(LOG_ERR, "Failed to override get_program_string_ARB: %i", err);

		MACH_OVERRIDE(void,get_programiv_ARB,(GLIContext ctx, GLenum target, GLenum pname, GLint *params), err ) {
			file_log("get_programiv_ARB called: ctx (GLIContext : %p) target (GLenum : %s) pname (GLenum : %s) params (GLint* : %p)\n", ctx, GLenumToString(target).c_str(), GLenumToString(pname).c_str(), params);
			return get_programiv_ARB_reenter(ctx, target, pname, params);
		} END_MACH_OVERRIDE_PTR(get_programiv_ARB, obj->disp.get_programiv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override get_programiv_ARB: %i", err);

		MACH_OVERRIDE(void,enable_vertex_attrib_ARB,(GLIContext ctx, GLuint index, GLenum pname), err ) {
			file_log("enable_vertex_attrib_ARB called: ctx (GLIContext : %p) index (GLuint : %u) pname (GLenum : %s)\n", ctx, index, GLenumToString(pname).c_str());
			return enable_vertex_attrib_ARB_reenter(ctx, index, pname);
		} END_MACH_OVERRIDE_PTR(enable_vertex_attrib_ARB, obj->disp.enable_vertex_attrib_ARB);

		if (err)
			log(LOG_ERR, "Failed to override enable_vertex_attrib_ARB: %i", err);

		MACH_OVERRIDE(void,disable_vertex_attrib_ARB,(GLIContext ctx, GLuint index, GLenum pname), err ) {
			file_log("disable_vertex_attrib_ARB called: ctx (GLIContext : %p) index (GLuint : %u) pname (GLenum : %s)\n", ctx, index, GLenumToString(pname).c_str());
			return disable_vertex_attrib_ARB_reenter(ctx, index, pname);
		} END_MACH_OVERRIDE_PTR(disable_vertex_attrib_ARB, obj->disp.disable_vertex_attrib_ARB);

		if (err)
			log(LOG_ERR, "Failed to override disable_vertex_attrib_ARB: %i", err);

		MACH_OVERRIDE(GLboolean,is_vertex_attrib_enabled_ARB,(GLIContext ctx, GLuint index, GLenum pname), err ) {
			file_log("is_vertex_attrib_enabled_ARB called: ctx (GLIContext : %p) index (GLuint : %u) pname (GLenum : %s)\n", ctx, index, GLenumToString(pname).c_str());
			GLboolean result = is_vertex_attrib_enabled_ARB_reenter(ctx, index, pname);
			return result;
		} END_MACH_OVERRIDE_PTR(is_vertex_attrib_enabled_ARB, obj->disp.is_vertex_attrib_enabled_ARB);

		if (err)
			log(LOG_ERR, "Failed to override is_vertex_attrib_enabled_ARB: %i", err);

		MACH_OVERRIDE(void,map_vertex_attrib1d_ARB,(GLIContext ctx, GLuint index, GLuint size, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points), err ) {
			file_log("map_vertex_attrib1d_ARB called: ctx (GLIContext : %p) index (GLuint : %u) size (GLuint : %u) u1 (GLdouble : %f) u2 (GLdouble : %f) stride (GLint : %i) order (GLint : %i) points (const GLdouble* : %p)\n", ctx, index, size, u1, u2, stride, order, points);
			return map_vertex_attrib1d_ARB_reenter(ctx, index, size, u1, u2, stride, order, points);
		} END_MACH_OVERRIDE_PTR(map_vertex_attrib1d_ARB, obj->disp.map_vertex_attrib1d_ARB);

		if (err)
			log(LOG_ERR, "Failed to override map_vertex_attrib1d_ARB: %i", err);

		MACH_OVERRIDE(void,map_vertex_attrib1f_ARB,(GLIContext ctx, GLuint index, GLuint size, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points), err ) {
			file_log("map_vertex_attrib1f_ARB called: ctx (GLIContext : %p) index (GLuint : %u) size (GLuint : %u) u1 (GLfloat : %f) u2 (GLfloat : %f) stride (GLint : %i) order (GLint : %i) points (const GLfloat* : %p)\n", ctx, index, size, u1, u2, stride, order, points);
			return map_vertex_attrib1f_ARB_reenter(ctx, index, size, u1, u2, stride, order, points);
		} END_MACH_OVERRIDE_PTR(map_vertex_attrib1f_ARB, obj->disp.map_vertex_attrib1f_ARB);

		if (err)
			log(LOG_ERR, "Failed to override map_vertex_attrib1f_ARB: %i", err);

		MACH_OVERRIDE(void,map_vertex_attrib2d_ARB,(GLIContext ctx, GLuint index, GLuint size, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points), err ) {
			file_log("map_vertex_attrib2d_ARB called: ctx (GLIContext : %p) index (GLuint : %u) size (GLuint : %u) u1 (GLdouble : %f) u2 (GLdouble : %f) ustride (GLint : %i) uorder (GLint : %i) v1 (GLdouble : %f) v2 (GLdouble : %f) vstride (GLint : %i) vorder (GLint : %i) points (const GLdouble* : %p)\n", ctx, index, size, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
			return map_vertex_attrib2d_ARB_reenter(ctx, index, size, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
		} END_MACH_OVERRIDE_PTR(map_vertex_attrib2d_ARB, obj->disp.map_vertex_attrib2d_ARB);

		if (err)
			log(LOG_ERR, "Failed to override map_vertex_attrib2d_ARB: %i", err);

		MACH_OVERRIDE(void,map_vertex_attrib2f_ARB,(GLIContext ctx, GLuint index, GLuint size, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points), err ) {
			file_log("map_vertex_attrib2f_ARB called: ctx (GLIContext : %p) index (GLuint : %u) size (GLuint : %u) u1 (GLfloat : %f) u2 (GLfloat : %f) ustride (GLint : %i) uorder (GLint : %i) v1 (GLfloat : %f) v2 (GLfloat : %f) vstride (GLint : %i) vorder (GLint : %i) points (const GLfloat* : %p)\n", ctx, index, size, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
			return map_vertex_attrib2f_ARB_reenter(ctx, index, size, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
		} END_MACH_OVERRIDE_PTR(map_vertex_attrib2f_ARB, obj->disp.map_vertex_attrib2f_ARB);

		if (err)
			log(LOG_ERR, "Failed to override map_vertex_attrib2f_ARB: %i", err);

		MACH_OVERRIDE(void,point_parameterf,(GLIContext ctx, GLenum pname, GLfloat param), err ) {
			file_log("point_parameterf called: ctx (GLIContext : %p) pname (GLenum : %s) param (GLfloat : %f)\n", ctx, GLenumToString(pname).c_str(), param);
			return point_parameterf_reenter(ctx, pname, param);
		} END_MACH_OVERRIDE_PTR(point_parameterf, obj->disp.point_parameterf);

		if (err)
			log(LOG_ERR, "Failed to override point_parameterf: %i", err);

		MACH_OVERRIDE(void,point_parameterfv,(GLIContext ctx, GLenum pname, const GLfloat *params), err ) {
			file_log("point_parameterfv called: ctx (GLIContext : %p) pname (GLenum : %s) params (const GLfloat* : %p)\n", ctx, GLenumToString(pname).c_str(), params);
			return point_parameterfv_reenter(ctx, pname, params);
		} END_MACH_OVERRIDE_PTR(point_parameterfv, obj->disp.point_parameterfv);

		if (err)
			log(LOG_ERR, "Failed to override point_parameterfv: %i", err);

		MACH_OVERRIDE(void,point_parameteri,(GLIContext ctx, GLenum pname, GLint param), err ) {
			file_log("point_parameteri called: ctx (GLIContext : %p) pname (GLenum : %s) param (GLint : %i)\n", ctx, GLenumToString(pname).c_str(), param);
			return point_parameteri_reenter(ctx, pname, param);
		} END_MACH_OVERRIDE_PTR(point_parameteri, obj->disp.point_parameteri);

		if (err)
			log(LOG_ERR, "Failed to override point_parameteri: %i", err);

		MACH_OVERRIDE(void,point_parameteriv,(GLIContext ctx, GLenum pname, const GLint *params), err ) {
			file_log("point_parameteriv called: ctx (GLIContext : %p) pname (GLenum : %s) params (const GLint* : %p)\n", ctx, GLenumToString(pname).c_str(), params);
			return point_parameteriv_reenter(ctx, pname, params);
		} END_MACH_OVERRIDE_PTR(point_parameteriv, obj->disp.point_parameteriv);

		if (err)
			log(LOG_ERR, "Failed to override point_parameteriv: %i", err);

		MACH_OVERRIDE(void,fog_coordf,(GLIContext ctx, GLfloat coord), err ) {
			file_log("fog_coordf called: ctx (GLIContext : %p) coord (GLfloat : %f)\n", ctx, coord);
			return fog_coordf_reenter(ctx, coord);
		} END_MACH_OVERRIDE_PTR(fog_coordf, obj->disp.fog_coordf);

		if (err)
			log(LOG_ERR, "Failed to override fog_coordf: %i", err);

		MACH_OVERRIDE(void,fog_coordfv,(GLIContext ctx, const GLfloat *coord), err ) {
			file_log("fog_coordfv called: ctx (GLIContext : %p) coord (const GLfloat* : %p)\n", ctx, coord);
			return fog_coordfv_reenter(ctx, coord);
		} END_MACH_OVERRIDE_PTR(fog_coordfv, obj->disp.fog_coordfv);

		if (err)
			log(LOG_ERR, "Failed to override fog_coordfv: %i", err);

		MACH_OVERRIDE(void,fog_coordd,(GLIContext ctx, GLdouble coord), err ) {
			file_log("fog_coordd called: ctx (GLIContext : %p) coord (GLdouble : %f)\n", ctx, coord);
			return fog_coordd_reenter(ctx, coord);
		} END_MACH_OVERRIDE_PTR(fog_coordd, obj->disp.fog_coordd);

		if (err)
			log(LOG_ERR, "Failed to override fog_coordd: %i", err);

		MACH_OVERRIDE(void,fog_coorddv,(GLIContext ctx, const GLdouble *coord), err ) {
			file_log("fog_coorddv called: ctx (GLIContext : %p) coord (const GLdouble* : %p)\n", ctx, coord);
			return fog_coorddv_reenter(ctx, coord);
		} END_MACH_OVERRIDE_PTR(fog_coorddv, obj->disp.fog_coorddv);

		if (err)
			log(LOG_ERR, "Failed to override fog_coorddv: %i", err);

		MACH_OVERRIDE(void,fog_coord_pointer,(GLIContext ctx, GLenum type, GLsizei stride, const GLvoid *pointer), err ) {
			file_log("fog_coord_pointer called: ctx (GLIContext : %p) type (GLenum : %s) stride (GLsizei : %i) pointer (const GLvoid* : %p)\n", ctx, GLenumToString(type).c_str(), stride, pointer);
			return fog_coord_pointer_reenter(ctx, type, stride, pointer);
		} END_MACH_OVERRIDE_PTR(fog_coord_pointer, obj->disp.fog_coord_pointer);

		if (err)
			log(LOG_ERR, "Failed to override fog_coord_pointer: %i", err);

		MACH_OVERRIDE(void,vertex_array_parameteri_EXT,(GLIContext ctx, GLenum pname, GLint param), err ) {
			file_log("vertex_array_parameteri_EXT called: ctx (GLIContext : %p) pname (GLenum : %s) param (GLint : %i)\n", ctx, GLenumToString(pname).c_str(), param);
			return vertex_array_parameteri_EXT_reenter(ctx, pname, param);
		} END_MACH_OVERRIDE_PTR(vertex_array_parameteri_EXT, obj->disp.vertex_array_parameteri_EXT);

		if (err)
			log(LOG_ERR, "Failed to override vertex_array_parameteri_EXT: %i", err);

		MACH_OVERRIDE(void,bind_vertex_array_EXT,(GLIContext ctx, GLuint id), err ) {
			file_log("bind_vertex_array_EXT called: ctx (GLIContext : %p) id (GLuint : %u)\n", ctx, id);
			OpenGL::StateMachine::Shared.bind_vertex_array_EXT(ctx, id);
			return bind_vertex_array_EXT_reenter(ctx, id);
		} END_MACH_OVERRIDE_PTR(bind_vertex_array_EXT, obj->disp.bind_vertex_array_EXT);

		if (err)
			log(LOG_ERR, "Failed to override bind_vertex_array_EXT: %i", err);

		MACH_OVERRIDE(void,delete_vertex_arrays_EXT,(GLIContext ctx, GLsizei n, const GLuint *ids), err ) {
			file_log("delete_vertex_arrays_EXT called: ctx (GLIContext : %p) n (GLsizei : %i) ids (const GLuint* : %p)\n", ctx, n, ids);
			return delete_vertex_arrays_EXT_reenter(ctx, n, ids);
		} END_MACH_OVERRIDE_PTR(delete_vertex_arrays_EXT, obj->disp.delete_vertex_arrays_EXT);

		if (err)
			log(LOG_ERR, "Failed to override delete_vertex_arrays_EXT: %i", err);

		MACH_OVERRIDE(void,gen_vertex_arrays_EXT,(GLIContext ctx, GLsizei n, GLuint *ids), err ) {
			file_log("gen_vertex_arrays_EXT called: ctx (GLIContext : %p) n (GLsizei : %i) ids (GLuint* : %p)\n", ctx, n, ids);
			return gen_vertex_arrays_EXT_reenter(ctx, n, ids);
		} END_MACH_OVERRIDE_PTR(gen_vertex_arrays_EXT, obj->disp.gen_vertex_arrays_EXT);

		if (err)
			log(LOG_ERR, "Failed to override gen_vertex_arrays_EXT: %i", err);

		MACH_OVERRIDE(GLboolean,is_vertex_array_EXT,(GLIContext ctx, GLuint id), err ) {
			file_log("is_vertex_array_EXT called: ctx (GLIContext : %p) id (GLuint : %u)\n", ctx, id);
			GLboolean result = is_vertex_array_EXT_reenter(ctx, id);
			return result;
		} END_MACH_OVERRIDE_PTR(is_vertex_array_EXT, obj->disp.is_vertex_array_EXT);

		if (err)
			log(LOG_ERR, "Failed to override is_vertex_array_EXT: %i", err);

		MACH_OVERRIDE(void,element_pointer_APPLE,(GLIContext ctx, GLenum type, const GLvoid *pointer), err ) {
			file_log("element_pointer_APPLE called: ctx (GLIContext : %p) type (GLenum : %s) pointer (const GLvoid* : %p)\n", ctx, GLenumToString(type).c_str(), pointer);
			return element_pointer_APPLE_reenter(ctx, type, pointer);
		} END_MACH_OVERRIDE_PTR(element_pointer_APPLE, obj->disp.element_pointer_APPLE);

		if (err)
			log(LOG_ERR, "Failed to override element_pointer_APPLE: %i", err);

		MACH_OVERRIDE(void,draw_element_array_APPLE,(GLIContext ctx, GLenum mode, GLint first, GLsizei count), err ) {
			file_log("draw_element_array_APPLE called: ctx (GLIContext : %p) mode (GLenum : %s) first (GLint : %i) count (GLsizei : %i)\n", ctx, GLenumToString(mode).c_str(), first, count);
			OpenGL::StateMachine::Shared.draw_element_array_APPLE(ctx, mode, first, count);
			return draw_element_array_APPLE_reenter(ctx, mode, first, count);
		} END_MACH_OVERRIDE_PTR(draw_element_array_APPLE, obj->disp.draw_element_array_APPLE);

		if (err)
			log(LOG_ERR, "Failed to override draw_element_array_APPLE: %i", err);

		MACH_OVERRIDE(void,draw_range_element_array_APPLE,(GLIContext ctx, GLenum mode, GLuint start, GLuint end, GLint first, GLsizei count), err ) {
			file_log("draw_range_element_array_APPLE called: ctx (GLIContext : %p) mode (GLenum : %s) start (GLuint : %u) end (GLuint : %u) first (GLint : %i) count (GLsizei : %i)\n", ctx, GLenumToString(mode).c_str(), start, end, first, count);
			OpenGL::StateMachine::Shared.draw_range_element_array_APPLE(ctx, mode, start, end, first, count);
			return draw_range_element_array_APPLE_reenter(ctx, mode, start, end, first, count);
		} END_MACH_OVERRIDE_PTR(draw_range_element_array_APPLE, obj->disp.draw_range_element_array_APPLE);

		if (err)
			log(LOG_ERR, "Failed to override draw_range_element_array_APPLE: %i", err);

		MACH_OVERRIDE(void,weightbv_ARB,(GLIContext ctx, GLint size, const GLbyte *weights), err ) {
			file_log("weightbv_ARB called: ctx (GLIContext : %p) size (GLint : %i) weights (const GLbyte* : %p)\n", ctx, size, weights);
			return weightbv_ARB_reenter(ctx, size, weights);
		} END_MACH_OVERRIDE_PTR(weightbv_ARB, obj->disp.weightbv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override weightbv_ARB: %i", err);

		MACH_OVERRIDE(void,weightsv_ARB,(GLIContext ctx, GLint size, const GLshort *weights), err ) {
			file_log("weightsv_ARB called: ctx (GLIContext : %p) size (GLint : %i) weights (const GLshort* : %p)\n", ctx, size, weights);
			return weightsv_ARB_reenter(ctx, size, weights);
		} END_MACH_OVERRIDE_PTR(weightsv_ARB, obj->disp.weightsv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override weightsv_ARB: %i", err);

		MACH_OVERRIDE(void,weightiv_ARB,(GLIContext ctx, GLint size, const GLint *weights), err ) {
			file_log("weightiv_ARB called: ctx (GLIContext : %p) size (GLint : %i) weights (const GLint* : %p)\n", ctx, size, weights);
			return weightiv_ARB_reenter(ctx, size, weights);
		} END_MACH_OVERRIDE_PTR(weightiv_ARB, obj->disp.weightiv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override weightiv_ARB: %i", err);

		MACH_OVERRIDE(void,weightfv_ARB,(GLIContext ctx, GLint size, const GLfloat *weights), err ) {
			file_log("weightfv_ARB called: ctx (GLIContext : %p) size (GLint : %i) weights (const GLfloat* : %p)\n", ctx, size, weights);
			return weightfv_ARB_reenter(ctx, size, weights);
		} END_MACH_OVERRIDE_PTR(weightfv_ARB, obj->disp.weightfv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override weightfv_ARB: %i", err);

		MACH_OVERRIDE(void,weightdv_ARB,(GLIContext ctx, GLint size, const GLdouble *weights), err ) {
			file_log("weightdv_ARB called: ctx (GLIContext : %p) size (GLint : %i) weights (const GLdouble* : %p)\n", ctx, size, weights);
			return weightdv_ARB_reenter(ctx, size, weights);
		} END_MACH_OVERRIDE_PTR(weightdv_ARB, obj->disp.weightdv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override weightdv_ARB: %i", err);

		MACH_OVERRIDE(void,weightubv_ARB,(GLIContext ctx, GLint size, const GLubyte *weights), err ) {
			file_log("weightubv_ARB called: ctx (GLIContext : %p) size (GLint : %i) weights (const GLubyte* : %p)\n", ctx, size, weights);
			return weightubv_ARB_reenter(ctx, size, weights);
		} END_MACH_OVERRIDE_PTR(weightubv_ARB, obj->disp.weightubv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override weightubv_ARB: %i", err);

		MACH_OVERRIDE(void,weightusv_ARB,(GLIContext ctx, GLint size, const GLushort *weights), err ) {
			file_log("weightusv_ARB called: ctx (GLIContext : %p) size (GLint : %i) weights (const GLushort* : %p)\n", ctx, size, weights);
			return weightusv_ARB_reenter(ctx, size, weights);
		} END_MACH_OVERRIDE_PTR(weightusv_ARB, obj->disp.weightusv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override weightusv_ARB: %i", err);

		MACH_OVERRIDE(void,weightuiv_ARB,(GLIContext ctx, GLint size, const GLuint *weights), err ) {
			file_log("weightuiv_ARB called: ctx (GLIContext : %p) size (GLint : %i) weights (const GLuint* : %p)\n", ctx, size, weights);
			return weightuiv_ARB_reenter(ctx, size, weights);
		} END_MACH_OVERRIDE_PTR(weightuiv_ARB, obj->disp.weightuiv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override weightuiv_ARB: %i", err);

		MACH_OVERRIDE(void,weight_pointer_ARB,(GLIContext ctx, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer), err ) {
			file_log("weight_pointer_ARB called: ctx (GLIContext : %p) size (GLint : %i) type (GLenum : %s) stride (GLsizei : %i) pointer (const GLvoid* : %p)\n", ctx, size, GLenumToString(type).c_str(), stride, pointer);
			return weight_pointer_ARB_reenter(ctx, size, type, stride, pointer);
		} END_MACH_OVERRIDE_PTR(weight_pointer_ARB, obj->disp.weight_pointer_ARB);

		if (err)
			log(LOG_ERR, "Failed to override weight_pointer_ARB: %i", err);

		MACH_OVERRIDE(void,vertex_blend_ARB,(GLIContext ctx, GLint count), err ) {
			file_log("vertex_blend_ARB called: ctx (GLIContext : %p) count (GLint : %i)\n", ctx, count);
			return vertex_blend_ARB_reenter(ctx, count);
		} END_MACH_OVERRIDE_PTR(vertex_blend_ARB, obj->disp.vertex_blend_ARB);

		if (err)
			log(LOG_ERR, "Failed to override vertex_blend_ARB: %i", err);

		MACH_OVERRIDE(void,multi_draw_arrays,(GLIContext ctx, GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount), err ) {
			file_log("multi_draw_arrays called: ctx (GLIContext : %p) mode (GLenum : %s) first (const GLint* : %p) count (const GLsizei* : %p) drawcount (GLsizei : %i)\n", ctx, GLenumToString(mode).c_str(), first, count, drawcount);
			OpenGL::StateMachine::Shared.multi_draw_arrays(ctx, mode, first, count, drawcount);
			return multi_draw_arrays_reenter(ctx, mode, first, count, drawcount);
		} END_MACH_OVERRIDE_PTR(multi_draw_arrays, obj->disp.multi_draw_arrays);

		if (err)
			log(LOG_ERR, "Failed to override multi_draw_arrays: %i", err);

		MACH_OVERRIDE(void,multi_draw_elements,(GLIContext ctx, GLenum mode, const GLsizei *count, GLenum type, const GLvoid* const *indices, GLsizei drawcount), err ) {
			file_log("multi_draw_elements called: ctx (GLIContext : %p) mode (GLenum : %s) count (const GLsizei* : %p) type (GLenum : %s) indices (const GLvoid*const* : %p) drawcount (GLsizei : %i)\n", ctx, GLenumToString(mode).c_str(), count, GLenumToString(type).c_str(), indices, drawcount);
			OpenGL::StateMachine::Shared.multi_draw_elements(ctx, mode, count, type, indices, drawcount);
			return multi_draw_elements_reenter(ctx, mode, count, type, indices, drawcount);
		} END_MACH_OVERRIDE_PTR(multi_draw_elements, obj->disp.multi_draw_elements);

		if (err)
			log(LOG_ERR, "Failed to override multi_draw_elements: %i", err);

		MACH_OVERRIDE(void,window_pos2d,(GLIContext ctx, GLdouble x, GLdouble y), err ) {
			file_log("window_pos2d called: ctx (GLIContext : %p) x (GLdouble : %f) y (GLdouble : %f)\n", ctx, x, y);
			return window_pos2d_reenter(ctx, x, y);
		} END_MACH_OVERRIDE_PTR(window_pos2d, obj->disp.window_pos2d);

		if (err)
			log(LOG_ERR, "Failed to override window_pos2d: %i", err);

		MACH_OVERRIDE(void,window_pos2dv,(GLIContext ctx, const GLdouble *v), err ) {
			file_log("window_pos2dv called: ctx (GLIContext : %p) v (const GLdouble* : %p)\n", ctx, v);
			return window_pos2dv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(window_pos2dv, obj->disp.window_pos2dv);

		if (err)
			log(LOG_ERR, "Failed to override window_pos2dv: %i", err);

		MACH_OVERRIDE(void,window_pos2f,(GLIContext ctx, GLfloat x, GLfloat y), err ) {
			file_log("window_pos2f called: ctx (GLIContext : %p) x (GLfloat : %f) y (GLfloat : %f)\n", ctx, x, y);
			return window_pos2f_reenter(ctx, x, y);
		} END_MACH_OVERRIDE_PTR(window_pos2f, obj->disp.window_pos2f);

		if (err)
			log(LOG_ERR, "Failed to override window_pos2f: %i", err);

		MACH_OVERRIDE(void,window_pos2fv,(GLIContext ctx, const GLfloat *v), err ) {
			file_log("window_pos2fv called: ctx (GLIContext : %p) v (const GLfloat* : %p)\n", ctx, v);
			return window_pos2fv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(window_pos2fv, obj->disp.window_pos2fv);

		if (err)
			log(LOG_ERR, "Failed to override window_pos2fv: %i", err);

		MACH_OVERRIDE(void,window_pos2i,(GLIContext ctx, GLint x, GLint y), err ) {
			file_log("window_pos2i called: ctx (GLIContext : %p) x (GLint : %i) y (GLint : %i)\n", ctx, x, y);
			return window_pos2i_reenter(ctx, x, y);
		} END_MACH_OVERRIDE_PTR(window_pos2i, obj->disp.window_pos2i);

		if (err)
			log(LOG_ERR, "Failed to override window_pos2i: %i", err);

		MACH_OVERRIDE(void,window_pos2iv,(GLIContext ctx, const GLint *v), err ) {
			file_log("window_pos2iv called: ctx (GLIContext : %p) v (const GLint* : %p)\n", ctx, v);
			return window_pos2iv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(window_pos2iv, obj->disp.window_pos2iv);

		if (err)
			log(LOG_ERR, "Failed to override window_pos2iv: %i", err);

		MACH_OVERRIDE(void,window_pos2s,(GLIContext ctx, GLshort x, GLshort y), err ) {
			file_log("window_pos2s called: ctx (GLIContext : %p) x (GLshort : %i) y (GLshort : %i)\n", ctx, x, y);
			return window_pos2s_reenter(ctx, x, y);
		} END_MACH_OVERRIDE_PTR(window_pos2s, obj->disp.window_pos2s);

		if (err)
			log(LOG_ERR, "Failed to override window_pos2s: %i", err);

		MACH_OVERRIDE(void,window_pos2sv,(GLIContext ctx, const GLshort *v), err ) {
			file_log("window_pos2sv called: ctx (GLIContext : %p) v (const GLshort* : %p)\n", ctx, v);
			return window_pos2sv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(window_pos2sv, obj->disp.window_pos2sv);

		if (err)
			log(LOG_ERR, "Failed to override window_pos2sv: %i", err);

		MACH_OVERRIDE(void,window_pos3d,(GLIContext ctx, GLdouble x, GLdouble y, GLdouble z), err ) {
			file_log("window_pos3d called: ctx (GLIContext : %p) x (GLdouble : %f) y (GLdouble : %f) z (GLdouble : %f)\n", ctx, x, y, z);
			return window_pos3d_reenter(ctx, x, y, z);
		} END_MACH_OVERRIDE_PTR(window_pos3d, obj->disp.window_pos3d);

		if (err)
			log(LOG_ERR, "Failed to override window_pos3d: %i", err);

		MACH_OVERRIDE(void,window_pos3dv,(GLIContext ctx, const GLdouble *v), err ) {
			file_log("window_pos3dv called: ctx (GLIContext : %p) v (const GLdouble* : %p)\n", ctx, v);
			return window_pos3dv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(window_pos3dv, obj->disp.window_pos3dv);

		if (err)
			log(LOG_ERR, "Failed to override window_pos3dv: %i", err);

		MACH_OVERRIDE(void,window_pos3f,(GLIContext ctx, GLfloat x, GLfloat y, GLfloat z), err ) {
			file_log("window_pos3f called: ctx (GLIContext : %p) x (GLfloat : %f) y (GLfloat : %f) z (GLfloat : %f)\n", ctx, x, y, z);
			return window_pos3f_reenter(ctx, x, y, z);
		} END_MACH_OVERRIDE_PTR(window_pos3f, obj->disp.window_pos3f);

		if (err)
			log(LOG_ERR, "Failed to override window_pos3f: %i", err);

		MACH_OVERRIDE(void,window_pos3fv,(GLIContext ctx, const GLfloat *v), err ) {
			file_log("window_pos3fv called: ctx (GLIContext : %p) v (const GLfloat* : %p)\n", ctx, v);
			return window_pos3fv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(window_pos3fv, obj->disp.window_pos3fv);

		if (err)
			log(LOG_ERR, "Failed to override window_pos3fv: %i", err);

		MACH_OVERRIDE(void,window_pos3i,(GLIContext ctx, GLint x, GLint y, GLint z), err ) {
			file_log("window_pos3i called: ctx (GLIContext : %p) x (GLint : %i) y (GLint : %i) z (GLint : %i)\n", ctx, x, y, z);
			return window_pos3i_reenter(ctx, x, y, z);
		} END_MACH_OVERRIDE_PTR(window_pos3i, obj->disp.window_pos3i);

		if (err)
			log(LOG_ERR, "Failed to override window_pos3i: %i", err);

		MACH_OVERRIDE(void,window_pos3iv,(GLIContext ctx, const GLint *v), err ) {
			file_log("window_pos3iv called: ctx (GLIContext : %p) v (const GLint* : %p)\n", ctx, v);
			return window_pos3iv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(window_pos3iv, obj->disp.window_pos3iv);

		if (err)
			log(LOG_ERR, "Failed to override window_pos3iv: %i", err);

		MACH_OVERRIDE(void,window_pos3s,(GLIContext ctx, GLshort x, GLshort y, GLshort z), err ) {
			file_log("window_pos3s called: ctx (GLIContext : %p) x (GLshort : %i) y (GLshort : %i) z (GLshort : %i)\n", ctx, x, y, z);
			return window_pos3s_reenter(ctx, x, y, z);
		} END_MACH_OVERRIDE_PTR(window_pos3s, obj->disp.window_pos3s);

		if (err)
			log(LOG_ERR, "Failed to override window_pos3s: %i", err);

		MACH_OVERRIDE(void,window_pos3sv,(GLIContext ctx, const GLshort *v), err ) {
			file_log("window_pos3sv called: ctx (GLIContext : %p) v (const GLshort* : %p)\n", ctx, v);
			return window_pos3sv_reenter(ctx, v);
		} END_MACH_OVERRIDE_PTR(window_pos3sv, obj->disp.window_pos3sv);

		if (err)
			log(LOG_ERR, "Failed to override window_pos3sv: %i", err);

		MACH_OVERRIDE(void,active_stencil_face_EXT,(GLIContext ctx, GLenum face), err ) {
			file_log("active_stencil_face_EXT called: ctx (GLIContext : %p) face (GLenum : %s)\n", ctx, GLenumToString(face).c_str());
			OpenGL::StateMachine::Shared.active_stencil_face_EXT(ctx, face);
			return active_stencil_face_EXT_reenter(ctx, face);
		} END_MACH_OVERRIDE_PTR(active_stencil_face_EXT, obj->disp.active_stencil_face_EXT);

		if (err)
			log(LOG_ERR, "Failed to override active_stencil_face_EXT: %i", err);

		MACH_OVERRIDE(void,stencil_op_separate_ATI,(GLIContext ctx, GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass), err ) {
			file_log("stencil_op_separate_ATI called: ctx (GLIContext : %p) face (GLenum : %s) sfail (GLenum : %s) dpfail (GLenum : %s) dppass (GLenum : %s)\n", ctx, GLenumToString(face).c_str(), GLenumToString(sfail).c_str(), GLenumToString(dpfail).c_str(), GLenumToString(dppass).c_str());
			return stencil_op_separate_ATI_reenter(ctx, face, sfail, dpfail, dppass);
		} END_MACH_OVERRIDE_PTR(stencil_op_separate_ATI, obj->disp.stencil_op_separate_ATI);

		if (err)
			log(LOG_ERR, "Failed to override stencil_op_separate_ATI: %i", err);

		MACH_OVERRIDE(void,stencil_func_separate_ATI,(GLIContext ctx, GLenum frontfunc, GLenum backfunc, GLint ref, GLuint mask), err ) {
			file_log("stencil_func_separate_ATI called: ctx (GLIContext : %p) frontfunc (GLenum : %s) backfunc (GLenum : %s) ref (GLint : %i) mask (GLuint : %u)\n", ctx, GLenumToString(frontfunc).c_str(), GLenumToString(backfunc).c_str(), ref, mask);
			return stencil_func_separate_ATI_reenter(ctx, frontfunc, backfunc, ref, mask);
		} END_MACH_OVERRIDE_PTR(stencil_func_separate_ATI, obj->disp.stencil_func_separate_ATI);

		if (err)
			log(LOG_ERR, "Failed to override stencil_func_separate_ATI: %i", err);

		MACH_OVERRIDE(void,flush_render_APPLE,(GLIContext ctx), err ) {
			file_log("flush_render_APPLE called: ctx (GLIContext : %p)\n", ctx);
			return flush_render_APPLE_reenter(ctx);
		} END_MACH_OVERRIDE_PTR(flush_render_APPLE, obj->disp.flush_render_APPLE);

		if (err)
			log(LOG_ERR, "Failed to override flush_render_APPLE: %i", err);

		MACH_OVERRIDE(void,finish_render_APPLE,(GLIContext ctx), err ) {
			file_log("finish_render_APPLE called: ctx (GLIContext : %p)\n", ctx);
			return finish_render_APPLE_reenter(ctx);
		} END_MACH_OVERRIDE_PTR(finish_render_APPLE, obj->disp.finish_render_APPLE);

		if (err)
			log(LOG_ERR, "Failed to override finish_render_APPLE: %i", err);

		MACH_OVERRIDE(void,swap_APPLE,(GLIContext ctx), err ) {
			file_log("swap_APPLE called: ctx (GLIContext : %p)\n", ctx);
			OpenGL::StateMachine::Shared.swap_APPLE(ctx);
			return swap_APPLE_reenter(ctx);
		} END_MACH_OVERRIDE_PTR(swap_APPLE, obj->disp.swap_APPLE);

		if (err)
			log(LOG_ERR, "Failed to override swap_APPLE: %i", err);

		MACH_OVERRIDE(void,delete_object_ARB,(GLIContext ctx, GLhandleARB obj), err ) {
			file_log("delete_object_ARB called: ctx (GLIContext : %p) obj (GLhandleARB : %p)\n", ctx, obj);
			return delete_object_ARB_reenter(ctx, obj);
		} END_MACH_OVERRIDE_PTR(delete_object_ARB, obj->disp.delete_object_ARB);

		if (err)
			log(LOG_ERR, "Failed to override delete_object_ARB: %i", err);

		MACH_OVERRIDE(GLhandleARB,get_handle_ARB,(GLIContext ctx, GLenum pname), err ) {
			file_log("get_handle_ARB called: ctx (GLIContext : %p) pname (GLenum : %s)\n", ctx, GLenumToString(pname).c_str());
			GLhandleARB result = get_handle_ARB_reenter(ctx, pname);
			return result;
		} END_MACH_OVERRIDE_PTR(get_handle_ARB, obj->disp.get_handle_ARB);

		if (err)
			log(LOG_ERR, "Failed to override get_handle_ARB: %i", err);

		MACH_OVERRIDE(void,detach_object_ARB,(GLIContext ctx, GLhandleARB containerObj, GLhandleARB attachedObj), err ) {
			file_log("detach_object_ARB called: ctx (GLIContext : %p) containerObj (GLhandleARB : %p) attachedObj (GLhandleARB : %p)\n", ctx, containerObj, attachedObj);
			return detach_object_ARB_reenter(ctx, containerObj, attachedObj);
		} END_MACH_OVERRIDE_PTR(detach_object_ARB, obj->disp.detach_object_ARB);

		if (err)
			log(LOG_ERR, "Failed to override detach_object_ARB: %i", err);

		MACH_OVERRIDE(GLhandleARB,create_shader_object_ARB,(GLIContext ctx, GLenum shaderType), err ) {
			file_log("create_shader_object_ARB called: ctx (GLIContext : %p) shaderType (GLenum : %s)\n", ctx, GLenumToString(shaderType).c_str());
			GLhandleARB result = create_shader_object_ARB_reenter(ctx, shaderType);
			return result;
		} END_MACH_OVERRIDE_PTR(create_shader_object_ARB, obj->disp.create_shader_object_ARB);

		if (err)
			log(LOG_ERR, "Failed to override create_shader_object_ARB: %i", err);

		MACH_OVERRIDE(void,shader_source_ARB,(GLIContext ctx, GLhandleARB shaderObj, GLsizei count, const GLcharARB* const *string, const GLint *length), err ) {
			file_log("shader_source_ARB called: ctx (GLIContext : %p) shaderObj (GLhandleARB : %p) count (GLsizei : %i) string (const GLcharARB*const* : %p) length (const GLint* : %p)\n", ctx, shaderObj, count, string, length);
			return shader_source_ARB_reenter(ctx, shaderObj, count, string, length);
		} END_MACH_OVERRIDE_PTR(shader_source_ARB, obj->disp.shader_source_ARB);

		if (err)
			log(LOG_ERR, "Failed to override shader_source_ARB: %i", err);

		MACH_OVERRIDE(void,compile_shader_ARB,(GLIContext ctx, GLhandleARB shaderObj), err ) {
			file_log("compile_shader_ARB called: ctx (GLIContext : %p) shaderObj (GLhandleARB : %p)\n", ctx, shaderObj);
			return compile_shader_ARB_reenter(ctx, shaderObj);
		} END_MACH_OVERRIDE_PTR(compile_shader_ARB, obj->disp.compile_shader_ARB);

		if (err)
			log(LOG_ERR, "Failed to override compile_shader_ARB: %i", err);

		MACH_OVERRIDE(GLhandleARB,create_program_object_ARB,(GLIContext ctx), err ) {
			file_log("create_program_object_ARB called: ctx (GLIContext : %p)\n", ctx);
			GLhandleARB result = create_program_object_ARB_reenter(ctx);
			return result;
		} END_MACH_OVERRIDE_PTR(create_program_object_ARB, obj->disp.create_program_object_ARB);

		if (err)
			log(LOG_ERR, "Failed to override create_program_object_ARB: %i", err);

		MACH_OVERRIDE(void,attach_object_ARB,(GLIContext ctx, GLhandleARB containerObj, GLhandleARB obj), err ) {
			file_log("attach_object_ARB called: ctx (GLIContext : %p) containerObj (GLhandleARB : %p) obj (GLhandleARB : %p)\n", ctx, containerObj, obj);
			return attach_object_ARB_reenter(ctx, containerObj, obj);
		} END_MACH_OVERRIDE_PTR(attach_object_ARB, obj->disp.attach_object_ARB);

		if (err)
			log(LOG_ERR, "Failed to override attach_object_ARB: %i", err);

		MACH_OVERRIDE(void,link_program_ARB,(GLIContext ctx, GLhandleARB programObj), err ) {
			file_log("link_program_ARB called: ctx (GLIContext : %p) programObj (GLhandleARB : %p)\n", ctx, programObj);
			return link_program_ARB_reenter(ctx, programObj);
		} END_MACH_OVERRIDE_PTR(link_program_ARB, obj->disp.link_program_ARB);

		if (err)
			log(LOG_ERR, "Failed to override link_program_ARB: %i", err);

		MACH_OVERRIDE(void,use_program_object_ARB,(GLIContext ctx, GLhandleARB programObj), err ) {
			file_log("use_program_object_ARB called: ctx (GLIContext : %p) programObj (GLhandleARB : %p)\n", ctx, programObj);
			return use_program_object_ARB_reenter(ctx, programObj);
		} END_MACH_OVERRIDE_PTR(use_program_object_ARB, obj->disp.use_program_object_ARB);

		if (err)
			log(LOG_ERR, "Failed to override use_program_object_ARB: %i", err);

		MACH_OVERRIDE(void,validate_program_ARB,(GLIContext ctx, GLhandleARB programObj), err ) {
			file_log("validate_program_ARB called: ctx (GLIContext : %p) programObj (GLhandleARB : %p)\n", ctx, programObj);
			return validate_program_ARB_reenter(ctx, programObj);
		} END_MACH_OVERRIDE_PTR(validate_program_ARB, obj->disp.validate_program_ARB);

		if (err)
			log(LOG_ERR, "Failed to override validate_program_ARB: %i", err);

		MACH_OVERRIDE(void,uniform1f_ARB,(GLIContext ctx, GLint location, GLfloat v0), err ) {
			file_log("uniform1f_ARB called: ctx (GLIContext : %p) location (GLint : %i) v0 (GLfloat : %f)\n", ctx, location, v0);
			return uniform1f_ARB_reenter(ctx, location, v0);
		} END_MACH_OVERRIDE_PTR(uniform1f_ARB, obj->disp.uniform1f_ARB);

		if (err)
			log(LOG_ERR, "Failed to override uniform1f_ARB: %i", err);

		MACH_OVERRIDE(void,uniform2f_ARB,(GLIContext ctx, GLint location, GLfloat v0, GLfloat v1), err ) {
			file_log("uniform2f_ARB called: ctx (GLIContext : %p) location (GLint : %i) v0 (GLfloat : %f) v1 (GLfloat : %f)\n", ctx, location, v0, v1);
			return uniform2f_ARB_reenter(ctx, location, v0, v1);
		} END_MACH_OVERRIDE_PTR(uniform2f_ARB, obj->disp.uniform2f_ARB);

		if (err)
			log(LOG_ERR, "Failed to override uniform2f_ARB: %i", err);

		MACH_OVERRIDE(void,uniform3f_ARB,(GLIContext ctx, GLint location, GLfloat v0, GLfloat v1, GLfloat v2), err ) {
			file_log("uniform3f_ARB called: ctx (GLIContext : %p) location (GLint : %i) v0 (GLfloat : %f) v1 (GLfloat : %f) v2 (GLfloat : %f)\n", ctx, location, v0, v1, v2);
			return uniform3f_ARB_reenter(ctx, location, v0, v1, v2);
		} END_MACH_OVERRIDE_PTR(uniform3f_ARB, obj->disp.uniform3f_ARB);

		if (err)
			log(LOG_ERR, "Failed to override uniform3f_ARB: %i", err);

		MACH_OVERRIDE(void,uniform4f_ARB,(GLIContext ctx, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3), err ) {
			file_log("uniform4f_ARB called: ctx (GLIContext : %p) location (GLint : %i) v0 (GLfloat : %f) v1 (GLfloat : %f) v2 (GLfloat : %f) v3 (GLfloat : %f)\n", ctx, location, v0, v1, v2, v3);
			return uniform4f_ARB_reenter(ctx, location, v0, v1, v2, v3);
		} END_MACH_OVERRIDE_PTR(uniform4f_ARB, obj->disp.uniform4f_ARB);

		if (err)
			log(LOG_ERR, "Failed to override uniform4f_ARB: %i", err);

		MACH_OVERRIDE(void,uniform1i_ARB,(GLIContext ctx, GLint location, GLint v0), err ) {
			file_log("uniform1i_ARB called: ctx (GLIContext : %p) location (GLint : %i) v0 (GLint : %i)\n", ctx, location, v0);
			return uniform1i_ARB_reenter(ctx, location, v0);
		} END_MACH_OVERRIDE_PTR(uniform1i_ARB, obj->disp.uniform1i_ARB);

		if (err)
			log(LOG_ERR, "Failed to override uniform1i_ARB: %i", err);

		MACH_OVERRIDE(void,uniform2i_ARB,(GLIContext ctx, GLint location, GLint v0, GLint v1), err ) {
			file_log("uniform2i_ARB called: ctx (GLIContext : %p) location (GLint : %i) v0 (GLint : %i) v1 (GLint : %i)\n", ctx, location, v0, v1);
			return uniform2i_ARB_reenter(ctx, location, v0, v1);
		} END_MACH_OVERRIDE_PTR(uniform2i_ARB, obj->disp.uniform2i_ARB);

		if (err)
			log(LOG_ERR, "Failed to override uniform2i_ARB: %i", err);

		MACH_OVERRIDE(void,uniform3i_ARB,(GLIContext ctx, GLint location, GLint v0, GLint v1, GLint v2), err ) {
			file_log("uniform3i_ARB called: ctx (GLIContext : %p) location (GLint : %i) v0 (GLint : %i) v1 (GLint : %i) v2 (GLint : %i)\n", ctx, location, v0, v1, v2);
			return uniform3i_ARB_reenter(ctx, location, v0, v1, v2);
		} END_MACH_OVERRIDE_PTR(uniform3i_ARB, obj->disp.uniform3i_ARB);

		if (err)
			log(LOG_ERR, "Failed to override uniform3i_ARB: %i", err);

		MACH_OVERRIDE(void,uniform4i_ARB,(GLIContext ctx, GLint location, GLint v0, GLint v1, GLint v2, GLint v3), err ) {
			file_log("uniform4i_ARB called: ctx (GLIContext : %p) location (GLint : %i) v0 (GLint : %i) v1 (GLint : %i) v2 (GLint : %i) v3 (GLint : %i)\n", ctx, location, v0, v1, v2, v3);
			return uniform4i_ARB_reenter(ctx, location, v0, v1, v2, v3);
		} END_MACH_OVERRIDE_PTR(uniform4i_ARB, obj->disp.uniform4i_ARB);

		if (err)
			log(LOG_ERR, "Failed to override uniform4i_ARB: %i", err);

		MACH_OVERRIDE(void,uniform1fv_ARB,(GLIContext ctx, GLint location, GLsizei count, const GLfloat *value), err ) {
			file_log("uniform1fv_ARB called: ctx (GLIContext : %p) location (GLint : %i) count (GLsizei : %i) value (const GLfloat* : %p)\n", ctx, location, count, value);
			return uniform1fv_ARB_reenter(ctx, location, count, value);
		} END_MACH_OVERRIDE_PTR(uniform1fv_ARB, obj->disp.uniform1fv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override uniform1fv_ARB: %i", err);

		MACH_OVERRIDE(void,uniform2fv_ARB,(GLIContext ctx, GLint location, GLsizei count, const GLfloat *value), err ) {
			file_log("uniform2fv_ARB called: ctx (GLIContext : %p) location (GLint : %i) count (GLsizei : %i) value (const GLfloat* : %p)\n", ctx, location, count, value);
			return uniform2fv_ARB_reenter(ctx, location, count, value);
		} END_MACH_OVERRIDE_PTR(uniform2fv_ARB, obj->disp.uniform2fv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override uniform2fv_ARB: %i", err);

		MACH_OVERRIDE(void,uniform3fv_ARB,(GLIContext ctx, GLint location, GLsizei count, const GLfloat *value), err ) {
			file_log("uniform3fv_ARB called: ctx (GLIContext : %p) location (GLint : %i) count (GLsizei : %i) value (const GLfloat* : %p)\n", ctx, location, count, value);
			return uniform3fv_ARB_reenter(ctx, location, count, value);
		} END_MACH_OVERRIDE_PTR(uniform3fv_ARB, obj->disp.uniform3fv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override uniform3fv_ARB: %i", err);

		MACH_OVERRIDE(void,uniform4fv_ARB,(GLIContext ctx, GLint location, GLsizei count, const GLfloat *value), err ) {
			file_log("uniform4fv_ARB called: ctx (GLIContext : %p) location (GLint : %i) count (GLsizei : %i) value (const GLfloat* : %p)\n", ctx, location, count, value);
			return uniform4fv_ARB_reenter(ctx, location, count, value);
		} END_MACH_OVERRIDE_PTR(uniform4fv_ARB, obj->disp.uniform4fv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override uniform4fv_ARB: %i", err);

		MACH_OVERRIDE(void,uniform1iv_ARB,(GLIContext ctx, GLint location, GLsizei count, const GLint *value), err ) {
			file_log("uniform1iv_ARB called: ctx (GLIContext : %p) location (GLint : %i) count (GLsizei : %i) value (const GLint* : %p)\n", ctx, location, count, value);
			return uniform1iv_ARB_reenter(ctx, location, count, value);
		} END_MACH_OVERRIDE_PTR(uniform1iv_ARB, obj->disp.uniform1iv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override uniform1iv_ARB: %i", err);

		MACH_OVERRIDE(void,uniform2iv_ARB,(GLIContext ctx, GLint location, GLsizei count, const GLint *value), err ) {
			file_log("uniform2iv_ARB called: ctx (GLIContext : %p) location (GLint : %i) count (GLsizei : %i) value (const GLint* : %p)\n", ctx, location, count, value);
			return uniform2iv_ARB_reenter(ctx, location, count, value);
		} END_MACH_OVERRIDE_PTR(uniform2iv_ARB, obj->disp.uniform2iv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override uniform2iv_ARB: %i", err);

		MACH_OVERRIDE(void,uniform3iv_ARB,(GLIContext ctx, GLint location, GLsizei count, const GLint *value), err ) {
			file_log("uniform3iv_ARB called: ctx (GLIContext : %p) location (GLint : %i) count (GLsizei : %i) value (const GLint* : %p)\n", ctx, location, count, value);
			return uniform3iv_ARB_reenter(ctx, location, count, value);
		} END_MACH_OVERRIDE_PTR(uniform3iv_ARB, obj->disp.uniform3iv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override uniform3iv_ARB: %i", err);

		MACH_OVERRIDE(void,uniform4iv_ARB,(GLIContext ctx, GLint location, GLsizei count, const GLint *value), err ) {
			file_log("uniform4iv_ARB called: ctx (GLIContext : %p) location (GLint : %i) count (GLsizei : %i) value (const GLint* : %p)\n", ctx, location, count, value);
			return uniform4iv_ARB_reenter(ctx, location, count, value);
		} END_MACH_OVERRIDE_PTR(uniform4iv_ARB, obj->disp.uniform4iv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override uniform4iv_ARB: %i", err);

		MACH_OVERRIDE(void,uniform_matrix2fv_ARB,(GLIContext ctx, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value), err ) {
			file_log("uniform_matrix2fv_ARB called: ctx (GLIContext : %p) location (GLint : %i) count (GLsizei : %i) transpose (GLboolean : %i) value (const GLfloat* : %p)\n", ctx, location, count, transpose, value);
			return uniform_matrix2fv_ARB_reenter(ctx, location, count, transpose, value);
		} END_MACH_OVERRIDE_PTR(uniform_matrix2fv_ARB, obj->disp.uniform_matrix2fv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override uniform_matrix2fv_ARB: %i", err);

		MACH_OVERRIDE(void,uniform_matrix3fv_ARB,(GLIContext ctx, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value), err ) {
			file_log("uniform_matrix3fv_ARB called: ctx (GLIContext : %p) location (GLint : %i) count (GLsizei : %i) transpose (GLboolean : %i) value (const GLfloat* : %p)\n", ctx, location, count, transpose, value);
			return uniform_matrix3fv_ARB_reenter(ctx, location, count, transpose, value);
		} END_MACH_OVERRIDE_PTR(uniform_matrix3fv_ARB, obj->disp.uniform_matrix3fv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override uniform_matrix3fv_ARB: %i", err);

		MACH_OVERRIDE(void,uniform_matrix4fv_ARB,(GLIContext ctx, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value), err ) {
			file_log("uniform_matrix4fv_ARB called: ctx (GLIContext : %p) location (GLint : %i) count (GLsizei : %i) transpose (GLboolean : %i) value (const GLfloat* : %p)\n", ctx, location, count, transpose, value);
			return uniform_matrix4fv_ARB_reenter(ctx, location, count, transpose, value);
		} END_MACH_OVERRIDE_PTR(uniform_matrix4fv_ARB, obj->disp.uniform_matrix4fv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override uniform_matrix4fv_ARB: %i", err);

		MACH_OVERRIDE(void,get_object_parameterfv_ARB,(GLIContext ctx, GLhandleARB obj, GLenum pname, GLfloat *params), err ) {
			file_log("get_object_parameterfv_ARB called: ctx (GLIContext : %p) obj (GLhandleARB : %p) pname (GLenum : %s) params (GLfloat* : %p)\n", ctx, obj, GLenumToString(pname).c_str(), params);
			return get_object_parameterfv_ARB_reenter(ctx, obj, pname, params);
		} END_MACH_OVERRIDE_PTR(get_object_parameterfv_ARB, obj->disp.get_object_parameterfv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override get_object_parameterfv_ARB: %i", err);

		MACH_OVERRIDE(void,get_object_parameteriv_ARB,(GLIContext ctx, GLhandleARB obj, GLenum pname, GLint *params), err ) {
			file_log("get_object_parameteriv_ARB called: ctx (GLIContext : %p) obj (GLhandleARB : %p) pname (GLenum : %s) params (GLint* : %p)\n", ctx, obj, GLenumToString(pname).c_str(), params);
			return get_object_parameteriv_ARB_reenter(ctx, obj, pname, params);
		} END_MACH_OVERRIDE_PTR(get_object_parameteriv_ARB, obj->disp.get_object_parameteriv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override get_object_parameteriv_ARB: %i", err);

		MACH_OVERRIDE(void,get_info_log_ARB,(GLIContext ctx, GLhandleARB obj, GLsizei maxLength, GLsizei *length, GLcharARB *infoLog), err ) {
			file_log("get_info_log_ARB called: ctx (GLIContext : %p) obj (GLhandleARB : %p) maxLength (GLsizei : %i) length (GLsizei* : %p) infoLog (GLcharARB* : %p)\n", ctx, obj, maxLength, length, infoLog);
			return get_info_log_ARB_reenter(ctx, obj, maxLength, length, infoLog);
		} END_MACH_OVERRIDE_PTR(get_info_log_ARB, obj->disp.get_info_log_ARB);

		if (err)
			log(LOG_ERR, "Failed to override get_info_log_ARB: %i", err);

		MACH_OVERRIDE(void,get_attached_objects_ARB,(GLIContext ctx, GLhandleARB containerObj, GLsizei maxCount, GLsizei *count, GLhandleARB *obj), err ) {
			file_log("get_attached_objects_ARB called: ctx (GLIContext : %p) containerObj (GLhandleARB : %p) maxCount (GLsizei : %i) count (GLsizei* : %p) obj (GLhandleARB* : %p)\n", ctx, containerObj, maxCount, count, obj);
			return get_attached_objects_ARB_reenter(ctx, containerObj, maxCount, count, obj);
		} END_MACH_OVERRIDE_PTR(get_attached_objects_ARB, obj->disp.get_attached_objects_ARB);

		if (err)
			log(LOG_ERR, "Failed to override get_attached_objects_ARB: %i", err);

		MACH_OVERRIDE(GLint,get_uniform_location_ARB,(GLIContext ctx, GLhandleARB programObj, const GLcharARB *name), err ) {
			file_log("get_uniform_location_ARB called: ctx (GLIContext : %p) programObj (GLhandleARB : %p) name (const GLcharARB* : %p)\n", ctx, programObj, name);
			GLint result = get_uniform_location_ARB_reenter(ctx, programObj, name);
			return result;
		} END_MACH_OVERRIDE_PTR(get_uniform_location_ARB, obj->disp.get_uniform_location_ARB);

		if (err)
			log(LOG_ERR, "Failed to override get_uniform_location_ARB: %i", err);

		MACH_OVERRIDE(void,get_active_uniform_ARB,(GLIContext ctx, GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei *length, GLint *size, GLenum *type, GLcharARB *name), err ) {
			file_log("get_active_uniform_ARB called: ctx (GLIContext : %p) programObj (GLhandleARB : %p) index (GLuint : %u) maxLength (GLsizei : %i) length (GLsizei* : %p) size (GLint* : %p) type (GLenum* : %p) name (GLcharARB* : %p)\n", ctx, programObj, index, maxLength, length, size, type, name);
			return get_active_uniform_ARB_reenter(ctx, programObj, index, maxLength, length, size, type, name);
		} END_MACH_OVERRIDE_PTR(get_active_uniform_ARB, obj->disp.get_active_uniform_ARB);

		if (err)
			log(LOG_ERR, "Failed to override get_active_uniform_ARB: %i", err);

		MACH_OVERRIDE(void,get_uniformfv_ARB,(GLIContext ctx, GLhandleARB programObj, GLint location, GLfloat *params), err ) {
			file_log("get_uniformfv_ARB called: ctx (GLIContext : %p) programObj (GLhandleARB : %p) location (GLint : %i) params (GLfloat* : %p)\n", ctx, programObj, location, params);
			return get_uniformfv_ARB_reenter(ctx, programObj, location, params);
		} END_MACH_OVERRIDE_PTR(get_uniformfv_ARB, obj->disp.get_uniformfv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override get_uniformfv_ARB: %i", err);

		MACH_OVERRIDE(void,get_uniformiv_ARB,(GLIContext ctx, GLhandleARB programObj, GLint location, GLint *params), err ) {
			file_log("get_uniformiv_ARB called: ctx (GLIContext : %p) programObj (GLhandleARB : %p) location (GLint : %i) params (GLint* : %p)\n", ctx, programObj, location, params);
			return get_uniformiv_ARB_reenter(ctx, programObj, location, params);
		} END_MACH_OVERRIDE_PTR(get_uniformiv_ARB, obj->disp.get_uniformiv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override get_uniformiv_ARB: %i", err);

		MACH_OVERRIDE(void,get_shader_source_ARB,(GLIContext ctx, GLhandleARB obj, GLsizei maxLength, GLsizei *length, GLcharARB *source), err ) {
			file_log("get_shader_source_ARB called: ctx (GLIContext : %p) obj (GLhandleARB : %p) maxLength (GLsizei : %i) length (GLsizei* : %p) source (GLcharARB* : %p)\n", ctx, obj, maxLength, length, source);
			return get_shader_source_ARB_reenter(ctx, obj, maxLength, length, source);
		} END_MACH_OVERRIDE_PTR(get_shader_source_ARB, obj->disp.get_shader_source_ARB);

		if (err)
			log(LOG_ERR, "Failed to override get_shader_source_ARB: %i", err);

		MACH_OVERRIDE(void,bind_attrib_location_ARB,(GLIContext ctx, GLhandleARB programObj, GLuint index, const GLcharARB *name), err ) {
			file_log("bind_attrib_location_ARB called: ctx (GLIContext : %p) programObj (GLhandleARB : %p) index (GLuint : %u) name (const GLcharARB* : %p)\n", ctx, programObj, index, name);
			OpenGL::StateMachine::Shared.bind_attrib_location_ARB(ctx, programObj, index, name);
			return bind_attrib_location_ARB_reenter(ctx, programObj, index, name);
		} END_MACH_OVERRIDE_PTR(bind_attrib_location_ARB, obj->disp.bind_attrib_location_ARB);

		if (err)
			log(LOG_ERR, "Failed to override bind_attrib_location_ARB: %i", err);

		MACH_OVERRIDE(void,get_active_attrib_ARB,(GLIContext ctx, GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei *length, GLint *size, GLenum *type, GLcharARB *name), err ) {
			file_log("get_active_attrib_ARB called: ctx (GLIContext : %p) programObj (GLhandleARB : %p) index (GLuint : %u) maxLength (GLsizei : %i) length (GLsizei* : %p) size (GLint* : %p) type (GLenum* : %p) name (GLcharARB* : %p)\n", ctx, programObj, index, maxLength, length, size, type, name);
			return get_active_attrib_ARB_reenter(ctx, programObj, index, maxLength, length, size, type, name);
		} END_MACH_OVERRIDE_PTR(get_active_attrib_ARB, obj->disp.get_active_attrib_ARB);

		if (err)
			log(LOG_ERR, "Failed to override get_active_attrib_ARB: %i", err);

		MACH_OVERRIDE(GLint,get_attrib_location_ARB,(GLIContext ctx, GLhandleARB programObj, const GLcharARB *name), err ) {
			file_log("get_attrib_location_ARB called: ctx (GLIContext : %p) programObj (GLhandleARB : %p) name (const GLcharARB* : %p)\n", ctx, programObj, name);
			GLint result = get_attrib_location_ARB_reenter(ctx, programObj, name);
			return result;
		} END_MACH_OVERRIDE_PTR(get_attrib_location_ARB, obj->disp.get_attrib_location_ARB);

		if (err)
			log(LOG_ERR, "Failed to override get_attrib_location_ARB: %i", err);

		MACH_OVERRIDE(void,clamp_color_ARB,(GLIContext ctx, GLenum target, GLenum clamp), err ) {
			file_log("clamp_color_ARB called: ctx (GLIContext : %p) target (GLenum : %s) clamp (GLenum : %s)\n", ctx, GLenumToString(target).c_str(), GLenumToString(clamp).c_str());
			return clamp_color_ARB_reenter(ctx, target, clamp);
		} END_MACH_OVERRIDE_PTR(clamp_color_ARB, obj->disp.clamp_color_ARB);

		if (err)
			log(LOG_ERR, "Failed to override clamp_color_ARB: %i", err);

		MACH_OVERRIDE(void,gen_queries,(GLIContext ctx, GLsizei n, GLuint *ids), err ) {
			file_log("gen_queries called: ctx (GLIContext : %p) n (GLsizei : %i) ids (GLuint* : %p)\n", ctx, n, ids);
			return gen_queries_reenter(ctx, n, ids);
		} END_MACH_OVERRIDE_PTR(gen_queries, obj->disp.gen_queries);

		if (err)
			log(LOG_ERR, "Failed to override gen_queries: %i", err);

		MACH_OVERRIDE(void,delete_queries,(GLIContext ctx, GLsizei n, const GLuint *ids), err ) {
			file_log("delete_queries called: ctx (GLIContext : %p) n (GLsizei : %i) ids (const GLuint* : %p)\n", ctx, n, ids);
			return delete_queries_reenter(ctx, n, ids);
		} END_MACH_OVERRIDE_PTR(delete_queries, obj->disp.delete_queries);

		if (err)
			log(LOG_ERR, "Failed to override delete_queries: %i", err);

		MACH_OVERRIDE(GLboolean,is_query,(GLIContext ctx, GLuint id), err ) {
			file_log("is_query called: ctx (GLIContext : %p) id (GLuint : %u)\n", ctx, id);
			GLboolean result = is_query_reenter(ctx, id);
			return result;
		} END_MACH_OVERRIDE_PTR(is_query, obj->disp.is_query);

		if (err)
			log(LOG_ERR, "Failed to override is_query: %i", err);

		MACH_OVERRIDE(void,begin_query,(GLIContext ctx, GLenum target, GLuint id), err ) {
			file_log("begin_query called: ctx (GLIContext : %p) target (GLenum : %s) id (GLuint : %u)\n", ctx, GLenumToString(target).c_str(), id);
			return begin_query_reenter(ctx, target, id);
		} END_MACH_OVERRIDE_PTR(begin_query, obj->disp.begin_query);

		if (err)
			log(LOG_ERR, "Failed to override begin_query: %i", err);

		MACH_OVERRIDE(void,end_query,(GLIContext ctx, GLenum target), err ) {
			file_log("end_query called: ctx (GLIContext : %p) target (GLenum : %s)\n", ctx, GLenumToString(target).c_str());
			return end_query_reenter(ctx, target);
		} END_MACH_OVERRIDE_PTR(end_query, obj->disp.end_query);

		if (err)
			log(LOG_ERR, "Failed to override end_query: %i", err);

		MACH_OVERRIDE(void,get_queryiv,(GLIContext ctx, GLenum target, GLenum pname, GLint *params), err ) {
			file_log("get_queryiv called: ctx (GLIContext : %p) target (GLenum : %s) pname (GLenum : %s) params (GLint* : %p)\n", ctx, GLenumToString(target).c_str(), GLenumToString(pname).c_str(), params);
			return get_queryiv_reenter(ctx, target, pname, params);
		} END_MACH_OVERRIDE_PTR(get_queryiv, obj->disp.get_queryiv);

		if (err)
			log(LOG_ERR, "Failed to override get_queryiv: %i", err);

		MACH_OVERRIDE(void,get_query_objectiv,(GLIContext ctx, GLuint id, GLenum pname, GLint *params), err ) {
			file_log("get_query_objectiv called: ctx (GLIContext : %p) id (GLuint : %u) pname (GLenum : %s) params (GLint* : %p)\n", ctx, id, GLenumToString(pname).c_str(), params);
			return get_query_objectiv_reenter(ctx, id, pname, params);
		} END_MACH_OVERRIDE_PTR(get_query_objectiv, obj->disp.get_query_objectiv);

		if (err)
			log(LOG_ERR, "Failed to override get_query_objectiv: %i", err);

		MACH_OVERRIDE(void,get_query_objectuiv,(GLIContext ctx, GLuint id, GLenum pname, GLuint *params), err ) {
			file_log("get_query_objectuiv called: ctx (GLIContext : %p) id (GLuint : %u) pname (GLenum : %s) params (GLuint* : %p)\n", ctx, id, GLenumToString(pname).c_str(), params);
			return get_query_objectuiv_reenter(ctx, id, pname, params);
		} END_MACH_OVERRIDE_PTR(get_query_objectuiv, obj->disp.get_query_objectuiv);

		if (err)
			log(LOG_ERR, "Failed to override get_query_objectuiv: %i", err);

		MACH_OVERRIDE(void,bind_buffer,(GLIContext ctx, GLenum target, GLuint buffer), err ) {
			file_log("bind_buffer called: ctx (GLIContext : %p) target (GLenum : %s) buffer (GLuint : %u)\n", ctx, GLenumToString(target).c_str(), buffer);
			OpenGL::StateMachine::Shared.bind_buffer(ctx, target, buffer);
			return bind_buffer_reenter(ctx, target, buffer);
		} END_MACH_OVERRIDE_PTR(bind_buffer, obj->disp.bind_buffer);

		if (err)
			log(LOG_ERR, "Failed to override bind_buffer: %i", err);

		MACH_OVERRIDE(void,delete_buffers,(GLIContext ctx, GLsizei n, const GLuint *buffers), err ) {
			file_log("delete_buffers called: ctx (GLIContext : %p) n (GLsizei : %i) buffers (const GLuint* : %p)\n", ctx, n, buffers);
			return delete_buffers_reenter(ctx, n, buffers);
		} END_MACH_OVERRIDE_PTR(delete_buffers, obj->disp.delete_buffers);

		if (err)
			log(LOG_ERR, "Failed to override delete_buffers: %i", err);

		MACH_OVERRIDE(void,gen_buffers,(GLIContext ctx, GLsizei n, GLuint *buffers), err ) {
			file_log("gen_buffers called: ctx (GLIContext : %p) n (GLsizei : %i) buffers (GLuint* : %p)\n", ctx, n, buffers);
			return gen_buffers_reenter(ctx, n, buffers);
		} END_MACH_OVERRIDE_PTR(gen_buffers, obj->disp.gen_buffers);

		if (err)
			log(LOG_ERR, "Failed to override gen_buffers: %i", err);

		MACH_OVERRIDE(GLboolean,is_buffer,(GLIContext ctx, GLuint buffer), err ) {
			file_log("is_buffer called: ctx (GLIContext : %p) buffer (GLuint : %u)\n", ctx, buffer);
			GLboolean result = is_buffer_reenter(ctx, buffer);
			return result;
		} END_MACH_OVERRIDE_PTR(is_buffer, obj->disp.is_buffer);

		if (err)
			log(LOG_ERR, "Failed to override is_buffer: %i", err);

		MACH_OVERRIDE(void,buffer_data,(GLIContext ctx, GLenum target, GLsizeiptrARB size, const GLvoid *data, GLenum usage), err ) {
			file_log("buffer_data called: ctx (GLIContext : %p) target (GLenum : %s) size (GLsizeiptrARB : %p) data (const GLvoid* : %p) usage (GLenum : %s)\n", ctx, GLenumToString(target).c_str(), size, data, GLenumToString(usage).c_str());
			return buffer_data_reenter(ctx, target, size, data, usage);
		} END_MACH_OVERRIDE_PTR(buffer_data, obj->disp.buffer_data);

		if (err)
			log(LOG_ERR, "Failed to override buffer_data: %i", err);

		MACH_OVERRIDE(void,buffer_sub_data,(GLIContext ctx, GLenum target, GLintptrARB offset, GLsizeiptrARB size, const GLvoid *data), err ) {
			file_log("buffer_sub_data called: ctx (GLIContext : %p) target (GLenum : %s) offset (GLintptrARB : %p) size (GLsizeiptrARB : %p) data (const GLvoid* : %p)\n", ctx, GLenumToString(target).c_str(), offset, size, data);
			return buffer_sub_data_reenter(ctx, target, offset, size, data);
		} END_MACH_OVERRIDE_PTR(buffer_sub_data, obj->disp.buffer_sub_data);

		if (err)
			log(LOG_ERR, "Failed to override buffer_sub_data: %i", err);

		MACH_OVERRIDE(void,get_buffer_sub_data,(GLIContext ctx, GLenum target, GLintptrARB offset, GLsizeiptrARB size, GLvoid *data), err ) {
			file_log("get_buffer_sub_data called: ctx (GLIContext : %p) target (GLenum : %s) offset (GLintptrARB : %p) size (GLsizeiptrARB : %p) data (GLvoid* : %p)\n", ctx, GLenumToString(target).c_str(), offset, size, data);
			return get_buffer_sub_data_reenter(ctx, target, offset, size, data);
		} END_MACH_OVERRIDE_PTR(get_buffer_sub_data, obj->disp.get_buffer_sub_data);

		if (err)
			log(LOG_ERR, "Failed to override get_buffer_sub_data: %i", err);

		MACH_OVERRIDE(GLvoid,map_buffer,(GLIContext ctx, GLenum target, GLenum access), err ) {
			file_log("map_buffer called: ctx (GLIContext : %p) target (GLenum : %s) access (GLenum : %s)\n", ctx, GLenumToString(target).c_str(), GLenumToString(access).c_str());
			return map_buffer_reenter(ctx, target, access);
		} END_MACH_OVERRIDE_PTR(map_buffer, obj->disp.map_buffer);

		if (err)
			log(LOG_ERR, "Failed to override map_buffer: %i", err);

		MACH_OVERRIDE(GLboolean,unmap_buffer,(GLIContext ctx, GLenum target), err ) {
			file_log("unmap_buffer called: ctx (GLIContext : %p) target (GLenum : %s)\n", ctx, GLenumToString(target).c_str());
			GLboolean result = unmap_buffer_reenter(ctx, target);
			return result;
		} END_MACH_OVERRIDE_PTR(unmap_buffer, obj->disp.unmap_buffer);

		if (err)
			log(LOG_ERR, "Failed to override unmap_buffer: %i", err);

		MACH_OVERRIDE(void,get_buffer_parameteriv,(GLIContext ctx, GLenum target, GLenum pname, GLint *params), err ) {
			file_log("get_buffer_parameteriv called: ctx (GLIContext : %p) target (GLenum : %s) pname (GLenum : %s) params (GLint* : %p)\n", ctx, GLenumToString(target).c_str(), GLenumToString(pname).c_str(), params);
			return get_buffer_parameteriv_reenter(ctx, target, pname, params);
		} END_MACH_OVERRIDE_PTR(get_buffer_parameteriv, obj->disp.get_buffer_parameteriv);

		if (err)
			log(LOG_ERR, "Failed to override get_buffer_parameteriv: %i", err);

		MACH_OVERRIDE(void,get_buffer_pointerv,(GLIContext ctx, GLenum target, GLenum pname, GLvoid **params), err ) {
			file_log("get_buffer_pointerv called: ctx (GLIContext : %p) target (GLenum : %s) pname (GLenum : %s) params (GLvoid** : %p)\n", ctx, GLenumToString(target).c_str(), GLenumToString(pname).c_str(), params);
			return get_buffer_pointerv_reenter(ctx, target, pname, params);
		} END_MACH_OVERRIDE_PTR(get_buffer_pointerv, obj->disp.get_buffer_pointerv);

		if (err)
			log(LOG_ERR, "Failed to override get_buffer_pointerv: %i", err);

		MACH_OVERRIDE(void,depth_bounds_EXT,(GLIContext ctx, GLclampd zmin, GLclampd zmax), err ) {
			file_log("depth_bounds_EXT called: ctx (GLIContext : %p) zmin (GLclampd : %f) zmax (GLclampd : %f)\n", ctx, zmin, zmax);
			return depth_bounds_EXT_reenter(ctx, zmin, zmax);
		} END_MACH_OVERRIDE_PTR(depth_bounds_EXT, obj->disp.depth_bounds_EXT);

		if (err)
			log(LOG_ERR, "Failed to override depth_bounds_EXT: %i", err);

		MACH_OVERRIDE(void,draw_buffers_ARB,(GLIContext ctx, GLsizei n, const GLenum *bufs), err ) {
			file_log("draw_buffers_ARB called: ctx (GLIContext : %p) n (GLsizei : %i) bufs (const GLenum* : %p)\n", ctx, n, bufs);
			OpenGL::StateMachine::Shared.draw_buffers_ARB(ctx, n, bufs);
			return draw_buffers_ARB_reenter(ctx, n, bufs);
		} END_MACH_OVERRIDE_PTR(draw_buffers_ARB, obj->disp.draw_buffers_ARB);

		if (err)
			log(LOG_ERR, "Failed to override draw_buffers_ARB: %i", err);

		MACH_OVERRIDE(GLboolean,is_shader,(GLIContext ctx, GLuint shader), err ) {
			file_log("is_shader called: ctx (GLIContext : %p) shader (GLuint : %u)\n", ctx, shader);
			GLboolean result = is_shader_reenter(ctx, shader);
			return result;
		} END_MACH_OVERRIDE_PTR(is_shader, obj->disp.is_shader);

		if (err)
			log(LOG_ERR, "Failed to override is_shader: %i", err);

		MACH_OVERRIDE(GLboolean,is_program,(GLIContext ctx, GLuint program), err ) {
			file_log("is_program called: ctx (GLIContext : %p) program (GLuint : %u)\n", ctx, program);
			GLboolean result = is_program_reenter(ctx, program);
			return result;
		} END_MACH_OVERRIDE_PTR(is_program, obj->disp.is_program);

		if (err)
			log(LOG_ERR, "Failed to override is_program: %i", err);

		MACH_OVERRIDE(void,get_shaderiv,(GLIContext ctx, GLuint shader, GLenum pname, GLint *params), err ) {
			file_log("get_shaderiv called: ctx (GLIContext : %p) shader (GLuint : %u) pname (GLenum : %s) params (GLint* : %p)\n", ctx, shader, GLenumToString(pname).c_str(), params);
			return get_shaderiv_reenter(ctx, shader, pname, params);
		} END_MACH_OVERRIDE_PTR(get_shaderiv, obj->disp.get_shaderiv);

		if (err)
			log(LOG_ERR, "Failed to override get_shaderiv: %i", err);

		MACH_OVERRIDE(void,get_programiv,(GLIContext ctx, GLuint program, GLenum pname, GLint *params), err ) {
			file_log("get_programiv called: ctx (GLIContext : %p) program (GLuint : %u) pname (GLenum : %s) params (GLint* : %p)\n", ctx, program, GLenumToString(pname).c_str(), params);
			return get_programiv_reenter(ctx, program, pname, params);
		} END_MACH_OVERRIDE_PTR(get_programiv, obj->disp.get_programiv);

		if (err)
			log(LOG_ERR, "Failed to override get_programiv: %i", err);

		MACH_OVERRIDE(void,get_shader_info_log,(GLIContext ctx, GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog), err ) {
			file_log("get_shader_info_log called: ctx (GLIContext : %p) shader (GLuint : %u) bufSize (GLsizei : %i) length (GLsizei* : %p) infoLog (GLchar* : %p)\n", ctx, shader, bufSize, length, infoLog);
			return get_shader_info_log_reenter(ctx, shader, bufSize, length, infoLog);
		} END_MACH_OVERRIDE_PTR(get_shader_info_log, obj->disp.get_shader_info_log);

		if (err)
			log(LOG_ERR, "Failed to override get_shader_info_log: %i", err);

		MACH_OVERRIDE(void,get_program_info_log,(GLIContext ctx, GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog), err ) {
			file_log("get_program_info_log called: ctx (GLIContext : %p) program (GLuint : %u) bufSize (GLsizei : %i) length (GLsizei* : %p) infoLog (GLchar* : %p)\n", ctx, program, bufSize, length, infoLog);
			return get_program_info_log_reenter(ctx, program, bufSize, length, infoLog);
		} END_MACH_OVERRIDE_PTR(get_program_info_log, obj->disp.get_program_info_log);

		if (err)
			log(LOG_ERR, "Failed to override get_program_info_log: %i", err);

		MACH_OVERRIDE(void,stencil_func_separate,(GLIContext ctx, GLenum face, GLenum func, GLint ref, GLuint mask), err ) {
			file_log("stencil_func_separate called: ctx (GLIContext : %p) face (GLenum : %s) func (GLenum : %s) ref (GLint : %i) mask (GLuint : %u)\n", ctx, GLenumToString(face).c_str(), GLenumToString(func).c_str(), ref, mask);
			return stencil_func_separate_reenter(ctx, face, func, ref, mask);
		} END_MACH_OVERRIDE_PTR(stencil_func_separate, obj->disp.stencil_func_separate);

		if (err)
			log(LOG_ERR, "Failed to override stencil_func_separate: %i", err);

		MACH_OVERRIDE(void,stencil_mask_separate,(GLIContext ctx, GLenum face, GLuint mask), err ) {
			file_log("stencil_mask_separate called: ctx (GLIContext : %p) face (GLenum : %s) mask (GLuint : %u)\n", ctx, GLenumToString(face).c_str(), mask);
			return stencil_mask_separate_reenter(ctx, face, mask);
		} END_MACH_OVERRIDE_PTR(stencil_mask_separate, obj->disp.stencil_mask_separate);

		if (err)
			log(LOG_ERR, "Failed to override stencil_mask_separate: %i", err);

		MACH_OVERRIDE(void,multi_draw_element_array_APPLE,(GLIContext ctx, GLenum mode, const GLint *first, const GLsizei *count, GLsizei primcount), err ) {
			file_log("multi_draw_element_array_APPLE called: ctx (GLIContext : %p) mode (GLenum : %s) first (const GLint* : %p) count (const GLsizei* : %p) primcount (GLsizei : %i)\n", ctx, GLenumToString(mode).c_str(), first, count, primcount);
			OpenGL::StateMachine::Shared.multi_draw_element_array_APPLE(ctx, mode, first, count, primcount);
			return multi_draw_element_array_APPLE_reenter(ctx, mode, first, count, primcount);
		} END_MACH_OVERRIDE_PTR(multi_draw_element_array_APPLE, obj->disp.multi_draw_element_array_APPLE);

		if (err)
			log(LOG_ERR, "Failed to override multi_draw_element_array_APPLE: %i", err);

		MACH_OVERRIDE(void,multi_draw_range_element_array_APPLE,(GLIContext ctx, GLenum mode, GLuint start, GLuint end, const GLint *first, const GLsizei *count, GLsizei primcount), err ) {
			file_log("multi_draw_range_element_array_APPLE called: ctx (GLIContext : %p) mode (GLenum : %s) start (GLuint : %u) end (GLuint : %u) first (const GLint* : %p) count (const GLsizei* : %p) primcount (GLsizei : %i)\n", ctx, GLenumToString(mode).c_str(), start, end, first, count, primcount);
			OpenGL::StateMachine::Shared.multi_draw_range_element_array_APPLE(ctx, mode, start, end, first, count, primcount);
			return multi_draw_range_element_array_APPLE_reenter(ctx, mode, start, end, first, count, primcount);
		} END_MACH_OVERRIDE_PTR(multi_draw_range_element_array_APPLE, obj->disp.multi_draw_range_element_array_APPLE);

		if (err)
			log(LOG_ERR, "Failed to override multi_draw_range_element_array_APPLE: %i", err);

		MACH_OVERRIDE(GLboolean,is_renderbuffer_EXT,(GLIContext ctx, GLuint renderbuffer), err ) {
			file_log("is_renderbuffer_EXT called: ctx (GLIContext : %p) renderbuffer (GLuint : %u)\n", ctx, renderbuffer);
			GLboolean result = is_renderbuffer_EXT_reenter(ctx, renderbuffer);
			return result;
		} END_MACH_OVERRIDE_PTR(is_renderbuffer_EXT, obj->disp.is_renderbuffer_EXT);

		if (err)
			log(LOG_ERR, "Failed to override is_renderbuffer_EXT: %i", err);

		MACH_OVERRIDE(void,bind_renderbuffer_EXT,(GLIContext ctx, GLenum target, GLuint renderbuffer), err ) {
			file_log("bind_renderbuffer_EXT called: ctx (GLIContext : %p) target (GLenum : %s) renderbuffer (GLuint : %u)\n", ctx, GLenumToString(target).c_str(), renderbuffer);
			OpenGL::StateMachine::Shared.bind_renderbuffer_EXT(ctx, target, renderbuffer);
			return bind_renderbuffer_EXT_reenter(ctx, target, renderbuffer);
		} END_MACH_OVERRIDE_PTR(bind_renderbuffer_EXT, obj->disp.bind_renderbuffer_EXT);

		if (err)
			log(LOG_ERR, "Failed to override bind_renderbuffer_EXT: %i", err);

		MACH_OVERRIDE(void,delete_renderbuffers_EXT,(GLIContext ctx, GLsizei n, const GLuint *renderbuffers), err ) {
			file_log("delete_renderbuffers_EXT called: ctx (GLIContext : %p) n (GLsizei : %i) renderbuffers (const GLuint* : %p)\n", ctx, n, renderbuffers);
			return delete_renderbuffers_EXT_reenter(ctx, n, renderbuffers);
		} END_MACH_OVERRIDE_PTR(delete_renderbuffers_EXT, obj->disp.delete_renderbuffers_EXT);

		if (err)
			log(LOG_ERR, "Failed to override delete_renderbuffers_EXT: %i", err);

		MACH_OVERRIDE(void,gen_renderbuffers_EXT,(GLIContext ctx, GLsizei n, GLuint *renderbuffers), err ) {
			file_log("gen_renderbuffers_EXT called: ctx (GLIContext : %p) n (GLsizei : %i) renderbuffers (GLuint* : %p)\n", ctx, n, renderbuffers);
			return gen_renderbuffers_EXT_reenter(ctx, n, renderbuffers);
		} END_MACH_OVERRIDE_PTR(gen_renderbuffers_EXT, obj->disp.gen_renderbuffers_EXT);

		if (err)
			log(LOG_ERR, "Failed to override gen_renderbuffers_EXT: %i", err);

		MACH_OVERRIDE(void,renderbuffer_storage_EXT,(GLIContext ctx, GLenum target, GLenum internalformat, GLsizei width, GLsizei height), err ) {
			file_log("renderbuffer_storage_EXT called: ctx (GLIContext : %p) target (GLenum : %s) internalformat (GLenum : %s) width (GLsizei : %i) height (GLsizei : %i)\n", ctx, GLenumToString(target).c_str(), GLenumToString(internalformat).c_str(), width, height);
			return renderbuffer_storage_EXT_reenter(ctx, target, internalformat, width, height);
		} END_MACH_OVERRIDE_PTR(renderbuffer_storage_EXT, obj->disp.renderbuffer_storage_EXT);

		if (err)
			log(LOG_ERR, "Failed to override renderbuffer_storage_EXT: %i", err);

		MACH_OVERRIDE(void,get_renderbuffer_parameteriv_EXT,(GLIContext ctx, GLenum target, GLenum pname, GLint *params), err ) {
			file_log("get_renderbuffer_parameteriv_EXT called: ctx (GLIContext : %p) target (GLenum : %s) pname (GLenum : %s) params (GLint* : %p)\n", ctx, GLenumToString(target).c_str(), GLenumToString(pname).c_str(), params);
			return get_renderbuffer_parameteriv_EXT_reenter(ctx, target, pname, params);
		} END_MACH_OVERRIDE_PTR(get_renderbuffer_parameteriv_EXT, obj->disp.get_renderbuffer_parameteriv_EXT);

		if (err)
			log(LOG_ERR, "Failed to override get_renderbuffer_parameteriv_EXT: %i", err);

		MACH_OVERRIDE(GLboolean,is_framebuffer_EXT,(GLIContext ctx, GLuint framebuffer), err ) {
			file_log("is_framebuffer_EXT called: ctx (GLIContext : %p) framebuffer (GLuint : %u)\n", ctx, framebuffer);
			GLboolean result = is_framebuffer_EXT_reenter(ctx, framebuffer);
			return result;
		} END_MACH_OVERRIDE_PTR(is_framebuffer_EXT, obj->disp.is_framebuffer_EXT);

		if (err)
			log(LOG_ERR, "Failed to override is_framebuffer_EXT: %i", err);

		MACH_OVERRIDE(void,bind_framebuffer_EXT,(GLIContext ctx, GLenum target, GLuint framebuffer), err ) {
			file_log("bind_framebuffer_EXT called: ctx (GLIContext : %p) target (GLenum : %s) framebuffer (GLuint : %u)\n", ctx, GLenumToString(target).c_str(), framebuffer);
			OpenGL::StateMachine::Shared.bind_framebuffer_EXT(ctx, target, framebuffer);
			return bind_framebuffer_EXT_reenter(ctx, target, framebuffer);
		} END_MACH_OVERRIDE_PTR(bind_framebuffer_EXT, obj->disp.bind_framebuffer_EXT);

		if (err)
			log(LOG_ERR, "Failed to override bind_framebuffer_EXT: %i", err);

		MACH_OVERRIDE(void,delete_framebuffers_EXT,(GLIContext ctx, GLsizei n, const GLuint *framebuffers), err ) {
			file_log("delete_framebuffers_EXT called: ctx (GLIContext : %p) n (GLsizei : %i) framebuffers (const GLuint* : %p)\n", ctx, n, framebuffers);
			return delete_framebuffers_EXT_reenter(ctx, n, framebuffers);
		} END_MACH_OVERRIDE_PTR(delete_framebuffers_EXT, obj->disp.delete_framebuffers_EXT);

		if (err)
			log(LOG_ERR, "Failed to override delete_framebuffers_EXT: %i", err);

		MACH_OVERRIDE(void,gen_framebuffers_EXT,(GLIContext ctx, GLsizei n, GLuint *framebuffers), err ) {
			file_log("gen_framebuffers_EXT called: ctx (GLIContext : %p) n (GLsizei : %i) framebuffers (GLuint* : %p)\n", ctx, n, framebuffers);
			return gen_framebuffers_EXT_reenter(ctx, n, framebuffers);
		} END_MACH_OVERRIDE_PTR(gen_framebuffers_EXT, obj->disp.gen_framebuffers_EXT);

		if (err)
			log(LOG_ERR, "Failed to override gen_framebuffers_EXT: %i", err);

		MACH_OVERRIDE(GLenum,check_framebuffer_status_EXT,(GLIContext ctx, GLenum target), err ) {
			file_log("check_framebuffer_status_EXT called: ctx (GLIContext : %p) target (GLenum : %s)\n", ctx, GLenumToString(target).c_str());
			GLenum result = check_framebuffer_status_EXT_reenter(ctx, target);
			return result;
		} END_MACH_OVERRIDE_PTR(check_framebuffer_status_EXT, obj->disp.check_framebuffer_status_EXT);

		if (err)
			log(LOG_ERR, "Failed to override check_framebuffer_status_EXT: %i", err);

		MACH_OVERRIDE(void,framebuffer_texture1D_EXT,(GLIContext ctx, GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level), err ) {
			file_log("framebuffer_texture1D_EXT called: ctx (GLIContext : %p) target (GLenum : %s) attachment (GLenum : %s) textarget (GLenum : %s) texture (GLuint : %u) level (GLint : %i)\n", ctx, GLenumToString(target).c_str(), GLenumToString(attachment).c_str(), GLenumToString(textarget).c_str(), texture, level);
			return framebuffer_texture1D_EXT_reenter(ctx, target, attachment, textarget, texture, level);
		} END_MACH_OVERRIDE_PTR(framebuffer_texture1D_EXT, obj->disp.framebuffer_texture1D_EXT);

		if (err)
			log(LOG_ERR, "Failed to override framebuffer_texture1D_EXT: %i", err);

		MACH_OVERRIDE(void,framebuffer_texture2D_EXT,(GLIContext ctx, GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level), err ) {
			file_log("framebuffer_texture2D_EXT called: ctx (GLIContext : %p) target (GLenum : %s) attachment (GLenum : %s) textarget (GLenum : %s) texture (GLuint : %u) level (GLint : %i)\n", ctx, GLenumToString(target).c_str(), GLenumToString(attachment).c_str(), GLenumToString(textarget).c_str(), texture, level);
			return framebuffer_texture2D_EXT_reenter(ctx, target, attachment, textarget, texture, level);
		} END_MACH_OVERRIDE_PTR(framebuffer_texture2D_EXT, obj->disp.framebuffer_texture2D_EXT);

		if (err)
			log(LOG_ERR, "Failed to override framebuffer_texture2D_EXT: %i", err);

		MACH_OVERRIDE(void,framebuffer_texture3D_EXT,(GLIContext ctx, GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset), err ) {
			file_log("framebuffer_texture3D_EXT called: ctx (GLIContext : %p) target (GLenum : %s) attachment (GLenum : %s) textarget (GLenum : %s) texture (GLuint : %u) level (GLint : %i) zoffset (GLint : %i)\n", ctx, GLenumToString(target).c_str(), GLenumToString(attachment).c_str(), GLenumToString(textarget).c_str(), texture, level, zoffset);
			return framebuffer_texture3D_EXT_reenter(ctx, target, attachment, textarget, texture, level, zoffset);
		} END_MACH_OVERRIDE_PTR(framebuffer_texture3D_EXT, obj->disp.framebuffer_texture3D_EXT);

		if (err)
			log(LOG_ERR, "Failed to override framebuffer_texture3D_EXT: %i", err);

		MACH_OVERRIDE(void,framebuffer_renderbuffer_EXT,(GLIContext ctx, GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer), err ) {
			file_log("framebuffer_renderbuffer_EXT called: ctx (GLIContext : %p) target (GLenum : %s) attachment (GLenum : %s) renderbuffertarget (GLenum : %s) renderbuffer (GLuint : %u)\n", ctx, GLenumToString(target).c_str(), GLenumToString(attachment).c_str(), GLenumToString(renderbuffertarget).c_str(), renderbuffer);
			return framebuffer_renderbuffer_EXT_reenter(ctx, target, attachment, renderbuffertarget, renderbuffer);
		} END_MACH_OVERRIDE_PTR(framebuffer_renderbuffer_EXT, obj->disp.framebuffer_renderbuffer_EXT);

		if (err)
			log(LOG_ERR, "Failed to override framebuffer_renderbuffer_EXT: %i", err);

		MACH_OVERRIDE(void,get_framebuffer_attachment_parameteriv_EXT,(GLIContext ctx, GLenum target, GLenum attachment, GLenum pname, GLint *params), err ) {
			file_log("get_framebuffer_attachment_parameteriv_EXT called: ctx (GLIContext : %p) target (GLenum : %s) attachment (GLenum : %s) pname (GLenum : %s) params (GLint* : %p)\n", ctx, GLenumToString(target).c_str(), GLenumToString(attachment).c_str(), GLenumToString(pname).c_str(), params);
			return get_framebuffer_attachment_parameteriv_EXT_reenter(ctx, target, attachment, pname, params);
		} END_MACH_OVERRIDE_PTR(get_framebuffer_attachment_parameteriv_EXT, obj->disp.get_framebuffer_attachment_parameteriv_EXT);

		if (err)
			log(LOG_ERR, "Failed to override get_framebuffer_attachment_parameteriv_EXT: %i", err);

		MACH_OVERRIDE(void,generate_mipmap_EXT,(GLIContext ctx, GLenum target), err ) {
			file_log("generate_mipmap_EXT called: ctx (GLIContext : %p) target (GLenum : %s)\n", ctx, GLenumToString(target).c_str());
			return generate_mipmap_EXT_reenter(ctx, target);
		} END_MACH_OVERRIDE_PTR(generate_mipmap_EXT, obj->disp.generate_mipmap_EXT);

		if (err)
			log(LOG_ERR, "Failed to override generate_mipmap_EXT: %i", err);

		MACH_OVERRIDE(void,buffer_parameteri_APPLE,(GLIContext ctx, GLenum target, GLenum pname, GLint param), err ) {
			file_log("buffer_parameteri_APPLE called: ctx (GLIContext : %p) target (GLenum : %s) pname (GLenum : %s) param (GLint : %i)\n", ctx, GLenumToString(target).c_str(), GLenumToString(pname).c_str(), param);
			return buffer_parameteri_APPLE_reenter(ctx, target, pname, param);
		} END_MACH_OVERRIDE_PTR(buffer_parameteri_APPLE, obj->disp.buffer_parameteri_APPLE);

		if (err)
			log(LOG_ERR, "Failed to override buffer_parameteri_APPLE: %i", err);

		MACH_OVERRIDE(void,flush_mapped_buffer_range_APPLE,(GLIContext ctx, GLenum target, GLintptr offset, GLsizeiptr size), err ) {
			file_log("flush_mapped_buffer_range_APPLE called: ctx (GLIContext : %p) target (GLenum : %s) offset (GLintptr : %p) size (GLsizeiptr : %p)\n", ctx, GLenumToString(target).c_str(), offset, size);
			return flush_mapped_buffer_range_APPLE_reenter(ctx, target, offset, size);
		} END_MACH_OVERRIDE_PTR(flush_mapped_buffer_range_APPLE, obj->disp.flush_mapped_buffer_range_APPLE);

		if (err)
			log(LOG_ERR, "Failed to override flush_mapped_buffer_range_APPLE: %i", err);

		MACH_OVERRIDE(void,program_env_parameters4fv_EXT,(GLIContext ctx, GLenum target, GLuint index, GLsizei count, const GLfloat *params), err ) {
			file_log("program_env_parameters4fv_EXT called: ctx (GLIContext : %p) target (GLenum : %s) index (GLuint : %u) count (GLsizei : %i) params (const GLfloat* : %p)\n", ctx, GLenumToString(target).c_str(), index, count, params);
			return program_env_parameters4fv_EXT_reenter(ctx, target, index, count, params);
		} END_MACH_OVERRIDE_PTR(program_env_parameters4fv_EXT, obj->disp.program_env_parameters4fv_EXT);

		if (err)
			log(LOG_ERR, "Failed to override program_env_parameters4fv_EXT: %i", err);

		MACH_OVERRIDE(void,program_local_parameters4fv_EXT,(GLIContext ctx, GLenum target, GLuint index, GLsizei count, const GLfloat *params), err ) {
			file_log("program_local_parameters4fv_EXT called: ctx (GLIContext : %p) target (GLenum : %s) index (GLuint : %u) count (GLsizei : %i) params (const GLfloat* : %p)\n", ctx, GLenumToString(target).c_str(), index, count, params);
			return program_local_parameters4fv_EXT_reenter(ctx, target, index, count, params);
		} END_MACH_OVERRIDE_PTR(program_local_parameters4fv_EXT, obj->disp.program_local_parameters4fv_EXT);

		if (err)
			log(LOG_ERR, "Failed to override program_local_parameters4fv_EXT: %i", err);

		MACH_OVERRIDE(GLenum,object_purgeable_APPLE,(GLIContext ctx, GLenum objectType, GLuint name, GLenum option), err ) {
			file_log("object_purgeable_APPLE called: ctx (GLIContext : %p) objectType (GLenum : %s) name (GLuint : %u) option (GLenum : %s)\n", ctx, GLenumToString(objectType).c_str(), name, GLenumToString(option).c_str());
			GLenum result = object_purgeable_APPLE_reenter(ctx, objectType, name, option);
			return result;
		} END_MACH_OVERRIDE_PTR(object_purgeable_APPLE, obj->disp.object_purgeable_APPLE);

		if (err)
			log(LOG_ERR, "Failed to override object_purgeable_APPLE: %i", err);

		MACH_OVERRIDE(GLenum,object_unpurgeable_APPLE,(GLIContext ctx, GLenum objectType, GLuint name, GLenum option), err ) {
			file_log("object_unpurgeable_APPLE called: ctx (GLIContext : %p) objectType (GLenum : %s) name (GLuint : %u) option (GLenum : %s)\n", ctx, GLenumToString(objectType).c_str(), name, GLenumToString(option).c_str());
			GLenum result = object_unpurgeable_APPLE_reenter(ctx, objectType, name, option);
			return result;
		} END_MACH_OVERRIDE_PTR(object_unpurgeable_APPLE, obj->disp.object_unpurgeable_APPLE);

		if (err)
			log(LOG_ERR, "Failed to override object_unpurgeable_APPLE: %i", err);

		MACH_OVERRIDE(void,get_object_parameteriv_APPLE,(GLIContext ctx, GLenum objectType, GLuint name, GLenum pname, GLint* params), err ) {
			file_log("get_object_parameteriv_APPLE called: ctx (GLIContext : %p) objectType (GLenum : %s) name (GLuint : %u) pname (GLenum : %s) params (GLint* : %p)\n", ctx, GLenumToString(objectType).c_str(), name, GLenumToString(pname).c_str(), params);
			return get_object_parameteriv_APPLE_reenter(ctx, objectType, name, pname, params);
		} END_MACH_OVERRIDE_PTR(get_object_parameteriv_APPLE, obj->disp.get_object_parameteriv_APPLE);

		if (err)
			log(LOG_ERR, "Failed to override get_object_parameteriv_APPLE: %i", err);

		MACH_OVERRIDE(void,program_parameteri_EXT,(GLIContext ctx, GLuint program_name, GLenum pname, GLint value), err ) {
			file_log("program_parameteri_EXT called: ctx (GLIContext : %p) program_name (GLuint : %u) pname (GLenum : %s) value (GLint : %i)\n", ctx, program_name, GLenumToString(pname).c_str(), value);
			return program_parameteri_EXT_reenter(ctx, program_name, pname, value);
		} END_MACH_OVERRIDE_PTR(program_parameteri_EXT, obj->disp.program_parameteri_EXT);

		if (err)
			log(LOG_ERR, "Failed to override program_parameteri_EXT: %i", err);

		MACH_OVERRIDE(void,framebuffer_texture_EXT,(GLIContext ctx, GLenum target, GLenum attachment, GLuint texture, GLint level), err ) {
			file_log("framebuffer_texture_EXT called: ctx (GLIContext : %p) target (GLenum : %s) attachment (GLenum : %s) texture (GLuint : %u) level (GLint : %i)\n", ctx, GLenumToString(target).c_str(), GLenumToString(attachment).c_str(), texture, level);
			return framebuffer_texture_EXT_reenter(ctx, target, attachment, texture, level);
		} END_MACH_OVERRIDE_PTR(framebuffer_texture_EXT, obj->disp.framebuffer_texture_EXT);

		if (err)
			log(LOG_ERR, "Failed to override framebuffer_texture_EXT: %i", err);

		MACH_OVERRIDE(void,framebuffer_texture_layer_EXT,(GLIContext ctx, GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer), err ) {
			file_log("framebuffer_texture_layer_EXT called: ctx (GLIContext : %p) target (GLenum : %s) attachment (GLenum : %s) texture (GLuint : %u) level (GLint : %i) layer (GLint : %i)\n", ctx, GLenumToString(target).c_str(), GLenumToString(attachment).c_str(), texture, level, layer);
			return framebuffer_texture_layer_EXT_reenter(ctx, target, attachment, texture, level, layer);
		} END_MACH_OVERRIDE_PTR(framebuffer_texture_layer_EXT, obj->disp.framebuffer_texture_layer_EXT);

		if (err)
			log(LOG_ERR, "Failed to override framebuffer_texture_layer_EXT: %i", err);

		MACH_OVERRIDE(void,framebuffer_texture_face_EXT,(GLIContext ctx, GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face), err ) {
			file_log("framebuffer_texture_face_EXT called: ctx (GLIContext : %p) target (GLenum : %s) attachment (GLenum : %s) texture (GLuint : %u) level (GLint : %i) face (GLenum : %s)\n", ctx, GLenumToString(target).c_str(), GLenumToString(attachment).c_str(), texture, level, GLenumToString(face).c_str());
			return framebuffer_texture_face_EXT_reenter(ctx, target, attachment, texture, level, face);
		} END_MACH_OVERRIDE_PTR(framebuffer_texture_face_EXT, obj->disp.framebuffer_texture_face_EXT);

		if (err)
			log(LOG_ERR, "Failed to override framebuffer_texture_face_EXT: %i", err);

		MACH_OVERRIDE(void,bind_buffer_range_EXT,(GLIContext ctx, GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size), err ) {
			file_log("bind_buffer_range_EXT called: ctx (GLIContext : %p) target (GLenum : %s) index (GLuint : %u) buffer (GLuint : %u) offset (GLintptr : %p) size (GLsizeiptr : %p)\n", ctx, GLenumToString(target).c_str(), index, buffer, offset, size);
			OpenGL::StateMachine::Shared.bind_buffer_range_EXT(ctx, target, index, buffer, offset, size);
			return bind_buffer_range_EXT_reenter(ctx, target, index, buffer, offset, size);
		} END_MACH_OVERRIDE_PTR(bind_buffer_range_EXT, obj->disp.bind_buffer_range_EXT);

		if (err)
			log(LOG_ERR, "Failed to override bind_buffer_range_EXT: %i", err);

		MACH_OVERRIDE(void,bind_buffer_offset_EXT,(GLIContext ctx, GLenum target, GLuint index, GLuint buffer, GLintptr offset), err ) {
			file_log("bind_buffer_offset_EXT called: ctx (GLIContext : %p) target (GLenum : %s) index (GLuint : %u) buffer (GLuint : %u) offset (GLintptr : %p)\n", ctx, GLenumToString(target).c_str(), index, buffer, offset);
			OpenGL::StateMachine::Shared.bind_buffer_offset_EXT(ctx, target, index, buffer, offset);
			return bind_buffer_offset_EXT_reenter(ctx, target, index, buffer, offset);
		} END_MACH_OVERRIDE_PTR(bind_buffer_offset_EXT, obj->disp.bind_buffer_offset_EXT);

		if (err)
			log(LOG_ERR, "Failed to override bind_buffer_offset_EXT: %i", err);

		MACH_OVERRIDE(void,bind_buffer_base_EXT,(GLIContext ctx, GLenum target, GLuint index, GLuint buffer), err ) {
			file_log("bind_buffer_base_EXT called: ctx (GLIContext : %p) target (GLenum : %s) index (GLuint : %u) buffer (GLuint : %u)\n", ctx, GLenumToString(target).c_str(), index, buffer);
			OpenGL::StateMachine::Shared.bind_buffer_base_EXT(ctx, target, index, buffer);
			return bind_buffer_base_EXT_reenter(ctx, target, index, buffer);
		} END_MACH_OVERRIDE_PTR(bind_buffer_base_EXT, obj->disp.bind_buffer_base_EXT);

		if (err)
			log(LOG_ERR, "Failed to override bind_buffer_base_EXT: %i", err);

		MACH_OVERRIDE(void,begin_transform_feedback_EXT,(GLIContext ctx, GLenum primitiveMode), err ) {
			file_log("begin_transform_feedback_EXT called: ctx (GLIContext : %p) primitiveMode (GLenum : %s)\n", ctx, GLenumToString(primitiveMode).c_str());
			return begin_transform_feedback_EXT_reenter(ctx, primitiveMode);
		} END_MACH_OVERRIDE_PTR(begin_transform_feedback_EXT, obj->disp.begin_transform_feedback_EXT);

		if (err)
			log(LOG_ERR, "Failed to override begin_transform_feedback_EXT: %i", err);

		MACH_OVERRIDE(void,end_transform_feedback_EXT,(GLIContext ctx), err ) {
			file_log("end_transform_feedback_EXT called: ctx (GLIContext : %p)\n", ctx);
			return end_transform_feedback_EXT_reenter(ctx);
		} END_MACH_OVERRIDE_PTR(end_transform_feedback_EXT, obj->disp.end_transform_feedback_EXT);

		if (err)
			log(LOG_ERR, "Failed to override end_transform_feedback_EXT: %i", err);

		MACH_OVERRIDE(void,transform_feedback_varyings_EXT,(GLIContext ctx, GLuint program, GLsizei count, const GLchar* const *varyings, GLenum bufferMode), err ) {
			file_log("transform_feedback_varyings_EXT called: ctx (GLIContext : %p) program (GLuint : %u) count (GLsizei : %i) varyings (const GLchar*const* : %p) bufferMode (GLenum : %s)\n", ctx, program, count, varyings, GLenumToString(bufferMode).c_str());
			return transform_feedback_varyings_EXT_reenter(ctx, program, count, varyings, bufferMode);
		} END_MACH_OVERRIDE_PTR(transform_feedback_varyings_EXT, obj->disp.transform_feedback_varyings_EXT);

		if (err)
			log(LOG_ERR, "Failed to override transform_feedback_varyings_EXT: %i", err);

		MACH_OVERRIDE(void,get_transform_feedback_varying_EXT,(GLIContext ctx, GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name), err ) {
			file_log("get_transform_feedback_varying_EXT called: ctx (GLIContext : %p) program (GLuint : %u) index (GLuint : %u) bufSize (GLsizei : %i) length (GLsizei* : %p) size (GLsizei* : %p) type (GLenum* : %p) name (GLchar* : %p)\n", ctx, program, index, bufSize, length, size, type, name);
			return get_transform_feedback_varying_EXT_reenter(ctx, program, index, bufSize, length, size, type, name);
		} END_MACH_OVERRIDE_PTR(get_transform_feedback_varying_EXT, obj->disp.get_transform_feedback_varying_EXT);

		if (err)
			log(LOG_ERR, "Failed to override get_transform_feedback_varying_EXT: %i", err);

		MACH_OVERRIDE(void,get_integer_indexedv_EXT,(GLIContext ctx, GLenum param, GLuint index, GLint *values), err ) {
			file_log("get_integer_indexedv_EXT called: ctx (GLIContext : %p) param (GLenum : %s) index (GLuint : %u) values (GLint* : %p)\n", ctx, GLenumToString(param).c_str(), index, values);
			return get_integer_indexedv_EXT_reenter(ctx, param, index, values);
		} END_MACH_OVERRIDE_PTR(get_integer_indexedv_EXT, obj->disp.get_integer_indexedv_EXT);

		if (err)
			log(LOG_ERR, "Failed to override get_integer_indexedv_EXT: %i", err);

		MACH_OVERRIDE(void,get_boolean_indexedv_EXT,(GLIContext ctx, GLenum param, GLuint index, GLboolean *values), err ) {
			file_log("get_boolean_indexedv_EXT called: ctx (GLIContext : %p) param (GLenum : %s) index (GLuint : %u) values (GLboolean* : %p)\n", ctx, GLenumToString(param).c_str(), index, values);
			return get_boolean_indexedv_EXT_reenter(ctx, param, index, values);
		} END_MACH_OVERRIDE_PTR(get_boolean_indexedv_EXT, obj->disp.get_boolean_indexedv_EXT);

		if (err)
			log(LOG_ERR, "Failed to override get_boolean_indexedv_EXT: %i", err);

		MACH_OVERRIDE(void,uniform_buffer_EXT,(GLIContext ctx, GLuint program, GLint location, GLuint buffer), err ) {
			file_log("uniform_buffer_EXT called: ctx (GLIContext : %p) program (GLuint : %u) location (GLint : %i) buffer (GLuint : %u)\n", ctx, program, location, buffer);
			return uniform_buffer_EXT_reenter(ctx, program, location, buffer);
		} END_MACH_OVERRIDE_PTR(uniform_buffer_EXT, obj->disp.uniform_buffer_EXT);

		if (err)
			log(LOG_ERR, "Failed to override uniform_buffer_EXT: %i", err);

		MACH_OVERRIDE(GLint,get_uniform_buffer_size_EXT,(GLIContext ctx, GLuint program, GLint location), err ) {
			file_log("get_uniform_buffer_size_EXT called: ctx (GLIContext : %p) program (GLuint : %u) location (GLint : %i)\n", ctx, program, location);
			GLint result = get_uniform_buffer_size_EXT_reenter(ctx, program, location);
			return result;
		} END_MACH_OVERRIDE_PTR(get_uniform_buffer_size_EXT, obj->disp.get_uniform_buffer_size_EXT);

		if (err)
			log(LOG_ERR, "Failed to override get_uniform_buffer_size_EXT: %i", err);

		MACH_OVERRIDE(GLintptr,get_uniform_buffer_offset_EXT,(GLIContext ctx, GLuint program, GLint location), err ) {
			file_log("get_uniform_buffer_offset_EXT called: ctx (GLIContext : %p) program (GLuint : %u) location (GLint : %i)\n", ctx, program, location);
			GLintptr result = get_uniform_buffer_offset_EXT_reenter(ctx, program, location);
			return result;
		} END_MACH_OVERRIDE_PTR(get_uniform_buffer_offset_EXT, obj->disp.get_uniform_buffer_offset_EXT);

		if (err)
			log(LOG_ERR, "Failed to override get_uniform_buffer_offset_EXT: %i", err);

		MACH_OVERRIDE(void,clear_colorIi_EXT,(GLIContext ctx, GLint r, GLint g, GLint b, GLint a ), err ) {
			file_log("clear_colorIi_EXT called: ctx (GLIContext : %p) r (GLint : %i) g (GLint : %i) b (GLint : %i) a (GLint : %i)\n", ctx, r, g, b, a);
			return clear_colorIi_EXT_reenter(ctx, r, g, b, a);
		} END_MACH_OVERRIDE_PTR(clear_colorIi_EXT, obj->disp.clear_colorIi_EXT);

		if (err)
			log(LOG_ERR, "Failed to override clear_colorIi_EXT: %i", err);

		MACH_OVERRIDE(void,clear_colorIui_EXT,(GLIContext ctx, GLuint r, GLuint g, GLuint b, GLuint a ), err ) {
			file_log("clear_colorIui_EXT called: ctx (GLIContext : %p) r (GLuint : %u) g (GLuint : %u) b (GLuint : %u) a (GLuint : %u)\n", ctx, r, g, b, a);
			return clear_colorIui_EXT_reenter(ctx, r, g, b, a);
		} END_MACH_OVERRIDE_PTR(clear_colorIui_EXT, obj->disp.clear_colorIui_EXT);

		if (err)
			log(LOG_ERR, "Failed to override clear_colorIui_EXT: %i", err);

		MACH_OVERRIDE(void,tex_parameterIiv_EXT,(GLIContext ctx, GLenum target, GLenum pname, GLint *params ), err ) {
			file_log("tex_parameterIiv_EXT called: ctx (GLIContext : %p) target (GLenum : %s) pname (GLenum : %s) params (GLint* : %p)\n", ctx, GLenumToString(target).c_str(), GLenumToString(pname).c_str(), params);
			return tex_parameterIiv_EXT_reenter(ctx, target, pname, params);
		} END_MACH_OVERRIDE_PTR(tex_parameterIiv_EXT, obj->disp.tex_parameterIiv_EXT);

		if (err)
			log(LOG_ERR, "Failed to override tex_parameterIiv_EXT: %i", err);

		MACH_OVERRIDE(void,tex_parameterIuiv_EXT,(GLIContext ctx, GLenum target, GLenum pname, GLuint *params ), err ) {
			file_log("tex_parameterIuiv_EXT called: ctx (GLIContext : %p) target (GLenum : %s) pname (GLenum : %s) params (GLuint* : %p)\n", ctx, GLenumToString(target).c_str(), GLenumToString(pname).c_str(), params);
			return tex_parameterIuiv_EXT_reenter(ctx, target, pname, params);
		} END_MACH_OVERRIDE_PTR(tex_parameterIuiv_EXT, obj->disp.tex_parameterIuiv_EXT);

		if (err)
			log(LOG_ERR, "Failed to override tex_parameterIuiv_EXT: %i", err);

		MACH_OVERRIDE(void,get_tex_parameterIiv_EXT,(GLIContext ctx, GLenum target, GLenum pname, GLint *params), err ) {
			file_log("get_tex_parameterIiv_EXT called: ctx (GLIContext : %p) target (GLenum : %s) pname (GLenum : %s) params (GLint* : %p)\n", ctx, GLenumToString(target).c_str(), GLenumToString(pname).c_str(), params);
			return get_tex_parameterIiv_EXT_reenter(ctx, target, pname, params);
		} END_MACH_OVERRIDE_PTR(get_tex_parameterIiv_EXT, obj->disp.get_tex_parameterIiv_EXT);

		if (err)
			log(LOG_ERR, "Failed to override get_tex_parameterIiv_EXT: %i", err);

		MACH_OVERRIDE(void,get_tex_parameterIuiv_EXT,(GLIContext ctx, GLenum target, GLenum pname, GLuint *params), err ) {
			file_log("get_tex_parameterIuiv_EXT called: ctx (GLIContext : %p) target (GLenum : %s) pname (GLenum : %s) params (GLuint* : %p)\n", ctx, GLenumToString(target).c_str(), GLenumToString(pname).c_str(), params);
			return get_tex_parameterIuiv_EXT_reenter(ctx, target, pname, params);
		} END_MACH_OVERRIDE_PTR(get_tex_parameterIuiv_EXT, obj->disp.get_tex_parameterIuiv_EXT);

		if (err)
			log(LOG_ERR, "Failed to override get_tex_parameterIuiv_EXT: %i", err);

		MACH_OVERRIDE(void,vertex_attribI1i_EXT,(GLIContext ctx, GLuint index, GLint x), err ) {
			file_log("vertex_attribI1i_EXT called: ctx (GLIContext : %p) index (GLuint : %u) x (GLint : %i)\n", ctx, index, x);
			return vertex_attribI1i_EXT_reenter(ctx, index, x);
		} END_MACH_OVERRIDE_PTR(vertex_attribI1i_EXT, obj->disp.vertex_attribI1i_EXT);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attribI1i_EXT: %i", err);

		MACH_OVERRIDE(void,vertex_attribI2i_EXT,(GLIContext ctx, GLuint index, GLint x, GLint y), err ) {
			file_log("vertex_attribI2i_EXT called: ctx (GLIContext : %p) index (GLuint : %u) x (GLint : %i) y (GLint : %i)\n", ctx, index, x, y);
			return vertex_attribI2i_EXT_reenter(ctx, index, x, y);
		} END_MACH_OVERRIDE_PTR(vertex_attribI2i_EXT, obj->disp.vertex_attribI2i_EXT);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attribI2i_EXT: %i", err);

		MACH_OVERRIDE(void,vertex_attribI3i_EXT,(GLIContext ctx, GLuint index, GLint x, GLint y, GLint z), err ) {
			file_log("vertex_attribI3i_EXT called: ctx (GLIContext : %p) index (GLuint : %u) x (GLint : %i) y (GLint : %i) z (GLint : %i)\n", ctx, index, x, y, z);
			return vertex_attribI3i_EXT_reenter(ctx, index, x, y, z);
		} END_MACH_OVERRIDE_PTR(vertex_attribI3i_EXT, obj->disp.vertex_attribI3i_EXT);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attribI3i_EXT: %i", err);

		MACH_OVERRIDE(void,vertex_attribI4i_EXT,(GLIContext ctx, GLuint index, GLint x, GLint y, GLint z, GLint w), err ) {
			file_log("vertex_attribI4i_EXT called: ctx (GLIContext : %p) index (GLuint : %u) x (GLint : %i) y (GLint : %i) z (GLint : %i) w (GLint : %i)\n", ctx, index, x, y, z, w);
			return vertex_attribI4i_EXT_reenter(ctx, index, x, y, z, w);
		} END_MACH_OVERRIDE_PTR(vertex_attribI4i_EXT, obj->disp.vertex_attribI4i_EXT);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attribI4i_EXT: %i", err);

		MACH_OVERRIDE(void,vertex_attribI1ui_EXT,(GLIContext ctx, GLuint index, GLuint x), err ) {
			file_log("vertex_attribI1ui_EXT called: ctx (GLIContext : %p) index (GLuint : %u) x (GLuint : %u)\n", ctx, index, x);
			return vertex_attribI1ui_EXT_reenter(ctx, index, x);
		} END_MACH_OVERRIDE_PTR(vertex_attribI1ui_EXT, obj->disp.vertex_attribI1ui_EXT);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attribI1ui_EXT: %i", err);

		MACH_OVERRIDE(void,vertex_attribI2ui_EXT,(GLIContext ctx, GLuint index, GLuint x, GLuint y), err ) {
			file_log("vertex_attribI2ui_EXT called: ctx (GLIContext : %p) index (GLuint : %u) x (GLuint : %u) y (GLuint : %u)\n", ctx, index, x, y);
			return vertex_attribI2ui_EXT_reenter(ctx, index, x, y);
		} END_MACH_OVERRIDE_PTR(vertex_attribI2ui_EXT, obj->disp.vertex_attribI2ui_EXT);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attribI2ui_EXT: %i", err);

		MACH_OVERRIDE(void,vertex_attribI3ui_EXT,(GLIContext ctx, GLuint index, GLuint x, GLuint y, GLuint z), err ) {
			file_log("vertex_attribI3ui_EXT called: ctx (GLIContext : %p) index (GLuint : %u) x (GLuint : %u) y (GLuint : %u) z (GLuint : %u)\n", ctx, index, x, y, z);
			return vertex_attribI3ui_EXT_reenter(ctx, index, x, y, z);
		} END_MACH_OVERRIDE_PTR(vertex_attribI3ui_EXT, obj->disp.vertex_attribI3ui_EXT);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attribI3ui_EXT: %i", err);

		MACH_OVERRIDE(void,vertex_attribI4ui_EXT,(GLIContext ctx, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w), err ) {
			file_log("vertex_attribI4ui_EXT called: ctx (GLIContext : %p) index (GLuint : %u) x (GLuint : %u) y (GLuint : %u) z (GLuint : %u) w (GLuint : %u)\n", ctx, index, x, y, z, w);
			return vertex_attribI4ui_EXT_reenter(ctx, index, x, y, z, w);
		} END_MACH_OVERRIDE_PTR(vertex_attribI4ui_EXT, obj->disp.vertex_attribI4ui_EXT);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attribI4ui_EXT: %i", err);

		MACH_OVERRIDE(void,vertex_attribI1iv_EXT,(GLIContext ctx, GLuint index, const GLint *v), err ) {
			file_log("vertex_attribI1iv_EXT called: ctx (GLIContext : %p) index (GLuint : %u) v (const GLint* : %p)\n", ctx, index, v);
			return vertex_attribI1iv_EXT_reenter(ctx, index, v);
		} END_MACH_OVERRIDE_PTR(vertex_attribI1iv_EXT, obj->disp.vertex_attribI1iv_EXT);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attribI1iv_EXT: %i", err);

		MACH_OVERRIDE(void,vertex_attribI2iv_EXT,(GLIContext ctx, GLuint index, const GLint *v), err ) {
			file_log("vertex_attribI2iv_EXT called: ctx (GLIContext : %p) index (GLuint : %u) v (const GLint* : %p)\n", ctx, index, v);
			return vertex_attribI2iv_EXT_reenter(ctx, index, v);
		} END_MACH_OVERRIDE_PTR(vertex_attribI2iv_EXT, obj->disp.vertex_attribI2iv_EXT);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attribI2iv_EXT: %i", err);

		MACH_OVERRIDE(void,vertex_attribI3iv_EXT,(GLIContext ctx, GLuint index, const GLint *v), err ) {
			file_log("vertex_attribI3iv_EXT called: ctx (GLIContext : %p) index (GLuint : %u) v (const GLint* : %p)\n", ctx, index, v);
			return vertex_attribI3iv_EXT_reenter(ctx, index, v);
		} END_MACH_OVERRIDE_PTR(vertex_attribI3iv_EXT, obj->disp.vertex_attribI3iv_EXT);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attribI3iv_EXT: %i", err);

		MACH_OVERRIDE(void,vertex_attribI4iv_EXT,(GLIContext ctx, GLuint index, const GLint *v), err ) {
			file_log("vertex_attribI4iv_EXT called: ctx (GLIContext : %p) index (GLuint : %u) v (const GLint* : %p)\n", ctx, index, v);
			return vertex_attribI4iv_EXT_reenter(ctx, index, v);
		} END_MACH_OVERRIDE_PTR(vertex_attribI4iv_EXT, obj->disp.vertex_attribI4iv_EXT);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attribI4iv_EXT: %i", err);

		MACH_OVERRIDE(void,vertex_attribI1uiv_EXT,(GLIContext ctx, GLuint index, const GLuint *v), err ) {
			file_log("vertex_attribI1uiv_EXT called: ctx (GLIContext : %p) index (GLuint : %u) v (const GLuint* : %p)\n", ctx, index, v);
			return vertex_attribI1uiv_EXT_reenter(ctx, index, v);
		} END_MACH_OVERRIDE_PTR(vertex_attribI1uiv_EXT, obj->disp.vertex_attribI1uiv_EXT);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attribI1uiv_EXT: %i", err);

		MACH_OVERRIDE(void,vertex_attribI2uiv_EXT,(GLIContext ctx, GLuint index, const GLuint *v), err ) {
			file_log("vertex_attribI2uiv_EXT called: ctx (GLIContext : %p) index (GLuint : %u) v (const GLuint* : %p)\n", ctx, index, v);
			return vertex_attribI2uiv_EXT_reenter(ctx, index, v);
		} END_MACH_OVERRIDE_PTR(vertex_attribI2uiv_EXT, obj->disp.vertex_attribI2uiv_EXT);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attribI2uiv_EXT: %i", err);

		MACH_OVERRIDE(void,vertex_attribI3uiv_EXT,(GLIContext ctx, GLuint index, const GLuint *v), err ) {
			file_log("vertex_attribI3uiv_EXT called: ctx (GLIContext : %p) index (GLuint : %u) v (const GLuint* : %p)\n", ctx, index, v);
			return vertex_attribI3uiv_EXT_reenter(ctx, index, v);
		} END_MACH_OVERRIDE_PTR(vertex_attribI3uiv_EXT, obj->disp.vertex_attribI3uiv_EXT);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attribI3uiv_EXT: %i", err);

		MACH_OVERRIDE(void,vertex_attribI4uiv_EXT,(GLIContext ctx, GLuint index, const GLuint *v), err ) {
			file_log("vertex_attribI4uiv_EXT called: ctx (GLIContext : %p) index (GLuint : %u) v (const GLuint* : %p)\n", ctx, index, v);
			return vertex_attribI4uiv_EXT_reenter(ctx, index, v);
		} END_MACH_OVERRIDE_PTR(vertex_attribI4uiv_EXT, obj->disp.vertex_attribI4uiv_EXT);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attribI4uiv_EXT: %i", err);

		MACH_OVERRIDE(void,vertex_attribI4bv_EXT,(GLIContext ctx, GLuint index, const GLbyte *v), err ) {
			file_log("vertex_attribI4bv_EXT called: ctx (GLIContext : %p) index (GLuint : %u) v (const GLbyte* : %p)\n", ctx, index, v);
			return vertex_attribI4bv_EXT_reenter(ctx, index, v);
		} END_MACH_OVERRIDE_PTR(vertex_attribI4bv_EXT, obj->disp.vertex_attribI4bv_EXT);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attribI4bv_EXT: %i", err);

		MACH_OVERRIDE(void,vertex_attribI4sv_EXT,(GLIContext ctx, GLuint index, const GLshort *v), err ) {
			file_log("vertex_attribI4sv_EXT called: ctx (GLIContext : %p) index (GLuint : %u) v (const GLshort* : %p)\n", ctx, index, v);
			return vertex_attribI4sv_EXT_reenter(ctx, index, v);
		} END_MACH_OVERRIDE_PTR(vertex_attribI4sv_EXT, obj->disp.vertex_attribI4sv_EXT);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attribI4sv_EXT: %i", err);

		MACH_OVERRIDE(void,vertex_attribI4ubv_EXT,(GLIContext ctx, GLuint index, const GLubyte *v), err ) {
			file_log("vertex_attribI4ubv_EXT called: ctx (GLIContext : %p) index (GLuint : %u) v (const GLubyte* : %p)\n", ctx, index, v);
			return vertex_attribI4ubv_EXT_reenter(ctx, index, v);
		} END_MACH_OVERRIDE_PTR(vertex_attribI4ubv_EXT, obj->disp.vertex_attribI4ubv_EXT);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attribI4ubv_EXT: %i", err);

		MACH_OVERRIDE(void,vertex_attribI4usv_EXT,(GLIContext ctx, GLuint index, const GLushort *v), err ) {
			file_log("vertex_attribI4usv_EXT called: ctx (GLIContext : %p) index (GLuint : %u) v (const GLushort* : %p)\n", ctx, index, v);
			return vertex_attribI4usv_EXT_reenter(ctx, index, v);
		} END_MACH_OVERRIDE_PTR(vertex_attribI4usv_EXT, obj->disp.vertex_attribI4usv_EXT);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attribI4usv_EXT: %i", err);

		MACH_OVERRIDE(void,vertex_attribI_pointer_EXT,(GLIContext ctx, GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer), err ) {
			file_log("vertex_attribI_pointer_EXT called: ctx (GLIContext : %p) index (GLuint : %u) size (GLint : %i) type (GLenum : %s) stride (GLsizei : %i) pointer (const GLvoid* : %p)\n", ctx, index, size, GLenumToString(type).c_str(), stride, pointer);
			return vertex_attribI_pointer_EXT_reenter(ctx, index, size, type, stride, pointer);
		} END_MACH_OVERRIDE_PTR(vertex_attribI_pointer_EXT, obj->disp.vertex_attribI_pointer_EXT);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attribI_pointer_EXT: %i", err);

		MACH_OVERRIDE(void,get_vertex_attribIiv_EXT,(GLIContext ctx, GLuint index, GLenum pname, GLint *params), err ) {
			file_log("get_vertex_attribIiv_EXT called: ctx (GLIContext : %p) index (GLuint : %u) pname (GLenum : %s) params (GLint* : %p)\n", ctx, index, GLenumToString(pname).c_str(), params);
			return get_vertex_attribIiv_EXT_reenter(ctx, index, pname, params);
		} END_MACH_OVERRIDE_PTR(get_vertex_attribIiv_EXT, obj->disp.get_vertex_attribIiv_EXT);

		if (err)
			log(LOG_ERR, "Failed to override get_vertex_attribIiv_EXT: %i", err);

		MACH_OVERRIDE(void,get_vertex_attribIuiv_EXT,(GLIContext ctx, GLuint index, GLenum pname, GLuint *params), err ) {
			file_log("get_vertex_attribIuiv_EXT called: ctx (GLIContext : %p) index (GLuint : %u) pname (GLenum : %s) params (GLuint* : %p)\n", ctx, index, GLenumToString(pname).c_str(), params);
			return get_vertex_attribIuiv_EXT_reenter(ctx, index, pname, params);
		} END_MACH_OVERRIDE_PTR(get_vertex_attribIuiv_EXT, obj->disp.get_vertex_attribIuiv_EXT);

		if (err)
			log(LOG_ERR, "Failed to override get_vertex_attribIuiv_EXT: %i", err);

		MACH_OVERRIDE(void,uniform1ui_EXT,(GLIContext ctx, GLint location, GLuint v0), err ) {
			file_log("uniform1ui_EXT called: ctx (GLIContext : %p) location (GLint : %i) v0 (GLuint : %u)\n", ctx, location, v0);
			return uniform1ui_EXT_reenter(ctx, location, v0);
		} END_MACH_OVERRIDE_PTR(uniform1ui_EXT, obj->disp.uniform1ui_EXT);

		if (err)
			log(LOG_ERR, "Failed to override uniform1ui_EXT: %i", err);

		MACH_OVERRIDE(void,uniform2ui_EXT,(GLIContext ctx, GLint location, GLuint v0, GLuint v1), err ) {
			file_log("uniform2ui_EXT called: ctx (GLIContext : %p) location (GLint : %i) v0 (GLuint : %u) v1 (GLuint : %u)\n", ctx, location, v0, v1);
			return uniform2ui_EXT_reenter(ctx, location, v0, v1);
		} END_MACH_OVERRIDE_PTR(uniform2ui_EXT, obj->disp.uniform2ui_EXT);

		if (err)
			log(LOG_ERR, "Failed to override uniform2ui_EXT: %i", err);

		MACH_OVERRIDE(void,uniform3ui_EXT,(GLIContext ctx, GLint location, GLuint v0, GLuint v1, GLuint v2), err ) {
			file_log("uniform3ui_EXT called: ctx (GLIContext : %p) location (GLint : %i) v0 (GLuint : %u) v1 (GLuint : %u) v2 (GLuint : %u)\n", ctx, location, v0, v1, v2);
			return uniform3ui_EXT_reenter(ctx, location, v0, v1, v2);
		} END_MACH_OVERRIDE_PTR(uniform3ui_EXT, obj->disp.uniform3ui_EXT);

		if (err)
			log(LOG_ERR, "Failed to override uniform3ui_EXT: %i", err);

		MACH_OVERRIDE(void,uniform4ui_EXT,(GLIContext ctx, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3), err ) {
			file_log("uniform4ui_EXT called: ctx (GLIContext : %p) location (GLint : %i) v0 (GLuint : %u) v1 (GLuint : %u) v2 (GLuint : %u) v3 (GLuint : %u)\n", ctx, location, v0, v1, v2, v3);
			return uniform4ui_EXT_reenter(ctx, location, v0, v1, v2, v3);
		} END_MACH_OVERRIDE_PTR(uniform4ui_EXT, obj->disp.uniform4ui_EXT);

		if (err)
			log(LOG_ERR, "Failed to override uniform4ui_EXT: %i", err);

		MACH_OVERRIDE(void,uniform1uiv_EXT,(GLIContext ctx, GLint location, GLsizei count, const GLuint *value), err ) {
			file_log("uniform1uiv_EXT called: ctx (GLIContext : %p) location (GLint : %i) count (GLsizei : %i) value (const GLuint* : %p)\n", ctx, location, count, value);
			return uniform1uiv_EXT_reenter(ctx, location, count, value);
		} END_MACH_OVERRIDE_PTR(uniform1uiv_EXT, obj->disp.uniform1uiv_EXT);

		if (err)
			log(LOG_ERR, "Failed to override uniform1uiv_EXT: %i", err);

		MACH_OVERRIDE(void,uniform2uiv_EXT,(GLIContext ctx, GLint location, GLsizei count, const GLuint *value), err ) {
			file_log("uniform2uiv_EXT called: ctx (GLIContext : %p) location (GLint : %i) count (GLsizei : %i) value (const GLuint* : %p)\n", ctx, location, count, value);
			return uniform2uiv_EXT_reenter(ctx, location, count, value);
		} END_MACH_OVERRIDE_PTR(uniform2uiv_EXT, obj->disp.uniform2uiv_EXT);

		if (err)
			log(LOG_ERR, "Failed to override uniform2uiv_EXT: %i", err);

		MACH_OVERRIDE(void,uniform3uiv_EXT,(GLIContext ctx, GLint location, GLsizei count, const GLuint *value), err ) {
			file_log("uniform3uiv_EXT called: ctx (GLIContext : %p) location (GLint : %i) count (GLsizei : %i) value (const GLuint* : %p)\n", ctx, location, count, value);
			return uniform3uiv_EXT_reenter(ctx, location, count, value);
		} END_MACH_OVERRIDE_PTR(uniform3uiv_EXT, obj->disp.uniform3uiv_EXT);

		if (err)
			log(LOG_ERR, "Failed to override uniform3uiv_EXT: %i", err);

		MACH_OVERRIDE(void,uniform4uiv_EXT,(GLIContext ctx, GLint location, GLsizei count, const GLuint *value), err ) {
			file_log("uniform4uiv_EXT called: ctx (GLIContext : %p) location (GLint : %i) count (GLsizei : %i) value (const GLuint* : %p)\n", ctx, location, count, value);
			return uniform4uiv_EXT_reenter(ctx, location, count, value);
		} END_MACH_OVERRIDE_PTR(uniform4uiv_EXT, obj->disp.uniform4uiv_EXT);

		if (err)
			log(LOG_ERR, "Failed to override uniform4uiv_EXT: %i", err);

		MACH_OVERRIDE(void,get_uniformuiv_EXT,(GLIContext ctx, GLuint program, GLint location, GLuint *params), err ) {
			file_log("get_uniformuiv_EXT called: ctx (GLIContext : %p) program (GLuint : %u) location (GLint : %i) params (GLuint* : %p)\n", ctx, program, location, params);
			return get_uniformuiv_EXT_reenter(ctx, program, location, params);
		} END_MACH_OVERRIDE_PTR(get_uniformuiv_EXT, obj->disp.get_uniformuiv_EXT);

		if (err)
			log(LOG_ERR, "Failed to override get_uniformuiv_EXT: %i", err);

		MACH_OVERRIDE(void,bind_frag_data_location_EXT,(GLIContext ctx, GLuint program, GLuint colorNumber, const GLchar *name), err ) {
			file_log("bind_frag_data_location_EXT called: ctx (GLIContext : %p) program (GLuint : %u) colorNumber (GLuint : %u) name (const GLchar* : %p)\n", ctx, program, colorNumber, name);
			OpenGL::StateMachine::Shared.bind_frag_data_location_EXT(ctx, program, colorNumber, name);
			return bind_frag_data_location_EXT_reenter(ctx, program, colorNumber, name);
		} END_MACH_OVERRIDE_PTR(bind_frag_data_location_EXT, obj->disp.bind_frag_data_location_EXT);

		if (err)
			log(LOG_ERR, "Failed to override bind_frag_data_location_EXT: %i", err);

		MACH_OVERRIDE(GLint,get_frag_data_location_EXT,(GLIContext ctx, GLuint program, const GLchar *name), err ) {
			file_log("get_frag_data_location_EXT called: ctx (GLIContext : %p) program (GLuint : %u) name (const GLchar* : %p)\n", ctx, program, name);
			GLint result = get_frag_data_location_EXT_reenter(ctx, program, name);
			return result;
		} END_MACH_OVERRIDE_PTR(get_frag_data_location_EXT, obj->disp.get_frag_data_location_EXT);

		if (err)
			log(LOG_ERR, "Failed to override get_frag_data_location_EXT: %i", err);

		MACH_OVERRIDE(void,color_mask_indexed_EXT,(GLIContext ctx, GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a), err ) {
			file_log("color_mask_indexed_EXT called: ctx (GLIContext : %p) index (GLuint : %u) r (GLboolean : %i) g (GLboolean : %i) b (GLboolean : %i) a (GLboolean : %i)\n", ctx, index, r, g, b, a);
			return color_mask_indexed_EXT_reenter(ctx, index, r, g, b, a);
		} END_MACH_OVERRIDE_PTR(color_mask_indexed_EXT, obj->disp.color_mask_indexed_EXT);

		if (err)
			log(LOG_ERR, "Failed to override color_mask_indexed_EXT: %i", err);

		MACH_OVERRIDE(void,enable_indexed_EXT,(GLIContext ctx, GLenum target, GLuint index), err ) {
			file_log("enable_indexed_EXT called: ctx (GLIContext : %p) target (GLenum : %s) index (GLuint : %u)\n", ctx, GLenumToString(target).c_str(), index);
			return enable_indexed_EXT_reenter(ctx, target, index);
		} END_MACH_OVERRIDE_PTR(enable_indexed_EXT, obj->disp.enable_indexed_EXT);

		if (err)
			log(LOG_ERR, "Failed to override enable_indexed_EXT: %i", err);

		MACH_OVERRIDE(void,disable_indexed_EXT,(GLIContext ctx, GLenum target, GLuint index), err ) {
			file_log("disable_indexed_EXT called: ctx (GLIContext : %p) target (GLenum : %s) index (GLuint : %u)\n", ctx, GLenumToString(target).c_str(), index);
			return disable_indexed_EXT_reenter(ctx, target, index);
		} END_MACH_OVERRIDE_PTR(disable_indexed_EXT, obj->disp.disable_indexed_EXT);

		if (err)
			log(LOG_ERR, "Failed to override disable_indexed_EXT: %i", err);

		MACH_OVERRIDE(GLboolean,is_enabled_indexed_EXT,(GLIContext ctx, GLenum target, GLuint index), err ) {
			file_log("is_enabled_indexed_EXT called: ctx (GLIContext : %p) target (GLenum : %s) index (GLuint : %u)\n", ctx, GLenumToString(target).c_str(), index);
			GLboolean result = is_enabled_indexed_EXT_reenter(ctx, target, index);
			return result;
		} END_MACH_OVERRIDE_PTR(is_enabled_indexed_EXT, obj->disp.is_enabled_indexed_EXT);

		if (err)
			log(LOG_ERR, "Failed to override is_enabled_indexed_EXT: %i", err);

		MACH_OVERRIDE(void,uniform_matrix2x3fv,(GLIContext ctx, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value), err ) {
			file_log("uniform_matrix2x3fv called: ctx (GLIContext : %p) location (GLint : %i) count (GLsizei : %i) transpose (GLboolean : %i) value (const GLfloat* : %p)\n", ctx, location, count, transpose, value);
			return uniform_matrix2x3fv_reenter(ctx, location, count, transpose, value);
		} END_MACH_OVERRIDE_PTR(uniform_matrix2x3fv, obj->disp.uniform_matrix2x3fv);

		if (err)
			log(LOG_ERR, "Failed to override uniform_matrix2x3fv: %i", err);

		MACH_OVERRIDE(void,uniform_matrix3x2fv,(GLIContext ctx, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value), err ) {
			file_log("uniform_matrix3x2fv called: ctx (GLIContext : %p) location (GLint : %i) count (GLsizei : %i) transpose (GLboolean : %i) value (const GLfloat* : %p)\n", ctx, location, count, transpose, value);
			return uniform_matrix3x2fv_reenter(ctx, location, count, transpose, value);
		} END_MACH_OVERRIDE_PTR(uniform_matrix3x2fv, obj->disp.uniform_matrix3x2fv);

		if (err)
			log(LOG_ERR, "Failed to override uniform_matrix3x2fv: %i", err);

		MACH_OVERRIDE(void,uniform_matrix2x4fv,(GLIContext ctx, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value), err ) {
			file_log("uniform_matrix2x4fv called: ctx (GLIContext : %p) location (GLint : %i) count (GLsizei : %i) transpose (GLboolean : %i) value (const GLfloat* : %p)\n", ctx, location, count, transpose, value);
			return uniform_matrix2x4fv_reenter(ctx, location, count, transpose, value);
		} END_MACH_OVERRIDE_PTR(uniform_matrix2x4fv, obj->disp.uniform_matrix2x4fv);

		if (err)
			log(LOG_ERR, "Failed to override uniform_matrix2x4fv: %i", err);

		MACH_OVERRIDE(void,uniform_matrix4x2fv,(GLIContext ctx, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value), err ) {
			file_log("uniform_matrix4x2fv called: ctx (GLIContext : %p) location (GLint : %i) count (GLsizei : %i) transpose (GLboolean : %i) value (const GLfloat* : %p)\n", ctx, location, count, transpose, value);
			return uniform_matrix4x2fv_reenter(ctx, location, count, transpose, value);
		} END_MACH_OVERRIDE_PTR(uniform_matrix4x2fv, obj->disp.uniform_matrix4x2fv);

		if (err)
			log(LOG_ERR, "Failed to override uniform_matrix4x2fv: %i", err);

		MACH_OVERRIDE(void,uniform_matrix3x4fv,(GLIContext ctx, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value), err ) {
			file_log("uniform_matrix3x4fv called: ctx (GLIContext : %p) location (GLint : %i) count (GLsizei : %i) transpose (GLboolean : %i) value (const GLfloat* : %p)\n", ctx, location, count, transpose, value);
			return uniform_matrix3x4fv_reenter(ctx, location, count, transpose, value);
		} END_MACH_OVERRIDE_PTR(uniform_matrix3x4fv, obj->disp.uniform_matrix3x4fv);

		if (err)
			log(LOG_ERR, "Failed to override uniform_matrix3x4fv: %i", err);

		MACH_OVERRIDE(void,uniform_matrix4x3fv,(GLIContext ctx, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value), err ) {
			file_log("uniform_matrix4x3fv called: ctx (GLIContext : %p) location (GLint : %i) count (GLsizei : %i) transpose (GLboolean : %i) value (const GLfloat* : %p)\n", ctx, location, count, transpose, value);
			return uniform_matrix4x3fv_reenter(ctx, location, count, transpose, value);
		} END_MACH_OVERRIDE_PTR(uniform_matrix4x3fv, obj->disp.uniform_matrix4x3fv);

		if (err)
			log(LOG_ERR, "Failed to override uniform_matrix4x3fv: %i", err);

		MACH_OVERRIDE(void,blit_framebuffer_EXT,(GLIContext ctx, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter), err ) {
			file_log("blit_framebuffer_EXT called: ctx (GLIContext : %p) srcX0 (GLint : %i) srcY0 (GLint : %i) srcX1 (GLint : %i) srcY1 (GLint : %i) dstX0 (GLint : %i) dstY0 (GLint : %i) dstX1 (GLint : %i) dstY1 (GLint : %i) mask (GLbitfield : %u) filter (GLenum : %s)\n", ctx, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, GLenumToString(filter).c_str());
			return blit_framebuffer_EXT_reenter(ctx, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
		} END_MACH_OVERRIDE_PTR(blit_framebuffer_EXT, obj->disp.blit_framebuffer_EXT);

		if (err)
			log(LOG_ERR, "Failed to override blit_framebuffer_EXT: %i", err);

		MACH_OVERRIDE(void,renderbuffer_storage_multisample_EXT,(GLIContext ctx, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height), err ) {
			file_log("renderbuffer_storage_multisample_EXT called: ctx (GLIContext : %p) target (GLenum : %s) samples (GLsizei : %i) internalformat (GLenum : %s) width (GLsizei : %i) height (GLsizei : %i)\n", ctx, GLenumToString(target).c_str(), samples, GLenumToString(internalformat).c_str(), width, height);
			return renderbuffer_storage_multisample_EXT_reenter(ctx, target, samples, internalformat, width, height);
		} END_MACH_OVERRIDE_PTR(renderbuffer_storage_multisample_EXT, obj->disp.renderbuffer_storage_multisample_EXT);

		if (err)
			log(LOG_ERR, "Failed to override renderbuffer_storage_multisample_EXT: %i", err);

		MACH_OVERRIDE(void,begin_conditional_render_NV,(GLIContext ctx, GLuint id, GLenum mode), err ) {
			file_log("begin_conditional_render_NV called: ctx (GLIContext : %p) id (GLuint : %u) mode (GLenum : %s)\n", ctx, id, GLenumToString(mode).c_str());
			return begin_conditional_render_NV_reenter(ctx, id, mode);
		} END_MACH_OVERRIDE_PTR(begin_conditional_render_NV, obj->disp.begin_conditional_render_NV);

		if (err)
			log(LOG_ERR, "Failed to override begin_conditional_render_NV: %i", err);

		MACH_OVERRIDE(void,end_conditional_render_NV,(GLIContext ctx), err ) {
			file_log("end_conditional_render_NV called: ctx (GLIContext : %p)\n", ctx);
			return end_conditional_render_NV_reenter(ctx);
		} END_MACH_OVERRIDE_PTR(end_conditional_render_NV, obj->disp.end_conditional_render_NV);

		if (err)
			log(LOG_ERR, "Failed to override end_conditional_render_NV: %i", err);

		MACH_OVERRIDE(void,get_attached_shaders,(GLIContext ctx, GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders), err ) {
			file_log("get_attached_shaders called: ctx (GLIContext : %p) program (GLuint : %u) maxCount (GLsizei : %i) count (GLsizei* : %p) shaders (GLuint* : %p)\n", ctx, program, maxCount, count, shaders);
			return get_attached_shaders_reenter(ctx, program, maxCount, count, shaders);
		} END_MACH_OVERRIDE_PTR(get_attached_shaders, obj->disp.get_attached_shaders);

		if (err)
			log(LOG_ERR, "Failed to override get_attached_shaders: %i", err);

		MACH_OVERRIDE(void,provoking_vertex_EXT,(GLIContext ctx, GLenum mode), err ) {
			file_log("provoking_vertex_EXT called: ctx (GLIContext : %p) mode (GLenum : %s)\n", ctx, GLenumToString(mode).c_str());
			return provoking_vertex_EXT_reenter(ctx, mode);
		} END_MACH_OVERRIDE_PTR(provoking_vertex_EXT, obj->disp.provoking_vertex_EXT);

		if (err)
			log(LOG_ERR, "Failed to override provoking_vertex_EXT: %i", err);

		MACH_OVERRIDE(void,vertex_attrib_divisor,(GLIContext ctx, GLuint index, GLuint divisor), err ) {
			file_log("vertex_attrib_divisor called: ctx (GLIContext : %p) index (GLuint : %u) divisor (GLuint : %u)\n", ctx, index, divisor);
			return vertex_attrib_divisor_reenter(ctx, index, divisor);
		} END_MACH_OVERRIDE_PTR(vertex_attrib_divisor, obj->disp.vertex_attrib_divisor);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attrib_divisor: %i", err);

		MACH_OVERRIDE(void,draw_arrays_instanced,(GLIContext ctx, GLenum mode, GLint first, GLsizei count, GLsizei instancecount), err ) {
			file_log("draw_arrays_instanced called: ctx (GLIContext : %p) mode (GLenum : %s) first (GLint : %i) count (GLsizei : %i) instancecount (GLsizei : %i)\n", ctx, GLenumToString(mode).c_str(), first, count, instancecount);
			OpenGL::StateMachine::Shared.draw_arrays_instanced(ctx, mode, first, count, instancecount);
			return draw_arrays_instanced_reenter(ctx, mode, first, count, instancecount);
		} END_MACH_OVERRIDE_PTR(draw_arrays_instanced, obj->disp.draw_arrays_instanced);

		if (err)
			log(LOG_ERR, "Failed to override draw_arrays_instanced: %i", err);

		MACH_OVERRIDE(void,draw_elements_instanced,(GLIContext ctx, GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLsizei instancecount), err ) {
			file_log("draw_elements_instanced called: ctx (GLIContext : %p) mode (GLenum : %s) count (GLsizei : %i) type (GLenum : %s) indices (const GLvoid* : %p) instancecount (GLsizei : %i)\n", ctx, GLenumToString(mode).c_str(), count, GLenumToString(type).c_str(), indices, instancecount);
			OpenGL::StateMachine::Shared.draw_elements_instanced(ctx, mode, count, type, indices, instancecount);
			return draw_elements_instanced_reenter(ctx, mode, count, type, indices, instancecount);
		} END_MACH_OVERRIDE_PTR(draw_elements_instanced, obj->disp.draw_elements_instanced);

		if (err)
			log(LOG_ERR, "Failed to override draw_elements_instanced: %i", err);

		MACH_OVERRIDE(void,draw_elements_base_vertex,(GLIContext ctx, GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLint base_vertex), err ) {
			file_log("draw_elements_base_vertex called: ctx (GLIContext : %p) mode (GLenum : %s) count (GLsizei : %i) type (GLenum : %s) indices (const GLvoid* : %p) base_vertex (GLint : %i)\n", ctx, GLenumToString(mode).c_str(), count, GLenumToString(type).c_str(), indices, base_vertex);
			OpenGL::StateMachine::Shared.draw_elements_base_vertex(ctx, mode, count, type, indices, base_vertex);
			return draw_elements_base_vertex_reenter(ctx, mode, count, type, indices, base_vertex);
		} END_MACH_OVERRIDE_PTR(draw_elements_base_vertex, obj->disp.draw_elements_base_vertex);

		if (err)
			log(LOG_ERR, "Failed to override draw_elements_base_vertex: %i", err);

		MACH_OVERRIDE(void,draw_range_elements_base_vertex,(GLIContext ctx, GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices, GLint base_vertex), err ) {
			file_log("draw_range_elements_base_vertex called: ctx (GLIContext : %p) mode (GLenum : %s) start (GLuint : %u) end (GLuint : %u) count (GLsizei : %i) type (GLenum : %s) indices (const GLvoid* : %p) base_vertex (GLint : %i)\n", ctx, GLenumToString(mode).c_str(), start, end, count, GLenumToString(type).c_str(), indices, base_vertex);
			OpenGL::StateMachine::Shared.draw_range_elements_base_vertex(ctx, mode, start, end, count, type, indices, base_vertex);
			return draw_range_elements_base_vertex_reenter(ctx, mode, start, end, count, type, indices, base_vertex);
		} END_MACH_OVERRIDE_PTR(draw_range_elements_base_vertex, obj->disp.draw_range_elements_base_vertex);

		if (err)
			log(LOG_ERR, "Failed to override draw_range_elements_base_vertex: %i", err);

		MACH_OVERRIDE(void,draw_elements_instanced_base_vertex,(GLIContext ctx, GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLsizei instancecount, GLint base_vertex), err ) {
			file_log("draw_elements_instanced_base_vertex called: ctx (GLIContext : %p) mode (GLenum : %s) count (GLsizei : %i) type (GLenum : %s) indices (const GLvoid* : %p) instancecount (GLsizei : %i) base_vertex (GLint : %i)\n", ctx, GLenumToString(mode).c_str(), count, GLenumToString(type).c_str(), indices, instancecount, base_vertex);
			OpenGL::StateMachine::Shared.draw_elements_instanced_base_vertex(ctx, mode, count, type, indices, instancecount, base_vertex);
			return draw_elements_instanced_base_vertex_reenter(ctx, mode, count, type, indices, instancecount, base_vertex);
		} END_MACH_OVERRIDE_PTR(draw_elements_instanced_base_vertex, obj->disp.draw_elements_instanced_base_vertex);

		if (err)
			log(LOG_ERR, "Failed to override draw_elements_instanced_base_vertex: %i", err);

		MACH_OVERRIDE(void,multi_draw_elements_base_vertex,(GLIContext ctx, GLenum mode, const GLsizei *count, GLenum type, const GLvoid* const *indices, GLsizei drawcount, const GLint *base_vertex), err ) {
			file_log("multi_draw_elements_base_vertex called: ctx (GLIContext : %p) mode (GLenum : %s) count (const GLsizei* : %p) type (GLenum : %s) indices (const GLvoid*const* : %p) drawcount (GLsizei : %i) base_vertex (const GLint* : %p)\n", ctx, GLenumToString(mode).c_str(), count, GLenumToString(type).c_str(), indices, drawcount, base_vertex);
			OpenGL::StateMachine::Shared.multi_draw_elements_base_vertex(ctx, mode, count, type, indices, drawcount, base_vertex);
			return multi_draw_elements_base_vertex_reenter(ctx, mode, count, type, indices, drawcount, base_vertex);
		} END_MACH_OVERRIDE_PTR(multi_draw_elements_base_vertex, obj->disp.multi_draw_elements_base_vertex);

		if (err)
			log(LOG_ERR, "Failed to override multi_draw_elements_base_vertex: %i", err);

		MACH_OVERRIDE(void,bind_vertex_array_ARB,(GLIContext ctx, GLuint array), err ) {
			file_log("bind_vertex_array_ARB called: ctx (GLIContext : %p) array (GLuint : %u)\n", ctx, array);
			OpenGL::StateMachine::Shared.bind_vertex_array_ARB(ctx, array);
			return bind_vertex_array_ARB_reenter(ctx, array);
		} END_MACH_OVERRIDE_PTR(bind_vertex_array_ARB, obj->disp.bind_vertex_array_ARB);

		if (err)
			log(LOG_ERR, "Failed to override bind_vertex_array_ARB: %i", err);

		MACH_OVERRIDE(void,delete_vertex_arrays_ARB,(GLIContext ctx, GLsizei n, const GLuint *arrays), err ) {
			file_log("delete_vertex_arrays_ARB called: ctx (GLIContext : %p) n (GLsizei : %i) arrays (const GLuint* : %p)\n", ctx, n, arrays);
			return delete_vertex_arrays_ARB_reenter(ctx, n, arrays);
		} END_MACH_OVERRIDE_PTR(delete_vertex_arrays_ARB, obj->disp.delete_vertex_arrays_ARB);

		if (err)
			log(LOG_ERR, "Failed to override delete_vertex_arrays_ARB: %i", err);

		MACH_OVERRIDE(void,gen_vertex_arrays_ARB,(GLIContext ctx, GLsizei n, GLuint *arrays), err ) {
			file_log("gen_vertex_arrays_ARB called: ctx (GLIContext : %p) n (GLsizei : %i) arrays (GLuint* : %p)\n", ctx, n, arrays);
			return gen_vertex_arrays_ARB_reenter(ctx, n, arrays);
		} END_MACH_OVERRIDE_PTR(gen_vertex_arrays_ARB, obj->disp.gen_vertex_arrays_ARB);

		if (err)
			log(LOG_ERR, "Failed to override gen_vertex_arrays_ARB: %i", err);

		MACH_OVERRIDE(GLboolean,is_vertex_array_ARB,(GLIContext ctx, GLuint array), err ) {
			file_log("is_vertex_array_ARB called: ctx (GLIContext : %p) array (GLuint : %u)\n", ctx, array);
			GLboolean result = is_vertex_array_ARB_reenter(ctx, array);
			return result;
		} END_MACH_OVERRIDE_PTR(is_vertex_array_ARB, obj->disp.is_vertex_array_ARB);

		if (err)
			log(LOG_ERR, "Failed to override is_vertex_array_ARB: %i", err);

		MACH_OVERRIDE(void,point_size_pointer,(GLIContext ctx, GLenum type, GLsizei stride, const GLvoid *pointer), err ) {
			file_log("point_size_pointer called: ctx (GLIContext : %p) type (GLenum : %s) stride (GLsizei : %i) pointer (const GLvoid* : %p)\n", ctx, GLenumToString(type).c_str(), stride, pointer);
			return point_size_pointer_reenter(ctx, type, stride, pointer);
		} END_MACH_OVERRIDE_PTR(point_size_pointer, obj->disp.point_size_pointer);

		if (err)
			log(LOG_ERR, "Failed to override point_size_pointer: %i", err);

		MACH_OVERRIDE(void,vertex_point_sizef_APPLE,(GLIContext ctx, GLfloat size), err ) {
			file_log("vertex_point_sizef_APPLE called: ctx (GLIContext : %p) size (GLfloat : %f)\n", ctx, size);
			return vertex_point_sizef_APPLE_reenter(ctx, size);
		} END_MACH_OVERRIDE_PTR(vertex_point_sizef_APPLE, obj->disp.vertex_point_sizef_APPLE);

		if (err)
			log(LOG_ERR, "Failed to override vertex_point_sizef_APPLE: %i", err);

		MACH_OVERRIDE(void,clear_bufferiv,(GLIContext ctx, GLenum buffer, GLint drawbuffer, const GLint *value), err ) {
			file_log("clear_bufferiv called: ctx (GLIContext : %p) buffer (GLenum : %s) drawbuffer (GLint : %i) value (const GLint* : %p)\n", ctx, GLenumToString(buffer).c_str(), drawbuffer, value);
			return clear_bufferiv_reenter(ctx, buffer, drawbuffer, value);
		} END_MACH_OVERRIDE_PTR(clear_bufferiv, obj->disp.clear_bufferiv);

		if (err)
			log(LOG_ERR, "Failed to override clear_bufferiv: %i", err);

		MACH_OVERRIDE(void,clear_bufferuiv,(GLIContext ctx, GLenum buffer, GLint drawbuffer, const GLuint *value), err ) {
			file_log("clear_bufferuiv called: ctx (GLIContext : %p) buffer (GLenum : %s) drawbuffer (GLint : %i) value (const GLuint* : %p)\n", ctx, GLenumToString(buffer).c_str(), drawbuffer, value);
			return clear_bufferuiv_reenter(ctx, buffer, drawbuffer, value);
		} END_MACH_OVERRIDE_PTR(clear_bufferuiv, obj->disp.clear_bufferuiv);

		if (err)
			log(LOG_ERR, "Failed to override clear_bufferuiv: %i", err);

		MACH_OVERRIDE(void,clear_bufferfv,(GLIContext ctx, GLenum buffer, GLint drawbuffer, const GLfloat *value), err ) {
			file_log("clear_bufferfv called: ctx (GLIContext : %p) buffer (GLenum : %s) drawbuffer (GLint : %i) value (const GLfloat* : %p)\n", ctx, GLenumToString(buffer).c_str(), drawbuffer, value);
			return clear_bufferfv_reenter(ctx, buffer, drawbuffer, value);
		} END_MACH_OVERRIDE_PTR(clear_bufferfv, obj->disp.clear_bufferfv);

		if (err)
			log(LOG_ERR, "Failed to override clear_bufferfv: %i", err);

		MACH_OVERRIDE(void,clear_bufferfi,(GLIContext ctx, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil), err ) {
			file_log("clear_bufferfi called: ctx (GLIContext : %p) buffer (GLenum : %s) drawbuffer (GLint : %i) depth (GLfloat : %f) stencil (GLint : %i)\n", ctx, GLenumToString(buffer).c_str(), drawbuffer, depth, stencil);
			return clear_bufferfi_reenter(ctx, buffer, drawbuffer, depth, stencil);
		} END_MACH_OVERRIDE_PTR(clear_bufferfi, obj->disp.clear_bufferfi);

		if (err)
			log(LOG_ERR, "Failed to override clear_bufferfi: %i", err);

		MACH_OVERRIDE(GLsync,fence_sync,(GLIContext ctx, GLenum condition, GLbitfield flags), err ) {
			file_log("fence_sync called: ctx (GLIContext : %p) condition (GLenum : %s) flags (GLbitfield : %u)\n", ctx, GLenumToString(condition).c_str(), flags);
			GLsync result = fence_sync_reenter(ctx, condition, flags);
			return result;
		} END_MACH_OVERRIDE_PTR(fence_sync, obj->disp.fence_sync);

		if (err)
			log(LOG_ERR, "Failed to override fence_sync: %i", err);

		MACH_OVERRIDE(GLboolean,is_sync,(GLIContext ctx, GLsync sync), err ) {
			file_log("is_sync called: ctx (GLIContext : %p) sync (GLsync : %p)\n", ctx, sync);
			GLboolean result = is_sync_reenter(ctx, sync);
			return result;
		} END_MACH_OVERRIDE_PTR(is_sync, obj->disp.is_sync);

		if (err)
			log(LOG_ERR, "Failed to override is_sync: %i", err);

		MACH_OVERRIDE(void,delete_sync,(GLIContext ctx, GLsync sync), err ) {
			file_log("delete_sync called: ctx (GLIContext : %p) sync (GLsync : %p)\n", ctx, sync);
			return delete_sync_reenter(ctx, sync);
		} END_MACH_OVERRIDE_PTR(delete_sync, obj->disp.delete_sync);

		if (err)
			log(LOG_ERR, "Failed to override delete_sync: %i", err);

		MACH_OVERRIDE(GLenum,client_wait_sync,(GLIContext ctx, GLsync sync, GLbitfield flags, GLuint64 timeout), err ) {
			file_log("client_wait_sync called: ctx (GLIContext : %p) sync (GLsync : %p) flags (GLbitfield : %u) timeout (GLuint64 : %u)\n", ctx, sync, flags, timeout);
			GLenum result = client_wait_sync_reenter(ctx, sync, flags, timeout);
			return result;
		} END_MACH_OVERRIDE_PTR(client_wait_sync, obj->disp.client_wait_sync);

		if (err)
			log(LOG_ERR, "Failed to override client_wait_sync: %i", err);

		MACH_OVERRIDE(void,wait_sync,(GLIContext ctx, GLsync sync, GLbitfield flags, GLuint64 timeout), err ) {
			file_log("wait_sync called: ctx (GLIContext : %p) sync (GLsync : %p) flags (GLbitfield : %u) timeout (GLuint64 : %u)\n", ctx, sync, flags, timeout);
			return wait_sync_reenter(ctx, sync, flags, timeout);
		} END_MACH_OVERRIDE_PTR(wait_sync, obj->disp.wait_sync);

		if (err)
			log(LOG_ERR, "Failed to override wait_sync: %i", err);

		MACH_OVERRIDE(void,get_integer64v_sync,(GLIContext ctx, GLenum pname, GLint64 *params), err ) {
			file_log("get_integer64v_sync called: ctx (GLIContext : %p) pname (GLenum : %s) params (GLint64* : %p)\n", ctx, GLenumToString(pname).c_str(), params);
			return get_integer64v_sync_reenter(ctx, pname, params);
		} END_MACH_OVERRIDE_PTR(get_integer64v_sync, obj->disp.get_integer64v_sync);

		if (err)
			log(LOG_ERR, "Failed to override get_integer64v_sync: %i", err);

		MACH_OVERRIDE(void,get_synciv,(GLIContext ctx, GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values), err ) {
			file_log("get_synciv called: ctx (GLIContext : %p) sync (GLsync : %p) pname (GLenum : %s) bufSize (GLsizei : %i) length (GLsizei* : %p) values (GLint* : %p)\n", ctx, sync, GLenumToString(pname).c_str(), bufSize, length, values);
			return get_synciv_reenter(ctx, sync, pname, bufSize, length, values);
		} END_MACH_OVERRIDE_PTR(get_synciv, obj->disp.get_synciv);

		if (err)
			log(LOG_ERR, "Failed to override get_synciv: %i", err);

		MACH_OVERRIDE(void,tex_image2D_multisample,(GLIContext ctx, GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations), err ) {
			file_log("tex_image2D_multisample called: ctx (GLIContext : %p) target (GLenum : %s) samples (GLsizei : %i) internalformat (GLint : %i) width (GLsizei : %i) height (GLsizei : %i) fixedsamplelocations (GLboolean : %i)\n", ctx, GLenumToString(target).c_str(), samples, internalformat, width, height, fixedsamplelocations);
			return tex_image2D_multisample_reenter(ctx, target, samples, internalformat, width, height, fixedsamplelocations);
		} END_MACH_OVERRIDE_PTR(tex_image2D_multisample, obj->disp.tex_image2D_multisample);

		if (err)
			log(LOG_ERR, "Failed to override tex_image2D_multisample: %i", err);

		MACH_OVERRIDE(void,tex_image3D_multisample,(GLIContext ctx, GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations), err ) {
			file_log("tex_image3D_multisample called: ctx (GLIContext : %p) target (GLenum : %s) samples (GLsizei : %i) internalformat (GLint : %i) width (GLsizei : %i) height (GLsizei : %i) depth (GLsizei : %i) fixedsamplelocations (GLboolean : %i)\n", ctx, GLenumToString(target).c_str(), samples, internalformat, width, height, depth, fixedsamplelocations);
			return tex_image3D_multisample_reenter(ctx, target, samples, internalformat, width, height, depth, fixedsamplelocations);
		} END_MACH_OVERRIDE_PTR(tex_image3D_multisample, obj->disp.tex_image3D_multisample);

		if (err)
			log(LOG_ERR, "Failed to override tex_image3D_multisample: %i", err);

		MACH_OVERRIDE(void,get_multisamplefv,(GLIContext ctx, GLenum pname, GLuint index, GLfloat *val), err ) {
			file_log("get_multisamplefv called: ctx (GLIContext : %p) pname (GLenum : %s) index (GLuint : %u) val (GLfloat* : %p)\n", ctx, GLenumToString(pname).c_str(), index, val);
			return get_multisamplefv_reenter(ctx, pname, index, val);
		} END_MACH_OVERRIDE_PTR(get_multisamplefv, obj->disp.get_multisamplefv);

		if (err)
			log(LOG_ERR, "Failed to override get_multisamplefv: %i", err);

		MACH_OVERRIDE(void,sample_maski,(GLIContext ctx, GLuint index, GLbitfield mask), err ) {
			file_log("sample_maski called: ctx (GLIContext : %p) index (GLuint : %u) mask (GLbitfield : %u)\n", ctx, index, mask);
			return sample_maski_reenter(ctx, index, mask);
		} END_MACH_OVERRIDE_PTR(sample_maski, obj->disp.sample_maski);

		if (err)
			log(LOG_ERR, "Failed to override sample_maski: %i", err);

		MACH_OVERRIDE(void,tex_buffer,(GLIContext ctx, GLenum target, GLenum internalformat, GLuint buffer), err ) {
			file_log("tex_buffer called: ctx (GLIContext : %p) target (GLenum : %s) internalformat (GLenum : %s) buffer (GLuint : %u)\n", ctx, GLenumToString(target).c_str(), GLenumToString(internalformat).c_str(), buffer);
			return tex_buffer_reenter(ctx, target, internalformat, buffer);
		} END_MACH_OVERRIDE_PTR(tex_buffer, obj->disp.tex_buffer);

		if (err)
			log(LOG_ERR, "Failed to override tex_buffer: %i", err);

		MACH_OVERRIDE(void,copy_buffer_sub_data,(GLIContext ctx, GLenum readtarget, GLenum writetarget, GLintptr readoffset, GLintptr writeoffset, GLsizeiptr size), err ) {
			file_log("copy_buffer_sub_data called: ctx (GLIContext : %p) readtarget (GLenum : %s) writetarget (GLenum : %s) readoffset (GLintptr : %p) writeoffset (GLintptr : %p) size (GLsizeiptr : %p)\n", ctx, GLenumToString(readtarget).c_str(), GLenumToString(writetarget).c_str(), readoffset, writeoffset, size);
			return copy_buffer_sub_data_reenter(ctx, readtarget, writetarget, readoffset, writeoffset, size);
		} END_MACH_OVERRIDE_PTR(copy_buffer_sub_data, obj->disp.copy_buffer_sub_data);

		if (err)
			log(LOG_ERR, "Failed to override copy_buffer_sub_data: %i", err);

		MACH_OVERRIDE(void,primitive_restart_index,(GLIContext ctx, GLuint index), err ) {
			file_log("primitive_restart_index called: ctx (GLIContext : %p) index (GLuint : %u)\n", ctx, index);
			return primitive_restart_index_reenter(ctx, index);
		} END_MACH_OVERRIDE_PTR(primitive_restart_index, obj->disp.primitive_restart_index);

		if (err)
			log(LOG_ERR, "Failed to override primitive_restart_index: %i", err);

		MACH_OVERRIDE(void,get_query_objecti64v,(GLIContext ctx, GLuint id, GLenum pname, GLint64EXT *params), err ) {
			file_log("get_query_objecti64v called: ctx (GLIContext : %p) id (GLuint : %u) pname (GLenum : %s) params (GLint64EXT* : %p)\n", ctx, id, GLenumToString(pname).c_str(), params);
			return get_query_objecti64v_reenter(ctx, id, pname, params);
		} END_MACH_OVERRIDE_PTR(get_query_objecti64v, obj->disp.get_query_objecti64v);

		if (err)
			log(LOG_ERR, "Failed to override get_query_objecti64v: %i", err);

		MACH_OVERRIDE(void,get_query_objectui64v,(GLIContext ctx, GLuint id, GLenum pname, GLuint64EXT *params), err ) {
			file_log("get_query_objectui64v called: ctx (GLIContext : %p) id (GLuint : %u) pname (GLenum : %s) params (GLuint64EXT* : %p)\n", ctx, id, GLenumToString(pname).c_str(), params);
			return get_query_objectui64v_reenter(ctx, id, pname, params);
		} END_MACH_OVERRIDE_PTR(get_query_objectui64v, obj->disp.get_query_objectui64v);

		if (err)
			log(LOG_ERR, "Failed to override get_query_objectui64v: %i", err);

		MACH_OVERRIDE(GLvoid,map_buffer_range,(GLIContext ctx, GLenum target, GLintptr offset, GLsizeiptr length, GLenum access), err ) {
			file_log("map_buffer_range called: ctx (GLIContext : %p) target (GLenum : %s) offset (GLintptr : %p) length (GLsizeiptr : %p) access (GLenum : %s)\n", ctx, GLenumToString(target).c_str(), offset, length, GLenumToString(access).c_str());
			return map_buffer_range_reenter(ctx, target, offset, length, access);
		} END_MACH_OVERRIDE_PTR(map_buffer_range, obj->disp.map_buffer_range);

		if (err)
			log(LOG_ERR, "Failed to override map_buffer_range: %i", err);

		MACH_OVERRIDE(void,flush_mapped_buffer_range,(GLIContext ctx, GLenum target, GLintptr offset, GLsizeiptr length), err ) {
			file_log("flush_mapped_buffer_range called: ctx (GLIContext : %p) target (GLenum : %s) offset (GLintptr : %p) length (GLsizeiptr : %p)\n", ctx, GLenumToString(target).c_str(), offset, length);
			return flush_mapped_buffer_range_reenter(ctx, target, offset, length);
		} END_MACH_OVERRIDE_PTR(flush_mapped_buffer_range, obj->disp.flush_mapped_buffer_range);

		if (err)
			log(LOG_ERR, "Failed to override flush_mapped_buffer_range: %i", err);

		MACH_OVERRIDE(void,query_counter,(GLIContext ctx, GLuint id, GLenum target), err ) {
			file_log("query_counter called: ctx (GLIContext : %p) id (GLuint : %u) target (GLenum : %s)\n", ctx, id, GLenumToString(target).c_str());
			return query_counter_reenter(ctx, id, target);
		} END_MACH_OVERRIDE_PTR(query_counter, obj->disp.query_counter);

		if (err)
			log(LOG_ERR, "Failed to override query_counter: %i", err);

		MACH_OVERRIDE(void,get_integer64i_v,(GLIContext ctx, GLenum target, GLuint index, GLint64 *data), err ) {
			file_log("get_integer64i_v called: ctx (GLIContext : %p) target (GLenum : %s) index (GLuint : %u) data (GLint64* : %p)\n", ctx, GLenumToString(target).c_str(), index, data);
			return get_integer64i_v_reenter(ctx, target, index, data);
		} END_MACH_OVERRIDE_PTR(get_integer64i_v, obj->disp.get_integer64i_v);

		if (err)
			log(LOG_ERR, "Failed to override get_integer64i_v: %i", err);

		MACH_OVERRIDE(void,get_buffer_parameteri64v,(GLIContext ctx, GLenum target, GLenum pname, GLint64 *params), err ) {
			file_log("get_buffer_parameteri64v called: ctx (GLIContext : %p) target (GLenum : %s) pname (GLenum : %s) params (GLint64* : %p)\n", ctx, GLenumToString(target).c_str(), GLenumToString(pname).c_str(), params);
			return get_buffer_parameteri64v_reenter(ctx, target, pname, params);
		} END_MACH_OVERRIDE_PTR(get_buffer_parameteri64v, obj->disp.get_buffer_parameteri64v);

		if (err)
			log(LOG_ERR, "Failed to override get_buffer_parameteri64v: %i", err);

		MACH_OVERRIDE(void,gen_samplers,(GLIContext ctx, GLsizei count, GLuint *samplers), err ) {
			file_log("gen_samplers called: ctx (GLIContext : %p) count (GLsizei : %i) samplers (GLuint* : %p)\n", ctx, count, samplers);
			return gen_samplers_reenter(ctx, count, samplers);
		} END_MACH_OVERRIDE_PTR(gen_samplers, obj->disp.gen_samplers);

		if (err)
			log(LOG_ERR, "Failed to override gen_samplers: %i", err);

		MACH_OVERRIDE(void,delete_samplers,(GLIContext ctx, GLsizei count, const GLuint *samplers), err ) {
			file_log("delete_samplers called: ctx (GLIContext : %p) count (GLsizei : %i) samplers (const GLuint* : %p)\n", ctx, count, samplers);
			return delete_samplers_reenter(ctx, count, samplers);
		} END_MACH_OVERRIDE_PTR(delete_samplers, obj->disp.delete_samplers);

		if (err)
			log(LOG_ERR, "Failed to override delete_samplers: %i", err);

		MACH_OVERRIDE(GLboolean,is_sampler,(GLIContext ctx, GLuint sampler), err ) {
			file_log("is_sampler called: ctx (GLIContext : %p) sampler (GLuint : %u)\n", ctx, sampler);
			GLboolean result = is_sampler_reenter(ctx, sampler);
			return result;
		} END_MACH_OVERRIDE_PTR(is_sampler, obj->disp.is_sampler);

		if (err)
			log(LOG_ERR, "Failed to override is_sampler: %i", err);

		MACH_OVERRIDE(void,bind_sampler,(GLIContext ctx, GLuint unit, GLuint sampler), err ) {
			file_log("bind_sampler called: ctx (GLIContext : %p) unit (GLuint : %u) sampler (GLuint : %u)\n", ctx, unit, sampler);
			OpenGL::StateMachine::Shared.bind_sampler(ctx, unit, sampler);
			return bind_sampler_reenter(ctx, unit, sampler);
		} END_MACH_OVERRIDE_PTR(bind_sampler, obj->disp.bind_sampler);

		if (err)
			log(LOG_ERR, "Failed to override bind_sampler: %i", err);

		MACH_OVERRIDE(void,sampler_parameteri,(GLIContext ctx, GLuint sampler, GLenum pname, GLint param), err ) {
			file_log("sampler_parameteri called: ctx (GLIContext : %p) sampler (GLuint : %u) pname (GLenum : %s) param (GLint : %i)\n", ctx, sampler, GLenumToString(pname).c_str(), param);
			return sampler_parameteri_reenter(ctx, sampler, pname, param);
		} END_MACH_OVERRIDE_PTR(sampler_parameteri, obj->disp.sampler_parameteri);

		if (err)
			log(LOG_ERR, "Failed to override sampler_parameteri: %i", err);

		MACH_OVERRIDE(void,sampler_parameteriv,(GLIContext ctx, GLuint sampler, GLenum pname, const GLint *param), err ) {
			file_log("sampler_parameteriv called: ctx (GLIContext : %p) sampler (GLuint : %u) pname (GLenum : %s) param (const GLint* : %p)\n", ctx, sampler, GLenumToString(pname).c_str(), param);
			return sampler_parameteriv_reenter(ctx, sampler, pname, param);
		} END_MACH_OVERRIDE_PTR(sampler_parameteriv, obj->disp.sampler_parameteriv);

		if (err)
			log(LOG_ERR, "Failed to override sampler_parameteriv: %i", err);

		MACH_OVERRIDE(void,sampler_parameterf,(GLIContext ctx, GLuint sampler, GLenum pname, GLfloat param), err ) {
			file_log("sampler_parameterf called: ctx (GLIContext : %p) sampler (GLuint : %u) pname (GLenum : %s) param (GLfloat : %f)\n", ctx, sampler, GLenumToString(pname).c_str(), param);
			return sampler_parameterf_reenter(ctx, sampler, pname, param);
		} END_MACH_OVERRIDE_PTR(sampler_parameterf, obj->disp.sampler_parameterf);

		if (err)
			log(LOG_ERR, "Failed to override sampler_parameterf: %i", err);

		MACH_OVERRIDE(void,sampler_parameterfv,(GLIContext ctx, GLuint sampler, GLenum pname, const GLfloat *param), err ) {
			file_log("sampler_parameterfv called: ctx (GLIContext : %p) sampler (GLuint : %u) pname (GLenum : %s) param (const GLfloat* : %p)\n", ctx, sampler, GLenumToString(pname).c_str(), param);
			return sampler_parameterfv_reenter(ctx, sampler, pname, param);
		} END_MACH_OVERRIDE_PTR(sampler_parameterfv, obj->disp.sampler_parameterfv);

		if (err)
			log(LOG_ERR, "Failed to override sampler_parameterfv: %i", err);

		MACH_OVERRIDE(void,sampler_parameterIiv,(GLIContext ctx, GLuint sampler, GLenum pname, const GLint *param), err ) {
			file_log("sampler_parameterIiv called: ctx (GLIContext : %p) sampler (GLuint : %u) pname (GLenum : %s) param (const GLint* : %p)\n", ctx, sampler, GLenumToString(pname).c_str(), param);
			return sampler_parameterIiv_reenter(ctx, sampler, pname, param);
		} END_MACH_OVERRIDE_PTR(sampler_parameterIiv, obj->disp.sampler_parameterIiv);

		if (err)
			log(LOG_ERR, "Failed to override sampler_parameterIiv: %i", err);

		MACH_OVERRIDE(void,sampler_parameterIuiv,(GLIContext ctx, GLuint sampler, GLenum pname, const GLuint *param), err ) {
			file_log("sampler_parameterIuiv called: ctx (GLIContext : %p) sampler (GLuint : %u) pname (GLenum : %s) param (const GLuint* : %p)\n", ctx, sampler, GLenumToString(pname).c_str(), param);
			return sampler_parameterIuiv_reenter(ctx, sampler, pname, param);
		} END_MACH_OVERRIDE_PTR(sampler_parameterIuiv, obj->disp.sampler_parameterIuiv);

		if (err)
			log(LOG_ERR, "Failed to override sampler_parameterIuiv: %i", err);

		MACH_OVERRIDE(void,get_sampler_parameteriv,(GLIContext ctx, GLuint sampler, GLenum pname, GLint *params), err ) {
			file_log("get_sampler_parameteriv called: ctx (GLIContext : %p) sampler (GLuint : %u) pname (GLenum : %s) params (GLint* : %p)\n", ctx, sampler, GLenumToString(pname).c_str(), params);
			return get_sampler_parameteriv_reenter(ctx, sampler, pname, params);
		} END_MACH_OVERRIDE_PTR(get_sampler_parameteriv, obj->disp.get_sampler_parameteriv);

		if (err)
			log(LOG_ERR, "Failed to override get_sampler_parameteriv: %i", err);

		MACH_OVERRIDE(void,get_sampler_parameterfv,(GLIContext ctx, GLuint sampler, GLenum pname, GLfloat *params), err ) {
			file_log("get_sampler_parameterfv called: ctx (GLIContext : %p) sampler (GLuint : %u) pname (GLenum : %s) params (GLfloat* : %p)\n", ctx, sampler, GLenumToString(pname).c_str(), params);
			return get_sampler_parameterfv_reenter(ctx, sampler, pname, params);
		} END_MACH_OVERRIDE_PTR(get_sampler_parameterfv, obj->disp.get_sampler_parameterfv);

		if (err)
			log(LOG_ERR, "Failed to override get_sampler_parameterfv: %i", err);

		MACH_OVERRIDE(void,get_sampler_parameterIiv,(GLIContext ctx, GLuint sampler, GLenum pname, GLint *params), err ) {
			file_log("get_sampler_parameterIiv called: ctx (GLIContext : %p) sampler (GLuint : %u) pname (GLenum : %s) params (GLint* : %p)\n", ctx, sampler, GLenumToString(pname).c_str(), params);
			return get_sampler_parameterIiv_reenter(ctx, sampler, pname, params);
		} END_MACH_OVERRIDE_PTR(get_sampler_parameterIiv, obj->disp.get_sampler_parameterIiv);

		if (err)
			log(LOG_ERR, "Failed to override get_sampler_parameterIiv: %i", err);

		MACH_OVERRIDE(void,get_sampler_parameterIuiv,(GLIContext ctx, GLuint sampler, GLenum pname, GLuint *params), err ) {
			file_log("get_sampler_parameterIuiv called: ctx (GLIContext : %p) sampler (GLuint : %u) pname (GLenum : %s) params (GLuint* : %p)\n", ctx, sampler, GLenumToString(pname).c_str(), params);
			return get_sampler_parameterIuiv_reenter(ctx, sampler, pname, params);
		} END_MACH_OVERRIDE_PTR(get_sampler_parameterIuiv, obj->disp.get_sampler_parameterIuiv);

		if (err)
			log(LOG_ERR, "Failed to override get_sampler_parameterIuiv: %i", err);

		MACH_OVERRIDE(void,label_object_EXT,(GLIContext ctx, GLenum type, GLuint object, GLsizei length, const GLchar *label), err ) {
			file_log("label_object_EXT called: ctx (GLIContext : %p) type (GLenum : %s) object (GLuint : %u) length (GLsizei : %i) label (const GLchar* : %p)\n", ctx, GLenumToString(type).c_str(), object, length, label);
			return label_object_EXT_reenter(ctx, type, object, length, label);
		} END_MACH_OVERRIDE_PTR(label_object_EXT, obj->disp.label_object_EXT);

		if (err)
			log(LOG_ERR, "Failed to override label_object_EXT: %i", err);

		MACH_OVERRIDE(void,get_object_label_EXT,(GLIContext ctx, GLenum type, GLuint object, GLsizei bufSize, GLsizei *length, GLchar *label), err ) {
			file_log("get_object_label_EXT called: ctx (GLIContext : %p) type (GLenum : %s) object (GLuint : %u) bufSize (GLsizei : %i) length (GLsizei* : %p) label (GLchar* : %p)\n", ctx, GLenumToString(type).c_str(), object, bufSize, length, label);
			return get_object_label_EXT_reenter(ctx, type, object, bufSize, length, label);
		} END_MACH_OVERRIDE_PTR(get_object_label_EXT, obj->disp.get_object_label_EXT);

		if (err)
			log(LOG_ERR, "Failed to override get_object_label_EXT: %i", err);

		MACH_OVERRIDE(void,insert_event_marker_EXT,(GLIContext ctx, GLsizei length, const GLchar *marker), err ) {
			file_log("insert_event_marker_EXT called: ctx (GLIContext : %p) length (GLsizei : %i) marker (const GLchar* : %p)\n", ctx, length, marker);
			return insert_event_marker_EXT_reenter(ctx, length, marker);
		} END_MACH_OVERRIDE_PTR(insert_event_marker_EXT, obj->disp.insert_event_marker_EXT);

		if (err)
			log(LOG_ERR, "Failed to override insert_event_marker_EXT: %i", err);

		MACH_OVERRIDE(void,push_group_marker_EXT,(GLIContext ctx, GLsizei length, const GLchar *marker), err ) {
			file_log("push_group_marker_EXT called: ctx (GLIContext : %p) length (GLsizei : %i) marker (const GLchar* : %p)\n", ctx, length, marker);
			return push_group_marker_EXT_reenter(ctx, length, marker);
		} END_MACH_OVERRIDE_PTR(push_group_marker_EXT, obj->disp.push_group_marker_EXT);

		if (err)
			log(LOG_ERR, "Failed to override push_group_marker_EXT: %i", err);

		MACH_OVERRIDE(void,pop_group_marker_EXT,(GLIContext ctx), err ) {
			file_log("pop_group_marker_EXT called: ctx (GLIContext : %p)\n", ctx);
			return pop_group_marker_EXT_reenter(ctx);
		} END_MACH_OVERRIDE_PTR(pop_group_marker_EXT, obj->disp.pop_group_marker_EXT);

		if (err)
			log(LOG_ERR, "Failed to override pop_group_marker_EXT: %i", err);

		MACH_OVERRIDE(void,use_program_stages,(GLIContext ctx, GLuint pipeline, GLbitfield stages, GLuint program), err ) {
			file_log("use_program_stages called: ctx (GLIContext : %p) pipeline (GLuint : %u) stages (GLbitfield : %u) program (GLuint : %u)\n", ctx, pipeline, stages, program);
			return use_program_stages_reenter(ctx, pipeline, stages, program);
		} END_MACH_OVERRIDE_PTR(use_program_stages, obj->disp.use_program_stages);

		if (err)
			log(LOG_ERR, "Failed to override use_program_stages: %i", err);

		MACH_OVERRIDE(void,active_shader_program,(GLIContext ctx, GLuint pipeline, GLuint program), err ) {
			file_log("active_shader_program called: ctx (GLIContext : %p) pipeline (GLuint : %u) program (GLuint : %u)\n", ctx, pipeline, program);
			OpenGL::StateMachine::Shared.active_shader_program(ctx, pipeline, program);
			return active_shader_program_reenter(ctx, pipeline, program);
		} END_MACH_OVERRIDE_PTR(active_shader_program, obj->disp.active_shader_program);

		if (err)
			log(LOG_ERR, "Failed to override active_shader_program: %i", err);

		MACH_OVERRIDE(GLuint,create_shader_programv,(GLIContext ctx, GLenum type, GLsizei count, const GLchar* const *strings), err ) {
			file_log("create_shader_programv called: ctx (GLIContext : %p) type (GLenum : %s) count (GLsizei : %i) strings (const GLchar*const* : %p)\n", ctx, GLenumToString(type).c_str(), count, strings);
			GLuint result = create_shader_programv_reenter(ctx, type, count, strings);
			return result;
		} END_MACH_OVERRIDE_PTR(create_shader_programv, obj->disp.create_shader_programv);

		if (err)
			log(LOG_ERR, "Failed to override create_shader_programv: %i", err);

		MACH_OVERRIDE(void,bind_program_pipeline,(GLIContext ctx, GLuint pipeline), err ) {
			file_log("bind_program_pipeline called: ctx (GLIContext : %p) pipeline (GLuint : %u)\n", ctx, pipeline);
			OpenGL::StateMachine::Shared.bind_program_pipeline(ctx, pipeline);
			return bind_program_pipeline_reenter(ctx, pipeline);
		} END_MACH_OVERRIDE_PTR(bind_program_pipeline, obj->disp.bind_program_pipeline);

		if (err)
			log(LOG_ERR, "Failed to override bind_program_pipeline: %i", err);

		MACH_OVERRIDE(void,delete_program_pipelines,(GLIContext ctx, GLsizei n, const GLuint *pipelines), err ) {
			file_log("delete_program_pipelines called: ctx (GLIContext : %p) n (GLsizei : %i) pipelines (const GLuint* : %p)\n", ctx, n, pipelines);
			return delete_program_pipelines_reenter(ctx, n, pipelines);
		} END_MACH_OVERRIDE_PTR(delete_program_pipelines, obj->disp.delete_program_pipelines);

		if (err)
			log(LOG_ERR, "Failed to override delete_program_pipelines: %i", err);

		MACH_OVERRIDE(void,gen_program_pipelines,(GLIContext ctx, GLsizei n, GLuint *pipelines), err ) {
			file_log("gen_program_pipelines called: ctx (GLIContext : %p) n (GLsizei : %i) pipelines (GLuint* : %p)\n", ctx, n, pipelines);
			return gen_program_pipelines_reenter(ctx, n, pipelines);
		} END_MACH_OVERRIDE_PTR(gen_program_pipelines, obj->disp.gen_program_pipelines);

		if (err)
			log(LOG_ERR, "Failed to override gen_program_pipelines: %i", err);

		MACH_OVERRIDE(GLboolean,is_program_pipeline,(GLIContext ctx, GLuint pipeline), err ) {
			file_log("is_program_pipeline called: ctx (GLIContext : %p) pipeline (GLuint : %u)\n", ctx, pipeline);
			GLboolean result = is_program_pipeline_reenter(ctx, pipeline);
			return result;
		} END_MACH_OVERRIDE_PTR(is_program_pipeline, obj->disp.is_program_pipeline);

		if (err)
			log(LOG_ERR, "Failed to override is_program_pipeline: %i", err);

		MACH_OVERRIDE(void,get_program_pipelineiv,(GLIContext ctx, GLuint pipeline, GLenum pname, GLint *params), err ) {
			file_log("get_program_pipelineiv called: ctx (GLIContext : %p) pipeline (GLuint : %u) pname (GLenum : %s) params (GLint* : %p)\n", ctx, pipeline, GLenumToString(pname).c_str(), params);
			return get_program_pipelineiv_reenter(ctx, pipeline, pname, params);
		} END_MACH_OVERRIDE_PTR(get_program_pipelineiv, obj->disp.get_program_pipelineiv);

		if (err)
			log(LOG_ERR, "Failed to override get_program_pipelineiv: %i", err);

		MACH_OVERRIDE(void,validate_program_pipeline,(GLIContext ctx, GLuint pipeline), err ) {
			file_log("validate_program_pipeline called: ctx (GLIContext : %p) pipeline (GLuint : %u)\n", ctx, pipeline);
			return validate_program_pipeline_reenter(ctx, pipeline);
		} END_MACH_OVERRIDE_PTR(validate_program_pipeline, obj->disp.validate_program_pipeline);

		if (err)
			log(LOG_ERR, "Failed to override validate_program_pipeline: %i", err);

		MACH_OVERRIDE(void,get_program_pipeline_info_log,(GLIContext ctx, GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog), err ) {
			file_log("get_program_pipeline_info_log called: ctx (GLIContext : %p) pipeline (GLuint : %u) bufSize (GLsizei : %i) length (GLsizei* : %p) infoLog (GLchar* : %p)\n", ctx, pipeline, bufSize, length, infoLog);
			return get_program_pipeline_info_log_reenter(ctx, pipeline, bufSize, length, infoLog);
		} END_MACH_OVERRIDE_PTR(get_program_pipeline_info_log, obj->disp.get_program_pipeline_info_log);

		if (err)
			log(LOG_ERR, "Failed to override get_program_pipeline_info_log: %i", err);

		MACH_OVERRIDE(void,program_uniform1i,(GLIContext ctx, GLuint program, GLint location, GLint x), err ) {
			file_log("program_uniform1i called: ctx (GLIContext : %p) program (GLuint : %u) location (GLint : %i) x (GLint : %i)\n", ctx, program, location, x);
			return program_uniform1i_reenter(ctx, program, location, x);
		} END_MACH_OVERRIDE_PTR(program_uniform1i, obj->disp.program_uniform1i);

		if (err)
			log(LOG_ERR, "Failed to override program_uniform1i: %i", err);

		MACH_OVERRIDE(void,program_uniform2i,(GLIContext ctx, GLuint program, GLint location, GLint x, GLint y), err ) {
			file_log("program_uniform2i called: ctx (GLIContext : %p) program (GLuint : %u) location (GLint : %i) x (GLint : %i) y (GLint : %i)\n", ctx, program, location, x, y);
			return program_uniform2i_reenter(ctx, program, location, x, y);
		} END_MACH_OVERRIDE_PTR(program_uniform2i, obj->disp.program_uniform2i);

		if (err)
			log(LOG_ERR, "Failed to override program_uniform2i: %i", err);

		MACH_OVERRIDE(void,program_uniform3i,(GLIContext ctx, GLuint program, GLint location, GLint x, GLint y, GLint z), err ) {
			file_log("program_uniform3i called: ctx (GLIContext : %p) program (GLuint : %u) location (GLint : %i) x (GLint : %i) y (GLint : %i) z (GLint : %i)\n", ctx, program, location, x, y, z);
			return program_uniform3i_reenter(ctx, program, location, x, y, z);
		} END_MACH_OVERRIDE_PTR(program_uniform3i, obj->disp.program_uniform3i);

		if (err)
			log(LOG_ERR, "Failed to override program_uniform3i: %i", err);

		MACH_OVERRIDE(void,program_uniform4i,(GLIContext ctx, GLuint program, GLint location, GLint x, GLint y, GLint z, GLint w), err ) {
			file_log("program_uniform4i called: ctx (GLIContext : %p) program (GLuint : %u) location (GLint : %i) x (GLint : %i) y (GLint : %i) z (GLint : %i) w (GLint : %i)\n", ctx, program, location, x, y, z, w);
			return program_uniform4i_reenter(ctx, program, location, x, y, z, w);
		} END_MACH_OVERRIDE_PTR(program_uniform4i, obj->disp.program_uniform4i);

		if (err)
			log(LOG_ERR, "Failed to override program_uniform4i: %i", err);

		MACH_OVERRIDE(void,program_uniform1f,(GLIContext ctx, GLuint program, GLint location, GLfloat x), err ) {
			file_log("program_uniform1f called: ctx (GLIContext : %p) program (GLuint : %u) location (GLint : %i) x (GLfloat : %f)\n", ctx, program, location, x);
			return program_uniform1f_reenter(ctx, program, location, x);
		} END_MACH_OVERRIDE_PTR(program_uniform1f, obj->disp.program_uniform1f);

		if (err)
			log(LOG_ERR, "Failed to override program_uniform1f: %i", err);

		MACH_OVERRIDE(void,program_uniform2f,(GLIContext ctx, GLuint program, GLint location, GLfloat x, GLfloat y), err ) {
			file_log("program_uniform2f called: ctx (GLIContext : %p) program (GLuint : %u) location (GLint : %i) x (GLfloat : %f) y (GLfloat : %f)\n", ctx, program, location, x, y);
			return program_uniform2f_reenter(ctx, program, location, x, y);
		} END_MACH_OVERRIDE_PTR(program_uniform2f, obj->disp.program_uniform2f);

		if (err)
			log(LOG_ERR, "Failed to override program_uniform2f: %i", err);

		MACH_OVERRIDE(void,program_uniform3f,(GLIContext ctx, GLuint program, GLint location, GLfloat x, GLfloat y, GLfloat z), err ) {
			file_log("program_uniform3f called: ctx (GLIContext : %p) program (GLuint : %u) location (GLint : %i) x (GLfloat : %f) y (GLfloat : %f) z (GLfloat : %f)\n", ctx, program, location, x, y, z);
			return program_uniform3f_reenter(ctx, program, location, x, y, z);
		} END_MACH_OVERRIDE_PTR(program_uniform3f, obj->disp.program_uniform3f);

		if (err)
			log(LOG_ERR, "Failed to override program_uniform3f: %i", err);

		MACH_OVERRIDE(void,program_uniform4f,(GLIContext ctx, GLuint program, GLint location, GLfloat x, GLfloat y, GLfloat z, GLfloat w), err ) {
			file_log("program_uniform4f called: ctx (GLIContext : %p) program (GLuint : %u) location (GLint : %i) x (GLfloat : %f) y (GLfloat : %f) z (GLfloat : %f) w (GLfloat : %f)\n", ctx, program, location, x, y, z, w);
			return program_uniform4f_reenter(ctx, program, location, x, y, z, w);
		} END_MACH_OVERRIDE_PTR(program_uniform4f, obj->disp.program_uniform4f);

		if (err)
			log(LOG_ERR, "Failed to override program_uniform4f: %i", err);

		MACH_OVERRIDE(void,program_uniform1iv,(GLIContext ctx, GLuint program, GLint location, GLsizei count, const GLint *value), err ) {
			file_log("program_uniform1iv called: ctx (GLIContext : %p) program (GLuint : %u) location (GLint : %i) count (GLsizei : %i) value (const GLint* : %p)\n", ctx, program, location, count, value);
			return program_uniform1iv_reenter(ctx, program, location, count, value);
		} END_MACH_OVERRIDE_PTR(program_uniform1iv, obj->disp.program_uniform1iv);

		if (err)
			log(LOG_ERR, "Failed to override program_uniform1iv: %i", err);

		MACH_OVERRIDE(void,program_uniform2iv,(GLIContext ctx, GLuint program, GLint location, GLsizei count, const GLint *value), err ) {
			file_log("program_uniform2iv called: ctx (GLIContext : %p) program (GLuint : %u) location (GLint : %i) count (GLsizei : %i) value (const GLint* : %p)\n", ctx, program, location, count, value);
			return program_uniform2iv_reenter(ctx, program, location, count, value);
		} END_MACH_OVERRIDE_PTR(program_uniform2iv, obj->disp.program_uniform2iv);

		if (err)
			log(LOG_ERR, "Failed to override program_uniform2iv: %i", err);

		MACH_OVERRIDE(void,program_uniform3iv,(GLIContext ctx, GLuint program, GLint location, GLsizei count, const GLint *value), err ) {
			file_log("program_uniform3iv called: ctx (GLIContext : %p) program (GLuint : %u) location (GLint : %i) count (GLsizei : %i) value (const GLint* : %p)\n", ctx, program, location, count, value);
			return program_uniform3iv_reenter(ctx, program, location, count, value);
		} END_MACH_OVERRIDE_PTR(program_uniform3iv, obj->disp.program_uniform3iv);

		if (err)
			log(LOG_ERR, "Failed to override program_uniform3iv: %i", err);

		MACH_OVERRIDE(void,program_uniform4iv,(GLIContext ctx, GLuint program, GLint location, GLsizei count, const GLint *value), err ) {
			file_log("program_uniform4iv called: ctx (GLIContext : %p) program (GLuint : %u) location (GLint : %i) count (GLsizei : %i) value (const GLint* : %p)\n", ctx, program, location, count, value);
			return program_uniform4iv_reenter(ctx, program, location, count, value);
		} END_MACH_OVERRIDE_PTR(program_uniform4iv, obj->disp.program_uniform4iv);

		if (err)
			log(LOG_ERR, "Failed to override program_uniform4iv: %i", err);

		MACH_OVERRIDE(void,program_uniform1fv,(GLIContext ctx, GLuint program, GLint location, GLsizei count, const GLfloat *value), err ) {
			file_log("program_uniform1fv called: ctx (GLIContext : %p) program (GLuint : %u) location (GLint : %i) count (GLsizei : %i) value (const GLfloat* : %p)\n", ctx, program, location, count, value);
			return program_uniform1fv_reenter(ctx, program, location, count, value);
		} END_MACH_OVERRIDE_PTR(program_uniform1fv, obj->disp.program_uniform1fv);

		if (err)
			log(LOG_ERR, "Failed to override program_uniform1fv: %i", err);

		MACH_OVERRIDE(void,program_uniform2fv,(GLIContext ctx, GLuint program, GLint location, GLsizei count, const GLfloat *value), err ) {
			file_log("program_uniform2fv called: ctx (GLIContext : %p) program (GLuint : %u) location (GLint : %i) count (GLsizei : %i) value (const GLfloat* : %p)\n", ctx, program, location, count, value);
			return program_uniform2fv_reenter(ctx, program, location, count, value);
		} END_MACH_OVERRIDE_PTR(program_uniform2fv, obj->disp.program_uniform2fv);

		if (err)
			log(LOG_ERR, "Failed to override program_uniform2fv: %i", err);

		MACH_OVERRIDE(void,program_uniform3fv,(GLIContext ctx, GLuint program, GLint location, GLsizei count, const GLfloat *value), err ) {
			file_log("program_uniform3fv called: ctx (GLIContext : %p) program (GLuint : %u) location (GLint : %i) count (GLsizei : %i) value (const GLfloat* : %p)\n", ctx, program, location, count, value);
			return program_uniform3fv_reenter(ctx, program, location, count, value);
		} END_MACH_OVERRIDE_PTR(program_uniform3fv, obj->disp.program_uniform3fv);

		if (err)
			log(LOG_ERR, "Failed to override program_uniform3fv: %i", err);

		MACH_OVERRIDE(void,program_uniform4fv,(GLIContext ctx, GLuint program, GLint location, GLsizei count, const GLfloat *value), err ) {
			file_log("program_uniform4fv called: ctx (GLIContext : %p) program (GLuint : %u) location (GLint : %i) count (GLsizei : %i) value (const GLfloat* : %p)\n", ctx, program, location, count, value);
			return program_uniform4fv_reenter(ctx, program, location, count, value);
		} END_MACH_OVERRIDE_PTR(program_uniform4fv, obj->disp.program_uniform4fv);

		if (err)
			log(LOG_ERR, "Failed to override program_uniform4fv: %i", err);

		MACH_OVERRIDE(void,program_uniform_matrix2fv,(GLIContext ctx, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value), err ) {
			file_log("program_uniform_matrix2fv called: ctx (GLIContext : %p) program (GLuint : %u) location (GLint : %i) count (GLsizei : %i) transpose (GLboolean : %i) value (const GLfloat* : %p)\n", ctx, program, location, count, transpose, value);
			return program_uniform_matrix2fv_reenter(ctx, program, location, count, transpose, value);
		} END_MACH_OVERRIDE_PTR(program_uniform_matrix2fv, obj->disp.program_uniform_matrix2fv);

		if (err)
			log(LOG_ERR, "Failed to override program_uniform_matrix2fv: %i", err);

		MACH_OVERRIDE(void,program_uniform_matrix3fv,(GLIContext ctx, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value), err ) {
			file_log("program_uniform_matrix3fv called: ctx (GLIContext : %p) program (GLuint : %u) location (GLint : %i) count (GLsizei : %i) transpose (GLboolean : %i) value (const GLfloat* : %p)\n", ctx, program, location, count, transpose, value);
			return program_uniform_matrix3fv_reenter(ctx, program, location, count, transpose, value);
		} END_MACH_OVERRIDE_PTR(program_uniform_matrix3fv, obj->disp.program_uniform_matrix3fv);

		if (err)
			log(LOG_ERR, "Failed to override program_uniform_matrix3fv: %i", err);

		MACH_OVERRIDE(void,program_uniform_matrix4fv,(GLIContext ctx, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value), err ) {
			file_log("program_uniform_matrix4fv called: ctx (GLIContext : %p) program (GLuint : %u) location (GLint : %i) count (GLsizei : %i) transpose (GLboolean : %i) value (const GLfloat* : %p)\n", ctx, program, location, count, transpose, value);
			return program_uniform_matrix4fv_reenter(ctx, program, location, count, transpose, value);
		} END_MACH_OVERRIDE_PTR(program_uniform_matrix4fv, obj->disp.program_uniform_matrix4fv);

		if (err)
			log(LOG_ERR, "Failed to override program_uniform_matrix4fv: %i", err);

		MACH_OVERRIDE(void,program_uniform1ui,(GLIContext ctx, GLuint program, GLint location, GLuint x), err ) {
			file_log("program_uniform1ui called: ctx (GLIContext : %p) program (GLuint : %u) location (GLint : %i) x (GLuint : %u)\n", ctx, program, location, x);
			return program_uniform1ui_reenter(ctx, program, location, x);
		} END_MACH_OVERRIDE_PTR(program_uniform1ui, obj->disp.program_uniform1ui);

		if (err)
			log(LOG_ERR, "Failed to override program_uniform1ui: %i", err);

		MACH_OVERRIDE(void,program_uniform2ui,(GLIContext ctx, GLuint program, GLint location, GLuint x, GLuint y), err ) {
			file_log("program_uniform2ui called: ctx (GLIContext : %p) program (GLuint : %u) location (GLint : %i) x (GLuint : %u) y (GLuint : %u)\n", ctx, program, location, x, y);
			return program_uniform2ui_reenter(ctx, program, location, x, y);
		} END_MACH_OVERRIDE_PTR(program_uniform2ui, obj->disp.program_uniform2ui);

		if (err)
			log(LOG_ERR, "Failed to override program_uniform2ui: %i", err);

		MACH_OVERRIDE(void,program_uniform3ui,(GLIContext ctx, GLuint program, GLint location, GLuint x, GLuint y, GLuint z), err ) {
			file_log("program_uniform3ui called: ctx (GLIContext : %p) program (GLuint : %u) location (GLint : %i) x (GLuint : %u) y (GLuint : %u) z (GLuint : %u)\n", ctx, program, location, x, y, z);
			return program_uniform3ui_reenter(ctx, program, location, x, y, z);
		} END_MACH_OVERRIDE_PTR(program_uniform3ui, obj->disp.program_uniform3ui);

		if (err)
			log(LOG_ERR, "Failed to override program_uniform3ui: %i", err);

		MACH_OVERRIDE(void,program_uniform4ui,(GLIContext ctx, GLuint program, GLint location, GLuint x, GLuint y, GLuint z, GLuint w), err ) {
			file_log("program_uniform4ui called: ctx (GLIContext : %p) program (GLuint : %u) location (GLint : %i) x (GLuint : %u) y (GLuint : %u) z (GLuint : %u) w (GLuint : %u)\n", ctx, program, location, x, y, z, w);
			return program_uniform4ui_reenter(ctx, program, location, x, y, z, w);
		} END_MACH_OVERRIDE_PTR(program_uniform4ui, obj->disp.program_uniform4ui);

		if (err)
			log(LOG_ERR, "Failed to override program_uniform4ui: %i", err);

		MACH_OVERRIDE(void,program_uniform1uiv,(GLIContext ctx, GLuint program, GLint location, GLsizei count, const GLuint *value), err ) {
			file_log("program_uniform1uiv called: ctx (GLIContext : %p) program (GLuint : %u) location (GLint : %i) count (GLsizei : %i) value (const GLuint* : %p)\n", ctx, program, location, count, value);
			return program_uniform1uiv_reenter(ctx, program, location, count, value);
		} END_MACH_OVERRIDE_PTR(program_uniform1uiv, obj->disp.program_uniform1uiv);

		if (err)
			log(LOG_ERR, "Failed to override program_uniform1uiv: %i", err);

		MACH_OVERRIDE(void,program_uniform2uiv,(GLIContext ctx, GLuint program, GLint location, GLsizei count, const GLuint *value), err ) {
			file_log("program_uniform2uiv called: ctx (GLIContext : %p) program (GLuint : %u) location (GLint : %i) count (GLsizei : %i) value (const GLuint* : %p)\n", ctx, program, location, count, value);
			return program_uniform2uiv_reenter(ctx, program, location, count, value);
		} END_MACH_OVERRIDE_PTR(program_uniform2uiv, obj->disp.program_uniform2uiv);

		if (err)
			log(LOG_ERR, "Failed to override program_uniform2uiv: %i", err);

		MACH_OVERRIDE(void,program_uniform3uiv,(GLIContext ctx, GLuint program, GLint location, GLsizei count, const GLuint *value), err ) {
			file_log("program_uniform3uiv called: ctx (GLIContext : %p) program (GLuint : %u) location (GLint : %i) count (GLsizei : %i) value (const GLuint* : %p)\n", ctx, program, location, count, value);
			return program_uniform3uiv_reenter(ctx, program, location, count, value);
		} END_MACH_OVERRIDE_PTR(program_uniform3uiv, obj->disp.program_uniform3uiv);

		if (err)
			log(LOG_ERR, "Failed to override program_uniform3uiv: %i", err);

		MACH_OVERRIDE(void,program_uniform4uiv,(GLIContext ctx, GLuint program, GLint location, GLsizei count, const GLuint *value), err ) {
			file_log("program_uniform4uiv called: ctx (GLIContext : %p) program (GLuint : %u) location (GLint : %i) count (GLsizei : %i) value (const GLuint* : %p)\n", ctx, program, location, count, value);
			return program_uniform4uiv_reenter(ctx, program, location, count, value);
		} END_MACH_OVERRIDE_PTR(program_uniform4uiv, obj->disp.program_uniform4uiv);

		if (err)
			log(LOG_ERR, "Failed to override program_uniform4uiv: %i", err);

		MACH_OVERRIDE(void,program_uniform_matrix2x3fv,(GLIContext ctx, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value), err ) {
			file_log("program_uniform_matrix2x3fv called: ctx (GLIContext : %p) program (GLuint : %u) location (GLint : %i) count (GLsizei : %i) transpose (GLboolean : %i) value (const GLfloat* : %p)\n", ctx, program, location, count, transpose, value);
			return program_uniform_matrix2x3fv_reenter(ctx, program, location, count, transpose, value);
		} END_MACH_OVERRIDE_PTR(program_uniform_matrix2x3fv, obj->disp.program_uniform_matrix2x3fv);

		if (err)
			log(LOG_ERR, "Failed to override program_uniform_matrix2x3fv: %i", err);

		MACH_OVERRIDE(void,program_uniform_matrix3x2fv,(GLIContext ctx, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value), err ) {
			file_log("program_uniform_matrix3x2fv called: ctx (GLIContext : %p) program (GLuint : %u) location (GLint : %i) count (GLsizei : %i) transpose (GLboolean : %i) value (const GLfloat* : %p)\n", ctx, program, location, count, transpose, value);
			return program_uniform_matrix3x2fv_reenter(ctx, program, location, count, transpose, value);
		} END_MACH_OVERRIDE_PTR(program_uniform_matrix3x2fv, obj->disp.program_uniform_matrix3x2fv);

		if (err)
			log(LOG_ERR, "Failed to override program_uniform_matrix3x2fv: %i", err);

		MACH_OVERRIDE(void,program_uniform_matrix2x4fv,(GLIContext ctx, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value), err ) {
			file_log("program_uniform_matrix2x4fv called: ctx (GLIContext : %p) program (GLuint : %u) location (GLint : %i) count (GLsizei : %i) transpose (GLboolean : %i) value (const GLfloat* : %p)\n", ctx, program, location, count, transpose, value);
			return program_uniform_matrix2x4fv_reenter(ctx, program, location, count, transpose, value);
		} END_MACH_OVERRIDE_PTR(program_uniform_matrix2x4fv, obj->disp.program_uniform_matrix2x4fv);

		if (err)
			log(LOG_ERR, "Failed to override program_uniform_matrix2x4fv: %i", err);

		MACH_OVERRIDE(void,program_uniform_matrix4x2fv,(GLIContext ctx, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value), err ) {
			file_log("program_uniform_matrix4x2fv called: ctx (GLIContext : %p) program (GLuint : %u) location (GLint : %i) count (GLsizei : %i) transpose (GLboolean : %i) value (const GLfloat* : %p)\n", ctx, program, location, count, transpose, value);
			return program_uniform_matrix4x2fv_reenter(ctx, program, location, count, transpose, value);
		} END_MACH_OVERRIDE_PTR(program_uniform_matrix4x2fv, obj->disp.program_uniform_matrix4x2fv);

		if (err)
			log(LOG_ERR, "Failed to override program_uniform_matrix4x2fv: %i", err);

		MACH_OVERRIDE(void,program_uniform_matrix3x4fv,(GLIContext ctx, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value), err ) {
			file_log("program_uniform_matrix3x4fv called: ctx (GLIContext : %p) program (GLuint : %u) location (GLint : %i) count (GLsizei : %i) transpose (GLboolean : %i) value (const GLfloat* : %p)\n", ctx, program, location, count, transpose, value);
			return program_uniform_matrix3x4fv_reenter(ctx, program, location, count, transpose, value);
		} END_MACH_OVERRIDE_PTR(program_uniform_matrix3x4fv, obj->disp.program_uniform_matrix3x4fv);

		if (err)
			log(LOG_ERR, "Failed to override program_uniform_matrix3x4fv: %i", err);

		MACH_OVERRIDE(void,program_uniform_matrix4x3fv,(GLIContext ctx, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value), err ) {
			file_log("program_uniform_matrix4x3fv called: ctx (GLIContext : %p) program (GLuint : %u) location (GLint : %i) count (GLsizei : %i) transpose (GLboolean : %i) value (const GLfloat* : %p)\n", ctx, program, location, count, transpose, value);
			return program_uniform_matrix4x3fv_reenter(ctx, program, location, count, transpose, value);
		} END_MACH_OVERRIDE_PTR(program_uniform_matrix4x3fv, obj->disp.program_uniform_matrix4x3fv);

		if (err)
			log(LOG_ERR, "Failed to override program_uniform_matrix4x3fv: %i", err);

		MACH_OVERRIDE(void,bind_frag_data_location_indexed,(GLIContext ctx, GLuint program, GLuint colorNumber, GLuint index, const GLchar *name), err ) {
			file_log("bind_frag_data_location_indexed called: ctx (GLIContext : %p) program (GLuint : %u) colorNumber (GLuint : %u) index (GLuint : %u) name (const GLchar* : %p)\n", ctx, program, colorNumber, index, name);
			OpenGL::StateMachine::Shared.bind_frag_data_location_indexed(ctx, program, colorNumber, index, name);
			return bind_frag_data_location_indexed_reenter(ctx, program, colorNumber, index, name);
		} END_MACH_OVERRIDE_PTR(bind_frag_data_location_indexed, obj->disp.bind_frag_data_location_indexed);

		if (err)
			log(LOG_ERR, "Failed to override bind_frag_data_location_indexed: %i", err);

		MACH_OVERRIDE(GLint,get_frag_data_index,(GLIContext ctx, GLuint program, const GLchar *name), err ) {
			file_log("get_frag_data_index called: ctx (GLIContext : %p) program (GLuint : %u) name (const GLchar* : %p)\n", ctx, program, name);
			GLint result = get_frag_data_index_reenter(ctx, program, name);
			return result;
		} END_MACH_OVERRIDE_PTR(get_frag_data_index, obj->disp.get_frag_data_index);

		if (err)
			log(LOG_ERR, "Failed to override get_frag_data_index: %i", err);

		MACH_OVERRIDE(void,blend_func_i,(GLIContext ctx, GLuint buf, GLenum src, GLenum dst), err ) {
			file_log("blend_func_i called: ctx (GLIContext : %p) buf (GLuint : %u) src (GLenum : %s) dst (GLenum : %s)\n", ctx, buf, GLenumToString(src).c_str(), GLenumToString(dst).c_str());
			return blend_func_i_reenter(ctx, buf, src, dst);
		} END_MACH_OVERRIDE_PTR(blend_func_i, obj->disp.blend_func_i);

		if (err)
			log(LOG_ERR, "Failed to override blend_func_i: %i", err);

		MACH_OVERRIDE(void,blend_func_separate_i,(GLIContext ctx, GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha), err ) {
			file_log("blend_func_separate_i called: ctx (GLIContext : %p) buf (GLuint : %u) srcRGB (GLenum : %s) dstRGB (GLenum : %s) srcAlpha (GLenum : %s) dstAlpha (GLenum : %s)\n", ctx, buf, GLenumToString(srcRGB).c_str(), GLenumToString(dstRGB).c_str(), GLenumToString(srcAlpha).c_str(), GLenumToString(dstAlpha).c_str());
			return blend_func_separate_i_reenter(ctx, buf, srcRGB, dstRGB, srcAlpha, dstAlpha);
		} END_MACH_OVERRIDE_PTR(blend_func_separate_i, obj->disp.blend_func_separate_i);

		if (err)
			log(LOG_ERR, "Failed to override blend_func_separate_i: %i", err);

		MACH_OVERRIDE(void,blend_equation_i,(GLIContext ctx, GLuint buf, GLenum mode), err ) {
			file_log("blend_equation_i called: ctx (GLIContext : %p) buf (GLuint : %u) mode (GLenum : %s)\n", ctx, buf, GLenumToString(mode).c_str());
			return blend_equation_i_reenter(ctx, buf, mode);
		} END_MACH_OVERRIDE_PTR(blend_equation_i, obj->disp.blend_equation_i);

		if (err)
			log(LOG_ERR, "Failed to override blend_equation_i: %i", err);

		MACH_OVERRIDE(void,blend_equation_separate_i,(GLIContext ctx, GLuint buf, GLenum modeRGB, GLenum modeAlpha), err ) {
			file_log("blend_equation_separate_i called: ctx (GLIContext : %p) buf (GLuint : %u) modeRGB (GLenum : %s) modeAlpha (GLenum : %s)\n", ctx, buf, GLenumToString(modeRGB).c_str(), GLenumToString(modeAlpha).c_str());
			return blend_equation_separate_i_reenter(ctx, buf, modeRGB, modeAlpha);
		} END_MACH_OVERRIDE_PTR(blend_equation_separate_i, obj->disp.blend_equation_separate_i);

		if (err)
			log(LOG_ERR, "Failed to override blend_equation_separate_i: %i", err);

		MACH_OVERRIDE(void,named_string_ARB,(GLIContext ctx, GLenum type, GLint namelen, const GLchar *name, GLint stringlen, const GLchar *string), err ) {
			file_log("named_string_ARB called: ctx (GLIContext : %p) type (GLenum : %s) namelen (GLint : %i) name (const GLchar* : %p) stringlen (GLint : %i) string (const GLchar* : %p)\n", ctx, GLenumToString(type).c_str(), namelen, name, stringlen, string);
			return named_string_ARB_reenter(ctx, type, namelen, name, stringlen, string);
		} END_MACH_OVERRIDE_PTR(named_string_ARB, obj->disp.named_string_ARB);

		if (err)
			log(LOG_ERR, "Failed to override named_string_ARB: %i", err);

		MACH_OVERRIDE(void,delete_named_string_ARB,(GLIContext ctx, GLint namelen, const GLchar *name), err ) {
			file_log("delete_named_string_ARB called: ctx (GLIContext : %p) namelen (GLint : %i) name (const GLchar* : %p)\n", ctx, namelen, name);
			return delete_named_string_ARB_reenter(ctx, namelen, name);
		} END_MACH_OVERRIDE_PTR(delete_named_string_ARB, obj->disp.delete_named_string_ARB);

		if (err)
			log(LOG_ERR, "Failed to override delete_named_string_ARB: %i", err);

		MACH_OVERRIDE(void,compile_shader_include_ARB,(GLIContext ctx, GLuint shader, GLsizei count, const GLchar* const *path, const GLint *length), err ) {
			file_log("compile_shader_include_ARB called: ctx (GLIContext : %p) shader (GLuint : %u) count (GLsizei : %i) path (const GLchar*const* : %p) length (const GLint* : %p)\n", ctx, shader, count, path, length);
			return compile_shader_include_ARB_reenter(ctx, shader, count, path, length);
		} END_MACH_OVERRIDE_PTR(compile_shader_include_ARB, obj->disp.compile_shader_include_ARB);

		if (err)
			log(LOG_ERR, "Failed to override compile_shader_include_ARB: %i", err);

		MACH_OVERRIDE(GLboolean,is_named_string_ARB,(GLIContext ctx, GLint namelen, const GLchar *name), err ) {
			file_log("is_named_string_ARB called: ctx (GLIContext : %p) namelen (GLint : %i) name (const GLchar* : %p)\n", ctx, namelen, name);
			GLboolean result = is_named_string_ARB_reenter(ctx, namelen, name);
			return result;
		} END_MACH_OVERRIDE_PTR(is_named_string_ARB, obj->disp.is_named_string_ARB);

		if (err)
			log(LOG_ERR, "Failed to override is_named_string_ARB: %i", err);

		MACH_OVERRIDE(void,get_named_string_ARB,(GLIContext ctx, GLint namelen, const GLchar *name, GLsizei bufSize, GLint *stringlen, GLchar *string), err ) {
			file_log("get_named_string_ARB called: ctx (GLIContext : %p) namelen (GLint : %i) name (const GLchar* : %p) bufSize (GLsizei : %i) stringlen (GLint* : %p) string (GLchar* : %p)\n", ctx, namelen, name, bufSize, stringlen, string);
			return get_named_string_ARB_reenter(ctx, namelen, name, bufSize, stringlen, string);
		} END_MACH_OVERRIDE_PTR(get_named_string_ARB, obj->disp.get_named_string_ARB);

		if (err)
			log(LOG_ERR, "Failed to override get_named_string_ARB: %i", err);

		MACH_OVERRIDE(void,get_named_string_iv_ARB,(GLIContext ctx, GLint namelen, const GLchar *name, GLenum pname, GLint *params), err ) {
			file_log("get_named_string_iv_ARB called: ctx (GLIContext : %p) namelen (GLint : %i) name (const GLchar* : %p) pname (GLenum : %s) params (GLint* : %p)\n", ctx, namelen, name, GLenumToString(pname).c_str(), params);
			return get_named_string_iv_ARB_reenter(ctx, namelen, name, pname, params);
		} END_MACH_OVERRIDE_PTR(get_named_string_iv_ARB, obj->disp.get_named_string_iv_ARB);

		if (err)
			log(LOG_ERR, "Failed to override get_named_string_iv_ARB: %i", err);

		MACH_OVERRIDE(void,release_shader_compiler,(GLIContext ctx), err ) {
			file_log("release_shader_compiler called: ctx (GLIContext : %p)\n", ctx);
			return release_shader_compiler_reenter(ctx);
		} END_MACH_OVERRIDE_PTR(release_shader_compiler, obj->disp.release_shader_compiler);

		if (err)
			log(LOG_ERR, "Failed to override release_shader_compiler: %i", err);

		MACH_OVERRIDE(void,shader_binary,(GLIContext ctx, GLint n, GLuint *shaders, GLenum binaryformat, const GLvoid *binary, GLint length), err ) {
			file_log("shader_binary called: ctx (GLIContext : %p) n (GLint : %i) shaders (GLuint* : %p) binaryformat (GLenum : %s) binary (const GLvoid* : %p) length (GLint : %i)\n", ctx, n, shaders, GLenumToString(binaryformat).c_str(), binary, length);
			return shader_binary_reenter(ctx, n, shaders, binaryformat, binary, length);
		} END_MACH_OVERRIDE_PTR(shader_binary, obj->disp.shader_binary);

		if (err)
			log(LOG_ERR, "Failed to override shader_binary: %i", err);

		MACH_OVERRIDE(void,get_shader_precision_format,(GLIContext ctx, GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision), err ) {
			file_log("get_shader_precision_format called: ctx (GLIContext : %p) shadertype (GLenum : %s) precisiontype (GLenum : %s) range (GLint* : %p) precision (GLint* : %p)\n", ctx, GLenumToString(shadertype).c_str(), GLenumToString(precisiontype).c_str(), range, precision);
			return get_shader_precision_format_reenter(ctx, shadertype, precisiontype, range, precision);
		} END_MACH_OVERRIDE_PTR(get_shader_precision_format, obj->disp.get_shader_precision_format);

		if (err)
			log(LOG_ERR, "Failed to override get_shader_precision_format: %i", err);

		MACH_OVERRIDE(void,depth_rangef,(GLIContext ctx, GLclampf zNear, GLclampf zFar), err ) {
			file_log("depth_rangef called: ctx (GLIContext : %p) zNear (GLclampf : %f) zFar (GLclampf : %f)\n", ctx, zNear, zFar);
			return depth_rangef_reenter(ctx, zNear, zFar);
		} END_MACH_OVERRIDE_PTR(depth_rangef, obj->disp.depth_rangef);

		if (err)
			log(LOG_ERR, "Failed to override depth_rangef: %i", err);

		MACH_OVERRIDE(void,clear_depthf,(GLIContext ctx, GLclampf depth), err ) {
			file_log("clear_depthf called: ctx (GLIContext : %p) depth (GLclampf : %f)\n", ctx, depth);
			return clear_depthf_reenter(ctx, depth);
		} END_MACH_OVERRIDE_PTR(clear_depthf, obj->disp.clear_depthf);

		if (err)
			log(LOG_ERR, "Failed to override clear_depthf: %i", err);

		MACH_OVERRIDE(void,vertex_attribP1ui,(GLIContext ctx, GLuint index, GLenum type, GLboolean normalized, GLuint value), err ) {
			file_log("vertex_attribP1ui called: ctx (GLIContext : %p) index (GLuint : %u) type (GLenum : %s) normalized (GLboolean : %i) value (GLuint : %u)\n", ctx, index, GLenumToString(type).c_str(), normalized, value);
			return vertex_attribP1ui_reenter(ctx, index, type, normalized, value);
		} END_MACH_OVERRIDE_PTR(vertex_attribP1ui, obj->disp.vertex_attribP1ui);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attribP1ui: %i", err);

		MACH_OVERRIDE(void,vertex_attribP2ui,(GLIContext ctx, GLuint index, GLenum type, GLboolean normalized, GLuint value), err ) {
			file_log("vertex_attribP2ui called: ctx (GLIContext : %p) index (GLuint : %u) type (GLenum : %s) normalized (GLboolean : %i) value (GLuint : %u)\n", ctx, index, GLenumToString(type).c_str(), normalized, value);
			return vertex_attribP2ui_reenter(ctx, index, type, normalized, value);
		} END_MACH_OVERRIDE_PTR(vertex_attribP2ui, obj->disp.vertex_attribP2ui);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attribP2ui: %i", err);

		MACH_OVERRIDE(void,vertex_attribP3ui,(GLIContext ctx, GLuint index, GLenum type, GLboolean normalized, GLuint value), err ) {
			file_log("vertex_attribP3ui called: ctx (GLIContext : %p) index (GLuint : %u) type (GLenum : %s) normalized (GLboolean : %i) value (GLuint : %u)\n", ctx, index, GLenumToString(type).c_str(), normalized, value);
			return vertex_attribP3ui_reenter(ctx, index, type, normalized, value);
		} END_MACH_OVERRIDE_PTR(vertex_attribP3ui, obj->disp.vertex_attribP3ui);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attribP3ui: %i", err);

		MACH_OVERRIDE(void,vertex_attribP4ui,(GLIContext ctx, GLuint index, GLenum type, GLboolean normalized, GLuint value), err ) {
			file_log("vertex_attribP4ui called: ctx (GLIContext : %p) index (GLuint : %u) type (GLenum : %s) normalized (GLboolean : %i) value (GLuint : %u)\n", ctx, index, GLenumToString(type).c_str(), normalized, value);
			return vertex_attribP4ui_reenter(ctx, index, type, normalized, value);
		} END_MACH_OVERRIDE_PTR(vertex_attribP4ui, obj->disp.vertex_attribP4ui);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attribP4ui: %i", err);

		MACH_OVERRIDE(void,vertex_attribP1uiv,(GLIContext ctx, GLuint index, GLenum type, GLboolean normalized, const GLuint *value), err ) {
			file_log("vertex_attribP1uiv called: ctx (GLIContext : %p) index (GLuint : %u) type (GLenum : %s) normalized (GLboolean : %i) value (const GLuint* : %p)\n", ctx, index, GLenumToString(type).c_str(), normalized, value);
			return vertex_attribP1uiv_reenter(ctx, index, type, normalized, value);
		} END_MACH_OVERRIDE_PTR(vertex_attribP1uiv, obj->disp.vertex_attribP1uiv);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attribP1uiv: %i", err);

		MACH_OVERRIDE(void,vertex_attribP2uiv,(GLIContext ctx, GLuint index, GLenum type, GLboolean normalized, const GLuint *value), err ) {
			file_log("vertex_attribP2uiv called: ctx (GLIContext : %p) index (GLuint : %u) type (GLenum : %s) normalized (GLboolean : %i) value (const GLuint* : %p)\n", ctx, index, GLenumToString(type).c_str(), normalized, value);
			return vertex_attribP2uiv_reenter(ctx, index, type, normalized, value);
		} END_MACH_OVERRIDE_PTR(vertex_attribP2uiv, obj->disp.vertex_attribP2uiv);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attribP2uiv: %i", err);

		MACH_OVERRIDE(void,vertex_attribP3uiv,(GLIContext ctx, GLuint index, GLenum type, GLboolean normalized, const GLuint *value), err ) {
			file_log("vertex_attribP3uiv called: ctx (GLIContext : %p) index (GLuint : %u) type (GLenum : %s) normalized (GLboolean : %i) value (const GLuint* : %p)\n", ctx, index, GLenumToString(type).c_str(), normalized, value);
			return vertex_attribP3uiv_reenter(ctx, index, type, normalized, value);
		} END_MACH_OVERRIDE_PTR(vertex_attribP3uiv, obj->disp.vertex_attribP3uiv);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attribP3uiv: %i", err);

		MACH_OVERRIDE(void,vertex_attribP4uiv,(GLIContext ctx, GLuint index, GLenum type, GLboolean normalized, const GLuint *value), err ) {
			file_log("vertex_attribP4uiv called: ctx (GLIContext : %p) index (GLuint : %u) type (GLenum : %s) normalized (GLboolean : %i) value (const GLuint* : %p)\n", ctx, index, GLenumToString(type).c_str(), normalized, value);
			return vertex_attribP4uiv_reenter(ctx, index, type, normalized, value);
		} END_MACH_OVERRIDE_PTR(vertex_attribP4uiv, obj->disp.vertex_attribP4uiv);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attribP4uiv: %i", err);

		MACH_OVERRIDE(void,get_program_binary,(GLIContext ctx, GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, GLvoid *binary), err ) {
			file_log("get_program_binary called: ctx (GLIContext : %p) program (GLuint : %u) bufSize (GLsizei : %i) length (GLsizei* : %p) binaryFormat (GLenum* : %p) binary (GLvoid* : %p)\n", ctx, program, bufSize, length, binaryFormat, binary);
			return get_program_binary_reenter(ctx, program, bufSize, length, binaryFormat, binary);
		} END_MACH_OVERRIDE_PTR(get_program_binary, obj->disp.get_program_binary);

		if (err)
			log(LOG_ERR, "Failed to override get_program_binary: %i", err);

		MACH_OVERRIDE(void,program_binary,(GLIContext ctx, GLuint program, GLenum binaryFormat, const GLvoid *binary, GLsizei length), err ) {
			file_log("program_binary called: ctx (GLIContext : %p) program (GLuint : %u) binaryFormat (GLenum : %s) binary (const GLvoid* : %p) length (GLsizei : %i)\n", ctx, program, GLenumToString(binaryFormat).c_str(), binary, length);
			return program_binary_reenter(ctx, program, binaryFormat, binary, length);
		} END_MACH_OVERRIDE_PTR(program_binary, obj->disp.program_binary);

		if (err)
			log(LOG_ERR, "Failed to override program_binary: %i", err);

		MACH_OVERRIDE(void,min_sample_shading,(GLIContext ctx, GLclampf value), err ) {
			file_log("min_sample_shading called: ctx (GLIContext : %p) value (GLclampf : %f)\n", ctx, value);
			return min_sample_shading_reenter(ctx, value);
		} END_MACH_OVERRIDE_PTR(min_sample_shading, obj->disp.min_sample_shading);

		if (err)
			log(LOG_ERR, "Failed to override min_sample_shading: %i", err);

		MACH_OVERRIDE(void,viewport_arrayv,(GLIContext ctx, GLuint first, GLsizei count, const GLfloat * v), err ) {
			file_log("viewport_arrayv called: ctx (GLIContext : %p) first (GLuint : %u) count (GLsizei : %i) v (const GLfloat * : %p)\n", ctx, first, count, v);
			return viewport_arrayv_reenter(ctx, first, count, v);
		} END_MACH_OVERRIDE_PTR(viewport_arrayv, obj->disp.viewport_arrayv);

		if (err)
			log(LOG_ERR, "Failed to override viewport_arrayv: %i", err);

		MACH_OVERRIDE(void,viewport_indexedf,(GLIContext ctx, GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h), err ) {
			file_log("viewport_indexedf called: ctx (GLIContext : %p) index (GLuint : %u) x (GLfloat : %f) y (GLfloat : %f) w (GLfloat : %f) h (GLfloat : %f)\n", ctx, index, x, y, w, h);
			return viewport_indexedf_reenter(ctx, index, x, y, w, h);
		} END_MACH_OVERRIDE_PTR(viewport_indexedf, obj->disp.viewport_indexedf);

		if (err)
			log(LOG_ERR, "Failed to override viewport_indexedf: %i", err);

		MACH_OVERRIDE(void,viewport_indexedfv,(GLIContext ctx, GLuint index, const GLfloat * v), err ) {
			file_log("viewport_indexedfv called: ctx (GLIContext : %p) index (GLuint : %u) v (const GLfloat * : %p)\n", ctx, index, v);
			return viewport_indexedfv_reenter(ctx, index, v);
		} END_MACH_OVERRIDE_PTR(viewport_indexedfv, obj->disp.viewport_indexedfv);

		if (err)
			log(LOG_ERR, "Failed to override viewport_indexedfv: %i", err);

		MACH_OVERRIDE(void,scissor_arrayv,(GLIContext ctx, GLuint first, GLsizei count, const GLint * v), err ) {
			file_log("scissor_arrayv called: ctx (GLIContext : %p) first (GLuint : %u) count (GLsizei : %i) v (const GLint * : %p)\n", ctx, first, count, v);
			return scissor_arrayv_reenter(ctx, first, count, v);
		} END_MACH_OVERRIDE_PTR(scissor_arrayv, obj->disp.scissor_arrayv);

		if (err)
			log(LOG_ERR, "Failed to override scissor_arrayv: %i", err);

		MACH_OVERRIDE(void,scissor_indexed,(GLIContext ctx, GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height), err ) {
			file_log("scissor_indexed called: ctx (GLIContext : %p) index (GLuint : %u) left (GLint : %i) bottom (GLint : %i) width (GLsizei : %i) height (GLsizei : %i)\n", ctx, index, left, bottom, width, height);
			return scissor_indexed_reenter(ctx, index, left, bottom, width, height);
		} END_MACH_OVERRIDE_PTR(scissor_indexed, obj->disp.scissor_indexed);

		if (err)
			log(LOG_ERR, "Failed to override scissor_indexed: %i", err);

		MACH_OVERRIDE(void,scissor_indexedv,(GLIContext ctx, GLuint index, const GLint * v), err ) {
			file_log("scissor_indexedv called: ctx (GLIContext : %p) index (GLuint : %u) v (const GLint * : %p)\n", ctx, index, v);
			return scissor_indexedv_reenter(ctx, index, v);
		} END_MACH_OVERRIDE_PTR(scissor_indexedv, obj->disp.scissor_indexedv);

		if (err)
			log(LOG_ERR, "Failed to override scissor_indexedv: %i", err);

		MACH_OVERRIDE(void,depth_range_arrayv,(GLIContext ctx, GLuint first, GLsizei count, const GLclampd * v), err ) {
			file_log("depth_range_arrayv called: ctx (GLIContext : %p) first (GLuint : %u) count (GLsizei : %i) v (const GLclampd * : %p)\n", ctx, first, count, v);
			return depth_range_arrayv_reenter(ctx, first, count, v);
		} END_MACH_OVERRIDE_PTR(depth_range_arrayv, obj->disp.depth_range_arrayv);

		if (err)
			log(LOG_ERR, "Failed to override depth_range_arrayv: %i", err);

		MACH_OVERRIDE(void,depth_range_indexed,(GLIContext ctx, GLuint index, GLclampd n, GLclampd f), err ) {
			file_log("depth_range_indexed called: ctx (GLIContext : %p) index (GLuint : %u) n (GLclampd : %f) f (GLclampd : %f)\n", ctx, index, n, f);
			return depth_range_indexed_reenter(ctx, index, n, f);
		} END_MACH_OVERRIDE_PTR(depth_range_indexed, obj->disp.depth_range_indexed);

		if (err)
			log(LOG_ERR, "Failed to override depth_range_indexed: %i", err);

		MACH_OVERRIDE(void,get_floati_v,(GLIContext ctx, GLenum target, GLuint index, GLfloat *data), err ) {
			file_log("get_floati_v called: ctx (GLIContext : %p) target (GLenum : %s) index (GLuint : %u) data (GLfloat* : %p)\n", ctx, GLenumToString(target).c_str(), index, data);
			return get_floati_v_reenter(ctx, target, index, data);
		} END_MACH_OVERRIDE_PTR(get_floati_v, obj->disp.get_floati_v);

		if (err)
			log(LOG_ERR, "Failed to override get_floati_v: %i", err);

		MACH_OVERRIDE(void,get_doublei_v,(GLIContext ctx, GLenum target, GLuint index, GLdouble *data), err ) {
			file_log("get_doublei_v called: ctx (GLIContext : %p) target (GLenum : %s) index (GLuint : %u) data (GLdouble* : %p)\n", ctx, GLenumToString(target).c_str(), index, data);
			return get_doublei_v_reenter(ctx, target, index, data);
		} END_MACH_OVERRIDE_PTR(get_doublei_v, obj->disp.get_doublei_v);

		if (err)
			log(LOG_ERR, "Failed to override get_doublei_v: %i", err);

		MACH_OVERRIDE(void,draw_arrays_indirect,(GLIContext ctx, GLenum mode, const GLvoid *indirect), err ) {
			file_log("draw_arrays_indirect called: ctx (GLIContext : %p) mode (GLenum : %s) indirect (const GLvoid* : %p)\n", ctx, GLenumToString(mode).c_str(), indirect);
			OpenGL::StateMachine::Shared.draw_arrays_indirect(ctx, mode, indirect);
			return draw_arrays_indirect_reenter(ctx, mode, indirect);
		} END_MACH_OVERRIDE_PTR(draw_arrays_indirect, obj->disp.draw_arrays_indirect);

		if (err)
			log(LOG_ERR, "Failed to override draw_arrays_indirect: %i", err);

		MACH_OVERRIDE(void,draw_elements_indirect,(GLIContext ctx, GLenum mode, GLenum type, const GLvoid *indirect), err ) {
			file_log("draw_elements_indirect called: ctx (GLIContext : %p) mode (GLenum : %s) type (GLenum : %s) indirect (const GLvoid* : %p)\n", ctx, GLenumToString(mode).c_str(), GLenumToString(type).c_str(), indirect);
			OpenGL::StateMachine::Shared.draw_elements_indirect(ctx, mode, type, indirect);
			return draw_elements_indirect_reenter(ctx, mode, type, indirect);
		} END_MACH_OVERRIDE_PTR(draw_elements_indirect, obj->disp.draw_elements_indirect);

		if (err)
			log(LOG_ERR, "Failed to override draw_elements_indirect: %i", err);

		MACH_OVERRIDE(void,patch_parameteri,(GLIContext ctx, GLenum pname, GLint value), err ) {
			file_log("patch_parameteri called: ctx (GLIContext : %p) pname (GLenum : %s) value (GLint : %i)\n", ctx, GLenumToString(pname).c_str(), value);
			return patch_parameteri_reenter(ctx, pname, value);
		} END_MACH_OVERRIDE_PTR(patch_parameteri, obj->disp.patch_parameteri);

		if (err)
			log(LOG_ERR, "Failed to override patch_parameteri: %i", err);

		MACH_OVERRIDE(void,patch_parameterfv,(GLIContext ctx, GLenum pname, const GLfloat* values), err ) {
			file_log("patch_parameterfv called: ctx (GLIContext : %p) pname (GLenum : %s) values (const GLfloat* : %p)\n", ctx, GLenumToString(pname).c_str(), values);
			return patch_parameterfv_reenter(ctx, pname, values);
		} END_MACH_OVERRIDE_PTR(patch_parameterfv, obj->disp.patch_parameterfv);

		if (err)
			log(LOG_ERR, "Failed to override patch_parameterfv: %i", err);

		MACH_OVERRIDE(void,bind_transform_feedback,(GLIContext ctx, GLenum target, GLuint name), err ) {
			file_log("bind_transform_feedback called: ctx (GLIContext : %p) target (GLenum : %s) name (GLuint : %u)\n", ctx, GLenumToString(target).c_str(), name);
			OpenGL::StateMachine::Shared.bind_transform_feedback(ctx, target, name);
			return bind_transform_feedback_reenter(ctx, target, name);
		} END_MACH_OVERRIDE_PTR(bind_transform_feedback, obj->disp.bind_transform_feedback);

		if (err)
			log(LOG_ERR, "Failed to override bind_transform_feedback: %i", err);

		MACH_OVERRIDE(void,gen_transform_feedbacks,(GLIContext ctx, GLsizei n, GLuint* ids), err ) {
			file_log("gen_transform_feedbacks called: ctx (GLIContext : %p) n (GLsizei : %i) ids (GLuint* : %p)\n", ctx, n, ids);
			return gen_transform_feedbacks_reenter(ctx, n, ids);
		} END_MACH_OVERRIDE_PTR(gen_transform_feedbacks, obj->disp.gen_transform_feedbacks);

		if (err)
			log(LOG_ERR, "Failed to override gen_transform_feedbacks: %i", err);

		MACH_OVERRIDE(void,delete_transform_feedbacks,(GLIContext ctx, GLsizei n, const GLuint* ids), err ) {
			file_log("delete_transform_feedbacks called: ctx (GLIContext : %p) n (GLsizei : %i) ids (const GLuint* : %p)\n", ctx, n, ids);
			return delete_transform_feedbacks_reenter(ctx, n, ids);
		} END_MACH_OVERRIDE_PTR(delete_transform_feedbacks, obj->disp.delete_transform_feedbacks);

		if (err)
			log(LOG_ERR, "Failed to override delete_transform_feedbacks: %i", err);

		MACH_OVERRIDE(void,pause_transform_feedback,(GLIContext ctx), err ) {
			file_log("pause_transform_feedback called: ctx (GLIContext : %p)\n", ctx);
			return pause_transform_feedback_reenter(ctx);
		} END_MACH_OVERRIDE_PTR(pause_transform_feedback, obj->disp.pause_transform_feedback);

		if (err)
			log(LOG_ERR, "Failed to override pause_transform_feedback: %i", err);

		MACH_OVERRIDE(void,resume_transform_feedback,(GLIContext ctx), err ) {
			file_log("resume_transform_feedback called: ctx (GLIContext : %p)\n", ctx);
			return resume_transform_feedback_reenter(ctx);
		} END_MACH_OVERRIDE_PTR(resume_transform_feedback, obj->disp.resume_transform_feedback);

		if (err)
			log(LOG_ERR, "Failed to override resume_transform_feedback: %i", err);

		MACH_OVERRIDE(GLboolean,is_transform_feedback,(GLIContext ctx, GLuint name), err ) {
			file_log("is_transform_feedback called: ctx (GLIContext : %p) name (GLuint : %u)\n", ctx, name);
			GLboolean result = is_transform_feedback_reenter(ctx, name);
			return result;
		} END_MACH_OVERRIDE_PTR(is_transform_feedback, obj->disp.is_transform_feedback);

		if (err)
			log(LOG_ERR, "Failed to override is_transform_feedback: %i", err);

		MACH_OVERRIDE(void,draw_transform_feedback,(GLIContext ctx, GLenum mode, GLuint name), err ) {
			file_log("draw_transform_feedback called: ctx (GLIContext : %p) mode (GLenum : %s) name (GLuint : %u)\n", ctx, GLenumToString(mode).c_str(), name);
			OpenGL::StateMachine::Shared.draw_transform_feedback(ctx, mode, name);
			return draw_transform_feedback_reenter(ctx, mode, name);
		} END_MACH_OVERRIDE_PTR(draw_transform_feedback, obj->disp.draw_transform_feedback);

		if (err)
			log(LOG_ERR, "Failed to override draw_transform_feedback: %i", err);

		MACH_OVERRIDE(void,begin_query_indexed,(GLIContext ctx, GLenum target, GLuint index, GLuint id), err ) {
			file_log("begin_query_indexed called: ctx (GLIContext : %p) target (GLenum : %s) index (GLuint : %u) id (GLuint : %u)\n", ctx, GLenumToString(target).c_str(), index, id);
			return begin_query_indexed_reenter(ctx, target, index, id);
		} END_MACH_OVERRIDE_PTR(begin_query_indexed, obj->disp.begin_query_indexed);

		if (err)
			log(LOG_ERR, "Failed to override begin_query_indexed: %i", err);

		MACH_OVERRIDE(void,end_query_indexed,(GLIContext ctx, GLenum target, GLuint index), err ) {
			file_log("end_query_indexed called: ctx (GLIContext : %p) target (GLenum : %s) index (GLuint : %u)\n", ctx, GLenumToString(target).c_str(), index);
			return end_query_indexed_reenter(ctx, target, index);
		} END_MACH_OVERRIDE_PTR(end_query_indexed, obj->disp.end_query_indexed);

		if (err)
			log(LOG_ERR, "Failed to override end_query_indexed: %i", err);

		MACH_OVERRIDE(void,get_query_indexediv,(GLIContext ctx, GLenum target, GLuint index, GLenum pname, GLint *params), err ) {
			file_log("get_query_indexediv called: ctx (GLIContext : %p) target (GLenum : %s) index (GLuint : %u) pname (GLenum : %s) params (GLint* : %p)\n", ctx, GLenumToString(target).c_str(), index, GLenumToString(pname).c_str(), params);
			return get_query_indexediv_reenter(ctx, target, index, pname, params);
		} END_MACH_OVERRIDE_PTR(get_query_indexediv, obj->disp.get_query_indexediv);

		if (err)
			log(LOG_ERR, "Failed to override get_query_indexediv: %i", err);

		MACH_OVERRIDE(void,draw_transform_feedback_stream,(GLIContext ctx, GLenum mode, GLuint name, GLuint stream), err ) {
			file_log("draw_transform_feedback_stream called: ctx (GLIContext : %p) mode (GLenum : %s) name (GLuint : %u) stream (GLuint : %u)\n", ctx, GLenumToString(mode).c_str(), name, stream);
			OpenGL::StateMachine::Shared.draw_transform_feedback_stream(ctx, mode, name, stream);
			return draw_transform_feedback_stream_reenter(ctx, mode, name, stream);
		} END_MACH_OVERRIDE_PTR(draw_transform_feedback_stream, obj->disp.draw_transform_feedback_stream);

		if (err)
			log(LOG_ERR, "Failed to override draw_transform_feedback_stream: %i", err);

		MACH_OVERRIDE(void,program_uniform1d,(GLIContext ctx, GLuint program, GLint location, GLdouble x), err ) {
			file_log("program_uniform1d called: ctx (GLIContext : %p) program (GLuint : %u) location (GLint : %i) x (GLdouble : %f)\n", ctx, program, location, x);
			return program_uniform1d_reenter(ctx, program, location, x);
		} END_MACH_OVERRIDE_PTR(program_uniform1d, obj->disp.program_uniform1d);

		if (err)
			log(LOG_ERR, "Failed to override program_uniform1d: %i", err);

		MACH_OVERRIDE(void,program_uniform2d,(GLIContext ctx, GLuint program, GLint location, GLdouble x, GLdouble y), err ) {
			file_log("program_uniform2d called: ctx (GLIContext : %p) program (GLuint : %u) location (GLint : %i) x (GLdouble : %f) y (GLdouble : %f)\n", ctx, program, location, x, y);
			return program_uniform2d_reenter(ctx, program, location, x, y);
		} END_MACH_OVERRIDE_PTR(program_uniform2d, obj->disp.program_uniform2d);

		if (err)
			log(LOG_ERR, "Failed to override program_uniform2d: %i", err);

		MACH_OVERRIDE(void,program_uniform3d,(GLIContext ctx, GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z), err ) {
			file_log("program_uniform3d called: ctx (GLIContext : %p) program (GLuint : %u) location (GLint : %i) x (GLdouble : %f) y (GLdouble : %f) z (GLdouble : %f)\n", ctx, program, location, x, y, z);
			return program_uniform3d_reenter(ctx, program, location, x, y, z);
		} END_MACH_OVERRIDE_PTR(program_uniform3d, obj->disp.program_uniform3d);

		if (err)
			log(LOG_ERR, "Failed to override program_uniform3d: %i", err);

		MACH_OVERRIDE(void,program_uniform4d,(GLIContext ctx, GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w), err ) {
			file_log("program_uniform4d called: ctx (GLIContext : %p) program (GLuint : %u) location (GLint : %i) x (GLdouble : %f) y (GLdouble : %f) z (GLdouble : %f) w (GLdouble : %f)\n", ctx, program, location, x, y, z, w);
			return program_uniform4d_reenter(ctx, program, location, x, y, z, w);
		} END_MACH_OVERRIDE_PTR(program_uniform4d, obj->disp.program_uniform4d);

		if (err)
			log(LOG_ERR, "Failed to override program_uniform4d: %i", err);

		MACH_OVERRIDE(void,program_uniform1dv,(GLIContext ctx, GLuint program, GLint location, GLsizei count, const GLdouble *value), err ) {
			file_log("program_uniform1dv called: ctx (GLIContext : %p) program (GLuint : %u) location (GLint : %i) count (GLsizei : %i) value (const GLdouble* : %p)\n", ctx, program, location, count, value);
			return program_uniform1dv_reenter(ctx, program, location, count, value);
		} END_MACH_OVERRIDE_PTR(program_uniform1dv, obj->disp.program_uniform1dv);

		if (err)
			log(LOG_ERR, "Failed to override program_uniform1dv: %i", err);

		MACH_OVERRIDE(void,program_uniform2dv,(GLIContext ctx, GLuint program, GLint location, GLsizei count, const GLdouble *value), err ) {
			file_log("program_uniform2dv called: ctx (GLIContext : %p) program (GLuint : %u) location (GLint : %i) count (GLsizei : %i) value (const GLdouble* : %p)\n", ctx, program, location, count, value);
			return program_uniform2dv_reenter(ctx, program, location, count, value);
		} END_MACH_OVERRIDE_PTR(program_uniform2dv, obj->disp.program_uniform2dv);

		if (err)
			log(LOG_ERR, "Failed to override program_uniform2dv: %i", err);

		MACH_OVERRIDE(void,program_uniform3dv,(GLIContext ctx, GLuint program, GLint location, GLsizei count, const GLdouble *value), err ) {
			file_log("program_uniform3dv called: ctx (GLIContext : %p) program (GLuint : %u) location (GLint : %i) count (GLsizei : %i) value (const GLdouble* : %p)\n", ctx, program, location, count, value);
			return program_uniform3dv_reenter(ctx, program, location, count, value);
		} END_MACH_OVERRIDE_PTR(program_uniform3dv, obj->disp.program_uniform3dv);

		if (err)
			log(LOG_ERR, "Failed to override program_uniform3dv: %i", err);

		MACH_OVERRIDE(void,program_uniform4dv,(GLIContext ctx, GLuint program, GLint location, GLsizei count, const GLdouble *value), err ) {
			file_log("program_uniform4dv called: ctx (GLIContext : %p) program (GLuint : %u) location (GLint : %i) count (GLsizei : %i) value (const GLdouble* : %p)\n", ctx, program, location, count, value);
			return program_uniform4dv_reenter(ctx, program, location, count, value);
		} END_MACH_OVERRIDE_PTR(program_uniform4dv, obj->disp.program_uniform4dv);

		if (err)
			log(LOG_ERR, "Failed to override program_uniform4dv: %i", err);

		MACH_OVERRIDE(void,program_uniform_matrix2dv,(GLIContext ctx, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value), err ) {
			file_log("program_uniform_matrix2dv called: ctx (GLIContext : %p) program (GLuint : %u) location (GLint : %i) count (GLsizei : %i) transpose (GLboolean : %i) value (const GLdouble* : %p)\n", ctx, program, location, count, transpose, value);
			return program_uniform_matrix2dv_reenter(ctx, program, location, count, transpose, value);
		} END_MACH_OVERRIDE_PTR(program_uniform_matrix2dv, obj->disp.program_uniform_matrix2dv);

		if (err)
			log(LOG_ERR, "Failed to override program_uniform_matrix2dv: %i", err);

		MACH_OVERRIDE(void,program_uniform_matrix3dv,(GLIContext ctx, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value), err ) {
			file_log("program_uniform_matrix3dv called: ctx (GLIContext : %p) program (GLuint : %u) location (GLint : %i) count (GLsizei : %i) transpose (GLboolean : %i) value (const GLdouble* : %p)\n", ctx, program, location, count, transpose, value);
			return program_uniform_matrix3dv_reenter(ctx, program, location, count, transpose, value);
		} END_MACH_OVERRIDE_PTR(program_uniform_matrix3dv, obj->disp.program_uniform_matrix3dv);

		if (err)
			log(LOG_ERR, "Failed to override program_uniform_matrix3dv: %i", err);

		MACH_OVERRIDE(void,program_uniform_matrix4dv,(GLIContext ctx, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value), err ) {
			file_log("program_uniform_matrix4dv called: ctx (GLIContext : %p) program (GLuint : %u) location (GLint : %i) count (GLsizei : %i) transpose (GLboolean : %i) value (const GLdouble* : %p)\n", ctx, program, location, count, transpose, value);
			return program_uniform_matrix4dv_reenter(ctx, program, location, count, transpose, value);
		} END_MACH_OVERRIDE_PTR(program_uniform_matrix4dv, obj->disp.program_uniform_matrix4dv);

		if (err)
			log(LOG_ERR, "Failed to override program_uniform_matrix4dv: %i", err);

		MACH_OVERRIDE(void,program_uniform_matrix2x3dv,(GLIContext ctx, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value), err ) {
			file_log("program_uniform_matrix2x3dv called: ctx (GLIContext : %p) program (GLuint : %u) location (GLint : %i) count (GLsizei : %i) transpose (GLboolean : %i) value (const GLdouble* : %p)\n", ctx, program, location, count, transpose, value);
			return program_uniform_matrix2x3dv_reenter(ctx, program, location, count, transpose, value);
		} END_MACH_OVERRIDE_PTR(program_uniform_matrix2x3dv, obj->disp.program_uniform_matrix2x3dv);

		if (err)
			log(LOG_ERR, "Failed to override program_uniform_matrix2x3dv: %i", err);

		MACH_OVERRIDE(void,program_uniform_matrix3x2dv,(GLIContext ctx, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value), err ) {
			file_log("program_uniform_matrix3x2dv called: ctx (GLIContext : %p) program (GLuint : %u) location (GLint : %i) count (GLsizei : %i) transpose (GLboolean : %i) value (const GLdouble* : %p)\n", ctx, program, location, count, transpose, value);
			return program_uniform_matrix3x2dv_reenter(ctx, program, location, count, transpose, value);
		} END_MACH_OVERRIDE_PTR(program_uniform_matrix3x2dv, obj->disp.program_uniform_matrix3x2dv);

		if (err)
			log(LOG_ERR, "Failed to override program_uniform_matrix3x2dv: %i", err);

		MACH_OVERRIDE(void,program_uniform_matrix2x4dv,(GLIContext ctx, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value), err ) {
			file_log("program_uniform_matrix2x4dv called: ctx (GLIContext : %p) program (GLuint : %u) location (GLint : %i) count (GLsizei : %i) transpose (GLboolean : %i) value (const GLdouble* : %p)\n", ctx, program, location, count, transpose, value);
			return program_uniform_matrix2x4dv_reenter(ctx, program, location, count, transpose, value);
		} END_MACH_OVERRIDE_PTR(program_uniform_matrix2x4dv, obj->disp.program_uniform_matrix2x4dv);

		if (err)
			log(LOG_ERR, "Failed to override program_uniform_matrix2x4dv: %i", err);

		MACH_OVERRIDE(void,program_uniform_matrix4x2dv,(GLIContext ctx, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value), err ) {
			file_log("program_uniform_matrix4x2dv called: ctx (GLIContext : %p) program (GLuint : %u) location (GLint : %i) count (GLsizei : %i) transpose (GLboolean : %i) value (const GLdouble* : %p)\n", ctx, program, location, count, transpose, value);
			return program_uniform_matrix4x2dv_reenter(ctx, program, location, count, transpose, value);
		} END_MACH_OVERRIDE_PTR(program_uniform_matrix4x2dv, obj->disp.program_uniform_matrix4x2dv);

		if (err)
			log(LOG_ERR, "Failed to override program_uniform_matrix4x2dv: %i", err);

		MACH_OVERRIDE(void,program_uniform_matrix3x4dv,(GLIContext ctx, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value), err ) {
			file_log("program_uniform_matrix3x4dv called: ctx (GLIContext : %p) program (GLuint : %u) location (GLint : %i) count (GLsizei : %i) transpose (GLboolean : %i) value (const GLdouble* : %p)\n", ctx, program, location, count, transpose, value);
			return program_uniform_matrix3x4dv_reenter(ctx, program, location, count, transpose, value);
		} END_MACH_OVERRIDE_PTR(program_uniform_matrix3x4dv, obj->disp.program_uniform_matrix3x4dv);

		if (err)
			log(LOG_ERR, "Failed to override program_uniform_matrix3x4dv: %i", err);

		MACH_OVERRIDE(void,program_uniform_matrix4x3dv,(GLIContext ctx, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value), err ) {
			file_log("program_uniform_matrix4x3dv called: ctx (GLIContext : %p) program (GLuint : %u) location (GLint : %i) count (GLsizei : %i) transpose (GLboolean : %i) value (const GLdouble* : %p)\n", ctx, program, location, count, transpose, value);
			return program_uniform_matrix4x3dv_reenter(ctx, program, location, count, transpose, value);
		} END_MACH_OVERRIDE_PTR(program_uniform_matrix4x3dv, obj->disp.program_uniform_matrix4x3dv);

		if (err)
			log(LOG_ERR, "Failed to override program_uniform_matrix4x3dv: %i", err);

		MACH_OVERRIDE(void,uniform1d,(GLIContext ctx, GLint location, GLdouble x), err ) {
			file_log("uniform1d called: ctx (GLIContext : %p) location (GLint : %i) x (GLdouble : %f)\n", ctx, location, x);
			return uniform1d_reenter(ctx, location, x);
		} END_MACH_OVERRIDE_PTR(uniform1d, obj->disp.uniform1d);

		if (err)
			log(LOG_ERR, "Failed to override uniform1d: %i", err);

		MACH_OVERRIDE(void,uniform2d,(GLIContext ctx, GLint location, GLdouble x, GLdouble y), err ) {
			file_log("uniform2d called: ctx (GLIContext : %p) location (GLint : %i) x (GLdouble : %f) y (GLdouble : %f)\n", ctx, location, x, y);
			return uniform2d_reenter(ctx, location, x, y);
		} END_MACH_OVERRIDE_PTR(uniform2d, obj->disp.uniform2d);

		if (err)
			log(LOG_ERR, "Failed to override uniform2d: %i", err);

		MACH_OVERRIDE(void,uniform3d,(GLIContext ctx, GLint location, GLdouble x, GLdouble y, GLdouble z), err ) {
			file_log("uniform3d called: ctx (GLIContext : %p) location (GLint : %i) x (GLdouble : %f) y (GLdouble : %f) z (GLdouble : %f)\n", ctx, location, x, y, z);
			return uniform3d_reenter(ctx, location, x, y, z);
		} END_MACH_OVERRIDE_PTR(uniform3d, obj->disp.uniform3d);

		if (err)
			log(LOG_ERR, "Failed to override uniform3d: %i", err);

		MACH_OVERRIDE(void,uniform4d,(GLIContext ctx, GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w), err ) {
			file_log("uniform4d called: ctx (GLIContext : %p) location (GLint : %i) x (GLdouble : %f) y (GLdouble : %f) z (GLdouble : %f) w (GLdouble : %f)\n", ctx, location, x, y, z, w);
			return uniform4d_reenter(ctx, location, x, y, z, w);
		} END_MACH_OVERRIDE_PTR(uniform4d, obj->disp.uniform4d);

		if (err)
			log(LOG_ERR, "Failed to override uniform4d: %i", err);

		MACH_OVERRIDE(void,uniform1dv,(GLIContext ctx, GLint location, GLsizei count, const GLdouble *value), err ) {
			file_log("uniform1dv called: ctx (GLIContext : %p) location (GLint : %i) count (GLsizei : %i) value (const GLdouble* : %p)\n", ctx, location, count, value);
			return uniform1dv_reenter(ctx, location, count, value);
		} END_MACH_OVERRIDE_PTR(uniform1dv, obj->disp.uniform1dv);

		if (err)
			log(LOG_ERR, "Failed to override uniform1dv: %i", err);

		MACH_OVERRIDE(void,uniform2dv,(GLIContext ctx, GLint location, GLsizei count, const GLdouble *value), err ) {
			file_log("uniform2dv called: ctx (GLIContext : %p) location (GLint : %i) count (GLsizei : %i) value (const GLdouble* : %p)\n", ctx, location, count, value);
			return uniform2dv_reenter(ctx, location, count, value);
		} END_MACH_OVERRIDE_PTR(uniform2dv, obj->disp.uniform2dv);

		if (err)
			log(LOG_ERR, "Failed to override uniform2dv: %i", err);

		MACH_OVERRIDE(void,uniform3dv,(GLIContext ctx, GLint location, GLsizei count, const GLdouble *value), err ) {
			file_log("uniform3dv called: ctx (GLIContext : %p) location (GLint : %i) count (GLsizei : %i) value (const GLdouble* : %p)\n", ctx, location, count, value);
			return uniform3dv_reenter(ctx, location, count, value);
		} END_MACH_OVERRIDE_PTR(uniform3dv, obj->disp.uniform3dv);

		if (err)
			log(LOG_ERR, "Failed to override uniform3dv: %i", err);

		MACH_OVERRIDE(void,uniform4dv,(GLIContext ctx, GLint location, GLsizei count, const GLdouble *value), err ) {
			file_log("uniform4dv called: ctx (GLIContext : %p) location (GLint : %i) count (GLsizei : %i) value (const GLdouble* : %p)\n", ctx, location, count, value);
			return uniform4dv_reenter(ctx, location, count, value);
		} END_MACH_OVERRIDE_PTR(uniform4dv, obj->disp.uniform4dv);

		if (err)
			log(LOG_ERR, "Failed to override uniform4dv: %i", err);

		MACH_OVERRIDE(void,uniform_matrix2dv,(GLIContext ctx, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value), err ) {
			file_log("uniform_matrix2dv called: ctx (GLIContext : %p) location (GLint : %i) count (GLsizei : %i) transpose (GLboolean : %i) value (const GLdouble* : %p)\n", ctx, location, count, transpose, value);
			return uniform_matrix2dv_reenter(ctx, location, count, transpose, value);
		} END_MACH_OVERRIDE_PTR(uniform_matrix2dv, obj->disp.uniform_matrix2dv);

		if (err)
			log(LOG_ERR, "Failed to override uniform_matrix2dv: %i", err);

		MACH_OVERRIDE(void,uniform_matrix3dv,(GLIContext ctx, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value), err ) {
			file_log("uniform_matrix3dv called: ctx (GLIContext : %p) location (GLint : %i) count (GLsizei : %i) transpose (GLboolean : %i) value (const GLdouble* : %p)\n", ctx, location, count, transpose, value);
			return uniform_matrix3dv_reenter(ctx, location, count, transpose, value);
		} END_MACH_OVERRIDE_PTR(uniform_matrix3dv, obj->disp.uniform_matrix3dv);

		if (err)
			log(LOG_ERR, "Failed to override uniform_matrix3dv: %i", err);

		MACH_OVERRIDE(void,uniform_matrix4dv,(GLIContext ctx, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value), err ) {
			file_log("uniform_matrix4dv called: ctx (GLIContext : %p) location (GLint : %i) count (GLsizei : %i) transpose (GLboolean : %i) value (const GLdouble* : %p)\n", ctx, location, count, transpose, value);
			return uniform_matrix4dv_reenter(ctx, location, count, transpose, value);
		} END_MACH_OVERRIDE_PTR(uniform_matrix4dv, obj->disp.uniform_matrix4dv);

		if (err)
			log(LOG_ERR, "Failed to override uniform_matrix4dv: %i", err);

		MACH_OVERRIDE(void,uniform_matrix2x3dv,(GLIContext ctx, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value), err ) {
			file_log("uniform_matrix2x3dv called: ctx (GLIContext : %p) location (GLint : %i) count (GLsizei : %i) transpose (GLboolean : %i) value (const GLdouble* : %p)\n", ctx, location, count, transpose, value);
			return uniform_matrix2x3dv_reenter(ctx, location, count, transpose, value);
		} END_MACH_OVERRIDE_PTR(uniform_matrix2x3dv, obj->disp.uniform_matrix2x3dv);

		if (err)
			log(LOG_ERR, "Failed to override uniform_matrix2x3dv: %i", err);

		MACH_OVERRIDE(void,uniform_matrix3x2dv,(GLIContext ctx, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value), err ) {
			file_log("uniform_matrix3x2dv called: ctx (GLIContext : %p) location (GLint : %i) count (GLsizei : %i) transpose (GLboolean : %i) value (const GLdouble* : %p)\n", ctx, location, count, transpose, value);
			return uniform_matrix3x2dv_reenter(ctx, location, count, transpose, value);
		} END_MACH_OVERRIDE_PTR(uniform_matrix3x2dv, obj->disp.uniform_matrix3x2dv);

		if (err)
			log(LOG_ERR, "Failed to override uniform_matrix3x2dv: %i", err);

		MACH_OVERRIDE(void,uniform_matrix2x4dv,(GLIContext ctx, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value), err ) {
			file_log("uniform_matrix2x4dv called: ctx (GLIContext : %p) location (GLint : %i) count (GLsizei : %i) transpose (GLboolean : %i) value (const GLdouble* : %p)\n", ctx, location, count, transpose, value);
			return uniform_matrix2x4dv_reenter(ctx, location, count, transpose, value);
		} END_MACH_OVERRIDE_PTR(uniform_matrix2x4dv, obj->disp.uniform_matrix2x4dv);

		if (err)
			log(LOG_ERR, "Failed to override uniform_matrix2x4dv: %i", err);

		MACH_OVERRIDE(void,uniform_matrix4x2dv,(GLIContext ctx, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value), err ) {
			file_log("uniform_matrix4x2dv called: ctx (GLIContext : %p) location (GLint : %i) count (GLsizei : %i) transpose (GLboolean : %i) value (const GLdouble* : %p)\n", ctx, location, count, transpose, value);
			return uniform_matrix4x2dv_reenter(ctx, location, count, transpose, value);
		} END_MACH_OVERRIDE_PTR(uniform_matrix4x2dv, obj->disp.uniform_matrix4x2dv);

		if (err)
			log(LOG_ERR, "Failed to override uniform_matrix4x2dv: %i", err);

		MACH_OVERRIDE(void,uniform_matrix3x4dv,(GLIContext ctx, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value), err ) {
			file_log("uniform_matrix3x4dv called: ctx (GLIContext : %p) location (GLint : %i) count (GLsizei : %i) transpose (GLboolean : %i) value (const GLdouble* : %p)\n", ctx, location, count, transpose, value);
			return uniform_matrix3x4dv_reenter(ctx, location, count, transpose, value);
		} END_MACH_OVERRIDE_PTR(uniform_matrix3x4dv, obj->disp.uniform_matrix3x4dv);

		if (err)
			log(LOG_ERR, "Failed to override uniform_matrix3x4dv: %i", err);

		MACH_OVERRIDE(void,uniform_matrix4x3dv,(GLIContext ctx, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value), err ) {
			file_log("uniform_matrix4x3dv called: ctx (GLIContext : %p) location (GLint : %i) count (GLsizei : %i) transpose (GLboolean : %i) value (const GLdouble* : %p)\n", ctx, location, count, transpose, value);
			return uniform_matrix4x3dv_reenter(ctx, location, count, transpose, value);
		} END_MACH_OVERRIDE_PTR(uniform_matrix4x3dv, obj->disp.uniform_matrix4x3dv);

		if (err)
			log(LOG_ERR, "Failed to override uniform_matrix4x3dv: %i", err);

		MACH_OVERRIDE(void,get_uniformdv,(GLIContext ctx, GLuint program_obj, GLint location, GLdouble *params), err ) {
			file_log("get_uniformdv called: ctx (GLIContext : %p) program_obj (GLuint : %u) location (GLint : %i) params (GLdouble* : %p)\n", ctx, program_obj, location, params);
			return get_uniformdv_reenter(ctx, program_obj, location, params);
		} END_MACH_OVERRIDE_PTR(get_uniformdv, obj->disp.get_uniformdv);

		if (err)
			log(LOG_ERR, "Failed to override get_uniformdv: %i", err);

		MACH_OVERRIDE(void,vertex_attribl1d,(GLIContext ctx, GLuint index, GLdouble x), err ) {
			file_log("vertex_attribl1d called: ctx (GLIContext : %p) index (GLuint : %u) x (GLdouble : %f)\n", ctx, index, x);
			return vertex_attribl1d_reenter(ctx, index, x);
		} END_MACH_OVERRIDE_PTR(vertex_attribl1d, obj->disp.vertex_attribl1d);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attribl1d: %i", err);

		MACH_OVERRIDE(void,vertex_attribl2d,(GLIContext ctx, GLuint index, GLdouble x, GLdouble y), err ) {
			file_log("vertex_attribl2d called: ctx (GLIContext : %p) index (GLuint : %u) x (GLdouble : %f) y (GLdouble : %f)\n", ctx, index, x, y);
			return vertex_attribl2d_reenter(ctx, index, x, y);
		} END_MACH_OVERRIDE_PTR(vertex_attribl2d, obj->disp.vertex_attribl2d);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attribl2d: %i", err);

		MACH_OVERRIDE(void,vertex_attribl3d,(GLIContext ctx, GLuint index, GLdouble x, GLdouble y, GLdouble z), err ) {
			file_log("vertex_attribl3d called: ctx (GLIContext : %p) index (GLuint : %u) x (GLdouble : %f) y (GLdouble : %f) z (GLdouble : %f)\n", ctx, index, x, y, z);
			return vertex_attribl3d_reenter(ctx, index, x, y, z);
		} END_MACH_OVERRIDE_PTR(vertex_attribl3d, obj->disp.vertex_attribl3d);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attribl3d: %i", err);

		MACH_OVERRIDE(void,vertex_attribl4d,(GLIContext ctx, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w), err ) {
			file_log("vertex_attribl4d called: ctx (GLIContext : %p) index (GLuint : %u) x (GLdouble : %f) y (GLdouble : %f) z (GLdouble : %f) w (GLdouble : %f)\n", ctx, index, x, y, z, w);
			return vertex_attribl4d_reenter(ctx, index, x, y, z, w);
		} END_MACH_OVERRIDE_PTR(vertex_attribl4d, obj->disp.vertex_attribl4d);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attribl4d: %i", err);

		MACH_OVERRIDE(void,vertex_attribl1dv,(GLIContext ctx, GLuint index, const GLdouble *v), err ) {
			file_log("vertex_attribl1dv called: ctx (GLIContext : %p) index (GLuint : %u) v (const GLdouble* : %p)\n", ctx, index, v);
			return vertex_attribl1dv_reenter(ctx, index, v);
		} END_MACH_OVERRIDE_PTR(vertex_attribl1dv, obj->disp.vertex_attribl1dv);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attribl1dv: %i", err);

		MACH_OVERRIDE(void,vertex_attribl2dv,(GLIContext ctx, GLuint index, const GLdouble *v), err ) {
			file_log("vertex_attribl2dv called: ctx (GLIContext : %p) index (GLuint : %u) v (const GLdouble* : %p)\n", ctx, index, v);
			return vertex_attribl2dv_reenter(ctx, index, v);
		} END_MACH_OVERRIDE_PTR(vertex_attribl2dv, obj->disp.vertex_attribl2dv);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attribl2dv: %i", err);

		MACH_OVERRIDE(void,vertex_attribl3dv,(GLIContext ctx, GLuint index, const GLdouble *v), err ) {
			file_log("vertex_attribl3dv called: ctx (GLIContext : %p) index (GLuint : %u) v (const GLdouble* : %p)\n", ctx, index, v);
			return vertex_attribl3dv_reenter(ctx, index, v);
		} END_MACH_OVERRIDE_PTR(vertex_attribl3dv, obj->disp.vertex_attribl3dv);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attribl3dv: %i", err);

		MACH_OVERRIDE(void,vertex_attribl4dv,(GLIContext ctx, GLuint index, const GLdouble *v), err ) {
			file_log("vertex_attribl4dv called: ctx (GLIContext : %p) index (GLuint : %u) v (const GLdouble* : %p)\n", ctx, index, v);
			return vertex_attribl4dv_reenter(ctx, index, v);
		} END_MACH_OVERRIDE_PTR(vertex_attribl4dv, obj->disp.vertex_attribl4dv);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attribl4dv: %i", err);

		MACH_OVERRIDE(void,vertex_attrib_lpointer,(GLIContext ctx, GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer), err ) {
			file_log("vertex_attrib_lpointer called: ctx (GLIContext : %p) index (GLuint : %u) size (GLint : %i) type (GLenum : %s) stride (GLsizei : %i) pointer (const void* : %p)\n", ctx, index, size, GLenumToString(type).c_str(), stride, pointer);
			return vertex_attrib_lpointer_reenter(ctx, index, size, type, stride, pointer);
		} END_MACH_OVERRIDE_PTR(vertex_attrib_lpointer, obj->disp.vertex_attrib_lpointer);

		if (err)
			log(LOG_ERR, "Failed to override vertex_attrib_lpointer: %i", err);

		MACH_OVERRIDE(void,get_vertex_attrib_ldv,(GLIContext ctx, GLuint index, GLenum pname, GLdouble *params), err ) {
			file_log("get_vertex_attrib_ldv called: ctx (GLIContext : %p) index (GLuint : %u) pname (GLenum : %s) params (GLdouble* : %p)\n", ctx, index, GLenumToString(pname).c_str(), params);
			return get_vertex_attrib_ldv_reenter(ctx, index, pname, params);
		} END_MACH_OVERRIDE_PTR(get_vertex_attrib_ldv, obj->disp.get_vertex_attrib_ldv);

		if (err)
			log(LOG_ERR, "Failed to override get_vertex_attrib_ldv: %i", err);

		MACH_OVERRIDE(GLint,get_subroutine_uniform_location,(GLIContext ctx, GLuint program, GLenum shadertype, const GLchar *name), err ) {
			file_log("get_subroutine_uniform_location called: ctx (GLIContext : %p) program (GLuint : %u) shadertype (GLenum : %s) name (const GLchar* : %p)\n", ctx, program, GLenumToString(shadertype).c_str(), name);
			GLint result = get_subroutine_uniform_location_reenter(ctx, program, shadertype, name);
			return result;
		} END_MACH_OVERRIDE_PTR(get_subroutine_uniform_location, obj->disp.get_subroutine_uniform_location);

		if (err)
			log(LOG_ERR, "Failed to override get_subroutine_uniform_location: %i", err);

		MACH_OVERRIDE(GLuint,get_subroutine_index,(GLIContext ctx, GLuint program, GLenum shadertype, const GLchar *name), err ) {
			file_log("get_subroutine_index called: ctx (GLIContext : %p) program (GLuint : %u) shadertype (GLenum : %s) name (const GLchar* : %p)\n", ctx, program, GLenumToString(shadertype).c_str(), name);
			GLuint result = get_subroutine_index_reenter(ctx, program, shadertype, name);
			return result;
		} END_MACH_OVERRIDE_PTR(get_subroutine_index, obj->disp.get_subroutine_index);

		if (err)
			log(LOG_ERR, "Failed to override get_subroutine_index: %i", err);

		MACH_OVERRIDE(void,get_active_subroutine_uniformiv,(GLIContext ctx, GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint *values), err ) {
			file_log("get_active_subroutine_uniformiv called: ctx (GLIContext : %p) program (GLuint : %u) shadertype (GLenum : %s) index (GLuint : %u) pname (GLenum : %s) values (GLint* : %p)\n", ctx, program, GLenumToString(shadertype).c_str(), index, GLenumToString(pname).c_str(), values);
			return get_active_subroutine_uniformiv_reenter(ctx, program, shadertype, index, pname, values);
		} END_MACH_OVERRIDE_PTR(get_active_subroutine_uniformiv, obj->disp.get_active_subroutine_uniformiv);

		if (err)
			log(LOG_ERR, "Failed to override get_active_subroutine_uniformiv: %i", err);

		MACH_OVERRIDE(void,get_active_subroutine_uniform_name,(GLIContext ctx, GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name), err ) {
			file_log("get_active_subroutine_uniform_name called: ctx (GLIContext : %p) program (GLuint : %u) shadertype (GLenum : %s) index (GLuint : %u) bufsize (GLsizei : %i) length (GLsizei* : %p) name (GLchar* : %p)\n", ctx, program, GLenumToString(shadertype).c_str(), index, bufsize, length, name);
			return get_active_subroutine_uniform_name_reenter(ctx, program, shadertype, index, bufsize, length, name);
		} END_MACH_OVERRIDE_PTR(get_active_subroutine_uniform_name, obj->disp.get_active_subroutine_uniform_name);

		if (err)
			log(LOG_ERR, "Failed to override get_active_subroutine_uniform_name: %i", err);

		MACH_OVERRIDE(void,get_active_subroutine_name,(GLIContext ctx, GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name), err ) {
			file_log("get_active_subroutine_name called: ctx (GLIContext : %p) program (GLuint : %u) shadertype (GLenum : %s) index (GLuint : %u) bufsize (GLsizei : %i) length (GLsizei* : %p) name (GLchar* : %p)\n", ctx, program, GLenumToString(shadertype).c_str(), index, bufsize, length, name);
			return get_active_subroutine_name_reenter(ctx, program, shadertype, index, bufsize, length, name);
		} END_MACH_OVERRIDE_PTR(get_active_subroutine_name, obj->disp.get_active_subroutine_name);

		if (err)
			log(LOG_ERR, "Failed to override get_active_subroutine_name: %i", err);

		MACH_OVERRIDE(void,uniform_subroutinesuiv,(GLIContext ctx, GLenum shadertype, GLsizei count, const GLuint *indices), err ) {
			file_log("uniform_subroutinesuiv called: ctx (GLIContext : %p) shadertype (GLenum : %s) count (GLsizei : %i) indices (const GLuint* : %p)\n", ctx, GLenumToString(shadertype).c_str(), count, indices);
			return uniform_subroutinesuiv_reenter(ctx, shadertype, count, indices);
		} END_MACH_OVERRIDE_PTR(uniform_subroutinesuiv, obj->disp.uniform_subroutinesuiv);

		if (err)
			log(LOG_ERR, "Failed to override uniform_subroutinesuiv: %i", err);

		MACH_OVERRIDE(void,get_uniform_subroutineuiv,(GLIContext ctx, GLenum shadertype, GLint location, GLuint *params), err ) {
			file_log("get_uniform_subroutineuiv called: ctx (GLIContext : %p) shadertype (GLenum : %s) location (GLint : %i) params (GLuint* : %p)\n", ctx, GLenumToString(shadertype).c_str(), location, params);
			return get_uniform_subroutineuiv_reenter(ctx, shadertype, location, params);
		} END_MACH_OVERRIDE_PTR(get_uniform_subroutineuiv, obj->disp.get_uniform_subroutineuiv);

		if (err)
			log(LOG_ERR, "Failed to override get_uniform_subroutineuiv: %i", err);

		MACH_OVERRIDE(void,get_program_stageiv,(GLIContext ctx, GLuint program, GLenum shadertype, GLenum pname, GLint *values), err ) {
			file_log("get_program_stageiv called: ctx (GLIContext : %p) program (GLuint : %u) shadertype (GLenum : %s) pname (GLenum : %s) values (GLint* : %p)\n", ctx, program, GLenumToString(shadertype).c_str(), GLenumToString(pname).c_str(), values);
			return get_program_stageiv_reenter(ctx, program, shadertype, pname, values);
		} END_MACH_OVERRIDE_PTR(get_program_stageiv, obj->disp.get_program_stageiv);

		if (err)
			log(LOG_ERR, "Failed to override get_program_stageiv: %i", err);

		MACH_OVERRIDE(void,get_internal_formativ,(GLIContext ctx, GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint* params), err ) {
			file_log("get_internal_formativ called: ctx (GLIContext : %p) target (GLenum : %s) internalformat (GLenum : %s) pname (GLenum : %s) bufSize (GLsizei : %i) params (GLint* : %p)\n", ctx, GLenumToString(target).c_str(), GLenumToString(internalformat).c_str(), GLenumToString(pname).c_str(), bufSize, params);
			return get_internal_formativ_reenter(ctx, target, internalformat, pname, bufSize, params);
		} END_MACH_OVERRIDE_PTR(get_internal_formativ, obj->disp.get_internal_formativ);

		if (err)
			log(LOG_ERR, "Failed to override get_internal_formativ: %i", err);

		MACH_OVERRIDE(void,tex_storage1D,(GLIContext ctx, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width), err ) {
			file_log("tex_storage1D called: ctx (GLIContext : %p) target (GLenum : %s) levels (GLsizei : %i) internalformat (GLenum : %s) width (GLsizei : %i)\n", ctx, GLenumToString(target).c_str(), levels, GLenumToString(internalformat).c_str(), width);
			return tex_storage1D_reenter(ctx, target, levels, internalformat, width);
		} END_MACH_OVERRIDE_PTR(tex_storage1D, obj->disp.tex_storage1D);

		if (err)
			log(LOG_ERR, "Failed to override tex_storage1D: %i", err);

		MACH_OVERRIDE(void,tex_storage2D,(GLIContext ctx, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height), err ) {
			file_log("tex_storage2D called: ctx (GLIContext : %p) target (GLenum : %s) levels (GLsizei : %i) internalformat (GLenum : %s) width (GLsizei : %i) height (GLsizei : %i)\n", ctx, GLenumToString(target).c_str(), levels, GLenumToString(internalformat).c_str(), width, height);
			return tex_storage2D_reenter(ctx, target, levels, internalformat, width, height);
		} END_MACH_OVERRIDE_PTR(tex_storage2D, obj->disp.tex_storage2D);

		if (err)
			log(LOG_ERR, "Failed to override tex_storage2D: %i", err);

		MACH_OVERRIDE(void,tex_storage3D,(GLIContext ctx, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth), err ) {
			file_log("tex_storage3D called: ctx (GLIContext : %p) target (GLenum : %s) levels (GLsizei : %i) internalformat (GLenum : %s) width (GLsizei : %i) height (GLsizei : %i) depth (GLsizei : %i)\n", ctx, GLenumToString(target).c_str(), levels, GLenumToString(internalformat).c_str(), width, height, depth);
			return tex_storage3D_reenter(ctx, target, levels, internalformat, width, height, depth);
		} END_MACH_OVERRIDE_PTR(tex_storage3D, obj->disp.tex_storage3D);

		if (err)
			log(LOG_ERR, "Failed to override tex_storage3D: %i", err);

		MACH_OVERRIDE(void,label_object_with_responsible_process_APPLE,(GLIContext ctx, GLenum type, GLuint name, GLint pid), err ) {
			file_log("label_object_with_responsible_process_APPLE called: ctx (GLIContext : %p) type (GLenum : %s) name (GLuint : %u) pid (GLint : %i)\n", ctx, GLenumToString(type).c_str(), name, pid);
			return label_object_with_responsible_process_APPLE_reenter(ctx, type, name, pid);
		} END_MACH_OVERRIDE_PTR(label_object_with_responsible_process_APPLE, obj->disp.label_object_with_responsible_process_APPLE);

		if (err)
			log(LOG_ERR, "Failed to override label_object_with_responsible_process_APPLE: %i", err);

		MACH_OVERRIDE(void,texture_barrier_NV,(GLIContext ctx), err ) {
			file_log("texture_barrier_NV called: ctx (GLIContext : %p)\n", ctx);
			return texture_barrier_NV_reenter(ctx);
		} END_MACH_OVERRIDE_PTR(texture_barrier_NV, obj->disp.texture_barrier_NV);

		if (err)
			log(LOG_ERR, "Failed to override texture_barrier_NV: %i", err);

		extern void unsuspend_all_threads();
		unsuspend_all_threads();
		
		log(LOG_NOTICE, "Finished overriding Context Function PTRs");
	}
}


void OverrideCGLGetContext()
{
	void* handle = dlopen("/System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries/libGL.dylib", RTLD_NOW);

	if (!handle)
		log(LOG_ERR, "Failed to open libGL.  %s", dlerror());

	void* opengl_function = dlsym(handle, "CGLGetCurrentContext");

	if (!opengl_function)
		log(LOG_ERR, "Failed to find _CGLGetCurrentContext.  %s", dlerror());

	kern_return_t err;
	MACH_OVERRIDE( CGLContextObj, CGLGetCurrentContext, (void), err ) {
		CGLContextObj obj = CGLGetCurrentContext_reenter();
		HandleCGLGetCurrentContext(obj);
		return obj;
	} END_MACH_OVERRIDE_PTR(CGLGetCurrentContext, opengl_function);

	if (err)
		log(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'CGLGetCurrentContext' %i", err);

	dlclose(handle);
}
