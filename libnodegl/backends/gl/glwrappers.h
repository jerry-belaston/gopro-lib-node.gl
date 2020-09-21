/* DO NOT EDIT - This file is autogenerated */

/* WARNING: this file must only be included once */

#include "config.h"

#ifdef DEBUG_GL
# define check_error_code ngli_glcontext_check_gl_error
#else
# define check_error_code(gl, glfuncname) do { } while (0)
#endif

static inline void ngli_glActiveTexture(const struct glcontext *gl, GLenum texture)
{
    gl->funcs.ActiveTexture(texture);
    check_error_code(gl, "glActiveTexture");
}

static inline void ngli_glAttachShader(const struct glcontext *gl, GLuint program, GLuint shader)
{
    gl->funcs.AttachShader(program, shader);
    check_error_code(gl, "glAttachShader");
}

static inline void ngli_glBeginQuery(const struct glcontext *gl, GLenum target, GLuint id)
{
    gl->funcs.BeginQuery(target, id);
    check_error_code(gl, "glBeginQuery");
}

static inline void ngli_glBeginQueryEXT(const struct glcontext *gl, GLenum target, GLuint id)
{
    gl->funcs.BeginQueryEXT(target, id);
    check_error_code(gl, "glBeginQueryEXT");
}

static inline void ngli_glBindAttribLocation(const struct glcontext *gl, GLuint program, GLuint index, const GLchar * name)
{
    gl->funcs.BindAttribLocation(program, index, name);
    check_error_code(gl, "glBindAttribLocation");
}

static inline void ngli_glBindBuffer(const struct glcontext *gl, GLenum target, GLuint buffer)
{
    gl->funcs.BindBuffer(target, buffer);
    check_error_code(gl, "glBindBuffer");
}

static inline void ngli_glBindBufferBase(const struct glcontext *gl, GLenum target, GLuint index, GLuint buffer)
{
    gl->funcs.BindBufferBase(target, index, buffer);
    check_error_code(gl, "glBindBufferBase");
}

static inline void ngli_glBindBufferRange(const struct glcontext *gl, GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size)
{
    gl->funcs.BindBufferRange(target, index, buffer, offset, size);
    check_error_code(gl, "glBindBufferRange");
}

static inline void ngli_glBindFramebuffer(const struct glcontext *gl, GLenum target, GLuint framebuffer)
{
    gl->funcs.BindFramebuffer(target, framebuffer);
    check_error_code(gl, "glBindFramebuffer");
}

static inline void ngli_glBindImageTexture(const struct glcontext *gl, GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format)
{
    gl->funcs.BindImageTexture(unit, texture, level, layered, layer, access, format);
    check_error_code(gl, "glBindImageTexture");
}

static inline void ngli_glBindRenderbuffer(const struct glcontext *gl, GLenum target, GLuint renderbuffer)
{
    gl->funcs.BindRenderbuffer(target, renderbuffer);
    check_error_code(gl, "glBindRenderbuffer");
}

static inline void ngli_glBindTexture(const struct glcontext *gl, GLenum target, GLuint texture)
{
    gl->funcs.BindTexture(target, texture);
    check_error_code(gl, "glBindTexture");
}

static inline void ngli_glBindVertexArray(const struct glcontext *gl, GLuint array)
{
    gl->funcs.BindVertexArray(array);
    check_error_code(gl, "glBindVertexArray");
}

static inline void ngli_glBlendColor(const struct glcontext *gl, GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
    gl->funcs.BlendColor(red, green, blue, alpha);
    check_error_code(gl, "glBlendColor");
}

static inline void ngli_glBlendEquation(const struct glcontext *gl, GLenum mode)
{
    gl->funcs.BlendEquation(mode);
    check_error_code(gl, "glBlendEquation");
}

static inline void ngli_glBlendEquationSeparate(const struct glcontext *gl, GLenum modeRGB, GLenum modeAlpha)
{
    gl->funcs.BlendEquationSeparate(modeRGB, modeAlpha);
    check_error_code(gl, "glBlendEquationSeparate");
}

static inline void ngli_glBlendFunc(const struct glcontext *gl, GLenum sfactor, GLenum dfactor)
{
    gl->funcs.BlendFunc(sfactor, dfactor);
    check_error_code(gl, "glBlendFunc");
}

static inline void ngli_glBlendFuncSeparate(const struct glcontext *gl, GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha)
{
    gl->funcs.BlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
    check_error_code(gl, "glBlendFuncSeparate");
}

