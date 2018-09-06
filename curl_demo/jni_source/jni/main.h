
#include <jni.h>

#ifndef MAIN_H
#define MAIN_H
#ifdef __cplusplus
extern "C" {
#endif

int curl_get(JNIEnv *env, jclass class, jstring url_str);

#ifdef __cplusplus
}
#endif
#endif
