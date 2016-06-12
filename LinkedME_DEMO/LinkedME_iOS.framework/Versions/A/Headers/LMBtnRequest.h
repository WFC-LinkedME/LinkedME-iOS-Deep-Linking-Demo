//
//  LMBtnRequest.h
//  iOS-Deep-Linking-SDK
//
//  Created by han on 16/4/14.
//  Copyright © 2016年 LM han. All rights reserved.
//

#import "LMServerRequest.h"
#import "LMContext.h"
#import "LMButton.h"
#import "LMServerInterface.h"
#import "LMBaseEntity.h"

@interface LMBtnRequest : LMServerRequest


//@property (nonatomic,copy)CompletionHandler completionHandler;
//@property (nonatomic,copy) innerCallBack innerCallBack;
//@property (nonatomic,strong)LMContext *context;
//@property (nonatomic,strong)NSString *buttonId;
//
//-(id)initWithLinkedMeContext:(LMContext *)context andButtonId:(NSString *)btnId  completion:(CompletionHandler)completionHandler andInnerCallBack:(innerCallBack)innerCallBack;

@property (strong, nonatomic) callbackWithStatus callback;

- (id)initWithCallback:(callbackWithStatus)callback;

@end