static inline void ngli_glBlitFramebuffer(const struct glcontext *gl, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter)
{
    gl->funcs.BlitFramebuffer(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
    check_error_code(gl, "glBlitFramebuffer");
}

static inline void ngli_glBufferData(const struct glcontext *gl, GLenum target, GLsizeiptr size, const void * data, GLenum usage)
{
    gl->funcs.BufferData(target, size, data, usage);
    check_error_code(gl, "glBufferData");
}

static inline void ngli_glBufferSubData(const struct glcontext *gl, GLenum target, GLintptr offset, GLsizeiptr size, const void * data)
{
    gl->funcs.BufferSubData(target, offset, size, data);
    check_error_code(gl, "glBufferSubData");
}

static inline GLenum ngli_glCheckFramebufferStatus(const struct glcontext *gl, GLenum target)
{
    GLenum ret = gl->funcs.CheckFramebufferStatus(target);
    check_error_code(gl, "glCheckFramebufferStatus");
    return ret;
}

static inline void ngli_glClear(const struct glcontext *gl, GLbitfield mask)
{
    gl->funcs.Clear(mask);
    check_error_code(gl, "glClear");
}

static inline void ngli_glClearBufferfi(const struct glcontext *gl, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil)
{
    gl->funcs.ClearBufferfi(buffer, drawbuffer, depth, stencil);
    check_error_code(gl, "glClearBufferfi");
}

static inline void ngli_glClearBufferfv(const struct glcontext *gl, GLenum buffer, GLint drawbuffer, const GLfloat * value)
{
    gl->funcs.ClearBufferfv(buffer, drawbuffer, value);
    check_error_code(gl, "glClearBufferfv");
}

static inline void ngli_glClearColor(const struct glcontext *gl, GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
    gl->funcs.ClearColor(red, green, blue, alpha);
    check_error_code(gl, "glClearColor");
}

static inline GLenum ngli_glClientWaitSync(const struct glcontext *gl, GLsync sync, GLbitfield flags, GLuint64 timeout)
{
    GLenum ret = gl->funcs.ClientWaitSync(sync, flags, timeout);
    check_error_code(gl, "glClientWaitSync");
    return ret;
}

static inline void ngli_glColorMask(const struct glcontext *gl, GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha)
{
    gl->funcs.ColorMask(red, green, blue, alpha);
    check_error_code(gl, "glColorMask");
}

static inline void ngli_glCompileShader(const struct glcontext *gl, GLuint shader)
{
    gl->funcs.CompileShader(shader);
    check_error_code(gl, "glCompileShader");
}

static inline GLuint ngli_glCreateProgram(const struct glcontext *gl)
{
    GLuint ret = gl->funcs.CreateProgram();
    check_error_code(gl, "glCreateProgram");
    return ret;
}

static inline GLuint ngli_glCreateShader(const struct glcontext *gl, GLenum type)
{
    GLuint ret = gl->funcs.CreateShader(type);
    check_error_code(gl, "glCreateShader");
    return ret;
}

static inline void ngli_glCullFace(const struct glcontext *gl, GLenum mode)
{
    gl->funcs.CullFace(mode);
    check_error_code(gl, "glCullFace");
}

static inline void ngli_glDebugMessageCallback(const struct glcontext *gl, GLDEBUGPROC callback, const void * userParam)
{
    gl->funcs.DebugMessageCallback(callback, userParam);
    check_error_code(gl, "glDebugMessageCallback");
}

static inline void ngli_glDeleteBuffers(const struct glcontext *gl, GLsizei n, const GLuint * buffers)
{
    gl->funcs.DeleteBuffers(n, buffers);
    check_error_code(gl, "glDeleteBuffers");
}

static inline void ngli_glDeleteFramebuffers(const struct glcontext *gl, GLsizei n, const GLuint * framebuffers)
{
    gl->funcs.DeleteFramebuffers(n, framebuffers);
    check_error_code(gl, "glDeleteFramebuffers");
}

static inline void ngli_glDeleteProgram(const struct glcontext *gl, GLuint program)
{
    gl->funcs.DeleteProgram(program);
    check_error_code(gl, "glDeleteProgram");
}

static inline void ngli_glDeleteQueries(const struct glcontext *gl, GLsizei n, const GLuint * ids)
{
    gl->funcs.DeleteQueries(n, ids);
    check_error_code(gl, "glDeleteQueries");
}

static inline void ngli_glDeleteQueriesEXT(const struct glcontext *gl, GLsizei n, const GLuint * ids)
{
    gl->funcs.DeleteQueriesEXT(n, ids);
    check_error_code(gl, "glDeleteQueriesEXT");
}

static inline void ngli_glDeleteRenderbuffers(const struct glcontext *gl, GLsizei n, const GLuint * renderbuffers)
{
    gl->funcs.DeleteRenderbuffers(n, renderbuffers);
    check_error_code(gl, "glDeleteRenderbuffers");
}

static inline void ngli_glDeleteShader(const struct glcontext *gl, GLuint shader)
{
    gl->funcs.DeleteShader(shader);
    check_error_code(gl, "glDeleteShader");
}

static inline void ngli_glDeleteTextures(const struct glcontext *gl, GLsizei n, const GLuint * textures)
{
    gl->funcs.DeleteTextures(n, textures);
    check_error_code(gl, "glDeleteTextures");
}

static inline void ngli_glDeleteVertexArrays(const struct glcontext *gl, GLsizei n, const GLuint * arrays)
{
    gl->funcs.DeleteVertexArrays(n, arrays);
    check_error_code(gl, "glDeleteVertexArrays");
}

static inline void ngli_glDepthFunc(const struct glcontext *gl, GLenum func)
{
    gl->funcs.DepthFunc(func);
    check_error_code(gl, "glDepthFunc");
}

static inline void ngli_glDepthMask(const struct glcontext *gl, GLboolean flag)
{
    gl->funcs.DepthMask(flag);
    check_error_code(gl, "glDepthMask");
}

static inline void ngli_glDetachShader(const struct glcontext *gl, GLuint program, GLuint shader)
{
    gl->funcs.DetachShader(program, shader);
    check_error_code(gl, "glDetachShader");
}

static inline void ngli_glDisable(const struct glcontext *gl, GLenum cap)
{
    gl->funcs.Disable(cap);
    check_error_code(gl, "glDisable");
}

static inline void ngli_glDisableVertexAttribArray(const struct glcontext *gl, GLuint index)
{
    gl->funcs.DisableVertexAttribArray(index);
    check_error_code(gl, "glDisableVertexAttribArray");
}

static inline void ngli_glDispatchCompute(const struct glcontext *gl, GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z)
{
    gl->funcs.DispatchCompute(num_groups_x, num_groups_y, num_groups_z);
    check_error_code(gl, "glDispatchCompute");
}

static inline void ngli_glDrawArrays(const struct glcontext *gl, GLenum mode, GLint first, GLsizei count)
{
    gl->funcs.DrawArrays(mode, first, count);
    check_error_code(gl, "glDrawArrays");
}

static inline void ngli_glDrawArraysInstanced(const struct glcontext *gl, GLenum mode, GLint first, GLsizei count, GLsizei instancecount)
{
    gl->funcs.DrawArraysInstanced(mode, first, count, instancecount);
    check_error_code(gl, "glDrawArraysInstanced");
}

static inline void ngli_glDrawBuffer(const struct glcontext *gl, GLenum buf)
{
    gl->funcs.DrawBuffer(buf);
    check_error_code(gl, "glDrawBuffer");
}

static inline void ngli_glDrawBuffers(const struct glcontext *gl, GLsizei n, const GLenum * bufs)
{
    gl->funcs.DrawBuffers(n, bufs);
    check_error_code(gl, "glDrawBuffers");
}

static inline void ngli_glDrawElements(const struct glcontext *gl, GLenum mode, GLsizei count, GLenum type, const void * indices)
{
    gl->funcs.DrawElements(mode, count, type, indices);
    check_error_code(gl, "glDrawElements");
}

static inline void ngli_glDrawElementsInstanced(const struct glcontext *gl, GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount)
{
    gl->funcs.DrawElementsInstanced(mode, count, type, indices, instancecount);
    check_error_code(gl, "glDrawElementsInstanced");
}

static inline void ngli_glEGLImageTargetTexture2DOES(const struct glcontext *gl, GLenum target, GLeglImageOES image)
{
    gl->funcs.EGLImageTargetTexture2DOES(target, image);
    check_error_code(gl, "glEGLImageTargetTexture2DOES");
}

static inline void ngli_glEnable(const struct glcontext *gl, GLenum cap)
{
    gl->funcs.Enable(cap);
    check_error_code(gl, "glEnable");
}

static inline void ngli_glEnableVertexAttribArray(const struct glcontext *gl, GLuint index)
{
    gl->funcs.EnableVertexAttribArray(index);
    check_error_code(gl, "glEnableVertexAttribArray");
}

static inline void ngli_glEndQuery(const struct glcontext *gl, GLenum target)
{
    gl->funcs.EndQuery(target);
    check_error_code(gl, "glEndQuery");
}

static inline void ngli_glEndQueryEXT(const struct glcontext *gl, GLenum target)
{
    gl->funcs.EndQueryEXT(target);
    check_error_code(gl, "glEndQueryEXT");
}

static inline GLsync ngli_glFenceSync(const struct glcontext *gl, GLenum condition, GLbitfield flags)
{
    GLsync ret = gl->funcs.FenceSync(condition, flags);
    check_error_code(gl, "glFenceSync");
    return ret;
}

static inline void ngli_glFinish(const struct glcontext *gl)
{
    gl->funcs.Finish();
    check_error_code(gl, "glFinish");
}

static inline void ngli_glFlush(const struct glcontext *gl)
{
    gl->funcs.Flush();
    check_error_code(gl, "glFlush");
}

static inline void ngli_glFramebufferRenderbuffer(const struct glcontext *gl, GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer)
{
    gl->funcs.FramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
    check_error_code(gl, "glFramebufferRenderbuffer");
}

static inline void ngli_glFramebufferTexture2D(const struct glcontext *gl, GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)
{
    gl->funcs.FramebufferTexture2D(target, attachment, textarget, texture, level);
    check_error_code(gl, "glFramebufferTexture2D");
}

static inline void ngli_glGenBuffers(const struct glcontext *gl, GLsizei n, GLuint * buffers)
{
    gl->funcs.GenBuffers(n, buffers);
    check_error_code(gl, "glGenBuffers");
}

static inline void ngli_glGenFramebuffers(const struct glcontext *gl, GLsizei n, GLuint * framebuffers)
{
    gl->funcs.GenFramebuffers(n, framebuffers);
    check_error_code(gl, "glGenFramebuffers");
}

static inline void ngli_glGenQueries(const struct glcontext *gl, GLsizei n, GLuint * ids)
{
    gl->funcs.GenQueries(n, ids);
    check_error_code(gl, "glGenQueries");
}

static inline void ngli_glGenQueriesEXT(const struct glcontext *gl, GLsizei n, GLuint * ids)
{
    gl->funcs.GenQueriesEXT(n, ids);
    check_error_code(gl, "glGenQueriesEXT");
}

static inline void ngli_glGenRenderbuffers(const struct glcontext *gl, GLsizei n, GLuint * renderbuffers)
{
    gl->funcs.GenRenderbuffers(n, renderbuffers);
    check_error_code(gl, "glGenRenderbuffers");
}

static inline void ngli_glGenTextures(const struct glcontext *gl, GLsizei n, GLuint * textures)
{
    gl->funcs.GenTextures(n, textures);
    check_error_code(gl, "glGenTextures");
}

static inline void ngli_glGenVertexArrays(const struct glcontext *gl, GLsizei n, GLuint * arrays)
{
    gl->funcs.GenVertexArrays(n, arrays);
    check_error_code(gl, "glGenVertexArrays");
}

static inline void ngli_glGenerateMipmap(const struct glcontext *gl, GLenum target)
{
    gl->funcs.GenerateMipmap(target);
    check_error_code(gl, "glGenerateMipmap");
}

static inline void ngli_glGetActiveAttrib(const struct glcontext *gl, GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name)
{
    gl->funcs.GetActiveAttrib(program, index, bufSize, length, size, type, name);
    check_error_code(gl, "glGetActiveAttrib");
}

static inline void ngli_glGetActiveUniform(const struct glcontext *gl, GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name)
{
    gl->funcs.GetActiveUniform(program, index, bufSize, length, size, type, name);
    check_error_code(gl, "glGetActiveUniform");
}

static inline void ngli_glGetActiveUniformBlockName(const struct glcontext *gl, GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei * length, GLchar * uniformBlockName)
{
    gl->funcs.GetActiveUniformBlockName(program, uniformBlockIndex, bufSize, length, uniformBlockName);
    check_error_code(gl, "glGetActiveUniformBlockName");
}

static inline void ngli_glGetActiveUniformBlockiv(const struct glcontext *gl, GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint * params)
{
    gl->funcs.GetActiveUniformBlockiv(program, uniformBlockIndex, pname, params);
    check_error_code(gl, "glGetActiveUniformBlockiv");
}

static inline void ngli_glGetAttachedShaders(const struct glcontext *gl, GLuint program, GLsizei maxCount, GLsizei * count, GLuint * shaders)
{
    gl->funcs.GetAttachedShaders(program, maxCount, count, shaders);
    check_error_code(gl, "glGetAttachedShaders");
}

static inline GLint ngli_glGetAttribLocation(const struct glcontext *gl, GLuint program, const GLchar * name)
{
    GLint ret = gl->funcs.GetAttribLocation(program, name);
    check_error_code(gl, "glGetAttribLocation");
    return ret;
}

static inline void ngli_glGetBooleanv(const struct glcontext *gl, GLenum pname, GLboolean * data)
{
    gl->funcs.GetBooleanv(pname, data);
    check_error_code(gl, "glGetBooleanv");
}

static inline GLenum ngli_glGetError(const struct glcontext *gl)
{
    return gl->funcs.GetError();
}

static inline void ngli_glGetIntegeri_v(const struct glcontext *gl, GLenum target, GLuint index, GLint * data)
{
    gl->funcs.GetIntegeri_v(target, index, data);
    check_error_code(gl, "glGetIntegeri_v");
}

static inline void ngli_glGetIntegerv(const struct glcontext *gl, GLenum pname, GLint * data)
{
    gl->funcs.GetIntegerv(pname, data);
    check_error_code(gl, "glGetIntegerv");
}

static inline void ngli_glGetInternalformativ(const struct glcontext *gl, GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint * params)
{
    gl->funcs.GetInternalformativ(target, internalformat, pname, count, params);
    check_error_code(gl, "glGetInternalformativ");
}

static inline void ngli_glGetProgramInfoLog(const struct glcontext *gl, GLuint program, GLsizei bufSize, GLsizei * length, GLchar * infoLog)
{
    gl->funcs.GetProgramInfoLog(program, bufSize, length, infoLog);
    check_error_code(gl, "glGetProgramInfoLog");
}

static inline void ngli_glGetProgramInterfaceiv(const struct glcontext *gl, GLuint program, GLenum programInterface, GLenum pname, GLint * params)
{
    gl->funcs.GetProgramInterfaceiv(program, programInterface, pname, params);
    check_error_code(gl, "glGetProgramInterfaceiv");
}

static inline GLuint ngli_glGetProgramResourceIndex(const struct glcontext *gl, GLuint program, GLenum programInterface, const GLchar * name)
{
    GLuint ret = gl->funcs.GetProgramResourceIndex(program, programInterface, name);
    check_error_code(gl, "glGetProgramResourceIndex");
    return ret;
}

static inline GLint ngli_glGetProgramResourceLocation(const struct glcontext *gl, GLuint program, GLenum programInterface, const GLchar * name)
{
    GLint ret = gl->funcs.GetProgramResourceLocation(program, programInterface, name);
    check_error_code(gl, "glGetProgramResourceLocation");
    return ret;
}

static inline void ngli_glGetProgramResourceName(const struct glcontext *gl, GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei * length, GLchar * name)
{
    gl->funcs.GetProgramResourceName(program, programInterface, index, bufSize, length, name);
    check_error_code(gl, "glGetProgramResourceName");
}

static inline void ngli_glGetProgramResourceiv(const struct glcontext *gl, GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum * props, GLsizei count, GLsizei * length, GLint * params)
{
    gl->funcs.GetProgramResourceiv(program, programInterface, index, propCount, props, count, length, params);
    check_error_code(gl, "glGetProgramResourceiv");
}

static inline void ngli_glGetProgramiv(const struct glcontext *gl, GLuint program, GLenum pname, GLint * params)
{
    gl->funcs.GetProgramiv(program, pname, params);
    check_error_code(gl, "glGetProgramiv");
}

static inline void ngli_glGetQueryObjectui64v(const struct glcontext *gl, GLuint id, GLenum pname, GLuint64 * params)
{
    gl->funcs.GetQueryObjectui64v(id, pname, params);
    check_error_code(gl, "glGetQueryObjectui64v");
}

static inline void ngli_glGetQueryObjectui64vEXT(const struct glcontext *gl, GLuint id, GLenum pname, GLuint64 * params)
{
    gl->funcs.GetQueryObjectui64vEXT(id, pname, params);
    check_error_code(gl, "glGetQueryObjectui64vEXT");
}

static inline void ngli_glGetRenderbufferParameteriv(const struct glcontext *gl, GLenum target, GLenum pname, GLint * params)
{
    gl->funcs.GetRenderbufferParameteriv(target, pname, params);
    check_error_code(gl, "glGetRenderbufferParameteriv");
}

static inline void ngli_glGetShaderInfoLog(const struct glcontext *gl, GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * infoLog)
{
    gl->funcs.GetShaderInfoLog(shader, bufSize, length, infoLog);
    check_error_code(gl, "glGetShaderInfoLog");
}

static inline void ngli_glGetShaderSource(const struct glcontext *gl, GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * source)
{
    gl->funcs.GetShaderSource(shader, bufSize, length, source);
    check_error_code(gl, "glGetShaderSource");
}

static inline void ngli_glGetShaderiv(const struct glcontext *gl, GLuint shader, GLenum pname, GLint * params)
{
    gl->funcs.GetShaderiv(shader, pname, params);
    check_error_code(gl, "glGetShaderiv");
}

static inline const GLubyte * ngli_glGetString(const struct glcontext *gl, GLenum name)
{
    const GLubyte * ret = gl->funcs.GetString(name);
    check_error_code(gl, "glGetString");
    return ret;
}

static inline const GLubyte * ngli_glGetStringi(const struct glcontext *gl, GLenum name, GLuint index)
{
    const GLubyte * ret = gl->funcs.GetStringi(name, index);
    check_error_code(gl, "glGetStringi");
    return ret;
}

static inline GLuint ngli_glGetUniformBlockIndex(const struct glcontext *gl, GLuint program, const GLchar * uniformBlockName)
{
    GLuint ret = gl->funcs.GetUniformBlockIndex(program, uniformBlockName);
    check_error_code(gl, "glGetUniformBlockIndex");
    return ret;
}

static inline GLint ngli_glGetUniformLocation(const struct glcontext *gl, GLuint program, const GLchar * name)
{
    GLint ret = gl->funcs.GetUniformLocation(program, name);
    check_error_code(gl, "glGetUniformLocation");
    return ret;
}

static inline void ngli_glGetUniformiv(const struct glcontext *gl, GLuint program, GLint location, GLint * params)
{
    gl->funcs.GetUniformiv(program, location, params);
    check_error_code(gl, "glGetUniformiv");
}

static inline void ngli_glInvalidateFramebuffer(const struct glcontext *gl, GLenum target, GLsizei numAttachments, const GLenum * attachments)
{
    gl->funcs.InvalidateFramebuffer(target, numAttachments, attachments);
    check_error_code(gl, "glInvalidateFramebuffer");
}

static inline void ngli_glLinkProgram(const struct glcontext *gl, GLuint program)
{
    gl->funcs.LinkProgram(program);
    check_error_code(gl, "glLinkProgram");
}

static inline void * ngli_glMapBufferRange(const struct glcontext *gl, GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access)
{
    void * ret = gl->funcs.MapBufferRange(target, offset, length, access);
    check_error_code(gl, "glMapBufferRange");
    return ret;
}

static inline void ngli_glMemoryBarrier(const struct glcontext *gl, GLbitfield barriers)
{
    gl->funcs.MemoryBarrier(barriers);
    check_error_code(gl, "glMemoryBarrier");
}

static inline void ngli_glPixelStorei(const struct glcontext *gl, GLenum pname, GLint param)
{
    gl->funcs.PixelStorei(pname, param);
    check_error_code(gl, "glPixelStorei");
}

static inline void ngli_glPolygonMode(const struct glcontext *gl, GLenum face, GLenum mode)
{
    gl->funcs.PolygonMode(face, mode);
    check_error_code(gl, "glPolygonMode");
}

static inline void ngli_glQueryCounter(const struct glcontext *gl, GLuint id, GLenum target)
{
    gl->funcs.QueryCounter(id, target);
    check_error_code(gl, "glQueryCounter");
}

static inline void ngli_glQueryCounterEXT(const struct glcontext *gl, GLuint id, GLenum target)
{
    gl->funcs.QueryCounterEXT(id, target);
    check_error_code(gl, "glQueryCounterEXT");
}

static inline void ngli_glReadBuffer(const struct glcontext *gl, GLenum src)
{
    gl->funcs.ReadBuffer(src);
    check_error_code(gl, "glReadBuffer");
}

static inline void ngli_glReadPixels(const struct glcontext *gl, GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void * pixels)
{
    gl->funcs.ReadPixels(x, y, width, height, format, type, pixels);
    check_error_code(gl, "glReadPixels");
}

static inline void ngli_glReleaseShaderCompiler(const struct glcontext *gl)
{
    gl->funcs.ReleaseShaderCompiler();
    check_error_code(gl, "glReleaseShaderCompiler");
}

static inline void ngli_glRenderbufferStorage(const struct glcontext *gl, GLenum target, GLenum internalformat, GLsizei width, GLsizei height)
{
    gl->funcs.RenderbufferStorage(target, internalformat, width, height);
    check_error_code(gl, "glRenderbufferStorage");
}

static inline void ngli_glRenderbufferStorageMultisample(const struct glcontext *gl, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height)
{
    gl->funcs.RenderbufferStorageMultisample(target, samples, internalformat, width, height);
    check_error_code(gl, "glRenderbufferStorageMultisample");
}

static inline void ngli_glScissor(const struct glcontext *gl, GLint x, GLint y, GLsizei width, GLsizei height)
{
    gl->funcs.Scissor(x, y, width, height);
    check_error_code(gl, "glScissor");
}

static inline void ngli_glShaderBinary(const struct glcontext *gl, GLsizei count, const GLuint * shaders, GLenum binaryFormat, const void * binary, GLsizei length)
{
    gl->funcs.ShaderBinary(count, shaders, binaryFormat, binary, length);
    check_error_code(gl, "glShaderBinary");
}

static inline void ngli_glShaderSource(const struct glcontext *gl, GLuint shader, GLsizei count, const GLchar *const* string, const GLint * length)
{
    gl->funcs.ShaderSource(shader, count, string, length);
    check_error_code(gl, "glShaderSource");
}

static inline void ngli_glStencilFunc(const struct glcontext *gl, GLenum func, GLint ref, GLuint mask)
{
    gl->funcs.StencilFunc(func, ref, mask);
    check_error_code(gl, "glStencilFunc");
}

static inline void ngli_glStencilFuncSeparate(const struct glcontext *gl, GLenum face, GLenum func, GLint ref, GLuint mask)
{
    gl->funcs.StencilFuncSeparate(face, func, ref, mask);
    check_error_code(gl, "glStencilFuncSeparate");
}

static inline void ngli_glStencilMask(const struct glcontext *gl, GLuint mask)
{
    gl->funcs.StencilMask(mask);
    check_error_code(gl, "glStencilMask");
}

static inline void ngli_glStencilMaskSeparate(const struct glcontext *gl, GLenum face, GLuint mask)
{
    gl->funcs.StencilMaskSeparate(face, mask);
    check_error_code(gl, "glStencilMaskSeparate");
}

static inline void ngli_glStencilOp(const struct glcontext *gl, GLenum fail, GLenum zfail, GLenum zpass)
{
    gl->funcs.StencilOp(fail, zfail, zpass);
    check_error_code(gl, "glStencilOp");
}

static inline void ngli_glStencilOpSeparate(const struct glcontext *gl, GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass)
{
    gl->funcs.StencilOpSeparate(face, sfail, dpfail, dppass);
    check_error_code(gl, "glStencilOpSeparate");
}

static inline void ngli_glTexImage2D(const struct glcontext *gl, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void * pixels)
{
    gl->funcs.TexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
    check_error_code(gl, "glTexImage2D");
}

static inline void ngli_glTexImage3D(const struct glcontext *gl, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void * pixels)
{
    gl->funcs.TexImage3D(target, level, internalformat, width, height, depth, border, format, type, pixels);
    check_error_code(gl, "glTexImage3D");
}

static inline void ngli_glTexParameteri(const struct glcontext *gl, GLenum target, GLenum pname, GLint param)
{
    gl->funcs.TexParameteri(target, pname, param);
    check_error_code(gl, "glTexParameteri");
}

static inline void ngli_glTexStorage2D(const struct glcontext *gl, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height)
{
    gl->funcs.TexStorage2D(target, levels, internalformat, width, height);
    check_error_code(gl, "glTexStorage2D");
}

static inline void ngli_glTexStorage3D(const struct glcontext *gl, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth)
{
    gl->funcs.TexStorage3D(target, levels, internalformat, width, height, depth);
    check_error_code(gl, "glTexStorage3D");
}

static inline void ngli_glTexSubImage2D(const struct glcontext *gl, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels)
{
    gl->funcs.TexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);
    check_error_code(gl, "glTexSubImage2D");
}

