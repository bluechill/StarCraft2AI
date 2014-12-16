#include "OpenGLLogger.h"
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#include <syslog.h>
#include "mach_override.h"

extern OpenGLLogger logger;

void OverrideOpenGL()
{
	syslog(LOG_NOTICE, "OpenGLFileLogger: Overriding OpenGL2 calls");
	
	kern_return_t err;

	MACH_OVERRIDE(void, glAccum, (GLenum op, GLfloat value), err)
	{
		logger.glAccum(op, value);

		glAccum_reenter(op, value);
	} END_MACH_OVERRIDE(glAccum);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glAccum' %i", err);

	MACH_OVERRIDE(void, glAlphaFunc, (GLenum func, GLclampf ref), err)
	{
		logger.glAlphaFunc(func, ref);

		glAlphaFunc_reenter(func, ref);
	} END_MACH_OVERRIDE(glAlphaFunc);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glAlphaFunc' %i", err);

	MACH_OVERRIDE(GLboolean, glAreTexturesResident, (GLsizei n, const GLuint *textures, GLboolean *residences), err)
	{
		logger.glAreTexturesResident(n, textures, residences);

		return glAreTexturesResident_reenter(n, textures, residences);
	} END_MACH_OVERRIDE(glAreTexturesResident);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glAreTexturesResident' %i", err);

	MACH_OVERRIDE(void, glArrayElement, (GLint i), err)
	{
		logger.glArrayElement(i);

		glArrayElement_reenter(i);
	} END_MACH_OVERRIDE(glArrayElement);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glArrayElement' %i", err);

	MACH_OVERRIDE(void, glBegin, (GLenum mode), err)
	{
		logger.glBegin(mode);

		glBegin_reenter(mode);
	} END_MACH_OVERRIDE(glBegin);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glBegin' %i", err);

	MACH_OVERRIDE(void, glBindTexture, (GLenum target, GLuint texture), err)
	{
		logger.glBindTexture(target, texture);

		glBindTexture_reenter(target, texture);
	} END_MACH_OVERRIDE(glBindTexture);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glBindTexture' %i", err);

	MACH_OVERRIDE(void, glBitmap, (GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte *bitmap), err)
	{
		logger.glBitmap(width, height, xorig, yorig, xmove, ymove, bitmap);

		glBitmap_reenter(width, height, xorig, yorig, xmove, ymove, bitmap);
	} END_MACH_OVERRIDE(glBitmap);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glBitmap' %i", err);

	MACH_OVERRIDE(void, glBlendColor, (GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha), err)
	{
		logger.glBlendColor(red, green, blue, alpha);

		glBlendColor_reenter(red, green, blue, alpha);
	} END_MACH_OVERRIDE(glBlendColor);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glBlendColor' %i", err);

	MACH_OVERRIDE(void, glBlendEquation, (GLenum mode), err)
	{
		logger.glBlendEquation(mode);

		glBlendEquation_reenter(mode);
	} END_MACH_OVERRIDE(glBlendEquation);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glBlendEquation' %i", err);

	MACH_OVERRIDE(void, glBlendEquationSeparate, (GLenum modeRGB, GLenum modeAlpha), err)
	{
		logger.glBlendEquationSeparate(modeRGB, modeAlpha);

		glBlendEquationSeparate_reenter(modeRGB, modeAlpha);
	} END_MACH_OVERRIDE(glBlendEquationSeparate);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glBlendEquationSeparate' %i", err);

	MACH_OVERRIDE(void, glBlendFunc, (GLenum sfactor, GLenum dfactor), err)
	{
		logger.glBlendFunc(sfactor, dfactor);

		glBlendFunc_reenter(sfactor, dfactor);
	} END_MACH_OVERRIDE(glBlendFunc);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glBlendFunc' %i", err);

	MACH_OVERRIDE(void, glCallList, (GLuint list), err)
	{
		logger.glCallList(list);

		glCallList_reenter(list);
	} END_MACH_OVERRIDE(glCallList);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glCallList' %i", err);

	MACH_OVERRIDE(void, glCallLists, (GLsizei n, GLenum type, const GLvoid *lists), err)
	{
		logger.glCallLists(n, type, lists);

		glCallLists_reenter(n, type, lists);
	} END_MACH_OVERRIDE(glCallLists);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glCallLists' %i", err);

	MACH_OVERRIDE(void, glClear, (GLbitfield mask), err)
	{
		logger.glClear(mask);

		glClear_reenter(mask);
	} END_MACH_OVERRIDE(glClear);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glClear' %i", err);

	MACH_OVERRIDE(void, glClearAccum, (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha), err)
	{
		logger.glClearAccum(red, green, blue, alpha);

		glClearAccum_reenter(red, green, blue, alpha);
	} END_MACH_OVERRIDE(glClearAccum);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glClearAccum' %i", err);

	MACH_OVERRIDE(void, glClearColor, (GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha), err)
	{
		logger.glClearColor(red, green, blue, alpha);

		glClearColor_reenter(red, green, blue, alpha);
	} END_MACH_OVERRIDE(glClearColor);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glClearColor' %i", err);

	MACH_OVERRIDE(void, glClearDepth, (GLclampd depth), err)
	{
		logger.glClearDepth(depth);

		glClearDepth_reenter(depth);
	} END_MACH_OVERRIDE(glClearDepth);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glClearDepth' %i", err);

	MACH_OVERRIDE(void, glClearIndex, (GLfloat c), err)
	{
		logger.glClearIndex(c);

		glClearIndex_reenter(c);
	} END_MACH_OVERRIDE(glClearIndex);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glClearIndex' %i", err);

	MACH_OVERRIDE(void, glClearStencil, (GLint s), err)
	{
		logger.glClearStencil(s);

		glClearStencil_reenter(s);
	} END_MACH_OVERRIDE(glClearStencil);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glClearStencil' %i", err);

	MACH_OVERRIDE(void, glClipPlane, (GLenum plane, const GLdouble *equation), err)
	{
		logger.glClipPlane(plane, equation);

		glClipPlane_reenter(plane, equation);
	} END_MACH_OVERRIDE(glClipPlane);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glClipPlane' %i", err);

	MACH_OVERRIDE(void, glColor3b, (GLbyte red, GLbyte green, GLbyte blue), err)
	{
		logger.glColor3b(red, green, blue);

		glColor3b_reenter(red, green, blue);
	} END_MACH_OVERRIDE(glColor3b);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glColor3b' %i", err);

	MACH_OVERRIDE(void, glColor3bv, (const GLbyte *v), err)
	{
		logger.glColor3bv(v);

		glColor3bv_reenter(v);
	} END_MACH_OVERRIDE(glColor3bv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glColor3bv' %i", err);

	MACH_OVERRIDE(void, glColor3d, (GLdouble red, GLdouble green, GLdouble blue), err)
	{
		logger.glColor3d(red, green, blue);

		glColor3d_reenter(red, green, blue);
	} END_MACH_OVERRIDE(glColor3d);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glColor3d' %i", err);

	MACH_OVERRIDE(void, glColor3dv, (const GLdouble *v), err)
	{
		logger.glColor3dv(v);

		glColor3dv_reenter(v);
	} END_MACH_OVERRIDE(glColor3dv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glColor3dv' %i", err);

	MACH_OVERRIDE(void, glColor3f, (GLfloat red, GLfloat green, GLfloat blue), err)
	{
		logger.glColor3f(red, green, blue);

		glColor3f_reenter(red, green, blue);
	} END_MACH_OVERRIDE(glColor3f);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glColor3f' %i", err);

	MACH_OVERRIDE(void, glColor3fv, (const GLfloat *v), err)
	{
		logger.glColor3fv(v);

		glColor3fv_reenter(v);
	} END_MACH_OVERRIDE(glColor3fv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glColor3fv' %i", err);

	MACH_OVERRIDE(void, glColor3i, (GLint red, GLint green, GLint blue), err)
	{
		logger.glColor3i(red, green, blue);

		glColor3i_reenter(red, green, blue);
	} END_MACH_OVERRIDE(glColor3i);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glColor3i' %i", err);

	MACH_OVERRIDE(void, glColor3iv, (const GLint *v), err)
	{
		logger.glColor3iv(v);

		glColor3iv_reenter(v);
	} END_MACH_OVERRIDE(glColor3iv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glColor3iv' %i", err);

	MACH_OVERRIDE(void, glColor3s, (GLshort red, GLshort green, GLshort blue), err)
	{
		logger.glColor3s(red, green, blue);

		glColor3s_reenter(red, green, blue);
	} END_MACH_OVERRIDE(glColor3s);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glColor3s' %i", err);

	MACH_OVERRIDE(void, glColor3sv, (const GLshort *v), err)
	{
		logger.glColor3sv(v);

		glColor3sv_reenter(v);
	} END_MACH_OVERRIDE(glColor3sv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glColor3sv' %i", err);

	MACH_OVERRIDE(void, glColor3ub, (GLubyte red, GLubyte green, GLubyte blue), err)
	{
		logger.glColor3ub(red, green, blue);

		glColor3ub_reenter(red, green, blue);
	} END_MACH_OVERRIDE(glColor3ub);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glColor3ub' %i", err);

	MACH_OVERRIDE(void, glColor3ubv, (const GLubyte *v), err)
	{
		logger.glColor3ubv(v);

		glColor3ubv_reenter(v);
	} END_MACH_OVERRIDE(glColor3ubv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glColor3ubv' %i", err);

	MACH_OVERRIDE(void, glColor3ui, (GLuint red, GLuint green, GLuint blue), err)
	{
		logger.glColor3ui(red, green, blue);

		glColor3ui_reenter(red, green, blue);
	} END_MACH_OVERRIDE(glColor3ui);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glColor3ui' %i", err);

	MACH_OVERRIDE(void, glColor3uiv, (const GLuint *v), err)
	{
		logger.glColor3uiv(v);

		glColor3uiv_reenter(v);
	} END_MACH_OVERRIDE(glColor3uiv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glColor3uiv' %i", err);

	MACH_OVERRIDE(void, glColor3us, (GLushort red, GLushort green, GLushort blue), err)
	{
		logger.glColor3us(red, green, blue);

		glColor3us_reenter(red, green, blue);
	} END_MACH_OVERRIDE(glColor3us);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glColor3us' %i", err);

	MACH_OVERRIDE(void, glColor3usv, (const GLushort *v), err)
	{
		logger.glColor3usv(v);

		glColor3usv_reenter(v);
	} END_MACH_OVERRIDE(glColor3usv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glColor3usv' %i", err);

	MACH_OVERRIDE(void, glColor4b, (GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha), err)
	{
		logger.glColor4b(red, green, blue, alpha);

		glColor4b_reenter(red, green, blue, alpha);
	} END_MACH_OVERRIDE(glColor4b);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glColor4b' %i", err);

	MACH_OVERRIDE(void, glColor4bv, (const GLbyte *v), err)
	{
		logger.glColor4bv(v);

		glColor4bv_reenter(v);
	} END_MACH_OVERRIDE(glColor4bv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glColor4bv' %i", err);

	MACH_OVERRIDE(void, glColor4d, (GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha), err)
	{
		logger.glColor4d(red, green, blue, alpha);

		glColor4d_reenter(red, green, blue, alpha);
	} END_MACH_OVERRIDE(glColor4d);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glColor4d' %i", err);

	MACH_OVERRIDE(void, glColor4dv, (const GLdouble *v), err)
	{
		logger.glColor4dv(v);

		glColor4dv_reenter(v);
	} END_MACH_OVERRIDE(glColor4dv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glColor4dv' %i", err);

	MACH_OVERRIDE(void, glColor4f, (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha), err)
	{
		logger.glColor4f(red, green, blue, alpha);

		glColor4f_reenter(red, green, blue, alpha);
	} END_MACH_OVERRIDE(glColor4f);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glColor4f' %i", err);

	MACH_OVERRIDE(void, glColor4fv, (const GLfloat *v), err)
	{
		logger.glColor4fv(v);

		glColor4fv_reenter(v);
	} END_MACH_OVERRIDE(glColor4fv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glColor4fv' %i", err);

	MACH_OVERRIDE(void, glColor4i, (GLint red, GLint green, GLint blue, GLint alpha), err)
	{
		logger.glColor4i(red, green, blue, alpha);

		glColor4i_reenter(red, green, blue, alpha);
	} END_MACH_OVERRIDE(glColor4i);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glColor4i' %i", err);

	MACH_OVERRIDE(void, glColor4iv, (const GLint *v), err)
	{
		logger.glColor4iv(v);

		glColor4iv_reenter(v);
	} END_MACH_OVERRIDE(glColor4iv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glColor4iv' %i", err);

	MACH_OVERRIDE(void, glColor4s, (GLshort red, GLshort green, GLshort blue, GLshort alpha), err)
	{
		logger.glColor4s(red, green, blue, alpha);

		glColor4s_reenter(red, green, blue, alpha);
	} END_MACH_OVERRIDE(glColor4s);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glColor4s' %i", err);

	MACH_OVERRIDE(void, glColor4sv, (const GLshort *v), err)
	{
		logger.glColor4sv(v);

		glColor4sv_reenter(v);
	} END_MACH_OVERRIDE(glColor4sv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glColor4sv' %i", err);

	MACH_OVERRIDE(void, glColor4ub, (GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha), err)
	{
		logger.glColor4ub(red, green, blue, alpha);

		glColor4ub_reenter(red, green, blue, alpha);
	} END_MACH_OVERRIDE(glColor4ub);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glColor4ub' %i", err);

	MACH_OVERRIDE(void, glColor4ubv, (const GLubyte *v), err)
	{
		logger.glColor4ubv(v);

		glColor4ubv_reenter(v);
	} END_MACH_OVERRIDE(glColor4ubv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glColor4ubv' %i", err);

	MACH_OVERRIDE(void, glColor4ui, (GLuint red, GLuint green, GLuint blue, GLuint alpha), err)
	{
		logger.glColor4ui(red, green, blue, alpha);

		glColor4ui_reenter(red, green, blue, alpha);
	} END_MACH_OVERRIDE(glColor4ui);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glColor4ui' %i", err);

	MACH_OVERRIDE(void, glColor4uiv, (const GLuint *v), err)
	{
		logger.glColor4uiv(v);

		glColor4uiv_reenter(v);
	} END_MACH_OVERRIDE(glColor4uiv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glColor4uiv' %i", err);

	MACH_OVERRIDE(void, glColor4us, (GLushort red, GLushort green, GLushort blue, GLushort alpha), err)
	{
		logger.glColor4us(red, green, blue, alpha);

		glColor4us_reenter(red, green, blue, alpha);
	} END_MACH_OVERRIDE(glColor4us);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glColor4us' %i", err);

	MACH_OVERRIDE(void, glColor4usv, (const GLushort *v), err)
	{
		logger.glColor4usv(v);

		glColor4usv_reenter(v);
	} END_MACH_OVERRIDE(glColor4usv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glColor4usv' %i", err);

	MACH_OVERRIDE(void, glColorMask, (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha), err)
	{
		logger.glColorMask(red, green, blue, alpha);

		glColorMask_reenter(red, green, blue, alpha);
	} END_MACH_OVERRIDE(glColorMask);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glColorMask' %i", err);

	MACH_OVERRIDE(void, glColorMaterial, (GLenum face, GLenum mode), err)
	{
		logger.glColorMaterial(face, mode);

		glColorMaterial_reenter(face, mode);
	} END_MACH_OVERRIDE(glColorMaterial);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glColorMaterial' %i", err);

	MACH_OVERRIDE(void, glColorPointer, (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer), err)
	{
		logger.glColorPointer(size, type, stride, pointer);

		glColorPointer_reenter(size, type, stride, pointer);
	} END_MACH_OVERRIDE(glColorPointer);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glColorPointer' %i", err);

	MACH_OVERRIDE(void, glColorSubTable, (GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const GLvoid *data), err)
	{
		logger.glColorSubTable(target, start, count, format, type, data);

		glColorSubTable_reenter(target, start, count, format, type, data);
	} END_MACH_OVERRIDE(glColorSubTable);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glColorSubTable' %i", err);

	MACH_OVERRIDE(void, glColorTable, (GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *table), err)
	{
		logger.glColorTable(target, internalformat, width, format, type, table);

		glColorTable_reenter(target, internalformat, width, format, type, table);
	} END_MACH_OVERRIDE(glColorTable);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glColorTable' %i", err);

	MACH_OVERRIDE(void, glColorTableParameterfv, (GLenum target, GLenum pname, const GLfloat *params), err)
	{
		logger.glColorTableParameterfv(target, pname, params);

		glColorTableParameterfv_reenter(target, pname, params);
	} END_MACH_OVERRIDE(glColorTableParameterfv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glColorTableParameterfv' %i", err);

	MACH_OVERRIDE(void, glColorTableParameteriv, (GLenum target, GLenum pname, const GLint *params), err)
	{
		logger.glColorTableParameteriv(target, pname, params);

		glColorTableParameteriv_reenter(target, pname, params);
	} END_MACH_OVERRIDE(glColorTableParameteriv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glColorTableParameteriv' %i", err);

	MACH_OVERRIDE(void, glConvolutionFilter1D, (GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *image), err)
	{
		logger.glConvolutionFilter1D(target, internalformat, width, format, type, image);

		glConvolutionFilter1D_reenter(target, internalformat, width, format, type, image);
	} END_MACH_OVERRIDE(glConvolutionFilter1D);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glConvolutionFilter1D' %i", err);

	MACH_OVERRIDE(void, glConvolutionFilter2D, (GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *image), err)
	{
		logger.glConvolutionFilter2D(target, internalformat, width, height, format, type, image);

		glConvolutionFilter2D_reenter(target, internalformat, width, height, format, type, image);
	} END_MACH_OVERRIDE(glConvolutionFilter2D);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glConvolutionFilter2D' %i", err);

	MACH_OVERRIDE(void, glConvolutionParameterf, (GLenum target, GLenum pname, GLfloat params), err)
	{
		logger.glConvolutionParameterf(target, pname, params);

		glConvolutionParameterf_reenter(target, pname, params);
	} END_MACH_OVERRIDE(glConvolutionParameterf);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glConvolutionParameterf' %i", err);

	MACH_OVERRIDE(void, glConvolutionParameterfv, (GLenum target, GLenum pname, const GLfloat *params), err)
	{
		logger.glConvolutionParameterfv(target, pname, params);

		glConvolutionParameterfv_reenter(target, pname, params);
	} END_MACH_OVERRIDE(glConvolutionParameterfv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glConvolutionParameterfv' %i", err);

	MACH_OVERRIDE(void, glConvolutionParameteri, (GLenum target, GLenum pname, GLint params), err)
	{
		logger.glConvolutionParameteri(target, pname, params);

		glConvolutionParameteri_reenter(target, pname, params);
	} END_MACH_OVERRIDE(glConvolutionParameteri);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glConvolutionParameteri' %i", err);

	MACH_OVERRIDE(void, glConvolutionParameteriv, (GLenum target, GLenum pname, const GLint *params), err)
	{
		logger.glConvolutionParameteriv(target, pname, params);

		glConvolutionParameteriv_reenter(target, pname, params);
	} END_MACH_OVERRIDE(glConvolutionParameteriv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glConvolutionParameteriv' %i", err);

	MACH_OVERRIDE(void, glCopyColorSubTable, (GLenum target, GLsizei start, GLint x, GLint y, GLsizei width), err)
	{
		logger.glCopyColorSubTable(target, start, x, y, width);

		glCopyColorSubTable_reenter(target, start, x, y, width);
	} END_MACH_OVERRIDE(glCopyColorSubTable);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glCopyColorSubTable' %i", err);

	MACH_OVERRIDE(void, glCopyColorTable, (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width), err)
	{
		logger.glCopyColorTable(target, internalformat, x, y, width);

		glCopyColorTable_reenter(target, internalformat, x, y, width);
	} END_MACH_OVERRIDE(glCopyColorTable);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glCopyColorTable' %i", err);

	MACH_OVERRIDE(void, glCopyConvolutionFilter1D, (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width), err)
	{
		logger.glCopyConvolutionFilter1D(target, internalformat, x, y, width);

		glCopyConvolutionFilter1D_reenter(target, internalformat, x, y, width);
	} END_MACH_OVERRIDE(glCopyConvolutionFilter1D);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glCopyConvolutionFilter1D' %i", err);

	MACH_OVERRIDE(void, glCopyConvolutionFilter2D, (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height), err)
	{
		logger.glCopyConvolutionFilter2D(target, internalformat, x, y, width, height);

		glCopyConvolutionFilter2D_reenter(target, internalformat, x, y, width, height);
	} END_MACH_OVERRIDE(glCopyConvolutionFilter2D);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glCopyConvolutionFilter2D' %i", err);

	MACH_OVERRIDE(void, glCopyPixels, (GLint x, GLint y, GLsizei width, GLsizei height, GLenum type), err)
	{
		logger.glCopyPixels(x, y, width, height, type);

		glCopyPixels_reenter(x, y, width, height, type);
	} END_MACH_OVERRIDE(glCopyPixels);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glCopyPixels' %i", err);

	MACH_OVERRIDE(void, glCopyTexImage1D, (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border), err)
	{
		logger.glCopyTexImage1D(target, level, internalformat, x, y, width, border);

		glCopyTexImage1D_reenter(target, level, internalformat, x, y, width, border);
	} END_MACH_OVERRIDE(glCopyTexImage1D);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glCopyTexImage1D' %i", err);

	MACH_OVERRIDE(void, glCopyTexImage2D, (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border), err)
	{
		logger.glCopyTexImage2D(target, level, internalformat, x, y, width, height, border);

		glCopyTexImage2D_reenter(target, level, internalformat, x, y, width, height, border);
	} END_MACH_OVERRIDE(glCopyTexImage2D);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glCopyTexImage2D' %i", err);

	MACH_OVERRIDE(void, glCopyTexSubImage1D, (GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width), err)
	{
		logger.glCopyTexSubImage1D(target, level, xoffset, x, y, width);

		glCopyTexSubImage1D_reenter(target, level, xoffset, x, y, width);
	} END_MACH_OVERRIDE(glCopyTexSubImage1D);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glCopyTexSubImage1D' %i", err);

	MACH_OVERRIDE(void, glCopyTexSubImage2D, (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height), err)
	{
		logger.glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);

		glCopyTexSubImage2D_reenter(target, level, xoffset, yoffset, x, y, width, height);
	} END_MACH_OVERRIDE(glCopyTexSubImage2D);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glCopyTexSubImage2D' %i", err);

	MACH_OVERRIDE(void, glCopyTexSubImage3D, (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height), err)
	{
		logger.glCopyTexSubImage3D(target, level, xoffset, yoffset, zoffset, x, y, width, height);

		glCopyTexSubImage3D_reenter(target, level, xoffset, yoffset, zoffset, x, y, width, height);
	} END_MACH_OVERRIDE(glCopyTexSubImage3D);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glCopyTexSubImage3D' %i", err);

	MACH_OVERRIDE(void, glCullFace, (GLenum mode), err)
	{
		logger.glCullFace(mode);

		glCullFace_reenter(mode);
	} END_MACH_OVERRIDE(glCullFace);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glCullFace' %i", err);

	MACH_OVERRIDE(void, glDeleteLists, (GLuint list, GLsizei range), err)
	{
		logger.glDeleteLists(list, range);

		glDeleteLists_reenter(list, range);
	} END_MACH_OVERRIDE(glDeleteLists);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glDeleteLists' %i", err);

	MACH_OVERRIDE(void, glDeleteTextures, (GLsizei n, const GLuint *textures), err)
	{
		logger.glDeleteTextures(n, textures);

		glDeleteTextures_reenter(n, textures);
	} END_MACH_OVERRIDE(glDeleteTextures);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glDeleteTextures' %i", err);

	MACH_OVERRIDE(void, glDepthFunc, (GLenum func), err)
	{
		logger.glDepthFunc(func);

		glDepthFunc_reenter(func);
	} END_MACH_OVERRIDE(glDepthFunc);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glDepthFunc' %i", err);

	MACH_OVERRIDE(void, glDepthMask, (GLboolean flag), err)
	{
		logger.glDepthMask(flag);

		glDepthMask_reenter(flag);
	} END_MACH_OVERRIDE(glDepthMask);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glDepthMask' %i", err);

	MACH_OVERRIDE(void, glDepthRange, (GLclampd zNear, GLclampd zFar), err)
	{
		logger.glDepthRange(zNear, zFar);

		glDepthRange_reenter(zNear, zFar);
	} END_MACH_OVERRIDE(glDepthRange);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glDepthRange' %i", err);

	MACH_OVERRIDE(void, glDisable, (GLenum cap), err)
	{
		logger.glDisable(cap);

		glDisable_reenter(cap);
	} END_MACH_OVERRIDE(glDisable);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glDisable' %i", err);

	MACH_OVERRIDE(void, glDisableClientState, (GLenum array), err)
	{
		logger.glDisableClientState(array);

		glDisableClientState_reenter(array);
	} END_MACH_OVERRIDE(glDisableClientState);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glDisableClientState' %i", err);

	MACH_OVERRIDE(void, glDrawArrays, (GLenum mode, GLint first, GLsizei count), err)
	{
		logger.glDrawArrays(mode, first, count);

		glDrawArrays_reenter(mode, first, count);
	} END_MACH_OVERRIDE(glDrawArrays);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glDrawArrays' %i", err);

	MACH_OVERRIDE(void, glDrawBuffer, (GLenum mode), err)
	{
		logger.glDrawBuffer(mode);

		glDrawBuffer_reenter(mode);
	} END_MACH_OVERRIDE(glDrawBuffer);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glDrawBuffer' %i", err);

	MACH_OVERRIDE(void, glDrawElements, (GLenum mode, GLsizei count, GLenum type, const GLvoid *indices), err)
	{
		logger.glDrawElements(mode, count, type, indices);

		glDrawElements_reenter(mode, count, type, indices);
	} END_MACH_OVERRIDE(glDrawElements);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glDrawElements' %i", err);

	MACH_OVERRIDE(void, glDrawPixels, (GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels), err)
	{
		logger.glDrawPixels(width, height, format, type, pixels);

		glDrawPixels_reenter(width, height, format, type, pixels);
	} END_MACH_OVERRIDE(glDrawPixels);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glDrawPixels' %i", err);

	MACH_OVERRIDE(void, glDrawRangeElements, (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices), err)
	{
		logger.glDrawRangeElements(mode, start, end, count, type, indices);

		glDrawRangeElements_reenter(mode, start, end, count, type, indices);
	} END_MACH_OVERRIDE(glDrawRangeElements);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glDrawRangeElements' %i", err);

	MACH_OVERRIDE(void, glEdgeFlag, (GLboolean flag), err)
	{
		logger.glEdgeFlag(flag);

		glEdgeFlag_reenter(flag);
	} END_MACH_OVERRIDE(glEdgeFlag);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glEdgeFlag' %i", err);

	MACH_OVERRIDE(void, glEdgeFlagPointer, (GLsizei stride, const GLvoid *pointer), err)
	{
		logger.glEdgeFlagPointer(stride, pointer);

		glEdgeFlagPointer_reenter(stride, pointer);
	} END_MACH_OVERRIDE(glEdgeFlagPointer);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glEdgeFlagPointer' %i", err);

	MACH_OVERRIDE(void, glEdgeFlagv, (const GLboolean *flag), err)
	{
		logger.glEdgeFlagv(flag);

		glEdgeFlagv_reenter(flag);
	} END_MACH_OVERRIDE(glEdgeFlagv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glEdgeFlagv' %i", err);

	MACH_OVERRIDE(void, glEnable, (GLenum cap), err)
	{
		logger.glEnable(cap);

		glEnable_reenter(cap);
	} END_MACH_OVERRIDE(glEnable);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glEnable' %i", err);

	MACH_OVERRIDE(void, glEnableClientState, (GLenum array), err)
	{
		logger.glEnableClientState(array);

		glEnableClientState_reenter(array);
	} END_MACH_OVERRIDE(glEnableClientState);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glEnableClientState' %i", err);

	MACH_OVERRIDE(void, glEnd, (void), err)
	{
		logger.glEnd();

		glEnd_reenter();
	} END_MACH_OVERRIDE(glEnd);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glEnd' %i", err);

	MACH_OVERRIDE(void, glEndList, (void), err)
	{
		logger.glEndList();

		glEndList_reenter();
	} END_MACH_OVERRIDE(glEndList);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glEndList' %i", err);

	MACH_OVERRIDE(void, glEvalCoord1d, (GLdouble u), err)
	{
		logger.glEvalCoord1d(u);

		glEvalCoord1d_reenter(u);
	} END_MACH_OVERRIDE(glEvalCoord1d);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glEvalCoord1d' %i", err);

	MACH_OVERRIDE(void, glEvalCoord1dv, (const GLdouble *u), err)
	{
		logger.glEvalCoord1dv(u);

		glEvalCoord1dv_reenter(u);
	} END_MACH_OVERRIDE(glEvalCoord1dv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glEvalCoord1dv' %i", err);

	MACH_OVERRIDE(void, glEvalCoord1f, (GLfloat u), err)
	{
		logger.glEvalCoord1f(u);

		glEvalCoord1f_reenter(u);
	} END_MACH_OVERRIDE(glEvalCoord1f);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glEvalCoord1f' %i", err);

	MACH_OVERRIDE(void, glEvalCoord1fv, (const GLfloat *u), err)
	{
		logger.glEvalCoord1fv(u);

		glEvalCoord1fv_reenter(u);
	} END_MACH_OVERRIDE(glEvalCoord1fv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glEvalCoord1fv' %i", err);

	MACH_OVERRIDE(void, glEvalCoord2d, (GLdouble u, GLdouble v), err)
	{
		logger.glEvalCoord2d(u, v);

		glEvalCoord2d_reenter(u, v);
	} END_MACH_OVERRIDE(glEvalCoord2d);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glEvalCoord2d' %i", err);

	MACH_OVERRIDE(void, glEvalCoord2dv, (const GLdouble *u), err)
	{
		logger.glEvalCoord2dv(u);

		glEvalCoord2dv_reenter(u);
	} END_MACH_OVERRIDE(glEvalCoord2dv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glEvalCoord2dv' %i", err);

	MACH_OVERRIDE(void, glEvalCoord2f, (GLfloat u, GLfloat v), err)
	{
		logger.glEvalCoord2f(u, v);

		glEvalCoord2f_reenter(u, v);
	} END_MACH_OVERRIDE(glEvalCoord2f);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glEvalCoord2f' %i", err);

	MACH_OVERRIDE(void, glEvalCoord2fv, (const GLfloat *u), err)
	{
		logger.glEvalCoord2fv(u);

		glEvalCoord2fv_reenter(u);
	} END_MACH_OVERRIDE(glEvalCoord2fv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glEvalCoord2fv' %i", err);

	MACH_OVERRIDE(void, glEvalMesh1, (GLenum mode, GLint i1, GLint i2), err)
	{
		logger.glEvalMesh1(mode, i1, i2);

		glEvalMesh1_reenter(mode, i1, i2);
	} END_MACH_OVERRIDE(glEvalMesh1);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glEvalMesh1' %i", err);

	MACH_OVERRIDE(void, glEvalMesh2, (GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2), err)
	{
		logger.glEvalMesh2(mode, i1, i2, j1, j2);

		glEvalMesh2_reenter(mode, i1, i2, j1, j2);
	} END_MACH_OVERRIDE(glEvalMesh2);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glEvalMesh2' %i", err);

	MACH_OVERRIDE(void, glEvalPoint1, (GLint i), err)
	{
		logger.glEvalPoint1(i);

		glEvalPoint1_reenter(i);
	} END_MACH_OVERRIDE(glEvalPoint1);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glEvalPoint1' %i", err);

	MACH_OVERRIDE(void, glEvalPoint2, (GLint i, GLint j), err)
	{
		logger.glEvalPoint2(i, j);

		glEvalPoint2_reenter(i, j);
	} END_MACH_OVERRIDE(glEvalPoint2);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glEvalPoint2' %i", err);

	MACH_OVERRIDE(void, glFeedbackBuffer, (GLsizei size, GLenum type, GLfloat *buffer), err)
	{
		logger.glFeedbackBuffer(size, type, buffer);

		glFeedbackBuffer_reenter(size, type, buffer);
	} END_MACH_OVERRIDE(glFeedbackBuffer);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glFeedbackBuffer' %i", err);

	MACH_OVERRIDE(void, glFinish, (void), err)
	{
		logger.glFinish();

		glFinish_reenter();
	} END_MACH_OVERRIDE(glFinish);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glFinish' %i", err);

	MACH_OVERRIDE(void, glFlush, (void), err)
	{
		logger.glFlush();

		glFlush_reenter();
	} END_MACH_OVERRIDE(glFlush);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glFlush' %i", err);

	MACH_OVERRIDE(void, glFogf, (GLenum pname, GLfloat param), err)
	{
		logger.glFogf(pname, param);

		glFogf_reenter(pname, param);
	} END_MACH_OVERRIDE(glFogf);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glFogf' %i", err);

	MACH_OVERRIDE(void, glFogfv, (GLenum pname, const GLfloat *params), err)
	{
		logger.glFogfv(pname, params);

		glFogfv_reenter(pname, params);
	} END_MACH_OVERRIDE(glFogfv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glFogfv' %i", err);

	MACH_OVERRIDE(void, glFogi, (GLenum pname, GLint param), err)
	{
		logger.glFogi(pname, param);

		glFogi_reenter(pname, param);
	} END_MACH_OVERRIDE(glFogi);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glFogi' %i", err);

	MACH_OVERRIDE(void, glFogiv, (GLenum pname, const GLint *params), err)
	{
		logger.glFogiv(pname, params);

		glFogiv_reenter(pname, params);
	} END_MACH_OVERRIDE(glFogiv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glFogiv' %i", err);

	MACH_OVERRIDE(void, glFrontFace, (GLenum mode), err)
	{
		logger.glFrontFace(mode);

		glFrontFace_reenter(mode);
	} END_MACH_OVERRIDE(glFrontFace);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glFrontFace' %i", err);

	MACH_OVERRIDE(void, glFrustum, (GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar), err)
	{
		logger.glFrustum(left, right, bottom, top, zNear, zFar);

		glFrustum_reenter(left, right, bottom, top, zNear, zFar);
	} END_MACH_OVERRIDE(glFrustum);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glFrustum' %i", err);

	MACH_OVERRIDE(GLuint, glGenLists, (GLsizei range), err)
	{
		logger.glGenLists(range);

		return glGenLists_reenter(range);
	} END_MACH_OVERRIDE(glGenLists);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGenLists' %i", err);

	MACH_OVERRIDE(void, glGenTextures, (GLsizei n, GLuint *textures), err)
	{
		logger.glGenTextures(n, textures);

		glGenTextures_reenter(n, textures);
	} END_MACH_OVERRIDE(glGenTextures);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGenTextures' %i", err);

	MACH_OVERRIDE(void, glGetBooleanv, (GLenum pname, GLboolean *params), err)
	{
		logger.glGetBooleanv(pname, params);

		glGetBooleanv_reenter(pname, params);
	} END_MACH_OVERRIDE(glGetBooleanv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetBooleanv' %i", err);

	MACH_OVERRIDE(void, glGetClipPlane, (GLenum plane, GLdouble *equation), err)
	{
		logger.glGetClipPlane(plane, equation);

		glGetClipPlane_reenter(plane, equation);
	} END_MACH_OVERRIDE(glGetClipPlane);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetClipPlane' %i", err);

	MACH_OVERRIDE(void, glGetColorTable, (GLenum target, GLenum format, GLenum type, GLvoid *table), err)
	{
		logger.glGetColorTable(target, format, type, table);

		glGetColorTable_reenter(target, format, type, table);
	} END_MACH_OVERRIDE(glGetColorTable);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetColorTable' %i", err);

	MACH_OVERRIDE(void, glGetColorTableParameterfv, (GLenum target, GLenum pname, GLfloat *params), err)
	{
		logger.glGetColorTableParameterfv(target, pname, params);

		glGetColorTableParameterfv_reenter(target, pname, params);
	} END_MACH_OVERRIDE(glGetColorTableParameterfv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetColorTableParameterfv' %i", err);

	MACH_OVERRIDE(void, glGetColorTableParameteriv, (GLenum target, GLenum pname, GLint *params), err)
	{
		logger.glGetColorTableParameteriv(target, pname, params);

		glGetColorTableParameteriv_reenter(target, pname, params);
	} END_MACH_OVERRIDE(glGetColorTableParameteriv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetColorTableParameteriv' %i", err);

	MACH_OVERRIDE(void, glGetConvolutionFilter, (GLenum target, GLenum format, GLenum type, GLvoid *image), err)
	{
		logger.glGetConvolutionFilter(target, format, type, image);

		glGetConvolutionFilter_reenter(target, format, type, image);
	} END_MACH_OVERRIDE(glGetConvolutionFilter);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetConvolutionFilter' %i", err);

	MACH_OVERRIDE(void, glGetConvolutionParameterfv, (GLenum target, GLenum pname, GLfloat *params), err)
	{
		logger.glGetConvolutionParameterfv(target, pname, params);

		glGetConvolutionParameterfv_reenter(target, pname, params);
	} END_MACH_OVERRIDE(glGetConvolutionParameterfv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetConvolutionParameterfv' %i", err);

	MACH_OVERRIDE(void, glGetConvolutionParameteriv, (GLenum target, GLenum pname, GLint *params), err)
	{
		logger.glGetConvolutionParameteriv(target, pname, params);

		glGetConvolutionParameteriv_reenter(target, pname, params);
	} END_MACH_OVERRIDE(glGetConvolutionParameteriv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetConvolutionParameteriv' %i", err);

	MACH_OVERRIDE(void, glGetDoublev, (GLenum pname, GLdouble *params), err)
	{
		logger.glGetDoublev(pname, params);

		glGetDoublev_reenter(pname, params);
	} END_MACH_OVERRIDE(glGetDoublev);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetDoublev' %i", err);

	MACH_OVERRIDE(GLenum, glGetError, (void), err)
	{
		logger.glGetError();

		return glGetError_reenter();
	} END_MACH_OVERRIDE(glGetError);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetError' %i", err);

	MACH_OVERRIDE(void, glGetFloatv, (GLenum pname, GLfloat *params), err)
	{
		logger.glGetFloatv(pname, params);

		glGetFloatv_reenter(pname, params);
	} END_MACH_OVERRIDE(glGetFloatv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetFloatv' %i", err);

	MACH_OVERRIDE(void, glGetHistogram, (GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid *values), err)
	{
		logger.glGetHistogram(target, reset, format, type, values);

		glGetHistogram_reenter(target, reset, format, type, values);
	} END_MACH_OVERRIDE(glGetHistogram);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetHistogram' %i", err);

	MACH_OVERRIDE(void, glGetHistogramParameterfv, (GLenum target, GLenum pname, GLfloat *params), err)
	{
		logger.glGetHistogramParameterfv(target, pname, params);

		glGetHistogramParameterfv_reenter(target, pname, params);
	} END_MACH_OVERRIDE(glGetHistogramParameterfv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetHistogramParameterfv' %i", err);

	MACH_OVERRIDE(void, glGetHistogramParameteriv, (GLenum target, GLenum pname, GLint *params), err)
	{
		logger.glGetHistogramParameteriv(target, pname, params);

		glGetHistogramParameteriv_reenter(target, pname, params);
	} END_MACH_OVERRIDE(glGetHistogramParameteriv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetHistogramParameteriv' %i", err);

	MACH_OVERRIDE(void, glGetIntegerv, (GLenum pname, GLint *params), err)
	{
		logger.glGetIntegerv(pname, params);

		glGetIntegerv_reenter(pname, params);
	} END_MACH_OVERRIDE(glGetIntegerv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetIntegerv' %i", err);

	MACH_OVERRIDE(void, glGetLightfv, (GLenum light, GLenum pname, GLfloat *params), err)
	{
		logger.glGetLightfv(light, pname, params);

		glGetLightfv_reenter(light, pname, params);
	} END_MACH_OVERRIDE(glGetLightfv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetLightfv' %i", err);

	MACH_OVERRIDE(void, glGetLightiv, (GLenum light, GLenum pname, GLint *params), err)
	{
		logger.glGetLightiv(light, pname, params);

		glGetLightiv_reenter(light, pname, params);
	} END_MACH_OVERRIDE(glGetLightiv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetLightiv' %i", err);

	MACH_OVERRIDE(void, glGetMapdv, (GLenum target, GLenum query, GLdouble *v), err)
	{
		logger.glGetMapdv(target, query, v);

		glGetMapdv_reenter(target, query, v);
	} END_MACH_OVERRIDE(glGetMapdv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetMapdv' %i", err);

	MACH_OVERRIDE(void, glGetMapfv, (GLenum target, GLenum query, GLfloat *v), err)
	{
		logger.glGetMapfv(target, query, v);

		glGetMapfv_reenter(target, query, v);
	} END_MACH_OVERRIDE(glGetMapfv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetMapfv' %i", err);

	MACH_OVERRIDE(void, glGetMapiv, (GLenum target, GLenum query, GLint *v), err)
	{
		logger.glGetMapiv(target, query, v);

		glGetMapiv_reenter(target, query, v);
	} END_MACH_OVERRIDE(glGetMapiv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetMapiv' %i", err);

	MACH_OVERRIDE(void, glGetMaterialfv, (GLenum face, GLenum pname, GLfloat *params), err)
	{
		logger.glGetMaterialfv(face, pname, params);

		glGetMaterialfv_reenter(face, pname, params);
	} END_MACH_OVERRIDE(glGetMaterialfv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetMaterialfv' %i", err);

	MACH_OVERRIDE(void, glGetMaterialiv, (GLenum face, GLenum pname, GLint *params), err)
	{
		logger.glGetMaterialiv(face, pname, params);

		glGetMaterialiv_reenter(face, pname, params);
	} END_MACH_OVERRIDE(glGetMaterialiv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetMaterialiv' %i", err);

	MACH_OVERRIDE(void, glGetMinmax, (GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid *values), err)
	{
		logger.glGetMinmax(target, reset, format, type, values);

		glGetMinmax_reenter(target, reset, format, type, values);
	} END_MACH_OVERRIDE(glGetMinmax);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetMinmax' %i", err);

	MACH_OVERRIDE(void, glGetMinmaxParameterfv, (GLenum target, GLenum pname, GLfloat *params), err)
	{
		logger.glGetMinmaxParameterfv(target, pname, params);

		glGetMinmaxParameterfv_reenter(target, pname, params);
	} END_MACH_OVERRIDE(glGetMinmaxParameterfv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetMinmaxParameterfv' %i", err);

	MACH_OVERRIDE(void, glGetMinmaxParameteriv, (GLenum target, GLenum pname, GLint *params), err)
	{
		logger.glGetMinmaxParameteriv(target, pname, params);

		glGetMinmaxParameteriv_reenter(target, pname, params);
	} END_MACH_OVERRIDE(glGetMinmaxParameteriv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetMinmaxParameteriv' %i", err);

	MACH_OVERRIDE(void, glGetPixelMapfv, (GLenum map, GLfloat *values), err)
	{
		logger.glGetPixelMapfv(map, values);

		glGetPixelMapfv_reenter(map, values);
	} END_MACH_OVERRIDE(glGetPixelMapfv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetPixelMapfv' %i", err);

	MACH_OVERRIDE(void, glGetPixelMapuiv, (GLenum map, GLuint *values), err)
	{
		logger.glGetPixelMapuiv(map, values);

		glGetPixelMapuiv_reenter(map, values);
	} END_MACH_OVERRIDE(glGetPixelMapuiv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetPixelMapuiv' %i", err);

	MACH_OVERRIDE(void, glGetPixelMapusv, (GLenum map, GLushort *values), err)
	{
		logger.glGetPixelMapusv(map, values);

		glGetPixelMapusv_reenter(map, values);
	} END_MACH_OVERRIDE(glGetPixelMapusv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetPixelMapusv' %i", err);

	MACH_OVERRIDE(void, glGetPointerv, (GLenum pname, GLvoid **params), err)
	{
		logger.glGetPointerv(pname, params);

		glGetPointerv_reenter(pname, params);
	} END_MACH_OVERRIDE(glGetPointerv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetPointerv' %i", err);

	MACH_OVERRIDE(void, glGetPolygonStipple, (GLubyte *mask), err)
	{
		logger.glGetPolygonStipple(mask);

		glGetPolygonStipple_reenter(mask);
	} END_MACH_OVERRIDE(glGetPolygonStipple);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetPolygonStipple' %i", err);

	MACH_OVERRIDE(void, glGetSeparableFilter, (GLenum target, GLenum format, GLenum type, GLvoid *row, GLvoid *column, GLvoid *span), err)
	{
		logger.glGetSeparableFilter(target, format, type, row, column, span);

		glGetSeparableFilter_reenter(target, format, type, row, column, span);
	} END_MACH_OVERRIDE(glGetSeparableFilter);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetSeparableFilter' %i", err);

	MACH_OVERRIDE(const GLubyte *, glGetString, (GLenum name), err)
	{
		logger.glGetString(name);

		return glGetString_reenter(name);
	} END_MACH_OVERRIDE(glGetString);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetString' %i", err);

	MACH_OVERRIDE(void, glGetTexEnvfv, (GLenum target, GLenum pname, GLfloat *params), err)
	{
		logger.glGetTexEnvfv(target, pname, params);

		glGetTexEnvfv_reenter(target, pname, params);
	} END_MACH_OVERRIDE(glGetTexEnvfv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetTexEnvfv' %i", err);

	MACH_OVERRIDE(void, glGetTexEnviv, (GLenum target, GLenum pname, GLint *params), err)
	{
		logger.glGetTexEnviv(target, pname, params);

		glGetTexEnviv_reenter(target, pname, params);
	} END_MACH_OVERRIDE(glGetTexEnviv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetTexEnviv' %i", err);

	MACH_OVERRIDE(void, glGetTexGendv, (GLenum coord, GLenum pname, GLdouble *params), err)
	{
		logger.glGetTexGendv(coord, pname, params);

		glGetTexGendv_reenter(coord, pname, params);
	} END_MACH_OVERRIDE(glGetTexGendv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetTexGendv' %i", err);

	MACH_OVERRIDE(void, glGetTexGenfv, (GLenum coord, GLenum pname, GLfloat *params), err)
	{
		logger.glGetTexGenfv(coord, pname, params);

		glGetTexGenfv_reenter(coord, pname, params);
	} END_MACH_OVERRIDE(glGetTexGenfv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetTexGenfv' %i", err);

	MACH_OVERRIDE(void, glGetTexGeniv, (GLenum coord, GLenum pname, GLint *params), err)
	{
		logger.glGetTexGeniv(coord, pname, params);

		glGetTexGeniv_reenter(coord, pname, params);
	} END_MACH_OVERRIDE(glGetTexGeniv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetTexGeniv' %i", err);

	MACH_OVERRIDE(void, glGetTexImage, (GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels), err)
	{
		logger.glGetTexImage(target, level, format, type, pixels);

		glGetTexImage_reenter(target, level, format, type, pixels);
	} END_MACH_OVERRIDE(glGetTexImage);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetTexImage' %i", err);

	MACH_OVERRIDE(void, glGetTexLevelParameterfv, (GLenum target, GLint level, GLenum pname, GLfloat *params), err)
	{
		logger.glGetTexLevelParameterfv(target, level, pname, params);

		glGetTexLevelParameterfv_reenter(target, level, pname, params);
	} END_MACH_OVERRIDE(glGetTexLevelParameterfv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetTexLevelParameterfv' %i", err);

	MACH_OVERRIDE(void, glGetTexLevelParameteriv, (GLenum target, GLint level, GLenum pname, GLint *params), err)
	{
		logger.glGetTexLevelParameteriv(target, level, pname, params);

		glGetTexLevelParameteriv_reenter(target, level, pname, params);
	} END_MACH_OVERRIDE(glGetTexLevelParameteriv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetTexLevelParameteriv' %i", err);

	MACH_OVERRIDE(void, glGetTexParameterfv, (GLenum target, GLenum pname, GLfloat *params), err)
	{
		logger.glGetTexParameterfv(target, pname, params);

		glGetTexParameterfv_reenter(target, pname, params);
	} END_MACH_OVERRIDE(glGetTexParameterfv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetTexParameterfv' %i", err);

	MACH_OVERRIDE(void, glGetTexParameteriv, (GLenum target, GLenum pname, GLint *params), err)
	{
		logger.glGetTexParameteriv(target, pname, params);

		glGetTexParameteriv_reenter(target, pname, params);
	} END_MACH_OVERRIDE(glGetTexParameteriv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetTexParameteriv' %i", err);

	MACH_OVERRIDE(void, glHint, (GLenum target, GLenum mode), err)
	{
		logger.glHint(target, mode);

		glHint_reenter(target, mode);
	} END_MACH_OVERRIDE(glHint);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glHint' %i", err);

	MACH_OVERRIDE(void, glHistogram, (GLenum target, GLsizei width, GLenum internalformat, GLboolean sink), err)
	{
		logger.glHistogram(target, width, internalformat, sink);

		glHistogram_reenter(target, width, internalformat, sink);
	} END_MACH_OVERRIDE(glHistogram);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glHistogram' %i", err);

	MACH_OVERRIDE(void, glIndexMask, (GLuint mask), err)
	{
		logger.glIndexMask(mask);

		glIndexMask_reenter(mask);
	} END_MACH_OVERRIDE(glIndexMask);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glIndexMask' %i", err);

	MACH_OVERRIDE(void, glIndexPointer, (GLenum type, GLsizei stride, const GLvoid *pointer), err)
	{
		logger.glIndexPointer(type, stride, pointer);

		glIndexPointer_reenter(type, stride, pointer);
	} END_MACH_OVERRIDE(glIndexPointer);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glIndexPointer' %i", err);

	MACH_OVERRIDE(void, glIndexd, (GLdouble c), err)
	{
		logger.glIndexd(c);

		glIndexd_reenter(c);
	} END_MACH_OVERRIDE(glIndexd);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glIndexd' %i", err);

	MACH_OVERRIDE(void, glIndexdv, (const GLdouble *c), err)
	{
		logger.glIndexdv(c);

		glIndexdv_reenter(c);
	} END_MACH_OVERRIDE(glIndexdv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glIndexdv' %i", err);

	MACH_OVERRIDE(void, glIndexf, (GLfloat c), err)
	{
		logger.glIndexf(c);

		glIndexf_reenter(c);
	} END_MACH_OVERRIDE(glIndexf);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glIndexf' %i", err);

	MACH_OVERRIDE(void, glIndexfv, (const GLfloat *c), err)
	{
		logger.glIndexfv(c);

		glIndexfv_reenter(c);
	} END_MACH_OVERRIDE(glIndexfv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glIndexfv' %i", err);

	MACH_OVERRIDE(void, glIndexi, (GLint c), err)
	{
		logger.glIndexi(c);

		glIndexi_reenter(c);
	} END_MACH_OVERRIDE(glIndexi);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glIndexi' %i", err);

	MACH_OVERRIDE(void, glIndexiv, (const GLint *c), err)
	{
		logger.glIndexiv(c);

		glIndexiv_reenter(c);
	} END_MACH_OVERRIDE(glIndexiv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glIndexiv' %i", err);

	MACH_OVERRIDE(void, glIndexs, (GLshort c), err)
	{
		logger.glIndexs(c);

		glIndexs_reenter(c);
	} END_MACH_OVERRIDE(glIndexs);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glIndexs' %i", err);

	MACH_OVERRIDE(void, glIndexsv, (const GLshort *c), err)
	{
		logger.glIndexsv(c);

		glIndexsv_reenter(c);
	} END_MACH_OVERRIDE(glIndexsv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glIndexsv' %i", err);

	MACH_OVERRIDE(void, glIndexub, (GLubyte c), err)
	{
		logger.glIndexub(c);

		glIndexub_reenter(c);
	} END_MACH_OVERRIDE(glIndexub);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glIndexub' %i", err);

	MACH_OVERRIDE(void, glIndexubv, (const GLubyte *c), err)
	{
		logger.glIndexubv(c);

		glIndexubv_reenter(c);
	} END_MACH_OVERRIDE(glIndexubv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glIndexubv' %i", err);

	MACH_OVERRIDE(void, glInitNames, (void), err)
	{
		logger.glInitNames();

		glInitNames_reenter();
	} END_MACH_OVERRIDE(glInitNames);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glInitNames' %i", err);

	MACH_OVERRIDE(void, glInterleavedArrays, (GLenum format, GLsizei stride, const GLvoid *pointer), err)
	{
		logger.glInterleavedArrays(format, stride, pointer);

		glInterleavedArrays_reenter(format, stride, pointer);
	} END_MACH_OVERRIDE(glInterleavedArrays);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glInterleavedArrays' %i", err);

	MACH_OVERRIDE(GLboolean, glIsEnabled, (GLenum cap), err)
	{
		logger.glIsEnabled(cap);

		return glIsEnabled_reenter(cap);
	} END_MACH_OVERRIDE(glIsEnabled);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glIsEnabled' %i", err);

	MACH_OVERRIDE(GLboolean, glIsList, (GLuint list), err)
	{
		logger.glIsList(list);

		return glIsList_reenter(list);
	} END_MACH_OVERRIDE(glIsList);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glIsList' %i", err);

	MACH_OVERRIDE(GLboolean, glIsTexture, (GLuint texture), err)
	{
		logger.glIsTexture(texture);

		return glIsTexture_reenter(texture);
	} END_MACH_OVERRIDE(glIsTexture);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glIsTexture' %i", err);

	MACH_OVERRIDE(void, glLightModelf, (GLenum pname, GLfloat param), err)
	{
		logger.glLightModelf(pname, param);

		glLightModelf_reenter(pname, param);
	} END_MACH_OVERRIDE(glLightModelf);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glLightModelf' %i", err);

	MACH_OVERRIDE(void, glLightModelfv, (GLenum pname, const GLfloat *params), err)
	{
		logger.glLightModelfv(pname, params);

		glLightModelfv_reenter(pname, params);
	} END_MACH_OVERRIDE(glLightModelfv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glLightModelfv' %i", err);

	MACH_OVERRIDE(void, glLightModeli, (GLenum pname, GLint param), err)
	{
		logger.glLightModeli(pname, param);

		glLightModeli_reenter(pname, param);
	} END_MACH_OVERRIDE(glLightModeli);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glLightModeli' %i", err);

	MACH_OVERRIDE(void, glLightModeliv, (GLenum pname, const GLint *params), err)
	{
		logger.glLightModeliv(pname, params);

		glLightModeliv_reenter(pname, params);
	} END_MACH_OVERRIDE(glLightModeliv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glLightModeliv' %i", err);

	MACH_OVERRIDE(void, glLightf, (GLenum light, GLenum pname, GLfloat param), err)
	{
		logger.glLightf(light, pname, param);

		glLightf_reenter(light, pname, param);
	} END_MACH_OVERRIDE(glLightf);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glLightf' %i", err);

	MACH_OVERRIDE(void, glLightfv, (GLenum light, GLenum pname, const GLfloat *params), err)
	{
		logger.glLightfv(light, pname, params);

		glLightfv_reenter(light, pname, params);
	} END_MACH_OVERRIDE(glLightfv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glLightfv' %i", err);

	MACH_OVERRIDE(void, glLighti, (GLenum light, GLenum pname, GLint param), err)
	{
		logger.glLighti(light, pname, param);

		glLighti_reenter(light, pname, param);
	} END_MACH_OVERRIDE(glLighti);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glLighti' %i", err);

	MACH_OVERRIDE(void, glLightiv, (GLenum light, GLenum pname, const GLint *params), err)
	{
		logger.glLightiv(light, pname, params);

		glLightiv_reenter(light, pname, params);
	} END_MACH_OVERRIDE(glLightiv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glLightiv' %i", err);

	MACH_OVERRIDE(void, glLineStipple, (GLint factor, GLushort pattern), err)
	{
		logger.glLineStipple(factor, pattern);

		glLineStipple_reenter(factor, pattern);
	} END_MACH_OVERRIDE(glLineStipple);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glLineStipple' %i", err);

	MACH_OVERRIDE(void, glLineWidth, (GLfloat width), err)
	{
		logger.glLineWidth(width);

		glLineWidth_reenter(width);
	} END_MACH_OVERRIDE(glLineWidth);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glLineWidth' %i", err);

	MACH_OVERRIDE(void, glListBase, (GLuint base), err)
	{
		logger.glListBase(base);

		glListBase_reenter(base);
	} END_MACH_OVERRIDE(glListBase);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glListBase' %i", err);

	MACH_OVERRIDE(void, glLoadIdentity, (void), err)
	{
		logger.glLoadIdentity();

		glLoadIdentity_reenter();
	} END_MACH_OVERRIDE(glLoadIdentity);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glLoadIdentity' %i", err);

	MACH_OVERRIDE(void, glLoadMatrixd, (const GLdouble *m), err)
	{
		logger.glLoadMatrixd(m);

		glLoadMatrixd_reenter(m);
	} END_MACH_OVERRIDE(glLoadMatrixd);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glLoadMatrixd' %i", err);

	MACH_OVERRIDE(void, glLoadMatrixf, (const GLfloat *m), err)
	{
		logger.glLoadMatrixf(m);

		glLoadMatrixf_reenter(m);
	} END_MACH_OVERRIDE(glLoadMatrixf);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glLoadMatrixf' %i", err);

	MACH_OVERRIDE(void, glLoadName, (GLuint name), err)
	{
		logger.glLoadName(name);

		glLoadName_reenter(name);
	} END_MACH_OVERRIDE(glLoadName);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glLoadName' %i", err);

	MACH_OVERRIDE(void, glLogicOp, (GLenum opcode), err)
	{
		logger.glLogicOp(opcode);

		glLogicOp_reenter(opcode);
	} END_MACH_OVERRIDE(glLogicOp);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glLogicOp' %i", err);

	MACH_OVERRIDE(void, glMap1d, (GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points), err)
	{
		logger.glMap1d(target, u1, u2, stride, order, points);

		glMap1d_reenter(target, u1, u2, stride, order, points);
	} END_MACH_OVERRIDE(glMap1d);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glMap1d' %i", err);

	MACH_OVERRIDE(void, glMap1f, (GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points), err)
	{
		logger.glMap1f(target, u1, u2, stride, order, points);

		glMap1f_reenter(target, u1, u2, stride, order, points);
	} END_MACH_OVERRIDE(glMap1f);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glMap1f' %i", err);

	MACH_OVERRIDE(void, glMap2d, (GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points), err)
	{
		logger.glMap2d(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);

		glMap2d_reenter(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
	} END_MACH_OVERRIDE(glMap2d);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glMap2d' %i", err);

	MACH_OVERRIDE(void, glMap2f, (GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points), err)
	{
		logger.glMap2f(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);

		glMap2f_reenter(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
	} END_MACH_OVERRIDE(glMap2f);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glMap2f' %i", err);

	MACH_OVERRIDE(void, glMapGrid1d, (GLint un, GLdouble u1, GLdouble u2), err)
	{
		logger.glMapGrid1d(un, u1, u2);

		glMapGrid1d_reenter(un, u1, u2);
	} END_MACH_OVERRIDE(glMapGrid1d);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glMapGrid1d' %i", err);

	MACH_OVERRIDE(void, glMapGrid1f, (GLint un, GLfloat u1, GLfloat u2), err)
	{
		logger.glMapGrid1f(un, u1, u2);

		glMapGrid1f_reenter(un, u1, u2);
	} END_MACH_OVERRIDE(glMapGrid1f);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glMapGrid1f' %i", err);

	MACH_OVERRIDE(void, glMapGrid2d, (GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2), err)
	{
		logger.glMapGrid2d(un, u1, u2, vn, v1, v2);

		glMapGrid2d_reenter(un, u1, u2, vn, v1, v2);
	} END_MACH_OVERRIDE(glMapGrid2d);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glMapGrid2d' %i", err);

	MACH_OVERRIDE(void, glMapGrid2f, (GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2), err)
	{
		logger.glMapGrid2f(un, u1, u2, vn, v1, v2);

		glMapGrid2f_reenter(un, u1, u2, vn, v1, v2);
	} END_MACH_OVERRIDE(glMapGrid2f);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glMapGrid2f' %i", err);

	MACH_OVERRIDE(void, glMaterialf, (GLenum face, GLenum pname, GLfloat param), err)
	{
		logger.glMaterialf(face, pname, param);

		glMaterialf_reenter(face, pname, param);
	} END_MACH_OVERRIDE(glMaterialf);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glMaterialf' %i", err);

	MACH_OVERRIDE(void, glMaterialfv, (GLenum face, GLenum pname, const GLfloat *params), err)
	{
		logger.glMaterialfv(face, pname, params);

		glMaterialfv_reenter(face, pname, params);
	} END_MACH_OVERRIDE(glMaterialfv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glMaterialfv' %i", err);

	MACH_OVERRIDE(void, glMateriali, (GLenum face, GLenum pname, GLint param), err)
	{
		logger.glMateriali(face, pname, param);

		glMateriali_reenter(face, pname, param);
	} END_MACH_OVERRIDE(glMateriali);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glMateriali' %i", err);

	MACH_OVERRIDE(void, glMaterialiv, (GLenum face, GLenum pname, const GLint *params), err)
	{
		logger.glMaterialiv(face, pname, params);

		glMaterialiv_reenter(face, pname, params);
	} END_MACH_OVERRIDE(glMaterialiv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glMaterialiv' %i", err);

	MACH_OVERRIDE(void, glMatrixMode, (GLenum mode), err)
	{
		logger.glMatrixMode(mode);

		glMatrixMode_reenter(mode);
	} END_MACH_OVERRIDE(glMatrixMode);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glMatrixMode' %i", err);

	MACH_OVERRIDE(void, glMinmax, (GLenum target, GLenum internalformat, GLboolean sink), err)
	{
		logger.glMinmax(target, internalformat, sink);

		glMinmax_reenter(target, internalformat, sink);
	} END_MACH_OVERRIDE(glMinmax);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glMinmax' %i", err);

	MACH_OVERRIDE(void, glMultMatrixd, (const GLdouble *m), err)
	{
		logger.glMultMatrixd(m);

		glMultMatrixd_reenter(m);
	} END_MACH_OVERRIDE(glMultMatrixd);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glMultMatrixd' %i", err);

	MACH_OVERRIDE(void, glMultMatrixf, (const GLfloat *m), err)
	{
		logger.glMultMatrixf(m);

		glMultMatrixf_reenter(m);
	} END_MACH_OVERRIDE(glMultMatrixf);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glMultMatrixf' %i", err);

	MACH_OVERRIDE(void, glNewList, (GLuint list, GLenum mode), err)
	{
		logger.glNewList(list, mode);

		glNewList_reenter(list, mode);
	} END_MACH_OVERRIDE(glNewList);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glNewList' %i", err);

	MACH_OVERRIDE(void, glNormal3b, (GLbyte nx, GLbyte ny, GLbyte nz), err)
	{
		logger.glNormal3b(nx, ny, nz);

		glNormal3b_reenter(nx, ny, nz);
	} END_MACH_OVERRIDE(glNormal3b);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glNormal3b' %i", err);

	MACH_OVERRIDE(void, glNormal3bv, (const GLbyte *v), err)
	{
		logger.glNormal3bv(v);

		glNormal3bv_reenter(v);
	} END_MACH_OVERRIDE(glNormal3bv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glNormal3bv' %i", err);

	MACH_OVERRIDE(void, glNormal3d, (GLdouble nx, GLdouble ny, GLdouble nz), err)
	{
		logger.glNormal3d(nx, ny, nz);

		glNormal3d_reenter(nx, ny, nz);
	} END_MACH_OVERRIDE(glNormal3d);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glNormal3d' %i", err);

	MACH_OVERRIDE(void, glNormal3dv, (const GLdouble *v), err)
	{
		logger.glNormal3dv(v);

		glNormal3dv_reenter(v);
	} END_MACH_OVERRIDE(glNormal3dv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glNormal3dv' %i", err);

	MACH_OVERRIDE(void, glNormal3f, (GLfloat nx, GLfloat ny, GLfloat nz), err)
	{
		logger.glNormal3f(nx, ny, nz);

		glNormal3f_reenter(nx, ny, nz);
	} END_MACH_OVERRIDE(glNormal3f);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glNormal3f' %i", err);

	MACH_OVERRIDE(void, glNormal3fv, (const GLfloat *v), err)
	{
		logger.glNormal3fv(v);

		glNormal3fv_reenter(v);
	} END_MACH_OVERRIDE(glNormal3fv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glNormal3fv' %i", err);

	MACH_OVERRIDE(void, glNormal3i, (GLint nx, GLint ny, GLint nz), err)
	{
		logger.glNormal3i(nx, ny, nz);

		glNormal3i_reenter(nx, ny, nz);
	} END_MACH_OVERRIDE(glNormal3i);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glNormal3i' %i", err);

	MACH_OVERRIDE(void, glNormal3iv, (const GLint *v), err)
	{
		logger.glNormal3iv(v);

		glNormal3iv_reenter(v);
	} END_MACH_OVERRIDE(glNormal3iv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glNormal3iv' %i", err);

	MACH_OVERRIDE(void, glNormal3s, (GLshort nx, GLshort ny, GLshort nz), err)
	{
		logger.glNormal3s(nx, ny, nz);

		glNormal3s_reenter(nx, ny, nz);
	} END_MACH_OVERRIDE(glNormal3s);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glNormal3s' %i", err);

	MACH_OVERRIDE(void, glNormal3sv, (const GLshort *v), err)
	{
		logger.glNormal3sv(v);

		glNormal3sv_reenter(v);
	} END_MACH_OVERRIDE(glNormal3sv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glNormal3sv' %i", err);

	MACH_OVERRIDE(void, glNormalPointer, (GLenum type, GLsizei stride, const GLvoid *pointer), err)
	{
		logger.glNormalPointer(type, stride, pointer);

		glNormalPointer_reenter(type, stride, pointer);
	} END_MACH_OVERRIDE(glNormalPointer);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glNormalPointer' %i", err);

	MACH_OVERRIDE(void, glOrtho, (GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar), err)
	{
		logger.glOrtho(left, right, bottom, top, zNear, zFar);

		glOrtho_reenter(left, right, bottom, top, zNear, zFar);
	} END_MACH_OVERRIDE(glOrtho);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glOrtho' %i", err);

	MACH_OVERRIDE(void, glPassThrough, (GLfloat token), err)
	{
		logger.glPassThrough(token);

		glPassThrough_reenter(token);
	} END_MACH_OVERRIDE(glPassThrough);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glPassThrough' %i", err);

	MACH_OVERRIDE(void, glPixelMapfv, (GLenum map, GLint mapsize, const GLfloat *values), err)
	{
		logger.glPixelMapfv(map, mapsize, values);

		glPixelMapfv_reenter(map, mapsize, values);
	} END_MACH_OVERRIDE(glPixelMapfv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glPixelMapfv' %i", err);

	MACH_OVERRIDE(void, glPixelMapuiv, (GLenum map, GLint mapsize, const GLuint *values), err)
	{
		logger.glPixelMapuiv(map, mapsize, values);

		glPixelMapuiv_reenter(map, mapsize, values);
	} END_MACH_OVERRIDE(glPixelMapuiv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glPixelMapuiv' %i", err);

	MACH_OVERRIDE(void, glPixelMapusv, (GLenum map, GLint mapsize, const GLushort *values), err)
	{
		logger.glPixelMapusv(map, mapsize, values);

		glPixelMapusv_reenter(map, mapsize, values);
	} END_MACH_OVERRIDE(glPixelMapusv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glPixelMapusv' %i", err);

	MACH_OVERRIDE(void, glPixelStoref, (GLenum pname, GLfloat param), err)
	{
		logger.glPixelStoref(pname, param);

		glPixelStoref_reenter(pname, param);
	} END_MACH_OVERRIDE(glPixelStoref);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glPixelStoref' %i", err);

	MACH_OVERRIDE(void, glPixelStorei, (GLenum pname, GLint param), err)
	{
		logger.glPixelStorei(pname, param);

		glPixelStorei_reenter(pname, param);
	} END_MACH_OVERRIDE(glPixelStorei);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glPixelStorei' %i", err);

	MACH_OVERRIDE(void, glPixelTransferf, (GLenum pname, GLfloat param), err)
	{
		logger.glPixelTransferf(pname, param);

		glPixelTransferf_reenter(pname, param);
	} END_MACH_OVERRIDE(glPixelTransferf);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glPixelTransferf' %i", err);

	MACH_OVERRIDE(void, glPixelTransferi, (GLenum pname, GLint param), err)
	{
		logger.glPixelTransferi(pname, param);

		glPixelTransferi_reenter(pname, param);
	} END_MACH_OVERRIDE(glPixelTransferi);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glPixelTransferi' %i", err);

	MACH_OVERRIDE(void, glPixelZoom, (GLfloat xfactor, GLfloat yfactor), err)
	{
		logger.glPixelZoom(xfactor, yfactor);

		glPixelZoom_reenter(xfactor, yfactor);
	} END_MACH_OVERRIDE(glPixelZoom);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glPixelZoom' %i", err);

	MACH_OVERRIDE(void, glPointSize, (GLfloat size), err)
	{
		logger.glPointSize(size);

		glPointSize_reenter(size);
	} END_MACH_OVERRIDE(glPointSize);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glPointSize' %i", err);

	MACH_OVERRIDE(void, glPolygonMode, (GLenum face, GLenum mode), err)
	{
		logger.glPolygonMode(face, mode);

		glPolygonMode_reenter(face, mode);
	} END_MACH_OVERRIDE(glPolygonMode);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glPolygonMode' %i", err);

	MACH_OVERRIDE(void, glPolygonOffset, (GLfloat factor, GLfloat units), err)
	{
		logger.glPolygonOffset(factor, units);

		glPolygonOffset_reenter(factor, units);
	} END_MACH_OVERRIDE(glPolygonOffset);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glPolygonOffset' %i", err);

	MACH_OVERRIDE(void, glPolygonStipple, (const GLubyte *mask), err)
	{
		logger.glPolygonStipple(mask);

		glPolygonStipple_reenter(mask);
	} END_MACH_OVERRIDE(glPolygonStipple);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glPolygonStipple' %i", err);

	MACH_OVERRIDE(void, glPopAttrib, (void), err)
	{
		logger.glPopAttrib();

		glPopAttrib_reenter();
	} END_MACH_OVERRIDE(glPopAttrib);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glPopAttrib' %i", err);

	MACH_OVERRIDE(void, glPopClientAttrib, (void), err)
	{
		logger.glPopClientAttrib();

		glPopClientAttrib_reenter();
	} END_MACH_OVERRIDE(glPopClientAttrib);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glPopClientAttrib' %i", err);

	MACH_OVERRIDE(void, glPopMatrix, (void), err)
	{
		logger.glPopMatrix();

		glPopMatrix_reenter();
	} END_MACH_OVERRIDE(glPopMatrix);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glPopMatrix' %i", err);

	MACH_OVERRIDE(void, glPopName, (void), err)
	{
		logger.glPopName();

		glPopName_reenter();
	} END_MACH_OVERRIDE(glPopName);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glPopName' %i", err);

	MACH_OVERRIDE(void, glPrioritizeTextures, (GLsizei n, const GLuint *textures, const GLclampf *priorities), err)
	{
		logger.glPrioritizeTextures(n, textures, priorities);

		glPrioritizeTextures_reenter(n, textures, priorities);
	} END_MACH_OVERRIDE(glPrioritizeTextures);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glPrioritizeTextures' %i", err);

	MACH_OVERRIDE(void, glPushAttrib, (GLbitfield mask), err)
	{
		logger.glPushAttrib(mask);

		glPushAttrib_reenter(mask);
	} END_MACH_OVERRIDE(glPushAttrib);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glPushAttrib' %i", err);

	MACH_OVERRIDE(void, glPushClientAttrib, (GLbitfield mask), err)
	{
		logger.glPushClientAttrib(mask);

		glPushClientAttrib_reenter(mask);
	} END_MACH_OVERRIDE(glPushClientAttrib);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glPushClientAttrib' %i", err);

	MACH_OVERRIDE(void, glPushMatrix, (void), err)
	{
		logger.glPushMatrix();

		glPushMatrix_reenter();
	} END_MACH_OVERRIDE(glPushMatrix);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glPushMatrix' %i", err);

	MACH_OVERRIDE(void, glPushName, (GLuint name), err)
	{
		logger.glPushName(name);

		glPushName_reenter(name);
	} END_MACH_OVERRIDE(glPushName);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glPushName' %i", err);

	MACH_OVERRIDE(void, glRasterPos2d, (GLdouble x, GLdouble y), err)
	{
		logger.glRasterPos2d(x, y);

		glRasterPos2d_reenter(x, y);
	} END_MACH_OVERRIDE(glRasterPos2d);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glRasterPos2d' %i", err);

	MACH_OVERRIDE(void, glRasterPos2dv, (const GLdouble *v), err)
	{
		logger.glRasterPos2dv(v);

		glRasterPos2dv_reenter(v);
	} END_MACH_OVERRIDE(glRasterPos2dv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glRasterPos2dv' %i", err);

	MACH_OVERRIDE(void, glRasterPos2f, (GLfloat x, GLfloat y), err)
	{
		logger.glRasterPos2f(x, y);

		glRasterPos2f_reenter(x, y);
	} END_MACH_OVERRIDE(glRasterPos2f);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glRasterPos2f' %i", err);

	MACH_OVERRIDE(void, glRasterPos2fv, (const GLfloat *v), err)
	{
		logger.glRasterPos2fv(v);

		glRasterPos2fv_reenter(v);
	} END_MACH_OVERRIDE(glRasterPos2fv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glRasterPos2fv' %i", err);

	MACH_OVERRIDE(void, glRasterPos2i, (GLint x, GLint y), err)
	{
		logger.glRasterPos2i(x, y);

		glRasterPos2i_reenter(x, y);
	} END_MACH_OVERRIDE(glRasterPos2i);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glRasterPos2i' %i", err);

	MACH_OVERRIDE(void, glRasterPos2iv, (const GLint *v), err)
	{
		logger.glRasterPos2iv(v);

		glRasterPos2iv_reenter(v);
	} END_MACH_OVERRIDE(glRasterPos2iv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glRasterPos2iv' %i", err);

	MACH_OVERRIDE(void, glRasterPos2s, (GLshort x, GLshort y), err)
	{
		logger.glRasterPos2s(x, y);

		glRasterPos2s_reenter(x, y);
	} END_MACH_OVERRIDE(glRasterPos2s);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glRasterPos2s' %i", err);

	MACH_OVERRIDE(void, glRasterPos2sv, (const GLshort *v), err)
	{
		logger.glRasterPos2sv(v);

		glRasterPos2sv_reenter(v);
	} END_MACH_OVERRIDE(glRasterPos2sv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glRasterPos2sv' %i", err);

	MACH_OVERRIDE(void, glRasterPos3d, (GLdouble x, GLdouble y, GLdouble z), err)
	{
		logger.glRasterPos3d(x, y, z);

		glRasterPos3d_reenter(x, y, z);
	} END_MACH_OVERRIDE(glRasterPos3d);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glRasterPos3d' %i", err);

	MACH_OVERRIDE(void, glRasterPos3dv, (const GLdouble *v), err)
	{
		logger.glRasterPos3dv(v);

		glRasterPos3dv_reenter(v);
	} END_MACH_OVERRIDE(glRasterPos3dv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glRasterPos3dv' %i", err);

	MACH_OVERRIDE(void, glRasterPos3f, (GLfloat x, GLfloat y, GLfloat z), err)
	{
		logger.glRasterPos3f(x, y, z);

		glRasterPos3f_reenter(x, y, z);
	} END_MACH_OVERRIDE(glRasterPos3f);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glRasterPos3f' %i", err);

	MACH_OVERRIDE(void, glRasterPos3fv, (const GLfloat *v), err)
	{
		logger.glRasterPos3fv(v);

		glRasterPos3fv_reenter(v);
	} END_MACH_OVERRIDE(glRasterPos3fv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glRasterPos3fv' %i", err);

	MACH_OVERRIDE(void, glRasterPos3i, (GLint x, GLint y, GLint z), err)
	{
		logger.glRasterPos3i(x, y, z);

		glRasterPos3i_reenter(x, y, z);
	} END_MACH_OVERRIDE(glRasterPos3i);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glRasterPos3i' %i", err);

	MACH_OVERRIDE(void, glRasterPos3iv, (const GLint *v), err)
	{
		logger.glRasterPos3iv(v);

		glRasterPos3iv_reenter(v);
	} END_MACH_OVERRIDE(glRasterPos3iv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glRasterPos3iv' %i", err);

	MACH_OVERRIDE(void, glRasterPos3s, (GLshort x, GLshort y, GLshort z), err)
	{
		logger.glRasterPos3s(x, y, z);

		glRasterPos3s_reenter(x, y, z);
	} END_MACH_OVERRIDE(glRasterPos3s);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glRasterPos3s' %i", err);

	MACH_OVERRIDE(void, glRasterPos3sv, (const GLshort *v), err)
	{
		logger.glRasterPos3sv(v);

		glRasterPos3sv_reenter(v);
	} END_MACH_OVERRIDE(glRasterPos3sv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glRasterPos3sv' %i", err);

	MACH_OVERRIDE(void, glRasterPos4d, (GLdouble x, GLdouble y, GLdouble z, GLdouble w), err)
	{
		logger.glRasterPos4d(x, y, z, w);

		glRasterPos4d_reenter(x, y, z, w);
	} END_MACH_OVERRIDE(glRasterPos4d);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glRasterPos4d' %i", err);

	MACH_OVERRIDE(void, glRasterPos4dv, (const GLdouble *v), err)
	{
		logger.glRasterPos4dv(v);

		glRasterPos4dv_reenter(v);
	} END_MACH_OVERRIDE(glRasterPos4dv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glRasterPos4dv' %i", err);

	MACH_OVERRIDE(void, glRasterPos4f, (GLfloat x, GLfloat y, GLfloat z, GLfloat w), err)
	{
		logger.glRasterPos4f(x, y, z, w);

		glRasterPos4f_reenter(x, y, z, w);
	} END_MACH_OVERRIDE(glRasterPos4f);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glRasterPos4f' %i", err);

	MACH_OVERRIDE(void, glRasterPos4fv, (const GLfloat *v), err)
	{
		logger.glRasterPos4fv(v);

		glRasterPos4fv_reenter(v);
	} END_MACH_OVERRIDE(glRasterPos4fv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glRasterPos4fv' %i", err);

	MACH_OVERRIDE(void, glRasterPos4i, (GLint x, GLint y, GLint z, GLint w), err)
	{
		logger.glRasterPos4i(x, y, z, w);

		glRasterPos4i_reenter(x, y, z, w);
	} END_MACH_OVERRIDE(glRasterPos4i);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glRasterPos4i' %i", err);

	MACH_OVERRIDE(void, glRasterPos4iv, (const GLint *v), err)
	{
		logger.glRasterPos4iv(v);

		glRasterPos4iv_reenter(v);
	} END_MACH_OVERRIDE(glRasterPos4iv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glRasterPos4iv' %i", err);

	MACH_OVERRIDE(void, glRasterPos4s, (GLshort x, GLshort y, GLshort z, GLshort w), err)
	{
		logger.glRasterPos4s(x, y, z, w);

		glRasterPos4s_reenter(x, y, z, w);
	} END_MACH_OVERRIDE(glRasterPos4s);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glRasterPos4s' %i", err);

	MACH_OVERRIDE(void, glRasterPos4sv, (const GLshort *v), err)
	{
		logger.glRasterPos4sv(v);

		glRasterPos4sv_reenter(v);
	} END_MACH_OVERRIDE(glRasterPos4sv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glRasterPos4sv' %i", err);

	MACH_OVERRIDE(void, glReadBuffer, (GLenum mode), err)
	{
		logger.glReadBuffer(mode);

		glReadBuffer_reenter(mode);
	} END_MACH_OVERRIDE(glReadBuffer);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glReadBuffer' %i", err);

	MACH_OVERRIDE(void, glReadPixels, (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels), err)
	{
		logger.glReadPixels(x, y, width, height, format, type, pixels);

		glReadPixels_reenter(x, y, width, height, format, type, pixels);
	} END_MACH_OVERRIDE(glReadPixels);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glReadPixels' %i", err);

	MACH_OVERRIDE(void, glRectd, (GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2), err)
	{
		logger.glRectd(x1, y1, x2, y2);

		glRectd_reenter(x1, y1, x2, y2);
	} END_MACH_OVERRIDE(glRectd);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glRectd' %i", err);

	MACH_OVERRIDE(void, glRectdv, (const GLdouble *v1, const GLdouble *v2), err)
	{
		logger.glRectdv(v1, v2);

		glRectdv_reenter(v1, v2);
	} END_MACH_OVERRIDE(glRectdv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glRectdv' %i", err);

	MACH_OVERRIDE(void, glRectf, (GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2), err)
	{
		logger.glRectf(x1, y1, x2, y2);

		glRectf_reenter(x1, y1, x2, y2);
	} END_MACH_OVERRIDE(glRectf);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glRectf' %i", err);

	MACH_OVERRIDE(void, glRectfv, (const GLfloat *v1, const GLfloat *v2), err)
	{
		logger.glRectfv(v1, v2);

		glRectfv_reenter(v1, v2);
	} END_MACH_OVERRIDE(glRectfv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glRectfv' %i", err);

	MACH_OVERRIDE(void, glRecti, (GLint x1, GLint y1, GLint x2, GLint y2), err)
	{
		logger.glRecti(x1, y1, x2, y2);

		glRecti_reenter(x1, y1, x2, y2);
	} END_MACH_OVERRIDE(glRecti);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glRecti' %i", err);

	MACH_OVERRIDE(void, glRectiv, (const GLint *v1, const GLint *v2), err)
	{
		logger.glRectiv(v1, v2);

		glRectiv_reenter(v1, v2);
	} END_MACH_OVERRIDE(glRectiv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glRectiv' %i", err);

	MACH_OVERRIDE(void, glRects, (GLshort x1, GLshort y1, GLshort x2, GLshort y2), err)
	{
		logger.glRects(x1, y1, x2, y2);

		glRects_reenter(x1, y1, x2, y2);
	} END_MACH_OVERRIDE(glRects);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glRects' %i", err);

	MACH_OVERRIDE(void, glRectsv, (const GLshort *v1, const GLshort *v2), err)
	{
		logger.glRectsv(v1, v2);

		glRectsv_reenter(v1, v2);
	} END_MACH_OVERRIDE(glRectsv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glRectsv' %i", err);

	MACH_OVERRIDE(GLint, glRenderMode, (GLenum mode), err)
	{
		logger.glRenderMode(mode);

		return glRenderMode_reenter(mode);
	} END_MACH_OVERRIDE(glRenderMode);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glRenderMode' %i", err);

	MACH_OVERRIDE(void, glResetHistogram, (GLenum target), err)
	{
		logger.glResetHistogram(target);

		glResetHistogram_reenter(target);
	} END_MACH_OVERRIDE(glResetHistogram);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glResetHistogram' %i", err);

	MACH_OVERRIDE(void, glResetMinmax, (GLenum target), err)
	{
		logger.glResetMinmax(target);

		glResetMinmax_reenter(target);
	} END_MACH_OVERRIDE(glResetMinmax);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glResetMinmax' %i", err);

	MACH_OVERRIDE(void, glRotated, (GLdouble angle, GLdouble x, GLdouble y, GLdouble z), err)
	{
		logger.glRotated(angle, x, y, z);

		glRotated_reenter(angle, x, y, z);
	} END_MACH_OVERRIDE(glRotated);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glRotated' %i", err);

	MACH_OVERRIDE(void, glRotatef, (GLfloat angle, GLfloat x, GLfloat y, GLfloat z), err)
	{
		logger.glRotatef(angle, x, y, z);

		glRotatef_reenter(angle, x, y, z);
	} END_MACH_OVERRIDE(glRotatef);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glRotatef' %i", err);

	MACH_OVERRIDE(void, glScaled, (GLdouble x, GLdouble y, GLdouble z), err)
	{
		logger.glScaled(x, y, z);

		glScaled_reenter(x, y, z);
	} END_MACH_OVERRIDE(glScaled);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glScaled' %i", err);

	MACH_OVERRIDE(void, glScalef, (GLfloat x, GLfloat y, GLfloat z), err)
	{
		logger.glScalef(x, y, z);

		glScalef_reenter(x, y, z);
	} END_MACH_OVERRIDE(glScalef);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glScalef' %i", err);

	MACH_OVERRIDE(void, glScissor, (GLint x, GLint y, GLsizei width, GLsizei height), err)
	{
		logger.glScissor(x, y, width, height);

		glScissor_reenter(x, y, width, height);
	} END_MACH_OVERRIDE(glScissor);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glScissor' %i", err);

	MACH_OVERRIDE(void, glSelectBuffer, (GLsizei size, GLuint *buffer), err)
	{
		logger.glSelectBuffer(size, buffer);

		glSelectBuffer_reenter(size, buffer);
	} END_MACH_OVERRIDE(glSelectBuffer);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glSelectBuffer' %i", err);

	MACH_OVERRIDE(void, glSeparableFilter2D, (GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *row, const GLvoid *column), err)
	{
		logger.glSeparableFilter2D(target, internalformat, width, height, format, type, row, column);

		glSeparableFilter2D_reenter(target, internalformat, width, height, format, type, row, column);
	} END_MACH_OVERRIDE(glSeparableFilter2D);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glSeparableFilter2D' %i", err);

	MACH_OVERRIDE(void, glShadeModel, (GLenum mode), err)
	{
		logger.glShadeModel(mode);

		glShadeModel_reenter(mode);
	} END_MACH_OVERRIDE(glShadeModel);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glShadeModel' %i", err);

	MACH_OVERRIDE(void, glStencilFunc, (GLenum func, GLint ref, GLuint mask), err)
	{
		logger.glStencilFunc(func, ref, mask);

		glStencilFunc_reenter(func, ref, mask);
	} END_MACH_OVERRIDE(glStencilFunc);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glStencilFunc' %i", err);

	MACH_OVERRIDE(void, glStencilMask, (GLuint mask), err)
	{
		logger.glStencilMask(mask);

		glStencilMask_reenter(mask);
	} END_MACH_OVERRIDE(glStencilMask);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glStencilMask' %i", err);

	MACH_OVERRIDE(void, glStencilOp, (GLenum fail, GLenum zfail, GLenum zpass), err)
	{
		logger.glStencilOp(fail, zfail, zpass);

		glStencilOp_reenter(fail, zfail, zpass);
	} END_MACH_OVERRIDE(glStencilOp);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glStencilOp' %i", err);

	MACH_OVERRIDE(void, glTexCoord1d, (GLdouble s), err)
	{
		logger.glTexCoord1d(s);

		glTexCoord1d_reenter(s);
	} END_MACH_OVERRIDE(glTexCoord1d);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glTexCoord1d' %i", err);

	MACH_OVERRIDE(void, glTexCoord1dv, (const GLdouble *v), err)
	{
		logger.glTexCoord1dv(v);

		glTexCoord1dv_reenter(v);
	} END_MACH_OVERRIDE(glTexCoord1dv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glTexCoord1dv' %i", err);

	MACH_OVERRIDE(void, glTexCoord1f, (GLfloat s), err)
	{
		logger.glTexCoord1f(s);

		glTexCoord1f_reenter(s);
	} END_MACH_OVERRIDE(glTexCoord1f);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glTexCoord1f' %i", err);

	MACH_OVERRIDE(void, glTexCoord1fv, (const GLfloat *v), err)
	{
		logger.glTexCoord1fv(v);

		glTexCoord1fv_reenter(v);
	} END_MACH_OVERRIDE(glTexCoord1fv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glTexCoord1fv' %i", err);

	MACH_OVERRIDE(void, glTexCoord1i, (GLint s), err)
	{
		logger.glTexCoord1i(s);

		glTexCoord1i_reenter(s);
	} END_MACH_OVERRIDE(glTexCoord1i);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glTexCoord1i' %i", err);

	MACH_OVERRIDE(void, glTexCoord1iv, (const GLint *v), err)
	{
		logger.glTexCoord1iv(v);

		glTexCoord1iv_reenter(v);
	} END_MACH_OVERRIDE(glTexCoord1iv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glTexCoord1iv' %i", err);

	MACH_OVERRIDE(void, glTexCoord1s, (GLshort s), err)
	{
		logger.glTexCoord1s(s);

		glTexCoord1s_reenter(s);
	} END_MACH_OVERRIDE(glTexCoord1s);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glTexCoord1s' %i", err);

	MACH_OVERRIDE(void, glTexCoord1sv, (const GLshort *v), err)
	{
		logger.glTexCoord1sv(v);

		glTexCoord1sv_reenter(v);
	} END_MACH_OVERRIDE(glTexCoord1sv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glTexCoord1sv' %i", err);

	MACH_OVERRIDE(void, glTexCoord2d, (GLdouble s, GLdouble t), err)
	{
		logger.glTexCoord2d(s, t);

		glTexCoord2d_reenter(s, t);
	} END_MACH_OVERRIDE(glTexCoord2d);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glTexCoord2d' %i", err);

	MACH_OVERRIDE(void, glTexCoord2dv, (const GLdouble *v), err)
	{
		logger.glTexCoord2dv(v);

		glTexCoord2dv_reenter(v);
	} END_MACH_OVERRIDE(glTexCoord2dv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glTexCoord2dv' %i", err);

	MACH_OVERRIDE(void, glTexCoord2f, (GLfloat s, GLfloat t), err)
	{
		logger.glTexCoord2f(s, t);

		glTexCoord2f_reenter(s, t);
	} END_MACH_OVERRIDE(glTexCoord2f);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glTexCoord2f' %i", err);

	MACH_OVERRIDE(void, glTexCoord2fv, (const GLfloat *v), err)
	{
		logger.glTexCoord2fv(v);

		glTexCoord2fv_reenter(v);
	} END_MACH_OVERRIDE(glTexCoord2fv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glTexCoord2fv' %i", err);

	MACH_OVERRIDE(void, glTexCoord2i, (GLint s, GLint t), err)
	{
		logger.glTexCoord2i(s, t);

		glTexCoord2i_reenter(s, t);
	} END_MACH_OVERRIDE(glTexCoord2i);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glTexCoord2i' %i", err);

	MACH_OVERRIDE(void, glTexCoord2iv, (const GLint *v), err)
	{
		logger.glTexCoord2iv(v);

		glTexCoord2iv_reenter(v);
	} END_MACH_OVERRIDE(glTexCoord2iv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glTexCoord2iv' %i", err);

	MACH_OVERRIDE(void, glTexCoord2s, (GLshort s, GLshort t), err)
	{
		logger.glTexCoord2s(s, t);

		glTexCoord2s_reenter(s, t);
	} END_MACH_OVERRIDE(glTexCoord2s);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glTexCoord2s' %i", err);

	MACH_OVERRIDE(void, glTexCoord2sv, (const GLshort *v), err)
	{
		logger.glTexCoord2sv(v);

		glTexCoord2sv_reenter(v);
	} END_MACH_OVERRIDE(glTexCoord2sv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glTexCoord2sv' %i", err);

	MACH_OVERRIDE(void, glTexCoord3d, (GLdouble s, GLdouble t, GLdouble r), err)
	{
		logger.glTexCoord3d(s, t, r);

		glTexCoord3d_reenter(s, t, r);
	} END_MACH_OVERRIDE(glTexCoord3d);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glTexCoord3d' %i", err);

	MACH_OVERRIDE(void, glTexCoord3dv, (const GLdouble *v), err)
	{
		logger.glTexCoord3dv(v);

		glTexCoord3dv_reenter(v);
	} END_MACH_OVERRIDE(glTexCoord3dv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glTexCoord3dv' %i", err);

	MACH_OVERRIDE(void, glTexCoord3f, (GLfloat s, GLfloat t, GLfloat r), err)
	{
		logger.glTexCoord3f(s, t, r);

		glTexCoord3f_reenter(s, t, r);
	} END_MACH_OVERRIDE(glTexCoord3f);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glTexCoord3f' %i", err);

	MACH_OVERRIDE(void, glTexCoord3fv, (const GLfloat *v), err)
	{
		logger.glTexCoord3fv(v);

		glTexCoord3fv_reenter(v);
	} END_MACH_OVERRIDE(glTexCoord3fv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glTexCoord3fv' %i", err);

	MACH_OVERRIDE(void, glTexCoord3i, (GLint s, GLint t, GLint r), err)
	{
		logger.glTexCoord3i(s, t, r);

		glTexCoord3i_reenter(s, t, r);
	} END_MACH_OVERRIDE(glTexCoord3i);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glTexCoord3i' %i", err);

	MACH_OVERRIDE(void, glTexCoord3iv, (const GLint *v), err)
	{
		logger.glTexCoord3iv(v);

		glTexCoord3iv_reenter(v);
	} END_MACH_OVERRIDE(glTexCoord3iv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glTexCoord3iv' %i", err);

	MACH_OVERRIDE(void, glTexCoord3s, (GLshort s, GLshort t, GLshort r), err)
	{
		logger.glTexCoord3s(s, t, r);

		glTexCoord3s_reenter(s, t, r);
	} END_MACH_OVERRIDE(glTexCoord3s);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glTexCoord3s' %i", err);

	MACH_OVERRIDE(void, glTexCoord3sv, (const GLshort *v), err)
	{
		logger.glTexCoord3sv(v);

		glTexCoord3sv_reenter(v);
	} END_MACH_OVERRIDE(glTexCoord3sv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glTexCoord3sv' %i", err);

	MACH_OVERRIDE(void, glTexCoord4d, (GLdouble s, GLdouble t, GLdouble r, GLdouble q), err)
	{
		logger.glTexCoord4d(s, t, r, q);

		glTexCoord4d_reenter(s, t, r, q);
	} END_MACH_OVERRIDE(glTexCoord4d);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glTexCoord4d' %i", err);

	MACH_OVERRIDE(void, glTexCoord4dv, (const GLdouble *v), err)
	{
		logger.glTexCoord4dv(v);

		glTexCoord4dv_reenter(v);
	} END_MACH_OVERRIDE(glTexCoord4dv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glTexCoord4dv' %i", err);

	MACH_OVERRIDE(void, glTexCoord4f, (GLfloat s, GLfloat t, GLfloat r, GLfloat q), err)
	{
		logger.glTexCoord4f(s, t, r, q);

		glTexCoord4f_reenter(s, t, r, q);
	} END_MACH_OVERRIDE(glTexCoord4f);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glTexCoord4f' %i", err);

	MACH_OVERRIDE(void, glTexCoord4fv, (const GLfloat *v), err)
	{
		logger.glTexCoord4fv(v);

		glTexCoord4fv_reenter(v);
	} END_MACH_OVERRIDE(glTexCoord4fv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glTexCoord4fv' %i", err);

	MACH_OVERRIDE(void, glTexCoord4i, (GLint s, GLint t, GLint r, GLint q), err)
	{
		logger.glTexCoord4i(s, t, r, q);

		glTexCoord4i_reenter(s, t, r, q);
	} END_MACH_OVERRIDE(glTexCoord4i);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glTexCoord4i' %i", err);

	MACH_OVERRIDE(void, glTexCoord4iv, (const GLint *v), err)
	{
		logger.glTexCoord4iv(v);

		glTexCoord4iv_reenter(v);
	} END_MACH_OVERRIDE(glTexCoord4iv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glTexCoord4iv' %i", err);

	MACH_OVERRIDE(void, glTexCoord4s, (GLshort s, GLshort t, GLshort r, GLshort q), err)
	{
		logger.glTexCoord4s(s, t, r, q);

		glTexCoord4s_reenter(s, t, r, q);
	} END_MACH_OVERRIDE(glTexCoord4s);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glTexCoord4s' %i", err);

	MACH_OVERRIDE(void, glTexCoord4sv, (const GLshort *v), err)
	{
		logger.glTexCoord4sv(v);

		glTexCoord4sv_reenter(v);
	} END_MACH_OVERRIDE(glTexCoord4sv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glTexCoord4sv' %i", err);

	MACH_OVERRIDE(void, glTexCoordPointer, (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer), err)
	{
		logger.glTexCoordPointer(size, type, stride, pointer);

		glTexCoordPointer_reenter(size, type, stride, pointer);
	} END_MACH_OVERRIDE(glTexCoordPointer);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glTexCoordPointer' %i", err);

	MACH_OVERRIDE(void, glTexEnvf, (GLenum target, GLenum pname, GLfloat param), err)
	{
		logger.glTexEnvf(target, pname, param);

		glTexEnvf_reenter(target, pname, param);
	} END_MACH_OVERRIDE(glTexEnvf);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glTexEnvf' %i", err);

	MACH_OVERRIDE(void, glTexEnvfv, (GLenum target, GLenum pname, const GLfloat *params), err)
	{
		logger.glTexEnvfv(target, pname, params);

		glTexEnvfv_reenter(target, pname, params);
	} END_MACH_OVERRIDE(glTexEnvfv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glTexEnvfv' %i", err);

	MACH_OVERRIDE(void, glTexEnvi, (GLenum target, GLenum pname, GLint param), err)
	{
		logger.glTexEnvi(target, pname, param);

		glTexEnvi_reenter(target, pname, param);
	} END_MACH_OVERRIDE(glTexEnvi);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glTexEnvi' %i", err);

	MACH_OVERRIDE(void, glTexEnviv, (GLenum target, GLenum pname, const GLint *params), err)
	{
		logger.glTexEnviv(target, pname, params);

		glTexEnviv_reenter(target, pname, params);
	} END_MACH_OVERRIDE(glTexEnviv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glTexEnviv' %i", err);

	MACH_OVERRIDE(void, glTexGend, (GLenum coord, GLenum pname, GLdouble param), err)
	{
		logger.glTexGend(coord, pname, param);

		glTexGend_reenter(coord, pname, param);
	} END_MACH_OVERRIDE(glTexGend);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glTexGend' %i", err);

	MACH_OVERRIDE(void, glTexGendv, (GLenum coord, GLenum pname, const GLdouble *params), err)
	{
		logger.glTexGendv(coord, pname, params);

		glTexGendv_reenter(coord, pname, params);
	} END_MACH_OVERRIDE(glTexGendv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glTexGendv' %i", err);

	MACH_OVERRIDE(void, glTexGenf, (GLenum coord, GLenum pname, GLfloat param), err)
	{
		logger.glTexGenf(coord, pname, param);

		glTexGenf_reenter(coord, pname, param);
	} END_MACH_OVERRIDE(glTexGenf);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glTexGenf' %i", err);

	MACH_OVERRIDE(void, glTexGenfv, (GLenum coord, GLenum pname, const GLfloat *params), err)
	{
		logger.glTexGenfv(coord, pname, params);

		glTexGenfv_reenter(coord, pname, params);
	} END_MACH_OVERRIDE(glTexGenfv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glTexGenfv' %i", err);

	MACH_OVERRIDE(void, glTexGeni, (GLenum coord, GLenum pname, GLint param), err)
	{
		logger.glTexGeni(coord, pname, param);

		glTexGeni_reenter(coord, pname, param);
	} END_MACH_OVERRIDE(glTexGeni);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glTexGeni' %i", err);

	MACH_OVERRIDE(void, glTexGeniv, (GLenum coord, GLenum pname, const GLint *params), err)
	{
		logger.glTexGeniv(coord, pname, params);

		glTexGeniv_reenter(coord, pname, params);
	} END_MACH_OVERRIDE(glTexGeniv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glTexGeniv' %i", err);

	MACH_OVERRIDE(void, glTexImage1D, (GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels), err)
	{
		logger.glTexImage1D(target, level, internalformat, width, border, format, type, pixels);

		glTexImage1D_reenter(target, level, internalformat, width, border, format, type, pixels);
	} END_MACH_OVERRIDE(glTexImage1D);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glTexImage1D' %i", err);

	MACH_OVERRIDE(void, glTexImage2D, (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels), err)
	{
		logger.glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);

		glTexImage2D_reenter(target, level, internalformat, width, height, border, format, type, pixels);
	} END_MACH_OVERRIDE(glTexImage2D);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glTexImage2D' %i", err);

	MACH_OVERRIDE(void, glTexImage3D, (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels), err)
	{
		logger.glTexImage3D(target, level, internalformat, width, height, depth, border, format, type, pixels);

		glTexImage3D_reenter(target, level, internalformat, width, height, depth, border, format, type, pixels);
	} END_MACH_OVERRIDE(glTexImage3D);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glTexImage3D' %i", err);

	MACH_OVERRIDE(void, glTexParameterf, (GLenum target, GLenum pname, GLfloat param), err)
	{
		logger.glTexParameterf(target, pname, param);

		glTexParameterf_reenter(target, pname, param);
	} END_MACH_OVERRIDE(glTexParameterf);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glTexParameterf' %i", err);

	MACH_OVERRIDE(void, glTexParameterfv, (GLenum target, GLenum pname, const GLfloat *params), err)
	{
		logger.glTexParameterfv(target, pname, params);

		glTexParameterfv_reenter(target, pname, params);
	} END_MACH_OVERRIDE(glTexParameterfv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glTexParameterfv' %i", err);

	MACH_OVERRIDE(void, glTexParameteri, (GLenum target, GLenum pname, GLint param), err)
	{
		logger.glTexParameteri(target, pname, param);

		glTexParameteri_reenter(target, pname, param);
	} END_MACH_OVERRIDE(glTexParameteri);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glTexParameteri' %i", err);

	MACH_OVERRIDE(void, glTexParameteriv, (GLenum target, GLenum pname, const GLint *params), err)
	{
		logger.glTexParameteriv(target, pname, params);

		glTexParameteriv_reenter(target, pname, params);
	} END_MACH_OVERRIDE(glTexParameteriv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glTexParameteriv' %i", err);

	MACH_OVERRIDE(void, glTexSubImage1D, (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels), err)
	{
		logger.glTexSubImage1D(target, level, xoffset, width, format, type, pixels);

		glTexSubImage1D_reenter(target, level, xoffset, width, format, type, pixels);
	} END_MACH_OVERRIDE(glTexSubImage1D);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glTexSubImage1D' %i", err);

	MACH_OVERRIDE(void, glTexSubImage2D, (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels), err)
	{
		logger.glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);

		glTexSubImage2D_reenter(target, level, xoffset, yoffset, width, height, format, type, pixels);
	} END_MACH_OVERRIDE(glTexSubImage2D);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glTexSubImage2D' %i", err);

	MACH_OVERRIDE(void, glTexSubImage3D, (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels), err)
	{
		logger.glTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);

		glTexSubImage3D_reenter(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
	} END_MACH_OVERRIDE(glTexSubImage3D);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glTexSubImage3D' %i", err);

	MACH_OVERRIDE(void, glTranslated, (GLdouble x, GLdouble y, GLdouble z), err)
	{
		logger.glTranslated(x, y, z);

		glTranslated_reenter(x, y, z);
	} END_MACH_OVERRIDE(glTranslated);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glTranslated' %i", err);

	MACH_OVERRIDE(void, glTranslatef, (GLfloat x, GLfloat y, GLfloat z), err)
	{
		logger.glTranslatef(x, y, z);

		glTranslatef_reenter(x, y, z);
	} END_MACH_OVERRIDE(glTranslatef);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glTranslatef' %i", err);

	MACH_OVERRIDE(void, glVertex2d, (GLdouble x, GLdouble y), err)
	{
		logger.glVertex2d(x, y);

		glVertex2d_reenter(x, y);
	} END_MACH_OVERRIDE(glVertex2d);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertex2d' %i", err);

	MACH_OVERRIDE(void, glVertex2dv, (const GLdouble *v), err)
	{
		logger.glVertex2dv(v);

		glVertex2dv_reenter(v);
	} END_MACH_OVERRIDE(glVertex2dv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertex2dv' %i", err);

	MACH_OVERRIDE(void, glVertex2f, (GLfloat x, GLfloat y), err)
	{
		logger.glVertex2f(x, y);

		glVertex2f_reenter(x, y);
	} END_MACH_OVERRIDE(glVertex2f);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertex2f' %i", err);

	MACH_OVERRIDE(void, glVertex2fv, (const GLfloat *v), err)
	{
		logger.glVertex2fv(v);

		glVertex2fv_reenter(v);
	} END_MACH_OVERRIDE(glVertex2fv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertex2fv' %i", err);

	MACH_OVERRIDE(void, glVertex2i, (GLint x, GLint y), err)
	{
		logger.glVertex2i(x, y);

		glVertex2i_reenter(x, y);
	} END_MACH_OVERRIDE(glVertex2i);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertex2i' %i", err);

	MACH_OVERRIDE(void, glVertex2iv, (const GLint *v), err)
	{
		logger.glVertex2iv(v);

		glVertex2iv_reenter(v);
	} END_MACH_OVERRIDE(glVertex2iv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertex2iv' %i", err);

	MACH_OVERRIDE(void, glVertex2s, (GLshort x, GLshort y), err)
	{
		logger.glVertex2s(x, y);

		glVertex2s_reenter(x, y);
	} END_MACH_OVERRIDE(glVertex2s);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertex2s' %i", err);

	MACH_OVERRIDE(void, glVertex2sv, (const GLshort *v), err)
	{
		logger.glVertex2sv(v);

		glVertex2sv_reenter(v);
	} END_MACH_OVERRIDE(glVertex2sv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertex2sv' %i", err);

	MACH_OVERRIDE(void, glVertex3d, (GLdouble x, GLdouble y, GLdouble z), err)
	{
		logger.glVertex3d(x, y, z);

		glVertex3d_reenter(x, y, z);
	} END_MACH_OVERRIDE(glVertex3d);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertex3d' %i", err);

	MACH_OVERRIDE(void, glVertex3dv, (const GLdouble *v), err)
	{
		logger.glVertex3dv(v);

		glVertex3dv_reenter(v);
	} END_MACH_OVERRIDE(glVertex3dv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertex3dv' %i", err);

	MACH_OVERRIDE(void, glVertex3f, (GLfloat x, GLfloat y, GLfloat z), err)
	{
		logger.glVertex3f(x, y, z);

		glVertex3f_reenter(x, y, z);
	} END_MACH_OVERRIDE(glVertex3f);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertex3f' %i", err);

	MACH_OVERRIDE(void, glVertex3fv, (const GLfloat *v), err)
	{
		logger.glVertex3fv(v);

		glVertex3fv_reenter(v);
	} END_MACH_OVERRIDE(glVertex3fv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertex3fv' %i", err);

	MACH_OVERRIDE(void, glVertex3i, (GLint x, GLint y, GLint z), err)
	{
		logger.glVertex3i(x, y, z);

		glVertex3i_reenter(x, y, z);
	} END_MACH_OVERRIDE(glVertex3i);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertex3i' %i", err);

	MACH_OVERRIDE(void, glVertex3iv, (const GLint *v), err)
	{
		logger.glVertex3iv(v);

		glVertex3iv_reenter(v);
	} END_MACH_OVERRIDE(glVertex3iv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertex3iv' %i", err);

	MACH_OVERRIDE(void, glVertex3s, (GLshort x, GLshort y, GLshort z), err)
	{
		logger.glVertex3s(x, y, z);

		glVertex3s_reenter(x, y, z);
	} END_MACH_OVERRIDE(glVertex3s);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertex3s' %i", err);

	MACH_OVERRIDE(void, glVertex3sv, (const GLshort *v), err)
	{
		logger.glVertex3sv(v);

		glVertex3sv_reenter(v);
	} END_MACH_OVERRIDE(glVertex3sv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertex3sv' %i", err);

	MACH_OVERRIDE(void, glVertex4d, (GLdouble x, GLdouble y, GLdouble z, GLdouble w), err)
	{
		logger.glVertex4d(x, y, z, w);

		glVertex4d_reenter(x, y, z, w);
	} END_MACH_OVERRIDE(glVertex4d);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertex4d' %i", err);

	MACH_OVERRIDE(void, glVertex4dv, (const GLdouble *v), err)
	{
		logger.glVertex4dv(v);

		glVertex4dv_reenter(v);
	} END_MACH_OVERRIDE(glVertex4dv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertex4dv' %i", err);

	MACH_OVERRIDE(void, glVertex4f, (GLfloat x, GLfloat y, GLfloat z, GLfloat w), err)
	{
		logger.glVertex4f(x, y, z, w);

		glVertex4f_reenter(x, y, z, w);
	} END_MACH_OVERRIDE(glVertex4f);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertex4f' %i", err);

	MACH_OVERRIDE(void, glVertex4fv, (const GLfloat *v), err)
	{
		logger.glVertex4fv(v);

		glVertex4fv_reenter(v);
	} END_MACH_OVERRIDE(glVertex4fv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertex4fv' %i", err);

	MACH_OVERRIDE(void, glVertex4i, (GLint x, GLint y, GLint z, GLint w), err)
	{
		logger.glVertex4i(x, y, z, w);

		glVertex4i_reenter(x, y, z, w);
	} END_MACH_OVERRIDE(glVertex4i);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertex4i' %i", err);

	MACH_OVERRIDE(void, glVertex4iv, (const GLint *v), err)
	{
		logger.glVertex4iv(v);

		glVertex4iv_reenter(v);
	} END_MACH_OVERRIDE(glVertex4iv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertex4iv' %i", err);

	MACH_OVERRIDE(void, glVertex4s, (GLshort x, GLshort y, GLshort z, GLshort w), err)
	{
		logger.glVertex4s(x, y, z, w);

		glVertex4s_reenter(x, y, z, w);
	} END_MACH_OVERRIDE(glVertex4s);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertex4s' %i", err);

	MACH_OVERRIDE(void, glVertex4sv, (const GLshort *v), err)
	{
		logger.glVertex4sv(v);

		glVertex4sv_reenter(v);
	} END_MACH_OVERRIDE(glVertex4sv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertex4sv' %i", err);

	MACH_OVERRIDE(void, glVertexPointer, (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer), err)
	{
		logger.glVertexPointer(size, type, stride, pointer);

		glVertexPointer_reenter(size, type, stride, pointer);
	} END_MACH_OVERRIDE(glVertexPointer);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertexPointer' %i", err);

	MACH_OVERRIDE(void, glViewport, (GLint x, GLint y, GLsizei width, GLsizei height), err)
	{
		logger.glViewport(x, y, width, height);

		glViewport_reenter(x, y, width, height);
	} END_MACH_OVERRIDE(glViewport);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glViewport' %i", err);

	MACH_OVERRIDE(void, glSampleCoverage, (GLclampf value, GLboolean invert), err)
	{
		logger.glSampleCoverage(value, invert);

		glSampleCoverage_reenter(value, invert);
	} END_MACH_OVERRIDE(glSampleCoverage);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glSampleCoverage' %i", err);

	MACH_OVERRIDE(void, glLoadTransposeMatrixf, (const GLfloat *m), err)
	{
		logger.glLoadTransposeMatrixf(m);

		glLoadTransposeMatrixf_reenter(m);
	} END_MACH_OVERRIDE(glLoadTransposeMatrixf);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glLoadTransposeMatrixf' %i", err);

	MACH_OVERRIDE(void, glLoadTransposeMatrixd, (const GLdouble *m), err)
	{
		logger.glLoadTransposeMatrixd(m);

		glLoadTransposeMatrixd_reenter(m);
	} END_MACH_OVERRIDE(glLoadTransposeMatrixd);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glLoadTransposeMatrixd' %i", err);

	MACH_OVERRIDE(void, glMultTransposeMatrixf, (const GLfloat *m), err)
	{
		logger.glMultTransposeMatrixf(m);

		glMultTransposeMatrixf_reenter(m);
	} END_MACH_OVERRIDE(glMultTransposeMatrixf);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glMultTransposeMatrixf' %i", err);

	MACH_OVERRIDE(void, glMultTransposeMatrixd, (const GLdouble *m), err)
	{
		logger.glMultTransposeMatrixd(m);

		glMultTransposeMatrixd_reenter(m);
	} END_MACH_OVERRIDE(glMultTransposeMatrixd);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glMultTransposeMatrixd' %i", err);

	MACH_OVERRIDE(void, glCompressedTexImage3D, (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *data), err)
	{
		logger.glCompressedTexImage3D(target, level, internalformat, width, height, depth, border, imageSize, data);

		glCompressedTexImage3D_reenter(target, level, internalformat, width, height, depth, border, imageSize, data);
	} END_MACH_OVERRIDE(glCompressedTexImage3D);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glCompressedTexImage3D' %i", err);

	MACH_OVERRIDE(void, glCompressedTexImage2D, (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data), err)
	{
		logger.glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data);

		glCompressedTexImage2D_reenter(target, level, internalformat, width, height, border, imageSize, data);
	} END_MACH_OVERRIDE(glCompressedTexImage2D);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glCompressedTexImage2D' %i", err);

	MACH_OVERRIDE(void, glCompressedTexImage1D, (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data), err)
	{
		logger.glCompressedTexImage1D(target, level, internalformat, width, border, imageSize, data);

		glCompressedTexImage1D_reenter(target, level, internalformat, width, border, imageSize, data);
	} END_MACH_OVERRIDE(glCompressedTexImage1D);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glCompressedTexImage1D' %i", err);

	MACH_OVERRIDE(void, glCompressedTexSubImage3D, (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data), err)
	{
		logger.glCompressedTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);

		glCompressedTexSubImage3D_reenter(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
	} END_MACH_OVERRIDE(glCompressedTexSubImage3D);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glCompressedTexSubImage3D' %i", err);

	MACH_OVERRIDE(void, glCompressedTexSubImage2D, (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data), err)
	{
		logger.glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data);

		glCompressedTexSubImage2D_reenter(target, level, xoffset, yoffset, width, height, format, imageSize, data);
	} END_MACH_OVERRIDE(glCompressedTexSubImage2D);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glCompressedTexSubImage2D' %i", err);

	MACH_OVERRIDE(void, glCompressedTexSubImage1D, (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data), err)
	{
		logger.glCompressedTexSubImage1D(target, level, xoffset, width, format, imageSize, data);

		glCompressedTexSubImage1D_reenter(target, level, xoffset, width, format, imageSize, data);
	} END_MACH_OVERRIDE(glCompressedTexSubImage1D);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glCompressedTexSubImage1D' %i", err);

	MACH_OVERRIDE(void, glGetCompressedTexImage, (GLenum target, GLint lod, GLvoid *img), err)
	{
		logger.glGetCompressedTexImage(target, lod, img);

		glGetCompressedTexImage_reenter(target, lod, img);
	} END_MACH_OVERRIDE(glGetCompressedTexImage);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetCompressedTexImage' %i", err);

	MACH_OVERRIDE(void, glActiveTexture, (GLenum texture), err)
	{
		logger.glActiveTexture(texture);

		glActiveTexture_reenter(texture);
	} END_MACH_OVERRIDE(glActiveTexture);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glActiveTexture' %i", err);

	MACH_OVERRIDE(void, glClientActiveTexture, (GLenum texture), err)
	{
		logger.glClientActiveTexture(texture);

		glClientActiveTexture_reenter(texture);
	} END_MACH_OVERRIDE(glClientActiveTexture);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glClientActiveTexture' %i", err);

	MACH_OVERRIDE(void, glMultiTexCoord1d, (GLenum target, GLdouble s), err)
	{
		logger.glMultiTexCoord1d(target, s);

		glMultiTexCoord1d_reenter(target, s);
	} END_MACH_OVERRIDE(glMultiTexCoord1d);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glMultiTexCoord1d' %i", err);

	MACH_OVERRIDE(void, glMultiTexCoord1dv, (GLenum target, const GLdouble *v), err)
	{
		logger.glMultiTexCoord1dv(target, v);

		glMultiTexCoord1dv_reenter(target, v);
	} END_MACH_OVERRIDE(glMultiTexCoord1dv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glMultiTexCoord1dv' %i", err);

	MACH_OVERRIDE(void, glMultiTexCoord1f, (GLenum target, GLfloat s), err)
	{
		logger.glMultiTexCoord1f(target, s);

		glMultiTexCoord1f_reenter(target, s);
	} END_MACH_OVERRIDE(glMultiTexCoord1f);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glMultiTexCoord1f' %i", err);

	MACH_OVERRIDE(void, glMultiTexCoord1fv, (GLenum target, const GLfloat *v), err)
	{
		logger.glMultiTexCoord1fv(target, v);

		glMultiTexCoord1fv_reenter(target, v);
	} END_MACH_OVERRIDE(glMultiTexCoord1fv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glMultiTexCoord1fv' %i", err);

	MACH_OVERRIDE(void, glMultiTexCoord1i, (GLenum target, GLint s), err)
	{
		logger.glMultiTexCoord1i(target, s);

		glMultiTexCoord1i_reenter(target, s);
	} END_MACH_OVERRIDE(glMultiTexCoord1i);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glMultiTexCoord1i' %i", err);

	MACH_OVERRIDE(void, glMultiTexCoord1iv, (GLenum target, const GLint *v), err)
	{
		logger.glMultiTexCoord1iv(target, v);

		glMultiTexCoord1iv_reenter(target, v);
	} END_MACH_OVERRIDE(glMultiTexCoord1iv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glMultiTexCoord1iv' %i", err);

	MACH_OVERRIDE(void, glMultiTexCoord1s, (GLenum target, GLshort s), err)
	{
		logger.glMultiTexCoord1s(target, s);

		glMultiTexCoord1s_reenter(target, s);
	} END_MACH_OVERRIDE(glMultiTexCoord1s);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glMultiTexCoord1s' %i", err);

	MACH_OVERRIDE(void, glMultiTexCoord1sv, (GLenum target, const GLshort *v), err)
	{
		logger.glMultiTexCoord1sv(target, v);

		glMultiTexCoord1sv_reenter(target, v);
	} END_MACH_OVERRIDE(glMultiTexCoord1sv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glMultiTexCoord1sv' %i", err);

	MACH_OVERRIDE(void, glMultiTexCoord2d, (GLenum target, GLdouble s, GLdouble t), err)
	{
		logger.glMultiTexCoord2d(target, s, t);

		glMultiTexCoord2d_reenter(target, s, t);
	} END_MACH_OVERRIDE(glMultiTexCoord2d);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glMultiTexCoord2d' %i", err);

	MACH_OVERRIDE(void, glMultiTexCoord2dv, (GLenum target, const GLdouble *v), err)
	{
		logger.glMultiTexCoord2dv(target, v);

		glMultiTexCoord2dv_reenter(target, v);
	} END_MACH_OVERRIDE(glMultiTexCoord2dv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glMultiTexCoord2dv' %i", err);

	MACH_OVERRIDE(void, glMultiTexCoord2f, (GLenum target, GLfloat s, GLfloat t), err)
	{
		logger.glMultiTexCoord2f(target, s, t);

		glMultiTexCoord2f_reenter(target, s, t);
	} END_MACH_OVERRIDE(glMultiTexCoord2f);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glMultiTexCoord2f' %i", err);

	MACH_OVERRIDE(void, glMultiTexCoord2fv, (GLenum target, const GLfloat *v), err)
	{
		logger.glMultiTexCoord2fv(target, v);

		glMultiTexCoord2fv_reenter(target, v);
	} END_MACH_OVERRIDE(glMultiTexCoord2fv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glMultiTexCoord2fv' %i", err);

	MACH_OVERRIDE(void, glMultiTexCoord2i, (GLenum target, GLint s, GLint t), err)
	{
		logger.glMultiTexCoord2i(target, s, t);

		glMultiTexCoord2i_reenter(target, s, t);
	} END_MACH_OVERRIDE(glMultiTexCoord2i);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glMultiTexCoord2i' %i", err);

	MACH_OVERRIDE(void, glMultiTexCoord2iv, (GLenum target, const GLint *v), err)
	{
		logger.glMultiTexCoord2iv(target, v);

		glMultiTexCoord2iv_reenter(target, v);
	} END_MACH_OVERRIDE(glMultiTexCoord2iv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glMultiTexCoord2iv' %i", err);

	MACH_OVERRIDE(void, glMultiTexCoord2s, (GLenum target, GLshort s, GLshort t), err)
	{
		logger.glMultiTexCoord2s(target, s, t);

		glMultiTexCoord2s_reenter(target, s, t);
	} END_MACH_OVERRIDE(glMultiTexCoord2s);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glMultiTexCoord2s' %i", err);

	MACH_OVERRIDE(void, glMultiTexCoord2sv, (GLenum target, const GLshort *v), err)
	{
		logger.glMultiTexCoord2sv(target, v);

		glMultiTexCoord2sv_reenter(target, v);
	} END_MACH_OVERRIDE(glMultiTexCoord2sv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glMultiTexCoord2sv' %i", err);

	MACH_OVERRIDE(void, glMultiTexCoord3d, (GLenum target, GLdouble s, GLdouble t, GLdouble r), err)
	{
		logger.glMultiTexCoord3d(target, s, t, r);

		glMultiTexCoord3d_reenter(target, s, t, r);
	} END_MACH_OVERRIDE(glMultiTexCoord3d);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glMultiTexCoord3d' %i", err);

	MACH_OVERRIDE(void, glMultiTexCoord3dv, (GLenum target, const GLdouble *v), err)
	{
		logger.glMultiTexCoord3dv(target, v);

		glMultiTexCoord3dv_reenter(target, v);
	} END_MACH_OVERRIDE(glMultiTexCoord3dv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glMultiTexCoord3dv' %i", err);

	MACH_OVERRIDE(void, glMultiTexCoord3f, (GLenum target, GLfloat s, GLfloat t, GLfloat r), err)
	{
		logger.glMultiTexCoord3f(target, s, t, r);

		glMultiTexCoord3f_reenter(target, s, t, r);
	} END_MACH_OVERRIDE(glMultiTexCoord3f);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glMultiTexCoord3f' %i", err);

	MACH_OVERRIDE(void, glMultiTexCoord3fv, (GLenum target, const GLfloat *v), err)
	{
		logger.glMultiTexCoord3fv(target, v);

		glMultiTexCoord3fv_reenter(target, v);
	} END_MACH_OVERRIDE(glMultiTexCoord3fv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glMultiTexCoord3fv' %i", err);

	MACH_OVERRIDE(void, glMultiTexCoord3i, (GLenum target, GLint s, GLint t, GLint r), err)
	{
		logger.glMultiTexCoord3i(target, s, t, r);

		glMultiTexCoord3i_reenter(target, s, t, r);
	} END_MACH_OVERRIDE(glMultiTexCoord3i);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glMultiTexCoord3i' %i", err);

	MACH_OVERRIDE(void, glMultiTexCoord3iv, (GLenum target, const GLint *v), err)
	{
		logger.glMultiTexCoord3iv(target, v);

		glMultiTexCoord3iv_reenter(target, v);
	} END_MACH_OVERRIDE(glMultiTexCoord3iv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glMultiTexCoord3iv' %i", err);

	MACH_OVERRIDE(void, glMultiTexCoord3s, (GLenum target, GLshort s, GLshort t, GLshort r), err)
	{
		logger.glMultiTexCoord3s(target, s, t, r);

		glMultiTexCoord3s_reenter(target, s, t, r);
	} END_MACH_OVERRIDE(glMultiTexCoord3s);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glMultiTexCoord3s' %i", err);

	MACH_OVERRIDE(void, glMultiTexCoord3sv, (GLenum target, const GLshort *v), err)
	{
		logger.glMultiTexCoord3sv(target, v);

		glMultiTexCoord3sv_reenter(target, v);
	} END_MACH_OVERRIDE(glMultiTexCoord3sv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glMultiTexCoord3sv' %i", err);

	MACH_OVERRIDE(void, glMultiTexCoord4d, (GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q), err)
	{
		logger.glMultiTexCoord4d(target, s, t, r, q);

		glMultiTexCoord4d_reenter(target, s, t, r, q);
	} END_MACH_OVERRIDE(glMultiTexCoord4d);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glMultiTexCoord4d' %i", err);

	MACH_OVERRIDE(void, glMultiTexCoord4dv, (GLenum target, const GLdouble *v), err)
	{
		logger.glMultiTexCoord4dv(target, v);

		glMultiTexCoord4dv_reenter(target, v);
	} END_MACH_OVERRIDE(glMultiTexCoord4dv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glMultiTexCoord4dv' %i", err);

	MACH_OVERRIDE(void, glMultiTexCoord4f, (GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q), err)
	{
		logger.glMultiTexCoord4f(target, s, t, r, q);

		glMultiTexCoord4f_reenter(target, s, t, r, q);
	} END_MACH_OVERRIDE(glMultiTexCoord4f);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glMultiTexCoord4f' %i", err);

	MACH_OVERRIDE(void, glMultiTexCoord4fv, (GLenum target, const GLfloat *v), err)
	{
		logger.glMultiTexCoord4fv(target, v);

		glMultiTexCoord4fv_reenter(target, v);
	} END_MACH_OVERRIDE(glMultiTexCoord4fv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glMultiTexCoord4fv' %i", err);

	MACH_OVERRIDE(void, glMultiTexCoord4i, (GLenum target, GLint s, GLint t, GLint r, GLint q), err)
	{
		logger.glMultiTexCoord4i(target, s, t, r, q);

		glMultiTexCoord4i_reenter(target, s, t, r, q);
	} END_MACH_OVERRIDE(glMultiTexCoord4i);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glMultiTexCoord4i' %i", err);

	MACH_OVERRIDE(void, glMultiTexCoord4iv, (GLenum target, const GLint *v), err)
	{
		logger.glMultiTexCoord4iv(target, v);

		glMultiTexCoord4iv_reenter(target, v);
	} END_MACH_OVERRIDE(glMultiTexCoord4iv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glMultiTexCoord4iv' %i", err);

	MACH_OVERRIDE(void, glMultiTexCoord4s, (GLenum target, GLshort s, GLshort t, GLshort r, GLshort q), err)
	{
		logger.glMultiTexCoord4s(target, s, t, r, q);

		glMultiTexCoord4s_reenter(target, s, t, r, q);
	} END_MACH_OVERRIDE(glMultiTexCoord4s);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glMultiTexCoord4s' %i", err);

	MACH_OVERRIDE(void, glMultiTexCoord4sv, (GLenum target, const GLshort *v), err)
	{
		logger.glMultiTexCoord4sv(target, v);

		glMultiTexCoord4sv_reenter(target, v);
	} END_MACH_OVERRIDE(glMultiTexCoord4sv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glMultiTexCoord4sv' %i", err);

	MACH_OVERRIDE(void, glFogCoordf, (GLfloat coord), err)
	{
		logger.glFogCoordf(coord);

		glFogCoordf_reenter(coord);
	} END_MACH_OVERRIDE(glFogCoordf);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glFogCoordf' %i", err);

	MACH_OVERRIDE(void, glFogCoordfv, (const GLfloat *coord), err)
	{
		logger.glFogCoordfv(coord);

		glFogCoordfv_reenter(coord);
	} END_MACH_OVERRIDE(glFogCoordfv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glFogCoordfv' %i", err);

	MACH_OVERRIDE(void, glFogCoordd, (GLdouble coord), err)
	{
		logger.glFogCoordd(coord);

		glFogCoordd_reenter(coord);
	} END_MACH_OVERRIDE(glFogCoordd);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glFogCoordd' %i", err);

	MACH_OVERRIDE(void, glFogCoorddv, (const GLdouble *coord), err)
	{
		logger.glFogCoorddv(coord);

		glFogCoorddv_reenter(coord);
	} END_MACH_OVERRIDE(glFogCoorddv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glFogCoorddv' %i", err);

	MACH_OVERRIDE(void, glFogCoordPointer, (GLenum type, GLsizei stride, const GLvoid *pointer), err)
	{
		logger.glFogCoordPointer(type, stride, pointer);

		glFogCoordPointer_reenter(type, stride, pointer);
	} END_MACH_OVERRIDE(glFogCoordPointer);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glFogCoordPointer' %i", err);

	MACH_OVERRIDE(void, glSecondaryColor3b, (GLbyte red, GLbyte green, GLbyte blue), err)
	{
		logger.glSecondaryColor3b(red, green, blue);

		glSecondaryColor3b_reenter(red, green, blue);
	} END_MACH_OVERRIDE(glSecondaryColor3b);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glSecondaryColor3b' %i", err);

	MACH_OVERRIDE(void, glSecondaryColor3bv, (const GLbyte *v), err)
	{
		logger.glSecondaryColor3bv(v);

		glSecondaryColor3bv_reenter(v);
	} END_MACH_OVERRIDE(glSecondaryColor3bv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glSecondaryColor3bv' %i", err);

	MACH_OVERRIDE(void, glSecondaryColor3d, (GLdouble red, GLdouble green, GLdouble blue), err)
	{
		logger.glSecondaryColor3d(red, green, blue);

		glSecondaryColor3d_reenter(red, green, blue);
	} END_MACH_OVERRIDE(glSecondaryColor3d);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glSecondaryColor3d' %i", err);

	MACH_OVERRIDE(void, glSecondaryColor3dv, (const GLdouble *v), err)
	{
		logger.glSecondaryColor3dv(v);

		glSecondaryColor3dv_reenter(v);
	} END_MACH_OVERRIDE(glSecondaryColor3dv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glSecondaryColor3dv' %i", err);

	MACH_OVERRIDE(void, glSecondaryColor3f, (GLfloat red, GLfloat green, GLfloat blue), err)
	{
		logger.glSecondaryColor3f(red, green, blue);

		glSecondaryColor3f_reenter(red, green, blue);
	} END_MACH_OVERRIDE(glSecondaryColor3f);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glSecondaryColor3f' %i", err);

	MACH_OVERRIDE(void, glSecondaryColor3fv, (const GLfloat *v), err)
	{
		logger.glSecondaryColor3fv(v);

		glSecondaryColor3fv_reenter(v);
	} END_MACH_OVERRIDE(glSecondaryColor3fv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glSecondaryColor3fv' %i", err);

	MACH_OVERRIDE(void, glSecondaryColor3i, (GLint red, GLint green, GLint blue), err)
	{
		logger.glSecondaryColor3i(red, green, blue);

		glSecondaryColor3i_reenter(red, green, blue);
	} END_MACH_OVERRIDE(glSecondaryColor3i);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glSecondaryColor3i' %i", err);

	MACH_OVERRIDE(void, glSecondaryColor3iv, (const GLint *v), err)
	{
		logger.glSecondaryColor3iv(v);

		glSecondaryColor3iv_reenter(v);
	} END_MACH_OVERRIDE(glSecondaryColor3iv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glSecondaryColor3iv' %i", err);

	MACH_OVERRIDE(void, glSecondaryColor3s, (GLshort red, GLshort green, GLshort blue), err)
	{
		logger.glSecondaryColor3s(red, green, blue);

		glSecondaryColor3s_reenter(red, green, blue);
	} END_MACH_OVERRIDE(glSecondaryColor3s);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glSecondaryColor3s' %i", err);

	MACH_OVERRIDE(void, glSecondaryColor3sv, (const GLshort *v), err)
	{
		logger.glSecondaryColor3sv(v);

		glSecondaryColor3sv_reenter(v);
	} END_MACH_OVERRIDE(glSecondaryColor3sv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glSecondaryColor3sv' %i", err);

	MACH_OVERRIDE(void, glSecondaryColor3ub, (GLubyte red, GLubyte green, GLubyte blue), err)
	{
		logger.glSecondaryColor3ub(red, green, blue);

		glSecondaryColor3ub_reenter(red, green, blue);
	} END_MACH_OVERRIDE(glSecondaryColor3ub);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glSecondaryColor3ub' %i", err);

	MACH_OVERRIDE(void, glSecondaryColor3ubv, (const GLubyte *v), err)
	{
		logger.glSecondaryColor3ubv(v);

		glSecondaryColor3ubv_reenter(v);
	} END_MACH_OVERRIDE(glSecondaryColor3ubv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glSecondaryColor3ubv' %i", err);

	MACH_OVERRIDE(void, glSecondaryColor3ui, (GLuint red, GLuint green, GLuint blue), err)
	{
		logger.glSecondaryColor3ui(red, green, blue);

		glSecondaryColor3ui_reenter(red, green, blue);
	} END_MACH_OVERRIDE(glSecondaryColor3ui);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glSecondaryColor3ui' %i", err);

	MACH_OVERRIDE(void, glSecondaryColor3uiv, (const GLuint *v), err)
	{
		logger.glSecondaryColor3uiv(v);

		glSecondaryColor3uiv_reenter(v);
	} END_MACH_OVERRIDE(glSecondaryColor3uiv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glSecondaryColor3uiv' %i", err);

	MACH_OVERRIDE(void, glSecondaryColor3us, (GLushort red, GLushort green, GLushort blue), err)
	{
		logger.glSecondaryColor3us(red, green, blue);

		glSecondaryColor3us_reenter(red, green, blue);
	} END_MACH_OVERRIDE(glSecondaryColor3us);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glSecondaryColor3us' %i", err);

	MACH_OVERRIDE(void, glSecondaryColor3usv, (const GLushort *v), err)
	{
		logger.glSecondaryColor3usv(v);

		glSecondaryColor3usv_reenter(v);
	} END_MACH_OVERRIDE(glSecondaryColor3usv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glSecondaryColor3usv' %i", err);

	MACH_OVERRIDE(void, glSecondaryColorPointer, (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer), err)
	{
		logger.glSecondaryColorPointer(size, type, stride, pointer);

		glSecondaryColorPointer_reenter(size, type, stride, pointer);
	} END_MACH_OVERRIDE(glSecondaryColorPointer);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glSecondaryColorPointer' %i", err);

	MACH_OVERRIDE(void, glPointParameterf, (GLenum pname, GLfloat param), err)
	{
		logger.glPointParameterf(pname, param);

		glPointParameterf_reenter(pname, param);
	} END_MACH_OVERRIDE(glPointParameterf);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glPointParameterf' %i", err);

	MACH_OVERRIDE(void, glPointParameterfv, (GLenum pname, const GLfloat *params), err)
	{
		logger.glPointParameterfv(pname, params);

		glPointParameterfv_reenter(pname, params);
	} END_MACH_OVERRIDE(glPointParameterfv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glPointParameterfv' %i", err);

	MACH_OVERRIDE(void, glPointParameteri, (GLenum pname, GLint param), err)
	{
		logger.glPointParameteri(pname, param);

		glPointParameteri_reenter(pname, param);
	} END_MACH_OVERRIDE(glPointParameteri);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glPointParameteri' %i", err);

	MACH_OVERRIDE(void, glPointParameteriv, (GLenum pname, const GLint *params), err)
	{
		logger.glPointParameteriv(pname, params);

		glPointParameteriv_reenter(pname, params);
	} END_MACH_OVERRIDE(glPointParameteriv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glPointParameteriv' %i", err);

	MACH_OVERRIDE(void, glBlendFuncSeparate, (GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha), err)
	{
		logger.glBlendFuncSeparate(srcRGB, dstRGB, srcAlpha, dstAlpha);

		glBlendFuncSeparate_reenter(srcRGB, dstRGB, srcAlpha, dstAlpha);
	} END_MACH_OVERRIDE(glBlendFuncSeparate);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glBlendFuncSeparate' %i", err);

	MACH_OVERRIDE(void, glMultiDrawArrays, (GLenum mode, const GLint *first, const GLsizei *count, GLsizei primcount), err)
	{
		logger.glMultiDrawArrays(mode, first, count, primcount);

		glMultiDrawArrays_reenter(mode, first, count, primcount);
	} END_MACH_OVERRIDE(glMultiDrawArrays);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glMultiDrawArrays' %i", err);

	MACH_OVERRIDE(void, glMultiDrawElements, (GLenum mode, const GLsizei *count, GLenum type, const GLvoid* const *indices, GLsizei primcount), err)
	{
		logger.glMultiDrawElements(mode, count, type, indices, primcount);

		glMultiDrawElements_reenter(mode, count, type, indices, primcount);
	} END_MACH_OVERRIDE(glMultiDrawElements);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glMultiDrawElements' %i", err);

	MACH_OVERRIDE(void, glWindowPos2d, (GLdouble x, GLdouble y), err)
	{
		logger.glWindowPos2d(x, y);

		glWindowPos2d_reenter(x, y);
	} END_MACH_OVERRIDE(glWindowPos2d);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glWindowPos2d' %i", err);

	MACH_OVERRIDE(void, glWindowPos2dv, (const GLdouble *v), err)
	{
		logger.glWindowPos2dv(v);

		glWindowPos2dv_reenter(v);
	} END_MACH_OVERRIDE(glWindowPos2dv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glWindowPos2dv' %i", err);

	MACH_OVERRIDE(void, glWindowPos2f, (GLfloat x, GLfloat y), err)
	{
		logger.glWindowPos2f(x, y);

		glWindowPos2f_reenter(x, y);
	} END_MACH_OVERRIDE(glWindowPos2f);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glWindowPos2f' %i", err);

	MACH_OVERRIDE(void, glWindowPos2fv, (const GLfloat *v), err)
	{
		logger.glWindowPos2fv(v);

		glWindowPos2fv_reenter(v);
	} END_MACH_OVERRIDE(glWindowPos2fv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glWindowPos2fv' %i", err);

	MACH_OVERRIDE(void, glWindowPos2i, (GLint x, GLint y), err)
	{
		logger.glWindowPos2i(x, y);

		glWindowPos2i_reenter(x, y);
	} END_MACH_OVERRIDE(glWindowPos2i);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glWindowPos2i' %i", err);

	MACH_OVERRIDE(void, glWindowPos2iv, (const GLint *v), err)
	{
		logger.glWindowPos2iv(v);

		glWindowPos2iv_reenter(v);
	} END_MACH_OVERRIDE(glWindowPos2iv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glWindowPos2iv' %i", err);

	MACH_OVERRIDE(void, glWindowPos2s, (GLshort x, GLshort y), err)
	{
		logger.glWindowPos2s(x, y);

		glWindowPos2s_reenter(x, y);
	} END_MACH_OVERRIDE(glWindowPos2s);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glWindowPos2s' %i", err);

	MACH_OVERRIDE(void, glWindowPos2sv, (const GLshort *v), err)
	{
		logger.glWindowPos2sv(v);

		glWindowPos2sv_reenter(v);
	} END_MACH_OVERRIDE(glWindowPos2sv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glWindowPos2sv' %i", err);

	MACH_OVERRIDE(void, glWindowPos3d, (GLdouble x, GLdouble y, GLdouble z), err)
	{
		logger.glWindowPos3d(x, y, z);

		glWindowPos3d_reenter(x, y, z);
	} END_MACH_OVERRIDE(glWindowPos3d);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glWindowPos3d' %i", err);

	MACH_OVERRIDE(void, glWindowPos3dv, (const GLdouble *v), err)
	{
		logger.glWindowPos3dv(v);

		glWindowPos3dv_reenter(v);
	} END_MACH_OVERRIDE(glWindowPos3dv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glWindowPos3dv' %i", err);

	MACH_OVERRIDE(void, glWindowPos3f, (GLfloat x, GLfloat y, GLfloat z), err)
	{
		logger.glWindowPos3f(x, y, z);

		glWindowPos3f_reenter(x, y, z);
	} END_MACH_OVERRIDE(glWindowPos3f);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glWindowPos3f' %i", err);

	MACH_OVERRIDE(void, glWindowPos3fv, (const GLfloat *v), err)
	{
		logger.glWindowPos3fv(v);

		glWindowPos3fv_reenter(v);
	} END_MACH_OVERRIDE(glWindowPos3fv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glWindowPos3fv' %i", err);

	MACH_OVERRIDE(void, glWindowPos3i, (GLint x, GLint y, GLint z), err)
	{
		logger.glWindowPos3i(x, y, z);

		glWindowPos3i_reenter(x, y, z);
	} END_MACH_OVERRIDE(glWindowPos3i);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glWindowPos3i' %i", err);

	MACH_OVERRIDE(void, glWindowPos3iv, (const GLint *v), err)
	{
		logger.glWindowPos3iv(v);

		glWindowPos3iv_reenter(v);
	} END_MACH_OVERRIDE(glWindowPos3iv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glWindowPos3iv' %i", err);

	MACH_OVERRIDE(void, glWindowPos3s, (GLshort x, GLshort y, GLshort z), err)
	{
		logger.glWindowPos3s(x, y, z);

		glWindowPos3s_reenter(x, y, z);
	} END_MACH_OVERRIDE(glWindowPos3s);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glWindowPos3s' %i", err);

	MACH_OVERRIDE(void, glWindowPos3sv, (const GLshort *v), err)
	{
		logger.glWindowPos3sv(v);

		glWindowPos3sv_reenter(v);
	} END_MACH_OVERRIDE(glWindowPos3sv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glWindowPos3sv' %i", err);

	MACH_OVERRIDE(void, glGenQueries, (GLsizei n, GLuint *ids), err)
	{
		logger.glGenQueries(n, ids);

		glGenQueries_reenter(n, ids);
	} END_MACH_OVERRIDE(glGenQueries);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGenQueries' %i", err);

	MACH_OVERRIDE(void, glDeleteQueries, (GLsizei n, const GLuint *ids), err)
	{
		logger.glDeleteQueries(n, ids);

		glDeleteQueries_reenter(n, ids);
	} END_MACH_OVERRIDE(glDeleteQueries);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glDeleteQueries' %i", err);

	MACH_OVERRIDE(GLboolean, glIsQuery, (GLuint id), err)
	{
		logger.glIsQuery(id);

		return glIsQuery_reenter(id);
	} END_MACH_OVERRIDE(glIsQuery);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glIsQuery' %i", err);

	MACH_OVERRIDE(void, glBeginQuery, (GLenum target, GLuint id), err)
	{
		logger.glBeginQuery(target, id);

		glBeginQuery_reenter(target, id);
	} END_MACH_OVERRIDE(glBeginQuery);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glBeginQuery' %i", err);

	MACH_OVERRIDE(void, glEndQuery, (GLenum target), err)
	{
		logger.glEndQuery(target);

		glEndQuery_reenter(target);
	} END_MACH_OVERRIDE(glEndQuery);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glEndQuery' %i", err);

	MACH_OVERRIDE(void, glGetQueryiv, (GLenum target, GLenum pname, GLint *params), err)
	{
		logger.glGetQueryiv(target, pname, params);

		glGetQueryiv_reenter(target, pname, params);
	} END_MACH_OVERRIDE(glGetQueryiv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetQueryiv' %i", err);

	MACH_OVERRIDE(void, glGetQueryObjectiv, (GLuint id, GLenum pname, GLint *params), err)
	{
		logger.glGetQueryObjectiv(id, pname, params);

		glGetQueryObjectiv_reenter(id, pname, params);
	} END_MACH_OVERRIDE(glGetQueryObjectiv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetQueryObjectiv' %i", err);

	MACH_OVERRIDE(void, glGetQueryObjectuiv, (GLuint id, GLenum pname, GLuint *params), err)
	{
		logger.glGetQueryObjectuiv(id, pname, params);

		glGetQueryObjectuiv_reenter(id, pname, params);
	} END_MACH_OVERRIDE(glGetQueryObjectuiv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetQueryObjectuiv' %i", err);

	MACH_OVERRIDE(void, glBindBuffer, (GLenum target, GLuint buffer), err)
	{
		logger.glBindBuffer(target, buffer);

		glBindBuffer_reenter(target, buffer);
	} END_MACH_OVERRIDE(glBindBuffer);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glBindBuffer' %i", err);

	MACH_OVERRIDE(void, glDeleteBuffers, (GLsizei n, const GLuint *buffers), err)
	{
		logger.glDeleteBuffers(n, buffers);

		glDeleteBuffers_reenter(n, buffers);
	} END_MACH_OVERRIDE(glDeleteBuffers);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glDeleteBuffers' %i", err);

	MACH_OVERRIDE(void, glGenBuffers, (GLsizei n, GLuint *buffers), err)
	{
		logger.glGenBuffers(n, buffers);

		glGenBuffers_reenter(n, buffers);
	} END_MACH_OVERRIDE(glGenBuffers);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGenBuffers' %i", err);

	MACH_OVERRIDE(GLboolean, glIsBuffer, (GLuint buffer), err)
	{
		logger.glIsBuffer(buffer);

		return glIsBuffer_reenter(buffer);
	} END_MACH_OVERRIDE(glIsBuffer);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glIsBuffer' %i", err);

	MACH_OVERRIDE(void, glBufferData, (GLenum target, GLsizeiptr size, const GLvoid *data, GLenum usage), err)
	{
		logger.glBufferData(target, size, data, usage);

		glBufferData_reenter(target, size, data, usage);
	} END_MACH_OVERRIDE(glBufferData);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glBufferData' %i", err);

	MACH_OVERRIDE(void, glBufferSubData, (GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid *data), err)
	{
		logger.glBufferSubData(target, offset, size, data);

		glBufferSubData_reenter(target, offset, size, data);
	} END_MACH_OVERRIDE(glBufferSubData);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glBufferSubData' %i", err);

	MACH_OVERRIDE(void, glGetBufferSubData, (GLenum target, GLintptr offset, GLsizeiptr size, GLvoid *data), err)
	{
		logger.glGetBufferSubData(target, offset, size, data);

		glGetBufferSubData_reenter(target, offset, size, data);
	} END_MACH_OVERRIDE(glGetBufferSubData);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetBufferSubData' %i", err);

	MACH_OVERRIDE(GLvoid *, glMapBuffer, (GLenum target, GLenum access), err)
	{
		logger.glMapBuffer(target, access);

		return glMapBuffer_reenter(target, access);
	} END_MACH_OVERRIDE(glMapBuffer);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glMapBuffer' %i", err);

	MACH_OVERRIDE(GLboolean, glUnmapBuffer, (GLenum target), err)
	{
		logger.glUnmapBuffer(target);

		return glUnmapBuffer_reenter(target);
	} END_MACH_OVERRIDE(glUnmapBuffer);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glUnmapBuffer' %i", err);

	MACH_OVERRIDE(void, glGetBufferParameteriv, (GLenum target, GLenum pname, GLint *params), err)
	{
		logger.glGetBufferParameteriv(target, pname, params);

		glGetBufferParameteriv_reenter(target, pname, params);
	} END_MACH_OVERRIDE(glGetBufferParameteriv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetBufferParameteriv' %i", err);

	MACH_OVERRIDE(void, glGetBufferPointerv, (GLenum target, GLenum pname, GLvoid **params), err)
	{
		logger.glGetBufferPointerv(target, pname, params);

		glGetBufferPointerv_reenter(target, pname, params);
	} END_MACH_OVERRIDE(glGetBufferPointerv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetBufferPointerv' %i", err);

	MACH_OVERRIDE(void, glDrawBuffers, (GLsizei n, const GLenum *bufs), err)
	{
		logger.glDrawBuffers(n, bufs);

		glDrawBuffers_reenter(n, bufs);
	} END_MACH_OVERRIDE(glDrawBuffers);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glDrawBuffers' %i", err);

	MACH_OVERRIDE(void, glVertexAttrib1d, (GLuint index, GLdouble x), err)
	{
		logger.glVertexAttrib1d(index, x);

		glVertexAttrib1d_reenter(index, x);
	} END_MACH_OVERRIDE(glVertexAttrib1d);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertexAttrib1d' %i", err);

	MACH_OVERRIDE(void, glVertexAttrib1dv, (GLuint index, const GLdouble *v), err)
	{
		logger.glVertexAttrib1dv(index, v);

		glVertexAttrib1dv_reenter(index, v);
	} END_MACH_OVERRIDE(glVertexAttrib1dv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertexAttrib1dv' %i", err);

	MACH_OVERRIDE(void, glVertexAttrib1f, (GLuint index, GLfloat x), err)
	{
		logger.glVertexAttrib1f(index, x);

		glVertexAttrib1f_reenter(index, x);
	} END_MACH_OVERRIDE(glVertexAttrib1f);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertexAttrib1f' %i", err);

	MACH_OVERRIDE(void, glVertexAttrib1fv, (GLuint index, const GLfloat *v), err)
	{
		logger.glVertexAttrib1fv(index, v);

		glVertexAttrib1fv_reenter(index, v);
	} END_MACH_OVERRIDE(glVertexAttrib1fv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertexAttrib1fv' %i", err);

	MACH_OVERRIDE(void, glVertexAttrib1s, (GLuint index, GLshort x), err)
	{
		logger.glVertexAttrib1s(index, x);

		glVertexAttrib1s_reenter(index, x);
	} END_MACH_OVERRIDE(glVertexAttrib1s);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertexAttrib1s' %i", err);

	MACH_OVERRIDE(void, glVertexAttrib1sv, (GLuint index, const GLshort *v), err)
	{
		logger.glVertexAttrib1sv(index, v);

		glVertexAttrib1sv_reenter(index, v);
	} END_MACH_OVERRIDE(glVertexAttrib1sv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertexAttrib1sv' %i", err);

	MACH_OVERRIDE(void, glVertexAttrib2d, (GLuint index, GLdouble x, GLdouble y), err)
	{
		logger.glVertexAttrib2d(index, x, y);

		glVertexAttrib2d_reenter(index, x, y);
	} END_MACH_OVERRIDE(glVertexAttrib2d);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertexAttrib2d' %i", err);

	MACH_OVERRIDE(void, glVertexAttrib2dv, (GLuint index, const GLdouble *v), err)
	{
		logger.glVertexAttrib2dv(index, v);

		glVertexAttrib2dv_reenter(index, v);
	} END_MACH_OVERRIDE(glVertexAttrib2dv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertexAttrib2dv' %i", err);

	MACH_OVERRIDE(void, glVertexAttrib2f, (GLuint index, GLfloat x, GLfloat y), err)
	{
		logger.glVertexAttrib2f(index, x, y);

		glVertexAttrib2f_reenter(index, x, y);
	} END_MACH_OVERRIDE(glVertexAttrib2f);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertexAttrib2f' %i", err);

	MACH_OVERRIDE(void, glVertexAttrib2fv, (GLuint index, const GLfloat *v), err)
	{
		logger.glVertexAttrib2fv(index, v);

		glVertexAttrib2fv_reenter(index, v);
	} END_MACH_OVERRIDE(glVertexAttrib2fv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertexAttrib2fv' %i", err);

	MACH_OVERRIDE(void, glVertexAttrib2s, (GLuint index, GLshort x, GLshort y), err)
	{
		logger.glVertexAttrib2s(index, x, y);

		glVertexAttrib2s_reenter(index, x, y);
	} END_MACH_OVERRIDE(glVertexAttrib2s);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertexAttrib2s' %i", err);

	MACH_OVERRIDE(void, glVertexAttrib2sv, (GLuint index, const GLshort *v), err)
	{
		logger.glVertexAttrib2sv(index, v);

		glVertexAttrib2sv_reenter(index, v);
	} END_MACH_OVERRIDE(glVertexAttrib2sv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertexAttrib2sv' %i", err);

	MACH_OVERRIDE(void, glVertexAttrib3d, (GLuint index, GLdouble x, GLdouble y, GLdouble z), err)
	{
		logger.glVertexAttrib3d(index, x, y, z);

		glVertexAttrib3d_reenter(index, x, y, z);
	} END_MACH_OVERRIDE(glVertexAttrib3d);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertexAttrib3d' %i", err);

	MACH_OVERRIDE(void, glVertexAttrib3dv, (GLuint index, const GLdouble *v), err)
	{
		logger.glVertexAttrib3dv(index, v);

		glVertexAttrib3dv_reenter(index, v);
	} END_MACH_OVERRIDE(glVertexAttrib3dv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertexAttrib3dv' %i", err);

	MACH_OVERRIDE(void, glVertexAttrib3f, (GLuint index, GLfloat x, GLfloat y, GLfloat z), err)
	{
		logger.glVertexAttrib3f(index, x, y, z);

		glVertexAttrib3f_reenter(index, x, y, z);
	} END_MACH_OVERRIDE(glVertexAttrib3f);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertexAttrib3f' %i", err);

	MACH_OVERRIDE(void, glVertexAttrib3fv, (GLuint index, const GLfloat *v), err)
	{
		logger.glVertexAttrib3fv(index, v);

		glVertexAttrib3fv_reenter(index, v);
	} END_MACH_OVERRIDE(glVertexAttrib3fv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertexAttrib3fv' %i", err);

	MACH_OVERRIDE(void, glVertexAttrib3s, (GLuint index, GLshort x, GLshort y, GLshort z), err)
	{
		logger.glVertexAttrib3s(index, x, y, z);

		glVertexAttrib3s_reenter(index, x, y, z);
	} END_MACH_OVERRIDE(glVertexAttrib3s);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertexAttrib3s' %i", err);

	MACH_OVERRIDE(void, glVertexAttrib3sv, (GLuint index, const GLshort *v), err)
	{
		logger.glVertexAttrib3sv(index, v);

		glVertexAttrib3sv_reenter(index, v);
	} END_MACH_OVERRIDE(glVertexAttrib3sv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertexAttrib3sv' %i", err);

	MACH_OVERRIDE(void, glVertexAttrib4Nbv, (GLuint index, const GLbyte *v), err)
	{
		logger.glVertexAttrib4Nbv(index, v);

		glVertexAttrib4Nbv_reenter(index, v);
	} END_MACH_OVERRIDE(glVertexAttrib4Nbv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertexAttrib4Nbv' %i", err);

	MACH_OVERRIDE(void, glVertexAttrib4Niv, (GLuint index, const GLint *v), err)
	{
		logger.glVertexAttrib4Niv(index, v);

		glVertexAttrib4Niv_reenter(index, v);
	} END_MACH_OVERRIDE(glVertexAttrib4Niv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertexAttrib4Niv' %i", err);

	MACH_OVERRIDE(void, glVertexAttrib4Nsv, (GLuint index, const GLshort *v), err)
	{
		logger.glVertexAttrib4Nsv(index, v);

		glVertexAttrib4Nsv_reenter(index, v);
	} END_MACH_OVERRIDE(glVertexAttrib4Nsv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertexAttrib4Nsv' %i", err);

	MACH_OVERRIDE(void, glVertexAttrib4Nub, (GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w), err)
	{
		logger.glVertexAttrib4Nub(index, x, y, z, w);

		glVertexAttrib4Nub_reenter(index, x, y, z, w);
	} END_MACH_OVERRIDE(glVertexAttrib4Nub);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertexAttrib4Nub' %i", err);

	MACH_OVERRIDE(void, glVertexAttrib4Nubv, (GLuint index, const GLubyte *v), err)
	{
		logger.glVertexAttrib4Nubv(index, v);

		glVertexAttrib4Nubv_reenter(index, v);
	} END_MACH_OVERRIDE(glVertexAttrib4Nubv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertexAttrib4Nubv' %i", err);

	MACH_OVERRIDE(void, glVertexAttrib4Nuiv, (GLuint index, const GLuint *v), err)
	{
		logger.glVertexAttrib4Nuiv(index, v);

		glVertexAttrib4Nuiv_reenter(index, v);
	} END_MACH_OVERRIDE(glVertexAttrib4Nuiv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertexAttrib4Nuiv' %i", err);

	MACH_OVERRIDE(void, glVertexAttrib4Nusv, (GLuint index, const GLushort *v), err)
	{
		logger.glVertexAttrib4Nusv(index, v);

		glVertexAttrib4Nusv_reenter(index, v);
	} END_MACH_OVERRIDE(glVertexAttrib4Nusv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertexAttrib4Nusv' %i", err);

	MACH_OVERRIDE(void, glVertexAttrib4bv, (GLuint index, const GLbyte *v), err)
	{
		logger.glVertexAttrib4bv(index, v);

		glVertexAttrib4bv_reenter(index, v);
	} END_MACH_OVERRIDE(glVertexAttrib4bv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertexAttrib4bv' %i", err);

	MACH_OVERRIDE(void, glVertexAttrib4d, (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w), err)
	{
		logger.glVertexAttrib4d(index, x, y, z, w);

		glVertexAttrib4d_reenter(index, x, y, z, w);
	} END_MACH_OVERRIDE(glVertexAttrib4d);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertexAttrib4d' %i", err);

	MACH_OVERRIDE(void, glVertexAttrib4dv, (GLuint index, const GLdouble *v), err)
	{
		logger.glVertexAttrib4dv(index, v);

		glVertexAttrib4dv_reenter(index, v);
	} END_MACH_OVERRIDE(glVertexAttrib4dv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertexAttrib4dv' %i", err);

	MACH_OVERRIDE(void, glVertexAttrib4f, (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w), err)
	{
		logger.glVertexAttrib4f(index, x, y, z, w);

		glVertexAttrib4f_reenter(index, x, y, z, w);
	} END_MACH_OVERRIDE(glVertexAttrib4f);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertexAttrib4f' %i", err);

	MACH_OVERRIDE(void, glVertexAttrib4fv, (GLuint index, const GLfloat *v), err)
	{
		logger.glVertexAttrib4fv(index, v);

		glVertexAttrib4fv_reenter(index, v);
	} END_MACH_OVERRIDE(glVertexAttrib4fv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertexAttrib4fv' %i", err);

	MACH_OVERRIDE(void, glVertexAttrib4iv, (GLuint index, const GLint *v), err)
	{
		logger.glVertexAttrib4iv(index, v);

		glVertexAttrib4iv_reenter(index, v);
	} END_MACH_OVERRIDE(glVertexAttrib4iv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertexAttrib4iv' %i", err);

	MACH_OVERRIDE(void, glVertexAttrib4s, (GLuint index, GLshort x, GLshort y, GLshort z, GLshort w), err)
	{
		logger.glVertexAttrib4s(index, x, y, z, w);

		glVertexAttrib4s_reenter(index, x, y, z, w);
	} END_MACH_OVERRIDE(glVertexAttrib4s);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertexAttrib4s' %i", err);

	MACH_OVERRIDE(void, glVertexAttrib4sv, (GLuint index, const GLshort *v), err)
	{
		logger.glVertexAttrib4sv(index, v);

		glVertexAttrib4sv_reenter(index, v);
	} END_MACH_OVERRIDE(glVertexAttrib4sv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertexAttrib4sv' %i", err);

	MACH_OVERRIDE(void, glVertexAttrib4ubv, (GLuint index, const GLubyte *v), err)
	{
		logger.glVertexAttrib4ubv(index, v);

		glVertexAttrib4ubv_reenter(index, v);
	} END_MACH_OVERRIDE(glVertexAttrib4ubv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertexAttrib4ubv' %i", err);

	MACH_OVERRIDE(void, glVertexAttrib4uiv, (GLuint index, const GLuint *v), err)
	{
		logger.glVertexAttrib4uiv(index, v);

		glVertexAttrib4uiv_reenter(index, v);
	} END_MACH_OVERRIDE(glVertexAttrib4uiv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertexAttrib4uiv' %i", err);

	MACH_OVERRIDE(void, glVertexAttrib4usv, (GLuint index, const GLushort *v), err)
	{
		logger.glVertexAttrib4usv(index, v);

		glVertexAttrib4usv_reenter(index, v);
	} END_MACH_OVERRIDE(glVertexAttrib4usv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertexAttrib4usv' %i", err);

	MACH_OVERRIDE(void, glVertexAttribPointer, (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid *pointer), err)
	{
		logger.glVertexAttribPointer(index, size, type, normalized, stride, pointer);

		glVertexAttribPointer_reenter(index, size, type, normalized, stride, pointer);
	} END_MACH_OVERRIDE(glVertexAttribPointer);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glVertexAttribPointer' %i", err);

	MACH_OVERRIDE(void, glEnableVertexAttribArray, (GLuint index), err)
	{
		logger.glEnableVertexAttribArray(index);

		glEnableVertexAttribArray_reenter(index);
	} END_MACH_OVERRIDE(glEnableVertexAttribArray);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glEnableVertexAttribArray' %i", err);

	MACH_OVERRIDE(void, glDisableVertexAttribArray, (GLuint index), err)
	{
		logger.glDisableVertexAttribArray(index);

		glDisableVertexAttribArray_reenter(index);
	} END_MACH_OVERRIDE(glDisableVertexAttribArray);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glDisableVertexAttribArray' %i", err);

	MACH_OVERRIDE(void, glGetVertexAttribdv, (GLuint index, GLenum pname, GLdouble *params), err)
	{
		logger.glGetVertexAttribdv(index, pname, params);

		glGetVertexAttribdv_reenter(index, pname, params);
	} END_MACH_OVERRIDE(glGetVertexAttribdv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetVertexAttribdv' %i", err);

	MACH_OVERRIDE(void, glGetVertexAttribfv, (GLuint index, GLenum pname, GLfloat *params), err)
	{
		logger.glGetVertexAttribfv(index, pname, params);

		glGetVertexAttribfv_reenter(index, pname, params);
	} END_MACH_OVERRIDE(glGetVertexAttribfv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetVertexAttribfv' %i", err);

	MACH_OVERRIDE(void, glGetVertexAttribiv, (GLuint index, GLenum pname, GLint *params), err)
	{
		logger.glGetVertexAttribiv(index, pname, params);

		glGetVertexAttribiv_reenter(index, pname, params);
	} END_MACH_OVERRIDE(glGetVertexAttribiv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetVertexAttribiv' %i", err);

	MACH_OVERRIDE(void, glGetVertexAttribPointerv, (GLuint index, GLenum pname, GLvoid **pointer), err)
	{
		logger.glGetVertexAttribPointerv(index, pname, pointer);

		glGetVertexAttribPointerv_reenter(index, pname, pointer);
	} END_MACH_OVERRIDE(glGetVertexAttribPointerv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetVertexAttribPointerv' %i", err);

	MACH_OVERRIDE(void, glDeleteShader, (GLuint shader), err)
	{
		logger.glDeleteShader(shader);

		glDeleteShader_reenter(shader);
	} END_MACH_OVERRIDE(glDeleteShader);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glDeleteShader' %i", err);

	MACH_OVERRIDE(void, glDetachShader, (GLuint program, GLuint shader), err)
	{
		logger.glDetachShader(program, shader);

		glDetachShader_reenter(program, shader);
	} END_MACH_OVERRIDE(glDetachShader);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glDetachShader' %i", err);

	MACH_OVERRIDE(GLuint, glCreateShader, (GLenum type), err)
	{
		logger.glCreateShader(type);

		return glCreateShader_reenter(type);
	} END_MACH_OVERRIDE(glCreateShader);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glCreateShader' %i", err);

	MACH_OVERRIDE(void, glShaderSource, (GLuint shader, GLsizei count, const GLchar* const *string, const GLint *length), err)
	{
		logger.glShaderSource(shader, count, string, length);

		glShaderSource_reenter(shader, count, string, length);
	} END_MACH_OVERRIDE(glShaderSource);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glShaderSource' %i", err);

	MACH_OVERRIDE(void, glCompileShader, (GLuint shader), err)
	{
		logger.glCompileShader(shader);

		glCompileShader_reenter(shader);
	} END_MACH_OVERRIDE(glCompileShader);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glCompileShader' %i", err);

	MACH_OVERRIDE(GLuint, glCreateProgram, (void), err)
	{
		logger.glCreateProgram();

		return glCreateProgram_reenter();
	} END_MACH_OVERRIDE(glCreateProgram);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glCreateProgram' %i", err);

	MACH_OVERRIDE(void, glAttachShader, (GLuint program, GLuint shader), err)
	{
		logger.glAttachShader(program, shader);

		glAttachShader_reenter(program, shader);
	} END_MACH_OVERRIDE(glAttachShader);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glAttachShader' %i", err);

	MACH_OVERRIDE(void, glLinkProgram, (GLuint program), err)
	{
		logger.glLinkProgram(program);

		glLinkProgram_reenter(program);
	} END_MACH_OVERRIDE(glLinkProgram);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glLinkProgram' %i", err);

	MACH_OVERRIDE(void, glUseProgram, (GLuint program), err)
	{
		logger.glUseProgram(program);

		glUseProgram_reenter(program);
	} END_MACH_OVERRIDE(glUseProgram);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glUseProgram' %i", err);

	MACH_OVERRIDE(void, glDeleteProgram, (GLuint program), err)
	{
		logger.glDeleteProgram(program);

		glDeleteProgram_reenter(program);
	} END_MACH_OVERRIDE(glDeleteProgram);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glDeleteProgram' %i", err);

	MACH_OVERRIDE(void, glValidateProgram, (GLuint program), err)
	{
		logger.glValidateProgram(program);

		glValidateProgram_reenter(program);
	} END_MACH_OVERRIDE(glValidateProgram);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glValidateProgram' %i", err);

	MACH_OVERRIDE(void, glUniform1f, (GLint location, GLfloat v0), err)
	{
		logger.glUniform1f(location, v0);

		glUniform1f_reenter(location, v0);
	} END_MACH_OVERRIDE(glUniform1f);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glUniform1f' %i", err);

	MACH_OVERRIDE(void, glUniform2f, (GLint location, GLfloat v0, GLfloat v1), err)
	{
		logger.glUniform2f(location, v0, v1);

		glUniform2f_reenter(location, v0, v1);
	} END_MACH_OVERRIDE(glUniform2f);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glUniform2f' %i", err);

	MACH_OVERRIDE(void, glUniform3f, (GLint location, GLfloat v0, GLfloat v1, GLfloat v2), err)
	{
		logger.glUniform3f(location, v0, v1, v2);

		glUniform3f_reenter(location, v0, v1, v2);
	} END_MACH_OVERRIDE(glUniform3f);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glUniform3f' %i", err);

	MACH_OVERRIDE(void, glUniform4f, (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3), err)
	{
		logger.glUniform4f(location, v0, v1, v2, v3);

		glUniform4f_reenter(location, v0, v1, v2, v3);
	} END_MACH_OVERRIDE(glUniform4f);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glUniform4f' %i", err);

	MACH_OVERRIDE(void, glUniform1i, (GLint location, GLint v0), err)
	{
		logger.glUniform1i(location, v0);

		glUniform1i_reenter(location, v0);
	} END_MACH_OVERRIDE(glUniform1i);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glUniform1i' %i", err);

	MACH_OVERRIDE(void, glUniform2i, (GLint location, GLint v0, GLint v1), err)
	{
		logger.glUniform2i(location, v0, v1);

		glUniform2i_reenter(location, v0, v1);
	} END_MACH_OVERRIDE(glUniform2i);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glUniform2i' %i", err);

	MACH_OVERRIDE(void, glUniform3i, (GLint location, GLint v0, GLint v1, GLint v2), err)
	{
		logger.glUniform3i(location, v0, v1, v2);

		glUniform3i_reenter(location, v0, v1, v2);
	} END_MACH_OVERRIDE(glUniform3i);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glUniform3i' %i", err);

	MACH_OVERRIDE(void, glUniform4i, (GLint location, GLint v0, GLint v1, GLint v2, GLint v3), err)
	{
		logger.glUniform4i(location, v0, v1, v2, v3);

		glUniform4i_reenter(location, v0, v1, v2, v3);
	} END_MACH_OVERRIDE(glUniform4i);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glUniform4i' %i", err);

	MACH_OVERRIDE(void, glUniform1fv, (GLint location, GLsizei count, const GLfloat *value), err)
	{
		logger.glUniform1fv(location, count, value);

		glUniform1fv_reenter(location, count, value);
	} END_MACH_OVERRIDE(glUniform1fv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glUniform1fv' %i", err);

	MACH_OVERRIDE(void, glUniform2fv, (GLint location, GLsizei count, const GLfloat *value), err)
	{
		logger.glUniform2fv(location, count, value);

		glUniform2fv_reenter(location, count, value);
	} END_MACH_OVERRIDE(glUniform2fv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glUniform2fv' %i", err);

	MACH_OVERRIDE(void, glUniform3fv, (GLint location, GLsizei count, const GLfloat *value), err)
	{
		logger.glUniform3fv(location, count, value);

		glUniform3fv_reenter(location, count, value);
	} END_MACH_OVERRIDE(glUniform3fv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glUniform3fv' %i", err);

	MACH_OVERRIDE(void, glUniform4fv, (GLint location, GLsizei count, const GLfloat *value), err)
	{
		logger.glUniform4fv(location, count, value);

		glUniform4fv_reenter(location, count, value);
	} END_MACH_OVERRIDE(glUniform4fv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glUniform4fv' %i", err);

	MACH_OVERRIDE(void, glUniform1iv, (GLint location, GLsizei count, const GLint *value), err)
	{
		logger.glUniform1iv(location, count, value);

		glUniform1iv_reenter(location, count, value);
	} END_MACH_OVERRIDE(glUniform1iv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glUniform1iv' %i", err);

	MACH_OVERRIDE(void, glUniform2iv, (GLint location, GLsizei count, const GLint *value), err)
	{
		logger.glUniform2iv(location, count, value);

		glUniform2iv_reenter(location, count, value);
	} END_MACH_OVERRIDE(glUniform2iv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glUniform2iv' %i", err);

	MACH_OVERRIDE(void, glUniform3iv, (GLint location, GLsizei count, const GLint *value), err)
	{
		logger.glUniform3iv(location, count, value);

		glUniform3iv_reenter(location, count, value);
	} END_MACH_OVERRIDE(glUniform3iv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glUniform3iv' %i", err);

	MACH_OVERRIDE(void, glUniform4iv, (GLint location, GLsizei count, const GLint *value), err)
	{
		logger.glUniform4iv(location, count, value);

		glUniform4iv_reenter(location, count, value);
	} END_MACH_OVERRIDE(glUniform4iv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glUniform4iv' %i", err);

	MACH_OVERRIDE(void, glUniformMatrix2fv, (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value), err)
	{
		logger.glUniformMatrix2fv(location, count, transpose, value);

		glUniformMatrix2fv_reenter(location, count, transpose, value);
	} END_MACH_OVERRIDE(glUniformMatrix2fv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glUniformMatrix2fv' %i", err);

	MACH_OVERRIDE(void, glUniformMatrix3fv, (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value), err)
	{
		logger.glUniformMatrix3fv(location, count, transpose, value);

		glUniformMatrix3fv_reenter(location, count, transpose, value);
	} END_MACH_OVERRIDE(glUniformMatrix3fv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glUniformMatrix3fv' %i", err);

	MACH_OVERRIDE(void, glUniformMatrix4fv, (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value), err)
	{
		logger.glUniformMatrix4fv(location, count, transpose, value);

		glUniformMatrix4fv_reenter(location, count, transpose, value);
	} END_MACH_OVERRIDE(glUniformMatrix4fv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glUniformMatrix4fv' %i", err);

	MACH_OVERRIDE(GLboolean, glIsShader, (GLuint shader), err)
	{
		logger.glIsShader(shader);

		return glIsShader_reenter(shader);
	} END_MACH_OVERRIDE(glIsShader);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glIsShader' %i", err);

	MACH_OVERRIDE(GLboolean, glIsProgram, (GLuint program), err)
	{
		logger.glIsProgram(program);

		return glIsProgram_reenter(program);
	} END_MACH_OVERRIDE(glIsProgram);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glIsProgram' %i", err);

	MACH_OVERRIDE(void, glGetShaderiv, (GLuint shader, GLenum pname, GLint *params), err)
	{
		logger.glGetShaderiv(shader, pname, params);

		glGetShaderiv_reenter(shader, pname, params);
	} END_MACH_OVERRIDE(glGetShaderiv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetShaderiv' %i", err);

	MACH_OVERRIDE(void, glGetProgramiv, (GLuint program, GLenum pname, GLint *params), err)
	{
		logger.glGetProgramiv(program, pname, params);

		glGetProgramiv_reenter(program, pname, params);
	} END_MACH_OVERRIDE(glGetProgramiv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetProgramiv' %i", err);

	MACH_OVERRIDE(void, glGetAttachedShaders, (GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders), err)
	{
		logger.glGetAttachedShaders(program, maxCount, count, shaders);

		glGetAttachedShaders_reenter(program, maxCount, count, shaders);
	} END_MACH_OVERRIDE(glGetAttachedShaders);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetAttachedShaders' %i", err);

	MACH_OVERRIDE(void, glGetShaderInfoLog, (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog), err)
	{
		logger.glGetShaderInfoLog(shader, bufSize, length, infoLog);

		glGetShaderInfoLog_reenter(shader, bufSize, length, infoLog);
	} END_MACH_OVERRIDE(glGetShaderInfoLog);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetShaderInfoLog' %i", err);

	MACH_OVERRIDE(void, glGetProgramInfoLog, (GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog), err)
	{
		logger.glGetProgramInfoLog(program, bufSize, length, infoLog);

		glGetProgramInfoLog_reenter(program, bufSize, length, infoLog);
	} END_MACH_OVERRIDE(glGetProgramInfoLog);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetProgramInfoLog' %i", err);

	MACH_OVERRIDE(GLint, glGetUniformLocation, (GLuint program, const GLchar *name), err)
	{
		logger.glGetUniformLocation(program, name);

		return glGetUniformLocation_reenter(program, name);
	} END_MACH_OVERRIDE(glGetUniformLocation);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetUniformLocation' %i", err);

	MACH_OVERRIDE(void, glGetActiveUniform, (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name), err)
	{
		logger.glGetActiveUniform(program, index, bufSize, length, size, type, name);

		glGetActiveUniform_reenter(program, index, bufSize, length, size, type, name);
	} END_MACH_OVERRIDE(glGetActiveUniform);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetActiveUniform' %i", err);

	MACH_OVERRIDE(void, glGetUniformfv, (GLuint program, GLint location, GLfloat *params), err)
	{
		logger.glGetUniformfv(program, location, params);

		glGetUniformfv_reenter(program, location, params);
	} END_MACH_OVERRIDE(glGetUniformfv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetUniformfv' %i", err);

	MACH_OVERRIDE(void, glGetUniformiv, (GLuint program, GLint location, GLint *params), err)
	{
		logger.glGetUniformiv(program, location, params);

		glGetUniformiv_reenter(program, location, params);
	} END_MACH_OVERRIDE(glGetUniformiv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetUniformiv' %i", err);

	MACH_OVERRIDE(void, glGetShaderSource, (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source), err)
	{
		logger.glGetShaderSource(shader, bufSize, length, source);

		glGetShaderSource_reenter(shader, bufSize, length, source);
	} END_MACH_OVERRIDE(glGetShaderSource);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetShaderSource' %i", err);

	MACH_OVERRIDE(void, glBindAttribLocation, (GLuint program, GLuint index, const GLchar *name), err)
	{
		logger.glBindAttribLocation(program, index, name);

		glBindAttribLocation_reenter(program, index, name);
	} END_MACH_OVERRIDE(glBindAttribLocation);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glBindAttribLocation' %i", err);

	MACH_OVERRIDE(void, glGetActiveAttrib, (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name), err)
	{
		logger.glGetActiveAttrib(program, index, bufSize, length, size, type, name);

		glGetActiveAttrib_reenter(program, index, bufSize, length, size, type, name);
	} END_MACH_OVERRIDE(glGetActiveAttrib);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetActiveAttrib' %i", err);

	MACH_OVERRIDE(GLint, glGetAttribLocation, (GLuint program, const GLchar *name), err)
	{
		logger.glGetAttribLocation(program, name);

		return glGetAttribLocation_reenter(program, name);
	} END_MACH_OVERRIDE(glGetAttribLocation);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glGetAttribLocation' %i", err);

	MACH_OVERRIDE(void, glStencilFuncSeparate, (GLenum face, GLenum func, GLint ref, GLuint mask), err)
	{
		logger.glStencilFuncSeparate(face, func, ref, mask);

		glStencilFuncSeparate_reenter(face, func, ref, mask);
	} END_MACH_OVERRIDE(glStencilFuncSeparate);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glStencilFuncSeparate' %i", err);

	MACH_OVERRIDE(void, glStencilOpSeparate, (GLenum face, GLenum fail, GLenum zfail, GLenum zpass), err)
	{
		logger.glStencilOpSeparate(face, fail, zfail, zpass);

		glStencilOpSeparate_reenter(face, fail, zfail, zpass);
	} END_MACH_OVERRIDE(glStencilOpSeparate);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glStencilOpSeparate' %i", err);

	MACH_OVERRIDE(void, glStencilMaskSeparate, (GLenum face, GLuint mask), err)
	{
		logger.glStencilMaskSeparate(face, mask);

		glStencilMaskSeparate_reenter(face, mask);
	} END_MACH_OVERRIDE(glStencilMaskSeparate);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glStencilMaskSeparate' %i", err);

	MACH_OVERRIDE(void, glUniformMatrix2x3fv, (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value), err)
	{
		logger.glUniformMatrix2x3fv(location, count, transpose, value);

		glUniformMatrix2x3fv_reenter(location, count, transpose, value);
	} END_MACH_OVERRIDE(glUniformMatrix2x3fv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glUniformMatrix2x3fv' %i", err);

	MACH_OVERRIDE(void, glUniformMatrix3x2fv, (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value), err)
	{
		logger.glUniformMatrix3x2fv(location, count, transpose, value);

		glUniformMatrix3x2fv_reenter(location, count, transpose, value);
	} END_MACH_OVERRIDE(glUniformMatrix3x2fv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glUniformMatrix3x2fv' %i", err);

	MACH_OVERRIDE(void, glUniformMatrix2x4fv, (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value), err)
	{
		logger.glUniformMatrix2x4fv(location, count, transpose, value);

		glUniformMatrix2x4fv_reenter(location, count, transpose, value);
	} END_MACH_OVERRIDE(glUniformMatrix2x4fv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glUniformMatrix2x4fv' %i", err);

	MACH_OVERRIDE(void, glUniformMatrix4x2fv, (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value), err)
	{
		logger.glUniformMatrix4x2fv(location, count, transpose, value);

		glUniformMatrix4x2fv_reenter(location, count, transpose, value);
	} END_MACH_OVERRIDE(glUniformMatrix4x2fv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glUniformMatrix4x2fv' %i", err);

	MACH_OVERRIDE(void, glUniformMatrix3x4fv, (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value), err)
	{
		logger.glUniformMatrix3x4fv(location, count, transpose, value);

		glUniformMatrix3x4fv_reenter(location, count, transpose, value);
	} END_MACH_OVERRIDE(glUniformMatrix3x4fv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glUniformMatrix3x4fv' %i", err);

	MACH_OVERRIDE(void, glUniformMatrix4x3fv, (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value), err)
	{
		logger.glUniformMatrix4x3fv(location, count, transpose, value);

		glUniformMatrix4x3fv_reenter(location, count, transpose, value);
	} END_MACH_OVERRIDE(glUniformMatrix4x3fv);

	if (err)
		syslog(LOG_ERR, "OpenGLFileLogger: Error overriding OpenGL call 'glUniformMatrix4x3fv' %i", err);
	
	syslog(LOG_NOTICE, "OpenGLFileLogger: Done overriding OpenGL2 calls");

}
