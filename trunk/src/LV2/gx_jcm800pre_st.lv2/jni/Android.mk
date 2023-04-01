LOCAL_PATH := $(call my-dir) 
include $(CLEAR_VARS) 
LOCAL_MODULE := gx_jcm800pre_st.lv2 
LOCAL_SRC_FILES := gx_jcm800pre_st.cpp 
include $(BUILD_SHARED_LIBRARY) 
LOCAL_C_INCLUDES := dsp/ plugin/
