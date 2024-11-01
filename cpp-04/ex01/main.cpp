/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:53:54 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/31 20:52:46 by adherrer         ###   ########.fr       */
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
	return 0;
}