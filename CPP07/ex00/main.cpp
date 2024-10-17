/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:02:51 by victoirevau       #+#    #+#             */
/*   Updated: 2024/10/17 14:29:52 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

void printSeparator()
{
	std::cout << "---------------------------------" << std::endl;
}

// int main(void)
// {
// 	int a = 2;
// 	int b = 3;

// 	std::cout << BOLDGREEN << "a = " << a << "," << BOLDYELLOW << " b = " << b << RESET << std::endl;
// 	printSeparator();
// 	std::cout << BOLDBLUE << "Let's swap them!" << RESET << std::endl;
// 	swap(a, b);
// 	printSeparator();
// 	std::cout << BOLDGREEN << "a = " << a << "," << BOLDYELLOW <<  "b = " << b << RESET << std::endl;
// 	std::cout << "min(a, b) = " << min(a, b) << std::endl;
// 	std::cout << "max(a, b) = " << max(a, b) << std::endl;
	
// 	std::cout << std::endl;
// 	std::cout << std::endl;
	
// 	std::string c = "blabla1";
// 	std::string d = "blabla2";

// 	std::cout << BOLDGREEN << "c = " << c << "," << BOLDYELLOW << "d = " << d << RESET << std::endl;
// 	printSeparator();
// 	std::cout << BOLDBLUE << "Let's swap them!" << RESET << std::endl;
// 	swap(c, d);
// 	printSeparator();
// 	std::cout << BOLDGREEN << "c = " << c << "," << BOLDYELLOW << "d = " << d << RESET << std::endl;
// 	std::cout << "min(c, d) = " << min(c, d) << std::endl;
// 	std::cout << "max(c, d) = " << max(c, d) << std::endl;

// 	return 0;
// }

int main( void ) 
{
	int a = 2;
	int b = 3;
	swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}