/**
 * \brief Ce fichier contient l'implémentation de méthodes
 *        de la classe RequestHandler.
 * \date 10/03/18
 * \author jordy
 */

#include "../../include/Util/Crypto.hpp"

#include "../../include/Exception.hpp"
#include "../../include/Util/RegularFile.hpp"
#include "../../include/Util/JSONValidator.hpp"
#include "../../include/Rest/RequestHandler.hpp"

// API de persistence
#include "../../include/API/PersistenceAPI.hpp"
#include "../../include/API/AccountAPI.hpp"
#include "../../include/API/PersonAPI.hpp"
#include "../../include/API/OperationAPI.hpp"
#include "../../include/API/SessionAPI.hpp"

#include "../../include/Util/Converter/Converters.hpp"

#include <exception>
#include <plog/Log.h>

// api JSON
#include <rapidjson/rapidjson.h>
#include <rapidjson/document.h>

// STL
#include <cstring>
#include <memory>
#include <ctime>

using namespace Entity ;
using namespace API ;
using namespace Util ;

namespace RestAPI
{
    // /account/get/all sécurisé
    void RequestHandler::getAllAccounts(const Rest::Request &request, Http::ResponseWriter response)
    {
        try
        {
            std::string token = request.param(":token").as<std::string>() ;
            // Vérification de session
            std::shared_ptr<Session> p_user_session = SessionAPI::getInstance()->findByToken<Session>(token) ;
            PersonAPI::getInstance()->findById<Employee>(p_user_session->getPerson()->getId()) ;
            if(p_user_session->getEnd() < (ulong) std::time(nullptr))
            {
                std::string err_msg = "{\"erreur\":[\"message\":\"session expirée\"]}" ;
                response.send(Http::Code::Unauthorized, err_msg, MIME(Application, Json)) ;
                return ;
            }
            // Traitement de la requête
            std::vector<std::shared_ptr<Account> > accounts = AccountAPI::getInstance()->findAll<Account>() ;
            std::string json("[\n\t") ;
            for(auto &account : accounts)
            {
                json += AccountConverter().entityToJson(account)+",\n";
            }
            json.pop_back() ;
            json.pop_back() ;
            json += "\t]\n";
            response.send(Http::Code::Ok, json, MIME(Application, Json)) ;

        }
        catch(const NotFound &nf)
        {
            LOG_WARNING << nf.what() ;
            std::string err_msg = "{\"erreur\":[\"message\":\"non authorisé sur cet API\"]}" ;
            response.send(Http::Code::Unauthorized, err_msg, MIME(Application, Json)) ;
            return ;
        }
    }

    void RequestHandler::getAccountById(const Rest::Request &request, Http::ResponseWriter response)
    {
        /* Vérifions le paramettre */
        response.headers().add(std::make_shared<Pistache::Http::Header::AccessControlAllowOrigin>("http://127.0.0.1")) ;
        long id ;
        try
        {
            id = request.param(":id").as<int>() ;
        }catch(const std::exception &e)
        {
            LOG_ERROR << e.what() ;
            response.send(Http::Code::Not_Acceptable, e.what(), Http::Mime::MediaType::fromString("text/plain")) ;
            return ;
        }
        // Pas d'erreur on continue
        bool flag = true ;
        std::string json ;
        std::shared_ptr<Account> account ;
        {
            try
            {
                /* voyons voir si le comptes est courant ou non */
                account = AccountAPI::getInstance()->findById<CurrentAccount>(id) ;
            }catch(const NotFound &nf)
            {
                flag = false ;
            }
        }
        // Il n'y a pas de compte courant avec cette ID, on essaie
        // avec un compte d'épargne.
        if(!flag)
        {
            try
            {
                /* voyons voir si le compte est courant ou non */
                account = AccountAPI::getInstance()->findById<SavingsAccount>(id) ;
            }catch(const NotFound &nf)
            {
                LOG_ERROR << nf.what() ;
                response.send(Http::Code::Not_Found, nf.what(), MIME(Text, Plain)) ;
                return ;
            }
            // Il s'agit d'un compte d'épargne. On envoie une réponse.
            json = SavingsAccountConverter().entityToJson(dynamic_cast<SavingsAccount*>(account.get()));
            response.send(Http::Code::Ok, json, MIME(Application, Json)) ;
            return ;
        }
        // Il s'agit d'un compte courant j'envoie la bonne réponse
        json = CurrentAccountConverter().entityToJson(dynamic_cast<CurrentAccount*>(account.get()));
        response.send(Http::Code::Ok, json, MIME(Application, Json)) ;
    }

