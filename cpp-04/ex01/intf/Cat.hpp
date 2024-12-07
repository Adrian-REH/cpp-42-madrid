/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:53:45 by adherrer          #+#    #+#             */
/*   Updated: 2024/11/26 09:11:12 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	private:
		Brain *_brain;
	public:
		Cat();
		~Cat();
		Cat(Brain *);
		Cat(const Cat& cat);
		Cat& operator=(const Cat& cat);
		void createIdeas();
		std::string getType() const;
		void makeSound() const;
};

#endif