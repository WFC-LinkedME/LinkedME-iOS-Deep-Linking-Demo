//
//  LMAppConnect.h
//  LinkedME-iOS-Deep-Linking-Demo
//
//  Created by Bindx on 5/19/16.
//  Copyright © 2016 Bindx. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Apis.h"

typedef void (^CompletioBlock)(NSDictionary *dic, NSURLResponse *response, NSError *error);
typedef void (^SuccessBlock)(NSDictionary *data);
typedef void (^FailureBlock)(NSError *error);

@interface LMAppConnect : NSObject<NSURLSessionDelegate>

/**
 *  get请求
 */
+ (void)getWithUrlString:(NSString *)url parameters:(id)parameters success:(SuccessBlock)successBlock failure:(FailureBlock)failureBlock;

+ (void)getWithUrlString:(NSString *)url KvParameters:(id)parameters kv:(BOOL)k success:(SuccessBlock)successBlock failure:(FailureBlock)failureBlock;


/**
 * post请求
 */
+ (void)postWithUrlString:(NSString *)url parameters:(id)parameters success:(SuccessBlock)successBlock failure:(FailureBlock)failureBlock;

+ (void)postWithUrlString:(NSString *)url jsonStringParameters:(id)parameters success:(SuccessBlock)successBlock failure:(FailureBlock)failureBlock;




@end
