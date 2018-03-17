#ifndef OPERATIONAPI_HPP_INCLUDED
#define OPERATIONAPI_HPP_INCLUDED

#include "PersistenceAPI.hpp"


namespace API
{

/**
 * \class OperationAPI
 * \brief Cette classe est en charge de la persistence
 *				des entités BaseOperation, Operation et Virement.
 *				La classe est un singleton.
 */
class OperationAPI: public PersistenceAPI
{
private:
	static OperationAPI *p_singleton ;
	OperationAPI() {}
public:
  static OperationAPI *getInstance()
  {
    if(!p_singleton)
    {
        p_singleton = new OperationAPI ;
    }
    return p_singleton ;
  }
	~OperationAPI() { if(p_singleton) delete p_singleton ;}


	// Fonction polymorphique
  virtual void doNothing() {}
};

OperationAPI* OperationAPI::p_singleton = nullptr ;

}
#endif // OPERATIONAPI_HPP_INCLUDED
