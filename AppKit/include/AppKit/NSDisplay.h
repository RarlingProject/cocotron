/* Copyright (c) 2006-2007 Christopher J. W. Lloyd

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#import <Foundation/Foundation.h>
#import <AppKit/NSFont.h>
#import <CoreServices/UnicodeUtilities.h>

@class NSEvent, NSColor, NSPasteboard, NSDraggingManager, NSPrintInfo, NSView, NSSavePanel, NSOpenPanel, CGWindow;

@interface NSDisplay : NSObject {
    NSMutableArray *_eventQueue;
}

+ (NSDisplay *)currentDisplay;

- (NSArray *)screens;

- (NSPasteboard *)pasteboardWithName:(NSString *)name;

- (NSDraggingManager *)draggingManager;

- (CGWindow *) newWindowWithDelegate: (NSWindow *) delegate;

- (NSColor *)colorWithName:(NSString *)colorName;
- (void)_addSystemColor:(NSColor *)result forName:(NSString *)colorName;

- (NSTimeInterval)textCaretBlinkInterval;

- (void)hideCursor;
- (void)unhideCursor;

- (id)cursorWithImage:(NSImage *)image hotSpot:(NSPoint)hotSpot;
- (id)cursorWithName:(NSString *)name;
- (void)setCursor:(id)cursor;

- (NSEvent *)nextEventMatchingMask:(unsigned)mask untilDate:(NSDate *)untilDate inMode:(NSString *)mode dequeue:(BOOL)dequeue;

- (void)discardEventsMatchingMask:(unsigned)mask beforeEvent:(NSEvent *)event;

- (void)postEvent:(NSEvent *)event atStart:(BOOL)atStart;

- (BOOL)containsAndRemovePeriodicEvents;

- (unsigned)modifierForDefault: (NSString *) key : (unsigned) standard;

- (void)beep;

- (NSSet *)allFontFamilyNames;
- (NSArray *)fontTypefacesForFamilyName:(NSString *)name;

- (CGFloat)scrollerWidth;

- (int)runModalPageLayoutWithPrintInfo:(NSPrintInfo *)printInfo;
- (int)runModalPrintPanelWithPrintInfoDictionary:(NSMutableDictionary *)attributes;

- (CGContextRef)graphicsPortForPrintOperationWithView:(NSView *)view printInfo:(NSPrintInfo *)printInfo pageRange:(NSRange)pageRange;

- (BOOL) implementsCustomPanelForClass: (Class) panelClass;

- (int)savePanel:(NSSavePanel *)savePanel runModalForDirectory:(NSString *)directory file:(NSString *)file;
- (int)openPanel:(NSOpenPanel *)openPanel runModalForDirectory:(NSString *)directory file:(NSString *)file types:(NSArray *)types;

- (NSPoint)mouseLocation;
- (NSUInteger)currentModifierFlags;

- (NSArray *) orderedWindowNumbers;

- (CGRect) insetRect: (CGRect) frame forNativeWindowBorderWithStyle: (NSUInteger) styleMask;
- (CGRect) outsetRect: (CGRect) frame forNativeWindowBorderWithStyle: (NSUInteger) styleMask;

- (NSArray *) modesForScreen:(int)screenIndex;
- (NSDictionary*) currentModeForScreen:(int)screenIndex;
- (BOOL) setMode:(NSDictionary *)mode forScreen:(int)screenIndex;

// Returned memory must be free()ed by the caller
- (UCKeyboardLayout*) keyboardLayout:(uint32_t*)byteLength;
// Returns an opaque number of the current keyboard layout.
// This is because apps tend to call TISCopyCurrentKeyboardLayoutInputSource() repeatedly
// and expect to get the same pointer if layout hasn't changed.
- (int)keyboardLayoutId;

@end
