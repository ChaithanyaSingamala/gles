#pragma once

#include "gl\opengl_header.h"

#ifdef ENABLE_ANDROID_INTERFACE

#include "../common/interface.h"


class AndroidInterface : public Interface
{

public:
	AndroidInterface();
	virtual ~AndroidInterface();

	virtual void Update() override;

};

#endif

