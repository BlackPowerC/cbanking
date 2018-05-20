//
// Created by jordy on 02/04/18.
//

#ifndef OPERATIONCONVERTER_HPP
#define OPERATIONCONVERTER_HPP

#include "AccountConverter.hpp"
#include "PersonConverter.hpp"

namespace Util
{
    /**
     * @class OperationConverter
     * @brief Cette classe est la convertisseur de la classe Operation.
     */
    class OperationConverter: public Converter<Entity::BaseOperation>
    {
    public:
        /**
         * \brief Cette fonction convertit une instance
         *        de Operation en format JSON.
         * @param entity
         * @return Une chaine de caractère formaté en JSON.
         */
        virtual std::string entityToJson(const Entity::BaseOperation &entity) ;

        virtual std::string entityToJson(const Entity::BaseOperation *entity) ;

        virtual std::string entityToJson(const std::shared_ptr<Entity::BaseOperation> &entity) ;
    };
}

#endif //CBANKING_REST_API_OPERATIONCONVERTER_HPP
