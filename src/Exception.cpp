#include "Exception.hpp"

// BaseException
BaseException::BaseException(std::string msg_) noexcept : msg(msg_)
{

}

const char *BaseException::what() const noexcept
{
	return this->msg.c_str() ;
}

// IllegalArgument
IllegalArgument::IllegalArgument(std::string msg_): BaseException(msg_)
{

}

// NotFount
NotFound::NotFound(std::string msg_): BaseException(msg_)
{

}

// NotErasable
NotErasable::NotErasable(std::string msg_): BaseException(msg_)
{

}

// NotUpdatable
NotUpdatable::NotUpdatable(std::string msg_): BaseException(msg_)
{

}
