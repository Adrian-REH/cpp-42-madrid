/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inter.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:46:14 by adherrer          #+#    #+#             */
/*   Updated: 2024/12/07 11:23:08 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTER_HPP
#define INTER_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

class Intern {
	private:
		AForm *newPresidentialPardon(std::string trg);
		AForm *newRobotomiRequest(std::string trg);
		AForm *newShrubberyCreation(std::string trg);
		static AForm *(Intern::*_k[3])(std::string trg);
	public:
		Intern();
		~Intern();
		Intern(const Intern &src);
		Intern &operator=(const Intern &src);
		AForm *makeForm(std::string name, std::string trg);
};

#endif