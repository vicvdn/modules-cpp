/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:13:26 by victoirevau       #+#    #+#             */
/*   Updated: 2024/10/15 08:51:47 by victoirevau      ###   ########.fr       */
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
	if (this != &rhs) {
	}
	return *this;
}

//======================= Overflow check =======================

bool isOverflow(std::string const &str, etype type)
{
	
	if (type == INT)
    {
        long long num = std::stoll(str);
        if (num > INT_MAX || num < INT_MIN)
        {
            return true;
        }
    	return false;
    }
	else if (type == FLOAT)
	{
		double num = std::stod(str);
		if (num > FLT_MAX || num < -FLT_MAX)
		{
			return true;
		}
		return false;
	}
	else if (type == DOUBLE)
	{
		try {
            double num = std::stod(str);
			(void)num;
        } catch (const std::out_of_range& oor) {
            return true;
        }
		return false;
	}
	return false;
}


//======================= Printing functions =======================

void printChar(std::string const & str, etype type) {
	std::cout << "char: ";
	if (type == CHAR)
	{
		if (isprint(str[0]))
			std::cout << "'" << str[0] << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	else if (type == INT)
	{
		int i = std::stoi(str);
		if (isprint(i))
			std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	else if (type == FLOAT)
	{
		int i = static_cast<int>(std::stof(str));
		if (isprint(i))
			std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	else if (type == DOUBLE)
	{
		int i = static_cast<int>(std::stod(str));
		if (isprint(i))
			std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;
}

void printInt(std::string const &str, etype type)
{
	std::cout << "int: ";
	if (isOverflow(str, getType(str)))
	{
		std::cout << "overflow" << std::endl;
		return;
	}
	if (type == INT)
		std::cout << std::stoi(str) << std::endl;
	else if (type == CHAR)
		std::cout << static_cast<int>(str[0]) << std::endl;
	else if (type == FLOAT)
		std::cout << static_cast<int>(std::stof(str)) << std::endl;
	else if (type == DOUBLE)
		std::cout << static_cast<int>(std::stod(str)) << std::endl;
	else
		std::cout << "impossible" << std::endl;
}

void printFloat(std::string const &str, etype type)
{
	std::cout << "float: ";
	if (type == CHAR)
		std::cout << static_cast<float>(str[0]) << ".0f" << std::endl;
	else if (type == INT)
		std::cout << static_cast<float>(std::stoi(str)) << ".0f" << std::endl;
	else if (type == FLOAT)
		std::cout << std::stof(str) << "f" << std::endl;
	else if (type == DOUBLE)
		std::cout << static_cast<float>(std::stod(str)) << "f" << std::endl;
	else
		std::cout << "impossible" << std::endl;
}

void printDouble(std::string const &str, etype type)
{
	std::cout << "double: ";
	if (type == CHAR)
		std::cout << static_cast<double>(str[0]) << ".0" << std::endl;
	else if (type == INT)
		std::cout << static_cast<double>(std::stoi(str)) << ".0" << std::endl;
	else if (type == FLOAT)
		std::cout << static_cast<double>(std::stof(str)) << std::endl;
	else if (type == DOUBLE)
		std::cout << std::stod(str) << std::endl;
	else
		std::cout << "impossible" << std::endl;
}

//======================= Converter =======================

void ScalarConverter::convert(std::string const & str) {
	etype type = getType(str);
	if (type == UNKNOWN){
		std::cerr << str << " is not a scalar type" << std::endl;
	}
	printChar(str, type);
	printInt(str, type);
	printFloat(str, type);
	printDouble(str, type);
}

// void	ScalarConverter::convert(std::string const & str) {
	
// 	//handling char
// 	etype type = getType(str);
// 	std::cout << "char: ";
// 	if (isChar(str)) {
// 		if (isprint(str[0]))
// 			std::cout << "'" << str[0] << "'" << std::endl;
// 		else
// 			std::cout << "Non displayable" << std::endl;
// 	}
// 	else if (isInt(str)) {
// 		int i = std::stoi(str);
// 		if (isprint(i))
// 			std::cout << "'" << static_cast<char>(i) << "'" << std::endl; // static_cast<char>(i) is equivalent to (char)i
// 		else
// 			std::cout << "Non displayable" << std::endl;
// 	}
// 	else {
// 		std::cout << "impossible" << std::endl;
// 	}

// 	//handling int
// 	std::cout << "int: ";
// 	try {
// 		int i = std::stoi(str);
// 		std::cout << i << std::endl;
// 	}
// 	catch (std::exception & e) {
// 		std::cout << "impossible" << std::endl;
// 	}

// 	//handling float and double
// 	std::cout << "float: ";
// 	try {
// 		float f = std::stof(str);
// 		std::cout << f << "f" << std::endl;
// 	}
// 	catch (std::exception & e) {
// 		std::cout << "impossible" << std::endl;
// 	}

// 	std::cout << "double: ";
// 	try {
// 		double d = std::stod(str);
// 		std::cout << d << std::endl;
// 	}
// 	catch (std::exception & e) {
// 		std::cout << "impossible" << std::endl;
// 	}
// }