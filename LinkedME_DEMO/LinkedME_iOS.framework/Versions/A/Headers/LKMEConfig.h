//
//  LMConfig.h
//  iOS-Deep-Linking-SDK
//
//  Created by han on 10/6/14.
//  Copyright (c) 2014 LM han. All rights reserved.
//

#ifndef Branch_SDK_Config_h
#define Branch_SDK_Config_h




#define  KOnlineSecretKey       //线上环境，线上环®境优先级最高

#ifdef KOnlineSecretKey

// 正式
#define LKME_API_BASE_URL        @"http://lkme.cc"
#define LKME_API_VERSION         @"i"
#define LINKME_KEY [NSBundle mainBundle].infoDictionary[@"linkedme_key"][@"live"]

#else

// 测试
#define LKME_API_BASE_URL        @"http://10.0.2.106:8080"
#define LKME_API_VERSION         @"t"
#define LINKME_KEY [NSBundle mainBundle].infoDictionary[@"linkedme_key"][@"test"]


#endif


#define LKME_KEY(LIVE) LIVE?[NSBundle mainBundle].infoDictionary[@"linkedme_key"][@"live"]:\
[NSBundle mainBundle].infoDictionary[@"linkedme_key"][@"test"]

#define SDK_VERSION             @"1.0.1"

#define BNC_PROD_ENV
//#define BNC_STAGE_ENV
//#define BNC_DEV_ENV

#ifdef BNC_PROD_ENV
//#define BNC_API_BASE_URL        @"https://api.branch.io"
//#define BNC_API_BASE_URL        @"http://192.168.0.101:8888"

//#define LKME_API_BASE_URL        @"https://lkme.cc"
//#define LKME_API_TEST_URL        @"https://lkme.cc"

#endif

#ifdef BNC_STAGE_ENV
#define BNC_API_BASE_URL        @"http://api.dev.branchmetrics.io"
#endif

#define BNC_LINK_URL             @"https://bnc.lt"

#ifdef BNC_DEV_ENV
#define BNC_API_BASE_URL        @"http://localhost:3001"
#endif

//#define BNC_API_VERSION         @"v1"

#define LKME_API_PREFIX_SDK     @"sdk"
#define LKME_API_PREFIX_UBER    @"uber"
#define UBER_SERIVER_TOKEN    @"MKNqADasDys70b6R9HBEW-51fM59sEM3r8pWHibB"


#endif
