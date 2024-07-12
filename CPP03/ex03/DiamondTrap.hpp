/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:53:25 by vvaudain          #+#    #+#             */
/*   Updated: 2024/07/11 18:05:42 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"
# define BLUE			"\033[34m"
# define PURPLE			"\033[35m"
# define CYAN			"\033[36m"
# define BOLDPURPLE		"\033[1;35m"
# define BOLDRED		"\033[1;31m"
# define BOLDYELLOW		"\033[1;33m"
# define RESET			"\033[0m"

class DiamondTrap: public ScavTrap, public FragTrap{

	private:
		const std::string	_name;
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& copy);
		~DiamondTrap();
		virtual std::string	getName() const;
		DiamondTrap& operator=(DiamondTrap const &rhs);
		void	WhoAmI();
		virtual void	attack(const std::string& target);
};

std::ostream &operator<<(std::ostream &os, DiamondTrap &obj);

#endif