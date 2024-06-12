/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:31:00 by vvaudain          #+#    #+#             */
/*   Updated: 2024/06/12 12:03:15 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed t1;
	Fixed t2;
	Fixed t3;

	if ( point == a || point == b || point == c)
		return (false);

	t1 = (b.get_x() - point.get_x()) * (a.get_y() - point.get_y()) - (b.get_y() - point.get_y()) * (a.get_x() - point.get_x());
	t2 = (a.get_x() - point.get_x()) * (c.get_y() - point.get_y()) - (a.get_y() - point.get_y()) * (c.get_x() - point.get_x());
	t3 = (c.get_x() - point.get_x()) * (b.get_y() - point.get_y()) - (c.get_y() - point.get_y()) * (b.get_x() - point.get_x());
	
	if ((t1 > 0 && t2 > 0 && t3 > 0) || (t1 < 0 && t2 < 0 && t3 < 0))
		return (true);
	else
		return (false);
}