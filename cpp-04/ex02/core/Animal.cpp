/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:54:45 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/31 19:59:04 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../intf/Animal.hpp"

Animal::Animal(std::string type) : _type(type) {
	std::cout << "[Created] Animal, added Type: "<< type << std::endl;
}
Animal::Animal() : _type("") {
	std::cout << "[Created] Animal" << std::endl;
}
Animal::~Animal(){
	std::cout << "[Destroyed] Animal" << std::endl;
}

std::string Animal::getType() const {
	return _type;
}

void Animal::makeSound() const {
	std::cout << "" << std::endl;
}