//
//  LM_SDK.h
//  iOS-Deep-Linking-SDK
//
//  Created by han on 6/5/14.
//  Copyright (c) 2014 LM han. All rights reserved.
//
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "LMActivityItemProvider.h"
#import "LMServerInterface.h"
#import "LMServerRequestQueue.h"
#import "LMLinkCache.h"
#import "LMDeepLinkingController.h"
#import "LMPreferenceHelper.h"
#import "LMBaseEntity.h"
#import "LMContext.h"

@class LMUniversalObject;
@class LMLinkProperties;

//#import "LMUniversalObject.h"

/**
 `LM` is the primary interface of the LM iOS SDK. Currently, all interactions you will make are funneled through this class. It is not meant to be instantiated or subclassed, usage should be limited to the global instance.
 
  Note, when `getInstance` is called, it assumes that you have already placed a LM Key in your main `Info.plist` file for your project. For additional information on configuring the LM SDK, check out the getting started guides in the Readme.
 */

typedef void (^callbackWithParams) (NSDictionary *params, NSError *error);
typedef void (^callbackWithUrl) (NSString *url, NSError *error);
typedef void (^callbackWithStatus) (BOOL changed, NSError *error);
typedef void (^callbackWithList) (NSArray *list, NSError *error);
typedef void (^callbackWithUrlAndSpotlightIdentifier) (NSString *url, NSString *spotlightIdentifier, NSError *error);
typedef void (^callbackWithLinkedMEUniversalObject) (LMUniversalObject *universalObject, LMLinkProperties *linkProperties, NSError *error);
///----------------
/// @name Constants
///----------------

#pragma mark - LM Link Features

/**
 ## LM 链接功能
 以下是常量用于指定特性参数,创建一个LM链接.
 
 `LINKEDME_FEATURE_SHARE`
  这个链接是用来分享的内容。使用“getContentUrl”方法。
 
 `LINKEDME_FEATURE_TAG_REFERRAL`
 Indicates this link was used to refer users to this app. Used by the `getReferralUrl` methods.
 
 `LINKEDME_FEATURE_TAG_INVITE`
  这个链接用作邀请。
 
 `LINKEDME_FEATURE_TAG_DEAL`
 Indicates this link is being used to trigger a deal, like a discounted rate.
  表示该链接被用来触发交易，如打折。
 
 `LINKEDME_FEATURE_TAG_GIFT`
 使用的是这个链接表示发送礼物到另一个用户。
 */
extern NSString * const LINKEDME_FEATURE_TAG_SHARE;
extern NSString * const LINKEDME_FEATURE_TAG_REFERRAL;
extern NSString * const LINKEDME_FEATURE_TAG_INVITE;
extern NSString * const LINKEDME_FEATURE_TAG_DEAL;
extern NSString * const LINKEDME_FEATURE_TAG_GIFT;

#pragma mark - LINKEDME InitSession Dictionary Constants

/**
 ## LINKEDME Link Features
 
 `LINKEDME_INIT_KEY_CHANNEL`
 在创建连接时,指定链接的共享
 
 `LINKEDME_INIT_KEY_FEATURE`
 The feature, such as `invite` or `share`, specified at link creation time.
 在创建连接时指定功能,如“邀请”或“分享”,
 
 `LINKEDME_INIT_KEY_TAGS`
 在创建链接时指定任何标记。
 
 `LINKEDME_INIT_KEY_CAMPAIGN`
 链接创建时在指定的活动相关的链接。 
 
 `LINKEDME_INIT_KEY_STAGE`
 在创建链接时指定阶段。
 
 `LINKEDME_INIT_KEY_CREATION_SOURCE`
 创建链接(“API”、“Dashboard”、“SDK”,“iOS SDK”,“Android SDK”,或 “Web SDK”)
 
 `LINKEDME_INIT_KEY_REFERRER`
 如果链接被点击,获得链接推荐人,
 
 `LINKEDME_INIT_KEY_PHONE_NUMBER`
 如果用户给自己发送连接
 
 `LINKEDME_INIT_KEY_IS_FIRST_SESSION`
 Denotes whether this is the first session (install) or any other session (open).
 是否这是首次安装(安装)或任何其它会话话(打开)。
 
 `LINKEDME_INIT_KEY_CLICKED_LINKEDME_LINK`
 用户点击一个LKME链接是否触发这个会话。 
 */

extern NSString * const LINKEDME_INIT_KEY_CHANNEL;
extern NSString * const LINKEDME_INIT_KEY_FEATURE;
extern NSString * const LINKEDME_INIT_KEY_TAGS;
extern NSString * const LINKEDME_INIT_KEY_CAMPAIGN;
extern NSString * const LINKEDME_INIT_KEY_STAGE;
extern NSString * const LINKEDME_INIT_KEY_CREATION_SOURCE;
extern NSString * const LINKEDME_INIT_KEY_REFERRER;
extern NSString * const LINKEDME_INIT_KEY_PHONE_NUMBER;
extern NSString * const LINKEDME_INIT_KEY_IS_FIRST_SESSION;
extern NSString * const LINKEDME_INIT_KEY_CLICKED_LINKEDME_LINK;

#pragma mark - LKME Enums
typedef NS_ENUM(NSUInteger, LMCreditHistoryOrder) {
    
    LinkedMeMostRecentFirst,
    LinkedMeLeastRecentFirst
    
};

typedef NS_ENUM(NSUInteger, LMPromoCodeRewardLocation ) {
    LinkedMePromoCodeRewardReferredUser __attribute__((deprecated(("这个属性已被弃用。LinkedME将不再提供任何改进或修改推荐/优惠码功能。")))) = 0,
    LinkedMePromoCodeRewardReferringUser __attribute__((deprecated(("这个属性已被弃用。LinkedME将不再提供任何改进或修改推荐/优惠码功能。")))) = 2,
    LinkedMePromoCodeRewardBothUsers __attribute__((deprecated(("这个属性已被弃用。LinkedME将不再提供任何改进或修改推荐/优惠码功能。")))) = 3
};

typedef NS_ENUM(NSUInteger, LMPromoCodeUsageType) {
    LinkedMePromoCodeUsageTypeOncePerUser __attribute__((deprecated(("这个属性已被弃用。LinkedME将不再提供任何改进或修改推荐/优惠码功能。")))) = 1,
    LinkedMePromoCodeUsageTypeUnlimitedUses __attribute__((deprecated(("这个属性已被弃用。LinkedME将不再提供任何改进或修改推荐/优惠码功能。")))) = 0
};

@interface LinkedME : NSObject

#pragma mark - Global Instance Accessors

///--------------------------------
/// @name 全局实例访问器
///--------------------------------

/**
 线上版
 */
+ (LinkedME *)getInstance;

/**
 测试版
 
 @warning 不要使用此方法production!
 */
+ (LinkedME *)getTestInstance;

/**
 获取LinkedME实例、配置linkedMeKey
 
 @param 必要参数.
 @warning 不建议使用此方法,建议在Info.plist中配置
 */
+ (LinkedME *)getInstance:(NSString *)linkedMeKey;


#pragma mark - LKMEActivityItemProvider methods

///-----------------------------------------
/// @name LKMEActivityItemProvider methods
///-----------------------------------------

/**
 创建一个UIActivityViewController子类通过UIActivityViewController分享内容,创建一个短连接添加到共享中
 
 @param 创建LinkMe短链接必要参数
 */
+ (LMActivityItemProvider *)getLinkedMEActivityItemWithParams:(NSDictionary *)params;

/**
 创建一个“UIActivityItemProvider”子类LKMEActivityItemProvider用于简单的通过“UIActivityViewController”共享。在内部,这将创建一个短LinkedME Url将被附加到共享内容。
 
 @param 创建LinkMe短链接必要参数
 @param 生成特定功能的相关链接.
 */
+ (LMActivityItemProvider *)getBranchActivityItemWithParams:(NSDictionary *)params feature:(NSString *)feature;
+ (LMActivityItemProvider *)getBranchActivityItemWithParams:(NSDictionary *)params andFeature:(NSString *)feature  __attribute__((deprecated(("Use methods without 'and'"))));

