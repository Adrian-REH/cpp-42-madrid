
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <exception>

//NEEDED TEST!
int main()
{
	std::cout << "-------------------------------------------------------" << std::endl;
	{
		Bureaucrat	b("bob", 150);
		std::cout << &b << std::endl;
		try {
			b.incrementGrade();
		}
		catch (std::exception & e) {
			std::cout << "[Exception: " << e.what() << " , Function: Main, Action: Increment]"<< std::endl;
		}
		std::cout << &b << std::endl;
	}
	std::cout << "-------------------------------------------------------" << std::endl;
	{
		Bureaucrat c("carl", 1);
		std::cout << &c << std::endl;
		try {
			c.decrementGrade();
		}
		catch (std::exception & e) {
			std::cout << "[Exception: " << e.what() << " , Function: Main, Action: Drecrement]"<< std::endl;
		}
		std::cout << &c << std::endl;
	}
	std::cout << "-------------------------------------------------------" << std::endl;
	{
		AForm f;
	}
}