/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:52:01 by vvaudain          #+#    #+#             */
/*   Updated: 2024/06/03 15:40:01 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	Zombie* 	horde;
	int			N = 5;
	std::string	name = "crackos";

	horde = zombieHorde(N, name);
	horde->announce(); //should display the name of the first element of horde
	for (int i = 0; i < N; i++) {
		horde[i].announce();
	}
	delete[] horde;
	return 0;
}