/**
 创建“UIActivityItemProvider”子类LKMEActivityItemProvider这可用于简单的通过“UIActivityViewController”共享。在内部,这将创建一个短LinkedME Url将被附加到共享内容。
 
 @param 创建LinkMe短链接必要参数
 @param 生成特定功能的相关链接.
 @param 阶段性链接,用于指示用户属于什么是时间点
 */
+ (LMActivityItemProvider *)getBranchActivityItemWithParams:(NSDictionary *)params feature:(NSString *)feature stage:(NSString *)stage;
+ (LMActivityItemProvider *)getBranchActivityItemWithParams:(NSDictionary *)params andFeature:(NSString *)feature andStage:(NSString *)stage __attribute__((deprecated(("Use methods without 'and'"))));

/**
 创建`UIActivityViewController`子类的`UIActivityItemProvider`这可以通过一个用于简单共享LKMEActivityItemProvider。将创建一个短LinkedME地址将被附连到共享内容。
 
 @param 创建LinkMe短链接必要参数
 @param 生成特定功能的相关链接.
 @param 阶段性链接,用于指示用户属于什么是时间点
 @param 添加标签和关联
 */
+ (LMActivityItemProvider *)getBranchActivityItemWithParams:(NSDictionary *)params feature:(NSString *)feature stage:(NSString *)stage tags:(NSArray *)tags;
+ (LMActivityItemProvider *)getBranchActivityItemWithParams:(NSDictionary *)params andFeature:(NSString *)feature andStage:(NSString *)stage andTags:(NSArray *)tags __attribute__((deprecated(("Use methods without 'and'"))));

/**
 创建`UIActivityViewController`子类的`UIActivityItemProvider`这可以通过一个用于简单共享LKMEActivityItemProvider。将创建一个短LinkedME地址将被附连到共享内容。
 
 
 @param 创建LinkMe短链接必要参数
 @param 生成特定功能的相关链接.
 @param 阶段性链接,用于指示用户属于什么是时间点
 @param 链接别名.
 @warning 如果已使用别名可能失败.
 */
+ (LMActivityItemProvider *)getBranchActivityItemWithParams:(NSDictionary *)params feature:(NSString *)feature stage:(NSString *)stage tags:(NSArray *)tags alias:(NSString *)alias;
+ (LMActivityItemProvider *)getBranchActivityItemWithParams:(NSDictionary *)params andFeature:(NSString *)feature andStage:(NSString *)stage andAlias:(NSString *)alias __attribute__((deprecated(("Use methods without 'and'"))));
+ (LMActivityItemProvider *)getBranchActivityItemWithParams:(NSDictionary *)params andTags:(NSArray *)tags andFeature:(NSString *)feature andStage:(NSString *)stage andAlias:(NSString *)alias __attribute__((deprecated(("Use methods without 'and'"))));

/**
 创建`UIActivityViewController`子类的`UIActivityItemProvider`这可以通过一个用于简单共享LKMEActivityItemProvider。将创建一个短LinkedME地址将被附连到共享内容。

 
 @param 创建LinkMe短链接必要参数
 @param 生成特定功能的相关链接.
 @param 阶段性链接,用于指示用户属于什么是时间点
 @param 链接别名.
 @params delegate覆盖用户选择的参数
 @warning 如果已使用别名会失败.
 */

+ (LMActivityItemProvider *)getBranchActivityItemWithParams:(NSDictionary *)params feature:(NSString *)feature stage:(NSString *)stage tags:(NSArray *)tags alias:(NSString *)alias delegate:(id <LKMEActivityItemProviderDelegate>)delegate;



#pragma mark - 初始化方法

///---------------------
/// @name 初始化
///---------------------

/**
 初始化LinkedME会话和应用程序启动选项。
 
 @param AppDelegate提供的启动选项的“didFinishLaunchingWithOptions:”方法中实现。
 @warning 不推荐使用此方法初始化LinkedME. 可以正常启动但没有回调信息
 */
- (void)initSessionWithLaunchOptions:(NSDictionary *)options;

/**
 初始化LinkedME会话和应用程序启动选项
 
 @param 在AppDelegate提供的启动选项的“didFinishLaunchingWithOptions:”方法中实现。
 @param 是否允许会话标记为参考,覆盖默认行为。
 @warning 不推荐使用此方法初始化LinkedME. 可以正常启动但没有回调信息
 */
- (void)initSessionWithLaunchOptions:(NSDictionary *)options isReferrable:(BOOL)isReferrable;

/**
 初始化LinkedME提供Block回调处理RegisterDeepLinkHandler
 
 @param 选项在AppDelegate提供的启动选项的“didFinishLaunchingWithOptions:”方法中实现
 @param callback 打开App时回调,包含后台进入前台.
 */
- (void)initSessionWithLaunchOptions:(NSDictionary *)options andRegisterDeepLinkHandler:(callbackWithParams)callback;

/**
 初始化LinkedME提供Block回调处理
 
 @param 选项在AppDelegate提供的启动选项的“didFinishLaunchingWithOptions:”方法中实现
 @param callback 打开App时回调,包含后台进入前台.
 */
- (void)initSessionWithLaunchOptions:(NSDictionary *)options pres:(callbackWithLinkedMEUniversalObject)callback;

/**
 初始化LinkedME提供Block回调处理
 
 @param 选项在AppDelegate提供的启动选项的“didFinishLaunchingWithOptions:”方法中实现
 @param automaticallyDisplayController 是否自动打开DeepLink连接
 */
- (void)initSessionWithLaunchOptions:(NSDictionary *)options automaticallyDisplayDeepLinkController:(BOOL)automaticallyDisplayController;

/**
 初始化LinkedME提供Block回调处理
 
 @param 选项在AppDelegate提供的启动选项的“didFinishLaunchingWithOptions:”方法中实现
 @param 是否允许会话标记为参考,覆盖默认行为。
 @param callback 打开App时回调,包含后台进入前台.
 */
- (void)initSessionWithLaunchOptions:(NSDictionary *)options isReferrable:(BOOL)isReferrable andRegisterDeepLinkHandler:(callbackWithParams)callback;

/**
 初始化LinkedME提供Block回调处理
 
 @param 选项在AppDelegate提供的启动选项的“didFinishLaunchingWithOptions:”方法中实现
 @param 是否允许会话标记为参考,覆盖默认行为。
 @param automaticallyDisplayController 是否自动打开DeepLink连接
 */
- (void)initSessionWithLaunchOptions:(NSDictionary *)options isReferrable:(BOOL)isReferrable automaticallyDisplayDeepLinkController:(BOOL)automaticallyDisplayController;

/**
 初始化LinkedME提供Block回调处理
 
 @param 选项在AppDelegate提供的启动选项的“didFinishLaunchingWithOptions:”方法中实现
 @param automaticallyDisplayController 是否自动打开DeepLink连接
 @param callback 打开App时回调,包含后台进入前台.
 */
- (void)initSessionWithLaunchOptions:(NSDictionary *)options automaticallyDisplayDeepLinkController:(BOOL)automaticallyDisplayController deepLinkHandler:(callbackWithParams)callback;

/**
 初始化LinkedME提供Block回调处理
 
 @param 选项在AppDelegate提供的启动选项的“didFinishLaunchingWithOptions:”方法中实现
 @param automaticallyDisplayController 是否自动打开DeepLink连接
 @param 是否允许会话标记为参考,覆盖默认行为。
 @param callback 打开App时回调,包含后台进入前台.
 */
- (void)initSessionWithLaunchOptions:(NSDictionary *)options automaticallyDisplayDeepLinkController:(BOOL)automaticallyDisplayController isReferrable:(BOOL)isReferrable deepLinkHandler:(callbackWithParams)callback;

/**
 允许LinkedME处理链接打开应用程序,打开后是否返回。
 
 @param url 使用url打开应用.
 */
