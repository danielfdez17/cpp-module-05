#include "GradeTooHighException.hpp"
#include "colors.hpp"
#include <string>

GradeTooHighException::GradeTooHighException(const char* msg) : message(msg) {}

GradeTooHighException::~GradeTooHighException() {}

const char *GradeTooHighException::what()
{
	return message.c_str();
	return "Grade is greater than the maximum value\n";
}
