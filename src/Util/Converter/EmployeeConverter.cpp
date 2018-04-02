//
// Created by jordy on 09/03/18.
//

/**
 * \file PersonConverter.hpp
 * \brief Implémentation de la classe EmployeeConverter.
 * \date 09/03/18
 */

#include "../../../include/Util/Converter/EmployeeConverter.hpp"
#include "../../../include/Util/Converter/OperationConverter.hpp"

namespace Util
{
    std::string EmployeeConverter::entityToJson(const Entity::Employee &entity)
    {
        bool flag = false;
        OperationConverter oc ;
        std::string json("{\n") ;
        json += "\"id\":"+std::to_string(entity.getId())+",\n" ;
        json += "\"name\":\""+entity.getName()+"\",\n" ;
        json += "\"email\":\""+entity.getEmail()+"\",\n" ;
        json += "\"passwd\":\""+entity.getPasswd()+"\",\n" ;
        json += "\"accounts\":\n\t[\n" ;
        // Les comptes créer par l'employée
        for(auto accounts: entity.getAccounts())
        {
            flag = true ;
            json += "\t{\"id\":"+std::to_string(accounts->getId())+", " ;
            json += "\"creationDate\":\""+accounts->getCreationDate()+"\"},\n" ;
        }
        if(flag)
        {
            json.pop_back();
            json.pop_back();
        }
        json += "\t],\n" ;
        flag = false ;
        // Ces subordonnés
        json += "\"subordinates\":\n\t[\n" ;
        for(auto subordinate: entity.getSubordinate())
        {
            flag = true ;
            json += "\t{\"id\":"+std::to_string(subordinate->getId())+", " ;
            json += "\"name\":\""+subordinate->getName()+"\"},\n" ;
        }
        if(flag)
        {
            json.pop_back();
            json.pop_back();
        }
        json += "\t],\n" ;
        flag = false ;
        // Les opérations faires
        json += "\"operations\":\n\t[\n" ;
        for(auto operation: entity.getOperations())
        {
            flag = true ;
            json += oc.entityToJson(dynamic_cast<Entity::Operation*>(operation.get()))+",\n" ;
        }
        // fin de la convertion
        if(flag)
        {
            json.pop_back();
            json.pop_back();
        }
        json += "\t]\n}" ;

        return json ;
    }

    std::string EmployeeConverter::entityToJson(const Entity::Employee *entity)
    {
        return this->entityToJson(*entity) ;
    }

    std::string EmployeeConverter::entityToJson(const std::shared_ptr <Entity::Employee> &entity)
    {
        return this->entityToJson(*entity) ;
    }
}