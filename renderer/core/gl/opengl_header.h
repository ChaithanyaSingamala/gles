#pragma once


#include <EGL/egl.h>
#ifdef ENABLE_EGL_EXT
#include <EGL/eglext.h>
#endif
#include <GLES3/gl3.h>
#ifdef ENABLE_GL_EXT
#include <GLES3/gl3ext.h>
#endif

#define GLSL_VERSION_STRING		"#version 300 es\n"
#define GLSL_VERSION			"v300es"


enum
{
	VERT_POS_LOC = 0,
	VERT_COLOR_LOC,
	VERT_NORMAL_LOC,
	VERT_UV0_LOC,
	VERT_UV1_LOC,

	VERT_ATTRIB_MAX
};

#ifndef APIENTRY
#define APIENTRY
#endif
#ifndef APIENTRYP
#define APIENTRYP
#endif


