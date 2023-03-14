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
 * ！shareInfo参数说明：
 * ！title 链接标题
 * ！url 分享链接
 * ！material_type 分享类型
 * ！image 分享图片
 * ！content 分享文案
 */
- (void)shareToWWithShareInfo:(NSDictionary *)shareInfo
                     complete:(void(^)(BOOL success))complete;

/**
 * 微信分享（直接调用，不需要获取分享信息）
 * @param func 埋点标识  必须
 * @param platform 分享平台 wechat
 * @param region 地区码  非必须
 * @param transmits 透传参数，原样返回， 请使用key=value形式，并对值使用urlencode，返回时会原样返回  非必须
 * @param ext 扩展字段，拼接url用  非必须
 */
- (void)shareToWWithFunc:(NSString *)func
                platform:(NSString *)platform
                  region:(NSString *)region
               transmits:(NSString * _Nullable)transmits
                     ext:(NSDictionary * _Nullable)ext
                complete:(void(^)(BOOL success))complete;

/**
 * 微信登录
 * @param wxAppid 微信登录appid
 * @param migrate_args 任意合法的 json 类型, 比如 string, nujber，账号迁移用的参数, 调用 CP account-query 及 account-queryandbind 接口时透传给 CP  非必须
 * @param sign_fields 指定对登录成功后返回的特定字段, 使用 CPKEY 计算签名. CP 服务器可重新计算签名并与登录返回的签名比对, 作为对瑞雪登录数据的校验. 支持的字段包括: nickname, avatar, openid, region, sex, age, 计算签名的逻辑会对指定字段进行排序, 此处传参与顺序无关。类型为字符串数组 @[@"nickname",@"avatar"]  非必须
 */
- (void)loginReq_wWithWXAppid:(NSString *)wxAppid
                 migrate_args:(id _Nullable)migrate_args
                  sign_fields:(NSArray * _Nullable)sign_fields;

/**
 * 检测是否安装微信
 */
- (BOOL)isWXAppInstalled;

/**
 * 处理微信通过Universal Link启动App时传递的数据
 * 需要在 application:openURL:sourceApplication:annotation:或者application:handleOpenURL中调用。
 * @param url 微信启动第三方应用时传递过来的URL
 */
- (BOOL)handleOpenUrl:(NSURL *)url;

/**
 * 处理微信通过Universal Link启动App时传递的数据
 * 需要在 application:continueUserActivity:restorationHandler:中调用。
 * @param userActivity 启动第三方应用时系统API传递过来的userActivity
 */
- (BOOL)handleOpenUniversalLink:(NSUserActivity *)userActivity;

@end

NS_ASSUME_NONNULL_END
