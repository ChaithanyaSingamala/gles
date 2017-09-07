#include "application_test01.h"


void ApplicationBase::RegisterApplications(Renderer *_renderer)
{
	applicationLists.push_back(new ApplicationTest01(_renderer));

	SetActiveApplication(0);
}

