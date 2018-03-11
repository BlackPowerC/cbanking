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
     * \struct ResquestHandler
     * \brief Cette structure contient les méthodes distantes du web service
     */
    struct RequestHandler
    {
        // Les routes GET
        void getAccountById(const Rest::Request &request, Http::ResponseWriter response) ;
        void getAccountByCustomerId(const Rest::Request &request, Http::ResponseWriter response) ;
        void getAccountByEmployeeId(const Rest::Request &request, Http::ResponseWriter response) ;
        void getEmployeeById(const Rest::Request &request, Http::ResponseWriter response) ;
        void getAllEmployees(const Rest::Request &request, Http::ResponseWriter response) ;
        void getCustomerById(const Rest::Request &request, Http::ResponseWriter response) ;
        void getAllCustomers(const Rest::Request &request, Http::ResponseWriter response) ;
        void getCustomerByName(const Rest::Request &request, Http::ResponseWriter response) ;

        // Les routes DELETE
        void deletePerson(const Rest::Request &request, Http::ResponseWriter response) ;
        void deleteAccount(const Rest::Request &request, Http::ResponseWriter response) ;
        void deleteOperation(const Rest::Request &request, Http::ResponseWriter response) ;

        // Les routes POST
        void addCustomer(const Rest::Request &request, Http::ResponseWriter response) ;
        void addEmployee(const Rest::Request &request, Http::ResponseWriter response) ;
        void addAccount(const Rest::Request &request, Http::ResponseWriter response) ;
        void addOperation(const Rest::Request &request, Http::ResponseWriter response) ;

        // Les routes pour l'authentification
        void authentification(const Rest::Request &request, Http::ResponseWriter response) ;
    };
}

#endif //_REQUESTHANDLER_HPP
