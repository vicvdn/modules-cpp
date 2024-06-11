/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:24:41 by vvaudain          #+#    #+#             */
/*   Updated: 2024/06/11 15:51:32 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): x(0), y(0) {
}

Point::Point(const float nb1, const float nb2) : x(nb1), y(nb2) {
}

Point::Point(const	Point&	copy) {
}

Point::~Point(){
}

Point&	Point::operator=(Point const & rhs) {
	(void)rhs;
	return (*this);
}
