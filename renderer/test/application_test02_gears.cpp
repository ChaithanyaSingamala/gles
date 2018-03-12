#include "application_test02_gears.h"
#include "../core/common/renderer.h"

ApplicationTest02Gears::ApplicationTest02Gears(Renderer *_renderer): ApplicationBase(_renderer)
{
	
}


ApplicationTest02Gears::~ApplicationTest02Gears()
{
}

void ApplicationTest02Gears::Init()
{
	renderer->SetClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void ApplicationTest02Gears::Render()
{
	renderer->SetClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	renderer->Clear();
}
