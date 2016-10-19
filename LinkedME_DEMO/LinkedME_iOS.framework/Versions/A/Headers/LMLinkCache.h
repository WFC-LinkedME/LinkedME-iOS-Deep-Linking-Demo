//
//  LMLinkCache.h
//  iOS-Deep-Linking-SDK
//
//  Created by han on 1/23/15.
//  Copyright (c) 2015 Bindx. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LMLinkData.h"

@interface LMLinkCache : NSObject

/**
 *  设置缓存
 *
 *  @param anObject 缓存数据
 *  @param aKey     key
 */
- (void)setObject:(NSString *)anObject forKey:(LMLinkData *)aKey;
- (NSString *)objectForKey:(LMLinkData *)aKey;

@end

