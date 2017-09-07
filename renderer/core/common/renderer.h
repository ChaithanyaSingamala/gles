#pragma once
class Renderer
{
public:
	Renderer();
	virtual ~Renderer();

	virtual void Clear(bool _colorBit = true, bool _depthBit = true) = 0;

};

