//
//  LinkedMETracking.h
//  Monitoring
//
//  Created by Admin on 26/10/2016.
//  Copyright © 2016 bindx. All rights reserved.
//

#import <Foundation/Foundation.h>


//订单
@interface LMOrder : NSObject

/**
 *  @method orderWithOrderId
 *  @param  orderId          订单id         类型:NSString
 *  @param  total            订单总价        类型:int
 *  @param  currencyType     币种           类型:NSString
 */
+ (LMOrder *)orderWithOrderId:(NSString *)orderId total:(int)total currencyType:(NSString *)currencyType;

/**
 *  @method addItemWithCategory
 *  @param  category         商品类别        类型:NSString
 *  @param  name             商品名称        类型:NSString
 *  @param  unitPrice        商品单价        类型:int
 *  @param  amount           商品数量        类型:int
 */
- (LMOrder *)addItemWithCategory:(NSString *)category name:(NSString *)name unitPrice:(int)unitPrice amount:(int)amount;

/**
 *  @method addItemWithCategory
 *  @param  category         商品类别        类型:NSString
 *  @param  itemId           商品Id         类型:NSString
 *  @param  name             商品名称        类型:NSString
 *  @param  unitPrice        商品单价        类型:int
 *  @param  amount           商品数量        类型:int
 */
- (LMOrder *)addItemWithCategory:(NSString *)category itemId:(NSString *)itemId name:(NSString *)name unitPrice:(int)unitPrice amount:(int)amount;

@end

//购物车
@interface LMShoppingCart : NSObject

/**
 *  @method createShoppingCart
 */
+ (LMShoppingCart *)createShoppingCart;



/**
 *  @method addItemWithCategory
 *  @param  category         商品类别        类型:NSString
 *  @param  itemId           商品Id         类型:NSString
 *  @param  name             商品名称        类型:NSString
 *  @param  unitPrice        商品单价        类型:int
 *  @param  amount           商品数量        类型:int
 */
- (LMShoppingCart *)addItemWithCategory:(NSString *)category itemId:(NSString *)itemId name:(NSString *)name unitPrice:(int)unitPrice amount:(int)amount;

@end


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
 *  @method onLogOff        注销
 *  @param  account         帐号            类型:NSString
 */
+ (void)onLogOff:(NSString *)account;

/*--------------------------------游戏--------------------------------*/

/**
 *  @method onCreateRole    创建角色
 *  @param  name            角色名称         类型:NSString
 */

+ (void)onCreateRole:(NSString *)name;
/**
 *  @method onDeleteRole    删除角色
 *  @param  name            角色名称         类型:NSString
 */
+ (void)onDeleteRole:(NSString *)name;

/**
 *  @method onCheckIn    签到
 */
+ (void)onCheckIn:(NSString *)name;

/*--------------------------------支付--------------------------------*/

/*pay*/
/**
 *  @method onPay           支付
 *  @param  account         帐号            类型:NSString
 *  @param  orderId         订单id          类型:NSString
 *  @param  amount          金额            类型:int
 *  @param  currencyType    币种            类型:NSString
 *  @param  payType         支付类型         类型:NSString
 */


+ (void)onPay:(NSString *)account withOrderId:(NSString *)orderId withAmount:(int)amount withCurrencyType:(NSString *)currencyType withPayType:(NSString *)payType;

/**
 *  @method onPay           支付
 *  @param  account         帐号            类型:NSString
 *  @param  orderId         订单id          类型:NSString
 *  @param  amount          金额            类型:int
 *  @param  currencyType    币种            类型:NSString
 *  @param  payType         支付类型         类型:NSString
 *  @param  order           订单详情         类型:TDOrder
 */
+ (void)onPay:(NSString *)account withOrderId:(NSString *)orderId withAmount:(int)amount withCurrencyType:(NSString *)currencyType withPayType:(NSString *)payType withOrder:(LMOrder *)order;

/**
 *  @method onPay           支付
 *  @param  account         帐号            类型:NSString
 *  @param  orderId         订单id          类型:NSString
 *  @param  amount          金额            类型:int
 *  @param  currencyType    币种            类型:NSString
 *  @param  payType         支付类型         类型:NSString
 *  @param  itemId          商品id          类型:NSString
 *  @param  itemCount       商品个数         类型:int
 */
+ (void)onPay:(NSString *)account withOrderId:(NSString *)orderId withAmount:(int)amount withCurrencyType:(NSString *)currencyType withPayType:(NSString *)payType withItemId:(int)itemId withItemCount:(int)itemCount;

/**
 *  @method onPlaceOrder    下单
 *  @param  account         帐号            类型:NSString
 *  @param  order           订单            类型:TDOrder
 */
+ (void)onPlaceOrder:(NSString *)account withOrder:(LMOrder *)order;

/**
 *  @method onOrderPaySucc  支付
 *  @param  account         帐号            类型:NSString
 *  @param  orderId         订单id          类型:NSString
 *  @param  amount          金额            类型:int
 *  @param  currencyType    币种            类型:NSString
 *  @param  payType         支付类型         类型:NSString
 */
+ (void)onOrderPaySucc:(NSString *)account withOrderId:(NSString *)orderId withAmount:(int)amount withCurrencyType:(NSString *)currencyType withPayType:(NSString *)payType;

/**
 *  @method onViewItemWithCategory
 *  @param  category         商品类别        类型:NSString
 *  @param  itemId           商品Id         类型:NSString
 *  @param  name             商品名称        类型:NSString
 *  @param  unitPrice        商品单价        类型:int
 */
+ (void)onViewItemWithCategory:(NSString *)category itemId:(NSString *)itemId name:(NSString *)name unitPrice:(int)unitPrice;

/**
 *  @method onAddItemToShoppingCartWithCategory
 *  @param  category         商品类别        类型:NSString
 *  @param  itemId           商品Id         类型:NSString
 *  @param  name             商品名称        类型:NSString
 *  @param  unitPrice        商品单价        类型:int
 *  @param  amount           商品数量        类型:int
 */
+ (void)onAddItemToShoppingCartWithCategory:(NSString *)category itemId:(NSString *)itemId name:(NSString *)name unitPrice:(int)unitPrice amount:(int)amount;

+ (void)onRemoveItemToShoppingCartWithCategory:(NSString *)category itemId:(NSString *)itemId name:(NSString *)name unitPrice:(int)unitPrice amount:(int)amount;

/**
 *  @method onViewShoppingCart
 *  @param  shoppingCart    购物车信息       类型:TDShoppingCart
 */
+ (void)onViewShoppingCart:(LMShoppingCart *)shoppingCart;

/**
 *  @method onCustEvent1    自定义事件1
 */
+ (void)onCustEvent:(NSString *)eventName;


@end
