/**
 * \brief Ce fichier contient l'implémentation de méthodes
 *        de la classe RequestHandler.
 * \date 10/03/18
 * \author jordy
 */

#include "../../include/Rest/RequestHandler.hpp"

namespace RestAPI
{
    void RequestHandler::getAccountById(const Rest::Request &request, Http::ResponseWriter response)
    {
    	response.send(Http::Code::Ok, "Tout est OK", Http::Mime:MediaType::fromString("text/plain"));
    }
    void RequestHandler::getAccountByCustomerId(const Rest::Request &request, Http::ResponseWriter response)
    {
    	response.send(Http::Code::Ok, "Tout est OK", Http::Mime:MediaType::fromString("text/plain"));
    }
    void RequestHandler::getAccountByEmployeeId(const Rest::Request &request, Http::ResponseWriter response)
    {
    	response.send(Http::Code::Ok, "Tout est OK", Http::Mime:MediaType::fromString("text/plain"));
    }
    void RequestHandler::getEmployeeById(const Rest::Request &request, Http::ResponseWriter response)
    {
    	response.send(Http::Code::Ok, "Tout est OK", Http::Mime:MediaType::fromString("text/plain"));
    }
    void RequestHandler::getAllEmployees(const Rest::Request &request, Http::ResponseWriter response)
    {
    	response.send(Http::Code::Ok, "Tout est OK", Http::Mime:MediaType::fromString("text/plain"));
    }
    void RequestHandler::getCustomerById(const Rest::Request &request, Http::ResponseWriter response)
    {
    	response.send(Http::Code::Ok, "Tout est OK", Http::Mime:MediaType::fromString("text/plain"));
    }
    void RequestHandler::getAllCustomers(const Rest::Request &request, Http::ResponseWriter response)
    {
    	response.send(Http::Code::Ok, "Tout est OK", Http::Mime:MediaType::fromString("text/plain"));
    }
    void RequestHandler::getCustomerByName(const Rest::Request &request, Http::ResponseWriter response)
    {
    	response.send(Http::Code::Ok, "Tout est OK", Http::Mime:MediaType::fromString("text/plain"));
    }

    // Les routes DELETE
    void RequestHandler::deletePerson(const Rest::Request &request, Http::ResponseWriter response)
    {
    	response.send(Http::Code::Ok, "Tout est OK", Http::Mime:MediaType::fromString("text/plain"));
    }
    void RequestHandler::deleteAccount(const Rest::Request &request, Http::ResponseWriter response)
    {
    	response.send(Http::Code::Ok, "Tout est OK", Http::Mime:MediaType::fromString("text/plain"));
    }
    void RequestHandler::deleteOperation(const Rest::Request &request, Http::ResponseWriter response)
    {
    	response.send(Http::Code::Ok, "Tout est OK", Http::Mime:MediaType::fromString("text/plain"));
    }

    // Les routes POST
    void RequestHandler::addCustomer(const Rest::Request &request, Http::ResponseWriter response)
    {
    	response.send(Http::Code::Ok, "Tout est OK", Http::Mime:MediaType::fromString("text/plain"));
    }
    void RequestHandler::addEmployee(const Rest::Request &request, Http::ResponseWriter response)
    {
    	response.send(Http::Code::Ok, "Tout est OK", Http::Mime:MediaType::fromString("text/plain"));
    }
    void RequestHandler::addAccount(const Rest::Request &request, Http::ResponseWriter response)
    {
    	response.send(Http::Code::Ok, "Tout est OK", Http::Mime:MediaType::fromString("text/plain"));
    }
    void RequestHandler::addOperation(const Rest::Request &request, Http::ResponseWriter response)
    {
    	response.send(Http::Code::Ok, "Tout est OK", Http::Mime:MediaType::fromString("text/plain"));
    }

    // Les routes pour l'authentification
    void RequestHandler::authentification(const Rest::Request &request, Http::ResponseWriter response)
    {
    	response.send(Http::Code::Ok, "Tout est OK", Http::Mime:MediaType::fromString("text/plain"));
    }
}