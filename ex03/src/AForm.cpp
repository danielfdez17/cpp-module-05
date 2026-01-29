#include "AForm.hpp"
#include <iostream>
#include <string>
#include <sstream>

AForm::AForm() : name(__func__), isSigned(false), signGrade(1), executeGrade(1), type(__func__)
{
}

AForm::AForm(const AForm&copy) : name(copy.name), signGrade(copy.signGrade), executeGrade(copy.executeGrade), type(copy.type)
{
	if (this != &copy)
	{
		this->isSigned = copy.isSigned;
		this->type = copy.type;
	}
}

AForm& AForm::operator=(const AForm& copy)
{
	if (this != &copy)
	{
		this->isSigned = copy.isSigned;
		this->type = copy.type;
	}
	return *this;
}

AForm::~AForm()
{
}

AForm::AForm(const std::string name, const unsigned short int signGrade, const unsigned short int executeGrade)
	: name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade), type(__func__)
{
	std::cout << YELLOW << __func__ << " called with name " << name
		<< ", sign grade " << signGrade << ", execute grade " << executeGrade << "\n" RESET;
	if (signGrade < LOWEST_VALUE || executeGrade < LOWEST_VALUE)
		throw Bureaucrat::GradeTooHighException("AForm grade is lower than the highest value\n");
	if (signGrade > HIGHEST_VALUE || executeGrade > HIGHEST_VALUE)
		throw Bureaucrat::GradeTooLowException("AForm grade is higher than the lowest value\n");
}

void	AForm::beSigned(Bureaucrat bureaucrat)
{
	if (bureaucrat.getGrade() > signGrade)
		throw AForm::GradeTooLowException("Bureaucrat grade too low to sign the form\n");
	if (this->isSigned)
		std::cout << YELLOW << this->type << " '" << name << "' has already been signed!!!\n" RESET;
	this->isSigned = true;
	std::cout << GREEN << this->type << " '" << name << "' has been signed successfully\n" RESET;
}

std::string			AForm::getName() const { return name; }
bool				AForm::getIsSigned() const { return isSigned; }
unsigned short int	AForm::getSignGrade() const { return signGrade; }
unsigned short int	AForm::getExecuteGrade() const { return executeGrade; }

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	return os << "AForm " << form.getName() << ", is signed: " << (form.getIsSigned() ? "true" : "false")
		<< ", sign grade: " << form.getSignGrade() << ", execute grade: " << form.getExecuteGrade() << "\n";
}

AForm::GradeTooHighException::GradeTooHighException(const char *msg) : message(msg)
{
	std::cout << INFO << "Form::" << __func__ << " called\n" RESET;
}

AForm::GradeTooHighException::GradeTooHighException(const int grade, const unsigned short int limit)
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

AForm::GradeTooHighException::~GradeTooHighException() throw() {}

const char *AForm::GradeTooHighException::what() const throw()
{
	return this->message.c_str();
}

AForm::GradeTooLowException::GradeTooLowException(const char *msg) : message(msg)
{
	std::cout << INFO << "Form::" << __func__ << " called\n" RESET;
}

AForm::GradeTooLowException::GradeTooLowException(const int grade, const unsigned short int limit)
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

AForm::GradeTooLowException::~GradeTooLowException() throw() {}

const char *AForm::GradeTooLowException::what() const throw()
{
	return this->message.c_str();
}

