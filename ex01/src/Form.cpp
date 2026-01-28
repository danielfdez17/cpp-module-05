#include "utils.hpp"
#include "Form.hpp"
#include <iostream>
#include <string>
#include <sstream>

Form::Form() : name(__func__), isSigned(false), signGrade(1), executeGrade(1)
{
}

Form::Form(const Form&copy) : name(copy.name), signGrade(copy.signGrade), executeGrade(copy.executeGrade)
{
	if (this != &copy)
	{
		isSigned = copy.isSigned;
	}
}

Form& Form::operator=(const Form& copy)
{
	if (this != &copy)
	{
		isSigned = copy.isSigned;
	}
	return *this;
}

Form::~Form()
{
}

Form::Form(const std::string name, const unsigned short int signGrade, const unsigned short int executeGrade)
	: name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
	std::cout << INFO << __func__ << " called with name " << name
		<< ", sign grade " << signGrade << ", execute grade " << executeGrade << "\n" RESET;
	if (signGrade < LOWEST_VALUE || executeGrade < LOWEST_VALUE)
		throw Form::GradeTooHighException(signGrade, LOWEST_VALUE);
	if (signGrade > HIGHEST_VALUE || executeGrade > HIGHEST_VALUE)
		throw Form::GradeTooLowException(signGrade, HIGHEST_VALUE);
}

std::string	Form::getName() const { return name; }
bool	Form::getIsSigned() const { return isSigned; }
unsigned short int	Form::getSignGrade() const { return signGrade; }
unsigned short int	Form::getExecuteGrade() const { return executeGrade; }

void	Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > signGrade)
		throw Form::GradeTooLowException("Bureaucrat grade too low to sign the form\n");
	this->isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	return os << MAGENTA << "Form '" << form.getName() << "', is signed: " << (form.getIsSigned() ? "true" : "false")
		<< ", sign grade: " << form.getSignGrade() << ", execute grade: " << form.getExecuteGrade() << "\n" RESET;
}

Form::GradeTooHighException::GradeTooHighException(const char *msg) : message(msg)
{
	std::cout << INFO << "Form::" << __func__ << " called\n" RESET;
}

Form::GradeTooHighException::GradeTooHighException(const int grade, const unsigned short int limit)
{
	std::cout << INFO << "Form::" << __func__ << " called with grade " << grade << " and limit " << limit << "\n" RESET;
	std::stringstream ss1;
	std::stringstream ss2;
	ss1 << grade;
	this->message = "Grade (";
	this->message += ss1.str();
	this->message += ") is higher than the highest value (";
	ss2 << limit;
	this->message += ss2.str();
	this->message += ")\n";
}

Form::GradeTooHighException::~GradeTooHighException() throw() {}

const char *Form::GradeTooHighException::what() const throw()
{
	return this->message.c_str();
}

Form::GradeTooLowException::GradeTooLowException(const char *msg) : message(msg)
{
	std::cout << INFO << "Form::" << __func__ << " called\n" RESET;
}

Form::GradeTooLowException::GradeTooLowException(const int grade, const unsigned short int limit)
{
	std::cout << INFO << "Form::" << __func__ << " called with grade " << grade << " and limit " << limit << "\n" RESET;
	std::stringstream ss1;
	std::stringstream ss2;
	ss1 << grade;
	this->message = "Grade (";
	this->message += ss1.str();;
	this->message += ") is lower than the lowest value (";
	ss2 << limit;
	this->message += ss2.str();
	this->message += ")\n";
}

Form::GradeTooLowException::~GradeTooLowException() throw() {}

const char *Form::GradeTooLowException::what() const throw()
{
	return this->message.c_str();
}
