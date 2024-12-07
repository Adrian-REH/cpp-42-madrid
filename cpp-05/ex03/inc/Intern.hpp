/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:46:14 by adherrer          #+#    #+#             */
/*   Updated: 2024/12/07 12:38:01 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTER_HPP
#define INTER_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Form.hpp"

class Intern {
	private:
		Form *newPresidentialPardon(std::string trg);
		Form *newRobotomiRequest(std::string trg);
		Form *newShrubberyCreation(std::string trg);
		static Form *(Intern::*_k[3])(std::string trg);
	public:
		Intern();
		~Intern();
		Intern(const Intern &src);
		Intern &operator=(const Intern &src);
		Form *makeForm(std::string name, std::string trg);
};

#endif