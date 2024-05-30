/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:29:34 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/30 15:18:35 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <limits>

Contact::Contact(){
}

Contact::Contact(std::string n1, std::string n2, std::string sur, std::string nb, std::string secret) : first_name(n1),
last_name(n2), nickname(sur), phone_number(nb), darkest_secret(secret) 
{
	return ;
}

Contact::~Contact()
{
	// std::cout << "This is the Contact destructor" << std::endl;
	return ;
}

void	Contact::SetName(std::string name1, std::string name2, std::string sur)
{
	this->first_name = name1;
	this->last_name = name2;
	this->nickname = sur;
	return ;
}

void	Contact::SetNumber(int number)
{
	this->phone_number = number;
	return ;
}

void	Contact::SetSecret(std::string secret)
{
	this->darkest_secret = secret;
	return ;
}