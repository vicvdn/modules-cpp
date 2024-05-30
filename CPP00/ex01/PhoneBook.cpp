/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:52:36 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/30 16:58:47 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

void	FormatColumn(std::string to_print, int last){
	
	int len = to_print.length();
	int	space_nb = 0;

	if (len < 10){
		space_nb = 10 - len;
		for (int i = 0; i < space_nb; i++) {
			std::cout << " ";
		}
		if (last == 1)
			std::cout << to_print << std::endl;
		else
			std::cout << to_print;
	}
	if (len >= 10){
		if (last != 1) {
			std::cout << to_print.substr(0, 9) << ".";
		}
		else {
			std::cout << to_print.substr(0, 9) << "." << std::endl;
		}
	}
	if (last == 0){
		std::cout << "|";
	}
}

void	PrintHeader(void) {
	FormatColumn("Index", 0);
	FormatColumn("First Name", 0);
	FormatColumn("Last Name", 0);
	FormatColumn("Nickname", 1);
}

void	PrintIndex(int i)
{
	if (i == 0)
		FormatColumn("1", 0);
	if (i == 1)
		FormatColumn("2", 0);
	if (i == 2)
		FormatColumn("3", 0);
	if (i == 3)
		FormatColumn("4", 0);
	if (i == 4)
		FormatColumn("5", 0);
	if (i == 5)
		FormatColumn("6", 0);
	if (i == 6)
		FormatColumn("7", 0);
	if (i == 7)
		FormatColumn("8", 0);
}

void	Phonebook::IncreaseAmount(void){
	this->contact_amount++;
}

void	PrintContact(Contact person){
	std::cout << person.GetFName() << std::endl;
	std::cout << person.GetLName() << std::endl;
	std::cout << person.GetNName() << std::endl;
	std::cout << person.GetNum() << std::endl;
	std::cout << person.GetSecret() << std::endl;
}

void	HandleContactInfo(Phonebook instance, std::string index){
	if (index == "1")
		PrintContact(instance.GetContact(0));
	else if (index == "2")
		PrintContact(instance.GetContact(1));
	else if (index == "3")
		PrintContact(instance.GetContact(2));
	else if (index == "4")
		PrintContact(instance.GetContact(3));
	else if (index == "5")
		PrintContact(instance.GetContact(4));
	else if (index == "6")
		PrintContact(instance.GetContact(5));
	else if (index == "7")
		PrintContact(instance.GetContact(6));
	else if (index == "8")
		PrintContact(instance.GetContact(7));
	else
		std::cout << "This index does not exist yet or is too high!" << std::endl;
}

void	Phonebook::PrintTable(Phonebook instance) const{
	std::string	index_to_print;

	PrintHeader();
	for(int i = 0; i < instance.contact_amount && i < instance.contact_limit; i++){
		PrintIndex(i);
		FormatColumn(instance.GetContact(i).GetFName(), 0);
		FormatColumn(instance.GetContact(i).GetLName(), 0);
		FormatColumn(instance.GetContact(i).GetNName(), 1);
	}
	std::cout << "Which contact info do you want? Index :" << std::endl;
	std::getline(std::cin >> std::ws, index_to_print);
	HandleContactInfo(instance, index_to_print);
	
}

Phonebook::Phonebook(void) : contact_limit(8) {
	contact_amount = 0;
	return ;
}

Phonebook::~Phonebook(void) {
	return ;
}