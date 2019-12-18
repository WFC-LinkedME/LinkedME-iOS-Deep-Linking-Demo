//
//  LM_SDK.h
//  iOS-Deep-Linking-SDK
//
//  Created on 6/5/14.
//  Copyright (c) 2014 Bindx. All rights reserved.
//  version 1.5.0.4

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "LMServerInterface.h"
#import "LMLinkCache.h"
#import "LMDeepLinkingController.h"

@class LMUniversalObject;
@class LMLinkProperties;

typedef void (^callbackWithParams) (NSDictionary *params, NSError *error);
typedef void (^callbackWithUrl) (NSString *url, NSError *error);
typedef void (^callbackWithStatus) (BOOL changed, NSError *error);
typedef void (^callbackWithList) (NSArray *list, NSError *error);
typedef void (^callbackWithAdInfo) (BOOL status, NSDictionary *dict,NSError *error);
typedef void (^callbackWithUrlAndSpotlightIdentifier) (NSString *url, NSString *spotlightIdentifier, NSError *error);
typedef void (^callbackWithLinkedMEUniversalObject) (LMUniversalObject *universalObject, LMLinkProperties *linkProperties, NSError *error);
///----------------
/// @name   常量
///----------------

#pragma mark - LM Link Features

/**
 ## LinkedME 链接功能
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

@interface LinkedME : NSObject

#pragma mark - Global Instance Accessors

//--------------------------------
// @name 全局实例访问器
//--------------------------------

/**
 线上版
 */
+ (LinkedME *)getInstance;

/*
 获取LinkedME实例，配置LinkedMEKey
 @pparam 必要参数
 @warning 不建议c使用此方法j，建议在Info.plist中配置
 */
+ (LinkedME *)getInstance:(NSString *)linkedMeKey;

#pragma mark - 初始化方法

//---------------------
// @name 初始化
//---------------------

/*
 初始化LinkedME会话和应用程序启动选项。
 @param AppDelegate提供的启动选项的“didFinishLaunchingWithOptions:”方法中实现。
 @warning 不推荐使用此方法初始化LinkedME. 可以正常启动但没有回调信息
 */
- (void)initSessionWithLaunchOptions:(NSDictionary *)options;

/*
 初始化LinkedME会话和应用程序启动选项
 
 @param 在AppDelegate提供的启动选项的“didFinishLaunchingWithOptions:”方法中实现。
 @param 是否允许会话标记为参考,覆盖默认行为。
 @warning 不推荐使用此方法初始化LinkedME. 可以正常启动但没有回调信息
 */
- (void)initSessionWithLaunchOptions:(NSDictionary *)options isReferrable:(BOOL)isReferrable;

/*
 初始化LinkedME提供Block回调处理RegisterDeepLinkHandler
 
 @param 选项在AppDelegate提供的启动选项的“didFinishLaunchingWithOptions:”方法中实现
 @param callback 打开App时回调,包含后台进入前台.
 */
- (void)initSessionWithLaunchOptions:(NSDictionary *)options andRegisterDeepLinkHandler:(callbackWithParams)callback;

/*
 初始化LinkedME提供Block回调处理
 
 @param 选项在AppDelegate提供的启动选项的“didFinishLaunchingWithOptions:”方法中实现
 @param callback 打开App时回调,包含后台进入前台.
 */
- (void)initSessionWithLaunchOptions:(NSDictionary *)options pres:(callbackWithLinkedMEUniversalObject)callback;

/*
 初始化LinkedME提供Block回调处理
 
 @param 选项在AppDelegate提供的启动选项的“didFinishLaunchingWithOptions:”方法中实现
 @param automaticallyDisplayController 是否自动打开DeepLink连接
 */
- (void)initSessionWithLaunchOptions:(NSDictionary *)options automaticallyDisplayDeepLinkController:(BOOL)automaticallyDisplayController;

