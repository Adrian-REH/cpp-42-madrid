#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("Presidential Pardon Form", 25, 5) , _target(""){
	std::cout << "[BUilder] Presidential Pardon Form with target "<< this->_target << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "[Destroyed] Presidential Pardon Form"<< std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("Presidential Pardon Form", 25, 5) {
	std::cout << "[BUilder] Presidential Pardon Form with target "<< this->_target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) :
AForm(src.getName() + "_copy", src.getSignGrade(), src.getExecGrade()),
_target(src.getTarget())
{
	std::cout << "[Copy] Presidential Pardon Form"<< std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src) {
	std::cout << "[Assignment] PresidentialPardonForm called to assignment " << src.getName() << std::endl;
	if (this == &src)
		return (*this);
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	
}

std::string PresidentialPardonForm::getTarget(void)const{
	return (this->_target);
}


std::ostream &operator<<(std::ostream &o, PresidentialPardonForm *a) {
	o << a->getName() 
	<< ", form signed: " << a->getIsSigned() 
	<< ", form sign grade " << a->getSignGrade() 
	<< ", form exec grade " << a->getExecGrade()
	<< ", form target "<< a->getTarget() << std::endl;
	return (o);
}
