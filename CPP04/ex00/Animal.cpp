/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:28:21 by victoirevau       #+#    #+#             */
/*   Updated: 2024/08/14 13:39:41 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal") {
	std::cout << GREEN << "This is the Animal constructor" << RESET << std::endl;
} //default constructor

Animal::Animal(std::string type) : _type(type){
	std::cout << GREEN << "This is the Animal param constructor" << RESET << std::endl;
	
}

Animal::Animal(const Animal &copy){
	std::cout << GREEN << "This is the Animal copy constructor" << RESET << std::endl;
	*this = copy;
} //copy constructor

Animal::~Animal(){
	std::cout << RED << "This is the Animal destructor" << RESET << std::endl;
} //destructor

std::string Animal::getType(void) const{
	return (this->_type);
}

void Animal::makeSound(void) const {
	std::cout << BLUE << "Animal default sound" << RESET << std::endl;
}

Animal & Animal::operator=(const Animal &rhs){
	if (this != &rhs){
		this->_type = rhs._type;
		std::cout << GREEN << "This is the Animal assign operator constructor" << RESET << std::endl;
	}
	return (*this);
} //= operator overload