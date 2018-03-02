cmake_minimum_required(VERSION 3.5)

project(test_dbconnection)

# odb include
include_directories(/usr/local/include/odb)
link_directories(/usr/lib/x86_64-linux-gnu)

#plog include
include_directories(/usr/local/include/plog)

add_executable(
	test_dbconnection

	test_dbconnection.cpp

	../../src/Core/DBConnection.hpp
	../../src/Core/DBConnection.cpp
)

target_link_libraries(
	test_dbconnection
	libodb-2.4.so
	libodb-mysql-2.4.so
)

target_compile_features(test_dbconnection PUBLIC cxx_std_14)