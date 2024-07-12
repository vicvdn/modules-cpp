/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:00:36 by vvaudain          #+#    #+#             */
/*   Updated: 2024/07/12 13:33:18 by vvaudain         ###   ########.fr       */
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
	ClapTrap player("FIGHTER");
	ClapTrap player2("VICTIM");
	ScavTrap other("SV FIGHTER");
	ScavTrap copy_other2(other);

	std::cout << BOLDYELLOW << "ClapTrap attacks ClapTrap" << RESET << std::endl;
	for (int i = 0; i < 4; i++) {
		player.attack("VICTIM");
		player2.takeDamage(player.getAttackDamage());
		if (i % 2 == 0)
			player2.beRepaired(5);
	}
	std::cout << BOLDYELLOW << "ScavTrap attacks ScavTrap" << RESET << std::endl;
	for (int i = 0; i < 4; i++) {
		other.attack("SV OPPONENT");
		copy_other2.takeDamage(other.getAttackDamage());
		if (i % 2 == 0)
			copy_other2.beRepaired(10);
	}
	std::cout << BOLDYELLOW << "ClapTrap attacks ScavTrap" << RESET << std::endl;
	for (int i = 0; i < 4; i++) {
		player.attack("SV OPPONENT");
		copy_other2.takeDamage(player.getAttackDamage());
		if (i % 2 == 0)
			copy_other2.beRepaired(10);
	}
	std::cout << BOLDYELLOW << "ScavTrap attacks ClapTrap" << RESET << std::endl;
	for (int i = 0; i < 4; i++) {
		other.attack("VICTIM");
		player2.takeDamage(other.getAttackDamage());
		if (i % 2 == 0)
			player2.beRepaired(5);
	}
	other.guardGate();
}

return 0;
}