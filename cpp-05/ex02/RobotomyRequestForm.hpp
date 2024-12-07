/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 01:41:45 by adherrer          #+#    #+#             */
/*   Updated: 2024/12/07 09:24:16 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

/**
 * Required grades: sign 72, exec 45
Makes some drilling noises. Then, informs that <target> has been robotomized
successfully 50% of the time. Otherwise, informs that the robotomy failed.
 */
class RobotomyRequestForm : public AForm {
	private:
		std::string target;
		RobotomyRequestForm();
	public:
		~RobotomyRequestForm();
		RobotomyRequestForm(std::string);
		RobotomyRequestForm(const RobotomyRequestForm &);
		void execute(Bureaucrat const & executor) const;
		RobotomyRequestForm &operator=(RobotomyRequestForm &a);
		std::string getTarget(void)const;
};
std::ostream &operator<<(std::ostream &o, RobotomyRequestForm *a);

#endif