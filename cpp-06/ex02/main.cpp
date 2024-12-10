/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:22:54 by adherrer          #+#    #+#             */
/*   Updated: 2024/12/07 21:31:42 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <memory>
#include <stdlib.h>
#include <stdexcept>
#include <iostream>

static	size_t	randNumber()
{
	srand(time(0));
	return ((rand() % 3) );
}

template <typename T>
Base* newClass() {
	return new T();
}

Base* randomClass(int index) {
    typedef Base* (*Creator)();
	Creator creators[] = {
		&newClass<A>,
		&newClass<B>,
		&newClass<C>
	};
	return creators[index]();
}

void identify(Base *p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << "A\n";
	} else if (dynamic_cast<B*>(p)) {
		std::cout << "B\n";
	} else if (dynamic_cast<C*>(p)) {
		std::cout << "C\n";
	} else {
		std::cout << "Unknown type\n";
	}
}

void identify(Base &p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A\n";
	} catch (...) {
		try {
			(void)dynamic_cast<B&>(p);
			std::cout << "B\n";
		} catch (...) {
			try {
				(void)dynamic_cast<C&>(p);
				std::cout << "C\n";
			} catch (...) {
				std::cout << "Unknown type\n";
			}
		}
	}
}

int main() {
	size_t valor = randNumber();
	std::cout << "pos:\t"  <<  valor << std::endl;
	Base *rand1 = randomClass(valor);
	std::cout << "class:\t";
	identify(rand1);


	valor = randNumber();
	std::cout << "pos:\t"  <<  valor << std::endl;
	Base *rand2 = randomClass(valor);
	std::cout << "class:\t";
	identify(*rand2);



	valor = randNumber();
	std::cout << "pos:\t"  <<  valor << std::endl;
	Base *rand3 = randomClass(valor);
	std::cout << "class:\t";
	identify(rand3);


	delete rand1;
	delete rand2;
	delete rand3;

}
