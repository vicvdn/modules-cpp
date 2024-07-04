/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:23:57 by vvaudain          #+#    #+#             */
/*   Updated: 2024/07/04 15:44:43 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"
# define BLUE			"\033[34m"
# define PURPLE			"\033[35m"
# define BOLDPURPLE		"\033[1;35m"
# define BOLDRED		"\033[1;31m"
# define BOLDYELLOW		"\033[1;33m"
# define RESET			"\033[0m"

class ScavTrap: public ClapTrap {

	public:
	
		ScavTrap(); //default constructor
		ScavTrap(std::string name); //init constructor
		ScavTrap(const ScavTrap& copy);	//copy constructor
		~ScavTrap(); //destructor
		void attack(const std::string& target);
		void guardGate();
};

#endif