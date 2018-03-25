cmake_minimum_required(VERSION 3.5)

project(test_create_root_session)

# odb include
include_directories(/usr/local/include/odb)
link_directories(/usr/lib/x86_64-linux-gnu)

# sodium include
include_directories(/usr/local/include/sodium)
link_directories(/usr/local/lib)

add_executable(

    test_create_root_session

    test_create_root_session.cpp

    ../../src/Core/DBConnection.cpp

    ../../src/Exception.cpp

    ../../src/Util/Crypto.cpp

    ../../src/Entity/Persons.cpp

	../../src/Entity/Persons-odb.cxx

	../../src/Entity/Operation.cpp

	../../src/Entity/Operation-odb.cxx

	../../src/Entity/Account.cpp

	../../src/Entity/Account-odb.cxx

)

target_link_libraries(
        test_create_root_session
	libodb-2.4.so
	libodb-mysql-2.4.so
	libsodium.so
)

target_compile_features(test_create_root_session PUBLIC cxx_std_14)