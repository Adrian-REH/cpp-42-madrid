/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:30:28 by adherrer          #+#    #+#             */
/*   Updated: 2024/11/01 17:20:18 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "character/infra/Character.hpp"
#include "materiaSource/infra/MateriaSource.hpp"
#include "materia/domain/Ice.hpp"
#include "materia/domain/Cure.hpp"
#include "materia/domain/Fire.hpp"
#include "materia/domain/Hold.hpp"
#include "materia/domain/Electric.hpp"

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
 	me->equip(src->createMateria("cure"));
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