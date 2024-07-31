/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:51:10 by victoirevau       #+#    #+#             */
/*   Updated: 2024/07/30 16:54:02 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("default") {
	std::cout << GREEN << "This is the WrongAnimal constructor" << RESET << std::endl;
} //default constructor

WrongAnimal::WrongAnimal(std::string type) : _type(type){
	std::cout << GREEN << "This is the WrongAnimal param constructor" << RESET << std::endl;
	
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy){
	std::cout << GREEN << "This is the WrongAnimal copy constructor" << RESET << std::endl;
	*this = copy;
} //copy constructor

WrongAnimal::~WrongAnimal(){
	std::cout << GREEN << "This is the WrongAnimal destructor" << RESET << std::endl;
} //destructor

std::string WrongAnimal::getType(void) const{
	return (this->_type);
}

void WrongAnimal::makeSound(void) const {
	std::cout << BLUE << "WrongAnimal default sound" << RESET << std::endl;
}

WrongAnimal & WrongAnimal::operator=(const WrongAnimal &rhs){
	if (this != &rhs){
		this->_type = rhs._type;
	}
	return (*this);
} //= operator overload