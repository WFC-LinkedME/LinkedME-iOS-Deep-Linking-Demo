//
//  LMShortUrlRequest.h
//  iOS-Deep-Linking-SDK
//
//  Created by han on 5/26/15.
//  Copyright (c) 2015 LM han. All rights reserved.
//

#import "LMServerRequest.h"
#import "LinkedME.h"

//短连接请求

@interface LMShortUrlRequest : LMServerRequest

- (id)initWithTags:(NSArray *)tags alias:(NSString *)alias type:(LMLinkType)type matchDuration:(NSInteger)duration channel:(NSString *)channel feature:(NSString *)feature stage:(NSString *)stage params:(NSDictionary *)params linkData:(LMLinkData *)linkData linkCache:(LMLinkCache *)linkCache callback:(callbackWithUrl)callback;

@end
