//
//  DetailViewController.h
//  LinkedME_DEMO
//
//  Created by LinkedME04 on 6/7/16.
//  Copyright © 2016 Bindx. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <LinkedME_iOS/LMDeepLinkingController.h>

@interface DetailViewController : UIViewController<LMDeepLinkingController>

@property (weak, nonatomic) IBOutlet UIWebView *webView;

@property (strong ,nonatomic) NSString *openUrl;

- (void)setPage:(NSUInteger)index;

@end
