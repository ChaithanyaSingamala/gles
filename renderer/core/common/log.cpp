#include "log.h"

Logger Log;

Logger::Logger()
{
}


Logger::~Logger()
{
}

void Logger::output(char *type, const char* const formatString, va_list argumentList)
{
	static char buffer[4096];
	va_list tempList;
	memset(buffer, 0, sizeof(buffer));
#if (defined _MSC_VER) // Pre VS2013
	tempList = argumentList;
#else
	va_copy(tempList, argumentList);
#endif
	vsnprintf(buffer, 4095, formatString, argumentList);

	printf("%s", type);
	vprintf(formatString, tempList);
	printf("\n");
}

//void Logger::operator()(char *type, const char* const formatString, ...)
//{
//	va_list argumentList;
//	va_start(argumentList, formatString);
//	output(type, formatString, argumentList);
//	va_end(argumentList);
//
//}
void Logger::operator()(const char* const formatString, ...)
{
	va_list argumentList;
	va_start(argumentList, formatString);
	output("Info: ", formatString, argumentList);
	va_end(argumentList);
}