//
// Created by jordy on 06/03/18.
//

/**
 * \file PersonConverter.hpp
 * \brief Implémentation de la classe PersonConverter.
 * \date 06/03/18
 */

#include "../../../include/Util/Converter/PersonConverter.hpp"

namespace Util
{
    std::string PersonConverter::entityToJson(const Entity::Person &entity)
    {
        std::string json("{") ;
        json += "\"id\":"+std::to_string(entity.getId())+", " ;
        json += std::string("\"name\":")+std::string("\""+entity.getName())+std::string("\", ") ;
        json += std::string("\"surname\":")+std::string("\""+entity.getSurname())+std::string("\", ") ;
        json += std::string("\"email\":")+std::string("\""+entity.getEmail())+std::string("\", ") ;
        json += std::string("\"passwd\":")+std::string("\""+entity.getPasswd())+std::string("\"") ;
        json += "}" ;
        return json ;
    }

    std::string PersonConverter::entityToJson(const Entity::Person *entity)
    {
        return this->entityToJson(*entity) ;
    }

    std::string PersonConverter::entityToJson(const std::shared_ptr <Entity::Person> &entity)
    {
        return this->entityToJson(*entity) ;
    }
}