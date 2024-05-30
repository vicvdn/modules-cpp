/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:52:36 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/30 11:55:41 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// void	SetPhonebookContact(Phonebook phonebook, Contact person, int index)
// {
// 	phonebook.SetList(index, person); 
// }

void	Phonebook::PrintTable(void) const{
	std::cout << "   Index  " << "|" << "First Name" << "|" << "Last Name " << "|" << " Nickname "<< std::endl;
	for(int i = 0; i < this->contact_amount; i++){
		std::cout << i;
		std::cout << this->list[i].GetFName();
		std::cout << this->list[i].GetLName();
		std::cout << this->list[i].GetNName() << std::endl;
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