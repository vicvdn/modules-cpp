/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:52:34 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/30 11:55:37 by vvaudain         ###   ########.fr       */
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
	void	PrintTable(void) const;
	int	GetLim(void){
		return (contact_limit);
	}
	// void	SetPhonebookContact(Phonebook phonebook, Contact person, int index);
};

#endif