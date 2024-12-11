/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:30:49 by adherrer          #+#    #+#             */
/*   Updated: 2024/12/11 02:04:29 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>

template <typename T>
class Array {
	private:
		T				*_array;
		unsigned int	_length;
	public:
		Array();
		~Array();
		Array(unsigned int n);
		Array(const Array&);
		Array &operator=(const Array&);
		T &operator[](unsigned int idx);
		const T &operator[](unsigned int idx) const;
		unsigned int size(void) const;

};
# include "Array.tpp"
#endif