//
//  RXWXService.h
//  RXWXSDK
//
//  Created by 陈汉 on 2022/5/30.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RXWXService : NSObject

/**
 * 获取SDK实例（单例）
 */
+ (instancetype)sharedSDK;

/**
 * 配置universallink
 */
- (void)configUniversallink:(NSString *)universallink;

/**
 * 微信分享
 * @param func 埋点标识  必须
 * @param platform 分享平台 wechat
 * @param region 地区码  非必须
 * @param transmits 透传参数，原样返回  非必须
 * @param ext 扩展字段，拼接url用  非必须
 */
- (void)shareToWWithFunc:(NSString *)func
                platform:(NSString *)platform
                  region:(NSString *)region
               transmits:(NSDictionary * _Nullable)transmits
                     ext:(NSDictionary * _Nullable)ext
                complete:(void(^)(BOOL success))complete;

/**
 * 微信登录
 * @param wxAppid 微信登录appid
 */
- (void)loginReq_wWithWXAppid:(NSString *)wxAppid;

/**
 * 检测是否安装微信
 */
- (BOOL)isWXAppInstalled;

/**
 * 处理跳转
 */
- (BOOL)handleOpenUrl:(NSURL *)url;

@end

NS_ASSUME_NONNULL_END
