/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:19:12 by adherrer          #+#    #+#             */
/*   Updated: 2024/12/07 10:19:14 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void PresidentialPardonForm::execute(Bureaucrat const & src) const {
	verifyGrade(src.getGrade(), this->getExecGrade(), 1);
	verifyGrade(src.getGrade(), this->getSignGrade(), 1);
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

