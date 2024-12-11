/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.tpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:53:13 by adherrer          #+#    #+#             */
/*   Updated: 2024/12/11 16:36:49 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REALLOC_TPP
#define REALLOC_TPP
#include "realloc.hpp"

template <typename T>
T* realloc(T*data, int size) {
	if (!size)
		return new T[size + 1];
	T	*tmp = new T[size];
	for (int i = 0; i < size - 1 ; i++)
		tmp[i] = data[i];
	return tmp;
}
#endif