static inline void ngli_glTexSubImage3D(const struct glcontext *gl, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels)
{
    gl->funcs.TexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
    check_error_code(gl, "glTexSubImage3D");
}

static inline void ngli_glUniform1fv(const struct glcontext *gl, GLint location, GLsizei count, const GLfloat * value)
{
    gl->funcs.Uniform1fv(location, count, value);
    check_error_code(gl, "glUniform1fv");
}

static inline void ngli_glUniform1i(const struct glcontext *gl, GLint location, GLint v0)
{
    gl->funcs.Uniform1i(location, v0);
    check_error_code(gl, "glUniform1i");
}

static inline void ngli_glUniform1iv(const struct glcontext *gl, GLint location, GLsizei count, const GLint * value)
{
    gl->funcs.Uniform1iv(location, count, value);
    check_error_code(gl, "glUniform1iv");
}

static inline void ngli_glUniform1uiv(const struct glcontext *gl, GLint location, GLsizei count, const GLuint * value)
{
    gl->funcs.Uniform1uiv(location, count, value);
    check_error_code(gl, "glUniform1uiv");
}

static inline void ngli_glUniform2fv(const struct glcontext *gl, GLint location, GLsizei count, const GLfloat * value)
{
    gl->funcs.Uniform2fv(location, count, value);
    check_error_code(gl, "glUniform2fv");
}

