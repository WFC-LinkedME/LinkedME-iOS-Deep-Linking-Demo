//
//  AppDelegate.m
//  LinkedME_DEMO
//
//  Created by LinkedME04 on 6/7/16.
//  Copyright © 2016 Bindx. All rights reserved.
//

#import "AppDelegate.h"
#import <LinkedME_iOS/LinkedME.h>
#import "DetailViewController.h"



@interface AppDelegate ()

@end

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.'
    
    //初始化及实例
    LinkedME* linkedme = [LinkedME getInstance];
    
    //打印日志
    [linkedme setDebug];
    
    //    //注册需要跳转的viewController
    UIStoryboard * storyBoard=[UIStoryboard storyboardWithName:@"Main" bundle:[NSBundle mainBundle]];
    DetailViewController  *dvc=[storyBoard instantiateViewControllerWithIdentifier:@"detailView"];
    
    //[自动跳转]如果使用自动跳转需要注册viewController
    //    [linkedme registerDeepLinkController:featureVC forKey:@"LMFeatureViewController"];
 
#warning 必须实现
    //获取跳转参数
    [linkedme initSessionWithLaunchOptions:launchOptions automaticallyDisplayDeepLinkController:NO deepLinkHandler:^(NSDictionary* params, NSError* error) {
        if (!error) {
            //防止传递参数出错取不到数据,导致App崩溃这里一定要用try catch
            @try {
            NSLog(@"LinkedME finished init with params = %@",[params description]);
            //获取详情页类型(如新闻客户端,有图片类型,视频类型,文字类型等)
//            NSString *title = [params objectForKey:@"$og_title"];
            NSString *tag = params[@"$control"][@"View"];
                
//                if (title.length >0 && tag.length >0) {
                if (tag.length >0) {
                    //[自动跳转]使用自动跳转
                    //SDK提供的跳转方法
                    /**
                     *  pushViewController : 类名
                     *  storyBoardID : 需要跳转的页面的storyBoardID
                     *  animated : 是否开启动画
                     *  customValue : 传参
                     *
                     *warning  需要在被跳转页中实现次方法 - (void)configureControlWithData:(NSDictionary *)data;
                     */

//                    [LinkedME pushViewController:title storyBoardID:@"detailView" animated:YES customValue:@{@"tag":tag} completion:^{
///
//                    }];
                    
                    //自定义跳转
                    dvc.openUrl = params[@"$control"][@"ViewId"];
                    [[LinkedME getViewController] showViewController:dvc sender:nil];
                    
                }
                
                            } @catch (NSException *exception) {
                
                            } @finally {
                
                            }
            
        } else {
            NSLog(@"LinkedME failed init: %@", error);
        }
    }];
    

    return YES;
}

#warning 必须实现
- (BOOL)application:(UIApplication*)application openURL:(NSURL*)url sourceApplication:(NSString*)sourceApplication annotation:(id)annotation{
    //判断是否是通过LinkedME的UrlScheme唤起App
    if ([[url description] rangeOfString:@"click_id"].location != NSNotFound) {
        return [[LinkedME getInstance] handleDeepLink:url];
    }
    
    return YES;
}

#warning 必须实现
//Universal Links 通用链接实现深度链接技术
- (BOOL)application:(UIApplication*)application continueUserActivity:(NSUserActivity*)userActivity restorationHandler:(void (^)(NSArray*))restorationHandler{
    
    //判断是否是通过LinkedME的Universal Links唤起App
    if ([[userActivity.webpageURL description] rangeOfString:@"lkme.cc"].location != NSNotFound) {
        return  [[LinkedME getInstance] continueUserActivity:userActivity];
    }
    
    return YES;
}

#warning 必须实现
//URI Scheme 实现深度链接技术
- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<NSString*, id> *)options{
    NSLog(@"opened app from URL %@", [url description]);
    
    //判断是否是通过LinkedME的UrlScheme唤起App
    if ([[url description] rangeOfString:@"click_id"].location != NSNotFound) {
        return [[LinkedME getInstance] handleDeepLink:url];
    }
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}




- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
