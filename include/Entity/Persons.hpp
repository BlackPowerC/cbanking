#ifndef PERSON_DEF
#define PERSON_DEF

#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <odb/core.hxx>
#include "Account.hpp"
#include "Operation.hpp"

/**
 * \file Persons.hpp
 * \author Jordy Fatigba fatigba72@gmail.com
 * \date 22-02-2018
 * \brief Cet espace de nom contient la définition des entités
 * du programme.
 */

namespace Entity
{
/* forward class declaration */
class Person ;
class Customer ;
class Group ;
class Employee ;
class Account ;
class BaseOperation ;
class Operation ;
class Virement ;
class SavingsAccount ;
class CurrentAccount ;


/**
 * \class Person
 * \brief Classe représantant une personne.
 */
#pragma db object polymorphic pointer(std::shared_ptr) session
class Person
{
protected:
	friend class odb::access ;

		#pragma db id auto not_null
    long id ;
    #pragma db value_type("VARCHAR(255)")
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
		virtual ~Person() {}
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
#pragma db object pointer(std::shared_ptr) session
class Customer: public Person
{
private:
	friend class odb::access ;

	#pragma db value_null inverse(t_customer)
  std::vector<std::shared_ptr<Account> > accounts ;
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

		/* Opérations */
	  /**
     * \fn void remove(long id)
     * \brief Supprime un compte de la liste des comptes.
     * \param id ID du compte à supprimer.
     */
    void remove(long id) ;

    /**
     * \fn void push_back(SavingsAccount &t_account)
     * \brief Ajoute un compte d'épargne à la fin de la liste des comptes.
     * \param t_account Le compte à ajouter.
     */
    void push_back(SavingsAccount &t_account) ;

	 /**
		* \fn void push_back(CurrentAccount &t_account)
		* \brief Ajoute un compte d'épargne à la fin de la liste des comptes.
		* \param t_account Le compte à ajouter.
		*/
    void push_back(CurrentAccount &t_account) ;

    /* getters setters */
    std::vector<std::shared_ptr<Account> > &getAccounts() ;
    void setAccounts(std::vector<std::shared_ptr<Account> > & another) ;

    void operator=(const Customer &t_another)
    {
    	this->id = t_another.id ;
    	this->name = t_another.name ;
    	this->accounts = std::move(t_another.accounts) ;
    }

    bool operator==(const Customer &t_another)
    {
        return this->id == t_another.id ;
    }
};

/**
 * \class Customer
 * \brief Classe représentant un employé.
 */
#pragma db object pointer(std::shared_ptr) session
class Employee: public Person
{
private:
	friend class odb::access ;

		#pragma db value_null column("id_subordinate")
    std::vector<std::shared_ptr<Employee> > subordinate ; /*!< Liste des employés subordonnées. */

    #pragma db value_null column("id_account") inverse(t_employee)
    std::vector<std::shared_ptr<Account> > accounts ; /*!< Listes des comptes créés par l'employé. */

		#pragma db value_null column("id_operation") inverse(t_employee)
    std::vector<std::shared_ptr<BaseOperation> > operations ;/*!< Listes des opérations éffectuées. */

		#pragma db value_null column("id_group") inverse(members)
    std::vector<std::shared_ptr<Group> > groups ; /*!< Listes des groupes de l'employé. */
public:
    /**
    * \fn Employee(long _id = 0, std::string _name= "", std::vector<Employee> _subordonne)
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
     * \fn void removeSubordinate(long subordinateId)
     * \brief Supprime un employé de la liste des subordonnées.
     * \param subordinateId ID de l'employé à supprimer ;
     */
    void removeSubordinate(long subordinateId) ;

    /**
     * \fn void removeAccount(long accuontID)
     * \brief Supprime un compte de la liste des comptes.
     * \param accuontID ID du compte à supprimer ;
     */
    void removeAccount(long accuontID) ;

		/**
     * \fn void removeOperation(long operationID)
     * \brief Supprime une opération faite par un employé.
     * \param accuontID ID du compte à supprimer ;
     */
    void removeOperation(long operationID) ;

		/**
     * \fn void removeAccount(long operationID)
     * \brief Supprime l'employé d'un groupe.
     * \param accuontID ID du compte à supprimer ;
     */
    void removeGroup(long operationID) ;

    /**
     * \fn void addSubordinate(Employee &subordinate)
     * \brief Ajoute un employé à la liste des subornonnées.
     * \param subordinate Employé à ajouter.
     */
    void addSubordinate(Employee &subordinate) ;

