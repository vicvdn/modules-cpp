/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:22:44 by ubuntu            #+#    #+#             */
/*   Updated: 2024/06/06 18:40:42 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl( void ){
}

Harl::~Harl( void ){
}

void	Harl::debug( void ) {
}

void	Harl::info( void ) {
}

void	Harl::warning( void ) {
}

void	Harl::error( void ) {
}

void	Harl::complain( std::string level) {
	std::string	tab[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void	(Harl::*functiontab[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for(int i = 0; i < 4; i++) {

	}
		
	
}