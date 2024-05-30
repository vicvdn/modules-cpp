/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:52:36 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/30 15:20:28 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// void	SetPhonebookContact(Phonebook phonebook, Contact person, int index)
// {
// 	phonebook.SetList(index, person); 
// }

void	FormatColumn(std::string to_print, int last){
	
	int len = to_print.length();
	int	space_nb = 0;

	if (len < 10){
		std::cout << to_print;
		space_nb = 10 - len;
		if (last != 1) {
			for (int i = 0; i < space_nb; i++)
				std::cout << " ";
		}
		else {
			for (int i = 0; i < space_nb - 1; i++)
				std::cout << " ";
			std::cout << " " << std::endl;
		}
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
	std::cout << this->contact_amount <<std::endl;
}

void	Phonebook::PrintTable(Phonebook instance) const{
	PrintHeader();
	for(int i = 0; i < this->contact_amount; i++){
		PrintIndex(i);
		FormatColumn(instance.GetContact(i + 1).GetFName(), 0);
		FormatColumn(instance.GetContact(i + 1).GetLName(), 0);
		FormatColumn(instance.GetContact(i + 1).GetNName(), 1);
	}
}

Phonebook::Phonebook(void) : contact_limit(8) {
	contact_amount = 0;
	return ;
}

Phonebook::~Phonebook(void) {
	std::cout << "This is the destructor" << std::endl;
	return ;
}