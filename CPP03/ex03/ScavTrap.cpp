/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:33:02 by vvaudain          #+#    #+#             */
/*   Updated: 2024/07/12 12:57:18 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap("default", 100, 50, 20){
	std::cout << GREEN << "[INFO] ScavTrap default constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name, 100, 50, 20) {
	std::cout << RED << "[INFO] ScavTrap constructor called" << RESET << std::endl;
} //init constructor

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy){
	std::cout << RED << "[INFO] ScavTrap copy constructor called" << RESET << std::endl;
	*this = copy;
}	//copy constructor

ScavTrap::~ScavTrap(){
	std::cout << RED << "[INFO] ScavTrap destructor called" << std::endl;
} //destructor

void ScavTrap::attack(const std::string& target){
	std::cout	<< "	" << BOLDPURPLE << "ScavTrap " << this->getName() 
				<< RESET << PURPLE << " attacks " << target << ", causing " 
				<< this->getAttackDamage() << " points of damage!" 
				<< RESET << std::endl;
	this->setEnergyPoints(this->getEnergyPoints() - 1);
}

void ScavTrap::guardGate(){
	std::cout 	<< "	"<< BOLDPURPLE << "ScavTrap " << this->getName() 
				<< RESET << PURPLE << " is now in Gate keeper mode" 
				<< RESET << std::endl;
}

#endif