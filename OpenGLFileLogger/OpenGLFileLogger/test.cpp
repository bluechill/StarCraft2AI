#include "OpenGLLogger.h"
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl3.h>
#include "mach_override.h"

extern OpenGL3Logger logger3;

void OverrideOpenGL()
{
void OpenGL3Logger::glCullFace(GLenum mode)
{
	output_path << "Called glCullFace" << endl;
}

void OpenGL3Logger::glFrontFace(GLenum mode)
{
	output_path << "Called glFrontFace" << endl;
}

void OpenGL3Logger::glHint(GLenum target, GLenum mode)
{
	output_path << "Called glHint" << endl;
}

void OpenGL3Logger::glLineWidth(GLfloat width)
{
	output_path << "Called glLineWidth" << endl;
}

void OpenGL3Logger::glPointSize(GLfloat size)
{
	output_path << "Called glPointSize" << endl;
}

void OpenGL3Logger::glPolygonMode(GLenum face, GLenum mode)
{
	output_path << "Called glPolygonMode" << endl;
}

void OpenGL3Logger::glScissor(GLint x, GLint y, GLsizei width, GLsizei height)
{
	output_path << "Called glScissor" << endl;
}

void OpenGL3Logger::glTexParameterf(GLenum target, GLenum pname, GLfloat param)
{
	output_path << "Called glTexParameterf" << endl;
}

void OpenGL3Logger::glTexParameterfv(GLenum target, GLenum pname, const GLfloat *params)
{
	output_path << "Called glTexParameterfv" << endl;
}

void OpenGL3Logger::glTexParameteri(GLenum target, GLenum pname, GLint param)
{
	output_path << "Called glTexParameteri" << endl;
}

void OpenGL3Logger::glTexParameteriv(GLenum target, GLenum pname, const GLint *params)
{
	output_path << "Called glTexParameteriv" << endl;
}

void OpenGL3Logger::glTexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels)
{
	output_path << "Called glTexImage1D" << endl;
}

void OpenGL3Logger::glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels)
{
	output_path << "Called glTexImage2D" << endl;
}

void OpenGL3Logger::glDrawBuffer(GLenum mode)
{
	output_path << "Called glDrawBuffer" << endl;
}

void OpenGL3Logger::glClear(GLbitfield mask)
{
	output_path << "Called glClear" << endl;
}

void OpenGL3Logger::glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
	output_path << "Called glClearColor" << endl;
}

void OpenGL3Logger::glClearStencil(GLint s)
{
	output_path << "Called glClearStencil" << endl;
}

void OpenGL3Logger::glClearDepth(GLclampd depth)
{
	output_path << "Called glClearDepth" << endl;
}

void OpenGL3Logger::glStencilMask(GLuint mask)
{
	output_path << "Called glStencilMask" << endl;
}

void OpenGL3Logger::glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha)
{
	output_path << "Called glColorMask" << endl;
}

void OpenGL3Logger::glDepthMask(GLboolean flag)
{
	output_path << "Called glDepthMask" << endl;
}

void OpenGL3Logger::glDisable(GLenum cap)
{
	output_path << "Called glDisable" << endl;
}

void OpenGL3Logger::glEnable(GLenum cap)
{
	output_path << "Called glEnable" << endl;
}

void OpenGL3Logger::glFinish(void)
{
	output_path << "Called glFinish" << endl;
}

void OpenGL3Logger::glFlush(void)
{
	output_path << "Called glFlush" << endl;
}

void OpenGL3Logger::glBlendFunc(GLenum sfactor, GLenum dfactor)
{
	output_path << "Called glBlendFunc" << endl;
}

void OpenGL3Logger::glLogicOp(GLenum opcode)
{
	output_path << "Called glLogicOp" << endl;
}

void OpenGL3Logger::glStencilFunc(GLenum func, GLint ref, GLuint mask)
{
	output_path << "Called glStencilFunc" << endl;
}

void OpenGL3Logger::glStencilOp(GLenum fail, GLenum zfail, GLenum zpass)
{
	output_path << "Called glStencilOp" << endl;
}

void OpenGL3Logger::glDepthFunc(GLenum func)
{
	output_path << "Called glDepthFunc" << endl;
}

void OpenGL3Logger::glPixelStoref(GLenum pname, GLfloat param)
{
	output_path << "Called glPixelStoref" << endl;
}

void OpenGL3Logger::glPixelStorei(GLenum pname, GLint param)
{
	output_path << "Called glPixelStorei" << endl;
}

void OpenGL3Logger::glReadBuffer(GLenum mode)
{
	output_path << "Called glReadBuffer" << endl;
}

void OpenGL3Logger::glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels)
{
	output_path << "Called glReadPixels" << endl;
}

void OpenGL3Logger::glGetBooleanv(GLenum pname, GLboolean *params)
{
	output_path << "Called glGetBooleanv" << endl;
}

void OpenGL3Logger::glGetDoublev(GLenum pname, GLdouble *params)
{
	output_path << "Called glGetDoublev" << endl;
}

GLenum OpenGL3Logger::glGetError(void)
{
	output_path << "Called glGetError" << endl;
	return 0;
}

void OpenGL3Logger::glGetFloatv(GLenum pname, GLfloat *params)
{
	output_path << "Called glGetFloatv" << endl;
}

void OpenGL3Logger::glGetIntegerv(GLenum pname, GLint *params)
{
	output_path << "Called glGetIntegerv" << endl;
}

const GLubyte * OpenGL3Logger::glGetString(GLenum name)
{
	output_path << "Called glGetString" << endl;
	return nullptr;
}

void OpenGL3Logger::glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels)
{
	output_path << "Called glGetTexImage" << endl;
}

void OpenGL3Logger::glGetTexParameterfv(GLenum target, GLenum pname, GLfloat *params)
{
	output_path << "Called glGetTexParameterfv" << endl;
}

void OpenGL3Logger::glGetTexParameteriv(GLenum target, GLenum pname, GLint *params)
{
	output_path << "Called glGetTexParameteriv" << endl;
}

void OpenGL3Logger::glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat *params)
{
	output_path << "Called glGetTexLevelParameterfv" << endl;
}

void OpenGL3Logger::glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint *params)
{
	output_path << "Called glGetTexLevelParameteriv" << endl;
}

GLboolean OpenGL3Logger::glIsEnabled(GLenum cap)
{
	output_path << "Called glIsEnabled" << endl;
	return 0;
}

void OpenGL3Logger::glDepthRange(GLclampd near, GLclampd far)
{
	output_path << "Called glDepthRange" << endl;
}

void OpenGL3Logger::glViewport(GLint x, GLint y, GLsizei width, GLsizei height)
{
	output_path << "Called glViewport" << endl;
}

void OpenGL3Logger::glDrawArrays(GLenum mode, GLint first, GLsizei count)
{
	output_path << "Called glDrawArrays" << endl;
}

void OpenGL3Logger::glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices)
{
	output_path << "Called glDrawElements" << endl;
}

void OpenGL3Logger::glPolygonOffset(GLfloat factor, GLfloat units)
{
	output_path << "Called glPolygonOffset" << endl;
}

void OpenGL3Logger::glCopyTexImage1D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border)
{
	output_path << "Called glCopyTexImage1D" << endl;
}

void OpenGL3Logger::glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border)
{
	output_path << "Called glCopyTexImage2D" << endl;
}

void OpenGL3Logger::glCopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width)
{
	output_path << "Called glCopyTexSubImage1D" << endl;
}

void OpenGL3Logger::glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height)
{
	output_path << "Called glCopyTexSubImage2D" << endl;
}

void OpenGL3Logger::glTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels)
{
	output_path << "Called glTexSubImage1D" << endl;
}

void OpenGL3Logger::glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels)
{
	output_path << "Called glTexSubImage2D" << endl;
}

void OpenGL3Logger::glBindTexture(GLenum target, GLuint texture)
{
	output_path << "Called glBindTexture" << endl;
}

void OpenGL3Logger::glDeleteTextures(GLsizei n, const GLuint *textures)
{
	output_path << "Called glDeleteTextures" << endl;
}

void OpenGL3Logger::glGenTextures(GLsizei n, GLuint *textures)
{
	output_path << "Called glGenTextures" << endl;
}

GLboolean OpenGL3Logger::glIsTexture(GLuint texture)
{
	output_path << "Called glIsTexture" << endl;
	return 0;
}

void OpenGL3Logger::glBlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
	output_path << "Called glBlendColor" << endl;
}

void OpenGL3Logger::glBlendEquation(GLenum mode)
{
	output_path << "Called glBlendEquation" << endl;
}

void OpenGL3Logger::glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices)
{
	output_path << "Called glDrawRangeElements" << endl;
}

void OpenGL3Logger::glTexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels)
{
	output_path << "Called glTexImage3D" << endl;
}

void OpenGL3Logger::glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels)
{
	output_path << "Called glTexSubImage3D" << endl;
}

void OpenGL3Logger::glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height)
{
	output_path << "Called glCopyTexSubImage3D" << endl;
}

void OpenGL3Logger::glActiveTexture(GLenum texture)
{
	output_path << "Called glActiveTexture" << endl;
}

