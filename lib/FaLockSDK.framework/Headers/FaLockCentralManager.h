//
//  FaLockBluetooth.h
//  FaLock
//
//  Created by kexin on 16/11/15.
//  Copyright © 2016年 KeXin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "FaLockCallback.h"

@interface FaLockCentralManager : NSObject

/**
 * 自动连接的设备ID
 */
@property (nonatomic, copy) NSString *peripherID;

/**
 * 搜寻唯一设备的ID
 */
@property (nonatomic, copy) NSString *onlyPeripherID;

/**
 * 扫描Peripherals
 */
- (void)scanPeripherals;

/**
 * 停止扫描
 */
- (void)cancelScan;

/**
 * 获取当前扫描到的peripherals
 */
- (NSArray *)findScannedPeripherals;

/**
 * 获取当前扫描到的peripherals信息数组
 */
- (NSArray *)findInfoPeripherals;

/**
 * 连接Peripherals
 */
- (void)connectToPeripheral:(CBPeripheral *)peripheral;

/**
 * 断开设备连接
 */
- (void)cancelPeripheralConnection:(CBPeripheral *)peripheral;

/**
 * 获取当前连接的peripherals
 */
- (CBPeripheral *)findConnectedPeripherals;

#pragma mark - 操作

/**
 * APP初始化锁
 */
- (void)initialLock:(InitialLockBlock)block;

/**
 * APP开锁
 */
- (void)openTheLock:(OpenTheLockBlock)block;

- (void)openTheLock:(NSString *)lockId Password:(NSString *)password SEQ:(NSString *)seq OpenFinish:(OpenTheLockBlock)block;

/**
 * APP查询锁电量 (需要当前有连接的设备、设备找到特征后调用)
 */
- (void)batteryOfLock:(LockBatteryBlock)block;

/**
 * APP查询锁状态 (需要当前有连接的设备、设备找到特征后调用)
 */
- (void)stateOfLock:(LockStateBlock)block;

#pragma mark - 中心模式

/**
 *  设备状态改变的block |  when CentralManager state changed
 */
- (void)setBlockOnCentralManagerDidUpdateState:(CentralManagerDidUpdateStateBlock)block;

/**
 *  找到设备、返回设备信息的block |  when find peripheral
 */
- (void)setBlockOnDiscoverToPeripherals:(DiscoverPeripheralsBlock)block;

/**
 *  连接设备成功的block |  when connected peripheral
 */
- (void)setBlockOnConnected:(ConnectedPeripheralBlock)block;

/**
 *  连接设备失败的block |  when fail to connect peripheral
 */
- (void)setBlockOnFailToConnect:(FailToConnectBlock)block;

/**
 *  断开Peripherals的连接的block |  when disconnected peripheral
 */
- (void)setBlockOnDisconnect:(DisconnectBlock)block;

/**
 *  设置查找服务的block |  when discover services of peripheral
 */
- (void)setBlockOnDiscoverServices:(DiscoverServicesBlock)block;

/**
 *  设置查找到特征的block |  when discovered Characteristics
 */
- (void)setBlockOnDiscoverCharacteristics:(DiscoverCharacteristicsBlock)block;

/**
 *  设置获取到最新外设发来的Characteristics值的block |  when read new characteristics value  or notiy a characteristics value
 */
- (void)setBlockOnReadValueForCharacteristic:(ReadValueForCharacteristicBlock)block;

/**
 *  设置查找到Characteristics名称的block |  when discover descriptors for characteristic
 */
- (void)setBlockOnDiscoverDescriptorsForCharacteristic:(DiscoverDescriptorsForCharacteristicBlock)block;

/**
 *  设置读取到Descriptors值的block |  when read descriptors for characteristic
 */
- (void)setBlockOnReadValueForDescriptors:(ReadValueForDescriptorsBlock)block;

/**
 *  设置读取到Battery值的block |  when read battery of peripheral
 */
- (void)setBlockOnReadBattery:(LockBatteryBlock)block;
@end
