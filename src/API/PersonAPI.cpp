#include "PersonAPI.hpp"
#include <odb/query.hxx>
#include <odb/result.hxx>
#include <odb/exception.hxx>
#include "../Core/DBConnection.hpp"

// STL
#include <string>
#include <iostream>
#include <exception>

// Plog
#include <plog/Log.h>

// Exceptions personnalisées
#include "../Exception.hpp"

namespace API
{

// PersonAPI
PersonAPI* PersonAPI::p_singleton = nullptr ;

PersonAPI::PersonAPI()
{

}

PersonAPI* PersonAPI::getInstance()
{
	if(p_singleton == nullptr)
	{
		p_singleton = new PersonAPI ;
	}
	return p_singleton ;
}

PersonAPI::~PersonAPI()
{
	delete p_singleton ;
}

template <typename T>
void PersonAPI::update(const T &t_person)
{
	try
	{
    DBConnection::getInstance()->getConnection()->update<T>(t_person) ;
	}catch(const odb::exception &e)
	{
    LOG_ERROR << e.what() ;
    throw NotUpdatable("Impossible de mettre à jour la ressource ayant l'ID: "+std::to_string(t_person.getId())) ;
	}
}

template <typename T>
void PersonAPI::insert(const T &t_person)
{
	try
	{
    DBConnection::getInstance()->getConnection()->persist(t_person) ;
	}catch(const odb::exception &e)
	{
    LOG_ERROR << e.what() ;
	}
}

template <typename T>
std::vector<std::shared_ptr<T> > PersonAPI::findAll()
{
	try
	{
		std::vector<std::shared_ptr<T> > persons ;
    DBConnection *s = DBConnection::getInstance() ;

		odb::result<T> t_result(s->getConnection()->query<T>()) ;
		for(auto it = t_result.begin(); it!= t_result.end(); it++)
		{
			persons.push_back(std::make_shared<T>(it.load())) ;
		}
		return persons;
	}
	catch(const odb::exception &e)
	{
		LOG_ERROR << e.what() ;
		throw NotFound("Recherche infructueuse !") ;
	}
}

template <typename T>
std::unique_ptr<T> PersonAPI::findById(long id)
{
  try
  {
    DBConnection *s = DBConnection::getInstance() ;
    return std::make_unique<T>(s->getConnection()->load<T>()) ;
  }
  catch(const odb::exception &e)
  {
  	LOG_ERROR << e.what() ;
  	throw NotFound("Impossible de trouver la ressource à l'ID "+std::to_string(id)) ;
  }
}

template <typename T>
std::vector<std::shared_ptr<T> > PersonAPI::findByName(const std::string &name)
{
  try
  {
    std::vector<std::shared_ptr<T> > persons ;
    odb::query<T> t_query(odb::query<T>::name.like(name+"%")) ;
    odb::result<T> t_result(t_query) ;
		for(auto it = t_result.begin(); it!= t_result.end(); it++)
		{
			persons.push_back(std::make_shared<T>(it.load())) ;
		}
		return persons ;
  }catch(const odb::exception &e)
  {
  	LOG_ERROR << e.what() ;
  	throw NotFound("Recherche infructeuse !") ;
  }
}

}
