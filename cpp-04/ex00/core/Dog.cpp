
#include "../interface/Dog.hpp"

Dog::Dog() : Animal("Dog") {}

Dog::~Dog(){

}

std::string Dog::getType() const {
	return (_type);
}
void Dog::makeSound() const {
	std::cout << "Woof" << std::endl;
}