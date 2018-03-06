#ifndef SACCOUNT_CONVERTER_HPP_INCLUDED
#define SACCOUNT_CONVERTER_HPP_INCLUDED

#include "Converter.hpp"

namespace Util
{
    class SavingsAccountConverter: public Converter<Entity::SavingsAccount>
    {
    public:
        /**
         * \brief Cette fonction convertit une entité en format JSON
         * @param entity Une instance de SavingsAccount.
         * @return Une chaine de caractère formaté en JSON.
         */
        virtual std::string entityToJson(const Entity::SavingsAccount &entity) ;

        virtual std::string entityToJson(const Entity::SavingsAccount *entity) ;

        virtual std::string entityToJson(const std::shared_ptr <Entity::SavingsAccount> &entity) ;
    };
}

#endif // SACCOUNT_CONVERTER_HPP_INCLUDED