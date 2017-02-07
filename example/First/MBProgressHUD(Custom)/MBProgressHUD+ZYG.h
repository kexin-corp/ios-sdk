//
//  MBProgressHUD.h
//  text1
//
//  Created by 张运国 on 15/12/8.
//  Copyright © 2015年 张运国. All rights reserved.
//

#import "MBProgressHUD.h"
@interface MBProgressHUD(ZYG)

+ (void)showSuccess:(NSString *)success toView:(UIView *)view;
+ (void)showSuccess:(NSString *)success;

+ (MBProgressHUD *)showMessage:(NSString *)message toView:(UIView *)view;
+ (MBProgressHUD *)showMessage:(NSString *)message;
+ (void)showToast:(NSString *)message toView:(UIView *)view;

+ (void)showError:(NSString *)error toView:(UIView *)view;
+ (void)showError:(NSString *)error;

+ (void)hideHUDForView:(UIView *)view;
+ (void)hideHUD;

@end
