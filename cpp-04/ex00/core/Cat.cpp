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

Cat::Cat() : Animal("Cat") {}

Cat::~Cat(){

}

std::string Cat::getType()  const {
	return (_type);
}

void Cat::makeSound() const {
	std::cout << "Miau" << std::endl;
}
