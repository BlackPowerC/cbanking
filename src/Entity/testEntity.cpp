#include "Entity.hpp"
#include <iostream>

long id = 0 ;

int main(int argc, const char *argv[])
{
    Entity::Person person(id++, "jordy") ;
    Entity::Customer customer(id++, "jordy") ;
    Entity::Customer customer2(customer) ;
    Entity::Group group(id++, "Group "+std::to_string(id++)) ;
    Entity::Group group2(group) ;
    Entity::Employee boss(id++, "dalida") ;
    Entity::Employee boss2(id++, "dalida") ;
    Entity::Employee employee1(id++, "dalila") ;
    Entity::Employee employee2(id++, "kodjo") ;
    Entity::Employee employee3(id++, "affi") ;
    Entity::Employee employee4(id++, "ablagan") ;
    boss.push_back(employee1) ;
    boss.push_back(employee2) ;
    boss.push_back(employee4) ;
    boss.push_back(employee3) ;

    std::cout << "Subordonnées du boss !\n" ;
    for(auto &e : boss.getSubordinate())
    {
        std::cout << e->getId() << " " << e->getName() << std::endl ;
    }
    boss2 = boss ;
    std::cout << "Subordonnées du boss !\n" ;
    for(auto &e : boss.getSubordinate())
    {
        std::cout << e->getId() << " " << e->getName() << std::endl ;
    }
    std::cout << "Subordonnées du boss2 !\n" ;
    for(auto &e : boss.getSubordinate())
    {
        std::cout << e->getId() << " " << e->getName() << std::endl ;
    }
    std::cout << "Autres !\n" ;
    std::cout << person.getId() << " " << person.getName() << std::endl ;
    std::cout << customer.getId() << " " << customer.getName() << std::endl ;
    std::cout << customer2.getId() << " " << customer2.getName() << std::endl ;
    std::cout << group2.getId() << " " << group2.getName() << std::endl ;
    std::cout << group.getId() << " " << group.getName() << std::endl ;
    return 0;
}
