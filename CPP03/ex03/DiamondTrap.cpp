/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:53:11 by vvaudain          #+#    #+#             */
/*   Updated: 2024/07/11 18:03:41 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap(), _name("default"){
	this->setHitPoints(FragTrap::getHitPoints());
	this->setEnergyPoints(ScavTrap::getEnergyPoints());
	this->setAttackDamage(FragTrap::getAttackDamage());
	std::cout	<< CYAN << "[INFO] Default DiamondTrap constructor called" 
				<< RESET << std::endl;
}

DiamondTrap::DiamondTrap(std::string const name) : ClapTrap(name + "_clap_name", 100, 100, 30), _name(name) {
	std::cout	<< CYAN << "[INFO] DiamondTrap constructor called" 
				<< RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap & copy){
	*this = copy;
	std::cout	<< CYAN << "[INFO] DiamondTrap copy constructor called" 
				<< RESET << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap& rhs){
	this->_name = rhs.getName();
	this->setHitPoints(rhs.getHitPoints());
	this->setEnergyPoints(rhs.getEnergyPoints());
  	this->setAttackDamage(rhs.getAttackDamage());
	return (*this);
}

DiamondTrap::~DiamondTrap(){
	std::cout	<< CYAN << "[INFO] DiamondTrap destructor called" 
				<< RESET << std::endl;
}

std::string DiamondTrap::getName() const {
  return this->_name;
}

void	DiamondTrap::WhoAmI(void){
	std::cout	<< "My name is " << this->_name << " and my ClapTrap name is "
				<< ClapTrap::_name << std::endl;
}

void	DiamondTrap::attack(const std::string& target){
	ScavTrap::attack(target);
}

std::ostream &operator<<(std::ostream &os, DiamondTrap &obj){
	os	<< "Diamond infos: " << "\n" 
		<< "Name: " << obj.getName() << "\n"
		<< "Hit Points: " << obj.getHitPoints() << "\n"
		<< "Energy Points: " << obj.getEnergyPoints() << "\n"
		<< "Attack Damage: " << obj.getAttackDamage() << std::endl;
	return (os);
}