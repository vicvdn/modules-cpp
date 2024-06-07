/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:47:12 by vvaudain          #+#    #+#             */
/*   Updated: 2024/06/07 12:00:22 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char *av[]) {
	Harl		harlito;

	if (ac != 2)
		return 1;
	else {
		std::string	level = (std::string) av[1];
		harlito.complain(level);
	}
	return 0;
}