#ifndef ACCOUNT_DEF
#define ACCOUNT_DEF

#include "Persons.hpp"

namespace Entity
{

class Account
{
protected:
  long id ;
  Customer t_customer ;
  Employee t_employee ;
  double balance ;
  std::string creationDate ;
public:
  Account(long _id = 0,
					const Customer &customer = Customer(),
          const Employee &employee = Employee(),
					double _balance=0.0, std::string date="") ;
  Account(const Account &another) ;
  Account(const Account *another) ;

  /* getters && setters */
  long getId() const ;
  void setId(long id) ;

  Customer getCustomer() const ;
  void setCustomer(const Customer &customer) ;

  Employee getEmployee() const ;
  void setEmployee(const Employee &employee) ;

	std::string getCreationDate() const ;
  void setCreationDate(std::string creationDate) ;

	double getBalance() const ;
  void setBalance(double balance) ;
};

class CurrentAccount: public Account
{
private:
  double overdraft ;
public:
  CurrentAccount(const Account &account = Account(), double _overdraft = 0.0) ;
  CurrentAccount(const CurrentAccount &ca) ;
  CurrentAccount(const CurrentAccount *ca) ;
  /* getters && setters */
  double getOverdraft() const ;
  void setOverdraft(double overdraft) ;
};

class SavingsAccount: public Account
{
private:
  double rate ;
public:
  SavingsAccount(const Account &account = Account(), double _rate = 0.0) ;
  SavingsAccount(const SavingsAccount &ca) ;
  SavingsAccount(const SavingsAccount *ca) ;
  /* getters && setters */
  double getRate() const ;
  void setRate(double rate) ;
};

}

#endif // ACCOUNT_DEF
