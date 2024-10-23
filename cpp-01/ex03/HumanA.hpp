/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 01:59:40 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/23 01:59:40 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "Weapon.hpp"
class HumanA{
	private:
		Weapon& _weapon;
		std::string _name;
	public:
		HumanA(std::string name, Weapon& Weapon);
		~HumanA();
		void attack();
};

#endif