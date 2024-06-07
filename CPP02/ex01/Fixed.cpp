/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:21:12 by vvaudain          #+#    #+#             */
/*   Updated: 2024/06/07 18:42:10 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) : _number(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int number ) {
	std::cout << "Int constructor called" << std::endl;
	this->_number = number << this->_frac_bits;
}

Fixed::Fixed (const float number) {
	std::cout << "Float constructor called" << std::endl;
	this->_number = roundf(number * (1 << this->_frac_bits));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const	Fixed&	copy){
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed&	Fixed::operator=( Fixed const &rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	
	if (this != &rhs) {
		this->_number = rhs.getRawBits();
	}
	return *this;
}

int Fixed::getRawBits( void ) const {
	return this->_number;
}

void Fixed::setRawBits( int const raw ) {
	this->_number = raw;
}

float 	Fixed::toFloat( void ) const {
	return ((float)(this->_number) / (float)(1 << this->_frac_bits));
}

int 	Fixed::toInt( void ) const {
	return (this->_number >> this->_frac_bits);
}

std::ostream & operator<<( std::ostream & o, Fixed const & rhs) {
	o << rhs.toFloat();
	return (o);
}