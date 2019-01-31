//
//  MLStatisticsAPI.m
//  iOS-FoundationKit
//
//  Created by luoty on 2019/1/30.
//  Copyright © 2019年 luoty. All rights reserved.
//

#import "MLStatisticsAPI.h"

#import "MLInstance.h"
#import "MLAnalyse.h"
#import "MLCrashHandler.h"

@implementation MLStatisticsAPI

+ (void)setLogEnable:(BOOL)enable
{
    [MLInstance sharedInstance].enableLog = enable;
}

+ (void)registerKey:(NSString *)key
{
    ML_INFORMATION_LOG(@"注册的key：%@",key);
    
    NSSetUncaughtExceptionHandler(&MLUncaughtExceptionHandler);
    [MLAnalyse startMonitor];
#warning 创建数据库，还未完善
    
    
    
    
    
#warning 发送网络请求，校验key，还未完善
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1.0f * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        
        [MLInstance sharedInstance].registerKey = key;
        
#warning 上传上次缓存的Crash信息，还未完善
        
        
    });
}


@end