/*
 初始化LinkedME提供Block回调处理
 
 @param 选项在AppDelegate提供的启动选项的“didFinishLaunchingWithOptions:”方法中实现
 @param 是否允许会话标记为参考,覆盖默认行为。
 @param callback 打开App时回调,包含后台进入前台.
 */
- (void)initSessionWithLaunchOptions:(NSDictionary *)options isReferrable:(BOOL)isReferrable andRegisterDeepLinkHandler:(callbackWithParams)callback;

/*
 初始化LinkedME提供Block回调处理
 
 @param 选项在AppDelegate提供的启动选项的“didFinishLaunchingWithOptions:”方法中实现
 @param 是否允许会话标记为参考,覆盖默认行为。
 @param automaticallyDisplayController 是否自动打开DeepLink连接
 */
- (void)initSessionWithLaunchOptions:(NSDictionary *)options isReferrable:(BOOL)isReferrable automaticallyDisplayDeepLinkController:(BOOL)automaticallyDisplayController;

/*
 初始化LinkedME提供Block回调处理
 
 @param 选项在AppDelegate提供的启动选项的“didFinishLaunchingWithOptions:”方法中实现
 @param automaticallyDisplayController 是否自动打开DeepLink连接
 @param callback 打开App时回调,包含后台进入前台.
 */
- (void)initSessionWithLaunchOptions:(NSDictionary *)options automaticallyDisplayDeepLinkController:(BOOL)automaticallyDisplayController deepLinkHandler:(callbackWithParams)callback;

/*
 初始化LinkedME提供Block回调处理
 
 @param 选项在AppDelegate提供的启动选项的“didFinishLaunchingWithOptions:”方法中实现
 @param automaticallyDisplayController 是否自动打开DeepLink连接
 @param 是否允许会话标记为参考,覆盖默认行为。
 @param callback 打开App时回调,包含后台进入前台.
 */
- (void)initSessionWithLaunchOptions:(NSDictionary *)options automaticallyDisplayDeepLinkController:(BOOL)automaticallyDisplayController isReferrable:(BOOL)isReferrable deepLinkHandler:(callbackWithParams)callback;

/*
 允许LinkedME处理链接打开应用程序,打开后是否返回。
 
 @param url 使用url打开应用.
 */
- (BOOL)handleDeepLink:(NSURL *)url;
    
- (BOOL)handleSchemeLink:(NSURL *)url;

/*
 允许从NSUserActivity处理连接,是否返回。
 
 @param userActivity 打开应用.
 */
- (BOOL)continueUserActivity:(NSUserActivity *)userActivity API_AVAILABLE(ios(8.0));

///--------------------------------
/// @name 推送通知支持
///--------------------------------

#pragma mark - Push Notification support

/*
 允许从通知中心打开
 在创建推送式通知时,指定关键的NSString LKME链接,@“LinkedME”
 NSDictionary userInfo = @{@"linkedme": @"https://lkme.cc/...", ... };
 */
- (void)handlePushNotification:(NSDictionary *)userInfo;

#pragma mark - Deep Link Controller methods

///---------------------------
/// @name Deep Link 控制器
///---------------------------

//注册深度链接控制器`
- (void)registerDeepLinkController:(UIViewController <LMDeepLinkingController> *)controller forKey:(NSString *)key;

#pragma mark - Configuration methods

///--------------------
/// @name 配置
///--------------------

/*
 Debug模式,记录反馈更多信息
 
 @warning 不适用于production!!
 */
- (void)setDebug;

- (void)getSafariCookice:(BOOL)status;

+ (NSString *)getTestID;

- (void)disableMatching;

/*
 增加指定其他常数的参数
 
 @param debugParams dictionary of keystrings/valuestrings that will be added to response
 */
-(void) setDeepLinkDebugMode:(NSDictionary *)debugParams;


/*
 设置时间（秒）尝试重连LinkedME服务器
 
 @param retryInterval 秒.
 */
