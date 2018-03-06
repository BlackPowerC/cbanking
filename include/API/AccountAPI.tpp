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
}

template <typename T>
std::vector<std::shared_ptr<T> > AccountAPI::findByEmployeeId(long id)
{

}

}
