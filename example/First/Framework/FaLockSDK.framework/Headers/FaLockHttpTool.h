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
/**
 * 单例模式
 */
+ (instancetype)shareTool;

/**
 * 初始化模块
 */
- (void)initModule;

/**
 * 卸载模块
 */
- (void)uninitModule;

/** ================================= 锁 ===================================== */

/**
 * APP初始化锁
 */
- (void)initialLock:(NSString *)lockId HttpFinish:(HttpFinishBlock)block Log:(BOOL)log;

/**
 * APP开锁
 */
- (void)openTheDoor:(NSString *)lockId HttpFinish:(HttpFinishBlock)block Log:(BOOL)log;

/**
 * 上报服务器开锁结果
 */
- (void)pushLockOpenResult:(NSString *)lockId SEQ:(int)seq State:(NSString *)state HttpFinish:(HttpFinishBlock)block Log:(BOOL)log;

/**
 * 上报服务器时间同步结果
 */
- (void)pushLockUpdateResult:(NSString *)lockId SEQ:(int)seq State:(NSString *)state HttpFinish:(HttpFinishBlock)block Log:(BOOL)log;

/**
 * 获取锁信息
 */
- (void)getLockInfo:(NSString *)lockId HttpFinish:(HttpFinishBlock)block Log:(BOOL)log;

/**
 * 获取锁状态
 */
- (void)getLockState:(NSString *)lockId HttpFinish:(HttpFinishBlock)block Log:(BOOL)log;

/**
 * 获取锁用户列表
 */
- (void)getLockMemberList:(NSString *)lockId HttpFinish:(HttpFinishBlock)block Log:(BOOL)log;

/**
 * 修改锁信息
 */
- (void)updateLockInfo:(NSString *)lockId LockName:(NSString *)lockName LockAddress:(NSString *)address HttpFinish:(HttpFinishBlock)block Log:(BOOL)log;

/**
 * 锁时间同步
 */
- (void)updateLockTime:(NSString *)lockId HttpFinish:(HttpFinishBlock)block Log:(BOOL)log;

/** ================================= 用户 ===================================== */

/**
 * 设置Token
 */
- (void)userSetToken:(NSString *)token;

/**
 * 用户注册
 */
- (void)userRegister:(NSString *)phone password:(NSString *)password HttpFinish:(HttpFinishBlock)block Log:(BOOL)log;


/**
 * 用户登录
 */
- (void)userLogin:(NSString *)phone password:(NSString *)password HttpFinish:(HttpFinishBlock)block Log:(BOOL)log;

/**
 * 用户验证码
 */
- (void)userVerify:(NSString *)phone Condition:(NSString *)condition HttpFinish:(HttpFinishBlock)block Log:(BOOL)log;

/**
 * 忘记密码
 */
- (void)userforgetPassWord:(NSString *)phone password:(NSString *)password HttpFinish:(HttpFinishBlock)block Log:(BOOL)log;

/**
 * 修改电话号码
 */
- (void)userChangeTel:(NSString *)phone HttpFinish:(HttpFinishBlock)block Log:(BOOL)log;

/**
 * 用户绑定锁
 */
- (void)userBindLock:(NSString *)lockId HttpFinish:(HttpFinishBlock)block Log:(BOOL)log;

/**
 * 用户锁解除绑定
 */
- (void)userUnbindLock:(NSString *)lockId HttpFinish:(HttpFinishBlock)block Log:(BOOL)log;

/**
 * 用户锁列表
 */
- (void)userLockListV2:(NSString *)lastId HttpFinish:(HttpFinishBlock)block Log:(BOOL)log;

/**
 * 用户添加锁成员
 */
- (void)userAddLockMember:(NSString *)lockId Phone:(NSString *)phone NickName:(NSString *)niceName Room:(NSString *)room HttpFinish:(HttpFinishBlock)block Log:(BOOL)log;

/**
 * 用户删除锁成员
 */
- (void)userDeleteLockMember:(NSString *)lockId Phone:(NSString *)phone HttpFinish:(HttpFinishBlock)block Log:(BOOL)log;

/**
 * 用户修改用户名
 */
- (void)userUpdateUserName:(NSString *)userName HttpFinish:(HttpFinishBlock)block Log:(BOOL)log;

/**
 * 用户修改修改锁成员备注名
 */
- (void)userUpdateLockMemberNickName:(NSString *)lockId Phone:(NSString *)phone UserName:(NSString *)userName HttpFinish:(HttpFinishBlock)block Log:(BOOL)log;

/**
 * 用户修改锁成员房间
 */
- (void)userUpdateLockMemberRoom:(NSString *)lockId Phone:(NSString *)phone RoomName:(NSString *)roomName HttpFinish:(HttpFinishBlock)block Log:(BOOL)log;

/**
 * 分享开锁密码
 */
- (void)userShareLockPwd:(NSString *)lockId Phone:(NSString *)phone OpenTime:(NSTimeInterval)time HttpFinish:(HttpFinishBlock)block Log:(BOOL)log;

/**
 * 获取开锁记录
 */
- (void)userGetLockOpenLogs:(NSString *)lockId BeginTime:(NSString *)begin EndTime:(NSString *)end lastID:(NSString *)lastId HttpFinish:(HttpFinishBlock)block Log:(BOOL)log;

/**
 * 用户意见反馈
 */
- (void)userSendFeedback:(NSString *)contactInfo Content:(NSString *)content HttpFinish:(HttpFinishBlock)block Log:(BOOL)log;
@end
