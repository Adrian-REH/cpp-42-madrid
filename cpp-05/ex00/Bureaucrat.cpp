
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("_bureaucrat_"), _grade(150) {
	std::cout << "[Build] Bureaucrat with name " << this->_name << " and grade: "<< this->_grade << std::endl;

}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name) {
	this->setGrade(grade);
	std::cout << "[Build] Bureaucrat with name " << this->_name << " and grade: "<< this->_grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src.getName() + "_copy")
{
	std::cout << "[Copy Constructor] Bureaucrat called to copy " << src.getName() <<
	" into " << this->getName() << std::endl;
	*this = src;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "[Destroyed] Bureaucrat " << this->_name << std::endl;
}


std::string Bureaucrat::getName() const {
	return (this->_name);
}

int Bureaucrat::getGrade(void) const {
	return (this->_grade);
}

void Bureaucrat::setGrade(int grade) {
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw  Bureaucrat::GradeTooHighException();
	else 
		this->_grade = grade;
}

void Bureaucrat::incrementGrade(void) {
	std::cout << "Trying to increment grade of " << this->getName() << std::endl;
	this->setGrade(this->_grade + 1);
}

void Bureaucrat::drecrementGrade(void) {
	std::cout << "Trying to drecement grade of " << this->getName() << std::endl;
	this->setGrade(this->_grade - 1);
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw() {
	return ("Grade too low");
};

const char *Bureaucrat::GradeTooHighException::what(void) const throw() {
	return ("Grade too hight");
};

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src) {
	if (this == &src)
		return *this;
	this->_grade = src.getGrade();
	return (*this);
}
std::ostream &operator<<(std::ostream &o, Bureaucrat *a) {
	o << a->getName() << ", bureaucrat grade: " << a->getGrade();
	return (o);
}