void OpenGL3Logger::glSampleCoverage(GLclampf value, GLboolean invert)
{
	output_path << "Called glSampleCoverage" << endl;
}

void OpenGL3Logger::glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *data)
{
	output_path << "Called glCompressedTexImage3D" << endl;
}

void OpenGL3Logger::glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data)
{
	output_path << "Called glCompressedTexImage2D" << endl;
}

void OpenGL3Logger::glCompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data)
{
	output_path << "Called glCompressedTexImage1D" << endl;
}

void OpenGL3Logger::glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data)
{
	output_path << "Called glCompressedTexSubImage3D" << endl;
}

void OpenGL3Logger::glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data)
{
	output_path << "Called glCompressedTexSubImage2D" << endl;
}

void OpenGL3Logger::glCompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data)
{
	output_path << "Called glCompressedTexSubImage1D" << endl;
}

void OpenGL3Logger::glGetCompressedTexImage(GLenum target, GLint level, GLvoid *img)
{
	output_path << "Called glGetCompressedTexImage" << endl;
}

void OpenGL3Logger::glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha)
{
	output_path << "Called glBlendFuncSeparate" << endl;
}

void OpenGL3Logger::glMultiDrawArrays(GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount)
{
	output_path << "Called glMultiDrawArrays" << endl;
}

void OpenGL3Logger::glMultiDrawElements(GLenum mode, const GLsizei *count, GLenum type, const GLvoid* const *indices, GLsizei drawcount)
{
	output_path << "Called glMultiDrawElements" << endl;
}

void OpenGL3Logger::glPointParameterf(GLenum pname, GLfloat param)
{
	output_path << "Called glPointParameterf" << endl;
}

void OpenGL3Logger::glPointParameterfv(GLenum pname, const GLfloat *params)
{
	output_path << "Called glPointParameterfv" << endl;
}

void OpenGL3Logger::glPointParameteri(GLenum pname, GLint param)
{
	output_path << "Called glPointParameteri" << endl;
}

void OpenGL3Logger::glPointParameteriv(GLenum pname, const GLint *params)
{
	output_path << "Called glPointParameteriv" << endl;
}

void OpenGL3Logger::glGenQueries(GLsizei n, GLuint *ids)
{
	output_path << "Called glGenQueries" << endl;
}

void OpenGL3Logger::glDeleteQueries(GLsizei n, const GLuint *ids)
{
	output_path << "Called glDeleteQueries" << endl;
}

GLboolean OpenGL3Logger::glIsQuery(GLuint id)
{
	output_path << "Called glIsQuery" << endl;
	return 0;
}

void OpenGL3Logger::glBeginQuery(GLenum target, GLuint id)
{
	output_path << "Called glBeginQuery" << endl;
}

void OpenGL3Logger::glEndQuery(GLenum target)
{
	output_path << "Called glEndQuery" << endl;
}

void OpenGL3Logger::glGetQueryiv(GLenum target, GLenum pname, GLint *params)
{
	output_path << "Called glGetQueryiv" << endl;
}

void OpenGL3Logger::glGetQueryObjectiv(GLuint id, GLenum pname, GLint *params)
{
	output_path << "Called glGetQueryObjectiv" << endl;
}

void OpenGL3Logger::glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint *params)
{
	output_path << "Called glGetQueryObjectuiv" << endl;
}

void OpenGL3Logger::glBindBuffer(GLenum target, GLuint buffer)
{
	output_path << "Called glBindBuffer" << endl;
}

void OpenGL3Logger::glDeleteBuffers(GLsizei n, const GLuint *buffers)
{
	output_path << "Called glDeleteBuffers" << endl;
}

void OpenGL3Logger::glGenBuffers(GLsizei n, GLuint *buffers)
{
	output_path << "Called glGenBuffers" << endl;
}

GLboolean OpenGL3Logger::glIsBuffer(GLuint buffer)
{
	output_path << "Called glIsBuffer" << endl;
	return 0;
}

void OpenGL3Logger::glBufferData(GLenum target, GLsizeiptr size, const GLvoid *data, GLenum usage)
{
	output_path << "Called glBufferData" << endl;
}

void OpenGL3Logger::glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid *data)
{
	output_path << "Called glBufferSubData" << endl;
}

void OpenGL3Logger::glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid *data)
{
	output_path << "Called glGetBufferSubData" << endl;
}

GLvoid* OpenGL3Logger::glMapBuffer(GLenum target, GLenum access)
{
	output_path << "Called glMapBuffer" << endl;
	return nullptr;
}

GLboolean OpenGL3Logger::glUnmapBuffer(GLenum target)
{
	output_path << "Called glUnmapBuffer" << endl;
	return 0;
}

void OpenGL3Logger::glGetBufferParameteriv(GLenum target, GLenum pname, GLint *params)
{
	output_path << "Called glGetBufferParameteriv" << endl;
}

void OpenGL3Logger::glGetBufferPointerv(GLenum target, GLenum pname, GLvoid* *params)
{
	output_path << "Called glGetBufferPointerv" << endl;
}

void OpenGL3Logger::glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha)
{
	output_path << "Called glBlendEquationSeparate" << endl;
}

void OpenGL3Logger::glDrawBuffers(GLsizei n, const GLenum *bufs)
{
	output_path << "Called glDrawBuffers" << endl;
}

void OpenGL3Logger::glStencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass)
{
	output_path << "Called glStencilOpSeparate" << endl;
}

void OpenGL3Logger::glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask)
{
	output_path << "Called glStencilFuncSeparate" << endl;
}

void OpenGL3Logger::glStencilMaskSeparate(GLenum face, GLuint mask)
{
	output_path << "Called glStencilMaskSeparate" << endl;
}

void OpenGL3Logger::glAttachShader(GLuint program, GLuint shader)
{
	output_path << "Called glAttachShader" << endl;
}

void OpenGL3Logger::glBindAttribLocation(GLuint program, GLuint index, const GLchar *name)
{
	output_path << "Called glBindAttribLocation" << endl;
}

void OpenGL3Logger::glCompileShader(GLuint shader)
{
	output_path << "Called glCompileShader" << endl;
}

GLuint OpenGL3Logger::glCreateProgram(void)
{
	output_path << "Called glCreateProgram" << endl;
	return 0;
}

GLuint OpenGL3Logger::glCreateShader(GLenum type)
{
	output_path << "Called glCreateShader" << endl;
	return 0;
}

void OpenGL3Logger::glDeleteProgram(GLuint program)
{
	output_path << "Called glDeleteProgram" << endl;
}

void OpenGL3Logger::glDeleteShader(GLuint shader)
{
	output_path << "Called glDeleteShader" << endl;
}

void OpenGL3Logger::glDetachShader(GLuint program, GLuint shader)
{
	output_path << "Called glDetachShader" << endl;
}

void OpenGL3Logger::glDisableVertexAttribArray(GLuint index)
{
	output_path << "Called glDisableVertexAttribArray" << endl;
}

void OpenGL3Logger::glEnableVertexAttribArray(GLuint index)
{
	output_path << "Called glEnableVertexAttribArray" << endl;
}

void OpenGL3Logger::glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name)
{
	output_path << "Called glGetActiveAttrib" << endl;
}

void OpenGL3Logger::glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name)
{
	output_path << "Called glGetActiveUniform" << endl;
}

void OpenGL3Logger::glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders)
{
	output_path << "Called glGetAttachedShaders" << endl;
}

GLint OpenGL3Logger::glGetAttribLocation(GLuint program, const GLchar *name)
{
	output_path << "Called glGetAttribLocation" << endl;
	return 0;
}

void OpenGL3Logger::glGetProgramiv(GLuint program, GLenum pname, GLint *params)
{
	output_path << "Called glGetProgramiv" << endl;
}

void OpenGL3Logger::glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog)
{
	output_path << "Called glGetProgramInfoLog" << endl;
}

void OpenGL3Logger::glGetShaderiv(GLuint shader, GLenum pname, GLint *params)
{
	output_path << "Called glGetShaderiv" << endl;
}

void OpenGL3Logger::glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog)
{
	output_path << "Called glGetShaderInfoLog" << endl;
}

void OpenGL3Logger::glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source)
{
	output_path << "Called glGetShaderSource" << endl;
}

GLint OpenGL3Logger::glGetUniformLocation(GLuint program, const GLchar *name)
{
	output_path << "Called glGetUniformLocation" << endl;
	return 0;
}

void OpenGL3Logger::glGetUniformfv(GLuint program, GLint location, GLfloat *params)
{
	output_path << "Called glGetUniformfv" << endl;
}

void OpenGL3Logger::glGetUniformiv(GLuint program, GLint location, GLint *params)
{
	output_path << "Called glGetUniformiv" << endl;
}

void OpenGL3Logger::glGetVertexAttribdv(GLuint index, GLenum pname, GLdouble *params)
{
	output_path << "Called glGetVertexAttribdv" << endl;
}

void OpenGL3Logger::glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat *params)
{
	output_path << "Called glGetVertexAttribfv" << endl;
}

