/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:29:57 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/25 18:48:54 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Ice.hpp"
#include <string>

Ice::Ice(): AMateria("Ice") {
	std::cout << "create Materia Ice" << std::endl;
}

Ice::~Ice(){}

AMateria* Ice::clone() const {
	AMateria *nIce = new Ice();
	return nIce;
}
