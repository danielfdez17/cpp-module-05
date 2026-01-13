#include "AForm.hpp"
#include <iostream>

AForm::AForm() : name(__func__), isSigned(false), signGrade(1), executeGrade(1)
{
}

AForm::AForm(const AForm&copy) : name(copy.name), signGrade(copy.signGrade), executeGrade(copy.executeGrade)
{
	if (this != &copy)
	{
		isSigned = copy.isSigned;
	}
}

AForm& AForm::operator=(const AForm& copy)
{
	if (this != &copy)
	{
		isSigned = copy.isSigned;
	}
	return *this;
}

AForm::~AForm()
{
}

AForm::AForm(const std::string name, const unsigned short int signGrade, const unsigned short int executeGrade)
	: name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
	std::cout << YELLOW << __func__ << " called with name " << name
		<< ", sign grade " << signGrade << ", execute grade " << executeGrade << "\n" RESET;
	if (signGrade < LOWEST_VALUE || executeGrade < LOWEST_VALUE)
		throw GradeTooHighException("AForm grade is lower than the highest value\n");
	if (signGrade > HIGHEST_VALUE || executeGrade > HIGHEST_VALUE)
		throw GradeTooLowException("AForm grade is higher than the lowest value\n");
}

std::string			AForm::getName() const { return name; }
bool				AForm::getIsSigned() const { return isSigned; }
unsigned short int	AForm::getSignGrade() const { return signGrade; }
unsigned short int	AForm::getExecuteGrade() const { return executeGrade; }

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	return os << "AForm " << form.getName() << ", is signed: " << (form.getIsSigned() ? "true" : "false")
		<< ", sign grade: " << form.getSignGrade() << ", execute grade: " << form.getExecuteGrade() << "\n";
}
