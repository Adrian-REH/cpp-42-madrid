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
#define YELLOW  "\033[33m"
#define GREEN  "\033[32m"
#define BLUE   "\033[36m"
#define RESET  "\033[0m"
#define RED    "\033[31m"

ClapTrap::ClapTrap(std::string name, int hit_pt, int ene, int dmg) 
    : _name(name), _hit_point(hit_pt), _energy(ene), _attack_damage(dmg) 
{
    std::cout << YELLOW << "[Init] " << RESET
              << "ClapTrap: " << _name
              << " hit point: " << _hit_point
              << " energy: " << _energy
              << " attack damage: " << _attack_damage 
              << YELLOW << " [Created]" << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name) 
{
    _hit_point = 100;
    _energy = 100;
    _attack_damage = 30;
    std::cout << YELLOW << "[Init] " << RESET
              << "ClapTrap: " << _name
              << " hit point: " << _hit_point
              << " energy: " << _energy
              << " attack damage: " << _attack_damage 
              << YELLOW << " [Created]" << RESET << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << RED << "[Destroy]" << RESET 
              << " ClapTrap: " << _name 
              << RED << " [Destructed]" << RESET << std::endl;
}

void ClapTrap::attack(const std::string& target) 
{
    std::cout << BLUE << "[Attack]" << RESET << " ClapTrap: " << _name
              << ", attacks: " << target
              << ", causing: " << _attack_damage 
              << " point of damage!" << std::endl;
    _energy--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    _hit_point -= amount;
    std::cout << RED << "[Pain] " << RESET 
              << _name << " Life is reduced to: " << _hit_point << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    _energy--;
    _hit_point += amount;
    std::cout << GREEN << "[Health] " << RESET 
              << _name << " Life is restored to: " << _hit_point << std::endl;
}
