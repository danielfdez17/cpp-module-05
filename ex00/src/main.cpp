#include "utils.hpp"
#include "Bureaucrat.hpp"

int main()
{
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
	return 0;
}