- (BOOL)handleDeepLink:(NSURL *)url;

/**
 允许从NSUserActivity处理连接,是否返回。
 
 @param userActivity 打开应用.
 */
- (BOOL)continueUserActivity:(NSUserActivity *)userActivity;

///--------------------------------
/// @name 推送通知支持
///--------------------------------

#pragma mark - Push Notification support

/**
 允许从通知中心打开
 
 在创建推送式通知时,指定关键的NSString LKME链接,@“LinkedME”
 
 NSDictionary userInfo = @{@"LKME": @"https://bnc.lt/...", ... };
 */
- (void)handlePushNotification:(NSDictionary *)userInfo;

#pragma mark - Deep Link Controller methods

///---------------------------
/// @name Deep Link 控制器
///---------------------------

//注册深度链接控制器
- (void)registerDeepLinkController:(UIViewController <LMDeepLinkingController> *)controller forKey:(NSString *)key;

#pragma mark - Configuration methods

///--------------------
/// @name 配置
///--------------------

/**
 Debug模式,记录反馈更多信息
 
 @warning 不适用于production!!
 */
- (void)setDebug;

/**
 Debug模式,记录反馈更多信息
 
 @warning 方法已启用,使用实例方法调用
 @warning 不适用于production!!
 */
+ (void)setDebug __attribute__((deprecated(("使用实例方法调用,方法已弃用"))));

/**
 增加指定其他常数的参数
 
 @param debugParams dictionary of keystrings/valuestrings that will be added to response
 */
-(void) setDeepLinkDebugMode:(NSDictionary *)debugParams;


/**
 设置时间（秒）尝试重连LinkedME服务器
 
 @param retryInterval 秒.
 */
- (void)setRetryInterval:(NSTimeInterval)retryInterval;

/**
 设置最大重试次数
 
 @param maxRetries 重试次数
 */
- (void)setMaxRetries:(NSInteger)maxRetries;

/**
 请求超时设置(秒)
 
 @param timeout 秒
 */
- (void)setNetworkTimeout:(NSTimeInterval)timeout;

/**
 使用SFSafariViewController尝试cookie匹配。默认情况启用。
 
 @warning Please import SafariServices in order for this to work.
 */
- (void)disableCookieBasedMatching;

#pragma mark - Session Item methods

///--------------------
/// @name Session Items
///--------------------

/**
 Get the LKMEUniversalObject from the first time this user was referred (can be empty).
 */
- (LMUniversalObject *)getFirstReferringBranchUniversalObject;

/**
 Get the LKMELinkProperties from the first time this user was referred (can be empty).
 */
- (LMLinkProperties *)getFirstReferringBranchLinkProperties;

/**
 获取用户第一次使用信息 (可空).
 */
- (NSDictionary *)getFirstReferringParams;

/**
 最近一次获取LKMEUniversalObject信息(可空)
 */
- (LMUniversalObject *)getLatestReferringBranchUniversalObject;

/**
 从最近一次获取LKMELinkProperties属性(可空）
 */
- (LMLinkProperties *)getLatestReferringBranchLinkProperties;

/**
    获取参数最近使用时间
 */
- (NSDictionary *)getLatestReferringParams;

/**
 内部调用自动完成
 Tells LinkedME to act as though initSession hadn't been called. Will require another open call (this is done automatically, internally).

 */
- (void)resetUserSession;

/**
 
 用户是否自定义身份
 */
- (BOOL)isUserIdentified;

/**
 设置用户标识设置
 @param userId 用户标识
 @warning 如果你使用相同的ID用户之间在不同会话/设备,他们的行为将会被合并。
 */
- (void)setIdentity:(NSString *)userId;

/**
 设置用户表示,并且提供回调信息
 
 @param userId 用户标识
 @param callback 回调信息,成功或失败.
 
 */
- (void)setIdentity:(NSString *)userId withCallback:(callbackWithParams)callback;

/**
 清除当前用户的所有会话
 
 @warning 如果注销失败,内容将不回被清除
 */
- (void)logout;

- (void)logoutWithCallback:(callbackWithStatus)callback;

#pragma mark - Credit methods

///--------------
/// @name 积分
///--------------

/**
 从服务器获取积分
 
 @param callback 回调信息
 */
- (void)loadRewardsWithCallback:(callbackWithStatus)callback;

/**
 兑换信息
 
 @param 积分数量
 @warning 必须在回调前redeemRewards.
 */
- (void)redeemRewards:(NSInteger)count;

/**
 积分兑换
 
 @param count 积分数量.
 @param callback 回调信息
 @warning 必须在回调前redeemRewards.
 */
- (void)redeemRewards:(NSInteger)count callback:(callbackWithStatus)callback;

/**
 指定渠道兑换积分
 
 @param count 积分.
 @param bucket 赎回积分.
 @warning 必须在回调前redeemRewards.
 */
- (void)redeemRewards:(NSInteger)count forBucket:(NSString *)bucket;

/**
 指定渠道兑换积分
 
 @param count 积分.
 @param bucket 赎回积分
 @param callback 回调信息
 @warning 必须在回调前redeemRewards.
 */
- (void)redeemRewards:(NSInteger)count forBucket:(NSString *)bucket callback:(callbackWithStatus)callback;

/**
 获取信息信息
 
 @warning You must `loadRewardsWithCallback:` before calling `getCredits`. This method does not make a request for the balance.
 */
- (NSInteger)getCredits;

/**
 获取制定信用信息
 
 @param bucket 积分
 @warning You must `loadRewardsWithCallback:` before calling `getCredits`. This method does not make a request for the balance.
 */
- (NSInteger)getCreditsForBucket:(NSString *)bucket;

/**
 加载最后100条信用交易历史项目为默认项。
 
 @param callback 回调信息
 */
- (void)getCreditHistoryWithCallback:(callbackWithList)callback;

/**
 加载最后100信用交易历史项目为默认项。
 
 @param bucket The bucket to get transaction history for.
 @param callback The callback to call with the list of transactions.
 */
- (void)getCreditHistoryForBucket:(NSString *)bucket andCallback:(callbackWithList)callback;

/**
 加载最后N条历史纪录,指定默认transaction ID
 
 @param creditTransactionId ID
 @param length 交易数量
 @param order 订单交易列表.
 @param callback The callback 回调信息
 */
- (void)getCreditHistoryAfter:(NSString *)creditTransactionId number:(NSInteger)length order:(LMCreditHistoryOrder)order andCallback:(callbackWithList)callback;

/**
 加载最后N条历史纪录,指定默认transaction ID
 
 @param bucket 交易历史
 @param creditTransactionId ID
 @param length 交易数量
 @param order 订单交易列表.
 @param callback 回调信息.
 */
- (void)getCreditHistoryForBucket:(NSString *)bucket after:(NSString *)creditTransactionId number:(NSInteger)length order:(LMCreditHistoryOrder)order andCallback:(callbackWithList)callback;

#pragma mark - Action methods

///--------------
/// @name Actions
///--------------

/**
 加载当前用户操作计数
 
 @deprecated 方法已停用,更多信息查看 https://github.com/BranchMetrics/iOS-Deferred-Deep-Linking-SDK#deprecation-notice---action-counts
 
 @param callback 回调信息.
 */
- (void)loadActionCountsWithCallback:(callbackWithStatus)callback __attribute__((deprecated(("方法已停用,更多信息查看 https://github.com/BranchMetrics/iOS-Deferred-Deep-Linking-SDK#deprecation-notice---action-counts"))));

/**
 发送用户信息到服务器 `viewed_personal_welcome`, `purchased_an_item`, etc.
 
 @param action 字段
 */
- (void)userCompletedAction:(NSString *)action;

/**
 发送用户信息到服务器. 如 `viewed_personal_welcome`, `purchased_an_item`, etc.
 
 @param action 字段.
 @param state 额外信息
 */
- (void)userCompletedAction:(NSString *)action withState:(NSDictionary *)state;

