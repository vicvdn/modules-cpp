/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:01:08 by vvaudain          #+#    #+#             */
/*   Updated: 2024/07/12 13:37:58 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

# define GREEN			"\033[32m"
# define RED			"\033[31m"
# define PURPLE			"\033[35m"
# define BOLDPURPLE		"\033[1;35m"
# define BOLDRED		"\033[1;31m"
# define BOLDYELLOW		"\033[1;33m"
# define RESET			"\033[0m"

class ClapTrap {

	protected:
		std::string	_name;
		int			_hit_points;
		int			_energy_points;
		int			_attack_damage;

	public:
		ClapTrap(); //default constructor
		ClapTrap(std::string name); //init constructor
		ClapTrap(const ClapTrap& copy);	//copy constructor
		virtual ~ClapTrap(); //destructor
		std::string	getName()const;
		int		getHitPoints() const;
		void	setHitPoints(int pts);
		int		getEnergyPoints() const;
		void	setEnergyPoints(int nrj);
		int		getAttackDamage() const;
		void	setAttackDamage(int dmg);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};



#endif