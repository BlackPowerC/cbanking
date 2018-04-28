#include <iostream>
#include <plog/Log.h>
#include <plog/Appenders/ColorConsoleAppender.h>

// Mes includes
#include "../include/Rest/Rest.hpp"
#include "../include/Core/DBConnection.hpp"
#include <cstdlib>

int main(int argc, char **argv)
{
	static plog::ColorConsoleAppender<plog::TxtFormatter> consoleAppender;
	plog::init(plog::verbose, &consoleAppender);
  	// Initialisation de la connexion à la db
 	DBConnection::getInstance() ;
	if(argc >= 2)
	{
        std::cout << argc ;
		RestAPI::RestServer r(getenv("HOSTNAME"), std::atoi(argv[1])) ;
        r.start() ;
        r.stop() ;
	}
	else
	{
        RestAPI::RestServer r ;
        r.start() ;
        r.stop() ;
	}
	std::cout << "Hello world !\n" ;
	return 0 ;
}
