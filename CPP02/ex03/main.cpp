/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:06:20 by vvaudain          #+#    #+#             */
/*   Updated: 2024/06/12 12:16:18 by vvaudain         ###   ########.fr       */
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

// static void	printTitle( std::string title, int width )
// {
// 	int	spaces = width - title.length() - 2;
	
// 	std::cout << "╔";
// 	for (int i = 0; i < width; i++)
// 		std::cout << "═";
// 	std::cout << "╗" << std::endl;
// 	std::cout << "║ " << title;
// 	for (int i = 0; i < spaces; i++)
// 		std::cout << " ";
// 	std::cout << " ║" << std::endl;
// 	std::cout << "╚";
// 	for (int i = 0; i < width; i++)
// 		std::cout << "═";
// 	std::cout << "╝" << std::endl;
// }

// static void	testBSP( void )
// {
// 	Point	a( 2.0f, 3.0f );
// 	Point	b( 6.0f, 4.0f );
// 	Point	c( 3.0f, 7.0f );
// 	Point	x( 5.0f, 5.0f );
// 	Point	z( 5.0f, 2.0f );
// 	Point	y( 4.0f, 5.0f );

// 	printTitle("BSP", 42);

// 	std::cout << "a = " << a << std::endl;
// 	std::cout << "b = " << b << std::endl;
// 	std::cout << "c = " << c << std::endl;
// 	std::cout << "x = " << x << std::endl;
// 	std::cout << "z = " << z << std::endl;
// 	std::cout << "y = " << y << std::endl;
	
// 	std::cout << "Let's check if x is inside the triangle abc" << std::endl;
// 	std::cout << "bsp( a, b, c, x ) = " << (bsp( a, b, c, x ) ? "true" : "false") << std::endl << std::endl;
// 	std::cout << "Let's check if z is inside the triangle abc" << std::endl;
// 	std::cout << "bsp( a, b, c, z ) = " << (bsp( a, b, c, z ) ? "true" : "false") << std::endl << std::endl;
// 	std::cout << "Let's check if y is inside the triangle abc" << std::endl;
// 	std::cout << "bsp( a, b, c, y ) = " << (bsp( a, b, c, y ) ? "true" : "false") << std::endl << std::endl;
// }

// int main( void )
// {
// 	testBSP();
// 	return (0);
// }
