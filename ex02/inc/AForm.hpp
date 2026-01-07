#pragma once
#ifndef __AFORM__
#define __AFORM__

#include <string>
#include "colors.hpp"
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"
#include "Bureaucrat.hpp"

typedef class Bureaucrat Bureaucrat;

class AForm
{
protected:
	
	const std::string			name;
	bool						isSigned;
	const unsigned short int	signGrade;
	const unsigned short int	executeGrade;
public:
	AForm();
	AForm(const AForm& copy);
	AForm& operator=(const AForm& copy);
	virtual ~AForm();

	AForm(const std::string name, const unsigned short int signGrade, const unsigned short int executeGrade);

	std::string			getName() const;
	bool				getIsSigned() const;
	unsigned short int	getSignGrade() const;
	unsigned short int	getExecuteGrade() const;

	virtual void		beSigned(Bureaucrat bureaucrat) = 0;
	virtual void		execute(Bureaucrat const & executor) const = 0;
};

std::ostream&	operator<<(std::ostream& os, const AForm& form);

#endif // __AFORM__