#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 130000 && __IPHONE_OS_VERSION_MAX_ALLOWED < 140000

#import "Xcode_11_0_XCTAutomationSupport_CDStructures.h"
#import "Xcode_11_0_SharedHeader.h"
#import "Xcode_11_0_XCTRuntimeIssue.h"
#import <Foundation/Foundation.h>

@class XCAccessibilityElement;

//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

@interface XCTAutomationTypeMismatchIssue : NSObject <XCTRuntimeIssue>
{
    XCAccessibilityElement *_accessibilityElement;
    unsigned long long _legacyElementType;
    unsigned long long _elementTypeFromAutomationType;
    NSDictionary *_accessibilityAttributes;
}

+ (_Bool)supportsSecureCoding;
+ (id)capability;
@property(readonly, copy) NSDictionary *accessibilityAttributes; // @synthesize accessibilityAttributes=_accessibilityAttributes;
@property(readonly) unsigned long long elementTypeFromAutomationType; // @synthesize elementTypeFromAutomationType=_elementTypeFromAutomationType;
@property(readonly) unsigned long long legacyElementType; // @synthesize legacyElementType=_legacyElementType;
@property(readonly, copy) XCAccessibilityElement *accessibilityElement; // @synthesize accessibilityElement=_accessibilityElement;
- (_Bool)isEqualForAggregationWith:(id)arg1;
- (_Bool)isEqual:(id)arg1;
@property(readonly) unsigned long long aggregationHash;
@property(readonly) NSString *detailedDescription;
@property(readonly) NSString *shortDescription;
- (id)initWithCoder:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initForAccessibilityElement:(id)arg1 legacyElementType:(unsigned long long)arg2 elementTypeFromAutomationType:(unsigned long long)arg3 accessibilityAttributes:(id)arg4;

// Remaining properties

@end

#endif