/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:13:40 by ubuntu            #+#    #+#             */
/*   Updated: 2024/06/07 11:28:56 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main( void ) {
	Harl	Harlito;

	Harlito.complain("DEBUG");
	Harlito.complain("INFO");
	Harlito.complain("WARNING");
	Harlito.complain("ERROR");
	Harlito.complain("");
	Harlito.complain(std::string());
	return 0;
}