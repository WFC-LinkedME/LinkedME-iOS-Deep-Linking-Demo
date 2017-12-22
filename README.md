#LinkedME iOS 集成文档

[![CI Status](http://img.shields.io/travis/Bindx/LinkedME_iOS.svg?style=flat)](https://travis-ci.org/Bindx/LinkedME_iOS)
[![Version](https://img.shields.io/cocoapods/v/LinkedME_iOS.svg?style=flat)](http://cocoapods.org/pods/LinkedME_iOS)
[![License](https://img.shields.io/cocoapods/l/LinkedME_iOS.svg?style=flat)](http://cocoapods.org/pods/LinkedME_iOS)
[![Platform](https://img.shields.io/cocoapods/p/LinkedME_iOS.svg?style=flat)](http://cocoapods.org/pods/LinkedME_iOS)

[进入官网查看详细文档](http://linkedme.cc/docs/page4.html#link0)

#接入方法

##使用 CocoaPods

1.编辑Podfile文件并添加以下代码

```
pod 'LinkedME_LinkPage'
```
2.运行 pod install

3.从现在开始使用 .xcworkspace 打开项目，而不是 .xcodeproj

##手动导入
1.获取SDK,下载Demo, LinkedME_DEMO文件夹下的LinkedME_iOS.framework文件是SDK的文件。（[SDK下载地址](https://github.com/WFC-LinkedME/LinkedME-iOS-Deep-Linking-Demo/raw/master/LinkedME_Lib.zip)）

2.依赖Frameworks:

`CoreSpotlight.framework (status:Optional)`
`SystemConfiguration.framework`
`Security.framework`
`AdSupport.framework`
`CoreTelephony.framework`

**注意事项:CoreSpotlight.framework必须标记为可选**
	**[导入AdSupport.frame但是app中没有广告审核问题](https://github.com/WFC-LinkedME/LinkedME-iOS-Deep-Linking-Demo/blob/master/IDFA_Audit.md)**
![spotlight warning](http://7xq8b0.com1.z0.glb.clouddn.com/spotlight1.png)


# 1.注册并添加应用
##1.1注册账号
LinkedME账号通用于我们提供的所有产品，登录官方网站进行[注册](http://linkedme.cc/),并登陆系统。

##1.2 开通使用
注册成功之后，即可登录使用。

##1.3 创建应用
>成功登录后台之后，可点击`+`按钮创建应用。
![创建app](https://www.linkedme.cc/docs/images/2.2.1-1.jpg)

输入APP名字之后，点击“创建APP”完成创建。可以到后台导航栏`设置`->`应用`中查看应用相关信息。
![创建app](https://www.linkedme.cc/docs/images/2.2.1-2.jpg)

##1.4 应用设置
点击`设置`可以对应用进行设置。
![设置app](https://www.linkedme.cc/docs/images/2.3.1.jpg)

`1` 点击修改应用名字

`2` 点击修改应用Logo

`3` 点击删除应用

>注意事项：如果误删应用后，请发邮件到support@linkedme.cc。

## 1.5 设置应用
![设置应用](https://www.linkedme.cc/docs/images/2.3.2.1-1.jpg)

`1` 勾选“是否有iOS应用”项。

`2` URI Scheme，点击输入框输入您的iOS应用的URI Scheme协议，示例：linkedmedemo

`3` 下载地址，可以是AppStore上的下载地址，也可以自定义

`4` Universal Links为iOS官方深度链接标准，iOS 9.0以上系统支持，可实现应用间无缝跳转。[访问苹果开发者网站](http://developer.apple.com/)，在Appid中查看Bundle ID和Prefix的值

![bundle id](http://7xq8b0.com1.z0.glb.clouddn.com/appid.png)


# 2.1 SDK&Demo（简述）

文件名 | 描述
------------ | -------------
LinkedME_iOS.framework | LinkedME SDK
DetailViewController | Demo详情页-webView加载html网页 
DemoViewController | 生成短链，展示生成锻炼的必要参数 
DefaultData | 参数默认必要参数 


#3.导入LinkedME iOS SDK(必须实现)*

把Demo工程中的LinkedME_iOS.framework，导入工程中。

#4. 添加系统Framework*

`1`  CoreSpotlight.framework (status:Optional)

`2`  SystemConfiguration.framework

`3`  Security.framework
	
**注意事项:CoreSpotlight.framework必须标记为可选**	
![spotlight warning](http://7xq8b0.com1.z0.glb.clouddn.com/spotlight1.png)

#5.注册URL Scheme（推荐/可选）

`1` 打开info.plist

`2` 找到URL Types（如果没有就右键add row添加一个）

`3` 添加"you app"(你的app的唯一标识字符串)
![urltypes set up](http://7xq8b0.com1.z0.glb.clouddn.com/url_scheme.jpg)

#5.1 添加Universal Linking支持 (仅支持iOS 9)*
`1` 在左侧导航器中点击您的项目

`2` 选择'Capabilities'标签

`3` 打开'Associated Domains'开关

`4` 添加applinks:lkme.cc和applinks:www\.lkme\.cc
![Associated Domains set up](http://7xq8b0.com1.z0.glb.clouddn.com/universal_link.jpg)
	


## 5.2 添加linkedme_key
`1` 打开info.plist文件

`2` 在列表中点击右键选择add row添加一个分组

`3` 创建一个新的item名称为linkedme_key类型为Dictionary

`4` 在linkedme_key新增一个字符串类型的item, live字段，到后台“设置”->“应用”中进行[查看](http://linkedme.cc/dashboard/index.html#/app/changeapp)

![lmkey set up](http://7xq8b0.com1.z0.glb.clouddn.com/keyyy.png)

# 6.代码集成 - 设置AppDelegate - 解析深度链接跳转参数*

`1` 在AppDelegate中引入头文件
> `import <LinkedME_iOS/LinkedME.h>`

`2` 在Appdelegate里注册ViewController

####　6.1配置注册viewController并设置跳转方式

```objc
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.'
    //初始化及实例
    LinkedME* linkedme = [LinkedME getInstance];
    
    //    //注册需要跳转的viewController
    UIStoryboard * storyBoard=[UIStoryboard storyboardWithName:@"Main" bundle:[NSBundle mainBundle]];
    DetailViewController  *dvc=[storyBoard instantiateViewControllerWithIdentifier:@"detailView"];
    
    //[自动跳转]如果使用自动跳转需要注册viewController
    //    [linkedme registerDeepLinkController:featureVC forKey:@"LMFeatureViewController"];
    
    //获取跳转参数
    [linkedme initSessionWithLaunchOptions:launchOptions automaticallyDisplayDeepLinkController:NO deepLinkHandler:^(NSDictionary* params, NSError* error) {
        if (!error) {
            //防止传递参数出错取不到数据,导致App崩溃这里一定要用try catch
            @try {
            NSLog(@"LinkedME finished init with params = %@",[params description]);
            //获取标题
            NSString *title = [params objectForKey:@"$og_title"];
            NSString *tag = params[@"$control"][@"View"];
                
                if (title.length >0 && tag.length >0) {
                    
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
////
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
```

### Swift
`1` xxxx-Bridging-Header.h中导入头文件
`#import <LinkedME_iOS/LinkedME.h>`

`2` 在Appdelegate里注册ViewController
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

# 7.添加URLScheme和Uniiversal LinKing支持
####　在Appdelegate中实现下列方法
###OC

```objc
- (BOOL)application:(UIApplication*)application openURL:(NSURL*)url sourceApplication:(NSString*)sourceApplication annotation:(id)annotation{
    //判断是否是通过LinkedME的UrlScheme唤起App
    if ([[url description] rangeOfString:@"click_id"].location != NSNotFound) {
        return [[LinkedME getInstance] handleDeepLink:url];
    }
    
    return YES;
}
```
	
```objc
//Universal Links 通用链接实现深度链接技术
- (BOOL)application:(UIApplication*)application continueUserActivity:(NSUserActivity*)userActivity restorationHandler:(void (^)(NSArray*))restorationHandler{
    
    //判断是否是通过LinkedME的Universal Links唤起App
    if ([[userActivity.webpageURL description] rangeOfString:@"lkme.cc"].location != NSNotFound) {
        return  [[LinkedME getInstance] continueUserActivity:userActivity];
    }
    
    return YES;
}
```
	
```objc
//URI Scheme 实现深度链接技术
- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<NSString*, id> *)options{
    NSLog(@"opened app from URL %@", [url description]);
    
    //判断是否是通过LinkedME的UrlScheme唤起App
    if ([[url description] rangeOfString:@"click_id"].location != NSNotFound) {
        return [[LinkedME getInstance] handleDeepLink:url];
    }
    return YES;
}
```

###Swift

```swift
//URI Scheme 实现深度链接技术
 func application(application: UIApplication, openURL url: NSURL, sourceApplication: String?, annotation: AnyObject) -> Bool {
    //判断是否是通过LinkedME的UrlScheme唤起App
        if url.absoluteString.componentsSeparatedByString("click_id").count > 1 {
            return LinkedME.getInstance().handleDeepLink(url);
        }

    }
```
	
```swift
 //Universal Links 通用链接实现深度链接技术
    func application(application: UIApplication, continueUserActivity userActivity: NSUserActivity, restorationHandler: ([AnyObject]?) -> Void) -> Bool {
        //判断是否是通过LinkedME的Universal Links唤起App
        if url.absoluteString.componentsSeparatedByString("lkme.cc").count > 1 {
            return LinkedME.getInstance().continueUserActivity(userActivity);
        }
    }
```
	
```swift
    //URI Scheme 实现深度链接技术
    func  application(app: UIApplication, openURL url: NSURL, options: [String : AnyObject]) -> Bool {
        //判断是否是通过LinkedME的UrlScheme唤起App
        if url.absoluteString.componentsSeparatedByString("click_id").count > 1 {
            return LinkedME.getInstance().handleDeepLink(url);
        }
    }
```
	
# 创建深度连接
>创建深度链接提供两种方式

`1` 使用iOS/[Android SDK](https://github.com/WFC-LinkedME/LinkedME-Android-Deep-Linking-Demo)创建
`2` 使用[WEB SDK](https://www.linkedme.cc/docs/page4.html#link2)创建

**注：附录中详解采用哪种方式创建深度链接**


```objc
//创建短链
-(void)addPara{
    self.linkedUniversalObject = [[LMUniversalObject alloc] init];
    self.linkedUniversalObject.title = title;//标题
    LMLinkProperties *linkProperties = [[LMLinkProperties alloc] init];
    linkProperties.channel = @"";//渠道(微信,微博,QQ,等...)
    linkProperties.feature = @"Share Wechat1";//特点
    linkProperties.tags=@[@"LinkedME",@"Demo"];//标签
    linkProperties.stage = @"Live";//阶段

    [linkProperties addControlParam:@"View" withValue:arr[page][@"url"]];//页面唯一标识
    [linkProperties addControlParam:@"LinkedME" withValue:@"Demo"];//Demo标识
    
    [self.linkedUniversalObject getShortUrlWithLinkProperties:linkProperties andCallback:^(NSString *url, NSError *err) {
        if (url) {
            NSLog(@"[LinkedME Info] SDK creates the url is:%@", url);
            //
            [H5_LIVE_URL stringByAppendingString:arr[page][@"form"]];
            [H5_LIVE_URL stringByAppendingString:@"?linkedme="];
            
            H5_LIVE_URL = [NSString stringWithFormat:@"https://www.linkedme.cc/h5/%@?linkedme=",arr[page][@"form"]];
            _LINKEDME_SHORT_URL = [H5_LIVE_URL stringByAppendingString:url];
            
        } else {
            _LINKEDME_SHORT_URL = H5_LIVE_URL;
        }
    }];
}
```
#Debug模式
>在Debug模式下会打印日志

##OC
  [linkedme setDebug];

##Swift
  linkedme.setDebug();
  
  
#测试模式
>在后台(Dashboard)中-设置-测试-添加测试设备

##OC
通过[LinkedME getTestID]获取设备ID,去后台中添加设备

##Swift
通过LinkedME.getTestID()获取设备ID,去后台中添加设备

# 6.Spotlight

##6.1创建Spotlight索引
>OC

```objc
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
```

>Swift

```swift
	LinkedME.getInstance().createDiscoverableContentWithTitle("LinkedME 国内第一家企业级深度链接",
                                                                  description: "让APP不再是信息孤岛!",
                                                                  thumbnailUrl: NSURL.init(string: "http://7xq8b0.com1.z0.glb.clouddn.com/logo.png"),
                                                                  linkParams: dic,
                                                                  type: nil,
                                                                  publiclyIndexable: false,
                                                                  keywords: keyWord as NSSet as Set<NSObject>,
                                                                  expirationDate: nil,
                                                                  spotlightIdentifier: "linkedme") { (url, spotlightID, error) in
                                                                    
        }
```

`设置关键字`
 
>OC

```objc
    NSSet *keyWord = [NSSet setWithObjects:@"linkedme", nil];
```
>Swift

```swift
	let keyWord = NSSet.init(array: ["linkedme","hellolkm"])
```


`需要传递的参数`



>OC

```objc
	NSSet *set5 = [NSSet 	setWithObjects:@"linkedme",@"linked",@"深度链接", nil];
```
>Swift

```swift
	let dic = ["url":"http://linkedme.cc"]
```

>关键字详解

| title  | 标题 
| --- | --- | 
| description | 描述 
|publiclyIndexable| 是否公开
|type             | 类型
|thumbnailUrl     | 缩略图Url
|keywords         | 关键字
|userInfo         | 用户详情
|expirationDate   | 失效日期,设置失效日期会自动删除索引
|identifier       | 标志符
|callback         | 回调
|spotlightCallback| Spotlight回掉

##6.2删除索引

###6.2.1删除所有索引

#### OC

```objc

[LinkedME removeAllSearchItems];
```

#### Swift

```swift   
     LinkedME.removeAllSearchItems();
```

###6.2.2通过spotlightIdentifier删除索引

#### OC

```objc

[LinkedME removeSearchItemWith:@[@"linkedme"]];
```

#### Swift

```swift 

LinkedME.removeSearchItemWith(["linkedme"])
```


#附录：
## 1.实现SDK提供的跳转方法（传参）
![reg view0](http://7xq8b0.com1.z0.glb.clouddn.com/deeplinking.png)
![reg view](http://7xq8b0.com1.z0.glb.clouddn.com/mothed.png )

## 2.什么时候使用WEB SDK 创建深度链接

>使用WEB SDK生成深度链接

如下图这种类型有自己的wap站同时有自己的app并且wap站和app的所有页面都是一一对应的，一般如（新闻资讯类，电商类，直播类等），这种方式的app我们建议使用WEB SDK(js)生产深度链接,客户端仅用于解析深度链接。
注：（也可以使用iOS/Android SDK生成深度链接）

![ctoutiao](http://7xq8b0.com1.z0.glb.clouddn.com/ctoutiao1.jpg)


## 3.什么时候使用iOS/Android SDK 创建深度链接

>使用iOS/Android SDK生成深度链接

如下图这种类型，一般是分享活动或者一个游戏房间号，一般没有wap站点的app采用这种方式生成深度链接，再通过js把深度链接放到打开按钮下。

![invate](http://7xq8b0.com1.z0.glb.clouddn.com/invate1.jpg)



## 常见问题

![YOU+](http://7xq8b0.com1.z0.glb.clouddn.com/you1+.jpg)

|  | 常见问题 | 
| --- | --- | 
|`Q:`|为什么点击按钮可以直接从微信唤起app？|
|`A:`| 使用Universal Link技术，可以通过链接直接唤起app。|  
||
|`Q:`|为什么右上角会出现lkme.cc？|
|`A:`|因为使用了苹果的Universal Link技术打开App。|
||
|`Q:`|可以取消显示么？|
|`A:`|不可以，因为这是系统级的，无法控制。|
||
|`Q:`|点击了右上角的lkme.cc为什么出现了下拉点击打开的提示？|
|`A:`|当用户点击lkme.cc会在safari中打开链接，如果不点击`打开`按钮Universal Link会失效，只有再次点击`打开`按钮，Universal Link才会恢复。|
||
|`Q:`|如果用户没有安装app会怎么样？|
|`A:`|点击`前往App store下载`下载完成后，打开app会跳转到当前分享页面。|
||
|`Q:`|如果没有点击`前往App store下载`自己去App store搜索下载，下载完成后可以跳转到分享页吗？|
|`A:`|不可以，只有点击`前往App store下载`按钮才会记录浏览器指纹信息，用于匹配跳转指定页，如果没有点击按钮就不会记录信息。|


## License

LinkedME_iOS is available under the MIT license. See the LICENSE file for more info.


