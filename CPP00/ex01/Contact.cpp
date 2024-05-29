/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:29:34 by vvaudain          #+#    #+#             */
/*   Updated: 2024/05/29 17:36:10 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <limits>

Contact::Contact(){
}

Contact::Contact(std::string n1, std::string n2, std::string sur, int nb, std::string secret) : first_name(n1),
last_name(n2), nickname(sur), phone_number(nb), darkest_secret(secret) 
{
	// std::cout << "Enter first name: " << std::endl;
	// std::string name1;
	// std::getline(std::cin >> std::ws, name1);
	// std::cout << "Enter last name: " << std::endl;
	// std::string name2;
	// std::getline(std::cin >> std::ws, name2);
	// std::cout << "Enter nickname: " << std::endl;
	// std::string sur;
	// std::getline(std::cin >> std::ws, sur);
	// SetName(name1, name2, sur);
	// std::cout << "Enter phone number: " << std::endl;
	// int	number;
	// std::cin >> number;
	// SetNumber(number);
	// std::cout << "Enter your darkest secret: " << std::endl;
	// std::string secret;
	// std::getline(std::cin >> std::ws, secret);
	// SetSecret(secret);
	std::cout << phone_number << std::endl;
	std::cout << last_name << std::endl;
	return ;
}

Contact::~Contact()
{
	std::cout << "This is the Contact destructor" << std::endl;
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