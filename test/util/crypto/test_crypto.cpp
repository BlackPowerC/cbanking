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

class MyTest: public ::testing::Test
{
public:
    virtual void setUp() {};
    virtual void tearDown() {} ;
};

TEST_F(MyTest, hashSha512)
{
    std::string mdp = "dadadadadadadad" ;
    std::string hash ;
    ASSERT_NE(-1, Util::hashSha512(hash, mdp)) ;
    std::cout << hash << std::endl ;
}

TEST_F(MyTest, hashArgon2i)
{
    std::string mdp = "dadadadadadadad" ;
    std::string hash ;
    ASSERT_NE(-1, Util::hashArgon2(hash, mdp)) ;
    std::cout << hash << std::endl ;
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv) ;
    return RUN_ALL_TESTS() ;
}