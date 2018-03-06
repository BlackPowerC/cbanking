#ifndef CUSTOMER_CONVERTER_HPP_INCLUDED
#define CUSTOMER_CONVERTER_HPP_INCLUDED

#include "Converter.hpp"

namespace Util
{
    class CustomerConverter: public Converter<Entity::Customer>
    {
    public:
        virtual void entityToJson(const Entity::Customer &entity);

        virtual void entityToJson(const Entity::Customer *entity) ;

        virtual void entityToJson(const std::shared_ptr <Entity::Customer> &entity) ;
    };
}



#endif // CUSTOMER_CONVERTER_HPP_INCLUDED