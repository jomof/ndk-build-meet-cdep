# Copyright (C) 2017 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := hello-openssl
LOCAL_SRC_FILES += hello-openssl.c
LOCAL_STATIC_LIBRARIES += openssl-ssl
LOCAL_STATIC_LIBRARIES += openssl-crypto
LOCAL_LDLIBS += -latomic

include $(BUILD_SHARED_LIBRARY)

# Import all cdep-defined dependencies. The modules defined within are added
# to LOCAL_STATIC_LIBRARIES above.
$(call import-module, cdep-dependencies)
