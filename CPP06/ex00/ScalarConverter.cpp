/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:13:26 by victoirevau       #+#    #+#             */
/*   Updated: 2024/10/16 14:05:27 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

//======================= Constructors/Destructors =======================

ScalarConverter::ScalarConverter() {
}

ScalarConverter::ScalarConverter(ScalarConverter const & src) {
	*this = src;
}

ScalarConverter::~ScalarConverter() {
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & rhs) {
	(void)rhs;
	return *this;
}

void handleChar(std::string const & str, etype type) 
{
	std::cout << "char: ";
	char charToPrint = strToChar(str, type);
	if (charToPrint == 0)
	{
		if (isOverflowPrint(str))
		{
			std::cout << "impossible" << std::endl;
			return;
		}
		else
		{
			int i;
			std::stringstream ss(str);
			ss >> i;
			if (i >= 32 && i <= 126)
			{
				std::cout << static_cast<char>(i) << "'" << std::endl;
				return;
			}
			else if ((i >= 0 && i <= 32) || i == 127)
			{
				std::cout << "Non displayable" << std::endl;
				return;
			}
			else
			{
				std::cout << "impossible" << std::endl;
				return;
			}
		}
	}
	printChar(charToPrint, str);
}

void handleInt(std::string const & str, etype type) 
{
	std::cout << "int: ";
	if (isOverflowPrint(str))
	{
		std::cout << "overflow" << std::endl;
		return;
	}
	if (isSpecial(str))
		std::cout << "impossible" << std::endl;
	else
	{
		int intToPrint = strToInt(str, type);
		std::cout << intToPrint << std::endl;
	}
}

void handleFloat(std::string const & str, etype type) 
{
	std::cout << "float: ";
	if (isFloatOverflow(str) == true)
	{
		if (str.find("-") != std::string::npos)
			std::cout << "-inff" << std::endl;
		else
			std::cout << "inff" << std::endl;
		return;
	}
	if (isSpecial(str))
	{
		if (type == FLOAT)
			std::cout << str << std::endl;
		else if (type == DOUBLE)
			std::cout << str << "f" << std::endl;
	}
	else
	{
		// std::cout << "je passe par la" << std::endl;
		float floatToPrint = strToFloat(str, type);
		printFloat(floatToPrint, type);
	}
}

void handleDouble(std::string const & str, etype type) 
{
	std::cout << "double: ";
	if (isDoubleOverflow(str) == true)
	{
		if (str.find("-") != std::string::npos)
			std::cout << "-inf" << std::endl;
		else
			std::cout << "inf" << std::endl;
		return;
	}
	if (isSpecial(str))
	{
		if (type == FLOAT)
			std::cout << str.substr(0, str.length() - 1) << std::endl;
		else if (type == DOUBLE)
			std::cout << str << std::endl;
	}
	else
	{
		double doubleToPrint = strToDouble(str, type);
		printDouble(doubleToPrint, type);
	}
}

//======================= Converter =======================

void ScalarConverter::convert(std::string const & str) {
	
	if (str.empty())
	{
		std::cerr << "Empty string" << std::endl;
		return;
	}
	etype type = getType(str);
	if (type == UNKNOWN)
	{
		std::cerr << str << " is not a scalar type" << std::endl;
		return;	
	}
	
	handleChar(str, type);
	handleInt(str, type);
	handleFloat(str, type);
	handleDouble(str, type);
}