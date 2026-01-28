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
	std::cout << INFO << __func__ << " called with grade " << grade << "\n" RESET;
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
	std::cout << INFO "Incrementing bureaucrat " << this->name << " to grade " << this->grade - 1 << "...\n" RESET;
	checkInRange(--this->grade);
}

void	Bureaucrat::decrement()
{
	std::cout << INFO "Decrementing bureaucrat " << this->name << " to grade " << this->grade + 1 << "...\n" RESET;
	checkInRange(++this->grade);
}

void	Bureaucrat::signForm(Form& form) const
{
	std::cout << INFO << this->name << " attempts to sign form " << form.getName() << "...\n" RESET;
	try
	{
		form.beSigned(*this);
		std::cout << OK << this->name << " signed " << form.getName() << "\n" RESET;
	}
	catch (const std::exception& e)
	{
		std::cerr << ERROR << this->name << " couldn't sign " << form.getName() << " because " << e.what() << "\n" RESET;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	return os << BLUE << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".\n" RESET;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const char *msg) : message(msg)
{
	std::cout << INFO << "Bureaucrat::" << __func__ << " called\n" RESET;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const int grade, const unsigned short int limit)
{
	std::cout << INFO << "Bureaucrat::" << __func__ << " called with grade " << grade << " and limit " << limit << "\n" RESET;
	std::stringstream ss1;
	std::stringstream ss2;
	ss1 << grade;
	this->message = "Grade (";
	this->message += ss1.str();
	this->message += ") is higher than the highest value (";
	ss2 << limit;
	this->message += ss2.str();
	this->message += ")\n";
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return this->message.c_str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const char *msg) : message(msg)
{
	std::cout << INFO << "Bureaucrat::" << __func__ << " called\n" RESET;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const int grade, const unsigned short int limit)
{
	std::cout << INFO << "Bureaucrat::" << __func__ << " called with grade " << grade << " and limit " << limit << "\n" RESET;
	std::stringstream ss1;
	std::stringstream ss2;
	ss1 << grade;
	this->message = "Grade (";
	this->message += ss1.str();
	this->message += ") is lower than the lowest value (";
	ss2 << limit;
	this->message += ss2.str();
	this->message += ")\n";
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return this->message.c_str();
}

