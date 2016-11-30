//
//  LMLinkProperties.h
//  iOS-Deep-Linking-SDK
//
//  Created by han on 10/16/15.
//  Copyright © 2015 Bindx. All rights reserved.
//

#import <Foundation/Foundation.h>

//端链属性

@interface LMLinkProperties : NSObject

@property (nonatomic, strong) NSArray  *tags;                   //标签
@property (nonatomic, strong) NSString *feature;                //特点
@property (nonatomic, strong) NSString *alias;                  //别名(lime没有实现,深度链接别名)
@property (nonatomic, strong) NSString *channel;                //渠道
@property (nonatomic, strong) NSString *stage;                  //阶段
@property (nonatomic, strong) NSString *source;                 //来源
@property (nonatomic) NSUInteger matchDuration;                 //匹配延迟周期
@property (nonatomic, strong) NSDictionary *controlParams;
@property (nonatomic,copy)NSString *androidPathControlParam;
@property (nonatomic,copy)NSString *iOSKeyControlParam;         


- (void)addControlParam:(NSString *)controlParam withValue:(NSString *)value;
+ (LMLinkProperties *)getLinkedMELinkPropertiesFromDictionary:(NSDictionary *)dictionary;

- (NSString *)description;

@end
