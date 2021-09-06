#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 150000 && __IPHONE_OS_VERSION_MAX_ALLOWED < 160000

#import "Xcode_13_0_XCTestCore_CDStructures.h"
#import "Xcode_13_0_SharedHeader.h"
#import <Foundation/Foundation.h>

@class XCTestCase;

//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

__attribute__((visibility("hidden")))
@interface XCTAttachmentManager : NSObject
{
    _Bool _isValid;
    XCTestCase *_testCase;
    NSMutableArray *_attachments;
}

+ (void)_synthesizeActivityForAttachment:(id)arg1 testCase:(id)arg2;
@property _Bool isValid; // @synthesize isValid=_isValid;
@property(readonly) NSMutableArray *attachments; // @synthesize attachments=_attachments;
@property(readonly) XCTestCase *testCase; // @synthesize testCase=_testCase;
- (void)enqueueAttachment:(id)arg1;
- (void)dequeueAndReportBackgroundAttachments;
- (void)ensureNoRemainingAttachments;
- (void)_invalidate;
- (void)dealloc;
- (id)initWithTestCase:(id)arg1;

@end

#endif