#pragma once
#include <cstdarg>
#include <cstdlib>
#include <cstdarg>
#include <cstring>
#include <cstdio>

class Logger
{
public:
	Logger();
	virtual ~Logger();

	void output(char *type, const char* const formatString, va_list argumentList);
//	void operator()(char *type, const char* const formatString, ...);
	void operator()(const char* const formatString, ...);

};

extern Logger Log;