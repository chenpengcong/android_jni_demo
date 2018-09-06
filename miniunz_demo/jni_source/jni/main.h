
#include <jni.h>

#ifndef MAIN_H
#define MAIN_H
#ifdef __cplusplus
extern "C" {
#endif

void my_unzip(JNIEnv *env, jclass class, jstring zipFileName, jstring unzipDstDir);

#ifdef __cplusplus
}
#endif
#endif
