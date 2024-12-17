/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:30:49 by adherrer          #+#    #+#             */
/*   Updated: 2024/12/17 20:00:56 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

template < typename T, typename C>
void iter(T *address, size_t length, void (*f)(C&)) {
	size_t i = -1;

	if (!address)
		return ;
	while ( ++i < length)
		f(address[i]);
}

#endif