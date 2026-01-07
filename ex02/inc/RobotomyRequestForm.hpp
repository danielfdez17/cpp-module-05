#pragma once
#ifndef __ROBOTOMY_REQUEST_FORM__
#define __ROBOTOMY_REQUEST_FORM__

#include <string>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	// const std::string			name;
	// bool						isSigned;
	// const unsigned short int	signGrade;
	// const unsigned short int	executeGrade;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& copy);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);
	virtual ~RobotomyRequestForm();

	RobotomyRequestForm(const std::string name, const unsigned short int signGrade, const unsigned short int executeGrade);
	void		beSigned(Bureaucrat bureaucrat);
	void		execute(Bureaucrat const & executor) const;
};

std::ostream&	operator<<(std::ostream& os, const RobotomyRequestForm& form);

#endif // __ROBOTOMY_REQUEST_FORM__