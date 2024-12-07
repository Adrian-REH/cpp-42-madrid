/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:19:21 by adherrer          #+#    #+#             */
/*   Updated: 2024/12/07 14:54:54 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"

int writeTruncFile(ShrubberyCreationForm src)
{
	std::string ascii;
	std::string filename = src.getTarget() + "_shrubbery";
	std::ofstream outFile(filename.c_str(), std::ios::trunc);
	if (!outFile) {
		std::cout << "Error to open file: "<< filename << std::endl;
		return 1;
	}

	for (int i = 0; i <= 127; i++)
		outFile <<  static_cast<char>(i) << "\n";
	outFile.close();
	return 0;
}

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery Creation Form", 145, 137) , _target(""){
	std::cout << "[BUilder] Shrubbery Creation Form with target "<< this->_target << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "[Destroyed] Shrubbery Creation Form"<< std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("Shrubbery Creation Form", 25, 5), _target(target){
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
	this->verifyGrade(src.getGrade(), this->getExecGrade(), 1);
	this->verifyGrade(src.getGrade(), this->getSignGrade(), 1);
	std::cout << src.getName() << " executed " << "Shrubbery Creation Form"<< std::endl;
	writeTruncFile(*this);
	std::cout << " File " << this->getTarget() << "_shrubbery created"<< std::endl;
}

std::string ShrubberyCreationForm::getTarget(void) const {
	return (this->_target);
}


std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm *a) {
	if (!a)
		return (o);
	o << a->getName() 
	<< ", form signed: " << a->getIsSigned() 
	<< ", form sign grade " << a->getSignGrade() 
	<< ", form exec grade " << a->getExecGrade()
	<< ", form target "<< a->getTarget() << std::endl;
	return (o);
}
