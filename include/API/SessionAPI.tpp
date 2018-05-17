namespace API
{

template<class T>
std::shared_ptr<T> SessionAPI::findByInstanceAppId(const std::string &instanceAppId)
{
    try
    {
        odb::session t_session ;
        DBConnection *conn = DBConnection::getInstance() ;
        conn->reset() ;
        odb::query<T> t_query(odb::query<T>::appInstanceId == instanceAppId) ;
        odb::result<T> t_result(conn->getConnection()->query(t_query)) ;
        if(t_result.empty() || t_result.size() > 1)
        {
            throw NotFound("Impossible de trouver la ressource à l'ID "+instanceAppId) ;
        }
        std::shared_ptr<T> token(t_result.begin().load()) ;
        conn->commit() ;
        return token ;

    }catch(const odb::exception &e)
    {
        throw NotFound("Recherche infructueuse") ;
    }
}

template <typename T>
std::shared_ptr<T> SessionAPI::findById(long id)
{
    if(id < 0)
    {
        throw IllegalArgument("L'argument ID doit être un entier positif !");
    }
    try
    {
        odb::session t_session ;
        DBConnection *c = DBConnection::getInstance() ;
        c->reset();

        odb::query<T> t_query(odb::query<T>::t_person == id) ;
        odb::result<T> t_result(c->getConnection()->query(t_query)) ;
        if(t_result.empty() || t_result.size() > 1)
        {
            throw NotFound("Impossible de trouver la ressource à l'ID "+std::to_string(id)) ;
        }
        std::shared_ptr<T> token(t_result.begin().load()) ;
        c->commit() ;
        return token ;
    }
    catch(const odb::exception &e)
    {
        LOG_ERROR << e.what() ;
        throw NotFound("Impossible de trouver la ressource à l'ID "+std::to_string(id)) ;
    }
}

template <typename T>
std::shared_ptr<T> SessionAPI::findByToken(const std::string &token)
{
    if(token.empty())
    {
        throw IllegalArgument("Jeton sans valeur !");
    }
    try
    {
        odb::session t_session ;
        DBConnection *c = DBConnection::getInstance() ;
        c->reset();

        odb::query<T> t_query(odb::query<T>::token == token) ;
        odb::result<T> t_result(c->getConnection()->query(t_query)) ;
        if(t_result.empty() || t_result.size() > 1)
        {
            throw NotFound("Impossible de trouver la session au jetton "+token) ;
        }
        std::shared_ptr<T> token(t_result.begin().load()) ;
        c->commit() ;
        return token ;
    }
    catch(const odb::exception &e)
    {
        LOG_ERROR << e.what() ;
        throw NotFound("Impossible de trouver la session au jetton "+token) ;
    }
}

}