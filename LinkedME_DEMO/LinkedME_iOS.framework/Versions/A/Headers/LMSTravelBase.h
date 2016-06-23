//
//  Uber.h
//  LinkedME-iOS-Deep-Linking-Demo
//
//  Created by Bindx on 5/18/16.
//  Copyright © 2016 Bindx. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

#import "LMContext.h"
//#import "LMButton.h"
#import "LMServerInterface.h"
#import "LMBaseEntity.h"

@interface LMSTravelBase : NSObject

//起点位置
@property (nonatomic ,assign) CLLocationCoordinate2D pickupLocation;
//重点位置
@property (nonatomic ,assign) CLLocationCoordinate2D dropoffLocation;
//起点位置名称
@property (nonatomic ,copy  ) NSString *pickupNickname;
//起点地址
@property (nonatomic ,copy  ) NSString *pickupFormattedAddress;
//终点位置名称
@property (nonatomic ,copy  ) NSString *dropoffNickname;
//终点位置地址
@property (nonatomic ,copy  ) NSString *dropoffFormattedAddress;

/**
 *	@brief	如果已安装App直接打开App,否则打开Deeplink url
 */
- (void)deepLink;

/**
 *	@brief	初始化
 *
 *	@param 	pickupLocation 	开始位置
 *
 *	@return	self
 */

- (instancetype)initWithLocation:(CLLocationCoordinate2D)pickupLocation;
/**
 *	@brief	通过位置获取预计价格
 *
 *	@param 	pickup 	开始位置
 *	@param 	drop 	结束位置
 */
- (void)getUberEstimatesPriceWithPickupLocation:(CLLocationCoordinate2D)pickup DropofLocation:(CLLocationCoordinate2D)drop callBack:(void(^)(NSString *))callback;

@end
