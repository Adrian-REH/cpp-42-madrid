/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:55:23 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/31 19:55:24 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

Cure::Cure(): AMateria("cure") {
	std::cout << "Create Materia Cure" << std::endl;

};

Cure::~Cure() {}

AMateria* Cure::clone() const {
	AMateria *nCure = new Cure();
	return nCure;
}
