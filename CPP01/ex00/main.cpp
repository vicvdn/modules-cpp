/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:19:22 by vvaudain          #+#    #+#             */
/*   Updated: 2024/06/03 14:48:26 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	Zombie		standard; //default constructor
	Zombie		test("Test"); //param constructor
	std::string name = "Foo";
	std::string name2 = "Bar";
	Zombie*		ptr; //allocated zombie

	standard.announce();
	test.announce();
	ptr = newZombie(name);
	ptr->announce();
	randomChump(name2); //random zombie
	delete ptr;
	return 0;
}