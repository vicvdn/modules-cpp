/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:06:05 by victoirevau       #+#    #+#             */
/*   Updated: 2024/08/14 13:47:06 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal("Cat"){
	std::cout << CYAN << "This is the Cat default constructor" << RESET << std::endl;
	this->_brain = new Brain();
}

Cat::Cat(const Cat& copy) : Animal(copy) {
	std::cout << CYAN << "This is the Cat copy constructor" << RESET << std::endl;
	if (this != &copy){
		this->_type = copy._type;
		this->_brain = new Brain(*copy._brain);
	}
}

void	Cat::makeSound(void) const {
	std::cout << BLUE << "Miaou" << RESET << std::endl;
}

Cat::~Cat(){
	delete this->_brain;
	std::cout << YELLOW << "This is the Cat destructor" << RESET << std::endl;
}

Cat& Cat::operator=(const Cat &rhs){
	std::cout << CYAN << "This is the assignation operator" << RESET << std::endl;
	if (this != &rhs){
		this->_type = rhs._type;
		delete this->_brain;
		this->_brain = new Brain(*rhs._brain);
	}
	return (*this);
}

Brain *Cat::getBrain(void) const {
	return (this->_brain);
}