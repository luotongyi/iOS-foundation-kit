//
//  MLHTTPRequest.h
//  iOS-FoundationKit
//
//  Created by luoty on 2019/1/30.
//  Copyright © 2019年 luoty. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MLRequestItem.h"

@interface MLHTTPRequest : NSObject

/**
 * requestItem 请求消息体
 * 加解密未封装进此方法
 * 成功返回
 * 失败返回
 */
+ (void)requestItem:(MLRequestItem *)item
       successBlock:(void (^)(id responseObject))success
       failureBlock:(void (^)(id errorObject))failure;


@end
