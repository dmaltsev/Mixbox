#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 150000 && __IPHONE_OS_VERSION_MAX_ALLOWED < 160000

#import "Xcode_13_0_XCTestCore_CDStructures.h"
#import "Xcode_13_0_SharedHeader.h"
#import <Foundation/Foundation.h>
#import <XCTest/XCTestObservationCenter.h>

@protocol XCTestObservation;

//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

@interface XCTestObservationCenter ()
{
    _Bool _suspended;
    NSMutableArray *_observers;
    NSMutableArray *_privateObservers;
    NSMutableArray *_internalObservers;
    CDUnknownBlockType _exceptionHandler;
    id <XCTestObservation> _throwingTestObserver;
    SEL _throwingTestObserverMethod;
}

+ (void)setSharedTestObservationCenter:(id)arg1;
@property SEL throwingTestObserverMethod; // @synthesize throwingTestObserverMethod=_throwingTestObserverMethod;
@property(retain) id <XCTestObservation> throwingTestObserver; // @synthesize throwingTestObserver=_throwingTestObserver;
@property(readonly, copy) CDUnknownBlockType exceptionHandler; // @synthesize exceptionHandler=_exceptionHandler;
@property _Bool suspended; // @synthesize suspended=_suspended;
@property(readonly) NSMutableArray *internalObservers; // @synthesize internalObservers=_internalObservers;
@property(readonly) NSMutableArray *privateObservers; // @synthesize privateObservers=_privateObservers;
@property(readonly) NSMutableArray *observers; // @synthesize observers=_observers;
- (void)_performBlockOnInternalObserversWhichRespondToSelector:(SEL)arg1 block:(CDUnknownBlockType)arg2;
- (void)_performBlockOnPrivateObserversWhichRespondToSelector:(SEL)arg1 block:(CDUnknownBlockType)arg2;
- (void)_performBlockOnObserversWhichRespondToSelector:(SEL)arg1 block:(CDUnknownBlockType)arg2;
- (void)_context:(id)arg1 didFinishActivity:(id)arg2;
- (void)_context:(id)arg1 willStartActivity:(id)arg2;
- (void)_testCase:(id)arg1 didRecordExpectedFailure:(id)arg2;
- (void)_testCase:(id)arg1 didRecordIssue:(id)arg2;
- (void)_testCase:(id)arg1 didMeasureValues:(id)arg2 forPerformanceMetricID:(id)arg3 name:(id)arg4 unitsOfMeasurement:(id)arg5 baselineName:(id)arg6 baselineAverage:(id)arg7 maxPercentRegression:(id)arg8 maxPercentRelativeStandardDeviation:(id)arg9 maxRegression:(id)arg10 maxStandardDeviation:(id)arg11 file:(id)arg12 line:(unsigned long long)arg13 polarity:(long long)arg14;
- (void)_testCaseDidStop:(id)arg1;
- (void)_testCaseWasSkipped:(id)arg1 withDescription:(id)arg2 sourceCodeContext:(id)arg3;
- (void)_testCaseDidStart:(id)arg1;
- (void)_testSuite:(id)arg1 didRecordExpectedFailure:(id)arg2;
- (void)_testSuite:(id)arg1 didRecordIssue:(id)arg2;
- (void)_testSuiteDidStop:(id)arg1;
- (void)_testSuiteDidStart:(id)arg1;
- (void)_handleException:(id)arg1 thrownBy:(id)arg2 inMethod:(SEL)arg3;
- (void)_suspendObservationForBlock:(CDUnknownBlockType)arg1;
- (void)_suspendObservation;
- (void)_resumeObservation;
- (void)_observeTestExecutionForBlock:(CDUnknownBlockType)arg1;

- (id)description;
- (id)init;
- (id)initWithObservers:(id)arg1 exceptionHandler:(CDUnknownBlockType)arg2;

@end

#endif