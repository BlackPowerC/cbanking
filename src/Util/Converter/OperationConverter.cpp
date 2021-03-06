//
// Created by jordy on 02/04/18.
//

#include "../../../include/Util/Converter/OperationConverter.hpp"

namespace Util
{
    std::string OperationConverter::entityToJson(const Entity::Operation &entity)
    {
        std::string json("{\n\t") ;
        json += "\"id\":"+std::to_string(entity.getId())+",\n";
        json += "\"employee\":"+PersonConverter().entityToJson(entity.getEmployee())+",\n" ;
        json += "\"date\":\""+entity.getDate()+"\",\n" ;
        json += "\"type\":\""+entity.getTypeOperation()+"\",\n" ;
        json += "\"amount\":"+std::to_string(entity.getMontant())+"\n}" ;

        return json ;
    }

    std::string OperationConverter::entityToJson(const Entity::Operation *entity)
    {
        return this->entityToJson(*entity) ;
    }

    std::string OperationConverter::entityToJson(const std::shared_ptr<Entity::Operation> &entity)
    {
        return this->entityToJson(*entity) ;
    }
}