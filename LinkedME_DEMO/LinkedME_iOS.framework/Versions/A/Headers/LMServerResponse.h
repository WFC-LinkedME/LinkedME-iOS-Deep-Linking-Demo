//
//  LMServerResponse.h
//  iOS-Deep-Linking-SDK
//
//  Created by han on 10/10/14.
//  Copyright (c) 2014 LM han. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LMServerResponse : NSObject

@property (nonatomic, strong) NSNumber *statusCode;
@property (nonatomic, strong) id data;

@end
