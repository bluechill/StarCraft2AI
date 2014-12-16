//
//  OpenGLLogger.cpp
//  OpenGLFileLogger
//
//  Created by Alex Turner on 12/2/14.
//  Copyright (c) 2014 Alex Turner. All rights reserved.
//

#include "OpenGLLogger.h"

#include <syslog.h>

using namespace std;

OpenGLLogger::OpenGLLogger(std::string log_path)
{
	output_path = fopen(log_path.c_str(), "w+");
	
	if (!output_path)
	{
		syslog(LOG_ERR, "Failed to open %s", log_path.c_str());
		syslog(LOG_NOTICE, "Trying to open /output.txt");
		
		output_path = fopen("/output.txt", "w+");
		
		if (!output_path)
			syslog(LOG_ERR, "Failed to open /output.txt.  This will not log.");
	}
}

OpenGLLogger::~OpenGLLogger()
{
	fclose(output_path);
}

void OpenGLLogger::glAccum(GLenum op, GLfloat value)
{
	fprintf(output_path, "Called glAccum\n");
}

void OpenGLLogger::glAlphaFunc(GLenum func, GLclampf ref)
{
	fprintf(output_path, "Called glAlphaFunc\n");
}

GLboolean OpenGLLogger::glAreTexturesResident(GLsizei n, const GLuint *textures, GLboolean *residences)
{
	fprintf(output_path, "Called glAreTexturesResident\n");
	
	return false;
}

void OpenGLLogger::glArrayElement(GLint i)
{
	fprintf(output_path, "Called glArrayElement\n");
}

void OpenGLLogger::glBegin(GLenum mode)
{
	fprintf(output_path, "Called glBegin\n");
}

void OpenGLLogger::glBindTexture(GLenum target, GLuint texture)
{
	fprintf(output_path, "Called glBindTexture\n");
}

void OpenGLLogger::glBitmap(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte *bitmap)
{
	fprintf(output_path, "Called glBitmap\n");
}

void OpenGLLogger::glBlendColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)
{
	fprintf(output_path, "Called glBlendColor\n");
}

void OpenGLLogger::glBlendEquation(GLenum mode)
{
	fprintf(output_path, "Called glBlendEquation\n");
}

void OpenGLLogger::glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha)
{
	fprintf(output_path, "Called glBlendEquationSeparate\n");
}

void OpenGLLogger::glBlendFunc(GLenum sfactor, GLenum dfactor)
{
	fprintf(output_path, "Called glBlendFunc\n");
}

void OpenGLLogger::glCallList(GLuint list)
{
	fprintf(output_path, "Called glCallList\n");
}

void OpenGLLogger::glCallLists(GLsizei n, GLenum type, const GLvoid *lists)
{
	fprintf(output_path, "Called glCallLists\n");
}

void OpenGLLogger::glClear(GLbitfield mask)
{
	fprintf(output_path, "Called glClear\n");
}

void OpenGLLogger::glClearAccum(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
	fprintf(output_path, "Called glClearAccum\n");
}

void OpenGLLogger::glClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)
{
	fprintf(output_path, "Called glClearColor\n");
}

void OpenGLLogger::glClearDepth(GLclampd depth)
{
	fprintf(output_path, "Called glClearDepth\n");
}

void OpenGLLogger::glClearIndex(GLfloat c)
{
	fprintf(output_path, "Called glClearIndex\n");
}

void OpenGLLogger::glClearStencil(GLint s)
{
	fprintf(output_path, "Called glClearStencil\n");
}

void OpenGLLogger::glClipPlane(GLenum plane, const GLdouble *equation)
{
	fprintf(output_path, "Called glClipPlane\n");
}

void OpenGLLogger::glColor3b(GLbyte red, GLbyte green, GLbyte blue)
{
	fprintf(output_path, "Called glColor3b\n");
}

void OpenGLLogger::glColor3bv(const GLbyte *v)
{
	fprintf(output_path, "Called glColor3bv\n");
}

void OpenGLLogger::glColor3d(GLdouble red, GLdouble green, GLdouble blue)
{
	fprintf(output_path, "Called glColor3d\n");
}

void OpenGLLogger::glColor3dv(const GLdouble *v)
{
	fprintf(output_path, "Called glColor3dv\n");
}

void OpenGLLogger::glColor3f(GLfloat red, GLfloat green, GLfloat blue)
{
	fprintf(output_path, "Called glColor3f\n");
}

void OpenGLLogger::glColor3fv(const GLfloat *v)
{
	fprintf(output_path, "Called glColor3fv\n");
}

void OpenGLLogger::glColor3i(GLint red, GLint green, GLint blue)
{
	fprintf(output_path, "Called glColor3i\n");
}

void OpenGLLogger::glColor3iv(const GLint *v)
{
	fprintf(output_path, "Called glColor3iv\n");
}

void OpenGLLogger::glColor3s(GLshort red, GLshort green, GLshort blue)
{
	fprintf(output_path, "Called glColor3s\n");
}

void OpenGLLogger::glColor3sv(const GLshort *v)
{
	fprintf(output_path, "Called glColor3sv\n");
}

void OpenGLLogger::glColor3ub(GLubyte red, GLubyte green, GLubyte blue)
{
	fprintf(output_path, "Called glColor3ub\n");
}

void OpenGLLogger::glColor3ubv(const GLubyte *v)
{
	fprintf(output_path, "Called glColor3ubv\n");
}

void OpenGLLogger::glColor3ui(GLuint red, GLuint green, GLuint blue)
{
	fprintf(output_path, "Called glColor3ui\n");
}

void OpenGLLogger::glColor3uiv(const GLuint *v)
{
	fprintf(output_path, "Called glColor3uiv\n");
}

void OpenGLLogger::glColor3us(GLushort red, GLushort green, GLushort blue)
{
	fprintf(output_path, "Called glColor3us\n");
}

void OpenGLLogger::glColor3usv(const GLushort *v)
{
	fprintf(output_path, "Called glColor3usv\n");
}

void OpenGLLogger::glColor4b(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha)
{
	fprintf(output_path, "Called glColor4b\n");
}

void OpenGLLogger::glColor4bv(const GLbyte *v)
{
	fprintf(output_path, "Called glColor4bv\n");
}

void OpenGLLogger::glColor4d(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha)
{
	fprintf(output_path, "Called glColor4d\n");
}

void OpenGLLogger::glColor4dv(const GLdouble *v)
{
	fprintf(output_path, "Called glColor4dv\n");
}

void OpenGLLogger::glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
	fprintf(output_path, "Called glColor4f\n");
}

void OpenGLLogger::glColor4fv(const GLfloat *v)
{
	fprintf(output_path, "Called glColor4fv\n");
}

void OpenGLLogger::glColor4i(GLint red, GLint green, GLint blue, GLint alpha)
{
	fprintf(output_path, "Called glColor4i\n");
}

void OpenGLLogger::glColor4iv(const GLint *v)
{
	fprintf(output_path, "Called glColor4iv\n");
}

void OpenGLLogger::glColor4s(GLshort red, GLshort green, GLshort blue, GLshort alpha)
{
	fprintf(output_path, "Called glColor4s\n");
}

void OpenGLLogger::glColor4sv(const GLshort *v)
{
	fprintf(output_path, "Called glColor4sv\n");
}

void OpenGLLogger::glColor4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha)
{
	fprintf(output_path, "Called glColor4ub\n");
}

void OpenGLLogger::glColor4ubv(const GLubyte *v)
{
	fprintf(output_path, "Called glColor4ubv\n");
}

void OpenGLLogger::glColor4ui(GLuint red, GLuint green, GLuint blue, GLuint alpha)
{
	fprintf(output_path, "Called glColor4ui\n");
}

void OpenGLLogger::glColor4uiv(const GLuint *v)
{
	fprintf(output_path, "Called glColor4uiv\n");
}

void OpenGLLogger::glColor4us(GLushort red, GLushort green, GLushort blue, GLushort alpha)
{
	fprintf(output_path, "Called glColor4us\n");
}

void OpenGLLogger::glColor4usv(const GLushort *v)
{
	fprintf(output_path, "Called glColor4usv\n");
}

void OpenGLLogger::glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha)
{
	fprintf(output_path, "Called glColorMask\n");
}

void OpenGLLogger::glColorMaterial(GLenum face, GLenum mode)
{
	fprintf(output_path, "Called glColorMaterial\n");
}

void OpenGLLogger::glColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)
{
	fprintf(output_path, "Called glColorPointer\n");
}

void OpenGLLogger::glColorSubTable(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const GLvoid *data)
{
	fprintf(output_path, "Called glColorSubTable\n");
}

void OpenGLLogger::glColorTable(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *table)
{
	fprintf(output_path, "Called glColorTable\n");
}

void OpenGLLogger::glColorTableParameterfv(GLenum target, GLenum pname, const GLfloat *params)
{
	fprintf(output_path, "Called glColorTableParameterfv\n");
}

void OpenGLLogger::glColorTableParameteriv(GLenum target, GLenum pname, const GLint *params)
{
	fprintf(output_path, "Called glColorTableParameteriv\n");
}

void OpenGLLogger::glConvolutionFilter1D(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *image)
{
	fprintf(output_path, "Called glConvolutionFilter1D\n");
}

void OpenGLLogger::glConvolutionFilter2D(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *image)
{
	fprintf(output_path, "Called glConvolutionFilter2D\n");
}

void OpenGLLogger::glConvolutionParameterf(GLenum target, GLenum pname, GLfloat params)
{
	fprintf(output_path, "Called glConvolutionParameterf\n");
}

void OpenGLLogger::glConvolutionParameterfv(GLenum target, GLenum pname, const GLfloat *params)
{
	fprintf(output_path, "Called glConvolutionParameterfv\n");
}

void OpenGLLogger::glConvolutionParameteri(GLenum target, GLenum pname, GLint params)
{
	fprintf(output_path, "Called glConvolutionParameteri\n");
}

void OpenGLLogger::glConvolutionParameteriv(GLenum target, GLenum pname, const GLint *params)
{
	fprintf(output_path, "Called glConvolutionParameteriv\n");
}

void OpenGLLogger::glCopyColorSubTable(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width)
{
	fprintf(output_path, "Called glCopyColorSubTable\n");
}

void OpenGLLogger::glCopyColorTable(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width)
{
	fprintf(output_path, "Called glCopyColorTable\n");
}

void OpenGLLogger::glCopyConvolutionFilter1D(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width)
{
	fprintf(output_path, "Called glCopyConvolutionFilter1D\n");
}

void OpenGLLogger::glCopyConvolutionFilter2D(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height)
{
	fprintf(output_path, "Called glCopyConvolutionFilter2D\n");
}

void OpenGLLogger::glCopyPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type)
{
	fprintf(output_path, "Called glCopyPixels\n");
}

void OpenGLLogger::glCopyTexImage1D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border)
{
	fprintf(output_path, "Called glCopyTexImage1D\n");
}

void OpenGLLogger::glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border)
{
	fprintf(output_path, "Called glCopyTexImage2D\n");
}

