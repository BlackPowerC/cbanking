#include "../../include/Entity/Persons.hpp"

namespace Entity
{
/* Classe Person */
Person::Person(long _id, std::string _name, std::string _email, std::string _passwd):
        id(_id), name(_name), email(_email), passwd(_passwd)
{}

Person::Person(const Person &t_person)
{
    *this = t_person ;
}

Person::Person(const Person *p_person)
{
    *this = *p_person ;
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

std::string Person::getEmail() const
{
    return this->email;
}

void Person::setEmail(std::string _email)
{
    this->email = _email ;
}

std::string Person::getPasswd() const
{
    return this->passwd;
}

void Person::setPasswd(std::string _passwd)
{
    this->passwd = _passwd;
}

Token* Person::getToken() const
{
    return this->p_token.get() ;
}

void Person::setToken(const Token &token)
{
    this->p_token = std::make_shared<Token>(token) ;
}

/* Classe Customer */
Customer::Customer(long _id, std::string _name, std::string _email, std::string _passwd):
        Person(_id, _name, _email, _passwd)
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
Employee::Employee(long _id, std::string _name, std::string _email, std::string _passwd):
        Person(_id, _name, _email, _passwd)
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

    Token::~Token() {}

    Token::Token(const Token *p_another)
    {
        *this = *p_another ;
    }

    Token::Token(const Token &t_another)
    {
        *this = t_another ;
    }

    int Token::getId() const
    {
        return this->id ;
    }

    void Token::setId(int id)
    {
        this->id = id ;
    }

    Person *Token::getPerson() const
    {
        return this->t_person.get() ;
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

    // Session
    Session::Session()
    {

    }

    Session::Session(const Session *p_another) : Token(p_another)
    {
        this->begin_ = p_another->begin_ ;
        this->end_ = p_another->end_ ;
    }

    Session::Session(const Session &t_another) : Token(t_another)
    {
        this->begin_ = t_another.begin_ ;
        this->end_ = t_another.end_ ;
    }

    ulong Session::getBegin() const
    {
        return this->begin_;
    }

    void Session::setBegin(ulong begin_)
    {
        this->begin_ = begin_ ;
    }

    ulong Session::getEnd() const
    {
        return this->end_ ;
    }

    void Session::setEnd(const ulong end)
    {
        this->end_ = end_ ;
    }

    // ReloadSession
    ReloadSession::ReloadSession(bool reloaded) : reloaded(reloaded)
    {

    }
}
