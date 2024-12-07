#include "PresidentialPardonForm.hpp"

int writeTruncFile(PresidentialPardonForm src)
{
	std::string ascii;
	std::string filename = src.getTarget() + "_shrubbery";
	std::ofstream outFile(filename.c_str(), std::ios::trunc);
	if (!outFile){
		std::cout << "Error to open file: "<< filename << std::endl;
		return 1;
	}

	for (char i = 0; i <= 127; i++)
	{
		outFile << std::to_string(i) + "\n";
	}
	outFile.close();
	return 0;
}

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

void PresidentialPardonForm::execute(Bureaucrat const & src) const {
	verifyGrade(src.getGrade(), this->getExecGrade(), 1);
	verifyGrade(src.getGrade(), this->getSignGrade(), 1);
	writeTruncFile(*this);
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

