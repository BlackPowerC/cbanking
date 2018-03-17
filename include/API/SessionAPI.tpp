namespace API
{

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
        std::shared_ptr<T> token(c->getConnection()->load<T>(id)) ;
        c->commit() ;
        return token ;
    }
    catch(const odb::exception &e)
    {
        LOG_ERROR << e.what() ;
        throw NotFound("Impossible de trouver la ressource à l'ID "+std::to_string(id)) ;
    }
}

}