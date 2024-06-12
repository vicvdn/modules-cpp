/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:00:36 by vvaudain          #+#    #+#             */
/*   Updated: 2024/06/12 15:23:12 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap player("FIGHTER");
	ClapTrap other("OPPONENT");

	for (int i = 0; i < 4; i++) {
		player.attack("OPPONENT");
		other.takeDamage(0);
		if (i % 2 == 0)
			other.beRepaired(10);
	}
	return 0;
}