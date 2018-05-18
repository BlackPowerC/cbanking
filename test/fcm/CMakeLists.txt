cmake_minimum_required(VERSION 3.5)

project(FCMNotificationTest)

# curl
include_directories(/usr/local/include/curl)
link_directories(/usr/local/lib)

# pthread
include_directories(/usr/include)
link_directories(/usr/lib/x86_64-linux-gnu/)

# Gtest
include_directories(/usr/local/include/gtest)
link_directories(/usr/local/lib)

add_executable(

        FCMNotificationTest
        FCMNotificationTest.cpp
        ../../src/Rest/FCMNotification.cpp
        ../../src/Util/RegularFile.cpp
        ../../src/Util/JSONValidator.cpp
        ../../src/Exception.cpp

)

set(CMAKE_CXX_FLAGS -fpermissive)

target_link_libraries(
        FCMNotificationTest

        libgtest.a
        libgtest_main.a
        libpthread.so
        libcurl.so
)

target_compile_features(FCMNotificationTest PUBLIC cxx_std_14)
