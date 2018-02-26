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
 *				sam créera ensuite 1 Compte Courant (CurrentAccount) pour ablavi.
 *        edem-kouakou créera 1 Compte Courant (CurrentAccount) pour ablavi.
 *				INSERTION DE GROUPE
 *				Deux groupes seront créer {groupe1, groupe2}.
 *        sam et edem-kouakou appartiendront chacun aux deux groupes.
 *				LECTURE DES DONNÉES ENREGISTRÉES
 *
 */

#include "../src/Entity/Entity.hpp"

#include <odb/database.hxx>
#include <odb/mysql/database.hxx>
#include <odb/transaction.hxx>

using namespace std ;
using namespace Entity ;

int main(void)
{
	try
	{
		unique_ptr<odb::database> db = make_unique<odb::mysql::database("jordy", "dalila", "test_cbanking", "172.17.0.2", 3306) ;
 	}catch(const odb::exception &e)
 	{
 		cerr << e.what() ;
 		exit(-1) ;
 	}
 	return 0 ;
 }
