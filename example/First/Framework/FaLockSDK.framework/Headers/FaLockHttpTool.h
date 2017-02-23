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

// 是否为Debug模式、区分内外网
#define KX_IS_Debug 0

// 是否为第三方使用的SDK、区分提供给别人的SDK还是自己使用
#define KX_IS_Self 0

#define KUserToken                      @"/account/token/update"        // 更新token
#define KUserLogin                      @"/account/login"               // 登录
#define KUserVerify                     @"/account/captcha/get"         // 获取验证码
#define KUserLockList                   @"/v2/user/lock/list"           // 用户锁列表
#define KUserRegister                   @"/account/register"            // 用户注册
#define KUserForgetPwd                  @"/account/pwd/retrieve"        // 忘记密码
#define KUserTelUpdate                  @"/account/tel/update"          // 修改手机号
#define KUserBindLock                   @"/lock/bind"                   // 用户绑定锁
#define KUserUnBindLock                 @"/lock/unbind"                 // 用户解绑锁
#define KUserAddLockMember              @"/lock/member/add"             // 添加锁成员
#define KUserDeleteLockMember           @"/lock/member/delete"          // 删除锁成员
#define KUserUpdateUserName             @"/account/user_name/update"    // 更新用户名
#define KUserUpdateLockMemberNickName   @"/lock/member/update"          // 用户修改锁成员备注名
#define KUserUpdateLockMemberRoom       @"/lock/member/update"          // 用户修改锁成员房间
#define KUserShareLockPwd               @"/lock/pwd/share"              // 分享开锁密码
#define KUserGetLockOpenLogs            @"/lock/open/log/get"           // 获取开锁记录
#define KUserSendFeedback               @"/user/feedback"               // 用户意见反馈
#define KUserFaceIdentify               @"/face/identity"               // 人脸识别，需要名称、身份证、拍照图像

#define KLockMemberList                 @"/lock/member/list"            // 锁用户列表
#define KLockOpen                       @"/lock/pwd/get"                // 开锁
#define KLockOpenResult                 @"/lock/open/result"            // 上报开锁结果
#define KLockGetInfo                    @"/lock/get"                    // 获取锁信息
#define KLockInit                       @"/lock/init"                   // 初始化锁
#define KLockTimeUpdate                 @"/lock/time_sync/seq/get"      // 时间同步
#define KLockUpdateResult               @"/lock/time_sync/result"       // 上报时间同步
#define KLockUpdateInfo                 @"/lock/update"                 // 修改锁信息

/**
 * 单例模式
 */
+ (instancetype)shareTool;

/**
 * 如何获取到token，需要传入
 */
@property (nonatomic, copy) NSString *token;

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
