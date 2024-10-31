/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 04:15:59 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/30 20:27:25 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#define RESET   "\033[0m"
#define BLUE    "\033[34m"

ClapTrap::ClapTrap(std::string name) : _name(name) {
	_hit_point = 100;
	_energy = 100;
	_attack_damage = 30;
	std::cout << "[Init] "
	<< "ClapTrap: " << BLUE << _name << RESET
	<< " hit point: " << BLUE << _hit_point << RESET
	<< " energy: " << BLUE << _energy << RESET
	<< " attack damage " << BLUE << _attack_damage << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name, int hit_pt, int ene, int dmg) 
: _name(name), _hit_point(hit_pt),_energy(ene), _attack_damage(dmg) {
	std::cout << "[Init] "
	<< "ClapTrap: " <<BLUE << _name<< RESET
	<< " hit point: " << BLUE <<_hit_point<< RESET
	<< " energy: " << BLUE <<_energy<< RESET
	<< " attack damage: " << BLUE <<_attack_damage << RESET<< " [Created]" << std::endl;
}

ClapTrap::~ClapTrap(){
	std::cout << "[Destroy] " << "ClapTrap: " << BLUE << _name<< RESET << std::endl;
}

void	ClapTrap::attack(const std::string& target) {
	std::cout 
	<< "[Attack] ClapTrap: " << BLUE << _name << RESET
	<< ", attacks: " <<  BLUE << target << RESET
	 << ", causing: "<< BLUE <<_attack_damage  << RESET << " point of damage!" << std::endl;
	 _energy--;
}

void	ClapTrap::takeDamage(unsigned int amount){
	_hit_point -= amount;
	std::cout 
	 << "[Pain] " << BLUE<< _name << RESET<< " Life is reduced to: " << BLUE<< _hit_point << RESET<< std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount){
	 _energy--;
	_hit_point += amount;
	std::cout 
	 << "[Healt] " << BLUE<< _name << RESET<< " Life is restored to: "<< BLUE<< _hit_point << RESET<< std::endl;
}
