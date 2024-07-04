/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:00:36 by vvaudain          #+#    #+#             */
/*   Updated: 2024/07/04 14:46:24 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void) {
{
	ClapTrap* ptr = new ScavTrap("LOL");
	delete ptr;
}
std::cout << "----------------------------------------------" << std::endl;
{
	ClapTrap player("FIGHTER", 10, 10, 0);
	ClapTrap player2("VICTIM", 10, 10, 0);
	ScavTrap other("SV FIGHTER");
	ScavTrap copy_other2(other);

	std::cout << BOLDYELLOW << "ClapTrap attacks ClapTrap" << RESET << std::endl;
	for (int i = 0; i < 4; i++) {
		player.attack("VICTIM");
		player2.takeDamage(player.getAttackDamage());
		if (i % 2 == 0)
			player2.beRepaired(player2.getEnergyPoints());
	}
	std::cout << BOLDYELLOW << "ScavTrap attacks ScavTrap" << RESET << std::endl;
	for (int i = 0; i < 4; i++) {
		other.attack("SV OPPONENT");
		copy_other2.takeDamage(other.getAttackDamage());
		if (i % 2 == 0)
			copy_other2.beRepaired(copy_other2.getEnergyPoints());
	}
	std::cout << BOLDYELLOW << "ClapTrap attacks ScavTrap" << RESET << std::endl;
	for (int i = 0; i < 4; i++) {
		player.attack("SV OPPONENT");
		copy_other2.takeDamage(player.getAttackDamage());
		if (i % 2 == 0)
			copy_other2.beRepaired(copy_other2.getEnergyPoints());
	}
	std::cout << BOLDYELLOW << "ScavTrap attacks ClapTrap" << RESET << std::endl;
	for (int i = 0; i < 4; i++) {
		other.attack("VICTIM");
		player2.takeDamage(other.getAttackDamage());
		if (i % 2 == 0)
			player2.beRepaired(player2.getEnergyPoints());
	}
	other.guardGate();
}

return 0;
}