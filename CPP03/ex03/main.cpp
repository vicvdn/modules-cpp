/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:00:36 by vvaudain          #+#    #+#             */
/*   Updated: 2024/07/12 13:58:48 by vvaudain         ###   ########.fr       */
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
  ClapTrap player_a("Clappy");
  ScavTrap player_b("Scavy");
  FragTrap player_c("Fraggy");
  DiamondTrap player_d("Diamondy");

	std::cout << BOLDYELLOW << "What info do we have?" << RESET << std::endl;
  std::cout << playerdiamond << "\n" << playerdiamond2 << "\n" << playerdiamondcopy << std::endl;

  
	std::cout << BOLDYELLOW << "Let the attacks begin!" << RESET << std::endl;
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
  player_d.guardGate();
  player_d.highFivesGuys();
  std::cout << BOLDYELLOW << "\nWho am I?" << RESET << std::endl;
  player_d.whoAmI();
	playerdiamond.whoAmI();
	return 0;
}