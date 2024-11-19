/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:53:35 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/31 20:50:45 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../intf/Dog.hpp"
#include "../intf/Brain.hpp"

Dog::Dog() : Animal("Dog"), _brain(new Brain()) {
	std::cout << "[Created] Dog"<< std::endl;
}

Dog::Dog(Brain *brain) : Animal("Dog"), _brain(brain) {
	std::cout << "[Created] Dog, Added Brain"<< std::endl;
}

Dog::~Dog() {
	delete _brain;
	std::cout << "[Destroyed] Dog"<< std::endl;
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

std::string Dog::getType() const {
	return (_type);
}
void Dog::makeSound() const {
	std::cout << "Woof" << std::endl;
}