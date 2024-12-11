/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:53:13 by adherrer          #+#    #+#             */
/*   Updated: 2024/12/11 16:37:14 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REALLOC_HPP
#define REALLOC_HPP

template <typename T>
T* realloc(T*data, int size);

#include "realloc.tpp"
#endif