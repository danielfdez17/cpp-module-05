#include "GradeTooHighException.hpp"
#include "colors.hpp"
#include <string>

GradeTooHighException::GradeTooHighException(const char* msg) : message(msg) {}

GradeTooHighException::~GradeTooHighException() throw() {}

const char *GradeTooHighException::what() const throw()
{
	return message.c_str();
}
