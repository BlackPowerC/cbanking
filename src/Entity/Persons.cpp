#include "../../include/Entity/Persons.hpp"

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

void Customer::remove(long id)
{
    for(auto it(this->accounts.begin()); it != this->accounts.end(); it++)
    {
        if((*it)->getId() == id)
        {
            this->accounts.erase(it) ;
        }
    }
}

void Customer::push_back(CurrentAccount &t_account)
{
  this->accounts.push_back(std::make_shared<CurrentAccount>(t_account)) ;
}

void Customer::push_back(SavingsAccount &t_account)
{
  this->accounts.push_back(std::make_shared<SavingsAccount>(t_account)) ;
}

std::vector<std::shared_ptr<Account> > &Customer::getAccounts()
{
  return this->accounts ;
}

void Customer::setAccounts(std::vector<std::shared_ptr<Account> > & another)
{
  this->accounts = std::move(another) ;
}

/* Classe Employe */
Employee::Employee(long _id, std::string _name): Person(_id, _name)
{}

Employee::Employee(const Employee *p_employee): Person(p_employee)
{}

Employee::Employee(const Employee &t_employee): Person(t_employee)
{}

void Employee::removeSubordinate(long subordinateId)
{
  for(auto it(this->subordinate.begin()); it != this->subordinate.end(); it++)
  {
    if((*it)->getId() == subordinateId)
    {
      this->subordinate.erase(it) ;
    }
  }
}

void Employee::removeAccount(long accuontID)
{
  for(auto it(this->accounts.begin()); it != this->accounts.end(); it++)
  {
    if((*it)->getId() == accuontID)
    {
      this->accounts.erase(it) ;
    }
  }
}

void Employee::removeOperation(long operationID)
{
  for(auto it(this->operations.begin()); it != this->operations.end(); it++)
  {
    if((*it)->getId() == operationID)
    {
      this->operations.erase(it) ;
    }
  }
}

void Employee::removeGroup(long groupID)
{
  for(auto it(this->groups.begin()); it != this->groups.end(); it++)
  {
    if((*it)->getId() == groupID)
    {
      this->groups.erase(it) ;
    }
  }
}

void Employee::addSubordinate(Employee &subordinate)
{
  this->subordinate.push_back(std::make_shared<Employee>(subordinate)) ;
}

void Employee::addAccount(SavingsAccount &t_account)
{
  this->accounts.push_back(std::make_shared<SavingsAccount>(t_account)) ;
}

void Employee::addAccount(CurrentAccount &t_account)
{
  this->accounts.push_back(std::make_shared<CurrentAccount>(t_account)) ;
}

void Employee::addOperation(Operation &t_operation)
{
  this->operations.push_back(std::make_shared<Operation>(t_operation)) ;
}

void Employee::addVirement(Virement &t_virement)
{
  this->operations.push_back(std::make_shared<Virement>(t_virement)) ;
}

void Employee::addGroup(Group &t_group)
{
  this->groups.push_back(std::make_shared<Group>(t_group)) ;
}

std::vector<std::shared_ptr<Employee> > &Employee::getSubordinate()
{
  return this->subordinate;
}

void Employee::setSubordinate(std::vector<std::shared_ptr<Employee> > &t_another)
{
  this->subordinate = std::move(t_another) ;
}
// accounts
std::vector<std::shared_ptr<Account> > &Employee::getAccounts()
{
  return this->accounts ;
}

void Employee::setAccounts(std::vector<std::shared_ptr<Account> > &t_another)
{
  this->accounts = std::move(t_another) ;
}

// operations
std::vector<std::shared_ptr<BaseOperation> > &Employee::getOperations()
{
  return this->operations ;
}

void Employee::setOperations(std::vector<std::shared_ptr<BaseOperation> > &t_another)
{
  this->operations = std::move(t_another) ;
}
// group
std::vector<std::shared_ptr<Group> > &Employee::getGroups()
{
    return this->groups ;
}

void Employee::setGroups(std::vector<std::shared_ptr<Group> > &t_another)
{
  this->groups = std::move(t_another) ;
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

void Group::push_back(Employee &employee)
{
    this->members.push_back(std::make_shared<Employee>(&employee)) ;
}

std::vector<std::shared_ptr<Employee> > &Group::getMembers()
{
    return this->members ;
}

void Group::remove(long id)
{
    for(std::vector<std::shared_ptr<Employee> >::iterator it(this->members.begin()); it != this->members.end(); it++)
    {
        if((*it)->getId() == id)
        {
            this->members.erase(it) ;
            break ;
        }
    }
}

void Group::setMembers(std::vector<std::shared_ptr<Employee> > &t_another)
{
    this->members = std::move(t_another) ;
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

// Token
    Token::Token() {}

    Token::Token(const Token *p_another)
    {
        *this = *p_another ;
    }

    Token::Token(const Token &t_another)
    {
        *this = p_another ;
    }

    int Token::getId() const
    {
        return this->id ;
    }

    void Token::setId(int id)
    {
        this->id = id ;
    }

    const std::shared_ptr<Person> &Token::getPerson() const
    {
        return this->t_person ;
    }

    void Token::setPerson(const std::shared_ptr<Person> &t_person)
    {
        this->t_person = std::move(t_person) ;
    }

    std::string Token::getToken() const
    {
        return this->token;
    }

    void Token::setToken(const std::string &token)
    {
        this->token = token ;
    }
}
