#include <iostream>
#include <plog/Log.h>
#include <plog/Appenders/ColorConsoleAppender.h>

// Mes includes
#include "../include/Rest/Rest.hpp"
#include "../include/Core/DBConnection.hpp"

int main()
{
	static plog::ColorConsoleAppender<plog::TxtFormatter> consoleAppender;
	plog::init(plog::verbose, &consoleAppender);
    // Initialisation de la connexion à la db
    DBConnection::getInstance() ;
	RestAPI::RestServer r ;
	r.start() ;
	r.stop() ;
	std::cout << "Hello world !\n" ;
	return 0 ;
}