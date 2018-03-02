#ifndef ENTITYAPI_HPP_INCLUDED
#define ENTITYAPI_HPP_INCLUDED

/*
 * \file PersonAPI.hpp
 * \author jordy fatigba fatigba@gmail.com
 * \brief Ce fichier contient toute les classes
 *				d'API pour faire des opérations dans la
 *				base de données sur les tables Customer,
 *				Person, et Employee.
 */

#include "../Entity/Persons.hpp"
#include <iostream>
#include <exception>

namespace API
{

/**
 * \class PersonAPI
 * \brief Cette classe permet de faire des opérations
 *        d'insertion de suppression de recherche dans
 *		  la base de données avec les entitées
 *		  Person, Customer et Employee.
 */
class PersonAPI
{
private:
	static PersonAPI *p_singleton ;
	PersonAPI() ;
public:
  static PersonAPI *getInstance() ;
  ~PersonAPI() ;
};

class CustomerAPI
{
private:
	static CustomerAPI *p_singleton ;
	CustomerAPI() ;
public:
  static CustomerAPI *getInstance() ;
  ~CustomerAPI() ;
};

class EmployeeAPI
{
private:
	static EmployeeAPI *p_singleton ;
	EmployeeAPI() ;
public:
  static EmployeeAPI *getInstance() ;
  ~EmployeeAPI() ;
};

}
#endif // ENTITYAPI_HPP_INCLUDED
