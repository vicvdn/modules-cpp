/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:00:36 by vvaudain          #+#    #+#             */
/*   Updated: 2024/07/11 18:01:39 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void) {

	DiamondTrap	playerdiamond("Diamond");
	DiamondTrap	playerdiamond2;
	DiamondTrap	playerdiamondcopy(playerdiamond);

	std::cout << playerdiamond << "\n" << playerdiamond2 << "\n" << playerdiamondcopy << std::endl;
	std::cout << BOLDYELLOW << "ClapTrap attacks ScavTrap" << RESET << std::endl;
	for (int i = 0; i < 4; i++) {
		playerdiamond.attack("player2");
		playerdiamond2.takeDamage(playerdiamond.getAttackDamage());
		if (i % 2 == 0)
			playerdiamond2.beRepaired(playerdiamond2.getEnergyPoints());
	}
	playerdiamond.WhoAmI();
	return 0;
}