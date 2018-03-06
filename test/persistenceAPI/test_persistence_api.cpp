#include <iostream>
#include <gtest/gtest.h>
#include "../../include/Entity/Entity.hpp"
#include "../../include/API/AccountAPI.hpp"
#include "../../include/API/OperationAPI.hpp"
#include "../../include/API/PersonAPI.hpp"

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
    Customer titi(0, "titianne") ;
    Customer baba(0, "baba") ;
    Customer barry(0, "thierrno") ;
    Employee souley(0, "souleymane") ;
    Employee adoum(0, "adoum") ;
    Employee abide(0, "abidé") ;

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
TEST_F(Test, persistence_api_select1)
{
  std::vector<std::shared_ptr<Employee> > employees ;
  employees = PersonAPI::getInstance()->findByName<Employee>("a") ;
  ASSERT_NE(0, employees.size()) ;
}

// Test de selection 2
TEST_F(Test, persistence_api_select2)
{
  ASSERT_ANY_THROW(PersonAPI::getInstance()->findAll<Person>()) ;
}

// Test de selection 2
TEST_F(Test, persistence_api_select3)
{
  ASSERT_NO_THROW(PersonAPI::getInstance()->findAll<Customer>()) ;
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
    static plog::ColorConsoleAppender<plog::TxtFormatter> consoleAppender;
	plog::init(plog::verbose, &consoleAppender);
    return RUN_ALL_TESTS() ;
}
