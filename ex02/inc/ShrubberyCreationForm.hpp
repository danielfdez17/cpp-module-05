#pragma once
#ifndef __SHRUBBERY_CREATION_FORM__
#define __SHRUBBERY_CREATION_FORM__

#include <string>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	const std::string			name;
	bool						isSigned;
	const unsigned short int	signGrade;
	const unsigned short int	executeGrade;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& copy);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy);
	virtual ~ShrubberyCreationForm();

	ShrubberyCreationForm(const std::string name, const unsigned short int signGrade, const unsigned short int executeGrade);
	// void		beSigned(Bureaucrat bureaucrat);
	void		execute(Bureaucrat const & executor) const;
};

std::ostream&	operator<<(std::ostream& os, const ShrubberyCreationForm& form);

#endif // __SHRUBBERY_CREATION_FORM__