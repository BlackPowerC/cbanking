namespace API
{

// PersonAPI
PersonAPI* PersonAPI::p_singleton = nullptr ;

PersonAPI::PersonAPI()
{

}

PersonAPI* PersonAPI::getInstance()
{
	if(p_singleton == nullptr)
	{
		p_singleton = new PersonAPI ;
	}
	return p_singleton ;
}

PersonAPI::~PersonAPI()
{
	if(p_singleton)
	{
		delete p_singleton ;
	}
}

template <typename T>
std::vector<std::shared_ptr<T> > PersonAPI::findByName(const std::string &name)
{
	if(!name.size())
  {
    throw IllegalArgument("L'argument name ne peut être une chaine de caractères vide !'") ;
  }
  try
  {
		odb::session t_session ;
    std::vector<std::shared_ptr<T> > persons ;
    odb::query<T> t_query(odb::query<T>::name.like(name+"%")) ;
    odb::result<T> t_result(DBConnection::getInstance()->getConnection()->query(t_query)) ;
		for(auto it = t_result.begin(); it!= t_result.end(); it++)
		{
			persons.push_back(it.load()) ;
		}
		return persons ;
  }catch(const odb::exception &e)
  {
  	LOG_ERROR << e.what() ;
  	throw NotFound("Recherche infructeuse !") ;
  }
}

}
