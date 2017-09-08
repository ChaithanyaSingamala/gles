#include "application_test01.h"
#include "../core/common/renderer.h"
#include "model\orbit_camera.h"
#include "model\shader.h"
#include "model\model.h"
#include "defines.h"
#include "glm\gtc\type_ptr.hpp"
#include "test_objects.h"

ApplicationTest01::ApplicationTest01(Renderer *_renderer): ApplicationBase(_renderer)
{
}


ApplicationTest01::~ApplicationTest01()
{
}

void ApplicationTest01::Init()
{
	//load camera
	camera = new OrbitCamera();
	//load texture
	//texture1 = new Texture("resources/textures/texture_4.png");

	//load shaders
	{
		shaderForLightSource = new Shader(SHADER_RESOURCE("solid.vert"), SHADER_RESOURCE("solid.frag"));
		shaderForLightSource->Set();
		shaderForLightSource->Reset();
	}
	{
		ShaderAttribInfo infos = {
			{ "vertexPosition", VERT_POS_LOC },
			{ "vertexUV", VERT_UV0_LOC },
			{ "vertexNormal", VERT_NORMAL_LOC },
		};
		shader = new Shader(SHADER_RESOURCE("lighting01.vert"), SHADER_RESOURCE("lighting01.frag"));
		shader->Set();
		glUniform3fv(shader->GetUniformLocation("lightColor"), 1, value_ptr(glm::vec3(1.0)));
		glUniform3fv(shader->GetUniformLocation("objectColor"), 1, value_ptr(glm::vec3(1.0f, 0.5f, 0.31f)));
		shader->Reset();
	}

	//load models
	testMesh = CreateModelCube(shader);
	testPlaneModel = CreateModelPlaneXZ(shader, 5.0f);

	//light source
	lightPos = glm::vec3(1.5f, 0.0f, 0.0f);
	testModelLightSource = CreateModelCube(shaderForLightSource);



	glEnable(GL_DEPTH_TEST);

	renderer->SetClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void ApplicationTest01::Render()
{
	renderer->Clear();

	//glClearColor(0.3f, 0.1f, 0.3f, 1.0f);
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glm::vec3 newLightPos = glm::vec3(0);
	{
		static float rot = 0.0;
		rot += 0.001f;// *Engine::get()->GetDeltaTime();
		shaderForLightSource->Set();
		glUniformMatrix4fv(shaderForLightSource->GetUniformLocation("proj"), 1, GL_FALSE, glm::value_ptr(camera->GetPerspectiveMatrix()));
		glUniformMatrix4fv(shaderForLightSource->GetUniformLocation("view"), 1, GL_FALSE, glm::value_ptr(camera->GetViewMatrix()));

		testModelLightSource->ResetTransfrom();
		testModelLightSource->Rotate(glm::vec3(0.0, 1.0, 0.0), rot);
		testModelLightSource->Translate(lightPos);
		testModelLightSource->Scale(glm::vec3(0.1f));
		glm::mat4 m = testModelLightSource->GetTransfrom();
		newLightPos.x = m[3][0];
		newLightPos.y = m[3][1];
		newLightPos.z = m[3][2];
		glm::mat3 normalMat = testModelLightSource->GetTransfrom();
		normalMat = glm::inverse(normalMat);
		normalMat = glm::transpose(normalMat);
		glUniformMatrix3fv(shaderForLightSource->GetUniformLocation("normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMat));
		glUniformMatrix4fv(shaderForLightSource->GetUniformLocation("model"), 1, GL_FALSE, glm::value_ptr(testModelLightSource->GetTransfrom()));

		testModelLightSource->Render();
		shaderForLightSource->Reset();
	}

	{
		shader->Set();
		glUniformMatrix4fv(shader->GetUniformLocation("proj"), 1, GL_FALSE, glm::value_ptr(camera->GetPerspectiveMatrix()));
		glUniformMatrix4fv(shader->GetUniformLocation("view"), 1, GL_FALSE, glm::value_ptr(camera->GetViewMatrix()));
		glUniform3fv(shader->GetUniformLocation("lightPos"), 1, glm::value_ptr(newLightPos));
		glm::mat4 m = camera->GetViewMatrix();
		glm::vec3 viewPos = glm::vec3(m[3][0], m[3][1], m[3][2]);
		glUniform3fv(shader->GetUniformLocation("lightPos"), 1, glm::value_ptr(newLightPos));

		{
			glm::mat3 normalMat = testPlaneModel->GetTransfrom();
			normalMat = glm::inverse(normalMat);
			normalMat = glm::transpose(normalMat);
			glUniformMatrix3fv(shader->GetUniformLocation("normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMat));
			glUniformMatrix4fv(shader->GetUniformLocation("model"), 1, GL_FALSE, glm::value_ptr(testMesh->GetTransfrom()));
			testPlaneModel->Render();
		}

		{
			glm::mat3 normalMat = testMesh->GetTransfrom();
			normalMat = glm::inverse(normalMat);
			normalMat = glm::transpose(normalMat);
			glUniformMatrix3fv(shader->GetUniformLocation("normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMat));
			glUniformMatrix4fv(shader->GetUniformLocation("model"), 1, GL_FALSE, glm::value_ptr(testMesh->GetTransfrom()));
			testMesh->Render();
		}


		shader->Reset();
	}
}
