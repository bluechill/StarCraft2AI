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

NSBundle* sc2api_bundle;
NSWindow* sc2api_window;
NSWindowController* sc2api_window_controller;
SC2Controller* sc2api_controller;

__attribute__((constructor))
void load()
{
	SC2::Utilities::console_log("Loaded.  My pid is %d\n", getpid());
	
	// Suspend all other threads
	SC2::Utilities::suspend_all_threads();
	
	// Start Logging Functions
	
	extern void OverrideCGLGetContext();
	OverrideCGLGetContext();
	
	// End Logging Functions
	
	// Unsuspend them all
	SC2::Utilities::unsuspend_all_threads();
	
	// Load the logging window
	
	sc2api_bundle = [[NSBundle bundleWithIdentifier:@"edu.umich.StarCraft2API"] retain];
	
	NSArray* array;
	[sc2api_bundle loadNibNamed:@"SC2Window" owner:nil topLevelObjects:&array];
	
	for (id i in array)
	{
		if ([i isKindOfClass:NSWindow.class])
		{
			sc2api_window = i;
			[sc2api_window retain];
		}
	}
	
	[sc2api_bundle loadNibNamed:@"SC2Controller" owner:nil topLevelObjects:&array];
	
	for (id i in array)
	{
		if ([i isKindOfClass:SC2Controller.class])
		{
			sc2api_controller = i;
			[sc2api_controller retain];
		}
	}
	
	sc2api_window.contentView = sc2api_controller.view;
	
	sc2api_window_controller = [[NSWindowController alloc] initWithWindow:sc2api_window];
	[sc2api_window_controller showWindow:nil];
}
