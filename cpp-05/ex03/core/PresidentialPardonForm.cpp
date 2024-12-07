/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:19:12 by adherrer          #+#    #+#             */
/*   Updated: 2024/12/07 14:55:11 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm(): Form("Presidential Pardon Form", 25, 5) , _target(""){
	std::cout << "[BUilder] Presidential Pardon Form with target "<< this->_target << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "[Destroyed] Presidential Pardon Form"<< std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): Form("Presidential Pardon Form", 25, 5), _target(target) {
	std::cout << "[BUilder] Presidential Pardon Form with target "<< this->_target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) :
Form(src.getName() + "_copy", src.getSignGrade(), src.getExecGrade()),
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
	this->verifyGrade(src.getGrade(), this->getExecGrade(), 1);
	this->verifyGrade(src.getGrade(), this->getSignGrade(), 1);
	std::cout << src.getName() << " executed " << "Presidential Pardon Form"<< std::endl;
	std::cout << this->getTarget() << ", has been perdoned by Zaphod Beeblebrox" << std::endl;
}

std::string PresidentialPardonForm::getTarget(void)const {
	return (this->_target);
}


std::ostream &operator<<(std::ostream &o, PresidentialPardonForm *a) {
	if (!a)
		return (o);
	o << a->getName() 
	<< ", form signed: " << a->getIsSigned() 
	<< ", form sign grade " << a->getSignGrade() 
	<< ", form exec grade " << a->getExecGrade()
	<< ", form target "<< a->getTarget() << std::endl;
	return (o);
}

