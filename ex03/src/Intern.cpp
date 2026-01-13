#include <iostream>
#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "colors.hpp"

const std::string			ROBOTOMY_FORM = "robotomy request";
const unsigned short int	ROBOTOMY_REQUIRED_SIGN = 72;
const unsigned short int	ROBOTOMY_REQUIRED_EXEC = 45;

const std::string			PRESIDENTIAL_FORM = "presidential pardon";
const unsigned short int	PRESIDENTIAL_REQUIRED_SIGN = 25;
const unsigned short int	PRESIDENTIAL_REQUIRED_EXEC = 5;

const std::string			SHRUBBERY_FORM = "shrubbery creation";
const unsigned short int	SHRUBBERY_REQUIRED_SIGN = 145;
const unsigned short int	SHRUBBERY_REQUIRED_EXEC = 137;

Intern::Intern()
{
	forms[0].key = ROBOTOMY_FORM;
	forms[0].value = new RobotomyRequestForm();
	forms[1].key = PRESIDENTIAL_FORM;
	forms[1].value = new PresidentialPardonForm();
	forms[2].key = SHRUBBERY_FORM;
	forms[2].value = new ShrubberyCreationForm();
}

Intern::Intern(const Intern &copy)
{
	if (this != &copy)
		*this = copy;
}

Intern	Intern::operator=(const Intern &copy)
{
	if (this != &copy)
		*this = copy;
	return *this;
}

Intern::~Intern()
{
	delete forms[0].value;
	delete forms[1].value;
	delete forms[2].value;
}

AForm	*Intern::makeForm(std::string formName, std::string targetName)
{
	AForm *form = NULL;
	// for (unsigned short int i = 0; i < MAX_FORMS; i++)
	// {
	// 	if (formName == forms[i].key)
	// 	{
	// 		form = new 
	// 	}
	// }
	if (formName == "robotomy request")
		form = new RobotomyRequestForm(targetName, ROBOTOMY_REQUIRED_SIGN, ROBOTOMY_REQUIRED_EXEC);
	else if (formName == "presidential pardon")
		form = new PresidentialPardonForm(targetName, PRESIDENTIAL_REQUIRED_SIGN, PRESIDENTIAL_REQUIRED_EXEC);
	else if (formName == "shrubbery creation")
		form = new ShrubberyCreationForm(targetName, SHRUBBERY_REQUIRED_SIGN, SHRUBBERY_REQUIRED_EXEC);
	else
	{
		std::cout << RED "'" << formName << "' does not exist!!!\n" RESET;
		return NULL;
	}
	//? 1 enum and loop over the enum values till formName is found? 
	//? 2 map with struct {key, value}
	std::cout << YELLOW "Intern creates " << form << RESET;
	return form;
}
