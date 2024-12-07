/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 01:41:45 by adherrer          #+#    #+#             */
/*   Updated: 2024/12/07 01:57:46 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCHRUBBERYCREATIONFORM_HPP
# define SCHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

/**
 * Required grades: sign 145, exec 137
 * Create a file <target>_shrubbery in the working directory, and writes ASCII trees
 * inside it.
 */
class ShrubberyCreationForm : public AForm {
	public: 
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &);
		void execute(Bureaucrat const & executor) const;
};

#endif