#include <plog/Log.h>
#include "../../include/Core/DBConnection.hpp"
#include <plog/Appenders/ColorConsoleAppender.h>

int main()
{
	static plog::ColorConsoleAppender<plog::TxtFormatter> consoleAppender;
	plog::init(plog::verbose, &consoleAppender);
  	DBConnection::getInstance() ;
	return 0 ;
}
