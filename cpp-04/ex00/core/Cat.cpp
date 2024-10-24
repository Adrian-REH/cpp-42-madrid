
#include "../interface/Cat.hpp"

Cat::Cat() : Animal("Cat") {}

Cat::~Cat(){

}

std::string Cat::getType() const{
	return (_type);
}

void Cat::makeSound() const {
	std::cout << "Miau" << std::endl;
}
