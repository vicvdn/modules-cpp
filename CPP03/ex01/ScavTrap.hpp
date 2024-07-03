/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:23:57 by vvaudain          #+#    #+#             */
/*   Updated: 2024/07/03 13:38:12 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

class ScavTrap: public ClapTrap {
	ScavTrap(); //default constructor
	ScavTrap(std::string name); //init constructor
	ScavTrap(const ScavTrap& copy);	//copy constructor
	~ScavTrap(); //destructor
	void attack(const std::string& target);
};

#endif