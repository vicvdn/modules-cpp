/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:11:15 by victoirevau       #+#    #+#             */
/*   Updated: 2024/10/14 17:30:29 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <cfloat>

enum etype {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	UNKNOWN
};

class ScalarConverter {

	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const & src);
		
	public:
		~ScalarConverter();
		ScalarConverter & operator=(ScalarConverter const & rhs);
		static void	convert(std::string const & str);	
};

etype getType(std::string const &str);

#endif