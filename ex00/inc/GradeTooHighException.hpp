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
	GradeTooHighException(const char* msg);
	~GradeTooHighException();
	const char *what();
};


#endif // __GRADETOOHIGHEXCEPTION__