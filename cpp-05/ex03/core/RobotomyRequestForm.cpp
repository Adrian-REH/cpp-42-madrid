#include "../inc/RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm(): Form("Robotomy Request Form", 72, 45) , _target(""){
	std::cout << "[BUilder] Robotomy Request Form with target "<< this->_target << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "[Destroyed] Robotomy Request Form"<< std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): Form("Robotomy Request Form", 25, 5), _target(target) {
	std::cout << "[BUilder] Robotomy Request Form with target "<< this->_target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) :
Form(src.getName() + "_copy", src.getSignGrade(), src.getExecGrade()),
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
	this->verifyGrade(src.getGrade(), this->getExecGrade(), 1);
	this->verifyGrade(src.getGrade(), this->getSignGrade(), 1);
	std::cout << src.getName() << " executed " << "Robotomy Request Form"<< std::endl;
	std::cout << "Brrr Brrr Brrr\n" << std::endl;
	if (std::rand() % 1)
		std::cout <<"Successfully robotomized "<< this->getTarget() << std::endl;
	else
		std::cout <<"Fail robotomized "<< this->getTarget() << std::endl;
}

std::string RobotomyRequestForm::getTarget(void)const{
	return (this->_target);
}


std::ostream &operator<<(std::ostream &o, RobotomyRequestForm *a) {
	if (!a)
		return (o);
	o << a->getName() 
	<< ", form signed: " << a->getIsSigned() 
	<< ", form sign grade " << a->getSignGrade() 
	<< ", form exec grade " << a->getExecGrade()
	<< ", form target "<< a->getTarget() << std::endl;
	return (o);
}

