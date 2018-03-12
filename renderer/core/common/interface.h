#pragma once
class Interface
{
protected:
	int width = 800;
	int height = 600;

public:
	Interface();
	virtual ~Interface();

	virtual void Update() = 0;

	virtual unsigned short Width(unsigned short _width = 0) { return width = (_width == 0) ? width : _width; }
	virtual unsigned short Height(unsigned short _height = 0) { return height = (_height == 0) ? height : _height; }

};

