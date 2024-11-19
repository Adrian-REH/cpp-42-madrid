/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:29:57 by adherrer          #+#    #+#             */
/*   Updated: 2024/11/01 20:11:05 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../domain/Ice.hpp"
#include <string>

Ice::Ice(): AMateria("ice") {
	std::cout << "[Created] Materia Ice" << std::endl;
}

Ice::~Ice(){
	std::cout << "[Destroyed] Ice - ";
}

AMateria* Ice::clone() const {
	std::cout << "[Clone] Ice" << std::endl;
	AMateria *nIce = new Ice();
	return nIce;
}

void Ice::use(ICharacter& target) {
	std::cout << "shoots an ice bolt at " << target.getName() <<  std::endl;
}

Ice::Ice(const Ice& ice) : AMateria() {
	std::cout << "[Copy] Ice" << std::endl;
	*this = ice;
}
Ice& Ice::operator=(const Ice& ice) {
	std::cout << "Ice assignation operator called" << std::endl;
	if (this != &ice){
		this->_idx = ice.getIdx();
		this->_type = ice.getType();
	}
	return *this;
}