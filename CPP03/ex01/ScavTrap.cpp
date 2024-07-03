/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:33:02 by vvaudain          #+#    #+#             */
/*   Updated: 2024/07/03 13:39:40 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){}; //default constructor
ScavTrap::ScavTrap(std::string name); //init constructor
ScavTrap(const ScavTrap& copy);	//copy constructor
~ScavTrap(); //destructor
void attack(const std::string& target);