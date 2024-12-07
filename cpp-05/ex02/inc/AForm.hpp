/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:44:15 by adherrer          #+#    #+#             */
/*   Updated: 2024/12/07 14:38:52 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include "IntToStr.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>

class Bureaucrat;
/**
 * This class build a new Form for Bureaucrat
 * each Bureaucrat signed if grade is equal or more to _sign_grade and
 * his can execute Form if grade is equal or more to _exec_grade
 * these requirements
 * _is_signed:....
 * _name: name of the Form
 * _sign_grade: that ranges from 1 to 150
 * _exec_grade: that ranges from 1 to 150
 * 
 * signForm() : This function supports an int less than or equal to grade
 */
class AForm {
	private:
		bool		_is_signed;
		std::string	_name;
		const int	_sign_grade;
		const int	_exec_grade;
	public:
		AForm();
		AForm(const std::string, int sign_grade, int exec_grade);
		AForm(const AForm&);
		virtual ~AForm(void);
		AForm& operator=(const AForm&);
		//Getters
		bool getIsSigned(void) const;
		std::string getName(void) const;
		int getSignGrade(void) const;
		int getExecGrade(void) const;
		//Setters
		void setName(std::string);
		//Methods
		int verifyGrade(int grade, int max, int min) const;
		virtual void execute(Bureaucrat const & src) const = 0;
		void beSigned(Bureaucrat const &src);
	//Exceptions
	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &o, AForm *a);

#endif 