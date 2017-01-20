//
//  LinkedMETracking.h
//  Monitoring
//
//  Created by Admin on 26/10/2016.
//  Copyright © 2016 bindx. All rights reserved.
//

#import <Foundation/Foundation.h>


//游戏
@interface LMTracking : NSObject

/**
 *  @method onRegister      注册
 *  @param  account         帐号            类型:NSString
 */
+ (void)onRegister:(NSString *)account;

/**
 *  @method onLogin         登录
 *  @param  account         帐号            类型:NSString
 */
+ (void)onLogin:(NSString *)account;


/**
 *  @method onPay           支付
 *  @param  account         支付帐号          类型:NSString
 *  @param  orderId         订单id           类型:NSString
 *  @param  orderDetail     订单详           类型:NSString
 *  @param  amount          订单金额         类型:int
 *  @param  userAccount     账号            类型:NSString
 */
+ (void)onPay:(NSString *)payAccount withOrderId:(NSString *)orderId orderDetail:(NSDictionary *)orderDetail withAmount:(int)amount withUserAccount:(NSString *)userAccount;

/**
 *  @method onCustEvent1    自定义事件1
 */
+ (void)onCustEvent:(NSString *)pointName pointProperties:(NSDictionary *)pointProperties userAccount:(NSString *)account;


@end
