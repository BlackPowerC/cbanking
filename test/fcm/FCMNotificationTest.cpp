//
// Created by jordy on 18/05/18.
//

#include <iostream>
#include <gtest/gtest.h>
#include "../../include/Rest/FCMNotification.hpp"

class Test: public ::testing::Test
{
public:
    virtual void setUp() {}
    virtual void tearDown() {}
};

TEST_F(Test, test_FCMNotification_sendNotificationToSpecificDevice1)
{
    ASSERT_ANY_THROW(Fcm::FCMNotification::getInstance()->sendMessageToSpecificDevice("", "message")) ;
}

TEST_F(Test, test_FCMNotification_sendNotificationToSpecificDevice2)
{
    ASSERT_NO_THROW(Fcm::FCMNotification::getInstance()->sendMessageToSpecificDevice("token", "message")) ;
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv) ;
    return RUN_ALL_TESTS() ;
}