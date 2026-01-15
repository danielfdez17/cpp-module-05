#include "Bureaucrat.hpp"
#include "utils.hpp"
#include <string>
#include <sstream>

Bureaucrat::Bureaucrat() : name(__func__), grade(1)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : name(__func__)
{
	if (this != &copy)
	{
		checkInRange(copy.grade);
		grade = copy.grade;
	}
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
	if (this != &copy)
	{
		checkInRange(copy.grade);
		grade = copy.grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string name, const int grade) : name(name)
{
	std::cout << YELLOW << __func__ << " called with grade " << grade << "\n" RESET;
	checkInRange(grade);
	this->grade = grade;
}

const std::string Bureaucrat::getName() const { return name; }

unsigned short int Bureaucrat::getGrade() const { return grade; }

void	Bureaucrat::checkInRange(const int grade) const
{
	if (grade < LOWEST_VALUE)
		throw GradeTooHighException("Grade is lower than the highest value\n");
	if (grade > HIGHEST_VALUE)
		throw GradeTooLowException("Grade is higher than the lowest value\n");
}

void	Bureaucrat::increment()
{
	checkInRange(--grade);
}

void	Bureaucrat::decrement()
{
	checkInRange(++grade);
}

void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form .beSigned(*this);
		std::cout << GREEN << name << " signed " << form.getName() << "\n" RESET;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << name << " couldn't sign " << form.getName() << " because " << e.what() << "\n" RESET;
	}
}

void	Bureaucrat::executeForm(AForm &form)
{
	try
	{
		form .execute(*this);
		std::cout << GREEN << name << " executed " << form.getName() << "\n" RESET;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << name << " couldn't execute " << form.getName() << " because " << e.what() << "\n" RESET;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	return os << CYAN << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".\n" RESET;
}


Bureaucrat::GradeTooHighException::GradeTooHighException(const char *msg) : message(msg) {}

Bureaucrat::GradeTooHighException::GradeTooHighException(const int grade, const unsigned short int limit)
{
	std::stringstream ss1;
	std::stringstream ss2;
	ss1 << grade;
	this->message = "Grade (";
	this->message += ss1.str();
	this->message += ") is higher than the lowest value (";
	ss2 << limit;
	this->message += ss2.str();
	this->message += ")\n";
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return this->message.c_str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const char *msg) : message(msg) {}

Bureaucrat::GradeTooLowException::GradeTooLowException(const int grade, const unsigned short int limit)
{
	std::stringstream ss1;
	std::stringstream ss2;
	ss1 << grade;
	this->message = "Grade (";
	this->message += ss1.str();;
	this->message += ") is lower than the highest value (";
	ss2 << limit;
	this->message += ss2.str();
	this->message += ")\n";
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return this->message.c_str();
}