/**
 获取用户行为信息
 @deprecated Method 方法已停用
 
 @param action 字段
 @warning  必须在`loadActionCountsWithCallback:`回调前调用getTotalCountsForAction `.
 */
- (NSInteger)getTotalCountsForAction:(NSString *)action __attribute__((deprecated(("方法已停用"))));

/**
 获取用户行为信息
 
 @deprecated 方法已停用
 
 @param action 字段.
 @warning  必须在`loadActionCountsWithCallback:`回调前调用`.
 */
- (NSInteger)getUniqueCountsForAction:(NSString *)action __attribute__((deprecated(("方法已停用"))));

#pragma mark - 短链接同步方法

///---------------------------------------
/// @name   同步生成短连接
///---------------------------------------

/**
 使用默认参数生成短链接
 */
- (NSString *)getShortURL;

/**
 通过参数生成短链接
 
 @param params 参数.
 @warning 这个方法使用同步请求.
 */
- (NSString *)getShortURLWithParams:(NSDictionary *)params;

/**
 通过渠道信息生成短链接,类型默认
 
 @param params 参数
 @param 渠道信息如:"短信","Wechat","Weibo".
 @param feature 功能:分享,引用,邀请等.
 @warning 这个方法使用同步请求.
 */
- (NSString *)getShortURLWithParams:(NSDictionary *)params andChannel:(NSString *)channel andFeature:(NSString *)feature;

/**
 通过参数,渠道信息,功能,阶段生成短链接
 
 @param params 参数
 @param channel 渠道.
 @param feature 功能:分享,引用,邀请等.
 @param stage 用于指示用户属于什么是时间点

 @warning 这个方法使用同步请求.
 */
- (NSString *)getShortURLWithParams:(NSDictionary *)params andChannel:(NSString *)channel andFeature:(NSString *)feature andStage:(NSString *)stage;

/**
 通过参数,渠道信息,功能,阶段生成短链接

 
 @param params 参数
 @param channel 渠道
 @param feature 功能:分享,引用,邀请等.
 @param stage 用于指示用户属于什么是时间点
 @param alias 链接别名
 @warning 这个方法使用同步请求
 @warning 使用别名可能会导致失败
 */
- (NSString *)getShortURLWithParams:(NSDictionary *)params andChannel:(NSString *)channel andFeature:(NSString *)feature andStage:(NSString *)stage andAlias:(NSString *)alias;

/**
 通过参数,渠道信息,功能,阶段生成短链接
 
 @param params 参数
 @param channel 渠道
 @param feature 功能:分享,引用,邀请等.
 @param stage 用于指示用户属于什么是时间点
 @param type 连接是永久可用还是一次性的
 @warning 这个方法是使用同步请求
 */
- (NSString *)getShortURLWithParams:(NSDictionary *)params andChannel:(NSString *)channel andFeature:(NSString *)feature andStage:(NSString *)stage andType:(LMLinkType)type;

/**
 通过参数,渠道信息,功能,有效时间,阶段生成短链接
 
 @param params 参数.
 @param channel 渠道.
 @param feature 功能:分享,引用,邀请等.
 @param stage 用于指示用户属于什么是时间点
 @param duration 链接有效时长
 @warning 这个方法是同步请求
 */
- (NSString *)getShortURLWithParams:(NSDictionary *)params andChannel:(NSString *)channel andFeature:(NSString *)feature andStage:(NSString *)stage andMatchDuration:(NSUInteger)duration;

/**
 通过参数,渠道信息,功能,标签,有效时间,阶段生成短链接
 
 @param params 参数.
 @param tags 标签.
 @param channel 渠道.
 @param feature 功能:分享,引用,邀请等.
 @param stage 用于指示用户属于什么是时间点
 @param 链接有效时长
 @warning 这个方法是同步请求
 */
- (NSString *)getShortURLWithParams:(NSDictionary *)params andTags:(NSArray *)tags andChannel:(NSString *)channel andFeature:(NSString *)feature andStage:(NSString *)stage;

/**
 通过参数,渠道信息,功能,别名,标签,有效时间,阶段生成短链接
 
 @param params 参数.
 @param tags 标签.
 @param channel 渠道.
 @param feature 功能:分享,引用,邀请等.
 @param stage 用于指示用户属于什么是时间点
 @param alias 别名
 @param 链接有效时长
 @warning 这个方法是同步请求
 */
- (NSString *)getShortURLWithParams:(NSDictionary *)params andTags:(NSArray *)tags andChannel:(NSString *)channel andFeature:(NSString *)feature andStage:(NSString *)stage andAlias:(NSString *)alias;

/**
 通过参数,渠道信息,功能,别名,标签,阶段,生成短链接
 
 @param params 参数.
 @param tags 标签.
 @param channel 渠道.
 @param feature 功能:分享,引用,邀请等.
 @param stage 用于指示用户属于什么是时间点
 @param alias 别名
 @param ignoreUAString 通过字段让服务器忽略请求
 @warning 这个方法是同步请求
 @warning 内部方法用于解决SLComposeViewController bug
 @warning 已存在别名会导致失败
 */
- (NSString *)getShortURLWithParams:(NSDictionary *)params andTags:(NSArray *)tags andChannel:(NSString *)channel andFeature:(NSString *)feature andStage:(NSString *)stage andAlias:(NSString *)alias ignoreUAString:(NSString *)ignoreUAString;

/**
 通过参数,渠道信息,功能,别名,标签,阶段,生成短链接
 
 @param params 参数.
 @param tags 标签.
 @param channel 渠道.
 @param feature 功能:分享,引用,邀请等.
 @param stage 用于指示用户属于什么是时间点
 @param alias 别名
 @param ignoreUAString 通过字段让服务器忽略请求
 @param forceLinkCreation 是否创建initSession失败链接,默认NO
 @warning 这个方法是同步请求
 @warning 内部方法用于解决SLComposeViewController bug
 @warning 已存在别名会导致失败

 */
- (NSString *)getShortURLWithParams:(NSDictionary *)params andTags:(NSArray *)tags andChannel:(NSString *)channel andFeature:(NSString *)feature andStage:(NSString *)stage andAlias:(NSString *)alias ignoreUAString:(NSString *)ignoreUAString forceLinkCreation:(BOOL)forceLinkCreation;

/**
 通过参数,渠道信息,功能,阶段和类型生成短链接
 
 @param params 参数.
 @param tags 标签.
 @param channel 渠道.
 @param feature 功能:分享,引用,邀请等.
 @param stage 用于指示用户属于什么是时间点
 @param type 连接是永久可用还是一次性的
 @warning 这个方法是同步请求.
 */
- (NSString *)getShortURLWithParams:(NSDictionary *)params andTags:(NSArray *)tags andChannel:(NSString *)channel andFeature:(NSString *)feature andStage:(NSString *)stage andType:(LMLinkType)type;

/**
 通过参数,标签,渠道信息,功能,标签有效时间,生成短链接
 
 @param params 参数.
 @param tags 标签.
 @param channel 渠道.
 @param feature 功能:分享,引用,邀请等.
 @param stage 用于指示用户属于什么是时间点
 @param duration 链接有效时长
 @warning 这个方法是同步请求.
 */
- (NSString *)getShortURLWithParams:(NSDictionary *)params andTags:(NSArray *)tags andChannel:(NSString *)channel andFeature:(NSString *)feature andStage:(NSString *)stage andMatchDuration:(NSUInteger)duration;

/**
 通过参数,标签,别名,渠道信息,功能,标签有效时间,生成短链接

 @param params 参数.
 @param tags 标签.
 @param alias 别名
 @param channel 渠道.
 @param feature 功能:分享,引用,邀请等.
 @param stage 用于指示用户属于什么是时间点
 @param duration 链接有效时长
 @warning 这个方法是同步请求.
 @warning 这个方法是同步请求
 @warning 设置别名会导致失败
 */
- (NSString *)getShortUrlWithParams:(NSDictionary *)params andTags:(NSArray *)tags andAlias:(NSString *)alias andChannel:(NSString *)channel andFeature:(NSString *)feature andStage:(NSString *)stage andMatchDuration:(NSUInteger)duration;

