/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:09:14 by vvaudain          #+#    #+#             */
/*   Updated: 2024/06/11 16:38:20 by vvaudain         ###   ########.fr       */
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
};

#endif