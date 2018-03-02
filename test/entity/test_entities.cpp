/**
 * \file test_entities.cpp
 * \author fatigba jordy fatigba72@gmail.com
 * \date 26-02-2018
 * \brief Ce fichier va servir à effectuer des CRUD sur la db pour voir si
 *				tout fonctionnne.<br/>
 *				Voici le scénario.<br/>
 *        INSERTION DE PERSONNE
 *				Création de 3 Client{jordy, ablavi et koffi} (Customer)
 *				et de 2 Employé{sam, edem-kouakou} (Employee).
 *				Les Personnes seront enregistrées dans la base de données.
 *				INSERTION DE COMPTE
 *        sam créera 3 comptes pour jordy (2 SavingsAccount et 1 CurrentAccount)
 *        edem-kouakou créera 1 Compte Courant (CurrentAccount) pour ablavi.
 *				INSERTION DE GROUPE
 *				Deux groupes seront créer {groupe1, groupe2}.
 *        sam et edem-kouakou appartiendront chacun aux deux groupes.
 *        INSERTION DES OPÉRATIONS
 *        sam fera un virement d'un compte de jordy vers un compte de ablavi.
 *        edem-kouakou fera une opération sur le compte de ablavi.
 *        SUPRESSION DE COMPTE
 *        Un compte de jordy sera supprimé. Sur ce compte, une opération est déjà faite.
 *
 */

#include "../../src/Entity/Entity.hpp"

#include <odb/database.hxx>
#include <odb/mysql/database.hxx>
#include <odb/transaction.hxx>
#include <odb/session.hxx>
#include <iostream>

using namespace Entity ;

// Lecture d'une personne
std::ostream &operator<<(std::ostream &out, const Person &person)
{
    out << "ID: " << person.getId() << std::endl ;
    out << "Nom: " << person.getName() << std::endl ;
    return out ;
}

// Lecture d'un compte
std::ostream &operator<<(std::ostream &out, const Account &account)
{
    out << "ID: " << account.getId() << std::endl;
    out << "Date de création: " << account.getCreationDate() << std::endl;
    out << "Solde: " << account.getBalance() << std::endl;
    out << "Client proporiétaire: \n" << account.getCustomer() << std::endl;
    out << "Employé créateur: \n" << account.getEmployee() << std::endl;

    return out ;
}

// Lecture d'une opération
std::ostream &operator<<(std::ostream &out, const Operation &operation)
{
    out <<"ID: "<< operation.getId() <<"\n" ;
    out <<"Montant: "<< operation.getMontant() <<"\n" ;
    out <<"Date: "<< operation.getDate() <<"\n" ;
    out <<"Account: "<< operation.getAccountSource() <<"\n" ;
    out <<"Employee: "<< operation.getEmployee() <<"\n" ;
    return out ;
}

// Lecture d'un groupe
std::ostream &operator<<(std::ostream &out, const Group &group)
{
    out << "ID: "<< group.getId()<<"\n" ;
    out << "Nom: "<<group.getName()<<"\n" ;
    return out ;
}

