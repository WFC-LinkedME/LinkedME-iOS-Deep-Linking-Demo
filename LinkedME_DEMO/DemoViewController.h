//
//  DemoViewController.h
//  LinkedME_DEMO
//
//  Created by LinkedME04 on 6/7/16.
//  Copyright © 2016 Bindx. All rights reserved.
//

#import <UIKit/UIKit.h>
//#import <LinkedME_iOS/LMDeepLinkingController.h>
#import <LinkedME_iOS/LMDeepLinkingController.h>


@interface DemoViewController : UIViewController

@property (weak, nonatomic) IBOutlet UITextField *url;

@property (weak, nonatomic) IBOutlet UIButton *btn;

@property (weak, nonatomic) IBOutlet UITextView *textView;
@property (weak, nonatomic) IBOutlet UIButton *testID;

@property (weak, nonatomic) IBOutlet UIButton *btnTitle;

@property (weak, nonatomic) IBOutlet UITextField *function;
@property (weak, nonatomic) IBOutlet UITextField *activity;
@property (weak, nonatomic) IBOutlet UITextField *live;
@property (weak, nonatomic) IBOutlet UITextField *channel;
@property (weak, nonatomic) IBOutlet UITextField *tag;


@property (weak, nonatomic) IBOutlet UITextField *key_1;
@property (weak, nonatomic) IBOutlet UITextField *key_2;
@property (weak, nonatomic) IBOutlet UITextField *key_3;

@property (weak, nonatomic) IBOutlet UITextField *value_1;
@property (weak, nonatomic) IBOutlet UITextField *value_2;
@property (weak, nonatomic) IBOutlet UITextField *value_3;





@end
