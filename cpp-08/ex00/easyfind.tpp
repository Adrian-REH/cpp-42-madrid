#ifndef EASYFIND_TPP
#define EASYFIND_TPP
#include "easyfind.hpp"

template <typename T>
int easyfind(T &conteiner, int target) {
	if (conteiner.size() < 1)
		throw std::invalid_argument("Error: No arguments");
	typename T::iterator result = std::find(conteiner.begin(), conteiner.end(), target);
	if (*result)
		return *result;
	else
		throw std::invalid_argument("Error: Not found");
}


#endif