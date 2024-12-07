/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 01:41:45 by adherrer          #+#    #+#             */
/*   Updated: 2024/12/07 14:32:31 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCHRUBBERYCREATIONFORM_HPP
# define SCHRUBBERYCREATIONFORM_HPP

#include "../inc/AForm.hpp"
#include "AForm.hpp"
#include <fstream>
#include <iostream>
#include <string>

/**
 * Required grades: sign 145, exec 137
 * Create a file <target>_shrubbery in the working directory, and writes ASCII trees
 * inside it.
 */
class ShrubberyCreationForm : public AForm {
	private:
		std::string _target;
		ShrubberyCreationForm();
	public:
		~ShrubberyCreationForm();
		ShrubberyCreationForm(std::string);
		ShrubberyCreationForm(const ShrubberyCreationForm &);
		void execute(Bureaucrat const & executor) const;
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &a);
		std::string getTarget(void)const;
};
std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm *a);

#endif