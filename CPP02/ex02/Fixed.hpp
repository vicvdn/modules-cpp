/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:33:45 by vvaudain          #+#    #+#             */
/*   Updated: 2024/06/12 13:36:07 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define	FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int	_number;
	static const int _frac_bits = 8;
public:
	Fixed( void );
	Fixed (const int number);
	Fixed (const float number);
	Fixed(const	Fixed&	copy);
	~Fixed();
	int 				getRawBits( void ) const;
	void 				setRawBits( int const raw );
	float 				toFloat( void ) const;
	int 				toInt( void ) const;
	Fixed&	operator=(Fixed const & rhs);
	bool				operator==(const Fixed & rhs) const;
	bool				operator>(const Fixed & rhs) const;
	bool				operator<(const Fixed & rhs) const;
	bool				operator>=(const Fixed & rhs) const;
	bool				operator<=(const Fixed & rhs) const;
	bool				operator!=(const Fixed & rhs) const;
	Fixed				operator+(const Fixed & rhs) const;
	Fixed				operator-(const Fixed & rhs) const;
	Fixed				operator*(const Fixed & rhs) const;
	Fixed				operator/(const Fixed & rhs) const;
	Fixed&				operator++( void );
	Fixed				operator++( int );
	Fixed&				operator--( void );
	Fixed				operator--( int );
	static const Fixed&	min(Fixed& nb1, Fixed& nb2);
	static const Fixed&	min(const Fixed& nb1, const Fixed& nb2);
	static const Fixed&	max(Fixed& nb1, Fixed& nb2);
	static const Fixed&	max(const Fixed& nb1, const Fixed& nb2);
};

std::ostream & operator<<( std::ostream & o, Fixed const & rhs);

#endif