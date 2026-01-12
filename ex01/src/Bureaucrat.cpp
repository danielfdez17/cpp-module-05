#include "Bureaucrat.hpp"
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"
#include "colors.hpp"

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
		throw GradeTooHighException(grade, LOWEST_VALUE);
	if (grade > HIGHEST_VALUE)
		throw GradeTooLowException(grade, HIGHEST_VALUE);
}

void	Bureaucrat::increment()
{
	checkInRange(--grade);
}

void	Bureaucrat::decrement()
{
	checkInRange(++grade);
}


void	Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << GREEN << name << " signed " << form.getName() << "\n" RESET;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << name << " couldn't sign " << form.getName() << " because: " << e.what() << "\n" RESET;
	}
	
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	return os << BLUE << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".\n" RESET;
}