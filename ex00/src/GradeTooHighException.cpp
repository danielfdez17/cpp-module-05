#include "GradeTooHighException.hpp"
#include "colors.hpp"
#include <string>
#include <sstream>

GradeTooHighException::GradeTooHighException(const int grade, const unsigned short int limit)
{
	std::stringstream ss1;
	std::stringstream ss2;
	ss1 << grade;
	message = "Grade (";
	message += ss1.str();;
	message += ") is higher than the lowest value (";
	ss2 << limit;
	message += ss2.str();
	message += ")\n";
}

GradeTooHighException::~GradeTooHighException() throw() {}

const char *GradeTooHighException::what() const throw()
{
	return message.c_str();
}