void OpenGL3Logger::glGetVertexAttribiv(GLuint index, GLenum pname, GLint *params)
{
	output_path << "Called glGetVertexAttribiv" << endl;
}

void OpenGL3Logger::glGetVertexAttribPointerv(GLuint index, GLenum pname, GLvoid* *pointer)
{
	output_path << "Called glGetVertexAttribPointerv" << endl;
}

GLboolean OpenGL3Logger::glIsProgram(GLuint program)
{
	output_path << "Called glIsProgram" << endl;
	return 0;
}

GLboolean OpenGL3Logger::glIsShader(GLuint shader)
{
	output_path << "Called glIsShader" << endl;
	return 0;
}

void OpenGL3Logger::glLinkProgram(GLuint program)
{
	output_path << "Called glLinkProgram" << endl;
}

void OpenGL3Logger::glShaderSource(GLuint shader, GLsizei count, const GLchar* const *string, const GLint *length)
{
	output_path << "Called glShaderSource" << endl;
}

void OpenGL3Logger::glUseProgram(GLuint program)
{
	output_path << "Called glUseProgram" << endl;
}

void OpenGL3Logger::glUniform1f(GLint location, GLfloat v0)
{
	output_path << "Called glUniform1f" << endl;
}

void OpenGL3Logger::glUniform2f(GLint location, GLfloat v0, GLfloat v1)
{
	output_path << "Called glUniform2f" << endl;
}

void OpenGL3Logger::glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2)
{
	output_path << "Called glUniform3f" << endl;
}

void OpenGL3Logger::glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3)
{
	output_path << "Called glUniform4f" << endl;
}

void OpenGL3Logger::glUniform1i(GLint location, GLint v0)
{
	output_path << "Called glUniform1i" << endl;
}

void OpenGL3Logger::glUniform2i(GLint location, GLint v0, GLint v1)
{
	output_path << "Called glUniform2i" << endl;
}

void OpenGL3Logger::glUniform3i(GLint location, GLint v0, GLint v1, GLint v2)
{
	output_path << "Called glUniform3i" << endl;
}

void OpenGL3Logger::glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3)
{
	output_path << "Called glUniform4i" << endl;
}

void OpenGL3Logger::glUniform1fv(GLint location, GLsizei count, const GLfloat *value)
{
	output_path << "Called glUniform1fv" << endl;
}

void OpenGL3Logger::glUniform2fv(GLint location, GLsizei count, const GLfloat *value)
{
	output_path << "Called glUniform2fv" << endl;
}

void OpenGL3Logger::glUniform3fv(GLint location, GLsizei count, const GLfloat *value)
{
	output_path << "Called glUniform3fv" << endl;
}

void OpenGL3Logger::glUniform4fv(GLint location, GLsizei count, const GLfloat *value)
{
	output_path << "Called glUniform4fv" << endl;
}

void OpenGL3Logger::glUniform1iv(GLint location, GLsizei count, const GLint *value)
{
	output_path << "Called glUniform1iv" << endl;
}

void OpenGL3Logger::glUniform2iv(GLint location, GLsizei count, const GLint *value)
{
	output_path << "Called glUniform2iv" << endl;
}

void OpenGL3Logger::glUniform3iv(GLint location, GLsizei count, const GLint *value)
{
	output_path << "Called glUniform3iv" << endl;
}

void OpenGL3Logger::glUniform4iv(GLint location, GLsizei count, const GLint *value)
{
	output_path << "Called glUniform4iv" << endl;
}

void OpenGL3Logger::glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	output_path << "Called glUniformMatrix2fv" << endl;
}

void OpenGL3Logger::glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	output_path << "Called glUniformMatrix3fv" << endl;
}

void OpenGL3Logger::glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	output_path << "Called glUniformMatrix4fv" << endl;
}

void OpenGL3Logger::glValidateProgram(GLuint program)
{
	output_path << "Called glValidateProgram" << endl;
}

void OpenGL3Logger::glVertexAttrib1d(GLuint index, GLdouble x)
{
	output_path << "Called glVertexAttrib1d" << endl;
}

void OpenGL3Logger::glVertexAttrib1dv(GLuint index, const GLdouble *v)
{
	output_path << "Called glVertexAttrib1dv" << endl;
}

void OpenGL3Logger::glVertexAttrib1f(GLuint index, GLfloat x)
{
	output_path << "Called glVertexAttrib1f" << endl;
}

void OpenGL3Logger::glVertexAttrib1fv(GLuint index, const GLfloat *v)
{
	output_path << "Called glVertexAttrib1fv" << endl;
}

void OpenGL3Logger::glVertexAttrib1s(GLuint index, GLshort x)
{
	output_path << "Called glVertexAttrib1s" << endl;
}

void OpenGL3Logger::glVertexAttrib1sv(GLuint index, const GLshort *v)
{
	output_path << "Called glVertexAttrib1sv" << endl;
}

void OpenGL3Logger::glVertexAttrib2d(GLuint index, GLdouble x, GLdouble y)
{
	output_path << "Called glVertexAttrib2d" << endl;
}

void OpenGL3Logger::glVertexAttrib2dv(GLuint index, const GLdouble *v)
{
	output_path << "Called glVertexAttrib2dv" << endl;
}

void OpenGL3Logger::glVertexAttrib2f(GLuint index, GLfloat x, GLfloat y)
{
	output_path << "Called glVertexAttrib2f" << endl;
}

void OpenGL3Logger::glVertexAttrib2fv(GLuint index, const GLfloat *v)
{
	output_path << "Called glVertexAttrib2fv" << endl;
}

void OpenGL3Logger::glVertexAttrib2s(GLuint index, GLshort x, GLshort y)
{
	output_path << "Called glVertexAttrib2s" << endl;
}

void OpenGL3Logger::glVertexAttrib2sv(GLuint index, const GLshort *v)
{
	output_path << "Called glVertexAttrib2sv" << endl;
}

void OpenGL3Logger::glVertexAttrib3d(GLuint index, GLdouble x, GLdouble y, GLdouble z)
{
	output_path << "Called glVertexAttrib3d" << endl;
}

void OpenGL3Logger::glVertexAttrib3dv(GLuint index, const GLdouble *v)
{
	output_path << "Called glVertexAttrib3dv" << endl;
}

void OpenGL3Logger::glVertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z)
{
	output_path << "Called glVertexAttrib3f" << endl;
}

void OpenGL3Logger::glVertexAttrib3fv(GLuint index, const GLfloat *v)
{
	output_path << "Called glVertexAttrib3fv" << endl;
}

void OpenGL3Logger::glVertexAttrib3s(GLuint index, GLshort x, GLshort y, GLshort z)
{
	output_path << "Called glVertexAttrib3s" << endl;
}

void OpenGL3Logger::glVertexAttrib3sv(GLuint index, const GLshort *v)
{
	output_path << "Called glVertexAttrib3sv" << endl;
}

void OpenGL3Logger::glVertexAttrib4Nbv(GLuint index, const GLbyte *v)
{
	output_path << "Called glVertexAttrib4Nbv" << endl;
}

void OpenGL3Logger::glVertexAttrib4Niv(GLuint index, const GLint *v)
{
	output_path << "Called glVertexAttrib4Niv" << endl;
}

void OpenGL3Logger::glVertexAttrib4Nsv(GLuint index, const GLshort *v)
{
	output_path << "Called glVertexAttrib4Nsv" << endl;
}

void OpenGL3Logger::glVertexAttrib4Nub(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w)
{
	output_path << "Called glVertexAttrib4Nub" << endl;
}

void OpenGL3Logger::glVertexAttrib4Nubv(GLuint index, const GLubyte *v)
{
	output_path << "Called glVertexAttrib4Nubv" << endl;
}

void OpenGL3Logger::glVertexAttrib4Nuiv(GLuint index, const GLuint *v)
{
	output_path << "Called glVertexAttrib4Nuiv" << endl;
}

void OpenGL3Logger::glVertexAttrib4Nusv(GLuint index, const GLushort *v)
{
	output_path << "Called glVertexAttrib4Nusv" << endl;
}

void OpenGL3Logger::glVertexAttrib4bv(GLuint index, const GLbyte *v)
{
	output_path << "Called glVertexAttrib4bv" << endl;
}

void OpenGL3Logger::glVertexAttrib4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w)
{
	output_path << "Called glVertexAttrib4d" << endl;
}

void OpenGL3Logger::glVertexAttrib4dv(GLuint index, const GLdouble *v)
{
	output_path << "Called glVertexAttrib4dv" << endl;
}

void OpenGL3Logger::glVertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
	output_path << "Called glVertexAttrib4f" << endl;
}

void OpenGL3Logger::glVertexAttrib4fv(GLuint index, const GLfloat *v)
{
	output_path << "Called glVertexAttrib4fv" << endl;
}

void OpenGL3Logger::glVertexAttrib4iv(GLuint index, const GLint *v)
{
	output_path << "Called glVertexAttrib4iv" << endl;
}

void OpenGL3Logger::glVertexAttrib4s(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w)
{
	output_path << "Called glVertexAttrib4s" << endl;
}

