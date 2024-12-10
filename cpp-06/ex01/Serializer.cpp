#include "Serializer.hpp"


template <typename T>
Serializer<T>::Serializer() {}

template <typename T>
uintptr_t Serializer<T>::serialize(T* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

template <typename T>
T *Serializer<T>::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}