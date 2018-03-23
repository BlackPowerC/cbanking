//
// Created by jordy on 23/03/18.
//

/**
 * @brief Implémentation des fonctions de SessionAPI.hpp
 */

#include <ctime>
#include "../include/API/SessionAPI.hpp"
#include "../include/Util/Crypto.hpp"

namespace Util
{
    Entity::Session initSession(const std::shared_ptr<Entity::Person> &p_person)
    {
        Entity::Session t_session;
        t_session.setBegin((ulong) std::time(nullptr)) ;
        t_session.setEnd(t_session.getBegin()+31556952UL) ;
        t_session.setPerson(p_person) ;
        t_session.setToken(hashSha512(p_person->getEmail())) ;
        return t_session ;
    }
}