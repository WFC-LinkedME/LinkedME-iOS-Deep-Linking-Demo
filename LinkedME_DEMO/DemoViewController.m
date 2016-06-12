//
//  DemoViewController.m
//  LinkedME_DEMO
//
//  Created by LinkedME04 on 6/7/16.
//  Copyright © 2016 Bindx. All rights reserved.
//

#import "DemoViewController.h"
#import <LinkedME_iOS/LinkedME.h>
#import <LinkedME_iOS/LMUniversalObject.h>
#import <LinkedME_iOS/LMLinkProperties.h>

static NSString * const H5_TEST_URL = @"http://192.168.10.101:8888/h5/summary?linkedme=";
static NSString * const H5_LIVE_URL = @"https://www.linkedme.cc/h5/summary?linkedme=";
static NSString * LINKEDME_SHORT_URL;

@interface DemoViewController ()

@property (strong, nonatomic) LMUniversalObject *linkedUniversalObject;

@end

@implementation DemoViewController{
    NSString *parmas;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)createShotrUrl:(id)sender {
    [self addPara];
}

//创建短链
-(void)addPara{
    self.linkedUniversalObject = [[LMUniversalObject alloc] initWithCanonicalIdentifier:@"item/12345"];
    self.linkedUniversalObject.title = @"title";
    self.linkedUniversalObject.contentDescription = @"My Content Description";
    self.linkedUniversalObject.imageUrl = @"https://s3-us-west-1.amazonaws.com/branchhost/mosaic_og.png";
    [self.linkedUniversalObject addMetadataKey:@"custom_key1" value:@"some custom data"];
    [self.linkedUniversalObject addMetadataKey:@"custom_key2" value:@"more custom data"];
    
    LMLinkProperties *linkProperties = [[LMLinkProperties alloc] init];
    linkProperties.channel = @"Wechat";
    linkProperties.tags=@[@"LinkedME",@"test"];
    linkProperties.alias = @"alias";
    linkProperties.stage = @"test";
    linkProperties.source = @"iOS";
    [linkProperties addControlParam:@"$desktop_url" withValue:@"https://www.linkedme.cc"];
    [linkProperties addControlParam:@"$ios_url" withValue:@"https://www.linkedme.cc"];
    [linkProperties addControlParam:@"ViewId" withValue:@"ViewID"];
    [linkProperties setAndroidPathControlParam:@"*"];
    [linkProperties setIOSKeyControlParam:@"*"];
    
    parmas = [NSString stringWithFormat:@"%@\n%@",[self.linkedUniversalObject description],[linkProperties description]];
    
    self.textView.text = [parmas stringByReplacingOccurrencesOfString:@"BranchUniversalObject" withString:@""];
    
    [self.linkedUniversalObject getShortUrlWithLinkProperties:linkProperties andCallback:^(NSString *url, NSError *err) {
        if (url) {
            NSLog(@"[LinkedME Info] SDK creates the url is:%@", url);
            LINKEDME_SHORT_URL = [H5_LIVE_URL stringByAppendingString:url];
            
            self.url.text = LINKEDME_SHORT_URL;
            [self.btnTitle setTitle:@"复制成功" forState:UIControlStateNormal];
            self.btnTitle.backgroundColor = [UIColor greenColor];
            UIPasteboard *pasteboard = [UIPasteboard generalPasteboard];
            pasteboard.string = LINKEDME_SHORT_URL;
        } else {
            LINKEDME_SHORT_URL = H5_LIVE_URL;
        }
    }];
}
/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
