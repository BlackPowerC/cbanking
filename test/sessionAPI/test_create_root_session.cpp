//
// Created by jordy on 25/03/18.
//

#include "../../include/Entity/Entity.hpp"
#include "../../include/API/PersistenceAPI.hpp"
#include "../../include/API/PersonAPI.hpp"
#include "../../include/API/SessionAPI.hpp"
#include "../../include/Util/Crypto.hpp"

int main()
{
    try
    {
        Entity::Employee root(1, "root", "root@root.com", Util::hashArgon2("azerty123")) ;
        Entity::Session session = Util::initSession(std::make_shared<Entity::Employee>(root)) ;
        root.setToken(session) ;
        long id_employee = API::PersonAPI::getInstance()->insert<Entity::Employee>(root) ;
        long id_session = API::SessionAPI::getInstance()->insert<Entity::Session>(session) ;
        session.getPerson()->setId(id_employee) ;
        root.getToken()->setId(id_session) ;

        API::PersonAPI::getInstance()->update<Entity::Session>(session) ;
        API::PersonAPI::getInstance()->update<Entity::Employee>(root) ;

    }catch(const std::exception &e)
    {
        puts(e.what()) ;
    }
    return 0 ;
}