void OpenGL3Logger::glVertexAttrib4sv(GLuint index, const GLshort *v)
{
	output_path << "Called glVertexAttrib4sv" << endl;
}

void OpenGL3Logger::glVertexAttrib4ubv(GLuint index, const GLubyte *v)
{
	output_path << "Called glVertexAttrib4ubv" << endl;
}

void OpenGL3Logger::glVertexAttrib4uiv(GLuint index, const GLuint *v)
{
	output_path << "Called glVertexAttrib4uiv" << endl;
}

void OpenGL3Logger::glVertexAttrib4usv(GLuint index, const GLushort *v)
{
	output_path << "Called glVertexAttrib4usv" << endl;
}

void OpenGL3Logger::glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid *pointer)
{
	output_path << "Called glVertexAttribPointer" << endl;
}

void OpenGL3Logger::glUniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	output_path << "Called glUniformMatrix2x3fv" << endl;
}

void OpenGL3Logger::glUniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	output_path << "Called glUniformMatrix3x2fv" << endl;
}

void OpenGL3Logger::glUniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	output_path << "Called glUniformMatrix2x4fv" << endl;
}

void OpenGL3Logger::glUniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	output_path << "Called glUniformMatrix4x2fv" << endl;
}

void OpenGL3Logger::glUniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	output_path << "Called glUniformMatrix3x4fv" << endl;
}

void OpenGL3Logger::glUniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	output_path << "Called glUniformMatrix4x3fv" << endl;
}

void OpenGL3Logger::glColorMaski(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a)
{
	output_path << "Called glColorMaski" << endl;
}

void OpenGL3Logger::glGetBooleani_v(GLenum target, GLuint index, GLboolean *data)
{
	output_path << "Called glGetBooleani_v" << endl;
}

void OpenGL3Logger::glGetIntegeri_v(GLenum target, GLuint index, GLint *data)
{
	output_path << "Called glGetIntegeri_v" << endl;
}

void OpenGL3Logger::glEnablei(GLenum target, GLuint index)
{
	output_path << "Called glEnablei" << endl;
}

void OpenGL3Logger::glDisablei(GLenum target, GLuint index)
{
	output_path << "Called glDisablei" << endl;
}

GLboolean OpenGL3Logger::glIsEnabledi(GLenum target, GLuint index)
{
	output_path << "Called glIsEnabledi" << endl;
	return 0;
}

void OpenGL3Logger::glBeginTransformFeedback(GLenum primitiveMode)
{
	output_path << "Called glBeginTransformFeedback" << endl;
}

void OpenGL3Logger::glEndTransformFeedback(void)
{
	output_path << "Called glEndTransformFeedback" << endl;
}

void OpenGL3Logger::glBindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size)
{
	output_path << "Called glBindBufferRange" << endl;
}

void OpenGL3Logger::glBindBufferBase(GLenum target, GLuint index, GLuint buffer)
{
	output_path << "Called glBindBufferBase" << endl;
}

void OpenGL3Logger::glTransformFeedbackVaryings(GLuint program, GLsizei count, const GLchar* const *varyings, GLenum bufferMode)
{
	output_path << "Called glTransformFeedbackVaryings" << endl;
}

void OpenGL3Logger::glGetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name)
{
	output_path << "Called glGetTransformFeedbackVarying" << endl;
}

void OpenGL3Logger::glClampColor(GLenum target, GLenum clamp)
{
	output_path << "Called glClampColor" << endl;
}

void OpenGL3Logger::glBeginConditionalRender(GLuint id, GLenum mode)
{
	output_path << "Called glBeginConditionalRender" << endl;
}

void OpenGL3Logger::glEndConditionalRender(void)
{
	output_path << "Called glEndConditionalRender" << endl;
}

void OpenGL3Logger::glVertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)
{
	output_path << "Called glVertexAttribIPointer" << endl;
}

void OpenGL3Logger::glGetVertexAttribIiv(GLuint index, GLenum pname, GLint *params)
{
	output_path << "Called glGetVertexAttribIiv" << endl;
}

void OpenGL3Logger::glGetVertexAttribIuiv(GLuint index, GLenum pname, GLuint *params)
{
	output_path << "Called glGetVertexAttribIuiv" << endl;
}

void OpenGL3Logger::glVertexAttribI1i(GLuint index, GLint x)
{
	output_path << "Called glVertexAttribI1i" << endl;
}

void OpenGL3Logger::glVertexAttribI2i(GLuint index, GLint x, GLint y)
{
	output_path << "Called glVertexAttribI2i" << endl;
}

void OpenGL3Logger::glVertexAttribI3i(GLuint index, GLint x, GLint y, GLint z)
{
	output_path << "Called glVertexAttribI3i" << endl;
}

void OpenGL3Logger::glVertexAttribI4i(GLuint index, GLint x, GLint y, GLint z, GLint w)
{
	output_path << "Called glVertexAttribI4i" << endl;
}

void OpenGL3Logger::glVertexAttribI1ui(GLuint index, GLuint x)
{
	output_path << "Called glVertexAttribI1ui" << endl;
}

void OpenGL3Logger::glVertexAttribI2ui(GLuint index, GLuint x, GLuint y)
{
	output_path << "Called glVertexAttribI2ui" << endl;
}

void OpenGL3Logger::glVertexAttribI3ui(GLuint index, GLuint x, GLuint y, GLuint z)
{
	output_path << "Called glVertexAttribI3ui" << endl;
}

void OpenGL3Logger::glVertexAttribI4ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w)
{
	output_path << "Called glVertexAttribI4ui" << endl;
}

void OpenGL3Logger::glVertexAttribI1iv(GLuint index, const GLint *v)
{
	output_path << "Called glVertexAttribI1iv" << endl;
}

void OpenGL3Logger::glVertexAttribI2iv(GLuint index, const GLint *v)
{
	output_path << "Called glVertexAttribI2iv" << endl;
}

void OpenGL3Logger::glVertexAttribI3iv(GLuint index, const GLint *v)
{
	output_path << "Called glVertexAttribI3iv" << endl;
}

void OpenGL3Logger::glVertexAttribI4iv(GLuint index, const GLint *v)
{
	output_path << "Called glVertexAttribI4iv" << endl;
}

void OpenGL3Logger::glVertexAttribI1uiv(GLuint index, const GLuint *v)
{
	output_path << "Called glVertexAttribI1uiv" << endl;
}

void OpenGL3Logger::glVertexAttribI2uiv(GLuint index, const GLuint *v)
{
	output_path << "Called glVertexAttribI2uiv" << endl;
}

void OpenGL3Logger::glVertexAttribI3uiv(GLuint index, const GLuint *v)
{
	output_path << "Called glVertexAttribI3uiv" << endl;
}

void OpenGL3Logger::glVertexAttribI4uiv(GLuint index, const GLuint *v)
{
	output_path << "Called glVertexAttribI4uiv" << endl;
}

void OpenGL3Logger::glVertexAttribI4bv(GLuint index, const GLbyte *v)
{
	output_path << "Called glVertexAttribI4bv" << endl;
}

void OpenGL3Logger::glVertexAttribI4sv(GLuint index, const GLshort *v)
{
	output_path << "Called glVertexAttribI4sv" << endl;
}

void OpenGL3Logger::glVertexAttribI4ubv(GLuint index, const GLubyte *v)
{
	output_path << "Called glVertexAttribI4ubv" << endl;
}

void OpenGL3Logger::glVertexAttribI4usv(GLuint index, const GLushort *v)
{
	output_path << "Called glVertexAttribI4usv" << endl;
}

void OpenGL3Logger::glGetUniformuiv(GLuint program, GLint location, GLuint *params)
{
	output_path << "Called glGetUniformuiv" << endl;
}

void OpenGL3Logger::glBindFragDataLocation(GLuint program, GLuint color, const GLchar *name)
{
	output_path << "Called glBindFragDataLocation" << endl;
}

GLint OpenGL3Logger::glGetFragDataLocation(GLuint program, const GLchar *name)
{
	output_path << "Called glGetFragDataLocation" << endl;
	return 0;
}

void OpenGL3Logger::glUniform1ui(GLint location, GLuint v0)
{
	output_path << "Called glUniform1ui" << endl;
}

void OpenGL3Logger::glUniform2ui(GLint location, GLuint v0, GLuint v1)
{
	output_path << "Called glUniform2ui" << endl;
}

void OpenGL3Logger::glUniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2)
{
	output_path << "Called glUniform3ui" << endl;
}

void OpenGL3Logger::glUniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3)
{
	output_path << "Called glUniform4ui" << endl;
}

void OpenGL3Logger::glUniform1uiv(GLint location, GLsizei count, const GLuint *value)
{
	output_path << "Called glUniform1uiv" << endl;
}

void OpenGL3Logger::glUniform2uiv(GLint location, GLsizei count, const GLuint *value)
{
	output_path << "Called glUniform2uiv" << endl;
}

void OpenGL3Logger::glUniform3uiv(GLint location, GLsizei count, const GLuint *value)
{
	output_path << "Called glUniform3uiv" << endl;
}

void OpenGL3Logger::glUniform4uiv(GLint location, GLsizei count, const GLuint *value)
{
	output_path << "Called glUniform4uiv" << endl;
}

