/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 02:00:07 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/23 02:00:08 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"

Weapon::Weapon(std::string type): _type(type) {};

Weapon::~Weapon() {
	std::cout << "Destoy weapon " << RED <<  _type << RESET << std::endl;
}

void Weapon::setType(std::string type) {
	std::cout
	<< "Weapon " << RED << _type << RESET
	<< " was changed to " << BLUE << type << RESET << std::endl;
	_type = type;
}

std::string Weapon::getType(void) {
	return _type;
}