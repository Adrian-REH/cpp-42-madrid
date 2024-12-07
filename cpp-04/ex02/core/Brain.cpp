/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:54:50 by adherrer          #+#    #+#             */
/*   Updated: 2024/11/26 19:09:40 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../intf/Brain.hpp"
#include <iostream>

Brain::Brain() {
	std::cout << "[Created] Brain"<< std::endl;
}

Brain::~Brain() {
	std::cout << "[Destroyed] Brain"<< std::endl;
}

Brain::Brain(const Brain& brain) {
	std::cout << "[Copy] Brain"<< std::endl;
	*this = brain;
}

Brain& Brain::operator=(const Brain& brain) {
	std::cout << "Brain Assignation operator called" << std::endl;
	if (this == &brain)
		return *this;
	for (int i = 0; i < 100; i++)
	{
		if (brain._ideas[i].length() > 0)
			this->_ideas[i].assign(brain._ideas[i]);
	}
	return *this;
}

void Brain::display() {
	for (int i = 0; i < 100; i++)
		std::cout << _ideas[i] << std::endl;
}

void Brain::setIdea(int idx, std::string idea) {
	if (idx > 100)
	{
		std::cout << "No se encontro la idea" << std::endl;
		return ;
	}
	_ideas[idx].assign(idea);
}

std::string Brain::getIdea(int idx) {
	if (idx > 100)
	{
		std::cout << "No se encontro la idea" << std::endl;
		return NULL;
	}
	return _ideas[idx];
}


void Brain::getIdeas() {
	for (int i = 0; i < 3 ; i++)
		std::cout << _ideas[i] << std::endl;
	return ;
}


Brain *Brain::clone() {
	Brain *brain = new Brain();
	for (int i = 0; i < 100; i++)
		brain->setIdea(i, getIdea(i));
	return brain;
}