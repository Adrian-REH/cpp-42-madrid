/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:32:20 by adherrer          #+#    #+#             */
/*   Updated: 2024/12/11 17:25:32 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <climits>
#include <limits>
#include <algorithm>

Span::Span():
_store(0),
_n_max(0),
_len_stored(0),
_val_min(INT_MAX),
_val_max(INT_MIN) {
	std::cout << "[Build] Span class" << std::endl;
}
 
Span::~Span() {
	std::cout << "[Destroyed] Span class" << std::endl;
}

Span::Span(unsigned int n): 
_store(0),
_n_max(n),
_len_stored(0),
_val_min(INT_MAX),
_val_max(INT_MIN) {
	std::cout << "[Build] Span class" << std::endl;
	
}

Span::Span(Span const & src): 
_store(src._store),
_n_max(src._n_max),
_len_stored(src._len_stored),
_val_min(src.getValMin()),
_val_max(src.getValMax()) {
std::cout << "[Copy] Constructor called " << std::endl;
}

Span &Span::operator=(Span const & src) {
	if ( this == &src)
		return *this;
	this->_store = src._store;
	this->_n_max = src._n_max;
	this->_len_stored = src._len_stored;
	this->_val_min = src._val_min;
	this->_val_max = src._val_max;
	return *this;
}

int Span::getValMin() const{
	return _val_min;
}

int Span::getValMax() const{
	return _val_max;
}


void Span::addNumber(int num) {
	if (_len_stored >= _n_max)
		throw std::invalid_argument("Max args");
	_store.push_back(num);
	_len_stored = _store.size();
	if (num < _val_min)
		_val_min = num;
	if (num > _val_max)
		_val_max = num;
}


int Span::shortestSpan() {
	if (_n_max == 0 || _n_max == 1)
		throw std::invalid_argument("Error: There are not enough numbers");
	std::vector<int> sorted_store = _store;
	std::sort(sorted_store.begin(), sorted_store.end());

	int shortest = std::numeric_limits<int>::max();
	for (size_t i = 0; i < sorted_store.size() - 1; ++i) {
		int diff = sorted_store[i + 1] - sorted_store[i];
		if (diff < shortest)
			shortest = diff;
	}
	return shortest;
}

int Span::longestSpan() {
	if (_n_max == 0 || _n_max == 1)
		throw std::invalid_argument("Error: There are not enough numbers");

	return _val_max - _val_min;
}