/**
 通过参数,渠道信息获取短连接,使用 LKME_FEATURE_TAG_SHARE
 
 @param params 参数
 @param channel 渠道
 @warning 这个方法是同步请求
 */
- (NSString *)getContentUrlWithParams:(NSDictionary *)params andChannel:(NSString *)channel;

/**
 通过参数,标签渠道信息获取短连接,使用 LKME_FEATURE_TAG_SHARE
 
 @param params 参数
 @param channel 渠道
 @param tags 标签
 @warning 这个方法是同步请求
 */
- (NSString *)getContentUrlWithParams:(NSDictionary *)params andTags:(NSArray *)tags andChannel:(NSString *)channel;

/**
 通过参数,标签渠道信息获取短连接,使用 LKME_FEATURE_TAG_SHARE
 
 @param params 参数
 @param channel 渠道
 @warning 这个方法是同步请求
 */
- (NSString *)getReferralUrlWithParams:(NSDictionary *)params andChannel:(NSString *)channel;

/**
 通过参数,标签渠道信息获取短连接,使用 LKME_FEATURE_TAG_SHARE
 
 @param params 参数
 @param tags 标签
 @param channel 渠道
 @warning 这个方法是同步请求
 */
- (NSString *)getReferralUrlWithParams:(NSDictionary *)params andTags:(NSArray *)tags andChannel:(NSString *)channel;

#pragma mark - Long Url generation

///--------------------------
/// @name 生成长链接
///--------------------------

/**
 通过参数创建长链接
 
 @param params 参数.
 */
- (NSString *)getLongURLWithParams:(NSDictionary *)params;

/**
 通过参数和功能创建长链接
 
 @param params 参数.
 @param feature 功能:分享,引用,邀请等.
 */
- (NSString *)getLongURLWithParams:(NSDictionary *)params andFeature:(NSString *)feature;

/**
 通过参数,阶段,和功能创建长链接
 
 @param params 参数.
 @param feature 功能:分享,引用,邀请等.
 @param stage 用于指示用户属于什么是时间点
 */
- (NSString *)getLongURLWithParams:(NSDictionary *)params andFeature:(NSString *)feature andStage:(NSString *)stage;

/**
 通过参数,阶段,标签和功能创建长链接
 
 @param params 参数.
 @param feature 功能:分享,引用,邀请等.
 @param stage 用于指示用户属于什么是时间点
 @param tags 标签.
 */
- (NSString *)getLongURLWithParams:(NSDictionary *)params andFeature:(NSString *)feature andStage:(NSString *)stage andTags:(NSArray *)tags;

/**
 通过参数,阶段,时间点和别名创建长链接
 
 @param params 参数.
 @param feature 功能:分享,引用,邀请等.
 @param stage 用于指示用户属于什么是时间点
 @param alias 别名.
 @warning 设置别名可能会失败.
 */
- (NSString *)getLongURLWithParams:(NSDictionary *)params andFeature:(NSString *)feature andStage:(NSString *)stage andAlias:(NSString *)alias;

/**
 通过参数,渠道,阶段,时间点,标签和别名创建长链接
 
 @param params 参数.
 @param feature 功能:分享,引用,邀请等.
 @param tags 标签.
 @param stage 用于指示用户属于什么是时间点
 @param alias 别名.
 @warning 设置别名可能会失败.
 
 */
- (NSString *)getLongURLWithParams:(NSDictionary *)params andChannel:(NSString *)channel andTags:(NSArray *)tags andFeature:(NSString *)feature andStage:(NSString *)stage andAlias:(NSString *)alias;

#pragma mark - Short Url Async methods

///----------------------------------------
/// @name 异步生成短链接
///----------------------------------------

/**
 通过默认参数获取短连接
 
 @param callback 回调url
 */
- (void)getShortURLWithCallback:(callbackWithUrl)callback;

/**
 通过参数获取短连接
 
 @param params 参数.
 @param callback 回调url
 */
- (void)getShortURLWithParams:(NSDictionary *)params andCallback:(callbackWithUrl)callback;

/**
 通过参数,渠道和功能获取短连接
 
 @param params 参数
 @param channel 渠道.
 @param feature 功能:分享,引用,邀请等.
 @param callback 回调url.
 */
- (void)getShortURLWithParams:(NSDictionary *)params andChannel:(NSString *)channel andFeature:(NSString *)feature andCallback:(callbackWithUrl)callback;

/**
 通过参数,功能,渠道,时间点和功能获取短连接
 
 @param params 参数
 @param channel 渠道.
 @param feature 功能:分享,引用,邀请等.
 @param stage 用于指示用户属于什么是时间点

 @param callback 回掉url.
 */
- (void)getShortURLWithParams:(NSDictionary *)params andChannel:(NSString *)channel andFeature:(NSString *)feature andStage:(NSString *)stage andCallback:(callbackWithUrl)callback;

/**
 通过参数,渠道,功能,别名,时间点和功能获取短连接
 
 @param params 参数
 @param channel 渠道.
 @param feature 功能:分享,引用,邀请等.
 @param stage 用于指示用户属于什么是时间点
 @param alias 别名.
 @param callback 回掉url.
 @warning 使用别名可能会导致失败.
 */
- (void)getShortURLWithParams:(NSDictionary *)params andChannel:(NSString *)channel andFeature:(NSString *)feature andStage:(NSString *)stage andAlias:(NSString *)alias andCallback:(callbackWithUrl)callback;

/**
 通过参数,渠道,功能,类型,时间点和功能获取短连接
 
 @param params 参数
 @param channel 渠道.
 @param feature 功能:分享,引用,邀请等.
 @param stage 用于指示用户属于什么是时间点
 @param type 连接是永久可用还是一次性的
 @param callback 回掉url.
 @warning 使用别名可能会导致失败.
 */
- (void)getShortURLWithParams:(NSDictionary *)params andChannel:(NSString *)channel andFeature:(NSString *)feature andStage:(NSString *)stage andType:(LMLinkType)type andCallback:(callbackWithUrl)callback;

/**
 通过参数,渠道信息,功能,有效时间,阶段生成短链接
 
 @param params 参数.
 @param channel 渠道.
 @param feature 功能:分享,引用,邀请等.
 @param stage 用于指示用户属于什么是时间点.
 @param matchDuration 链接有效时长.
 @param callback 回掉url.
 */
- (void)getShortURLWithParams:(NSDictionary *)params andChannel:(NSString *)channel andFeature:(NSString *)feature andStage:(NSString *)stage andMatchDuration:(NSUInteger)duration andCallback:(callbackWithUrl)callback;

/**
 通过参数,标签,渠道信息,功能,阶段,生成短链接
 
 @param params 参数.
 @param tags 标签.
 @param channel 渠道.
 @param feature 功能:分享,引用,邀请等.
 @param stage 用于指示用户属于什么是时间点
 @param callback 回掉url.
 */
- (void)getShortURLWithParams:(NSDictionary *)params andTags:(NSArray *)tags andChannel:(NSString *)channel andFeature:(NSString *)feature andStage:(NSString *)stage andCallback:(callbackWithUrl)callback;

/**
 通过参数,标签,渠道信息,别名,功能,阶段,生成短链接
 
 @param params 参数.
 @param channel 渠道.
 @param tags 标签.
 @param feature 功能:分享,引用,邀请等.
 @param stage 用于指示用户属于什么是时间点
 @param alias 别名.
 @param callback 回掉url.
 @warning 使用别名可能会导致失败.
 */
- (void)getShortURLWithParams:(NSDictionary *)params andTags:(NSArray *)tags andChannel:(NSString *)channel andFeature:(NSString *)feature andStage:(NSString *)stage andAlias:(NSString *)alias andCallback:(callbackWithUrl)callback;

