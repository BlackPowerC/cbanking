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
        Rest::Routes::Get(this->t_router,"/customer/account/get/:id",
                          Rest::Routes::bind(&RequestHandler::getAccountByCustomerId, &this->t_rhandler)) ;
        // Les comptes créer par un employee
        Rest::Routes::Get(this->t_router, "/employee/account/get/:id",
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
        Rest::Routes::Get(this->t_router, "/customer/get/id/:value",
                          Rest::Routes::bind(&RequestHandler::getCustomerById, &this->t_rhandler)) ;
        // Un client avec un nom
        Rest::Routes::Get(this->t_router, "/customer/get/name/:value",
                          Rest::Routes::bind(&RequestHandler::getCustomerByName, &this->t_rhandler)) ;

        /* Les requetes POST */
        /* Les requetes DELETE */
        // Un client
        Rest::Routes::Delete(this->t_router, "/person/delete/:id",
                             Rest::Routes::bind(&RequestHandler::deletePerson, &this->t_rhandler)) ;
        // Un compte
        Rest::Routes::Delete(this->t_router, "/account/delete/:id",
                             Rest::Routes::bind(&RequestHandler::deleteAccount, &this->t_rhandler)) ;
        // Une operation
        Rest::Routes::Delete(this->t_router, "/operation/delete/:id",
                             Rest::Routes::bind(&RequestHandler::deleteOperation, &this->t_rhandler)) ;    
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
        rapidjson::Value &adr = doc["address"] ;
        rapidjson::Value &port = doc["port"] ;
        LOG_INFO << "Serveur REST sur " << adr.GetString() <<":"<<port.GetInt() << " !\n" ;
        return Address(adr.GetString(), port.GetInt()) ;
    }

    RestServer::RestServer(const std::string &json)
    {
        Address adr ;
        if(!json.size())
        {
            std::string json2 ;
            std::ifstream config("../../resources/config/rest/json") ;
            if(config.fail())
            {
                LOG_FATAL << "Impossible de lancer le serveur REST: configuration introuvable !\n" ;
                std::exit(EXIT_FAILURE) ;
            }
            // je me position à la fin du fichier
            config.seekg(std::ios::end) ;
            long filesize = config.tellg()+ 1L ;
            json2.resize(filesize) ;
            config.seekg(std::ios::beg) ;
            config.read(&json2[0], filesize) ;
            config.close() ;
            adr = this->parseJson(json2) ;
        }
        else
        {
            adr = this->parseJson(json) ;
        }

        this->p_endpoint = std::make_shared<Http::Endpoint>(adr) ;
        this->routing() ;
    }

    void RestServer::start()
    {
        auto opts = Http::Endpoint::options()
                .threads(2)
                .flags(Tcp::Options::InstallSignalHandler);
        this->p_endpoint->init(opts);
        this->routing() ;
        this->p_endpoint->setHandler(this->t_router.handler()) ;
        this->p_endpoint->serve() ;
    }

    void RestServer::stop()
    {
        this->p_endpoint->shutdown();
    }
}