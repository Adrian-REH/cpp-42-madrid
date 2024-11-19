/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:55:23 by adherrer          #+#    #+#             */
/*   Updated: 2024/11/01 20:08:56 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../domain/Cure.hpp"
#include <iostream>

Cure::Cure(): AMateria("cure") {
	std::cout << "[Created] Materia Cure" << std::endl;

};

Cure::~Cure() {
	std::cout << "[Destroyed] Cure - ";
}

AMateria* Cure::clone() const {
	std::cout << "[Clone] Cure" << std::endl;
	AMateria *nCure = new Cure();
	return nCure;
}

void Cure::use(ICharacter& target) {
	std::cout << " heals " << target.getName() << "’s wounds" <<  std::endl;
}

Cure::Cure(const Cure& cure) : AMateria() {
	std::cout << "[Copy] Cure" << std::endl;
	*this = cure;
}
Cure& Cure::operator=(const Cure& cure) {
	std::cout << "Cure assignation operator called" << std::endl;
	if (this != &cure){
		this->_idx = cure.getIdx();
		this->_type = cure.getType();
	}
	return *this;
}