#include "AForm.hpp"

int verifyGrade(int grade, int max, int min) {
	if (grade > max)
		throw AForm::GradeTooLowException();
	else if (grade < min)
		throw AForm::GradeTooHighException();
	return (grade);
}
