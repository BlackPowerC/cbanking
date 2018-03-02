cmake_minimum_required(VERSION 3.5)

project(test_entities)

# odb include
include_directories(/usr/local/include/odb)
link_directories(/usr/lib/x86_64-linux-gnu)

add_executable(
	test_entities

	test_entities.cpp

	../../src/Entity/Entity.hpp

	../../src/Entity/Account-odb.cxx
	../../src/Entity/Account-odb.hxx

	../../src/Entity/Operation-odb.cxx
	../../src/Entity/Operation-odb.hxx

	../../src/Entity/Persons-odb.cxx
	../../src/Entity/Persons-odb.hxx

	../../src/Entity/Account.cpp
	../../src/Entity/Account.hpp

	../../src/Entity/Operation.cpp
	../../src/Entity/Operation.hpp

	../../src/Entity/Persons.cpp
	../../src/Entity/Persons.hpp
)

target_link_libraries(
	test_entities
	libodb-2.4.so
	libodb-mysql-2.4.so

)

target_compile_features(test_entities PUBLIC cxx_std_14)