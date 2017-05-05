APP_ABI := all
APP_STL := c++_static
APP_CPPFLAGS += -fexceptions
APP_CPPFLAGS += -frtti
APP_CPPFLAGS += -std=c++11
NDK_MODULE_PATH += /usr/local/google/home/jomof/projects/ndk-build-meet-cdep/.cdep/modules/ndk-build
NDK_TOOLCHAIN_VERSION := clang