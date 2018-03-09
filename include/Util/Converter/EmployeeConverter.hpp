#ifndef EMPLOYEE_CONVERTER_HPP_INCLUDED
#define EMPLOYEE_CONVERTER_HPP_INCLUDED

#include "PersonConverter.hpp"

namespace Util
{
    class EmployeeConverter: public PersonConverter
    {
    public:
        virtual std::string entityToJson(const Entity::Employee &entity) ;

        virtual std::string entityToJson(const Entity::Employee *entity) ;

        virtual std::string entityToJson(const std::shared_ptr <Entity::Employee> &entity) ;
    };
}

#endif // EMPLOYEE_CONVERTER_HPP_INCLUDED