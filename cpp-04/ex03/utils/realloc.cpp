/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:53:13 by adherrer          #+#    #+#             */
/*   Updated: 2024/11/01 17:19:05 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


template <typename T>
T** realloc_materia(T**data, int size) {
	if (!size)
		return new T*[size + 1];
	T	**tmp = new T*[size];

	for (int i = 0; i < size - 1 ; i++)
		tmp[i] = data[i];
	delete [] data;
	return tmp;
}
