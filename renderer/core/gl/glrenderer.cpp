#include "glrenderer.h"
#include "../common/log.h"
#include "egl_interface.h"
#include <sstream>

void GLRenderer::Setup()
{
	/* Query OpenGL device information */
	const GLubyte* renderer = glGetString(GL_RENDERER);
	const GLubyte* vendor = glGetString(GL_VENDOR);
	const GLubyte* version = glGetString(GL_VERSION);
	const GLubyte* glslVersion = glGetString(GL_SHADING_LANGUAGE_VERSION);

	int major, minor;
	glGetIntegerv(GL_MAJOR_VERSION, &major);
	glGetIntegerv(GL_MINOR_VERSION, &minor);

	std::stringstream ss;
	ss << "\n-------------------------------------------------------------\n";
	ss << "GL Vendor    : " << vendor;
	ss << "\nGL GLRenderer : " << renderer;
	ss << "\nGL Version   : " << version;
	ss << "\nGL Version   : " << major << "." << minor;
	ss << "\nGLSL Version : " << glslVersion;
	ss << "\n-------------------------------------------------------------\n";
	printf("%s", ss.str().c_str());

	glClearColor(1.0, 0.0, 0.0, 1.0);

}

GLRenderer::GLRenderer()
{
	Log("Starting OpenGL renderer...");
	Setup();
}


GLRenderer::~GLRenderer()
{
	Log("Exiting OpenGL renderer...");

}

void GLRenderer::SetClearColor(float red, float green, float blue, float alpha)
{
	glClearColor(red, green, blue, alpha);
}

void GLRenderer::Clear(bool _colorBit, bool _depthBit)
{
	GLbitfield mask = 0;
	if (_colorBit) mask |= GL_COLOR_BUFFER_BIT;
	if (_depthBit) mask |= GL_DEPTH_BUFFER_BIT;
	glClear(mask);
}
