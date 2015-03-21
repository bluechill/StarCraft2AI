//
//  SC2Controller.m
//  StarCraft2API
//
//  Created by Alex Turner on 1/13/15.
//  Copyright (c) 2015 Alex Turner. All rights reserved.
//

#import "SC2Controller.h"

#include "OpenGL State Machine.h"
#include "Logging.h"

@interface SC2Controller ()

@end

extern CFBundleRef state_machine_bundle;
extern CFBundleRef sc2api_bundle;
extern CFBundleRef ai_bundle;

extern std::mutex opengl_api_mutex;

@implementation SC2Controller

@synthesize console = _console;
@synthesize reload_ai_button = _reload_ai_button;
@synthesize reload_api_button = _reload_api_button;
@synthesize reload_state_machine_button = _reload_state_machine_button;

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do view setup here.
}

- (IBAction)reloadAPI:(id)sender
{
	if (CFBundleIsExecutableLoaded(sc2api_bundle))
	{
		CFBundleUnloadExecutable(sc2api_bundle);
		CFBundleLoadExecutable(sc2api_bundle);
		
		void (*set_logging)(void* c_log, void* s_log, void* f_log, void* f_ptr_log, void* l) = (void (*)(void*, void*, void*, void*, void*))CFBundleGetFunctionPointerForName(sc2api_bundle, CFSTR("set_logging"));
		
		set_logging((void*)SC2::Utilities::console_log, (void*)SC2::Utilities::screen_log, (void*)SC2::Utilities::file_log, (void*)SC2::Utilities::file_log_file_ptr, (void*)SC2::Utilities::log);
	}
}

- (IBAction)reloadAI:(id)sender
{
	if (CFBundleIsExecutableLoaded(ai_bundle))
	{
		CFBundleUnloadExecutable(ai_bundle);
		CFBundleLoadExecutable(ai_bundle);
	}
}

- (IBAction)reloadStateMachine:(id)sender
{
	if (CFBundleIsExecutableLoaded(state_machine_bundle))
	{
		opengl_api_mutex.lock();
		
		delete OpenGL::Shared;
		
		CFBundleUnloadExecutable(state_machine_bundle);
		SC2::Utilities::screen_log("SC2 State Machine unloaded.");
		
		CFBundleLoadExecutable(state_machine_bundle);
		
		void (*set_logging)(void* c_log, void* s_log, void* f_log, void* f_ptr_log, void* l) = (void (*)(void*, void*, void*, void*, void*))CFBundleGetFunctionPointerForName(state_machine_bundle, CFSTR("set_logging"));
		
		set_logging((void*)SC2::Utilities::console_log, (void*)SC2::Utilities::screen_log, (void*)SC2::Utilities::file_log, (void*)SC2::Utilities::file_log_file_ptr, (void*)SC2::Utilities::log);
		
		OpenGL::StateMachine* (*make_new_state_machine)() = (OpenGL::StateMachine* (*)())CFBundleGetFunctionPointerForName(state_machine_bundle, CFSTR("make_new_state_machine"));
		
		OpenGL::Shared = make_new_state_machine();
		
		void (*set_shared)(OpenGL::StateMachine*) = (void (*)(OpenGL::StateMachine*))CFBundleGetFunctionPointerForName(state_machine_bundle, CFSTR("set_shared"));
		
		set_shared(OpenGL::Shared);
		
		opengl_api_mutex.unlock();
	}
}

@end
