#include "colors.hpp"
#include "Form.hpp"

int main()
{
	{
		std::cout << YELLOW "---------------------------------------------- ex00 tests ----------------------------------------------\n" RESET;
		try
		{
			Bureaucrat b("Juan", 155);
			std::cout << b;
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << "\n" RESET;
		}
		try
		{
			Bureaucrat b("Alberto", -155);
			std::cout << b;
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << "\n" RESET;
		}
		try
		{
			Bureaucrat b("Carlos", 150);
			std::cout << b;
			b.increment();
			std::cout << b;
			b.decrement();
			std::cout << b;
			b.decrement();
			std::cout << b;
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << "\n" RESET;
		}
		try
		{
			Bureaucrat b("David", 1);
			std::cout << b;
			b.decrement();
			std::cout << b;
			b.increment();
			std::cout << b;
			b.increment();
			std::cout << b;
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << "\n" RESET;
		}
	}

	{
		std::cout << YELLOW "---------------------------------------------- ex01 tests ----------------------------------------------\n" RESET;
		Form f1("Form1", 1, 1);
		Form f2("Form1", 80, 80);
		Bureaucrat b1("Eve", 75);
		std::cout << f1;
		std::cout << b1;
		b1.signForm(f1);
		std::cout << f1;
		std::cout << f2;
		std::cout << b1;
		b1.signForm(f2);
		std::cout << f2;
		Bureaucrat b2("Frank", 30);
		std::cout << b2;
		b2.signForm(f1);
		std::cout << f1;
		std::cout << b2;
		b2.signForm(f2);
		std::cout << f2;
	}
	
	return 0;
}