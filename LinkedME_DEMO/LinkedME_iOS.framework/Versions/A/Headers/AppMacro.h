//
//  AppMacro.h
//  GCD
//
//  Created by apple on 5/23/14.
//  Copyright (c) 2015 apple. All rights reserved.
//


//------------------获取设备标示------------------------
#define MAC [NSString macaddress]
#define ApplicationDelegate                 ((AppDelegate *)[[UIApplication sharedApplication] delegate])
#define AppVersion [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]
#define idfaString [[[UIDevice currentDevice] systemVersion] floatValue]>=6.0000?[[[ASIdentifierManager sharedManager] advertisingIdentifier] UUIDString]:@""//IDFA
#define idfvString [[[UIDevice currentDevice] identifierForVendor] UUIDString]//IDFV

//坐标
#define UserDefaults                        [NSUserDefaults standardUserDefaults]
#define NavBarHeight                        self.navigationController.navigationBar.bounds.size.height
#define TabBarHeight                        self.tabBarController.tabBar.bounds.size.height
#define ScreenWidth                         [[UIScreen mainScreen] bounds].size.width
#define ScreenHeight                        [[UIScreen mainScreen] bounds].size.height
#define ViewWidth(v)                        v.frame.size.width
#define ViewHeight(v)                       v.frame.size.height
#define ViewX(v)                            v.frame.origin.x
#define ViewY(v)                            v.frame.origin.y
#define SelfViewWidth                       self.view.bounds.size.width
#define SelfViewHeight                      self.view.bounds.size.height
#define RectX(f)                            f.origin.x
#define RectY(f)                            f.origin.y
#define RectWidth(f)                        f.size.width
#define RectHeight(f)                       f.size.height
#define RectSetWidth(f, w)                  CGRectMake(RectX(f), RectY(f), w, RectHeight(f))
#define RectSetHeight(f, h)                 CGRectMake(RectX(f), RectY(f), RectWidth(f), h)
#define RectSetX(f, x)                      CGRectMake(x, RectY(f), RectWidth(f), RectHeight(f))
#define RectSetY(f, y)                      CGRectMake(RectX(f), y, RectWidth(f), RectHeight(f))
#define RectSetSize(f, w, h)                CGRectMake(RectX(f), RectY(f), w, h)
#define RectSetOrigin(f, x, y)              CGRectMake(x, y, RectWidth(f), RectHeight(f))

//-------------------获取设备大小-------------------------
//NavBar高度
#define NavigationBar_HEIGHT 44

//获取屏幕 宽度、高度
#define SCREEN_WIDTH ([UIScreen mainScreen].bounds.size.width)
#define SCREEN_HEIGHT ([UIScreen mainScreen].bounds.size.height)

#define ICON_SIZE 40

#define BOUNDS CGRectMake(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT-64)

#define LSCAPE CGRectMake(0, 0, SCREEN_HEIGHT,SCREEN_WIDTH-44)

#define BGBOUNDS CGRectMake(0, 0, SCREEN_HEIGHT, SCREEN_WIDTH)

#define DETAILVIEWH CGRectMake((SCREEN_WIDTH-287)/2, 30, SCREEN_WIDTH-40, 300)
#define DETAILVIEWO CGRectMake((SCREEN_WIDTH-287)/2, 50, SCREEN_WIDTH-40, 300)
#define DETAILVIEWW CGRectMake((SCREEN_HEIGHT-287)/2, 5, SCREEN_WIDTH-40, 300)
//释放一个对象
#define SAFE_RELEASE(x) [x release];x=nil
//----------------------系统----------------------------
//获取系统版本
#define IOS_VERSION [[[UIDevice currentDevice] systemVersion] floatValue]
#define CurrentSystemVersion ([[UIDevice currentDevice] systemVersion])

#define IS_IOS_8  (([[[UIDevice currentDevice] systemVersion] floatValue]>=8.0)?YES:NO)
#define IS_IOS_7  (([[[UIDevice currentDevice] systemVersion] floatValue]>=7.0)?YES:NO)
#define IS_IOS_6  (([[[UIDevice currentDevice] systemVersion] floatValue]<=6.0)?YES:NO)
#define IS_IOS6UP (([[[UIDevice currentDevice] systemVersion] floatValue]>=6.0)?YES:NO)

//获取当前语言  
#define CurrentLanguage ([[NSLocale preferredLanguages] objectAtIndex:0])

#define BACKGROUND_COLOR [UIColor colorWithRed:242.0/255.0 green:236.0/255.0 blue:231.0/255.0 alpha:1.0]


#define AppWindow [[UIApplication sharedApplication].delegate window]
//使用网络日志本打印在调试模式
#ifdef DEBUG
#   define DLog(fmt, ...) NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
#   define DLog(...)
#endif


