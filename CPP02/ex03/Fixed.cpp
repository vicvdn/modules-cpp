/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:19:56 by vvaudain          #+#    #+#             */
/*   Updated: 2024/06/12 11:48:33 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


Fixed::Fixed( void ) : _number(0) {
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int number ) {
	// std::cout << "Int constructor called" << std::endl;
	this->_number = number << this->_frac_bits;
}

Fixed::Fixed (const float number) {
	// std::cout << "Float constructor called" << std::endl;
	this->_number = roundf(number * (1 << this->_frac_bits));
}

Fixed::~Fixed() {
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const	Fixed&	copy){
	// std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed&	Fixed::operator=( Fixed const &rhs) {
	// std::cout << "Copy assignment operator called" << std::endl;
	
	if (this != &rhs) {
		this->_number = rhs.getRawBits();
	}
	return (*this);
}

int Fixed::getRawBits( void ) const {
	return this->_number;
}

void Fixed::setRawBits( int const raw ) {
	this->_number = raw;
}

float 	Fixed::toFloat( void ) const {
	float	res = this->_number / (float)(1 << this->_frac_bits);
	return (res);
}

int 	Fixed::toInt( void ) const {
	return (this->_number >> this->_frac_bits);
}

std::ostream & operator<<( std::ostream & o, Fixed const & rhs) {
	o << rhs.toFloat();
	return (o);
}

//comparison operators

bool Fixed::operator==(const Fixed & rhs) const {
	return (this->_number == rhs.getRawBits());
}

bool Fixed::operator<(const Fixed & rhs) const {
	return (this->_number < rhs.getRawBits());
}

bool Fixed::operator>(const Fixed & rhs) const {
	return (this->_number > rhs.getRawBits());
}

bool Fixed::operator>=(const Fixed & rhs) const {
	return (this->_number >= rhs.getRawBits());
}

bool Fixed::operator<=(const Fixed & rhs) const {
	return (this->_number <= rhs.getRawBits());
}

bool Fixed::operator!=(const Fixed & rhs) const {
	return (this->_number != rhs.getRawBits());
}

//arithmetics operators

Fixed Fixed::operator+(const Fixed & rhs) const {
	return (this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed & rhs) const {
	return (this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed & rhs) const {
	return (this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed & rhs) const {
	return (this->_number / rhs.getRawBits());
}

//incrementation operators

Fixed&	Fixed::operator++( void ) {
	this->_number++;
	return (*this);
}

Fixed	Fixed::operator++( int ) {
	Fixed	instance = *this;
	this->_number++;
	return (instance);
}

Fixed&	Fixed::operator--( void ) {
	this->_number--;
	return (*this);
}

Fixed	Fixed::operator--( int ) {
	Fixed	instance = *this;
	this->_number--;
	return (instance);
}

const Fixed&	Fixed::min(Fixed& nb1, Fixed& nb2) {
	if (nb1 < nb2)
		return nb1;
	else
		return nb2;
}

const Fixed&	Fixed::min(const Fixed& nb1, const Fixed& nb2) {
	if (nb1 < nb2)
		return nb1;
	else
		return nb2;
}

const Fixed&	Fixed::max(Fixed& nb1, Fixed& nb2) {
	if (nb1 < nb2)
		return nb2;
	else
		return nb1;
}

const Fixed&	Fixed::max(const Fixed& nb1, const Fixed& nb2) {
	if (nb1 < nb2)
		return nb2;
	else
		return nb1;
}