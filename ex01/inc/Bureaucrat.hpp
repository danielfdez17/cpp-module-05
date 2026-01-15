#pragma once
#ifndef __BUREAUCRAT__
#define __BUREAUCRAT__

#include <string>
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat {
private:
	const std::string	name;
	unsigned short int	grade;

public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat& copy);
	Bureaucrat& operator=(const Bureaucrat& copy);
	~Bureaucrat();
	Bureaucrat(const std::string name, const int grade);
	
	const std::string	getName() const;
	unsigned short int	getGrade() const;
	void				checkInRange(const int grade) const;
	// ? increment === --
	void				increment();
	// ? decrement === ++
	void				decrement();

	void				signForm(Form& form) const;
	
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

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif // __BUREAUCRAT__