void OpenGLLogger::glCopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width)
{
	fprintf(output_path, "Called glCopyTexSubImage1D\n");
}

void OpenGLLogger::glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height)
{
	fprintf(output_path, "Called glCopyTexSubImage2D\n");
}

void OpenGLLogger::glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height)
{
	fprintf(output_path, "Called glCopyTexSubImage3D\n");
}

void OpenGLLogger::glCullFace(GLenum mode)
{
	fprintf(output_path, "Called glCullFace\n");
}

void OpenGLLogger::glDeleteLists(GLuint list, GLsizei range)
{
	fprintf(output_path, "Called glDeleteLists\n");
}

void OpenGLLogger::glDeleteTextures(GLsizei n, const GLuint *textures)
{
	fprintf(output_path, "Called glDeleteTextures\n");
}

void OpenGLLogger::glDepthFunc(GLenum func)
{
	fprintf(output_path, "Called glDepthFunc\n");
}

void OpenGLLogger::glDepthMask(GLboolean flag)
{
	fprintf(output_path, "Called glDepthMask\n");
}

void OpenGLLogger::glDepthRange(GLclampd zNear, GLclampd zFar)
{
	fprintf(output_path, "Called glDepthRange\n");
}

void OpenGLLogger::glDisable(GLenum cap)
{
	fprintf(output_path, "Called glDisable\n");
}

void OpenGLLogger::glDisableClientState(GLenum array)
{
	fprintf(output_path, "Called glDisableClientState\n");
}

void OpenGLLogger::glDrawArrays(GLenum mode, GLint first, GLsizei count)
{
	fprintf(output_path, "Called glDrawArrays\n");
}

void OpenGLLogger::glDrawBuffer(GLenum mode)
{
	fprintf(output_path, "Called glDrawBuffer\n");
}

void OpenGLLogger::glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices)
{
	fprintf(output_path, "Called glDrawElements\n");
}

void OpenGLLogger::glDrawPixels(GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels)
{
	fprintf(output_path, "Called glDrawPixels\n");
}

void OpenGLLogger::glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices)
{
	fprintf(output_path, "Called glDrawRangeElements\n");
}

void OpenGLLogger::glEdgeFlag(GLboolean flag)
{
	fprintf(output_path, "Called glEdgeFlag\n");
}

void OpenGLLogger::glEdgeFlagPointer(GLsizei stride, const GLvoid *pointer)
{
	fprintf(output_path, "Called glEdgeFlagPointer\n");
}

void OpenGLLogger::glEdgeFlagv(const GLboolean *flag)
{
	fprintf(output_path, "Called glEdgeFlagv\n");
}

void OpenGLLogger::glEnable(GLenum cap)
{
	fprintf(output_path, "Called glEnable\n");
}

void OpenGLLogger::glEnableClientState(GLenum array)
{
	fprintf(output_path, "Called glEnableClientState\n");
}

void OpenGLLogger::glEnd(void)
{
	fprintf(output_path, "Called glEnd\n");
}

void OpenGLLogger::glEndList(void)
{
	fprintf(output_path, "Called glEndList\n");
}

void OpenGLLogger::glEvalCoord1d(GLdouble u)
{
	fprintf(output_path, "Called glEvalCoord1d\n");
}

void OpenGLLogger::glEvalCoord1dv(const GLdouble *u)
{
	fprintf(output_path, "Called glEvalCoord1dv\n");
}

void OpenGLLogger::glEvalCoord1f(GLfloat u)
{
	fprintf(output_path, "Called glEvalCoord1f\n");
}

void OpenGLLogger::glEvalCoord1fv(const GLfloat *u)
{
	fprintf(output_path, "Called glEvalCoord1fv\n");
}

void OpenGLLogger::glEvalCoord2d(GLdouble u, GLdouble v)
{
	fprintf(output_path, "Called glEvalCoord2d\n");
}

void OpenGLLogger::glEvalCoord2dv(const GLdouble *u)
{
	fprintf(output_path, "Called glEvalCoord2dv\n");
}

void OpenGLLogger::glEvalCoord2f(GLfloat u, GLfloat v)
{
	fprintf(output_path, "Called glEvalCoord2f\n");
}

void OpenGLLogger::glEvalCoord2fv(const GLfloat *u)
{
	fprintf(output_path, "Called glEvalCoord2fv\n");
}

void OpenGLLogger::glEvalMesh1(GLenum mode, GLint i1, GLint i2)
{
	fprintf(output_path, "Called glEvalMesh1\n");
}

void OpenGLLogger::glEvalMesh2(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2)
{
	fprintf(output_path, "Called glEvalMesh2\n");
}

void OpenGLLogger::glEvalPoint1(GLint i)
{
	fprintf(output_path, "Called glEvalPoint1\n");
}

void OpenGLLogger::glEvalPoint2(GLint i, GLint j)
{
	fprintf(output_path, "Called glEvalPoint2\n");
}

void OpenGLLogger::glFeedbackBuffer(GLsizei size, GLenum type, GLfloat *buffer)
{
	fprintf(output_path, "Called glFeedbackBuffer\n");
}

void OpenGLLogger::glFinish(void)
{
	fprintf(output_path, "Called glFinish\n");
}

void OpenGLLogger::glFlush(void)
{
	fprintf(output_path, "Called glFlush\n");
}

void OpenGLLogger::glFogf(GLenum pname, GLfloat param)
{
	fprintf(output_path, "Called glFogf\n");
}

void OpenGLLogger::glFogfv(GLenum pname, const GLfloat *params)
{
	fprintf(output_path, "Called glFogfv\n");
}

void OpenGLLogger::glFogi(GLenum pname, GLint param)
{
	fprintf(output_path, "Called glFogi\n");
}

void OpenGLLogger::glFogiv(GLenum pname, const GLint *params)
{
	fprintf(output_path, "Called glFogiv\n");
}

void OpenGLLogger::glFrontFace(GLenum mode)
{
	fprintf(output_path, "Called glFrontFace\n");
}

void OpenGLLogger::glFrustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar)
{
	fprintf(output_path, "Called glFrustum\n");
}

GLuint OpenGLLogger::glGenLists(GLsizei range)
{
	fprintf(output_path, "Called glGenLists\n");
	
	return 0;
}

void OpenGLLogger::glGenTextures(GLsizei n, GLuint *textures)
{
	fprintf(output_path, "Called glGenTextures\n");
}

void OpenGLLogger::glGetBooleanv(GLenum pname, GLboolean *params)
{
	fprintf(output_path, "Called glGetBooleanv\n");
}

void OpenGLLogger::glGetClipPlane(GLenum plane, GLdouble *equation)
{
	fprintf(output_path, "Called glGetClipPlane\n");
}

void OpenGLLogger::glGetColorTable(GLenum target, GLenum format, GLenum type, GLvoid *table)
{
	fprintf(output_path, "Called glGetColorTable\n");
}

void OpenGLLogger::glGetColorTableParameterfv(GLenum target, GLenum pname, GLfloat *params)
{
	fprintf(output_path, "Called glGetColorTableParameterfv\n");
}

void OpenGLLogger::glGetColorTableParameteriv(GLenum target, GLenum pname, GLint *params)
{
	fprintf(output_path, "Called glGetColorTableParameteriv\n");
}

void OpenGLLogger::glGetConvolutionFilter(GLenum target, GLenum format, GLenum type, GLvoid *image)
{
	fprintf(output_path, "Called glGetConvolutionFilter\n");
}

void OpenGLLogger::glGetConvolutionParameterfv(GLenum target, GLenum pname, GLfloat *params)
{
	fprintf(output_path, "Called glGetConvolutionParameterfv\n");
}

void OpenGLLogger::glGetConvolutionParameteriv(GLenum target, GLenum pname, GLint *params)
{
	fprintf(output_path, "Called glGetConvolutionParameteriv\n");
}

void OpenGLLogger::glGetDoublev(GLenum pname, GLdouble *params)
{
	fprintf(output_path, "Called glGetDoublev\n");
}

GLenum OpenGLLogger::glGetError(void)
{
	fprintf(output_path, "Called glGetError\n");
	
	return 0;
}

void OpenGLLogger::glGetFloatv(GLenum pname, GLfloat *params)
{
	fprintf(output_path, "Called glGetFloatv\n");
}

void OpenGLLogger::glGetHistogram(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid *values)
{
	fprintf(output_path, "Called glGetHistogram\n");
}

void OpenGLLogger::glGetHistogramParameterfv(GLenum target, GLenum pname, GLfloat *params)
{
	fprintf(output_path, "Called glGetHistogramParameterfv\n");
}

void OpenGLLogger::glGetHistogramParameteriv(GLenum target, GLenum pname, GLint *params)
{
	fprintf(output_path, "Called glGetHistogramParameteriv\n");
}

void OpenGLLogger::glGetIntegerv(GLenum pname, GLint *params)
{
	fprintf(output_path, "Called glGetIntegerv\n");
}

void OpenGLLogger::glGetLightfv(GLenum light, GLenum pname, GLfloat *params)
{
	fprintf(output_path, "Called glGetLightfv\n");
}

void OpenGLLogger::glGetLightiv(GLenum light, GLenum pname, GLint *params)
{
	fprintf(output_path, "Called glGetLightiv\n");
}

void OpenGLLogger::glGetMapdv(GLenum target, GLenum query, GLdouble *v)
{
	fprintf(output_path, "Called glGetMapdv\n");
}

void OpenGLLogger::glGetMapfv(GLenum target, GLenum query, GLfloat *v)
{
	fprintf(output_path, "Called glGetMapfv\n");
}

void OpenGLLogger::glGetMapiv(GLenum target, GLenum query, GLint *v)
{
	fprintf(output_path, "Called glGetMapiv\n");
}

void OpenGLLogger::glGetMaterialfv(GLenum face, GLenum pname, GLfloat *params)
{
	fprintf(output_path, "Called glGetMaterialfv\n");
}

void OpenGLLogger::glGetMaterialiv(GLenum face, GLenum pname, GLint *params)
{
	fprintf(output_path, "Called glGetMaterialiv\n");
}

void OpenGLLogger::glGetMinmax(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid *values)
{
	fprintf(output_path, "Called glGetMinmax\n");
}

void OpenGLLogger::glGetMinmaxParameterfv(GLenum target, GLenum pname, GLfloat *params)
{
	fprintf(output_path, "Called glGetMinmaxParameterfv\n");
}

void OpenGLLogger::glGetMinmaxParameteriv(GLenum target, GLenum pname, GLint *params)
{
	fprintf(output_path, "Called glGetMinmaxParameteriv\n");
}

void OpenGLLogger::glGetPixelMapfv(GLenum map, GLfloat *values)
{
	fprintf(output_path, "Called glGetPixelMapfv\n");
}

void OpenGLLogger::glGetPixelMapuiv(GLenum map, GLuint *values)
{
	fprintf(output_path, "Called glGetPixelMapuiv\n");
}

void OpenGLLogger::glGetPixelMapusv(GLenum map, GLushort *values)
{
	fprintf(output_path, "Called glGetPixelMapusv\n");
}

