//
//  LMMeBaseEntity.h
//  iOS-Deep-Linking-SDK
//
//  Created by han on 16/4/13.
//  Copyright © 2016年 LM han. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LMBaseEntity : NSObject

typedef void (^CompletionHandler) (BOOL);
//typedef void (^completionHandler) (LinkedMeBaseEntity *);


//@property (nonatomic,assign) void (^ completionHandler) (BOOL isDisplayable);

typedef void (^innerCallBack) (LMBaseEntity *);

@property (nonatomic,strong) NSString * schemeUrl;
@property (nonatomic,strong) NSString * buttonIcon;
@property (nonatomic,copy)   NSDictionary *btn_msgDic;
@end
