/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 01:59:43 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/23 01:59:43 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

#define RESET   "\033[0m"
#define YELLOW  "\033[33m"
#define RED     "\033[31m"

HumanB::HumanB(std::string name, Weapon& weapon) : _weapon(weapon), _name(name)
{

}

HumanB::~HumanB()
{
	std::cout << _name << RED << " Dead" << RESET << std::endl;
}

void HumanB::attack()
{
	std::cout << _name << " attacks with their " << YELLOW << _weapon.getType() << RESET << std::endl; 
}