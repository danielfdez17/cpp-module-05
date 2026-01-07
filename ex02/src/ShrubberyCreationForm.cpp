#include "ShrubberyCreationForm.hpp"

const unsigned short int REQUIRED_SIGN = 145;
const unsigned short int REQUIRED_EXEC = 137;

ShrubberyCreationForm::ShrubberyCreationForm() : AForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm&copy) : AForm(copy)
{
	if (this != &copy)
	{
		isSigned = copy.isSigned;
	}
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
	if (this != &copy)
	{
		isSigned = copy.isSigned;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name, const unsigned short int signGrade, const unsigned short int executeGrade) : AForm(name, signGrade, executeGrade)
{
	std::cout << YELLOW << __func__ << " called with name " << name
		<< ", sign grade " << signGrade << ", execute grade " << executeGrade << "\n" RESET;
	if (signGrade > REQUIRED_SIGN)
		throw GradeTooLowException("ShrubberyCreationForm sign grade is not high enough\n");
	if (executeGrade > REQUIRED_EXEC)
		throw GradeTooLowException("ShrubberyCreationForm execution grade is not high enough\n");
}

void	ShrubberyCreationForm::beSigned(Bureaucrat bureaucrat)
{
	if (bureaucrat.getGrade() > signGrade)
		throw GradeTooLowException("Bureaucrat grade too low to sign the form\n");
	this->isSigned = true;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::cout << RED "Unimplemented method\n" RESET;
	(void)executor;
	// todo: creates a executor.getName()_shrubbery file to write ASCII trees inside it.
	// executor.getName();
}

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& form)
{
	return os << "ShrubberyCreationForm " << form.getName() << ", is signed: " << (form.getIsSigned() ? "true" : "false")
		<< ", sign grade: " << form.getSignGrade() << ", execute grade: " << form.getExecuteGrade() << "\n";
}