cmake_minimum_required(VERSION 3.5)

# gtest
include_directories(/usr/local/local/gtest)
link_directories(/usr/local/lib)

# pthread
include_directories(/usr/include)
link_directories(/lib/x86_64-linux-gnu/)

# rapisjson
include_directories(/usr/local/include/rapidjson)

add_executable(
        test_employee_converter

        test_employee_converter.cpp

        ../../../../src/Util/Converter/EmployeeConverter.cpp
        ../../../../src/Util/Converter/PersonConverter.cpp
        ../../../../src/Util/Converter/OperationConverter.cpp

        ../../../../src/Entity/Persons.cpp

        ../../../../src/Entity/Account.cpp

        ../../../../src/Entity/Operation.cpp

        ../../../../src/Util/Crypto.cpp

        ../../../../src/Exception.cpp
)

target_link_libraries(
        test_employee_converter
        libgtest.a
        libgtest_main.a
        libpthread.so
        sodium
)

set(CMAKE_CXX_FLAGS "-fpermissive")

target_compile_features(test_employee_converter PUBLIC cxx_std_14)
