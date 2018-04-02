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

#pragma db object polymorphic pointer(std::shared_ptr) session
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
  #pragma db type("VARCHAR(255)")
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
  virtual std::string getTypeOperation() const {} ;
  virtual void doOperation() {} ;
};

#pragma db object pointer(std::shared_ptr) session
class Operation: public BaseOperation
{
private:
  friend class odb::access ;
  #pragma db type("INT") value_type("TINYINT")
  TypeOperation typeOperation ;
public:
  Operation() {};
  Operation(const BaseOperation &ba, const TypeOperation &to = TypeOperation::DEPOT) ;
  Operation(const Operation &another) ;
  Operation(const Operation *another) ;
  virtual void doOperation() ;

  std::string getTypeOperation() const
  {
    return (this->typeOperation == TypeOperation::DEPOT) ? "depot":"retrait" ;
  }

  void setTypeOperation(const TypeOperation to)
  {
    this->typeOperation = to;
  }

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

#pragma db object pointer(std::shared_ptr) session
class Virement: public BaseOperation
{
private:
    friend class odb::access ;
  #pragma db value_not_null column("id_account")
  std::shared_ptr<Account> t_destination ;
public:
  Virement() {} ;
  Virement(const BaseOperation &ba, 
           const std::shared_ptr<Account> &destination = std::make_shared<Account>()) ;
  Virement(const Virement &another) ;
  Virement(const Virement *another) ;
  /* getters setters */
  Account getAccountDestination() const;
  void setAccountDestination(Account &another) ;
  virtual void doOperation() ;

  std::string getTypeOperation() const
  {
    return "virement" ;
  }

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
