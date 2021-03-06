//
//  MLSystemKit.h
//  iOS-FoundationKit
//
//  Created by luoty on 2019/2/14.
//  Copyright © 2019年 luoty. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>

typedef NS_ENUM(NSUInteger, MLSystemType) {
    
    MLSystem_Camera = 0,        //相机、相册功能
    MLSystem_Location,          //定位功能，初始化location
    MLSystem_QRCode,            //二维码
    MLSystem_Contact,           //通讯录
};

/**
 *  @brief 系统默认功能集合
 *  包括：拍照、定位、推送注册、二维码扫描、通讯录、指纹功能
 *  所有涉及到系统功能的都需要在plist文件里配置对应权限
 **/
@interface MLSystemKit : NSObject

+ (void)registeNotification;

/**
 *  @brief 成功注册推送，获取token
 *  token，推送token，eg. <adfs dfsf fasd ...>
 */
+ (void)successRegisteToken:(NSData *)deviceToken;

/**
 *  @brief 获取token失败
 */
+ (void)failRegisteToken;

/**
 *  @brief 初始化类
 *  MLSystem_Location时需要开启定位初始化，其他情况默认不处理
 */
- (instancetype)initWithType:(MLSystemType)type;

/**
 *  @brief 获取经纬度之后返回地址和经纬度
 */
@property (nonatomic, copy  )   void(^locationBlock)(CLPlacemark *placemark,CLLocationCoordinate2D curCoordinate2D);

/**
 *  @brief 开始获取经纬度
 */
- (void)startUpdatingLocation;

/**
 *  @brief 选择照片返回（单张）
 */
@property (nonatomic, copy  )   void(^imagePickerBlock)(UIImage *pickerImage);

/**
 *  @brief 拉起拍照/相册功能，拍照/选择照片（单张）
 */
- (void)getMediaFromSource:(UIImagePickerControllerSourceType)sourceType;

/**
 *  @brief 需要先调用此block，再执行startCamera
 */
@property (nonatomic, copy  )   void (^QRHandleBlock)(NSString *qrCode);

/**
 *  @brief 开始扫描二维码
 *
 *  @param view 把扫描控件添加到该view上
 */
- (void)startCamera:(UIView *)view;

/**
 *  @brief 停止扫描
 */
- (void)stopCamera;

/**
 *  @brief 打开系统通讯录
 */
- (void)openContact;

/**
 *  @brief 获取点击某个联系人之后的信息
 *  eg. @{@"name":name,@"phones":phones}
 */
@property (nonatomic, copy  )   void (^selectContactBlock)(NSDictionary *contact);

/**
 *  @brief 验证用户指纹
 */
+ (void)authenticationUser:(void (^)(void))successBlock
                   failure:(void (^)(void))failureBlock;

@end
