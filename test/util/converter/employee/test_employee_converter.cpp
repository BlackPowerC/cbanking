//
// Created by jordy on 08/03/18.
//

/**
 * \brief Test de la classe CustomerConverter
 */

#include "../../../../include/Util/Converter/EmployeeConverter.hpp"
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

TEST_F(Test, simple_employee)
{
    Entity::Employee employee(5, "jarvis") ;
    rapidjson::Document doc ;
    Util::EmployeeConverter ev ;
    std::cout << ev.entityToJson(employee) <<"\n" ;
    ASSERT_FALSE(doc.Parse(ev.entityToJson(employee).c_str()).HasParseError()) ;
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv) ;
    return RUN_ALL_TESTS() ;
}

