#pragma once

#define PATH_SEPRATER	"/"

#ifdef ANDROID_BUILD
#define RESOURCES_PATH	""
#else
#define RESOURCES_PATH	"resources/"
#endif

#define SHADER_PATH(x)	

#ifndef UINT_MAX
#define UINT_MAX      0xffffffff    // maximum unsigned int value
#endif

#ifndef APIENTRY
#define APIENTRY
#endif
#ifndef APIENTRYP
#define APIENTRYP
#endif
