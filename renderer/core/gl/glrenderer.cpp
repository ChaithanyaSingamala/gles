#include "glrenderer.h"
#include "../common/log.h"
#include "egl_interface.h"
#include "GLES3\gl32.h"
#include <sstream>

void GLRenderer::Setup()
{
	/* Query OpenGL device information */
	const GLubyte* renderer = glGetString(GL_RENDERER);
	const GLubyte* vendor = glGetString(GL_VENDOR);
	const GLubyte* version = glGetString(GL_VERSION);
	const GLubyte* glslVersion = glGetString(GL_SHADING_LANGUAGE_VERSION);

	GLint major, minor;
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

void GLRenderer::Clear(bool _colorBit, bool _depthBit)
{
	glClearColor(1.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
}
