#include "AccountAPI.hpp"

namespace API
{

template <typename T>
std::vector<std::shared_ptr<T> > AccountAPI::findByCustomerId(long id)
{
  if(id <= 0)
  {
    throw IllegalArgument("L'argument doit être un entier positif non nul !") ;
  }
  try
  {
    DBConnection *connection = DBConnection::getInstance() ;
    connection->reset();
    odb::query<T> t_query(odb::query<T>::id_customer == id) ;
    odb::result<T> t_result(connection->getConnection()->query<T>(t_query)) ;
    std::vector<std::shared_ptr<T> > accounts ;
    for(auto it(accounts.begin()); it != accounts.end(); it++)
    {
        accounts.push_back(it.load()) ;
    }
      return  accounts ;
  }
  catch(const odb::exception &e)
  {
        LOG_ERROR << e.what() ;
        throw NotFound("Recherche infructueuse !") ;
  }
}

template <typename T>
std::vector<std::shared_ptr<T> > AccountAPI::findByEmployeeId(long id)
{
    if(id <= 0)
    {
        throw IllegalArgument("L'argument doit être un entier positif non nul !") ;
    }
    try
    {
        DBConnection *connection = DBConnection::getInstance() ;
        connection->reset();
        odb::query<T> t_query(odb::query<T>::id_employee == id) ;
        odb::result<T> t_result(connection->getConnection()->query<T>(t_query)) ;
        std::vector<std::shared_ptr<T> > accounts ;
        for(auto it(accounts.begin()); it != accounts.end(); it++)
        {
            accounts.push_back(it.load()) ;
        }
        return  accounts ;
    }
    catch(const odb::exception &e)
    {
        LOG_ERROR << e.what() ;
        throw NotFound("Recherche infructueuse !") ;
    }
}

}
