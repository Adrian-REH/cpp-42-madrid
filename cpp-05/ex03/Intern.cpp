#include "Intern.hpp"
#include "SToLower.cpp"

static const std::string _forms[3] = {"presidential pardon", "robotomy request" ,"shrubbery creation"};

AForm *(Intern::*Intern::_k[3])(std::string) = {&Intern::newPresidentialPardon, &Intern::newRobotomiRequest, &Intern::newShrubberyCreation};

AForm *Intern::newPresidentialPardon(std::string trg) {
	return (new PresidentialPardonForm(trg));
}

AForm *Intern::newRobotomiRequest(std::string trg){
	return (new RobotomyRequestForm(trg));
}

AForm *Intern::newShrubberyCreation(std::string trg){
	return (new ShrubberyCreationForm(trg));
}

Intern::Intern() {
	std::cout << "[Created] intern" << std::endl;
}

Intern::~Intern() {
	std::cout << "[Destroyes] intern" << std::endl;

}

Intern::Intern(const Intern &src) {
	std::cout << "[Copy] intern" << std::endl;
	*this = src;
}

Intern &Intern::operator=(const Intern &src) {
	if (this == &src)
		return (*this);
	return (*this);
}

AForm *Intern::makeForm(std::string name, std::string trg) {
	int i = 0;

	name = stolower(name);
	while (_forms[i] != name)
		i++;

	std::cout << "Intern creates "<< name << "Form" << std::endl;
	if (this->_k[i])
		return (this->*_k[i])(trg);
}
