#include "Cure.hpp"
#include <iostream>

Cure::Cure(): AMateria("cure") {
	std::cout << "create Materia Cure" << std::endl;

};

Cure::~Cure() {}

AMateria* Cure::clone() const {
	AMateria *nCure = new Cure();
	return nCure;
}
