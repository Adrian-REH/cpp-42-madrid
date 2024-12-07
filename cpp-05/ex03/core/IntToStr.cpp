/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IntToStr.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:43:02 by adherrer          #+#    #+#             */
/*   Updated: 2024/12/07 12:32:02 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/IntToStr.hpp"

std::string intToStr(int val)
{
	std::stringstream ss;
	ss << val;
	return ss.str();
}
