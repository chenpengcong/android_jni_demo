#include "main.h"
#include "logcat.h"
#include "stdlib.h"

#define LOG_TAG "libmylib.so"
#define NATIVE_CLASS "com/example/cike/miniunz_jni_demo/NativeClass"

extern int unzip(char *zip_file_name, char *unzip_dst_dir);

const static JNINativeMethod native_methods[] = {
    {"unzip", "(Ljava/lang/String;Ljava/lang/String;)V", (void *)my_unzip} 
};

void my_unzip(JNIEnv *env, jclass class, jstring zipFileName, jstring unzipDstDir)
{
    const char *zip_file_name;
    const char *unzip_dst_dir;
    zip_file_name = (*env)->GetStringUTFChars(env, zipFileName, NULL);
    unzip_dst_dir = (*env)->GetStringUTFChars(env, unzipDstDir, NULL);
    unzip(zip_file_name, unzip_dst_dir);
    (*env)->ReleaseStringUTFChars(env, zipFileName, zip_file_name);
    (*env)->ReleaseStringUTFChars(env, unzipDstDir, unzip_dst_dir);
}

JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved)
{
    JNIEnv *env;
    if ((*vm)->GetEnv(vm, (void **)&env, JNI_VERSION_1_4) != JNI_OK) {
        return -1;
    }
    (*env)->RegisterNatives(env, (*env)->FindClass(env, NATIVE_CLASS), native_methods, sizeof(native_methods)/sizeof(JNINativeMethod));
    return JNI_VERSION_1_4;
}