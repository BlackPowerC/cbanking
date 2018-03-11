//
// Created by jordy on 10/03/18.
//

/**
 * \date 10/03/18
 * \brief Ce fichier contient l'implémentation de la classe
 *        CurrentAccountConverter
 */

#include "../../../include/Util/Converter/CurrentAccountConverter.hpp"

namespace Util
{
    std::string CurrentAccountConverter::entityToJson(const Entity::CurrentAccount &entity)
    {
        std::string json(AccountConverter::entityToJson(entity)) ;
        json.pop_back() ;
        json += ",\n\"overdraft\":"+std::to_string(entity.getOverdraft())+"}" ;
        return json ;
    }

    std::string CurrentAccountConverter::entityToJson(const Entity::CurrentAccount *entity)
    {
        return this->entityToJson(*entity) ;
    }

    std::string CurrentAccountConverter::entityToJson(const std::shared_ptr <Entity::CurrentAccount> &entity)
    {
        return this->entityToJson(*entity) ;
    }
}