static inline void ngli_glUniform2iv(const struct glcontext *gl, GLint location, GLsizei count, const GLint * value)
{
    gl->funcs.Uniform2iv(location, count, value);
    check_error_code(gl, "glUniform2iv");
}

static inline void ngli_glUniform2uiv(const struct glcontext *gl, GLint location, GLsizei count, const GLuint * value)
{
    gl->funcs.Uniform2uiv(location, count, value);
    check_error_code(gl, "glUniform2uiv");
}

static inline void ngli_glUniform3fv(const struct glcontext *gl, GLint location, GLsizei count, const GLfloat * value)
{
    gl->funcs.Uniform3fv(location, count, value);
    check_error_code(gl, "glUniform3fv");
}

static inline void ngli_glUniform3iv(const struct glcontext *gl, GLint location, GLsizei count, const GLint * value)
{
    gl->funcs.Uniform3iv(location, count, value);
    check_error_code(gl, "glUniform3iv");
}

static inline void ngli_glUniform3uiv(const struct glcontext *gl, GLint location, GLsizei count, const GLuint * value)
{
    gl->funcs.Uniform3uiv(location, count, value);
    check_error_code(gl, "glUniform3uiv");
}

static inline void ngli_glUniform4fv(const struct glcontext *gl, GLint location, GLsizei count, const GLfloat * value)
{
    gl->funcs.Uniform4fv(location, count, value);
    check_error_code(gl, "glUniform4fv");
}

