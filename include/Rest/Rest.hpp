//
// Created by jordy on 07/03/18.
//

#ifndef REST_INCLUDED_HPP
#define REST_INCLUDED_HPP

// Entête pistache
#include <pistache/endpoint.h>
#include <pistache/router.h>
#include <pistache/http.h>

// Les entités
#include "../../include/Entity/Entity.hpp"

// Les Convertisseurs
#include "../../include/Util/Converter/Converters.hpp"

// La journalisation
#include <plog/log.h>

// La STL
#include <memory>
#include <iostream>
#include <fstream>

// Json
#include <rapidjson/rapidjson.h>

using namespace pistache ;

/**
 * \class Rest
 * \brief Cette classe joue le rôle d'un serveur REST.
 */
class Rest
{
private:
    // Les champs
    Rest::Router t_router ; /*<! Le routeur du serveur */
    std::shared_ptr<Http::Endpoint> p_endpoint ; /*<! Point de chute des requêtes HTTP */
    // Les méthodes privées
    /**
     * \brief Cette fonction met en place le routage.
     */
    void routing() ;

    /**
     * @brief Cette fonction est un parseur interne de JSON.
     * @param json Une chaine de caractère au format json.
     * @param address Un pointeur sur une instance de Address.
     * @param port Un pointeur sur une instance de Port.
     */
    void parseJson(const std::string &json, Address *address, Port *port) ;
public:
    /**
     * \brief Constructeur de la classe.
     * @param json Une chaine de caractères formatée en JSON.
     */
    Rest(const std::string &json = "{\"address\":\"localhost\", \"port\":8181}") ;

    // Les fonctions de réponses
    // Insertion
    // Selection
    // Mise à jour
    // Suppression
};

#endif //REST_INCLUDED_HPP
