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

Animal::Animal(std::string type) : _type(type) {}
Animal::Animal() : _type("") {}
Animal::~Animal(){}

std::string Animal::getType() const {
	return _type;
}

void Animal::makeSound() const {
	std::cout << "" << std::endl;
}