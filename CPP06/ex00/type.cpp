/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:58:39 by victoirevau       #+#    #+#             */
/*   Updated: 2024/10/15 08:53:47 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool isChar(std::string const & str) {
	if (str.length() == 1 && !isdigit(str[0])) {
		return true;
	}
	return false;
}

bool isInt(std::string const & str) {
	if (isChar(str)) {
		return false;
	}
	for (size_t i = 0; i < str.length(); i++) {
		
		if (i == 0 && (str[i] == '+' || str[i] == '-')) {
			continue;
		}
		if (!isdigit(str[i])) {
			return false;
		}
	}
	return true;
}

bool isFloat(std::string const &str) {
	int dotCount = 0;
	int fCount = 0;
	
	for (size_t i = 0; i < str.length(); i++) {
		if (i == 0 && (str[i] == '+' || str[i] == '-')) {
			continue;
		}
		if (str[i] == '.') {
			dotCount++;
		}
		if (str[i] == 'f' || str[i] == 'F') {
			if (i != str.length() - 1)
				return false;
			else
				fCount++;
		}
		if (str[i] == 'e' && i != str.length() - 1 && i != str.length() - 2 && i != 0) {
			if (str[i + 1] == '+' || str[i + 1] == '-')
				i += 2;
		}
		if (!isdigit(str[i]) && str[i] != '.' && str[i] != 'f' && str[i] != 'F') {
			return false;
		}
	}
	if (dotCount == 1 && fCount == 1) {
		return true;
	}
	else
		return false;
}

bool isDouble(std::string const &str){
	int dotCount = 0;
	
	for (size_t i = 0; i < str.length(); i++) {
		if (i == 0 && (str[i] == '+' || str[i] == '-')) {
			continue;
		}
		if (str[i] == '.') {
			dotCount++;
		}
		if (!isdigit(str[i]) && str[i] != '.') {
			return false;
		}
	}
	if (dotCount == 1) {
		return true;
	}
	return false;
}

etype getType(std::string const &str) {
	if (isChar(str)) {
		std::cout << "CHAR" << std::endl;
		return CHAR;
	}
	if (isInt(str)) {
		std::cout << "INT" << std::endl;
		return INT;
	}
	if (isFloat(str)) {
		std::cout << "FLOAT" << std::endl;
		return FLOAT;
	}
	if (isDouble(str)) {
		std::cout << "DOUBLE" << std::endl;
		return DOUBLE;
	}
	return UNKNOWN;
}