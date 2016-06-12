//
//  LMRedeemRewardsRequest.h
//  iOS-Deep-Linking-SDK
//
//  Created by han on 5/22/15.
//  Copyright (c) 2015 LM han. All rights reserved.
//

#import "LMServerRequest.h"
#import "LinkedME.h"

//请求兑换奖励
@interface LMRedeemRewardsRequest : LMServerRequest

- (id)initWithAmount:(NSInteger)amount bucket:(NSString *)bucket callback:(callbackWithStatus)callback;

@end
