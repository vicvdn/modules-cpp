/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:48:35 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/30 16:16:34 by vvaudain         ###   ########.fr       */
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
	std::string	phone_number;
	std::string	darkest_secret;

public:
	Contact();
	Contact(std::string n1, std::string n2, std::string sur, std::string nb, std::string secret);
	void	SetName(std::string name1, std::string name2, std::string sur);
	void	SetNumber(int number);
	void	SetSecret(std::string secret);
	std::string	GetFName(void) const {
		return (first_name);
	}
	std::string	GetLName(void) const {
		return (last_name);
	}
	std::string	GetNName(void) const {
		return (nickname);
	}
	std::string	GetNum(void) const {
		return (phone_number);
	}
	std::string	GetSecret(void) const {
		return (darkest_secret);
	}
	~Contact();
};

#endif