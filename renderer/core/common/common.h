#pragma once

#include <string>
#include <assert.h>
#include "glm/glm.hpp"

#ifdef _WIN32
#else
#include <sys/time.h>
#endif

using namespace glm;

class Common
{
public:
	Common();
	virtual ~Common();
	static mat4 perspectiveMatrix;
	static mat4 viewMatrix;
	static vec3 light1Pos;
};

#if 0
void ASSERT(char *str);
#else
#define ASSERT(str)		assert(0 && str)
#endif
std::string GetFromCommandOption(std::string _for_value);
std::string ReadFromFile(std::string _filename);

#if BUILD_ANDRIOD
	#include <android/log.h>
	#define  LOG_TAG    "OpenGLES-android"
	#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
	#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
	#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
#else
	#define  LOGI(...)  printf(__VA_ARGS__)
	#define  LOGD(...)  printf(__VA_ARGS__)
	#define  LOGE(...)  printf(__VA_ARGS__)
#endif

long currentTimeInMS();
