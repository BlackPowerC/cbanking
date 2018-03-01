#include "Exception.hpp"

// BaseException
BaseException::BaseException(std::string msg_): msg(msg_)
{

}

const char *BaseException::what() const
{
	return this->msg.c_str() ;
}

// IllegalArgument
IllegalArgument::IllegalArgument(std::string msg_): msg(msg_)
{

}

// NotFount
NotFount::NotFount(std::string msg_): msg(msg_)
{

}

// NotErasable
NotErasable::NotErasable(std::string msg_): msg(msg_)
{

}

// NotUpdatable
NotUpdatable::NotUpdatable(std::string msg_): msg(msg_)
{

}