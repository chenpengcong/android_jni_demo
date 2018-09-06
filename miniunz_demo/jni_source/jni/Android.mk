LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := mylib
LOCAL_CFLAGS := -fvisibility=hidden -Os -Wall
LOCAL_SRC_FILES := main.c ioapi.c miniunz.c unzip.c
LOCAL_LDLIBS := -llog -lz
include $(BUILD_SHARED_LIBRARY)

