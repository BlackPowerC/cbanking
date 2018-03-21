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

// Schema signup

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

    std::string inputJson("{\"name\":\"jordy\", \"email\":\"fatigba72@gmail.com\", \"passwd\":\"azertyuiop5468?+\", \"type\":\"employee\"}") ;

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

    std::string inputJson("{\"name\":\"jordy\", \"email\":\"fatigba72gmailcom\", \"passwd\":\"azuiop\", \"type\":\"customer\"}") ;

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
    std::string inputJson("{\"name\":\"\", \"email\":\"fatigba72gmailcom\", \"passwd\":\"op\", \"type\":\"customer\"}") ;

    ASSERT_FALSE(Util::json_is_valid(json_schema, inputJson)) ;
}

// schema signin

TEST_F(Test, testSigninSchema1)
{
    std::string json_schema ;
    std::ifstream json_schema_file("../../../resources/json schema/signin.schema.json") ;
    if(!json_schema_file)
    {
        std::exit(-1) ;
    }
    json_schema_file.seekg(0, std::ios::end) ;
    long filesize = json_schema_file.tellg()+1L ;
    json_schema.resize(filesize) ;
    json_schema_file.seekg(std::ios::beg) ;
    json_schema_file.read(&json_schema[0], filesize) ;
    std::string inputJson("{\"name\":\"\", \"email\":\"fatigba72gmailcom\", \"passwd\":\"op\", \"type\":\"customer\"}") ;

    ASSERT_FALSE(Util::json_is_valid(json_schema, inputJson)) ;
}

TEST_F(Test, testSigninSchema2)
{
    std::string json_schema ;
    std::ifstream json_schema_file("../../../resources/json schema/signin.schema.json") ;
    if(!json_schema_file)
    {
        std::exit(-1) ;
    }
    json_schema_file.seekg(0, std::ios::end) ;
    long filesize = json_schema_file.tellg()+1L ;
    json_schema.resize(filesize) ;
    json_schema_file.seekg(std::ios::beg) ;
    json_schema_file.read(&json_schema[0], filesize) ;
    std::string inputJson("{\"email\":\"fatigba72gmailcom\", \"passwd\":\"op\"}") ;

    ASSERT_FALSE(Util::json_is_valid(json_schema, inputJson)) ;
}

TEST_F(Test, testSigninSchema3)
{
    std::string json_schema ;
    std::ifstream json_schema_file("../../../resources/json schema/signin.schema.json") ;
    if(!json_schema_file)
    {
        std::exit(-1) ;
    }
    json_schema_file.seekg(0, std::ios::end) ;
    long filesize = json_schema_file.tellg()+1L ;
    json_schema.resize(filesize) ;
    json_schema_file.seekg(std::ios::beg) ;
    json_schema_file.read(&json_schema[0], filesize) ;
    std::string inputJson("{\"email\":\"fatigba72gmailcom\", \"passwd\":\"operator\"}") ;

    ASSERT_TRUE(Util::json_is_valid(json_schema, inputJson)) ;
}

int main(int argc, char *argv[])
{
    static plog::ColorConsoleAppender<plog::TxtFormatter> consoleAppender;
    plog::init(plog::verbose, &consoleAppender);
    ::testing::InitGoogleTest(&argc, argv) ;
    return RUN_ALL_TESTS() ;
}