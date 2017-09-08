#pragma once
class Renderer
{
public:
	Renderer();
	virtual ~Renderer();

	virtual void Clear(bool _colorBit = true, bool _depthBit = true) = 0;
	virtual void SetClearColor(float red, float green, float blue, float alpha) = 0;


};

