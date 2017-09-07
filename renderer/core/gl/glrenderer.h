#pragma once
#include "../common/renderer.h"

class GLRenderer : public Renderer
{
	void Setup();
public:
	GLRenderer();
	virtual ~GLRenderer();

	void Clear(bool _colorBit = true, bool _depthBit = true);

};

