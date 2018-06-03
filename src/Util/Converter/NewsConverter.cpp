//
// Created by jordy on 01/06/18.
//

#include "../../../include/Util/Converter/NewsConverter.hpp"

namespace Util
{
    std::string NewsConverter::entityToJson(const Entity::News &entity)
    {
        std::string json = ("{") ;
        json += "\"id\":"+entity.getId()+std::string(",\n");
        json += "\"title\":\""+entity.getTitle()+std::string("\",\n") ;
        json += "\"date\":\""+entity.getDate()+std::string("\",\n") ;
        json += "\"text\":\""+entity.getText()+std::string("\n}") ;
        return json ;
    }

    std::string NewsConverter::entityToJson(const Entity::News *entity)
    {
        return entityToJson(*entity) ;
    }

    std::string NewsConverter::entityToJson(const std::shared_ptr<Entity::News> &entity)
    {
        return entityToJson(*entity.get()) ;
    }
}