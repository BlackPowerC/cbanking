#ifndef PERSONAPI_HPP_INCLUDED
#define PERSONAPI_HPP_INCLUDED

#include "PersistenceAPI.hpp"

namespace API
{

/**
 * \class PersonAPI
 * \brief Cette classe contient les fontions
 *				de persistance pour les entités,
 *				Person, Customer et Employee
 *
 */
class PersonAPI : public PersistenceAPI
{
private:
	static PersonAPI *p_singleton ;
	PersonAPI() {} ;
public:
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
		if(p_singleton)
		{
			delete p_singleton ;
		}
	}

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

  // Fonction polymorphic
  virtual void doNothing() {}
};

PersonAPI* PersonAPI::p_singleton = nullptr ;

}

#include "PersonAPI.tpp"

#endif // PERSONAPI_HPP_INCLUDED
