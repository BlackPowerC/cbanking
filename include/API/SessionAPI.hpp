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

    template <typename T>
    std::shared_ptr<T> findByToken(const std::string &token) ;

    // Fonction polymorphic
    virtual void doNothing() {}
};

SessionAPI* SessionAPI::p_singleton = nullptr ;

}
#include "SessionAPI.tpp"

#include "../Entity/Entity.hpp"
#include "../Util/Crypto.hpp"

namespace Util
{
    /**
     * Cetter fonction créer une session pour employée ou un client.
     * @param p_person Un smart_ptr contenant une réfénce de Customer
     *        ou Employee.
     * @return Une instance de session
     */
    Entity::Session initSession(const std::shared_ptr<Entity::Person> &p_person)
    {
        Entity::Session t_session;
        t_session.setBegin((ulong) std::time(nullptr)) ;
        t_session.setEnd(t_session.getBegin()+(ulong)31556952) ;
        t_session.setPerson(p_person) ;
        t_session.setToken(hashSha512(p_person->getEmail())) ;
        return t_session ;
    }
}

#endif //CBANKING_SERVER_SESSIONAPI_HPP
