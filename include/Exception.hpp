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

/**
 * @class OutOfMemory
 * @brief Classe d'exception en cas de mémoire insuffisante.
 */
class OutOfMemory: public BaseException
{
public:
    OutOfMemory(std::string msg_) ;
};

/**
 * @class OutOfMemory
 * @brief Classe d'exception en cas d'erreur d'allocation de mémoire.
 */
class BadMalloc: public BaseException
{
public:
    BadMalloc(std::string msg_) ;
};


/**
 * @class FileStreamError
 * @brief Classe d'exception relative au fichier normaux.
 */
class FileStreamError: public BaseException
{
public:
    FileStreamError(std::string msg_) ;
};

/**
 * @class SessionExprired
 * @brief Exception relative à l'expiration d'une session.
 */
class SessionExprired: public BaseException
{
public:
    SessionExprired(std::string _msg) ;
};

/**
 * @classe CurlException
 * @brief Classe pour les exceptions liés à curl.
 */
class CurlException: public BaseException
{
public:
    CurlException(std::string _msg) ;
};

#endif // EXCEPTION_HPP_INCLUDED
