#include "utils.hpp"
#include "Form.hpp"
#include <iostream>

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
	std::cout << YELLOW << __func__ << " called with name " << name
		<< ", sign grade " << signGrade << ", execute grade " << executeGrade << "\n" RESET;
	if (signGrade < LOWEST_VALUE || executeGrade < LOWEST_VALUE)
		throw Bureaucrat::GradeTooHighException(signGrade, LOWEST_VALUE);
	if (signGrade > HIGHEST_VALUE || executeGrade > HIGHEST_VALUE)
		throw Bureaucrat::GradeTooLowException(signGrade, HIGHEST_VALUE);
}

std::string	Form::getName() const { return name; }
bool	Form::getIsSigned() const { return isSigned; }
unsigned short int	Form::getSignGrade() const { return signGrade; }
unsigned short int	Form::getExecuteGrade() const { return executeGrade; }

void	Form::beSigned(Bureaucrat bureaucrat)
{
	if (bureaucrat.getGrade() > signGrade)
		throw Bureaucrat::GradeTooLowException("Bureaucrat grade too low to sign the form\n");
	this->isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	return os << MAGENTA << "Form " << form.getName() << ", is signed: " << (form.getIsSigned() ? "true" : "false")
		<< ", sign grade: " << form.getSignGrade() << ", execute grade: " << form.getExecuteGrade() << "\n" RESET;
}
