/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 23:29:16 by adherrer          #+#    #+#             */
/*   Updated: 2024/12/11 01:04:29 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP
template <class T>
Array<T>::Array() {
	std::cout << "[Build] Array class build" << std::endl;
}

template <class T>
Array<T>::~Array() {
	std::cout << "[Destroyed] Array class build" << std::endl;
}

template <class T>
Array<T>::Array(unsigned int n) {
	std::cout << "[Build] Array class build: "<< n << std::endl;
	if (n > 0)
		_array = new T[n];
}

template <class T>
Array<T>::Array(const Array& src) {
	std::cout << "[Copy Build] Array class build" << std::endl;
	*this = src;
}

template <class T>
Array<T> &Array<T>::operator=(const Array<T>& src) {
	std::cout << "" << std::endl;
	if (this == &src)
		return *this;
	for (int i = 0; i < _length; i++) {
		this->_array[i] = _array[i];
	}
	this->_length = _length;
	return *this;
}

template <class T>
const T &Array<T>::operator[](unsigned int idx) const{
	if (idx <= _length)
		return _array[idx];
	else
		throw std::out_of_range("Index is out of bounds");
	return NULL;
}

template <class T>
unsigned int Array<T>::size(void) const{
	return _length;
}

#endif