    /**
     * \fn void addAccount(SavingsAccount &t_account)
     * \brief Ajoute un Compte d'épargne à la liste des comptes.
     * \param t_account Le compte à ajouter.
     */
    void addAccount(SavingsAccount &t_account) ;

	 /**
		* \fn void addAccount(CurrentAccount &t_account)
		* \brief Ajoute un Compte d'épargne à la liste des comptes.
		* \param t_account Le compte à ajouter.
		*/
    void addAccount(CurrentAccount &t_account) ;

    /**
     * \fn void addOperation(Operation &t_operation)
     * \brief Ajoute une opération (retrait ou dépot) à la liste des opérations.
     * \param t_operation L'opération à ajouter.
     */
    void addOperation(Operation &t_operation) ;

    /**
     * \fn void addVirement(Virement &t_virement)
     * \brief Ajoute une opération (virement) à la liste des opérations.
     * \param t_virement Le virement à ajouter.
     */
    void addVirement(Virement &t_virement) ;

    /**
     * \fn void addGroup(Group &t_group)
     * \brief Ajoute un groupe à la liste des groupes.
     * \param t_group Employé à ajouter.
     */
    void addGroup(Group &t_group) ;

    /* getters setters */
    // subordinate
    std::vector<std::shared_ptr<Employee> > &getSubordinate() ;
    void setSubordinate(std::vector<std::shared_ptr<Employee> > &t_another) ;
    // accounts
    std::vector<std::shared_ptr<Account> > &getAccounts() ;
    void setAccounts(std::vector<std::shared_ptr<Account> > &t_another) ;
		// operations
    std::vector<std::shared_ptr<BaseOperation> > &getOperations() ;
    void setOperations(std::vector<std::shared_ptr<BaseOperation> > &t_another) ;
    // group
    std::vector<std::shared_ptr<Group> > &getGroups() ;
    void setGroups(std::vector<std::shared_ptr<Group> > &t_another) ;
    /* operateur d'affectation */
    void operator=(const Employee &employee)
    {
        this->id = employee.id ;
        this->name = employee.name ;
        this->subordinate = std::move(employee.subordinate) ;
        this->accounts = std::move(employee.accounts) ;
        this->operations = std::move(employee.operations) ;
        this->groups = std::move(employee.groups) ;
    }
};

/**
 * \class Group
 * \brief Cette class représente un groupe d'employé
 */
#pragma db object pointer(std::shared_ptr) session
class Group
{
private:
	friend class odb::access ;
	#pragma db id auto not_null
    long id ;
    std::string name ;
    #pragma db value_null column("id_group") unordered
    std::vector<std::shared_ptr<Employee> > members ;
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
    void push_back(Employee &employee) ;

    /* getters setters */
    std::vector<std::shared_ptr<Employee> > &getMembers() ;
    void setMembers(std::vector<std::shared_ptr<Employee> > &t_another) ;
    void setId(long _id) ;
    long getId() const ;
    std::string getName() const ;
    void setName(std::string _name) ;

    /* operateur d'affectation */
    void operator=(const Group &group)
    {
        this->id = group.id ;
        this->name = group.name ;
        this->members = std::move(group.members) ;
    }
};

/**
 * \class Cette classe représente un jeu de jetton
 *        associant une personne (Person) à un token.
 */
#pragma db object polymorphic pointer(std::shared_ptr) session
class Token
{
private:
    friend class odb::access ;
    #pragma db id auto not_null
    int id ;
    #pragma db value_null type("INT") column("id_person")
    std::shared_ptr<Person> t_person ;
    std::string token ; /*!< Jetton unique */
public:
    Token() ;
    Token(const Token *p_another) ;
    Token(const Token &t_another) ;
    /* getters setters */
    int getId() const ;

    void setId(int id) ;

    const std::shared_ptr<Person> &getPerson() const ;

    void setPerson(const std::shared_ptr<Person> &t_person) ;

    std::string getToken() const ;

    void setToken(const std::string &token) ;

    virtual void doNothing() = 0 ;
}

/**
 * \class Session
 * \brief Cette classe représente une session d'utilisateur.
 *        Un client ou un employée inscrit en possède.
 */
#pragma db object pointer(std::shared_ptr) session
class Session: public Token
{
private:
    friend class odb::access ;
    std::string begin_ ;
    std::string end_ ;
public:
    // Les constructeurs
    Session() ;
    Session(const UserAccount *p_another) ;
    Session(const UserAccount &t_another) ;

    // Getters et setters
    std::string getBegin() const ;

    void setBegin(std::string begin_) ;

    std::string getEnd() const ;

    void setEnd_(const std::string &end) ;

    bool operator==(const UserAccount &rhs) const;
}

};

}
#endif // PERSON_DEF
