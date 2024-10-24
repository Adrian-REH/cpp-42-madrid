#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	private:
		Brain *_brain;
	public:
		Cat();
		Cat(Brain *brain);
		~Cat();
		std::string getType() const;
		void makeSound() const;
};

#endif