#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <string>
#include <iostream>

class Animal {
	protected:
		std::string _type;
	public:
		Animal(std::string);
		Animal();
		virtual ~Animal();
		virtual std::string getType() const;
		virtual void makeSound() const;
};

#endif