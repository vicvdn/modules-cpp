/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:00:36 by vvaudain          #+#    #+#             */
/*   Updated: 2024/07/12 13:43:00 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void) {

	ClapTrap	player("FIGHTER");
	ScavTrap	other("SV FIGHTER");
	FragTrap	other2("FG FIGHTER");

	std::cout << BOLDYELLOW << "ClapTrap attacks ScavTrap" << RESET << std::endl;
	for (int i = 0; i < 4; i++) {
		player.attack("VICTIM");
		other.takeDamage(player.getAttackDamage());
		if (i % 2 == 0)
			other.beRepaired(10);
	}
	std::cout << BOLDYELLOW << "ClapTrap attacks FragTrap" << RESET << std::endl;
	for (int i = 0; i < 4; i++) {
		player.attack("SV OPPONENT");
		other2.takeDamage(player.getAttackDamage());
		if (i % 2 == 0)
			other2.beRepaired(5);
	}
	std::cout << BOLDYELLOW << "ScavTrap attacks FragTrap" << RESET << std::endl;
	for (int i = 0; i < 4; i++) {
		other.attack("SV OPPONENT");
		other2.takeDamage(other.getAttackDamage());
		if (i % 2 == 0)
			other2.beRepaired(5);
	}
	std::cout << BOLDYELLOW << "FragTrap attacks ScavTrap" << RESET << std::endl;
	for (int i = 0; i < 4; i++) {
		other2.attack("VICTIM");
		other.takeDamage(other.getAttackDamage());
		if (i % 2 == 0)
			other.beRepaired(10);
	}
	other.guardGate();
	return 0;
}