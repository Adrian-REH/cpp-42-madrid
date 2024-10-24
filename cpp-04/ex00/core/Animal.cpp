
#include "../interface/Animal.hpp"

Animal::Animal(std::string type) : _type(type) {}
Animal::Animal() : _type("") {}
Animal::~Animal(){}

std::string Animal::getType() const {
	return _type;
}

void Animal::makeSound() const {
	std::cout << "" << std::endl;
}