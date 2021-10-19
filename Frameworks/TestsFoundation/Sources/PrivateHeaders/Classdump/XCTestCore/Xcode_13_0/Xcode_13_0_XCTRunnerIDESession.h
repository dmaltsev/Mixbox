#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 150000 && __IPHONE_OS_VERSION_MAX_ALLOWED < 160000

#import "Xcode_13_0_XCTestCore_CDStructures.h"
#import "Xcode_13_0_SharedHeader.h"
#import "Xcode_13_0_XCDebugLogDelegate.h"
#import "Xcode_13_0_XCTMessagingChannel_IDEToRunner.h"
#import "Xcode_13_0_XCTTestRunSessionDelegate.h"
#import "Xcode_13_0_XCUIXcodeApplicationManaging.h"
#import "Xcode_13_0__XCTestObservationInternal.h"
#import <Foundation/Foundation.h>

@protocol XCTMessagingChannel_RunnerToIDE, XCTRunnerIDESessionDelegate, XCUIApplicationMonitor;

@class DTXConnection, XCTCapabilities, XCTFuture, XCTPromise, XCTestRun;

//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

@interface XCTRunnerIDESession : NSObject <_XCTestObservationInternal, XCTMessagingChannel_IDEToRunner, XCTTestRunSessionDelegate, XCUIXcodeApplicationManaging, XCDebugLogDelegate>
{
    XCTCapabilities *_IDECapabilities;
    XCTFuture *_readyForTestingFuture;
    XCTFuture *_testConfigurationFuture;
    XCTFuture *_IDEProxyFuture;
    id <XCTRunnerIDESessionDelegate> _delegate;
    id <XCUIApplicationMonitor> _applicationMonitor;
    NSObject *_queue;
    DTXConnection *_IDEConnection;
    id <XCTMessagingChannel_RunnerToIDE> _IDEProxy;
    XCTPromise *_readyForTestingPromise;
    XCTestRun *_currentTestRun;
    CDUnknownBlockType _readinessReply;
}

