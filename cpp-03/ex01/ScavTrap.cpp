/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:16:16 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/30 20:31:55 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "iostream"
#define RESET   "\033[0m"
#define GREEN   "\033[32m"

ScavTrap::ScavTrap(std::string name)
: ClapTrap(name, 100, 50, 20)
{
	std::cout << "[Init] ScavTrap [Created]" << std::endl;
}
ScavTrap::~ScavTrap() {
	std::cout << "[Destroy] ScavTrap " << GREEN << _name << RESET << std::endl;
}

void	ScavTrap::attack(const std::string& target){
	std::cout 
	<< "[Attack] ScavTrap: " << GREEN << _name << RESET
	<< ", attacks: " << GREEN << target << RESET
	 << ", causing: "<< GREEN << _attack_damage << RESET << " point of damage!" << std::endl;
	 _energy--;
}

void ScavTrap::guardGate() {
	std::cout 
	<< "Change to mode Gatekeeper: " << std::endl;
}