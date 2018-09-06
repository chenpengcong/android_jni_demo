LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := mylib
LOCAL_CFLAGS := -fvisibility=hidden -Os -Wall
LOCAL_SRC_FILES := main.c 
LOCAL_LDLIBS := -llog
LOCAL_SHARED_LIBRARIES := curl-prebuilt
include $(BUILD_SHARED_LIBRARY)


# ThirdParty prebuilt
include $(CLEAR_VARS)
LOCAL_MODULE := curl-prebuilt
LOCAL_SRC_FILES := $(LOCAL_PATH)/ThirdPartyLib/armeabi/libcurl.so
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/ThirdPartyLib/include/curl
include $(PREBUILT_SHARED_LIBRARY)
