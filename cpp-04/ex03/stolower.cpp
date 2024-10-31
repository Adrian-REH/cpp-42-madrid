/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stolower.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:55:43 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/31 19:55:44 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stolower.hpp"

std::string stolower(std::string src)
{
	for (size_t i = 0 ; i < src.size() ; ++i)
		src[i] = std::tolower(src[i]);
	return src;
}