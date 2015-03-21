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

#import <Cocoa/Cocoa.h>

#import "SC2Controller.h"

#include "Logging.h"
#include "ThreadHelpers.h"
#include "OpenGL State Machine.h"

NSBundle* loader_bundle;
NSWindow* sc2api_window;
NSWindowController* sc2api_window_controller;
SC2Controller* sc2api_controller;

CFBundleRef state_machine_bundle;
CFBundleRef sc2api_bundle;
CFBundleRef ai_bundle;

__attribute__((constructor))
void load()
{
	// Load the logging window
	
	loader_bundle = [[NSBundle bundleWithIdentifier:@"edu.umich.Loader"] retain];
	
	NSNumber* buildNumber = [loader_bundle objectForInfoDictionaryKey:@"CWBuildNumber"];
	NSString* version = [loader_bundle objectForInfoDictionaryKey:@"CFBundleShortVersionString"];
	
	SC2::Utilities::console_log("SC2 Loader v%s (%s) (PID: %d)", [version UTF8String], [[buildNumber stringValue] UTF8String], getpid());
	
	NSArray* array;
	[loader_bundle loadNibNamed:@"SC2Window" owner:nil topLevelObjects:&array];
	
	for (id i in array)
	{
		if ([i isKindOfClass:NSWindow.class])
		{
			sc2api_window = i;
			[sc2api_window retain];
		}
	}
	
	[loader_bundle loadNibNamed:@"SC2Controller" owner:nil topLevelObjects:&array];
	
	for (id i in array)
	{
		if ([i isKindOfClass:SC2Controller.class])
		{
			sc2api_controller = i;
			[sc2api_controller retain];
		}
	}
	
	sc2api_window_controller = [[NSWindowController alloc] initWithWindow:sc2api_window];
	[sc2api_window_controller.window.contentView addSubview:sc2api_controller.view];
	sc2api_controller.view.frame = ((NSView*)sc2api_window_controller.window.contentView).frame;
	
	[sc2api_window_controller showWindow:nil];
	
	// Suspend all other threads
	SC2::Utilities::suspend_all_threads();
	
	// Load the OpenGL State Machine
	
	NSURL* state_machine_path = [NSURL URLWithString:@"/Users/bluechill/Developer/OpenGLInjector/DerivedData/OpenGLInjector/Build/Products/Debug/OpenGLStateMachine.bundle"];
	state_machine_bundle = CFBundleCreate(kCFAllocatorDefault, (CFURLRef)state_machine_path);
	
	if (!CFBundleIsExecutableLoaded(state_machine_bundle))
		CFBundleLoadExecutable(state_machine_bundle);
	
	void (*set_logging)(void* c_log, void* s_log, void* f_log, void* f_ptr_log, void* l) = (void (*)(void*, void*, void*, void*, void*))CFBundleGetFunctionPointerForName(state_machine_bundle, CFSTR("set_logging"));

	set_logging((void*)SC2::Utilities::console_log, (void*)SC2::Utilities::screen_log, (void*)SC2::Utilities::file_log, (void*)SC2::Utilities::file_log_file_ptr, (void*)SC2::Utilities::log);
	
	OpenGL::StateMachine* (*make_new_state_machine)() = (OpenGL::StateMachine* (*)())CFBundleGetFunctionPointerForName(state_machine_bundle, CFSTR("make_new_state_machine"));
	
	OpenGL::Shared = make_new_state_machine();
	
	void (*set_shared)(OpenGL::StateMachine*) = (void (*)(OpenGL::StateMachine*))CFBundleGetFunctionPointerForName(state_machine_bundle, CFSTR("set_shared"));
	
	set_shared(OpenGL::Shared);
	
	// Start Logging Functions
	
	extern void OverrideCGLGetContext();
	OverrideCGLGetContext();
	
	// End Logging Functions
	
	// Unsuspend them all
	SC2::Utilities::unsuspend_all_threads();
	
	// Load the API
	
	NSURL* sc2api_path = [NSURL URLWithString:@"/Users/bluechill/Developer/OpenGLInjector/DerivedData/OpenGLInjector/Build/Products/Debug/SC2API.bundle"];
	sc2api_bundle = CFBundleCreate(kCFAllocatorDefault, (CFURLRef)sc2api_path);
	
	if (!CFBundleIsExecutableLoaded(sc2api_bundle))
		CFBundleLoadExecutable(sc2api_bundle);
	
	// Load the AI
	
	SC2::Utilities::screen_log("Finished Loading");
}
