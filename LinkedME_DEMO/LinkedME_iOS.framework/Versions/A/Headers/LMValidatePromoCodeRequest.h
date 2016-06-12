//
//  LMValidatePromoCodeRequest.h
//  iOS-Deep-Linking-SDK
//
//  Created by han on 5/26/15.
//  Copyright (c) 2015 LM han. All rights reserved.
//

#import "LMServerRequest.h"
#import "LinkedME.h"

//验证请求优惠码
@interface LMValidatePromoCodeRequest : LMServerRequest

- (id)initWithCode:(NSString *)code useOld:(BOOL)useOld callback:(callbackWithParams)callback;

@end
