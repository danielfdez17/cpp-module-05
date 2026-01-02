#pragma once
#ifndef __BUREAUCRAT__
#define __BUREAUCRAT__

#include <string>
#include <iostream>

class Bureaucrat {
private:
	const std::string	name;
	unsigned short int	grade;

public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat& copy);
	Bureaucrat& operator=(const Bureaucrat& copy);
	~Bureaucrat();
	Bureaucrat(const int grade);
	
	const std::string	getName() const;
	unsigned short int	getGrade() const;
	void				checkInRange(const int grade) const;
	// ? increment === --
	void				increment();
	// ? decrement === ++
	void				decrement();
	
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif // __BUREAUCRAT__