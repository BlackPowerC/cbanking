cmake_minimum_required(VERSION 3.5)

project(test_json_is_valid)

# include pour gtest
include_directories(/usr/local/include/gtest)
link_directories(/usr/local/lib)

add_executable(
        test_json_is_valid

        test_json_is_valid.cpp
        ../../../src/Util/JSONValidator.cpp
        ../../../src/Util/RegularFile.cpp
        ../../../src/Exception.cpp
)

target_link_libraries(
        test_json_is_valid
        libgtest.a
        libgtest_main.a
        libpthread.so
)

target_compile_features(test_json_is_valid PUBLIC cxx_std_14)