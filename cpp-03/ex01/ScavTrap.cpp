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

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
}
ScavTrap::~ScavTrap() {
	
}

ScavTrap::ClapTrap::ClapTrap(std::string name) : _name(name) {
	_hit_point = 100;
	_energy = 50;
	_attack_damage = 20;
	std::cout << " [Init] "
	<< "ScavTrap: " << _name
	<< " hit point: " << _hit_point
	<< " energy: " << _energy
	<< " attack damage" << _attack_damage << std::endl;

}

ScavTrap::ClapTrap::~ClapTrap() {
	std::cout << "[Destroy] " << "ScavTrap: " << _name << std::endl;
}

void	ScavTrap::ClapTrap::attack(const std::string& target){
	std::cout 
	<< " ScavTrap: " << _name
	<< ", attacks: " << target
	 << ", causing: "<< _attack_damage << " point of damage!" << std::endl;
	 _energy--;
}

void ScavTrap::guardGate() {
	std::cout 
	<< "Change to mode Gatekeeper: " << std::endl;
}