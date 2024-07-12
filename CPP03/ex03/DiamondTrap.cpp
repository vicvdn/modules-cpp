/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:53:11 by vvaudain          #+#    #+#             */
/*   Updated: 2024/07/12 15:42:57 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), _name("default"){
	
	this->_hit_points = FragTrap::_hit_points;
	this->_energy_points = ScavTrap::_nrj_points;
	this->_attack_damage = FragTrap::_attack_damage;
	
	std::cout	<< CYAN << "[INFO] Default DiamondTrap constructor called" 
				<< RESET << std::endl;
}

DiamondTrap::DiamondTrap(std::string const name) : ClapTrap(name + "_clap_name"),
	_name(name) {
	this->_hit_points = FragTrap::_hit_points;
	this->_energy_points = ScavTrap::_nrj_points;
	this->_attack_damage = FragTrap::_attack_damage;
	std::cout	<< CYAN << "[INFO] DiamondTrap constructor called" 
				<< RESET << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &copy) : ClapTrap(copy), 
	ScavTrap(copy), FragTrap(copy), _name(copy.getName() + "_cpy"){
	*this = copy;
	std::cout	<< CYAN << "[INFO] DiamondTrap copy constructor called" 
				<< RESET << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap& rhs){
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

void	DiamondTrap::whoAmI(void){
	std::cout	<< "My name is " << this->_name << " and my ClapTrap name is "
				<< ClapTrap::_name << std::endl;
}

void	DiamondTrap::attack(const std::string& target){
	ScavTrap::attack(target);
}

std::ostream &operator<<(std::ostream &os, DiamondTrap &obj){
	os	<< "\n" << BOLDPURPLE << "Diamond info: " << RESET << "\n" 
		<< "Name: " << obj.getName() << "\n"
		<< "Hit Points: " << obj.getHitPoints() << "\n"
		<< "Energy Points: " << obj.getEnergyPoints() << "\n"
		<< "Attack Damage: " << obj.getAttackDamage() << std::endl;
	return (os);
}