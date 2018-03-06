namespace API
{

template <typename T>
void PersistenceAPI::erase(long id)
{
	try
	{
	DBConnection::getInstance()->reset() ;
    DBConnection::getInstance()->getConnection()->erase<T>(id) ;
    DBConnection::getInstance()->commit() ;
	}catch(const odb::exception &e)
	{
    LOG_ERROR << e.what() ;
    throw NotErasable("Impossible de supprimer la ressource ayant l'ID: "+std::to_string(id)) ;
	}
}

template <typename T>
void PersistenceAPI::update(T &t_obj)
{
	try
	{
	DBConnection::getInstance()->reset() ;
    DBConnection::getInstance()->getConnection()->update<T>(t_obj) ;
    DBConnection::getInstance()->commit() ;
	}catch(const odb::exception &e)
	{
    LOG_ERROR << e.what() ;
    throw NotUpdatable("Impossible de mettre à jour la ressource ayant l'ID: "+std::to_string(t_obj.getId())) ;
	}
}

template <typename T>
void PersistenceAPI::insert(T &t_obj)
{
	try
	{
		DBConnection::getInstance()->reset() ;
    DBConnection::getInstance()->getConnection()->persist(t_obj) ;
    DBConnection::getInstance()->commit() ;
	}catch(const odb::exception &e)
	{
    LOG_ERROR << e.what() ;
    throw std::exception() ;
	}
}

template <typename T>
std::vector<std::shared_ptr<T> > PersistenceAPI::findAll()
{
	try
	{
    odb::session t_session ;
		std::vector<std::shared_ptr<T> > objects ;
    DBConnection *s = DBConnection::getInstance() ;
		s->reset() ;
		odb::result<T> t_result(s->getConnection()->query<T>()) ;
		for(auto it = t_result.begin(); it!= t_result.end(); it++)
		{
			objects.push_back(it.load()) ;
		}
		s->commit() ;
		return objects;
	}
	catch(const odb::exception &e)
	{
		LOG_ERROR << e.what() ;
		throw NotFound("Recherche infructueuse !") ;
	}
}

template <typename T>
std::shared_ptr<T> PersistenceAPI::findById(long id)
{
  try
  {
		odb::session t_session ;
    DBConnection *s = DBConnection::getInstance() ;
    s->reset() ;
    std::shared_ptr<T> object((s->getConnection()->load<T>(id))) ;
    s->commit() ;
    return object ;
  }
  catch(const odb::exception &e)
  {
  	LOG_ERROR << e.what() ;
  	throw NotFound("Impossible de trouver la ressource à l'ID "+std::to_string(id)) ;
  }
}

}
