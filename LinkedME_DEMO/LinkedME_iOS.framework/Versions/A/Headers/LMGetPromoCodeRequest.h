//
//  LMGetPromoCodeRequest.h
//  iOS-Deep-Linking-SDK
//
//  Created by han on 5/26/15.
//  Copyright (c) 2015 LM han. All rights reserved.
//

#import "LMServerRequest.h"
#import "LinkedME.h"


//请求优惠码
@interface LMGetPromoCodeRequest : LMServerRequest

- (id)initWithUsageType:(LMPromoCodeUsageType)usageType rewardLocation:(LMPromoCodeRewardLocation)rewardLocation amount:(NSInteger)amount bucket:(NSString *)bucket prefix:(NSString *)prefix expiration:(NSDate *)expiration useOld:(BOOL)useOld callback:(callbackWithParams)callback;

@end
