//
//  GazifyTestHostAppDelegate.m
//  GazifyTestHost
//
//  Created by Joachim Bengtsson on 2011-02-12.
//  Copyright 2011 Spotify AB. All rights reserved.
//

#import "GazifyTestHostAppDelegate.h"

@implementation GazifyTestHostAppDelegate

@synthesize window;
-(void)foo;
{
	[webView setMainFrameURL:[[NSBundle mainBundle] pathForResource:@"JMJ_wikipedia" ofType:@"html"]];
}
- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
    [self performSelector:@selector(foo) withObject:nil afterDelay:.1];
}

@end
