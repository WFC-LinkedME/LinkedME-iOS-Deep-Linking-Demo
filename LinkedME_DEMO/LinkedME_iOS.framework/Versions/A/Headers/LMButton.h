//
//  LMButton.h
//  Pods
//
//  Created by LinkedME04 on 6/16/16.
//
//

#import <Foundation/Foundation.h>
#import "LMSButtonType.h"

@interface LMButton : UIButton

@property (nonatomic, copy) NSString *buttonId;

- (void)prepareWithType:(ButtonType)context addTo:(UIView *)view
             completion:(void(^)(BOOL isDisplayable))completionHandler;

- (instancetype)initWithButtonId:(NSString *)buttonId;

@end
