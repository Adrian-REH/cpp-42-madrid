/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 01:59:36 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/23 01:59:36 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <string>
#include <iostream>


#define RESET   "\033[0m"
#define BLUE    "\033[34m"
#define YELLOW  "\033[33m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

HumanA::HumanA(std::string name, Weapon& weapon) : _weapon(weapon), _name(name)
{

}

HumanA::~HumanA()
{
	std::cout << _name << RED << " Dead" << RESET << std::endl;
}

void HumanA::attack()
{
	std::cout << _name << " attacks with their " << BLUE << _weapon.getType() << RESET << std::endl; 
}