/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:06:20 by vvaudain          #+#    #+#             */
/*   Updated: 2024/06/12 13:31:55 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

int	main(void) {
	Point a(0, 0);
	Point b(2, 3);
	Point c(3, 0);
	Point point(1.5864f, 1);
	Fixed test(3);
	
	std::cout << "a(x)" << a.get_x() << std::endl;
	std::cout << "a(y)" << a.get_y() << std::endl;
	std::cout << "b(x)" << b.get_x() << std::endl;
	std::cout << "b(x)" << b.get_y() << std::endl;
	std::cout << "c(x)" << c.get_x() << std::endl;
	std::cout << "c(x)" << c.get_y() << std::endl;
	std::cout << "point(x)" << point.get_x() << std::endl;
	std::cout << "point(x)" << point.get_y() << std::endl;
	
	std::cout << "-------------------" << std::endl;
	
	if (bsp(a, b, c, point) == true)
		std::cout << "TRUE" << std::endl;
	else
		std::cout << "FALSE" << std::endl;
}
