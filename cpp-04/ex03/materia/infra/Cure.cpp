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
	AMateria *nCure = new Cure();
	return nCure;
}

void Cure::use(ICharacter& target) {
	std::cout << " heals " << target.getName() << "’s wounds" <<  std::endl;
}