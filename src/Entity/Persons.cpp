#include "Persons.hpp"

namespace Entity
{
/* Classe Person */
Person::Person(long _id, std::string _name): id(_id), name(_name)
{}

Person::Person(const Person &t_person)
{
    this->id = t_person.id ;
    this->name = t_person.name ;
}

Person::Person(const Person *p_person)
{
    this->id = p_person->id ;
    this->name = p_person->name ;
}

void Person::setId(long _id)
{
    this->id = _id ;
}

long Person::getId() const
{
    return this->id ;
}

void Person::setName(std::string name)
{
    this->name = name ;
}

std::string Person::getName() const
{
    return this->name ;
}

/* Classe Customer */
Customer::Customer(long _id, std::string _name): Person(_id, _name)
{}

Customer::Customer(const Customer *p_customer): Person(p_customer)
{}

Customer::Customer(const Customer &t_customer): Person(t_customer)
{}

/* Classe Employe */
Employee::Employee(long _id, std::string _name): Person(_id, _name)
{}

Employee::Employee(const Employee *p_employee): Person(p_employee)
{}

Employee::Employee(const Employee &t_employee): Person(t_employee)
{}

void Employee::push_back(Employee t_another)
{
    this->subordinate.push_back(t_another) ;
}

std::list<Employee> &Employee::getSubordinate()
{
    return this->subordinate ;
}

void Employee::remove(long id)
{
    for(std::list<Employee>::iterator it(this->subordinate.begin()); it != this->subordinate.end(); it++)
    {
        if(it->id == id)
        {
            this->subordinate.erase(it) ;
            break ;
        }
    }
}

void Employee::setSubordinate(const std::list<Employee> &t_another)
{
    this->subordinate = std::move(t_another) ;
}

/* Classe Group */
Group::Group(long _id, std::string _name): id(_id), name(_name)
{}

Group::Group(const Group *p_group)
{
    *this = *p_group ;
}

Group::Group(const Group &t_group)
{
    *this = t_group ;
}

void Group::push_back(Employee employee)
{
    this->member.push_back(employee) ;
}

std::list<Employee> &Group::getMember()
{
    return this->member ;
}

void Group::remove(long id)
{
    for(std::list<Employee>::iterator it(this->member.begin()); it != this->member.end(); it++)
    {
        if(it->getId() == id)
        {
            this->member.erase(it) ;
            break ;
        }
    }
}

void Group::setMember(const std::list<Employee> &t_another)
{
    this->member = std::move(t_another) ;
}

void Group::setId(long _id)
{
    this->id = _id ;
}

long Group::getId() const
{
    return this->id ;
}

void Group::setName(std::string name)
{
    this->name = name ;
}

std::string Group::getName() const
{
    return this->name ;
}

}
