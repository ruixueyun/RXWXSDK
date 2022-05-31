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
 * @param shareInfo 获取分享信息返回的内容  必须
 * @param shareScene 分享方式 0-好友 1-朋友圈
 */
- (void)shareToWWithShareInfo:(NSDictionary *)shareInfo
                   shareScene:(NSInteger)shareScene
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
