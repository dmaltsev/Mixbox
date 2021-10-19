#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 150000 && __IPHONE_OS_VERSION_MAX_ALLOWED < 160000

#import "Xcode_13_0_XCTestCore_CDStructures.h"
#import "Xcode_13_0_SharedHeader.h"
#import <Foundation/Foundation.h>
#import <XCTest/XCTSourceCodeContext.h>

@class XCTSourceCodeSymbolInfo;

//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

@interface XCTSourceCodeFrame ()
{
    XCTSourceCodeSymbolInfo *_frameSymbolInfo;
    unsigned long long _address;
    NSError *_symbolicationError;
}

+ (_Bool)supportsSecureCoding;
- (_Bool)isEqual:(id)arg1;
- (unsigned long long)hash;
- (id)initWithCoder:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)description;
- (id)initWithAddress:(unsigned long long)arg1;

@end

#endif