static inline void ngli_glUniform4iv(const struct glcontext *gl, GLint location, GLsizei count, const GLint * value)
{
    gl->funcs.Uniform4iv(location, count, value);
    check_error_code(gl, "glUniform4iv");
}

static inline void ngli_glUniform4uiv(const struct glcontext *gl, GLint location, GLsizei count, const GLuint * value)
{
    gl->funcs.Uniform4uiv(location, count, value);
    check_error_code(gl, "glUniform4uiv");
}

static inline void ngli_glUniformBlockBinding(const struct glcontext *gl, GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding)
{
    gl->funcs.UniformBlockBinding(program, uniformBlockIndex, uniformBlockBinding);
    check_error_code(gl, "glUniformBlockBinding");
}

static inline void ngli_glUniformMatrix2fv(const struct glcontext *gl, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)
{
    gl->funcs.UniformMatrix2fv(location, count, transpose, value);
    check_error_code(gl, "glUniformMatrix2fv");
}

static inline void ngli_glUniformMatrix3fv(const struct glcontext *gl, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)
{
    gl->funcs.UniformMatrix3fv(location, count, transpose, value);
    check_error_code(gl, "glUniformMatrix3fv");
}

static inline void ngli_glUniformMatrix4fv(const struct glcontext *gl, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)
{
    gl->funcs.UniformMatrix4fv(location, count, transpose, value);
    check_error_code(gl, "glUniformMatrix4fv");
}

