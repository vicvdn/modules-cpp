/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:11:15 by victoirevau       #+#    #+#             */
/*   Updated: 2024/10/16 13:22:24 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <limits>
// #include <cfloat>

#define BOLDBLUE "\033[1m\033[34m"
#define RESET "\033[0m"

enum etype {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	SPECIAL,
	UNKNOWN
};

#define NON_DISPLAYABLE "Non displayable"
class ScalarConverter {

	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const & src);
		
	public:
		~ScalarConverter();
		ScalarConverter & operator=(ScalarConverter const & rhs);
		static void	convert(std::string const & str);	
};

//======================= Type check =================================
etype getType(std::string const &str);
bool isSpecial(std::string const &str);


//======================= Print functions ============================
bool isOverflowPrint(std::string const &str);
void printChar(char toPrint, std::string const & str);
// void printInt(int toPrint);
void printFloat(float toPrint, etype type);
void printDouble(double toPrint, etype type);

//======================= Overflow check =======================
bool isIntOverflow(std::string const &str);
bool isFloatOverflow(std::string const &str);
bool isDoubleOverflow(std::string const &str);

//======================= Conversion functions =======================
std::string intToStr(const int input);
std::string floatToStr(const float input);
std::string doubleToStr(const double input);
std::string longDoubleToStr(const long double input);

char strToChar(std::string const &str, etype type);
int strToInt(std::string const &str, etype type);
float strToFloat(std::string const &str, etype type);
double strToDouble(std::string const &str, etype type);

#endif