/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:36:12 by victoirevau       #+#    #+#             */
/*   Updated: 2024/10/16 14:04:27 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void separatorPrint() {
	std::cout << "============================================" << std::endl;
}

int main (int ac, char **av) {
	if (ac != 2) {
		std::cout << "Error: wrong number of arguments" << std::endl;
		return 1;
	}
	(void)av;
	// ScalarConverter::convert(av[1]);
	
	ScalarConverter::convert("0");
	separatorPrint();
	ScalarConverter::convert("42.0f");
	separatorPrint();
	ScalarConverter::convert("nan");
	separatorPrint();
	ScalarConverter::convert(intToStr(std::numeric_limits<int>::max()));
	separatorPrint();
	ScalarConverter::convert(floatToStr(std::numeric_limits<float>::max()) + "f");
	separatorPrint();
	ScalarConverter::convert(doubleToStr(std::numeric_limits<double>::max()));
	separatorPrint();
	ScalarConverter::convert(intToStr(std::numeric_limits<int>::min()));
	separatorPrint();
	ScalarConverter::convert(floatToStr(std::numeric_limits<float>::min()) + "f");
	separatorPrint();
	ScalarConverter::convert(doubleToStr(std::numeric_limits<double>::min()));
	return 0;
}

//values to test
/*
float max + 1: 3.4028235e+38f
float max: 3.4028234e+38f

float min - 1: -3.4028235e+38f
THIS DOES NOT WORK

float min: -3.4028234e+38f

double max + 1: 1.7976931348623157e+308
double max: 1.7976931348623158e+308
double min - 1: -1.7976931348623158e+308
double min: -1.7976931348623157e+308

int max + 1: 2147483648
int max: 2147483647
int min - 1: -2147483649
int min: -2147483648

char max + 1: 128
char max: 127
char max printables: 126
*/