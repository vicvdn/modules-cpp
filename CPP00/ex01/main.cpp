/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:01:58 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/29 17:10:58 by vvaudain         ###   ########.fr       */
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
	int	number;
	std::cin >> number;
	std::cout << "Enter your darkest secret: " << std::endl;
	std::string secret;
	std::getline(std::cin >> std::ws, secret);
	Contact	person(name1, name2, sur, number, secret);
	return (person);
}

int	main(void) {
	Phonebook	instance;
	std::string	input;
	int			index = 1;

	std::cout << "This is the PhoneBook! Chosse between ADD, SEARCH or EXIT options"  << std::endl;
	while (1)
	{
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
				index = 1;
			instance.SetList(index, CreateContact());
			index++;
			// if (index == 1)
			// 	instance.contact1()
			// SetPhonebookContact(CreateContact(), index);
			// Contact 	person;
			
		}
		else if (input == "SEARCH")
		{
			
		}
	}
	return 0;
}