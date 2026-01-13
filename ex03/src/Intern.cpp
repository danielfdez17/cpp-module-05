#include <iostream>
#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "colors.hpp"

const unsigned short int MAX_FORMS = 3;

const std::string			ROBOTOMY_FORM = "robotomy request";
const unsigned short int	ROBOTOMY_REQUIRED_SIGN = 72;
const unsigned short int	ROBOTOMY_REQUIRED_EXEC = 45;

const std::string			PRESIDENTIAL_FORM = "presidential pardon";
const unsigned short int	PRESIDENTIAL_REQUIRED_SIGN = 25;
const unsigned short int	PRESIDENTIAL_REQUIRED_EXEC = 5;

const std::string			SHRUBBERY_FORM = "shrubbery creation";
const unsigned short int	SHRUBBERY_REQUIRED_SIGN = 145;
const unsigned short int	SHRUBBERY_REQUIRED_EXEC = 137;

Intern::Intern() {}

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

Intern::~Intern() {}

AForm	*Intern::makeForm(std::string formName, std::string targetName)
{
	AForm	*form = NULL;
	int		index = -1;
	const	std::string names[MAX_FORMS] = {
		ROBOTOMY_FORM,
		PRESIDENTIAL_FORM,
		SHRUBBERY_FORM
	};

	for (unsigned short int i = 0; i < MAX_FORMS; i++)
	{
		if (formName == names[i])
		{
			index = i;
			break;
		}
	}
	switch (index)
	{
	case 0:
		form = new RobotomyRequestForm(targetName, ROBOTOMY_REQUIRED_SIGN, ROBOTOMY_REQUIRED_EXEC);
		break;
	case 1:
		form = new PresidentialPardonForm(targetName, PRESIDENTIAL_REQUIRED_SIGN, PRESIDENTIAL_REQUIRED_EXEC);
		break;
	case 2:
		form = new ShrubberyCreationForm(targetName, SHRUBBERY_REQUIRED_SIGN, SHRUBBERY_REQUIRED_EXEC);
		break;
	default:
		std::cout << RED "'" << formName << "' does not exist!!!\n" RESET;
		return NULL;
	}
	std::cout << GREEN "Intern creates " << *form << RESET;
	return form;
}
