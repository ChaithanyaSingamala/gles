#include "application_test01.h"
#include "application_test02_gears.h"


void ApplicationBase::RegisterApplications(Renderer *_renderer)
{
	applicationLists.push_back(new ApplicationTest01(_renderer));
	applicationLists.push_back(new ApplicationTest02Gears(_renderer));

	SetActiveApplication(0);
}