- (void)setRetryInterval:(NSTimeInterval)retryInterval;

/*
 设置最大重试次数
 
 @param maxRetries 重试次数
 */
- (void)setMaxRetries:(NSInteger)maxRetries;

/*
 请求超时设置(秒)
 
 @param timeout 秒
 */
- (void)setNetworkTimeout:(NSTimeInterval)timeout;

/*
 使用SFSafariViewController尝试cookie匹配。默认情况启用。
 
 @warning Please import SafariServices in order for this to work.
 */
- (void)disableCookieBasedMatching;

#pragma mark - Session Item methods

///--------------------
/// @name Session Items
///--------------------

/*
 Get the LKMEUniversalObject from the first time this user was referred (can be empty).
 */
- (LMUniversalObject *)getFirstReferringLinkedMEUniversalObject;

/*
 Get the LKMELinkProperties from the first time this user was referred (can be empty).
 */
- (LMLinkProperties *)getFirstReferringLinkedMELinkProperties;

/*
 获取用户第一次使用信息 (可空).
 */
- (NSDictionary *)getFirstReferringParams;

/*
 最近一次获取LKMEUniversalObject信息(可空)
 */
- (LMUniversalObject *)getLatestReferringLinkedMEUniversalObject;

/*
 从最近一次获取LKMELinkProperties属性(可空）
 */
- (LMLinkProperties *)getLatestReferringLinkedMELinkProperties;

/*
    获取参数最近使用时间
 */
- (NSDictionary *)getLatestReferringParams;

/*
 内部调用自动完成
 Tells LinkedME to act as though initSession hadn't been called. Will require another open call (this is done automatically, internally).
 */

/*
 *  重置用户会话
 */
- (void)resetUserSession;

/*
 
 用户是否自定义身份
 */
- (BOOL)isUserIdentified;

/*
 设置用户标识设置
 @param userId 用户标识
 @warning 如果你使用相同的ID用户之间在不同会话/设备,他们的行为将会被合并。
 */
- (void)setIdentity:(NSString *)userId;

/*
 设置用户表示,并且提供回调信息
 
 @param userId 用户标识
 @param callback 回调信息,成功或失败.
 
 */
- (void)setIdentity:(NSString *)userId withCallback:(callbackWithParams)callback;

/*
 清除当前用户的所有会话
 
 @warning 如果注销失败,内容将不回被清除
 */
- (void)logout;

- (void)logoutWithCallback:(callbackWithStatus)callback;


#pragma mark - 创建短链

///----------------------------------------
/// @name 创建链接
///----------------------------------------

- (void)getShortUrlWithParams:(NSDictionary *)params andTags:(NSArray *)tags andAlias:(NSString *)alias andMatchDuration:(NSUInteger)duration andChannel:(NSString *)channel andFeature:(NSString *)feature andStage:(NSString *)stage andCallback:(callbackWithUrl)callback;


- (void)getSpotlightUrlWithParams:(NSDictionary *)params callback:(callbackWithParams)callback;

#pragma mark - Content Discovery methods

///--------------------------------
/// @name Content Discovery methods
///--------------------------------

/**
 *  创建Spotlight索引
 *
 *  @param title             标题
 *  @param description       描述
 *  @param thumbnailUrl      缩略图Url
 *  @param linkParams        连接参数
 *  @param type              NSUserActivity类型,获取MobileCoreServices框架中的列表.
 *  @param publiclyIndexable 是否添加到Spotlight索引
 *  @param keywords          一组关键字用于搜索索引
 *  @param expirationDate    失效日期
 *  @param identifier        标志符
 *  @param callback          回掉方法
 *  @warning 只支持iOS 9及以上版本iOS 9以下版本只会返回一个错误回掉无法使用
 */
