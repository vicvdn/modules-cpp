/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:00:54 by vvaudain          #+#    #+#             */
/*   Updated: 2024/06/12 15:38:58 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << PURPLE << "[INFO] Default constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10),
_energy_points(10), _attack_damage(0) {
	std::cout << PURPLE << "[INFO] Initialization constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy) {
	std::cout << PURPLE << "[INFO] Copy constructor called" << RESET << std::endl;
	*this = copy;
}

ClapTrap::~ClapTrap() {
	std::cout << PURPLE << "[INFO] Destructor called" << RESET << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	std::cout	<< "ClapTrap " << this->_name << " attacks " 
				<< target << ", causing " << this->_attack_damage
				<< " points of damage!" << std::endl;
	this->_energy_points--;
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << this->_name << " took " << amount << " points of damage" << std::endl;
	this->_hit_points -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
	std::cout << this->_name << " is being repaired for 1 energy point" << std::endl;
	this->_hit_points += amount;
	this->_energy_points--;
}