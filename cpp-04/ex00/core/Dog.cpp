/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:53:05 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/31 19:58:23 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../intf/Dog.hpp"


Dog::Dog() : Animal("Dog") {
	std::cout << "[Created] Dog"<< std::endl;
}

Dog::~Dog(){
	std::cout << "[Destroyed] Dog"<< std::endl;
}

std::string Dog::getType() const {
	return (_type);
}

Dog::Dog(const Dog & dog) : Animal() {
	std::cout << "[Copy] Dog"<< std::endl;
	*this = dog;
}

Dog& Dog::operator=(const Dog& dog) {
	std::cout << "Dog Assignation operator called" << std::endl;
	if (this != &dog){
		this->_type = dog.getType();
	}
	return *this;
}


void Dog::makeSound() const {
	std::cout << "Woof" << std::endl;
}