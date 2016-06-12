//
//  LMShortUrlSyncRequest.h
//  iOS-Deep-Linking-SDK
//
//  Created by han on 5/27/15.
//  Copyright (c) 2015 LM han. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LinkedME.h"

//短链接同步请求

@interface LMShortUrlSyncRequest : NSObject

- (id)initWithTags:(NSArray *)tags alias:(NSString *)alias type:(LMLinkType)type matchDuration:(NSInteger)duration channel:(NSString *)channel feature:(NSString *)feature stage:(NSString *)stage params:(NSDictionary *)params linkData:(LMLinkData *)linkData linkCache:(LMLinkCache *)linkCache;
- (LMServerResponse *)makeRequest:(LMServerInterface *)serverInterface key:(NSString *)key;
- (NSString *)processResponse:(LMServerResponse *)response;
+ (NSString *)createLinkFromBranchKey:(NSString *)branchKey tags:(NSArray *)tags alias:(NSString *)alias type:(LMLinkType)type matchDuration:(NSInteger)duration channel:(NSString *)channel feature:(NSString *)feature stage:(NSString *)stage params:(NSDictionary *)params;

@end