void OpenGLLogger::glGetPointerv(GLenum pname, GLvoid **params)
{
	fprintf(output_path, "Called glGetPointerv\n");
}

void OpenGLLogger::glGetPolygonStipple(GLubyte *mask)
{
	fprintf(output_path, "Called glGetPolygonStipple\n");
}

void OpenGLLogger::glGetSeparableFilter(GLenum target, GLenum format, GLenum type, GLvoid *row, GLvoid *column, GLvoid *span)
{
	fprintf(output_path, "Called glGetSeparableFilter\n");
}

const GLubyte* OpenGLLogger::glGetString (GLenum name)
{
	fprintf(output_path, "Called GLubyte\n");
	
	return nullptr;
}

void OpenGLLogger::glGetTexEnvfv(GLenum target, GLenum pname, GLfloat *params)
{
	fprintf(output_path, "Called glGetTexEnvfv\n");
}

void OpenGLLogger::glGetTexEnviv(GLenum target, GLenum pname, GLint *params)
{
	fprintf(output_path, "Called glGetTexEnviv\n");
}

void OpenGLLogger::glGetTexGendv(GLenum coord, GLenum pname, GLdouble *params)
{
	fprintf(output_path, "Called glGetTexGendv\n");
}

void OpenGLLogger::glGetTexGenfv(GLenum coord, GLenum pname, GLfloat *params)
{
	fprintf(output_path, "Called glGetTexGenfv\n");
}

void OpenGLLogger::glGetTexGeniv(GLenum coord, GLenum pname, GLint *params)
{
	fprintf(output_path, "Called glGetTexGeniv\n");
}

void OpenGLLogger::glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels)
{
	fprintf(output_path, "Called glGetTexImage\n");
}

void OpenGLLogger::glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat *params)
{
	fprintf(output_path, "Called glGetTexLevelParameterfv\n");
}

void OpenGLLogger::glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint *params)
{
	fprintf(output_path, "Called glGetTexLevelParameteriv\n");
}

void OpenGLLogger::glGetTexParameterfv(GLenum target, GLenum pname, GLfloat *params)
{
	fprintf(output_path, "Called glGetTexParameterfv\n");
}

void OpenGLLogger::glGetTexParameteriv(GLenum target, GLenum pname, GLint *params)
{
	fprintf(output_path, "Called glGetTexParameteriv\n");
}

void OpenGLLogger::glHint(GLenum target, GLenum mode)
{
	fprintf(output_path, "Called glHint\n");
}

void OpenGLLogger::glHistogram(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink)
{
	fprintf(output_path, "Called glHistogram\n");
}

void OpenGLLogger::glIndexMask(GLuint mask)
{
	fprintf(output_path, "Called glIndexMask\n");
}

void OpenGLLogger::glIndexPointer(GLenum type, GLsizei stride, const GLvoid *pointer)
{
	fprintf(output_path, "Called glIndexPointer\n");
}

void OpenGLLogger::glIndexd(GLdouble c)
{
	fprintf(output_path, "Called glIndexd\n");
}

void OpenGLLogger::glIndexdv(const GLdouble *c)
{
	fprintf(output_path, "Called glIndexdv\n");
}

void OpenGLLogger::glIndexf(GLfloat c)
{
	fprintf(output_path, "Called glIndexf\n");
}

void OpenGLLogger::glIndexfv(const GLfloat *c)
{
	fprintf(output_path, "Called glIndexfv\n");
}

void OpenGLLogger::glIndexi(GLint c)
{
	fprintf(output_path, "Called glIndexi\n");
}

void OpenGLLogger::glIndexiv(const GLint *c)
{
	fprintf(output_path, "Called glIndexiv\n");
}

void OpenGLLogger::glIndexs(GLshort c)
{
	fprintf(output_path, "Called glIndexs\n");
}

void OpenGLLogger::glIndexsv(const GLshort *c)
{
	fprintf(output_path, "Called glIndexsv\n");
}

void OpenGLLogger::glIndexub(GLubyte c)
{
	fprintf(output_path, "Called glIndexub\n");
}

void OpenGLLogger::glIndexubv(const GLubyte *c)
{
	fprintf(output_path, "Called glIndexubv\n");
}

void OpenGLLogger::glInitNames(void)
{
	fprintf(output_path, "Called glInitNames\n");
}

void OpenGLLogger::glInterleavedArrays(GLenum format, GLsizei stride, const GLvoid *pointer)
{
	fprintf(output_path, "Called glInterleavedArrays\n");
}

GLboolean OpenGLLogger::glIsEnabled(GLenum cap)
{
	fprintf(output_path, "Called glIsEnabled\n");
	
	return false;
}

GLboolean OpenGLLogger::glIsList(GLuint list)
{
	fprintf(output_path, "Called glIsList\n");
	
	return false;
}

GLboolean OpenGLLogger::glIsTexture(GLuint texture)
{
	fprintf(output_path, "Called glIsTexture\n");
	
	return false;
}

void OpenGLLogger::glLightModelf(GLenum pname, GLfloat param)
{
	fprintf(output_path, "Called glLightModelf\n");
}

void OpenGLLogger::glLightModelfv(GLenum pname, const GLfloat *params)
{
	fprintf(output_path, "Called glLightModelfv\n");
}

void OpenGLLogger::glLightModeli(GLenum pname, GLint param)
{
	fprintf(output_path, "Called glLightModeli\n");
}

void OpenGLLogger::glLightModeliv(GLenum pname, const GLint *params)
{
	fprintf(output_path, "Called glLightModeliv\n");
}

void OpenGLLogger::glLightf(GLenum light, GLenum pname, GLfloat param)
{
	fprintf(output_path, "Called glLightf\n");
}

void OpenGLLogger::glLightfv(GLenum light, GLenum pname, const GLfloat *params)
{
	fprintf(output_path, "Called glLightfv\n");
}

void OpenGLLogger::glLighti(GLenum light, GLenum pname, GLint param)
{
	fprintf(output_path, "Called glLighti\n");
}

void OpenGLLogger::glLightiv(GLenum light, GLenum pname, const GLint *params)
{
	fprintf(output_path, "Called glLightiv\n");
}

void OpenGLLogger::glLineStipple(GLint factor, GLushort pattern)
{
	fprintf(output_path, "Called glLineStipple\n");
}

void OpenGLLogger::glLineWidth(GLfloat width)
{
	fprintf(output_path, "Called glLineWidth\n");
}

void OpenGLLogger::glListBase(GLuint base)
{
	fprintf(output_path, "Called glListBase\n");
}

void OpenGLLogger::glLoadIdentity(void)
{
	fprintf(output_path, "Called glLoadIdentity\n");
}

void OpenGLLogger::glLoadMatrixd(const GLdouble *m)
{
	fprintf(output_path, "Called glLoadMatrixd\n");
}

void OpenGLLogger::glLoadMatrixf(const GLfloat *m)
{
	fprintf(output_path, "Called glLoadMatrixf\n");
}

void OpenGLLogger::glLoadName(GLuint name)
{
	fprintf(output_path, "Called glLoadName\n");
}

void OpenGLLogger::glLogicOp(GLenum opcode)
{
	fprintf(output_path, "Called glLogicOp\n");
}

void OpenGLLogger::glMap1d(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points)
{
	fprintf(output_path, "Called glMap1d\n");
}

void OpenGLLogger::glMap1f(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points)
{
	fprintf(output_path, "Called glMap1f\n");
}

void OpenGLLogger::glMap2d(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points)
{
	fprintf(output_path, "Called glMap2d\n");
}

void OpenGLLogger::glMap2f(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points)
{
	fprintf(output_path, "Called glMap2f\n");
}

void OpenGLLogger::glMapGrid1d(GLint un, GLdouble u1, GLdouble u2)
{
	fprintf(output_path, "Called glMapGrid1d\n");
}

void OpenGLLogger::glMapGrid1f(GLint un, GLfloat u1, GLfloat u2)
{
	fprintf(output_path, "Called glMapGrid1f\n");
}

void OpenGLLogger::glMapGrid2d(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2)
{
	fprintf(output_path, "Called glMapGrid2d\n");
}

void OpenGLLogger::glMapGrid2f(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2)
{
	fprintf(output_path, "Called glMapGrid2f\n");
}

void OpenGLLogger::glMaterialf(GLenum face, GLenum pname, GLfloat param)
{
	fprintf(output_path, "Called glMaterialf\n");
}

void OpenGLLogger::glMaterialfv(GLenum face, GLenum pname, const GLfloat *params)
{
	fprintf(output_path, "Called glMaterialfv\n");
}

void OpenGLLogger::glMateriali(GLenum face, GLenum pname, GLint param)
{
	fprintf(output_path, "Called glMateriali\n");
}

void OpenGLLogger::glMaterialiv(GLenum face, GLenum pname, const GLint *params)
{
	fprintf(output_path, "Called glMaterialiv\n");
}

void OpenGLLogger::glMatrixMode(GLenum mode)
{
	fprintf(output_path, "Called glMatrixMode\n");
}

void OpenGLLogger::glMinmax(GLenum target, GLenum internalformat, GLboolean sink)
{
	fprintf(output_path, "Called glMinmax\n");
}

void OpenGLLogger::glMultMatrixd(const GLdouble *m)
{
	fprintf(output_path, "Called glMultMatrixd\n");
}

void OpenGLLogger::glMultMatrixf(const GLfloat *m)
{
	fprintf(output_path, "Called glMultMatrixf\n");
}

void OpenGLLogger::glNewList(GLuint list, GLenum mode)
{
	fprintf(output_path, "Called glNewList\n");
}

void OpenGLLogger::glNormal3b(GLbyte nx, GLbyte ny, GLbyte nz)
{
	fprintf(output_path, "Called glNormal3b\n");
}

void OpenGLLogger::glNormal3bv(const GLbyte *v)
{
	fprintf(output_path, "Called glNormal3bv\n");
}

void OpenGLLogger::glNormal3d(GLdouble nx, GLdouble ny, GLdouble nz)
{
	fprintf(output_path, "Called glNormal3d\n");
}

void OpenGLLogger::glNormal3dv(const GLdouble *v)
{
	fprintf(output_path, "Called glNormal3dv\n");
}

void OpenGLLogger::glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz)
{
	fprintf(output_path, "Called glNormal3f\n");
}

void OpenGLLogger::glNormal3fv(const GLfloat *v)
{
	fprintf(output_path, "Called glNormal3fv\n");
}

void OpenGLLogger::glNormal3i(GLint nx, GLint ny, GLint nz)
{
	fprintf(output_path, "Called glNormal3i\n");
}

void OpenGLLogger::glNormal3iv(const GLint *v)
{
	fprintf(output_path, "Called glNormal3iv\n");
}

void OpenGLLogger::glNormal3s(GLshort nx, GLshort ny, GLshort nz)
{
	fprintf(output_path, "Called glNormal3s\n");
}

void OpenGLLogger::glNormal3sv(const GLshort *v)
{
	fprintf(output_path, "Called glNormal3sv\n");
}

