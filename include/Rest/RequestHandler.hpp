//
// Created by jordy on 08/03/18.
//

#ifndef REQUESTHANDLER_HPP
#define REQUESTHANDLER_HPP

// Les APIS

// Les entitées
#include "../Entity/Entity.hpp"

// pistache
#include <pistache/endpoint.h>
#include <pistache/router.h>
#include <pistache/http.h>

using namespace Pistache;

/**
 * \namespace RestAPI
 * \brief Ce namespace contient les classes mettant en oeuvre
 *        le web service REST.
 */
namespace RestAPI
{


    /**
     * Cette méthode permet d'extraire facilement un paramettre URL de l'objet Pistache::Http::Uri::Query
     * @param queries Un objet contenant les paramettres.
     * @param param_name Le nom du paramettre dont on veut la valeur.
     * @return La valeur du paramettre.
     * @throw NotFound.
     */
    std::string getQueryParam(const Http::Uri::Query &queries, std::string &param_name) ;

    /**
     * \struct ResquestHandler
     * \brief Cette structure contient les méthodes distantes du web service
     */
    struct RequestHandler
    {
        /**
         * \fn checkToken(const std::string &token, Http::ResponseWriter response);
         * \brief Cette fonction est utilisé pour sécurisé les méthodes de l'API.
         * \param token Un jetton d'identification.
         * \throw SessionExpired
         * \throw NotFound
         * \return std::shared_ptr<Session> Une session.
         */
        std::shared_ptr<Entity::Session> checkToken(const std::string &token) ;

        /**
         * Cette fonction permet la mise à jour du AppInstanceId
         * d'un client.
         * @param request Une requête HTTP avec un corps json.
         * eg: {"instanceAppId":"something"}
         * @param response
         */
        void updateInstaceAppId(const Rest::Request &request, Http::ResponseWriter response) ;

        // Les routes GET
        void getAccountById(const Rest::Request &request, Http::ResponseWriter response) ;
        void getAllAccounts(const Rest::Request &request, Http::ResponseWriter response) ;
        void getAccountByCustomerId(const Rest::Request &request, Http::ResponseWriter response) ;
        void getAccountByEmployeeId(const Rest::Request &request, Http::ResponseWriter response) ;
        void getEmployeeById(const Rest::Request &request, Http::ResponseWriter response) ;
        void getAllEmployees(const Rest::Request &request, Http::ResponseWriter response) ;
        void getCustomerById(const Rest::Request &request, Http::ResponseWriter response) ;
        void getAllCustomers(const Rest::Request &request, Http::ResponseWriter response) ;
        void getCustomerByName(const Rest::Request &request, Http::ResponseWriter response) ;
        void getSubordinates(const Rest::Request &request, Http::ResponseWriter response) ;

        // Les routes DELETE
        void deletePerson(const Rest::Request &request, Http::ResponseWriter response) ;
        void deleteAccount(const Rest::Request &request, Http::ResponseWriter response) ;
        void deleteOperation(const Rest::Request &request, Http::ResponseWriter response) ;

        // Les routes POST
        void addCustomer(const Rest::Request &request, Http::ResponseWriter response) ;
        void addEmployee(const Rest::Request &request, Http::ResponseWriter response) ;
        void addAccount(const Rest::Request &request, Http::ResponseWriter response) ;
        void addOperation(const Rest::Request &request, Http::ResponseWriter response) ;

        // Les routes pour l'authentification et l'inscription et la modification
        void authentification(const Rest::Request &request, Http::ResponseWriter response) ;
        void subscription(const Rest::Request &request, Http::ResponseWriter response) ;
        void updateUserAccount(const Rest::Request &request, Http::ResponseWriter response) ;
    };
}

#endif //_REQUESTHANDLER_HPP
