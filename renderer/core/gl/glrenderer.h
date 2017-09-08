#pragma once
#include "../common/renderer.h"

#include "gl\opengl_header.h"

class GLRenderer : public Renderer
{
	void Setup();
public:
	GLRenderer();
	virtual ~GLRenderer();

	void SetClearColor(float red, float green, float blue, float alpha);
	void Clear(bool _colorBit = true, bool _depthBit = true);

};

