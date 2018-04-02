#include <iostream>
#include <gtest/gtest.h>
#include "../../include/Entity/Entity.hpp"
#include "../../include/API/AccountAPI.hpp"
#include "../../include/API/OperationAPI.hpp"
#include "../../include/API/PersonAPI.hpp"
#include "../../include/API/SessionAPI.hpp"
#include "../../include/Util/Crypto.hpp"

#include <plog/Log.h>
#include <plog/Appenders/ColorConsoleAppender.h>


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

using namespace Entity ;
using namespace API ;

// Test d'insertion
TEST_F(Test, persistence_api_insert)
{
    Customer titi(0, "titianne", "titianne@gmail.com") ;
    Customer baba(0, "baba", "baba@gmail.com") ;
    Customer barry(0, "thierrno", "thierrno@gmail.com") ;
    Employee souley(0, "souleymane", "soul@gmail.com") ;
    Employee adoum(0, "adoum", "adoum@gmail.com") ;
    Employee abide(0, "abidé", "abidé@gmail.com") ;

    souley.addSubordinate(adoum) ;
    souley.addSubordinate(abide) ;

    ASSERT_NO_THROW(PersonAPI::getInstance()->insert<Customer>(titi)) ;
    ASSERT_NO_THROW(PersonAPI::getInstance()->insert<Customer>(baba)) ;
    ASSERT_NO_THROW(PersonAPI::getInstance()->insert<Customer>(barry)) ;
    ASSERT_NO_THROW(PersonAPI::getInstance()->insert<Employee>(adoum)) ;
    ASSERT_NO_THROW(PersonAPI::getInstance()->insert<Employee>(abide)) ;
    ASSERT_NO_THROW(PersonAPI::getInstance()->insert<Employee>(souley)) ;
}

// Test de selection 1
TEST_F(Test, persistence_api_find_employee_by_name_a)
{
  ASSERT_NO_THROW(PersonAPI::getInstance()->findByName<Employee>("a")) ;
}

// Test de selection 2
TEST_F(Test, persistence_api_find_all_person)
{
  ASSERT_NO_THROW(PersonAPI::getInstance()->findAll<Person>()) ;
}

// Test de selection 3
TEST_F(Test, persistence_api_find_all_customer)
{
  ASSERT_NO_THROW(PersonAPI::getInstance()->findAll<Customer>()) ;
}

// Test de selection 4
TEST_F(Test, persistence_api_find_all_employee)
{
  ASSERT_NO_THROW(PersonAPI::getInstance()->findAll<Employee>()) ;
}

// Test de selection 5
TEST_F(Test, persistence_api_find_by_credentials_1)
{
  ASSERT_ANY_THROW(PersonAPI::getInstance()->findByCredentials<Person>("root@gmail.com", "454")) ;
}

// Test de selection 6
TEST_F(Test, persistence_api_find_by_credentials_2)
{
  ASSERT_NO_THROW(PersonAPI::getInstance()->findByCredentials<Person>("root@root.com", "454")) ;
}

// Test de selection 6
TEST_F(Test, persistence_api_find_by_token)
{
  ASSERT_NO_THROW(SessionAPI::getInstance()->findByToken<Session>(Util::hashSha512("root@root.com"))) ;
}

// Test de suppression 1
TEST_F(Test, persistence_api_delete1)
{
    ASSERT_ANY_THROW(PersonAPI::getInstance()->erase<Person>(2)) ;
}

// Test de suppression 2
TEST_F(Test, persistence_api_delete2)
{
    ASSERT_ANY_THROW(PersonAPI::getInstance()->erase<Operation>(555)) ;
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv) ;
//    static plog::ColorConsoleAppender<plog::TxtFormatter> consoleAppender;
//	plog::init(plog::verbose, &consoleAppender);
    RUN_ALL_TESTS() ;

    return 0 ;
}
