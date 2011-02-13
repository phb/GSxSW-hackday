#include "CocoaStore.h"
#define Point MacTypePoint
#import <Cocoa/Cocoa.h>
#undef Point

WindowPointer::WindowPointer(const WindowPointer::PointerSpec& pointerspec)
{
    NSWindow *pointerWindow = [[NSWindow alloc] initWithContentRect:NSMakeRect(0, 0, pointerspec.width, pointerspec.height) styleMask:NSBorderlessWindowMask backing:NSBackingStoreBuffered defer:NO];
    [pointerWindow setBackgroundColor:[NSColor colorWithDeviceRed:pointerspec.red green:pointerspec.green blue:pointerspec.blue alpha:1]];
    [pointerWindow orderFront:nil];
    window = pointerWindow;
}
WindowPointer::~WindowPointer()
{
     [(id)window release]; window = nil;
}
NSPoint inverse(Point foo)
{
    NSScreen *s = [NSScreen mainScreen];
    NSPoint p;
    p.x = foo.x;
    p.y = [s frame].size.height - foo.y;
    return p;
}

void WindowPointer::setPosition(int x, int y)
{
    [(id)window setFrameOrigin:inverse(Point(x, y))];
}

WindowStore::WindowStore(const WindowPointer::PointerSpec& pointerspec,
			 const WindowPointer::PointerSpec& targetspec) : pointer(pointerspec), target(targetspec)
{
}


void WindowStore::store(const TrackerOutput &output) {
    pointer.setPosition(output.gazepoint.x, output.gazepoint.y);
    target.setPosition(output.target.x, output.target.y);
}
