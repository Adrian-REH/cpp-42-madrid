#include "MutantStack.hpp"

template <typename T, typename Container >
MutantStack<T, Container>::MutantStack() : std::stack<T>() {
	std::cout << "[Build] MutantStack class" << std::endl;
}

template <typename T, typename Container >
MutantStack<T, Container>::MutantStack(T src) : std::stack<T>(src) {
	std::cout << "[Build] MutantStack class" << std::endl;
}

template <typename T, typename Container >
MutantStack<T, Container>::~MutantStack() {
	std::cout << "[Destroyed] MutantStack class" << std::endl;
}

template <typename T, typename Container >
MutantStack<T, Container>::MutantStack(MutantStack<T, Container> const &other) : std::stack<T>(other) {
	std::cout << "[Copy] MutantStack class" << std::endl;
}

template <typename T, typename Container >
MutantStack<T, Container> & MutantStack<T, Container>::operator=(MutantStack<T, Container> const &other) {
	std::cout << "[Assignment] MutantStack class" << std::endl;

	if (this != &other) {
		std::stack<T>::operator=(other);
	}
	return *this;
}

template <typename T, typename Container >
MutantStack<T, Container>::iterator MutantStack<T, Container>::begin() {
	return this->c.begin();
}

template <typename T, typename Container >
MutantStack<T, Container>::iterator MutantStack<T, Container>::end() {
	return this->c.end();
}

template <typename T, typename Container >
MutantStack<T, Container>::const_iterator MutantStack<T, Container>::begin() const {
	return this->c.begin();
}

template <typename T, typename Container >
MutantStack<T, Container>::const_iterator MutantStack<T, Container>::end() const {
	return this->c.end();
}