#ifndef EASYFIND_TPP
#define EASYFIND_TPP
#include "easyfind.hpp"


template <typename T>
int easyfind(T &conteiner, int target) {
	typename T::iterator result = std::find(conteiner.begin(), conteiner.end(), target);
	if (*result)
		return *result;
	else
		throw std::invalid_argument("Not found");
}


#endif