LOCAL_PATH := $(call my-dir) 
include $(CLEAR_VARS) 
LOCAL_MODULE := gx_switched_tremolo.lv2 
LOCAL_SRC_FILES := gx_switched_tremolo.cpp 
include $(BUILD_SHARED_LIBRARY) 
LOCAL_C_INCLUDES := dsp/ plugin/
