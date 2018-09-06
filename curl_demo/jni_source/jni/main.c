#include "main.h"
#include "logcat.h"
#include "stdlib.h"
#include "curl.h"

#define LOG_TAG "libmylib.so"
#define NATIVE_CLASS "com/example/cike/curl_jni_demo/NativeClass"

const static JNINativeMethod native_methods[] = {
    {"curlGet", "(Ljava/lang/String;)I", (void *)curl_get} 
};

struct string {
  char *ptr;
  size_t len;
};

int init_string(struct string *s) {
    s->len = 0;
    s->ptr = malloc(s->len+1);
    if (s->ptr == NULL) {
        LOG_E("malloc() failed");
        return -1;
    }
    s->ptr[0] = '\0';
    return 0;
}

size_t writefunc(void *ptr, size_t size, size_t nmemb, struct string *s)
{
    LOG_D("enter writefunc");
    size_t new_len = s->len + size*nmemb;
    s->ptr = realloc(s->ptr, new_len+1);
    if (s->ptr == NULL) {
        LOG_E("realloc() failed");
        return -1;
    }
    memcpy(s->ptr+s->len, ptr, size*nmemb);
    s->ptr[new_len] = '\0';
    s->len = new_len;

    return size * nmemb;
}

int curl_get(JNIEnv *env, jclass class, jstring url_str)
{
    int result = 0;
    struct string s;
    CURL *curl;
    CURLcode res;
    const char *url = (*env)->GetStringUTFChars(env, url_str, NULL);
    curl = curl_easy_init();
    if(curl) {
        
        result = init_string(&s);
        if (result == -1) {
            LOG_E("init_string failed");
            free(s.ptr);
            curl_easy_cleanup(curl);
            return result;
        }
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &s);
        res = curl_easy_perform(curl);
        if(res == CURLE_OK) {
            LOG_D("GET response:%s\n", s.ptr);
        } else {
            LOG_E("curl_easy_perform failed: %s", curl_easy_strerror(res));
            result = -1;
        }
        free(s.ptr);
        /* always cleanup */
        curl_easy_cleanup(curl);
    }
    (*env)->ReleaseStringUTFChars(env, url_str, url);
    return result;
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