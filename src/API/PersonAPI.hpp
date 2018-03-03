#ifndef ENTITYAPI_HPP_INCLUDED
#define ENTITYAPI_HPP_INCLUDED

/*
 * \file PersonAPI.hpp
 * \author jordy fatigba fatigba@gmail.com
 * \brief Ce fichier contient toute les classes
 *				d'API pour faire des opérations dans la
 *				base de données sur les tables Customer,
 *				Person, et Employee.
 */

#include <vector>
#include <memory>

namespace API
{

/**
 * \class PersonAPI
 * \brief Cette classe permet de faire des opérations
 *        d'insertion de suppression de recherche dans
 *		  	la base de données avec les entitées
 *		 		Person, Customer et Employee.
 */
class PersonAPI
{
private:
	static PersonAPI *p_singleton ;
	PersonAPI() ;
public:
  static PersonAPI *getInstance() ;
  ~PersonAPI() ;

	template <typename T>
	void update(const T &t_person) ;

	template <typename T>
  void insert(const T &t_person) ;

	/**
	 * \fn std::vector<std::shared_ptr<T> > findAll()
	 * \brief Cette fonction cherche toute les Personnes
	 *				enregistrées dans la base de données.
	 * \return Une vecteur de shared_ptr.
	 */
	template <typename T>
  std::vector<std::shared_ptr<T> > findAll() ;

	/**
	 * \fn std::unique_ptr<T> findById(long id)
	 * \brief Cette fonction cherche une Personne grâce un ID.
	 * \throw IllegalArgument.
	 * \throw NotFound.
	 * \param id L'ID de la Personne.
	 * \param typeID Le TypeID de la classe.
	 * \return Un unique_ptr contenant l'instance de la classe.
	 */
	template <typename T>
  std::unique_ptr<T> findById(long id) ;

  	/**
	 * \fn std::unique_ptr<Entity::Person> findByName(const std::string &name, const TypeID typeID) ;
	 * \brief Cette fonction cherche une Personne avec un nom commençant
	 *				par name.
	 * \throw IllegalArgument.
	 * \throw NotFound.
	 * \param name Le début du nom de la personne.
	 * \param typeID Le TypeID de la classe.
	 * \return Une vecteur de shared_ptr.
	 */
	template <typename T>
  std::vector<std::shared_ptr<T> > findByName(const std::string &name) ;
};

}
#endif // ENTITYAPI_HPP_INCLUDED
