cmake_minimum_required(VERSION 3.5)

# gtest
include_directories(/usr/local/include/gtest)
link_directories(/usr/local/lib)

# odb
include_directories(/usr/local/include/odb)
link_directories(/usr/lib/x86_64-linux-gnu)

# pthread
include_directories(/usr/local/include)
link_directories(/usr/lib/x86_64-linux-gnu)

# plog
include_directories(/usr/local/plog)

add_executable(
        test_persistence_api

        test_persistence_api.cpp

        # tout les sources
        ../../src/Exception.cpp

        ../../src/Util/Crypto.cpp

        ../../src/Util/RegularFile.cpp

        ../../src/Util/JSONValidator.cpp

        ../../src/Core/DBConnection.cpp

        ../../src/Entity/Persons.cpp

        ../../src/Entity/Persons-odb.cxx

        ../../src/Entity/Operation.cpp

        ../../src/Entity/Operation-odb.cxx

        ../../src/Entity/Account.cpp

        ../../src/Entity/Account-odb.cxx

        ../../src/Util/Crypto.cpp

        ../../src/Exception.cpp
)

target_link_libraries(
        test_persistence_api
        libodb-2.4.so
        libodb-mysql-2.4.so
        libgtest.a
        libgtest_main.a
        libpthread.so
        libsodium.so
)

target_compile_features(test_persistence_api PUBLIC cxx_std_14)
