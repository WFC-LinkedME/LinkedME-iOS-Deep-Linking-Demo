//
//  OWSManger.h
//  OWS
//
//  Created by Bindx on 14/8/9.
//  Copyright (c) 2014年 Bindx. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LMManger : NSObject


+ (LMManger *)netshared;

//经度
@property (nonatomic)  float longitude;
//纬度
@property (nonatomic)  float latitude;

//获取位置信息
- (void)getLocation;

@end
