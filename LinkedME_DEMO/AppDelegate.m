//
//  AppDelegate.m
//  LinkedME_DEMO
//
//  Created by LinkedME04 on 6/7/16.
//  Copyright © 2016 Bindx. All rights reserved.
//

#import "AppDelegate.h"
#import <LinkedME_iOS/LinkedME.h>
//#import "UMSocial.h"
#import "DetailViewController.h"



@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.' //初始化及实例
    LinkedME* linkedme = [LinkedME getInstance];
    [linkedme setDebug];
    //注册Spoltlight


    
    UIStoryboard * storyBoard=[UIStoryboard storyboardWithName:@"Main" bundle:[NSBundle mainBundle]];
    DetailViewController  *featureVC=[storyBoard instantiateViewControllerWithIdentifier:@"detailView"];
    
    [linkedme registerDeepLinkController:featureVC forKey:@"LMFeatureViewController"];
    
    
    //获取跳转参数
    [linkedme initSessionWithLaunchOptions:launchOptions automaticallyDisplayDeepLinkController:NO deepLinkHandler:^(NSDictionary* params, NSError* error) {
        if (!error) {
            NSLog(@"LinkedME finished init with params = %@",[params description]);
            //Router
            NSString *title = [params objectForKey:@"$og_title"];
            NSString *tag = params[@"$control"][@"ViewId"];
            
            if ([title isEqualToString:@"DetailViewController"]) {
                [LinkedME pushViewController:title storyBoardID:@"detailView" animated:YES customValue:@[tag] completion:^{
                    
                }];
            }
           
//            if ([title isEqualToString:@"demo"]) {
//                [LinkedME presentViewController:@"LMDemoViewController" storyBoardID:@"demoviewcontroller" animated:YES customValue:nil completion:^{
//                    
//                }];
//                
//            } else if ([title isEqualToString:@"Summary"]) {
//                [LinkedME presentViewController:@"LMSummaryViewController" storyBoardID:@"partnerviewcontroller" animated:YES customValue:nil completion:^{
//                    
//                }];
//                
//            } else if ([title isEqualToString:@"Feature"]) {
//                [LinkedME presentViewController:@"LMPartnerViewController" storyBoardID:@"summaryviewcontroller" animated:YES customValue:nil completion:^{
//                    
//                }];
//                
//            } else if ([title isEqualToString:@"Partner"]) {
//                [LinkedME presentViewController:@"LMPartnerViewController" storyBoardID:@"partnerviewcontroller" animated:YES customValue:@[@"我就是我，是颜色不一样的自定义参数~~"] completion:^{
//                    
//                }];
//            }
        } else {
            NSLog(@"LinkedME failed init: %@", error);
        }
    }];

    
    return YES;
}

- (BOOL)application:(UIApplication*)application openURL:(NSURL*)url sourceApplication:(NSString*)sourceApplication annotation:(id)annotation{
    return [[LinkedME getInstance] handleDeepLink:url];
}

//Universal Links 通用链接实现深度链接技术
- (BOOL)application:(UIApplication*)application continueUserActivity:(NSUserActivity*)userActivity restorationHandler:(void (^)(NSArray*))restorationHandler{
    return  [[LinkedME getInstance] continueUserActivity:userActivity];
}

//URI Scheme 实现深度链接技术
- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<NSString*, id> *)options{
    NSLog(@"opened app from URL %@", [url description]);
    return [[LinkedME getInstance] handleDeepLink:url];
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
