#include "ShrubberyCreationForm.hpp"

#include <fstream>

const unsigned short int REQUIRED_SIGN = 145;
const unsigned short int REQUIRED_EXEC = 137;

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(), isSigned(false), signGrade(REQUIRED_SIGN), executeGrade(REQUIRED_EXEC)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm&copy) : AForm(copy), isSigned(false), signGrade(REQUIRED_SIGN), executeGrade(REQUIRED_EXEC)
{
	if (this != &copy)
	{
		isSigned = copy.isSigned;
	}
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
	if (this != &copy)
	{
		isSigned = copy.isSigned;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name, const unsigned short int signGrade, const unsigned short int executeGrade) : AForm(name, signGrade, executeGrade), isSigned(false), signGrade(REQUIRED_SIGN), executeGrade(REQUIRED_EXEC)
{
	std::cout << YELLOW << __func__ << " called with name " << name
		<< ", sign grade " << signGrade << ", execute grade " << executeGrade << "\n" RESET;
	if (signGrade > REQUIRED_SIGN)
		throw GradeTooLowException("ShrubberyCreationForm sign grade is not high enough\n");
	if (executeGrade > REQUIRED_EXEC)
		throw GradeTooLowException("ShrubberyCreationForm execution grade is not high enough\n");
}

void	ShrubberyCreationForm::beSigned(Bureaucrat bureaucrat)
{
	if (bureaucrat.getGrade() > signGrade)
		throw GradeTooLowException("Bureaucrat grade too low to sign the form\n");
	this->isSigned = true;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::cout << RED "Unimplemented method\n" RESET;
	(void)executor;
	if (executeGrade > REQUIRED_EXEC)
		throw GradeTooLowException("ShrubberyCreationForm execution grade is not high enough\n");
	std::fstream outfile;
	std::string content =
	"      *             ,\n"
	"                          _/^\\_\n"
	"                         <     >\n"
	"        *                 /.-.\\         *\n"
	"                 *        `/&\\`                   *\n"
	"                         ,@.*;@,\n"
	"                        /_o.I %_\\    *\n"
	"           *           (`'--:o(_@;\n"
	"                      /`;--.,__ `')             *\n"
	"                     ;@`o % O,*`'`&\\\n"
	"               *    (`'--)_@ ;o %'()\\      *\n"
	"                    /`;--._`''--._O'@;\n"
	"                   /&*,()~o`;-.,_ `\"\"`)\n"
	"        *          /`,@ ;+& () o*`;-';\n"
	"                  (`\"\"--.,_0 +% @' &()\n"
	"                  /-.,_    ``''--....-'`)  *\n"
	"             *    /@%;o`:;'--,.__   __.'\n"
	"                 ;*,&(); @ % &^;~`\"`o;@();         *\n"
	"                 /(); o^~; & ().o@*&`;&%O\n"
	"           jgs   `\"=\"==\"\"==,,,.,=\"==\"==\"`\n"
	"              __.----.(\\-''#####---...___...-----._\n"
	"            '`         \\)_`\"\"\"\"`\"\n"
	"                    .--' ')\n"
	"                  o(  )_-\\\n"
	"                    `\"\"\"` `\n";
	outfile.open(& (executor.getName() + "_shrubbery")[0], std::fstream::out);
	
	outfile << content;
	outfile.close();
}

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& form)
{
	return os << "ShrubberyCreationForm " << form.getName() << ", is signed: " << (form.getIsSigned() ? "true" : "false")
		<< ", sign grade: " << form.getSignGrade() << ", execute grade: " << form.getExecuteGrade() << "\n";
}