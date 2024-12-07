/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:54:54 by adherrer          #+#    #+#             */
/*   Updated: 2024/11/26 19:08:17 by adherrer         ###   ########.fr       */
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
	std::cout << "[Destroyed] Cat"<< std::endl;
	delete _brain;
}

std::string Cat::getType() const{
	return (_type);
}

void Cat::makeSound() const {
	std::cout << "Miau" << std::endl;
}

void Cat::createIdeas() {

	const std::string vals[10] = {
		"El mundo es mi reino, y el sofá mi trono",
		"Soy un experto en la siesta, la caza es solo un hobby",
		"Cuando me miras, sabes que soy dueño de tu corazón.",
		"Silencio y sigilo son mi mantra; el caos es solo para los perros",
		"No soy un gato, soy una máquina de ternura con patas",
		"El sol es mi compañero favorito, pero tu regazo es mi lugar sagrado",
		"No me ignores, solo estoy aquí para observarte desde mi ángulo perfecto",
		"¿Miau? Mejor, ¡¡meow!!",
		"No necesito muchas cosas, solo comida, caricias y un buen lugar para dormir",
		"Tengo nueve vidas, pero no quiero gastar ninguna en trabajar"
		};
	for (int i = 0; i < 100; i++)
		_brain->setIdea(i, vals[(int)std::rand()%10]);
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
