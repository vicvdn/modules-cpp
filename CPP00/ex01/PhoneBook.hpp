/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:52:34 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/30 16:59:17 by vvaudain         ###   ########.fr       */
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
	void	PrintTable(Phonebook instance) const;
	int		GetContactAmount(void){
		return (contact_amount);
	}
	Contact	GetContact(int index) {
			return list[index];
	}
	void	AddContact(int index, const Contact& person){
		if (index >= 0 && index < GetLim()){	
			list[index] = person;
			return ;
		}
		else
			std::cout << "Index error!" << std::endl;
	}
	void	SetLim(int lim){
		contact_limit = lim;
	}
	int		GetLim(void){
		return (contact_limit);
	}
};

#endif