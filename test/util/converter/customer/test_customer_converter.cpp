//
// Created by jordy on 08/03/18.
//

/**
 * \brief Test de la classe CustomerConverter
 */

#include "../../../../include/Util/Converter/CustomerConverter.hpp"
#include <gtest/gtest.h>
#include <rapidjson/rapidjson.h>
#include <rapidjson/document.h>
#include <iostream>

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

TEST_F(Test, customer_with_account)
{
    Entity::Customer jordy(36, "jordy") ;
    Entity::CurrentAccount account ;
    account.setId(58) ;
    account.setBalance(789.6) ;
    account.setCreationDate("2017-09-11") ;
    jordy.push_back(account) ;
    jordy.push_back(account) ;
    // Le test
    Util::CustomerConverter cc ;
    rapidjson::Document document ;
    ASSERT_FALSE(document.Parse(cc.entityToJson(jordy).c_str()).HasParseError()) ;
}

TEST_F(Test, customer_without_account)
{
    Entity::Customer jordy(36, "jordy") ;
    // Le test
    Util::CustomerConverter cc ;
    rapidjson::Document document ;
    ASSERT_FALSE(document.Parse(cc.entityToJson(jordy).c_str()).HasParseError()) ;
}

TEST_F(Test, customer_without_account_and_name)
{
    Entity::Customer jordy(36, "") ;
    // Le test
    Util::CustomerConverter cc ;
    rapidjson::Document document ;
    ASSERT_FALSE(document.Parse(cc.entityToJson(jordy).c_str()).HasParseError()) ;
}

TEST_F(Test, customer_without_account_and_id_and_name)
{
    Entity::Customer jordy ;
    // Le test
    Util::CustomerConverter cc ;
    rapidjson::Document document ;
    ASSERT_FALSE(document.Parse(cc.entityToJson(jordy).c_str()).HasParseError()) ;
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv) ;
    return RUN_ALL_TESTS() ;
}

