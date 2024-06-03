/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:57:53 by vvaudain          #+#    #+#             */
/*   Updated: 2024/06/03 16:05:44 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream>

Zombie*	zombieHorde( int N, std::string name){
	Zombie*	horde = new Zombie[N];
	
	for (int i = 0; i < N; i++) {
		std::stringstream insert;
		insert << i;
		horde[i] = Zombie(name + " " + insert.str());
	}
	return (horde);
}