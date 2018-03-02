#include "PersonAPI.hpp"

namespace API
{

// PersonAPI
PersonAPI* PersonAPI::p_singleton = nullptr ;

PersonAPI::PersonAPI()
{

}

PersonAPI* PersonAPI::getInstance()
{
	if(p_singleton == nullptr)
	{
		p_singleton = new PersonAPI ;
	}
	return p_singleton ;
}

// CustomerAPI
CustomerAPI* CustomerAPI::p_singleton = nullptr ;

CustomerAPI::CustomerAPI()
{

}

CustomerAPI* CustomerAPI::getInstance()
{
	if(p_singleton == nullptr)
	{
		p_singleton = new CustomerAPI ;
	}
	return p_singleton ;
}

// EmployeeAPI
EmployeeAPI* EmployeeAPI::p_singleton = nullptr ;

EmployeeAPI::EmployeeAPI()
{

}

EmployeeAPI* EmployeeAPI::getInstance()
{
	if(p_singleton == nullptr)
	{
		p_singleton = new EmployeeAPI ;
	}
	return p_singleton ;
}

}