void OpenGL3Logger::glTexParameterIiv(GLenum target, GLenum pname, const GLint *params)
{
	output_path << "Called glTexParameterIiv" << endl;
}

void OpenGL3Logger::glTexParameterIuiv(GLenum target, GLenum pname, const GLuint *params)
{
	output_path << "Called glTexParameterIuiv" << endl;
}

void OpenGL3Logger::glGetTexParameterIiv(GLenum target, GLenum pname, GLint *params)
{
	output_path << "Called glGetTexParameterIiv" << endl;
}

void OpenGL3Logger::glGetTexParameterIuiv(GLenum target, GLenum pname, GLuint *params)
{
	output_path << "Called glGetTexParameterIuiv" << endl;
}

void OpenGL3Logger::glClearBufferiv(GLenum buffer, GLint drawbuffer, const GLint *value)
{
	output_path << "Called glClearBufferiv" << endl;
}

void OpenGL3Logger::glClearBufferuiv(GLenum buffer, GLint drawbuffer, const GLuint *value)
{
	output_path << "Called glClearBufferuiv" << endl;
}

void OpenGL3Logger::glClearBufferfv(GLenum buffer, GLint drawbuffer, const GLfloat *value)
{
	output_path << "Called glClearBufferfv" << endl;
}

void OpenGL3Logger::glClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil)
{
	output_path << "Called glClearBufferfi" << endl;
}

const GLubyte * OpenGL3Logger::glGetStringi(GLenum name, GLuint index)
{
	output_path << "Called glGetStringi" << endl;
	return nullptr;
}

void OpenGL3Logger::glDrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei instancecount)
{
	output_path << "Called glDrawArraysInstanced" << endl;
}

void OpenGL3Logger::glDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLsizei instancecount)
{
	output_path << "Called glDrawElementsInstanced" << endl;
}

void OpenGL3Logger::glTexBuffer(GLenum target, GLenum internalformat, GLuint buffer)
{
	output_path << "Called glTexBuffer" << endl;
}

void OpenGL3Logger::glPrimitiveRestartIndex(GLuint index)
{
	output_path << "Called glPrimitiveRestartIndex" << endl;
}

void OpenGL3Logger::glGetInteger64i_v(GLenum target, GLuint index, GLint64 *data)
{
	output_path << "Called glGetInteger64i_v" << endl;
}

void OpenGL3Logger::glGetBufferParameteri64v(GLenum target, GLenum pname, GLint64 *params)
{
	output_path << "Called glGetBufferParameteri64v" << endl;
}

void OpenGL3Logger::glFramebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level)
{
	output_path << "Called glFramebufferTexture" << endl;
}

void OpenGL3Logger::glVertexAttribDivisor(GLuint index, GLuint divisor)
{
	output_path << "Called glVertexAttribDivisor" << endl;
}

void OpenGL3Logger::glMinSampleShading(GLfloat value)
{
	output_path << "Called glMinSampleShading" << endl;
}

void OpenGL3Logger::glBlendEquationi(GLuint buf, GLenum mode)
{
	output_path << "Called glBlendEquationi" << endl;
}

void OpenGL3Logger::glBlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha)
{
	output_path << "Called glBlendEquationSeparatei" << endl;
}

void OpenGL3Logger::glBlendFunci(GLuint buf, GLenum src, GLenum dst)
{
	output_path << "Called glBlendFunci" << endl;
}

void OpenGL3Logger::glBlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha)
{
	output_path << "Called glBlendFuncSeparatei" << endl;
}

GLboolean OpenGL3Logger::glIsRenderbuffer(GLuint renderbuffer)
{
	output_path << "Called glIsRenderbuffer" << endl;
	return 0;
}

void OpenGL3Logger::glBindRenderbuffer(GLenum target, GLuint renderbuffer)
{
	output_path << "Called glBindRenderbuffer" << endl;
}

void OpenGL3Logger::glDeleteRenderbuffers(GLsizei n, const GLuint *renderbuffers)
{
	output_path << "Called glDeleteRenderbuffers" << endl;
}

void OpenGL3Logger::glGenRenderbuffers(GLsizei n, GLuint *renderbuffers)
{
	output_path << "Called glGenRenderbuffers" << endl;
}

void OpenGL3Logger::glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height)
{
	output_path << "Called glRenderbufferStorage" << endl;
}

void OpenGL3Logger::glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint *params)
{
	output_path << "Called glGetRenderbufferParameteriv" << endl;
}

GLboolean OpenGL3Logger::glIsFramebuffer(GLuint framebuffer)
{
	output_path << "Called glIsFramebuffer" << endl;
	return 0;
}

void OpenGL3Logger::glBindFramebuffer(GLenum target, GLuint framebuffer)
{
	output_path << "Called glBindFramebuffer" << endl;
}

void OpenGL3Logger::glDeleteFramebuffers(GLsizei n, const GLuint *framebuffers)
{
	output_path << "Called glDeleteFramebuffers" << endl;
}

void OpenGL3Logger::glGenFramebuffers(GLsizei n, GLuint *framebuffers)
{
	output_path << "Called glGenFramebuffers" << endl;
}

GLenum OpenGL3Logger::glCheckFramebufferStatus(GLenum target)
{
	output_path << "Called glCheckFramebufferStatus" << endl;
	return 0;
}

void OpenGL3Logger::glFramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)
{
	output_path << "Called glFramebufferTexture1D" << endl;
}

void OpenGL3Logger::glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)
{
	output_path << "Called glFramebufferTexture2D" << endl;
}

void OpenGL3Logger::glFramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset)
{
	output_path << "Called glFramebufferTexture3D" << endl;
}

void OpenGL3Logger::glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer)
{
	output_path << "Called glFramebufferRenderbuffer" << endl;
}

void OpenGL3Logger::glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint *params)
{
	output_path << "Called glGetFramebufferAttachmentParameteriv" << endl;
}

void OpenGL3Logger::glGenerateMipmap(GLenum target)
{
	output_path << "Called glGenerateMipmap" << endl;
}

void OpenGL3Logger::glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter)
{
	output_path << "Called glBlitFramebuffer" << endl;
}

void OpenGL3Logger::glRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height)
{
	output_path << "Called glRenderbufferStorageMultisample" << endl;
}

void OpenGL3Logger::glFramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer)
{
	output_path << "Called glFramebufferTextureLayer" << endl;
}

GLvoid* OpenGL3Logger::glMapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access)
{
	output_path << "Called glMapBufferRange" << endl;
	return nullptr;
}

void OpenGL3Logger::glFlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length)
{
	output_path << "Called glFlushMappedBufferRange" << endl;
}

void OpenGL3Logger::glBindVertexArray(GLuint array)
{
	output_path << "Called glBindVertexArray" << endl;
}

void OpenGL3Logger::glDeleteVertexArrays(GLsizei n, const GLuint *arrays)
{
	output_path << "Called glDeleteVertexArrays" << endl;
}

void OpenGL3Logger::glGenVertexArrays(GLsizei n, GLuint *arrays)
{
	output_path << "Called glGenVertexArrays" << endl;
}

GLboolean OpenGL3Logger::glIsVertexArray(GLuint array)
{
	output_path << "Called glIsVertexArray" << endl;
	return 0;
}

void OpenGL3Logger::glGetUniformIndices(GLuint program, GLsizei uniformCount, const GLchar* const *uniformNames, GLuint *uniformIndices)
{
	output_path << "Called glGetUniformIndices" << endl;
}

void OpenGL3Logger::glGetActiveUniformsiv(GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params)
{
	output_path << "Called glGetActiveUniformsiv" << endl;
}

void OpenGL3Logger::glGetActiveUniformName(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName)
{
	output_path << "Called glGetActiveUniformName" << endl;
}

GLuint OpenGL3Logger::glGetUniformBlockIndex(GLuint program, const GLchar *uniformBlockName)
{
	output_path << "Called glGetUniformBlockIndex" << endl;
	return 0;
}

void OpenGL3Logger::glGetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params)
{
	output_path << "Called glGetActiveUniformBlockiv" << endl;
}

void OpenGL3Logger::glGetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName)
{
	output_path << "Called glGetActiveUniformBlockName" << endl;
}

void OpenGL3Logger::glUniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding)
{
	output_path << "Called glUniformBlockBinding" << endl;
}

void OpenGL3Logger::glCopyBufferSubData(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size)
{
	output_path << "Called glCopyBufferSubData" << endl;
}

void OpenGL3Logger::glDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLint basevertex)
{
	output_path << "Called glDrawElementsBaseVertex" << endl;
}

void OpenGL3Logger::glDrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices, GLint basevertex)
{
	output_path << "Called glDrawRangeElementsBaseVertex" << endl;
}

void OpenGL3Logger::glDrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLsizei instancecount, GLint basevertex)
{
	output_path << "Called glDrawElementsInstancedBaseVertex" << endl;
}

void OpenGL3Logger::glMultiDrawElementsBaseVertex(GLenum mode, const GLsizei *count, GLenum type, const GLvoid* const *indices, GLsizei drawcount, const GLint *basevertex)
{
	output_path << "Called glMultiDrawElementsBaseVertex" << endl;
}

