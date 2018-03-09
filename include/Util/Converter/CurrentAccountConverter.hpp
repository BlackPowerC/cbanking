#ifndef CACCOUNT_CONVERTER_HPP_INCLUDED
#define CACCOUNT_CONVERTER_HPP_INCLUDED

#include "AccountConverter.hpp"

namespace Util
{
    class CurrentAccountConverter: public AccountConverter
    {
    public:
        virtual std::string entityToJson(const Entity::CurrentAccount &entity) ;

        virtual std::string entityToJson(const Entity::CurrentAccount *entity) ;

        virtual std::string entityToJson(const std::shared_ptr <Entity::CurrentAccount> &entity) ;
    };
}



#endif // CACCOUNT_CONVERTER_HPP_INCLUDED