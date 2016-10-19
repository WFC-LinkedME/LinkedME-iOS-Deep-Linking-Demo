//
//  LMDeepLinkingController.h
//  iOS-Deep-Linking-SDK
//
//  Created by han on 6/18/15.
//  Copyright (c) 2015 Bindx. All rights reserved.
//

@protocol LMDeepLinkingControllerCompletionDelegate <NSObject>

- (void)deepLinkingControllerCompleted;

@end

@protocol LMDeepLinkingController <NSObject>

- (void)configureControlWithData:(NSDictionary *)data;

@property (weak, nonatomic) id <LMDeepLinkingControllerCompletionDelegate> deepLinkingCompletionDelegate;

@end