void OpenGLLogger::glNormalPointer(GLenum type, GLsizei stride, const GLvoid *pointer)
{
	fprintf(output_path, "Called glNormalPointer\n");
}

void OpenGLLogger::glOrtho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar)
{
	fprintf(output_path, "Called glOrtho\n");
}

void OpenGLLogger::glPassThrough(GLfloat token)
{
	fprintf(output_path, "Called glPassThrough\n");
}

void OpenGLLogger::glPixelMapfv(GLenum map, GLint mapsize, const GLfloat *values)
{
	fprintf(output_path, "Called glPixelMapfv\n");
}

void OpenGLLogger::glPixelMapuiv(GLenum map, GLint mapsize, const GLuint *values)
{
	fprintf(output_path, "Called glPixelMapuiv\n");
}

void OpenGLLogger::glPixelMapusv(GLenum map, GLint mapsize, const GLushort *values)
{
	fprintf(output_path, "Called glPixelMapusv\n");
}

void OpenGLLogger::glPixelStoref(GLenum pname, GLfloat param)
{
	fprintf(output_path, "Called glPixelStoref\n");
}

void OpenGLLogger::glPixelStorei(GLenum pname, GLint param)
{
	fprintf(output_path, "Called glPixelStorei\n");
}

void OpenGLLogger::glPixelTransferf(GLenum pname, GLfloat param)
{
	fprintf(output_path, "Called glPixelTransferf\n");
}

void OpenGLLogger::glPixelTransferi(GLenum pname, GLint param)
{
	fprintf(output_path, "Called glPixelTransferi\n");
}

void OpenGLLogger::glPixelZoom(GLfloat xfactor, GLfloat yfactor)
{
	fprintf(output_path, "Called glPixelZoom\n");
}

void OpenGLLogger::glPointSize(GLfloat size)
{
	fprintf(output_path, "Called glPointSize\n");
}

void OpenGLLogger::glPolygonMode(GLenum face, GLenum mode)
{
	fprintf(output_path, "Called glPolygonMode\n");
}

void OpenGLLogger::glPolygonOffset(GLfloat factor, GLfloat units)
{
	fprintf(output_path, "Called glPolygonOffset\n");
}

void OpenGLLogger::glPolygonStipple(const GLubyte *mask)
{
	fprintf(output_path, "Called glPolygonStipple\n");
}

void OpenGLLogger::glPopAttrib(void)
{
	fprintf(output_path, "Called glPopAttrib\n");
}

void OpenGLLogger::glPopClientAttrib(void)
{
	fprintf(output_path, "Called glPopClientAttrib\n");
}

void OpenGLLogger::glPopMatrix(void)
{
	fprintf(output_path, "Called glPopMatrix\n");
}

void OpenGLLogger::glPopName(void)
{
	fprintf(output_path, "Called glPopName\n");
}

void OpenGLLogger::glPrioritizeTextures(GLsizei n, const GLuint *textures, const GLclampf *priorities)
{
	fprintf(output_path, "Called glPrioritizeTextures\n");
}

void OpenGLLogger::glPushAttrib(GLbitfield mask)
{
	fprintf(output_path, "Called glPushAttrib\n");
}

void OpenGLLogger::glPushClientAttrib(GLbitfield mask)
{
	fprintf(output_path, "Called glPushClientAttrib\n");
}

void OpenGLLogger::glPushMatrix(void)
{
	fprintf(output_path, "Called glPushMatrix\n");
}

void OpenGLLogger::glPushName(GLuint name)
{
	fprintf(output_path, "Called glPushName\n");
}

void OpenGLLogger::glRasterPos2d(GLdouble x, GLdouble y)
{
	fprintf(output_path, "Called glRasterPos2d\n");
}

void OpenGLLogger::glRasterPos2dv(const GLdouble *v)
{
	fprintf(output_path, "Called glRasterPos2dv\n");
}

void OpenGLLogger::glRasterPos2f(GLfloat x, GLfloat y)
{
	fprintf(output_path, "Called glRasterPos2f\n");
}

void OpenGLLogger::glRasterPos2fv(const GLfloat *v)
{
	fprintf(output_path, "Called glRasterPos2fv\n");
}

void OpenGLLogger::glRasterPos2i(GLint x, GLint y)
{
	fprintf(output_path, "Called glRasterPos2i\n");
}

void OpenGLLogger::glRasterPos2iv(const GLint *v)
{
	fprintf(output_path, "Called glRasterPos2iv\n");
}

void OpenGLLogger::glRasterPos2s(GLshort x, GLshort y)
{
	fprintf(output_path, "Called glRasterPos2s\n");
}

void OpenGLLogger::glRasterPos2sv(const GLshort *v)
{
	fprintf(output_path, "Called glRasterPos2sv\n");
}

void OpenGLLogger::glRasterPos3d(GLdouble x, GLdouble y, GLdouble z)
{
	fprintf(output_path, "Called glRasterPos3d\n");
}

void OpenGLLogger::glRasterPos3dv(const GLdouble *v)
{
	fprintf(output_path, "Called glRasterPos3dv\n");
}

void OpenGLLogger::glRasterPos3f(GLfloat x, GLfloat y, GLfloat z)
{
	fprintf(output_path, "Called glRasterPos3f\n");
}

void OpenGLLogger::glRasterPos3fv(const GLfloat *v)
{
	fprintf(output_path, "Called glRasterPos3fv\n");
}

void OpenGLLogger::glRasterPos3i(GLint x, GLint y, GLint z)
{
	fprintf(output_path, "Called glRasterPos3i\n");
}

void OpenGLLogger::glRasterPos3iv(const GLint *v)
{
	fprintf(output_path, "Called glRasterPos3iv\n");
}

void OpenGLLogger::glRasterPos3s(GLshort x, GLshort y, GLshort z)
{
	fprintf(output_path, "Called glRasterPos3s\n");
}

void OpenGLLogger::glRasterPos3sv(const GLshort *v)
{
	fprintf(output_path, "Called glRasterPos3sv\n");
}

void OpenGLLogger::glRasterPos4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w)
{
	fprintf(output_path, "Called glRasterPos4d\n");
}

void OpenGLLogger::glRasterPos4dv(const GLdouble *v)
{
	fprintf(output_path, "Called glRasterPos4dv\n");
}

void OpenGLLogger::glRasterPos4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
	fprintf(output_path, "Called glRasterPos4f\n");
}

void OpenGLLogger::glRasterPos4fv(const GLfloat *v)
{
	fprintf(output_path, "Called glRasterPos4fv\n");
}

void OpenGLLogger::glRasterPos4i(GLint x, GLint y, GLint z, GLint w)
{
	fprintf(output_path, "Called glRasterPos4i\n");
}

void OpenGLLogger::glRasterPos4iv(const GLint *v)
{
	fprintf(output_path, "Called glRasterPos4iv\n");
}

void OpenGLLogger::glRasterPos4s(GLshort x, GLshort y, GLshort z, GLshort w)
{
	fprintf(output_path, "Called glRasterPos4s\n");
}

void OpenGLLogger::glRasterPos4sv(const GLshort *v)
{
	fprintf(output_path, "Called glRasterPos4sv\n");
}

void OpenGLLogger::glReadBuffer(GLenum mode)
{
	fprintf(output_path, "Called glReadBuffer\n");
}

void OpenGLLogger::glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels)
{
	fprintf(output_path, "Called glReadPixels\n");
}

void OpenGLLogger::glRectd(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2)
{
	fprintf(output_path, "Called glRectd\n");
}

void OpenGLLogger::glRectdv(const GLdouble *v1, const GLdouble *v2)
{
	fprintf(output_path, "Called glRectdv\n");
}

void OpenGLLogger::glRectf(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2)
{
	fprintf(output_path, "Called glRectf\n");
}

void OpenGLLogger::glRectfv(const GLfloat *v1, const GLfloat *v2)
{
	fprintf(output_path, "Called glRectfv\n");
}

void OpenGLLogger::glRecti(GLint x1, GLint y1, GLint x2, GLint y2)
{
	fprintf(output_path, "Called glRecti\n");
}

void OpenGLLogger::glRectiv(const GLint *v1, const GLint *v2)
{
	fprintf(output_path, "Called glRectiv\n");
}

void OpenGLLogger::glRects(GLshort x1, GLshort y1, GLshort x2, GLshort y2)
{
	fprintf(output_path, "Called glRects\n");
}

void OpenGLLogger::glRectsv(const GLshort *v1, const GLshort *v2)
{
	fprintf(output_path, "Called glRectsv\n");
}

GLint OpenGLLogger::glRenderMode(GLenum mode)
{
	fprintf(output_path, "Called glRenderMode\n");
	
	return 0;
}

void OpenGLLogger::glResetHistogram(GLenum target)
{
	fprintf(output_path, "Called glResetHistogram\n");
}

void OpenGLLogger::glResetMinmax(GLenum target)
{
	fprintf(output_path, "Called glResetMinmax\n");
}

void OpenGLLogger::glRotated(GLdouble angle, GLdouble x, GLdouble y, GLdouble z)
{
	fprintf(output_path, "Called glRotated\n");
}

void OpenGLLogger::glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z)
{
	fprintf(output_path, "Called glRotatef\n");
}

void OpenGLLogger::glScaled(GLdouble x, GLdouble y, GLdouble z)
{
	fprintf(output_path, "Called glScaled\n");
}

void OpenGLLogger::glScalef(GLfloat x, GLfloat y, GLfloat z)
{
	fprintf(output_path, "Called glScalef\n");
}

void OpenGLLogger::glScissor(GLint x, GLint y, GLsizei width, GLsizei height)
{
	fprintf(output_path, "Called glScissor\n");
}

void OpenGLLogger::glSelectBuffer(GLsizei size, GLuint *buffer)
{
	fprintf(output_path, "Called glSelectBuffer\n");
}

void OpenGLLogger::glSeparableFilter2D(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *row, const GLvoid *column)
{
	fprintf(output_path, "Called glSeparableFilter2D\n");
}

void OpenGLLogger::glShadeModel(GLenum mode)
{
	fprintf(output_path, "Called glShadeModel\n");
}

void OpenGLLogger::glStencilFunc(GLenum func, GLint ref, GLuint mask)
{
	fprintf(output_path, "Called glStencilFunc\n");
}

void OpenGLLogger::glStencilMask(GLuint mask)
{
	fprintf(output_path, "Called glStencilMask\n");
}

void OpenGLLogger::glStencilOp(GLenum fail, GLenum zfail, GLenum zpass)
{
	fprintf(output_path, "Called glStencilOp\n");
}

void OpenGLLogger::glTexCoord1d(GLdouble s)
{
	fprintf(output_path, "Called glTexCoord1d\n");
}

void OpenGLLogger::glTexCoord1dv(const GLdouble *v)
{
	fprintf(output_path, "Called glTexCoord1dv\n");
}

void OpenGLLogger::glTexCoord1f(GLfloat s)
{
	fprintf(output_path, "Called glTexCoord1f\n");
}

void OpenGLLogger::glTexCoord1fv(const GLfloat *v)
{
	fprintf(output_path, "Called glTexCoord1fv\n");
}

