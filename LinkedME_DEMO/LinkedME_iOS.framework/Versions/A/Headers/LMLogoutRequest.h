//
//  LMLogoutRequest.h
//  iOS-Deep-Linking-SDK
//
//  Created by han on 5/22/15.
//  Copyright (c) 2015 LM han. All rights reserved.
//

#import "LMServerRequest.h"
#import "LinkedME.h"


//注销请求

@interface LMLogoutRequest : LMServerRequest

- (id)initWithCallback:(callbackWithStatus)callback;

@end
