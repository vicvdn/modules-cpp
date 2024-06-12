/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:09:14 by vvaudain          #+#    #+#             */
/*   Updated: 2024/06/12 11:59:43 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

class Point {

private:
	const Fixed x;
	const Fixed y;
	
public:
	Point();
	Point(const float nb1, const float nb2);
	Point(const	Point&	copy);
	~Point();
	Point&	operator=(Point const & rhs);
	bool	operator==(const Point &rhs) const;
	const Fixed	get_x( void ) const;
	const Fixed	get_y( void ) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
std::ostream & operator<<( std::ostream & o, Point const & rhs);


#endif