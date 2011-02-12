//
//  GazifyTestHostAppDelegate.h
//  GazifyTestHost
//
//  Created by Joachim Bengtsson on 2011-02-12.
//  Copyright 2011 Spotify AB. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <WebKit/WebKit.h>

@interface GazifyTestHostAppDelegate : NSObject <NSApplicationDelegate> {
    NSWindow *window;
    IBOutlet WebView *webView;
}

@property (assign) IBOutlet NSWindow *window;

@end
