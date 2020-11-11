
#if __has_feature(modules)
@import Foundation;
#else
#import <Foundation/Foundation.h>
#endif

@interface LMApplication : NSObject

+ (void)loadCurrentApplicationWithCompletion:(void (^_Nullable)(LMApplication * _Nonnull application))completion;

/// A reference to the current running application.
+ (LMApplication*_Nonnull) currentApplication;

/// 当前的bundle标识符
@property (atomic, readonly) NSString*_Nullable bundleID;

/// info plist中显示名称。
@property (atomic, readonly) NSString*_Nullable displayName;

/// The bundle short display name from the info plist.
@property (atomic, readonly) NSString*_Nullable shortDisplayName;

/// 简短的ID通常显示给用户，比如在iTunes或app store。
@property (atomic, readonly) NSString*_Nullable displayVersionString;

/// 供开发人员使用的版本ID。
@property (atomic, readonly) NSString*_Nullable versionString;

/// 当前可执行文件的创建日期。
@property (atomic, readonly) NSDate*_Nullable currentBuildDate;


@property (atomic, readonly) NSDate*_Nullable firstInstallBuildDate;

/// 这个应用程序安装在这个设备上的日期。
@property (atomic, readonly) NSDate*_Nullable currentInstallDate;

/// 这个应用程序第一次安装在这个设备上的日期。
@property (atomic, readonly) NSDate*_Nullable firstInstallDate;

/// 返回设备/标识对的字典。
@property (atomic, readonly) NSDictionary<NSString*, NSString*>*_Nonnull deviceKeyIdentityValueDictionary;

/// 返回teamID（Prefix）
@property (atomic, readonly) NSString*_Nullable teamID;

@end
