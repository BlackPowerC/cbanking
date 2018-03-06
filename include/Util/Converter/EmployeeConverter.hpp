#ifndef EMPLOYEE_CONVERTER_HPP_INCLUDED
#define EMPLOYEE_CONVERTER_HPP_INCLUDED

#include "Converter.hpp"

namespace Util
{
    class EmployeeConverter: public Converter<Entity::Employee>
    {
    public:
        virtual std::string entityToJson(const Entity::Employee &entity) ;

        virtual std::string entityToJson(const Entity::Employee *entity) ;

        virtual std::string entityToJson(const std::shared_ptr <Entity::Employee> &entity) ;
    };
}

#endif // EMPLOYEE_CONVERTER_HPP_INCLUDED