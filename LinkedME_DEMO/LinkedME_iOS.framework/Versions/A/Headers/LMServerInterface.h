//
//  LMServerInterface.h
//  iOS-Deep-Linking-SDK
//
//  Created by han on 6/4/14.
//  Copyright (c) 2014 LM han. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LMServerResponse.h"
#import "LMPreferenceHelper.h"

typedef void (^LMServerCallback)(LMServerResponse *response, NSError *error);

static NSString *REQ_TAG_DEBUG_CONNECT = @"t_debug_connect";
static NSString *REQ_TAG_DEBUG_LOG = @"t_debug_log";
static NSString *REQ_TAG_DEBUG_SCREEN = @"t_debug_screen";
static NSString *REQ_TAG_DEBUG_DISCONNECT = @"t_debug_disconnect";

@interface LMServerInterface : NSObject

@property (strong, nonatomic) LMPreferenceHelper *preferenceHelper;

- (LMServerResponse *)getRequest:(NSDictionary *)params url:(NSString *)url key:(NSString *)key;
- (LMServerResponse *)getRequest:(NSDictionary *)params url:(NSString *)url key:(NSString *)key log:(BOOL)log;
- (void)getRequest:(NSDictionary *)params url:(NSString *)url key:(NSString *)key callback:(LMServerCallback)callback;
- (void)getRequest:(NSDictionary *)params url:(NSString *)url key:(NSString *)key log:(BOOL)log callback:(LMServerCallback)callback;

- (LMServerResponse *)postRequest:(NSDictionary *)post url:(NSString *)url key:(NSString *)key log:(BOOL)log;
- (void)postRequest:(NSDictionary *)post url:(NSString *)url key:(NSString *)key callback:(LMServerCallback)callback;
- (void)postRequest:(NSDictionary *)post url:(NSString *)url key:(NSString *)key log:(BOOL)log callback:(LMServerCallback)callback;

- (void)genericHTTPRequest:(NSURLRequest *)request log:(BOOL)log callback:(LMServerCallback)callback;
- (LMServerResponse *)genericHTTPRequest:(NSURLRequest *)request log:(BOOL)log;

@end
