//
//  LMRegisterViewRequest.h
//  iOS-Deep-Linking-SDK
//
//  Created by han on 10/16/15.
//  Copyright © 2015 LM han. All rights reserved.
//

#import "LMServerRequest.h"
#import "LinkedME.h"

//注册view

@interface LMRegisterViewRequest : LMServerRequest

- (id)initWithParams:(NSDictionary *)params andCallback:(callbackWithParams)callback;

@end