+ (id)IDECapabilitiesForLegacyProtocolVersion:(unsigned long long)arg1;
+ (id)exportedCapabilities;
+ (void)daemonMediatedSessionForSessionIdentifier:(id)arg1 daemonSession:(id)arg2 delegate:(id)arg3 completion:(CDUnknownBlockType)arg4;
+ (double)IDEConnectionTimeout;
+ (void)setSharedSession:(id)arg1;
+ (instancetype)sharedSession;
+ (instancetype)sharedSessionQueue;
@property(copy) CDUnknownBlockType readinessReply; // @synthesize readinessReply=_readinessReply;
@property(retain) XCTestRun *currentTestRun; // @synthesize currentTestRun=_currentTestRun;
@property(retain) XCTPromise *readyForTestingPromise; // @synthesize readyForTestingPromise=_readyForTestingPromise;
@property(retain) id <XCTMessagingChannel_RunnerToIDE> IDEProxy; // @synthesize IDEProxy=_IDEProxy;
@property(retain) DTXConnection *IDEConnection; // @synthesize IDEConnection=_IDEConnection;
@property(readonly) NSObject *queue; // @synthesize queue=_queue;
@property __weak id <XCUIApplicationMonitor> applicationMonitor; // @synthesize applicationMonitor=_applicationMonitor;
@property __weak id <XCTRunnerIDESessionDelegate> delegate; // @synthesize delegate=_delegate;
- (void)testBundleDidFinish:(id)arg1;
- (void)_context:(id)arg1 didFinishActivity:(id)arg2;
- (void)_context:(id)arg1 willStartActivity:(id)arg2;
- (void)_testCase:(id)arg1 didMeasureValues:(id)arg2 forPerformanceMetricID:(id)arg3 name:(id)arg4 unitsOfMeasurement:(id)arg5 baselineName:(id)arg6 baselineAverage:(id)arg7 maxPercentRegression:(id)arg8 maxPercentRelativeStandardDeviation:(id)arg9 maxRegression:(id)arg10 maxStandardDeviation:(id)arg11 file:(id)arg12 line:(unsigned long long)arg13 polarity:(long long)arg14;
- (void)testCase:(id)arg1 didRecordExpectedFailure:(id)arg2;
- (void)testCase:(id)arg1 didRecordIssue:(id)arg2;
- (void)testCaseDidFinish:(id)arg1;
- (void)testCase:(id)arg1 didRecordSkipWithDescription:(id)arg2 sourceCodeContext:(id)arg3;
- (void)testCaseWillStart:(id)arg1;
- (void)testSuiteDidFinish:(id)arg1;
- (void)testSuite:(id)arg1 didRecordExpectedFailure:(id)arg2;
- (void)testSuite:(id)arg1 didRecordIssue:(id)arg2;
- (void)testSuiteWillStart:(id)arg1;
- (void)testBundleWillStart:(id)arg1;
- (id)_IDE_processWithToken:(id)arg1 exitedWithStatus:(id)arg2;
- (id)_IDE_stopTrackingProcessWithToken:(id)arg1;
- (void)reportSelfDiagnosisIssue:(id)arg1 description:(id)arg2;
- (void)terminateProcessWithToken:(id)arg1 completion:(CDUnknownBlockType)arg2;
- (void)requestLaunchProgressForProcessWithToken:(id)arg1 completion:(CDUnknownBlockType)arg2;
- (void)launchProcessWithPath:(id)arg1 bundleID:(id)arg2 arguments:(id)arg3 environmentVariables:(id)arg4 completion:(CDUnknownBlockType)arg5;
- (id)_IDE_processWithBundleID:(id)arg1 path:(id)arg2 pid:(id)arg3 crashedUnderSymbol:(id)arg4;
- (void)reportStallOnMainThreadInTestCase:(id)arg1 file:(id)arg2 line:(unsigned long long)arg3;
- (void)logDebugMessage:(id)arg1;
- (void)testRunSessionDidFinishExecutingTestPlan:(id)arg1 reply:(CDUnknownBlockType)arg2;
- (void)testRunSession:(id)arg1 initializationForUITestingDidFailWithError:(id)arg2;
- (void)testRunSessionDidBeginInitializingForUITesting:(id)arg1;
- (void)testRunSessionDidBeginExecutingTestPlan:(id)arg1;
- (id)_IDE_shutdown;
- (id)_IDE_executeTestsWithIdentifiersToRun:(id)arg1 identifiersToSkip:(id)arg2;
- (id)_IDE_executeTestIdentifiers:(id)arg1 skippingTestIdentifiers:(id)arg2;
- (id)_IDE_fetchParallelizableTestIdentifiers;
- (id)_IDE_fetchDiscoveredTestClasses;
- (id)_IDE_startExecutingTestPlanWithProtocolVersion:(id)arg1;
- (void)flushOutgoingMessagesWithIDEConfirmationTimeout:(double)arg1;
- (void)reportTestWithIdentifier:(id)arg1 didExceedExecutionTimeAllowance:(double)arg2;
- (void)reportBootstrappingFailure:(id)arg1 completion:(CDUnknownBlockType)arg2;
@property(readonly) XCTFuture *IDEProxyFuture; // @synthesize IDEProxyFuture=_IDEProxyFuture;
@property(readonly) XCTFuture *readyForTestingFuture; // @synthesize readyForTestingFuture=_readyForTestingFuture;
@property(readonly) XCTFuture *testConfigurationFuture; // @synthesize testConfigurationFuture=_testConfigurationFuture;
@property(retain) XCTCapabilities *IDECapabilities; // @synthesize IDECapabilities=_IDECapabilities;
- (id)initWithTransport:(id)arg1 delegate:(id)arg2;

// Remaining properties

@end

#endif