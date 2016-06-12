//
//  LMStrongMatchHelper.h
//  iOS-Deep-Linking-SDK
//
//  Created by han on 8/26/15.
//  Copyright © 2015 LM han. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface LMStrongMatchHelper : NSObject

+ (LMStrongMatchHelper *)strongMatchHelper;
- (void)createStrongMatchWithBranchKey:(NSString *)branchKey;
- (BOOL)shouldDelayInstallRequest;

@end
