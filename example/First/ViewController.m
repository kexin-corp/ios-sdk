//
//  ViewController.m
//  First
//
//  Created by kexin on 16/11/17.
//  Copyright © 2016年 KeXin. All rights reserved.
//

#import "ViewController.h"
#import <CoreBluetooth/CoreBluetooth.h>
#import <FaLockSDK/FaLockSDK.h>
#import <FaLockSDK/FaLockHttpTool.h>
#import "MBProgressHUD+ZYG.h"

#define kScreenHeight [UIScreen mainScreen].bounds.size.height
#define kScreenWidth  [UIScreen mainScreen].bounds.size.width

@interface ViewController ()<UITableViewDataSource,UITableViewDelegate>
@property (nonatomic, strong) UITableView          *tableView;
@property (nonatomic, strong) FaLockCentralManager *manager;
@property (nonatomic, strong) NSArray              *peripherals;
@property (nonatomic, strong) NSArray              *peripheralInfos;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self initUI];
    
    [self scan];
}

- (void)initUI
{
    self.title = @"蓝牙列表";
    
    self.tableView = [[UITableView alloc] initWithFrame:CGRectMake(0, 0, kScreenWidth, kScreenHeight) style:UITableViewStylePlain];
    self.tableView.delegate = self;
    self.tableView.dataSource = self;
    [self.view addSubview:self.tableView];
}

- (void)scan
{
    // 输入分配的AppId，如 app_kexin
    [FaLockHttpTool shareTool].appid = @"app_kexin";
    
    // 输入正式服务器地址，如 https://app.fastboot.net.cn
    [FaLockHttpTool shareTool].URLString = @"https://app.fastboot.net.cn";

    _manager = [[FaLockCentralManager alloc] init];
    
    __weak typeof(self) weakself = self;
    
    // 检查是否打开蓝牙
    [_manager setBlockOnCentralManagerDidUpdateState:^(CBCentralManager *central) {
        
        if (central.state == CBManagerStatePoweredOff) {
            
            [MBProgressHUD showError:@"请打开蓝牙"];
        }
        
        if (central.state == CBManagerStatePoweredOn) {
            
            [weakself.manager scanPeripherals];
        }
    }];
    
    // 扫描设备
    [_manager setBlockOnDiscoverToPeripherals:^(CBCentralManager *central, CBPeripheral *peripheral, NSDictionary *advertisementData, NSNumber *RSSI, NSDictionary *response) {
        
        weakself.peripherals = [weakself.manager findScannedPeripherals];
        weakself.peripheralInfos = [weakself.manager findInfoPeripherals];
        [weakself.tableView reloadData];
    }];
    
    // 发现外设特征
    [_manager setBlockOnDiscoverCharacteristics:^(CBPeripheral *peripheral, CBService *service, NSError *error) {
        
        // 显示按钮
        weakself.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:@"开锁" style:UIBarButtonItemStylePlain target:weakself action:@selector(open)];
    }];
    
    // 设备自动断开后处理
    [_manager setBlockOnDisconnect:^(CBCentralManager *central, CBPeripheral *peripheral, NSError *error) {
        
        weakself.navigationItem.rightBarButtonItem = nil;
        weakself.navigationItem.leftBarButtonItem = nil;
        
        [weakself.tableView reloadData];
    }];
}

-(NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return _peripherals.count;
}

-(UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *ID = @"Cell";
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:ID];
    
    if (!cell) {
        
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:ID];
        cell.textLabel.font = [UIFont systemFontOfSize:15.f];
    }
    
    CBPeripheral *object = _peripherals[indexPath.row];
    NSDictionary *info   = _peripheralInfos[indexPath.row];
    
    cell.textLabel.text = [NSString stringWithFormat:@"%@  (lock_id:%@)",object.name,info[@"lock_id"]];
    cell.detailTextLabel.text = [NSString stringWithFormat:@"mac:%@",info[@"mac"]];
    
    // 正在连接的锁显示红色、未连接显示黑色
    if ([object.name isEqualToString:[_manager findConnectedPeripherals].name]) {
        
        cell.textLabel.textColor = [UIColor redColor];
        cell.detailTextLabel.textColor = [UIColor redColor];
    }else{
        
        cell.textLabel.textColor = [UIColor blackColor];
        cell.detailTextLabel.textColor = [UIColor blackColor];
    }
    
    return cell;
}

-(CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return 64;
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    
    // 连接外设
    CBPeripheral *object = _peripherals[indexPath.row];
    [_manager connectToPeripheral:object];
    [self.tableView reloadData];
}

// 开锁
- (void)open
{
    [self.manager openTheLock:^(NSDictionary *response) {
        
        [MBProgressHUD showToast:response[@"desc"] toView:self.view];
    }];
}

@end
