#include <iostream>
#include <gtest/gtest.h>
#include "../../include/Entity/Entity.hpp"

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

TEST_F(Test, session)
{
  Entity::Session s ;
  ASSERT_FALSE(s.getEnd() == s.getBegin()) ;
}

int main(int argc, char *argv[])
{
  ::testing::InitGoogleTest(&argc, argv) ;
  return RUN_ALL_TESTS();
}
