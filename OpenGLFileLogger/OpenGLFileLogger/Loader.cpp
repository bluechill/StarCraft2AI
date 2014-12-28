//
//  Loader.cpp
//  OpenGLFileLogger
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

#include <mach/mach.h>
#include <pthread/pthread.h>

#include "mach_override.h"

#include <OpenGL/OpenGL.h>
#include <dlfcn.h>

#include <OpenGL/CGLContext.h>

void suspend_all_threads()
{
	kern_return_t err;
	thread_act_array_t thread_list;
	mach_msg_type_number_t thread_count;
	
	err = task_threads(mach_task_self(), &thread_list, &thread_count);
	
	if (err)
	{
		syslog(LOG_ERR, "OpenGLFileLogger: Unable to get a list of all threads: %i", err);
		return;
	}
	
	syslog(LOG_NOTICE, "OpenGLFileLogger: Suspending all other threads.");
	
	thread_port_t my_thread = pthread_mach_thread_np(pthread_self());
	
	thread_act_t* current;
	for (int i = 0;i < thread_count;++i, ++thread_list)
	{
		current = thread_list;
		
		if (*current == my_thread)
			continue;
		
		err = thread_suspend(*current);
		
		if (err)
			syslog(LOG_ERR, "Failed to suspend thread: %i", *current);
	}
	
	syslog(LOG_NOTICE, "OpenGLFileLogger: Suspended all other threads.");
}

void unsuspend_all_threads()
{
	kern_return_t err;
	thread_act_array_t thread_list;
	mach_msg_type_number_t thread_count;
	
	err = task_threads(mach_task_self(), &thread_list, &thread_count);
	
	if (err)
	{
		syslog(LOG_ERR, "OpenGLFileLogger: Unable to get a list of all threads: %i", err);
		return;
	}
	
	syslog(LOG_NOTICE, "OpenGLFileLogger: Unsuspending all other threads.");
	
	thread_port_t my_thread = pthread_mach_thread_np(pthread_self());
	
	thread_act_t* current;
	for (int i = 0;i < thread_count;++i, ++thread_list)
	{
		current = thread_list;
		
		if (*current == my_thread)
			continue;
		
		err = thread_resume(*current);
		
		if (err)
			syslog(LOG_ERR, "Failed to suspend thread: %i", *current);
	}
	
	syslog(LOG_NOTICE, "OpenGLFileLogger: Unsuspended all other threads.");
}

__attribute__((constructor))
void load()
{
	syslog(LOG_NOTICE, "OpenGLFileLogger: Loaded.  My pid is %d\n", getpid());
	
	// Suspend all other threads
	suspend_all_threads();
	
	// Start Logging Functions
	
	extern void OverrideCGLGetContext();
	OverrideCGLGetContext();
	
	// End Logging Functions
	
	// Unsuspend them all
	unsuspend_all_threads();
}
