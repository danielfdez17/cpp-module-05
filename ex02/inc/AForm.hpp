#pragma once
#ifndef __AFORM__
#define __AFORM__

#include <string>
#include "utils.hpp"
#include "Bureaucrat.hpp"

typedef class Bureaucrat Bureaucrat;

class AForm
{
private:
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

	class GradeTooHighException : public std::exception
	{
	private:
		std::string message;
	public:
		GradeTooHighException(const char *msg);
		GradeTooHighException(const int grade, const unsigned short int limit);
		virtual ~GradeTooHighException() throw();
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	private:
		std::string message;
	public:
		GradeTooLowException(const char *msg);
		GradeTooLowException(const int grade, const unsigned short int limit);
		virtual ~GradeTooLowException() throw();
		const char *what() const throw();
	};
};

std::ostream&	operator<<(std::ostream& os, const AForm& form);

#endif // __AFORM__