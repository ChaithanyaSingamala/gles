#pragma once

#include "gl\opengl_header.h"

#ifdef ENABLE_EGL

#include "../common/interface.h"


class EGLInterface : public Interface
{
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
};

#endif

