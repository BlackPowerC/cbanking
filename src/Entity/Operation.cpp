#include "Operation.hpp"

namespace Entity
{
/* classe BaseOperation */
BaseOperation::BaseOperation(long _id,
                             const Account &source,
                             const Employee &employee,
                             std::string _date, double _montant):
    id(_id),
    t_source(source),
    t_employee(employee),
    date(_date),
    montant(_montant)
{

}

BaseOperation::BaseOperation(const BaseOperation &bo)
{
    this->id = bo.id;
    this->montant = bo.montant ;
    this->t_employee = std::move(bo.t_employee) ;
    this->t_source = std::move(bo.t_source) ;
    this->date = bo.date ;
}

BaseOperation::BaseOperation(const BaseOperation *bo)
{
    this->id = bo->id;
    this->montant = bo->montant ;
    this->t_employee = std::move(bo->t_employee) ;
    this->t_source = std::move(bo->t_source) ;
    this->date = bo->date ;
}

Account BaseOperation::getAccountSource() const
{
    return this->t_source ;
}

void BaseOperation::setAccountSource(Account &another)
{
    this->t_source = std::move(std::make_unique<Account>(another)) ;
}

Employee BaseOperation::getEmployee() const
{
    return this->t_employee ;
}

void BaseOperation::setEmployee(Employee &another)
{
    this->t_employee = std::move(std::make_unique<Employee>(another)) ;
}

std::string BaseOperation::getDate() const
{
    return this->date ;
}

void BaseOperation::setDate(std::string date)
{
    this->date = date ;
}

double BaseOperation::getMontant() const
{

    return this->montant ;
}

void BaseOperation::setMontant(double montant)
{
    this->montant = montant ;
}

/* classe Operation */
Operation::Operation(const TypeOperation to) : BaseOperation(), typeOperation(to)
{}

Operation::Operation(const Operation &another)
{
    *this = another ;
}

Operation::Operation(const Operation *another)
{
    *this = *another ;
}

void Operation::doOperation()
{

}

/* classe Virement */
Virement::Virement(const Account &destination): BaseOperation(), t_destination(destination)
{

}

Virement::Virement(const Virement &another)
{
    *this = another ;
}
Virement::Virement(const Virement *another)
{
    *this = *another ;
}

Account Virement::getAccountDestination()
{
    return this->t_destination ;
}

void Virement::setAccountDestination(Account &another)
{
    this->t_destination = std::move(std::make_unique<Account>(another)) ; ;
}

void Virement::doOperation()
{

}

}
