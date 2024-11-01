/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Electric.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:29:57 by adherrer          #+#    #+#             */
/*   Updated: 2024/11/01 13:17:56 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../domain/Electric.hpp"
#include <iostream>

Electric::Electric() : AMateria("electric") {
	std::cout << "[Created] Material Electric" << std::endl;
}

Electric::~Electric() {
	std::cout << " Cure " << std::endl;
}

AMateria* Electric::clone() const {
	AMateria *nElec = new Electric();
	return nElec;
}
