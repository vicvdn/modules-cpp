/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:27:14 by victoirevau       #+#    #+#             */
/*   Updated: 2024/08/14 13:46:43 by vvaudain         ###   ########.fr       */
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
	delete this->_brain;
	std::cout << YELLOW << "This is the Dog destructor" << RESET << std::endl;
}

Dog& Dog::operator=(const Dog &rhs){
	this->_type = rhs._type;
	return (*this);
}

Brain *Dog::getBrain(void) const {
	return (this->_brain);
}