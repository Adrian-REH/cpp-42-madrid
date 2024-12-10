#include "Base.hpp"
#include <iostream>

Base::~Base() {
	std::cout << "[Destructor] Base class "<< std::endl;
}