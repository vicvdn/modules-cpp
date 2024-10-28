/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:18:14 by vvaudain          #+#    #+#             */
/*   Updated: 2024/10/28 11:14:54 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


//======================= Overflow check =======================

std::string intToStr(const int input)
{
  std::ostringstream oss;
  oss << input;
  std::string result = oss.str();
  return result;
}

std::string floatToStr(const float input)
{
  std::ostringstream oss;
  oss << input;
  std::string result = oss.str();
  return result;
}

std::string doubleToStr(const double input)
{
  std::ostringstream oss;
  oss << input;
  std::string result = oss.str();
  return result;
}

std::string longDoubleToStr(const long double input)
{
  std::ostringstream oss;
  oss << input;
  std::string result = oss.str();
  return result;
}

bool isIntOverflow(std::string const &str, etype type)
{
	if (type == CHAR)
		return false;
	if (str.find("f") != std::string::npos)
	{
		std::string str2 = str.substr(0, str.length() - 1);
		return isIntOverflow(str2, type);
	}
	double d;
	std::stringstream ss(str);
	ss >> d;
	if (isFloatOverflow(str) == true)
		return true;
	if (type == FLOAT || type == DOUBLE)
	{
		return (d > std::numeric_limits<int>::max()
            || d < std::numeric_limits<int>::min()
            || d != static_cast<int>(d));
	}
	else
	{
		if (ss.fail() || !ss.eof())
			return true;
	}
    return (d > std::numeric_limits<int>::max()
            || d < std::numeric_limits<int>::min()
            || d != static_cast<int>(d));
}

bool isFloatOverflow(std::string const &str)
{
    double d;
    std::stringstream ss(str);
    ss >> d;
	
    return (d == std::numeric_limits<float>::infinity() 
			|| d == -std::numeric_limits<float>::infinity() 
			|| d > std::numeric_limits<float>::max()
			|| d < -std::numeric_limits<float>::max());
}


bool isDoubleOverflow(std::string const &str)
{
    long double ld;
    std::stringstream ss(str);
    ss >> ld;

    return (ld == std::numeric_limits<double>::infinity() || ld == -std::numeric_limits<double>::infinity() ||
            ld > std::numeric_limits<double>::max() || ld < -std::numeric_limits<double>::max() ||
            ld != static_cast<double>(ld));
}

//======================= Conversion functions =======================

int toInt(std::string const &str)
{
	int i;
	std::stringstream ss(str);
	ss >> i;
	return i;
}

float toFloat(std::string const &str)
{
	if (str.find("f") != std::string::npos)
	{
		std::string str2 = str.substr(0, str.length() - 1);
		float f = toFloat(str2);
		return f;
	}
	float f;
	std::stringstream ss(str);
	ss >> f;
	return f;
}

double toDouble(std::string const &str)
{
	double d;
	std::stringstream ss(str);
	ss >> d;
	return d;
}

char strToChar(std::string const &str, etype type)
{
	if (type == CHAR)
	{
		if (str.size() != 1)
			return 0;
		return str[0];
	}
	else if (type == INT)
	{
        if (isIntOverflow(str, type) == true)
            return 0;
		int i = toInt(str);
		if (i >=32 && i <= 126)
			return static_cast<char>(i);
	}
	else if (type == FLOAT)
	{
		if (isFloatOverflow(str) == true)
			return 0;
		float f = toFloat(str);
		if (isIntOverflow(str, type) == true)
			return 0;
		int i = static_cast<int>(f);
		if (i >=32 && i <= 126)
			return static_cast<char>(i);
	}
	else if (type == DOUBLE)
	{
		if (isDoubleOverflow(str) == true)
			return 0;
		double d = toDouble(str);
		if (isIntOverflow(str, type) == true)
			return 0;
		int i = static_cast<int>(d);
		if (i >=32 && i <= 126)
			return static_cast<char>(i);
	}
	return 0;
}

int strToInt(std::string const &str, etype type)
{
	if (type == INT)
	{
		int i = toInt(str);
		return i;
	}
	else if (type == CHAR)
		return static_cast<int>(str[0]);
	else if (type == FLOAT)
	{
		float f = toFloat(str);
		return static_cast<int>(f);
	}
    double d = toDouble(str);
    return static_cast<int>(d);
}

float strToFloat(std::string const &str, etype type)
{
	if (type == CHAR)
		return static_cast<float>(str[0]);
	else if (type == INT)
	{
		int i = toInt(str);
		return static_cast<float>(i);
	}
	else if (type == FLOAT)
	{
		float f = toFloat(str);
		return f;
	}
	double d = toDouble(str);
	if (d > std::numeric_limits<float>::max() || d < std::numeric_limits<float>::min())	
		return (- std::numeric_limits<float>::infinity());
    return static_cast<float>(d);
}

double strToDouble(std::string const &str, etype type)
{
	if (type == CHAR)
		return static_cast<double>(str[0]);
	else if (type == INT)
	{
		int i = toInt(str);
		return static_cast<double>(i);
	}
	else if (type == FLOAT)
	{
		float f = toFloat(str);
		return static_cast<double>(f);
	}
    double d = toDouble(str);
    return d;
}
