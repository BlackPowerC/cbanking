#ifndef ACCOUNT_CONVERTER_HPP_INCLUDED
#define ACCOUNT_CONVERTER_HPP_INCLUDED

#include "Converter.hpp"

namespace Util
{
    class AccountConverter: public Converter<Entity::Account>
    {
    public:
        virtual std::string entityToJson(const Entity::Account &entity) ;

        virtual std::string entityToJson(const Entity::Account *entity) ;

        virtual std::string entityToJson(const std::shared_ptr <Entity::Account> &entity) ;
    };
}



#endif // ACCOUNT_CONVERTER_HPP_INCLUDED