/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:00:54 by vvaudain          #+#    #+#             */
/*   Updated: 2024/07/04 14:17:40 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << GREEN << "[INFO] ClapTrap default constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name, int hp, int ep, int dmg) : _name(name), _hit_points(hp),
_energy_points(ep), _attack_damage(dmg) {
	std::cout << GREEN << "[INFO] ClapTrap initialization constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy) {
	std::cout << GREEN << "[INFO] ClapTrap copy constructor called" << RESET << std::endl;
	*this = copy;
}

ClapTrap::~ClapTrap() {
	std::cout << GREEN << "[INFO] ClapTrap destructor called" << RESET << std::endl;
}

std::string	ClapTrap::getName() const {
	return (this->_name);
}

void ClapTrap::setHitPoints(int pts) {
	this->_hit_points = pts;
}

int		ClapTrap::getHitPoints() const {
	return (this->_hit_points);
}

void ClapTrap::setEnergyPoints(int nrj) {
	this->_energy_points = nrj;
}

int ClapTrap::getEnergyPoints() const {
	return (this->_energy_points);
}

void ClapTrap::setAttackDamage(int dmg) {
	this->_attack_damage = dmg;
}

int ClapTrap::getAttackDamage() const {
	return (this->_attack_damage);
}

void ClapTrap::attack(const std::string& target) {
	std::cout	<< "	" << BOLDPURPLE << "ClapTrap " << this->_name 
				<< RESET << PURPLE << " attacks " << target 
				<< ", causing " << this->_attack_damage 
				<< " points of damage!" << RESET << std::endl;
	this->_energy_points--;
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout 	<< "	" << this->_name << " took " << amount 
				<< " points of damage" << std::endl;
	this->_hit_points -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
	std::cout 	<< "	" << this->_name 
				<< " is being repaired for 1 energy point" 
				<< std::endl;
	this->_hit_points += amount;
	this->_energy_points--;
}