/**
 通过参数,标签,渠道信息,功能,类型,生成短链接
 
 @param params 参数
 @param channel 渠道.
 @param tags 标签.
 @param feature 功能:分享,引用,邀请等.
 @param stage 用于指示用户属于什么是时间点
 @param type 连接是永久可用还是一次性的
 @param callback 回调url.
 */
- (void)getShortURLWithParams:(NSDictionary *)params andTags:(NSArray *)tags andChannel:(NSString *)channel andFeature:(NSString *)feature andStage:(NSString *)stage andType:(LMLinkType)type andCallback:(callbackWithUrl)callback;

/**
 通过参数,标签,渠道信息,功能,连接有效时长,生成短链接
 
 @param params 参数.
 @param channel 渠道.
 @param tags 标签.
 @param feature 功能:分享,引用,邀请等.
 @param stage 用于指示用户属于什么是时间点
 @param matchDuration 链接有效时长.
 @param callback 回掉url.
 */
- (void)getShortURLWithParams:(NSDictionary *)params andTags:(NSArray *)tags andChannel:(NSString *)channel andFeature:(NSString *)feature andStage:(NSString *)stage andMatchDuration:(NSUInteger)duration andCallback:(callbackWithUrl)callback;

/**
 通过参数,标签,渠道信息,功能,时间点,连接有效时长,生成短链接
 
 @param params 参数
 @param channel 渠道.
 @param tags 标签.
 @param feature 功能:分享,引用,邀请等.
 @param stage 用于指示用户属于什么是时间点
 @param matchDuration 链接有效时长.
 @param callback 回调 url.
 @param alias 别名.
 @warning 使用别名可能会导致失败.
 */
- (void)getShortUrlWithParams:(NSDictionary *)params andTags:(NSArray *)tags andAlias:(NSString *)alias andMatchDuration:(NSUInteger)duration andChannel:(NSString *)channel andFeature:(NSString *)feature andStage:(NSString *)stage andCallback:(callbackWithUrl)callback;

/**
 通过参数,渠道,生成短连接`LKME_FEATURE_TAG_SHARE`.
 
 @param params 参数.
 @param channel 渠道.
 @param callback 回掉url.
 */
- (void)getContentUrlWithParams:(NSDictionary *)params andChannel:(NSString *)channel andCallback:(callbackWithUrl)callback;

/**
 通过参数,渠道,标签,生成短连接``LKME_FEATURE_TAG_SHARE`.
 
 @param params 参数.
 @param tags 标签.
 @param channel 渠道.
 @param callback 回调url.
 */
- (void)getContentUrlWithParams:(NSDictionary *)params andTags:(NSArray *)tags andChannel:(NSString *)channel andCallback:(callbackWithUrl)callback;

/**
 通过参数,渠道,生成短连接``LKME_FEATURE_TAG_SHARE`.
 
 @param params 参数.
 @param channel 渠道.
 @param callback 回掉url.
 */
- (void)getReferralUrlWithParams:(NSDictionary *)params andChannel:(NSString *)channel andCallback:(callbackWithUrl)callback;

/**
 通过参数,渠道,标签,生成短连接``LKME_FEATURE_TAG_SHARE`.
 
 @param params 参数.
 @param tags 标签.
 @param channel 渠道.
 @param callback 回调url.
 */
- (void)getReferralUrlWithParams:(NSDictionary *)params andTags:(NSArray *)tags andChannel:(NSString *)channel andCallback:(callbackWithUrl)callback;

- (void)getSpotlightUrlWithParams:(NSDictionary *)params callback:(callbackWithParams)callback;

#pragma mark - Content Discovery methods

///--------------------------------
/// @name Content Discovery methods
///--------------------------------

/**
 分享当前页面,默认不公开.
 
 @param title 别提.
 @param description 描述.
 @warning 仅支持iOS 9以上.
 */
- (void)createDiscoverableContentWithTitle:(NSString *)title description:(NSString *)description;

/**
 分享当前页面,默认不公开.
 
 @param title 标题.
 @param description 描述.
 @param callback 回掉信息.
 @warning 仅支持iOS 9以上.
 */
- (void)createDiscoverableContentWithTitle:(NSString *)title description:(NSString *)description callback:(callbackWithUrl)callback;

/**
 分享当前页面,默认为kUTTypeImage类型.
 
 @param title 标题.
 @param description 描述.
 @param publiclyIndexable 添加到公共搜索索引
 @param callback 回掉信息
 @warning 仅支持iOS 9以上.
 */
- (void)createDiscoverableContentWithTitle:(NSString *)title description:(NSString *)description publiclyIndexable:(BOOL)publiclyIndexable callback:(callbackWithUrl)callback;

/**
 将当前信息添加到Spotlight中,使用MobileCoreServices框架
 
 @param title 标题.
 @param description 描述.
 @param type NSUserActivity类型,获取MobileCoreServices框架中的列表.
 @param publiclyIndexable 添加到Spotlight索引
 @param callback 回调信息.
 @warning 仅支持iOS 9以上.
 */

- (void)createDiscoverableContentWithTitle:(NSString *)title description:(NSString *)description type:(NSString *)type publiclyIndexable:(BOOL)publiclyIndexable callback:(callbackWithUrl)callback;

/**
 将当前信息添加到Spotlight中,使用MobileCoreServices框架
 
 @param title 标题
 @param description 描述.
 @param thumbnailUrl spotlight thumnbail 图片url.
 @param type NSUserActivity类型,获取MobileCoreServices框架中的列表.
 @param publiclyIndexable 添加到Spotlight索引
 @param callback 回调信息.
 @warning 仅支持iOS 9以上.
 */

- (void)createDiscoverableContentWithTitle:(NSString *)title description:(NSString *)description thumbnailUrl:(NSURL *)thumbnailUrl type:(NSString *)type publiclyIndexable:(BOOL)publiclyIndexable callback:(callbackWithUrl)callback;

/**
 将当前信息添加到Spotlight中,使用MobileCoreServices框架
 
 @param title 标题.
 @param description 描述.
 @param publiclyIndexable 添加到Spotlight索引
 @param thumbnailUrl spotlight thumnbail 图片url.
 @param type NSUserActivity类型,获取MobileCoreServices框架中的列表.
 @param keywords 一组关键字用于搜索索引.
 @param callback 回掉信息.
 @warning 仅支持iOS 9以上.
 */

- (void)createDiscoverableContentWithTitle:(NSString *)title description:(NSString *)description thumbnailUrl:(NSURL *)thumbnailUrl type:(NSString *)type publiclyIndexable:(BOOL)publiclyIndexable keywords:(NSSet *)keywords callback:(callbackWithUrl)callback;

/**
 Take the current screen and make it discoverable, adding it to Apple's Core Spotlight index. Will be public if specified. You can override the type as desired, using one of the types provided in MobileCoreServices.
 
 @param title Title for the spotlight preview item.
 @param description Description for the spotlight preview item.
 @param thumbnailUrl Url to an image to be used for the thumnbail in spotlight.
 @param linkParams Additional params to be added to the NSUserActivity. These will also be added to the LKME link.
 @param publiclyIndexable Whether or not this item should be added to Apple's public search index.
 @param keywords A set of keywords to be used in Apple's search index.
 @warning These functions are only usable on iOS 9 or above. Earlier versions will simply receive the callback with an error.
 */
- (void)createDiscoverableContentWithTitle:(NSString *)title description:(NSString *)description thumbnailUrl:(NSURL *)thumbnailUrl linkParams:(NSDictionary *)linkParams publiclyIndexable:(BOOL)publiclyIndexable keywords:(NSSet *)keywords;

/**
 Take the current screen and make it discoverable, adding it to Apple's Core Spotlight index. Will be public if specified. You can override the type as desired, using one of the types provided in MobileCoreServices.
 
 @param title Title for the spotlight preview item.
 @param description Description for the spotlight preview item.
 @param thumbnailUrl Url to an image to be used for the thumnbail in spotlight.
 @param linkParams Additional params to be added to the NSUserActivity. These will also be added to the LKME link.
 @param type The type to use for the NSUserActivity, taken from the list of constants provided in the MobileCoreServices framework.
 @param publiclyIndexable Whether or not this item should be added to Apple's public search index.
 @param keywords A set of keywords to be used in Apple's search index.
 @warning These functions are only usable on iOS 9 or above. Earlier versions will simply receive the callback with an error.
 */
