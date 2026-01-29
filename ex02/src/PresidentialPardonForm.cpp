#include "PresidentialPardonForm.hpp"

const unsigned short int REQUIRED_SIGN = 25;
const unsigned short int REQUIRED_EXEC = 5;

PresidentialPardonForm::PresidentialPardonForm() : AForm(), isSigned(false), signGrade(REQUIRED_SIGN), executeGrade(REQUIRED_EXEC)//, type(__func__)
{
	this->type = __func__;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm&copy) : AForm(copy), isSigned(false), signGrade(REQUIRED_SIGN), executeGrade(REQUIRED_EXEC)//, type(__func__)
{
	this->type = __func__;
	if (this != &copy)
	{
		isSigned = copy.isSigned;
	}
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
	if (this != &copy)
	{
		isSigned = copy.isSigned;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string name, const unsigned short int signGrade, const unsigned short int executeGrade) : AForm(name, signGrade, executeGrade), name(name), isSigned(false), signGrade(REQUIRED_SIGN), executeGrade(REQUIRED_EXEC)
{
	std::cout << YELLOW << __func__ << " called with name " << name
		<< ", sign grade " << signGrade << ", execute grade " << executeGrade << "\n" RESET;
	if (signGrade > this->signGrade)
		throw AForm::GradeTooLowException("PresidentialPardonForm sign grade is not high enough\n");
	if (executeGrade > this->executeGrade)
		throw AForm::GradeTooLowException("PresidentialPardonForm execution grade is not high enough\n");
}

// void	PresidentialPardonForm::beSigned(Bureaucrat bureaucrat)
// {
// 	if (bureaucrat.getGrade() > this->signGrade)
// 		throw AForm::GradeTooLowException("Bureaucrat grade too low to sign the form\n");
// 	if (this->isSigned)
// 		std::cout << YELLOW "PresidentialPardonForm '" << name << "' has already been signed!!!\n" RESET;
// 	this->isSigned = true;
// 	std::cout << GREEN "PresidentialPardonForm '" << name << "' has been signed successfully\n" RESET;
// }

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->executeGrade)
		throw AForm::GradeTooLowException("Bureaucrat grade too low to execute the form\n");
	std::cout << YELLOW << executor.getName() << " has been pardoned by Zaphod Beeblebrox\n" RESET;
}

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& form)
{
	return os << BLUE << "PresidentialPardonForm " << form.getName() << ", is signed: " << (form.getIsSigned() ? "true" : "false")
		<< ", sign grade: " << form.getSignGrade() << ", execute grade: " << form.getExecuteGrade() << "\n" RESET;
}