/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:16:16 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/23 13:41:00 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "iostream"

ScavTrap::ScavTrap(std::string name)
: ClapTrap(name, 100, 50, 20)
{
	std::cout << "[Init] ScavTrap [Created]" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "[Destroy] ScavTrap " << _name << std::endl;
}

void	ScavTrap::attack(const std::string& target){
	std::cout 
	<< "[Attack] ScavTrap: " << _name
	<< ", attacks: " << target
	 << ", causing: "<< _attack_damage << " point of damage!" << std::endl;
	 _energy--;
}

void ScavTrap::guardGate() {
	std::cout 
	<< "[Mode] Change to mode Gatekeeper" << std::endl;
}