#include "camera1.h"
//#include "engine.h"
//#include "interface\neon_interface.h"

void Camera1::HandleKeyInput(int key, int action)
{
	if (action > 0)
	{
		//switch (key)
		//{
		//case 87://w
		//	ProcessKeyboard(FORWARD, (GLfloat)Engine::get()->GetDeltaTime());
		//	break;
		//case 83://s
		//	ProcessKeyboard(BACKWARD, (GLfloat)Engine::get()->GetDeltaTime());
		//	break;
		//case 65://a
		//	ProcessKeyboard(ORBIT_LEFT, (GLfloat)Engine::get()->GetDeltaTime());
		//	break;
		//case 68://d
		//	ProcessKeyboard(ORBIT_RIGHT, (GLfloat)Engine::get()->GetDeltaTime());
		//	break;
		//case 341:	//left ctl
		//case 345:	//right ctl
		//	freeCameraMouseLock = false;
		//	break;

		//}
	}
	else if (action == 0)
	{
		switch (key)
		{
		case 341:	//left ctl
		case 345:	//right ctl
			freeCameraMouseLock = true;
			break;
		}
	}
	else if (action == 1)
	{
		switch (key)
		{
		case 341:	//left ctl
		case 345:	//right ctl
			freeCameraMouseLock = false;
			break;
		}
	}
	//std::cout << "key " << key << " " << action << " " << std::endl;
}

void Camera1::HandleMouseButtonInputs(int button, int action)
{
	if (button == 1)
	{
		if (action == 1)
			freeCameraMouseLock = false;
		else
			freeCameraMouseLock = true;
	}
	if (button == 0)
	{
		if (action == 1)
			orbitCameraMouseLock = false;
		else
			orbitCameraMouseLock = true;
	}
	//std::cout << "mouse button " << button << " " << action << " " << std::endl;
}

void Camera1::HandleMouseScrollInputs(double xoffset, double yoffset)
{
	if(!freeCameraMouseLock)
		ProcessMouseScroll((GLfloat)yoffset);

	//std::cout << "mouse scroll " << xoffset << " " << yoffset << " " << std::endl;
}

void Camera1::HandleMouseCursorInputs(double xpos, double ypos)
{
	if (firstMouse)
	{
		lastX = (GLfloat)xpos;
		lastY = (GLfloat)ypos;
		firstMouse = false;
	}

	GLfloat xoffset = (GLfloat)(xpos - lastX);
	GLfloat yoffset = (GLfloat)(lastY - ypos);  // Reversed since y-coordinates go from bottom to left

	lastX = (GLfloat)xpos;
	lastY = (GLfloat)ypos;

	if (!freeCameraMouseLock)
	{
		ProcessMouseMovement((GLfloat)xoffset, (GLfloat)yoffset);
	}
	//if (!orbitCameraMouseLock)
	//	ProcessMouseMovementCameraOrbit((GLfloat)xoffset, (GLfloat)yoffset);

	//std::cout << "mouse cursor " << xpos << " " << ypos << " " << std::endl;
}

glm::mat4 Camera1::GetPerspectiveMatrix()
{
	int width = 800;
	int height = 600;
	return glm::perspective(glm::radians(Zoom), width/ (float)height, 0.1f, 1000.0f);
}

Camera1::Camera1(glm::vec3 position, glm::vec3 up, GLfloat yaw, GLfloat pitch)
{
	this->Position = position; 
	this->WorldUp = up;
	this->Yaw = yaw;
	this->Pitch = pitch;
	this->updateCameraVectors();
}

Camera1::Camera1(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat upX, GLfloat upY, GLfloat upZ, GLfloat yaw, GLfloat pitch)
{
	this->Position = glm::vec3(posX, posY, posZ);
	this->WorldUp = glm::vec3(upX, upY, upZ);
	this->Yaw = yaw;
	this->Pitch = pitch;
	this->updateCameraVectors();
}

