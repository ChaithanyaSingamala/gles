#include "shader.h"
#include <iostream>
#include "common\common.h"
#include "gl\opengl_header.h"
#include "common\log.h"

//#define SHADER_CHECK_STATUS	1

#ifdef SHADER_CHECK_STATUS
bool CheckStatus(unsigned int objectID, PFNGLGETSHADERIVPROC objectPropertyGetterFunc, PFNGLGETSHADERINFOLOGPROC getInfoLogFunc, GLenum statusType);
#endif

Shader::Shader()
{

}

Shader::Shader(std::string _vertexShaderFile, std::string _fragmentShaderFile, ShaderAttribInfo _vertexAttributeLocs)
{
	std::string vertShaderCode = ReadFromFile(_vertexShaderFile);
	std::string fragShaderCode = ReadFromFile(_fragmentShaderFile);

	CompileShaderCode(vertShaderCode, fragShaderCode);
	InitAttribLocations(_vertexAttributeLocs);
}

Shader::Shader(std::string _vertexShaderFile, std::string _fragmentShaderFile)
{
	std::string vertShaderCode = ReadFromFile(_vertexShaderFile);
	std::string fragShaderCode = ReadFromFile(_fragmentShaderFile);

	CompileShaderCode(vertShaderCode, fragShaderCode);

	ShaderAttribInfo vertexAttributeLocs = {
		{ "vertexPosition", VERT_POS_LOC },
		{ "vertexColor", VERT_COLOR_LOC },
		{ "vertexNormal", VERT_NORMAL_LOC },
		{ "vertexUV", VERT_UV0_LOC },
		{ "vertexUV1", VERT_UV1_LOC },
	};

	InitAttribLocations(vertexAttributeLocs);
}

void Shader::CompileShaderCode(std::string _shaderCodeVert, std::string _shaderCodeFrag)
{
	vertShaderId = CompileShaderCode(_shaderCodeVert, GL_VERTEX_SHADER);
	fragShaderId = CompileShaderCode(_shaderCodeFrag, GL_FRAGMENT_SHADER);

	programId = glCreateProgram();
	glAttachShader(programId, vertShaderId);
	glAttachShader(programId, fragShaderId);

	glLinkProgram(programId);

#ifdef SHADER_CHECK_STATUS
	CheckStatus(programId, glGetProgramiv, glGetProgramInfoLog, GL_LINK_STATUS);
#endif
}

void Shader::InitAttribLocations(ShaderAttribInfo _vertexAttributeLocs)
{
	for (auto info : _vertexAttributeLocs)
		attrribLocations[info.second] = glGetAttribLocation(programId, info.first.c_str());
}

Shader::~Shader()
{
	Reset();
	glDetachShader(programId, vertShaderId);
	glDetachShader(programId, fragShaderId);
	glDeleteShader(vertShaderId);
	glDeleteShader(fragShaderId);
	glDeleteProgram(programId);
	programId = 0;
	vertShaderId = 0;
	fragShaderId = 0;
}

int Shader::GetUniformLocation(std::string _uniform)
{
	int locPlusOne = uniformInfos[_uniform.c_str()];
	if (locPlusOne == 0)
		locPlusOne = uniformInfos[_uniform.c_str()] = glGetUniformLocation(programId, _uniform.c_str()) + 1;
	return locPlusOne - 1;
}

int Shader::GetAttribLocation(int _attrib)
{
	return attrribLocations[_attrib];
}


void Shader::UpdateUniform(std::string _uniform, int value)
{
	glUniform1i(GetUniformLocation(_uniform), value);
}

void Shader::Set()
{
	glUseProgram(programId);
}

void Shader::Reset()
{
	glUseProgram(0);
}

#ifdef SHADER_CHECK_STATUS
bool CheckStatus(unsigned int objectID, PFNGLGETSHADERIVPROC objectPropertyGetterFunc, PFNGLGETSHADERINFOLOGPROC getInfoLogFunc, GLenum statusType)
{
	int status;
	objectPropertyGetterFunc(objectID, statusType, &status);
	if (status != GL_TRUE)
	{
		int infoLogLength;
		objectPropertyGetterFunc(objectID, GL_INFO_LOG_LENGTH, &infoLogLength);
		GLchar* buffer = new GLchar[infoLogLength];

		GLsizei bufferSize;
		getInfoLogFunc(objectID, infoLogLength, &bufferSize, buffer);
		Log("Info: ", "%s", buffer);
		ASSERT("failed in compile shader");
		delete[] buffer;
		return false;
	}
	return true;
}
#endif
unsigned int Shader::CompileShaderCode(std::string _shaderCode, unsigned int _shaderType)
{
	unsigned int shaderId = glCreateShader(_shaderType);
	const GLchar* code[1] = { _shaderCode.c_str() };
	glShaderSource(shaderId, 1, code, 0);
	glCompileShader(shaderId);

#ifdef SHADER_CHECK_STATUS
	CheckStatus(shaderId, glGetShaderiv, glGetShaderInfoLog, GL_COMPILE_STATUS);
#endif

	return shaderId;
}