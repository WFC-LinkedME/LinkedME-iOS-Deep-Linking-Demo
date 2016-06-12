//
//  LMApplyPromoCodeRequest.h
//  iOS-Deep-Linking-SDK
//
//  Created by han on 5/26/15.
//  Copyright (c) 2015 LM han. All rights reserved.
//

#import "LMServerRequest.h"
#import "LinkedME.h"

//使用优惠码请求

@interface LMApplyPromoCodeRequest : LMServerRequest

- (id)initWithCode:(NSString *)code useOld:(BOOL)useOld callback:(callbackWithParams)callback;

@end
