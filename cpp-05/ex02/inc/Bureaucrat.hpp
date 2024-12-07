/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:46:32 by adherrer          #+#    #+#             */
/*   Updated: 2024/12/07 14:46:37 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <string>
#include <exception>
#include "AForm.hpp"
#include <iostream>

class AForm;
/**
 * This class build a new Bureacrat with
 * these requirements
 * _name: is to string const
 * _grade: that ranges from 1 to 150
 */
class Bureaucrat {
	private:
		const std::string _name;
		int			_grade;
		void setGrade(int grade);
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &);
		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat&);
		int getGrade(void) const;
		std::string getName(void) const;
		void incrementGrade(void);
		void decrementGrade(void);
		void executeForm(const AForm &form)const;
		void signForm(AForm &form);

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &o, Bureaucrat *a);

#endif