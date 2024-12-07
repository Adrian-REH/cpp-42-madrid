/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:53:54 by adherrer          #+#    #+#             */
/*   Updated: 2024/11/26 09:10:40 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intf/Animal.hpp"
#include "intf/Cat.hpp"
#include "intf/Dog.hpp"

int main()
{
	Animal* meta[10];

	for (int i = 0; i < 5; i++)
		meta[i] = new Dog();
	for (int i = 5; i <= 10; i++)
		meta[i] = new Cat();

	for (int i = 0; i < 10; i++)
		meta[i]->makeSound();
	for (int i = 0; i < 11; i++)
		delete meta[i];
	//----------------------------------------------------
	std::cout << "--------------------------------" << std::endl;

	Dog* dogs[1];
	Cat* cats[1];
	for (int i = 0; i < 1; i++) {
		dogs[i] = new Dog();
		dogs[i]->createIdeas();
		cats[i] = new Cat();
		cats[i]->createIdeas();
	}
	std::cout << "Imprimo las ideas de 0" << std::endl;
	dogs[0]->makeSound();
	std::cout << std::endl;
	Dog dog;
	dog = *dogs[0];
	std::cout << std::endl;
	std::cout << "Imprimo la idea de la copia" << std::endl;
	dog.createIdeas();
	dog.makeSound();
	std::cout << std::endl;
	std::cout << "Imprio las idea de 0 y compruebo que no se cambio" << std::endl;
	dogs[0]->makeSound();
	std::cout << std::endl;
	std::cout << "Borro las creaciones" << std::endl;
	for (int i = 0; i < 1; i++) {
		delete cats[i];
		delete dogs[i];
	}
	std::cout << "Borro las copias" << std::endl;
	return 0;
}