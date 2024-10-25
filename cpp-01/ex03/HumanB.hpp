/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 01:59:46 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/25 16:51:24 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB{
	private:
		Weapon* _weapon;
		std::string _name;
	public:
		HumanB(std::string name);
		~HumanB();
		void attack();
		void setWeapon(Weapon* weapon);
};

#endif