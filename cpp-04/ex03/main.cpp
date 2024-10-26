/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:30:28 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/25 19:22:51 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Fire.hpp"
#include "Hold.hpp"
#include "Electric.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Hold());
	src->learnMateria(new Fire());
	src->learnMateria(new Electric());
	ICharacter* me = new Character("me");
	me->equip(src->createMateria("ice"));
 	me->equip(src->createMateria("cure"));
 	me->equip(src->createMateria("hold"));
 	me->equip(src->createMateria("fire"));
 	me->equip(src->createMateria("electric"));
	me->unequip(0);
 	me->equip(src->createMateria("cure"));
 	ICharacter* bob = new Character("bob");
 	ICharacter* zomb = new Character("Zombie");
	me->use(1, *bob);
	me->use(2, *bob);
 	me->use(3, *zomb);
	delete zomb;
	delete bob;
	delete me;
	delete src;
	return 0;
}