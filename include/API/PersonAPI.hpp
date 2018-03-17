#ifndef PERSONAPI_HPP_INCLUDED
#define PERSONAPI_HPP_INCLUDED

#include "PersistenceAPI.hpp"

namespace API
{

/**
 * \class PersonAPI
 * \brief Cette classe contient les fontions
 *		  de persistance pour les entités, Person, Customer et Employee.
 *		  La classe est un singleton.
 *
 */
class PersonAPI : public PersistenceAPI
{
private:
	static PersonAPI *p_singleton ;
	PersonAPI() {} ;
public:
  static PersonAPI* getInstance()
	{
		if(p_singleton == nullptr)
		{
			p_singleton = new PersonAPI ;
		}
		return p_singleton ;
	}

	~PersonAPI()
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

  /**
   * @fn std::shared_ptr<T> findByCredentials(const std::string &email, const std::string &passwd)
   * @brief Cette fonction permet de récupérer les infos d'une personne grâce à son mot
   *        de passe et son addresse email.
   * @tparam T T doit une des classes suivantes Person, Customer ou Employee.
   * @param email L'addresse email.
   * @param passwd Le mot de passe.
   * @return Un pointeur intélligent.
   * @throw IllegalArgument si email ou passwd vaut "".
   * @throw NotFound si rien n'est trouvé.
   */
  template <typename T>
  std::shared_ptr<T> findByCredentials(const std::string &email, const std::string &passwd) ;

  // Fonction polymorphic
  virtual void doNothing() {}
};

PersonAPI* PersonAPI::p_singleton = nullptr ;

}

#include "PersonAPI.tpp"

#endif // PERSONAPI_HPP_INCLUDED
