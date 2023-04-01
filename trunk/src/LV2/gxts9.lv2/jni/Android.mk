LOCAL_PATH := $(call my-dir) 
include $(CLEAR_VARS) 
LOCAL_MODULE := gxts9.lv2 
LOCAL_SRC_FILES := gxts9.cpp 
include $(BUILD_SHARED_LIBRARY) 
LOCAL_C_INCLUDES := dsp/ plugin/
LOCAL_CPP_FEATURES:= fxsr
