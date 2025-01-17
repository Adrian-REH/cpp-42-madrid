/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 01:41:45 by adherrer          #+#    #+#             */
/*   Updated: 2024/12/07 12:38:01 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"
#include <iostream>
#include <string>

/**
 * Required grades: sign 25, exec 5
Informs that <target> has been pardoned by Zaphod Beeblebrox
 */
class PresidentialPardonForm : public Form {
	private:
		std::string _target;
		PresidentialPardonForm();
	public:
		~PresidentialPardonForm();
		PresidentialPardonForm(std::string);
		PresidentialPardonForm(const PresidentialPardonForm &);
		void execute(Bureaucrat const & executor) const;
		PresidentialPardonForm &operator=(const PresidentialPardonForm &a);
		std::string getTarget(void)const;
};
std::ostream &operator<<(std::ostream &o, PresidentialPardonForm *a);

#endif