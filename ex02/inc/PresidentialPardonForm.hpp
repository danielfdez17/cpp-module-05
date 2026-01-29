#pragma once
#ifndef __PRESIDENTIAL_PARDON_FORM__
#define __PRESIDENTIAL_PARDON_FORM__

#include <string>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	const std::string			name;
	bool						isSigned;
	const unsigned short int	signGrade;
	const unsigned short int	executeGrade;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& copy);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& copy);
	virtual ~PresidentialPardonForm();

	PresidentialPardonForm(const std::string name, const unsigned short int signGrade, const unsigned short int executeGrade);
	// void		beSigned(Bureaucrat bureaucrat);
	void		execute(Bureaucrat const & executor) const;
};

std::ostream&	operator<<(std::ostream& os, const PresidentialPardonForm& form);

#endif // __PRESIDENTIAL_PARDON_FORM__