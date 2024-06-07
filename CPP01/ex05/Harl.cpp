/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:22:44 by ubuntu            #+#    #+#             */
/*   Updated: 2024/06/07 11:38:27 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl( void ){
}

Harl::~Harl( void ){
}

void	Harl::debug( void ) {
	std::string output = "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !";
	std::cout << "DEBUG : " << output << std::endl;
	return ;
}

void	Harl::info( void ) {
	std::string output = "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !";
	std::cout << "INFO : " << output << std::endl;
	return ;
}

void	Harl::warning( void ) {
	std::string output = "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.";
	std::cout << "WARNING : " << output << std::endl;
	return ;
}

void	Harl::error( void ) {
	std::string output = "This is unacceptable ! I want to speak to the manager now.";
	std::cout << "ERROR : " << output << std::endl;
	return ;
}

void	Harl::complain( std::string level) {
	std::string	tab[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void	(Harl::*functiontab[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	
	if (level.empty()) {
		std::cerr << "You must give a level for Harl to complain properly!" << std::endl;
		return ;
	}
	for(int i = 0; i < 4; i++) {
		if (level.compare(tab[i]) == 0) {
			(this->*functiontab[i])();
			return ;	
		}
	}
}