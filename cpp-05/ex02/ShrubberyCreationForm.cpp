/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:19:21 by adherrer          #+#    #+#             */
/*   Updated: 2024/12/07 10:19:37 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"


int writeTruncFile(ShrubberyCreationForm src)
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

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery Creation Form", 72, 45) , _target(""){
	std::cout << "[BUilder] Shrubbery Creation Form with target "<< this->_target << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "[Destroyed] Shrubbery Creation Form"<< std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("Shrubbery Creation Form", 25, 5) {
	std::cout << "[BUilder] Shrubbery Creation Form with target "<< this->_target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) :
AForm(src.getName() + "_copy", src.getSignGrade(), src.getExecGrade()),
_target(src.getTarget())
{
	std::cout << "[Copy] Shrubbery Creation Form"<< std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src) {
	std::cout << "[Assignment] Shrubbery Creation Form called to assignment " << src.getName() << std::endl;
	if (this == &src)
		return (*this);
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & src) const {
	verifyGrade(src.getGrade(), this->getExecGrade(), 1);
	verifyGrade(src.getGrade(), this->getSignGrade(), 1);
	writeTruncFile(*this);
}

std::string ShrubberyCreationForm::getTarget(void)const{
	return (this->_target);
}


std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm *a) {
	o << a->getName() 
	<< ", form signed: " << a->getIsSigned() 
	<< ", form sign grade " << a->getSignGrade() 
	<< ", form exec grade " << a->getExecGrade()
	<< ", form target "<< a->getTarget() << std::endl;
	return (o);
}