- (void)createDiscoverableContentWithTitle:(NSString *)title description:(NSString *)description thumbnailUrl:(NSURL *)thumbnailUrl linkParams:(NSDictionary *)linkParams type:(NSString *)type publiclyIndexable:(BOOL)publiclyIndexable keywords:(NSSet *)keywords;

/**
 Take the current screen and make it discoverable, adding it to Apple's Core Spotlight index. Will be public if specified. You can override the type as desired, using one of the types provided in MobileCoreServices.
 
 @param title Title for the spotlight preview item.
 @param description Description for the spotlight preview item.
 @param thumbnailUrl Url to an image to be used for the thumnbail in spotlight.
 @param type The type to use for the NSUserActivity, taken from the list of constants provided in the MobileCoreServices framework.
 @param publiclyIndexable Whether or not this item should be added to Apple's public search index.
 @param keywords A set of keywords to be used in Apple's search index.
 @warning These functions are only usable on iOS 9 or above. Earlier versions will simply receive the callback with an error.
 */
- (void)createDiscoverableContentWithTitle:(NSString *)title description:(NSString *)description thumbnailUrl:(NSURL *)thumbnailUrl type:(NSString *)type publiclyIndexable:(BOOL)publiclyIndexable keywords:(NSSet *)keywords;

/**
 Take the current screen and make it discoverable, adding it to Apple's Core Spotlight index. Will be public if specified. You can override the type as desired, using one of the types provided in MobileCoreServices.
 
 @param title Title for the spotlight preview item.
 @param description Description for the spotlight preview item.
 @param thumbnailUrl Url to an image to be used for the thumnbail in spotlight.
 @param type The type to use for the NSUserActivity, taken from the list of constants provided in the MobileCoreServices framework.
 @param publiclyIndexable Whether or not this item should be added to Apple's public search index.
 @param keywords A set of keywords to be used in Apple's search index.
 @warning These functions are only usable on iOS 9 or above. Earlier versions will simply receive the callback with an error.
 */
- (void)createDiscoverableContentWithTitle:(NSString *)title description:(NSString *)description thumbnailUrl:(NSURL *)thumbnailUrl linkParams:(NSDictionary *)linkParams publiclyIndexable:(BOOL)publiclyIndexable;

/**
 Take the current screen and make it discoverable, adding it to Apple's Core Spotlight index. Will be public if specified. You can override the type as desired, using one of the types provided in MobileCoreServices.
 
 @param title Title for the spotlight preview item.
 @param description Description for the spotlight preview item.
 @param thumbnailUrl Url to an image to be used for the thumnbail in spotlight.
 @param linkParams Additional params to be added to the NSUserActivity. These will also be added to the LKME link.
 @param publiclyIndexable Whether or not this item should be added to Apple's public search index.
 @param type The type to use for the NSUserActivity, taken from the list of constants provided in the MobileCoreServices framework.
 @param keywords A set of keywords to be used in Apple's search index.
 @param callback Callback called with the LKME url this will fallback to.
 @warning These functions are only usable on iOS 9 or above. Earlier versions will simply receive the callback with an error.
 */

- (void)createDiscoverableContentWithTitle:(NSString *)title description:(NSString *)description thumbnailUrl:(NSURL *)thumbnailUrl linkParams:(NSDictionary *)linkParams type:(NSString *)type publiclyIndexable:(BOOL)publiclyIndexable keywords:(NSSet *)keywords callback:(callbackWithUrl)callback;
/**
 Take the current screen and make it discoverable, adding it to Apple's Core Spotlight index. Will be public if specified. You can override the type as desired, using one of the types provided in MobileCoreServices.
 
 @param title Title for the spotlight preview item.
 @param description Description for the spotlight preview item.
 @param thumbnailUrl Url to an image to be used for the thumnbail in spotlight.
 @param linkParams Additional params to be added to the NSUserActivity. These will also be added to the LKME link.
 @param publiclyIndexable Whether or not this item should be added to Apple's public search index.
 @param type The type to use for the NSUserActivity, taken from the list of constants provided in the MobileCoreServices framework.
 @param keywords A set of keywords to be used in Apple's search index.
 @param expirationDate ExpirationDate after which this will not appear in Apple's search index.
 @param callback Callback called with the LKME url this will fallback to.
 @warning These functions are only usable on iOS 9 or above. Earlier versions will simply receive the callback with an error.
 */
- (void)createDiscoverableContentWithTitle:(NSString *)title description:(NSString *)description thumbnailUrl:(NSURL *)thumbnailUrl linkParams:(NSDictionary *)linkParams type:(NSString *)type publiclyIndexable:(BOOL)publiclyIndexable keywords:(NSSet *)keywords expirationDate:(NSDate *)expirationDate callback:(callbackWithUrl)callback;

/**
 Take the current screen and make it discoverable, adding it to Apple's Core Spotlight index. Will be public if specified. You can override the type as desired, using one of the types provided in MobileCoreServices.
 
 @param title Title for the spotlight preview item.
 @param description Description for the spotlight preview item.
 @param thumbnailUrl Url to an image to be used for the thumnbail in spotlight.
 @param linkParams Additional params to be added to the NSUserActivity. These will also be added to the LKME link.
 @param publiclyIndexable Whether or not this item should be added to Apple's public search index.
 @param type The type to use for the NSUserActivity, taken from the list of constants provided in the MobileCoreServices framework.
 @param keywords A set of keywords to be used in Apple's search index.
 @param expirationDate ExpirationDate after which this will not appear in Apple's search index.
 @param callback Callback called with the LKME url this will fallback to.
 @warning These functions are only usable on iOS 9 or above. Earlier versions will simply receive the callback with an error.
 */
- (void)createDiscoverableContentWithTitle:(NSString *)title description:(NSString *)description thumbnailUrl:(NSURL *)thumbnailUrl linkParams:(NSDictionary *)linkParams type:(NSString *)type publiclyIndexable:(BOOL)publiclyIndexable keywords:(NSSet *)keywords expirationDate:(NSDate *)expirationDate spotlightCallback:(callbackWithUrlAndSpotlightIdentifier)spotlightCallback;

#pragma mark - Referral Code methods

///-------------------------
/// @name Promo Code methods
///-------------------------


/**
 Get a promo code without providing any parameters.
 
 @param callback The callback that is called with the created referral code object.
 */
- (void)getPromoCodeWithCallback:(callbackWithParams)callback __attribute__((deprecated(("This method has been deprecated. LinkedME will no longer provide improvements or modifications to referral/promo code functionality."))));
- (void)getReferralCodeWithCallback:(callbackWithParams)callback __attribute__((deprecated(("This method has been deprecated. LinkedME will no longer provide improvements or modifications to referral/promo code functionality."))));

/**
 Get a promo code with an amount of credits the code will be worth.
 
 @param amount Number of credits generating user will earn when a user is referred by this code.
 @param callback The callback that is called with the created referral code object.
 */
- (void)getPromoCodeWithAmount:(NSInteger)amount callback:(callbackWithParams)callback __attribute__((deprecated(("This method has been deprecated. LinkedME will no longer provide any improvements or modifications to referral/promo code functionality."))));
- (void)getReferralCodeWithAmount:(NSInteger)amount andCallback:(callbackWithParams)callback  __attribute__((deprecated(("This method has been deprecated. LinkedME will no longer provide any improvements or modifications to referral/promo code functionality."))));

/**
 Get a promo code with an amount of credits the code will be worth, and a prefix for the code.
 
 @param prefix The string to prefix the code with.
 @param amount Number of credits generating user will earn when a user is referred by this code.
 @param callback The callback that is called with the created referral code object.
 */
