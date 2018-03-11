#ifndef SACCOUNT_CONVERTER_HPP_INCLUDED
#define SACCOUNT_CONVERTER_HPP_INCLUDED

#include "AccountConverter.hpp"

namespace Util
{
    class SavingsAccountConverter: public AccountConverter
    {
    public:
        /**
         * \brief Cette fonction convertit une instance
         *        de SavingsAccount en format JSON
         * @param entity Une instance de SavingsAccount.
         * @return Une chaine de caractère formaté en JSON.
         */
        virtual std::string entityToJson(const Entity::SavingsAccount &entity) ;

        virtual std::string entityToJson(const Entity::SavingsAccount *entity) ;

        virtual std::string entityToJson(const std::shared_ptr <Entity::SavingsAccount> &entity) ;
    };
}

#endif // SACCOUNT_CONVERTER_HPP_INCLUDED