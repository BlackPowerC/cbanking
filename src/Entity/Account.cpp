#include "Account.hpp"

namespace Entity
{
/* Classe Account */
Account::Account(long _id,
                 const Customer &customer,
                 const Employee &employee,
                 double _balance, std::string date):
    id(_id),
    t_customer(customer),
    t_employee(employee),
    balance(_balance),
    creationDate(date)
{}

Account::Account(const Account &another)
{
    *this = another ;
}

Account::Account(const Account *another)
{
    *this = *another ;
}

long Account::getId() const
{
    return this->id ;
}

void Account::setId(long id)
{
    this->id = id ;
}

Customer Account::getCustomer() const
{
    return this->t_customer;
}

void Account::setCustomer(const Customer &customer)
{
    this->t_customer = customer ;
}

Employee Account::getEmployee() const
{
    return this->t_employee ;
}

void Account::setEmployee(const Employee &employee)
{
    this->t_employee = employee ;
}

std::string Account::getCreationDate() const
{
    return this->creationDate ;
}

void Account::setCreationDate(std::string creationDate)
{
    this->creationDate = creationDate ;
}

double Account::getBalance() const
{
    return this->balance ;
}

void Account::setBalance(double balance)
{
    this->balance = balance ;
}

/* Classe  CurrentAcount*/
CurrentAccount::CurrentAccount(const Account &account, double _overdraft):
    Account(account), overdraft(_overdraft)
{

}
CurrentAccount::CurrentAccount(const CurrentAccount &ca)
{
    *this = ca ;
}

CurrentAccount::CurrentAccount(const CurrentAccount *ca)
{
    *this = *ca ;
}

double CurrentAccount::getOverdraft() const
{
    return this->overdraft ;
}
void CurrentAccount::setOverdraft(double overdraft)
{
    this->overdraft = overdraft ;
}

/* classe SavingsAccount*/
SavingsAccount::SavingsAccount(const Account &account, double _rate):
    Account(account), rate(_rate)
{

}

SavingsAccount::SavingsAccount(const SavingsAccount &ca)
{
    *this = ca ;
}

SavingsAccount::SavingsAccount(const SavingsAccount *ca)
{
    *this = *ca ;
}

double SavingsAccount::SavingsAccount::getRate() const
{
    return this->rate ;
}

void SavingsAccount::setRate(double rate)
{
    this->rate = rate ;
}

}
