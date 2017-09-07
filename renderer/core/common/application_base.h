#pragma once
#include <vector>

class Renderer;

class ApplicationBase
{
	static std::vector<ApplicationBase *> applicationLists;
	static int currentApplicationIndex;

protected:
	Renderer *renderer = nullptr;
public:
	ApplicationBase(Renderer *_renderer);
	virtual ~ApplicationBase();

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;

	// need to implement by test classes
	static void RegisterApplications(Renderer *_renderer);
	static void SetActiveApplication(int _value);
	static ApplicationBase *ActiveApplication();
};

