/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:01:58 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/29 13:37:01 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(int ac, char *av[]) {
	Phonebook	instance;
	int			index;

	(void)ac;
	if (ac > 1)
	{	
		if ((std::string)av[1] == "EXIT")
			return (0);
		else if ((std::string)av[1] == "ADD")
		{
			Contact 	person;
			
		}
		else if ((std::string)av[1] == "SEARCH")
		{
			
		}
	}
	return (0);
}