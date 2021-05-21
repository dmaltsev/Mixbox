#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 120400 && __IPHONE_OS_VERSION_MAX_ALLOWED < 130000

#import "Xcode_10_3_XCTest_CDStructures.h"
#import "Xcode_10_3_SharedHeader.h"
#import <Foundation/Foundation.h>

@class CFRunLoopObserver;

//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

@interface XCUISnapshotGenerationTracker : NSObject
{
    struct __CFRunLoopObserver *_generationObserver;
    unsigned long long _generation;
}

+ (unsigned long long)generation;
+ (instancetype)sharedTracker;
- (id)_init;
- (void)dealloc;

@end

#endif