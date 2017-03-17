//
//  LMPreferenceHelper.h
//  iOS-Deep-Linking-SDK

//  Created by han on 6/6/14.
//  Copyright (c) 2014 Bindx. All rights reserved.
//

#import <Foundation/Foundation.h>

//偏好助手

#define FILE_NAME   [[NSString stringWithUTF8String:__FILE__] lastPathComponent]
#define LINE_NUM    __LINE__

@interface LMPreferenceHelper : NSObject

@property (strong, nonatomic) NSString *linedMEKey;
@property (strong, nonatomic) NSString *appKey;
@property (strong, nonatomic) NSString *lastRunLinkedMeKey;
@property (strong, nonatomic) NSDate   *lastStrongMatchDate;
@property (strong, nonatomic) NSString *appVersion;
@property (strong, nonatomic) NSString *deviceFingerprintID;
@property (strong, nonatomic) NSString *sessionID;
@property (strong, nonatomic) NSString *identityID;
@property (strong, nonatomic) NSString *linkClickIdentifier;
@property (strong, nonatomic) NSString *spotlightIdentifier;
@property (strong, nonatomic) NSString *universalLinkUrl;
@property (strong, nonatomic) NSString *userUrl;
@property (strong, nonatomic) NSString *userKey;
@property (strong, nonatomic) NSString *userIdentity;
@property (strong, nonatomic) NSString *sessionParams;
@property (strong, nonatomic) NSString *installParams;
@property (strong, nonatomic) NSString *callBackUrl;
@property (assign, nonatomic) BOOL explicitlyRequestedReferrable;
@property (assign, nonatomic) BOOL isReferrable;
@property (assign, nonatomic) BOOL isDebug;
@property (assign, nonatomic) BOOL useHTTPS;
@property (assign, nonatomic) BOOL shouldWaitForInit;
@property (assign, nonatomic) BOOL isContinuingUserActivity;
@property (assign, nonatomic) NSInteger retryCount;
@property (assign, nonatomic) NSTimeInterval retryInterval;
@property (assign, nonatomic) NSTimeInterval timeout;
@property (strong, nonatomic) NSString *externalIntentURI;
@property (strong, nonatomic) NSString *sdk_version;
@property (strong, nonatomic) NSString *closeSession;
@property (assign, nonatomic) BOOL getSafariCookice;
@property (assign, nonatomic) BOOL closeEnable;

+ (LMPreferenceHelper *)preferenceHelper;

- (NSString *)getAPIBaseURL;
- (NSString *)getAPIURL:(NSString *)endpoint;
- (NSString *)getLinkedMEKey:(BOOL)isLive;
-(NSString *)getGameTrackURL:(NSString *)endpoint;
- (NSString *)getTrackURL:(NSString *)endpoint;
- (NSString *)getSDKURL:(NSString *)endpoint;
- (NSString *)getUberURL:(NSString *)endpoint;

+ (NSString *)getSDKURL:(NSString *)endpoint;

- (void)clearUserCreditsAndCounts;
- (void)clearUserCredits;

- (id)getLinkedMEUniversalLinkDomains;

- (void)setCreditCount:(NSInteger)count;
- (void)setCreditCount:(NSInteger)count forBucket:(NSString *)bucket;
- (void)removeCreditCountForBucket:(NSString *)bucket;
- (NSDictionary *)getCreditDictionary;
- (NSInteger)getCreditCount;
- (NSInteger)getCreditCountForBucket:(NSString *)bucket;

- (void)setActionTotalCount:(NSString *)action withCount:(NSInteger)count;
- (void)setActionUniqueCount:(NSString *)action withCount:(NSInteger)count;


- (void)log:(NSString *)filename line:(int)line message:(NSString *)format, ...;

@end