int main(void)
{
    try
    {
        std::unique_ptr<odb::database> p_database = std::make_unique<odb::mysql::database>("jordy", "dalila", "test_cbanking", "172.17.0.2", 3306) ;
        odb::transaction t_transaction (p_database->begin()) ;
        /* Persistence */
        long jordy_id, ablavi_id, sam_id, edem_id ;
        long goupe1_id, groupe2_id ;
        long account1jojo_id, account2jojo_id, account3jojo_id ;
        long account1ablavi_id, account2ablavi_id ;

        {
            //Persistence des Personnes
            // Les groupes
            std::cout<< "Persistences des personnes et des groupes !\n" ;
            Group group1(0, "group1") ;
            Group group2(0, "group2") ;
            // Les employés
            Employee sam(0, "sam") ;
            Employee edem(0, "edem-kouakou") ;
            sam.addGroup(group1) ;
            sam.addGroup(group2) ;
            edem.addGroup(group1) ;
            edem.addGroup(group2) ;
            group1.push_back(sam) ;
            group1.push_back(edem) ;
            group2.push_back(sam) ;
            group2.push_back(edem) ;
            // Les clients
            Customer jordy(0, "jordy") ;
            Customer ablavi(0, "ablavi") ;
            Customer koffi(0, "koffi") ;
            // Persistence
            sam_id = p_database->persist(sam) ;
            edem_id = p_database->persist(edem);
            jordy_id = p_database->persist(jordy);
            p_database->persist(koffi);
            ablavi_id = p_database->persist(ablavi);
            p_database->persist(group1) ;
            p_database->persist(group2) ;
            t_transaction.commit() ;
        }

        // Créations des comptes
        {
            t_transaction.reset(p_database->begin()) ;
            std::cout<< "Création des comptes !\n" ;
            // Lecture des clients
            std::shared_ptr<Customer> jordy(p_database->load<Customer>(jordy_id)) ;
            std::shared_ptr<Customer> ablavi(p_database->load<Customer>(ablavi_id)) ;
            // Lectures des employés
            std::shared_ptr<Employee> sam(p_database->load<Employee>(sam_id)) ;
            std::shared_ptr<Employee> edem(p_database->load<Employee>(edem_id)) ;
            // Création des comptes
            Account base_edem(0, ablavi, edem, 1998.95, "26-02-2018") ;
            Account base_sam(0, jordy, sam, 9064.95, "26-02-2018") ;
            SavingsAccount sa1_jojo(base_sam, 1.5) ;
            CurrentAccount ca1_jojo(base_sam) ;
            CurrentAccount ca2_jojo(base_sam) ;
            CurrentAccount ca1_ablavi(base_edem) ;

            // Appartenance des comptes
            // Les comptes de jordy créer par sam
            jordy->push_back(sa1_jojo) ;
            jordy->push_back(ca1_jojo) ;
            jordy->push_back(ca2_jojo) ;
            sam->addAccount(sa1_jojo) ;
            sam->addAccount(ca1_jojo) ;
            sam->addAccount(ca2_jojo) ;
            // Les comptes créer par edem pour ablavi
            ablavi->push_back(ca1_ablavi) ;
            edem->addAccount(ca1_ablavi) ;
            //* Persistence des comptes
            account1ablavi_id = p_database->persist(ca1_ablavi) ;
            account1jojo_id = p_database->persist(ca1_jojo) ;
            p_database->persist(sa1_jojo) ;
            p_database->persist(ca2_jojo) ;
            // mise à jours des employées
            p_database->update<Employee>(*sam) ;
            p_database->update<Employee>(*edem) ;
            p_database->update<Customer>(*jordy) ;
            p_database->update<Customer>(*ablavi) ;

            std::cout << "Insertion des opérations\n";
            // L'opération de sam, sam fait une opération sur ca1

            Operation sam_operation(TypeOperation::DEPOT) ;
            sam_operation.setId(0) ;
            sam_operation.setAccountSource(ca1_jojo) ;
            sam_operation.setEmployee(*sam) ;
            sam_operation.setDate("28-02-2018") ;
            sam_operation.setMontant(850.95) ;
            // Mise à jour du compte et de l'employé
            ca1_jojo.addOperation(sam_operation) ;
            sam->addOperation(sam_operation) ;
            p_database->persist(sam_operation) ;
            p_database->update<CurrentAccount>(ca1_jojo) ;
            p_database->update<Employee>(*sam) ;

            // L'opération de edem, edem fait une opération sur ca2
            Operation edem_operation(TypeOperation::RETRAIT) ;
            edem_operation.setId(0) ;
            edem_operation.setAccountSource(ca1_ablavi) ;
            edem_operation.setEmployee(*edem) ;
            edem_operation.setDate("28-02-2018") ;
            edem_operation.setMontant(850.95) ;
            // Mise à jour du compte et de l'employé
            ca1_ablavi.addOperation(edem_operation) ;
            edem->addOperation(edem_operation) ;
            p_database->persist(edem_operation) ;
            p_database->update<CurrentAccount>(ca1_ablavi) ;
            p_database->update<Employee>(*edem) ;
            t_transaction.commit() ;
        }

        // Lecture des Personnes
        {
            odb::session s ;
            std::cout<< "Affichage des personnes !\n" ;
            t_transaction.reset(p_database->begin()) ;
            odb::result<Person> t_result(p_database->query<Person>()) ;
            for(auto it(t_result.begin()); it!= t_result.end(); it++)
            {
                std::shared_ptr<Person> p(it.load()) ;
                std::cout << *p ;
            }
            t_transaction.commit() ;
        }
        // Lesture des groupes
        {
            try
            {
                odb::session s ;
                std::cout<< "\nAffichage des groupes !\n" ;
                t_transaction.reset(p_database->begin()) ;
                odb::result<Group> t_result(p_database->query<Group>()) ;
                for(odb::result<Group>::iterator it(t_result.begin()); it!= t_result.end(); it++)
                {
                    std::shared_ptr<Group> g(it.load()) ;
                    std::cout << *g ;
                }
                t_transaction.commit() ;
            }
            catch(const std::exception &e)
            {
                puts(e.what()) ;
            }
        }
        // Lecture des comptes
        {
            odb::session s ;
            std::cout<< "\nAffichage des comptes !\n" ;
            t_transaction.reset(p_database->begin()) ;
            odb::result<CurrentAccount> t_result(p_database->query<CurrentAccount>()) ;
            for(odb::result<CurrentAccount>::iterator it(t_result.begin()); it!= t_result.end(); it++)
            {
                std::shared_ptr<CurrentAccount> a(it.load()) ;
                std::cout << *a ;
            }
            t_transaction.commit() ;
        }

        // Lectures des Opération et suppression d'un compte avec opération et proproétaire
        {
            odb::session s ;
            std::cout<< "Affichage des opérations !\n" ;
            t_transaction.reset(p_database->begin()) ;
            odb::result<Operation> t_result(p_database->query<Operation>()) ;
            for(auto it = t_result.begin(); it != t_result.end(); it++)
            {
                std::shared_ptr<Operation> op(it.load()) ;
                std::cout << *op ;
            }
            std::cout<< "Suppression de ID: " << account1jojo_id << " compte de jordy !\n" ;
            p_database->erase<CurrentAccount>(account1jojo_id) ;
            std::cout<< "Suppression de jojo" ;
            p_database->erase<Customer>(jordy_id) ;
            t_transaction.commit() ;
        }
    }
    catch(const std::exception &e)
    {
        puts(e.what()) ;
        exit(-1) ;
    }

    return 0 ;
}