    void RequestHandler::getAccountByCustomerId(const Rest::Request &request, Http::ResponseWriter response)
    {
        try
        {
            long id = request.param(":id").as<int>() ;
            std::vector<std::shared_ptr<Account> > accounts = AccountAPI::getInstance()->findByCustomerId<Account>(id) ;
            std::string json("[\n\t") ;
            for(auto &account : accounts)
            {
                json += AccountConverter().entityToJson(account)+",\n";
            }
            json.pop_back() ;
            json.pop_back() ;
            json += "\t]\n";
            response.send(Http::Code::Ok, json, MIME(Application, Json)) ;
        }
        catch(const NotFound &nf)
        {
            LOG_ERROR << nf.what() ;
            response.send(Http::Code::Not_Found, nf.what(), MIME(Text, Plain)) ;
        }
        catch(const std::exception &e)
        {
            LOG_ERROR << e.what() ;
            response.send(Http::Code::Not_Acceptable, e.what(), Http::Mime::MediaType::fromString("text/plain")) ;
        }
    }

    void RequestHandler::getAccountByEmployeeId(const Rest::Request &request, Http::ResponseWriter response)
    {
        try
        {
            long id = request.param(":id").as<int>() ;
            std::vector<std::shared_ptr<Account> > accounts = AccountAPI::getInstance()->findByEmployeeId<Account>(id) ;
            std::string json("[\n\t") ;
            for(auto &account : accounts)
            {
                json += AccountConverter().entityToJson(account)+",\n";
            }
            json.pop_back() ;
            json.pop_back() ;
            json += "\t]\n";
            response.send(Http::Code::Ok, json, MIME(Application, Json)) ;
        }
        catch(const NotFound &nf)
        {
            LOG_ERROR << nf.what() ;
            response.send(Http::Code::Not_Found, nf.what(), MIME(Text, Plain)) ;
        }
        catch(const std::exception &e)
        {
            LOG_ERROR << e.what() ;
            response.send(Http::Code::Not_Acceptable, e.what(), Http::Mime::MediaType::fromString("text/plain")) ;
        }
    }

    void RequestHandler::getEmployeeById(const Rest::Request &request, Http::ResponseWriter response)
    {
        /* Vérifions le paramettre */
        try
        {
            long id = request.param(":id").as<int>() ;
            std::shared_ptr<Employee> person = PersonAPI::getInstance()->findById<Employee>(id) ;
            std::string json = EmployeeConverter().entityToJson(person.get());
            response.send(Http::Code::Ok, json, MIME(Application, Json)) ;
        }
        catch(const NotFound &nf)
        {
            LOG_ERROR << nf.what() ;
            response.send(Http::Code::Not_Found, nf.what(), MIME(Text, Plain)) ;
        }
        catch(const std::exception &e)
        {
            LOG_ERROR << e.what() ;
            response.send(Http::Code::Not_Acceptable, e.what(), Http::Mime::MediaType::fromString("text/plain")) ;
        }
    }

    void RequestHandler::getAllEmployees(const Rest::Request &request, Http::ResponseWriter response)
    {
        try
        {
            std::vector<std::shared_ptr<Employee> > employees = PersonAPI::getInstance()->findAll<Employee>() ;
            std::string json("[\n\t") ;
            for(auto &employee : employees)
            {
                json += EmployeeConverter().entityToJson(employee)+",\n";
            }
            json.pop_back() ;
            json.pop_back() ;
            json += "\t]\n";
            response.send(Http::Code::Ok, json, MIME(Application, Json)) ;
        }
        catch(const NotFound &nf)
        {
            LOG_ERROR << nf.what() ;
            response.send(Http::Code::Not_Found, nf.what(), MIME(Text, Plain)) ;
        }
    }

