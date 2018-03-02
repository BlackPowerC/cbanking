#ifndef DBCONNECTION_HPP_INCLUDED
#define DBCONNECTION_HPP_INCLUDED

#include <odb/core.hxx>
#include <odb/database.hxx>
#include <odb/mysql/database.hxx>
#include <odb/transaction.hxx>
#include <odb/result.hxx>
#include <memory>


// PLOG Journalisation
#include <plog/Log.h>

/**
 * \class DBConnection
 * \brief Cette classe repésente une connection
 *				à une base de données MYSQL.
 */

class DBConnection
{
private:
  std::unique_ptr<odb::database> connection ; /*!< Objet de connection à la base de données */
  std::string user ;
  std::string password ;
  std::string database ;
  std::string host ;
  unsigned int port ;
  static DBConnection *p_singleton ; /*!< Singleton */
  // Constructeur privée
  DBConnection(std::string user_, std::string password_,
							std::string database_, std::string host_,
							unsigned int port_) ;
public:
	static DBConnection *getInstance() ;

	/**
	 * \fn std::unique_ptr<odb::database> &getConnection() ;
	 * \brief Cette fonction renvoie l'objet de connection.
	 *				L'objet renoyer sert à faire des opérations sur
	 *				la base de données.
	 * \return Une référence sur une unique_ptr.
	 * \warning  Le pointeur renvoyer ne doit pas être stocker.
	 */
  std::unique_ptr<odb::database> &getConnection() ;

  /**
   * \fn void begin()
   * \brief Débuter une transaction
   */
  void begin() ;

	/**
   * \fn void commit()
   * \brief Valider une transaction
   */
  void commit() ;

	/**
   * \fn void reset()
   * \brief Préparer une nouvelle transaction
   */
  void reset() ;
};

#endif // DBCONNECTION_HPP_INCLUDED
