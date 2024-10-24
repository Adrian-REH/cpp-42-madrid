#include "interface/Animal.hpp"
#include "interface/Cat.hpp"
#include "interface/Dog.hpp"

int main()
{
	//Animal a = new Animal();

	Animal* meta[10];
	for (int i = 0; i < 5; i++)
		meta[i] = new Dog();
	for (int i = 5; i <= 10; i++)
		meta[i] = new Cat();

	for (int i = 0; i < 10; i++)
		meta[i]->makeSound();

	for (int i = 0; i < 11; i++)
		delete meta[i];
	return 0;
}