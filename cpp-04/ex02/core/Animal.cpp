/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:53:17 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/31 20:00:02 by adherrer         ###   ########.fr       */
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

