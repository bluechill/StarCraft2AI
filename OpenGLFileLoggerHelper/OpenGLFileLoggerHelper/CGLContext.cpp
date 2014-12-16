//
//  CGLContext.c
//  OpenGLFileLoggerHelper
//
//  Created by Alex Turner on 12/11/14.
//  Copyright (c) 2014 Alex Turner. All rights reserved.
//

#include <mach/mach.h>
#include <pthread/pthread.h>
#include <unistd.h>

#include <OpenGL/OpenGL.h>

#include <syslog.h>

#include "mach_override.h"

#include "ContextRetriever.h"

extern "C" {
	struct List* contextes;
}

__attribute__((constructor))
void load()
{
	syslog(LOG_NOTICE, "OpenGLFileLoggerHelper: My pid is %d\n", getpid());
	
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
	
	contextes = new List;
	contextes->value = nullptr;
	contextes->next = nullptr;
	
	MACH_OVERRIDE(CGLError, CGLCreateContext, (CGLPixelFormatObj pix, CGLContextObj share, CGLContextObj *ctx), err)
	{
		syslog(LOG_NOTICE, "OpenGLFileLoggerHelper: CGLCreateContextCalled");
		
		CGLError err = CGLCreateContext_reenter(pix, share, ctx);
		
		struct List* last_list = contextes;
		
		while (last_list->next != nullptr)
			last_list = last_list->next;
		
		last_list->value = *ctx;
		last_list->next = new List;
		
		last_list->next->value = nullptr;
		last_list->next->next = nullptr;
		
		syslog(LOG_NOTICE, "OpenGLFileLoggerHelper: New Context: %p", *ctx);
		
		return err;
		
	} END_MACH_OVERRIDE(CGLCreateContext);
	
	MACH_OVERRIDE(CGLError, CGLDestroyContext, (CGLContextObj *ctx), err)
	{
		syslog(LOG_NOTICE, "OpenGLFileLoggerHelper: CGLDestroyContext");
		
		struct List* last_list = contextes;
		struct List* prev_list = nullptr;
		
		while (last_list->next != nullptr && last_list->value != *ctx)
		{
			prev_list = last_list;
			last_list = last_list->next;
		}
		
		if (prev_list == nullptr)
			contextes = contextes->next;
		else
			prev_list->next = last_list->next;
		
		delete last_list;
		
		syslog(LOG_NOTICE, "OpenGLFileLoggerHelper: Destroyed Context: %p", *ctx);
		
		return CGLDestroyContext_reenter(ctx);
		
	} END_MACH_OVERRIDE(CGLDestroyContext);
	
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