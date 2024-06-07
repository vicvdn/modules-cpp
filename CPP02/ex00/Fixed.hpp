/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:42:31 by vvaudain          #+#    #+#             */
/*   Updated: 2024/06/07 15:43:46 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int	_number;
	static const int _frac_bits = 8;
public:
	Fixed( void );
	~Fixed();
	Fixed(const	Fixed&	copy);
	Fixed&	operator=(Fixed const & rhs);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};


#endif