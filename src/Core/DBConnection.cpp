#include "../../include/Core/DBConnection.hpp"

DBConnection *DBConnection::p_singleton = nullptr ;

DBConnection::DBConnection(std::string user_, std::string password_,
                           std::string database_, std::string host_, uint port_):
    user(user_),
    password(password_),
    database(database_),
    host(host_),
    port(port_)
{
    this->p_connection = std::move(std::make_unique<odb::mysql::database>(user, password, database, host, port)) ;
    this->p_transaction = std::move(std::make_unique<odb::transaction>(this->p_connection->begin()));
}

DBConnection::~DBConnection()
{
  delete p_singleton ;
}

DBConnection *DBConnection::getInstance()
{
    try
    {
        if(!p_singleton)
        {
            p_singleton = new DBConnection("jordy", "dalila", "test_cbanking", "172.17.0.2",3306) ;
            LOG_INFO << "Connexion à la base de données éffectuée !" ;
        }
        return p_singleton ;
    }
    catch(const odb::exception &odb_e)
    {
        LOG_FATAL << odb_e.what() ;
        exit(-1) ;
    }
    catch(const std::bad_alloc &ba)
    {
        LOG_FATAL << ba.what() ;
        exit(-1) ;
    }
}

std::unique_ptr<odb::database> &DBConnection::getConnection()
{
	return this->p_connection ;
}

void DBConnection::commit()
{
	this->p_transaction->commit() ;
}

void DBConnection::reset()
{
	this->p_transaction->reset(this->p_connection->begin()) ;
}
