#ifndef PERSONAPI_HPP_INCLUDED
#define PERSONAPI_HPP_INCLUDED

#include "PersistenceAPI.hpp"

namespace API
{

/**
 * \class PersonAPI
 * \brief Cette classe contient les fontions
 *				spécifiques pour manipuler les entités,
 *				Person, Customer et Employee
 *
 */

class PersonAPI : public PersistenceAPI
{
private:
	static PersonAPI *p_singleton ;
	PersonAPI() ;
public:
  static PersonAPI *getInstance() ;
	~PersonAPI() ;

  	/**
	 * \fn std::vector<std::shared_ptr<T> > findByName(const std::string &name)
	 * \brief Cette fonction cherche une Personne avec un nom commençant
	 *				par name.
	 * \throw IllegalArgument si name vaut "".
	 * \throw NotFound si rien n'est trouvé.
	 * \param name Le début du nom de la personne.
	 * \return Une vecteur de shared_ptr.
	 */
	template <typename T>
  std::vector<std::shared_ptr<T> > findByName(const std::string &name) ;
};

}

#include "PersonAPI.tpp"

#endif // PERSONAPI_HPP_INCLUDED
