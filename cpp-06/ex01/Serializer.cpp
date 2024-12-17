#include "Serializer.hpp"
#include <iostream>

Serializer::Serializer() {
	std::cout << "[Build] constructor called" << std::endl;
}

Serializer::Serializer(const Serializer &src) {
	std::cout << "[Build] constructor called" << std::endl;
	*this = src;
}

Serializer::~Serializer() {
	std::cout << "[Destroyed] destructor called" << std::endl;

}

uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}

Serializer & Serializer::operator=(const Serializer &src) {
	std::cout << "Assignament called" << std::endl;
	return *this;
}
