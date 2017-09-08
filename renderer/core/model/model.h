#pragma once

#include <vector>
#include <iostream>
#include "glm\glm.hpp"

using namespace glm;

//#ifndef ANDROID_BUILD
//#include "assimp/Importer.hpp"
//#include "assimp/scene.h"
//#include "assimp/postprocess.h"
//#endif

struct VertexAttributeInfo
{
	bool isSet = false;
	int locationId = 0;
	unsigned char start = 0;
	unsigned char offset = 0;
	unsigned char size = 0;
	VertexAttributeInfo() {}
	VertexAttributeInfo(bool _isSet, int _locationId, unsigned char _start, unsigned char _offset, unsigned char _size):
		isSet(_isSet),
		locationId(_locationId),
		start(_start),
		offset(_offset),
		size(_size)
	{};
};
class MeshDataLayout
{
public:
	VertexAttributeInfo position;
	VertexAttributeInfo color;
	VertexAttributeInfo uv;
	VertexAttributeInfo normal;
};

class Mesh;

class Model
{
	std::vector<Mesh*> meshes;
	std::string directory;

	mat4 transform = mat4(1);

public:
	Model(std::string _fileName);
//#ifndef ANDROID_BUILD
//    void ProcessNode(aiNode * node, const aiScene * scene);
//	Mesh* ProcessMesh(aiMesh * mesh, const aiScene * scene);
//#endif
    virtual ~Model();

	Mesh* GetMesh(int index);

	void SetTransformation(vec3 _pos, vec3 _rot, vec3 _scale);
	void Translate(vec3 _pos);
	void Rotate(vec3 _axis, float32 angle);
	void Scale(vec3 _scale);

	mat4 GetTransfrom();
	void ResetTransfrom();

	void Render();
};

class Mesh
{
	unsigned int voaId = 0;
	unsigned int vertexCount = 0;
	std::vector<unsigned int> vbos;

	bool usingIndexBuffer = false;

	void CreateVAO();
	void CreateVBO(std::vector<float> _data, MeshDataLayout _layout);
	void CreateIBO(std::vector<unsigned short> _data);
	void SetVertexAttribute(VertexAttributeInfo _info);
	void BindVAO();
	void UnbindVAO();

	mat4 transform = mat4(1);

public:
	Mesh(std::vector<float> _vertexData);
	Mesh(std::vector<float> _vertexData, std::vector<unsigned short> _indices);
	Mesh(std::vector<float> _vertexData, std::vector<unsigned short> _indices, MeshDataLayout _layout);
	virtual ~Mesh();

	void SetTransformation(vec3 _pos, vec3 _rot, vec3 _scale);
	void Translate(vec3 _pos);
	void Rotate(vec3 _axis, float32 angle);
	void Scale(vec3 _scale);

	mat4 GetTransfrom();
	void ResetTransfrom();

	void Render();
};	

