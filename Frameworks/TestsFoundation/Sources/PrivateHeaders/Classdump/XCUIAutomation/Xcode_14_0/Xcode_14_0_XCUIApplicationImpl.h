#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 160000 && __IPHONE_OS_VERSION_MAX_ALLOWED < 170000

#import "Xcode_14_0_XCUIAutomation_CDStructures.h"
#import "Xcode_14_0_SharedHeader.h"
#import "Xcode_14_0_XCUIApplicationProcessDelegate.h"
#import <Foundation/Foundation.h>

@protocol XCUIDevice, XCUIIssueDiagnosticsProviding;

@class XCAccessibilityElement, XCUIApplicationProcess;

//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

@interface XCUIApplicationImpl : NSObject <XCUIApplicationProcessDelegate>
{
    _Bool _codeCoverageEnabled;
    _Bool _hasValidAlertCount;
    _Bool _previousOnDemandAutomationSessionRequestFailed;
    int _terminatingPID;
    NSString *_path;
    NSString *_bundleID;
    XCUIApplicationProcess *_currentProcess;
    id <XCUIDevice> _device;
}

+ (id)keyPathsForValuesAffectingCurrentProcessAccessibilityActive;
+ (id)keyPathsForValuesAffectingActivated;
+ (id)keyPathsForValuesAffectingForeground;
+ (id)keyPathsForValuesAffectingBackground;
+ (id)keyPathsForValuesAffectingSuspended;
+ (id)keyPathsForValuesAffectingRunning;
+ (id)keyPathsForValuesAffectingState;
+ (id)keyPathsForValuesAffectingHasCurrentProcess;
@property int terminatingPID; // @synthesize terminatingPID=_terminatingPID;
@property _Bool previousOnDemandAutomationSessionRequestFailed; // @synthesize previousOnDemandAutomationSessionRequestFailed=_previousOnDemandAutomationSessionRequestFailed;
@property _Bool hasValidAlertCount; // @synthesize hasValidAlertCount=_hasValidAlertCount;
@property _Bool codeCoverageEnabled; // @synthesize codeCoverageEnabled=_codeCoverageEnabled;
@property(readonly) id <XCUIDevice> device; // @synthesize device=_device;
@property(retain, nonatomic) XCUIApplicationProcess *currentProcess; // @synthesize currentProcess=_currentProcess;
@property(readonly, copy) NSString *bundleID; // @synthesize bundleID=_bundleID;
@property(readonly, copy) NSString *path; // @synthesize path=_path;
- (void)resetAuthorizationStatusForResource:(long long)arg1;
- (_Bool)waitForViewControllerViewDidDisappearWithTimeout:(double)arg1 error:(id *)arg2;
- (void)handleCrashUnderSymbol:(id)arg1;
- (void)terminate;
- (void)_waitOnActivationExpectation:(id)arg1;
- (id)_activationExpectation;
- (void)waitForAccessibilityActive;
- (_Bool)currentProcessAccessibilityActive;
- (void)_waitForValidPID;
- (void)_launchUsingPlatformWithArguments:(id)arg1 environment:(id)arg2;
- (void)_launchUsingXcodeWithArguments:(id)arg1 environment:(id)arg2;
- (void)_waitForLaunchProgressWithToken:(id)arg1;
- (void)_launchWithRequest:(id)arg1;
- (_Bool)shouldWaitForAutomationSessionWhenUsingPlatformLauncher:(_Bool)arg1;
- (_Bool)applicationProcessShouldRequestAutomationSession:(id)arg1;
- (void)applicationProcessAutomationSessionRequestFailed:(id)arg1;
- (void)_activateForPlatform;
- (void)_activate;
- (void)serviceOpenRequest:(id)arg1;
@property(readonly) _Bool activated;
@property(readonly) _Bool foreground;
@property(readonly) _Bool background;
@property(readonly) _Bool suspended;
@property(readonly) _Bool running;
- (void)_awaitValidCurrentProcess;
- (void)resetAlertCount;
@property(readonly) unsigned long long alertCount;
- (_Bool)waitForState:(unsigned long long)arg1 timeout:(double)arg2;
@property(nonatomic) unsigned long long state;
@property(nonatomic) int processID;
@property(readonly) id <XCUIIssueDiagnosticsProviding> diagnosticsProvider;
@property(readonly) XCAccessibilityElement *accessibilityElement;
- (_Bool)hasCurrentProcess;
- (id)compactDescription;
- (id)initWithPath:(id)arg1 bundleID:(id)arg2;
- (id)initWithPath:(id)arg1 bundleID:(id)arg2 device:(id)arg3;

// Remaining properties

@end

#endif