- (void)getPromoCodeWithPrefix:(NSString *)prefix amount:(NSInteger)amount callback:(callbackWithParams)callback __attribute__((deprecated(("This method has been deprecated. LinkedME will no longer provide any improvements or modifications to referral/promo code functionality."))));
- (void)getReferralCodeWithPrefix:(NSString *)prefix amount:(NSInteger)amount andCallback:(callbackWithParams)callback  __attribute__((deprecated(("This method has been deprecated. LinkedME will no longer provide any improvements or modifications to referral/promo code functionality."))));

/**
 Get a promo code with an amount of credits the code will be worth, and an expiration date.
 
 @param amount Number of credits generating user will earn when a user is referred by this code.
 @param expiration The date when the code should be invalidated.
 @param callback The callback that is called with the created referral code object.
 */
- (void)getPromoCodeWithAmount:(NSInteger)amount expiration:(NSDate *)expiration callback:(callbackWithParams)callback __attribute__((deprecated(("This method has been deprecated. LinkedME will no longer provide any improvements or modifications to referral/promo code functionality."))));
- (void)getReferralCodeWithAmount:(NSInteger)amount expiration:(NSDate *)expiration andCallback:(callbackWithParams)callback  __attribute__((deprecated(("This method has been deprecated. LinkedME will no longer provide any improvements or modifications to referral/promo code functionality."))));

/**
 Get a promo code with an amount of credits the code will be worth, the prefix to put in front of it, and an expiration date.
 
 @param prefix The string to prefix the code with.
 @param amount Number of credits generating user will earn when a user is referred by this code.
 @param expiration The date when the code should be invalidated.
 @param callback The callback that is called with the created referral code object.
 */
- (void)getPromoCodeWithPrefix:(NSString *)prefix amount:(NSInteger)amount expiration:(NSDate *)expiration callback:(callbackWithParams)callback __attribute__((deprecated(("This method has been deprecated. LinkedME will no longer provide any improvements or modifications to referral/promo code functionality."))));
- (void)getReferralCodeWithPrefix:(NSString *)prefix amount:(NSInteger)amount expiration:(NSDate *)expiration andCallback:(callbackWithParams)callback __attribute__((deprecated(("This method has been deprecated. LinkedME will no longer provide any improvements or modifications to referral/promo code functionality."))));

/**
 Get a promo code with an amount of credits the code will be worth, the prefix to put in front of it, an expiration date, the bucket it will be part of, the calculation method, and location of user earning credits.
 
 @param prefix The string to prefix the code with.
 @param amount Number of credits to be earned (by the user specified by location).
 @param expiration The date when the code should be invalidated.
 @param bucket A bucket the credits should be associated with.
 @param type The type of this code will be, one of Single Use or Unlimited Use. Single use means once *per user*, not once period.
 @param location The location of the user who earns credits for the referral, one of Referrer, Referree (the referred user), or Both.
 @param callback The callback that is called with the created referral code object.
 */
- (void)getPromoCodeWithPrefix:(NSString *)prefix amount:(NSInteger)amount expiration:(NSDate *)expiration bucket:(NSString *)bucket usageType:(LMPromoCodeUsageType)usageType rewardLocation:(LMPromoCodeRewardLocation)rewardLocation callback:(callbackWithParams)callback __attribute__((deprecated(("This method has been deprecated. LinkedME will no longer provide any improvements or modifications to referral/promo code functionality."))));
- (void)getReferralCodeWithPrefix:(NSString *)prefix amount:(NSInteger)amount expiration:(NSDate *)expiration bucket:(NSString *)bucket calculationType:(LMPromoCodeUsageType)calcType location:(LMPromoCodeRewardLocation)location andCallback:(callbackWithParams)callback  __attribute__((deprecated(("This method has been deprecated. LinkedME will no longer provide any improvements or modifications to referral/promo code functionality."))));

/**
 Validate a promo code. Will callback with the referral code object on success, or an error if it's invalid.
 
 @param code The referral code to validate
 @param callback The callback that is called with the referral code object on success, or an error if it's invalid.
 */
- (void)validatePromoCode:(NSString *)code callback:(callbackWithParams)callback __attribute__((deprecated(("This method has been deprecated. LinkedME will no longer provide any improvements or modifications to referral/promo code functionality."))));
- (void)validateReferralCode:(NSString *)code andCallback:(callbackWithParams)callback  __attribute__((deprecated(("This method has been deprecated. LinkedME will no longer provide any improvements or modifications to referral/promo code functionality."))));

/**
 Apply a promo code, awarding the referral points. Will callback with the referral code object on success, or an error if it's invalid.
 
 @param code The referral code to validate
 @param callback The callback that is called with the referral code object on success, or an error if it's invalid.
 */
- (void)applyPromoCode:(NSString *)code callback:(callbackWithParams)callback __attribute__((deprecated(("This method has been deprecated. LinkedME will no longer provide any improvements or modifications to referral/promo code functionality."))));
- (void)applyReferralCode:(NSString *)code andCallback:(callbackWithParams)callback  __attribute__((deprecated(("This method has been deprecated. LinkedME will no longer provide any improvements or modifications to referral/promo code functionality."))));

/**
 Method for creating a one of LKME instance and specifying its dependencies.
 
 @warning This is meant for use internally only (exposed for the sake of testing) and should not be used by apps.
 */
- (id)initWithInterface:(LMServerInterface *)interface queue:(LMServerRequestQueue *)queue cache:(LMLinkCache *)cache preferenceHelper:(LMPreferenceHelper *)preferenceHelper key:(NSString *)key;

/**
 Method used by LKMEUniversalObject to register a view on content
 
 @warning This is meant for use internally only and should not be used by apps.
 */
- (void)registerViewWithParams:(NSDictionary *)params andCallback:(callbackWithParams)callback;

/**
 Method used by external LKME libs to initiate server requests
 */
- (void)executeGenericRequest:(LMServerRequest*)request;

- (void)getButton:(LMContext *)context andButtonId:(NSString *)buttonId
       completion:(CompletionHandler)completionHandler andInnerCallBack:(innerCallBack) innerCallBack;


/**
 页面跳转方式-presentView（纯代码实现ViewController）
 
 @param vc 需要跳转的ViewController的类名（必选完全一致）
 @param flag 是否有动画效果.
 @param arr 自定义参数
 @param completion 完成回调
 */
+ (void)presentViewController:(NSString *)vc animated: (BOOL)flag customValue:(NSDictionary *)dict completion:(void (^)(void))completion NS_AVAILABLE_IOS(5_0);

/**
 页面跳转方式-presentView(storyBoard实现ViewController)
 
 @param vc 需要跳转的ViewController的类名（必选完全一致）
 @param flag 是否有动画效果.
 @param storyBoardID storyBoardID
 @param arr 自定义参数
 @param completion 完成回调
 */
+ (void)presentViewController:(NSString *)vc storyBoardID:(NSString *)identifier animated: (BOOL)flag customValue:(NSDictionary *)dict completion:(void (^)(void))completion NS_AVAILABLE_IOS(5_0);

/**
 页面跳转方式-push（纯代码实现ViewController）
 
 @param vc 需要跳转的ViewController的类名（必选完全一致）
 @param flag 是否有动画效果.
 @param arr 自定义参数
 @param completion 完成回调
 */
+ (void)pushViewController:(NSString *)vc animated: (BOOL)flag customValue:(NSDictionary *)dict completion:(void (^)(void))completion NS_AVAILABLE_IOS(5_0);

/**
 页面跳转方式-push(storyBoard实现ViewController)
 
 @param vc 需要跳转的ViewController的类名（必选完全一致）
 @param flag 是否有动画效果.
 @param storyBoardID storyBoardID
 @param arr 自定义参数
 @param completion 完成回调
 */
+ (void)pushViewController:(NSString *)vc storyBoardID:(NSString *)identifier animated: (BOOL)flag customValue:(NSDictionary *)dict completion:(void (^)(void))completion NS_AVAILABLE_IOS(5_0);

+(UIViewController *)getViewController;

@end
