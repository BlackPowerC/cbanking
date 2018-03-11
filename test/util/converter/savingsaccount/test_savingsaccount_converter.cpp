//
// Created by jordy on 08/03/18.
//

/**
 * \brief Test de la classe CurrentAccountConverter
 */

#include "../../../../include/Util/Converter/SavingsAccountConverter.hpp"
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

TEST_F(Test, full_account)
{
    Entity::Customer harimann(5, "harimann") ;
    Entity::Employee nikita(6, "nikita") ;
    Entity::SavingsAccount account ;
    account.setId(0) ;
    account.setCustomer(harimann) ;
    account.setEmployee(nikita) ;
    account.setCreationDate("2019-03-14") ;
    account.setBalance(556.14) ;
    account.setRate(100.5) ;
    Util::SavingsAccountConverter cac ;
    // Le Test
    rapidjson::Document doc ;
    ASSERT_FALSE(doc.Parse(cac.entityToJson(account).c_str()).HasParseError()) ;
}

TEST_F(Test, account_without_customer )
{
    Entity::Employee nikita(6, "nikita") ;
    Entity::SavingsAccount account ;
    account.setId(0) ;
    account.setEmployee(nikita) ;
    account.setCreationDate("2019-03-14") ;
    account.setBalance(556.14) ;
    account.setRate(100.5) ;
    Util::SavingsAccountConverter cac ;
    // Le Test
    rapidjson::Document doc ;
    ASSERT_FALSE(doc.Parse(cac.entityToJson(account).c_str()).HasParseError()) ;
}

TEST_F(Test, simple_account)
{
    Entity::SavingsAccount account ;
    account.setId(0) ;
    account.setCreationDate("2019-03-14") ;
    account.setBalance(556.14) ;
    account.setRate(100.5) ;
    Util::SavingsAccountConverter cac ;
    // Le Test
    rapidjson::Document doc ;
    ASSERT_FALSE(doc.Parse(cac.entityToJson(account).c_str()).HasParseError()) ;
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv) ;
    return RUN_ALL_TESTS() ;
}

