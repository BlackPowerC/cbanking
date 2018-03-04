#include "AccountAPI.hpp"

namespace API
{

AccountAPI* AccountAPI::p_singleton = nullptr ;

AccountAPI::AccountAPI()
{

}

AccountAPI* AccountAPI::getInstance()
{
    if(!p_singleton)
    {
        p_singleton = new AccountAPI ;
    }
    return p_singleton ;
}

AccountAPI::~AccountAPI()
{
	if(p_singleton)
	{
		delete p_singleton ;
	}
}

template <typename T>
std::vector<std::shared_ptr<T> > AccountAPI::findByCustomerId(long id)
{
  if(id <= 0)
  {
    throw IllegalArgument("L'argument doit être un entier positif non nul !") ;
  }
	try
	{
		// Contenu du résultat de recherche
		std::vector<std::shared_ptr<T> > objects ;
		// Transaction et querying
		DBConnection *s = DBConnection::getInstance() ;
		s->reset() ;
		odb::query<T> t_query(s->getConnection()->query<T>::t_customer.getId() == id) ;
	}
}

template <typename T>
std::vector<std::shared_ptr<T> > AccountAPI::findByEmployeeId(long id)
{

}

}
