/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:12:12 by victoirevau       #+#    #+#             */
/*   Updated: 2024/08/02 17:31:48 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(){
	// std::cout << GREEN << "This is the AMateria constructor" << RESET << std::endl;
} //default constructor

AMateria::AMateria(std::string const & type) : _type(type){
} //init constructor

AMateria::AMateria(const AMateria &copy){
	// std::cout << GREEN << "This is the AMateria copy constructor" << RESET << std::endl;
	*this = copy;
} //copy constructor

std::string const &AMateria::getType() const {
	return (this->_type);
}

AMateria &AMateria::operator=(const AMateria &rhs){
	// std::cout << GREEN << "This is the AMateria assignement operator" << RESET << std::endl;
	if (this != &rhs){
		this->_type = rhs.getType();
	}
	return (*this);
} //assignement operator overload

AMateria::~AMateria(){
	// std::cout << RED << "This is the AMateria destructor" << RESET << std::endl;
} //destructor

void AMateria::use(ICharacter& target){
	(void)target;
}