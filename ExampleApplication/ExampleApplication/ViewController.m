//
//  ViewController.m
//  ExampleApplication
//
//  Created by Alex Turner on 11/25/14.
//  Copyright (c) 2014 Alex Turner. All rights reserved.
//

#import "ViewController.h"

@implementation ViewController

- (void)viewDidLoad {
	[super viewDidLoad];

	// Do any additional setup after loading the view.
	NSProcessInfo *processInfo = [NSProcessInfo processInfo];
	int processID = [processInfo processIdentifier];

	[myPID setStringValue:[NSString stringWithFormat:@"My PID: %i", processID]];
}

- (void)setRepresentedObject:(id)representedObject {
	[super setRepresentedObject:representedObject];

	// Update the view, if already loaded.
}

@end
