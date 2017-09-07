#pragma once
class Interface
{
public:
	Interface();
	virtual ~Interface();

	virtual void Update() = 0;
};

