#include "options.h"

Options options;

Options::Options()
{
}


Options::~Options()
{
}

std::string Options::operator()(std::string _arg)
{
	std::string resultStr = "";
	std::vector<std::string> list = commandLineArguments;
	auto result = std::find(list.begin(), list.end(), _arg);
	if (result != list.end())
	{
		resultStr = "set";
		if (result + 1 != list.end())
		{
			resultStr = *(result + 1);
		}
	}
	return resultStr;
}

void Options::operator+(std::string _value)
{
	commandLineArguments.push_back(_value);
}

bool Options::operator==(std::string _arg)
{
	std::vector<std::string> list = commandLineArguments;
	auto result = std::find(list.begin(), list.end(), _arg);
	if (result != list.end())
		return true;

	return false;
}

void Options::operator()(int argc, char ** argv)
{
	for (int i = 0; i < argc; i++)
		commandLineArguments.push_back(argv[i]);
}