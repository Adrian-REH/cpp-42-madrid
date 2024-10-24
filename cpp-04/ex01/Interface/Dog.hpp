#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain *_brain;
	public:
		Dog();
		Dog(Brain *brain);
		~Dog();
		std::string getType() const;
		void makeSound() const;
};

#endif