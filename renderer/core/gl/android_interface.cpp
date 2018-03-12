#include "android_interface.h"

#ifdef ENABLE_ANDROID_INTERFACE

#include "../common/log.h"
#include <string>
#include "../common/options.h"


AndroidInterface::AndroidInterface()
{
	Log("Starting AndroidInterface...");
	Setup();
}


AndroidInterface::~AndroidInterface()
{
	Log("Exiting AndroidInterface...");
}

void AndroidInterface::Update()
{
	
}

#endif
