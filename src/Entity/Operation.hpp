#ifndef OPERATION_DEF
#define OPERATION_DEF

#include "Account.hpp"
#include "Persons.hpp"
#include <vector>
#include <memory>
#include <odb/core.hxx>

namespace Entity
{

class BaseOperation ;
class Operation ;
class Virement ;
class Account ;
class Employee ;

enum class TypeOperation
{
	DEPOT, RETRAIT
};

#pragma db object polymorphic
class BaseOperation
{
protected:
  friend class odb::access ;
  #pragma db id auto not_null
  long id ;
  #pragma db not_null column("id_account")
  std::shared_ptr<Account> t_source ;
  #pragma db not_null column("id_employee")
  std::shared_ptr<Employee> t_employee ;
  #pragma db value_type("VARCHAR(255)")
  std::string date ;
  double montant ;
public:
  BaseOperation(long _id = 0,
                std::shared_ptr<Account> source = std::make_shared<Account>(),
                std::shared_ptr<Employee> employee = std::make_shared<Employee>(),
                std::string date = "", double _montant=0.0) ;
  BaseOperation(const BaseOperation &bo) ;
  BaseOperation(const BaseOperation *bo) ;
  virtual ~BaseOperation() {}
  /* getters et setters */
  long getId() const ;
  void setId(long id) ;

  Account getAccountSource() const ;
  void setAccountSource(Account &another) ;

  Employee getEmployee() const ;
  void setEmployee(Employee &another) ;

  std::string getDate() const ;
  void setDate(std::string date) ;

  double getMontant() const ;
  void setMontant(double montant) ;

  /* Méthode virtuelle pure*/
  virtual void doOperation() = 0 ;
};

#pragma db object
class Operation: public BaseOperation
{
private:
  friend class odb::access ;
  #pragma db type("INT") value_type("TINYINT")
  TypeOperation typeOperation ;
public:
  Operation(const TypeOperation to = TypeOperation::DEPOT) ;
  Operation(const Operation &another) ;
  Operation(const Operation *another) ;
  virtual void doOperation() ;

  void operator=(const Operation &t_another)
  {
    this->id = t_another.id ;
    this->montant = t_another.montant ;
    this->t_employee = std::move(t_another.t_employee) ;
    this->t_source = std::move(t_another.t_source) ;
    this->date = t_another.date ;
    this->typeOperation = t_another.typeOperation ;
  }
};

#pragma db object
class Virement: public BaseOperation
{
private:
    friend class odb::access ;
  #pragma db value_not_null column("id_account")
  std::shared_ptr<Account> t_destination ;
public:
  Virement(std::shared_ptr<Account> destination = std::make_shared<Account>()) ;
  Virement(const Virement &another) ;
  Virement(const Virement *another) ;
  /* getters setters */
  Account getAccountDestination() ;
  void setAccountDestination(Account &another) ;
  virtual void doOperation() ;

  void operator=(const Virement &t_another)
  {
    this->id = t_another.id ;
    this->montant = t_another.montant ;
    this->t_employee = std::move(t_another.t_employee) ;
    this->t_source = std::move(t_another.t_source) ;
    this->date = t_another.date ;
    this->t_destination = std::move(t_another.t_destination) ;
  }
};

}
#endif // OPERATION_DEF
