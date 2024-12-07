/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:54:59 by adherrer          #+#    #+#             */
/*   Updated: 2024/12/07 10:29:41 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../intf/Dog.hpp"
#include "../intf/Brain.hpp"

Dog::Dog() : Animal("Dog"), _brain(new Brain()) {
	std::cout << "[Created] Dog"<< std::endl;
}

Dog::Dog(Brain *brain) : Animal("Dog"), _brain(brain) {
	std::cout << "[Created] Dog, Added Brain"<< std::endl;
}

Dog::~Dog() {
	std::cout << "[Destroyed] Dog"<< std::endl;
	delete _brain;
}
Dog::Dog(const Dog & dog) : Animal("Dog") , _brain(new Brain(*dog._brain)){
	std::cout << "[Copy] Dog"<< std::endl;
}
Dog& Dog::operator=(const Dog& dog) {
	std::cout << "Dog Assignation operator called" << std::endl;
	if (this != &dog){
		this->_type = dog.getType();
		*this->_brain = *dog._brain;
	}
	return *this;
}
void Dog::createIdeas() {
	const std::string vals[10] = {
		"El mundo es mi parque, y la cama de mi dueño mi guarida",
		"Soy un experto en las siestas, pero siempre listo para correr tras una pelota",
		"Cuando me miras, sabes que soy el mejor amigo del hombre, y de su corazón.",
		"Lealtad y alegría son mi mantra; el caos es solo para los gatos",
		"No soy un perro, soy una máquina de amor con patas",
		"El sol es mi compañero favorito, pero tu sofá es mi lugar sagrado",
		"No me ignores, solo estoy aquí para ladrar amor desde mi ángulo perfecto",
		"¿Guau? Mejor, ¡¡GUAAAAAU!!",
		"No necesito muchas cosas, solo comida, juegos y una buena caminata",
		"Tengo una vida, pero no quiero perderla sin una buena bola para morder"
		};
	for (int i = 0; i < 100; i++)
		_brain->setIdea(i, vals[std::rand()%10]);
}
std::string Dog::getType() const {
	return (_type);
}

void Dog::makeSound() const {
	_brain->getIdeas();
	std::cout << "Woof" << std::endl;
}
