//
//  LMOpenRequest.h
//  iOS-Deep-Linking-SDK
//
//  Created by han on 5/26/15.
//  Copyright (c) 2015 LM han. All rights reserved.
//

#import "LMServerRequest.h"
#import "LinkedME.h"

//打开请求

@interface LMButtonRequest : LMServerRequest

@property (strong, nonatomic) callbackWithStatus callback;

- (id)initWithCallback:(callbackWithStatus)callback;
//- (id)initWithCallback:(callbackWithStatus)callback isInstall:(BOOL)isInstall;

@end
