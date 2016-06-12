//
//  LMSetIdentityRequest.h
//  iOS-Deep-Linking-SDK
//
//  Created by han on 5/22/15.
//  Copyright (c) 2015 LM han. All rights reserved.
//

#import "LinkedME.h"
#import "LMServerRequest.h"

//设置请求身份
@interface LMSetIdentityRequest : LMServerRequest

- (id)initWithUserId:(NSString *)userId callback:(callbackWithParams)callback;

@end
