//
// Created by jordy on 09/03/18.
//

/**
 * \file AccountConverter.Cpp
 * \brief Implémentation de la classe PersonConverter.
 * \date 06/03/18
 */

#include "../../../include/Util/Converter/AccountConverter.hpp"
#include "../../../include/Util/Converter/OperationConverter.hpp"
#include "../../../include/Util/Converter/PersonConverter.hpp"

namespace Util
{
    std::string AccountConverter::entityToJson(const Entity::Account &entity)
    {
        bool flag = false ;
        std::string json("{") ;
        PersonConverter pc ;
        OperationConverter oc ;
        json += "\"id\":"+std::to_string(entity.getId())+",\n" ;
        json += "\"customer\":"+pc.entityToJson(entity.getCustomer())+",\n" ;
        json += "\"employee\":"+pc.entityToJson(entity.getEmployee())+",\n" ;
        json += "\"dateCreation\":\""+entity.getCreationDate()+"\",\n" ;
        json += "\"balance\":"+std::to_string(entity.getBalance())+",\n" ;
        json += "\"initialBalance\":"+std::to_string(entity.getInitialBalance())+",\n" ;
        json += "\"operations\":\n\t[\n" ;
        // Les opérations sur le compte
        for(const auto operation: entity.getOperations())
        {
            flag = true ;
            json += oc.entityToJson(dynamic_cast<Entity::Operation*>(operation.get()))+",\n" ;
        }
        if(flag)
        {
            json.pop_back();
            json.pop_back();
        }
        json += "\t]\n}" ;
        return json ;
    }

    std::string AccountConverter::entityToJson(const Entity::Account *entity)
    {
        return this->entityToJson(*entity) ;
    }

    std::string AccountConverter::entityToJson(const std::shared_ptr <Entity::Account> &entity)
    {
        return this->entityToJson(*entity) ;
    }
}
