/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 19:42:57 by victoirevau       #+#    #+#             */
/*   Updated: 2024/08/03 12:38:59 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(): AMateria("cure"){
}

Cure::Cure(const Cure& copy) : AMateria() {
	*this = copy;
}

Cure& Cure::operator=(const Cure& rhs){
	if (this != &rhs){
		this->_type = rhs.getType();
	}
	return (*this);
}

Cure::~Cure(){
}

AMateria*	Cure::clone(void) const{
	return (new Cure(*this)); //deep copy needed
}

void Cure::use(ICharacter& character){
	std::cout << "* heals " << character.getName() << "’s wounds *" << std::endl;
}