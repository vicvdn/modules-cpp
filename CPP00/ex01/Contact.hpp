/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:48:35 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/29 17:35:21 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CONTACT_HPP
#define	CONTACT_HPP

#include <iostream>
#include <string>

class Contact {

private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	int			phone_number;
	std::string	darkest_secret;

public:
	Contact();
	Contact(std::string n1, std::string n2, std::string sur, int nb, std::string secret);
	~Contact();
	void	SetName(std::string name1, std::string name2, std::string sur);
	void	SetNumber(int number);
	void	SetSecret(std::string secret);
};

#endif