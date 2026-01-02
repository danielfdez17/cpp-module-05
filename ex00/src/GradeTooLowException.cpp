#include "GradeTooLowException.hpp"
#include "colors.hpp"
#include <string>

GradeTooLowException::GradeTooLowException(const char* msg) : message(msg) {}

GradeTooLowException::~GradeTooLowException() {}

const char *GradeTooLowException::what()
{
	return message.c_str();
	return "Grade is lower than the maximum value\n";
}
