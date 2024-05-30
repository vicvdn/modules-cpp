/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:52:34 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/30 12:42:22 by vvaudain         ###   ########.fr       */
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
	void	IncreaseAmount(void);
	Contact	GetContact(int index) {
			return list[index];
	}
	void	AddContact(int index, const Contact& person){
		if (index > 0 && index <= 8){	
			list[index] = person;
			return ;
		}
		else
			std::cout << "Index error!" << std::endl;
	}
	void	PrintTable(Phonebook instance) const;
	int	GetLim(void){
		return (contact_limit);
	}
	// void	SetPhonebookContact(Phonebook phonebook, Contact person, int index);
};

#endif