//
//  Loader.cpp
//  ExampleFunctionOverride
//
//  Created by Alex Turner on 12/1/14.
//  Copyright (c) 2014 Alex Turner. All rights reserved.
//

#include <syslog.h>
#include <unistd.h>
#include <stdio.h>
#include <cassert>
#include <string>

#include <cstdarg>

#include "mach_override.h"

__attribute__((constructor))
void load()
{
	syslog(LOG_NOTICE, "Example Function Override: Loaded.  My pid is %d\n", getpid());
	
	kern_return_t err;
	
	MACH_OVERRIDE( void, syslog, (int priority, const char* message, ...), err ) {
		va_list list;
		va_start(list, message);
		
		std::string cpp_message;
		cpp_message = message;
		cpp_message.insert(0, "Overwritten: ");
		
		vsyslog(priority, cpp_message.c_str(), list);
	} END_MACH_OVERRIDE(syslog);
	
	if (err)
	{
		syslog(LOG_ERR, "Example Function Override: Error overriding function %i", err);
		
		return;
	}
	
	syslog(LOG_ERR, "Test?");
}
