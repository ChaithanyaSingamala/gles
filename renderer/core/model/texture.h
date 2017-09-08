#pragma once
#include <iostream>
#include "defines.h"

class Texture
{
	int width;
	int height;
	unsigned int textureId;

	static struct _staticTextureValues
	{
		int maxTextureUnits = -1;
		int maxCombinedTextureUnits = -1;
		bool init = false;
	}staticValues;

public:
	Texture(std::string _filename);
	virtual ~Texture();
	void Bind(int _textureUnit = UINT_MAX);
	void UnBind(int _textureUnit = UINT_MAX);

	static void StaticInit();
};

