# curl_obj
基于curl实现的http请求，http文件下载和文件上传

# 描述
一个基于curl开源库实现了http请求的接口组件
# 请求接口
@type	请求返回的类型
@url	请求地址
@data	带入请求body，如果有返回内容，将带回返回内容
@len	表示data的长度，作为内部判断使用
@return	请求结果，0成功，负数失败（可以查找失败码）
int httpQeq(httpReplyType type ,const char* url, char* data, const int len);
