#include <iostream>
#include <plog/Log.h>
#include <plog/Appenders/ColorConsoleAppender.h>

// Mes includes
#include "../include/Rest/Rest.hpp"
#include "../include/Core/DBConnection.hpp"
#include <cstdlib>

int main(char *argv[], int argc)
{
	static plog::ColorConsoleAppender<plog::TxtFormatter> consoleAppender;
	plog::init(plog::verbose, &consoleAppender);
  // Initialisation de la connexion à la db
  DBConnection::getInstance() ;
	if(argc >= 3)
	{
		RestAPI::RestServer r(argv[1], std::atoi(argc[2])) ;
	}
	else
	{
		RestAPI::RestServer r ;
	}
	r.start() ;
	r.stop() ;
	std::cout << "Hello world !\n" ;
	return 0 ;
}
