//
// Created by jordy on 07/03/18.
//

#include "../../../include/Util/Converter/CustomerConverter.hpp"

namespace Util
{
    std::string CustomerConverter::entityToJson(const Entity::Customer &entity)
    {
        std::string json("{\n") ;
        bool flag = false ;
        json += "\"id\":"+std::to_string(entity.getId())+",\n" ;
        json += "\"name\":\""+entity.getName()+"\",\n" ;
        json += "\"accounts\":\n\t{\n" ;
        for(auto &accounts: entity.getAccounts())
        {
            flag = true ;
            json += "\t[\"id\":"+std::to_string(accounts->getId())+",\n" ;
            json += "\t\"creationDate\":\""+accounts->getCreationDate()+"\",\n" ;
            json += "\t\"balance\":"+std::to_string(accounts->getBalance())+"],\n" ;
        }
        if(flag)
        {
            json.pop_back() ;
            json.pop_back() ;
        }
        json += "\n\t}\n}" ;

        return json ;
    }

    std::string CustomerConverter::entityToJson(const Entity::Customer *entity)
    {
        return this->entityToJson(*entity) ;
    }

    std::string CustomerConverter::entityToJson(const std::shared_ptr <Entity::Customer> &entity)
    {
        return this->entityToJson(*entity) ;
    }
}