//
// Created by jordy on 10/03/18.
//

#include "../../include/Rest/Rest.hpp"

namespace RestAPI
{
    void RestServer::routing()
    {
        /* Les routes GET */
        // Un compte particulier
        Rest::Routes::Get(this->t_router,"/account/get/:id",
                          Rest::Routes::bind(&RequestHandler::getAccountById, &this->t_rhandler)) ;
        // Les comptes d'un client
        Rest::Routes::Get(this->t_router,"/customer/acount/get/:id",
                          Rest::Routes::bind(&RequestHandler::getAccountByCustomerId, &this->t_rhandler)) ;
        // Les comptes créer par un employee
        Rest::Routes::Get(this->t_router, "/employee/account/get:id",
                          Rest::Routes::bind(&RequestHandler::getAccountByEmployeeId, &this->t_rhandler)) ;
        // Tout les employées
        Rest::Routes::Get(this->t_router, "/employee/get/all",
                          Rest::Routes::bind(&RequestHandler::getAllEmployees, &this->t_rhandler)) ;
        // Un employee avec un id
        Rest::Routes::Get(this->t_router, "/employee/get/:id",
                          Rest::Routes::bind(&RequestHandler::getEmployeeById, &this->t_rhandler)) ;
        // Tout les clients
        Rest::Routes::Get(this->t_router, "/customer/get/all",
                          Rest::Routes::bind(&RequestHandler::getAllCustomers, &this->t_rhandler)) ;
        // Un client avec un id
        Rest::Routes::Get(this->t_router, "/customer/get/:id",
                          Rest::Routes::bind(&RequestHandler::getCustomerById, &this->t_rhandler)) ;
        // Un client avec un nom
        Rest::Routes::Get(this->t_router, "/customer/get/:name",
                          Rest::Routes::bind(&RequestHandler::getCustomerByName, &this->t_rhandler)) ;

        /* Les requetes POST */
    }

    Address RestServer::parseJson(const std::string &json)
    {
        rapidjson::Document doc ;
        if(doc.Parse(json.c_str()).HasParseError())
        {
            LOG_FATAL << "Impossible de lancer le serveur REST: json parse error !\n" ;
            std::exit(EXIT_FAILURE) ;
        }
        if(!doc.HasMember("address") || !doc.HasMember("port"))
        {
            LOG_FATAL << "Impossible de lancer le serveur REST: configuration incorrect !\n" ;
            std::exit(EXIT_FAILURE) ;
        }
        rapidjson::Value adr = doc["address"] ;
        rapidjson::Value port = doc["port"] ;
        return Address(adr.GetString(), port.GetInt()) ;
    }

    RestServer::RestServer(const std::string &json = "{\"address\":\"localhost\", \"port\":8181}")
    {
        if(!json.size())
        {
            std::ifstream config("../../resources/config/rest/json") ;
            if(config.fail())
            {
                LOG_FATAL << "Impossible de lancer le serveur REST: configuration introuvable !\n" ;
                std::exit(EXIT_FAILURE) ;
            }
            // je me position à la fin du fichier
            config.seekg(std::ios::end) ;
            long filesize = config.tellg()+1 ;
            json.resize(filesize) ;
            config.seekg(std::ios::beg) ;
            config.read(&json[0], filesize) ;
            config.close() ;
        }
        Address address(this->parseJson(json)) ;
        this->p_endpoint = std::make_shared<Http::Endpoint>(address) ;
    }

    void RestServer::start()
    {

    }

    void RestServer::stop()
    {

    }
}