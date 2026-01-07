#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm() : name(__func__), isSigned(false), signGrade(1), executeGrade(1)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm&copy) : name(copy.name), signGrade(copy.signGrade), executeGrade(copy.executeGrade)
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

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name, const unsigned short int signGrade, const unsigned short int executeGrade)
	: name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
	std::cout << YELLOW << __func__ << " called with name " << name
		<< ", sign grade " << signGrade << ", execute grade " << executeGrade << "\n" RESET;
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException("AForm grade is lower than the highest value\n");
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException("AForm grade is higher than the lowest value\n");
}
