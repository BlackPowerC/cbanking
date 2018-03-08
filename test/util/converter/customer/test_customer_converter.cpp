//
// Created by jordy on 08/03/18.
//

/**
 * \brief Test de la classe CustomerConverter
 */

#include "../../../../include/Util/Converter/CustomerConverter.hpp"
#include <gtest/gtest.h>
#include <rapidjson/rapidjson.h>
#include <iostream>

int main(void)
{
    Entity::Employee jonas(5, "jonas") ;
    Entity::Customer jordy(36, "jordy") ;
    Entity::CurrentAccount account ;
    account.setId(58) ;
    account.setCustomer(jordy) ;
    account.setEmployee(jonas) ;
    account.setBalance(789.6) ;
    account.setCreationDate("2017-09-11") ;
    jordy.push_back(account) ;
    jordy.push_back(account) ;

    Util::CustomerConverter cc ;
    std::cout << cc.entityToJson(jordy) <<"\n";

    return 0 ;

}

