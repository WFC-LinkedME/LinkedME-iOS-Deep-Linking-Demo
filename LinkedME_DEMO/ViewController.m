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

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.   
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
