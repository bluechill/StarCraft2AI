//
//  InjectorDelegate.m
//  ExamplePayload
//
//  Created by Alex Turner on 12/1/14.
//  Copyright (c) 2014 Alex Turner. All rights reserved.
//

#import "InjectorDelegate.h"

@implementation InjectorDelegate

- (void)showWindow
{
	controller = [[NSWindowController alloc] initWithWindowNibName:@"InjectorDelegate" owner:self];
	[controller loadWindow];
	[controller showWindow:nil];
	[controller.window makeKeyAndOrderFront:NSApp];
}

- (IBAction)injectButton:(id)sender
{
	NSAlert* alert = [[NSAlert alloc] init];
	[alert setMessageText:@"Injected!"];
	
	[alert runModal];
}

@end
