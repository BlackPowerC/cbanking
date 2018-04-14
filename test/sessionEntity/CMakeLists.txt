cmake_minimum_required(VERSION 3.5)

project(test_session)

# gtest
include_directories(/usr/local/include/gtest)
link_directories(/usr/local/lib)

# pthread
include_directories(/usr/local/include)
link_directories(/usr/lib/x86_64-linux-gnu)

add_executable(
	test_session

	test_session.cpp

	../../src/Entity/Account.cpp

	../../src/Entity/Operation.cpp

	../../src/Entity/Persons.cpp

	../../src/Util/Crypto.cpp

	../../src/Exception.cpp
)

target_link_libraries(
	test_session
	gtest
	gtest_main
	pthread
	sodium
)

target_compile_features(test_session PUBLIC cxx_std_14)
