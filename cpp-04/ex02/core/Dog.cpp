/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:54:59 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/31 20:01:22 by adherrer         ###   ########.fr       */
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

Dog::~Dog(){
	delete _brain;
	std::cout << "[Destroyed] Dog"<< std::endl;
}

std::string Dog::getType() const {
	return (_type);
}
void Dog::makeSound() const {
	std::cout << "Woof" << std::endl;
}