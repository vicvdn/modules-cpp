/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:06:05 by victoirevau       #+#    #+#             */
/*   Updated: 2024/07/30 15:53:48 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal("Cat"){
	std::cout << RED << "This is the Cat default constructor" << RESET << std::endl;
}

Cat::Cat(const Cat& copy) : Animal(copy) {
	std::cout << RED << "This is the Cat copy constructor" << RESET << std::endl;
	if (this != &copy){
		*this = copy;
	}
}

void	Cat::makeSound(void) const {
	std::cout << BLUE << "Miaou" << RESET << std::endl;
}

Cat::~Cat(){
	std::cout << RED << "This is the Cat destructor" << RESET << std::endl;
}

Cat& Cat::operator=(const Cat &rhs){
	this->_type = rhs._type;
	return (*this);
}