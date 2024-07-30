/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:27:14 by victoirevau       #+#    #+#             */
/*   Updated: 2024/07/30 15:54:04 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal("Dog"){
	std::cout << YELLOW << "This is the Dog default constructor" << RESET << std::endl;
}

Dog::Dog(const Dog& copy): Animal(copy) {
	std::cout << YELLOW << "This is the Dog copy constructor" << RESET << std::endl;
	if (this != &copy){
		*this = copy;
	}
}

void	Dog::makeSound(void) const {
	std::cout << BLUE << "Woof" << RESET << std::endl;
}

Dog::~Dog(){
	std::cout << YELLOW << "This is the Dog destructor" << RESET << std::endl;
}

Dog& Dog::operator=(const Dog &rhs){
	this->_type = rhs._type;
	return (*this);
}