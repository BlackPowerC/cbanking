//
// Created by jordy on 10/03/18.
//

#include "../../include/Rest/Rest.hpp"

namespace RestAPI
{
    void Rest::routing()
    {
        // Les route
    }

    Address Rest::parseJson(const std::string &json)
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

    Rest::Rest(const std::string &json = "{\"address\":\"localhost\", \"port\":8181}")
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

    void Rest::start()
    {

    }

    void Rest::stop()
    {

    }
}