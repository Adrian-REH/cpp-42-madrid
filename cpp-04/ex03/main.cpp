/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:30:28 by adherrer          #+#    #+#             */
/*   Updated: 2024/11/01 20:20:43 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "character/infra/Character.hpp"
#include "materiaSource/infra/MateriaSource.hpp"
#include "materia/domain/Ice.hpp"
#include "materia/domain/Cure.hpp"
#include "materia/domain/Fire.hpp"
#include "materia/domain/Hold.hpp"
#include "materia/domain/Electric.hpp"

#include <iostream>
int main()
{
	std::cout << "----------------------[CREATE SOURCE]-----------------" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Hold());
	src->learnMateria(new Fire());
	src->learnMateria(new Electric());
	std::cout << "----------------------[CREATE CHARACTERS]-----------------" << std::endl;
	ICharacter* me = new Character("Me");
 	ICharacter* bob = new Character("Bob");
 	ICharacter* zomb = new Character("Zombie");
	me->equip(src->createMateria("ice"));
 	me->equip(src->createMateria("cure"));
 	bob->equip(src->createMateria("fire"));
 	me->equip(src->createMateria("electric"));
 	me->equip(src->createMateria("electric"));
	me->unequip(0);
 	me->equip(src->createMateria("hold"));
	zomb->equip(new Electric());
	std::cout << "----------------------[ACTION]-----------------" << std::endl;
	zomb->use(0, *bob);
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
 	bob->use(0, *zomb);
 	bob->use(0, *zomb);
	std::cout << "----------------------[DELETE]-----------------" << std::endl;
	delete zomb;
	delete bob;
	delete me;
	delete src;
	return 0;
}