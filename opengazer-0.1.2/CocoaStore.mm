#include "GtkStore.h"

static NSWindow *pointerWindow;
static NSWindow *targetWindow;

WindowStore::WindowStore(const WindowPointer::PointerSpec& pointerspec,
			 const WindowPointer::PointerSpec& targetspec)
{
    pointerWindow = [[NSWindow alloc] initWithContentRect:NSMakeRect(0, 0, pointerspec.width, pointerspec.height) styleMask:NSBorderlessWindowMask backing:NSBackingStoreBuffered defer:NO];
    [pointerWindow setBackgroundColor:[NSColor colorWithDeviceRed:pointerspec.red green:pointerspec.green blue:pointerspec.blue alpha:1]];
    [pointerWindow orderFront:nil];
    
    targetWindow = [[NSWindow alloc] initWithContentRect:NSMakeRect(0, 0, targetspec.width, targetspec.height) styleMask:NSBorderlessWindowMask backing:NSBackingStoreBuffered defer:NO];
    [targetWindow setBackgroundColor:[NSColor colorWithDeviceRed:targetspec.red green:targetspec.green blue:targetspec.blue alpha:1]];
    [targetWindow orderFront:nil];
}
WindowStore::~WindowStore()
{
    [pointerWindow release]; pointerWindow = nil;
    [targetWindow release]; targetWindow = nil;
}

NSPoint inverse(Point foo)
{
    NSScreen *s = [NSScreen mainScreen];
    NSPoint p;
    p.x = foo.x;
    p.y = [s frame].size.height - foo.y;
    return p;
}

void WindowStore::store(const TrackerOutput &output) {
    
    [pointerWindow setFrameOrigin:inverse(output.gazepoint)];
    [targetWindow setFrameOrigin:inverse(output.target)];
}