void OpenGLLogger::glTexCoord1i(GLint s)
{
	fprintf(output_path, "Called glTexCoord1i\n");
}

void OpenGLLogger::glTexCoord1iv(const GLint *v)
{
	fprintf(output_path, "Called glTexCoord1iv\n");
}

void OpenGLLogger::glTexCoord1s(GLshort s)
{
	fprintf(output_path, "Called glTexCoord1s\n");
}

void OpenGLLogger::glTexCoord1sv(const GLshort *v)
{
	fprintf(output_path, "Called glTexCoord1sv\n");
}

void OpenGLLogger::glTexCoord2d(GLdouble s, GLdouble t)
{
	fprintf(output_path, "Called glTexCoord2d\n");
}

void OpenGLLogger::glTexCoord2dv(const GLdouble *v)
{
	fprintf(output_path, "Called glTexCoord2dv\n");
}

void OpenGLLogger::glTexCoord2f(GLfloat s, GLfloat t)
{
	fprintf(output_path, "Called glTexCoord2f\n");
}

void OpenGLLogger::glTexCoord2fv(const GLfloat *v)
{
	fprintf(output_path, "Called glTexCoord2fv\n");
}

void OpenGLLogger::glTexCoord2i(GLint s, GLint t)
{
	fprintf(output_path, "Called glTexCoord2i\n");
}

void OpenGLLogger::glTexCoord2iv(const GLint *v)
{
	fprintf(output_path, "Called glTexCoord2iv\n");
}

void OpenGLLogger::glTexCoord2s(GLshort s, GLshort t)
{
	fprintf(output_path, "Called glTexCoord2s\n");
}

void OpenGLLogger::glTexCoord2sv(const GLshort *v)
{
	fprintf(output_path, "Called glTexCoord2sv\n");
}

void OpenGLLogger::glTexCoord3d(GLdouble s, GLdouble t, GLdouble r)
{
	fprintf(output_path, "Called glTexCoord3d\n");
}

void OpenGLLogger::glTexCoord3dv(const GLdouble *v)
{
	fprintf(output_path, "Called glTexCoord3dv\n");
}

void OpenGLLogger::glTexCoord3f(GLfloat s, GLfloat t, GLfloat r)
{
	fprintf(output_path, "Called glTexCoord3f\n");
}

void OpenGLLogger::glTexCoord3fv(const GLfloat *v)
{
	fprintf(output_path, "Called glTexCoord3fv\n");
}

void OpenGLLogger::glTexCoord3i(GLint s, GLint t, GLint r)
{
	fprintf(output_path, "Called glTexCoord3i\n");
}

void OpenGLLogger::glTexCoord3iv(const GLint *v)
{
	fprintf(output_path, "Called glTexCoord3iv\n");
}

void OpenGLLogger::glTexCoord3s(GLshort s, GLshort t, GLshort r)
{
	fprintf(output_path, "Called glTexCoord3s\n");
}

void OpenGLLogger::glTexCoord3sv(const GLshort *v)
{
	fprintf(output_path, "Called glTexCoord3sv\n");
}

void OpenGLLogger::glTexCoord4d(GLdouble s, GLdouble t, GLdouble r, GLdouble q)
{
	fprintf(output_path, "Called glTexCoord4d\n");
}

void OpenGLLogger::glTexCoord4dv(const GLdouble *v)
{
	fprintf(output_path, "Called glTexCoord4dv\n");
}

void OpenGLLogger::glTexCoord4f(GLfloat s, GLfloat t, GLfloat r, GLfloat q)
{
	fprintf(output_path, "Called glTexCoord4f\n");
}

void OpenGLLogger::glTexCoord4fv(const GLfloat *v)
{
	fprintf(output_path, "Called glTexCoord4fv\n");
}

void OpenGLLogger::glTexCoord4i(GLint s, GLint t, GLint r, GLint q)
{
	fprintf(output_path, "Called glTexCoord4i\n");
}

void OpenGLLogger::glTexCoord4iv(const GLint *v)
{
	fprintf(output_path, "Called glTexCoord4iv\n");
}

void OpenGLLogger::glTexCoord4s(GLshort s, GLshort t, GLshort r, GLshort q)
{
	fprintf(output_path, "Called glTexCoord4s\n");
}

void OpenGLLogger::glTexCoord4sv(const GLshort *v)
{
	fprintf(output_path, "Called glTexCoord4sv\n");
}

void OpenGLLogger::glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)
{
	fprintf(output_path, "Called glTexCoordPointer\n");
}

void OpenGLLogger::glTexEnvf(GLenum target, GLenum pname, GLfloat param)
{
	fprintf(output_path, "Called glTexEnvf\n");
}

void OpenGLLogger::glTexEnvfv(GLenum target, GLenum pname, const GLfloat *params)
{
	fprintf(output_path, "Called glTexEnvfv\n");
}

void OpenGLLogger::glTexEnvi(GLenum target, GLenum pname, GLint param)
{
	fprintf(output_path, "Called glTexEnvi\n");
}

void OpenGLLogger::glTexEnviv(GLenum target, GLenum pname, const GLint *params)
{
	fprintf(output_path, "Called glTexEnviv\n");
}

void OpenGLLogger::glTexGend(GLenum coord, GLenum pname, GLdouble param)
{
	fprintf(output_path, "Called glTexGend\n");
}

void OpenGLLogger::glTexGendv(GLenum coord, GLenum pname, const GLdouble *params)
{
	fprintf(output_path, "Called glTexGendv\n");
}

void OpenGLLogger::glTexGenf(GLenum coord, GLenum pname, GLfloat param)
{
	fprintf(output_path, "Called glTexGenf\n");
}

void OpenGLLogger::glTexGenfv(GLenum coord, GLenum pname, const GLfloat *params)
{
	fprintf(output_path, "Called glTexGenfv\n");
}

void OpenGLLogger::glTexGeni(GLenum coord, GLenum pname, GLint param)
{
	fprintf(output_path, "Called glTexGeni\n");
}

void OpenGLLogger::glTexGeniv(GLenum coord, GLenum pname, const GLint *params)
{
	fprintf(output_path, "Called glTexGeniv\n");
}

void OpenGLLogger::glTexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels)
{
	fprintf(output_path, "Called glTexImage1D\n");
}

void OpenGLLogger::glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels)
{
	fprintf(output_path, "Called glTexImage2D\n");
}

void OpenGLLogger::glTexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels)
{
	fprintf(output_path, "Called glTexImage3D\n");
}

void OpenGLLogger::glTexParameterf(GLenum target, GLenum pname, GLfloat param)
{
	fprintf(output_path, "Called glTexParameterf\n");
}

void OpenGLLogger::glTexParameterfv(GLenum target, GLenum pname, const GLfloat *params)
{
	fprintf(output_path, "Called glTexParameterfv\n");
}

void OpenGLLogger::glTexParameteri(GLenum target, GLenum pname, GLint param)
{
	fprintf(output_path, "Called glTexParameteri\n");
}

void OpenGLLogger::glTexParameteriv(GLenum target, GLenum pname, const GLint *params)
{
	fprintf(output_path, "Called glTexParameteriv\n");
}

void OpenGLLogger::glTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels)
{
	fprintf(output_path, "Called glTexSubImage1D\n");
}

void OpenGLLogger::glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels)
{
	fprintf(output_path, "Called glTexSubImage2D\n");
}

void OpenGLLogger::glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels)
{
	fprintf(output_path, "Called glTexSubImage3D\n");
}

void OpenGLLogger::glTranslated(GLdouble x, GLdouble y, GLdouble z)
{
	fprintf(output_path, "Called glTranslated\n");
}

void OpenGLLogger::glTranslatef(GLfloat x, GLfloat y, GLfloat z)
{
	fprintf(output_path, "Called glTranslatef\n");
}

void OpenGLLogger::glVertex2d(GLdouble x, GLdouble y)
{
	fprintf(output_path, "Called glVertex2d\n");
}

void OpenGLLogger::glVertex2dv(const GLdouble *v)
{
	fprintf(output_path, "Called glVertex2dv\n");
}

void OpenGLLogger::glVertex2f(GLfloat x, GLfloat y)
{
	fprintf(output_path, "Called glVertex2f\n");
}

void OpenGLLogger::glVertex2fv(const GLfloat *v)
{
	fprintf(output_path, "Called glVertex2fv\n");
}

void OpenGLLogger::glVertex2i(GLint x, GLint y)
{
	fprintf(output_path, "Called glVertex2i\n");
}

void OpenGLLogger::glVertex2iv(const GLint *v)
{
	fprintf(output_path, "Called glVertex2iv\n");
}

void OpenGLLogger::glVertex2s(GLshort x, GLshort y)
{
	fprintf(output_path, "Called glVertex2s\n");
}

void OpenGLLogger::glVertex2sv(const GLshort *v)
{
	fprintf(output_path, "Called glVertex2sv\n");
}

void OpenGLLogger::glVertex3d(GLdouble x, GLdouble y, GLdouble z)
{
	fprintf(output_path, "Called glVertex3d\n");
}

void OpenGLLogger::glVertex3dv(const GLdouble *v)
{
	fprintf(output_path, "Called glVertex3dv\n");
}

void OpenGLLogger::glVertex3f(GLfloat x, GLfloat y, GLfloat z)
{
	fprintf(output_path, "Called glVertex3f\n");
}

void OpenGLLogger::glVertex3fv(const GLfloat *v)
{
	fprintf(output_path, "Called glVertex3fv\n");
}

void OpenGLLogger::glVertex3i(GLint x, GLint y, GLint z)
{
	fprintf(output_path, "Called glVertex3i\n");
}

void OpenGLLogger::glVertex3iv(const GLint *v)
{
	fprintf(output_path, "Called glVertex3iv\n");
}

void OpenGLLogger::glVertex3s(GLshort x, GLshort y, GLshort z)
{
	fprintf(output_path, "Called glVertex3s\n");
}

void OpenGLLogger::glVertex3sv(const GLshort *v)
{
	fprintf(output_path, "Called glVertex3sv\n");
}

void OpenGLLogger::glVertex4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w)
{
	fprintf(output_path, "Called glVertex4d\n");
}

void OpenGLLogger::glVertex4dv(const GLdouble *v)
{
	fprintf(output_path, "Called glVertex4dv\n");
}

void OpenGLLogger::glVertex4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
	fprintf(output_path, "Called glVertex4f\n");
}

void OpenGLLogger::glVertex4fv(const GLfloat *v)
{
	fprintf(output_path, "Called glVertex4fv\n");
}

void OpenGLLogger::glVertex4i(GLint x, GLint y, GLint z, GLint w)
{
	fprintf(output_path, "Called glVertex4i\n");
}

void OpenGLLogger::glVertex4iv(const GLint *v)
{
	fprintf(output_path, "Called glVertex4iv\n");
}

void OpenGLLogger::glVertex4s(GLshort x, GLshort y, GLshort z, GLshort w)
{
	fprintf(output_path, "Called glVertex4s\n");
}

