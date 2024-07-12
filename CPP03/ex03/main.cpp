/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:00:36 by vvaudain          #+#    #+#             */
/*   Updated: 2024/07/12 12:58:30 by vvaudain         ###   ########.fr       */
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

  ClapTrap player_a("Clappy", 10, 10, 10);
  ScavTrap player_b("Scavy");
  FragTrap player_c("Fraggy");
  DiamondTrap player_d("Diamondy");
  
  player_a.attack("Dummy 0");
  player_a.takeDamage(2);
  player_a.beRepaired(3);
  player_b.attack("Dummy");
  player_b.takeDamage(2);
  player_b.beRepaired(3);
  player_b.guardGate();
  player_c.attack("Dumb Dummy");
  player_c.takeDamage(2);
  player_c.beRepaired(3);
  player_c.highFivesGuys();
  player_d.attack("Dummy 2");
  player_d.takeDamage(20);
  player_d.beRepaired(5);
  player_d.whoAmI();
  player_d.guardGate();
  player_d.highFivesGuys();
	playerdiamond.whoAmI();
	return 0;
}

// int main()
// {
//   ClapTrap player_a("Claper");
//   ScavTrap player_b("Scaver");
//   FragTrap player_c("Frager");
//   DiamondTrap player_d("Diamonder");
  
//   std::cout
//     << WHTB << std::setw(30) << std::setfill('=') 
//     << "[INFO]" << std::setw(30)
//     << RESET << std::setfill(' ') << "\n";

//   std::cout << player_a;
//   std::cout << player_b;
//   std::cout << player_c;
//   std::cout << player_d;

//   std::cout
//       << WHTB << std::setw(30) << std::setfill('=') 
//       << "[BATTLE INFO]" << std::setw(30) 
//       << RESET << std::setfill(' ') << "\n";
//   player_a.attack("Dummy 0");
//   player_a.takeDamage(2);
//   player_a.beRepaired(3);
//   player_b.attack("Dummy");
//   player_b.takeDamage(2);
//   player_b.beRepaired(3);
//   player_b.guardGate();
//   player_c.attack("Dumb Dummy");
//   player_c.takeDamage(2);
//   player_c.beRepaired(3);
//   player_c.highFivesGuys();
//   player_d.attack("Dummy 2");
//   player_d.takeDamage(20);
//   player_d.beRepaired(5);
//   player_d.whoAmI();
//   player_d.guardGate();
//   player_d.highFivesGuys();

//   std::cout
//     << "[INFO]" << std::endl;
//   std::cout << player_b;
//   std::cout << player_d;
// }