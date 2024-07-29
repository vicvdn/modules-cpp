/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:28:21 by victoirevau       #+#    #+#             */
/*   Updated: 2024/07/29 12:41:47 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(){
} //default constructor

Animal::Animal(const Animal &copy){
	*this = copy;
} //copy constructor

Animal::~Animal(){
} //destructor

Animal & Animal::operator=(const Animal &rhs){
	if (this != &rhs){
		this->type = rhs.type;
	}
	return (*this);
} //= operator overload