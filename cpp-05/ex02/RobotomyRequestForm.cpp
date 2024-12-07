#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm(): AForm("Robotomy Request Form", 72, 45) , _target(""){
	std::cout << "[BUilder] Robotomy Request Form with target "<< this->_target << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "[Destroyed] Robotomy Request Form"<< std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("Robotomy Request Form", 25, 5) {
	std::cout << "[BUilder] Robotomy Request Form with target "<< this->_target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) :
AForm(src.getName() + "_copy", src.getSignGrade(), src.getExecGrade()),
_target(src.getTarget())
{
	std::cout << "[Copy] Robotomy Request Form"<< std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src) {
	std::cout << "[Assignment] Robotomy Request Form called to assignment " << src.getName() << std::endl;
	if (this == &src)
		return (*this);
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & src) const {
	verifyGrade(src.getGrade(), this->getExecGrade(), 1);
	verifyGrade(src.getGrade(), this->getSignGrade(), 1);
	//Execute
}

std::string RobotomyRequestForm::getTarget(void)const{
	return (this->_target);
}


std::ostream &operator<<(std::ostream &o, RobotomyRequestForm *a) {
	o << a->getName() 
	<< ", form signed: " << a->getIsSigned() 
	<< ", form sign grade " << a->getSignGrade() 
	<< ", form exec grade " << a->getExecGrade()
	<< ", form target "<< a->getTarget() << std::endl;
	return (o);
}

