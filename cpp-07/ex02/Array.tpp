/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 23:29:16 by adherrer          #+#    #+#             */
/*   Updated: 2024/12/11 01:42:22 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP
#include "Array.hpp"

template <typename T>
Array<T>::Array(): _array(NULL), _length(0){
	std::cout << "[Build] Array class build" << std::endl;
}

template <typename T>
Array<T>::~Array() {
	std::cout << "[Destroyed] Array class build" << std::endl;
	if (this->_array)
		delete[] _array;
}

template <typename T>
Array<T>::Array(unsigned int n) : _length(n) {
	std::cout << "[Build] Array class build: "<< n << std::endl;
	if (n >= 0)
		this->_array = new T[n]();
	return;
}

template <typename T>
Array<T>::Array(const Array& src) {
	std::cout << "[Copy Build] Array class build" << std::endl;
	*this = src;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T>& src) {
	std::cout << "" << std::endl;
	if (this == &src)
		return *this;

	if (this->_array)
		delete[] _array;
	if (_length > 0)
	{
		this->_array = new T[this.size()];
		for (unsigned int i = 0; i < _length; i++) {
			this->_array[i] = _array[i];
		}
		this->_length = _length;
	}
	return *this;
}

template <typename T>
const T &Array<T>::operator[](unsigned int idx) const{
	if (idx < _length)
		return this->_array[idx];
	else
		throw std::out_of_range("Index is out of bounds");
}

template <typename T>
 T &Array<T>::operator[](unsigned int idx) {
	if (idx < _length)
		return this->_array[idx];
	else
		throw std::out_of_range("Index is out of bounds");
}

template <typename T>
unsigned int Array<T>::size(void) const{
	return _length;
}

#endif