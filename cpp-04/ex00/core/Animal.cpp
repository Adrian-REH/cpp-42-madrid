/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:52:56 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/31 19:58:09 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../intf/Animal.hpp"

Animal::Animal(std::string type) : _type(type) {
	std::cout << "[Created] Animal with type"<< std::endl;
}

Animal::Animal() : _type("") {
	std::cout << "[Created] Animal"<< std::endl;
}

Animal::~Animal() {
	std::cout << "[Destroyed] Animal"<< std::endl;

}

std::string Animal::getType() const {
	return _type;
}

Animal::Animal(const Animal& animal){
	std::cout << "[Copy] Animal"<< std::endl;
	*this = animal;
}
Animal& Animal::operator=(const Animal& animal) {
	std::cout << "Animal Assignation operator called" << std::endl;
	if (this != &animal){
		this->_type = animal.getType();
	}
	return *this;
}

void Animal::makeSound() const {
	std::cout << "" << std::endl;
}

