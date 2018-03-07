/**
 * \author jordy fatigba
 * \brief Fichier de test de la classe PersonConverter.
 *
 */

//
// Created by jordy on 06/03/18.
//

#include <gtest/gtest.h>
#include "../../../../include/Util/Converter/PersonConverter.hpp"

class Test: public ::testing::Test
{
protected:
    virtual void TearDown()
    {

    }

    virtual void SetUp()
    {

    }
};

#include <iostream>

TEST_F(Test, person_api_test1)
{
    Entity::Person jordy(6, "jordy") ;
    Util::PersonConverter pc ;
    std::string expected("{\"id\":6, \"name\":\"jordy\"}") ;
    ASSERT_TRUE(expected == pc.entityToJson(jordy)) ;
}

TEST_F(Test, person_api_test2)
{
    std::shared_ptr<Entity::Person> jordy = std::make_shared<Entity::Person>(6, "jordy") ;
    Util::PersonConverter pc ;
    std::string expected("{\"id\":6, \"name\":jordy}") ;
    ASSERT_FALSE(expected == pc.entityToJson(jordy)) ;
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv) ;
    return RUN_ALL_TESTS() ;
}