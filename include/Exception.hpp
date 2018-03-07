#ifndef EXCEPTION_HPP_INCLUDED
#define EXCEPTION_HPP_INCLUDED

#include <exception>
#include <string>

class BaseException: public std::exception
{
protected:
  std::string msg ;
public:
	BaseException(std::string msg_) noexcept ;
	const char *what() const noexcept ;
};

class IllegalArgument: public BaseException
{
public:
	IllegalArgument(std::string msg_) ;
};

class NotFound: public BaseException
{
public:
	NotFound(std::string msg_) ;
};

class NotErasable: public BaseException
{
public:
	NotErasable(std::string msg_) ;
};

class NotUpdatable: public BaseException
{
public:
	NotUpdatable(std::string msg_) ;
};

#endif // EXCEPTION_HPP_INCLUDED