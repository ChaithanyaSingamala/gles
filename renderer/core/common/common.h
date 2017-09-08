#pragma once

#include <string>
#include <assert.h>
#include "glm/glm.hpp"

using namespace glm;

class Common
{
public:
	Common();
	virtual ~Common();
	static mat4 perspectiveMatrix;
	static mat4 viewMatrix;
	static vec3 light1Pos;
};

#if 0
void ASSERT(char *str);
#else
#define ASSERT(str)		assert(0 && str)
#endif
std::string GetFromCommandOption(std::string _for_value);
std::string ReadFromFile(std::string _filename);

