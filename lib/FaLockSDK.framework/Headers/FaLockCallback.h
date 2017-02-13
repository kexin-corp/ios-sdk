//
//  FaLockCallback.h
//  FaLock
//
//  Created by kexin on 16/11/15.
//  Copyright © 2016年 KeXin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

//设备状态改变的block
typedef void (^CentralManagerDidUpdateStateBlock)(CBCentralManager *central);

//扫描不到设备锁block
typedef void (^ScanFailureBlock)(NSDictionary *response);

//找到设备的block
typedef void (^DiscoverPeripheralsBlock)(CBCentralManager *central,CBPeripheral *peripheral,NSDictionary *advertisementData,NSNumber *RSSI,NSDictionary *response);

//连接设备成功的block
typedef void (^ConnectedPeripheralBlock)(CBCentralManager *central,CBPeripheral *peripheral);

//连接设备失败的block
typedef void (^FailToConnectBlock)(CBCentralManager *central,CBPeripheral *peripheral,NSError *error);

//断开设备连接的bock
typedef void (^DisconnectBlock)(CBCentralManager *central,CBPeripheral *peripheral,NSError *error);

//找到服务的block
typedef void (^DiscoverServicesBlock)(CBPeripheral *peripheral,NSError *error);

//找到特征的block
typedef void (^DiscoverCharacteristicsBlock)(CBPeripheral *peripheral,CBService *service,NSError *error);

//更新（获取）Characteristics的value的block
typedef void (^ReadValueForCharacteristicBlock)(CBPeripheral *peripheral,CBCharacteristic *characteristic,NSError *error);

//获取Characteristics的名称
typedef void (^DiscoverDescriptorsForCharacteristicBlock)(CBPeripheral *peripheral,CBCharacteristic *service,NSError *error);

//获取Descriptors的值
typedef void (^ReadValueForDescriptorsBlock)(CBPeripheral *peripheral,CBDescriptor *descriptor,NSError *error);

//网络请求结果回调Block
typedef void (^HttpFinishBlock)(NSDictionary *response);

//初始化锁结果Block
typedef void (^InitialLockBlock)(NSDictionary *response);

//返回开锁结果Block
typedef void (^OpenTheLockBlock)(NSDictionary *response);

//返回锁电量状态详情Block
typedef void (^LockBatteryBlock)(NSDictionary *response);

//返回锁状态详情Block
typedef void (^LockStateBlock)(NSDictionary *response);

@interface FaLockCallback : NSObject
//设备状态改变
@property (nonatomic, copy) CentralManagerDidUpdateStateBlock blockOnCentralManagerDidUpdateState;
//扫描不到设备
@property (nonatomic, copy) DiscoverPeripheralsBlock blockOnDiscoverPeripherals;
//找到设备
@property (nonatomic, copy) ScanFailureBlock ScanFailureBlock;
//连接设备
@property (nonatomic, copy) ConnectedPeripheralBlock blockOnConnectedPeripheral;
//连接设备失败
@property (nonatomic, copy) FailToConnectBlock blockOnFailToConnect;
//断开设备连接
@property (nonatomic, copy) DisconnectBlock blockOnDisconnect;
//找到服务
@property (nonatomic, copy) DiscoverServicesBlock blockOnDiscoverServices;
//找到特征
@property (nonatomic, copy) DiscoverCharacteristicsBlock blockOnDiscoverCharacteristics;
//发现更新（获取）Characteristics的value
@property (nonatomic, copy) ReadValueForCharacteristicBlock blockOnReadValueForCharacteristic;
//获取Characteristics的名称
@property (nonatomic, copy) DiscoverDescriptorsForCharacteristicBlock blockOnDiscoverDescriptorsForCharacteristic;
//获取Descriptors的值
@property (nonatomic, copy) ReadValueForDescriptorsBlock blockOnReadValueForDescriptors;
//返回初始化锁结果
@property (nonatomic, copy) HttpFinishBlock HttpFinishBlock;
//返回网络请求结果
@property (nonatomic, copy) InitialLockBlock InitialLockBlock;
//返回开锁结果
@property (nonatomic, copy) OpenTheLockBlock OpenTheLockBlock;
//返回锁电量
@property (nonatomic, copy) LockBatteryBlock LockBatteryBlock;
//返回锁状态
@property (nonatomic, copy) LockStateBlock LockStateBlock;
@end
