#ifndef ACCOUNT_DEF
#define ACCOUNT_DEF

#include "Persons.hpp"
#include "Operation.hpp"
#include <odb/core.hxx>

namespace Entity
{

class Customer ;
class Employee ;

#pragma db object polymorphic pointer(std::shared_ptr) session
class Account
{
protected:
  friend class odb::access ;

  #pragma db id auto not_null
  long id ;
  #pragma db not_null column("id_customer")
  std::shared_ptr<Customer> t_customer ;
  #pragma db not_null column("id_employee")
  std::shared_ptr<Employee> t_employee ;
  double balance ;
  std::string creationDate ;
  #pragma db value_null inverse(t_source) column("id_operation")
  std::vector<std::shared_ptr<BaseOperation> > operations ;
public:
  Account(long _id = 0,
					std::shared_ptr<Customer> customer = std::make_shared<Customer>(),
          std::shared_ptr<Employee> employee = std::make_shared<Employee>(),
					double _balance=0.0, std::string date="") ;
  Account(const Account &another) ;
  Account(const Account *another) ;
  virtual ~Account() {}
  /* Opérations */
  /**
   * \fn void remove(long id)
   * \brief Supprime un opération de la liste des opérations.
   * \param id ID de l'opération à supprimer ;
   */
  void remove(long id) ;

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

  std::vector<std::shared_ptr<BaseOperation> > &getOperations() ;
  void setOperations(std::vector<std::shared_ptr<BaseOperation> > &t_another) ;

  void operator=(const Account &t_another)
  {
    this->id = t_another.id ;
    this->t_customer = std::move(t_another.t_customer) ;
    this->t_employee = std::move(t_another.t_employee) ;
    this->balance = t_another.balance ;
    this->creationDate = t_another.creationDate;
    this->operations = std::move(t_another.operations);
  }
};

#pragma db object pointer(std::shared_ptr) session
class CurrentAccount: public Account
{
private:
  friend class odb::access ;
  double overdraft ;
public:
  CurrentAccount(const Account &account = Account(), double _overdraft = 0.0) ;
  CurrentAccount(const CurrentAccount &ca) ;
  CurrentAccount(const CurrentAccount *ca) ;
  /* getters && setters */
  double getOverdraft() const ;
  void setOverdraft(double overdraft) ;

  void operator=(const CurrentAccount &t_another)
  {
    this->id = t_another.id ;
    this->t_customer = std::move(t_another.t_customer) ;
    this->t_employee = std::move(t_another.t_employee) ;
    this->balance = t_another.balance ;
    this->creationDate = t_another.creationDate;
    this->operations = std::move(t_another.operations);
    this->overdraft = t_another.overdraft ;
  }
};

#pragma db object pointer(std::shared_ptr) session
class SavingsAccount: public Account
{
private:
    friend class odb::access ;
  double rate ;
public:
  SavingsAccount(const Account &account = Account(), double _rate = 0.0) ;
  SavingsAccount(const SavingsAccount &ca) ;
  SavingsAccount(const SavingsAccount *ca) ;
  /* getters && setters */
  double getRate() const ;
  void setRate(double rate) ;

  void operator=(const SavingsAccount &t_another)
  {
    this->id = t_another.id ;
    this->t_customer = t_another.t_customer ;
    this->t_employee = t_another.t_employee ;
    this->balance = t_another.balance ;
    this->creationDate = t_another.creationDate;
    this->operations = std::move(t_another.operations);
    this->rate = t_another.rate ;
  }
};

}

#endif // ACCOUNT_DEF