//判断是否 Retina屏、设备是否%fhone 5、是否是iPad
#define isRetina ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 960), [[UIScreen mainScreen] currentMode].size) : NO)
#define iPhone5 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size) : NO)
#define isPad (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)


//判断是真机还是模拟器
#if TARGET_OS_IPHONE
//iPhone Device
#endif

#if TARGET_IPHONE_SIMULATOR
//iPhone Simulator
#endif


//----------------------内存----------------------------
//ARC OR without ARC
#if __has_feature(objc_arc)
//compiling with ARC

#else
// compiling without ARC

//UIAlertView
#define alertContent(mytitle,content,cancelButton,otherButton) \
UIAlertView *alert = [[UIAlertView alloc] initWithTitle:mytitle \
message:content \
delegate:nil   \
cancelButtonTitle:cancelButton \
otherButtonTitles:otherButton,nil];  \
[alert show];  \
[alert release];
#endif


//设备唯一标识
#define idfaString [[[UIDevice currentDevice] systemVersion] floatValue]>=6.0000?[[[ASIdentifierManager sharedManager] advertisingIdentifier] UUIDString]:@""//IDFA
#define idfvString [[[UIDevice currentDevice] identifierForVendor] UUIDString]//IDFV

//G－C－D
#define BACK(block) dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), block)
#define MAIN(block) dispatch_async(dispatch_get_main_queue(),block)

//UserDefaults
#define USER_DEFAULT [NSUserDefaults standardUserDefaults]

//----------------------图片----------------------------

#define ImageNamed(_pointer) [UIImage imageNamed:[UIUtil imageName:_pointer]]

#define BundleImage(imageNamed) [[[NSBundle mainBundle] resourcePath] stringByAppendingPathComponent: [NSString stringWithFormat:@"OWS.bundle/%@",imageNamed]]

//读取本地图片,例如 imageView.image =  LOADIMAGE(@"文件名",@"png");
#define LOADIMAGE(file,ext) [UIImage imageWithContentsOfFile:[[NSBundle mainBundle]pathForResource:file ofType:ext]]

//定义UIImage对象
#define IMAGE(A) [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:A ofType:nil]]

//定义UIImage对象
#define ImageNamed(_pointer) [UIImage imageNamed:[UIUtil imageName:_pointer]]

//建议使用前两种宏定义,性能高于后者

#pragma mark - common functions
#define RELEASE_SAFELY(__POINTER) { [__POINTER release]; __POINTER = nil; }

// StringWithFormatx
#define F(string, args...)                  [NSString stringWithFormat:string, args]

/*
 MyLocal(@"0094")代替了
 NSLocalizedString(@"0094", nil) */
#define MyLocal(x, ...) NSLocalizedString(x, nil)

#pragma mark - degrees/radian functions
#define degreesToRadian(x) (M_PI * (x) / 180.0)
#define radianToDegrees(radian) (radian*180.0)/(M_PI)

#pragma mark - color functions
#define RGBCOLOR(r,g,b) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:1]
// 获取RGB颜色
#define RGBACOLOR(r,g,b,a) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:(a)]
#define ITTDEBUG
#define ITTLOGLEVEL_INFO     10
#define ITTLOGLEVEL_WARNING  3
#define ITTLOGLEVEL_ERROR    1

#ifndef ITTMAXLOGLEVEL

#ifdef DEBUG
#define ITTMAXLOGLEVEL ITTLOGLEVEL_INFO
#else
#define ITTMAXLOGLEVEL ITTLOGLEVEL_ERROR
#endif

#endif

// 通用的日志记录器。忽略了日志级别。
#ifdef ITTDEBUG
#define ITTDPRINT(xx, ...)  NSLog(@"%s(%d): " xx, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)
#else
#define ITTDPRINT(xx, ...)  ((void)0)
#endif

// 打印当前方法名
#define ITTDPRINTMETHODNAME() ITTDPRINT(@"%s", __PRETTY_FUNCTION__)

// 日志记录
#if ITTLOGLEVEL_ERROR <= ITTMAXLOGLEVEL
#define ITTDERROR(xx, ...)  ITTDPRINT(xx, ##__VA_ARGS__)
#else
#define ITTDERROR(xx, ...)  ((void)0)
#endif

#if ITTLOGLEVEL_WARNING <= ITTMAXLOGLEVEL
#define ITTDWARNING(xx, ...)  ITTDPRINT(xx, ##__VA_ARGS__)
#else
#define ITTDWARNING(xx, ...)  ((void)0)
#endif

#if ITTLOGLEVEL_INFO <= ITTMAXLOGLEVEL
#define ITTDINFO(xx, ...)  ITTDPRINT(xx, ##__VA_ARGS__)
#else
#define ITTDINFO(xx, ...)  ((void)0)
#endif

