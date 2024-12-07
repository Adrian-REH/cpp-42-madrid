#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("Presidential Pardon Form", 25, 5) {
	std::cout << "[BUilder] Presidential Pardon Form"<< std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "[Destroyed] Presidential Pardon Form"<< std::endl;
}


void PresidentialPardonForm::execute(const Bureaucrat & src) {
	
}