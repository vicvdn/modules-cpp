/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:28:21 by victoirevau       #+#    #+#             */
/*   Updated: 2024/07/30 14:52:35 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("default") {
	std::cout << GREEN << "This is the Animal constructor" << RESET << std::endl;
} //default constructor

Animal::Animal(std::string type) : _type(type){
}

Animal::Animal(const Animal &copy){
	std::cout << GREEN << "This is the Animal copy constructor" << RESET << std::endl;
	*this = copy;
} //copy constructor

Animal::~Animal(){
	std::cout << GREEN << "This is the Animal destructor" << RESET << std::endl;
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
	}
	return (*this);
} //= operator overload