#pragma once
#ifndef __FORM__
#define __FORM__

#include <string>
#include "Bureaucrat.hpp"

typedef class Bureaucrat Bureaucrat;

class Form
{
private:
	const std::string			name;
	bool						isSigned;
	const unsigned short int	signGrade;
	const unsigned short int	executeGrade;
public:
	Form();
	Form(const Form& copy);
	Form& operator=(const Form& copy);
	~Form();

	Form(const std::string name, const unsigned short int signGrade, const unsigned short int executeGrade);

	std::string			getName() const;
	bool				getIsSigned() const;
	unsigned short int	getSignGrade() const;
	unsigned short int	getExecuteGrade() const;

	void				beSigned(Bureaucrat const &bureaucrat);

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

std::ostream&	operator<<(std::ostream& os, const Form& form);

#endif // __FORM__