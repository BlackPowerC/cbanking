cmake_minimum_required(VERSION 3.5)

project(test_personapi)

# odb include
include_directories(/usr/local/include/odb)
link_directories(/usr/lib/x86_64-linux-gnu)

#plog include
include_directories(/usr/local/include/plog)

add_executable(

	test_personapi

	test_personapi.cpp

	../../src/Exception.cpp

    ../../src/Util/RegularFile.cpp

    ../../src/Util/JSONValidator.cpp

	../../src/Core/DBConnection.cpp

	../../src/Entity/Persons.cpp

	../../src/Entity/Persons-odb.cxx

	../../src/Entity/Operation.cpp

	../../src/Entity/Operation-odb.cxx

	../../src/Entity/Account.cpp

	../../src/Entity/Account-odb.cxx
)

target_link_libraries(
	test_personapi
	libodb-2.4.so
	libodb-mysql-2.4.so
)

target_compile_features(test_personapi PUBLIC cxx_std_14)