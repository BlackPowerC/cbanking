cmake_minimum_required(VERSION 3.5)

project(test_crypto)

# libsodium
include_directories(/usr/local/include/sodium)
link_directories(/usr/local/lib)

# google test
include_directories(/usr/local/include/gtest)
link_directories(/usr/local/lib)

add_executable(
        test_crypto

        test_crypto.cpp
        ../../../src/Util/Crypto.cpp
)

target_link_libraries(
        test_crypto

        libgtest.a
        libgtest_main.a
        libpthread.so
        libsodium.so
)

target_compile_features(test_crypto PUBLIC cxx_std_14)