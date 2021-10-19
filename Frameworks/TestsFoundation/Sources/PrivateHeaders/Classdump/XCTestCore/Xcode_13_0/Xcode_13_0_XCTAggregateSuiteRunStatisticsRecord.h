#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 150000 && __IPHONE_OS_VERSION_MAX_ALLOWED < 160000

#import "Xcode_13_0_XCTestCore_CDStructures.h"
#import "Xcode_13_0_SharedHeader.h"
#import <Foundation/Foundation.h>

//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

@interface XCTAggregateSuiteRunStatisticsRecord : NSObject <NSSecureCoding>
{
    NSString *_suiteName;
    unsigned long long _executionCount;
    unsigned long long _skipCount;
    unsigned long long _expectedFailureCount;
    unsigned long long _failureCount;
    unsigned long long _unexpectedExceptionCount;
}

+ (_Bool)supportsSecureCoding;
@property(readonly) unsigned long long unexpectedExceptionCount; // @synthesize unexpectedExceptionCount=_unexpectedExceptionCount;
@property(readonly) unsigned long long failureCount; // @synthesize failureCount=_failureCount;
@property(readonly) unsigned long long expectedFailureCount; // @synthesize expectedFailureCount=_expectedFailureCount;
@property(readonly) unsigned long long skipCount; // @synthesize skipCount=_skipCount;
@property(readonly) unsigned long long executionCount; // @synthesize executionCount=_executionCount;
@property(readonly) NSString *suiteName; // @synthesize suiteName=_suiteName;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (_Bool)isEqualToStatisticsRecord:(id)arg1;
- (_Bool)isEqual:(id)arg1;
- (id)initWithSuiteName:(id)arg1 executionCount:(unsigned long long)arg2 skipCount:(unsigned long long)arg3 expectedFailureCount:(unsigned long long)arg4 failureCount:(unsigned long long)arg5 unexpectedExceptionCount:(unsigned long long)arg6;
- (id)initWithSuiteName:(id)arg1 executionCount:(unsigned long long)arg2 skipCount:(unsigned long long)arg3 failureCount:(unsigned long long)arg4 unexpectedExceptionCount:(unsigned long long)arg5;

@end

#endif