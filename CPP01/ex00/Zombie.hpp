/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:59:05 by vvaudain          #+#    #+#             */
/*   Updated: 2024/06/03 14:45:00 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {

private:
	std::string	name;
public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	void	announce( void );
	
};

Zombie* newZombie( std::string name);
void	randomChump( std::string name);

#endif