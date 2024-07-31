/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:27:14 by victoirevau       #+#    #+#             */
/*   Updated: 2024/07/31 16:36:27 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal("Dog"){
	std::cout << YELLOW << "This is the Dog default constructor" << RESET << std::endl;
	this->_brain = new Brain();
}

Dog::Dog(const Dog& copy): Animal(copy) {
	std::cout << YELLOW << "This is the Dog copy constructor" << RESET << std::endl;
	if (this != &copy){
		this->_type = copy._type;
		this->_brain = new Brain(*copy._brain);//deep copy
		// this->_brain = copy._brain; //shallow copy
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

Brain *Dog::getBrain(void) const {
	return (this->_brain);
}