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
	_energy = 100;
	_attack_damage = 30;
	std::cout << "[Init] "
	<< "ClapTrap: " << _name
	<< " hit point: " << _hit_point
	<< " energy: " << _energy
	<< " attack damage: " << _attack_damage << " [Created]" << std::endl;
}

ClapTrap::ClapTrap(std::string name, int hit_pt, int ene, int dmg) 
: _name(name), _hit_point(hit_pt),_energy(ene), _attack_damage(dmg) {
	std::cout << "[Init] "
	<< "ClapTrap: " << _name
	<< " hit point: " << _hit_point
	<< " energy: " << _energy
	<< " attack damage: " << _attack_damage << " [Created]" << std::endl;
}

ClapTrap::~ClapTrap(){
	std::cout << "[Destroy] " << "ClapTrap: " << _name << std::endl;
}
void	ClapTrap::attack(const std::string& target) {
	std::cout 
	<< "[Attack] ClapTrap: " << _name
	<< ", attacks: " << target
	 << ", causing: "<< _attack_damage << " point of damage!" << std::endl;
	 _energy--;
}

void	ClapTrap::takeDamage(unsigned int amount){
	_hit_point -= amount;
	std::cout 
	 << "[Pain] " << _name << " Life is reduced to: "<< _hit_point << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount){
	 _energy--;
	_hit_point += amount;
	std::cout 
	 << "[Healt] " << _name << " Life is restored to: "<< _hit_point << std::endl;
}
