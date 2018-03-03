#ifndef ENTITYAPI_HPP_INCLUDED
#define ENTITYAPI_HPP_INCLUDED

/*
 * \file PersistenceAPI.hpp
 * \author jordy fatigba fatigba@gmail.com
 * \brief Ce fichier contient toute les classes
 *				d'API pour faire des opérations dans la
 *				base de données.
 */

#include <vector>
#include <memory>

namespace API
{

class PersistenceAPI
{
public:
	~virtual PersistenceAPI() = 0 ;

	template <typename T>
	void erase(T &t_person) ;

	template <typename T>
	void update(T &t_person) ;

	template <typename T>
 	void insert(T &t_person) ;

	/**
	 * \fn std::vector<std::shared_ptr<T> > findAll()
	 * \brief Cette fonction cherche toute les données
	 *		  d'une table dans la base de données.
	 * \return Une vecteur de shared_ptr.
	 */
	template <typename T>
  std::vector<std::shared_ptr<T> > findAll() ;

	/**
	 * \fn std::unique_ptr<T> findById(long id)
	 * \brief Cette fonction cherche une ligne d'une table grâce un ID.
	 * \throw IllegalArgument.
	 * \throw NotFound.
	 * \param id L'ID de la ligne.
	 * \return Un unique_ptr contenant l'instance de la classe persistante.
	 */
	template <typename T>
  std::shared_ptr<T> findById(long id) ;
};

}

#include "PersistenceAPI.tpp"

#endif // ENTITYAPI_HPP_INCLUDED
