//
//  YLT_BaseWebVC.h
//  YLT_Kit
//
//  Created by 项普华 on 2018/5/22.
//

#import <YLT_Kit/YLT_Kit.h>
#import <WebKit/WebKit.h>

@protocol YLT_WebProtocl

@optional
/**
 JS给OC发送数据 （JS调用OC的方法）
 
 @param names 方法名
 @param callback 监听到js调用的回调
 */
- (void)ylt_addObserverNames:(NSArray<NSString *> *)names callback:(void(^)(WKScriptMessage *message))callback;

/**
 OC给JS发送数据 （OC调用JS的方法）
 
 @param jsMedhodName 方法名
 @param param 数据
 */
- (void)ylt_sendMethodName:(NSString *)jsMedhodName param:(NSString *)param, ...NS_REQUIRES_NIL_TERMINATION;

/**
 OC给JS发送JS数据 （OC调用JS的方法）
 
 @param function js方法名
 @param param 参数
 */
- (void)ylt_sendFunction:(NSString *)function param:(NSString *)param, ...NS_REQUIRES_NIL_TERMINATION;

/**
 刷新页面
 */
- (void)ylt_reload;

/**
 清理缓存
 */
- (void)ylt_cleanCache;

@end


@interface YLT_BaseWebView : YLT_BaseView<WKScriptMessageHandler, WKNavigationDelegate, WKUIDelegate, YLT_WebProtocl>

/**
 网页视图
 */
@property (nonatomic, strong, readonly) WKWebView *webView;

/**
 加载失败的占位图
 */
@property (nonatomic, strong) UIView *loadingFailedView;

/**
 网络视图参数配置
 */
@property (nonatomic, strong) WKWebViewConfiguration *configuration;

/**
 根据地址生成网页视图
 
 @param frame frame
 @param urlString 网页地址
 @return 网页视图
 */
+ (instancetype)ylt_webViewFrame:(CGRect)frame URLString:(NSString *)urlString;

/**
 根据地址生成网页视图
 
 @param frame frame
 @param filePath 本地路径
 @return 网页视图
 */
+ (instancetype)ylt_webViewFrame:(CGRect)frame filePath:(NSString *)filePath;

@end

@interface YLT_BaseWebVC : YLT_BaseVC<YLT_WebProtocl>

/**
 网页视图
 */
@property (nonatomic, strong, readonly) YLT_BaseWebView *webView;

/**
 根据地址生成网页视图
 
 @param urlString 路径
 @return 控制器
 */
+ (instancetype)ylt_webVCFromURLString:(NSString *)urlString;

/**
 根据地址生成网页视图
 
 @param filePath 路径
 @return 控制器
 */
+ (instancetype)ylt_webVCFromFilePath:(NSString *)filePath;

@end
