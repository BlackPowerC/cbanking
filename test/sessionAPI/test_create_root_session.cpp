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
        API::PersonAPI::getInstance()->insert<Entity::Employee>(root) ;
        API::SessionAPI::getInstance()->insert<Entity::Session>(session) ;

    }catch(const std::exception &e)
    {
        puts(e.what()) ;
        return -1 ;
    }
    return 0 ;
}