    void RequestHandler::getCustomerById(const Rest::Request &request, Http::ResponseWriter response)
    {
        /* Vérifions le paramettre */
        try
        {
            long id = request.param(":value").as<int>() ;
            std::shared_ptr<Customer> person = PersonAPI::getInstance()->findById<Customer>(id) ;
            std::string json = CustomerConverter().entityToJson(person.get());
            response.send(Http::Code::Ok, json, MIME(Application, Json)) ;
        }
        catch(const NotFound &nf)
        {
            LOG_ERROR << nf.what() ;
            response.send(Http::Code::Not_Found, nf.what(), MIME(Text, Plain)) ;
        }
        catch(const std::exception &e)
        {
            LOG_ERROR << e.what() ;
            response.send(Http::Code::Not_Acceptable, e.what(), Http::Mime::MediaType::fromString("text/plain")) ;
        }
    }

    void RequestHandler::getAllCustomers(const Rest::Request &request, Http::ResponseWriter response)
    {
        try
        {
            std::vector<std::shared_ptr<Customer> > customers = PersonAPI::getInstance()->findAll<Customer>() ;
            std::string json("[\n\t") ;
            for(auto &customer : customers)
            {
                json += CustomerConverter().entityToJson(customer)+",\n";
            }
            json.pop_back() ;
            json.pop_back() ;
            json += "\t]\n";
            response.send(Http::Code::Ok, json, MIME(Application, Json)) ;
        }
        catch(const NotFound &nf)
        {
            LOG_ERROR << nf.what() ;
            response.send(Http::Code::Not_Found, nf.what(), MIME(Text, Plain)) ;
        }
    }

    void RequestHandler::getCustomerByName(const Rest::Request &request, Http::ResponseWriter response)
    {
        // Header pour authorisé l'ajax
        response.headers().add(std::make_shared<Pistache::Http::Header::AccessControlAllowOrigin>("http://127.0.0.1")) ;
        try
        {
            std::string name_pattern = request.param(":value").as<std::string>() ;
            std::vector<std::shared_ptr<Customer> > customers = PersonAPI::getInstance()->findByName<Customer>(name_pattern) ;
            CustomerConverter cc ;
            std::string json("[\n\t") ;
            for(auto &customer : customers)
            {
                json += cc.entityToJson(customer)+",\n";
            }
            json.pop_back() ;
            json.pop_back() ;
            json += "\t]\n";
            response.send(Http::Code::Ok, json, MIME(Application, Json)) ;

        }catch(const NotFound &nf)
        {
            LOG_ERROR << nf.what() ;
            response.send(Http::Code::Not_Found, nf.what(), MIME(Text, Plain)) ;
        }
        catch(const std::exception &e)
        {
            LOG_ERROR << e.what() ;
            response.send(Http::Code::Not_Acceptable, e.what(), MIME(Text, Plain)) ;
        }
    }

    void RequestHandler::getSubordinates(const Rest::Request &request, Http::ResponseWriter response)
    {
        try
        {
            rapidjson::Document doc ; doc.Parse(request.body().c_str()) ;
            if(doc.HasParseError() || !doc.HasMember("token"))
            {
                LOG_WARNING << request.body() ;
                response.send(Http::Code::Bad_Request) ;
                return ;
            }
            rapidjson::Value &token = doc["token"];
            std::shared_ptr<Session> p_employee_session = SessionAPI::getInstance()
                                                                  ->findByToken<Session>(std::string(token.GetString())) ;
            PersonAPI::getInstance()->findById<Employee>(p_employee_session->getPerson()->getId()) ;
            if(p_employee_session->getEnd() < (ulong) std::time(nullptr))
            {
                std::string err_msg = "{\"erreur\":[\"message\":\"session expirée\"]}" ;
                response.send(Http::Code::Unauthorized, err_msg, MIME(Application, Json)) ;
                return ;
            }

            Employee *p_employee = dynamic_cast<Employee*>(p_employee_session->getPerson()) ;
            std::string json_response("[\n\t") ;
            for(const auto &employee : p_employee->getSubordinate())
            {
                json_response += EmployeeConverter().entityToJson(employee)+",\n";
            }
            json_response.pop_back() ;
            json_response.pop_back() ;
            json_response += "\t]\n";

            response.send(Http::Code::Ok, json_response, MIME(Application, Json)) ;
        }
        catch(const NotFound &nf)
        {
            LOG_WARNING << nf.what() ;
            std::string err_msg = "{\"erreur\":[\"message\":\"non authorisé sur cet API\"]}" ;
            response.send(Http::Code::Unauthorized, err_msg, MIME(Application, Json)) ;
            return ;
        }
    }