void OpenGLLogger::glVertex4sv(const GLshort *v)
{
	fprintf(output_path, "Called glVertex4sv\n");
}

void OpenGLLogger::glVertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)
{
	fprintf(output_path, "Called glVertexPointer\n");
}

void OpenGLLogger::glViewport(GLint x, GLint y, GLsizei width, GLsizei height)
{
	fprintf(output_path, "Called glViewport\n");
}

void OpenGLLogger::glSampleCoverage(GLclampf value, GLboolean invert)
{
	fprintf(output_path, "Called glSampleCoverage\n");
}

void OpenGLLogger::glLoadTransposeMatrixf(const GLfloat *m)
{
	fprintf(output_path, "Called glLoadTransposeMatrixf\n");
}

void OpenGLLogger::glLoadTransposeMatrixd(const GLdouble *m)
{
	fprintf(output_path, "Called glLoadTransposeMatrixd\n");
}

void OpenGLLogger::glMultTransposeMatrixf(const GLfloat *m)
{
	fprintf(output_path, "Called glMultTransposeMatrixf\n");
}

void OpenGLLogger::glMultTransposeMatrixd(const GLdouble *m)
{
	fprintf(output_path, "Called glMultTransposeMatrixd\n");
}

void OpenGLLogger::glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *data)
{
	fprintf(output_path, "Called glCompressedTexImage3D\n");
}

void OpenGLLogger::glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data)
{
	fprintf(output_path, "Called glCompressedTexImage2D\n");
}

void OpenGLLogger::glCompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data)
{
	fprintf(output_path, "Called glCompressedTexImage1D\n");
}

void OpenGLLogger::glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data)
{
	fprintf(output_path, "Called glCompressedTexSubImage3D\n");
}

void OpenGLLogger::glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data)
{
	fprintf(output_path, "Called glCompressedTexSubImage2D\n");
}

void OpenGLLogger::glCompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data)
{
	fprintf(output_path, "Called glCompressedTexSubImage1D\n");
}

void OpenGLLogger::glGetCompressedTexImage(GLenum target, GLint lod, GLvoid *img)
{
	fprintf(output_path, "Called glGetCompressedTexImage\n");
}

void OpenGLLogger::glActiveTexture(GLenum texture)
{
	fprintf(output_path, "Called glActiveTexture\n");
}

void OpenGLLogger::glClientActiveTexture(GLenum texture)
{
	fprintf(output_path, "Called glClientActiveTexture\n");
}

void OpenGLLogger::glMultiTexCoord1d(GLenum target, GLdouble s)
{
	fprintf(output_path, "Called glMultiTexCoord1d\n");
}

void OpenGLLogger::glMultiTexCoord1dv(GLenum target, const GLdouble *v)
{
	fprintf(output_path, "Called glMultiTexCoord1dv\n");
}

void OpenGLLogger::glMultiTexCoord1f(GLenum target, GLfloat s)
{
	fprintf(output_path, "Called glMultiTexCoord1f\n");
}

void OpenGLLogger::glMultiTexCoord1fv(GLenum target, const GLfloat *v)
{
	fprintf(output_path, "Called glMultiTexCoord1fv\n");
}

void OpenGLLogger::glMultiTexCoord1i(GLenum target, GLint s)
{
	fprintf(output_path, "Called glMultiTexCoord1i\n");
}

void OpenGLLogger::glMultiTexCoord1iv(GLenum target, const GLint *v)
{
	fprintf(output_path, "Called glMultiTexCoord1iv\n");
}

void OpenGLLogger::glMultiTexCoord1s(GLenum target, GLshort s)
{
	fprintf(output_path, "Called glMultiTexCoord1s\n");
}

void OpenGLLogger::glMultiTexCoord1sv(GLenum target, const GLshort *v)
{
	fprintf(output_path, "Called glMultiTexCoord1sv\n");
}

void OpenGLLogger::glMultiTexCoord2d(GLenum target, GLdouble s, GLdouble t)
{
	fprintf(output_path, "Called glMultiTexCoord2d\n");
}

void OpenGLLogger::glMultiTexCoord2dv(GLenum target, const GLdouble *v)
{
	fprintf(output_path, "Called glMultiTexCoord2dv\n");
}

void OpenGLLogger::glMultiTexCoord2f(GLenum target, GLfloat s, GLfloat t)
{
	fprintf(output_path, "Called glMultiTexCoord2f\n");
}

void OpenGLLogger::glMultiTexCoord2fv(GLenum target, const GLfloat *v)
{
	fprintf(output_path, "Called glMultiTexCoord2fv\n");
}

void OpenGLLogger::glMultiTexCoord2i(GLenum target, GLint s, GLint t)
{
	fprintf(output_path, "Called glMultiTexCoord2i\n");
}

void OpenGLLogger::glMultiTexCoord2iv(GLenum target, const GLint *v)
{
	fprintf(output_path, "Called glMultiTexCoord2iv\n");
}

void OpenGLLogger::glMultiTexCoord2s(GLenum target, GLshort s, GLshort t)
{
	fprintf(output_path, "Called glMultiTexCoord2s\n");
}

void OpenGLLogger::glMultiTexCoord2sv(GLenum target, const GLshort *v)
{
	fprintf(output_path, "Called glMultiTexCoord2sv\n");
}

void OpenGLLogger::glMultiTexCoord3d(GLenum target, GLdouble s, GLdouble t, GLdouble r)
{
	fprintf(output_path, "Called glMultiTexCoord3d\n");
}

void OpenGLLogger::glMultiTexCoord3dv(GLenum target, const GLdouble *v)
{
	fprintf(output_path, "Called glMultiTexCoord3dv\n");
}

void OpenGLLogger::glMultiTexCoord3f(GLenum target, GLfloat s, GLfloat t, GLfloat r)
{
	fprintf(output_path, "Called glMultiTexCoord3f\n");
}

void OpenGLLogger::glMultiTexCoord3fv(GLenum target, const GLfloat *v)
{
	fprintf(output_path, "Called glMultiTexCoord3fv\n");
}

void OpenGLLogger::glMultiTexCoord3i(GLenum target, GLint s, GLint t, GLint r)
{
	fprintf(output_path, "Called glMultiTexCoord3i\n");
}

void OpenGLLogger::glMultiTexCoord3iv(GLenum target, const GLint *v)
{
	fprintf(output_path, "Called glMultiTexCoord3iv\n");
}

void OpenGLLogger::glMultiTexCoord3s(GLenum target, GLshort s, GLshort t, GLshort r)
{
	fprintf(output_path, "Called glMultiTexCoord3s\n");
}

void OpenGLLogger::glMultiTexCoord3sv(GLenum target, const GLshort *v)
{
	fprintf(output_path, "Called glMultiTexCoord3sv\n");
}

void OpenGLLogger::glMultiTexCoord4d(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q)
{
	fprintf(output_path, "Called glMultiTexCoord4d\n");
}

void OpenGLLogger::glMultiTexCoord4dv(GLenum target, const GLdouble *v)
{
	fprintf(output_path, "Called glMultiTexCoord4dv\n");
}

void OpenGLLogger::glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q)
{
	fprintf(output_path, "Called glMultiTexCoord4f\n");
}

void OpenGLLogger::glMultiTexCoord4fv(GLenum target, const GLfloat *v)
{
	fprintf(output_path, "Called glMultiTexCoord4fv\n");
}

void OpenGLLogger::glMultiTexCoord4i(GLenum target, GLint s, GLint t, GLint r, GLint q)
{
	fprintf(output_path, "Called glMultiTexCoord4i\n");
}

void OpenGLLogger::glMultiTexCoord4iv(GLenum target, const GLint *v)
{
	fprintf(output_path, "Called glMultiTexCoord4iv\n");
}

void OpenGLLogger::glMultiTexCoord4s(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q)
{
	fprintf(output_path, "Called glMultiTexCoord4s\n");
}

void OpenGLLogger::glMultiTexCoord4sv(GLenum target, const GLshort *v)
{
	fprintf(output_path, "Called glMultiTexCoord4sv\n");
}

void OpenGLLogger::glFogCoordf(GLfloat coord)
{
	fprintf(output_path, "Called glFogCoordf\n");
}

void OpenGLLogger::glFogCoordfv(const GLfloat *coord)
{
	fprintf(output_path, "Called glFogCoordfv\n");
}

void OpenGLLogger::glFogCoordd(GLdouble coord)
{
	fprintf(output_path, "Called glFogCoordd\n");
}

void OpenGLLogger::glFogCoorddv(const GLdouble *coord)
{
	fprintf(output_path, "Called glFogCoorddv\n");
}

void OpenGLLogger::glFogCoordPointer(GLenum type, GLsizei stride, const GLvoid *pointer)
{
	fprintf(output_path, "Called glFogCoordPointer\n");
}

void OpenGLLogger::glSecondaryColor3b(GLbyte red, GLbyte green, GLbyte blue)
{
	fprintf(output_path, "Called glSecondaryColor3b\n");
}

void OpenGLLogger::glSecondaryColor3bv(const GLbyte *v)
{
	fprintf(output_path, "Called glSecondaryColor3bv\n");
}

void OpenGLLogger::glSecondaryColor3d(GLdouble red, GLdouble green, GLdouble blue)
{
	fprintf(output_path, "Called glSecondaryColor3d\n");
}

void OpenGLLogger::glSecondaryColor3dv(const GLdouble *v)
{
	fprintf(output_path, "Called glSecondaryColor3dv\n");
}

void OpenGLLogger::glSecondaryColor3f(GLfloat red, GLfloat green, GLfloat blue)
{
	fprintf(output_path, "Called glSecondaryColor3f\n");
}

void OpenGLLogger::glSecondaryColor3fv(const GLfloat *v)
{
	fprintf(output_path, "Called glSecondaryColor3fv\n");
}

void OpenGLLogger::glSecondaryColor3i(GLint red, GLint green, GLint blue)
{
	fprintf(output_path, "Called glSecondaryColor3i\n");
}

void OpenGLLogger::glSecondaryColor3iv(const GLint *v)
{
	fprintf(output_path, "Called glSecondaryColor3iv\n");
}

void OpenGLLogger::glSecondaryColor3s(GLshort red, GLshort green, GLshort blue)
{
	fprintf(output_path, "Called glSecondaryColor3s\n");
}

void OpenGLLogger::glSecondaryColor3sv(const GLshort *v)
{
	fprintf(output_path, "Called glSecondaryColor3sv\n");
}

void OpenGLLogger::glSecondaryColor3ub(GLubyte red, GLubyte green, GLubyte blue)
{
	fprintf(output_path, "Called glSecondaryColor3ub\n");
}

void OpenGLLogger::glSecondaryColor3ubv(const GLubyte *v)
{
	fprintf(output_path, "Called glSecondaryColor3ubv\n");
}

void OpenGLLogger::glSecondaryColor3ui(GLuint red, GLuint green, GLuint blue)
{
	fprintf(output_path, "Called glSecondaryColor3ui\n");
}

void OpenGLLogger::glSecondaryColor3uiv(const GLuint *v)
{
	fprintf(output_path, "Called glSecondaryColor3uiv\n");
}

