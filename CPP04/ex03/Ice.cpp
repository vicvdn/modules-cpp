/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 22:01:05 by victoirevau       #+#    #+#             */
/*   Updated: 2024/08/02 11:06:04 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria("ice"){
};

Ice::Ice(const Ice& copy){
	*this = copy;
}

Ice& Ice::operator=(const Ice& rhs){
	if (this != &rhs){
		this->_type = rhs.getType();
	}
	return (*this);
}

Ice::~Ice(){
}

AMateria*	Ice::clone(void) const{
	return (new Ice(*this));
}

void use(ICharacter& character){
	std::cout << "* shoots an ice bolt at" << character.getName() << " *" << std::endl;
}