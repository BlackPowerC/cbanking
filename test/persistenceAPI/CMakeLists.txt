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
        # les apis
        ../../include/API/PersonAPI.hpp
        ../../include/API/PersistenceAPI.hpp
        ../../include/API/OperationAPI.hpp
        ../../include/API/AccountAPI.hpp

        ../../src/Exception.cpp
        ../../include/Exception.hpp

        ../../include/Core/DBConnection.hpp
        ../../src/Core/DBConnection.cpp

        ../../include/Entity/Persons.hpp
        ../../src/Entity/Persons.cpp

        ../../src/Entity/Persons-odb.cxx
        ../../include/Entity/Persons-odb.hxx

        ../../include/Entity/Operation.hpp
        ../../src/Entity/Operation.cpp

        ../../include/Entity/Operation-odb.hxx
        ../../src/Entity/Operation-odb.cxx

        ../../include/Entity/Account.hpp
        ../../src/Entity/Account.cpp

        ../../include/Entity/Account-odb.hxx
        ../../src/Entity/Account-odb.cxx
)

target_link_libraries(
        test_persistence_api
        libodb-2.4.so
        libodb-mysql-2.4.so
        libgtest.a
        libgtest_main.a
        libpthread.so
)

target_compile_features(test_persistence_api PUBLIC cxx_std_14)