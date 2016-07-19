//
//  LMUniversalObject.h
//  iOS-Deep-Linking-SDK
//
//  Created by han on 10/16/15.
//  Copyright © 2015 LM han. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LMLinkProperties.h"
#import "LinkedME.h"

typedef void (^callback) ();
typedef void (^shareCompletion) (NSString *activityType, BOOL completed);

//通用对象

@interface LMUniversalObject : NSObject

typedef NS_ENUM(NSInteger, ContentIndexMode) {
    ContentIndexModePublic,
    ContentIndexModePrivate
};

//规范标识符
@property (nonatomic, strong) NSString *canonicalIdentifier;
//规范Url
@property (nonatomic, strong) NSString *canonicalUrl;
//标题
@property (nonatomic, strong) NSString *title;
//内容描述
@property (nonatomic, strong) NSString *contentDescription;
//图片地址
@property (nonatomic, strong) NSString *imageUrl;
// Note: properties found in metadata will overwrite properties on the BranchUniversalObject itself
@property (nonatomic, strong) NSDictionary *metadata;
//类型
@property (nonatomic, strong) NSString *type;
@property (nonatomic) ContentIndexMode contentIndexMode;
//关键字
@property (nonatomic, strong) NSArray *keywords;
//截止日期
@property (nonatomic, strong) NSDate *expirationDate;
//spotlight标识符
@property (nonatomic, strong) NSString *spotlightIdentifier;


- (instancetype)initWithCanonicalIdentifier:(NSString *)canonicalIdentifier;
- (instancetype)initWithTitle:(NSString *)title;

- (void)addMetadataKey:(NSString *)key value:(NSString *)value;

//注册View
- (void)registerView;
- (void)registerViewWithCallback:(callbackWithParams)callback;

//通过LMLinkProperties获得短链接
- (NSString *)getShortUrlWithLinkProperties:(LMLinkProperties *)linkProperties;
//通过LMLinkProperties获得短链接并忽略第一次点击
//- (NSString *)getShortUrlWithLinkPropertiesAndIgnoreFirstClick:(LMLinkProperties *)linkProperties;
//通过LMLinkProperties获得短链接Block形式
- (void)getShortUrlWithLinkProperties:(LMLinkProperties *)linkProperties andCallback:(callbackWithUrl)callback;

- (void)listOnSpotlight;
- (void)listOnSpotlightWithCallback:(callbackWithUrl)callback;
- (void)listOnSpotlightWithIdentifierCallback:(callbackWithUrlAndSpotlightIdentifier)spotlightCallback;

// Convenience method for initSession methods that return BranchUniversalObject, but can be used safely by anyone.
//返回LMUniversalObject(安全方法)
+ (LMUniversalObject *)getBranchUniversalObjectFromDictionary:(NSDictionary *)dictionary;

- (NSString *)description;

@end