void OpenGLLogger::glSecondaryColor3us(GLushort red, GLushort green, GLushort blue)
{
	fprintf(output_path, "Called glSecondaryColor3us\n");
}

void OpenGLLogger::glSecondaryColor3usv(const GLushort *v)
{
	fprintf(output_path, "Called glSecondaryColor3usv\n");
}

void OpenGLLogger::glSecondaryColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)
{
	fprintf(output_path, "Called glSecondaryColorPointer\n");
}

void OpenGLLogger::glPointParameterf(GLenum pname, GLfloat param)
{
	fprintf(output_path, "Called glPointParameterf\n");
}

void OpenGLLogger::glPointParameterfv(GLenum pname, const GLfloat *params)
{
	fprintf(output_path, "Called glPointParameterfv\n");
}

void OpenGLLogger::glPointParameteri(GLenum pname, GLint param)
{
	fprintf(output_path, "Called glPointParameteri\n");
}

void OpenGLLogger::glPointParameteriv(GLenum pname, const GLint *params)
{
	fprintf(output_path, "Called glPointParameteriv\n");
}

void OpenGLLogger::glBlendFuncSeparate(GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha)
{
	fprintf(output_path, "Called glBlendFuncSeparate\n");
}

void OpenGLLogger::glMultiDrawArrays(GLenum mode, const GLint *first, const GLsizei *count, GLsizei primcount)
{
	fprintf(output_path, "Called glMultiDrawArrays\n");
}

void OpenGLLogger::glMultiDrawElements(GLenum mode, const GLsizei *count, GLenum type, const GLvoid* const *indices, GLsizei primcount)
{
	fprintf(output_path, "Called glMultiDrawElements\n");
}

void OpenGLLogger::glWindowPos2d(GLdouble x, GLdouble y)
{
	fprintf(output_path, "Called glWindowPos2d\n");
}

void OpenGLLogger::glWindowPos2dv(const GLdouble *v)
{
	fprintf(output_path, "Called glWindowPos2dv\n");
}

void OpenGLLogger::glWindowPos2f(GLfloat x, GLfloat y)
{
	fprintf(output_path, "Called glWindowPos2f\n");
}

void OpenGLLogger::glWindowPos2fv(const GLfloat *v)
{
	fprintf(output_path, "Called glWindowPos2fv\n");
}

void OpenGLLogger::glWindowPos2i(GLint x, GLint y)
{
	fprintf(output_path, "Called glWindowPos2i\n");
}

void OpenGLLogger::glWindowPos2iv(const GLint *v)
{
	fprintf(output_path, "Called glWindowPos2iv\n");
}

void OpenGLLogger::glWindowPos2s(GLshort x, GLshort y)
{
	fprintf(output_path, "Called glWindowPos2s\n");
}

void OpenGLLogger::glWindowPos2sv(const GLshort *v)
{
	fprintf(output_path, "Called glWindowPos2sv\n");
}

void OpenGLLogger::glWindowPos3d(GLdouble x, GLdouble y, GLdouble z)
{
	fprintf(output_path, "Called glWindowPos3d\n");
}

void OpenGLLogger::glWindowPos3dv(const GLdouble *v)
{
	fprintf(output_path, "Called glWindowPos3dv\n");
}

void OpenGLLogger::glWindowPos3f(GLfloat x, GLfloat y, GLfloat z)
{
	fprintf(output_path, "Called glWindowPos3f\n");
}

void OpenGLLogger::glWindowPos3fv(const GLfloat *v)
{
	fprintf(output_path, "Called glWindowPos3fv\n");
}

void OpenGLLogger::glWindowPos3i(GLint x, GLint y, GLint z)
{
	fprintf(output_path, "Called glWindowPos3i\n");
}

void OpenGLLogger::glWindowPos3iv(const GLint *v)
{
	fprintf(output_path, "Called glWindowPos3iv\n");
}

void OpenGLLogger::glWindowPos3s(GLshort x, GLshort y, GLshort z)
{
	fprintf(output_path, "Called glWindowPos3s\n");
}

void OpenGLLogger::glWindowPos3sv(const GLshort *v)
{
	fprintf(output_path, "Called glWindowPos3sv\n");
}

void OpenGLLogger::glGenQueries(GLsizei n, GLuint *ids)
{
	fprintf(output_path, "Called glGenQueries\n");
}

void OpenGLLogger::glDeleteQueries(GLsizei n, const GLuint *ids)
{
	fprintf(output_path, "Called glDeleteQueries\n");
}

GLboolean OpenGLLogger::glIsQuery(GLuint id)
{
	fprintf(output_path, "Called glIsQuery\n");
	
	return false;
}

void OpenGLLogger::glBeginQuery(GLenum target, GLuint id)
{
	fprintf(output_path, "Called glBeginQuery\n");
}

void OpenGLLogger::glEndQuery(GLenum target)
{
	fprintf(output_path, "Called glEndQuery\n");
}

void OpenGLLogger::glGetQueryiv(GLenum target, GLenum pname, GLint *params)
{
	fprintf(output_path, "Called glGetQueryiv\n");
}

void OpenGLLogger::glGetQueryObjectiv(GLuint id, GLenum pname, GLint *params)
{
	fprintf(output_path, "Called glGetQueryObjectiv\n");
}

void OpenGLLogger::glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint *params)
{
	fprintf(output_path, "Called glGetQueryObjectuiv\n");
}

void OpenGLLogger::glBindBuffer(GLenum target, GLuint buffer)
{
	fprintf(output_path, "Called glBindBuffer\n");
}

void OpenGLLogger::glDeleteBuffers(GLsizei n, const GLuint *buffers)
{
	fprintf(output_path, "Called glDeleteBuffers\n");
}

void OpenGLLogger::glGenBuffers(GLsizei n, GLuint *buffers)
{
	fprintf(output_path, "Called glGenBuffers\n");
}

GLboolean OpenGLLogger::glIsBuffer(GLuint buffer)
{
	fprintf(output_path, "Called glIsBuffer\n");
	
	return false;
}

void OpenGLLogger::glBufferData(GLenum target, GLsizeiptr size, const GLvoid *data, GLenum usage)
{
	fprintf(output_path, "Called glBufferData\n");
}

void OpenGLLogger::glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid *data)
{
	fprintf(output_path, "Called glBufferSubData\n");
}

void OpenGLLogger::glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid *data)
{
	fprintf(output_path, "Called glGetBufferSubData\n");
}

GLvoid* OpenGLLogger::glMapBuffer(GLenum target, GLenum access)
{
	fprintf(output_path, "Called *glMapBuffer\n");
	
	return nullptr;
}

GLboolean OpenGLLogger::glUnmapBuffer(GLenum target)
{
	fprintf(output_path, "Called glUnmapBuffer\n");
	
	return false;
}

void OpenGLLogger::glGetBufferParameteriv(GLenum target, GLenum pname, GLint *params)
{
	fprintf(output_path, "Called glGetBufferParameteriv\n");
}

void OpenGLLogger::glGetBufferPointerv(GLenum target, GLenum pname, GLvoid **params)
{
	fprintf(output_path, "Called glGetBufferPointerv\n");
}

void OpenGLLogger::glDrawBuffers(GLsizei n, const GLenum *bufs)
{
	fprintf(output_path, "Called glDrawBuffers\n");
}

void OpenGLLogger::glVertexAttrib1d(GLuint index, GLdouble x)
{
	fprintf(output_path, "Called glVertexAttrib1d\n");
}

void OpenGLLogger::glVertexAttrib1dv(GLuint index, const GLdouble *v)
{
	fprintf(output_path, "Called glVertexAttrib1dv\n");
}

void OpenGLLogger::glVertexAttrib1f(GLuint index, GLfloat x)
{
	fprintf(output_path, "Called glVertexAttrib1f\n");
}

void OpenGLLogger::glVertexAttrib1fv(GLuint index, const GLfloat *v)
{
	fprintf(output_path, "Called glVertexAttrib1fv\n");
}

void OpenGLLogger::glVertexAttrib1s(GLuint index, GLshort x)
{
	fprintf(output_path, "Called glVertexAttrib1s\n");
}

void OpenGLLogger::glVertexAttrib1sv(GLuint index, const GLshort *v)
{
	fprintf(output_path, "Called glVertexAttrib1sv\n");
}

void OpenGLLogger::glVertexAttrib2d(GLuint index, GLdouble x, GLdouble y)
{
	fprintf(output_path, "Called glVertexAttrib2d\n");
}

void OpenGLLogger::glVertexAttrib2dv(GLuint index, const GLdouble *v)
{
	fprintf(output_path, "Called glVertexAttrib2dv\n");
}

void OpenGLLogger::glVertexAttrib2f(GLuint index, GLfloat x, GLfloat y)
{
	fprintf(output_path, "Called glVertexAttrib2f\n");
}

void OpenGLLogger::glVertexAttrib2fv(GLuint index, const GLfloat *v)
{
	fprintf(output_path, "Called glVertexAttrib2fv\n");
}

void OpenGLLogger::glVertexAttrib2s(GLuint index, GLshort x, GLshort y)
{
	fprintf(output_path, "Called glVertexAttrib2s\n");
}

void OpenGLLogger::glVertexAttrib2sv(GLuint index, const GLshort *v)
{
	fprintf(output_path, "Called glVertexAttrib2sv\n");
}

void OpenGLLogger::glVertexAttrib3d(GLuint index, GLdouble x, GLdouble y, GLdouble z)
{
	fprintf(output_path, "Called glVertexAttrib3d\n");
}

void OpenGLLogger::glVertexAttrib3dv(GLuint index, const GLdouble *v)
{
	fprintf(output_path, "Called glVertexAttrib3dv\n");
}

void OpenGLLogger::glVertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z)
{
	fprintf(output_path, "Called glVertexAttrib3f\n");
}

void OpenGLLogger::glVertexAttrib3fv(GLuint index, const GLfloat *v)
{
	fprintf(output_path, "Called glVertexAttrib3fv\n");
}

void OpenGLLogger::glVertexAttrib3s(GLuint index, GLshort x, GLshort y, GLshort z)
{
	fprintf(output_path, "Called glVertexAttrib3s\n");
}

void OpenGLLogger::glVertexAttrib3sv(GLuint index, const GLshort *v)
{
	fprintf(output_path, "Called glVertexAttrib3sv\n");
}

void OpenGLLogger::glVertexAttrib4Nbv(GLuint index, const GLbyte *v)
{
	fprintf(output_path, "Called glVertexAttrib4Nbv\n");
}

void OpenGLLogger::glVertexAttrib4Niv(GLuint index, const GLint *v)
{
	fprintf(output_path, "Called glVertexAttrib4Niv\n");
}

void OpenGLLogger::glVertexAttrib4Nsv(GLuint index, const GLshort *v)
{
	fprintf(output_path, "Called glVertexAttrib4Nsv\n");
}

void OpenGLLogger::glVertexAttrib4Nub(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w)
{
	fprintf(output_path, "Called glVertexAttrib4Nub\n");
}

