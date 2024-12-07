#include "../inc/Intern.hpp"
#include "../inc/StrToLower.hpp"

static const std::string _forms[3] = {"PresidentialPardonForm", "RobotomyRequestForm" ,"ShrubberyCreationForm"};

Form *(Intern::*Intern::_k[3])(std::string) = {&Intern::newPresidentialPardon, &Intern::newRobotomiRequest, &Intern::newShrubberyCreation};

Form *Intern::newPresidentialPardon(std::string trg) {
	return (new PresidentialPardonForm(trg));
}

Form *Intern::newRobotomiRequest(std::string trg){
	return (new RobotomyRequestForm(trg));
}

Form *Intern::newShrubberyCreation(std::string trg){
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

Form *Intern::makeForm(std::string name, std::string trg) {
	int i = 0;

	while (i <= 3)
	{
		if (_forms[i] == name)
		{
			break ;
		}
		i++;
	}
	if (i <= 3 && this->_k[i]) {
		std::cout << "Intern creates "<< name << "Form" << std::endl;
		return (this->*_k[i])(trg);
	}
	return (NULL);
}
