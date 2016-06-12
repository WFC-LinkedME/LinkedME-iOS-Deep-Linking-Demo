//
//  LMError.h
//  iOS-Deep-Linking-SDK
//
//  Created by han on 11/17/14.
//  Copyright (c) 2014 LM han. All rights reserved.
//

#import <Foundation/Foundation.h>

FOUNDATION_EXPORT NSString * const LMErrorDomain;

enum {
    BNCInitError = 1000,
    BNCDuplicateResourceError,  //重复的资源错误
    BNCInvalidPromoCodeError,   //无效的促销代码
    BNCRedeemCreditsError,      //额度错误
    BNCBadRequestError,         //错误请求
    BNCServerProblemError,      //服务器错误
    BNCNilLogError,             //日志错误
    BNCVersionError             //版本错误
};

@interface LMError : NSObject

@end