//
// Created by jordy on 10/03/18.
//

/**
 * \date 10/03/18
 * \brief Ce fichier contient l'implémentation de la classe
 *        CurrentAccountConverter
 */

#include "../../../include/Util/Converter/SavingsAccountConverter.hpp"

namespace Util
{
    std::string SavingsAccountConverter::entityToJson(const Entity::SavingsAccount &entity)
    {
        std::string json(AccountConverter::entityToJson(entity)) ;
        json.pop_back() ;
        json += ",\n\"rate\":"+std::to_string(entity.getRate())+"}" ;
        return json ;
    }

    std::string SavingsAccountConverter::entityToJson(const Entity::SavingsAccount *entity)
    {
        return this->entityToJson(*entity) ;
    }

    std::string SavingsAccountConverter::entityToJson(const std::shared_ptr <Entity::SavingsAccount> &entity)
    {
        return this->entityToJson(*entity) ;
    }
}