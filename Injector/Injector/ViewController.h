//
//  ViewController.h
//  Injector
//
//  Created by Alex Turner on 11/25/14.
//  Copyright (c) 2014 Alex Turner. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface ViewController : NSViewController
{
	NSURL* bundlePath;
	NSUInteger pid;
	
	IBOutlet NSTextField* pathLabel, *pidLabel, *pidInputField;
}


- (IBAction)SelectBundle:(id)sender;
- (IBAction)SelectProcess:(id)sender;
- (IBAction)InjectIntoProcess:(id)sender;

@end