static inline GLboolean ngli_glUnmapBuffer(const struct glcontext *gl, GLenum target)
{
    GLboolean ret = gl->funcs.UnmapBuffer(target);
    check_error_code(gl, "glUnmapBuffer");
    return ret;
}

static inline void ngli_glUseProgram(const struct glcontext *gl, GLuint program)
{
    gl->funcs.UseProgram(program);
    check_error_code(gl, "glUseProgram");
}

static inline void ngli_glVertexAttribDivisor(const struct glcontext *gl, GLuint index, GLuint divisor)
{
    gl->funcs.VertexAttribDivisor(index, divisor);
    check_error_code(gl, "glVertexAttribDivisor");
}

static inline void ngli_glVertexAttribPointer(const struct glcontext *gl, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void * pointer)
{
    gl->funcs.VertexAttribPointer(index, size, type, normalized, stride, pointer);
    check_error_code(gl, "glVertexAttribPointer");
}

static inline void ngli_glViewport(const struct glcontext *gl, GLint x, GLint y, GLsizei width, GLsizei height)
{
    gl->funcs.Viewport(x, y, width, height);
    check_error_code(gl, "glViewport");
}

static inline void ngli_glWaitSync(const struct glcontext *gl, GLsync sync, GLbitfield flags, GLuint64 timeout)
{
    gl->funcs.WaitSync(sync, flags, timeout);
    check_error_code(gl, "glWaitSync");
}
