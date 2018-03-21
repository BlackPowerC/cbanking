//
// Created by jordy on 21/03/18.
//

/**
 * \brief Test de la fonction json_is_valid.
 */

#include "../../../include/Util/JSONValidator.hpp"

#include <plog/Log.h>
#include <plog/Appenders/ColorConsoleAppender.h>
#include <fstream>
#include <gtest/gtest.h>

class Test: public ::testing::Test
{
public:
    virtual void setUp() {}
    virtual void tearDown() {}
};

TEST_F(Test, testSignupSchema1)
{
    std::string json_schema ;
    std::ifstream json_schema_file("../../../resources/json schema/signup.schema.json") ;
    if(!json_schema_file)
    {
        std::exit(-1) ;
    }
    json_schema_file.seekg(std::ios::end) ;
    long filesize = json_schema_file.tellg()+1L ;
    json_schema.resize(filesize) ;
    json_schema_file.seekg(std::ios::beg) ;
    json_schema_file.read(&json_schema[0], filesize) ;

    std::string inputJson("{clé:valeur}") ;

    ASSERT_FALSE(Util::json_is_valid(json_schema, inputJson)) ;
}

TEST_F(Test, testSignupSchema2)
{
    std::string json_schema ;
    std::ifstream json_schema_file("../../../resources/json schema/signup.schema.json") ;
    if(!json_schema_file)
    {
        std::exit(-1) ;
    }
    json_schema_file.seekg(0, std::ios::end) ;
    long filesize = json_schema_file.tellg()+1L ;
    json_schema.resize(filesize) ;
    json_schema_file.seekg(std::ios::beg) ;
    json_schema_file.read(&json_schema[0], filesize) ;

    std::string inputJson("{\"name\":\"jordy\", \"email\":\"fatigba72@gmail.com\", \"passwd\":\"azertyuiop\", \"type\":\"client\"}") ;

    ASSERT_TRUE(Util::json_is_valid(json_schema, inputJson)) ;
}

TEST_F(Test, testSignupSchema3)
{
    std::string json_schema ;
    std::ifstream json_schema_file("../../../resources/json schema/signup.schema.json") ;
    if(!json_schema_file)
    {
        std::exit(-1) ;
    }
    json_schema_file.seekg(0, std::ios::end) ;
    long filesize = json_schema_file.tellg()+1L ;
    json_schema.resize(filesize) ;
    json_schema_file.seekg(std::ios::beg) ;
    json_schema_file.read(&json_schema[0], filesize) ;

    std::string inputJson("{\"name\":\"jordy\", \"email\":\"fatigba72gmailcom\", \"passwd\":\"azuiop\", \"type\":\"client\"}") ;

    ASSERT_FALSE(Util::json_is_valid(json_schema, inputJson)) ;
}

TEST_F(Test, testSignupSchema4)
{
    std::string json_schema ;
    std::ifstream json_schema_file("../../../resources/json schema/signup.schema.json") ;
    if(!json_schema_file)
    {
        std::exit(-1) ;
    }
    json_schema_file.seekg(0, std::ios::end) ;
    long filesize = json_schema_file.tellg()+1L ;
    json_schema.resize(filesize) ;
    json_schema_file.seekg(std::ios::beg) ;
    json_schema_file.read(&json_schema[0], filesize) ;
    std::string inputJson("{\"name\":\"\", \"email\":\"fatigba72gmailcom\", \"passwd\":\"op\", \"type\":\"client\"}") ;

    ASSERT_FALSE(Util::json_is_valid(json_schema, inputJson)) ;
}

int main(int argc, char *argv[])
{
    static plog::ColorConsoleAppender<plog::TxtFormatter> consoleAppender;
    plog::init(plog::verbose, &consoleAppender);
    ::testing::InitGoogleTest(&argc, argv) ;
    return RUN_ALL_TESTS() ;
}