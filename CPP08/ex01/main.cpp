/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:43:57 by victoirevau       #+#    #+#             */
/*   Updated: 2024/10/21 15:44:22 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void printSeparator()
{
	std::cout << "-----------------------------------------" << std::endl;
}

int main(void)
{
	try {
		Span sp = Span(5);
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	printSeparator();

	try {
		Span sp2 = Span(10000);
		std::vector<int> vec;
		for (int i = 0; i < 10000; i++)
			vec.push_back(i);
		sp2.addRange(vec);
		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	printSeparator();
	try {
		Span sp4 = Span(0);
		std::cout << sp4.shortestSpan() << std::endl;
		std::cout << sp4.longestSpan() << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	printSeparator();

	try {
		Span sp3 = Span(1);
		std::cout << sp3.shortestSpan() << std::endl;
		std::cout << sp3.longestSpan() << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	printSeparator();

	try {
		Span sp5 = Span(2);
		sp5.addNumber(1);
		sp5.addNumber(2);
		std::cout << sp5.shortestSpan() << std::endl;
		std::cout << sp5.longestSpan() << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}