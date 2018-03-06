#ifndef CACCOUNT_CONVERTER_HPP_INCLUDED
#define CACCOUNT_CONVERTER_HPP_INCLUDED

#include "Converter.hpp"

namespace Util
{
    class CurrentAccountConverter: public Converter<Entity::CurrentAccount>
    {
    public:
        virtual std::string entityToJson(const Entity::CurrentAccount &entity) ;

        virtual std::string entityToJson(const Entity::CurrentAccount *entity) ;

        virtual std::string entityToJson(const std::shared_ptr <Entity::CurrentAccount> &entity) ;
    };
}



#endif // CACCOUNT_CONVERTER_HPP_INCLUDED