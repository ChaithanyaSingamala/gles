#pragma once
#include <stdarg.h>
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <vector>

class Options
{
	std::vector<std::string> commandLineArguments;
public:
	Options();
	virtual ~Options();
	void operator()(int argc, char **argv);

	std::string operator()(std::string);
	void operator+(std::string);
	bool operator==(std::string);

};

extern Options options;