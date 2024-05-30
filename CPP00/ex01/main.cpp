/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:01:58 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/30 16:58:19 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

Contact	CreateContact()
{
	std::cout << "Enter first name: " << std::endl;
	std::string name1;
	std::getline(std::cin >> std::ws, name1);
	std::cout << "Enter last name: " << std::endl;
	std::string name2;
	std::getline(std::cin >> std::ws, name2);
	std::cout << "Enter nickname: " << std::endl;
	std::string sur;
	std::getline(std::cin >> std::ws, sur);
	std::cout << "Enter phone number: " << std::endl;
	std::string	number;
	std::getline(std::cin >> std::ws, number);
	std::cout << "Enter your darkest secret: " << std::endl;
	std::string secret;
	std::getline(std::cin >> std::ws, secret);
	Contact	person(name1, name2, sur, number, secret);
	return (person);
}

int	main(void) {
	Phonebook	instance;
	std::string	input;
	int			index = 0;

	instance.SetLim(8);
	while (1)
	{
		std::cout << "This is the PhoneBook! Chosse between ADD, SEARCH or EXIT options"  << std::endl;
		if (std::cin.eof())
			return 0;
		getline(std::cin, input);
		if (input.empty()){
			std::cout << "You must choose an option between ADD, SEARCH of EXIT" << std::endl;
		}	
		if (input == "EXIT")
			break ;
		else if (input == "ADD")
		{
			if (index == instance.GetLim())
				index = 0;
			instance.AddContact(index, CreateContact());
			instance.IncreaseAmount();
			index++;
		}
		else if (input == "SEARCH") {
			instance.PrintTable(instance);
		}
	}
	return 0;
}