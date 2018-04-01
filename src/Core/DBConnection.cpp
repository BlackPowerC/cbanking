#include "../../include/Util/RegularFile.hpp"
#include "../../include/Core/DBConnection.hpp"
#include "../../include/Util/JSONValidator.hpp"

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
  if(p_singleton)
  {
      delete p_singleton ;
  }
}

DBConnection *DBConnection::getInstance()
{
    try
    {
        if(!p_singleton)
        {
            /* Validation du fichier de configuration */
            if(!Util::json_is_valid(Util::fromFileToString("resources/database/db_config.schema.json"),
                                    Util::fromFileToString("resources/database/db_config.json")))
            {
                std::exit(-1) ;
            }
            // Parsing
            rapidjson::Document doc; doc.Parse(Util::fromFileToString("resources/database/db_config.json").c_str()) ;
            rapidjson::Value &user = doc["user"] ;
            rapidjson::Value &passwd= doc["passwd"] ;
            rapidjson::Value &database= doc["database"] ;
            rapidjson::Value &host= doc["host"] ;
            rapidjson::Value &port= doc["port"] ;

            p_singleton = new DBConnection(
                    std::string(user.GetString()),
                    std::string(passwd.GetString()),
                    std::string(database.GetString()),
                    std::string(host.GetString()),
                    port.GetInt()) ;
            // Journalisation de la connexion
            LOG_INFO << "Connexion à la base de données éffectuée !" ;
            LOG_INFO << "user: "<< user.GetString() ;
            LOG_INFO << "host: "<< host.GetString() ;
            LOG_INFO << "database: "<< database.GetString() ;
            LOG_INFO << "port: "<< port.GetInt() ;
            LOG_INFO << "type: "<< doc["type"].GetString() ;
        }
        return p_singleton ;
    }
    catch(const FileStreamError &fse)
    {
        // Pour les tests en local
#include "../../include/Core/DBConnection.hpp"
        p_singleton = new DBConnection("jordy", "dalila", "test_cbanking", "172.17.0.2", 3306) ;
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
