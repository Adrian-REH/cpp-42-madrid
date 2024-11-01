/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:29:57 by adherrer          #+#    #+#             */
/*   Updated: 2024/11/01 13:17:50 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../domain/Ice.hpp"
#include <string>

Ice::Ice(): AMateria("ice") {
	std::cout << "[Created] Materia Ice" << std::endl;
}

Ice::~Ice(){
	std::cout << " Cure " << std::endl;}

AMateria* Ice::clone() const {
	AMateria *nIce = new Ice();
	return nIce;
}
