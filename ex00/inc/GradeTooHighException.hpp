#pragma once
#ifndef __GRADETOOHIGHEXCEPTION__
#define __GRADETOOHIGHEXCEPTION__

#include <exception>
#include <string>

class GradeTooHighException : public std::exception
{
private:
	std::string message;
public:
	GradeTooHighException(const char *msg);
	GradeTooHighException(const int grade, const unsigned short int limit);
	virtual ~GradeTooHighException() throw();
	const char *what() const throw();
};


#endif // __GRADETOOHIGHEXCEPTION__