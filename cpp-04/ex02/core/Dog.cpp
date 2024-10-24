
#include "../interface/Dog.hpp"
#include "../interface/Brain.hpp"

Dog::Dog() : Animal("Dog"), _brain(new Brain()) {
	std::cout << "[Created] Dog"<< std::endl;
}

Dog::Dog(Brain *brain) : Animal("Dog"), _brain(brain) {
	std::cout << "[Created] Dog, Added Brain"<< std::endl;
}

Dog::~Dog(){
	delete _brain;
	std::cout << "[Destroyed] Dog"<< std::endl;
}

std::string Dog::getType() const {
	return (_type);
}
void Dog::makeSound() const {
	std::cout << "Woof" << std::endl;
}