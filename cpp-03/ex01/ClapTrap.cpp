/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 04:15:59 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/23 17:33:02 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string name) : _name(name) {
	_hit_point = 100;
	_energy = 50;
	_attack_damage = 20;
	std::cout << " [Init] "
	<< "ClapTrap: " << _name
	<< " hit point: " << _hit_point
	<< " energy: " << _energy
	<< " attack damage" << _attack_damage << std::endl;
}
ClapTrap::~ClapTrap(){

	std::cout << "[Destroy] " << "ClapTrap: " << _name << std::endl;
}
void	ClapTrap::attack(const std::string& target){
	std::cout 
	<< " ClapTrap: " << _name
	<< ", attacks: " << target
	 << ", causing: "<< _attack_damage << " point of damage!" << std::endl;
	 _energy--;
}

void	ClapTrap::takeDamage(unsigned int amount){
	_hit_point -= amount;
	std::cout 
	 << "Life is reduced to: "<< _hit_point << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount){
	 _energy--;
	_hit_point += amount;
	std::cout 
	 << "Life is restored to: "<< _hit_point << std::endl;
}
