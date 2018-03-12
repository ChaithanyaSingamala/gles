#pragma once
#include "../core/common/application_base.h"

class ApplicationTest02Gears :public ApplicationBase
{
public:
	ApplicationTest02Gears(Renderer *_renderer);
	virtual ~ApplicationTest02Gears();

	void Init() override ;
	void Update() override {}
	void Render() override;
	virtual void ViewportChanged(int _width, int _height) override {}

};

