//
//  FaLockHttpTool.h
//  FaLockSDK
//
//  Created by kexin on 16/11/16.
//  Copyright © 2016年 KeXin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FaLockCallback.h"

@interface FaLockHttpTool : NSObject

// 是否打印日志，默认1：打印 ，0：不打印
#define KX_IS_SHOW_LOG 0

// 是否为Debug模式、1为测试服 0为正式服、需传入 URLString DevString
#define KX_IS_Debug 0

// 是否为第三方使用的SDK、区分提供给别人的SDK还是自己使用
#define KX_IS_Self 0

#define KUserToken                      @"/account/token/update"        // 更新token
#define KLockMemberList                 @"/lock/member/list"            // 锁用户列表
#define KLockOpen                       @"/lock/pwd/get"                // 开锁
#define KLockOpenResult                 @"/lock/open/result"            // 上报开锁结果
#define KLockGetInfo                    @"/lock/get"                    // 获取锁信息
#define KLockInit                       @"/lock/init"                   // 初始化锁
#define KLockTimeUpdate                 @"/lock/time_sync/seq/get"      // 时间同步
#define KLockUpdateResult               @"/lock/time_sync/result"       // 上报时间同步
#define KLockUpdateInfo                 @"/lock/update"                 // 修改锁信息
#define KUserFaceIdentify               @"/face/identity"               // 人脸识别，需要名称、身份证、拍照图像

/**
 * 单例模式
 */
+ (instancetype)shareTool;

/**
 * 获取token，需要传入
 */
@property (nonatomic, copy) NSString *token;

/**
 * 获取appid，需要传入
 */
@property (nonatomic, copy) NSString *appid;

/**
 * 获取正式服URL，需要传入
 */
@property (nonatomic, copy) NSString *URLString;

/**
 * 获取测试服URL，需要传入
 */
@property (nonatomic, copy) NSString *DevString;

/**
 *  普通post方法请求网络数据
 *
 *  @param url     请求网址路径
 *  @param params  请求参数
 *  @param block   回调
 */
- (void)POST:(NSString *)url params:(NSMutableDictionary *)params HttpFinish:(HttpFinishBlock)block Log:(BOOL)log;

/**
 *  post方法请求网络数据
 *
 *  @param url     请求网址路径
 *  @param params  请求参数、需要签名
 *  @param extra   请求参数、不需要签名
 *  @param block   回调
 */
- (void)POST:(NSString *)url params:(NSMutableDictionary *)params extra:(NSMutableDictionary *)extra HttpFinish:(HttpFinishBlock)block Log:(BOOL)log;

@end
