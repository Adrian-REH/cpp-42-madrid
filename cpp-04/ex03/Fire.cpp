/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FIre.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:29:57 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/25 19:26:59 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Fire.hpp"
#include <iostream>

Fire::Fire() : AMateria("fire") {
	std::cout << "Create Material fire" << std::endl;

}
Fire::~Fire() {}
AMateria* Fire::clone() const {
	AMateria *nFire = new Fire();
	return nFire;
}