void OpenGLLogger::glVertexAttrib4Nubv(GLuint index, const GLubyte *v)
{
	fprintf(output_path, "Called glVertexAttrib4Nubv\n");
}

void OpenGLLogger::glVertexAttrib4Nuiv(GLuint index, const GLuint *v)
{
	fprintf(output_path, "Called glVertexAttrib4Nuiv\n");
}

void OpenGLLogger::glVertexAttrib4Nusv(GLuint index, const GLushort *v)
{
	fprintf(output_path, "Called glVertexAttrib4Nusv\n");
}

void OpenGLLogger::glVertexAttrib4bv(GLuint index, const GLbyte *v)
{
	fprintf(output_path, "Called glVertexAttrib4bv\n");
}

void OpenGLLogger::glVertexAttrib4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w)
{
	fprintf(output_path, "Called glVertexAttrib4d\n");
}

void OpenGLLogger::glVertexAttrib4dv(GLuint index, const GLdouble *v)
{
	fprintf(output_path, "Called glVertexAttrib4dv\n");
}

void OpenGLLogger::glVertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
	fprintf(output_path, "Called glVertexAttrib4f\n");
}

void OpenGLLogger::glVertexAttrib4fv(GLuint index, const GLfloat *v)
{
	fprintf(output_path, "Called glVertexAttrib4fv\n");
}

void OpenGLLogger::glVertexAttrib4iv(GLuint index, const GLint *v)
{
	fprintf(output_path, "Called glVertexAttrib4iv\n");
}

void OpenGLLogger::glVertexAttrib4s(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w)
{
	fprintf(output_path, "Called glVertexAttrib4s\n");
}

void OpenGLLogger::glVertexAttrib4sv(GLuint index, const GLshort *v)
{
	fprintf(output_path, "Called glVertexAttrib4sv\n");
}

void OpenGLLogger::glVertexAttrib4ubv(GLuint index, const GLubyte *v)
{
	fprintf(output_path, "Called glVertexAttrib4ubv\n");
}

void OpenGLLogger::glVertexAttrib4uiv(GLuint index, const GLuint *v)
{
	fprintf(output_path, "Called glVertexAttrib4uiv\n");
}

void OpenGLLogger::glVertexAttrib4usv(GLuint index, const GLushort *v)
{
	fprintf(output_path, "Called glVertexAttrib4usv\n");
}

void OpenGLLogger::glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid *pointer)
{
	fprintf(output_path, "Called glVertexAttribPointer\n");
}

void OpenGLLogger::glEnableVertexAttribArray(GLuint index)
{
	fprintf(output_path, "Called glEnableVertexAttribArray\n");
}

void OpenGLLogger::glDisableVertexAttribArray(GLuint index)
{
	fprintf(output_path, "Called glDisableVertexAttribArray\n");
}

void OpenGLLogger::glGetVertexAttribdv(GLuint index, GLenum pname, GLdouble *params)
{
	fprintf(output_path, "Called glGetVertexAttribdv\n");
}

void OpenGLLogger::glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat *params)
{
	fprintf(output_path, "Called glGetVertexAttribfv\n");
}

void OpenGLLogger::glGetVertexAttribiv(GLuint index, GLenum pname, GLint *params)
{
	fprintf(output_path, "Called glGetVertexAttribiv\n");
}

void OpenGLLogger::glGetVertexAttribPointerv(GLuint index, GLenum pname, GLvoid **pointer)
{
	fprintf(output_path, "Called glGetVertexAttribPointerv\n");
}

void OpenGLLogger::glDeleteShader(GLuint shader)
{
	fprintf(output_path, "Called glDeleteShader\n");
}

void OpenGLLogger::glDetachShader(GLuint program, GLuint shader)
{
	fprintf(output_path, "Called glDetachShader\n");
}

GLuint OpenGLLogger::glCreateShader(GLenum type)
{
	fprintf(output_path, "Called glCreateShader\n");
	
	return false;
}

void OpenGLLogger::glShaderSource(GLuint shader, GLsizei count, const GLchar* const *string, const GLint *length)
{
	fprintf(output_path, "Called glShaderSource\n");
}

void OpenGLLogger::glCompileShader(GLuint shader)
{
	fprintf(output_path, "Called glCompileShader\n");
}

GLuint OpenGLLogger::glCreateProgram(void)
{
	fprintf(output_path, "Called glCreateProgram\n");
	
	return 0;
}

void OpenGLLogger::glAttachShader(GLuint program, GLuint shader)
{
	fprintf(output_path, "Called glAttachShader\n");
}

void OpenGLLogger::glLinkProgram(GLuint program)
{
	fprintf(output_path, "Called glLinkProgram\n");
}

void OpenGLLogger::glUseProgram(GLuint program)
{
	fprintf(output_path, "Called glUseProgram\n");
}

void OpenGLLogger::glDeleteProgram(GLuint program)
{
	fprintf(output_path, "Called glDeleteProgram\n");
}

void OpenGLLogger::glValidateProgram(GLuint program)
{
	fprintf(output_path, "Called glValidateProgram\n");
}

void OpenGLLogger::glUniform1f(GLint location, GLfloat v0)
{
	fprintf(output_path, "Called glUniform1f\n");
}

void OpenGLLogger::glUniform2f(GLint location, GLfloat v0, GLfloat v1)
{
	fprintf(output_path, "Called glUniform2f\n");
}

void OpenGLLogger::glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2)
{
	fprintf(output_path, "Called glUniform3f\n");
}

void OpenGLLogger::glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3)
{
	fprintf(output_path, "Called glUniform4f\n");
}

void OpenGLLogger::glUniform1i(GLint location, GLint v0)
{
	fprintf(output_path, "Called glUniform1i\n");
}

void OpenGLLogger::glUniform2i(GLint location, GLint v0, GLint v1)
{
	fprintf(output_path, "Called glUniform2i\n");
}

void OpenGLLogger::glUniform3i(GLint location, GLint v0, GLint v1, GLint v2)
{
	fprintf(output_path, "Called glUniform3i\n");
}

void OpenGLLogger::glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3)
{
	fprintf(output_path, "Called glUniform4i\n");
}

void OpenGLLogger::glUniform1fv(GLint location, GLsizei count, const GLfloat *value)
{
	fprintf(output_path, "Called glUniform1fv\n");
}

void OpenGLLogger::glUniform2fv(GLint location, GLsizei count, const GLfloat *value)
{
	fprintf(output_path, "Called glUniform2fv\n");
}

void OpenGLLogger::glUniform3fv(GLint location, GLsizei count, const GLfloat *value)
{
	fprintf(output_path, "Called glUniform3fv\n");
}

void OpenGLLogger::glUniform4fv(GLint location, GLsizei count, const GLfloat *value)
{
	fprintf(output_path, "Called glUniform4fv\n");
}

void OpenGLLogger::glUniform1iv(GLint location, GLsizei count, const GLint *value)
{
	fprintf(output_path, "Called glUniform1iv\n");
}

void OpenGLLogger::glUniform2iv(GLint location, GLsizei count, const GLint *value)
{
	fprintf(output_path, "Called glUniform2iv\n");
}

void OpenGLLogger::glUniform3iv(GLint location, GLsizei count, const GLint *value)
{
	fprintf(output_path, "Called glUniform3iv\n");
}

void OpenGLLogger::glUniform4iv(GLint location, GLsizei count, const GLint *value)
{
	fprintf(output_path, "Called glUniform4iv\n");
}

void OpenGLLogger::glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	fprintf(output_path, "Called glUniformMatrix2fv\n");
}

void OpenGLLogger::glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	fprintf(output_path, "Called glUniformMatrix3fv\n");
}

void OpenGLLogger::glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	fprintf(output_path, "Called glUniformMatrix4fv\n");
}

GLboolean OpenGLLogger::glIsShader(GLuint shader)
{
	fprintf(output_path, "Called glIsShader\n");
	
	return false;
}

GLboolean OpenGLLogger::glIsProgram(GLuint program)
{
	fprintf(output_path, "Called glIsProgram\n");
	
	return false;
}

void OpenGLLogger::glGetShaderiv(GLuint shader, GLenum pname, GLint *params)
{
	fprintf(output_path, "Called glGetShaderiv\n");
}

void OpenGLLogger::glGetProgramiv(GLuint program, GLenum pname, GLint *params)
{
	fprintf(output_path, "Called glGetProgramiv\n");
}

void OpenGLLogger::glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders)
{
	fprintf(output_path, "Called glGetAttachedShaders\n");
}

void OpenGLLogger::glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog)
{
	fprintf(output_path, "Called glGetShaderInfoLog\n");
}

void OpenGLLogger::glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog)
{
	fprintf(output_path, "Called glGetProgramInfoLog\n");
}

GLint OpenGLLogger::glGetUniformLocation(GLuint program, const GLchar *name)
{
	fprintf(output_path, "Called glGetUniformLocation\n");
	
	return 0;
}

void OpenGLLogger::glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name)
{
	fprintf(output_path, "Called glGetActiveUniform\n");
}

void OpenGLLogger::glGetUniformfv(GLuint program, GLint location, GLfloat *params)
{
	fprintf(output_path, "Called glGetUniformfv\n");
}

void OpenGLLogger::glGetUniformiv(GLuint program, GLint location, GLint *params)
{
	fprintf(output_path, "Called glGetUniformiv\n");
}

void OpenGLLogger::glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source)
{
	fprintf(output_path, "Called glGetShaderSource\n");
}

void OpenGLLogger::glBindAttribLocation(GLuint program, GLuint index, const GLchar *name)
{
	fprintf(output_path, "Called glBindAttribLocation\n");
}

void OpenGLLogger::glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name)
{
	fprintf(output_path, "Called glGetActiveAttrib\n");
}

GLint OpenGLLogger::glGetAttribLocation(GLuint program, const GLchar *name)
{
	fprintf(output_path, "Called glGetAttribLocation\n");
	
	return 0;
}

void OpenGLLogger::glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask)
{
	fprintf(output_path, "Called glStencilFuncSeparate\n");
}

void OpenGLLogger::glStencilOpSeparate(GLenum face, GLenum fail, GLenum zfail, GLenum zpass)
{
	fprintf(output_path, "Called glStencilOpSeparate\n");
}

void OpenGLLogger::glStencilMaskSeparate(GLenum face, GLuint mask)
{
	fprintf(output_path, "Called glStencilMaskSeparate\n");
}

void OpenGLLogger::glUniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	fprintf(output_path, "Called glUniformMatrix2x3fv\n");
}

void OpenGLLogger::glUniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	fprintf(output_path, "Called glUniformMatrix3x2fv\n");
}

void OpenGLLogger::glUniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	fprintf(output_path, "Called glUniformMatrix2x4fv\n");
}

void OpenGLLogger::glUniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	fprintf(output_path, "Called glUniformMatrix4x2fv\n");
}

void OpenGLLogger::glUniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	fprintf(output_path, "Called glUniformMatrix3x4fv\n");
}

void OpenGLLogger::glUniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	fprintf(output_path, "Called glUniformMatrix4x3fv\n");
}
