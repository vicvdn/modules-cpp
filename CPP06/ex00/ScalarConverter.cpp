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
	return *this;
}

//======================= Overflow check =======================

bool isIntOverflow(std::string const &str, etype type)
{
	long l;
	std::stringstream ss(str);
	ss >> l;
	if (l > INT_MAX || l < INT_MIN)
		return true;
	return false;
}

bool isFloatOverflow(std::string const &str, etype type)
{
	double d;
	std::stringstream ss(str);
	ss >> d;
	if (d > FLT_MAX || d < -FLT_MAX)
		return true;
	return false;
}

bool isDoubleOverflow(std::string const &str, etype type)
{
	long double ld;
	std::stringstream ss(str);
	ss >> ld;
	if (ld > DBL_MAX || ld < -DBL_MAX)
		return true;
	return false;
}

//======================= Printing functions =======================

void printChar(char toPrint, std::string const & str, etype type) {
	std::cout << "char: ";
	if (toPrint == 0 && str.size() > 1)
		std::cout << "Impossible" << std::endl;
	else if (isprint(toPrint))
		std::cout << "'" << str[0] << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

void printInt(int toPrint, etype type)
{
	std::cout << "int: ";
	//gerer l'overflow au moment de la conversion
	if (toPrint == -1)
		std::cout << "impossible" << std::endl;
	else if (toPrint == -2)
		std::cout << "overflow" << std::endl;
	else
		std::cout << toPrint << std::endl;
}

void printFloat(float toPrint, etype type)
{
	std::cout << "float: ";
	//gerer l'overflow au moment de la conversion
	if (toPrint == -1)
		std::cout << "impossible" << std::endl;
	else if (toPrint == -2)
		std::cout << "overflow" << std::endl;
	else
		std::cout << toPrint << std::endl;
}

void printDouble(double toPrint, etype type)
{
	std::cout << "double: ";
	//gerer l'overflow au moment de la conversion
	if (toPrint == -1)
		std::cout << "impossible" << std::endl;
	else if (toPrint == -2)
		std::cout << "overflow" << std::endl;
	else
		std::cout << toPrint << std::endl;
}


//======================= Conversion functions =======================

char strToChar(std::string const &str, etype type)
{
	// if (str.size() > 1)
	// 	return 0;
	if (type == CHAR)
		return str[0];
	else if (type == INT)
	{
		int i;
		std::stringstream ss(str);
		ss >> i;
		if (isprint(i))
			return static_cast<char>(i);
	}
	else if (type == FLOAT)
	{
		float f;
		std::stringstream ss(str);
		ss >> f;
		if (isprint(f))
			return static_cast<char>(f);
	}
	else if (type == DOUBLE)
	{
		double d;
		std::stringstream ss(str);
		ss >> d;
		if (isprint(d))
			return static_cast<char>(d);
	}
	return 0;
}

int strToInt(std::string const &str, etype type)
{
	if (type == INT)
	{
		if (isIntOverflow(str, type) == true)
			return -2;
		int i;
		std::stringstream ss(str);
		ss >> i;
		return i;
	}
	else if (type == CHAR)
		return static_cast<int>(str[0]);
	else if (type == FLOAT)
	{
		float f;
		std::stringstream ss(str);
		ss >> f;
		return static_cast<int>(f);
	}
	else if (type == DOUBLE)
	{
		double d;
		std::stringstream ss(str);
		ss >> d;
		return static_cast<int>(d);
	}
	return -1;
}

float strToFloat(std::string const &str, etype type)
{
	if (type == CHAR)
		return static_cast<float>(str[0]);
	else if (type == INT)
	{
		int i;
		std::stringstream ss(str);
		ss >> i;
		return static_cast<float>(i);
	}
	else if (type == FLOAT)
	{
		float f;
		std::stringstream ss(str);
		ss >> f;
		return f;
	}
	else if (type == DOUBLE)
	{
		double d;
		std::stringstream ss(str);
		ss >> d;
		return static_cast<float>(d);
	}
	return 0;
}

double strToDouble(std::string const &str, etype type)
{
	if (type == CHAR)
		return static_cast<double>(str[0]);
	else if (type == INT)
	{
		int i;
		std::stringstream ss(str);
		ss >> i;
		return static_cast<double>(i);
	}
	else if (type == FLOAT)
	{
		float f;
		std::stringstream ss(str);
		ss >> f;
		return static_cast<double>(f);
	}
	else if (type == DOUBLE)
	{
		double d;
		std::stringstream ss(str);
		ss >> d;
		return d;
	}
	return 0;
}

//======================= Converter =======================

void ScalarConverter::convert(std::string const & str) {
	etype type = getType(str);
	if (type == UNKNOWN)
		std::cerr << str << " is not a scalar type" << std::endl;
	else
	{
		charToPrint = strToChar(str, type); //OK
		intToPrint = strToInt(str, type);
		floatToPrint = strToFloat(str, type);
		doubleToPrint = strToDouble(str, type);
	}
	printChar(str, type);
	printInt(str, type);
	printFloat(str, type);
	printDouble(str, type);
}


//d'abord gettype pour savoir quel type c'est
//puis convertir en char, int, float, double la string
//puis print les 4
//si c'est pas un type connu, print impossible
//gerer ensuite les overflow