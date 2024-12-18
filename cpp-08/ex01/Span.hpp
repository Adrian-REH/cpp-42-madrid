/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:27:45 by adherrer          #+#    #+#             */
/*   Updated: 2024/12/18 15:18:20 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP
#include <stdexcept>
#include <iostream>
#include <vector>

class Span {
	private:
		std::vector<int>	_store;
		unsigned int	_n_max;
		unsigned int	_len_stored;
		int				_val_min;
		int				_val_max;
	public:
		Span();
		~Span();
		Span(unsigned int);
		Span(Span const &);
		Span &operator=(Span const &);
		void addNumber(int);
		int shortestSpan();
		int longestSpan();
		int &operator[](unsigned int i);
		int	getValMin() const;
		int	getValMax() const;
		std::vector<int>::iterator begin();
		std::vector<int>::iterator end();
		template <typename InputIterator>
		void addRange(InputIterator begin, InputIterator end) {
			for (InputIterator it = begin; it != end; ++it) {
				if (_len_stored >= _n_max)
					throw std::overflow_error("Error: Span is full");
				_store.push_back(*it);
				_len_stored++;
				if (_len_stored == 1) {
					_val_min = *it;
					_val_max = *it;
				} else {
					_val_min = std::min(_val_min, *it);
					_val_max = std::max(_val_max, *it);
				}
			}
		}
};

#endif