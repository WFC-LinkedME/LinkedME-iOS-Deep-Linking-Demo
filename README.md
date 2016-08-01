#LinkedME iOS 集成文档

[![CI Status](http://img.shields.io/travis/Bindx/LinkedME_iOS.svg?style=flat)](https://travis-ci.org/Bindx/LinkedME_iOS)
[![Version](https://img.shields.io/cocoapods/v/LinkedME_iOS.svg?style=flat)](http://cocoapods.org/pods/LinkedME_iOS)
[![License](https://img.shields.io/cocoapods/l/LinkedME_iOS.svg?style=flat)](http://cocoapods.org/pods/LinkedME_iOS)
[![Platform](https://img.shields.io/cocoapods/p/LinkedME_iOS.svg?style=flat)](http://cocoapods.org/pods/LinkedME_iOS)

## Installation

LinkedME_iOS is available through [CocoaPods](http://cocoapods.org). To install
it, simply add the following line to your Podfile:

```ruby
pod "LinkedME_iOS"
```
## Example

To run the example project, clone the repo, and run `pod install` from the Example directory first.

# 1.下载SDK&Demo（简述）
![sdkinfo set up](http://7xq8b0.com1.z0.glb.clouddn.com/sdk_info.png)

文件名 | 描述
------------ | -------------
LinkedME_iOS.framework | LinkedME SDK
DetailViewController | Demo详情页-webView加载html网页 
DemoViewController | 生成短链，展示生成锻炼的必要参数 
DefaultData | 参数默认必要参数 

注：为了iOS/Android/Web三端更好的统一，和版本迭代更新

## 1.1. Framework
	1.CoreSpotlight.framework (status:Optional)
	2.SystemConfiguration.framework
	3.Security.framework
	
	注:CoreSpotlight.framework必须标记为可选

# 2.注册用户
1. 注册用户，并登陆系统

![image](http://o8fx2z8ev.bkt.clouddn.com/lkme/register1.png)

# 3.创建App生成linkedme_key
1. 创建app

	![image](http://o8fx2z8ev.bkt.clouddn.com/lkme/create_app11.png)
	
	![image](http://o8fx2z8ev.bkt.clouddn.com/lkme/create_app22.png)

2. 获取LinkedME Key

	创建完App后，系统会分配一个LinkedME App ID、LinkedME Key和LinkedME Secret（无法修改）。
	
	如下图的红框2，就是LinkedME Key。

	![image](http://o8fx2z8ev.bkt.clouddn.com/lkme/get_key.png)


3. 设置App，分为两部分：概览和链接；其中概览部分只能修改app名称和修改LOGO。


4. 设置App的链接部分

	4.1 如果没有iOS应用，Directed URL框里填写深度链接默认跳转地址；
	
	![image](http://o8fx2z8ev.bkt.clouddn.com/lkme/set_app_ios1.png)
	
	4.2 如果有iOS应用，勾选有iOS应用的框，并填写App的URI Scheme；如果App在App Store上线了，请勾选“App Store”，并填写App在App Store上的地址；
	
	![image](http://o8fx2z8ev.bkt.clouddn.com/lkme/set_app_ios2.png)
	
	4.3 如果App没有在App Store上线，请勾选“自定义”，并填写App的ipc文件的下载地址；
	
	![image](http://o8fx2z8ev.bkt.clouddn.com/lkme/set_app_ios3.png)
	
	4.4 如果App支持Universal Links，请勾选“Universal Links”,并填写Bundle ID和Apple App Prefix。
	
	![image](http://o8fx2z8ev.bkt.clouddn.com/lkme/set_app_ios4.png)

# 4.工程设置
## 4.1 注册URLScheme（推荐/可选）
	1.打开info.plist
	2.找到URL Types（如果没有就右键add row添加一个）
	3.添加"you app"(你的app的唯一标识字符串)
![urltypes set up](https://camo.githubusercontent.com/f763b14111fbf591bf8cb45de5e884d3b68cd46d/68747470733a2f2f73332d75732d776573742d312e616d617a6f6e6177732e636f6d2f6272616e6368686f73742f75726c536368656d652e706e67)

	
	
## 4.2 Universal Linking (仅支持iOS 9)
	1.在左侧导航器中点击您的项目
	2.选择'Capabilities'标签
	3.打开'Associated Domains'开关
	4.添加applinks:lkme.cc和applinks:www\.lkme\.cc
![Associated Domains set up](http://7xq8b0.com1.z0.glb.clouddn.com/ass.png)


# 5.代码集成

## 5.1 添加linkedme_key
	1.打开info.plist文件
	2.在列表中点击右键选择add row添加一个分组
	3.创建一个新的item名称为linkedme_key类型为Dictionary。
	4.在linkedme_key新增两个字符串类型的item分别为live和test

![lmkey set up](http://7xq8b0.com1.z0.glb.clouddn.com/lmkey.png)

## 5.2 设置AppDelegate
### 5.2.1 解析深度链接跳转参数
### Objective-C

#####1.在AppDelegate中引入头文件 

#####　`#import <LinkedME_iOS/LinkedME.h>`

#####2.在Appdelegate里注册ViewController
####　2.1配置注册vc设置及跳转方式

```objc
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.'
    //初始化及实例
    LinkedME* linkedme = [LinkedME getInstance];
    
    //    //注册需要跳转的viewController
    UIStoryboard * storyBoard=[UIStoryboard storyboardWithName:@"Main" bundle:[NSBundle mainBundle]];
    DetailViewController  *dvc=[storyBoard instantiateViewControllerWithIdentifier:@"detailView"];
    
    //如果使用自动跳转需要注册viewController
    //    [linkedme registerDeepLinkController:featureVC forKey:@"LMFeatureViewController"];
    
    //获取跳转参数
    [linkedme initSessionWithLaunchOptions:launchOptions automaticallyDisplayDeepLinkController:NO deepLinkHandler:^(NSDictionary* params, NSError* error) {
        if (!error) {
            @try {
            NSLog(@"LinkedME finished init with params = %@",[params description]);
            //获取标题
            NSString *title = [params objectForKey:@"$og_title"];
                if ([title isEqualToString:@"DetailViewController"]) {
                    dvc.openUrl = params[@"$control"][@"ViewId"];
                    [[LinkedME getViewController] showViewController:dvc sender:nil];
                }
                
            } @catch (NSException *exception) {
                
            } @finally {
                
            }
            
            //使用自动跳转
            //            if ([title isEqualToString:@"DetailViewController"]) {
            //                //通过标题跳转当详细页面，customValue跳转的参数
            //
            //                [LinkedME pushViewController:title storyBoardID:@"detailView" animated:YES customValue:@{@"tag":tag} completion:^{
            //
            //                }];
            //            }
            
            //手动跳转
            //[[LinkedME getViewController].navigationController pushViewController:featureVC animated:YES];
            // 传递自定义参数
            //featureVC.xxx = params[@"$control"][@"ViewId"];
            
        } else {
            NSLog(@"LinkedME failed init: %@", error);
        }
    }];
    return YES;
}
```

### Swift
##在 1.xxxx-Bridging-Header.h中导入头文件
####　`#import <LinkedME_iOS/LinkedME.h>`

##2.在Appdelegate里注册ViewController
####　2.1配置注册vc设置及跳转方式
```swift
    func application(application: UIApplication, didFinishLaunchingWithOptions launchOptions: [NSObject: AnyObject]?) -> Bool {
        // Override point for customization after application launch.
        
        let linkedme = LinkedME.getInstance();
        //是否开启Debug模式
        //linkedme.setDebug();
        let storyBoard = UIStoryboard().instantiateViewControllerWithIdentifier("detailView");
        linkedme.registerDeepLinkController(storyBoard, forKey: "detailView");
        
        //获取跳转参数
        linkedme.initSessionWithLaunchOptions(launchOptions, automaticallyDisplayDeepLinkController: false) { (params, error) in
            if(error != nil){
                print("LinkedME finished init with params\(params.description)");
                let title = params["$og_title"];
                let tag = params["$control"]!["ViewId"];

                if (title!.isEqualToString("DetailViewController")){
                    
                    LinkedME.pushViewController(title as! String, storyBoardID: "detailView", animated: true, customValue: tag as! [AnyObject], completion: {
                        
                    });
                }
            }else{
                print(error);
            }
        }
        
        return true
    }
```



#####实现自定义跳转必须注册ViewController遵循LMDeepLinkingController协议<br> 并实现 - (void)configureControlWithData:(NSDictionary *)data方法</br>
### 4.2.2 添加URLScheme和Uniiversal LinKing支持
####　在Appdelegate中实现下列方法
###OC


```objc
- (BOOL)application:(UIApplication*)application openURL:(NSURL*)url sourceApplication:(NSString*)sourceApplication annotation:(id)annotation{
	  return [[LinkedME getInstance] handleDeepLink:url];
}
```
	
```objc
//Universal Links 通用链接实现深度链接技术
- (BOOL)application:(UIApplication*)application continueUserActivity:(NSUserActivity*)userActivity restorationHandler:(void (^)(NSArray*))restorationHandler{
    return  [[LinkedME getInstance] continueUserActivity:userActivity];
}
```
	
```objc
//URI Scheme 实现深度链接技术
- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<NSString*, id> *)options{
    NSLog(@"opened app from URL %@", [url description]);
    return [[LinkedME getInstance] handleDeepLink:url];
}
```

###Swift

```swift
func application(application: UIApplication, openURL url: NSURL, sourceApplication: String?, annotation: AnyObject) -> Bool {
        return LinkedME.getInstance().handleDeepLink(url);
    }
```
	
```swift
//Universal Links 通用链接实现深度链接技术
func application(application: UIApplication, continueUserActivity userActivity: NSUserActivity, restorationHandler: ([AnyObject]?) -> Void) -> Bool {
        return LinkedME.getInstance().continueUserActivity(userActivity);
    }
```
	
```swift
//URI Scheme 实现深度链接技术
func  application(app: UIApplication, openURL url: NSURL, options: [String : AnyObject]) -> Bool {
        return LinkedME.getInstance().handleDeepLink(url);
    }
```
	
#（创建深度连接）
```
-(void)addPara{
    self.branchUniversalObject = [[LKMEUniversalObject alloc] initWithCanonicalIdentifier:@"item/12345"];//标识符
    self.branchUniversalObject.title = @"My Content Title";//标题
    self.branchUniversalObject.contentDescription = @"My Content Description";//描述
    self.branchUniversalObject.imageUrl = @"https://s3-us-west-1.amazonaws.com/branchhost/mosaic_og.png";//图片地址
    [self.branchUniversalObject addMetadataKey:@"custom_key1" value:@"some custom data"];
    [self.branchUniversalObject //自定义keyaddMetadataKey:@"custom_key2" value:@"more custom data"];
    
    LKMELinkProperties *linkProperties = [[LKMELinkProperties alloc] init];
    linkProperties.feature = @"wechat";
    linkProperties.channel = @"wechat";//渠道
    linkProperties.tags=@[@"111211",@"12333"];//标签
    linkProperties.alias = @"jump";//别名
    linkProperties.stage = @"normal";//阶段
    
    [linkProperties addControlParam:@"$desktop_url" withValue:@"http://example.com/home"];
    [linkProperties addControlParam:@"$ios_url" withValue:@"http://example.com/ios"];
    
        [linkProperties setAndroidPathControlParam:@"feature"];
        [linkProperties setIOSKeyControlParam:@"feature"];

    [self.branchUniversalObject getShortUrlWithLinkProperties:linkProperties andCallback:^(NSString *url, NSError *err) {
        //  这里的url就是得到的短链 
        if (err == nil) {
            NSLog(@"LinkedMe SDK creates the url is:%@", url);
            LINKEDME_SHORT_URL = [H5_URL stringByAppendingString:url];
        } else {
            LINKEDME_SHORT_URL = H5_URL;
        }
    }]; 
}
```
#Debug模式
# 5实现自定义跳转方法（传参）
![reg view0](http://7xq8b0.com1.z0.glb.clouddn.com/deeplinking.png)
![reg view](http://7xq8b0.com1.z0.glb.clouddn.com/mothed.png)






## License

LinkedME_iOS is available under the MIT license. See the LICENSE file for more info.


