/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:52:34 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/29 17:22:40 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHONEBOOK_H
#define	PHONEBOOK_H

#include <iostream>
#include "Contact.hpp"

class	Phonebook {

private:
	int		contact_amount;
	int		contact_limit;
	Contact	list[8];
	
public:
	Phonebook(void);
	~Phonebook(void);
	void	SetList(int index, Contact person){
		this->list[index] = person;
		return ;
	}
	int	GetLim(void){
		return (contact_limit);
	}
	// void	SetPhonebookContact(Phonebook phonebook, Contact person, int index);
};

Phonebook::Phonebook(void) : contact_limit(8) {
	contact_amount = 0;
	return ;
}

Phonebook::~Phonebook(void) {
	std::cout << "This is the destructor" << std::endl;
	return ;
}

#endif