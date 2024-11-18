/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:55:03 by adherrer          #+#    #+#             */
/*   Updated: 2024/11/18 18:54:15 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <string>
#include <iostream>

class Animal {
	protected:
		std::string _type;
	public:
		virtual ~Animal() = 0;
		virtual std::string getType() const = 0;
		Animal& operator=(const Animal& fixed);
		virtual void makeSound() const = 0;
};

#endif