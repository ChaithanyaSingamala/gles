#include "application_base.h"

int ApplicationBase::currentApplicationIndex = -1;

std::vector<ApplicationBase *> ApplicationBase::applicationLists;

ApplicationBase::ApplicationBase(Renderer *_renderer):renderer(_renderer)
{
}


ApplicationBase::~ApplicationBase()
{
}

void ApplicationBase::SetActiveApplication(int _value)
{
	if (_value < applicationLists.size())
		currentApplicationIndex = _value;
}

ApplicationBase * ApplicationBase::ActiveApplication()
{
	if(currentApplicationIndex < 0 || currentApplicationIndex >= applicationLists.size())
		return nullptr;
	return applicationLists[currentApplicationIndex];
}
