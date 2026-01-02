#include "colors.hpp"
#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b(155);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << "\n" RESET;
	}
	return 0;
}