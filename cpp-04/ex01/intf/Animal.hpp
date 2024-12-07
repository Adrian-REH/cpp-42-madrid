/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:53:39 by adherrer          #+#    #+#             */
/*   Updated: 2024/11/26 09:11:39 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <string>
#include <iostream>
#include <cstdlib>

class Animal {
	protected:
		std::string _type;
	public:
		Animal(std::string);
		Animal();
		Animal(const Animal& animal);
		Animal& operator=(const Animal& animal);
		virtual ~Animal();
		virtual std::string getType() const;
		virtual void makeSound() const;
};

#endif