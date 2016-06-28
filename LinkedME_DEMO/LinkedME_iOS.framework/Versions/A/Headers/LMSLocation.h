//
//  LMSLocation.h
//  Pods
//
//  Created by LinkedME04 on 6/16/16.
//
//

#import <Foundation/Foundation.h>
@import CoreLocation;

/**
 All fields are optional and should be populated only if known.
 @see `BTNBaseEntity` for inherited configuration options.
 */
@interface LMSLocation : NSObject

///---------------------
/// @name Initialization
///---------------------


/**
 Returns a named location instance.
 @param name The displayable name of the location.
 @param latitude  The latitude of the location.
 @param longitude The longitude of the location.
 */
+ (instancetype)locationWithPickupName:(NSString *)pname
                           dropoffName:(NSString *)dname
                                pickup:(CLLocationCoordinate2D)pickup
                               dropoff:(CLLocationCoordinate2D)drop;


/**
 Returns a location instance.
 @param latitude  The latitude of the location.
 @param longitude The longitude of the location.
 */
+ (instancetype)locationWithPickup:(CLLocationCoordinate2D)pickup
                           dropoff:(CLLocationCoordinate2D)drop;



///--------------------
/// @name Configuration
///--------------------


/// 设置纬度
- (void)setLatitude:(CLLocationDegrees)latitude;

/// 设置经度
- (void)setLongitude:(CLLocationDegrees)longitude;

/// 设置与位置相关的城市
- (void)setCity:(NSString *)city;

/// Sets the state associated with the location.
- (void)setState:(NSString *)state;

/// The country of the location.
- (void)setCountry:(NSString *)country;


@end