#include "../include/Exception.hpp"

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

// OutOfMemory
OutOfMemory::OutOfMemory(std::string msg_): BaseException(msg_)
{

}

// BadMalloc
BadMalloc::BadMalloc(std::string msg_): BaseException(msg_)
{

}

// FileStreamError
FileStreamError::FileStreamError(std::string msg_): BaseException(msg_)
{

}

// FileStreamError
SessionExprired::SessionExprired(std::string msg_): BaseException(msg_)
{

}

// CurlException
CurlException::CurlException(std::string _msg): BaseException(_msg)
{

}