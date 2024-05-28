/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:48:35 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/28 17:18:18 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CONTACT_H
#define	CONTACT_H

#include <iostream>
#include <string>

class Contact
{
private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	int			phone_number;
	std::string	darkest_secret;
public:
	Contact(void);
	~Contact();
};

Contact::Contact(/* args */)
{
	std::cout << "This is the constructor" << std::endl;
	return ;
}

Contact::~Contact()
{
	std::cout << "This is the destructor" << std::endl;
	return ;
}


#endif