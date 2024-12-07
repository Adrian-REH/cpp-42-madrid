/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:53:32 by adherrer          #+#    #+#             */
/*   Updated: 2024/11/26 19:08:02 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../intf/Cat.hpp"

Cat::Cat() : Animal("Cat"), _brain(new Brain()) {
	std::cout << "[Created] Cat"<< std::endl;
}
Cat::Cat(Brain *brain) : Animal("Cat"), _brain(brain) {
	std::cout << "[Created] Cat, Added Brain"<< std::endl;
}
Cat::~Cat(){
	delete _brain;
	std::cout << "[Destroyed] Cat"<< std::endl;
}

std::string Cat::getType() const{
	return (_type);
}

void Cat::makeSound() const {
	std::cout << "Miau" << std::endl;
}

void Cat::createIdeas() {
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
Cat::Cat(const Cat & cat) : Animal("Cat") , _brain(new Brain(*cat._brain)){
	std::cout << "[Copy] Cat"<< std::endl;
}

Cat& Cat::operator=(const Cat& cat) {
	std::cout << "Cat Assignation operator called" << std::endl;
	if (this != &cat){
		this->_type = cat.getType();
		*this->_brain = *cat._brain;
	}
	return *this;
}
