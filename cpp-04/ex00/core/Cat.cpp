/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:53:00 by adherrer          #+#    #+#             */
/*   Updated: 2024/11/18 13:51:28 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../intf/Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "[Created] Cat"<< std::endl;
}

Cat::~Cat(){
	std::cout << "[Destroyed] Cat"<< std::endl;
}

Cat::Cat(const Cat& cat) : Animal() {
	std::cout << "[Copy] Cat"<< std::endl;
	*this = cat;
}

std::string Cat::getType()  const {
	return (_type);
}

void Cat::makeSound() const {
	std::cout << "Miau" << std::endl;
}


Cat& Cat::operator=(const Cat& cat){
	std::cout << "Cat Assignation operator called" << std::endl;
	if (this != &cat){
		this->_type = cat._type;
	}
	return *this;
}