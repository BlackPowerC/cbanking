#include "../../include/Entity/Operation.hpp"

namespace Entity
{
/* classe BaseOperation */
BaseOperation::BaseOperation(long _id,
                             std::shared_ptr<Account> source,
                             std::shared_ptr<Employee> employee,
                             std::string _date, double _montant):
    id(_id),
    t_source(std::move(source)),
    t_employee(std::move(employee)),
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
    return *(this->t_source) ;
}

void BaseOperation::setAccountSource(Account &another)
{
    this->t_source = std::move(std::make_shared<Account>(another)) ;
}

Employee BaseOperation::getEmployee() const
{
    return *(this->t_employee) ;
}

void BaseOperation::setEmployee(Employee &another)
{
    this->t_employee = std::move(std::make_shared<Employee>(another)) ;
}

std::string BaseOperation::getDate() const
{
    return this->date ;
}

void BaseOperation::setDate(std::string date)
{
    this->date = date ;
}

long BaseOperation::getId() const
{
    return this->id ;
}

void BaseOperation::setId(long id)
{
    this->id = id;
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

Operation::Operation(const Operation &another): BaseOperation()
{
    *this = another ;
}

Operation::Operation(const Operation *another): BaseOperation()
{
    *this = *another ;
}

void Operation::doOperation()
{

}

/* classe Virement */
Virement::Virement(std::shared_ptr<Account> destination): BaseOperation(), t_destination(destination)
{

}

Virement::Virement(const Virement &another): BaseOperation()
{
    *this = another ;
}
Virement::Virement(const Virement *another): BaseOperation()
{
    *this = *another ;
}

Account Virement::getAccountDestination() const
{
    return *(this->t_destination) ;
}

void Virement::setAccountDestination(Account &another)
{
    this->t_destination = std::move(std::make_shared<Account>(another)) ; ;
}

void Virement::doOperation()
{

}

}
