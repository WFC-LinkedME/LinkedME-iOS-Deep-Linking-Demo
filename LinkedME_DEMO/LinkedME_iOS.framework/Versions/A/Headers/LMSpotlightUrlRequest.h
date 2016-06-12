//
//  LMSpotlightUrlRequest.h
//  iOS-Deep-Linking-SDK
//
//  Created by han on 7/23/15.
//  Copyright © 2015 LM han. All rights reserved.
//

#import "LMShortUrlRequest.h"

@interface LMSpotlightUrlRequest : LMShortUrlRequest

- (id)initWithParams:(NSDictionary *)params callback:(callbackWithParams)callback;

@end
