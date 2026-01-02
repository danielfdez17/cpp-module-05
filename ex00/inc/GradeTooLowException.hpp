#pragma once
#ifndef __GRADETOOLOWEXCEPTION__
#define __GRADETOOLOWEXCEPTION__

#include <exception>
#include <string>

class GradeTooLowException : public std::exception
{
private:
	std::string message;
public:
	GradeTooLowException(const char* msg);
	~GradeTooLowException();
	const char *what();
};


#endif // __GRADETOOLOWEXCEPTION__