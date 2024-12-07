/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StrToLower.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:55:43 by adherrer          #+#    #+#             */
/*   Updated: 2024/12/07 14:55:19 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/StrToLower.hpp"

std::string strToLower(std::string src)
{
	for (size_t i = 0 ; i < src.size() ; ++i)
		src[i] = std::tolower(src[i]);
	return src;
}