    // Les routes DELETE
    void RequestHandler::deletePerson(const Rest::Request &request, Http::ResponseWriter response)
    {
        /* Vérifions le paramettre */
        long id ;
        try
        {
            id = request.param(":id").as<int>() ;
        }catch(const std::exception &e)
        {
            LOG_ERROR << e.what() ;
            response.send(Http::Code::Not_Acceptable, e.what(), Http::Mime::MediaType::fromString("text/plain")) ;
            return ;
        }
        // Pas d'erreur on continue
        bool flag = true ;
        {
            try
            {
                /* voyons voir si la personne est un client */
                PersonAPI::getInstance()->erase<Customer>(id) ;
            }catch(const NotErasable &ne)
            {
                flag = false ;
            }
        }
        // Il n'y a pas de client avec cette ID, on essaie
        // avec un Employee.
        if(!flag)
        {
            try
            {
                /* voyons voir si la personne est un client */
                PersonAPI::getInstance()->erase<Employee>(id) ;
            }catch(const NotErasable &ne)
            {
                LOG_ERROR << ne.what() ;
                response.send(Http::Code::Not_Found, ne.what(), MIME(Text, Plain)) ;
                return ;
            }
        }
        // peut importe qu'il s'agissent d'un client ou d'un employee
        response.send(Http::Code::Ok) ;
    }

    void RequestHandler::deleteAccount(const Rest::Request &request, Http::ResponseWriter response)
    {
        /* Vérifions le paramettre */
        long id ;
        try
        {
            id = request.param(":id").as<int>() ;
        }catch(const std::exception &e)
        {
            LOG_ERROR << e.what() ;
            response.send(Http::Code::Not_Acceptable, e.what(), Http::Mime::MediaType::fromString("text/plain")) ;
            return ;
        }
        // Pas d'erreur on continue
        bool flag = true ;
        {
            try
            {
                /* voyons voir si le compte est courant ou pas */
                PersonAPI::getInstance()->erase<CurrentAccount>(id) ;
            }catch(const NotErasable &ne)
            {
                flag = false ;
            }
        }
        // Il n'y a pas de compte courant avec cette ID, on essaie
        // avec un compte d'épargne.
        if(!flag)
        {
            try
            {
                /* voyons voir si le compte est d'épargne */
                PersonAPI::getInstance()->erase<SavingsAccount>(id) ;
            }catch(const NotErasable &ne)
            {
                LOG_ERROR << ne.what() ;
                response.send(Http::Code::Not_Found, ne.what(), MIME(Text, Plain)) ;
                return ;
            }
        }
        // peut importe qu'il s'agissent d'un compte courant ou d'épargne
        response.send(Http::Code::Ok) ;
    }

    void RequestHandler::deleteOperation(const Rest::Request &request, Http::ResponseWriter response)
    {
        /* Vérifions le paramettre */
        long id ;
        try
        {
            id = request.param(":id").as<int>() ;
        }catch(const std::exception &e)
        {
            LOG_ERROR << e.what() ;
            response.send(Http::Code::Not_Acceptable, e.what(), Http::Mime::MediaType::fromString("text/plain")) ;
            return ;
        }
        // Pas d'erreur on continue
        bool flag = true ;
        {
            try
            {
                /* voyons voir si l'opération est un virement ou pas' */
                PersonAPI::getInstance()->erase<Virement>(id) ;
            }catch(const NotErasable &ne)
            {
                flag = false ;
            }
        }
        // Il n'y a pas de virement avec cette ID, on essaie
        // avec une opération simple.
        if(!flag)
        {
            try
            {
                /* voyons voir si l'opération est une opération simple */
                PersonAPI::getInstance()->erase<Employee>(id) ;
            }catch(const NotErasable &ne)
            {
                LOG_ERROR << ne.what() ;
                response.send(Http::Code::Not_Found, ne.what(), MIME(Text, Plain)) ;
                return ;
            }
        }
        response.send(Http::Code::Ok) ;
    }

