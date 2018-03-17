//
// Created by jordy on 17/03/18.
//

#ifndef SESSIONAPI_HPP
#define SESSIONAPI_HPP

#include "PersistenceAPI.hpp"

namespace API
{

/**
 * \class SessionAPI
 * \brief Cette classe gère la persistence pour les classes
 *        Token, SessionReload et Session.
 *        La classe est un singleton.
 */
class SessionAPI: public PersistenceAPI
{
private:
    static SessionAPI *p_singleton ;
    SessionAPI() {} ;
public:
    static SessionAPI* getInstance()
    {
        if(p_singleton == nullptr)
        {
            p_singleton = new SessionAPI ;
        }
        return p_singleton ;
    }

    ~SessionAPI()
    {
        if(p_singleton)
        {
            delete p_singleton ;
        }
    }

    /**
     * @fn std::shared_ptr<T> findById(long id)
     * @brief Cette fonction permet de récupérer un objet de session apartenant à un
     *        employée ou un client grâce à son ID.
     * @tparam T T doit prendre une des valeurs suivantes: Token, Session ou SessionReaload.
     * @param id L'ID de l'utilisateur.
     * @throw IllegalArgument si id est négatif.
     * @throw NotFound si rien n'est trouvé.
     * @return Un pointeur intélligent.
     */
    template <typename T>
    std::shared_ptr<T> findById(long id) ;

    // Fonction polymorphic
    virtual void doNothing() {}
};

SessionAPI* SessionAPI::p_singleton = nullptr ;

}
#include "SessionAPI.tpp"

#endif //CBANKING_SERVER_SESSIONAPI_HPP
