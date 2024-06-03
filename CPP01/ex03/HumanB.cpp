/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:21:52 by vvaudain          #+#    #+#             */
/*   Updated: 2024/06/03 18:00:47 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB ( std::string name ) : name(name), weapon(NULL) {
}

HumanB::~HumanB ( void ){
}

void	HumanB::attack( void ){
	std::cout << this->name;
	std::cout << " attacks with their ";
	std::cout << this->weapon->getType() << std::endl;
}

void	HumanB::setWeapon( Weapon *weapon) {
	this->weapon = weapon;
}