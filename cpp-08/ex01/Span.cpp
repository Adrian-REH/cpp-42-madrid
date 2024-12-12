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

Span::Span(unsigned int src): 
_store(0),
_n_max(src),
_len_stored(0),
_val_min(INT_MAX),
_val_max(INT_MIN) {
	std::cout << "[Build] Span class" << std::endl;
	
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
	return _val_max - _val_min;
}
