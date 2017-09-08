#pragma once
class Interface
{
protected:
	int width = 800;
	int height = 600;

public:
	Interface();
	virtual ~Interface();

	virtual void Update() = 0;
};

