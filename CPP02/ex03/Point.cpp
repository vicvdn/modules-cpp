/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:24:41 by vvaudain          #+#    #+#             */
/*   Updated: 2024/06/12 12:15:50 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): x(0), y(0) {
}

Point::Point(const float nb1, const float nb2) : x(Fixed(nb1)), y(Fixed(nb2)) {
}

Point::Point(const	Point&	copy) : x(copy.get_x()), y(copy.get_y()) {
}

Point::~Point(){
}

Point&	Point::operator=(Point const & rhs) {
	(void)rhs;
	return (*this);
}

bool	Point::operator==(const Point &rhs) const {
	if (this->x == rhs.get_x() && this->y == rhs.get_y())
		return (true);
	else
		return (false);
}

const Fixed	Point::get_x( void ) const {
	return (this->x);
}

const Fixed	Point::get_y( void )const {
	return (this->y);
}

std::ostream & operator<<( std::ostream & o, Point const & rhs) {
	o << "Point(" << rhs.get_x() << ", " << rhs.get_y() << ")" << std::endl;
	return (o);
}