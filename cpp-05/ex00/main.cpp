
#include "Bureaucrat.hpp"
#include <exception>

int main()
{
	Bureaucrat	b("bob", 150);
	std::cout << &b << std::endl;
	try {
		b.incrementGrade();
	}
	catch (std::exception & e) {
		std::cout << "[Exception: " << e.what() << " , Function: Main, Action: Increment]"<< std::endl;
	}
	Bureaucrat c("carl", 1);
	std::cout << &c << std::endl;
	try {
		c.drecrementGrade();
	}
	catch (std::exception & e) {
		std::cout << "[Exception: " << e.what() << " , Function: Main, Action: Drecrement]"<< std::endl;
	}
}