#ifdef ITTDEBUG
#define ITTDCONDITIONLOG(condition, xx, ...) { if ((condition)) { \
ITTDPRINT(xx, ##__VA_ARGS__); \
} \
} ((void)0)
#else
#define ITTDCONDITIONLOG(condition, xx, ...) ((void)0)
#endif

#define ITTAssert(condition, ...)                                       \
do {                                                                      \
if (!(condition)) {                                                     \
[[NSAssertionHandler currentHandler]                                  \
handleFailureInFunction:[NSString stringWithUTF8String:__PRETTY_FUNCTION__] \
file:[NSString stringWithUTF8String:__FILE__]  \
lineNumber:__LINE__                                  \
description:__VA_ARGS__];                             \
}                                                                       \
} while(0)

#define _po(o) DLOG(@"%@", (o))
#define _pn(o) DLOG(@"%d", (o))
#define _pf(o) DLOG(@"%f", (o))
#define _ps(o) DLOG(@"CGSize: {%.0f, %.0f}", (o).width, (o).height)
#define _pr(o) DLOG(@"NSRect: {{%.0f, %.0f}, {%.0f, %.0f}}", (o).origin.x, (o).origin.x, (o).size.width, (o).size.height)

#define DOBJ(obj)  DLOG(@"%s: %@", #obj, [(obj) description])

#define MARK    NSLog(@"\nMARK: %s, %d", __PRETTY_FUNCTION__, __LINE__)

//-------------------打印日志-------------------------
//重写NSLog,Debug模式下打印日志和当前行数
#if DEBUG
#define NSLog(FORMAT, ...) fprintf(stderr,"\nfunction:%s line:%d content:%s\n", __FUNCTION__, __LINE__, [[NSString stringWithFormat:FORMAT, ##__VA_ARGS__] UTF8String]);
#else
#define NSLog(FORMAT, ...) nil
#endif

#if __IPHONE_6_0 // iOS6 and later

#define UITextAlignment                 NSTextAlignment
#define UITextAlignmentCenter           NSTextAlignmentCenter
#define UITextAlignmentLeft             NSTextAlignmentLeft
#define UITextAlignmentRight            NSTextAlignmentRight

#define UILineBreakByWordWrapping       NSLineBreakByWordWrapping
#define UILineBreakByCharWrapping       NSLineBreakByCharWrapping
#define UILineBreakByClipping           NSLineBreakByClipping
#define UILineBreakByTruncatingHead     NSLineBreakByTruncatingHead
#define UILineBreakByTruncatingTail     NSLineBreakByTruncatingTail
#define UILineBreakByTruncatingMiddle   NSLineBreakByTruncatingMiddle
#define UILineBreakMode                 NSLineBreakMode

//----------------------------Xib---------------------------
#define NibBundle(Resource) [NSBundle bundleWithPath:[[NSBundle mainBundle]pathForResource:Resource ofType:@"bundle"]]

//----------------------------GCD----------------------------
//在Main线程上运行
#define DISPATCH_ON_MAIN_THREAD(mainQueueBlock) dispatch_async(dispatch_get_main_queue(), mainQueueBlock);

//在Global Queue上运行
#define DISPATCH_ON_GLOBAL_QUEUE_HIGH(globalQueueBlocl) dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0), globalQueueBlocl);
#define DISPATCH_ON_GLOBAL_QUEUE_DEFAULT(globalQueueBlocl) dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), globalQueueBlocl);
#define DISPATCH_ON_GLOBAL_QUEUE_LOW(globalQueueBlocl) dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_LOW, 0), globalQueueBlocl);
#define DISPATCH_ON_GLOBAL_QUEUE_BACKGROUND(globalQueueBlocl) dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_BACKGROUND, 0), globalQueueBlocl);


//---------------------------通知----------------------------
#define NotiPost(NotificationName,obj) [[NSNotificationCenter defaultCenter]postNotificationName:NotificationName object:obj]
#define Notiadd(Observer,SEL,notiName,obj) [[NSNotificationCenter defaultCenter]addObserver:Observer selector:SEL name:notiName object:obj]

#define SuppressPerformSelectorLeakWarning(Stuff) \
do { \
    _Pragma("clang diagnostic push") \
    _Pragma("clang diagnostic ignored \"-Warc-performSelector-leaks\"") \
    Stuff; \
    _Pragma("clang diagnostic pop") \
} while (0)

#define TT_FIX_CATEGORY_BUG(name) @interface TT_FIX_CATEGORY_BUG_##name @end \
@implementation TT_FIX_CATEGORY_BUG_##name @end


#endif
