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
	GradeTooLowException(const int grade, const unsigned short int limit);
	virtual ~GradeTooLowException() throw();
	const char *what() const throw();
};


#endif // __GRADETOOLOWEXCEPTION__