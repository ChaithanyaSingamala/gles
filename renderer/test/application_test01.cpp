#include "application_test01.h"
#include "../core/common/renderer.h"

ApplicationTest01::ApplicationTest01(Renderer *_renderer): ApplicationBase(_renderer)
{
}


ApplicationTest01::~ApplicationTest01()
{
}

void ApplicationTest01::Render()
{
	renderer->Clear();
}
