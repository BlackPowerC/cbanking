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

enum class TypeOperation
{
	DEPOT, RETRAIT
};

class BaseOperation
{
protected:
  long id ;
  std::unique_ptr<Account> t_source ;
  std::unique_ptr<Employee> t_employee ;
  std::string date ;
  double montant ;
public:
  BaseOperation(long _id = 0, const Account &source = Account(), const Employee &employee = Employee(), std::string date = "", double _montant=0.0) ;
  BaseOperation(const BaseOperation &bo) ;
  BaseOperation(const BaseOperation *bo) ;
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

class Operation: public BaseOperation
{
private:
  TypeOperation typeOperation ;
public:
  Operation(const TypeOperation to = TypeOperation::DEPOT) ;
  Operation(const Operation &another) ;
  Operation(const Operation *another) ;
  virtual void doOperation() ;
};

class Virement: public BaseOperation
{
private:
  std::unique_ptr<Account> t_destination ;
public:
  Virement(const Account &destination = Account()) ;
  Virement(const Virement &another) ;
  Virement(const Virement *another) ;
  /* getters setters */
  Account getAccountDestination() ;
  void setAccountDestination(Account &another) ;
  virtual void doOperation() ;
};

}
#endif // OPERATION_DEF
