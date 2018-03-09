#ifndef CUSTOMER_CONVERTER_HPP_INCLUDED
#define CUSTOMER_CONVERTER_HPP_INCLUDED

#include "PersonConverter.hpp"

namespace Util
{
    class CustomerConverter: public PersonConverter
    {
    public:
        virtual std::string entityToJson(const Entity::Customer &entity);

        virtual std::string entityToJson(const Entity::Customer *entity) ;

        virtual std::string entityToJson(const std::shared_ptr <Entity::Customer> &entity) ;
    };
}

#endif // CUSTOMER_CONVERTER_HPP_INCLUDED