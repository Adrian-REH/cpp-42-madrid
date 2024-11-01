/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:52:38 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/31 20:41:19 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intf/Animal.hpp"
#include "intf/Cat.hpp"
#include "intf/Dog.hpp"

int main()
{
	const Animal *meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); 
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;
	return 0;
}