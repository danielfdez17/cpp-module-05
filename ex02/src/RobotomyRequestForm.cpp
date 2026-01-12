#include "RobotomyRequestForm.hpp"
#include <cstdlib>

const unsigned short int REQUIRED_SIGN = 72;
const unsigned short int REQUIRED_EXEC = 45;

RobotomyRequestForm::RobotomyRequestForm() : AForm(), isSigned(false), signGrade(REQUIRED_SIGN), executeGrade(REQUIRED_EXEC)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm&copy) : AForm(copy), isSigned(false), signGrade(REQUIRED_SIGN), executeGrade(REQUIRED_EXEC)
{
	if (this != &copy)
	{
		isSigned = copy.isSigned;
	}
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
	if (this != &copy)
	{
		isSigned = copy.isSigned;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string name, const unsigned short int signGrade, const unsigned short int executeGrade) : AForm(name, signGrade, executeGrade), isSigned(false), signGrade(REQUIRED_SIGN), executeGrade(REQUIRED_EXEC)
{
	std::cout << YELLOW << __func__ << " called with name " << name
		<< ", sign grade " << signGrade << ", execute grade " << executeGrade << "\n" RESET;
	if (signGrade > REQUIRED_SIGN)
		throw GradeTooLowException("RobotomyRequestForm sign grade is not high enough\n");
	if (executeGrade > REQUIRED_EXEC)
		throw GradeTooLowException("RobotomyRequestForm execution grade is not high enough\n");
}

void	RobotomyRequestForm::beSigned(Bureaucrat bureaucrat)
{
	if (bureaucrat.getGrade() > signGrade)
		throw GradeTooLowException("Bureaucrat grade too low to sign the form\n");
	this->isSigned = true;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executeGrade > REQUIRED_EXEC)
		throw GradeTooLowException("RobotomyRequestForm execution grade is not high enough\n");
	(void)executor;
	std::cout << YELLOW "Making some drilling noises...\n" RESET;
	if (std::rand() % 2 == 0)
		std::cout << GREEN << executor.getName() << " has been successfully robotomized!\n" RESET;
	else
		std::cout << RED << executor.getName() << " has been unsuccessfully robotomized!\n" RESET;
	
	
	/**
	 * Required grades: sign 72, exec 45
		Makes some drilling noises, then informs that <target> has been robotomized
		successfully 50% of the time. Otherwise, it informs that the robotomy failed
	 * ! store a counter to achieve 50%
	 */
	// executor.getName();
}

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& form)
{
	return os << "RobotomyRequestForm " << form.getName() << ", is signed: " << (form.getIsSigned() ? "true" : "false")
		<< ", sign grade: " << form.getSignGrade() << ", execute grade: " << form.getExecuteGrade() << "\n";
}