void OpenGL3Logger::glProvokingVertex(GLenum mode)
{
	output_path << "Called glProvokingVertex" << endl;
}

GLsync OpenGL3Logger::glFenceSync(GLenum condition, GLbitfield flags)
{
	output_path << "Called glFenceSync" << endl;
	return 0;
}

GLboolean OpenGL3Logger::glIsSync(GLsync sync)
{
	output_path << "Called glIsSync" << endl;
	return 0;
}

void OpenGL3Logger::glDeleteSync(GLsync sync)
{
	output_path << "Called glDeleteSync" << endl;
}

GLenum OpenGL3Logger::glClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout)
{
	output_path << "Called glClientWaitSync" << endl;
	return 0;
}

void OpenGL3Logger::glWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout)
{
	output_path << "Called glWaitSync" << endl;
}

void OpenGL3Logger::glGetInteger64v(GLenum pname, GLint64 *params)
{
	output_path << "Called glGetInteger64v" << endl;
}

void OpenGL3Logger::glGetSynciv(GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values)
{
	output_path << "Called glGetSynciv" << endl;
}

void OpenGL3Logger::glTexImage2DMultisample(GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations)
{
	output_path << "Called glTexImage2DMultisample" << endl;
}

void OpenGL3Logger::glTexImage3DMultisample(GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations)
{
	output_path << "Called glTexImage3DMultisample" << endl;
}

void OpenGL3Logger::glGetMultisamplefv(GLenum pname, GLuint index, GLfloat *val)
{
	output_path << "Called glGetMultisamplefv" << endl;
}

void OpenGL3Logger::glSampleMaski(GLuint index, GLbitfield mask)
{
	output_path << "Called glSampleMaski" << endl;
}

void OpenGL3Logger::glBindFragDataLocationIndexed(GLuint program, GLuint colorNumber, GLuint index, const GLchar *name)
{
	output_path << "Called glBindFragDataLocationIndexed" << endl;
}

GLint OpenGL3Logger::glGetFragDataIndex(GLuint program, const GLchar *name)
{
	output_path << "Called glGetFragDataIndex" << endl;
	return 0;
}

void OpenGL3Logger::glGenSamplers(GLsizei count, GLuint *samplers)
{
	output_path << "Called glGenSamplers" << endl;
}

void OpenGL3Logger::glDeleteSamplers(GLsizei count, const GLuint *samplers)
{
	output_path << "Called glDeleteSamplers" << endl;
}

GLboolean OpenGL3Logger::glIsSampler(GLuint sampler)
{
	output_path << "Called glIsSampler" << endl;
	return 0;
}

void OpenGL3Logger::glBindSampler(GLuint unit, GLuint sampler)
{
	output_path << "Called glBindSampler" << endl;
}

void OpenGL3Logger::glSamplerParameteri(GLuint sampler, GLenum pname, GLint param)
{
	output_path << "Called glSamplerParameteri" << endl;
}

void OpenGL3Logger::glSamplerParameteriv(GLuint sampler, GLenum pname, const GLint *param)
{
	output_path << "Called glSamplerParameteriv" << endl;
}

void OpenGL3Logger::glSamplerParameterf(GLuint sampler, GLenum pname, GLfloat param)
{
	output_path << "Called glSamplerParameterf" << endl;
}

void OpenGL3Logger::glSamplerParameterfv(GLuint sampler, GLenum pname, const GLfloat *param)
{
	output_path << "Called glSamplerParameterfv" << endl;
}

void OpenGL3Logger::glSamplerParameterIiv(GLuint sampler, GLenum pname, const GLint *param)
{
	output_path << "Called glSamplerParameterIiv" << endl;
}

void OpenGL3Logger::glSamplerParameterIuiv(GLuint sampler, GLenum pname, const GLuint *param)
{
	output_path << "Called glSamplerParameterIuiv" << endl;
}

void OpenGL3Logger::glGetSamplerParameteriv(GLuint sampler, GLenum pname, GLint *params)
{
	output_path << "Called glGetSamplerParameteriv" << endl;
}

void OpenGL3Logger::glGetSamplerParameterIiv(GLuint sampler, GLenum pname, GLint *params)
{
	output_path << "Called glGetSamplerParameterIiv" << endl;
}

void OpenGL3Logger::glGetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat *params)
{
	output_path << "Called glGetSamplerParameterfv" << endl;
}

void OpenGL3Logger::glGetSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint *params)
{
	output_path << "Called glGetSamplerParameterIuiv" << endl;
}

void OpenGL3Logger::glQueryCounter(GLuint id, GLenum target)
{
	output_path << "Called glQueryCounter" << endl;
}

void OpenGL3Logger::glGetQueryObjecti64v(GLuint id, GLenum pname, GLint64 *params)
{
	output_path << "Called glGetQueryObjecti64v" << endl;
}

void OpenGL3Logger::glGetQueryObjectui64v(GLuint id, GLenum pname, GLuint64 *params)
{
	output_path << "Called glGetQueryObjectui64v" << endl;
}

void OpenGL3Logger::glVertexAttribP1ui(GLuint index, GLenum type, GLboolean normalized, GLuint value)
{
	output_path << "Called glVertexAttribP1ui" << endl;
}

void OpenGL3Logger::glVertexAttribP1uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint *value)
{
	output_path << "Called glVertexAttribP1uiv" << endl;
}

void OpenGL3Logger::glVertexAttribP2ui(GLuint index, GLenum type, GLboolean normalized, GLuint value)
{
	output_path << "Called glVertexAttribP2ui" << endl;
}

void OpenGL3Logger::glVertexAttribP2uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint *value)
{
	output_path << "Called glVertexAttribP2uiv" << endl;
}

void OpenGL3Logger::glVertexAttribP3ui(GLuint index, GLenum type, GLboolean normalized, GLuint value)
{
	output_path << "Called glVertexAttribP3ui" << endl;
}

void OpenGL3Logger::glVertexAttribP3uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint *value)
{
	output_path << "Called glVertexAttribP3uiv" << endl;
}

void OpenGL3Logger::glVertexAttribP4ui(GLuint index, GLenum type, GLboolean normalized, GLuint value)
{
	output_path << "Called glVertexAttribP4ui" << endl;
}

void OpenGL3Logger::glVertexAttribP4uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint *value)
{
	output_path << "Called glVertexAttribP4uiv" << endl;
}

void OpenGL3Logger::glDrawArraysIndirect(GLenum mode, const GLvoid *indirect)
{
	output_path << "Called glDrawArraysIndirect" << endl;
}

void OpenGL3Logger::glDrawElementsIndirect(GLenum mode, GLenum type, const GLvoid *indirect)
{
	output_path << "Called glDrawElementsIndirect" << endl;
}

void OpenGL3Logger::glUniform1d(GLint location, GLdouble x)
{
	output_path << "Called glUniform1d" << endl;
}

void OpenGL3Logger::glUniform2d(GLint location, GLdouble x, GLdouble y)
{
	output_path << "Called glUniform2d" << endl;
}

void OpenGL3Logger::glUniform3d(GLint location, GLdouble x, GLdouble y, GLdouble z)
{
	output_path << "Called glUniform3d" << endl;
}

void OpenGL3Logger::glUniform4d(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w)
{
	output_path << "Called glUniform4d" << endl;
}

void OpenGL3Logger::glUniform1dv(GLint location, GLsizei count, const GLdouble *value)
{
	output_path << "Called glUniform1dv" << endl;
}

void OpenGL3Logger::glUniform2dv(GLint location, GLsizei count, const GLdouble *value)
{
	output_path << "Called glUniform2dv" << endl;
}

void OpenGL3Logger::glUniform3dv(GLint location, GLsizei count, const GLdouble *value)
{
	output_path << "Called glUniform3dv" << endl;
}

void OpenGL3Logger::glUniform4dv(GLint location, GLsizei count, const GLdouble *value)
{
	output_path << "Called glUniform4dv" << endl;
}

void OpenGL3Logger::glUniformMatrix2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
{
	output_path << "Called glUniformMatrix2dv" << endl;
}

void OpenGL3Logger::glUniformMatrix3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
{
	output_path << "Called glUniformMatrix3dv" << endl;
}

void OpenGL3Logger::glUniformMatrix4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
{
	output_path << "Called glUniformMatrix4dv" << endl;
}

void OpenGL3Logger::glUniformMatrix2x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
{
	output_path << "Called glUniformMatrix2x3dv" << endl;
}

void OpenGL3Logger::glUniformMatrix2x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
{
	output_path << "Called glUniformMatrix2x4dv" << endl;
}

void OpenGL3Logger::glUniformMatrix3x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
{
	output_path << "Called glUniformMatrix3x2dv" << endl;
}

void OpenGL3Logger::glUniformMatrix3x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
{
	output_path << "Called glUniformMatrix3x4dv" << endl;
}

void OpenGL3Logger::glUniformMatrix4x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
{
	output_path << "Called glUniformMatrix4x2dv" << endl;
}

