//
//  LMButton.h
//  iOS-Deep-Linking-SDK
//
//  Created by han on 16/4/13.
//  Copyright © 2016年 LM han. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LMContext.h"
#import "LMUniversalObject.h"

@class LMContext;
@class LMUniversalObject;
@interface LMButton : UIButton


@property (strong, nonatomic) LMUniversalObject *branchUniversalObject;
@property (nonatomic,strong)  NSString *schemeUrl;
@property (nonatomic, copy) IBInspectable NSString *buttonId;
@property (nonatomic,copy)__block LMBaseEntity *entity;
@property (nonatomic,assign) CompletionHandler completionHandler;

- (void)prepareWithContext:(LMContext *)context
                completion:(CompletionHandler) completionHandler;

- (instancetype)initWithButtonId:(NSString *)buttonId;

-(void)touchBtn;

@end

@interface MyUIButton : LMButton{
    NSString *idx;
}

@property (nonatomic,retain) NSString *idx;

@end