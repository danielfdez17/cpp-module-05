#include "GradeTooLowException.hpp"
#include "colors.hpp"
#include <string>

GradeTooLowException::GradeTooLowException(const char* msg) : message(msg) {}

GradeTooLowException::~GradeTooLowException() throw() {}

const char *GradeTooLowException::what() const throw()
{
	return message.c_str();
}
