/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:36:12 by victoirevau       #+#    #+#             */
/*   Updated: 2024/10/28 11:14:08 by vvaudain         ###   ########.fr       */
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
	ScalarConverter::convert(av[1]);
	separatorPrint();
	separatorPrint();
	ScalarConverter::convert("-1.7976931348623158e+309");
	separatorPrint();
	ScalarConverter::convert("a");
	separatorPrint();
	ScalarConverter::convert("42");
	separatorPrint();
	ScalarConverter::convert("42.0");
	separatorPrint();
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