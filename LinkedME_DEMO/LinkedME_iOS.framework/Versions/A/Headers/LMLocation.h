//
//  LMLocation.h
//  iOS-Deep-Linking-SDK
//
//  Created by han on 16/4/13.
//  Copyright © 2016年 LM han. All rights reserved.
//

#import "LMBaseEntity.h"
#import <CoreLocation/CoreLocation.h>
@interface LMLocation : LMBaseEntity

//开始位置
@property (nonatomic,assign)CLLocationDegrees beginLatitude;
@property (nonatomic,assign)CLLocationDegrees beginLongitude;


//结束位置
@property (nonatomic,assign)CLLocationDegrees endLatitude;
@property (nonatomic,assign)CLLocationDegrees endLongitude;
@property (nonatomic,strong)NSString *begainLocationName;
@property (nonatomic,strong)NSString *endLocationName;

/**
 Returns a named location instance.
 @param name The displayable name of the location.
 @param latitude  The latitude of the location.
 @param longitude The longitude of the location.
 */

+ (instancetype)location;

+ (instancetype)locationWithBegainLocationName:(NSString *)name
                        latitude:(CLLocationDegrees)latitude
                       longitude:(CLLocationDegrees)longitude;


+ (instancetype)locationWithEndLocationName:(NSString *)name
                                      latitude:(CLLocationDegrees)latitude
                                     longitude:(CLLocationDegrees)longitude;
/// Sets the latitude of the location (requires a longitude).
- (void)setLatitude:(CLLocationDegrees)latitude;


/// Sets the longitude of the location (requires a latitude).
- (void)setLongitude:(CLLocationDegrees)longitude;


@end
