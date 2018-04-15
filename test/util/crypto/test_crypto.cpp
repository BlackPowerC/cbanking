//
// Created by jordy on 22/03/18.
//

/**
 * \file test_crypo
 * \brief Test des fonctions du fichier Crypto.hpp
 */

#include <gtest/gtest.h>
#include "../../../include/Util/Crypto.hpp"
#include <iostream>
#include <sodium.h>

class MyTest: public ::testing::Test
{
public:
    virtual void setUp() {};
    virtual void tearDown() {} ;
};

TEST_F(MyTest, hashArgon2i)
{
    std::string passwd = "qfdsbgkldsf45";
    std::string hash ;
    ASSERT_NO_THROW((hash = Util::hashArgon2(passwd))) ;
    std::cout << hash+"\n";
}

TEST_F(MyTest, verifyArgonHash1)
{
    std::string passwd = "qfdsbgkldsf45";
    std::string hash ;
    ASSERT_NO_THROW((hash = Util::hashArgon2(passwd))) ;
    ASSERT_TRUE(Util::verifyArgon2Hash(hash, passwd)) ;
}

TEST_F(MyTest, verifyArgonHash2)
{
    std::string passwd = "qfdsbgkldsf45";
    std::string hash ;
    ASSERT_NO_THROW((hash = Util::hashArgon2(passwd))) ;
    ASSERT_FALSE(Util::verifyArgon2Hash(hash, "jordy")) ;
}

TEST_F(MyTest, hashSha512_1)
{
    std::string passwd = "toto";
    std::string hash ;
    hash = Util::hashSha512(passwd) ;
    ASSERT_FALSE(hash.empty()) ;
}

int main(int argc, char *argv[])
{
    if(sodium_init())
    {
        return -1 ;
    }
    testing::InitGoogleTest(&argc, argv) ;
    return RUN_ALL_TESTS() ;
}
