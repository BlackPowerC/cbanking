#ifndef PERSON_CONVERTER_HPP_INCLUDED
#define PERSON_CONVERTER_HPP_INCLUDED

#include "Converter.hpp"

namespace Util
{
    class PersonConverter: public Converter<Entity::Person>
    {
    public:
        virtual std::string entityToJson(const Entity::Person &entity) ;

        virtual std::string entityToJson(const Entity::Person *entity) ;

        virtual std::string entityToJson(const std::shared_ptr <Entity::Person> &entity) ;
    };
}



#endif // PERSON_CONVERTER_HPP_INCLUDED