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


static NSString * const H5_TEST_URL = @"http://192.168.10.101:8888/h5/summary?linkedme=";
static NSString * const H5_LIVE_URL = @"https://guide.lkme.cc/h5/summary?linkedme=";
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
    
    //获取测试Key
//    [LMSystemObserver getTestID]

    [_testID setTitle:[LinkedME getTestID] forState:UIControlStateNormal];
}

- (IBAction)copyTestKey:(id)sender {
    return;
    UIPasteboard *pasteboard = [UIPasteboard generalPasteboard];
    pasteboard.string = _testID.titleLabel.text;
    UIAlertView *alertView = [[UIAlertView alloc]initWithTitle:@"添加成功" message:@"已添加的设备可以在DashBoard中删除" delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil, nil];
    [alertView show];
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
    linkProperties.channel = _channel.text;
    linkProperties.tags=@[_tag.text];
    linkProperties.stage = _live.text;
    
    linkProperties.source = @"iOS";
    if (_key_1.text.length && _value_1.text.length) {
        [linkProperties addControlParam:_key_1.text withValue:_value_1.text];
    }
    if (_key_2.text.length && _value_2.text.length) {
        [linkProperties addControlParam:_key_2.text withValue:_value_2.text];
    }
    if (_key_3.text.length && _value_3.text.length) {
        [linkProperties addControlParam:_key_3.text withValue:_value_3.text];
    }

    [linkProperties setAndroidPathControlParam:@"*"];
    [linkProperties setIOSKeyControlParam:@"*"];
    
    parmas = [NSString stringWithFormat:@"%@\n%@",[self.linkedUniversalObject description],[linkProperties description]];
    
//    self.textView.text = [parmas stringByReplacingOccurrencesOfString:@"BranchUniversalObject" withString:@""];
    
    [self.linkedUniversalObject getShortUrlWithLinkProperties:linkProperties andCallback:^(NSString *url, NSError *err) {
        if (url) {
            NSLog(@"[LinkedME Info] SDK creates the url is:%@", url);
//            LINKEDME_SHORT_URL = [H5_LIVE_URL stringByAppendingString:url];
//            self.url.text = LINKEDME_SHORT_URL;
            self.url.text = url;
            [self.btnTitle setTitle:@"复制成功" forState:UIControlStateNormal];
            self.btnTitle.backgroundColor = [UIColor greenColor];
            UIPasteboard *pasteboard = [UIPasteboard generalPasteboard];
            pasteboard.string = url;
        } else {
            LINKEDME_SHORT_URL = H5_LIVE_URL;
        }
    }];
}

- (IBAction)click_back:(id)sender {
    [self.view endEditing:YES];
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
