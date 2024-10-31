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

Dog::Dog() : Animal("Dog") {}

Dog::~Dog(){

}

std::string Dog::getType() const {
	return (_type);
}
void Dog::makeSound() const {
	std::cout << "Woof" << std::endl;
}