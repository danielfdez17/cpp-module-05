#include "Bureaucrat.hpp"
#include "colors.hpp"
#include <string>
#include <sstream>

const unsigned short int	HIGHEST_VALUE = 150;
const unsigned short int	LOWEST_VALUE = 1;

Bureaucrat::Bureaucrat() : name(__func__), grade(1)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : name(__func__)
{
	if (this != &copy)
	{
		checkInRange(copy.grade);
		this->grade = copy.grade;
	}
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
	if (this != &copy)
	{
		checkInRange(copy.grade);
		this->grade = copy.grade;
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

const std::string Bureaucrat::getName() const { return this->name; }

unsigned short int Bureaucrat::getGrade() const { return this->grade; }

void	Bureaucrat::checkInRange(const int grade) const
{
	if (grade < LOWEST_VALUE)
		throw Bureaucrat::GradeTooHighException(grade, LOWEST_VALUE);
	if (grade > HIGHEST_VALUE)
		throw Bureaucrat::GradeTooLowException(grade, HIGHEST_VALUE);
}

void	Bureaucrat::increment()
{
	checkInRange(--this->grade);
}

void	Bureaucrat::decrement()
{
	checkInRange(++this->grade);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	return os << BLUE << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".\n" RESET;
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

