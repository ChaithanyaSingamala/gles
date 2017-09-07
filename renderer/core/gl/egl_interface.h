#pragma once

#include "../common/interface.h"
#include "EGL\egl.h"
#include "GLES3\gl32.h"

class EGLInterface : public Interface
{
	EGLint width = 800;
	EGLint height = 600;

	EGLNativeDisplayType display = nullptr;
	EGLNativeWindowType window = nullptr;
	EGLDisplay eglDisplay = nullptr;
	EGLSurface eglWindowSurface = nullptr;
	EGLContext eglContext = nullptr;

	void WinLoop();
	GLboolean WinCreate();

	void Setup();
public:
	EGLInterface();
	virtual ~EGLInterface();

	virtual void Update() override;

	virtual EGLNativeWindowType Window() { return window; }

	virtual unsigned short Width(unsigned short _width = 0) { return width = (_width == 0) ? width : _width; }
	virtual unsigned short Height(unsigned short _height = 0) { return height = (_height == 0) ? height : _height; }
};

