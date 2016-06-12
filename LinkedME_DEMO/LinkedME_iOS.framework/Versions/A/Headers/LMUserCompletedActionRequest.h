//
//  LMUserCompletedActionRequest.h
//  iOS-Deep-Linking-SDK
//
//  Created by han on 5/22/15.
//  Copyright (c) 2015 LM han. All rights reserved.
//

#import "LMServerRequest.h"
#import "LinkedME.h"

//用户完成操作请求

@interface LMUserCompletedActionRequest : LMServerRequest

- (id)initWithAction:(NSString *)action state:(NSDictionary *)state;

@end
