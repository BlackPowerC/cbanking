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

/**
 * \class PersistenceAPI
 * \brief Classe de base pour l'api de persistance.
 *				Elle contient les méthodes de bases pour manipuler
 *				tout les classes persitantes.
 *
 */
class PersistenceAPI
{
public:
	virtual void doNothing() = 0;
	/**
	 * \brief Cette fonction supprime un entité de la base de données.
	 * \param id L'ID de l'entité.
	 * \throw NotErasable.
	 */
	template <typename T>
	void erase(long id) ;

	/**
	 * \brief Cette fonction met à jour une entité de la base de données.
	 * \param t_obj Une référence sur l'objet persistant.
	 * \throw NotUpdatable.
	 */
	template <typename T>
	void update(T &t_obj) ;

	/**
	 * \brief Cette fonction insert une entité de la base de données.
	 * \param t_obj Une référence sur l'objet persistant.
	 * \return L'id de l'objet sauvegardé.
	 */
	template <typename T>
 	long insert(T &t_obj) ;

	/**
	 * \fn std::vector<std::shared_ptr<T> > findAll()
	 * \brief Cette fonction cherche toute les données
	 *		  	d'une table dans la base de données.
	 * \return Une vecteur de shared_ptr.
	 */
	template <typename T>
  std::vector<std::shared_ptr<T> > findAll() ;

	/**
	 * \fn std::unique_ptr<T> findById(long id)
	 * \brief Cette fonction cherche une ligne d'une table grâce un ID.
	 * \throw IllegalArgument si id est négatif.
	 * \throw NotFound si rien n'est trouvé.
	 * \param id L'ID de la ligne.
	 * \return Un shared_ptr contenant l'instance de la classe persistante.
	 */
	template <typename T>
    std::shared_ptr<T> findById(long id) ;
};

}

#include <odb/query.hxx>
#include <odb/result.hxx>
#include <odb/exception.hxx>
#include "../Core/DBConnection.hpp"

// STL
#include <string>
#include <iostream>
#include <exception>

// Plog
#include <plog/Log.h>

// Exceptions personnalisées
#include "../Exception.hpp"

#include "PersistenceAPI.tpp"

#endif // ENTITYAPI_HPP_INCLUDED
