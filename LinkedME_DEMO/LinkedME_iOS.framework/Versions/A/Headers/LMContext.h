//
//  LMContext.h
//  iOS-Deep-Linking-SDK
//
//  Created by han on 16/4/13.
//  Copyright © 2016年 LM han. All rights reserved.
//

#import <Foundation/Foundation.h>
@class LMLocation;

#import "LMLocation.h"

@interface LMContext : NSObject

@property (nonatomic,strong)LMLocation *begainLocation;
@property (nonatomic,strong)LMLocation *endLocation;
/**
 Returns a newly instantiated context object.
 */
//+ (instancetype)context;

/**
 Returns a newly instantiated context object with a subject location.
 @param subjectLocation a location subject for the current activity or content.
 @see -setSubjectLocation: for more info.
 */
+ (instancetype)contextWithBegainLocation:(LMLocation *)begainLocation andEndLocation:(LMLocation *)endLocation;


/**
 Sets a location subject for the current activity or content.
 Example: A restaurant on a venue page, point on a map or city in a travel app
 @note Provide whatever level of granularity makes sense for the context.
 @see `BTNLocation` for details of all the different ways of expressing a location.
 */
//- (void)setSubjectLocation:(LinkedMeLocation *)subjectLocation;

@end
