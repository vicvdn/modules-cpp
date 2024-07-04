/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:01:08 by vvaudain          #+#    #+#             */
/*   Updated: 2024/07/04 11:29:19 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

# define GREEN		"\033[32m"
# define BOLDPURPLE		"\033[1;35m"
# define BOLDRED		"\033[1;31m"
# define BOLDYELLOW		"\033[1;33m"
# define RESET		"\033[0m"

class ClapTrap {

	private:
		std::string	_name;
		int			_hit_points;
		int			_energy_points;
		int			_attack_damage;

	public:
		ClapTrap(); //default constructor
		ClapTrap(std::string name); //init constructor
		ClapTrap(const ClapTrap& copy);	//copy constructor
		~ClapTrap(); //destructor
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

//faut assigner l'operateur =

#endif