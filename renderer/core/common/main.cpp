#include <stdio.h>
#include "gl/glrenderer.h"
#include "gl/egl_interface.h"
#include "log.h"
#include "options.h"
#include <string>
#include "application_base.h"
#include "interface.h"

int main(int argc, char **argv)
{
	Log("Staring ...");
	options(argc, argv);

	if (options == "-renderer");
	else
	{
		options + "-renderer";
		options + "gl";
	}
	Interface *interfaceI = nullptr;
	Renderer *renderer = nullptr;

	std::string value;
	value = options("-renderer");
	if(value == "gl")
	{
#ifdef ENABLE_EGL
        interfaceI = new EGLInterface();
#endif
		renderer = new GLRenderer();
	}

	ApplicationBase::RegisterApplications(renderer);

	ApplicationBase::ActiveApplication()->Init();
	ApplicationBase::ActiveApplication()->ViewportChanged(interfaceI->Width(), interfaceI->Height());
	bool done = false;
	while (!done)
	{
		if(interfaceI)
			interfaceI->Update();
		ApplicationBase::ActiveApplication()->Update();
		ApplicationBase::ActiveApplication()->Render();
	}

	delete interfaceI;
	interfaceI = nullptr;
	delete renderer;
	renderer = nullptr;
	Log("Exiting ...");
}