    // Les routes POST
    // /account/add
    void RequestHandler::addAccount(const Rest::Request &request, Http::ResponseWriter response)
    {
    	try
        {
            std::string body(request.body()) ;
            const char *body_cstr = body.c_str() ;
            // Vérification json
            if(!json_is_valid(fromFileToString("resources/json schema/account.schema.json"), body))
            {
                response.send(Http::Code::Bad_Request) ;
                return ;
            }
            rapidjson::Document doc; doc.Parse(body_cstr) ;
            // Vérification du token
            std::shared_ptr<Session> p_user_session = SessionAPI::getInstance()->findByToken<Session>(
                    std::string(doc["token"].GetString())
            );
            if(p_user_session->getEnd() < (ulong) std::time(nullptr))
            {
                std::string err_msg = "{\"erreur\":[\"message\":\"session expirée\"]}" ;
                response.send(Http::Code::Unauthorized, err_msg, MIME(Application, Json)) ;
                return ;
            }
            /* Récupération des Acteurs autour du compte*/
            // L'employée créateur
            std::shared_ptr<Employee> p_employee = PersonAPI::getInstance()
                    ->findById<Employee>(p_user_session->getPerson()->getId()) ;

            // Le client propriétaire
            std::shared_ptr<Customer> p_customer = PersonAPI::getInstance()
                    ->findById<Customer>(doc["customer"] .GetInt()) ;

            // construction de l'objet Account
            long account_id ;
            Account account(0, p_customer, p_employee,
                            doc["balance"].GetDouble(),
                            std::string(doc["creationDate"].GetString())) ;
            if(std::strcmp("savings account", doc["type"].GetString()) == 0)
            {
                LOG_INFO << "Création d'un d'épargne courant en cours..." ;
                // Insertion du compte d'épargne
                SavingsAccount sa(account);
                sa.setRate(doc["extra"].GetDouble());
                account_id = AccountAPI::getInstance()->insert<SavingsAccount>(sa) ;
                sa.setId(account_id) ;
                p_customer->push_back(sa) ;
                p_employee->addAccount(sa) ;
            }
            else
            {
                LOG_INFO << "Création d'un compte courant en cours..." ;
                // Insertion du compte courant
                CurrentAccount ca(account);
                ca.setOverdraft(doc["extra"].GetDouble());
                account_id = AccountAPI::getInstance()->insert<CurrentAccount>(ca) ;
                ca.setId(account_id) ;
                p_customer->push_back(ca) ;
                p_employee->addAccount(ca) ;
            }
            // Mise à jour du client et de l'employé
            PersonAPI::getInstance()->update<Customer>(*p_customer) ;
            PersonAPI::getInstance()->update<Employee>(*p_employee) ;
        }
        catch(const NotFound &nf)
        {
            LOG_WARNING << "Tentative frauduleuse de connexion !" ;
            std::string err_msg = "{\"erreur\":[\"message\":\"non authorisé sur cet API\"]}" ;
            response.send(Http::Code::Unauthorized, err_msg, MIME(Application, Json)) ;
            return ;
        }
        catch(const FileStreamError &fsr)
        {
            LOG_WARNING << fsr.what() ;
            response.send(Http::Code::Internal_Server_Error) ;
            return ;
        }
        catch(const std::exception &e)
        {
            LOG_WARNING << e.what() ;
            response.send(Http::Code::Internal_Server_Error) ;
            return ;
        }
        LOG_INFO << "Compte crée !" ;
        response.send(Http::Code::Ok) ;
    }

