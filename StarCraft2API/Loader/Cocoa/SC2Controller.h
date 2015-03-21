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
	NSButton* _reload_api_button;
	NSButton* _reload_ai_button;
	NSButton* _reload_state_machine_button;
}

@property (strong, nonatomic) IBOutlet NSTextView* console;
@property (strong, nonatomic) IBOutlet NSButton* reload_api_button;
@property (strong, nonatomic) IBOutlet NSButton* reload_ai_button;
@property (strong, nonatomic) IBOutlet NSButton* reload_state_machine_button;


- (IBAction)reloadAPI:(id)sender;
- (IBAction)reloadAI:(id)sender;
- (IBAction)reloadStateMachine:(id)sender;

@end
