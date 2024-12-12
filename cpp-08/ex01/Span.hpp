/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:27:45 by adherrer          #+#    #+#             */
/*   Updated: 2024/12/11 17:12:55 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP
#include "realloc.hpp"
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
		//Span(Span const &);
		//Span &operator=(Span const &);
		void addNumber(int);
		int shortestSpan();
		int longestSpan();
		int	getValMin() const;
		int	getValMax() const;
};

#endif