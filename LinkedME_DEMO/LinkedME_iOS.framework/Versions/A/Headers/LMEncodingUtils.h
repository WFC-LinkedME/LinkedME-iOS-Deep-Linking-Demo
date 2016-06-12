//
//  LMEncodingUtils.h
//  iOS-Deep-Linking-SDK
//
//  Created by han on 3/31/15.
//  Copyright (c) 2015 LM han. All rights reserved.
//

#import <Foundation/Foundation.h>

//Encoding

@interface LMEncodingUtils : NSObject

+ (NSString *)base64EncodeStringToString:(NSString *)strData;
+ (NSString *)base64DecodeStringToString:(NSString *)strData;
+ (NSString *)base64EncodeData:(NSData *)objData;

+ (NSString *)md5Encode:(NSString *)input;

+ (NSString *)encodeArrayToJsonString:(NSArray *)dictionary;
+ (NSString *)encodeDictionaryToJsonString:(NSDictionary *)dictionary;
+ (NSData *)encodeDictionaryToJsonData:(NSDictionary *)dictionary;

+ (NSDictionary *)decodeJsonDataToDictionary:(NSData *)jsonData;
+ (NSDictionary *)decodeJsonStringToDictionary:(NSString *)jsonString;
+ (NSDictionary *)decodeQueryStringToDictionary:(NSString *)queryString;
+ (NSString *)encodeDictionaryToQueryString:(NSDictionary *)dictionary;

/**
 *  传入NSArray生成Sign签名
 *
 *  @param params array
 *
 *  @return sign
 */
+ (NSString *)sign:(NSArray *)params;

@end
