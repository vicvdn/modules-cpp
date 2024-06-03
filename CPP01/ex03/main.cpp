/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:10:34 by vvaudain          #+#    #+#             */
/*   Updated: 2024/06/03 18:05:08 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

//because a reference always has to be initialized and we know HumanA  will always have a weapon, we can use a reference for its weapon
//on the contrary HumanB won't always have a weapon so we can use a pointer

int	main( void ) {
	
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon( &club );
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}