//
//  LMSystemObserver.h
//  iOS-Deep-Linking-SDK
//
//  Created by han on 6/5/14.
//  Copyright (c) 2014 LM han. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LMDeviceInfo.h"

@interface LMSystemObserver : NSObject

//获取UUID
+ (NSString *)getUniqueHardwareId:(BOOL *)isReal andIsDebug:(BOOL)debug;
+ (LMDeviceInfo *)getUniqueHardwareIdAndType:(BOOL *)isReal andIsDebug:(BOOL)debug;
//获取默认Url Scheme
+ (NSString *)getDefaultUriScheme;
//获取当前App版本
+ (NSString *)getAppVersion;
//获取Bundle ID
+ (NSString *)getBundleID;
//获取Team ID
+ (NSString *)getTeamIdentifier;
//获取运营商
+ (NSString *)getCarrier;
//LinkedMe
+ (NSString *)getLinkedME;
//获取设备类型
+ (NSString *)getModel;
//获取当前OS
+ (NSString *)getOS;
//获取OS版本
+ (NSString *)getOSVersion;
//获取屏幕宽度
+ (NSNumber *)getScreenWidth;
//获取屏幕高度
+ (NSNumber *)getScreenHeight;
//获取更新状态
+ (NSNumber *)getUpdateState;
//设置更新状态
+ (void)setUpdateState;
//获取设备名称
+ (NSString *)getDeviceName;
//判断是否是模拟器
+ (BOOL)isSimulator;
//安全获取idfa
+ (BOOL)adTrackingSafe;

@end
