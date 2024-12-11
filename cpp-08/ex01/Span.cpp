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
#include <algorithm>
//Constructors
Span::Span():
_store(NULL),
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
_store(NULL),
_n_max(src),
_len_stored(0),
_val_min(0),
_val_max(0) {
	std::cout << "[Build] Span class" << std::endl;
	
}

void Span::addNumber(int num) {
	if (num >= _n_max)
		throw std::invalid_argument("");
	_store.push_back(num);
	_len_stored = _store.size();
	if (num < _val_min)
		_val_min = num;
	if (num > _val_max)
		_val_max = num;
}

template <typename T>
int distBetween(T store, int v1, int v2) {
	typename T::iterator it1 = std::find(store.begin(), store.end(), v1);
	if (it1 == store.end())
		throw std::invalid_argument("Val not found"+ v1);
	typename T::iterator it2 = std::find(store.begin(), store.end(), v2);
	if (it2 == store.end())
		throw std::invalid_argument("Val not found" + v2);
	return std::abs(std::distance(it1, it2));
}

int Span::shortestSpan() {
}

int Span::longestSPan() {
	return _val_max - _val_min;
}
