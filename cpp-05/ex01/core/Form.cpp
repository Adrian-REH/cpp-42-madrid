
#include "../inc/Form.hpp"

//Utils
void handleSignError(const Bureaucrat &bure, const Form &form, const std::string &errorType, const std::string &expected) {
	std::cout << bure.getName() 
				<< " couldn’t sign " << form.getName() 
				<< " because Error: Grade is " << errorType 
				<< " " << form.getSignGrade() 
				<< ", expected "<< expected << std::endl;
}

int verifyGrade(int grade) {
	if (grade > 150)
		throw Form::GradeTooLowException();
	else if (grade < 1)
		throw Form::GradeTooHighException();
	return (grade);
}

std::string intToStr(int val)
{
	std::stringstream ss;
	ss << val;
	return ss.str();
}

Form::Form() : _is_signed(false), _name("_form_"), _sign_grade(150), _exec_grade(1) {
	std::cout
	<< "[Build] Form name: " << this->_name <<
	" | sign grade: "<< this->_sign_grade <<
	" | exec grade" << this->_exec_grade << std::endl;
}

Form::Form(const std::string name, int s_g, int e_g) :
 _is_signed(false),
 _name(name), 
 _sign_grade(e_g),
 _exec_grade(s_g) {
	std::cout
	<< "[Build] Form name: " << this->_name <<
	" | sign grade: "<< this->_sign_grade <<
	" | exec grade" << this->_exec_grade << std::endl;

}

Form::Form(const Form& form) :
 _is_signed(form.getIsSigned()),
 _name(form.getName()),
 _sign_grade(verifyGrade(form.getSignGrade())),
 _exec_grade(verifyGrade(form.getExecGrade())) {
	std::cout << "[Copy Constructor] Bureaucrat called to copy " << form.getName() <<
	" into " << this->getName() << std::endl;
}

Form::~Form(void) {
	std::cout << "[Destroyed] Form " << this->_name << std::endl;
}
//Getters
bool Form::getIsSigned(void) const {
	return (this->_is_signed);
}

std::string Form::getName(void) const {
	return (this->_name);
}

int Form::getSignGrade(void) const {
	return (this->_sign_grade);
}

int Form::getExecGrade(void) const {
	return (this->_exec_grade);
}

void Form::beSigned(Bureaucrat & bure) {

	try {
		verifyGrade(bure.getGrade());
	}
	catch (std::exception &e)
	{
		handleSignError(
			bure,
			*this,
			dynamic_cast<Form::GradeTooHighException*>(&e) ? "High" : "Low",
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

//Setters
void Form::setName(std::string name) {
	this->_name = name;
}

//Exceptions
const char *Form::GradeTooLowException::what(void) const throw() {
	return ("Grade too low");
};

const char *Form::GradeTooHighException::what(void) const throw() {
	return ("Grade too hight");
};

//Operators
Form& Form::operator=(const Form& src) {
	std::cout << "[Assignment] Form called to assignment " << src.getName() << std::endl;
	if (this == &src)
		return (*this);
	return (*this);
}

std::ostream &operator<<(std::ostream &o, Form *f) {
	if (!f)
		return (o);
	o << f->getName() 
	<< ", form signed: " << f->getIsSigned() 
	<< ", form sign grade " << f->getSignGrade() 
	<< ", form exec grade " << f->getExecGrade() << std::endl;
	return (o);
}

