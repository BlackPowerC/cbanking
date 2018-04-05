namespace API
{

template <typename T>
std::vector<std::shared_ptr<T> > PersonAPI::findByName(const std::string &name)
{
	if(!name.size())
  {
    throw IllegalArgument("L'argument name ne peut être une chaine de caractères vide !'") ;
  }
  try
  {
		DBConnection *s = DBConnection::getInstance() ;
		s->reset() ;
		odb::session t_session ;
    std::vector<std::shared_ptr<T> > persons ;
    odb::query<T> t_query(odb::query<T>::name.like(name+"%")) ;
    odb::result<T> t_result(DBConnection::getInstance()->getConnection()->query(t_query)) ;
    if(!t_result.size())
    {
      throw NotFound("Recherche infructeuse !") ;
    }
		for(auto it = t_result.begin(); it!= t_result.end(); it++)
		{
			persons.push_back(it.load()) ;
		}
		s->commit() ;
		return persons ;
  }catch(const odb::exception &e)
  {
  	LOG_ERROR << e.what() ;
  	throw NotFound("Recherche infructeuse !") ;
  }
}

template <typename T>
std::shared_ptr<T> PersonAPI::findByCredentials(const std::string &email, const std::string &passwd)
{
    if(email.empty() || passwd.empty())
    {
        throw IllegalArgument("Un des arguments est invalide !") ;
    }
    try
    {
        odb::session s ;
        DBConnection *c = DBConnection::getInstance() ;
        c->reset() ;
        odb::query<T> t_query(odb::query<T>::email == email/* && odb::query<T>::passwd == passwd*/);
        odb::result<T> t_result(c->getConnection()->query(t_query)) ;
        if(t_result.empty())
        {
            throw NotFound("Recherche infructeuse !") ;
        }
        std::shared_ptr<T> person(t_result.begin().load()) ;
        c->commit() ;
        return person ;

    }catch(const odb::exception &nf)
    {
        LOG_ERROR << nf.what() ;
        throw NotFound("Recherche infructeuse !") ;
    }
}

}
