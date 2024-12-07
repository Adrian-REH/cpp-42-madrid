
#include "../inc/AForm.hpp"
//Utils
void handleSignError(const Bureaucrat &bure, const AForm &form, const std::string &errorType, const std::string &expected) {
	std::cout << bure.getName() 
				<< " couldn’t sign " << form.getName() 
				<< " because Error: Grade is " << errorType 
				<< " " << form.getSignGrade() 
				<< ", expected "<< expected << std::endl;
}

int AForm::verifyGrade(int grade, int max, int min) const {
	if (grade > max)
		throw AForm::GradeTooLowException();
	else if (grade < min)
		throw AForm::GradeTooHighException();
	return (grade);
}

AForm::AForm(void) : _is_signed(false) , _name("_form_") ,_sign_grade(150), _exec_grade(10) {
	std::cout
	<< "[Build] Form name: " << this->_name <<
	" | sign grade: "<< this->_sign_grade <<
	" | exec grade" << this->_exec_grade << std::endl;
}

AForm::AForm(const std::string name, int s_g, int e_g) :
 _name(name), 
 _sign_grade(s_g),
 _exec_grade(e_g) {
	std::cout
	<< "[Build] Form name: " << this->_name <<
	" | sign grade: "<< this->_sign_grade <<
	" | exec grade" << this->_exec_grade << std::endl;

}

AForm::AForm(const AForm& form) :
 _is_signed(form.getIsSigned()),
 _name(form.getName()),
 _sign_grade(this->verifyGrade(form.getSignGrade(), 150, 1)),
 _exec_grade(this->verifyGrade(form.getExecGrade(), 150, 1)) {
	std::cout << "[Copy Constructor] Bureaucrat called to copy " << form.getName() <<
	" into " << this->getName() << std::endl;
}

AForm::~AForm(void) {
	std::cout << "[Destroyed] Form " << this->_name << std::endl;
}
//Getters
bool AForm::getIsSigned(void) const {
	return (this->_is_signed);
}

std::string AForm::getName(void) const {
	return (this->_name);
}

int AForm::getSignGrade(void) const {
	return (this->_sign_grade);
}

int AForm::getExecGrade(void) const {
	return (this->_exec_grade);
}

//Setters
void AForm::beSigned(Bureaucrat const & bure) {

	try {
		this->verifyGrade(bure.getGrade(), 150, 1);
	}
	catch (std::exception &e)
	{
		handleSignError(
			bure,
			*this,
			dynamic_cast<AForm::GradeTooHighException*>(&e) ? "High" : "Low",
			"0 to 150");
	}
	if (this->getSignGrade() >= bure.getGrade())
		this->_is_signed = true;
	else 
		handleSignError(
		bure,
		*this,
		intToStr(bure.getGrade()),
		"'< or =' to ");
}

void AForm::setName(std::string name) {
	this->_name = name;
}

//Exceptions
const char *AForm::GradeTooLowException::what(void) const throw() {
	return ("Grade too low");
};

const char *AForm::GradeTooHighException::what(void) const throw() {
	return ("Grade too hight");
};

//Operators
AForm& AForm::operator=(const AForm& src) {
	std::cout << "[Assignment] Form called to assignment " << src.getName() << std::endl;
	if (this == &src)
		return (*this);
	return (*this);
}

std::ostream &operator<<(std::ostream &o, AForm *f) {
	if (!f)
		return (o);
	o << f->getName() 
	<< ", form signed: " << f->getIsSigned() 
	<< ", form sign grade " << f->getSignGrade() 
	<< ", form exec grade " << f->getExecGrade() << std::endl;
	return (o);
}

