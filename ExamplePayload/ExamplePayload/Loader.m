//
//  Loader.m
//  ExamplePayload
//
//  Created by Alex Turner on 12/1/14.
//  Copyright (c) 2014 Alex Turner. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <syslog.h>

#import "InjectorDelegate.h"

InjectorDelegate* main;

__attribute__((constructor))
void load()
{
	syslog(LOG_NOTICE, "Example Payload: My pid is %d\n", getpid());
	
	main = [[InjectorDelegate alloc] init];
	[main showWindow];
}

