
#include "../interface/Animal.hpp"

Animal::Animal(std::string type) : _type(type) {
	std::cout << "[Created] Animal, added Type: "<< type << std::endl;
}
Animal::Animal() : _type("") {
	std::cout << "[Created] Animal" << std::endl;
}
Animal::~Animal(){
	std::cout << "[Destroyed] Animal" << std::endl;
}

std::string Animal::getType() const {
	return _type;
}

void Animal::makeSound() const {
	std::cout << "" << std::endl;
}