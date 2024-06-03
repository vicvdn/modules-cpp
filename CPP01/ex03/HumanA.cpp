/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:15:50 by vvaudain          #+#    #+#             */
/*   Updated: 2024/06/03 17:57:17 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA ( std::string name, Weapon& weapon ) : name(name), weapon(weapon) {
}

HumanA::~HumanA ( void ){
}

void	HumanA::attack( void ){
	std::cout << this->name;
	std::cout << " attacks with their ";
	std::cout << this->weapon.getType() << std::endl;
}