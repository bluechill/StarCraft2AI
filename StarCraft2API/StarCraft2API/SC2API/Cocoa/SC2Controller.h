//
//  SC2Controller.h
//  StarCraft2API
//
//  Created by Alex Turner on 1/13/15.
//  Copyright (c) 2015 Alex Turner. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface SC2Controller : NSViewController
{
	NSTextView* _console;
}

@property (strong, nonatomic) IBOutlet NSTextView* console;

@end
