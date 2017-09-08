#pragma once
#include <string>
#include <vector>
#include <map>
#include "gl/opengl_header.h"

#define SHADER_RES_DIR	"shaders/"
#define SHADER_RESOURCE(x)		RESOURCES_PATH SHADER_RES_DIR GLSL_VERSION PATH_SEPRATER x


typedef std::vector<std::pair<std::string, unsigned short>> ShaderAttribInfo;

class Shader
{
	unsigned int programId = 0;
	unsigned int vertShaderId = 0;
	unsigned int fragShaderId = 0;
	
	std::map<std::string, int> uniformInfos;

	int attrribLocations[VERT_ATTRIB_MAX];

	unsigned int	CompileShaderCode(std::string _shaderCode, unsigned int _shaderType);
public:
	
	Shader();
	Shader(std::string _vertexShaderFile, std::string _fragmentShaderFile, ShaderAttribInfo vertexAttributeLocs);
	Shader(std::string _vertexShaderFile, std::string _fragmentShaderFile);
	virtual ~Shader();

	void CompileShaderCode(std::string _shaderCodeVert, std::string _shaderCodeFrag);
	void InitAttribLocations(ShaderAttribInfo _vertexAttributeLocs);

	int GetUniformLocation(std::string _uniform);
	int GetAttribLocation(int _attrib);
	void UpdateUniform(std::string _uniform, int value);
	void Set();
	void Reset();
};

