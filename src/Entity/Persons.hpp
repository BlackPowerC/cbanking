#ifndef PERSON_DEF
#define PERSON_DEF

#include <string>
#include <list>
#include <algorithm>

/**
 * \file Persons.hpp
 * \author Jordy Fatigba fatigba72@gmail.com
 * \date 22-02-2018
 * \brief Cet espace de nom contient la définition des entités
 * du programme.
 */

namespace Entity
{

/**
 * \class Person
 * \brief Classe représantant une personne.
 */

class Person
{
protected:
    long id ;
    std::string name ;
public:
    /**
     * \fn Person(long _id = 0, std::string _name= "")
     * \brief Constructeur par défaut de la classe.
     * \param _id ID de la personne, zéro par défaut.
     * \param _name name de la personne, "" par défaut.
     */
    Person(long _id =0, std::string _name = "") ;
    /**
     * \fn Person(Person &t_person)
     * \brief Constructeur par recopie de la classe.
     * \param t_person Référence sur une instance Person.
     */
    Person(const Person &t_person) ;
    /**
     * \fn Person(Person *p_person)
     * \brief Constructeur par recopie de la classe.
     * \param p_person Pointeur sur une instance Person.
     */
    Person(const Person *p_person) ;

    /* getters setters */
    void setId(long _id) ;
    long getId() const ;
    std::string getName() const ;
    void setName(std::string _name) ;
};

/**
 * \class Customer
 * \brief Classe représentant un client.
 */
class Customer: public Person
{
public:
    /**
    * \fn Customer(long _id = 0, std::string _name= "")
    * \brief Constructeur par défaut de la classe.
    * \param _id ID du client, zéro par défaut.
    * \param _name nom du client, "" par défaut.
    */
    Customer(long _id =0, std::string _name = "") ;
    /**
     * \fn Customer(Customer &t_Customer)
     * \brief Constructeur par recopie de la classe.
     * \param t_customer Référence sur une instance Customer.
     */
    Customer(const Customer &t_customer) ;
    /**
     * \fn Customer(Customer *p_Customer)
     * \brief Constructeur par recopie de la classe.
     * \param p_Customer Pointeur sur une instance Customer.
     */
    Customer(const Customer *p_customer) ;
};

/**
 * \class Customer
 * \brief Classe représentant un employé.
 */
class Employee: public Person
{
private:
    std::list<Employee> subordinate ; /*!< Liste des employés subordonnées */
public:
    /**
    * \fn Employee(long _id = 0, std::string _name= "", std::list<Employee> _subordonne)
    * \brief Constructeur par défaut de la classe.
    * \param _id ID du l'employé, zéro par défaut.
    * \param _name nom de l'employé, "" par défaut.
    */
    Employee(long _id =0, std::string _name = "") ;
    /**
     * \fn Employee(Employee &t_employee)
     * \brief Constructeur par recopie de la classe.
     * \param t_employee Référence sur une instance Employee.
     */
    Employee(const Employee &t_employee) ;
    /**
     * \fn Employee(Employee *p_Employee)
     * \brief Constructeur par recopie de la classe.
     * \param p_Employee Pointeur sur une instance Employee.
     */
    Employee(const Employee *p_employee) ;

    /**
     * \fn void remove(long id)
     * \brief Supprime un employé de la liste des subordonnées.
     * \param id ID de l'employé à supprimer ;
     */
    void remove(long id) ;

    /**
     * \fn void push_back(Employee t_another)
     * \brief Ajoute un employé à la fin de la liste.
     * \param t_another Employé à ajouter
     */
    void push_back(Employee t_another) ;

    /* getters setters */
    std::list<Employee> &getSubordinate() ;
    void setSubordinate(const std::list<Employee> &t_another) ;

    /* operateur d'affectation */
    void operator=(const Employee &employee)
    {
        this->id = employee.id ;
        this->name = employee.name ;
        this->subordinate = std::move(employee.subordinate) ;
    }
};

/**
 * \class Group
 * \brief Cette class représente un groupe d'employé
 */
class Group
{
private:
    long id ;
    std::string name ;
    std::list<Employee> member ;
public:
    /**
    * \fn Group(long _id = 0, std::string _name= "")
    * \brief Constructeur par défaut de la classe.
    * \param _id ID du groupe, zéro par défaut.
    * \param _name nom du groupe, "" par défaut.
    */
    Group(long _id=0, std::string _name="") ;

    /**
    * \fn Group(Group &t_group)
    * \brief Constructeur par recopie de la classe.
    * \param t_group Référence sur une instance de Group.
    */
    Group(const Group &t_group) ;

    /**
    * \fn Group(Group &t_group)
    * \brief Constructeur par recopie de la classe.
    * \param t_group Pointeur sur une instance de Group.
    */
    Group(const Group *t_group) ;

    /**
     * \fn void remove(long id)
     * \brief Supprime un employé de la liste des membres.
     * \param id ID de l'employé à supprimer ;
     */
    void remove(long id) ;

    /**
     * \fn void push_back(Employee &employee)
     * \brief Ajoute un employé à la fin de la liste.
     * \param employee Employé à ajouter
     */
    void push_back(Employee employee) ;

    /* getters setters */
    std::list<Employee> &getMember() ;
    void setMember(const std::list<Employee> &t_another) ;
    void setId(long _id) ;
    long getId() const ;
    std::string getName() const ;
    void setName(std::string _name) ;

    /* operateur d'affectation */
    void operator=(const Group &group)
    {
        this->id = group.id ;
        this->name = group.name ;
        this->member = std::move(group.member) ;
    }
};

}
#endif // PERSON_DEF
