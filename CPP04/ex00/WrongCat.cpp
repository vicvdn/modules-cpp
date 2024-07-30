/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:55:36 by victoirevau       #+#    #+#             */
/*   Updated: 2024/07/30 16:56:18 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat"){
	std::cout << RED << "This is the WrongCat default constructor" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy) {
	std::cout << RED << "This is the WrongCat copy constructor" << RESET << std::endl;
	if (this != &copy){
		*this = copy;
	}
}

void	WrongCat::makeSound(void) const {
	std::cout << BLUE << "Miaou" << RESET << std::endl;
}

WrongCat::~WrongCat(){
	std::cout << RED << "This is the WrongCat destructor" << RESET << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &rhs){
	this->_type = rhs._type;
	return (*this);
}