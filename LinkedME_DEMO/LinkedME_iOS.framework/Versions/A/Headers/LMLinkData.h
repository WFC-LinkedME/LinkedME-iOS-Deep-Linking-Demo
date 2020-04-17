//
//  LMLinkData.h
//  iOS-Deep-Linking-SDK
//  Created on 1/22/15.
//  Copyright (c) 2015 Bindx. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, LMLinkType) {
    LinkedMELinkTypeUnlimitedUse = 0, //永久有效
    LinkedMELinkTypeOneTimeUse = 1    //一次有效
};

@interface LMLinkData : NSObject

@property (strong, nonatomic) NSMutableDictionary *data;

//设置标签
- (void)setupTags:(NSArray *)tags;
//设置别名
- (void)setupAlias:(NSString *)alias;
//设置类型
- (void)setupType:(LMLinkType)type;
//设置渠道
- (void)setupChannel:(NSString *)channel;
//设置功能
- (void)setupFeature:(NSString *)feature;
//设置阶段
- (void)setupStage:(NSString *)stage;
//
- (void)setupState:(BOOL)state;
//设置参数
- (void)setupParams:(NSDictionary *)params;
//设置有效时间
- (void)setupMatchDuration:(NSUInteger)duration;
//设置UA字段
- (void)setupIgnoreUAString:(NSString *)ignoreUAString;

@end
