#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 150000 && __IPHONE_OS_VERSION_MAX_ALLOWED < 160000

#import "Xcode_13_0_XCTestCore_CDStructures.h"
#import "Xcode_13_0_SharedHeader.h"
#import <Foundation/Foundation.h>

@protocol XCTMessagingRole_TestReporting;

@class XCTTestIdentifier;

//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

@interface XCTReportingSessionTestReporter : NSObject
{
    XCTTestIdentifier *_identifier;
    id <XCTMessagingRole_TestReporting> _IDEProxy;
    CDUnknownBlockType _finishHandler;
    NSDate *_startDate;
}

@property(readonly) XCTTestIdentifier *identifier; // @synthesize identifier=_identifier;
- (void)finishWithStatus:(id)arg1 atDate:(id)arg2;
- (id)reportActivityStartedWithName:(id)arg1 atDate:(id)arg2;
- (void)reportAttachment:(id)arg1 atDate:(id)arg2;
- (void)reportIssue:(id)arg1 atDate:(id)arg2;

@end

#endif