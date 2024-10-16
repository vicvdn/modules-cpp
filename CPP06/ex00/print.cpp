/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:15:52 by vvaudain          #+#    #+#             */
/*   Updated: 2024/10/16 15:38:48 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

//======================= Printing functions =======================

bool isOverflowPrint(std::string const &str, etype type)
{
	if (isDoubleOverflow(str) == true)
		return true;
	if (isFloatOverflow(str) == true)
		return true;
	if (isIntOverflow(str, type) == true)
		return true;
	return false;
}

void printChar(char toPrint, std::string const & str) {
	std::cout << "char: ";
	if (toPrint == 0 && str.size() > 3)
		std::cout << "impossible" << std::endl;
	else if (isprint(toPrint))
		std::cout << "'" << toPrint << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

void printFloat(float toPrint, etype type)
{
	if (type == FLOAT || type == DOUBLE)
	{
		//check for a ".0" at the end of the float
		if (toPrint - static_cast<int>(toPrint) == 0)
			std::cout << toPrint << ".0f" << std::endl;
		else
			std::cout << toPrint << "f" << std::endl;
	}
	else
		std::cout << toPrint << ".0f" << std::endl;
}

void printDouble(double toPrint, etype type)
{
	//gerer l'overflow au moment de la conversion
	if (type == FLOAT || type == DOUBLE)
	{
		//check for a ".0" at the end of the float
		if (toPrint - static_cast<int>(toPrint) == 0)
			std::cout << toPrint << ".0" << std::endl;
		else
			std::cout << toPrint << std::endl;
	}
	else
		std::cout << toPrint << ".0" << std::endl;
}
