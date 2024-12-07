/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 01:41:45 by adherrer          #+#    #+#             */
/*   Updated: 2024/12/07 09:23:43 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

/**
 * Required grades: sign 25, exec 5
Informs that <target> has been pardoned by Zaphod Beeblebrox
 */
class PresidentialPardonForm : public AForm {
	private:
		std::string target;
		PresidentialPardonForm();
	public:
		~PresidentialPardonForm();
		PresidentialPardonForm(std::string);
		PresidentialPardonForm(const PresidentialPardonForm &);
		void execute(Bureaucrat const & executor) const;
		PresidentialPardonForm &operator=(PresidentialPardonForm &a);
		std::string getTarget(void)const;
};
std::ostream &operator<<(std::ostream &o, PresidentialPardonForm *a);

#endif