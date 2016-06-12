//
//  LMLinkProperties.h
//  iOS-Deep-Linking-SDK
//
//  Created by han on 10/16/15.
//  Copyright © 2015 LM han. All rights reserved.
//

#import <Foundation/Foundation.h>

//端链属性
@interface LMLinkProperties : NSObject

@property (nonatomic, strong) NSArray *tags;
@property (nonatomic, strong) NSString *feature;
@property (nonatomic, strong) NSString *alias;
@property (nonatomic, strong) NSString *channel;
@property (nonatomic, strong) NSString *stage;
@property (nonatomic, strong) NSString *source;
@property (nonatomic) NSUInteger matchDuration;
@property (nonatomic, strong) NSDictionary *controlParams;
@property (nonatomic,copy)NSString *androidPathControlParam;
@property (nonatomic,copy)NSString *iOSKeyControlParam;


- (void)addControlParam:(NSString *)controlParam withValue:(NSString *)value;
+ (LMLinkProperties *)getBranchLinkPropertiesFromDictionary:(NSDictionary *)dictionary;

- (NSString *)description;

@end
