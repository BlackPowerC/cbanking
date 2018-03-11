#include <iostream>
#include "../include/Rest/Rest.hpp"
#include <plog/Log.h>
#include <plog/Appenders/ColorConsoleAppender.h>

int main()
{
	static plog::ColorConsoleAppender<plog::TxtFormatter> consoleAppender;
	plog::init(plog::verbose, &consoleAppender);
	RestAPI::RestServer r ;
	r.start() ;
	r.stop() ;
	std::cout << "Hello world !\n" ;
	return 0 ;
}