/**
 * http请求接口，
 * 功能：
 * 1、http请求，返回json字符串
 * 2、http请求，返回文件（指定返回文件路径）
 * 3、http请求，上传文件
 * 4、返回请求结果，成功/失败
*/
#ifndef _IFACEHTTPREQ_H_
#define _IFACEHTTPREQ_H_

#ifdef __cplusplus
extern "C" {
#endif

#define HTTPERROR_CHECK_PAREM       1   // 参数检查失败
#define HTTPERROR_OPENFILE          2   // 打开文件失败
#define HTTPERROR_CURL_INIT         3   // curl init失败
#define HTTPERROR_CURL_PERFORM      4   // curl preform失败
#define HTTPERROR_BUFF_NOTENOUGH    5   // 输入缓存不足

typedef int (*HTTP_REPLY_CONTENT_FUNC)(const char* buffer, int len, void* arg);
typedef enum {
    RET_NONE,
    RET_FILE,
    RET_JSON,
} HTTP_REPLY_TYPE;

typedef struct {
    HTTP_REPLY_TYPE type;          // 是否有返回值，或者指定返回类型
    HTTP_REPLY_CONTENT_FUNC opt;
    void* p;                        // 文件描述符或者指向一段内存，如果http请求成功
    int len;                        // 如果有返回内容，len指定给分配的缓存大小
    int offset;                     // 标记存储偏移
    int ret;                        // 带回回调的错误
} HTTP_REPLY;
#if 0
typedef struct {
    HTTP_REPLY reply;
    int callbk_flag;        // 回调执行成功或者失败，0成功，非0失败
    char* url;
    char* body;
    void* arg;              // 自定义参数，用户自己传入的参数，用户自己管理
} httpC_req_task;

typedef struct {
    char* admin;
    char* pass;
    char* file;
} httpC_UpFileStruct;

// 定义请求回调函数原型类型
typedef void (*http_response_cb)(httpC_req_task* req);
#endif
// http请求接口，这里的type是为了用户指定返回的内容
int httpReq(HTTP_REPLY_TYPE type ,const char* url, char* data, const int len);
// http上传文件，data
int httpUploadFile(const char* url, char* data, int len, char *admin, char *pass);
// int httpC_svc_set_req_cb();
#if 0
// 释放返回资源
void httpC_svc_reply_reset(HTTP_REPLY* reply);
// 上传日志文件（上传日志专用）
int httpC_uplaodFile(httpC_req_task *req, http_response_cb cb);
#endif

#ifdef __cplusplus
}
#endif

#endif /*_IFACEHTTPREQ_H_*/



