/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:52:34 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/28 16:49:24 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHONEBOOK_H
#define	PHONEBOOK_H

#include <iostream>

class	Phonebook {

public:

	Phonebook(void);
	~Phonebook(void);
};

Phonebook::Phonebook(void) {
	std::cout << "This is the constructor" << std::endl;
	return ;
}

Phonebook::~Phonebook(void) {
	std::cout << "This is the destructor" << std::endl;
	return ;
}

#endif