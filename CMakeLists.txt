cmake_minimum_required(VERSION 3.5)

project(cbanking_rest_api)

# Les bibliothèques de l'ouest
# pistache
include_directories(/usr/local/include/pistache)
link_directories(/usr/local/lib)

# pthread
include_directories(/usr/include)
link_directories(/usr/lib/x86_64-linux-gnu/)

# Gtest
include_directories(/usr/local/include/gtest)
link_directories(/usr/local/lib)

# sodium
include_directories(/usr/local/include/sodium)
link_directories(/usr/local/lib)

# odb
include_directories(/usr/local/include/odb)
link_directories(/usr/lib/x86_64-linux-gnu)

# plog
include_directories(/usr/local/include/plog)

file(
        GLOB_RECURSE
        source
        src/*
)

# option de compilation
set(CMAKE_CXX_FLAGS -fpermissive)

add_executable(
        cbanking_rest_api

        ${source}
)

#add_subdirectory(test/sessionAPI/)
add_subdirectory(test/persistenceAPI/)
add_subdirectory(test/entity/)
add_subdirectory(test/personAPI)
add_subdirectory(test/dbconnection/)
add_subdirectory(test/sessionAPI)
add_subdirectory(test/util/converter/savingsaccount)
add_subdirectory(test/util/converter/customer)
add_subdirectory(test/util/converter/employee)
add_subdirectory(test/util/converter/currentaccount)
add_subdirectory(test/util/converter/account)
add_subdirectory(test/util/converter/person)
add_subdirectory(test/util/converter/operation)
add_subdirectory(test/util/crypto)
add_subdirectory(test/util/json_is_valid)
add_subdirectory(test/sessionEntity)

target_link_libraries(
        cbanking_rest_api

        libpistache.a
        libpthread.so
        libodb-2.4.so
        libodb-mysql-2.4.so
        libsodium.so
)

target_compile_features(cbanking_rest_api PUBLIC cxx_std_14)
