#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() {
	std::cout << "[Builder] Robotomy Request Form"<< std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "[Destroyed] Robotomy Request Form"<< std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat &src) const {
	if (src.getGrade() <= this->getExecGrade()) {
		std::cout << "Informs that <target> has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
}