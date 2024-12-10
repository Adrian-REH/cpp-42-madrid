#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <cstdint>
#include "Data.hpp"

template <typename T>
class Serializer {
	private:
		Serializer();
	public:
	
		static uintptr_t serialize(T* ptr);
		static T* deserialize(uintptr_t raw);
};

#endif