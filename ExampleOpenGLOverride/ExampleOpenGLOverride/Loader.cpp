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

#include <mach/mach.h>
#include <pthread/pthread.h>

#include "mach_override.h"

#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>

__attribute__((constructor))
void load()
{
	syslog(LOG_NOTICE, "Example OpenGL Override: Loaded.  My pid is %d\n", getpid());
	
	kern_return_t err;
	thread_act_array_t thread_list;
	mach_msg_type_number_t thread_count;
	
	err = task_threads(mach_task_self(), &thread_list, &thread_count);
	
	if (err)
	{
		syslog(LOG_ERR, "Unable to get a list of all threads: %i", err);
		return;
	}
	
	// Suspend all other threads
	thread_port_t my_thread = pthread_mach_thread_np(pthread_self());
	
	thread_act_t* current, *original_array = thread_list;
	for (int i = 0;i < thread_count;++i, ++thread_list)
	{
		current = thread_list;
		
		if (*current == my_thread)
			continue;
		
		thread_suspend(*current);
	}
	
	MACH_OVERRIDE(void, glBegin, (GLenum node), err)
	{
		if (node == GL_TRIANGLES)
			syslog(LOG_NOTICE, "glBegin called with GL_TRIANGLES");
		else if (node == GL_QUADS)
			syslog(LOG_NOTICE, "glBegin called with GL_QUADS");
		
		glBegin_reenter(node);
	} END_MACH_OVERRIDE(glBegin);
	
	if (err)
		syslog(LOG_ERR, "Example Function Override: Error overriding function %i", err);
	
	// Unsuspend them all
	thread_list = original_array;
	for (int i = 0;i < thread_count;++i, ++thread_list)
	{
		current = thread_list;
		
		if (*current == my_thread)
			continue;
		
		thread_resume(*current);
	}
}
