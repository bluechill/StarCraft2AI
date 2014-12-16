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

#include "OpenGLLogger.h"

//extern void OverrideOpenGL();
//
OpenGLLogger* logger;

//extern "C" void override();

volatile CGLContextObj ctx = 0;

void get_cgl_context()
{
	ctx = CGLGetCurrentContext();
	
	thread_suspend(mach_thread_self());
}

__attribute__((constructor))
void load()
{
	syslog(LOG_NOTICE, "OpenGLFileLogger: Loaded.  My pid is %d\n", getpid());
	
	kern_return_t err;
	thread_act_array_t thread_list;
	mach_msg_type_number_t thread_count;
	
	err = task_threads(mach_task_self(), &thread_list, &thread_count);
	
	if (err)
	{
		syslog(LOG_ERR, "OpenGLFileLogger: Unable to get a list of all threads: %i", err);
		return;
	}
	
	// Suspend all other threads
	syslog(LOG_NOTICE, "OpenGLFileLogger: Suspending all other threads.");

	thread_port_t my_thread = pthread_mach_thread_np(pthread_self());
	
	thread_act_t* current, *original_array = thread_list;
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
	
	// Start Logging Functions
	
	syslog(LOG_NOTICE, "OpenGLFileLogger: Finding OpenGL Worker Thread.");

	thread_list = original_array;
	char c_name[150];

	pthread_t opengl_thread = 0;
	thread_port_t opengl_thread_port = 0;
	
	for (int i = 0;i < thread_count;++i, ++thread_list)
	{
		pthread_t thread = pthread_from_mach_thread_np(*thread_list);
		
		pthread_getname_np(thread, c_name, 150);
		
		std::string name = c_name;
		
		if (name.find("GL") != std::string::npos)
		{
			// Found the thread
			opengl_thread = thread;
			opengl_thread_port = *thread_list;
			syslog(LOG_NOTICE, "OpenGLFileLogger: Found OpenGL Worker Thread");
			break;
		}
	}
	
	// get thread contents;
	
	if (opengl_thread)
	{
		vm_size_t stackSize = 16 * 1024;
		vm_address_t remoteStack = (vm_address_t)NULL;
		
		err = vm_allocate( mach_task_self(), &remoteStack, stackSize, 1 );
		
		if (err)
		{
			syslog(LOG_ERR, "OpenGLFileLogger: Failed to allocate stack!");
			return;
		}

		i386_thread_state_t remoteThreadState;
		bzero( &remoteThreadState, sizeof(remoteThreadState) );
		mach_msg_type_number_t sc = i386_THREAD_STATE_COUNT;
		
		err = thread_get_state(opengl_thread_port, i386_THREAD_STATE, (thread_state_t)&remoteThreadState, &sc);
		
		if (err)
		{
			syslog(LOG_ERR, "OpenGLFileLogger: Failed to retrieve thread contents!");
			return;
		}
		
		i386_thread_state_t newThreadState;
		bzero( &newThreadState, sizeof(newThreadState) );
		
		vm_address_t dummy_thread_struct = remoteStack;
		remoteStack += (stackSize / 2); // this is the real stack
		// (*) increase the stack, since we're simulating a CALL instruction, which normally pushes return address on the stack
		remoteStack -= 4;
		
#define PARAM_COUNT 0
#define STACK_CONTENTS_SIZE ((1+PARAM_COUNT) * sizeof(unsigned int))
		unsigned int stackContents[1 + PARAM_COUNT]; // 1 for the return address and 1 for each param
		// first entry is return address (see above *)
		stackContents[0] = 0xDEADBEEF; // invalid return address.
		// then we push function parameters one by one.
		
		// push stackContents
		err = vm_write( mach_task_self(), remoteStack, (pointer_t) stackContents, STACK_CONTENTS_SIZE);
		
		if (err)
		{
			syslog(LOG_ERR, "OpenGLFileLogger: Failed to write stack contents!");
			return;
		}
		
		// set remote Program Counter
		newThreadState.__eip = (unsigned int) (&get_cgl_context);
		
		// set remote Stack Pointer
		newThreadState.__esp = (unsigned int) remoteStack;
		
		// make sure it's not in a state we can't modify/control
		err = thread_abort_safely(opengl_thread_port);
		
		if (err)
		{
			syslog(LOG_ERR, "OpenGLFileLogger: Failed to abort thread!");
			return;
		}
		
		// Set up control of it.
		err = thread_set_state(opengl_thread_port, i386_THREAD_STATE, (thread_state_t)&newThreadState, sc);
		
		if (err)
		{
			syslog(LOG_ERR, "OpenGLFileLogger: Failed to set the new thread state!");
			return;
		}
		
		while (!)
	}
	
	// End Logging Functions
	
	syslog(LOG_NOTICE, "OpenGLFileLogger: Unsuspending all threads.");
	
	// Unsuspend them all
	thread_list = original_array;
	for (int i = 0;i < thread_count;++i, ++thread_list)
	{
		current = thread_list;
		
		if (*current == my_thread)
			continue;
		
		err = thread_resume(*current);
		
		if (err)
			syslog(LOG_ERR, "Failed to unsuspend thread: %i", *current);
	}
	
	syslog(LOG_NOTICE, "OpenGLFileLogger: Unsuspended all threads.");
}