- (void)createDiscoverableContentWithTitle:(NSString *)title description:(NSString *)description thumbnailUrl:(NSURL *)thumbnailUrl linkParams:(NSDictionary *)linkParams type:(NSString *)type publiclyIndexable:(BOOL)publiclyIndexable keywords:(NSSet *)keywords expirationDate:(NSDate *)expirationDate spotlightIdentifier:(NSString *)identifier callback:(callbackWithUrl)callback;

/**
 *  创建Spotlight索引
 *
 *  @param title             标题
 *  @param description       描述
 *  @param thumbnailUrl      缩略图Url
 *  @param linkParams        链接参数
 *  @param type              NSUserActivity类型,获取MobileCoreServices框架中的列表.
 *  @param publiclyIndexable 是否添加到Spotlight索引
 *  @param keywords          一组关键字用于搜索索引
 *  @param expirationDate    失效日期
 *  @param identifier        标志符
 *  @param spotlightCallback 回掉方法
 *  @warning 只支持iOS 9及以上版本iOS 9以下版本只会返回一个错误回掉无法使用
 */

- (void)createDiscoverableContentWithTitle:(NSString *)title description:(NSString *)description thumbnailUrl:(NSURL *)thumbnailUrl linkParams:(NSDictionary *)linkParams type:(NSString *)type publiclyIndexable:(BOOL)publiclyIndexable keywords:(NSSet *)keywords expirationDate:(NSDate *)expirationDate                                     spotlightIdentifier:(NSString *)identifier spotlightCallback:(callbackWithUrlAndSpotlightIdentifier)spotlightCallback;


#pragma mark - Spolight Delete Method
// 根据identifier来删除
+ (void)removeSearchItemWith:(NSArray *)dataArray;
// 删除所有索引
+ (void)removeAllSearchItems;

#pragma mark -initIwhtInterface

/*
 
初始化LinkedME
 
 @warning SDK内部使用.
 */
//- (id)initWithInterface:(LMServerInterface *)interface queue:(LMServerRequestQueue *)queue cache:(LMLinkCache *)cache preferenceHelper:(LMPreferenceHelper *)preferenceHelper key:(NSString *)key;

/*
 通过params注册view
 
 @warning SDK内部使用.
 */
- (void)registerViewWithParams:(NSDictionary *)params andCallback:(callbackWithParams)callback;

/*
 Method used by external LKME libs to initiate server requests
 */
//- (void)executeGenericRequest:(LMServerRequest*)request;

//- (void)getButton:(LMContext *)context andButtonId:(NSString *)buttonId
//       completion:(CompletionHandler)completionHandler andInnerCallBack:(innerCallBack) innerCallBack;

/*
 页面跳转方式-presentView（纯代码实现ViewController）
 
 @param vc 需要跳转的ViewController的类名（必选完全一致）
 @param flag 是否有动画效果.
 @param arr 自定义参数
 @param completion 完成回调
 */
+ (void)presentViewController:(NSString *)vc animated: (BOOL)flag customValue:(NSDictionary *)dict completion:(void (^)(void))completion NS_AVAILABLE_IOS(5_0);

/*
 页面跳转方式-presentView(storyBoard实现ViewController)
 
 @param vc 需要跳转的ViewController的类名（必选完全一致）
 @param flag 是否有动画效果.
 @param storyBoardID storyBoardID
 @param arr 自定义参数
 @param completion 完成回调
 */
+ (void)presentViewController:(NSString *)vc storyBoardID:(NSString *)identifier animated: (BOOL)flag customValue:(NSDictionary *)dict completion:(void (^)(void))completion NS_AVAILABLE_IOS(5_0);

/*
 页面跳转方式-push（纯代码实现ViewController）
 
 @param vc 需要跳转的ViewController的类名（必选完全一致）
 @param flag 是否有动画效果.
 @param arr 自定义参数
 @param completion 完成回调
 */
+ (void)pushViewController:(NSString *)vc animated: (BOOL)flag customValue:(NSDictionary *)dict completion:(void (^)(void))completion NS_AVAILABLE_IOS(5_0);

/*
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
