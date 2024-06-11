/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:16:56 by vvaudain          #+#    #+#             */
/*   Updated: 2024/06/10 14:37:07 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

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
	Fixed&	operator=(Fixed const & rhs);
	int 	getRawBits( void ) const;
	void 	setRawBits( int const raw );
	float 	toFloat( void ) const;
	int 	toInt( void ) const;
};

std::ostream & operator<<( std::ostream & o, Fixed const & rhs);

#endif