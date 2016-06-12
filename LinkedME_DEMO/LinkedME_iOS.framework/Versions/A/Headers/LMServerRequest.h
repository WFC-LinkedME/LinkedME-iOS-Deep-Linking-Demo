//
//  LMServerRequest.h
//  iOS-Deep-Linking-SDK
//
//  Created by han on 6/5/14.
//  Copyright (c) 2014 LM han. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LMServerInterface.h"

@interface LMServerRequest : NSObject <NSCoding>

- (void)makeRequest:(LMServerInterface *)serverInterface key:(NSString *)key callback:(LMServerCallback)callback;
- (void)processResponse:(LMServerResponse *)response error:(NSError *)error;

@end
