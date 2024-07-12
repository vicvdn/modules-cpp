/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:01:23 by vvaudain          #+#    #+#             */
/*   Updated: 2024/07/12 12:50:54 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("default", 100, 100, 30){
} //default constructor

FragTrap::FragTrap (std::string name) : ClapTrap(name, 100, 100, 30) {
	std::cout	<< BLUE << "[INFO] FragTrap constructor called" 
				<< RESET << std::endl;
} //init constructor

FragTrap::FragTrap(const FragTrap& copy) {
	std::cout 	<< BLUE << "[INFO] FragTrap copy constructor called" 
				<< RESET << std::endl;
	*this = copy;
} //copy constructor

FragTrap::~FragTrap(){
	std::cout	<< BLUE << "[INFO] FragTrap destructor called"
				<< RESET << std::endl;
} //destructor

void FragTrap::highFivesGuys(void) {
	std::cout	<< "	" << BOLDPURPLE << "FragTrap" 
				<< RESET << PURPLE << "Hey! Can we High Five?" 
				<< RESET << std::endl;
}