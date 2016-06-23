//
//  LMSPreferenceHelper.h
//  Pods
//
//  Created by LinkedME04 on 6/16/16.
//
//

#import <Foundation/Foundation.h>

@interface LMSPreferenceHelper : NSObject

//起点
@property (nonatomic ,copy) NSString *pname;
//终点
@property (nonatomic ,copy) NSString *dname;

//开始纬度
@property (nonatomic) double pickup_longitude;
//开始经度
@property (nonatomic) double pickup_latitude;
//结束经度
@property (nonatomic) double dropoff_longitude;
//结束纬度
@property (nonatomic) double dropoff_latitude;

+ (LMSPreferenceHelper *)preferenceHelper;

@end
