/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:55:23 by adherrer          #+#    #+#             */
/*   Updated: 2024/11/01 13:17:54 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../domain/Cure.hpp"
#include <iostream>

Cure::Cure(): AMateria("cure") {
	std::cout << "[Created] Materia Cure" << std::endl;

};

Cure::~Cure() {
	std::cout << " Cure " << std::endl;
}

AMateria* Cure::clone() const {
	AMateria *nCure = new Cure();
	return nCure;
}
