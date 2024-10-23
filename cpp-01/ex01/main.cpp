/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 01:58:08 by adherrer          #+#    #+#             */
/*   Updated: 2024/10/23 01:58:09 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.cpp"

int main()
{
	int N = 5;
	Zombie *horde = zombieHorde(N, "WordMy");

	for (int i = 0; i < N; ++i)
		horde[i].announce();
	
	delete[] horde;
}