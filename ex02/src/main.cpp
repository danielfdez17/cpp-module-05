#include "utils.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	// {
	// 	try
	// 	{
	// 		Bureaucrat b("Juan", 155);
	// 		std::cout << b;
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cerr << RED << e.what() << "\n" RESET;
	// 	}
	// 	try
	// 	{
	// 		Bureaucrat b("Alberto", -155);
	// 		std::cout << b;
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cerr << RED << e.what() << "\n" RESET;
	// 	}
	// 	try
	// 	{
	// 		Bureaucrat b("Carlos", 150);
	// 		std::cout << b;
	// 		b.increment();
	// 		std::cout << b;
	// 		b.decrement();
	// 		std::cout << b;
	// 		b.decrement();
	// 		std::cout << b;
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cerr << RED << e.what() << "\n" RESET;
	// 	}
	// 	try
	// 	{
	// 		Bureaucrat b("David", 1);
	// 		std::cout << b;
	// 		b.decrement();
	// 		std::cout << b;
	// 		b.increment();
	// 		std::cout << b;
	// 		b.increment();
	// 		std::cout << b;
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cerr << RED << e.what() << "\n" RESET;
	// 	}
	// }

	try {
		std::cout << YELLOW "-----------------------------------Shrubbery tests-----------------------------------\n" RESET;
		ShrubberyCreationForm s1("Shrubbery", 50, 100);
		Bureaucrat b1("Eve", 75);
		std::cout << s1;
		std::cout << b1;
		b1.signForm(s1);
		std::cout << s1;
		Bureaucrat b2("Frank", 30);
		std::cout << b2;
		b2.signForm(s1);
		std::cout << s1;
		b1.executeForm(s1);
		std::cout << s1;
		b2.executeForm(s1);
		std::cout << s1;
	} catch (const std::exception& e) {
		std::cerr << RED << e.what() << "\n" RESET;
	}

	try {
		std::cout << YELLOW "-----------------------------------Robotomy tests-----------------------------------\n" RESET;
		RobotomyRequestForm r1("Robotomy", 40, 40);
		Bureaucrat b1("Eve", 1);
		std::cout << r1;
		std::cout << b1;
		b1.signForm(r1);
		b1.executeForm(r1);
		b1.executeForm(r1);
		std::cout << r1;
		Bureaucrat b2("Frank", 30);
		std::cout << b2;
		b2.signForm(r1);
		std::cout << r1;
		b1.executeForm(r1);
		std::cout << r1;
		b2.executeForm(r1);
		std::cout << r1;
	} catch (const std::exception& e) {
		std::cerr << RED << e.what() << "\n" RESET;
	}

	try {
		std::cout << YELLOW "-----------------------------------Presidential tests-----------------------------------\n" RESET;
		PresidentialPardonForm p1("Presidential", 1, 1);
		Bureaucrat b1("Eve", 75);
		std::cout << p1;
		std::cout << b1;
		b1.signForm(p1);
		std::cout << p1;
		Bureaucrat b2("Frank", 30);
		std::cout << b2;
		b2.signForm(p1);
		std::cout << p1;
		b1.executeForm(p1);
		std::cout << p1;
		b2.executeForm(p1);
		std::cout << p1;
	} catch (const std::exception& e) {
		std::cerr << RED << e.what() << "\n" RESET;
	}
	
	return 0;
}