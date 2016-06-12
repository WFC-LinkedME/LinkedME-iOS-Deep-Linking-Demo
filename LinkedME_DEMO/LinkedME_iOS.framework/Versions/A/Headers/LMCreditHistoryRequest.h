//
//  LMCreditHistoryRequest.h
//  iOS-Deep-Linking-SDK
//
//  Created by han on 5/22/15.
//  Copyright (c) 2015 LM han. All rights reserved.
//

#import "LMServerRequest.h"
#import "LinkedME.h"

//请求信用记录

@interface LMCreditHistoryRequest : LMServerRequest

- (id)initWithBucket:(NSString *)bucket creditTransactionId:(NSString *)creditTransactionId length:(NSInteger)length order:(LMCreditHistoryOrder)order callback:(callbackWithList)callback;

@end
