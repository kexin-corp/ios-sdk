# **可信APP SDK 集成指南**


- [一、简介](#Introduction)
    - [平台简介](#Platform_Introduction)
    - [APP SDK简介](#sdk_Introduction)
- [二、版本要求](#Version)
- [三、接入方法](#Integrated)
- [四、注意事项](#Notice)

## 一、<a name="Introduction">简介</a>

- [平台简介](#Platform_Introduction)
- [APP SDK简介](#sdk_Introduction)

### 1.1、<a name="Platform_Introduction">平台简介</a>
- 为传统企业提供物联网云平台软件服务，快速实现产品智能化、进入物联网领域
- 为企业提供技术、服务支撑平台和运营体系
- 为企业提供物联网数据服务的平台

### 1.2、<a name="sdk_Introduction">APP SDK 简介</a>

**为简化开发者的APP开发，可信提供了APP开发套件和相关的支持服务：**

- 提供APP的SDK和开发文档，兼容iOS、Android平以及HTML5嵌入式界面
- 提供APP端通用业务功能块的实例源代码，极大简化开发人员开发工作
- 为企业用户提供专业的技术支持服务

**APP开发套件包含以下主要功能：**

- 自动扫描、发现可用设备锁
- 提供数据接收与发送的接口
- 提供底层网络和设备状态回调接口
- 使开发者简化APP开发流程，快速完成APP开发，开发者仅需关注APP业务功能即可，而相对复杂的协议与错误处理等事项可忽略。


## 二、<a name="Version">版本要求</a>
iOS 8 及以上版本

## 三、<a name="Integrated">接入方法</a> 
- 将FaLockSDK.framework拖入工程目录：
- 导入头文件：`#import <CoreBluetooth/CoreBluetooth.h> #import <FaLockSDK/FaLockSDK.h>`
- 创建FaLockCentralManager对象，调用scanPeripherals方法进行蓝牙设备扫描
- 设置扫描设备回调Block,setBlockOnDiscoverToPeripherals。调用findScannedPeripherals获取扫描到的设备
- 用户点击手势处理，调用connectToPeripheral方法连接外设
- 确保发现外设特征后，先查询锁的状态，再执行开锁操作，否则开锁有可能无效（锁时间同步）
- 确保发现外设特征后，再执行初始化操作，否则初始化有可能无效
- 一键开锁只需要调用开锁函数，传入对应参数即可
- 具体操作方法，参考example 
 
## 四、<a name="Notice">注意事项</a>
