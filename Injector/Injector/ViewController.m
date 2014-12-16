//
//  ViewController.m
//  Injector
//
//  Created by Alex Turner on 11/25/14.
//  Copyright (c) 2014 Alex Turner. All rights reserved.
//

#import "ViewController.h"

#import <sys/proc.h>
#import <sys/proc_info.h>
#import <libproc.h>

#import <Carbon/Carbon.h>
#import <dlfcn.h>

#include "mach_inject_bundle_pid.h"

@implementation ViewController

- (void)viewDidLoad {
	[super viewDidLoad];

	// Do any additional setup after loading the view.
}

- (void)setRepresentedObject:(id)representedObject {
	[super setRepresentedObject:representedObject];

	// Update the view, if already loaded.
}

- (IBAction)SelectBundle:(id)sender
{
	// Create a File Open Dialog class.
	NSOpenPanel* openDlg = [NSOpenPanel openPanel];
	
	// Set array of file types
	NSArray *fileTypesArray = [NSArray arrayWithObjects:@"inject", @"bundle", nil];
	
	// Enable options in the dialog.
	[openDlg setCanChooseFiles:YES];
	[openDlg setAllowedFileTypes:fileTypesArray];
	[openDlg setAllowsMultipleSelection:NO];
	
	// Display the dialog box.  If the OK pressed,
	// process the files.
	if ([openDlg runModal] == NSModalResponseOK)
	{
		// Gets list of all files selected
		NSArray *files = [openDlg URLs];
		
		if (files.count > 0)
			bundlePath = [files objectAtIndex:0];
	}
	
	if (bundlePath)
		[pathLabel setStringValue:[NSString stringWithFormat:@"Bundle: %@", [bundlePath path]]];
}

- (IBAction)SelectProcess:(id)sender
{
	pid = [pidInputField.stringValue integerValue];
	
	if (pid <= 0)
		return;
	
	int numberOfProcesses = proc_listpids(PROC_ALL_PIDS, 0, NULL, 0);
	pid_t pids[1024];
	bzero(pids, 1024);
	proc_listpids(PROC_ALL_PIDS, 0, pids, sizeof(pids));
	
	bool found = false;
	for (int i = 0; i < numberOfProcesses; ++i) {
		if (pids[i] == 0 || pids[i] != pid)
			continue;
		
		char pathBuffer[PROC_PIDPATHINFO_MAXSIZE];
		bzero(pathBuffer, PROC_PIDPATHINFO_MAXSIZE);
		proc_pidpath(pids[i], pathBuffer, sizeof(pathBuffer));
		
		NSString* pathString = [NSString stringWithUTF8String:pathBuffer];
		
		if ([pathString length] == 0)
			continue;
		
		NSUInteger index = 0;
		
		for (int i = 0;i < [pathString length];++i)
		{
			if ([pathString characterAtIndex:i] == '/')
				index = i+1;
		}
		
		[pidLabel setStringValue:[NSString stringWithFormat:@"Process: %@", [pathString substringFromIndex:index]]];
		found = true;
		
		break;
	}
	
	if (!found)
		[pidLabel setStringValue:@"Process: None"];
}

- (IBAction)InjectIntoProcess:(id)sender
{
	mach_error_t error = 0;
 
	if (!bundlePath)
		error = 99;
	else if (pid == 0)
		error = 100;
	else
		error = mach_inject_bundle_pid([[bundlePath path] UTF8String], (int)pid);
	
	NSString* errorString = [NSString stringWithFormat:@"Error Injecting into process (%lu) the bundle (%@) with error: ", pid, [bundlePath path]];
	
	switch (error) {
		case 99:
			errorString = [errorString stringByAppendingString:@"No bundle was specified"];
			break;
		case 100:
			errorString = [errorString stringByAppendingString:@"No process was specified"];
			break;
		case err_mach_inject_bundle_couldnt_find_injection_bundle:
			errorString = [errorString stringByAppendingString:@"Couldn't find injection bundle"];
			break;
		case err_mach_inject_bundle_couldnt_load_injection_bundle:
			errorString = [errorString stringByAppendingString:@"Couldn't load injection bundle"];
			break;
		case err_mach_inject_bundle_couldnt_find_inject_entry_symbol:
			errorString = [errorString stringByAppendingString:@"Couldn't find injection entry symbol"];
			break;
		default:
			errorString = [errorString stringByAppendingFormat:@"Error injecting into process with error: %d", error];
			break;
	}

	if (error)
	{
		NSAlert* alert = [[NSAlert alloc] init];
		[alert addButtonWithTitle:@"OK"];
		[alert setMessageText:errorString];
		[alert setAlertStyle:NSWarningAlertStyle];
		
		[alert runModal];
	}
}

@end
