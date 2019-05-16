//
//  DetailViewController.m
//  LinkedME_DEMO
//
//  Created by LinkedME04 on 6/7/16.
//  Copyright © 2016 Bindx. All rights reserved.
//

#import "DetailViewController.h"
#import <LinkedME_iOS/LinkedME.h>
#import <LinkedME_iOS/LMUniversalObject.h>
#import <LinkedME_iOS/LMLinkProperties.h>


static NSString * const H5_TEST_URL = @"http://192.168.10.101:8888/h5/summary?linkedme=";
static NSString * LINKEDME_SHORT_URL;

@interface DetailViewController ()

@property (strong, nonatomic) LMUniversalObject *linkedUniversalObject;

@end

@implementation DetailViewController{
    BOOL deepLinking;
    NSInteger page;
    NSString *title;
    NSArray *arr;
    NSString * H5_LIVE_URL;
}

@synthesize deepLinkingCompletionDelegate;


- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    [self initData];
    [self initMoreButton];
    [self addPara];
}

- (void)configureControlWithData:(NSDictionary *)data{
    deepLinking = YES;
    _openUrl = [data objectForKey:@"tag"];
}

- (void)initData{
    NSString *Plist=[[NSBundle mainBundle] pathForResource:@"DefaultData" ofType:@"plist"];
    arr = [[NSArray alloc]initWithContentsOfFile:Plist];
    
    if (!deepLinking) {
        _openUrl = [NSString stringWithFormat:@"%@%@",arr[page][@"url"],[LMPreferenceHelper preferenceHelper].linedMEKey];
    }
    [self loadString:_openUrl];
    title = arr[page][@"key"];
}

- (void)setPage:(NSUInteger)index{
    page = index;
}

//初始化更多按钮
-(void)initMoreButton{
    UIButton *sharBtn = [[UIButton alloc]initWithFrame:CGRectMake(self.view.bounds.size.width-50, 20, 40, 40)];
    [sharBtn setImage:[UIImage imageNamed:@"more.png"] forState:UIControlStateNormal];
    [sharBtn addTarget:self action:@selector(umShare) forControlEvents:UIControlEventTouchDown];
    UIBarButtonItem *rightBraBttonItem = [[UIBarButtonItem alloc]initWithCustomView:sharBtn];
    self.navigationItem.rightBarButtonItem = rightBraBttonItem;
}


//分享
- (void)umShare{
    
    //分享的标题
    NSString *textToShare = @"LinkedME深度链接";
    //分享的图片
    UIImage *imageToShare = [UIImage imageNamed:@"share_logo.png"];
    //分享的url
    NSURL *urlToShare = [NSURL URLWithString:LINKEDME_SHORT_URL];
    //在这里呢 如果想分享图片 就把图片添加进去  文字什么的通上
    NSArray *activityItems = @[textToShare,imageToShare, urlToShare];
    UIActivityViewController *activityVC = [[UIActivityViewController alloc]initWithActivityItems:activityItems applicationActivities:nil];
    //不出现在活动项目
    activityVC.excludedActivityTypes = @[UIActivityTypePostToWeibo,UIActivityTypePrint, UIActivityTypeCopyToPasteboard,UIActivityTypeAssignToContact,UIActivityTypeSaveToCameraRoll];
    [self presentViewController:activityVC animated:YES completion:nil];
    // 分享之后的回调
    activityVC.completionWithItemsHandler = ^(UIActivityType  _Nullable activityType, BOOL completed, NSArray * _Nullable returnedItems, NSError * _Nullable activityError) {
        if (completed) {
            NSLog(@"completed");
            //分享 成功
        } else  {
            NSLog(@"cancled");
            //分享 取消
        }
    };
}


//创建短链
-(void)addPara{
    self.linkedUniversalObject = [[LMUniversalObject alloc] init];
    self.linkedUniversalObject.title = title;//标题
    
    LMLinkProperties *linkProperties = [[LMLinkProperties alloc] init];
    linkProperties.channel = @"";//渠道(微信,微博,QQ,等...)
    linkProperties.feature = @"Share";//特点
    linkProperties.tags=@[@"LinkedME",@"Demo"];//标签
    linkProperties.stage = @"Live";//阶段
    [linkProperties addControlParam:@"View" withValue:arr[page][@"url"]];//页面唯一标识
    [linkProperties addControlParam:@"LinkedME" withValue:@"Demo"];//Demo标识
    
    //开始请求短链
    [self.linkedUniversalObject getShortUrlWithLinkProperties:linkProperties andCallback:^(NSString *url, NSError *err) {
        if (url) {            NSLog(@"[LinkedME Info] SDK creates the url is:%@", url);
            //拼接连接
            [self->H5_LIVE_URL stringByAppendingString:self->arr[self->page][@"form"]];
            [self->H5_LIVE_URL stringByAppendingString:@"?linkedme="];
            
            self->H5_LIVE_URL = [NSString stringWithFormat:@"https://www.linkedme.cc/h5/%@?linkedme=",self->arr[self->page][@"form"]];
            //前面是Html5页面,后面拼上深度链接https://xxxxx.xxx (html5 页面地址) ?linkedme=(深度链接)
            //https://www.linkedme.cc/h5/feature?linkedme=https://lkme.cc/AfC/mj9H87tk7
            LINKEDME_SHORT_URL = [self->H5_LIVE_URL stringByAppendingString:url];
        } else {
            LINKEDME_SHORT_URL = self->H5_LIVE_URL;
        }
    }];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)loadString:(NSString *)str{
    NSURL *url = [NSURL URLWithString:str];
    NSURLRequest *request = [NSURLRequest requestWithURL:url];
    [self.webView loadRequest:request];
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