void OpenGL3Logger::glUniformMatrix4x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
{
	output_path << "Called glUniformMatrix4x3dv" << endl;
}

void OpenGL3Logger::glGetUniformdv(GLuint program, GLint location, GLdouble *params)
{
	output_path << "Called glGetUniformdv" << endl;
}

GLint OpenGL3Logger::glGetSubroutineUniformLocation(GLuint program, GLenum shadertype, const GLchar *name)
{
	output_path << "Called glGetSubroutineUniformLocation" << endl;
	return 0;
}

GLuint OpenGL3Logger::glGetSubroutineIndex(GLuint program, GLenum shadertype, const GLchar *name)
{
	output_path << "Called glGetSubroutineIndex" << endl;
	return 0;
}

void OpenGL3Logger::glGetActiveSubroutineUniformiv(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint *values)
{
	output_path << "Called glGetActiveSubroutineUniformiv" << endl;
}

void OpenGL3Logger::glGetActiveSubroutineUniformName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name)
{
	output_path << "Called glGetActiveSubroutineUniformName" << endl;
}

void OpenGL3Logger::glGetActiveSubroutineName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name)
{
	output_path << "Called glGetActiveSubroutineName" << endl;
}

void OpenGL3Logger::glUniformSubroutinesuiv(GLenum shadertype, GLsizei count, const GLuint *indices)
{
	output_path << "Called glUniformSubroutinesuiv" << endl;
}

void OpenGL3Logger::glGetUniformSubroutineuiv(GLenum shadertype, GLint location, GLuint *params)
{
	output_path << "Called glGetUniformSubroutineuiv" << endl;
}

void OpenGL3Logger::glGetProgramStageiv(GLuint program, GLenum shadertype, GLenum pname, GLint *values)
{
	output_path << "Called glGetProgramStageiv" << endl;
}

void OpenGL3Logger::glPatchParameteri(GLenum pname, GLint value)
{
	output_path << "Called glPatchParameteri" << endl;
}

void OpenGL3Logger::glPatchParameterfv(GLenum pname, const GLfloat *values)
{
	output_path << "Called glPatchParameterfv" << endl;
}

void OpenGL3Logger::glBindTransformFeedback(GLenum target, GLuint id)
{
	output_path << "Called glBindTransformFeedback" << endl;
}

void OpenGL3Logger::glDeleteTransformFeedbacks(GLsizei n, const GLuint *ids)
{
	output_path << "Called glDeleteTransformFeedbacks" << endl;
}

void OpenGL3Logger::glGenTransformFeedbacks(GLsizei n, GLuint *ids)
{
	output_path << "Called glGenTransformFeedbacks" << endl;
}

GLboolean OpenGL3Logger::glIsTransformFeedback(GLuint id)
{
	output_path << "Called glIsTransformFeedback" << endl;
	return 0;
}

void OpenGL3Logger::glPauseTransformFeedback(void)
{
	output_path << "Called glPauseTransformFeedback" << endl;
}

void OpenGL3Logger::glResumeTransformFeedback(void)
{
	output_path << "Called glResumeTransformFeedback" << endl;
}

void OpenGL3Logger::glDrawTransformFeedback(GLenum mode, GLuint id)
{
	output_path << "Called glDrawTransformFeedback" << endl;
}

void OpenGL3Logger::glDrawTransformFeedbackStream(GLenum mode, GLuint id, GLuint stream)
{
	output_path << "Called glDrawTransformFeedbackStream" << endl;
}

void OpenGL3Logger::glBeginQueryIndexed(GLenum target, GLuint index, GLuint id)
{
	output_path << "Called glBeginQueryIndexed" << endl;
}

void OpenGL3Logger::glEndQueryIndexed(GLenum target, GLuint index)
{
	output_path << "Called glEndQueryIndexed" << endl;
}

void OpenGL3Logger::glGetQueryIndexediv(GLenum target, GLuint index, GLenum pname, GLint *params)
{
	output_path << "Called glGetQueryIndexediv" << endl;
}

void OpenGL3Logger::glReleaseShaderCompiler(void)
{
	output_path << "Called glReleaseShaderCompiler" << endl;
}

void OpenGL3Logger::glShaderBinary(GLsizei count, const GLuint *shaders, GLenum binaryformat, const GLvoid *binary, GLsizei length)
{
	output_path << "Called glShaderBinary" << endl;
}

void OpenGL3Logger::glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision)
{
	output_path << "Called glGetShaderPrecisionFormat" << endl;
}

void OpenGL3Logger::glDepthRangef(GLclampf n, GLclampf f)
{
	output_path << "Called glDepthRangef" << endl;
}

void OpenGL3Logger::glClearDepthf(GLclampf d)
{
	output_path << "Called glClearDepthf" << endl;
}

void OpenGL3Logger::glGetProgramBinary(GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, GLvoid *binary)
{
	output_path << "Called glGetProgramBinary" << endl;
}

void OpenGL3Logger::glProgramBinary(GLuint program, GLenum binaryFormat, const GLvoid *binary, GLsizei length)
{
	output_path << "Called glProgramBinary" << endl;
}

void OpenGL3Logger::glProgramParameteri(GLuint program, GLenum pname, GLint value)
{
	output_path << "Called glProgramParameteri" << endl;
}

void OpenGL3Logger::glUseProgramStages(GLuint pipeline, GLbitfield stages, GLuint program)
{
	output_path << "Called glUseProgramStages" << endl;
}

void OpenGL3Logger::glActiveShaderProgram(GLuint pipeline, GLuint program)
{
	output_path << "Called glActiveShaderProgram" << endl;
}

GLuint OpenGL3Logger::glCreateShaderProgramv(GLenum type, GLsizei count, const GLchar* const *strings)
{
	output_path << "Called glCreateShaderProgramv" << endl;
	return 0;
}

void OpenGL3Logger::glBindProgramPipeline(GLuint pipeline)
{
	output_path << "Called glBindProgramPipeline" << endl;
}

void OpenGL3Logger::glDeleteProgramPipelines(GLsizei n, const GLuint *pipelines)
{
	output_path << "Called glDeleteProgramPipelines" << endl;
}

void OpenGL3Logger::glGenProgramPipelines(GLsizei n, GLuint *pipelines)
{
	output_path << "Called glGenProgramPipelines" << endl;
}

GLboolean OpenGL3Logger::glIsProgramPipeline(GLuint pipeline)
{
	output_path << "Called glIsProgramPipeline" << endl;
	return 0;
}

void OpenGL3Logger::glGetProgramPipelineiv(GLuint pipeline, GLenum pname, GLint *params)
{
	output_path << "Called glGetProgramPipelineiv" << endl;
}

void OpenGL3Logger::glProgramUniform1i(GLuint program, GLint location, GLint v0)
{
	output_path << "Called glProgramUniform1i" << endl;
}

void OpenGL3Logger::glProgramUniform1iv(GLuint program, GLint location, GLsizei count, const GLint *value)
{
	output_path << "Called glProgramUniform1iv" << endl;
}

void OpenGL3Logger::glProgramUniform1f(GLuint program, GLint location, GLfloat v0)
{
	output_path << "Called glProgramUniform1f" << endl;
}

void OpenGL3Logger::glProgramUniform1fv(GLuint program, GLint location, GLsizei count, const GLfloat *value)
{
	output_path << "Called glProgramUniform1fv" << endl;
}

void OpenGL3Logger::glProgramUniform1d(GLuint program, GLint location, GLdouble v0)
{
	output_path << "Called glProgramUniform1d" << endl;
}

void OpenGL3Logger::glProgramUniform1dv(GLuint program, GLint location, GLsizei count, const GLdouble *value)
{
	output_path << "Called glProgramUniform1dv" << endl;
}

void OpenGL3Logger::glProgramUniform1ui(GLuint program, GLint location, GLuint v0)
{
	output_path << "Called glProgramUniform1ui" << endl;
}

void OpenGL3Logger::glProgramUniform1uiv(GLuint program, GLint location, GLsizei count, const GLuint *value)
{
	output_path << "Called glProgramUniform1uiv" << endl;
}

void OpenGL3Logger::glProgramUniform2i(GLuint program, GLint location, GLint v0, GLint v1)
{
	output_path << "Called glProgramUniform2i" << endl;
}

void OpenGL3Logger::glProgramUniform2iv(GLuint program, GLint location, GLsizei count, const GLint *value)
{
	output_path << "Called glProgramUniform2iv" << endl;
}

void OpenGL3Logger::glProgramUniform2f(GLuint program, GLint location, GLfloat v0, GLfloat v1)
{
	output_path << "Called glProgramUniform2f" << endl;
}

void OpenGL3Logger::glProgramUniform2fv(GLuint program, GLint location, GLsizei count, const GLfloat *value)
{
	output_path << "Called glProgramUniform2fv" << endl;
}

void OpenGL3Logger::glProgramUniform2d(GLuint program, GLint location, GLdouble v0, GLdouble v1)
{
	output_path << "Called glProgramUniform2d" << endl;
}

void OpenGL3Logger::glProgramUniform2dv(GLuint program, GLint location, GLsizei count, const GLdouble *value)
{
	output_path << "Called glProgramUniform2dv" << endl;
}

