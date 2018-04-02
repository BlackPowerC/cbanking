//
// Created by jordy on 08/03/18.
//

/**
 * \brief Test de la classe CustomerConverter
 */

#include "../../../../include/Util/Converter/AccountConverter.hpp"
#include "../../../../include/Util/Converter/OperationConverter.hpp"
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

TEST_F(Test, full_operation)
{
    Entity::Operation operation ;
    Entity::Employee nikita(6, "nikita") ;
    Entity::Account account ;
    account.setId(0) ;
    account.setEmployee(nikita) ;
    account.setCreationDate("2019-03-14") ;
    account.setBalance(556.14) ;
    operation.setId(5); operation.setEmployee(nikita);
    operation.setAccountSource(account);
    operation.setDate("02-04-2018 21:06");
    operation.setMontant(55.64) ;
    Util::OperationConverter oc;
    // Le Test
    rapidjson::Document doc ;
    ASSERT_FALSE(doc.Parse(oc.entityToJson(operation).c_str()).HasParseError()) ;
}
/*
TEST_F(Test, account_without_customer )
{

}

TEST_F(Test, simple_account)
{

}
*/

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv) ;
    return RUN_ALL_TESTS() ;
}

