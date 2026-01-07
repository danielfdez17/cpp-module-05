#pragma once
#ifndef __BUREAUCRAT__
#define __BUREAUCRAT__

#include <string>
#include <iostream>
#include "AForm.hpp"

typedef class AForm AForm;

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

	void				signForm(AForm &form);
	void				executeForm(AForm &form);
	
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif // __BUREAUCRAT__