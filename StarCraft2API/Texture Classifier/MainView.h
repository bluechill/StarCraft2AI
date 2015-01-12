//
//  MainView.h
//  StarCraft2API
//
//  Created by Alex Turner on 1/11/15.
//  Copyright (c) 2015 Alex Turner. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface MainView : NSViewController <NSControlTextEditingDelegate>
{
	NSMutableArray* TextureObjects;
	int i;
}

@property (strong) IBOutlet NSImageView* imageView;
@property (strong) IBOutlet NSTextField* classification;

@end
