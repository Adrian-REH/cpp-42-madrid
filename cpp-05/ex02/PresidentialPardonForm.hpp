/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 01:41:45 by adherrer          #+#    #+#             */
/*   Updated: 2024/12/07 01:57:49 by adherrer         ###   ########.fr       */
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
	public: 
		PresidentialPardonForm();
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &);
		void execute(Bureaucrat const & executor) const;
};

#endif