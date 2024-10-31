/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:54:54 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/31 20:01:11 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../intf/Cat.hpp"

Cat::Cat() : Animal("Cat"), _brain(new Brain()) {
	std::cout << "[Created] Cat"<< std::endl;
}
Cat::Cat(Brain *brain) : Animal("Cat"), _brain(brain) {
	std::cout << "[Created] Cat, Added Brain"<< std::endl;
}
Cat::~Cat(){
	delete _brain;
	std::cout << "[Destroyed] Cat"<< std::endl;
}

std::string Cat::getType() const{
	return (_type);
}

void Cat::makeSound() const {
	std::cout << "Miau" << std::endl;
}