void OpenGL3Logger::glProgramUniform2ui(GLuint program, GLint location, GLuint v0, GLuint v1)
{
	output_path << "Called glProgramUniform2ui" << endl;
}

void OpenGL3Logger::glProgramUniform2uiv(GLuint program, GLint location, GLsizei count, const GLuint *value)
{
	output_path << "Called glProgramUniform2uiv" << endl;
}

void OpenGL3Logger::glProgramUniform3i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2)
{
	output_path << "Called glProgramUniform3i" << endl;
}

void OpenGL3Logger::glProgramUniform3iv(GLuint program, GLint location, GLsizei count, const GLint *value)
{
	output_path << "Called glProgramUniform3iv" << endl;
}

void OpenGL3Logger::glProgramUniform3f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2)
{
	output_path << "Called glProgramUniform3f" << endl;
}

void OpenGL3Logger::glProgramUniform3fv(GLuint program, GLint location, GLsizei count, const GLfloat *value)
{
	output_path << "Called glProgramUniform3fv" << endl;
}

void OpenGL3Logger::glProgramUniform3d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2)
{
	output_path << "Called glProgramUniform3d" << endl;
}

void OpenGL3Logger::glProgramUniform3dv(GLuint program, GLint location, GLsizei count, const GLdouble *value)
{
	output_path << "Called glProgramUniform3dv" << endl;
}

void OpenGL3Logger::glProgramUniform3ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2)
{
	output_path << "Called glProgramUniform3ui" << endl;
}

void OpenGL3Logger::glProgramUniform3uiv(GLuint program, GLint location, GLsizei count, const GLuint *value)
{
	output_path << "Called glProgramUniform3uiv" << endl;
}

void OpenGL3Logger::glProgramUniform4i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3)
{
	output_path << "Called glProgramUniform4i" << endl;
}

void OpenGL3Logger::glProgramUniform4iv(GLuint program, GLint location, GLsizei count, const GLint *value)
{
	output_path << "Called glProgramUniform4iv" << endl;
}

void OpenGL3Logger::glProgramUniform4f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3)
{
	output_path << "Called glProgramUniform4f" << endl;
}

void OpenGL3Logger::glProgramUniform4fv(GLuint program, GLint location, GLsizei count, const GLfloat *value)
{
	output_path << "Called glProgramUniform4fv" << endl;
}

void OpenGL3Logger::glProgramUniform4d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3)
{
	output_path << "Called glProgramUniform4d" << endl;
}

void OpenGL3Logger::glProgramUniform4dv(GLuint program, GLint location, GLsizei count, const GLdouble *value)
{
	output_path << "Called glProgramUniform4dv" << endl;
}

void OpenGL3Logger::glProgramUniform4ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3)
{
	output_path << "Called glProgramUniform4ui" << endl;
}

void OpenGL3Logger::glProgramUniform4uiv(GLuint program, GLint location, GLsizei count, const GLuint *value)
{
	output_path << "Called glProgramUniform4uiv" << endl;
}

void OpenGL3Logger::glProgramUniformMatrix2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	output_path << "Called glProgramUniformMatrix2fv" << endl;
}

void OpenGL3Logger::glProgramUniformMatrix3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	output_path << "Called glProgramUniformMatrix3fv" << endl;
}

void OpenGL3Logger::glProgramUniformMatrix4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	output_path << "Called glProgramUniformMatrix4fv" << endl;
}

void OpenGL3Logger::glProgramUniformMatrix2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
{
	output_path << "Called glProgramUniformMatrix2dv" << endl;
}

void OpenGL3Logger::glProgramUniformMatrix3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
{
	output_path << "Called glProgramUniformMatrix3dv" << endl;
}

void OpenGL3Logger::glProgramUniformMatrix4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
{
	output_path << "Called glProgramUniformMatrix4dv" << endl;
}

void OpenGL3Logger::glProgramUniformMatrix2x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	output_path << "Called glProgramUniformMatrix2x3fv" << endl;
}

void OpenGL3Logger::glProgramUniformMatrix3x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	output_path << "Called glProgramUniformMatrix3x2fv" << endl;
}

void OpenGL3Logger::glProgramUniformMatrix2x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	output_path << "Called glProgramUniformMatrix2x4fv" << endl;
}

void OpenGL3Logger::glProgramUniformMatrix4x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	output_path << "Called glProgramUniformMatrix4x2fv" << endl;
}

void OpenGL3Logger::glProgramUniformMatrix3x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	output_path << "Called glProgramUniformMatrix3x4fv" << endl;
}

void OpenGL3Logger::glProgramUniformMatrix4x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	output_path << "Called glProgramUniformMatrix4x3fv" << endl;
}

void OpenGL3Logger::glProgramUniformMatrix2x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
{
	output_path << "Called glProgramUniformMatrix2x3dv" << endl;
}

void OpenGL3Logger::glProgramUniformMatrix3x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
{
	output_path << "Called glProgramUniformMatrix3x2dv" << endl;
}

void OpenGL3Logger::glProgramUniformMatrix2x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
{
	output_path << "Called glProgramUniformMatrix2x4dv" << endl;
}

void OpenGL3Logger::glProgramUniformMatrix4x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
{
	output_path << "Called glProgramUniformMatrix4x2dv" << endl;
}

void OpenGL3Logger::glProgramUniformMatrix3x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
{
	output_path << "Called glProgramUniformMatrix3x4dv" << endl;
}

void OpenGL3Logger::glProgramUniformMatrix4x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
{
	output_path << "Called glProgramUniformMatrix4x3dv" << endl;
}

void OpenGL3Logger::glValidateProgramPipeline(GLuint pipeline)
{
	output_path << "Called glValidateProgramPipeline" << endl;
}

void OpenGL3Logger::glGetProgramPipelineInfoLog(GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog)
{
	output_path << "Called glGetProgramPipelineInfoLog" << endl;
}

void OpenGL3Logger::glVertexAttribL1d(GLuint index, GLdouble x)
{
	output_path << "Called glVertexAttribL1d" << endl;
}

void OpenGL3Logger::glVertexAttribL2d(GLuint index, GLdouble x, GLdouble y)
{
	output_path << "Called glVertexAttribL2d" << endl;
}

void OpenGL3Logger::glVertexAttribL3d(GLuint index, GLdouble x, GLdouble y, GLdouble z)
{
	output_path << "Called glVertexAttribL3d" << endl;
}

void OpenGL3Logger::glVertexAttribL4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w)
{
	output_path << "Called glVertexAttribL4d" << endl;
}

void OpenGL3Logger::glVertexAttribL1dv(GLuint index, const GLdouble *v)
{
	output_path << "Called glVertexAttribL1dv" << endl;
}

void OpenGL3Logger::glVertexAttribL2dv(GLuint index, const GLdouble *v)
{
	output_path << "Called glVertexAttribL2dv" << endl;
}

void OpenGL3Logger::glVertexAttribL3dv(GLuint index, const GLdouble *v)
{
	output_path << "Called glVertexAttribL3dv" << endl;
}

void OpenGL3Logger::glVertexAttribL4dv(GLuint index, const GLdouble *v)
{
	output_path << "Called glVertexAttribL4dv" << endl;
}

void OpenGL3Logger::glVertexAttribLPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)
{
	output_path << "Called glVertexAttribLPointer" << endl;
}

void OpenGL3Logger::glGetVertexAttribLdv(GLuint index, GLenum pname, GLdouble *params)
{
	output_path << "Called glGetVertexAttribLdv" << endl;
}

void OpenGL3Logger::glViewportArrayv(GLuint first, GLsizei count, const GLfloat *v)
{
	output_path << "Called glViewportArrayv" << endl;
}

void OpenGL3Logger::glViewportIndexedf(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h)
{
	output_path << "Called glViewportIndexedf" << endl;
}

void OpenGL3Logger::glViewportIndexedfv(GLuint index, const GLfloat *v)
{
	output_path << "Called glViewportIndexedfv" << endl;
}

void OpenGL3Logger::glScissorArrayv(GLuint first, GLsizei count, const GLint *v)
{
	output_path << "Called glScissorArrayv" << endl;
}

void OpenGL3Logger::glScissorIndexed(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height)
{
	output_path << "Called glScissorIndexed" << endl;
}

void OpenGL3Logger::glScissorIndexedv(GLuint index, const GLint *v)
{
	output_path << "Called glScissorIndexedv" << endl;
}

void OpenGL3Logger::glDepthRangeArrayv(GLuint first, GLsizei count, const GLclampd *v)
{
	output_path << "Called glDepthRangeArrayv" << endl;
}

void OpenGL3Logger::glDepthRangeIndexed(GLuint index, GLclampd n, GLclampd f)
{
	output_path << "Called glDepthRangeIndexed" << endl;
}

void OpenGL3Logger::glGetFloati_v(GLenum target, GLuint index, GLfloat *data)
{
	output_path << "Called glGetFloati_v" << endl;
}

void OpenGL3Logger::glGetDoublei_v(GLenum target, GLuint index, GLdouble *data)
{
	output_path << "Called glGetDoublei_v" << endl;
}

}
