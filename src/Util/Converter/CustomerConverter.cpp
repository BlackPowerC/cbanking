//
// Created by jordy on 07/03/18.
//

#include "../../../include/Util/Converter/CustomerConverter.hpp"

namespace Util
{
    std::string CustomerConverter::entityToJson(const Entity::Customer &entity)
    {
        if(!entity.getAccounts().size())
        {
            return PersonConverter::entityToJson(entity) ;
        }
        std::string json("{\n") ;
        json += "\"id\":"+std::to_string(entity.getId())+",\n" ;
        json += "\"name\":\""+entity.getName()+"\",\n" ;
        json += "\"surname\":\""+entity.getSurname()+"\",\n" ;
        json += "\"email\":\""+entity.getEmail()+"\",\n" ;
        json += "\"passwd\":\""+entity.getPasswd()+"\",\n" ;
        json += "\"sexe\":\""+entity.getSexe()+"\",\n" ;
        json += "\"accounts\":\n\t[\n" ;
        for(auto &accounts: entity.getAccounts())
        {
            json += "\t{\"id\":"+std::to_string(accounts->getId())+", " ;
            json += "\"creationDate\":\""+accounts->getCreationDate()+"\", " ;
            json += "\"balance\":"+std::to_string(accounts->getBalance())+"},\n" ;
        }
        json.pop_back() ;
        json.pop_back() ;
        json += "\n\t]\n}" ;

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
