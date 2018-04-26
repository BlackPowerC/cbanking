//
// Created by jordy on 07/03/18.
//

#ifndef REST_INCLUDED_HPP
#define REST_INCLUDED_HPP

// Les entités
#include "../../include/Entity/Entity.hpp"

// Les Convertisseurs
#include "../../include/Util/Converter/Converters.hpp"

// La journalisation
#include <plog/Log.h>

// La STL
#include <memory>
#include <iostream>
#include <fstream>

// Json
#include <rapidjson/rapidjson.h>
#include <rapidjson/document.h>

#include "RequestHandler.hpp"

using namespace Pistache ;

namespace RestAPI
{
/**
 * \class Rest
 * \brief Cette classe joue le rôle d'un serveur REST.
 */
    class RestServer
    {
    private:
        // Les champs
        std::shared_ptr <Http::Endpoint> p_endpoint; /*!< Point de chute des requêtes HTTP */
        Rest::Router t_router; /*!< Le routeur du serveur */
        RequestHandler t_rhandler ; /*!< Le conteneur de méthode distante */
        // Les méthodes privées
        /**
         * \brief Cette fonction met en place le routage.
         */
        void routing();

        /**
         * @brief Cette fonction est un parseur interne de JSON.
         * @param json Une chaine de caractère au format json.
         * @param address Un pointeur sur une instance de Address.
         * @param port Un pointeur sur une instance de Port.
         */
        Address parseJson(const std::string &json) ;
    public:
        /**
         * \brief Constructeur de la classe.
         * @param json Une chaine de caractères formatée en JSON.
         */
        RestServer(const std::string &json = "{\"address\":\"localhost\", \"port\":8181}");

        /**
         * \fn RestServer(char *hostname, int port) ;
         * \param hostame L'ip ou le nom d'hôte du serveur REST
         * \param port Le port d'écoute du serveur REST
         */
        RestServer(char *hostname, int port) ;

        // Les fonctions de démarrage
        void start() ;
        void stop() ;
    };
}
#endif //REST_INCLUDED_HPP
