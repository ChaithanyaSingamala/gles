#pragma once
#include "../core/common/application_base.h"
#include "glm\glm.hpp"

using namespace glm;

class Camera;
class Mesh;
class Shader;
class Texture;
class Model;
class OrbitCamera;

class ApplicationTest01 :public ApplicationBase
{
	OrbitCamera *camera = nullptr;
	bool orbitCameraMouseLock = true;
	Mesh* testMesh = nullptr;
	Mesh* testPlaneModel = nullptr;
	Mesh* testModelLightSource = nullptr;
	Shader *shader = nullptr;
	Shader *shaderForLightSource = nullptr;
	Texture *texture1 = nullptr;

	long prevTime = 0;

	Model *model;

	vec3 lightPos = vec3(1.2f, 1.0f, 2.0f);
public:
	ApplicationTest01(Renderer *_renderer);
	virtual ~ApplicationTest01();

	void Init() override;
	void Update() override {}
	void Render() override;
	virtual void ViewportChanged(int _width, int _height) override;

};

