//
//  ViewController.m
//  LinkedME_DEMO
//
//  Created by LinkedME04 on 6/7/16.
//  Copyright © 2016 Bindx. All rights reserved.
//

#import "ViewController.h"
#import "DetailViewController.h"
#import "DemoViewController.h"
#import <LinkedME_iOS/LinkedME.h>
#import <LinkedME_iOS/LinkAdView.h>


@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
//    LinkAdView *ad = [LinkAdView getAdWithFrame:CGRectMake(0, [UIScreen mainScreen].bounds.size.height - 100, 450, 100) withAdid:8005 tags:@"" statusCallBack:^(BOOL status, NSDictionary *content) {
//        //加载广告并回调广告状态（是否显示广告）
//        if (!status) {
//            //广告加载失败，这里处理显示其他广告的代码
//        }
//    }];
//    ad.backgroundColor = [UIColor redColor];
//    [self.view addSubview:ad];
    
    
    
    /*----------------------Spotlight------------------------*/
    
    //关键字
    NSSet *set5 = [NSSet setWithObjects:@"linkedme",@"linked",@"深度链接", nil];
    //链接参数
    NSDictionary *dict = @{@"url":@"http://linkedme.cc"};
    
    /*
     *  @param title             标题
     *  @param description       描述
     *  @param publiclyIndexable 是否公开
     *  @param type              类型
     *  @param thumbnailUrl      缩略图Url
     *  @param keywords          关键字
     *  @param userInfo          用户详情
     *  @param expirationDate    失效日期,设置失效日期会自动删除索引
     *  @param identifier        标志符
     *  @param callback          回调
     *  @param spotlightCallback Spotlight回掉
     */
    
    [[LinkedME getInstance] createDiscoverableContentWithTitle:@"LinkedME 国内第一家企业级深度链接"
                                                   description:@"让APP不再是信息孤岛!"
                                                  thumbnailUrl:[NSURL URLWithString:@"http://7xq8b0.com1.z0.glb.clouddn.com/logo.png"]
                                                    linkParams:dict
                                                          type:@""
                                             publiclyIndexable:NO keywords:set5
                                                expirationDate:nil
                                           spotlightIdentifier:@"bbcc"
                                             spotlightCallback:^(NSString *url, NSString *spotlightIdentifier, NSError *error) {
        
    }];
    
    
    //删除Spotlight item,在特定条件下触发
    //删除所有条目
    //[LinkedME removeAllSearchItems];
    //根据identifier删除
    //[LinkedME removeSearchItemWith:@[@"bbcc"]];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)pushDetailView:(UIButton *)btn{
    UIStoryboard * storyBoard=[UIStoryboard storyboardWithName:@"Main" bundle:[NSBundle mainBundle]];
    if (btn.tag != 2) {
        DetailViewController *featureVC=[storyBoard instantiateViewControllerWithIdentifier:@"detailView"];
        [featureVC setPage:btn.tag];
        [self.navigationController pushViewController:featureVC animated:YES];
    }else{
        DemoViewController *dvc=[storyBoard instantiateViewControllerWithIdentifier:@"demoView"];
        [self.navigationController pushViewController:dvc animated:YES];
    }
}

@end
