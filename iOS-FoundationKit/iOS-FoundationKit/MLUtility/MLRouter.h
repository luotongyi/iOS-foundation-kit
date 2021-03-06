//
//  MLRouter.h
//  iOS-FoundationKit
//
//  Created by luoty on 2019/2/24.
//  Copyright © 2019年 luoty. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 *  @brief 界面跳转路由
 *  包括：H5-->原生、原生-->H5、H5-->H5、原生-->原生
 */
@interface MLRouter : NSObject

/**
 *  @brief push到某个界面，无参数传递
 *  params 类里的参数，参数的key，需要和类名相同，默认为nil没有参数
 *  vcClassName 界面的类名
 */
+ (void)pushController:(NSString *)vcClassName params:(NSDictionary *)params;

/**
 *  @brief push到H5界面(WebViewController类)
 *  url H5加载的链接url
 */
+ (void)pushWebController:(NSString *)url;

/**
 *  @brief pop到上一个界面
 */
+ (void)popController;

/**
 *  @brief pop到根界面
 */
+ (void)popRootController;

@end
