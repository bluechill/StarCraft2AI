//
//  InjectorDelegate.h
//  ExamplePayload
//
//  Created by Alex Turner on 12/1/14.
//  Copyright (c) 2014 Alex Turner. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Cocoa/Cocoa.h>

@interface InjectorDelegate : NSViewController
{
	NSWindowController* controller;
}

- (void) showWindow;

- (IBAction)injectButton:(id)sender;

@end
