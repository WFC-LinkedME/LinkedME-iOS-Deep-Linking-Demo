//
//  LinkAdView.h
//  LinkActive
//
//  Created by Admin on 09/01/2017.
//  Copyright © 2017 bindx. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface LinkAdView : UIView


+ (instancetype)getAdWithFrame:(CGRect)frame withAdid:(NSInteger)adid tags:(NSString *)tags statusCallBack:(void(^)(BOOL status ,NSDictionary *content))block;

- (void)openScheme:(NSString *)scheme AndAdid:(NSUInteger)adid;


@end
