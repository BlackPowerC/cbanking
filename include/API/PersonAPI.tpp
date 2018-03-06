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

}