    // /operation/add
    void RequestHandler::addOperation(const Rest::Request &request, Http::ResponseWriter response)
    {
        try
        {
            std::string body(request.body()) ;
            const char *body_cstr = body.c_str() ;
            // Vérification json
            if(!json_is_valid(fromFileToString("resources/json schema/operation.schema.json"), body))
            {
                response.send(Http::Code::Bad_Request) ;
                return ;
            }
            // Deserialization json
            rapidjson::Document doc; doc.Parse(body_cstr) ;
            // Vérification du token
            std::shared_ptr<Session> p_user_session = SessionAPI::getInstance()->findByToken<Session>(
                    std::string(doc["token"].GetString())
            );
            if(p_user_session->getEnd() < (ulong) std::time(nullptr))
            {
                std::string err_msg = "{\"erreur\":[\"message\":\"session expirée\"]}" ;
                response.send(Http::Code::Unauthorized, err_msg, MIME(Application, Json)) ;
                return ;
            }
            /* Récupération des Acteurs autour de la transaction*/
            // L'employée créateur
            std::shared_ptr<Employee> p_employee = PersonAPI::getInstance()
                    ->findById<Employee>(p_user_session->getPerson()->getId()) ;

            // Le compte à modifier
            std::shared_ptr<Account> p_account = AccountAPI::getInstance()
                    ->findById<Account>(doc["account"].GetInt()) ;
            if(std::strcmp(doc["type"].GetString(), "retrait") == 0)
            {
                if(p_account->getBalance() < doc["balance"].GetDouble())
                {
                    response.send(Http::Code::Ok, "{\"message\":\"montant insufisant pour un retrait\"}", MIME(Application, Json)) ;
                    return ;
                }
                LOG_INFO << "Retrait en cours..." ;
                p_account->setBalance(p_account->getBalance()-doc["balance"].GetDouble()) ;
            }
            else
            {
                LOG_INFO << "Dépôt en cours..." ;
                p_account->setBalance(p_account->getBalance()+doc["balance"].GetDouble()) ;
            }

            // construction de l'objet operation
            long operation_id ;
            Operation t_operation(BaseOperation(0L, p_account, p_employee, doc["date"].GetString(), doc["balance"].GetDouble()),
                        (std::strcmp(doc["type"].GetString(), "retrait") == 0)? TypeOperation::RETRAIT:TypeOperation::DEPOT) ;
            operation_id = OperationAPI::getInstance()->insert<Operation>(t_operation) ;
            t_operation.setId(operation_id) ;
            // Mise à jour de l'employé et du compte
            p_account->addOperation(t_operation) ;
            p_employee->addOperation(t_operation) ;
            PersonAPI::getInstance()->update<Employee>(*p_employee) ;
            AccountAPI::getInstance()->update<Account>(*p_account) ;
        }
        catch(const NotFound &nf)
        {
            LOG_WARNING << "Tentative frauduleuse de connexion !" ;
            std::string err_msg = "{\"erreur\":[\"message\":\"non authorisé sur cet API\"]}" ;
            response.send(Http::Code::Unauthorized, err_msg, MIME(Application, Json)) ;
            return ;
        }
        catch(const FileStreamError &fsr)
        {
            LOG_WARNING << fsr.what() ;
            response.send(Http::Code::Internal_Server_Error) ;
            return ;
        }
        catch(const std::exception &e)
        {
            LOG_WARNING << e.what() ;
            response.send(Http::Code::Internal_Server_Error) ;
            return ;
        }
        LOG_INFO << "Transaction éffectuée !" ;
        response.send(Http::Code::Ok) ;
    }

    // /authentification
    void RequestHandler::authentification(const Rest::Request &request, Http::ResponseWriter response)
    {
        std::shared_ptr<Session> session ;
        std::string err_msg = "{\"erreur\":[\"message\":\"non authorisé sur cet API\"]}" ;

        try
        {
            if(!Util::json_is_valid(fromFileToString("resources/json schema/signin.schema.json"), request.body()))
            {
                response.send(Http::Code::Bad_Request) ;
                return ;
            }
            rapidjson::Document doc ; doc.Parse(request.body().c_str()) ;
            // Récupérons la person avec les credentials
            std::shared_ptr<Person> person = PersonAPI::getInstance()
                                                ->findByCredentials<Person>(
                                                    std::string(doc["email"].GetString()),
                                                    std::string(doc["passwd"].GetString())) ;

            if(person->getPasswd() !=  Util::hashSha512(std::string(doc["passwd"].GetString())))
            {
              response.send(Http::Code::Unauthorized, err_msg, MIME(Application, Json)) ;
              return ;
            }

            Session *session = dynamic_cast<Session*>(person->getToken()) ;
            if(session == nullptr)
            {
              LOG_WARNING << "session_ptr: " << (session==nullptr) ;
              response.send(Http::Code::Internal_Server_Error) ;
              return ;
            }
            // On vérifie la validité de la session grâce au timestamp courant
            ulong current_time = std::time(nullptr) ;
            if(session->getEnd() < current_time)
            {
                err_msg = "{\"erreur\":[\"message\":\"session expirée\"]}" ;
                response.send(Http::Code::Unauthorized, err_msg, MIME(Application, Json)) ;
                return ;
            }
            // Envoie du jeton
            std::string person_json = Util::PersonConverter().entityToJson(person) ;
            *(person_json.begin()) = '\n';
            std::string msg = "{\"token\":\""+session->getToken()+"\"}" ;
            msg.pop_back() ; msg += ","+person_json ;
            response.send(Http::Code::Ok, msg, MIME(Application, Json)) ;
        }
        catch(const NotFound &nf)
        {
            LOG_WARNING << nf.what() ;
            response.send(Http::Code::Unauthorized, err_msg, MIME(Application, Json)) ;
            return ;
        }
    }

