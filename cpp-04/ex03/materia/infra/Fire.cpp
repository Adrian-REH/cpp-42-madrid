/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fire.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:29:57 by adherrer          #+#    #+#             */
/*   Updated: 2024/11/01 19:56:19 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../domain/Fire.hpp"
#include <iostream>

Fire::Fire() : AMateria("fire") {
	std::cout << "[Created] Material fire" << std::endl;

}
Fire::~Fire() {
	std::cout << "[Destroyed] Fire - ";
}

AMateria* Fire::clone() const {
	std::cout << "[Clone] Fire"<< std::endl;
	AMateria *nFire = new Fire();
	return nFire;
}

void Fire::use(ICharacter& target) {
	std::cout << " Fired " << target.getName() << "’s wounds" <<  std::endl;
}

Fire::Fire(const Fire& fire) : AMateria() {
	std::cout << "[Copy] Fire"<< std::endl;
	*this = fire;
}
Fire& Fire::operator=(const Fire& fire) {
	std::cout << "Fire assignation operator called" << std::endl;
	if (this != &fire){
		this->_idx = fire.getIdx();
		this->_type = fire.getType();
	}
	return *this;
}