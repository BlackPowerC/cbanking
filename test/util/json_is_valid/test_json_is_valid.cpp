//
// Created by jordy on 21/03/18.
//

/**
 * \brief Test de la fonction json_is_valid.
 */

#include "../../../include/Util/JSONValidator.hpp"
#include "../../../include/Util/RegularFile.hpp"

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
    std::string json_schema = Util::fromFileToString("../../../resources/json schema/signup.schema.json") ;

    std::string inputJson("{clé:valeur}") ;

    ASSERT_FALSE(Util::json_is_valid(json_schema, inputJson)) ;
}

TEST_F(Test, testSignupSchema2)
{
    std::string json_schema = Util::fromFileToString("../../../resources/json schema/signup.schema.json") ;

    std::string inputJson("{\"name\":\"jordy\", \"email\":\"fatigba72@gmail.com\", \"passwd\":\"azertyuiop5468?+\", \"type\":\"employee\"}") ;

    ASSERT_TRUE(Util::json_is_valid(json_schema, inputJson)) ;
}

TEST_F(Test, testSignupSchema3)
{
    std::string json_schema = Util::fromFileToString("../../../resources/json schema/signup.schema.json") ;

    std::string inputJson("{\"name\":\"jordy\", \"email\":\"fatigba72gmailcom\", \"passwd\":\"azu6\", \"type\":\"customer\"}") ;

    ASSERT_FALSE(Util::json_is_valid(json_schema, inputJson)) ;
}

TEST_F(Test, testSignupSchema4)
{
    std::string json_schema = Util::fromFileToString("../../../resources/json schema/signup.schema.json") ;

    std::string inputJson("{\"name\":\"\", \"email\":\"fatigba72gmail.com\", \"passwd\":\"op\", \"type\":\"customer\"}") ;

    ASSERT_FALSE(Util::json_is_valid(json_schema, inputJson)) ;
}

// schema signin

TEST_F(Test, testSigninSchema1)
{
    std::string json_schema = Util::fromFileToString("../../../resources/json schema/signin.schema.json") ;

    std::string inputJson("{\"name\":\"\", \"email\":\"fatigba72gmailcom\", \"passwd\":\"op\", \"type\":\"customer\"}") ;

    ASSERT_FALSE(Util::json_is_valid(json_schema, inputJson)) ;
}

TEST_F(Test, testSigninSchema2)
{
    std::string json_schema = Util::fromFileToString("../../../resources/json schema/signin.schema.json") ;

    std::string inputJson("{\"email\":\"fatigba72gmailcom\", \"passwd\":\"op\"}") ;

    ASSERT_FALSE(Util::json_is_valid(json_schema, inputJson)) ;
}

TEST_F(Test, testSigninSchema3)
{
    std::string json_schema = Util::fromFileToString("../../../resources/json schema/signin.schema.json") ;

    std::string inputJson("{\"email\":\"fatigba72gmailcom\", \"passwd\":\"operator\"}") ;

    ASSERT_TRUE(Util::json_is_valid(json_schema, inputJson)) ;
}

// Account signup

TEST_F(Test, testAccountSchema1)
{
    std::string json_schema(Util::fromFileToString("../../../resources/json schema/account.schema.json")) ;

    std::string inputJson(Util::fromFileToString("account_test1.json")) ;

    ASSERT_TRUE(Util::json_is_valid(json_schema, inputJson)) ;
}

TEST_F(Test, testAccountSchema2)
{
    std::string json_schema(Util::fromFileToString("../../../resources/json schema/account.schema.json")) ;

    std::string inputJson(Util::fromFileToString("account_test2.json")) ;

    ASSERT_FALSE(Util::json_is_valid(json_schema, inputJson)) ;
}

TEST_F(Test, testAccountSchema3)
{
    std::string json_schema(Util::fromFileToString("../../../resources/json schema/account.schema.json")) ;

    std::string inputJson(Util::fromFileToString("account_test3.json")) ;

    ASSERT_FALSE(Util::json_is_valid(json_schema, inputJson)) ;
}

TEST_F(Test, testAccountSchema4)
{
    std::string json_schema(Util::fromFileToString("../../../resources/json schema/account.schema.json")) ;

    std::string inputJson(Util::fromFileToString("account_test4.json")) ;

    ASSERT_FALSE(Util::json_is_valid(json_schema, inputJson)) ;
}

TEST_F(Test, testAccountSchema5)
{
    std::string json_schema(Util::fromFileToString("../../../resources/json schema/account.schema.json")) ;

    std::string inputJson(Util::fromFileToString("account_test5.json")) ;

    ASSERT_FALSE(Util::json_is_valid(json_schema, inputJson)) ;
}

int main(int argc, char *argv[])
{
//    static plog::ColorConsoleAppender<plog::TxtFormatter> consoleAppender;
//    plog::init(plog::verbose, &consoleAppender);
    ::testing::InitGoogleTest(&argc, argv) ;
    return RUN_ALL_TESTS() ;
}