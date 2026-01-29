#include "RobotomyRequestForm.hpp"
#include <cstdlib>

const unsigned short int REQUIRED_SIGN = 72;
const unsigned short int REQUIRED_EXEC = 45;

RobotomyRequestForm::RobotomyRequestForm() : AForm(), isSigned(false), signGrade(REQUIRED_SIGN), executeGrade(REQUIRED_EXEC)//, type(__func__)
{
	this->type = __func__;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm&copy) : AForm(copy), isSigned(false), signGrade(REQUIRED_SIGN), executeGrade(REQUIRED_EXEC)//, type(__func__)
{
	this->type = __func__;
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

RobotomyRequestForm::RobotomyRequestForm(const std::string name, const unsigned short int signGrade, const unsigned short int executeGrade) : AForm(name, signGrade, executeGrade), name(name), isSigned(false), signGrade(REQUIRED_SIGN), executeGrade(REQUIRED_EXEC)
{
	std::cout << YELLOW << __func__ << " called with name " << name
		<< ", sign grade " << signGrade << ", execute grade " << executeGrade << "\n" RESET;
	if (signGrade > this->signGrade)
		throw AForm::GradeTooLowException("RobotomyRequestForm sign grade is not high enough\n");
	if (executeGrade > this->executeGrade)
		throw AForm::GradeTooLowException("RobotomyRequestForm execution grade is not high enough\n");
}

// void	RobotomyRequestForm::beSigned(Bureaucrat bureaucrat)
// {
// 	if (bureaucrat.getGrade() > signGrade)
// 		throw AForm::GradeTooLowException("Bureaucrat grade too low to sign the form\n");
// 	if (this->isSigned)
// 		std::cout << YELLOW "RobotomyRequestForm '" << name << "' has already been signed!!!\n" RESET;
// 	this->isSigned = true;
// 	std::cout << GREEN "RobotomyRequestForm '" << name << "' has been signed successfully\n" RESET;
// }

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->executeGrade)
		throw AForm::GradeTooLowException("RobotomyRequestForm execution grade is not high enough\n");
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
	return os << BLUE << "RobotomyRequestForm " << form.getName() << ", is signed: " << (form.getIsSigned() ? "true" : "false")
		<< ", sign grade: " << form.getSignGrade() << ", execute grade: " << form.getExecuteGrade() << "\n" RESET;
}