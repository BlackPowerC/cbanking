#ifndef ACCOUNTAPI_HPP_INCLUDED
#define ACCOUNTAPI_HPP_INCLUDED

#include "PersistenceAPI.hpp"

namespace API
{

class AccountAPI: public PersistenceAPI
{
private:
	static AccountAPI *p_singleton ;
	AccountAPI() ;
public:
  static AccountAPI *getInstance() ;
	~AccountAPI() ;

  /**
   * \brief Cette fontion cherche tout les comptes
   *				appartenant à un Client.
   * \param id L'ID du client.
   * \throw NotFound si rien n'est trouvé.
   * \throw IllegalArgument si id est négatif.
   */
  template <typename T>
  std::vector<std::shared_ptr<T> > findByCustomerId(long id) ;

	/**
   * \brief Cette fontion cherche tout les comptes
   *				créer par un employé.
   * \param id L'ID du client.
   * \throw NotFound si rien n'est trouvé.
   * \throw IllegalArgument si id est négatif.
   */
  template <typename T>
  std::vector<std::shared_ptr<T> > findByEmployeeId(long id) ;

  // Fonction polymorphic
  virtual void doNothing() {}
};

}

#include "AccountAPI.tpp"

#endif // ACCOUNTAPI_HPP_INCLUDED
