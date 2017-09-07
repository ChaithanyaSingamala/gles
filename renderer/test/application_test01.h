#pragma once
#include "../core/common/application_base.h"

class ApplicationTest01 :public ApplicationBase
{
public:
	ApplicationTest01(Renderer *_renderer);
	virtual ~ApplicationTest01();

	void Init() override {}
	void Update() override {}
	void Render() override;

};