    // /subscription/:token
    void RequestHandler::subscription(const Rest::Request &request, Http::ResponseWriter response)
    {
        try
        {
            std::string token = request.param(":token").as<std::string>() ;
            // Vérification JSON
            if(!json_is_valid(fromFileToString("resources/json schema/signup.schema.json"), request.body()))
            {
                LOG_WARNING << request.body() ;
                response.send(Http::Code::Bad_Request) ;
                return ;
            }
            // Vérification de session du requester
            std::shared_ptr<Session> p_userSession = SessionAPI::getInstance()->findByToken<Session>(token) ;
            // Garde fou pour empêcher les utilisateurs de type client
            PersonAPI::getInstance()->findById<Employee>(p_userSession->getPerson()->getId()) ;
            if(p_userSession->getEnd() < (ulong) std::time(nullptr))
            {
                std::string err_msg = "{\"erreur\":[\"message\":\"session expirée\"]}" ;
                response.send(Http::Code::Unauthorized, err_msg, MIME(Application, Json)) ;
                return ;
            }
            // Parse JSON
            rapidjson::Document doc ; doc.Parse(request.body().c_str()) ;
            // Création de la session
            Session t_new_user_session ;
            long id_user, id_session ;
            Person p_person(0,std::string(doc["name"].GetString()),
                            std::string(doc["surname"].GetString()),
                            std::string(doc["email"].GetString()),
                            hashArgon2(std::string(doc["passwd"].GetString()))) ;
            if(!std::strcmp(doc["type"].GetString(), "customer"))
            {
                Customer customer(p_person) ;
                t_new_user_session = initSession(std::make_shared<Customer>(customer)) ;
                customer.setToken(t_new_user_session) ;
                // Enregistrement de l'employé et de sa session
                id_user = PersonAPI::getInstance()->insert<Customer>(customer) ;
                id_session = SessionAPI::getInstance()->insert<Session>(t_new_user_session) ;

                t_new_user_session.getPerson()->setId(id_user) ;
                customer.getToken()->setId(id_session) ;

                PersonAPI::getInstance()->update<Session>(t_new_user_session) ;
                SessionAPI::getInstance()->update<Customer>(customer) ;

                LOG_INFO << "Inscription du client en cours..." ;
            }
            else
            {
                Employee employee(p_person) ;
                t_new_user_session = initSession(std::make_shared<Employee>(employee)) ;
                employee.setToken(t_new_user_session) ;
                // Mise à jour du requester
                Employee* to_update = dynamic_cast<Employee*>(p_userSession->getPerson()) ;
                to_update->addSubordinate(employee) ;
                PersonAPI::getInstance()->update<Employee>(*to_update) ; to_update = nullptr ;
                // Enregistrement de l'employé et de sa session
                id_user = PersonAPI::getInstance()->insert<Employee>(employee) ;
                id_session = SessionAPI::getInstance()->insert<Session>(t_new_user_session) ;

                t_new_user_session.getPerson()->setId(id_user) ;
                employee.getToken()->setId(id_session) ;

                PersonAPI::getInstance()->update<Session>(t_new_user_session) ;
                SessionAPI::getInstance()->update<Employee>(employee) ;
                LOG_INFO << "Inscription de l'employé en cours..." ;
            }
            // Envoie d'un email
        }
        catch(const NotFound &nf)
        {
            LOG_WARNING << "Tentative frauduleuse de connexion !" ;
            std::string err_msg = "{\"erreur\":[\"message\":\"non authorisé sur cet API\"]}" ;
            response.send(Http::Code::Unauthorized, err_msg, MIME(Application, Json)) ;
            return ;
        }
        catch(const FileStreamError &fsr)
        {
            LOG_WARNING << fsr.what() ;
            response.send(Http::Code::Internal_Server_Error) ;
            return ;
        }
        catch(const std::exception &e)
        {
            LOG_WARNING << e.what() ;
            response.send(Http::Code::Internal_Server_Error) ;
            return ;
        }
        LOG_INFO << "Utilisateur inscrit !" ;
        response.send(Http::Code::Ok) ;
    }
}
