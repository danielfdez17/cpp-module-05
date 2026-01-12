#include "GradeTooLowException.hpp"
#include "colors.hpp"
#include <string>
#include <sstream>

GradeTooLowException::GradeTooLowException(const char *msg) : message(msg) {}

GradeTooLowException::GradeTooLowException(const int grade, const unsigned short int limit)
{
	std::stringstream ss1;
	std::stringstream ss2;
	ss1 << grade;
	message = "Grade (";
	message += ss1.str();;
	message += ") is lower than the highest value (";
	ss2 << limit;
	message += ss2.str();
	message += ")\n";
}

GradeTooLowException::~GradeTooLowException() throw() {}

const char *GradeTooLowException::what() const throw()
{
	return message.c_str();
}
