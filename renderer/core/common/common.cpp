#include "common.h"
#include "defines.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <stdint.h> // portable: uint64_t   MSVC: __int64 

// MSVC defines this in winsock2.h!?
typedef struct timeval {
	long tv_sec;
	long tv_usec;
} timeval;

int gettimeofday(struct timeval * tp, struct timezone * tzp)
{
	// Note: some broken versions only have 8 trailing zero's, the correct epoch has 9 trailing zero's
	// This magic number is the number of 100 nanosecond intervals since January 1, 1601 (UTC)
	// until 00:00:00 January 1, 1970 
	static const uint64_t EPOCH = ((uint64_t)116444736000000000ULL);

	SYSTEMTIME  system_time;
	FILETIME    file_time;
	uint64_t    time;

	GetSystemTime(&system_time);
	SystemTimeToFileTime(&system_time, &file_time);
	time = ((uint64_t)file_time.dwLowDateTime);
	time += ((uint64_t)file_time.dwHighDateTime) << 32;

	tp->tv_sec = (long)((time - EPOCH) / 10000000L);
	tp->tv_usec = (long)(system_time.wMilliseconds * 1000);
	return 0;
}
#endif

#if ANDROID_BUILD
#include "AndroidHelper.h"
#endif

vec3 Common::light1Pos = vec3(0);
mat4 Common::perspectiveMatrix = mat4(1);
mat4 Common::viewMatrix = mat4(1);

Common::Common()
{
}


Common::~Common()
{
}

#if 0
void ASSERT(char *str)
{
	std::cout << "assert::" << str  << std::endl << "exiting..." <<std::endl;
	assert(0 && str);
	exit(0);
}
#endif

#if BUILD_ANDROID
#include "AndroidHelper.h"
#endif
std::string ReadFromFile(std::string _filename)
{
#if INTERFACE_SDL
	SDL_RWops *file = SDL_RWFromFile(_filename.c_str(), "r");
	if (file == NULL) ASSERT("file not found");

	Sint64 res_size = SDL_RWsize(file);
	char* res = (char*)malloc(res_size + 1);

	Sint64 nb_read_total = 0, nb_read = 1;
	char* buf = res;
	while (nb_read_total < res_size && nb_read != 0) {
		nb_read = SDL_RWread(file, buf, 1, (res_size - nb_read_total));
		nb_read_total += nb_read;
		buf += nb_read;
	}
	SDL_RWclose(file);
	if (nb_read_total != res_size) {
		free(res);
		return NULL;
	}

	res[nb_read_total] = '\0';

	std::string output = res;
	free(res);

	return output;

#else
#if ANDROID_BUILD
    std::string output = AndroidHelper::openTextFile(_filename.c_str());
#else
	LOGD("\ntring to read file %s", _filename.c_str());
	std::ifstream file(_filename);
	if (!file.good())
		ASSERT("fail to open file");

    std::string output = std::string(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
	//LOGD("\n@@@@@@@@@@@@@@@   \n%s\n   #########################\n", output.c_str());
#endif
	return output;
#endif
	
}

long currentTimeInMS() 
{
	struct timeval tv;
	gettimeofday(&tv, (struct timezone *) NULL);
	return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}
