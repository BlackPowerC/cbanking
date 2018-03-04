/**
 * \file test_personapi.cpp
 * \author fatigba jordy fatigba72@gmail.com
 * \date 26-02-2018
 * \brief Ce fichier va servir à effectuer un test de la
 *        classe PersonAPI.
 *        Toute les méthodes seront appelées.
 */

#include "../../include/Exception.hpp"
#include "../../include/Entity/Entity.hpp"
#include "../../include/API/PersonAPI.hpp"
#include <iostream>
#include <exception>


using namespace Entity ;
using namespace API ;

// Lecture d'une personne
std::ostream &operator<<(std::ostream &out, const Person &person)
{
    out << "ID: " << person.getId() << std::endl ;
    out << "Nom: " << person.getName() << std::endl ;
    return out ;
}

#include <plog/Log.h>
#include <plog/Appenders/ColorConsoleAppender.h>

int main()
{
    static plog::ColorConsoleAppender<plog::TxtFormatter> consoleAppender;
    plog::init(plog::verbose, &consoleAppender);

    PersonAPI *p_papi = PersonAPI::getInstance() ;

    /* Persitence de 2 Customer et d'un Employee */
    {
        // Lecture de tout les customers
        try
        {
            Customer dalida(0, "dalida") ;
            Customer thierrno(0, "thierrno") ;
            Customer nabine(0, "nabine") ;
            p_papi->insert<Customer>(dalida) ;
            p_papi->insert<Customer>(nabine) ;
            p_papi->insert<Customer>(thierrno) ;

            // Affiche de toutes les personnes
            {
                for(auto &c: p_papi->findAll<Customer>())
                {
                    std::cout << *c ;
                }
            }
            // Toutes les personnes dont les nom commence par j
            {
                try
                {
                    for(auto &c: p_papi->findByName<Customer>("j"))
                    {
                        std::cout << *c ;
                    }
                }
                catch(const BaseException &ba)
                {
                    LOG_ERROR << ba.what() ;
                }
            }
            // La personnes avec l'id 5 et l'id 200
            {
                try
                {
                    std::cout << *p_papi->findById<Person>(5) ;
                    std::cout << *p_papi->findById<Person>(200) ;
                }
                catch(const BaseException &ba)
                {
                    LOG_ERROR << ba.what() ;
                }
            }
        }
        catch(const BaseException &ba)
        {
            LOG_ERROR << ba.what() ;
        }
        catch(const std::exception &e)
        {
            LOG_ERROR << e.what() ;
        }
    }

    return 0 ;
}
